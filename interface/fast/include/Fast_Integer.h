/* Fast_Integer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Integer_H
#define Fast_Integer_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Integer::init(Integer object) */
db_int16 Fast_Integer_init(Fast_Integer object);

/* ::cortex::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Integer_serialize(Fast_Integer _this, db_type dstType, db_word dst);

/* virtual ::cortex::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Integer_toIc(Fast_Integer _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Integer_toIc_v(Fast_Integer _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

