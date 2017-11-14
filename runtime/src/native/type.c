/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_native_type_init(
    corto_native_type this)
{
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return safe_corto_binary_init(this);
}

