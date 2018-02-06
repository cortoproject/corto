/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_map_construct(
    corto_map this)
{
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
    corto_type(this)->size = sizeof(corto_map);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_map);
    corto_collection(this)->elementType = this->elementType;
    corto_claim(this->elementType);
    corto_collection(this)->max = this->max;
    return corto_type_construct(corto_type(this));
}

int16_t corto_map_init(
    corto_map this)
{
    corto_collection(this)->kind = CORTO_MAP;
    return corto_collection_init(corto_collection(this));
}
