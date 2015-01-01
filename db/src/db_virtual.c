/* cx_virtual.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::virtual::init(lang::virtual object) */
cx_int16 cx_virtual_init(cx_virtual object) {
/* $begin(::cortex::lang::virtual::init) */
    cx_method(object)->virtual = TRUE;
    return cx_method_init(cx_method(object));
/* $end */
}
