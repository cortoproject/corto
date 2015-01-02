/* Fast_Boolean.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Boolean_H
#define Fast_Boolean_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Boolean::init(Boolean object) */
cx_int16 Fast_Boolean_init(Fast_Boolean object);

/* ::cortex::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_Boolean_serialize(Fast_Boolean _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Boolean::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Boolean_toIc(Fast_Boolean _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Boolean::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Boolean_toIc_v(Fast_Boolean _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

