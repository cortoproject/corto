/*
 * corto_mm.c
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "_object.h"

corto_int16 corto_ser_keepReference(corto_serializer s, corto_value* v, void* userData) {
    corto_object o;
    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);

    o = *(corto_object*)corto_value_getPtr(v);
    if (o) {
        corto_bool weak = FALSE;
        if (v->kind == CORTO_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            corto_claim(o);
        }
    }

    return 0;
}

corto_int16 corto_ser_freePrimitive(corto_serializer s, corto_value* v, void* udata) {
    corto_type t;
    void* o;

    CORTO_UNUSED(s);
    CORTO_UNUSED(udata);

    t = corto_value_getType(v);
    o = corto_value_getPtr(v);

    /* Free strings */
    switch(corto_primitive(t)->kind) {
    case CORTO_TEXT: {
        corto_string str;
        if ((str = *(corto_string*)o)) {
            corto_dealloc(str);
        }
        break;
    }
    default:
        break;
    }

    return 0;
}

int corto_ser_clear(void* o, void* udata) {
    CORTO_UNUSED(udata);
    corto_dealloc(o);
    return 1;
}

corto_int16 corto_ser_freeCollection(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    void* o;

    t = corto_value_getType(v);
    o = corto_value_getPtr(v);

    /* Serialize elements */
    if (corto_serializeElements(s, v, userData)) {
        goto error;
    }

    switch(corto_collection(t)->kind) {
    case CORTO_ARRAY:
        break;
    case CORTO_SEQUENCE: {
        void* buffer;
        buffer = ((struct{corto_uint32 length; void* buffer;}*)o)->buffer;
        if (buffer) {
            corto_dealloc(buffer);
        }
        break;
    }
    case CORTO_LIST:
        if (*(corto_ll*)o) {
            /* Free memory allocated for listnodes */
            if (corto_collection_requiresAlloc(corto_collection(t)->elementType)) {
                corto_llWalk(*(corto_ll*)o, corto_ser_clear,NULL);
            }
            corto_llFree(*(corto_ll*)o);
        }
        break;
    case CORTO_MAP:
        if (*(corto_rbtree*)o) {
            /* Free memory allocated for mapnodes */
            if (corto_collection_requiresAlloc(corto_collection(t)->elementType)) {
                corto_rbtreeWalk(*(corto_rbtree*)o, corto_ser_clear,NULL);
            }
            corto_rbtreeFree(*(corto_rbtree*)o);
        }
        break;

    /* Free collection object */
    default:
        corto_error("invalid collection object!");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_ser_freeReference(corto_serializer s, corto_value* v, void* userData) {
    corto_object *optr, o;

    CORTO_UNUSED(s);
    CORTO_UNUSED(userData);
    optr = corto_value_getPtr(v);

    if ((o = *optr)) {
        corto_bool weak = FALSE;
        if (v->kind == CORTO_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            if (CORTO_TRACE_OBJECT) {
                corto_id buff;
                corto_valueExpr(v, buff, sizeof(buff));
                corto_release_ext(NULL, o, buff);
            } else {
                corto_release(o);
            }
        }
    }

    return 0;
}

struct corto_serializer_s corto_ser_keep(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
    s.reference = corto_ser_keepReference;
    return s;
}

struct corto_serializer_s corto_ser_free(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
    s.reference = corto_ser_freeReference;
    return s;
}

struct corto_serializer_s corto_ser_freeResources(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
    s.program[CORTO_PRIMITIVE] = corto_ser_freePrimitive;
    s.program[CORTO_COLLECTION] = corto_ser_freeCollection;
    s.reference = corto_ser_freeReference;
    return s;
}
