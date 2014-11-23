/* Fast_Define.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_Define_H
#define Fast_Define_H

#include "hyve.h"
#include "Fast_Node.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Define::construct(Fast::Define object) */
db_int16 Fast_Define_construct(Fast_Define object);

/* virtual ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Define_toIc(Fast_Define _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Define_toIc_v(Fast_Define _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

