/* db_map.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::map::construct(lang::map object) */
db_int16 db_map_construct(db_map object) {
/* $begin(::cortex::lang::map::construct) */
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(db_map);
	db_type(object)->alignment = DB_ALIGNMENT(db_map);
	db_collection(object)->elementType = object->elementType;
	db_keep_ext(object, object->elementType, "keep object for elementType");
	db_collection(object)->max = object->max;
	return db_type_construct(db_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::map::init(lang::map object) */
db_int16 db_map_init(db_map object) {
/* $begin(::cortex::lang::map::init) */
    db_collection(object)->kind = DB_MAP;
    return db_collection_init(db_collection(object));
/* $end */
}
