/* cx_float.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::float::init(lang::float object) */
cx_int16 cx_float_init(cx_float object) {
/* $begin(::cortex::lang::float::init) */
    cx_primitive(object)->kind = DB_FLOAT;
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
