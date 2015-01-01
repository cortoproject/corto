/* cx_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_enum_H
#define cx_enum_H

#include "cortex.h"
#include "cx_primitive.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::enum::constant(lang::int32 value) */
cx_object cx_enum_constant(cx_enum _this, cx_int32 value);

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::enum::construct(lang::enum object) */
cx_int16 cx_enum_construct(cx_enum object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::enum::destruct(lang::enum object) */
cx_void cx_enum_destruct(cx_enum object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::enum::init(lang::enum object) */
cx_int16 cx_enum_init(cx_enum object);

#ifdef __cplusplus
}
#endif
#endif

