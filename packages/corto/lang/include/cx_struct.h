/* cx_struct.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_struct_H
#define corto_lang_struct_H

#include "corto.h"
#include "cx_interface.h"
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

/* virtual ::corto::lang::struct::castable(type type) */
cx_bool _cx_struct_castable(cx_struct _this, cx_type type);
#define cx_struct_castable(_this, type) _cx_struct_castable(cx_struct(_this), cx_type(type))

/* ::corto::lang::struct::castable(type type) */
cx_bool _cx_struct_castable_v(cx_struct _this, cx_type type);
#define cx_struct_castable_v(_this, type) _cx_struct_castable_v(cx_struct(_this), cx_type(type))

/* virtual ::corto::lang::struct::compatible(type type) */
cx_bool _cx_struct_compatible(cx_struct _this, cx_type type);
#define cx_struct_compatible(_this, type) _cx_struct_compatible(cx_struct(_this), cx_type(type))

/* ::corto::lang::struct::compatible(type type) */
cx_bool _cx_struct_compatible_v(cx_struct _this, cx_type type);
#define cx_struct_compatible_v(_this, type) _cx_struct_compatible_v(cx_struct(_this), cx_type(type))

/* ::corto::lang::struct::construct() */
cx_int16 _cx_struct_construct(cx_struct _this);
#define cx_struct_construct(_this) _cx_struct_construct(cx_struct(_this))

/* ::corto::lang::struct::init() */
cx_int16 _cx_struct_init(cx_struct _this);
#define cx_struct_init(_this) _cx_struct_init(cx_struct(_this))

/* virtual ::corto::lang::struct::resolveMember(string name) */
cx_member _cx_struct_resolveMember(cx_struct _this, cx_string name);
#define cx_struct_resolveMember(_this, name) _cx_struct_resolveMember(cx_struct(_this), name)

/* ::corto::lang::struct::resolveMember(string name) */
cx_member _cx_struct_resolveMember_v(cx_struct _this, cx_string name);
#define cx_struct_resolveMember_v(_this, name) _cx_struct_resolveMember_v(cx_struct(_this), name)

#ifdef __cplusplus
}
#endif
#endif

