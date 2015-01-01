/* Fast_String.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_String_H
#define Fast_String_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::String::construct(String object) */
db_int16 Fast_String_construct(Fast_String object);

/* ::cortex::Fast::String::getValue() */
db_word Fast_String_getValue(Fast_String _this);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::String::init(String object) */
db_int16 Fast_String_init(Fast_String object);

/* ::cortex::Fast::String::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_String_serialize(Fast_String _this, db_type dstType, db_word dst);

/* virtual ::cortex::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_String_toIc(Fast_String _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_String_toIc_v(Fast_String _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

