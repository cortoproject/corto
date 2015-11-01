/* $CORTO_GENERATED
 *
 * corto_bitmask.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto__bitmask.h"
corto_int16 corto__bitmask_bindConstant(corto_bitmask this, corto_constant* c) {
    if (corto_checkState(corto_type_o, CORTO_DEFINED)) {
        *c = 0x1 << corto_scopeSize(this);
    }
    corto_enum(this)->constants.buffer = corto_realloc(corto_enum(this)->constants.buffer, (corto_enum(this)->constants.length+1) * sizeof(corto_constant*));
    corto_enum(this)->constants.buffer[corto_enum(this)->constants.length] = c;
    corto_enum(this)->constants.length++;
    
    corto_claim(c);

    return 0;
}
/* $end */

corto_int16 _corto_bitmask_init(corto_bitmask this) {
/* $begin(::corto::lang::bitmask::init) */
    corto_primitive(this)->kind = CORTO_BITMASK;
    corto_primitive(this)->width = CORTO_WIDTH_32;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
