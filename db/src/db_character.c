/* db_character.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::character::init(lang::character object) */
db_int16 db_character_init(db_character object) {
/* $begin(::cortex::lang::character::init) */
    db_primitive(object)->kind = DB_CHARACTER;
    return db_primitive_init((db_primitive)object);
/* $end */
}
