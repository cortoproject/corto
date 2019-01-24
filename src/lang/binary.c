/* This is a managed file. Do not delete this comment. */

#include <corto>

int16_t corto_binary_init(
    corto_binary this)
{
    corto_primitive(this)->kind = CORTO_BINARY;
    return corto_primitive_init((corto_primitive)this);
}

