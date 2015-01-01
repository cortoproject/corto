/* Fast_Boolean.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Boolean_H
#define Fast_Boolean_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Boolean::init(Boolean object) */
db_int16 Fast_Boolean_init(Fast_Boolean object);

/* ::cortex::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Boolean_serialize(Fast_Boolean _this, db_type dstType, db_word dst);

/* virtual ::cortex::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Boolean_toIc(Fast_Boolean _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Boolean_toIc_v(Fast_Boolean _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

