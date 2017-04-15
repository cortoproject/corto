/*
 * g_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#include "corto/g/g.h"

#ifdef CORTO_GENERATOR

int corto_genDepBuildAction(corto_object o, void* userData);

/* Walk objects in correct dependency order. */
typedef struct g_itemWalk_t *g_itemWalk_t;
struct g_itemWalk_t {
    g_generator g;
    void *userData;
    corto_depresolver resolver;
    corto_bool bootstrap;
    corto_depresolver_action onDeclare;
    corto_depresolver_action onDefine;
    corto_ll anonymousObjects;
};

typedef struct g_depWalk_t* g_depWalk_t;
struct g_depWalk_t  {
    corto_object o;
    g_itemWalk_t data;
    corto_ll anonymousObjects;
};

corto_object corto_genDepFindAnonymous(g_depWalk_t data, corto_object o) {
    corto_object result = o;

    if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (!data->anonymousObjects) {
            data->anonymousObjects = corto_llNew();
        }

        corto_iter iter = corto_llIter(data->anonymousObjects);
        while (corto_iterHasNext(&iter)) {
            corto_object a = corto_iterNext(&iter);
            if (corto_compare(o, a) == CORTO_EQ) {
                result = a;
                break;
            }
        }

        if (o == result) {
            corto_llAppend(data->anonymousObjects, o);
        }
    }

    return result;
}

/* Serialize dependencies on references */
corto_int16 corto_genDepReference(corto_serializer s, corto_value* info, void* userData) {
    corto_object o = *(corto_object*)corto_value_getPtr(info);
    g_depWalk_t data = userData;

    CORTO_UNUSED(s);

    if (o && g_mustParse(data->data->g, o)) {
        corto_member m;

        m = NULL;

        if (info->kind == CORTO_MEMBER) {
            m = info->is.member.t;
            if (!m->type->reference) {
                m = NULL;
            }
        }

        /* Include dependencies on anonymous types */
        if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            /* Look for equivalent anonymous objects. Since anonymous objects do
             * not have their own identity, they are equal if they have the same
             * value. Therefore, if multiple anonymous objects are found with
             * the same value, only insert it once in the dependency administration.
             */
            o = corto_genDepFindAnonymous(data, o);
            corto_genDepBuildAction(o, data->data);
        }

        /* Add dependency on item */
        if (m) {
            corto_state state = m->state;
            if (m->stateCondExpr) {
                corto_value v = corto_value_object(o, NULL);
                corto_value out;

                if (corto_value_getMember(&v, m->stateCondExpr, &out)) {
                    corto_seterr("invalid stateCondExpr '%s' for member '%s'",
                        m->stateCondExpr,
                        corto_fullpath(NULL, m));
                    goto error;
                }

                if (corto_value_getType(&out) != corto_type(corto_bool_o)) {
                    if (corto_value_cast(&out, corto_bool_o, &out)) {
                        corto_seterr("stateCondExpr '%s' of member '%s' is not castable to a boolean",
                            m->stateCondExpr,
                            corto_fullpath(NULL, m));
                        goto error;
                    }
                }

                corto_bool *result = corto_value_getPtr(&out);

                if (!*result) {
                    switch(state) {
                    case CORTO_DECLARED | CORTO_DEFINED:
                        state = CORTO_DEFINED;
                        break;
                    case CORTO_DECLARED:
                        state = CORTO_DEFINED;
                        break;
                    case CORTO_DEFINED:
                        state = CORTO_DECLARED;
                        break;
                    }
                }
            }
            corto_depresolver_depend(data->data->resolver, data->o, CORTO_DEFINED, o, state);
        } else {
            corto_depresolver_depend(data->data->resolver, data->o, CORTO_DEFINED, o, CORTO_DEFINED);
        }
    }

    return 0;
error:
    return -1;
}

/* Dependency serializer */
struct corto_serializer_s corto_genDepSerializer(void) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);
    s.reference = corto_genDepReference;
    s.access = CORTO_LOCAL;
    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Add dependencies for function arguments */
static int corto_genDepBuildProc(corto_function f, struct g_depWalk_t* data) {
    corto_uint32 i;
    corto_type t;

    for(i=0; i<f->parameters.length; i++) {
        t = f->parameters.buffer[i].type;
        if (g_mustParse(data->data->g, t)) {
            t = corto_genDepFindAnonymous(data, t);
            corto_depresolver_depend(data->data->resolver, f, CORTO_DECLARED, t, CORTO_DECLARED | CORTO_DEFINED); /* The type must be at least declared when the function is declared. */
        }
    }

    return 0;
}

/* Build dependency-administration for object */
int corto_genDepBuildAction(corto_object o, void* userData) {
    g_itemWalk_t data;
    struct g_depWalk_t walkData;
    struct corto_serializer_s s;
    int result;
    corto_object parent = NULL;

    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        parent = corto_parentof(o);
    }

    data = userData;

    walkData.o = o;
    walkData.data = data;
    walkData.anonymousObjects = data->anonymousObjects;

    /* If object a builtin package, signal that a bootstrap is found, indicating
     * that dependencies should be disregarded. */
    if (corto_isBuiltinPackage(o)) {
        data->bootstrap = TRUE;
        result = 0;
    } else {
        /* Insert type-dependency: object can be declared only after it's type is defined. */
        if (g_mustParse(data->g, corto_typeof(o))) {
            corto_type t = corto_genDepFindAnonymous(&walkData, corto_typeof(o));
            corto_depresolver_depend(data->resolver, o, CORTO_DECLARED, t, CORTO_DEFINED);
        }

        /* TODO: this is not nice */
        if (corto_class_instanceof(corto_procedure_o, corto_typeof(o))) {
            /* Insert base-dependency: methods may only be declared after the base of a class has been defined. */
            if (corto_typeof(o) != corto_type(corto_function_o)) {
                if (corto_class_instanceof(corto_class_o, parent) && corto_interface(parent)->base) {
                    if (g_mustParse(data->g, corto_interface(parent)->base)) {
                        corto_depresolver_depend(data->resolver, o, CORTO_DECLARED, corto_interface(parent)->base, CORTO_DEFINED);
                    }
                }
            }

            /* Add dependencies on function parameters - types must be declared before function is declared. */
            if (corto_genDepBuildProc(corto_function(o), &walkData)) {
                goto error;
            }
        }

        /* Insert dependency on parent */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED) && corto_parentof(o)) {
            if (parent != root_o) { /* Root is always available */
                corto_int8 parentState = corto_type(corto_typeof(o))->options.parentState;

                corto_depresolver_depend(data->resolver, o, CORTO_DECLARED, parent, parentState);
                if (parentState == CORTO_DECLARED) {
                    corto_depresolver_depend(data->resolver, parent, CORTO_DEFINED, o, CORTO_DEFINED);
                }
            }
        }

        /* Guard to ensure that the object is added to the dependency administration */
        corto_depresolver_insert(data->resolver, o);

        /* Insert dependencies on references in the object-value */
        s = corto_genDepSerializer();
        if (corto_serialize(&s, o, &walkData)) {
            goto error;
        }
        data->anonymousObjects = walkData.anonymousObjects;

        result = 1;
    }

    return result;
error:
    return 0;
}


static int corto_genDeclareAction(corto_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    if (data->onDeclare) {
        data->onDeclare(o, data->userData);
    }
    
    return 1;
}

static int corto_genDefineAction(corto_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    if ((corto_typeof(o)->kind != CORTO_VOID) || (corto_typeof(o)->reference)) {
        if (data->onDefine) {
            data->onDefine(o, data->userData);
        }
    }
    return 1;
}

int corto_genDepWalk(g_generator g, corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void* userData) {
    struct g_itemWalk_t walkData;
    corto_depresolver resolver = corto_depresolverCreate(corto_genDeclareAction, corto_genDefineAction, &walkData);

    /* Prepare walkData */
    walkData.g = g;
    walkData.userData = userData;
    walkData.resolver = resolver;
    walkData.onDefine = onDefine;
    walkData.onDeclare = onDeclare;
    walkData.bootstrap = FALSE;
    walkData.anonymousObjects = NULL;

    /* Build dependency administration */
    if (!g_walkRecursive(g, corto_genDepBuildAction, &walkData)) {
        if (!walkData.bootstrap) {
            corto_trace("dependency-builder failed.");
            goto error;
        } else {
            g_walkRecursive(g, corto_genDeclareAction, &walkData);
            g_walkRecursive(g, corto_genDefineAction, &walkData);
        }
    }

    if (walkData.anonymousObjects) {
        corto_llFree(walkData.anonymousObjects);
    }

    return corto_depresolver_walk(resolver);
error:
    return -1;
}

#endif
