/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

typedef struct __dummySeq {
    corto_uint32 length;
    void* buffer;
}__dummySeq;

/* Allocate buffer of specific size */
int corto_sequence_alloc(corto_collection this, corto_void* collection, corto_uint32 elements) {
    corto_uint32 elementSize;

    elementSize = corto_type_sizeof(this->element_type);

    ((__dummySeq*)collection)->buffer = corto_alloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}

int16_t corto_sequence_construct(
    corto_sequence this)
{
    corto_type element_type = corto_collection(this)->element_type;
    if (!element_type) {
        corto_error("no elementtype provided for sequence");
        goto error;
    }

    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_type(this)->size = sizeof(__dummySeq);
    corto_type(this)->alignment = CORTO_ALIGNMENT(__dummySeq);
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;

    if (element_type->flags & CORTO_TYPE_HAS_REFERENCES ||
        element_type->reference)
    {
        corto_type(this)->flags |= CORTO_TYPE_HAS_REFERENCES;
    }

    return corto_type_construct(corto_type(this));
error:
    return -1;
}

int16_t corto_sequence_init(
    corto_sequence this)
{
    corto_collection(this)->kind = CORTO_SEQUENCE;
    return corto_collection_init(corto_collection(this));
}
