/* Copyright (c) 2010-2018 the corto developers
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
#include "object.h"

CORTO_SEQUENCE(dummySeq, char,);

char* _corto_ptr_str(void *p, corto_type type, corto_uint32 maxLength) {
    corto_assert_object(type);
    corto_string_ser_t serData;
    corto_walk_opt s;
    corto_value v = corto_value_mem(p, type);

    serData.buffer = CORTO_BUFFER_INIT;
    serData.buffer.max = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_WALK_TRACE_NEVER);
    corto_walk_value(&s, &v, &serData);
    corto_string result = corto_buffer_str(&serData.buffer);
    corto_walk_deinit(&s, &serData);
    return result;
}

corto_int16 _corto_ptr_init(
    void *p,
    corto_type type)
{
    corto_assert_object(type);
    corto_value v = corto_value_mem(p, type);

    memset(p, 0, corto_type_sizeof(type));

    if (!type->reference && type->flags & CORTO_TYPE_NEEDS_INIT) {
        corto_walk_opt s = corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
        if (corto_walk_value(&s, &v, NULL)) {
            return -1;
        }
    }

    /* Never call init delegate of reference type on a reference pointer. The
     * initializer of reference types is only meant to be invoked on objects of
     * the reference types, not on *values* that contain a reference to the
     * object. */
    if (!type->reference && type->flags & CORTO_TYPE_HAS_INIT) {
        return corto_invoke_preDelegate(&type->init, type, p);
    } else {
        return 0;
    }
}

corto_int16 _corto_ptr_deinit(
    void *p,
    corto_type type)
{
    corto_assert_object(type);

    /* Don't deinit for reference types- see ptr_init for reason */
    if (!type->reference) {
        if (type->flags & CORTO_TYPE_HAS_RESOURCES) {
            corto_free(p, type);
        }

        if (type->flags & CORTO_TYPE_HAS_DEINIT) {
            corto_invoke_postDelegate(&type->deinit, type, p);
        }
    } else {
        corto_object o = *(corto_object*)p;
        if (o) {
            corto_release(o);
        }
    }

    return 0;
}

corto_int16 _corto_ptr_copy(
    void *dst,
    corto_type type,
    void *src)
{
    corto_assert_object(type);

    corto_walk_opt s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_copy_ser_t data;

    data.value = corto_value_mem(dst, type);

    return corto_walk_ptr(&s, src, type, &data);;
}

corto_equalityKind _corto_ptr_compare(
    const void *p1,
    corto_type type,
    const void *p2)
{
    corto_assert_object(type);
    corto_compare_ser_t data;
    corto_walk_opt s;

    data.value = corto_value_ptr((void*)p2, type);
    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_NEVER);

    corto_walk_ptr(&s, (void*)p1, type, &data);

    return data.result;
}

void* _corto_ptr_new(
    corto_type type)
{
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

void _corto_ptr_free(
    void *ptr,
    corto_type type)
{
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
        corto_value v = corto_value_mem(result, type);
        if (corto_walk_value(&s, &v, NULL)) {
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
    corto_type type = corto_mem_typeof(ptr);

    if (type->flags & CORTO_TYPE_HAS_RESOURCES) {
        corto_free(ptr, type);
    }

    ptr = CORTO_OFFSET(ptr, -sizeof(corto_type));
    corto_dealloc(ptr);
}

corto_type corto_mem_typeof(
    void *ptr)
{
    ptr = CORTO_OFFSET(ptr, -sizeof(corto_type));
    return *(corto_type*)ptr;
}

int16_t corto_mem_deserialize(
    void *ptr,
    const char *fmt,
    const void *value)
{
    corto_fmt fmt_handle;

    if (!(fmt_handle = corto_fmt_lookup(fmt))) {
        goto error;
    }

    corto_value v = corto_value_mem(ptr, corto_mem_typeof(ptr));

    return corto_fmt_to_value(fmt_handle, NULL, &v, value);
error:
    return -1;
}

int16_t _corto_ptr_resize(
    void *ptr,
    corto_type type,
    uint32_t size)
{
    corto_assert(type->kind == CORTO_COLLECTION, "corto_ptr_resize is only valid for collection types");
    corto_collection collectionType = corto_collection(type);
    corto_assert(!collectionType->max || collectionType->max < size, "ptr_size: size %d exceeds bounds of collectiontype (%d)",
        size,
        collectionType->max);
    corto_type element_type = collectionType->element_type;
    uint32_t elemSize = corto_type_sizeof(element_type);

    switch(collectionType->kind) {
    case CORTO_ARRAY:
        /* Only allocate array if it's is zero */
        if (!*(void**)ptr) {
            void *array = *(void**)ptr = corto_alloc(size * elemSize);
            int i;
            for (i = 0; i < size; i ++) {
                void *elem = CORTO_OFFSET(array, i * elemSize);
                if (corto_ptr_init(elem, element_type)) {
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
                corto_ptr_deinit(elem, element_type);
            }
        }
        seq->buffer = corto_realloc(seq->buffer, elemSize * size);
        if (seq->length < size) {
            int i;
            for (i = seq->length; i < size; i ++) {
                void *elem = CORTO_OFFSET(seq->buffer, i * elemSize);
                if (corto_ptr_init(elem, element_type)) {
                    goto error;
                }
            }
        }
        seq->length = size;
        break;
    }
    case CORTO_LIST: {
        corto_ll l = *(corto_ll*)ptr;
        if (!l) {
            *(corto_ll*)ptr = l = corto_ll_new();
        }
        if (corto_ll_count(l) > size) {
            corto_iter it = corto_ll_iter(l);

            /* Move iterator to first redundant element */
            corto_ll_iterMove(&it, size);

            /* Deinitialize redundant samples */
            while (corto_iter_hasNext(&it)) {
                void *elem;
                if (corto_collection_requires_alloc(element_type)) {
                    elem = corto_iter_next(&it);
                    corto_ptr_free(elem, element_type);
                } else {
                    elem = corto_ll_iterNextPtr(&it);
                    corto_ptr_deinit(elem, element_type);
                }
                corto_ll_iterRemove(&it);
            }
        }

        int i;
        for (i = corto_ll_count(l); i < size; i++) {
            void *elem;
            if (corto_collection_requires_alloc(element_type)) {
                elem = corto_ptr_new(element_type);
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
        return corto_ll_count(*(corto_ll*)ptr);
        break;
    default:
        //return corto_rb_count(*(corto_rb*)ptr);
        break;
    }

    return 0;
}
