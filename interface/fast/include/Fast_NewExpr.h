/* Fast_NewExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_NewExpr_H
#define Fast_NewExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::NewExpr::construct(Fast::NewExpr object) */
db_int16 Fast_NewExpr_construct(Fast_NewExpr object);

/* virtual ::cortex::Fast::NewExpr::hasSideEffects() */
db_bool Fast_NewExpr_hasSideEffects(Fast_NewExpr _this);

/* ::cortex::Fast::NewExpr::hasSideEffects() */
db_bool Fast_NewExpr_hasSideEffects_v(Fast_NewExpr _this);

/* virtual ::cortex::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_NewExpr_toIc(Fast_NewExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_NewExpr_toIc_v(Fast_NewExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

