/* cx_delegate.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_delegate_H
#define corto_lang_delegate_H

#include "corto.h"
#include "cx_struct.h"
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

/* ::corto::lang::delegate::bind(function object) */
cx_int16 _cx_delegate_bind(cx_function object);
#define cx_delegate_bind(object) _cx_delegate_bind(cx_function(object))

/* virtual ::corto::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable(cx_delegate _this, cx_type type);

/* ::corto::lang::delegate::castable(type type) */
cx_bool _cx_delegate_castable_v(cx_delegate _this, cx_type type);
#define cx_delegate_castable_v(_this, type) _cx_delegate_castable_v(cx_delegate(_this), cx_type(type))

/* virtual ::corto::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible(cx_delegate _this, cx_type type);

/* ::corto::lang::delegate::compatible(type type) */
cx_bool _cx_delegate_compatible_v(cx_delegate _this, cx_type type);
#define cx_delegate_compatible_v(_this, type) _cx_delegate_compatible_v(cx_delegate(_this), cx_type(type))

/* ::corto::lang::delegate::init() */
cx_int16 _cx_delegate_init(cx_delegate _this);
#define cx_delegate_init(_this) _cx_delegate_init(cx_delegate(_this))

/* ::corto::lang::delegate::instanceof(object object) */
cx_bool _cx_delegate_instanceof(cx_delegate _this, cx_object object);
#define cx_delegate_instanceof(_this, object) _cx_delegate_instanceof(cx_delegate(_this), object)

#ifdef __cplusplus
}
#endif
#endif

