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

/* ::cortex::Fast::SignedInteger::init() */
cx_int16 Fast_SignedInteger_init(Fast_SignedInteger _this);

/* ::cortex::Fast::SignedInteger::serialize(type dstType,word dst) */
cx_int16 Fast_SignedInteger_serialize(Fast_SignedInteger _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_SignedInteger_toIc(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

