/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_boolean_init(
    corto_boolean this)
{
    corto_primitive(this)->kind = CORTO_BOOLEAN;
    corto_primitive(this)->width = CORTO_WIDTH_8;
    return corto_primitive_init((corto_primitive)this);
}

