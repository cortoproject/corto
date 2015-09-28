/* cx_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ENUM_H
#define CORTO_LANG_ENUM_H

#include "corto.h"
#include "cx_primitive.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::enum::constant(int32 value) */
CORTO_LANG_EXPORT cx_object _cx_enum_constant(cx_enum _this, cx_int32 value);
#define cx_enum_constant(_this, value) _cx_enum_constant(cx_enum(_this), value)

/* ::corto::lang::enum::construct() */
CORTO_LANG_EXPORT cx_int16 _cx_enum_construct(cx_enum _this);
#define cx_enum_construct(_this) _cx_enum_construct(cx_enum(_this))

/* ::corto::lang::enum::destruct() */
CORTO_LANG_EXPORT cx_void _cx_enum_destruct(cx_enum _this);
#define cx_enum_destruct(_this) _cx_enum_destruct(cx_enum(_this))

/* ::corto::lang::enum::init() */
CORTO_LANG_EXPORT cx_int16 _cx_enum_init(cx_enum _this);
#define cx_enum_init(_this) _cx_enum_init(cx_enum(_this))

#ifdef __cplusplus
}
#endif
#endif

