/* Fast_Unary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Unary_H
#define Fast_Unary_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Unary::construct() */
cx_int16 Fast_Unary_construct(Fast_Unary _this);

/* virtual ::cortex::Fast::Unary::hasSideEffects() */
cx_bool Fast_Unary_hasSideEffects(Fast_Unary _this);

/* ::cortex::Fast::Unary::hasSideEffects() */
cx_bool Fast_Unary_hasSideEffects_v(Fast_Unary _this);

/* virtual ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Unary_toIc(Fast_Unary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Unary_toIc_v(Fast_Unary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

