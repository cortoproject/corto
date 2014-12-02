/* Fast_SignedInteger.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_SignedInteger_H
#define Fast_SignedInteger_H

#include "hyve.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::SignedInteger::init(SignedInteger object) */
db_int16 Fast_SignedInteger_init(Fast_SignedInteger object);

/* ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_SignedInteger_serialize(Fast_SignedInteger _this, db_type dstType, db_word dst);

/* virtual ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_SignedInteger_toIc(Fast_SignedInteger _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

