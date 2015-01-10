/* Fast_Integer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Integer_H
#define Fast_Integer_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(object object) -> ::cortex::Fast::Integer::init(Integer object) */
cx_int16 Fast_Integer_init(Fast_Integer object);

/* ::cortex::Fast::Integer::serialize(type dstType,word dst) */
cx_int16 Fast_Integer_serialize(Fast_Integer _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Integer_toIc(Fast_Integer _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Integer_toIc_v(Fast_Integer _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

