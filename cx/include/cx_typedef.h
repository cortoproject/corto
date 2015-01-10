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

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::typedef::construct(typedef object) */
cx_int16 cx_typedef_construct(cx_typedef object);

/* callback ::cortex::lang::class::destruct(object object) -> ::cortex::lang::typedef::destruct(typedef object) */
cx_void cx_typedef_destruct(cx_typedef object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::typedef::init(typedef object) */
cx_int16 cx_typedef_init(cx_typedef object);

/* ::cortex::lang::typedef::realType() */
cx_type cx_typedef_realType(cx_typedef _this);

#ifdef __cplusplus
}
#endif
#endif

