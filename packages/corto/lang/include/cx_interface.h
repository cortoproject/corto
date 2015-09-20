/* cx_interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_interface_H
#define corto_lang_interface_H

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

/* ::corto::lang::interface::baseof(interface type) */
cx_int16 _cx_interface_baseof(cx_interface _this, cx_interface type);
#define cx_interface_baseof(_this, type) _cx_interface_baseof(cx_interface(_this), cx_interface(type))

/* ::corto::lang::interface::bindMethod(method method) */
cx_int16 _cx_interface_bindMethod(cx_interface _this, cx_method method);
#define cx_interface_bindMethod(_this, method) _cx_interface_bindMethod(cx_interface(_this), cx_method(method))

/* virtual ::corto::lang::interface::compatible(type type) */
cx_bool _cx_interface_compatible(cx_interface _this, cx_type type);
#define cx_interface_compatible(_this, type) _cx_interface_compatible(cx_interface(_this), cx_type(type))

/* ::corto::lang::interface::compatible(type type) */
cx_bool _cx_interface_compatible_v(cx_interface _this, cx_type type);
#define cx_interface_compatible_v(_this, type) _cx_interface_compatible_v(cx_interface(_this), cx_type(type))

/* ::corto::lang::interface::construct() */
cx_int16 _cx_interface_construct(cx_interface _this);
#define cx_interface_construct(_this) _cx_interface_construct(cx_interface(_this))

/* ::corto::lang::interface::destruct() */
cx_void _cx_interface_destruct(cx_interface _this);
#define cx_interface_destruct(_this) _cx_interface_destruct(cx_interface(_this))

/* ::corto::lang::interface::init() */
cx_int16 _cx_interface_init(cx_interface _this);
#define cx_interface_init(_this) _cx_interface_init(cx_interface(_this))

/* virtual ::corto::lang::interface::resolveMember(string name) */
cx_member _cx_interface_resolveMember(cx_interface _this, cx_string name);
#define cx_interface_resolveMember(_this, name) _cx_interface_resolveMember(cx_interface(_this), name)

/* ::corto::lang::interface::resolveMember(string name) */
cx_member _cx_interface_resolveMember_v(cx_interface _this, cx_string name);
#define cx_interface_resolveMember_v(_this, name) _cx_interface_resolveMember_v(cx_interface(_this), name)

/* ::corto::lang::interface::resolveMethod(string name) */
cx_method _cx_interface_resolveMethod(cx_interface _this, cx_string name);
#define cx_interface_resolveMethod(_this, name) _cx_interface_resolveMethod(cx_interface(_this), name)

/* ::corto::lang::interface::resolveMethodById(uint32 id) */
cx_method _cx_interface_resolveMethodById(cx_interface _this, cx_uint32 id);
#define cx_interface_resolveMethodById(_this, id) _cx_interface_resolveMethodById(cx_interface(_this), id)

/* ::corto::lang::interface::resolveMethodId(string name) */
cx_uint32 _cx_interface_resolveMethodId(cx_interface _this, cx_string name);
#define cx_interface_resolveMethodId(_this, name) _cx_interface_resolveMethodId(cx_interface(_this), name)

#ifdef __cplusplus
}
#endif
#endif

