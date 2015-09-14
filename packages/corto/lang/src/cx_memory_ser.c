/*
 * cx_mm.c
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "cx_memory_ser.h"
#include "cx__object.h"
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_err.h"

#include "string.h"

cx_int16 cx_ser_keepReference(cx_serializer s, cx_value* v, void* userData) {
    cx_object o;
    CX_UNUSED(s);
    CX_UNUSED(userData);

    o = *(cx_object*)cx_valueValue(v);
    if (o) {
        cx_bool weak = FALSE;
        if (v->kind == CX_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            cx_claim(o);
        }
    }

    return 0;
}

cx_int16 cx_ser_freePrimitive(cx_serializer s, cx_value* v, void* udata) {
    cx_type t;
    void* o;

    CX_UNUSED(s);
    CX_UNUSED(udata);

    t = cx_valueType(v);
    o = cx_valueValue(v);

    /* Free strings */
    switch(cx_primitive(t)->kind) {
    case CX_TEXT: {
        cx_string str;
        if ((str = *(cx_string*)o)) {
            cx_dealloc(str);
        }
        break;
    }
    default:
        break;
    }

    return 0;
}

int cx_ser_clear(void* o, void* udata) {
    CX_UNUSED(udata);
    cx_dealloc(o);
    return 1;
}

cx_int16 cx_ser_freeCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    void* o;

    t = cx_valueType(v);
    o = cx_valueValue(v);

    /* Serialize elements */
    if (cx_serializeElements(s, v, userData)) {
        goto error;
    }

    switch(cx_collection(t)->kind) {
    case CX_ARRAY:
        break;
    case CX_SEQUENCE: {
        void* buffer;
        buffer = ((struct{cx_uint32 length; void* buffer;}*)o)->buffer;
        if (buffer) {
            cx_dealloc(buffer);
        }
        break;
    }
    case CX_LIST:
        if (*(cx_ll*)o) {
            /* Free memory allocated for listnodes */
            if (cx_collection_elementRequiresAlloc(cx_collection(t))) {
                cx_llWalk(*(cx_ll*)o, cx_ser_clear,NULL);
            }
            cx_llFree(*(cx_ll*)o);
        }
        break;
    case CX_MAP:
        if (*(cx_rbtree*)o) {
            /* Free memory allocated for mapnodes */
            if (cx_collection_elementRequiresAlloc(cx_collection(t))) {
                cx_rbtreeWalk(*(cx_rbtree*)o, cx_ser_clear,NULL);
            }
            cx_rbtreeFree(*(cx_rbtree*)o);
        }
        break;

    /* Free collection object */
    default:
        cx_error("invalid collection object!");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

cx_int16 cx_ser_freeReference(cx_serializer s, cx_value* v, void* userData) {
    cx_object *optr, o;

    CX_UNUSED(s);
    CX_UNUSED(userData);
    optr = cx_valueValue(v);

    if ((o = *optr)) {
        cx_bool weak = FALSE;
        if (v->kind == CX_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            cx_release(o);
        }
    }

    return 0;
}

struct cx_serializer_s cx_ser_keep(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CX_SERIALIZER_ALIAS_IGNORE;
    s.reference = cx_ser_keepReference;
    return s;
}

struct cx_serializer_s cx_ser_free(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CX_SERIALIZER_ALIAS_IGNORE;
    s.reference = cx_ser_freeReference;
    return s;
}

struct cx_serializer_s cx_ser_freeResources(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CX_SERIALIZER_ALIAS_IGNORE;
    s.program[CX_PRIMITIVE] = cx_ser_freePrimitive;
    s.program[CX_COLLECTION] = cx_ser_freeCollection;
    s.reference = cx_ser_freeReference;
    return s;
}
