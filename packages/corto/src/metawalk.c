/*
 * corto_metawalk.c

 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "_object.h" /* To mimic an object on stack */

/* Do metawalk on type */
corto_int16 corto_metaWalk(corto_serializer s, corto_type type, void* userData) {
    corto__object* o;
    corto_int16 result;

    corto_assert(type != NULL, "corto_metaWalk called with NULL type");

    /* Instantiate dummy-object */
    o = corto_alloc(sizeof(corto__object) + type->size); /* alloca is dangerous here because objects can get large, causing stack overflows. */
    memset(o, 0, sizeof(corto__object) + type->size);
    o->type = corto_type(type);
    o->refcount = 1;

    s->visitAllCases = TRUE;
    result = corto_serialize(s, CORTO_OFFSET(o, sizeof(corto__object)), userData);
    corto_dealloc(o);

    return result;
}

/* Serialize constants of enumeration */
corto_int16 corto_serializeConstants(
    corto_serializer s,
    corto_value* v,
    void* userData)
{
    corto_enum t;
    corto_uint32 i;

    t = corto_enum(corto_value_getType(v));

    /* If there is a callback for constants, serialize them */
    if (s->metaprogram[CORTO_CONSTANT]) {
        corto_value info;
        for(i = 0; i < t->constants.length; i++) {
            /* Fill info */
            info.parent = v;
            info.kind = CORTO_CONSTANT;
            info.is.constant.t = t->constants.buffer[i];
            info.is.constant.v = NULL;
            info.is.constant.o = corto_value_getObject(v);

            /* Serialize constant */
            if (s->metaprogram[CORTO_CONSTANT](s, &info, userData)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

/* Serialize union cases */
corto_int16 corto_serializeCases(
    corto_serializer s,
    corto_value *v,
    void *userData)
{
    corto_union t = corto_union(corto_value_getType(v));
    corto_uint32 i;

    if (s->metaprogram[CORTO_MEMBER]) {
        for (i = 0; i < corto_interface(t)->members.length; i++) {
            corto_member m = corto_interface(t)->members.buffer[i];
            corto_value memberValue = corto_value_member(
                corto_value_getObject(v),
                m,
                NULL
            );

            /* Serialize case */
            if (s->metaprogram[CORTO_MEMBER](s, &memberValue, userData)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}
