/* db_struct.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_struct_H
#define db_struct_H

#include "cortex.h"
#include "db_interface.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::struct::castable(lang::type type) */
db_bool db_struct_castable(db_struct _this, db_type type);

/* ::cortex::lang::struct::castable(lang::type type) */
db_bool db_struct_castable_v(db_struct _this, db_type type);

/* virtual ::cortex::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible(db_struct _this, db_type type);

/* ::cortex::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible_v(db_struct _this, db_type type);

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::struct::construct(lang::struct object) */
db_int16 db_struct_construct(db_struct object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::struct::init(lang::struct object) */
db_int16 db_struct_init(db_struct object);

/* virtual ::cortex::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember(db_struct _this, db_string name);

/* ::cortex::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember_v(db_struct _this, db_string name);

#ifdef __cplusplus
}
#endif
#endif

