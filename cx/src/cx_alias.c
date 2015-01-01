/* cx_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::alias::init(lang::alias object) */
cx_int16 cx_alias_init(cx_alias object) {
/* $begin(::cortex::lang::alias::init) */
    cx_primitive(object)->kind = DB_ALIAS;
    cx_primitive(object)->width = DB_WIDTH_WORD;
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
