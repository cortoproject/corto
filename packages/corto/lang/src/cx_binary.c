/* cx_binary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* ::corto::lang::binary::init() */
cx_int16 _cx_binary_init(cx_binary this) {
/* $begin(::corto::lang::binary::init) */
    cx_primitive(this)->kind = CX_BINARY;
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
