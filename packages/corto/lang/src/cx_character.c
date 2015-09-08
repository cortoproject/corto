/* cx_character.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* ::corto::lang::character::init() */
cx_int16 _cx_character_init(cx_character this) {
/* $begin(::corto::lang::character::init) */
    cx_primitive(this)->kind = CX_CHARACTER;
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
