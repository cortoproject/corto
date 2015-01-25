/* cx_sequence.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
typedef struct __dummySeq {
    cx_uint32 length;
    void* buffer;
}__dummySeq;

/* Allocate buffer of specific size */
int cx_sequence_alloc(cx_collection _this, cx_void* collection, cx_uint32 elements) {
    cx_uint32 elementSize;

    elementSize = cx_type_sizeof(_this->elementType);

    ((__dummySeq*)collection)->buffer = cx_malloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}
/* $end */

/* ::cortex::lang::sequence::construct() */
cx_int16 cx_sequence_construct(cx_sequence _this) {
/* $begin(::cortex::lang::sequence::construct) */
    cx_type(_this)->hasResources = TRUE;
    cx_type(_this)->size = sizeof(__dummySeq);
    cx_type(_this)->alignment = CX_ALIGNMENT(__dummySeq);
    return cx_type_construct(cx_type(_this));
/* $end */
}

/* ::cortex::lang::sequence::init() */
cx_int16 cx_sequence_init(cx_sequence _this) {
/* $begin(::cortex::lang::sequence::init) */
    cx_collection(_this)->kind = CX_SEQUENCE;
    return cx_collection_init(cx_collection(_this));
/* $end */
}

/* ::cortex::lang::sequence::size(uint32 size) */
cx_void cx_sequence_size(cx_any _this, cx_uint32 size) {
/* $begin(::cortex::lang::sequence::size) */
    cx_uint32 oldSize, elementSize;

    oldSize = ((cx_objectSeq*)_this.value)->length;
    elementSize = cx_type_sizeof(cx_collection(_this.type)->elementType);

    ((cx_objectSeq*)_this.value)->buffer = cx_realloc(((cx_objectSeq*)_this.value)->buffer, size * elementSize);
    memset(CX_OFFSET(((cx_objectSeq*)_this.value)->buffer, oldSize * elementSize), 0, elementSize * (size - oldSize));
    ((cx_objectSeq*)_this.value)->length = size;
/* $end */
}
