/* Fast_Local.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Local_H
#define Fast_Local_H

#include "cortex.h"
#include "Fast_Variable.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Local::construct() */
cx_int16 Fast_Local_construct(Fast_Local _this);

/* virtual ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Local_toIc(Fast_Local _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Local_toIc_v(Fast_Local _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

