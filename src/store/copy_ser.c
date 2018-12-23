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

#include <corto>
#include "copy_ser.h"

static
int16_t corto_ser_any(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_any *ptr = corto_value_ptrof(info);
    corto_copy_ser_t *data = userData, privateData;
    corto_any *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    corto_value v;

    if (ptr->type->kind == CORTO_PRIMITIVE) {
        value->value = corto_calloc(corto_type_sizeof(ptr->type));
    }

    v = corto_value_ptr(ptr->value, ptr->type);
    privateData.value = corto_value_ptr(value->value, value->type);

    /* Set base of privateData. Because we're reusing the serializer, the
     * construct callback won't be called again */
    privateData.base = ptr->value;

    corto_walk_value(s, &v, &privateData);

    value->type = ptr->type;
    value->owner = TRUE;

    return 0;
}

static
int16_t corto_ser_primitive(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_type type = corto_value_typeof(info);
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));

    CORTO_UNUSED(s);

    if (corto_primitive(type)->kind != CORTO_TEXT) {
        memcpy(value, ptr, type->size);
    } else {
        corto_set_str((corto_string*)value, *(corto_string*)ptr);
    }

    return 0;
}

static
int16_t corto_ser_reference(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    CORTO_UNUSED(s);

    corto_set_ref(value, *(corto_object*)ptr);

    return 0;
}

static
int16_t corto_ser_composite(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    corto_type t = corto_value_typeof(info);

    if (corto_interface(t)->kind == CORTO_UNION) {
        int32_t oldDiscriminator = *(int32_t*)value;
        int32_t newDiscriminator = *(int32_t*)ptr;

        /* If discriminators are different, we need to potentially deinitialize
         * and reinitialize the value with the new type. This will ensure that
         * for exampe list members are initialized properly with an empty list
         * object. */
        if (oldDiscriminator != newDiscriminator) {
            corto_member m = safe_corto_union_findCase(t, oldDiscriminator);
            if (m->modifiers & CORTO_OPTIONAL) {
                corto_ptr_free(*(void**)CORTO_OFFSET(value, m->offset), m->type);
            } else if (m->type->flags & CORTO_TYPE_NEEDS_INIT) {
                corto_ptr_deinit(CORTO_OFFSET(value, m->offset), m->type);
            }

            m = safe_corto_union_findCase(t, newDiscriminator);
            if (!(m->modifiers & CORTO_OPTIONAL)) {
                if (m->type->flags & CORTO_TYPE_NEEDS_INIT) {
                    corto_ptr_init(CORTO_OFFSET(value, m->offset), m->type);
                }
            } else {
                *(void**)CORTO_OFFSET(value, m->offset) = NULL;
            }
        }

        *(int32_t*)value = newDiscriminator;
    }

    return corto_walk_members(s, info, userData);
}

/* Deinit element */
void corto_collection_deinitElement(corto_collection t, void *ptr) {
    if (corto_collection_requires_alloc(t->element_type)) {
        corto_ptr_deinit(ptr, t->element_type);
    } else {
        corto_ptr_deinit(&ptr, t->element_type);
    }
}

static
int16_t corto_collection_copyListToArray(
    corto_collection t,
    void *array,
    uint32_t elementSize,
    ut_ll list,
    corto_bool reverse)
{
    corto_equalityKind result = 0;
    uint32_t i=0;
    ut_iter iter;
    void *e1, *e2;
    corto_type element_type = t->element_type;

    iter = ut_ll_iter(list);
    while(ut_iter_hasNext(&iter)) {
        if (corto_collection_requires_alloc(t->element_type)) {
            e2 = ut_iter_next(&iter);
        } else {
            e2 = ut_iter_nextPtr(&iter);
        }
        e1 = CORTO_OFFSET(array, elementSize * i);
        if (reverse) {
            void *tmp = e1;
            e1 = e2;
            e2 = tmp;
        }

        if (element_type->reference) {
            corto_set_ref(e1, *(corto_object*)e2);
        } else {
            result = corto_ptr_copy(e1, element_type, e2);
        }

        i++;
    }

    return result;
}

/* TODO: should new elements be initialized? Should all elements be deinitialized first and then initialized? */
static
int16_t corto_collection_copyListToList(
    corto_collection t,
    ut_ll dst,
    ut_ll src)
{
    corto_equalityKind result = 0;
    ut_iter dstIter, srcIter;
    void *dstElem, *srcElem;
    corto_type element_type = t->element_type;
    bool requires_alloc = corto_collection_requires_alloc(t->element_type);

    dstIter = ut_ll_iter(dst);
    srcIter = ut_ll_iter(src);
    while(ut_iter_hasNext(&dstIter) && ut_iter_hasNext(&srcIter)) {
        if (requires_alloc) {
            dstElem = ut_iter_next(&dstIter);
            srcElem = ut_iter_next(&srcIter);
        } else {
            dstElem = ut_iter_nextPtr(&dstIter);
            srcElem = ut_iter_nextPtr(&srcIter);
        }

        if (element_type->reference) {
            corto_set_ref((corto_object*)dstElem, *(corto_object*)srcElem);
        } else {
            result = corto_ptr_copy(dstElem, element_type, srcElem);
        }
    }

    return result;
}

/* Resize list */
static
void corto_collection_resizeList(
    corto_collection t,
    ut_ll list,
    uint32_t size)
{
    uint32_t ownSize = ut_ll_count(list);
    corto_type element_type = t->element_type;
    bool requires_alloc = corto_collection_requires_alloc(t->element_type);

    /* If there are more elements in the destination, remove superfluous elements */
    if (ownSize > size) {
        uint32_t i;
        void *ptr;
        for(i=size; i<ownSize; i++) {
            ptr = ut_ll_takeFirst(list);
            corto_collection_deinitElement(t, ptr);
        }
    /* If there are less elements in the destination, add new elements */
    } else if (ownSize < size) {
        uint32_t i;
        for(i=ownSize; i<size; i++) {
            void *elem = NULL;
            if (requires_alloc) {
                elem = corto_ptr_new(element_type);
            }

            void *ptr = ut_ll_insert(list, elem);

            if (!requires_alloc) {
                corto_ptr_init(ptr, element_type);
            }
        }
    }
}

/* Resize list */
static
void* corto_collection_resizeArray(
    corto_collection t,
    void* sequence,
    uint32_t size)
{
    void *result = sequence;

    /* Only sequences can be resized */
    if (t->kind == CORTO_SEQUENCE) {
        uint32_t ownSize = ((corto_objectseq*)sequence)->length;
        corto_type element_type = t->element_type;
        result = ((corto_objectseq*)sequence)->buffer;

        /* If there are more elements in the destination, remove superfluous elements */
        if (ownSize > size) {
            uint32_t i;
            for(i = size; i < ownSize; i++) {
                corto_ptr_deinit(CORTO_OFFSET(((corto_objectseq*)sequence)->buffer, element_type->size * i), element_type);
            }
            /* Reallocate buffer */
            result = ((corto_objectseq*)sequence)->buffer =
              corto_realloc(((corto_objectseq*)sequence)->buffer, element_type->size * size);

            /* If there are less elements in the destination, add new elements */
        } else if (ownSize < size) {
            /* Reallocate buffer */
            result = ((corto_objectseq*)sequence)->buffer =
              corto_realloc(((corto_objectseq*)sequence)->buffer, element_type->size * size);

            /* Memset new memory */
            memset(CORTO_OFFSET(((corto_objectseq*)sequence)->buffer, element_type->size * ownSize), 0, (size - ownSize) * element_type->size);
        }
        ((corto_objectseq*)sequence)->length = size;
    }

    return result;
}

/* Copy collections */
static
int16_t corto_ser_collection(
    corto_walk_opt* s,
    corto_value *info,
    void* userData)
{
    corto_type t1, t2;
    void *src, *dst;
    uint32_t size1 = 0;
    corto_copy_ser_t *data = userData;
    uint32_t result = 0;
    corto_bool v1IsArray = FALSE, v2IsArray = FALSE;
    bool srcIsList = false, dstIsList = false;

    CORTO_UNUSED(s);

    /* If this function is reached, collection-types are either equal or comparable. When the
     * base-object was a collection, the collection type can be different. When the base-object
     * was a composite type, the collection type has to be equal, since different composite
     * types are considered non-comparable. */
    t1 = corto_value_typeof(info);
    src = corto_value_ptrof(info);

    /* Verify whether current serialized object is the base-object */
    if (info->parent) {
        t2 = t1;
        dst = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)src - (corto_word)data->base));
    } else {
        t2 = corto_value_typeof(&data->value);
        dst = corto_value_ptrof(&data->value);
    }

    {
        void *array1 = NULL, *array2 = NULL;
        ut_ll srcList = NULL, dstList = NULL;
        uint32_t elementSize = 0;

        elementSize = corto_type_sizeof(corto_collection(t1)->element_type);

        switch(corto_collection(t1)->kind) {
            case CORTO_ARRAY:
                array1 = src;
                elementSize = corto_type_sizeof(corto_collection(t1)->element_type);
                size1 = corto_collection(t1)->max;
                v1IsArray = TRUE;
                break;
            case CORTO_SEQUENCE:
                array1 = ((corto_objectseq*)src)->buffer;
                elementSize = corto_type_sizeof(corto_collection(t1)->element_type);
                size1 = ((corto_objectseq*)src)->length;
                v1IsArray = TRUE;
                break;
            case CORTO_LIST:
                srcList = *(ut_ll*)src;
                size1 = ut_ll_count(srcList);
                srcIsList = true;
                break;
            case CORTO_MAP:
                break;
        }

        switch(corto_collection(t2)->kind) {
            case CORTO_ARRAY:
                array2 = dst;
                v2IsArray = TRUE;
                break;
            case CORTO_SEQUENCE:
                array2 = ((corto_objectseq*)dst)->buffer;
                v2IsArray = TRUE;
                break;
            case CORTO_LIST:
                dstList = *(ut_ll*)dst;
                dstIsList = true;
                break;
            case CORTO_MAP:
                break;
        }

        if (dstIsList && !dstList && (size1 || srcList)) {
            *(ut_ll*)dst = dstList = ut_ll_new();
        }

        if (v1IsArray) {
            if (v2IsArray) {
                corto_copy_ser_t privateData;

                /* This is a bit tricky: passing the pointer to what is potentially a sequence-buffer
                 * while providing a sequence type. */
                array2 = corto_collection_resizeArray(corto_collection(t2), dst, size1);

                privateData.value = corto_value_ptr(array2, corto_type(t2));
                privateData.base = array1;
                result = corto_walk_elements(s, info, &privateData);
            } else if (dstList) {
                corto_collection_resizeList(corto_collection(t1), dstList, size1);
                result = corto_collection_copyListToArray(corto_collection(t1), array1, elementSize, dstList, TRUE);
            }
        } else if (srcIsList) {
            if (array2) {
                array2 = corto_collection_resizeArray(corto_collection(t2), dst, size1);
                result = corto_collection_copyListToArray(corto_collection(t1), array2, elementSize, srcList, FALSE);
            } else if (dstIsList) {
                corto_collection_resizeList(corto_collection(t1), dstList, size1);
                result = corto_collection_copyListToList(corto_collection(t1), dstList, srcList);
            }
        }
        if (dstList && srcIsList && !srcList) {
            ut_ll_free(dstList); /* List should be empty by now */
            *(ut_ll*)dst = NULL;
        }
    }

    return result;
}

static
int16_t corto_ser_construct(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_copy_ser_t *data = userData;
    int16_t ret;
    CORTO_UNUSED(s);

    corto_type t1 = corto_value_typeof(info);
    corto_type t2 = corto_value_typeof(&data->value);

    data->base = corto_value_ptrof(info);

    ret = !corto_type_castable(t2, t1);
    if (ret) {
        ut_throw("cannot copy value of type '%s' to '%s'",
            corto_fullpath(NULL, t1), corto_fullpath(NULL, t2));
    }

    return ret;
}

static
int16_t corto_ser_member(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_copy_ser_t *data = userData;
    corto_member m = info->is.member.member;

    if (m->modifiers & CORTO_OPTIONAL) {
        void *ptr = corto_value_ptrof(info);
        void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));

        void *ptrOptional = *(void**)ptr;
        void *valueOptional = *(void**)value;

        if (ptrOptional) {
            if (!valueOptional) {
                *(void**)value = valueOptional = corto_ptr_new(m->type);
            }

            corto_copy_ser_t privateData = {
                .value = corto_value_ptr(valueOptional, m->type),
                .base = ptrOptional
            };

            corto_value_ptrset(info, *(void**)ptr);
            return corto_walk_value(s, info, &privateData);
        } else {
            if (valueOptional) {
                /* Unset value */
                corto_ptr_free(valueOptional, m->type);
                *(void**)value = NULL;
            }
            return 0;
        }
    } else {
        return corto_walk_value(s, info, data);
    }
}

static
int16_t corto_ser_observable(
    corto_walk_opt* s,
    corto_value *info,
    void *userData)
{
    corto_copy_ser_t *data = userData;

    corto_type type = corto_value_typeof(info);

    void *ptr = corto_value_ptrof(info);
    void *value =
        (void*)((corto_word)corto_value_ptrof(&data->value) +
            ((corto_word)ptr - (corto_word)data->base));

    if (!type->reference) {
        corto_copy_ser_t privateData = {
            .value = corto_value_object(*(corto_object*)value, NULL),
            .base = *(corto_object*)ptr
        };
        return corto_walk_observable(s, info, &privateData);
    } else {
        /* Observable reference members are automatically initialized with an
         * orphaned object of the specified member type. */
        corto_object dst = *(corto_object*)value;
        corto_object src = *(corto_object*)ptr;
        if (corto_copy(&dst, src)) {
            return -1;
        }
        return 0;
    }
}

corto_walk_opt corto_copy_ser(
    corto_modifierMask access,
    corto_operatorKind accessKind,
    corto_walk_traceKind trace)
{
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.optionalAction = CORTO_WALK_OPTIONAL_PASSTHROUGH;
    s.construct = corto_ser_construct;
    s.program[CORTO_VOID] = NULL;
    s.program[CORTO_ANY] = corto_ser_any;
    s.program[CORTO_PRIMITIVE] = corto_ser_primitive;
    s.program[CORTO_COMPOSITE] = corto_ser_composite;
    s.program[CORTO_COLLECTION] = corto_ser_collection;
    s.metaprogram[CORTO_MEMBER] = corto_ser_member;
    s.reference = corto_ser_reference;
    s.observable = corto_ser_observable;

    return s;
}
