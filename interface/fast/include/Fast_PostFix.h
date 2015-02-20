/* Fast_PostFix.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_PostFix_H
#define Fast_PostFix_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::PostFix::construct() */
cx_int16 Fast_PostFix_construct(Fast_PostFix _this);

/* virtual ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostFix_toIc(Fast_PostFix _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostFix_toIc_v(Fast_PostFix _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

