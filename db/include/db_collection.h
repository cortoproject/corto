/* db_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_collection_H
#define db_collection_H

#include "cortex.h"
#include "db_type.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::collection::castable(lang::type type) */
db_bool db_collection_castable(db_collection _this, db_type type);

/* ::cortex::lang::collection::castable(lang::type type) */
db_bool db_collection_castable_v(db_collection _this, db_type type);

/* ::cortex::lang::collection::elementRequiresAlloc() */
db_bool db_collection_elementRequiresAlloc(db_collection _this);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::collection::init(lang::collection object) */
db_int16 db_collection_init(db_collection object);

/* ::cortex::lang::collection::size() */
db_uint32 db_collection_size(db_any _this);

#ifdef __cplusplus
}
#endif
#endif

