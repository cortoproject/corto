/* cx_sequence.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* $header() */
typedef struct __dummySeq {
    cx_uint32 length;
    void* buffer;
}__dummySeq;

/* Allocate buffer of specific size */
int cx_sequence_alloc(cx_collection this, cx_void* collection, cx_uint32 elements) {
    cx_uint32 elementSize;

    elementSize = cx_type_sizeof(this->elementType);

    ((__dummySeq*)collection)->buffer = cx_alloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}
/* $end */

/* ::corto::lang::sequence::construct() */
cx_int16 _cx_sequence_construct(cx_sequence this) {
/* $begin(::corto::lang::sequence::construct) */
    cx_type(this)->hasResources = TRUE;
    cx_type(this)->size = sizeof(__dummySeq);
    cx_type(this)->alignment = CX_ALIGNMENT(__dummySeq);
    if (!cx_collection(this)->elementType) {
        cx_error("no elementtype provided for sequence");
        goto error;
    }
    return cx_type_construct(cx_type(this));
error:
    return -1;
/* $end */
}

/* ::corto::lang::sequence::init() */
cx_int16 _cx_sequence_init(cx_sequence this) {
/* $begin(::corto::lang::sequence::init) */
    cx_collection(this)->kind = CX_SEQUENCE;
    return cx_collection_init(cx_collection(this));
/* $end */
}

/* ::corto::lang::sequence::size(uint32 size) */
cx_void _cx_sequence_size(cx_any this, cx_uint32 size) {
/* $begin(::corto::lang::sequence::size) */
    cx_uint32 oldSize, elementSize;

    oldSize = ((cx_objectseq*)this.value)->length;
    elementSize = cx_type_sizeof(cx_collection(this.type)->elementType);

    ((cx_objectseq*)this.value)->buffer = cx_realloc(((cx_objectseq*)this.value)->buffer, size * elementSize);
    if (size > oldSize) {
        memset(CX_OFFSET(((cx_objectseq*)this.value)->buffer, oldSize * elementSize), 0, elementSize * (size - oldSize));
    } else {
        memset(((cx_objectseq*)this.value)->buffer, 0, elementSize * size);
    }
    ((cx_objectseq*)this.value)->length = size;
/* $end */
}
