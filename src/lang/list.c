/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_list_construct(
    corto_list this)
{
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
    corto_type(this)->size = sizeof(corto_ll);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_ll);
    corto_type elementType = corto_collection(this)->elementType;
    if (!elementType) {
        corto_error("no elementtype provided for list");
        goto error;
    }

    if (elementType->flags & CORTO_TYPE_HAS_REFERENCES ||
        elementType->reference)
    {
        corto_type(this)->flags |= CORTO_TYPE_HAS_REFERENCES;
    }

    return corto_type_construct(corto_type(this));
error:
    return -1;
}

int16_t corto_list_init(
    corto_list this)
{
    corto_collection(this)->kind = CORTO_LIST;
    return corto_collection_init(corto_collection(this));
}
