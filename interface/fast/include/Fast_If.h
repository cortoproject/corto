/* Fast_If.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_If_H
#define Fast_If_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::If::construct(If object) */
cx_int16 Fast_If_construct(Fast_If object);

/* ::cortex::Fast::If::noWarnUnreachable() */
void Fast_If_noWarnUnreachable(Fast_If _this);

/* virtual ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_If_toIc(Fast_If _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_If_toIc_v(Fast_If _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

