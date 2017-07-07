/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_table_construct(
    corto_table this)
{

    corto_ptr_setref(&corto_type(this)->options.parentType, corto_tableinstance_o);

    return safe_corto_container_construct(this);
}

