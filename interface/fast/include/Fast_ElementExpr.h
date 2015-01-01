/* Fast_ElementExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_ElementExpr_H
#define Fast_ElementExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::ElementExpr::construct(Fast::MemberExpr object) */
db_int16 Fast_ElementExpr_construct(Fast_MemberExpr object);

/* virtual ::cortex::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_ElementExpr_toIc(Fast_ElementExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_ElementExpr_toIc_v(Fast_ElementExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

