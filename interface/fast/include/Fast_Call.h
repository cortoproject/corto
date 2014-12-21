/* Fast_Call.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Call_H
#define Fast_Call_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Call::construct(Fast::Call object) */
db_int16 Fast_Call_construct(Fast_Call object);

/* virtual ::hyve::Fast::Call::hasSideEffects() */
db_bool Fast_Call_hasSideEffects(Fast_Call _this);

/* ::hyve::Fast::Call::hasSideEffects() */
db_bool Fast_Call_hasSideEffects_v(Fast_Call _this);

/* ::hyve::Fast::Call::resolveActual(string signature,lang::object scope,Fast::Expression instance) */
db_function Fast_Call_resolveActual(db_string signature, db_object scope, Fast_Expression instance);

/* virtual ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Call_toIc(Fast_Call _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Call_toIc_v(Fast_Call _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

