/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_int_init(
    corto_int this)
{
    corto_primitive(this)->kind = CORTO_INTEGER;
    return corto_primitive_init((corto_primitive)this);
}

