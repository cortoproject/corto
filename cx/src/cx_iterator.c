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

static cx_bool cx_iterator_hasNext_array(cx_collection collection, cx_void *array, void *element) {
    cx_assert(array != NULL, "array corrupt");
    cx_bool result = FALSE;
    cx_type elementType = collection->elementType->real;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    void *lastElement = CX_OFFSET(array, elementSize * length);
    cx_assert(element <= lastElement, "array element out of bounds");
    if (element < lastElement) {
        result = TRUE;
    }
    return result;
}

/* Returns 0 on succes */
static int cx_iterator_next_array(cx_collection collection, cx_void *array, void *element, void **next) {
    cx_assert(array != NULL, "array corrupt");
    int result = 1;
    cx_type elementType = collection->elementType->real;
    cx_uint32 elementSize = cx_type_sizeof(elementType);
    cx_uint32 length = collection->max;
    void *lastElement = CX_OFFSET(array, elementSize * length);
    cx_assert(element <= lastElement, "array element out of bounds");
    if (element < lastElement) {
        *next = CX_OFFSET(element, elementSize);
        result = 0;
    }
    return result;
}

static cx_bool cx_iterator_hasNext_list(cx_collection collection, cx_ll list, cx_iter *iter) {
    CX_UNUSED(collection);
    CX_UNUSED(list);

    cx_assert(list != NULL, "list corrupt");

    cx_bool result = FALSE;

    if (cx_iterHasNext(iter)) {
        result = TRUE;
    }

    return result;
}

/* Returns 0 on success */
static int cx_iterator_next_list(cx_collection collection, cx_ll list, cx_iter *iter, void **next) {
    CX_UNUSED(collection);
    CX_UNUSED(list);

    cx_assert(list != NULL, "list corrupt");

    int result = 1;

    if (cx_iterHasNext(iter)) {
        *next = cx_iterNext(iter);
    } else {
        cx_critical("illegal use of next when iterator doesn't have next");
    }

    return result;
}

/* $end */

/* ::cortex::lang::iterator::init() */
cx_int16 cx_iterator_init(cx_iterator _this) {
/* $begin(::cortex::lang::iterator::init) */
    cx_type(_this)->kind = CX_ITERATOR;
    CX_ITERATOR(iteratorType);
    cx_type(_this)->size = sizeof(iteratorType);
    return cx_type_init(cx_type(_this));
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
            result = cx_iterator_hasNext_array(iterator->type, iterator->value, iterator->element);
            break;
        case CX_SEQUENCE:
            break;
        case CX_LIST:
            cx_iterator_hasNext_list(iterator->type, iterator->value, iterator->element);
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
    int error;
    cx_any result;

    error = 0;
    result.type = iterator->type->elementType->real;
    result.owner = FALSE;

    switch (iterator->type->kind) {
        case CX_ARRAY:
            error = cx_iterator_next_array(iterator->type, iterator->value, iterator->element, &result.value);
            if (!error) {
                result.value = iterator->element;
            }
            break;
        case CX_SEQUENCE:
            break;
        case CX_LIST:
            cx_iterator_next_list(iterator->type, iterator->value, iterator->element, &result.value);
            break;
        case CX_MAP:
            break;
        default:
            break;
    }
    if (error) {
        cx_critical("failed to retrieve next element");
    }

    return result;
/* $end */
}
