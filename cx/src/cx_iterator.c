/* cx_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */

cx_int16 cx_iterator_set(void* _this, void* collection, cx_collection collectionType) {
    CX_ITERATOR(IteratorType);
    IteratorType *iter = _this;
    iter->type = collectionType;

    switch (collectionType->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            iter->is.array.array = collection;
            iter->is.array.element = collection;
            break;
        case CX_LIST:
            iter->is.ll.ll = collection;
            iter->is.ll.iter = cx_llIter(collection);
            break;
        case CX_MAP:
            break;
    }
    return 0;
}

static cx_bool cx_iterator_hasNext_array(void* iterator) {
    CX_ITERATOR(IteratorType);
    IteratorType *iter = iterator;
    cx_collection collection = iter->type;
    cx_void *array = iter->is.array.array;
    void *element = iter->is.array.element;
    cx_bool hasNext = FALSE;
    cx_type elementType = collection->elementType;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    if (element  < CX_OFFSET(array, elementSize * length)) {
        hasNext = TRUE;
    }
    return hasNext;
}

static int cx_iterator_next_array(void* iterator, void** nextElement) {
    CX_ITERATOR(IteratorType);
    IteratorType *iter;
    cx_collection collection;
    cx_void *array;
    void *element;
    cx_type elementType;
    cx_uint32 elementSize;
    cx_uint32 length;
    int error;

    error = 1;
    iter = iterator;
    collection  = iter->type;
    array = iter->is.array.array;
    element = iter->is.array.element;
    elementType = collection->elementType;
    elementSize = cx_type_sizeof(elementType);
    length = collection->max;
    if (element < CX_OFFSET(array, elementSize * length)) {
        *nextElement = CX_OFFSET(element, elementSize);
        iter->is.array.element = *nextElement;
        error = 0;
    }
    return error;
}

static cx_bool cx_iterator_hasNext_ll(void* iterator) {
    CX_ITERATOR(IteratorType);
    IteratorType *iter = iterator;
    cx_bool result = cx_iterHasNext(&(iter->is.ll.iter));
    return result;
}

static int cx_iterator_next_ll(void* iterator, void** nextElement) {
    CX_ITERATOR(IteratorType);
    IteratorType *iter = iterator;
    *nextElement = cx_iterNext(&iter->is.ll.iter);
    return 0;
}

cx_bool cx_iterator_hasNext(void* _this) {
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this;
    cx_bool result = FALSE;
    switch (iterator->type->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            result = cx_iterator_hasNext_array(iterator);
            break;
        case CX_LIST:
            result = cx_iterator_hasNext_ll(iterator);
            break;
        case CX_MAP:
            break;
        default:
            break;
    }
    return result;
}

void* cx_iterator_next(void* _this) {
    CX_ITERATOR(iteratorType);
    iteratorType *iterator;
    int error;
    void *result;

    iterator = _this;
    error = 0;

    switch (iterator->type->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            error = cx_iterator_next_array(iterator, &result);
            break;
            break;
        case CX_LIST:
            error = cx_iterator_next_ll(iterator, &result);
            break;
        case CX_MAP:
            break;
        default:
            break;
    }
    if (error) {
        cx_critical("reached end of collection while attempting to retrieve next");
    }
    return result;
}

/* $end */

/* ::cortex::lang::iterator::castable(type type) */
cx_bool cx_iterator_castable_v(cx_iterator _this, cx_type type) {
/* $begin(::cortex::lang::iterator::castable) */
    return cx_iterator_compatible_v(_this, type);
/* $end */
}

/* ::cortex::lang::iterator::compatible(type type) */
cx_bool cx_iterator_compatible_v(cx_iterator _this, cx_type type) {
/* $begin(::cortex::lang::iterator::compatible) */
    cx_bool result = FALSE;
    if (type->kind == CX_COLLECTION) {
        if (cx_collection(type)->elementType == _this->elementType) {
            result = TRUE;
        }
    }
    return result;
/* $end */
}

/* ::cortex::lang::iterator::init() */
cx_int16 cx_iterator_init(cx_iterator _this) {
/* $begin(::cortex::lang::iterator::init) */
    cx_type(_this)->kind = CX_ITERATOR;
    CX_ITERATOR(iteratorType);
    cx_type(_this)->size = sizeof(iteratorType);
    return cx_type_init(cx_type(_this));
/* $end */
}
