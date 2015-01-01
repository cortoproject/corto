/* Fast_Null.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Null_H
#define Fast_Null_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Null::init(Null object) */
cx_int16 Fast_Null_init(Fast_Null object);

/* ::cortex::Fast::Null::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_Null_serialize(Fast_Null _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Null::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Null_toIc(Fast_Null _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Null::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Null_toIc_v(Fast_Null _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

