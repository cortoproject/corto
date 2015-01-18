/* Fast_FloatingPoint.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_FloatingPoint_H
#define Fast_FloatingPoint_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::FloatingPoint::init() */
cx_int16 Fast_FloatingPoint_init(Fast_FloatingPoint _this);

/* ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) */
cx_int16 Fast_FloatingPoint_serialize(Fast_FloatingPoint _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_FloatingPoint_toIc(Fast_FloatingPoint _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_FloatingPoint_toIc_v(Fast_FloatingPoint _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

