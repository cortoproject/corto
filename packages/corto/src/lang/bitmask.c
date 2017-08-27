/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


#include "_bitmask.h"

corto_int16 corto__bitmask_bindConstant(corto_bitmask this, corto_constant* c) {
    if (corto_checkState(corto_type_o, CORTO_VALID)) {
        *c = 0x1 << (corto_scopeSize(this) - 1);
    }
    corto_enum(this)->constants.buffer = corto_realloc(corto_enum(this)->constants.buffer, (corto_enum(this)->constants.length+1) * sizeof(corto_constant*));
    corto_enum(this)->constants.buffer[corto_enum(this)->constants.length] = c;
    corto_enum(this)->constants.length++;

    corto_claim(c);

    return 0;
}

int16_t corto_bitmask_init(
    corto_bitmask this)
{
    corto_primitive(this)->kind = CORTO_BITMASK;
    corto_primitive(this)->width = CORTO_WIDTH_32;
    return corto_primitive_init((corto_primitive)this);
}

