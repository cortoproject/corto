/* cx_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"


static int cx_iterator_advance_array(cx_collection collection, cx_void *array, void **elementPtr) {
    int result;
    result = 1;
    if (array) {
        cx_type elementType = collection->elementType->real;
        cx_uint32 elementSize = cx_type_sizeof(elementType);
        cx_uint32 length = collection->max;
        void *element = *elementPtr;
        if (element < CX_OFFSET(array, elementSize * length)) {
            *elementPtr = CX_OFFSET(array, elementSize);
            result = 0;
        }
    }
    return result;
}

/* ::cortex::lang::iterator::advance() */
cx_any cx_iterator_advance(cx_any _this) {
/* $begin(::cortex::lang::iterator::advance) */
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this.value;
    /* we need it to have been initialized before */
    CX_UNUSED(iterator);
    switch (iterator->type->kind) {
        case CX_ARRAY:
            cx_iterator_advance_array(iterator->type, iterator->value, &(iterator->element));
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
    cx_any result;
    result.type = iterator->type->elementType->real;
    result.value = iterator->element;
    result.owner = FALSE;
    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::iterator::init(lang::iterator object) */
cx_int16 cx_iterator_init(cx_iterator object) {
/* $begin(::cortex::lang::iterator::init) */
    cx_type(object)->kind = CX_ITERATOR;
    return cx_type__init(cx_type(object));
/* $end */
}

/* ::cortex::lang::iterator::retrieve() */
cx_any cx_iterator_retrieve(cx_any _this) {
/* $begin(::cortex::lang::iterator::retrieve) */
    return _this;
/* $end */
}
