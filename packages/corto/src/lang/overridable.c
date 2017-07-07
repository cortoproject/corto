/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_overridable_init(
    corto_overridable this)
{
    corto_function(this)->overridable = TRUE;
    return corto_method_init(corto_method(this));
}

