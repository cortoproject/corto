/* db_boolean.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::boolean::init(lang::boolean object) */
db_int16 db_boolean_init(db_boolean object) {
/* $begin(::hyve::lang::boolean::init) */
    db_primitive(object)->kind = DB_BOOLEAN;
    db_primitive(object)->width = DB_WIDTH_8;
    return db_primitive_init((db_primitive)object);
/* $end */
}
