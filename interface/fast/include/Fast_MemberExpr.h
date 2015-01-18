/* Fast_MemberExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_MemberExpr_H
#define Fast_MemberExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::MemberExpr::construct() */
cx_int16 Fast_MemberExpr_construct(Fast_MemberExpr _this);

/* virtual ::cortex::Fast::MemberExpr::hasSideEffects() */
cx_bool Fast_MemberExpr_hasSideEffects(Fast_MemberExpr _this);

/* ::cortex::Fast::MemberExpr::hasSideEffects() */
cx_bool Fast_MemberExpr_hasSideEffects_v(Fast_MemberExpr _this);

/* virtual ::cortex::Fast::MemberExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_MemberExpr_toIc(Fast_MemberExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::MemberExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_MemberExpr_toIc_v(Fast_MemberExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

