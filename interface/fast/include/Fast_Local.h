/* Fast_Local.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Local_H
#define Fast_Local_H

#include "hyve.h"
#include "Fast_Variable.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Local::construct(Local object) */
db_int16 Fast_Local_construct(Fast_Local object);

/* virtual ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Local_toIc(Fast_Local _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Local_toIc_v(Fast_Local _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

