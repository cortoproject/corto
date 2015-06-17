/* cx_text.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::text::init() */
cx_int16 cx_text_init(cx_text _this) {
/* $begin(::cortex::lang::text::init) */
    cx_type(_this)->hasResources = TRUE;
    cx_primitive(_this)->kind = CX_TEXT;
    cx_primitive(_this)->width = CX_WIDTH_WORD;
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
