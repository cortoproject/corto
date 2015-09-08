/*
 * cx_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "cx.h"
#include "cx_generatorDepWalk.h"
#include "cx_depresolver.h"

#ifdef CX_GENERATOR

int cx_genDepBuildAction(cx_object o, void* userData);

/* Walk objects in correct dependency order. */
typedef struct g_itemWalk_t *g_itemWalk_t;
struct g_itemWalk_t {
    cx_generator g;
    void *userData;
    cx_depresolver resolver;
    cx_bool bootstrap;
    cx_depresolver_action onDeclare;
    cx_depresolver_action onDefine;
};

typedef struct g_depWalk_t* g_depWalk_t;
struct g_depWalk_t  {
    cx_object o;
    g_itemWalk_t data;
};

/* Serialize dependencies on references */
cx_int16 cx_genDepReference(cx_serializer s, cx_value* info, void* userData) {
    cx_object o;
    g_depWalk_t data;

    CX_UNUSED(s);

    data = userData;
    o = *(cx_object*)cx_valueValue(info);

    if (o && g_mustParse(data->data->g, o)) {
        cx_member m;

        m = NULL;

        if (info->kind == CX_MEMBER) {
            m = info->is.member.t;
            if (!m->type->reference) {
                m = NULL;
            }
        }

        /* Add dependency on item */
        if (m) {
            cx_depresolver_depend(data->data->resolver, data->o, CX_DEFINED, o, m->state);
        } else {
            cx_depresolver_depend(data->data->resolver, data->o, CX_DEFINED, o, CX_DEFINED);
        }

        /* Include dependencies on anonymous types */
        if (!cx_checkAttr(o, CX_ATTR_SCOPED)) {
            cx_genDepBuildAction(o, data->data);
        }
    }

    return 0;
}

/* Dependency serializer */
struct cx_serializer_s cx_genDepSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.reference = cx_genDepReference;
    s.access = CX_LOCAL;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Add dependencies for function arguments */
static int cx_genDepBuildProc(cx_function f, g_itemWalk_t data) {
    cx_uint32 i;
    cx_type t;

    if (cx_procedure(cx_typeof(f))->kind != CX_OBSERVER) {
        for(i=0; i<f->parameters.length; i++) {
            t = f->parameters.buffer[i].type;
            if (g_mustParse(data->g, t)) {
                cx_depresolver_depend(data->resolver, f, CX_DECLARED, t, CX_DECLARED | CX_DEFINED); /* The type must be at least declared when the function is declared. */
            }
        }
    }

    return 0;
}

/* Build dependency-administration for object */
int cx_genDepBuildAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    struct g_depWalk_t walkData;
    struct cx_serializer_s s;
    int result;
    cx_object parent = NULL;

    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        parent = cx_parentof(o);
    }

    data = userData;

    /* If object is corto_lang_o, signal that a bootstrap is found, indicating
     * that dependencies should be disregarded. */
    if (o == corto_lang_o) {
        data->bootstrap = TRUE;
        result = 0;
    } else {
        /* Insert type-dependency: object can be declared only after it's type is defined. */
        if (g_mustParse(data->g, cx_typeof(o))) {
            cx_depresolver_depend(data->resolver, o, CX_DECLARED, cx_typeof(o), CX_DEFINED);
        }

        /* TODO: this is not nice */
        if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
            /* Insert base-dependency: methods may only be declared after the base of a class has been defined. */
            if (cx_typeof(o) != cx_type(cx_function_o)) {
                if (cx_class_instanceof(cx_class_o, parent) && cx_interface(parent)->base) {
                    if (g_mustParse(data->g, cx_interface(parent)->base)) {
                        cx_depresolver_depend(data->resolver, o, CX_DECLARED, cx_interface(parent)->base, CX_DEFINED);
                    }
                }
            }

            /* Add dependencies on function parameters - types must be declared before function is declared. */
            if (cx_genDepBuildProc(cx_function(o), data)) {
                goto error;
            }
        }

        /* Insert dependency on parent */
        if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
            if (parent != root_o) { /* Root is always available */
                cx_int8 parentState = cx_type(cx_typeof(o))->parentState;

                cx_depresolver_depend(data->resolver, o, CX_DECLARED, parent, parentState);
                if (parentState == CX_DECLARED) {
                    cx_depresolver_depend(data->resolver, parent, CX_DEFINED, o, CX_DEFINED);
                }
            }
        }

        /* Guard to ensure that the object is added to the dependency administration */
        cx_depresolver_insert(data->resolver, o);

        /* Insert dependencies on references in the object-value */
        walkData.o = o;
        walkData.data = data;
        s = cx_genDepSerializer();
        if (cx_serialize(&s, o, &walkData)) {
            goto error;
        }

        result = 1;
    }

    return result;
error:
    return 0;
}


static int cx_genDeclareAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    data->onDeclare(o, data->userData);
    return 1;
}

static int cx_genDefineAction(cx_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    if ((cx_typeof(o)->kind != CX_VOID) || (cx_typeof(o)->reference)) {
        if (data->onDefine) {
            data->onDefine(o, data->userData);
        }
    }
    return 1;
}

int cx_genCollectAnonymous(void* o, void* userData) {
    cx_ll list = userData;

    if (!cx_checkAttr(o, CX_ATTR_SCOPED)) {
        cx_llInsert(list, o);
    }

    return 1;
}

int cx_genDepWalk(cx_generator g, cx_depresolver_action onDeclare, cx_depresolver_action onDefine, void* userData) {
    struct g_itemWalk_t walkData;
    cx_depresolver resolver = cx_depresolverCreate(cx_genDeclareAction, cx_genDefineAction, &walkData);

    /* Prepare walkData */
    walkData.g = g;
    walkData.userData = userData;
    walkData.resolver = resolver;
    walkData.onDefine = onDefine;
    walkData.onDeclare = onDeclare;
    walkData.bootstrap = FALSE;

    /* Build dependency administration */
    if (!g_walkRecursive(g, cx_genDepBuildAction, &walkData)) {
        if (!walkData.bootstrap) {
            cx_trace("dependency-builder failed.");
            goto error;
        } else {
            g_walkRecursive(g, cx_genDeclareAction, &walkData);
            g_walkRecursive(g, cx_genDefineAction, &walkData);
        }
    }

    return cx_depresolver_walk(resolver);
error:
    return -1;
}

#endif

