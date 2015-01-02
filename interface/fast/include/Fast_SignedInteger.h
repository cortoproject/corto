/* Fast_SignedInteger.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_SignedInteger_H
#define Fast_SignedInteger_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::SignedInteger::init(SignedInteger object) */
cx_int16 Fast_SignedInteger_init(Fast_SignedInteger object);

/* ::cortex::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_SignedInteger_serialize(Fast_SignedInteger _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::SignedInteger::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_SignedInteger_toIc(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::SignedInteger::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

