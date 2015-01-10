/* cx_uint.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::uint::init(uint object) */
cx_int16 cx_uint_init(cx_uint object) {
/* $begin(::cortex::lang::uint::init) */
    cx_primitive(object)->kind = CX_UINTEGER;
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
