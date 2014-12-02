/* db_text.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::text::init(lang::text object) */
db_int16 db_text_init(db_text object) {
/* $begin(::hyve::lang::text::init) */
	db_type(object)->hasResources = TRUE;
    db_primitive(object)->kind = DB_TEXT;
    db_primitive(object)->width = DB_WIDTH_WORD;
    return db_primitive_init((db_primitive)object);
/* $end */
}
