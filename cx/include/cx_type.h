/* cx_type.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_type_H
#define cx_type_H

#include "cortex.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::lang::type::alignmentof() */
cx_uint16 cx_type_alignmentof(cx_type _this);

/* virtual ::cortex::lang::type::allocSize() */
cx_uint32 cx_type_allocSize(cx_type _this);

/* ::cortex::lang::type::allocSize() */
cx_uint32 cx_type_allocSize_v(cx_type _this);

/* virtual ::cortex::lang::type::castable(type type) */
cx_bool cx_type_castable(cx_type _this, cx_type type);

/* ::cortex::lang::type::castable(type type) */
cx_bool cx_type_castable_v(cx_type _this, cx_type type);

/* ::cortex::lang::type::checkAttr(attr attributes) */
cx_bool cx_type_checkAttr(cx_any _this, cx_attr attributes);

/* ::cortex::lang::type::checkState(state state) */
cx_bool cx_type_checkState(cx_any _this, cx_state state);

/* ::cortex::lang::type::compare(any value) */
cx_equalityKind cx_type_compare(cx_any _this, cx_any value);

/* virtual ::cortex::lang::type::compatible(type type) */
cx_bool cx_type_compatible(cx_type _this, cx_type type);

/* ::cortex::lang::type::compatible(type type) */
cx_bool cx_type_compatible_v(cx_type _this, cx_type type);

/* ::cortex::lang::type::construct() */
cx_int16 cx_type_construct(cx_type _this);

/* ::cortex::lang::type::copy(any value) */
cx_int16 cx_type_copy(cx_any _this, cx_any value);

/* ::cortex::lang::type::declare(string name,type type) */
cx_object cx_type_declare(cx_any _this, cx_string name, cx_type type);

/* ::cortex::lang::type::define() */
cx_int16 cx_type_define(cx_any _this);

/* ::cortex::lang::type::delete() */
cx_void cx_type_delete(cx_any _this);

/* ::cortex::lang::type::destruct() */
cx_void cx_type_destruct(cx_type _this);

/* ::cortex::lang::type::fullname() */
cx_string cx_type_fullname(cx_any _this);

/* ::cortex::lang::type::init() */
cx_int16 cx_type_init(cx_type _this);

/* ::cortex::lang::type::instanceof(type type) */
cx_bool cx_type_instanceof(cx_any _this, cx_type type);

/* ::cortex::lang::type::invalidate() */
cx_void cx_type_invalidate(cx_any _this);

/* ::cortex::lang::type::lookup(string name) */
cx_object cx_type_lookup(cx_any _this, cx_string name);

/* ::cortex::lang::type::nameof() */
cx_string cx_type_nameof(cx_any _this);

/* ::cortex::lang::type::parentof() */
cx_object cx_type_parentof(cx_any _this);

/* ::cortex::lang::type::relname(object from) */
cx_string cx_type_relname(cx_any _this, cx_object from);

/* ::cortex::lang::type::resolve(string name) */
cx_object cx_type_resolve(cx_any _this, cx_string name);

/* ::cortex::lang::type::resolveProcedure(string name) */
cx_function cx_type_resolveProcedure(cx_type _this, cx_string name);

/* ::cortex::lang::type::sizeof() */
cx_uint32 cx_type_sizeof(cx_type _this);

/* ::cortex::lang::type::toString() */
cx_string cx_type_toString(cx_any _this);

/* ::cortex::lang::type::typeof() */
cx_type cx_type_typeof(cx_any _this);

#ifdef __cplusplus
}
#endif
#endif

