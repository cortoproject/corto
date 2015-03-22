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
CX_ITERATOR(iteratorType);
CX_SEQUENCE(seqType, cx_object, );

cx_int16 cx_iterator_set(void* _this, void* collection, cx_collection collectionType) {
    iteratorType *iter = _this;
    iter->type = collectionType;

    switch (collectionType->kind) {
        case CX_ARRAY:
            iter->is.array.array = collection;
            iter->is.array.elementSize = cx_type_sizeof(collectionType->elementType);
            iter->is.array.max = CX_OFFSET(iter->is.array.array, collectionType->max * iter->is.array.elementSize);
            iter->current = CX_OFFSET(collection, -iter->is.array.elementSize);
            break;
        case CX_SEQUENCE:
            iter->is.array.array = ((seqType*)collection)->buffer;
            iter->is.array.elementSize = cx_type_sizeof(collectionType->elementType);
            iter->is.array.max = CX_OFFSET(iter->is.array.array, ((seqType*)collection)->length * iter->is.array.elementSize);
            iter->current = CX_OFFSET(iter->is.array.array, -iter->is.array.elementSize);
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

/* Combined hasNext and next */
static cx_bool cx_iterator_next_array(void* iterator) {
    iteratorType *iter = iterator;
    cx_uint32 elementSize = iter->is.array.elementSize;
    void *current = iter->current;
    cx_bool result = FALSE;
    current = CX_OFFSET(current, elementSize);
    if (current  < iter->is.array.max) {
        iter->current = current;
        result = TRUE;
    }
    return result;
}

static cx_bool cx_iterator_next_ll(void* iterator) {
    iteratorType *iter = iterator;
    cx_bool result = FALSE;
    if ((result = cx_iterHasNext(&iter->is.ll.iter))) {
        iter->current = cx_iterNext(&iter->is.ll.iter);
        result = TRUE;
    }
    return result;
}

static cx_bool cx_iterator_next_map(void* iterator) {
    CX_UNUSED(iterator);
    // TODO implement
    return 1;
}

cx_bool cx_iterator_next(void* _this) {
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = _this;
    cx_bool result = FALSE;

    switch (iterator->type->kind) {
        case CX_ARRAY:
        case CX_SEQUENCE:
            result = cx_iterator_next_array(iterator);
            break;
        case CX_LIST:
            result = cx_iterator_next_ll(iterator);
            break;
        case CX_MAP:
            result = cx_iterator_next_map(iterator);
            break;
        default:
            break;
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
