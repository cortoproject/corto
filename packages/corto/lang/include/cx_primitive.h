/* cx_primitive.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_PRIMITIVE_H
#define CORTO_LANG_PRIMITIVE_H

#include "corto.h"
#include "cx_type.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::primitive::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_primitive_castable(cx_primitive _this, cx_type type);
#define cx_primitive_castable(_this, type) _cx_primitive_castable(cx_primitive(_this), cx_type(type))

/* ::corto::lang::primitive::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_primitive_castable_v(cx_primitive _this, cx_type type);
#define cx_primitive_castable_v(_this, type) _cx_primitive_castable_v(cx_primitive(_this), cx_type(type))

/* virtual ::corto::lang::primitive::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_primitive_compatible(cx_primitive _this, cx_type type);
#define cx_primitive_compatible(_this, type) _cx_primitive_compatible(cx_primitive(_this), cx_type(type))

/* ::corto::lang::primitive::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_primitive_compatible_v(cx_primitive _this, cx_type type);
#define cx_primitive_compatible_v(_this, type) _cx_primitive_compatible_v(cx_primitive(_this), cx_type(type))

/* ::corto::lang::primitive::construct() */
CORTO_LANG_EXPORT cx_int16 _cx_primitive_construct(cx_primitive _this);
#define cx_primitive_construct(_this) _cx_primitive_construct(cx_primitive(_this))

/* ::corto::lang::primitive::init() */
CORTO_LANG_EXPORT cx_int16 _cx_primitive_init(cx_primitive _this);
#define cx_primitive_init(_this) _cx_primitive_init(cx_primitive(_this))

#ifdef __cplusplus
}
#endif
#endif

