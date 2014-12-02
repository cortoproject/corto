/* db_float.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::float::init(lang::float object) */
db_int16 db_float_init(db_float object) {
/* $begin(::hyve::lang::float::init) */
    db_primitive(object)->kind = DB_FLOAT;
    return db_primitive_init((db_primitive)object);
/* $end */
}
