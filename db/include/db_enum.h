/* db_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_enum_H
#define db_enum_H

#include "cortex.h"
#include "db_primitive.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::enum::constant(lang::int32 value) */
db_object db_enum_constant(db_enum _this, db_int32 value);

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::enum::construct(lang::enum object) */
db_int16 db_enum_construct(db_enum object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::enum::destruct(lang::enum object) */
db_void db_enum_destruct(db_enum object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::enum::init(lang::enum object) */
db_int16 db_enum_init(db_enum object);

#ifdef __cplusplus
}
#endif
#endif

