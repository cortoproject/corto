/* cx_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::alias::construct() */
cx_int16 _cx_alias_construct(cx_alias this) {
/* $begin(::corto::lang::alias::construct) */

    CX_UNUSED(this);
    return 0;

/* $end */
}

/* ::corto::lang::alias::init() */
cx_int16 _cx_alias_init(cx_alias this) {
/* $begin(::corto::lang::alias::init) */

    return cx_member_init(this);

/* $end */
}
