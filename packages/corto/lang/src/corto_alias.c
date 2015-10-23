/* corto_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::alias::construct() */
corto_int16 _corto_alias_construct(corto_alias this) {
/* $begin(::corto::lang::alias::construct) */

    CORTO_UNUSED(this);
    return 0;

/* $end */
}

/* ::corto::lang::alias::init() */
corto_int16 _corto_alias_init(corto_alias this) {
/* $begin(::corto::lang::alias::init) */

    return corto_member_init(this);

/* $end */
}
