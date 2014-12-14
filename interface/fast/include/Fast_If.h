/* Fast_If.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_If_H
#define Fast_If_H

#include "hyve.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::If::construct(If object) */
db_int16 Fast_If_construct(Fast_If object);

/* ::hyve::Fast::If::noWarnUnreachable() */
void Fast_If_noWarnUnreachable(Fast_If _this);

/* virtual ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_If_toIc(Fast_If _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_If_toIc_v(Fast_If _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

