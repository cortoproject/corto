/* cx_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_enum_H
#define corto_lang_enum_H

#include "corto.h"
#include "cx_primitive.h"
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

/* ::corto::lang::enum::constant(int32 value) */
cx_object _cx_enum_constant(cx_enum _this, cx_int32 value);
#define cx_enum_constant(_this, value) _cx_enum_constant(cx_enum(_this), value)

/* ::corto::lang::enum::construct() */
cx_int16 _cx_enum_construct(cx_enum _this);
#define cx_enum_construct(_this) _cx_enum_construct(cx_enum(_this))

/* ::corto::lang::enum::destruct() */
cx_void _cx_enum_destruct(cx_enum _this);
#define cx_enum_destruct(_this) _cx_enum_destruct(cx_enum(_this))

/* ::corto::lang::enum::init() */
cx_int16 _cx_enum_init(cx_enum _this);
#define cx_enum_init(_this) _cx_enum_init(cx_enum(_this))

#ifdef __cplusplus
}
#endif
#endif

