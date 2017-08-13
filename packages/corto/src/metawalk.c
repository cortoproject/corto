/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "corto/corto.h"
#include "_object.h" /* To mimic an object on stack */

/* If application does not specify PRIMITIVE, replace with generic primitive
 * that automatically walks constants */
static corto_int16 corto_walk_primitive(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_primitive t = corto_primitive(corto_value_typeof(v));

    if (t->kind == CORTO_ENUM || t->kind == CORTO_BITMASK) {
        return corto_walk_constants(s, v, userData);
    } else {
        return 0;
    }
}
/* Do metawalk on type */
corto_int16 _corto_metawalk(corto_walk_opt* s, corto_type type, void* userData) {
    corto__object* o;
    corto_int16 result;

    /* Since we potentially overwrite some callbacks, make private copy */
    corto_walk_opt private = *s;

    corto_assert(type != NULL, "corto_metawalk called with NULL type");

    /* Instantiate dummy-object */
    o = corto_alloc(sizeof(corto__object) + type->size); /* alloca is dangerous here because objects can get large, causing stack overflows. */
    memset(o, 0, sizeof(corto__object) + type->size);
    o->type = corto_type(type);
    o->refcount = 1;
#ifndef NDEBUG
    o->magic = CORTO_MAGIC;
#endif
    private.visitAllCases = TRUE;

    if (!private.program[CORTO_PRIMITIVE]) {
        private.program[CORTO_PRIMITIVE] = corto_walk_primitive;
    }

    result = corto_walk(&private, CORTO_OFFSET(o, sizeof(corto__object)), userData);
    corto_dealloc(o);

    return result;
}

/* Serialize constants of enumeration */
corto_int16 corto_walk_constants(
    corto_walk_opt* s,
    corto_value* v,
    void* userData)
{
    corto_enum t;
    corto_uint32 i;

    t = corto_enum(corto_value_typeof(v));

    /* If there is a callback for constants, serialize them */
    if (s->metaprogram[CORTO_CONSTANT]) {
        corto_value info;
        for(i = 0; i < t->constants.length; i++) {
            /* Fill info */
            info.parent = v;
            info.kind = CORTO_CONSTANT;
            info.is.constant.t = t->constants.buffer[i];
            info.is.constant.v = NULL;
            info.is.constant.o = corto_value_objectof(v);

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
corto_int16 corto_walk_cases(
    corto_walk_opt* s,
    corto_value *v,
    void *userData)
{
    corto_union t = corto_union(corto_value_typeof(v));
    corto_uint32 i;

    if (s->metaprogram[CORTO_MEMBER]) {
        for (i = 0; i < corto_interface(t)->members.length; i++) {
            corto_member m = corto_interface(t)->members.buffer[i];
            corto_value memberValue = corto_value_member(
                corto_value_objectof(v),
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
