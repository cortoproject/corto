/*
 * corto_mm.c
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#include "corto/corto.h"

corto_int16 corto_ser_initCollection(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    void* o;

    t = corto_value_getType(v);
    o = corto_value_getPtr(v);

    switch(corto_collection(t)->kind) {
        case CORTO_ARRAY:
            /* Serialize elements */
            if (corto_serializeElements(s, v, userData)) {
                goto error;
            }
            break;
        case CORTO_SEQUENCE:
            ((corto_objectseq*)o)->buffer = NULL;
            ((corto_objectseq*)o)->length = 0;
            break;
        case CORTO_LIST:
            *(corto_ll*)o = corto_llNew();
            break;
        case CORTO_MAP:
            /**(corto_rbtree*)o = corto_rbtreeNew(t);*/
            break;
        default:
            corto_error("invalid collection object!");
            goto error;
            break;
    }

    return 0;
error:
    return -1;
}


struct corto_serializer_s corto_ser_init(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CORTO_COLLECTION] = corto_ser_initCollection;
    s.program[CORTO_ANY] = NULL;
    return s;
}
