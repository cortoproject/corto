/* primitive.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_PRIMITIVE_H
#define CORTO_LANG_PRIMITIVE_H

#include "corto/corto__interface.h"
#include "corto/lang/lang__type.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_bool _corto_primitive_castable(corto_primitive _this, corto_type type);
#define corto_primitive_castable(_this, type) _corto_primitive_castable(corto_primitive(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_primitive_castable_v(corto_primitive _this, corto_type type);
#define corto_primitive_castable_v(_this, type) _corto_primitive_castable_v(corto_primitive(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_primitive_compatible(corto_primitive _this, corto_type type);
#define corto_primitive_compatible(_this, type) _corto_primitive_compatible(corto_primitive(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_primitive_compatible_v(corto_primitive _this, corto_type type);
#define corto_primitive_compatible_v(_this, type) _corto_primitive_compatible_v(corto_primitive(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_primitive_construct(corto_primitive _this);
#define corto_primitive_construct(_this) _corto_primitive_construct(corto_primitive(_this))

CORTO_EXPORT corto_int16 _corto_primitive_init(corto_primitive _this);
#define corto_primitive_init(_this) _corto_primitive_init(corto_primitive(_this))

CORTO_EXPORT corto_bool _corto_primitive_isInteger(corto_primitive _this);
#define corto_primitive_isInteger(_this) _corto_primitive_isInteger(corto_primitive(_this))

CORTO_EXPORT corto_bool _corto_primitive_isNumber(corto_primitive _this);
#define corto_primitive_isNumber(_this) _corto_primitive_isNumber(corto_primitive(_this))

#ifdef __cplusplus
}
#endif
#endif
