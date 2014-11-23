/* Fast_Update.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_Update_H
#define Fast_Update_H

#include "hyve.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Update::construct(Update object) */
db_int16 Fast_Update_construct(Fast_Update object);

/* virtual ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Update_toIc(Fast_Update _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Update_toIc_v(Fast_Update _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

