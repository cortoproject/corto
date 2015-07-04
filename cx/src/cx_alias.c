/* cx_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::alias::init() */
cx_int16 cx_alias_init(cx_alias _this) {
/* $begin(::cortex::lang::alias::init) */
    cx_primitive(_this)->kind = CX_ALIAS;
    cx_primitive(_this)->width = CX_WIDTH_WORD;
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
