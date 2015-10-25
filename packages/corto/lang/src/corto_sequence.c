/* $CORTO_GENERATED
 *
 * corto_sequence.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "corto.h"

/* $header() */
typedef struct __dummySeq {
    corto_uint32 length;
    void* buffer;
}__dummySeq;

/* Allocate buffer of specific size */
int corto_sequence_alloc(corto_collection this, corto_void* collection, corto_uint32 elements) {
    corto_uint32 elementSize;

    elementSize = corto_type_sizeof(this->elementType);

    ((__dummySeq*)collection)->buffer = corto_alloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}
/* $end */

corto_int16 _corto_sequence_construct(corto_sequence this) {
/* $begin(::corto::lang::sequence::construct) */
    corto_type(this)->hasResources = TRUE;
    corto_type(this)->size = sizeof(__dummySeq);
    corto_type(this)->alignment = CORTO_ALIGNMENT(__dummySeq);
    if (!corto_collection(this)->elementType) {
        corto_error("no elementtype provided for sequence");
        goto error;
    }
    return corto_type_construct(corto_type(this));
error:
    return -1;
/* $end */
}

corto_int16 _corto_sequence_init(corto_sequence this) {
/* $begin(::corto::lang::sequence::init) */
    corto_collection(this)->kind = CORTO_SEQUENCE;
    return corto_collection_init(corto_collection(this));
/* $end */
}

corto_void _corto_sequence_size(corto_any this, corto_uint32 size) {
/* $begin(::corto::lang::sequence::size) */
    corto_uint32 oldSize, elementSize;

    oldSize = ((corto_objectseq*)this.value)->length;
    elementSize = corto_type_sizeof(corto_collection(this.type)->elementType);

    ((corto_objectseq*)this.value)->buffer = corto_realloc(((corto_objectseq*)this.value)->buffer, size * elementSize);
    if (size > oldSize) {
        memset(CORTO_OFFSET(((corto_objectseq*)this.value)->buffer, oldSize * elementSize), 0, elementSize * (size - oldSize));
    } else {
        memset(((corto_objectseq*)this.value)->buffer, 0, elementSize * size);
    }
    ((corto_objectseq*)this.value)->length = size;
/* $end */
}
