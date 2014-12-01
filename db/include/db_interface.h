/* db_interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_interface_H
#define db_interface_H

#include "hyve.h"
#include "db_type.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::hyve::lang::interface::bindMethod(lang::method method) */
db_int16 db_interface_bindMethod(db_interface _this, db_method method);

/* ::hyve::lang::interface::bindMethod(lang::method method) */
db_int16 db_interface_bindMethod_v(db_interface _this, db_method method);

/* virtual ::hyve::lang::interface::compatible(lang::type type) */
db_bool db_interface_compatible(db_interface _this, db_type type);

/* ::hyve::lang::interface::compatible(lang::type type) */
db_bool db_interface_compatible_v(db_interface _this, db_type type);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::interface::construct(lang::interface object) */
db_int16 db_interface_construct(db_interface object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::interface::destruct(lang::interface object) */
db_void db_interface_destruct(db_interface object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::interface::init(lang::interface object) */
db_int16 db_interface_init(db_interface object);

/* virtual ::hyve::lang::interface::resolveMember(lang::string name) */
db_member db_interface_resolveMember(db_interface _this, db_string name);

/* ::hyve::lang::interface::resolveMember(lang::string name) */
db_member db_interface_resolveMember_v(db_interface _this, db_string name);

/* ::hyve::lang::interface::resolveMethod(lang::string name) */
db_method db_interface_resolveMethod(db_interface _this, db_string name);

/* ::hyve::lang::interface::resolveMethodById(lang::uint32 id) */
db_method db_interface_resolveMethodById(db_interface _this, db_uint32 id);

/* ::hyve::lang::interface::resolveMethodId(lang::string name) */
db_uint32 db_interface_resolveMethodId(db_interface _this, db_string name);

#ifdef __cplusplus
}
#endif
#endif

