/* Fast_Cast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Cast_H
#define Fast_Cast_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Cast::construct() */
cx_int16 Fast_Cast_construct(Fast_Cast _this);

/* virtual ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Cast_toIc(Fast_Cast _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Cast_toIc_v(Fast_Cast _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

