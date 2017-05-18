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
#include "copy_ser.h"

static corto_int16 corto_ser_any(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_any *ptr = corto_value_ptrof(info);
    corto_copy_ser_t *data = userData, privateData;
    corto_any *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    corto_value v;

    if (ptr->type->kind == CORTO_PRIMITIVE) {
        value->value = corto_calloc(corto_type_sizeof(ptr->type));
    }

    v = corto_value_value(ptr->value, ptr->type);
    privateData.value = corto_value_value(value->value, value->type);

    /* Set base of privateData. Because we're reusing the serializer, the
     * construct callback won't be called again */
    privateData.base = ptr->value;

    corto_walk_value(s, &v, &privateData);

    value->type = ptr->type;
    value->owner = TRUE;

    return 0;
}

static corto_int16 corto_ser_primitive(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_type type = corto_value_typeof(info);
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));

    CORTO_UNUSED(s);

    if (corto_primitive(type)->kind != CORTO_TEXT) {
        memcpy(value, ptr, type->size);
    } else {
        corto_ptr_setstr((corto_string*)value, *(corto_string*)ptr);
    }

    return 0;
}

static corto_int16 corto_ser_reference(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    CORTO_UNUSED(s);

    corto_ptr_setref(value, *(corto_object*)ptr);

    return 0;
}

static corto_int16 corto_ser_composite(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_copy_ser_t *data = userData;
    void *ptr = corto_value_ptrof(info);
    void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
    corto_type t = corto_value_typeof(info);

    if (corto_interface(t)->kind == CORTO_UNION) {
        *(corto_int32*)value = *(corto_int32*)ptr;
    }

    return corto_walk_members(s, info, userData);
}

/* Deinit element */
void corto_collection_deinitElement(corto_collection t, void *ptr) {
    corto_value v;
    if (corto_collection_requiresAlloc(t->elementType)) {
        v = corto_value_value(ptr, corto_type(t->elementType));
    } else {
        v = corto_value_value(&ptr, corto_type(t->elementType));
    }
    corto_value_deinit(&v);
}

static corto_int16 corto_collection_copyListToArray(corto_collection t, void *array, corto_uint32 elementSize, corto_ll list, corto_bool reverse) {
    corto_equalityKind result = 0;
    corto_uint32 i=0;
    corto_iter iter;
    void *e1, *e2;
    corto_type elementType = t->elementType;

    iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        if (corto_collection_requiresAlloc(t->elementType)) {
            e2 = corto_iter_next(&iter);
        } else {
            e2 = corto_iter_nextPtr(&iter);
        }
        e1 = CORTO_OFFSET(array, elementSize * i);
        if (reverse) {
            void *tmp = e1;
            e1 = e2;
            e2 = tmp;
        }

        if (elementType->reference) {
            corto_ptr_setref(e1, *(corto_object*)e2);
        } else {
            result = corto_ptr_copy(e1, elementType, e2);
        }

        i++;
    }

    return result;
}

/* TODO: should new elements be initialized? Should all elements be deinitialized first and then initialized? */
static corto_int16 corto_collection_copyListToList(corto_collection t, corto_ll list1, corto_ll list2) {
    corto_equalityKind result = 0;
    corto_iter iter1, iter2;
    void *e1, *e2;
    corto_type elementType = t->elementType;

    iter1 = corto_ll_iter(list1);
    iter2 = corto_ll_iter(list2);
    while(corto_iter_hasNext(&iter1) && corto_iter_hasNext(&iter2)) {
        if (corto_collection_requiresAlloc(t->elementType)) {
            e1 = corto_iter_next(&iter1);
            e2 = corto_iter_next(&iter2);
        } else {
            e1 = corto_iter_nextPtr(&iter1);
            e2 = corto_iter_nextPtr(&iter2);
        }

        if (elementType->reference) {
            corto_ptr_setref((corto_object*)e1, *(corto_object*)e2);
        } else {
            result = corto_ptr_copy(e1, elementType, e2);
        }
    }

    return result;
}

/* Resize list */
static void corto_collection_resizeList(corto_collection t, corto_ll list, corto_uint32 size) {
    corto_uint32 ownSize = corto_ll_size(list);
    corto_type elementType = t->elementType;

    /* If there are more elements in the destination, remove superfluous elements */
    if (ownSize > size) {
        corto_uint32 i;
        void *ptr;
        for(i=size; i<ownSize; i++) {
            ptr = corto_ll_takeFirst(list);
            corto_collection_deinitElement(t, ptr);
        }
        /* If there are less elements in the destination, add new elements */
    } else if (ownSize < size) {
        corto_uint32 i;
        for(i=ownSize; i<size; i++) {
            void *ptr = NULL;
            if (corto_collection_requiresAlloc(t->elementType)) {
                ptr = corto_calloc(elementType->size);
            }
            corto_ll_insert(list, ptr);
        }
    }
}


/* Resize list */
static void* corto_collection_resizeArray(corto_collection t, void* sequence, corto_uint32 size) {
    void *result = sequence;

    /* Only sequences can be resized */
    if (t->kind == CORTO_SEQUENCE) {
        corto_uint32 ownSize = ((corto_objectseq*)sequence)->length;
        corto_type elementType = t->elementType;
        result = ((corto_objectseq*)sequence)->buffer;

        /* If there are more elements in the destination, remove superfluous elements */
        if (ownSize > size) {
            corto_uint32 i;
            for(i = size; i < ownSize; i++) {
                corto_ptr_deinit(CORTO_OFFSET(((corto_objectseq*)sequence)->buffer, elementType->size * i), elementType);
            }
            /* Reallocate buffer */
            result = ((corto_objectseq*)sequence)->buffer =
              corto_realloc(((corto_objectseq*)sequence)->buffer, elementType->size * size);

            /* If there are less elements in the destination, add new elements */
        } else if (ownSize < size) {
            /* Reallocate buffer */
            result = ((corto_objectseq*)sequence)->buffer =
              corto_realloc(((corto_objectseq*)sequence)->buffer, elementType->size * size);

            /* Memset new memory */
            memset(CORTO_OFFSET(((corto_objectseq*)sequence)->buffer, elementType->size * ownSize), 0, (size - ownSize) * elementType->size);
        }
        ((corto_objectseq*)sequence)->length = size;
    }

    return result;
}

/* Copy collections */
static corto_int16 corto_ser_collection(corto_walk_opt* s, corto_value *info, void* userData) {
    corto_type t1, t2;
    void *v1, *v2;
    corto_uint32 size1 = 0;
    corto_copy_ser_t *data = userData;
    corto_uint32 result = 0;
    corto_bool v1IsArray = FALSE, v2IsArray = FALSE;

    CORTO_UNUSED(s);

    /* If this function is reached, collection-types are either equal or comparable. When the
     * base-object was a collection, the collection type can be different. When the base-object
     * was a composite type, the collection type has to be equal, since different composite
     * types are considered non-comparable. */
    t1 = corto_value_typeof(info);
    v1 = corto_value_ptrof(info);

    /* Verify whether current serialized object is the base-object */
    if (info->parent) {
        t2 = t1;
        v2 = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)v1 - (corto_word)data->base));
    } else {
        t2 = corto_value_typeof(&data->value);
        v2 = corto_value_ptrof(&data->value);
    }

    {
        void *array1=NULL, *array2=NULL;
        corto_ll list1=NULL, list2=NULL;
        corto_uint32 elementSize=0;

        elementSize = corto_type_sizeof(corto_collection(t1)->elementType);

        switch(corto_collection(t1)->kind) {
            case CORTO_ARRAY:
                array1 = v1;
                elementSize = corto_type_sizeof(corto_collection(t1)->elementType);
                size1 = corto_collection(t1)->max;
                v1IsArray = TRUE;
                break;
            case CORTO_SEQUENCE:
                array1 = ((corto_objectseq*)v1)->buffer;
                elementSize = corto_type_sizeof(corto_collection(t1)->elementType);
                size1 = ((corto_objectseq*)v1)->length;
                v1IsArray = TRUE;
                break;
            case CORTO_LIST:
                list1 = *(corto_ll*)v1;
                size1 = corto_ll_size(list1);
                break;
            case CORTO_MAP:
                break;
        }

        switch(corto_collection(t2)->kind) {
            case CORTO_ARRAY:
                array2 = v2;
                v2IsArray = TRUE;
                break;
            case CORTO_SEQUENCE:
                array2 = ((corto_objectseq*)v2)->buffer;
                v2IsArray = TRUE;
                break;
            case CORTO_LIST:
                list2 = *(corto_ll*)v2;
                break;
            case CORTO_MAP:
                break;
        }

        if (v1IsArray) {
            if (v2IsArray) {
                corto_copy_ser_t privateData;

                /* This is a bit tricky: passing the pointer to what is potentially a sequence-buffer
                 * while providing a sequence type. */
                array2 = corto_collection_resizeArray(corto_collection(t2), v2, size1);

                privateData.value = corto_value_value(array2, corto_type(t2));
                privateData.base = array1;
                result = corto_walk_elements(s, info, &privateData);
            } else if (list2) {
                corto_collection_resizeList(corto_collection(t1), list2, size1);
                result = corto_collection_copyListToArray(corto_collection(t1), array1, elementSize, list2, TRUE);
            }
        } else if (list1) {
            if (array2) {
                array2 = corto_collection_resizeArray(corto_collection(t2), v2, size1);
                result = corto_collection_copyListToArray(corto_collection(t1), array2, elementSize, list1, FALSE);
            } else if (list2) {
                corto_collection_resizeList(corto_collection(t1), list2, size1);
                result = corto_collection_copyListToList(corto_collection(t1), list2, list1);
            }
        }
    }

    return result;
}

static corto_int16 corto_ser_construct(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_copy_ser_t *data = userData;
    corto_int16 ret;
    CORTO_UNUSED(s);

    corto_type t1 = corto_value_typeof(info);
    corto_type t2 = corto_value_typeof(&data->value);

    data->base = corto_value_ptrof(info);

    ret = !corto_type_castable(t2, t1);
    if (ret) {
        corto_seterr("cannot copy value of type '%s' to '%s'",
            corto_fullpath(NULL, t1), corto_fullpath(NULL, t2));
    }

    return ret;
}

static corto_int16 corto_ser_member(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_copy_ser_t *data = userData;
    corto_member m = info->is.member.t;

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
                .value = corto_value_value(valueOptional, m->type),
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

static corto_int16 corto_ser_observable(corto_walk_opt* s, corto_value *info, void *userData) {
    corto_copy_ser_t *data = userData;

    corto_type type = corto_value_typeof(info);

    if (!type->reference) {
        void *ptr = corto_value_ptrof(info);
        void *value = (void*)((corto_word)corto_value_ptrof(&data->value) + ((corto_word)ptr - (corto_word)data->base));
        corto_copy_ser_t privateData = {
            .value = corto_value_object(*(corto_object*)value, NULL), 
            .base = *(corto_object*)ptr
        };
        return corto_walk_observable(s, info, &privateData);
    } else {
        return corto_walk_observable(s, info, data);
    }
}

corto_walk_opt corto_copy_ser(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
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
