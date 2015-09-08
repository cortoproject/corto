/* cx_primitive.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_primitive_H
#define corto_lang_primitive_H

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

/* virtual ::corto::lang::primitive::castable(type type) */
cx_bool cx_primitive_castable(cx_primitive _this, cx_type type);

/* ::corto::lang::primitive::castable(type type) */
cx_bool _cx_primitive_castable_v(cx_primitive _this, cx_type type);
#define cx_primitive_castable_v(_this, type) _cx_primitive_castable_v(cx_primitive(_this), cx_type(type))

/* virtual ::corto::lang::primitive::compatible(type type) */
cx_bool cx_primitive_compatible(cx_primitive _this, cx_type type);

/* ::corto::lang::primitive::compatible(type type) */
cx_bool _cx_primitive_compatible_v(cx_primitive _this, cx_type type);
#define cx_primitive_compatible_v(_this, type) _cx_primitive_compatible_v(cx_primitive(_this), cx_type(type))

/* ::corto::lang::primitive::construct() */
cx_int16 _cx_primitive_construct(cx_primitive _this);
#define cx_primitive_construct(_this) _cx_primitive_construct(cx_primitive(_this))

/* ::corto::lang::primitive::init() */
cx_int16 _cx_primitive_init(cx_primitive _this);
#define cx_primitive_init(_this) _cx_primitive_init(cx_primitive(_this))

#ifdef __cplusplus
}
#endif
#endif

