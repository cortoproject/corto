/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_alias_construct(
    corto_alias this)
{

    CORTO_UNUSED(this);
    return 0;

}

int16_t corto_alias_init(
    corto_alias this)
{

    return safe_corto_member_init(this);

}

