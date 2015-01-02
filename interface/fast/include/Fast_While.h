/* Fast_While.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_While_H
#define Fast_While_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::While::construct(While object) */
cx_int16 Fast_While_construct(Fast_While object);

/* virtual ::cortex::Fast::While::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_While_toIc(Fast_While _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::While::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_While_toIc_v(Fast_While _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

