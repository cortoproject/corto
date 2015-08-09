/*
 * cx_mm.c
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#include "cx_memory_ser.h"
#include "cx__object.h"
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_err.h"

cx_int16 cx_ser_initCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    void* o;
    
    t = cx_valueType(v);
    o = cx_valueValue(v);
    
    switch(cx_collection(t)->kind) {
        case CX_ARRAY:
            /* Serialize elements */
            if (cx_serializeElements(s, v, userData)) {
                goto error;
            }
            break;
        case CX_SEQUENCE:
            ((cx_objectSeq*)o)->buffer = NULL;
            ((cx_objectSeq*)o)->length = 0;
            break;
        case CX_LIST:
            *(cx_ll*)o = cx_llNew();
            break;
        case CX_MAP:
            /**(cx_rbtree*)o = cx_rbtreeNew(t);*/
            break;
        default:
            cx_error("invalid collection object!");
            goto error;
            break;
    }
    
    return 0;
error:
    return -1;
}


struct cx_serializer_s cx_ser_init(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;
    
    cx_serializerInit(&s);
    
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CX_COLLECTION] = cx_ser_initCollection;
    s.program[CX_ANY] = NULL;
    return s;
}
