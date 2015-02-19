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

cx_int16 cx_iterator_set(void *_this, void *collection, cx_collection collectionType) {
    CX_UNUSED(_this);
    CX_UNUSED(collection);
    CX_UNUSED(collectionType);

    CX_ITERATOR(IteratorType);
    IteratorType *iteratorType = _this;
    iteratorType->type = collectionType;

    switch (collectionType->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            iteratorType->is.array.array = collection;
            iteratorType->is.array.element = collection;
            break;
        case CX_LIST:
            break;
        case CX_MAP:
            break;
    }
    return 0;
}

static cx_bool cx_iterator_hasNext_array(cx_collection collection, cx_void *array, void *element) {
    cx_assert(array != NULL, "array corrupt");
    cx_bool result = FALSE;
    cx_type elementType = collection->elementType;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    if (element  < CX_OFFSET(array, elementSize * length)) {
        result = TRUE;
    }
    return result;
}

static int cx_iterator_next_array(cx_collection collection, cx_void *array, void **elementPtr) {
    cx_assert(array != NULL, "array corrupt");
    int result;
    result = 1;
    cx_type elementType = collection->elementType;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    void *element = *elementPtr;
    if (element < CX_OFFSET(array, elementSize * length)) {
        *elementPtr = CX_OFFSET(element, elementSize);
        result = 0;
    }
    return result;
}

cx_bool cx_iterator_hasNext(void *_this) {
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this;
    cx_bool result = FALSE;
    switch (iterator->type->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            result = cx_iterator_hasNext_array(
                iterator->type,
                iterator->is.array.array,
                iterator->is.array.element);
            break;
            break;
        case CX_LIST:
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
    iteratorType *iterator = _this;
    int error = 0;
    void* result;
    switch (iterator->type->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            error = cx_iterator_next_array(
                iterator->type,
                iterator->is.array.array,
                &(iterator->is.array.element));
            break;
            break;
        case CX_LIST:
            break;
        case CX_MAP:
            break;
        default:
            break;
    }
    if (error) {
        cx_critical("reached end of collection while attempting to retrieve next");
    }
    result = iterator->is.array.element;
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
