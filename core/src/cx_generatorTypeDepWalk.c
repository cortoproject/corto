/*
 * cx_generatorTypeDepWalk.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "corto.h"
#include "cx_generatorTypeDepWalk.h"

#ifdef CX_GENERATOR

typedef struct cx_genTypeWalk_t {
    cx_generator g;
    cx_ll parsed; /* List of parsed types */
    cx_ll declared; /* List of declared objects */
    g_walkAction onDeclare;
    g_walkAction onDefine;
    void* userData;
}cx_genTypeWalk_t;

static int cx_genTypeParse(cx_object o, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data);

/* Mark type as parsed */
static void cx_genTypeParsed(cx_object o, cx_genTypeWalk_t* data) {
    cx_llInsert(data->parsed, o);
}

/* Mark object as declared */
typedef struct cx_genTypeDeclaration {
    cx_object o;
    cx_bool printed; /* If true, a forward declaration is printed in generated code. */
    cx_bool parsing; /* If true, then the object is currently being parsed and recursive
                        references can be checked. If false, this object only serves to
                        prevent re-declaring an object. */
}cx_genTypeDeclaration;

static cx_genTypeDeclaration* cx_genTypeDeclared(cx_object o, cx_genTypeWalk_t* data) {
    struct cx_genTypeDeclaration* decl;

    /* Insert declaration object */
    decl = cx_alloc(sizeof(struct cx_genTypeDeclaration));
    decl->o = o;
    decl->printed = FALSE;
    decl->parsing = FALSE;
    cx_llInsert(data->declared, decl);

    return decl;
}

/* Compare two types structurally */
static cx_bool cx_genTypeCompareStructural(cx_type t1, cx_type t2) {
    cx_bool result;
    result = FALSE;
    if (t1->kind == t2->kind) {
        switch(t1->kind) {
        case CX_PRIMITIVE:
            if (cx_primitive(t1)->kind == cx_primitive(t2)->kind) {
                if (cx_primitive(t1)->width == cx_primitive(t2)->width) {
                    result = TRUE;
                }
            }
            break;
        case CX_COLLECTION:
            if (cx_collection(t1)->kind == cx_collection(t2)->kind) {
                if (cx_collection(t1)->elementType == cx_collection(t2)->elementType) {
                    if (cx_collection(t1)->max == cx_collection(t2)->max) {
                        if (cx_collection(t1)->kind != CX_MAP) {
                            result = TRUE;
                        } else {
                            if (cx_map(t1)->keyType != cx_map(t2)->keyType) {
                                result = TRUE;
                            }
                        }
                    }
                }
            }
            break;
        default:
            cx_error("genTypeCompareStructural: only primitive and collection types can be compared structurally.");
            break;
        }
    }
    return result;
}

/* Find type in parsed-list */
static cx_bool cx_genTypeIsParsed(cx_object o, cx_genTypeWalk_t* data) {
    cx_iter iter;
    cx_object p;
    cx_bool found;

    p = NULL;
    found = FALSE;

    iter = cx_llIter(data->parsed);
    while(!found && cx_iterHasNext(&iter)) {
        p = cx_iterNext(&iter);
        /* If object is scoped, it must be matched exactly */
        if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
            if (o == p) {
                found = TRUE;
            }
        /* If object is not scoped (anonymous), it is matched structurally */
        } else {
            if (cx_typeof(o) == cx_typeof(p)) {
                if (cx_genTypeCompareStructural(o, p)) {
                    found = TRUE;
                }
            }
        }
    }

    return found;
}

/* Find type in declared-list */
static struct cx_genTypeDeclaration* cx_genTypeIsDeclared(cx_object o, cx_genTypeWalk_t* data) {
    cx_iter iter;
    struct cx_genTypeDeclaration* p;

    p = NULL;
    iter = cx_llIter(data->declared);
    while(cx_iterHasNext(&iter)) {
        p = cx_iterNext(&iter);
        if (o == p->o) {
            break;
        }
    }

    return p ? (o == p->o) ? p : NULL : NULL;
}

/* Resolve any-dependencies */
static int cx_genTypeAnyDependencies(cx_type t, cx_genTypeWalk_t* data) {
    cx_genTypeDeclaration* decl;

    CX_UNUSED(t);

    /* Any has a dependency on type */
    if (!(decl = cx_genTypeIsDeclared(cx_type_o, data))) {
        decl = cx_genTypeDeclared(cx_type_o, data);
    }

    if (!decl->printed) {
        /* Print forward declaration */
        if (data->onDeclare(cx_type_o, data->userData)) {
            goto error;
        }
        decl->printed = TRUE;
    }

    /* Any has a dependency on bool */
    if (!(decl = cx_genTypeIsDeclared(cx_bool_o, data))) {
        decl = cx_genTypeDeclared(cx_bool_o, data);
    }

    if (!decl->printed) {
        cx_bool recursion = FALSE;
        /* Print forward declaration */
        if (cx_genTypeParse(t, FALSE, &recursion, data)) {
            goto error;
        }
        decl->printed = TRUE;
    }

    return 0;
error:
    return -1;
}

/* Resolve class dependencies */
static int cx_genTypeInterfaceDependencies(cx_interface t, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {
    cx_uint32 i;
    cx_member m;
    cx_bool declAllowed;

    /* Serialize base */
    if (cx_interface(t)->base)  {
        if (cx_genTypeParse(cx_type(cx_interface(t)->base), FALSE, recursion, data)) {
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
        declAllowed = m->type->reference ? TRUE : allowDeclared;
        if (cx_genTypeParse(m->type, declAllowed, recursion, data)) {
            goto error;
        }

        /* If recursion occurred and a declaration is allowed, forward declare type and turn of recursion. */
        if (recursion && *recursion) {
            cx_genTypeDeclaration* decl;
            *recursion = FALSE;

            /* Mark the object as declared, printed and not parsing. */
            if (!(decl = cx_genTypeIsDeclared(m->type, data))) {
                decl = cx_genTypeDeclared(m->type, data);
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
static int cx_genTypeCollectionDependencies(cx_collection t, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {
    if (t->kind != CX_ARRAY) {
        allowDeclared = TRUE;
    }
    return cx_genTypeParse(t->elementType, allowDeclared, recursion, data);
}

/* Resolve map dependencies */
static int cx_genTypeMapDependencies(cx_map t, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {
    CX_UNUSED(allowDeclared);

    /* Serialize collection dependencies */
    if (cx_genTypeCollectionDependencies(cx_collection(t), allowDeclared, recursion, data)) {
        goto error;
    }

    /* Serialize keyType */
    if (cx_genTypeParse(t->keyType, TRUE, recursion, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Resolve iterator dependencies */
static int cx_genTypeIteratorDependencies(cx_iterator t, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {
    CX_UNUSED(allowDeclared);

    /* Serialize elementType */
    if (cx_genTypeParse(t->elementType, TRUE, recursion, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Serialize dependencies of a type */
static int cx_genTypeDependencies(cx_object o, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {
    cx_type t;

    t = cx_type(o);

    switch(cx_type(t)->kind) {
    case CX_VOID:
        /* Void types can't have dependencies */
        break;

    case CX_ANY:
        if (cx_genTypeAnyDependencies(cx_type(o), data)) {
            goto error;
        }
        break;

    /* Primitives can't have dependencies */
    case CX_PRIMITIVE:
        break;

    /* Serialize dependencies of composite type */
    case CX_COMPOSITE:
        switch(cx_interface(o)->kind) {
        case CX_STRUCT:
        case CX_INTERFACE:
        case CX_CLASS:
        case CX_DELEGATE:
        case CX_PROCEDURE:
            if (cx_genTypeInterfaceDependencies(cx_interface(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        }
        break;

    /* Serialize dependencies of collection type */
    case CX_COLLECTION:
        switch(cx_collection(o)->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
        case CX_LIST:
            if (cx_genTypeCollectionDependencies(cx_collection(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        case CX_MAP:
            if (cx_genTypeMapDependencies(cx_map(o), allowDeclared, recursion, data)) {
                goto error;
            }
            break;
        }
        break;
    case CX_ITERATOR:
        if (cx_genTypeIteratorDependencies(cx_iterator(o), allowDeclared, recursion, data)) {
            goto error;
        }
        break;
    default:
        cx_error("cx_genTypeDependencies: typeKind '%s' not handled by code-generator.", cx_nameof(cx_enum_constant(cx_typeKind_o, cx_type(t)->kind)));
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
static int cx_genTypeProcedureDependencies(cx_function o, cx_genTypeWalk_t* data) {
    cx_uint32 i;
    if (o->returnType && !cx_checkAttr(o->returnType, CX_ATTR_SCOPED)) {
        if (cx_genTypeParse(o->returnType, TRUE, NULL, data)) {
            goto error;
        }
    }

    for(i=0; i<o->parameters.length; i++) {
        if (!cx_checkAttr(o->parameters.buffer[i].type, CX_ATTR_SCOPED)) {
            if (cx_genTypeParse(o->parameters.buffer[i].type, TRUE, NULL, data)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

/* Parse object */
static int cx_genTypeParse(cx_object o, cx_bool allowDeclared, cx_bool* recursion, cx_genTypeWalk_t* data) {

    if (recursion) {
        *recursion = FALSE;
    }

    /* Check if object is valid */
    if (!cx_checkState(o, CX_VALID)) {
        cx_id id;
        cx_error("typedepwalk: scope '%s' contains invalid objects (%s).", cx_nameof(g_getCurrent(data->g)), cx_fullname(o, id));
        return 1;
    }

    /* If object is procedure, parse dependencies, but do not declare\define. */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
        cx_genTypeProcedureDependencies(cx_function(o), data);
    } else
    /* Check if object is defined - declared objects are allowed only for procedure objects. */
    if (!cx_checkState(o, CX_DEFINED)) {
        cx_id id;
        cx_error("typedepwalk: scope '%s' contains undefined objects (%s).", cx_nameof(g_getCurrent(data->g)), cx_fullname(o, id));
        return 1;
    }

    /* Only parse if type has not yet been parsed. */
    if (g_mustParse(data->g, o) && !cx_genTypeIsParsed(o, data)) {
        /* Only generate code for types */
        if (cx_class_instanceof(cx_type_o, o)) {
            struct cx_genTypeDeclaration* decl;

            /* Detect cycles */
            if ((decl = cx_genTypeIsDeclared(o, data)) && (decl->parsing)) {
                if (!allowDeclared) {
                    /* If caller handles recursion, report that recursion has occurred. */
                    if (recursion) {
                        *recursion = TRUE;
                        goto recursion;
                    } else {
                        /* If caller does not handle recursion, report an error. */
                        cx_id id;
                        cx_error("typedepwalk: invalid recursion for type '%s'", cx_fullname(o, id));
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
                cx_bool recurCheck;
                cx_genTypeDeclaration* decl;

                recurCheck = FALSE;

                /* Declare type, this allows the serializer to detect recursive references. */
                if (!(decl = cx_genTypeIsDeclared(o, data))) {
                    decl = cx_genTypeDeclared(o, data);
                }
                decl->parsing = TRUE;

                /* Serialize dependencies for type first */
                if (cx_genTypeDependencies(o, allowDeclared, &recurCheck, data)) {
                    goto error;
                }

                /* Can only write type when no recursion-error has occurred. */
                if (!recurCheck) {

                    /* If an typedef object equals it's real pointer, than it's the type itself. Otherwise it
                     * is a typedef. */
                    if (cx_type(o) != o) {
                        if (data->onDefine(o, data->userData)) goto error;
                    } else {
                        switch(cx_type(o)->kind) {
                        case CX_COMPOSITE:
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
                    cx_genTypeParsed(o, data);
                } else {
                    /* Un-declare type, so new attempts to generate it will not generate recursion errors! */
                    decl->parsing = FALSE;

                    /* Propagate recursion */
                    if (recursion) {
                        *recursion = recurCheck;
                    } else {
                        /* Recursion has not been catched in time. */
                        cx_id id;
                        cx_error("typedepwalk: recursion not handled for type '%s'", cx_fullname(o, id));
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
static int cx_genTypeWalk(cx_object o, void* userData) {
    return !cx_genTypeParse(o, FALSE, NULL, userData);
}

/* Generator main */
int cx_genTypeDepWalk(cx_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData) {
    cx_genTypeWalk_t walkData;
    struct cx_genTypeDeclaration* decl;

    /* Prepare walkdata, open headerfile */
    walkData.g = g;
    walkData.parsed = cx_llNew();
    walkData.declared = cx_llNew();
    walkData.onDeclare = onDeclare;
    walkData.onDefine = onDefine;
    walkData.userData = userData;

    /* Walk objects */
    if (!g_walkRecursive(g, cx_genTypeWalk, &walkData)) {
        goto error;
    }

    /* Free parsed-list */
    cx_llFree(walkData.parsed);

    while((decl = cx_llTakeFirst(walkData.declared))) {
        cx_dealloc(decl);
    }
    cx_llFree(walkData.declared);

    return 0;
error:
    return -1;
}

#endif

