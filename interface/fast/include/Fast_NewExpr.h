/* Fast_New.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_New_H
#define Fast_New_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::New::construct() */
cx_int16 Fast_New_construct(Fast_New _this);

/* virtual ::cortex::Fast::New::hasSideEffects() */
cx_bool Fast_New_hasSideEffects(Fast_New _this);

/* ::cortex::Fast::New::hasSideEffects() */
cx_bool Fast_New_hasSideEffects_v(Fast_New _this);

/* virtual ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_New_toIc(Fast_New _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_New_toIc_v(Fast_New _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

