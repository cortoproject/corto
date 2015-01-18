/* cx_virtual.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* ::cortex::lang::virtual::init() */
cx_int16 cx_virtual_init(cx_virtual _this) {
/* $begin(::cortex::lang::virtual::init) */
    cx_method(_this)->virtual = TRUE;
    return cx_method_init(cx_method(_this));
/* $end */
}
