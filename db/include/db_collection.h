/* db_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_collection_H
#define db_collection_H

#include "hyve.h"
#include "db_type.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::collection::castable(lang::type type) */
db_bool db_collection_castable(db_collection _this, db_type type);

/* ::hyve::lang::collection::castable(lang::type type) */
db_bool db_collection_castable_v(db_collection _this, db_type type);

/* ::hyve::lang::collection::elementRequiresAlloc() */
db_bool db_collection_elementRequiresAlloc(db_collection _this);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::collection::init(lang::collection object) */
db_int16 db_collection_init(db_collection object);

/* ::hyve::lang::collection::size() */
db_uint32 db_collection_size(db_any _this);

#ifdef __cplusplus
}
#endif
#endif

