/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_uint_init(
    corto_uint this)
{
    corto_primitive(this)->kind = CORTO_UINTEGER;
    return corto_primitive_init((corto_primitive)this);
}

