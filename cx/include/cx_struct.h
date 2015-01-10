/* cx_struct.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_struct_H
#define cx_struct_H

#include "cortex.h"
#include "cx_interface.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::struct::castable(type type) */
cx_bool cx_struct_castable(cx_struct _this, cx_type type);

/* ::cortex::lang::struct::castable(type type) */
cx_bool cx_struct_castable_v(cx_struct _this, cx_type type);

/* virtual ::cortex::lang::struct::compatible(type type) */
cx_bool cx_struct_compatible(cx_struct _this, cx_type type);

/* ::cortex::lang::struct::compatible(type type) */
cx_bool cx_struct_compatible_v(cx_struct _this, cx_type type);

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::struct::construct(struct object) */
cx_int16 cx_struct_construct(cx_struct object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::struct::init(struct object) */
cx_int16 cx_struct_init(cx_struct object);

/* virtual ::cortex::lang::struct::resolveMember(string name) */
cx_member cx_struct_resolveMember(cx_struct _this, cx_string name);

/* ::cortex::lang::struct::resolveMember(string name) */
cx_member cx_struct_resolveMember_v(cx_struct _this, cx_string name);

#ifdef __cplusplus
}
#endif
#endif

