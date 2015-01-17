/* Fast_Update.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Update_H
#define Fast_Update_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Update::construct() */
cx_int16 Fast_Update_construct(Fast_Update _this);

/* virtual ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Update_toIc(Fast_Update _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Update_toIc_v(Fast_Update _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

