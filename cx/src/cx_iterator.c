/* cx_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

#include "cx_err.h"

static cx_bool cx_iterator_hasNext_array(cx_collection collection, cx_void *array, void *element);
static int cx_iterator_next_array(cx_collection collection, cx_void *array, void **elementPtr);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::iterator::init(lang::iterator object) */
cx_int16 cx_iterator_init(cx_iterator object) {
    /* $begin(::cortex::lang::iterator::init) */
    cx_type(object)->kind = CX_ITERATOR;
    return cx_type_init(cx_type(object));
    /* $end */
}

/* ::cortex::lang::iterator::hasNext() */
cx_bool cx_iterator_hasNext(cx_any _this) {
/* $begin(::cortex::lang::iterator::hasNext) */
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this.value;
    cx_bool result = FALSE;
    switch (iterator->type->kind) {
        case CX_ARRAY:
            result = cx_iterator_hasNext_array(iterator->type, iterator->value, &(iterator->element));
            break;
        case CX_SEQUENCE:
            break;
        case CX_LIST:
            break;
        case CX_MAP:
            break;
        default:
            break;
    }
    return result;
/* $end */
}

/* ::cortex::lang::iterator::next() */
cx_any cx_iterator_next(cx_any _this) {
/* $begin(::cortex::lang::iterator::next) */
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this.value;
    int error = 0;
    switch (iterator->type->kind) {
        case CX_ARRAY:
            error = cx_iterator_next_array(iterator->type, iterator->value, &(iterator->element));
            break;
        case CX_SEQUENCE:
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
    cx_any result;
    result.type = iterator->type->elementType->real;
    result.value = iterator->element;
    result.owner = FALSE;
    return result;
/* $end */
}


static cx_bool cx_iterator_hasNext_array(cx_collection collection, cx_void *array, void *element) {
    cx_assert(array != NULL, "array corrupt");
    int result = 1;
    cx_type elementType = collection->elementType->real;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    if (element < CX_OFFSET(array, elementSize * length)) {
        result = 0;
    }
    return result;
}

static int cx_iterator_next_array(cx_collection collection, cx_void *array, void **elementPtr) {
    cx_assert(array != NULL, "array corrupt");
    int result;
    result = 1;
    cx_type elementType = collection->elementType->real;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    void *element = *elementPtr;
    if (element < CX_OFFSET(array, elementSize * length)) {
        *elementPtr = CX_OFFSET(array, elementSize);
        result = 0;
    }
    return result;
}
