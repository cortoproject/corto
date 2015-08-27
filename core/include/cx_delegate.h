/* cx_delegate.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_delegate_H
#define cx_delegate_H

#include "corto.h"
#include "cx_struct.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::delegate::bind(function object) */
cx_int16 cx_delegate_bind(cx_function object);

/* virtual ::corto::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable(cx_delegate _this, cx_type type);

/* ::corto::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable_v(cx_delegate _this, cx_type type);

/* virtual ::corto::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible(cx_delegate _this, cx_type type);

/* ::corto::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible_v(cx_delegate _this, cx_type type);

/* ::corto::lang::delegate::init() */
cx_int16 cx_delegate_init(cx_delegate _this);

/* ::corto::lang::delegate::instanceof(object object) */
cx_bool cx_delegate_instanceof(cx_delegate _this, cx_object object);

#ifdef __cplusplus
}
#endif
#endif

