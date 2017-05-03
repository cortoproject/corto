/*
 * g_generatorTypeDepWalk.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "corto/g/g.h"

#ifdef CORTO_GENERATOR

typedef struct corto_genTypeWalk_t {
    g_generator g;
    corto_ll parsed; /* List of parsed types */
    corto_ll declared; /* List of declared objects */
    g_walkAction onDeclare;
    g_walkAction onDefine;
    void* userData;
}corto_genTypeWalk_t;

static int corto_genTypeParse(corto_object o, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data);

/* Mark type as parsed */
static void corto_genTypeParsed(corto_object o, corto_genTypeWalk_t* data) {
    corto_llInsert(data->parsed, o);
}

/* Mark object as declared */
typedef struct corto_genTypeDeclaration {
    corto_object o;
    corto_bool printed; /* If true, a forward declaration is printed in generated code. */
    corto_bool parsing; /* If true, then the object is currently being parsed and recursive
                        references can be checked. If false, this object only serves to
                        prevent re-declaring an object. */
}corto_genTypeDeclaration;

static corto_genTypeDeclaration* corto_genTypeDeclared(corto_object o, corto_genTypeWalk_t* data) {
    struct corto_genTypeDeclaration* decl;

    /* Insert declaration object */
    decl = corto_alloc(sizeof(struct corto_genTypeDeclaration));
    decl->o = o;
    decl->printed = FALSE;
    decl->parsing = FALSE;
    corto_llInsert(data->declared, decl);

    return decl;
}

/* Compare two types structurally */
static corto_bool corto_genTypeCompareStructural(corto_type t1, corto_type t2) {
    corto_bool result;
    result = FALSE;
    if (t1->kind == t2->kind) {
        switch(t1->kind) {
        case CORTO_PRIMITIVE:
            if (corto_primitive(t1)->kind == corto_primitive(t2)->kind) {
                if (corto_primitive(t1)->width == corto_primitive(t2)->width) {
                    result = TRUE;
                }
            }
            break;
        case CORTO_COLLECTION:
            if (corto_collection(t1)->kind == corto_collection(t2)->kind) {
                if (corto_collection(t1)->elementType == corto_collection(t2)->elementType) {
                    if (corto_collection(t1)->max == corto_collection(t2)->max) {
                        if (corto_collection(t1)->kind != CORTO_MAP) {
                            result = TRUE;
                        } else {
                            if (corto_map(t1)->keyType != corto_map(t2)->keyType) {
                                result = TRUE;
                            }
                        }
                    }
                }
            }
            break;
        default:
            corto_seterr("only primitive and collection types can be compared structurally.");
            break;
        }
    }
    return result;
}

/* Find type in parsed-list */
static corto_bool corto_genTypeIsParsed(corto_object o, corto_genTypeWalk_t* data) {
    corto_iter iter;
    corto_object p;
    corto_bool found;

    p = NULL;
    found = FALSE;

    iter = corto_llIter(data->parsed);
    while(!found && corto_iter_hasNext(&iter)) {
        p = corto_iter_next(&iter);
        /* If object is scoped, it must be matched exactly */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            if (o == p) {
                found = TRUE;
            }
        /* If object is not scoped (anonymous), it is matched structurally */
        } else {
            if (!corto_checkAttr(p, CORTO_ATTR_SCOPED)) {
                if (corto_typeof(o) == corto_typeof(p)) {
                    if (corto_genTypeCompareStructural(o, p)) {
                        found = TRUE;
                    }
                }
            }
        }
    }

    return found;
}

/* Find type in declared-list */
static struct corto_genTypeDeclaration* corto_genTypeIsDeclared(corto_object o, corto_genTypeWalk_t* data) {
    corto_iter iter;
    struct corto_genTypeDeclaration* p;

    p = NULL;
    iter = corto_llIter(data->declared);
    while(corto_iter_hasNext(&iter)) {
        p = corto_iter_next(&iter);
        if (o == p->o) {
            break;
        }
    }

    return p ? (o == p->o) ? p : NULL : NULL;
}

/* Resolve any-dependencies */
static int corto_genTypeAnyDependencies(corto_type t, corto_genTypeWalk_t* data) {
    corto_genTypeDeclaration* decl;

    CORTO_UNUSED(t);

    /* Any has a dependency on type */
    if (!(decl = corto_genTypeIsDeclared(corto_type_o, data))) {
        decl = corto_genTypeDeclared(corto_type_o, data);
    }

    if (!decl->printed) {
        /* Print forward declaration */
        if (data->onDeclare) {
            if (g_mustParse(data->g, corto_type_o) &&
                data->onDeclare(corto_type_o, data->userData)) {
                goto error;
            }
        }
        decl->printed = TRUE;
    }

    /* Any has a dependency on bool */
    if (!(decl = corto_genTypeIsDeclared(corto_bool_o, data))) {
        decl = corto_genTypeDeclared(corto_bool_o, data);
    }

    if (!decl->printed) {
        corto_bool recursion = FALSE;
        /* Print forward declaration */
        if (corto_genTypeParse(t, FALSE, &recursion, data)) {
            goto error;
        }
        decl->printed = TRUE;
    }

    return 0;
error:
    return -1;
}

/* Resolve class dependencies */
static int corto_genTypeInterfaceDependencies(corto_interface t, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {
    corto_uint32 i;
    corto_member m;
    corto_bool declAllowed;

    /* Serialize base for structs, discriminator types for unions */
    if (corto_class_instanceof(corto_struct_o, t)) {
        if (corto_interface(t)->base)  {
            if (corto_genTypeParse(corto_type(corto_interface(t)->base), FALSE, recursion, data)) {
                goto error;
            }

            /* If recursion occurred, this type cannot be parsed (yet). */
            if (recursion && *recursion) {
                goto recursion;
            }
        }
    } else if (corto_typeof(t) == corto_type(corto_union_o)) {
      if (corto_genTypeParse(corto_type(corto_union(t)->discriminator), FALSE, recursion, data)) {
          goto error;
      }
    }

    /* Walk members of composite type */
    for(i=0; i<t->members.length; i++) {
        m = t->members.buffer[i];
        declAllowed = m->type->reference ? TRUE : allowDeclared;
        if (corto_genTypeParse(m->type, declAllowed, recursion, data)) {
            goto error;
        }

        /* If recursion occurred and a declaration is allowed, forward declare type and turn off recursion. */
        if (recursion && *recursion) {
            corto_genTypeDeclaration* decl;
            *recursion = FALSE;

            /* Mark the object as declared, printed and not parsing. */
            if (!(decl = corto_genTypeIsDeclared(m->type, data))) {
                decl = corto_genTypeDeclared(m->type, data);
            }

            if (!decl->printed && g_mustParse(data->g, m->type)) {
                /* Print forward declaration */
                if (data->onDeclare) {
                    if (data->onDeclare(m->type, data->userData)) {
                        goto error;
                    }
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
static int corto_genTypeCollectionDependencies(corto_collection t, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {
    if (t->kind != CORTO_ARRAY) {
        allowDeclared = TRUE;
    }
    return corto_genTypeParse(t->elementType, allowDeclared, recursion, data);
}

/* Resolve map dependencies */
static int corto_genTypeMapDependencies(corto_map t, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {
    CORTO_UNUSED(allowDeclared);

    /* Serialize collection dependencies */
    if (corto_genTypeCollectionDependencies(corto_collection(t), allowDeclared, recursion, data)) {
        goto error;
    }

    /* Serialize keyType */
    if (corto_genTypeParse(t->keyType, TRUE, recursion, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Resolve iterator dependencies */
static int corto_genTypeIteratorDependencies(corto_iterator t, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {
    CORTO_UNUSED(allowDeclared);

    /* Serialize elementType */
    if (corto_genTypeParse(t->elementType, TRUE, recursion, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Serialize dependencies of a type */
static int corto_genTypeDependencies(corto_object o, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {
    corto_type t;

    t = corto_type(o);

    switch(corto_type(t)->kind) {
    case CORTO_VOID:
        /* Void types can't have dependencies */
        break;

    case CORTO_ANY:
        if (corto_genTypeAnyDependencies(corto_type(o), data)) {
            goto error;
        }
        break;

    /* Primitives can't have dependencies */
    case CORTO_PRIMITIVE:
        break;

    /* Serialize dependencies of composite type */
    case CORTO_COMPOSITE:
        switch(corto_interface(o)->kind) {
        case CORTO_STRUCT:
        case CORTO_UNION:
        case CORTO_INTERFACE:
        case CORTO_CLASS:
        case CORTO_DELEGATE:
        case CORTO_PROCEDURE:
            if (corto_genTypeInterfaceDependencies(corto_interface(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        }
        break;

    /* Serialize dependencies of collection type */
    case CORTO_COLLECTION:
        switch(corto_collection(o)->kind) {
        case CORTO_ARRAY:
        case CORTO_SEQUENCE:
        case CORTO_LIST:
            if (corto_genTypeCollectionDependencies(corto_collection(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        case CORTO_MAP:
            if (corto_genTypeMapDependencies(corto_map(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        }
        break;
    case CORTO_ITERATOR:
        if (corto_genTypeIteratorDependencies(corto_iterator(o), allowDeclared, recursion, data)) {
            goto error;
        }
        break;
    default:
        corto_seterr("typeKind '%s' not handled by code-generator.", corto_idof(corto_enum_constant(corto_typeKind_o, corto_type(t)->kind)));
        goto error;
        break;
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
static int corto_genTypeProcedureDependencies(corto_function o, corto_genTypeWalk_t* data) {
    corto_uint32 i;
    if (o->returnType && !corto_checkAttr(o->returnType, CORTO_ATTR_SCOPED)) {
        if (corto_genTypeParse(o->returnType, TRUE, NULL, data)) {
            goto error;
        }
    }

    for(i=0; i<o->parameters.length; i++) {
        if (!corto_checkAttr(o->parameters.buffer[i].type, CORTO_ATTR_SCOPED)) {
            if (corto_genTypeParse(o->parameters.buffer[i].type, TRUE, NULL, data)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

/* Parse object */
static int corto_genTypeParse(corto_object o, corto_bool allowDeclared, corto_bool* recursion, corto_genTypeWalk_t* data) {

    if (recursion) {
        *recursion = FALSE;
    }

    /* Check if object is valid */
    if (!corto_checkState(o, CORTO_VALID)) {
        corto_seterr("%s has invalid objects (%s).",
            corto_fullpath(NULL, g_getCurrent(data->g)),
            corto_fullpath(NULL, o));
        return 1;
    }

    /* Check if the object has an anonymous type */
    if (!corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
        if (corto_genTypeParse(corto_typeof(o), TRUE, NULL, data)) {
            goto error;
        }
    }

    /* If object is procedure, parse dependencies, but do not declare\define. */
    if (corto_instanceof(corto_procedure_o, corto_typeof(o))) {
        corto_genTypeProcedureDependencies(corto_function(o), data);
    } else
    /* Check if object is defined - declared objects are allowed only for procedure objects. */
    if (corto_instanceof(corto_type_o, o) && !corto_checkState(o, CORTO_DEFINED)) {
        corto_seterr("%s has undefined objects (%s).",
            corto_fullpath(NULL, g_getCurrent(data->g)),
            corto_fullpath(NULL, o));
        return 1;
    }

    /* Only parse if type has not yet been parsed. */
    if (g_mustParse(data->g, o) && !corto_genTypeIsParsed(o, data)) {
        /* Only generate code for types */
        if (corto_class_instanceof(corto_type_o, o)) {
            struct corto_genTypeDeclaration* decl;

            /* Detect cycles */
            if ((decl = corto_genTypeIsDeclared(o, data)) && (decl->parsing)) {
                if (!allowDeclared) {
                    /* If caller handles recursion, report that recursion has occurred. */
                    if (recursion) {
                        *recursion = TRUE;
                        goto recursion;
                    } else {
                        /* If caller does not handle recursion, report error. */
                        corto_seterr("invalid recursion for type '%s'",
                            corto_fullpath(NULL, o));
                        goto error;
                    }
                } else {
                    /* Print forward declaration */
                    if (!decl->printed && g_mustParse(data->g, o)) {
                        /* Write end-of-line and comment with name before each definition */
                        if (data->onDeclare) {
                            if (data->onDeclare(o, data->userData)) {
                                goto error;
                            }
                        }
                        decl->printed = TRUE;
                    }
                }
            } else {
                corto_bool recurCheck;
                corto_genTypeDeclaration* decl;

                recurCheck = FALSE;

                /* Declare type, this allows the serializer to detect recursive references. */
                if (!(decl = corto_genTypeIsDeclared(o, data))) {
                    decl = corto_genTypeDeclared(o, data);
                }
                decl->parsing = TRUE;

                /* Serialize dependencies for type first */
                if (corto_genTypeDependencies(o, allowDeclared, &recurCheck, data)) {
                    goto error;
                }

                /* Can only write type when no recursion-error has occurred. */
                if (!recurCheck) {

                    /* If an typedef object equals it's real pointer, than it's the type itself. Otherwise it
                     * is a typedef. */
                    if (corto_type(o) != o) {
                        if (data->onDefine) {
                            if (data->onDefine(o, data->userData)) goto error;
                        }
                    } else {
                        switch(corto_type(o)->kind) {
                        case CORTO_COMPOSITE:
                            /* Composite types must be forward-declared */
                            if (!decl->printed) {
                                if (data->onDeclare) {
                                    if (data->onDeclare(o, data->userData)) {
                                        goto error;
                                    }
                                }
                            }
                            /* no break */
                        default:
                            if (data->onDefine) {
                                if (data->onDefine(o, data->userData)) {
                                    goto error;
                                }
                            }
                            break;
                        }
                    }

                    /* Mark object as parsed */
                    corto_genTypeParsed(o, data);
                } else {
                    /* Un-declare type, so new attempts to generate it will not generate recursion errors! */
                    decl->parsing = FALSE;

                    /* Propagate recursion */
                    if (recursion) {
                        *recursion = recurCheck;
                    } else {
                        /* Recursion has not been catched in time. */
                        corto_seterr("recursion not handled for type '%s'",
                            corto_fullpath(NULL, o));
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
static int corto_genTypeWalk(corto_object o, void* userData) {
    return !corto_genTypeParse(o, FALSE, NULL, userData);
}

/* Generator main */
int corto_genTypeDepWalk(g_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData) {
    corto_genTypeWalk_t walkData;
    struct corto_genTypeDeclaration* decl;

    /* Prepare walkdata, open headerfile */
    walkData.g = g;
    walkData.parsed = corto_llNew();
    walkData.declared = corto_llNew();
    walkData.onDeclare = onDeclare;
    walkData.onDefine = onDefine;
    walkData.userData = userData;

    /* Walk objects */
    if (!g_walkRecursive(g, corto_genTypeWalk, &walkData)) {
        goto error;
    }

    /* Free parsed-list */
    corto_llFree(walkData.parsed);

    while((decl = corto_llTakeFirst(walkData.declared))) {
        corto_dealloc(decl);
    }
    corto_llFree(walkData.declared);

    return 0;
error:
    return -1;
}

#endif
