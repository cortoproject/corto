/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_override_init(
    corto_override this)
{

    return corto_method_init(corto_method(this));
}

