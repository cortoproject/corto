/* db_primitive.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_primitive_H
#define db_primitive_H

#include "hyve.h"
#include "db_type.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::primitive::castable(lang::type type) */
db_bool db_primitive_castable(db_primitive _this, db_type type);

/* ::hyve::lang::primitive::castable(lang::type type) */
db_bool db_primitive_castable_v(db_primitive _this, db_type type);

/* virtual ::hyve::lang::primitive::compatible(lang::type type) */
db_bool db_primitive_compatible(db_primitive _this, db_type type);

/* ::hyve::lang::primitive::compatible(lang::type type) */
db_bool db_primitive_compatible_v(db_primitive _this, db_type type);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::primitive::construct(lang::primitive object) */
db_int16 db_primitive_construct(db_primitive object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::primitive::init(lang::primitive object) */
db_int16 db_primitive_init(db_primitive object);

#ifdef __cplusplus
}
#endif
#endif

