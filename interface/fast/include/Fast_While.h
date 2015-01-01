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
db_int16 Fast_While_construct(Fast_While object);

/* virtual ::cortex::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_While_toIc(Fast_While _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_While_toIc_v(Fast_While _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

