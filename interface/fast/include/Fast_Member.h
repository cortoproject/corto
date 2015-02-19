/* Fast_Member.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Member_H
#define Fast_Member_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Member::construct() */
cx_int16 Fast_Member_construct(Fast_Member _this);

/* virtual ::cortex::Fast::Member::hasSideEffects() */
cx_bool Fast_Member_hasSideEffects(Fast_Member _this);

/* ::cortex::Fast::Member::hasSideEffects() */
cx_bool Fast_Member_hasSideEffects_v(Fast_Member _this);

/* virtual ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Member_toIc(Fast_Member _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Member_toIc_v(Fast_Member _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

