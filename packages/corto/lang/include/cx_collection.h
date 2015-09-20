/* cx_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_collection_H
#define corto_lang_collection_H

#include "corto.h"
#include "cx_type.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::collection::castable(type type) */
cx_bool _cx_collection_castable(cx_collection _this, cx_type type);
#define cx_collection_castable(_this, type) _cx_collection_castable(cx_collection(_this), cx_type(type))

/* ::corto::lang::collection::castable(type type) */
cx_bool _cx_collection_castable_v(cx_collection _this, cx_type type);
#define cx_collection_castable_v(_this, type) _cx_collection_castable_v(cx_collection(_this), cx_type(type))

/* virtual ::corto::lang::collection::compatible(type type) */
cx_bool _cx_collection_compatible(cx_collection _this, cx_type type);
#define cx_collection_compatible(_this, type) _cx_collection_compatible(cx_collection(_this), cx_type(type))

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

