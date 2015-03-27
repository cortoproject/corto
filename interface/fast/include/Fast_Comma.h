/* Fast_Comma.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Comma_H
#define Fast_Comma_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Comma::addExpression(Expression expr) */
cx_int16 Fast_Comma_addExpression(Fast_Comma _this, Fast_Expression expr);

/* ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_Comma_addOrCreate(Fast_Expression list, Fast_Expression expr);

/* ::cortex::Fast::Comma::construct() */
cx_int16 Fast_Comma_construct(Fast_Comma _this);

/* virtual ::cortex::Fast::Comma::hasSideEffects() */
cx_bool Fast_Comma_hasSideEffects(Fast_Comma _this);

/* ::cortex::Fast::Comma::hasSideEffects() */
cx_bool Fast_Comma_hasSideEffects_v(Fast_Comma _this);

/* ::cortex::Fast::Comma::init() */
cx_int16 Fast_Comma_init(Fast_Comma _this);

/* virtual ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Comma_toIc(Fast_Comma _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Comma_toIc_v(Fast_Comma _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Comma::toList() */
Fast_Node_list Fast_Comma_toList(Fast_Comma _this);

#ifdef __cplusplus
}
#endif
#endif

