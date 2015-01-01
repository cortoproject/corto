/* db_uint.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::uint::init(lang::uint object) */
db_int16 db_uint_init(db_uint object) {
/* $begin(::cortex::lang::uint::init) */
    db_primitive(object)->kind = DB_UINTEGER;
    return db_primitive_init((db_primitive)object);
/* $end */
}
