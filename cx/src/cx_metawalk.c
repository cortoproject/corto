/*
 * cx_metawalk.c

 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#include "cx_metawalk.h"
#include "cx__object.h" /* To mimic an object */
#include "cx_err.h"
#include "cx_util.h"
#include "cx_mem.h"
#include "string.h"

/* Do metawalk on type */
cx_int16 cx_metaWalk(cx_serializer s, cx_type type, void* userData) {
    cx__object* o;
    cx_int16 result;

    /* Instantiate dummy-object */
    o = cx_malloc(sizeof(cx__object) + type->size); /* alloca is dangerous here because objects can get large, causing stack overflows. */
    memset(o, 0, sizeof(cx__object) + type->size);
    o->type = cx_typedef(type);
    o->refcount = 1;

    result = cx_serialize(s, CX_OFFSET(o, sizeof(cx__object)), userData);
    cx_dealloc(o);

    return result;
}

/* Serialize constants of enumeration */
cx_int16 cx_serializeConstants(cx_serializer s, cx_value* v, void* userData) {
    cx_enum t;
    cx_uint32 i;

    t = cx_enum(cx_valueType(v)->real);

    /* If there is a callback for constants, serialize them */
    if (s->metaprogram[CX_CONSTANT]) {
        cx_value info;
        for(i=0; i<t->constants.length; i++) {
            /* Fill info */
            info.parent = v;
            info.kind = CX_CONSTANT;
            info.is.constant.t = t->constants.buffer[i];
            info.is.constant.v = NULL;
            info.is.constant.o = cx_valueObject(v);

            /* Serialize constant */
            if (s->metaprogram[CX_CONSTANT](s, &info, userData)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}
