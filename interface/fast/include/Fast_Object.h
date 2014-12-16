/* Fast_Object.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Object_H
#define Fast_Object_H

#include "hyve.h"
#include "Fast_ObjectBase.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Object::construct(Object object) */
db_int16 Fast_Object_construct(Fast_Object object);

/* ::hyve::Fast::Object::getValue() */
db_word Fast_Object_getValue(Fast_Object _this);

/* ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Object_serialize(Fast_Object _this, db_type dstType, db_word dst);

/* virtual ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Object_toIc(Fast_Object _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Object_toIc_v(Fast_Object _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

