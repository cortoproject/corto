/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_map_construct(
    corto_map this)
{
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
    corto_type(this)->size = sizeof(corto_map);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_map);
    
    corto_type element_type = this->element_type;
    if (!element_type) {
        corto_error("no elementtype provided for list");
        goto error;
    }

    if (element_type->flags & CORTO_TYPE_HAS_REFERENCES ||
        element_type->reference)
    {
        corto_type(this)->flags |= CORTO_TYPE_HAS_REFERENCES;
    }

    corto_set_ref(&corto_collection(this)->element_type, element_type);
    corto_collection(this)->max = this->max;

    return corto_type_construct(corto_type(this));
error:
    return -1;
}

int16_t corto_map_init(
    corto_map this)
{
    corto_collection(this)->kind = CORTO_MAP;
    return corto_collection_init(corto_collection(this));
}
