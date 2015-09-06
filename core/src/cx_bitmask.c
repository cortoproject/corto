/* cx_bitmask.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx__bitmask.h"
cx_int16 cx__bitmask_bindConstant(cx_bitmask this, cx_constant* c) {
    if (cx_checkState(cx_type_o, CX_DEFINED)) {
        *c = 0x1 << (cx_scopeSize(this)-1);
    }
    cx_enum(this)->constants.buffer = cx_realloc(cx_enum(this)->constants.buffer, (cx_enum(this)->constants.length+1) * sizeof(cx_constant*));
    cx_enum(this)->constants.buffer[cx_enum(this)->constants.length] = c;
    cx_enum(this)->constants.length++;
    
    cx_claim(c);

    return 0;
}
/* $end */

/* ::corto::lang::bitmask::init() */
cx_int16 _cx_bitmask_init(cx_bitmask this) {
/* $begin(::corto::lang::bitmask::init) */
    cx_primitive(this)->kind = CX_BITMASK;
    cx_primitive(this)->width = CX_WIDTH_32;
    cx_setref(&cx_type(this)->defaultType, cx_constant_o);
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
