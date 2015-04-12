/* Fast_Object.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Object_H
#define Fast_Object_H

#include "cortex.h"
#include "Fast_Storage.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Object::construct() */
cx_int16 Fast_Object_construct(Fast_Object _this);

/* ::cortex::Fast::Object::getValue() */
cx_word Fast_Object_getValue(Fast_Object _this);

/* ::cortex::Fast::Object::serialize(type dstType,word dst) */
cx_int16 Fast_Object_serialize(Fast_Object _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Object_toIc(Fast_Object _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Object_toIc_v(Fast_Object _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

