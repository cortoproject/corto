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

corto_int16 corto_ser_initMember(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;

    t = corto_value_getType(v);

    /* If type is instanceof target, initialize member to a new target object */
    if (corto_typeof(t) == corto_type(corto_target_o)) {
        corto_object p = corto_value_getObject(v);
        void* ptr = corto_value_getPtr(v);
        corto_member m = v->is.member.t;

        /* Create object that is not added to the scope of its parent */
        /*corto_object o = corto_createOrphan(p, corto_nameof(m), t);
        if (!o) {
            goto error;
        }

        *(corto_object*)ptr = targetInstance;*/
    }

    return corto_serializeValue(s, v, userData);
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
    s.metaprogram[CORTO_MEMBER] = corto_ser_initMember;

    return s;
}
