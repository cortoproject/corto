/* corto_uint.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::uint::init() */
corto_int16 _corto_uint_init(corto_uint this) {
/* $begin(::corto::lang::uint::init) */
    corto_primitive(this)->kind = CORTO_UINTEGER;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
