/* cx_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
CX_ITERATOR(iteratorType);
CX_SEQUENCE(seqType, cx_object, );

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

static cx_bool cx_iterator_next_listPtr(void* iterator) {
    iteratorType *iter = iterator;
    cx_bool result = FALSE;
    if ((result = cx_iterHasNext(&iter->is.ll.iter))) {
        iter->current = cx_iterNextPtr(&iter->is.ll.iter);
        result = TRUE;
    }
    return result;
}

static cx_bool cx_iterator_next_list(void* iterator) {
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

cx_bool cx_iterator_next(void* this) {
    CX_ITERATOR(iteratorType);
    iteratorType *iterator = this;
    cx_bool result = FALSE;

    result = iterator->next(iterator);

    return result;
}

cx_int16 cx_iterator_set(void* this, void* collection, cx_collection collectionType) {
    iteratorType *iter = this;
    iter->type = collectionType;

    switch (collectionType->kind) {
        case CX_ARRAY:
            iter->is.array.array = collection;
            iter->is.array.elementSize = cx_type_sizeof(collectionType->elementType);
            iter->is.array.max = CX_OFFSET(iter->is.array.array, collectionType->max * iter->is.array.elementSize);
            iter->current = CX_OFFSET(collection, -iter->is.array.elementSize);
            iter->next = cx_iterator_next_array;
            break;
        case CX_SEQUENCE:
            iter->is.array.array = ((seqType*)collection)->buffer;
            iter->is.array.elementSize = cx_type_sizeof(collectionType->elementType);
            iter->is.array.max = CX_OFFSET(iter->is.array.array, ((seqType*)collection)->length * iter->is.array.elementSize);
            iter->current = CX_OFFSET(iter->is.array.array, -iter->is.array.elementSize);
            iter->next = cx_iterator_next_array;
            break;
        case CX_LIST:
            iter->is.ll.iter = cx_llIter(*(cx_ll*)collection);
            if (cx_collection_elementRequiresAlloc(collectionType)) {
                iter->next = cx_iterator_next_list;
            } else {
                iter->next = cx_iterator_next_listPtr;
            }

            break;
        case CX_MAP:
            iter->next = cx_iterator_next_map;
            break;
    }
    return 0;
}

/* $end */

/* ::corto::lang::iterator::castable(type type) */
cx_bool _cx_iterator_castable_v(cx_iterator this, cx_type type) {
/* $begin(::corto::lang::iterator::castable) */
    return cx_iterator_compatible_v(this, type);
/* $end */
}

/* ::corto::lang::iterator::compatible(type type) */
cx_bool _cx_iterator_compatible_v(cx_iterator this, cx_type type) {
/* $begin(::corto::lang::iterator::compatible) */
    cx_bool result = FALSE;
    if (type->kind == CX_COLLECTION) {
        if (cx_collection(type)->elementType == this->elementType) {
            result = TRUE;
        }
    }
    return result;
/* $end */
}

/* ::corto::lang::iterator::init() */
cx_int16 _cx_iterator_init(cx_iterator this) {
/* $begin(::corto::lang::iterator::init) */
    cx_type(this)->kind = CX_ITERATOR;
    CX_ITERATOR(iteratorType);
    cx_type(this)->size = sizeof(iteratorType);
    return cx_type_init(cx_type(this));
/* $end */
}
