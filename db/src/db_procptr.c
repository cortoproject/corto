/* db_procptr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::procptr::init(lang::procptr object) */
db_int16 db_procptr_init(db_procptr object) {
/* $begin(::hyve::lang::procptr::init) */
    db_int16 result;

    db_interface(object)->base = db_interface(db_procptrdata_o);

    result = db_struct_init(db_struct(object));
    if(result) {
        goto error;
    }

    db_interface(object)->kind = DB_PROCPTR;

    return 0;
error:
    return -1;
/* $end */
}
