/* corto_collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_COLLECTION_H
#define CORTO_LANG_COLLECTION_H

#include "corto.h"
#include "corto_type.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual /corto/lang/collection/castable(type type) */
CORTO_LANG_EXPORT corto_bool _corto_collection_castable(corto_collection _this, corto_type type);
#define corto_collection_castable(_this, type) _corto_collection_castable(corto_collection(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_collection_castable_v(corto_collection _this, corto_type type);
#define corto_collection_castable_v(_this, type) _corto_collection_castable_v(corto_collection(_this), corto_type(type))

/* virtual /corto/lang/collection/compatible(type type) */
CORTO_LANG_EXPORT corto_bool _corto_collection_compatible(corto_collection _this, corto_type type);
#define corto_collection_compatible(_this, type) _corto_collection_compatible(corto_collection(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_collection_compatible_v(corto_collection _this, corto_type type);
#define corto_collection_compatible_v(_this, type) _corto_collection_compatible_v(corto_collection(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_collection_elementRequiresAlloc(corto_collection _this);
#define corto_collection_elementRequiresAlloc(_this) _corto_collection_elementRequiresAlloc(corto_collection(_this))

CORTO_LANG_EXPORT corto_int16 _corto_collection_init(corto_collection _this);
#define corto_collection_init(_this) _corto_collection_init(corto_collection(_this))

CORTO_LANG_EXPORT corto_uint32 _corto_collection_size(corto_any _this);
#define corto_collection_size(_this) _corto_collection_size(_this)

#ifdef __cplusplus
}
#endif
#endif

