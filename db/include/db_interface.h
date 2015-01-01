/* db_interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_interface_H
#define db_interface_H

#include "cortex.h"
#include "db_type.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::interface::baseof(lang::interface type) */
db_int16 db_interface_baseof(db_interface _this, db_interface type);

/* virtual ::cortex::lang::interface::bindMethod(lang::method method) */
db_int16 db_interface_bindMethod(db_interface _this, db_method method);

/* ::cortex::lang::interface::bindMethod(lang::method method) */
db_int16 db_interface_bindMethod_v(db_interface _this, db_method method);

/* virtual ::cortex::lang::interface::compatible(lang::type type) */
db_bool db_interface_compatible(db_interface _this, db_type type);

/* ::cortex::lang::interface::compatible(lang::type type) */
db_bool db_interface_compatible_v(db_interface _this, db_type type);

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::interface::construct(lang::interface object) */
db_int16 db_interface_construct(db_interface object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::interface::destruct(lang::interface object) */
db_void db_interface_destruct(db_interface object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::interface::init(lang::interface object) */
db_int16 db_interface_init(db_interface object);

/* virtual ::cortex::lang::interface::resolveMember(lang::string name) */
db_member db_interface_resolveMember(db_interface _this, db_string name);

/* ::cortex::lang::interface::resolveMember(lang::string name) */
db_member db_interface_resolveMember_v(db_interface _this, db_string name);

/* ::cortex::lang::interface::resolveMethod(lang::string name) */
db_method db_interface_resolveMethod(db_interface _this, db_string name);

/* ::cortex::lang::interface::resolveMethodById(lang::uint32 id) */
db_method db_interface_resolveMethodById(db_interface _this, db_uint32 id);

/* ::cortex::lang::interface::resolveMethodId(lang::string name) */
db_uint32 db_interface_resolveMethodId(db_interface _this, db_string name);

#ifdef __cplusplus
}
#endif
#endif

