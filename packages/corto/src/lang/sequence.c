/* $CORTO_GENERATED
 *
 * sequence.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

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

int16_t _corto_sequence_construct(
    corto_sequence this)
{
/* $begin(corto/lang/sequence/construct) */
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
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

int16_t _corto_sequence_init(
    corto_sequence this)
{
/* $begin(corto/lang/sequence/init) */
    corto_collection(this)->kind = CORTO_SEQUENCE;
    return corto_collection_init(corto_collection(this));
/* $end */
}
