/* cx_method.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_method_H
#define corto_lang_method_H

#include "corto.h"
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

/* ::corto::lang::method::bind() */
cx_int16 _cx_method_bind(cx_method _this);
#define cx_method_bind(_this) _cx_method_bind(cx_method(_this))

/* ::corto::lang::method::init() */
cx_int16 _cx_method_init(cx_method _this);
#define cx_method_init(_this) _cx_method_init(cx_method(_this))

#ifdef __cplusplus
}
#endif
#endif

