/* cx_int.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::int::init() */
cx_int16 cx_int_init(cx_int _this) {
/* $begin(::cortex::lang::int::init) */
    cx_primitive(_this)->kind = CX_INTEGER;
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
