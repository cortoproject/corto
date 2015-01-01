/* Fast_Null.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Null_H
#define Fast_Null_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Null::init(Null object) */
db_int16 Fast_Null_init(Fast_Null object);

/* ::cortex::Fast::Null::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Null_serialize(Fast_Null _this, db_type dstType, db_word dst);

/* virtual ::cortex::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Null_toIc(Fast_Null _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Null_toIc_v(Fast_Null _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

