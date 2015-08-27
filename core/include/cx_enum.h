/* cx_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_enum_H
#define cx_enum_H

#include "corto.h"
#include "cx_primitive.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::enum::constant(int32 value) */
cx_object cx_enum_constant(cx_enum _this, cx_int32 value);

/* ::corto::lang::enum::construct() */
cx_int16 cx_enum_construct(cx_enum _this);

/* ::corto::lang::enum::destruct() */
cx_void cx_enum_destruct(cx_enum _this);

/* ::corto::lang::enum::init() */
cx_int16 cx_enum_init(cx_enum _this);

#ifdef __cplusplus
}
#endif
#endif

