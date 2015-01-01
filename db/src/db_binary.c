/* cx_binary.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::binary::init(lang::binary object) */
cx_int16 cx_binary_init(cx_binary object) {
/* $begin(::cortex::lang::binary::init) */
    cx_primitive(object)->kind = DB_BINARY;
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
