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

#include <corto/corto.h>
#include "init_ser.h"

CORTO_SEQUENCE(dummySeq, char,);

/* Set reference field */
void corto_ptr_setref(void* ptr, corto_object value) {
    corto_assertObject(value);

    corto_object old;
    old = *(corto_object*)ptr;
    if (value) {
        corto_claim(value);
    }
    *(corto_object*)ptr = value;
    if (old) {
        corto_release(old);
    }
}

/* Set string field */
void corto_ptr_setstr(corto_string* ptr, corto_string value) {
    char *str = *ptr;
    if (str != value) {
        if (str) {
            corto_dealloc(*ptr);
        }
        *ptr = value ? corto_strdup(value) : NULL;
    }
}

char* _corto_ptr_str(void *p, corto_type type, corto_uint32 maxLength) {
    corto_assertObject(type);

    corto_value v;
    v = corto_value_value(p, type);
    return corto_value_str(&v, maxLength);
}

char *_corto_ptr_contentof(void *ptr, corto_type type, char *contentType) {
    corto_value v = corto_value_mem(ptr, type);
    return corto_value_contentof(&v, contentType);
}

corto_int16 _corto_ptr_fromStr(void* out, corto_type type, corto_string string) {
    corto_assertObject(type);

    corto_string_deser_t serData = {
        .out = *(void**)out,
        .type = type,
        .isObject = FALSE
    };

    if (!corto_string_deser(string, &serData)) {
        corto_assert(!serData.out, "deserializer failed but out is set");
    }

    if (serData.out) {
        *(void**)out = serData.out;
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_equalityKind _corto_ptr_compare(
    const void *p1,
    corto_type type,
    const void *p2)
{
    corto_assertObject(type);

    corto_value vdst;
    corto_value vsrc;
    vdst = corto_value_value((void*)p1, type);
    vsrc = corto_value_value((void*)p2, type);
    return corto_value_compare(&vdst, &vsrc);
}

corto_int16 _corto_ptr_init(
    void *p,
    corto_type type)
{
    corto_assertObject(type);
    memset(p, 0, corto_type_sizeof(type));
    corto_value v;
    v = corto_value_value(p, type);
    return corto_value_init(&v);
}

corto_int16 _corto_ptr_deinit(void *p, corto_type type) {
    corto_assertObject(type);
    corto_value v;
    v = corto_value_value(p, type);
    return corto_value_deinit(&v);
}

corto_int16 _corto_ptr_copy(void *dst, corto_type type, void *src) {
    corto_assertObject(type);

    corto_value vdst;
    corto_value vsrc;
    corto_int16 result;
    vdst = corto_value_value(dst, type);
    vsrc = corto_value_value(src, type);
    result = corto_value_copy(&vdst, &vsrc);
    return result;
}

void* _corto_ptr_new(corto_type type) {
    void *result = NULL;

    result = corto_calloc(corto_type_sizeof(type));

    if (corto_ptr_init(result, type)) {
        corto_dealloc(result);
        goto error;
    }

    return result;
error:
    return NULL;
}

void _corto_ptr_free(void *ptr, corto_type type) {
    corto_ptr_deinit(ptr, type);
    corto_dealloc(ptr);
}

void* _corto_mem_new(
    corto_type type)
{
    void *result = NULL;

    result = corto_calloc(type->size + sizeof(corto_type));
    *(corto_type*)result = type;
    result = CORTO_OFFSET(result, sizeof(corto_type));

    if (type->flags & CORTO_TYPE_NEEDS_INIT) {
        corto_walk_opt s =
            corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
        if (corto_walk_ptr(&s, result, type, NULL)) {
            goto error;
        }
    }

    return result;
error:
    return NULL;
}

void corto_mem_free(
    void *ptr)
{
    corto_ptr_deinit(ptr, corto_mem_typeof(ptr));
    ptr = CORTO_OFFSET(ptr, -sizeof(corto_type));
    corto_dealloc(ptr);
}

corto_type corto_mem_typeof(
    void *ptr)
{
    ptr = CORTO_OFFSET(ptr, -sizeof(corto_type));
    return *(corto_type*)ptr;
}

int16_t _corto_ptr_size(void *ptr, corto_type type, uint32_t size) {
    corto_assert(type->kind == CORTO_COLLECTION, "corto_ptr_size is only valid for collection types");
    corto_collection collectionType = corto_collection(type);
    corto_assert(!collectionType->max || collectionType->max < size, "ptr_size: size %d exceeds bounds of collectiontype (%d)",
        size,
        collectionType->max);
    corto_type elementType = collectionType->elementType;
    uint32_t elemSize = corto_type_sizeof(elementType);

    switch(collectionType->kind) {
    case CORTO_ARRAY:
        /* Only allocate array if it's is zero */
        if (!*(void**)ptr) {
            void *array = *(void**)ptr = corto_alloc(size * elemSize);
            int i;
            for (i = 0; i < size; i ++) {
                void *elem = CORTO_OFFSET(array, i * elemSize);
                if (corto_ptr_init(elem, elementType)) {
                    goto error;
                }
            }
        }
        break;
    case CORTO_SEQUENCE: {
        dummySeq *seq = ptr;
        if (seq->length > size) {
            int i;
            for (i = size; i < seq->length; i ++) {
                void *elem = CORTO_OFFSET(seq->buffer, i * elemSize);
                corto_ptr_deinit(elem, elementType);
            }
        }
        seq->buffer = corto_realloc(seq->buffer, elemSize * size);
        if (seq->length < size) {
            int i;
            for (i = seq->length; i < size; i ++) {
                void *elem = CORTO_OFFSET(seq->buffer, i * elemSize);
                if (corto_ptr_init(elem, elementType)) {
                    goto error;
                }
            }
        }
        seq->length = size;
        break;
    }
    case CORTO_LIST: {
        corto_ll l = *(corto_ll*)ptr;
        if (corto_ll_size(l) > size) {
            corto_iter it = corto_ll_iter(l);

            /* Move iterator to first redundant element */
            corto_ll_iterMove(&it, size);

            /* Deinitialize redundant samples */
            while (corto_iter_hasNext(&it)) {
                void *elem;
                if (corto_collection_requiresAlloc(elementType)) {
                    elem = corto_iter_next(&it);
                    corto_ptr_free(elem, elementType);
                } else {
                    elem = corto_ll_iterNextPtr(&it);
                    corto_ptr_deinit(elem, elementType);
                }
                corto_ll_iterRemove(&it);
            }
        }

        int i;
        for (i = corto_ll_size(l); i < size; i++) {
            void *elem;
            if (corto_collection_requiresAlloc(elementType)) {
                elem = corto_ptr_new(elementType);
            } else {
                elem = NULL;
            }
            corto_ll_append(l, elem);
        }

        break;
    }
    default:
        break;
    }

    return 0;
error:
    return -1;
}

uint64_t _corto_ptr_count(void *ptr, corto_type type) {
    if (type->kind != CORTO_COLLECTION) {
        if (ptr) {
            return 1;
        } else {
            return 0;
        }
    }

    corto_collection collectionType = corto_collection(type);

    switch(collectionType->kind) {
    case CORTO_ARRAY:
        return collectionType->max;
        break;
    case CORTO_SEQUENCE: {
        dummySeq *seq = ptr;
        return seq->length;
        break;
    }
    case CORTO_LIST:
        return corto_ll_size(*(corto_ll*)ptr);
        break;
    default:
        //return corto_rb_size(*(corto_rb*)ptr);
        break;
    }

    return 0;
}
