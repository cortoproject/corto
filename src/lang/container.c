/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_container_construct(
    corto_container this)
{

    /* Containers are always scoped */
    corto_type(this)->attr = CORTO_ATTR_DEFAULT|CORTO_ATTR_NAMED;

    return safe_corto_class_construct(this);
}

