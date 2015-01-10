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

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::String::construct(Fast::String object) */
cx_int16 Fast_String_construct(Fast_String object);

/* ::cortex::Fast::String::getValue() */
cx_word Fast_String_getValue(Fast_String _this);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::Fast::String::init(Fast::String object) */
cx_int16 Fast_String_init(Fast_String object);

/* ::cortex::Fast::String::serialize(type dstType,word dst) */
cx_int16 Fast_String_serialize(Fast_String _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_String_toIc(Fast_String _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_String_toIc_v(Fast_String _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

