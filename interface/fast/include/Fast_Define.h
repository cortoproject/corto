/* Fast_Define.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Define_H
#define Fast_Define_H

#include "cortex.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Define::construct(Fast::Define object) */
cx_int16 Fast_Define_construct(Fast_Define object);

/* virtual ::cortex::Fast::Define::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Define_toIc(Fast_Define _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Define::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Define_toIc_v(Fast_Define _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

