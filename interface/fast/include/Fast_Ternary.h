/* Fast_Ternary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Ternary_H
#define Fast_Ternary_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Ternary::construct() */
cx_int16 Fast_Ternary_construct(Fast_Ternary _this);

/* virtual ::cortex::Fast::Ternary::hasSideEffects() */
cx_bool Fast_Ternary_hasSideEffects(Fast_Ternary _this);

/* ::cortex::Fast::Ternary::hasSideEffects() */
cx_bool Fast_Ternary_hasSideEffects_v(Fast_Ternary _this);

/* ::cortex::Fast::Ternary::setOperator(operatorKind kind) */
cx_void Fast_Ternary_setOperator(Fast_Ternary _this, cx_operatorKind kind);

/* virtual ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Ternary_toIc(Fast_Ternary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Ternary_toIc_v(Fast_Ternary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

