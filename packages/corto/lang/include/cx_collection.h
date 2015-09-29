/* cx_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_COLLECTION_H
#define CORTO_LANG_COLLECTION_H

#include "corto.h"
#include "cx_type.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::collection::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_collection_castable(cx_collection _this, cx_type type);
#define cx_collection_castable(_this, type) _cx_collection_castable(cx_collection(_this), cx_type(type))

/* ::corto::lang::collection::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_collection_castable_v(cx_collection _this, cx_type type);
#define cx_collection_castable_v(_this, type) _cx_collection_castable_v(cx_collection(_this), cx_type(type))

/* virtual ::corto::lang::collection::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_collection_compatible(cx_collection _this, cx_type type);
#define cx_collection_compatible(_this, type) _cx_collection_compatible(cx_collection(_this), cx_type(type))

/* ::corto::lang::collection::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_collection_compatible_v(cx_collection _this, cx_type type);
#define cx_collection_compatible_v(_this, type) _cx_collection_compatible_v(cx_collection(_this), cx_type(type))

/* ::corto::lang::collection::elementRequiresAlloc() */
CORTO_LANG_EXPORT cx_bool _cx_collection_elementRequiresAlloc(cx_collection _this);
#define cx_collection_elementRequiresAlloc(_this) _cx_collection_elementRequiresAlloc(cx_collection(_this))

/* ::corto::lang::collection::init() */
CORTO_LANG_EXPORT cx_int16 _cx_collection_init(cx_collection _this);
#define cx_collection_init(_this) _cx_collection_init(cx_collection(_this))

/* ::corto::lang::collection::size() */
CORTO_LANG_EXPORT cx_uint32 _cx_collection_size(cx_any _this);
#define cx_collection_size(_this) _cx_collection_size(_this)

#ifdef __cplusplus
}
#endif
#endif

