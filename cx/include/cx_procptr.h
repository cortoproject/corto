/* cx_procptr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_procptr_H
#define cx_procptr_H

#include "cortex.h"
#include "cx_struct.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::procptr::compatible(type type) */
cx_bool cx_procptr_compatible(cx_procptr _this, cx_type type);

/* ::cortex::lang::procptr::compatible(type type) */
cx_bool cx_procptr_compatible_v(cx_procptr _this, cx_type type);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::procptr::init(procptr object) */
cx_int16 cx_procptr_init(cx_procptr object);

#ifdef __cplusplus
}
#endif
#endif

