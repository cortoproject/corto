/* cx_text.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::text::init() */
cx_int16 _cx_text_init(cx_text this) {
/* $begin(::corto::lang::text::init) */
    cx_type(this)->hasResources = TRUE;
    cx_primitive(this)->kind = CX_TEXT;
    cx_primitive(this)->width = CX_WIDTH_WORD;
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
