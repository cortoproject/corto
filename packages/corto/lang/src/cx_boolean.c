/* cx_boolean.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* ::corto::lang::boolean::init() */
cx_int16 _cx_boolean_init(cx_boolean this) {
/* $begin(::corto::lang::boolean::init) */
    cx_primitive(this)->kind = CX_BOOLEAN;
    cx_primitive(this)->width = CX_WIDTH_8;
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
