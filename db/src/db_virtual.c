/* db_virtual.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::virtual::init(lang::virtual object) */
db_int16 db_virtual_init(db_virtual object) {
/* $begin(::hyve::lang::virtual::init) */
    db_method(object)->virtual = TRUE;
    return db_method_init(db_method(object));
/* $end */
}
