/* cx_virtual.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* ::corto::lang::virtual::init() */
cx_int16 _cx_virtual_init(cx_virtual this) {
/* $begin(::corto::lang::virtual::init) */
    cx_method(this)->virtual = TRUE;
    return cx_method_init(cx_method(this));
/* $end */
}
