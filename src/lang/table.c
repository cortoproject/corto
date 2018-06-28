/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_table_construct(
    corto_table this)
{
    corto_set_ref(&corto_type(this)->parent_type, corto_tableinstance_o);
    return safe_corto_container_construct(this);
}
