/* corto_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
CORTO_ITERATOR(iteratorType);
CORTO_SEQUENCE(seqType, corto_object, );

/* Combined hasNext and next */
static corto_bool corto_iterator_next_array(void* iterator) {
    iteratorType *iter = iterator;
    corto_uint32 elementSize = iter->is.array.elementSize;
    void *current = iter->current;
    corto_bool result = FALSE;
    current = CORTO_OFFSET(current, elementSize);
    if (current  < iter->is.array.max) {
        iter->current = current;
        result = TRUE;
    }
    return result;
}

static corto_bool corto_iterator_next_listPtr(void* iterator) {
    iteratorType *iter = iterator;
    corto_bool result = FALSE;
    if ((result = corto_iterHasNext(&iter->is.ll.iter))) {
        iter->current = corto_iterNextPtr(&iter->is.ll.iter);
        result = TRUE;
    }
    return result;
}

static corto_bool corto_iterator_next_list(void* iterator) {
    iteratorType *iter = iterator;
    corto_bool result = FALSE;
    if ((result = corto_iterHasNext(&iter->is.ll.iter))) {
        iter->current = corto_iterNext(&iter->is.ll.iter);
        result = TRUE;
    }
    return result;
}

static corto_bool corto_iterator_next_map(void* iterator) {
    CORTO_UNUSED(iterator);
    // TODO implement
    return 1;
}

corto_bool corto_iterator_next(void* this) {
    CORTO_ITERATOR(iteratorType);
    iteratorType *iterator = this;
    corto_bool result = FALSE;

    result = iterator->next(iterator);

    return result;
}

corto_int16 corto_iterator_set(void* this, void* collection, corto_collection collectionType) {
    iteratorType *iter = this;
    iter->type = collectionType;

    switch (collectionType->kind) {
        case CORTO_ARRAY:
            iter->is.array.array = collection;
            iter->is.array.elementSize = corto_type_sizeof(collectionType->elementType);
            iter->is.array.max = CORTO_OFFSET(iter->is.array.array, collectionType->max * iter->is.array.elementSize);
            iter->current = CORTO_OFFSET(collection, -iter->is.array.elementSize);
            iter->next = corto_iterator_next_array;
            break;
        case CORTO_SEQUENCE:
            iter->is.array.array = ((seqType*)collection)->buffer;
            iter->is.array.elementSize = corto_type_sizeof(collectionType->elementType);
            iter->is.array.max = CORTO_OFFSET(iter->is.array.array, ((seqType*)collection)->length * iter->is.array.elementSize);
            iter->current = CORTO_OFFSET(iter->is.array.array, -iter->is.array.elementSize);
            iter->next = corto_iterator_next_array;
            break;
        case CORTO_LIST:
            iter->is.ll.iter = corto_llIter(*(corto_ll*)collection);
            if (corto_collection_elementRequiresAlloc(collectionType)) {
                iter->next = corto_iterator_next_list;
            } else {
                iter->next = corto_iterator_next_listPtr;
            }

            break;
        case CORTO_MAP:
            iter->next = corto_iterator_next_map;
            break;
    }
    return 0;
}

/* $end */

/* ::corto::lang::iterator::castable(type type) */
corto_bool _corto_iterator_castable_v(corto_iterator this, corto_type type) {
/* $begin(::corto::lang::iterator::castable) */
    return corto_iterator_compatible_v(this, type);
/* $end */
}

/* ::corto::lang::iterator::compatible(type type) */
corto_bool _corto_iterator_compatible_v(corto_iterator this, corto_type type) {
/* $begin(::corto::lang::iterator::compatible) */
    corto_bool result = FALSE;
    if (type->kind == CORTO_COLLECTION) {
        if (corto_collection(type)->elementType == this->elementType) {
            result = TRUE;
        }
    }
    return result;
/* $end */
}

/* ::corto::lang::iterator::init() */
corto_int16 _corto_iterator_init(corto_iterator this) {
/* $begin(::corto::lang::iterator::init) */
    corto_type(this)->kind = CORTO_ITERATOR;
    CORTO_ITERATOR(iteratorType);
    corto_type(this)->size = sizeof(iteratorType);
    return corto_type_init(corto_type(this));
/* $end */
}
