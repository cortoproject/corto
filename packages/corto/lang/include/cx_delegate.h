/* cx_delegate.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_DELEGATE_H
#define CORTO_LANG_DELEGATE_H

#include "corto.h"
#include "cx_struct.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::delegate::bind(function object) */
CORTO_LANG_EXPORT cx_int16 _cx_delegate_bind(cx_function object);
#define cx_delegate_bind(object) _cx_delegate_bind(cx_function(object))

/* virtual ::corto::lang::delegate::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_delegate_castable(cx_delegate _this, cx_type type);
#define cx_delegate_castable(_this, type) _cx_delegate_castable(cx_delegate(_this), cx_type(type))

/* ::corto::lang::delegate::castable(type type) */
CORTO_LANG_EXPORT cx_bool _cx_delegate_castable_v(cx_delegate _this, cx_type type);
#define cx_delegate_castable_v(_this, type) _cx_delegate_castable_v(cx_delegate(_this), cx_type(type))

/* virtual ::corto::lang::delegate::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_delegate_compatible(cx_delegate _this, cx_type type);
#define cx_delegate_compatible(_this, type) _cx_delegate_compatible(cx_delegate(_this), cx_type(type))

/* ::corto::lang::delegate::compatible(type type) */
CORTO_LANG_EXPORT cx_bool _cx_delegate_compatible_v(cx_delegate _this, cx_type type);
#define cx_delegate_compatible_v(_this, type) _cx_delegate_compatible_v(cx_delegate(_this), cx_type(type))

/* ::corto::lang::delegate::init() */
CORTO_LANG_EXPORT cx_int16 _cx_delegate_init(cx_delegate _this);
#define cx_delegate_init(_this) _cx_delegate_init(cx_delegate(_this))

/* ::corto::lang::delegate::instanceof(object object) */
CORTO_LANG_EXPORT cx_bool _cx_delegate_instanceof(cx_delegate _this, cx_object object);
#define cx_delegate_instanceof(_this, object) _cx_delegate_instanceof(cx_delegate(_this), object)

#ifdef __cplusplus
}
#endif
#endif

