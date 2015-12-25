/* collection.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_COLLECTION_H
#define CORTO_LANG_COLLECTION_H

#include "corto/corto__interface.h"
#include "corto/lang/lang__type.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_bool _corto_collection_castable(corto_collection _this, corto_type type);
#define corto_collection_castable(_this, type) _corto_collection_castable(corto_collection(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_collection_castable_v(corto_collection _this, corto_type type);
#define corto_collection_castable_v(_this, type) _corto_collection_castable_v(corto_collection(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_collection_compatible(corto_collection _this, corto_type type);
#define corto_collection_compatible(_this, type) _corto_collection_compatible(corto_collection(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_collection_compatible_v(corto_collection _this, corto_type type);
#define corto_collection_compatible_v(_this, type) _corto_collection_compatible_v(corto_collection(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_collection_init(corto_collection _this);
#define corto_collection_init(_this) _corto_collection_init(corto_collection(_this))

CORTO_EXPORT corto_bool _corto_collection_requiresAlloc(corto_type elementType);
#define corto_collection_requiresAlloc(elementType) _corto_collection_requiresAlloc(corto_type(elementType))

CORTO_EXPORT corto_uint32 _corto_collection_size(corto_any _this);
#define corto_collection_size(_this) _corto_collection_size(_this)

#ifdef __cplusplus
}
#endif
#endif
