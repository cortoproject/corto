/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_character_init(
    corto_character this)
{
    corto_primitive(this)->kind = CORTO_CHARACTER;
    return corto_primitive_init((corto_primitive)this);
}

