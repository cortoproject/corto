/* cx_boolean.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::boolean::init() */
cx_int16 _cx_boolean_init(cx_boolean _this) {
/* $begin(::corto::lang::boolean::init) */
    cx_primitive(_this)->kind = CX_BOOLEAN;
    cx_primitive(_this)->width = CX_WIDTH_8;
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
