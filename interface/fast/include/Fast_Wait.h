/* Fast_Wait.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Wait_H
#define Fast_Wait_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Wait::construct(Wait object) */
db_int16 Fast_Wait_construct(Fast_Wait object);

/* virtual ::cortex::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Wait_toIc(Fast_Wait _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Wait_toIc_v(Fast_Wait _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

