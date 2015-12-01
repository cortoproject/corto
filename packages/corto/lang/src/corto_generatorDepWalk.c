/*
 * corto_generatorDepWalk.c
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#include "corto.h"

#ifdef CORTO_GENERATOR

int corto_genDepBuildAction(corto_object o, void* userData);

/* Walk objects in correct dependency order. */
typedef struct g_itemWalk_t *g_itemWalk_t;
struct g_itemWalk_t {
    corto_generator g;
    void *userData;
    corto_depresolver resolver;
    corto_bool bootstrap;
    corto_depresolver_action onDeclare;
    corto_depresolver_action onDefine;
};

typedef struct g_depWalk_t* g_depWalk_t;
struct g_depWalk_t  {
    corto_object o;
    g_itemWalk_t data;
};

/* Serialize dependencies on references */
corto_int16 corto_genDepReference(corto_serializer s, corto_value* info, void* userData) {
    corto_object o;
    g_depWalk_t data;

    CORTO_UNUSED(s);

    data = userData;
    o = *(corto_object*)corto_valueValue(info);

    if (o && g_mustParse(data->data->g, o)) {
        corto_member m;

        m = NULL;

        if (info->kind == CORTO_MEMBER) {
            m = info->is.member.t;
            if (!m->type->reference) {
                m = NULL;
            }
        }

        /* Add dependency on item */
        if (m) {
            corto_depresolver_depend(data->data->resolver, data->o, CORTO_DEFINED, o, m->state);
        } else {
            corto_depresolver_depend(data->data->resolver, data->o, CORTO_DEFINED, o, CORTO_DEFINED);
        }

        /* Include dependencies on anonymous types */
        if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            corto_genDepBuildAction(o, data->data);
        }
    }

    return 0;
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
static int corto_genDepBuildProc(corto_function f, g_itemWalk_t data) {
    corto_uint32 i;
    corto_type t;

    if (corto_procedure(corto_typeof(f))->kind != CORTO_OBSERVER) {
        for(i=0; i<f->parameters.length; i++) {
            t = f->parameters.buffer[i].type;
            if (g_mustParse(data->g, t)) {
                corto_depresolver_depend(data->resolver, f, CORTO_DECLARED, t, CORTO_DECLARED | CORTO_DEFINED); /* The type must be at least declared when the function is declared. */
            }
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

    /* If object is corto_lang_o, signal that a bootstrap is found, indicating
     * that dependencies should be disregarded. */
    if (o == corto_lang_o) {
        data->bootstrap = TRUE;
        result = 0;
    } else {
        /* Insert type-dependency: object can be declared only after it's type is defined. */
        if (g_mustParse(data->g, corto_typeof(o))) {
            corto_depresolver_depend(data->resolver, o, CORTO_DECLARED, corto_typeof(o), CORTO_DEFINED);
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
            if (corto_genDepBuildProc(corto_function(o), data)) {
                goto error;
            }
        }

        /* Insert dependency on parent */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED) && corto_parentof(o)) {
            if (parent != root_o) { /* Root is always available */
                corto_int8 parentState = corto_type(corto_typeof(o))->parentState;

                corto_depresolver_depend(data->resolver, o, CORTO_DECLARED, parent, parentState);
                if (parentState == CORTO_DECLARED) {
                    corto_depresolver_depend(data->resolver, parent, CORTO_DEFINED, o, CORTO_DEFINED);
                }
            }
        }

        /* Guard to ensure that the object is added to the dependency administration */
        corto_depresolver_insert(data->resolver, o);

        /* Insert dependencies on references in the object-value */
        walkData.o = o;
        walkData.data = data;
        s = corto_genDepSerializer();
        if (corto_serialize(&s, o, &walkData)) {
            goto error;
        }

        result = 1;
    }

    return result;
error:
    return 0;
}


static int corto_genDeclareAction(corto_object o, void* userData) {
    g_itemWalk_t data;
    data = userData;
    data->onDeclare(o, data->userData);
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

int corto_genCollectAnonymous(void* o, void* userData) {
    corto_ll list = userData;

    if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_llInsert(list, o);
    }

    return 1;
}

int corto_genDepWalk(corto_generator g, corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void* userData) {
    struct g_itemWalk_t walkData;
    corto_depresolver resolver = corto_depresolverCreate(corto_genDeclareAction, corto_genDefineAction, &walkData);

    /* Prepare walkData */
    walkData.g = g;
    walkData.userData = userData;
    walkData.resolver = resolver;
    walkData.onDefine = onDefine;
    walkData.onDeclare = onDeclare;
    walkData.bootstrap = FALSE;

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

    return corto_depresolver_walk(resolver);
error:
    return -1;
}

#endif
