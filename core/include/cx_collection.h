/* cx_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_collection_H
#define cx_collection_H

#include "corto.h"
#include "cx_type.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::collection::castable(type type) */
cx_bool cx_collection_castable(cx_collection _this, cx_type type);

/* ::corto::lang::collection::castable(type type) */
cx_bool _cx_collection_castable_v(cx_collection _this, cx_type type);
#define cx_collection_castable_v(_this, type) _cx_collection_castable_v(cx_collection(_this), cx_type(type))

/* virtual ::corto::lang::collection::compatible(type type) */
cx_bool cx_collection_compatible(cx_collection _this, cx_type type);

/* ::corto::lang::collection::compatible(type type) */
cx_bool _cx_collection_compatible_v(cx_collection _this, cx_type type);
#define cx_collection_compatible_v(_this, type) _cx_collection_compatible_v(cx_collection(_this), cx_type(type))

/* ::corto::lang::collection::elementRequiresAlloc() */
cx_bool _cx_collection_elementRequiresAlloc(cx_collection _this);
#define cx_collection_elementRequiresAlloc(_this) _cx_collection_elementRequiresAlloc(cx_collection(_this))

/* ::corto::lang::collection::init() */
cx_int16 _cx_collection_init(cx_collection _this);
#define cx_collection_init(_this) _cx_collection_init(cx_collection(_this))

/* ::corto::lang::collection::size() */
cx_uint32 _cx_collection_size(cx_any _this);
#define cx_collection_size(_this) _cx_collection_size(_this)

#ifdef __cplusplus
}
#endif
#endif

