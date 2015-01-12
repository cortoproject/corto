/* cx_text.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::text::init(text object) */
cx_int16 cx_text_init(cx_text object) {
/* $begin(::cortex::lang::text::init) */
    cx_type(object)->hasResources = TRUE;
    cx_primitive(object)->kind = CX_TEXT;
    cx_primitive(object)->width = CX_WIDTH_WORD;
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
