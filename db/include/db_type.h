/* db_type.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_type_H
#define db_type_H

#include "cortex.h"
#include "db_typedef.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::type::_destruct(lang::type object) */
db_void db_type__destruct(db_type object);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::type::_init(lang::type object) */
db_int16 db_type__init(db_type object);

/* ::cortex::lang::type::alignmentof() */
db_uint16 db_type_alignmentof(db_type _this);

/* virtual ::cortex::lang::type::allocSize() */
db_uint32 db_type_allocSize(db_type _this);

/* ::cortex::lang::type::allocSize() */
db_uint32 db_type_allocSize_v(db_type _this);

/* virtual ::cortex::lang::type::castable(lang::type type) */
db_bool db_type_castable(db_type _this, db_type type);

/* ::cortex::lang::type::castable(lang::type type) */
db_bool db_type_castable_v(db_type _this, db_type type);

/* ::cortex::lang::type::checkAttr(lang::attr attributes) */
db_bool db_type_checkAttr(db_any _this, db_attr attributes);

/* ::cortex::lang::type::checkState(lang::state state) */
db_bool db_type_checkState(db_any _this, db_state state);

/* ::cortex::lang::type::compare(lang::any value) */
db_equalityKind db_type_compare(db_any _this, db_any value);

/* virtual ::cortex::lang::type::compatible(lang::type type) */
db_bool db_type_compatible(db_type _this, db_type type);

/* ::cortex::lang::type::compatible(lang::type type) */
db_bool db_type_compatible_v(db_type _this, db_type type);

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::type::construct(lang::type object) */
db_int16 db_type_construct(db_type object);

/* ::cortex::lang::type::copy(lang::any value) */
db_int16 db_type_copy(db_any _this, db_any value);

/* ::cortex::lang::type::declare(lang::string name,lang::typedef type) */
db_object db_type_declare(db_any _this, db_string name, db_typedef type);

/* ::cortex::lang::type::define() */
db_int16 db_type_define(db_any _this);

/* ::cortex::lang::type::destruct() */
db_void db_type_destruct(db_any _this);

/* ::cortex::lang::type::fullname() */
db_string db_type_fullname(db_any _this);

/* delegate ::cortex::lang::type::init(lang::object object), obtain callback */
db_bool db_type_init_hasCallback(db_type _this);

/* ::cortex::lang::type::init(lang::object object) */
db_int16 db_type_init(db_type _this, db_object object);

/* ::cortex::lang::type::instanceof(lang::typedef type) */
db_bool db_type_instanceof(db_any _this, db_typedef type);

/* ::cortex::lang::type::invalidate() */
db_void db_type_invalidate(db_any _this);

/* ::cortex::lang::type::lookup(lang::string name) */
db_object db_type_lookup(db_any _this, db_string name);

/* ::cortex::lang::type::nameof() */
db_string db_type_nameof(db_any _this);

/* ::cortex::lang::type::parentof() */
db_object db_type_parentof(db_any _this);

/* ::cortex::lang::type::relname(lang::object from) */
db_string db_type_relname(db_any _this, db_object from);

/* ::cortex::lang::type::resolve(lang::string name) */
db_object db_type_resolve(db_any _this, db_string name);

/* ::cortex::lang::type::resolveProcedure(lang::string name) */
db_function db_type_resolveProcedure(db_type _this, db_string name);

/* ::cortex::lang::type::sizeof() */
db_uint32 db_type_sizeof(db_type _this);

/* ::cortex::lang::type::toString() */
db_string db_type_toString(db_any _this);

/* ::cortex::lang::type::typeof() */
db_type db_type_typeof(db_any _this);

#ifdef __cplusplus
}
#endif
#endif

