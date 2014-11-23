/* Fast_FloatingPoint.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_FloatingPoint_H
#define Fast_FloatingPoint_H

#include "hyve.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::FloatingPoint::init(FloatingPoint object) */
db_int16 Fast_FloatingPoint_init(Fast_FloatingPoint object);

/* ::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_FloatingPoint_serialize(Fast_FloatingPoint _this, db_type dstType, db_word dst);

/* virtual ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_FloatingPoint_toIc(Fast_FloatingPoint _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_FloatingPoint_toIc_v(Fast_FloatingPoint _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

