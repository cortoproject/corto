/* Fast_Call.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Call_H
#define Fast_Call_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::Call::construct(Fast::Call object) */
cx_int16 Fast_Call_construct(Fast_Call object);

/* virtual ::cortex::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects(Fast_Call _this);

/* ::cortex::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects_v(Fast_Call _this);

/* ::cortex::Fast::Call::setParameters(function function) */
void Fast_Call_setParameters(Fast_Call _this, cx_function function);

/* virtual ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Call_toIc(Fast_Call _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Call_toIc_v(Fast_Call _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

