/*
 * db_generatorTypeDepWalk.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */


/*
 * db_genType.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "db_generatorTypeDepWalk.h"

typedef struct db_genTypeWalk_t {
	db_generator g;
	db_ll parsed; /* List of parsed types */
	db_ll declared; /* List of declared objects */
	g_walkAction onDeclare;
	g_walkAction onDefine;
	void* userData;
}db_genTypeWalk_t;

static int db_genTypeParse(db_object o, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data);

/* Mark type as parsed */
static void db_genTypeParsed(db_object o, db_genTypeWalk_t* data) {
    db_llInsert(data->parsed, o);
}

/* Mark object as declared */
typedef struct db_genTypeDeclaration {
    db_object o;
    db_bool printed; /* If true, a forward declaration is printed in generated code. */
    db_bool parsing; /* If true, then the object is currently being parsed and recursive
                        references can be checked. If false, this object only serves to
                        prevent re-declaring an object. */
}db_genTypeDeclaration;

static db_genTypeDeclaration* db_genTypeDeclared(db_object o, db_genTypeWalk_t* data) {
    struct db_genTypeDeclaration* decl;

    /* Insert declaration object */
    decl = db_malloc(sizeof(struct db_genTypeDeclaration));
    decl->o = o;
    decl->printed = FALSE;
    decl->parsing = FALSE;
    db_llInsert(data->declared, decl);

    return decl;
}

/* Compare two types structurally */
static db_bool db_genTypeCompareStructural(db_type t1, db_type t2) {
    db_bool result;
    result = FALSE;
    if (t1->kind == t2->kind) {
        switch(t1->kind) {
        case DB_PRIMITIVE:
            if (db_primitive(t1)->kind == db_primitive(t2)->kind) {
            	if (db_primitive(t1)->kind == DB_ALIAS) {
            		result = !strcmp(db_alias(t1)->typeName, db_alias(t2)->typeName);
            	} else {
					if (db_primitive(t1)->width == db_primitive(t2)->width) {
						result = TRUE;
					}
            	}
            }
            break;
        case DB_COLLECTION:
            if (db_collection(t1)->kind == db_collection(t2)->kind) {
                if (db_collection(t1)->elementType == db_collection(t2)->elementType) {
                	if (db_collection(t1)->max == db_collection(t2)->max) {
                		if (db_collection(t1)->kind != DB_MAP) {
                			result = TRUE;
                		} else {
							if (db_map(t1)->keyType != db_map(t2)->keyType) {
								result = TRUE;
							}
                		}
                	}
                }
            }
            break;
        default:
            db_error("genTypeCompareStructural: only primitive and collection types can be compared structurally.");
            break;
        }
    }
    return result;
}

/* Find type in parsed-list */
static db_bool db_genTypeIsParsed(db_object o, db_genTypeWalk_t* data) {
    db_iter iter;
    db_object p;
    db_bool found;

    p = NULL;
    found = FALSE;

    iter = db_llIter(data->parsed);
    while(!found && db_iterHasNext(&iter)) {
        p = db_iterNext(&iter);
        /* If object is scoped, it must be matched exactly */
        if (db_checkAttr(o, DB_ATTR_SCOPED)) {
            if (o == p) {
                found = TRUE;
            }
        /* If object is not scoped (anonymous), it is matched structurally */
        } else {
        	if (db_typeof(o) == db_typeof(p)) {
				if (db_genTypeCompareStructural(o, p)) {
					found = TRUE;
				}
        	}
        }
    }

    return found;
}

/* Find type in declared-list */
static struct db_genTypeDeclaration* db_genTypeIsDeclared(db_object o, db_genTypeWalk_t* data) {
    db_iter iter;
    struct db_genTypeDeclaration* p;

    p = NULL;
    iter = db_llIter(data->declared);
    while(db_iterHasNext(&iter)) {
        p = db_iterNext(&iter);
        if (o == p->o) {
            break;
        }
    }

    return p ? (o == p->o) ? p : NULL : NULL;
}

/* Resolve any-dependencies */
static int db_genTypeAnyDependencies(db_type t, db_genTypeWalk_t* data) {
    db_genTypeDeclaration* decl;

    DB_UNUSED(t);

    /* Any has a dependency on type */
    if (!(decl = db_genTypeIsDeclared(db_type_o, data))) {
        decl = db_genTypeDeclared(db_type_o, data);
    }

    if (!decl->printed) {
        /* Print forward declaration */
        if (data->onDeclare(db_type_o, data->userData)) {
            goto error;
        }
        decl->printed = TRUE;
    }

    /* Any has a dependency on bool */
    if (!(decl = db_genTypeIsDeclared(db_bool_o, data))) {
        decl = db_genTypeDeclared(db_bool_o, data);
    }

    if (!decl->printed) {
        /* Print forward declaration */
        if (data->onDefine(db_bool_o, data->userData)) {
            goto error;
        }
        decl->printed = TRUE;
    }

    return 0;
error:
    return -1;
}

/* Resolve class dependencies */
static int db_genTypeInterfaceDependencies(db_interface t, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {
    db_uint32 i;
    db_member m;
    db_bool declAllowed;

    /* Serialize base */
    if (db_interface(t)->base)  {
        if (db_genTypeParse(db_typedef(db_interface(t)->base), FALSE, recursion, data)) {
            goto error;
        }

        /* If recursion occurred, this type cannot be parsed (yet). */
        if (recursion && *recursion) {
            goto recursion;
        }
    }

    /* Walk members of composite type */
    for(i=0; i<t->members.length; i++) {
        m = t->members.buffer[i];
        declAllowed = m->type->real->reference ? TRUE : allowDeclared;
        if (db_genTypeParse(m->type, declAllowed, recursion, data)) {
            goto error;
        }

        /* If recursion occurred and a declaration is allowed, forward declare type and turn of recursion. */
        if (recursion && *recursion) {
            db_genTypeDeclaration* decl;
            *recursion = FALSE;

            /* Mark the object as declared, printed and not parsing. */
            if (!(decl = db_genTypeIsDeclared(m->type, data))) {
                decl = db_genTypeDeclared(m->type, data);
            }

            if (!decl->printed) {
                /* Print forward declaration */
                if (data->onDeclare(m->type, data->userData)) {
                    goto error;
                }
                decl->printed = TRUE;
            }
        }
    }
recursion:
    return 0;
error:
    return -1;
}

/* Resolve collection dependencies */
static int db_genTypeCollectionDependencies(db_collection t, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {
    if (t->kind != DB_ARRAY) {
        allowDeclared = TRUE;
    }
    return db_genTypeParse(t->elementType, allowDeclared, recursion, data);
}

/* Resolve map dependencies */
static int db_genTypeMapDependencies(db_map t, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {
    DB_UNUSED(allowDeclared);

    /* Serialize collection dependencies */
    if (db_genTypeCollectionDependencies(db_collection(t), allowDeclared, recursion, data)) {
        goto error;
    }

    /* Serialize keyType */
    if (db_genTypeParse(t->keyType, TRUE, recursion, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Resolve typedef dependencies */
static int db_genTypeTypedefDependencies(db_typedef t, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {
    return db_genTypeParse(t->type, allowDeclared, recursion, data);
}

/* Serialize dependencies of a type */
static int db_genTypeDependencies(db_object o, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {
    db_typedef t;

    t = db_typedef(o);

    if (t != db_typedef(t->real)) {
        /* Dependencies of typedef */
        if (db_genTypeTypedefDependencies(t, allowDeclared, recursion, data)) {
            goto error;
        }
    } else {
        switch(db_type(t)->kind) {
        case DB_VOID:
        	/* Void types can't have dependencies */
        	break;

        case DB_ANY:
            if (db_genTypeAnyDependencies(db_type(o), data)) {
                goto error;
            }
            break;

        /* Primitives can't have dependencies */
        case DB_PRIMITIVE:
            break;

        /* Serialize dependencies of composite type */
        case DB_COMPOSITE:
            switch(db_interface(o)->kind) {
            case DB_STRUCT:
            case DB_INTERFACE:
            case DB_CLASS:
            case DB_PROCEDURE:
                if (db_genTypeInterfaceDependencies(db_interface(o), allowDeclared, recursion, data)) {
                    goto error;
                }
                break;
            }
            break;

        /* Serialize dependencies of collection type */
        case DB_COLLECTION:
            switch(db_collection(o)->kind) {
            case DB_ARRAY:
            case DB_SEQUENCE:
            case DB_LIST:
                if (db_genTypeCollectionDependencies(db_collection(o), allowDeclared, recursion, data)) {
                    goto error;
                }
                break;
            case DB_MAP:
                if (db_genTypeMapDependencies(db_map(o), allowDeclared, recursion, data)) {
                    goto error;
                }
                break;
            }
            break;
        default:
            db_error("db_genTypeDependencies: typeKind '%s' not handled by code-generator.", db_nameof(db_enum_constant(db_typeKind_o, db_type(t)->kind)));
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

/* Resolve dependencies for procedures.
 *   Only the anonymous dependencies are resolved. Procedures usually do not
 *   introduce extra dependencies because they can only use the types that
 *   are defined, and do not introduce new types for themselves (thus also
 *   not introducing dependencies). The only exception is the usage of
 *   anonymous types, which can be 'declared' in argumentlists and returnTypes.
 *   This function will make sure that these anonymous types are also forwarded
 *   to the generator. */
static int db_genTypeProcedureDependencies(db_function o, db_genTypeWalk_t* data) {
    db_uint32 i;
    if (o->returnType && !db_checkAttr(o->returnType, DB_ATTR_SCOPED)) {
        if (db_genTypeParse(o->returnType, TRUE, NULL, data)) {
            goto error;
        }
    }

    for(i=0; i<o->parameters.length; i++) {
        if (!db_checkAttr(o->parameters.buffer[i].type, DB_ATTR_SCOPED)) {
            if (db_genTypeParse(o->parameters.buffer[i].type, TRUE, NULL, data)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

/* Parse object */
static int db_genTypeParse(db_object o, db_bool allowDeclared, db_bool* recursion, db_genTypeWalk_t* data) {

    if (recursion) {
        *recursion = FALSE;
    }

    /* Check if object is valid */
    if (!db_checkState(o, DB_VALID)) {
        db_id id;
        db_error("db_genTypeParse: scope '%s' contains invalid objects (%s).", db_nameof(g_getCurrent(data->g)), db_fullname(o, id));
        return 1;
    }

    /* If object is procedure, parse dependencies, but do not declare\define. */
    if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
        db_genTypeProcedureDependencies(db_function(o), data);
    } else
    /* Check if object is defined - declared objects are allowed only for procedure objects. */
    if (!db_checkState(o, DB_DEFINED)) {
        db_id id;
        db_error("db_genTypeParse: scope '%s' contains undefined objects (%s).", db_nameof(g_getCurrent(data->g)), db_fullname(o, id));
        return 1;
    }

    /* Only parse if type has not yet been parsed. */
    if (g_mustParse(data->g, o) && !db_genTypeIsParsed(o, data)) {
        /* Only generate code for types */
        if (db_class_instanceof(db_typedef_o, o)) {
            struct db_genTypeDeclaration* decl;

            /* Detect cycles */
            if ((decl = db_genTypeIsDeclared(o, data)) && (decl->parsing)) {
                if (!allowDeclared) {
                    /* If caller handles recursion, report that recursion has occurred. */
                    if (recursion) {
						db_trace("recursion has occurred!");
                        *recursion = TRUE;
                        goto recursion;
                    } else {
                        /* If caller does not handle recursion, report an error. */
                        db_id id;
                        db_error("db_genTypeParse: invalid recursion for type '%s'", db_fullname(o, id));
                        goto error;
                    }
                } else {
                    /* Print forward declaration */
                    if (!decl->printed) {
                        /* Write end-of-line and comment with name before each definition */
                        if (data->onDeclare(o, data->userData)) {
                            goto error;
                        }
                        decl->printed = TRUE;
                    }
                }
            } else {
                db_bool recurCheck;
                db_genTypeDeclaration* decl;

                recurCheck = FALSE;

                /* Declare type, this allows the serializer to detect recursive references. */
                if (!(decl = db_genTypeIsDeclared(o, data))) {
                	decl = db_genTypeDeclared(o, data);
                }
                decl->parsing = TRUE;

                /* Serialize dependencies for type first */
                if (db_genTypeDependencies(o, allowDeclared, &recurCheck, data)) {
                    goto error;
                }

                /* Can only write type when no recursion-error has occurred. */
                if (!recurCheck) {

                    /* If an typedef object equals it's real pointer, than it's the type itself. Otherwise it
                     * is a typedef. */
                    if (db_typedef(o)->real != o) {
                    	if (data->onDefine(o, data->userData)) goto error;
                    } else {
                    	switch(db_typedef(o)->real->kind) {
                    	case DB_COMPOSITE:
                    		/* Composite types must be forward-declared */
                    		if (!decl->printed) {
                    			if (data->onDeclare(o, data->userData)) goto error;
                    		}
                    		/* no break */
                    	default:
                    		if (data->onDefine(o, data->userData)) goto error;
                    		break;
                    	}
                    }

                    /* Mark object as parsed */
                    db_genTypeParsed(o, data);
                } else {
                    /* Un-declare type, so new attempts to generate it will not generate recursion errors! */
                    decl->parsing = FALSE;

                    /* Propagate recursion */
                    if (recursion) {
                        *recursion = recurCheck;
                    } else {
                        /* Recursion has not been catched in time. */
                        db_id id;
                        db_error("db_genTypeParse: recursion not handled for type '%s'", db_fullname(o, id));
                        goto error;
                    }
                }
            }
        }
    }

recursion:
    return 0;
error:
    return -1;
}

/* Walk objects, forward typedefs and types */
static int db_genTypeWalk(db_object o, void* userData) {
	return !db_genTypeParse(o, FALSE, NULL, userData);
}

/* Generator main */
int db_genTypeDepWalk(db_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData) {
	db_genTypeWalk_t walkData;
	struct db_genTypeDeclaration* decl;

	/* Prepare walkdata, open headerfile */
	walkData.g = g;
	walkData.parsed = db_llNew();
	walkData.declared = db_llNew();
	walkData.onDeclare = onDeclare;
	walkData.onDefine = onDefine;
	walkData.userData = userData;

	/* Walk objects */
	if (!g_walkRecursive(g, db_genTypeWalk, &walkData)) {
	    goto error;
	}

	/* Free parsed-list */
	db_llFree(walkData.parsed);

	while((decl = db_llTakeFirst(walkData.declared))) {
	    db_dealloc(decl);
	}
	db_llFree(walkData.declared);

	return 0;
error:
    return -1;
}
