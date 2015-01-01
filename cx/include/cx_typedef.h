/* cx_typedef.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_typedef_H
#define cx_typedef_H

#include "cortex.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::typedef::construct(lang::typedef object) */
cx_int16 cx_typedef_construct(cx_typedef object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::typedef::destruct(lang::typedef object) */
cx_void cx_typedef_destruct(cx_typedef object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::typedef::init(lang::typedef object) */
cx_int16 cx_typedef_init(cx_typedef object);

/* ::cortex::lang::typedef::realType() */
cx_type cx_typedef_realType(cx_typedef _this);

#ifdef __cplusplus
}
#endif
#endif

