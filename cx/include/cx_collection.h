/* cx_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_collection_H
#define cx_collection_H

#include "cortex.h"
#include "cx_type.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::collection::castable(type type) */
cx_bool cx_collection_castable(cx_collection _this, cx_type type);

/* ::cortex::lang::collection::castable(type type) */
cx_bool cx_collection_castable_v(cx_collection _this, cx_type type);

/* virtual ::cortex::lang::collection::compatible(type type) */
cx_bool cx_collection_compatible(cx_collection _this, cx_type type);

/* ::cortex::lang::collection::compatible(type type) */
cx_bool cx_collection_compatible_v(cx_collection _this, cx_type type);

/* ::cortex::lang::collection::elementRequiresAlloc() */
cx_bool cx_collection_elementRequiresAlloc(cx_collection _this);

/* ::cortex::lang::collection::init() */
cx_int16 cx_collection_init(cx_collection _this);

/* ::cortex::lang::collection::size() */
cx_uint32 cx_collection_size(cx_any _this);

#ifdef __cplusplus
}
#endif
#endif

