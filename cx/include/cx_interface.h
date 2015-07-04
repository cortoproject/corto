/* cx_interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_interface_H
#define cx_interface_H

#include "cortex.h"
#include "cx_type.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::interface::baseof(interface type) */
cx_int16 cx_interface_baseof(cx_interface _this, cx_interface type);

/* ::cortex::lang::interface::bindMethod(method method) */
cx_int16 cx_interface_bindMethod(cx_interface _this, cx_method method);

/* virtual ::cortex::lang::interface::compatible(type type) */
cx_bool cx_interface_compatible(cx_interface _this, cx_type type);

/* ::cortex::lang::interface::compatible(type type) */
cx_bool cx_interface_compatible_v(cx_interface _this, cx_type type);

/* ::cortex::lang::interface::construct() */
cx_int16 cx_interface_construct(cx_interface _this);

/* ::cortex::lang::interface::destruct() */
cx_void cx_interface_destruct(cx_interface _this);

/* ::cortex::lang::interface::init() */
cx_int16 cx_interface_init(cx_interface _this);

/* virtual ::cortex::lang::interface::resolveMember(string name) */
cx_member cx_interface_resolveMember(cx_interface _this, cx_string name);

/* ::cortex::lang::interface::resolveMember(string name) */
cx_member cx_interface_resolveMember_v(cx_interface _this, cx_string name);

/* ::cortex::lang::interface::resolveMethod(string name) */
cx_method cx_interface_resolveMethod(cx_interface _this, cx_string name);

/* ::cortex::lang::interface::resolveMethodById(uint32 id) */
cx_method cx_interface_resolveMethodById(cx_interface _this, cx_uint32 id);

/* ::cortex::lang::interface::resolveMethodId(string name) */
cx_uint32 cx_interface_resolveMethodId(cx_interface _this, cx_string name);

#ifdef __cplusplus
}
#endif
#endif

