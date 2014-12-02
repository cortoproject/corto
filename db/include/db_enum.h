/* db_enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_enum_H
#define db_enum_H

#include "hyve.h"
#include "db_primitive.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::lang::enum::constant(lang::int32 value) */
db_object db_enum_constant(db_enum _this, db_int32 value);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::enum::construct(lang::enum object) */
db_int16 db_enum_construct(db_enum object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::enum::destruct(lang::enum object) */
db_void db_enum_destruct(db_enum object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::enum::init(lang::enum object) */
db_int16 db_enum_init(db_enum object);

#ifdef __cplusplus
}
#endif
#endif

