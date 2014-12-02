/* db_struct.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_struct_H
#define db_struct_H

#include "hyve.h"
#include "db_interface.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::struct::castable(lang::type type) */
db_bool db_struct_castable(db_struct _this, db_type type);

/* ::hyve::lang::struct::castable(lang::type type) */
db_bool db_struct_castable_v(db_struct _this, db_type type);

/* virtual ::hyve::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible(db_struct _this, db_type type);

/* ::hyve::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible_v(db_struct _this, db_type type);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::struct::construct(lang::struct object) */
db_int16 db_struct_construct(db_struct object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::struct::init(lang::struct object) */
db_int16 db_struct_init(db_struct object);

/* virtual ::hyve::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember(db_struct _this, db_string name);

/* ::hyve::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember_v(db_struct _this, db_string name);

#ifdef __cplusplus
}
#endif
#endif

