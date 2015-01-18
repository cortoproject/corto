/* Fast_CastExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_CastExpr_H
#define Fast_CastExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::CastExpr::construct() */
cx_int16 Fast_CastExpr_construct(Fast_CastExpr _this);

/* virtual ::cortex::Fast::CastExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CastExpr_toIc(Fast_CastExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::CastExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CastExpr_toIc_v(Fast_CastExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

