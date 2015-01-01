/* db_alias.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::alias::init(lang::alias object) */
db_int16 db_alias_init(db_alias object) {
/* $begin(::cortex::lang::alias::init) */
    db_primitive(object)->kind = DB_ALIAS;
    db_primitive(object)->width = DB_WIDTH_WORD;
    return db_primitive_init((db_primitive)object);
/* $end */
}
