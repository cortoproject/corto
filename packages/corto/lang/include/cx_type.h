/* cx_type.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_type_H
#define corto_lang_type_H

#include "corto.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::type::alignmentof() */
cx_uint16 _cx_type_alignmentof(cx_type _this);
#define cx_type_alignmentof(_this) _cx_type_alignmentof(cx_type(_this))

/* virtual ::corto::lang::type::allocSize() */
cx_uint32 cx_type_allocSize(cx_type _this);

/* ::corto::lang::type::allocSize() */
cx_uint32 _cx_type_allocSize_v(cx_type _this);
#define cx_type_allocSize_v(_this) _cx_type_allocSize_v(cx_type(_this))

/* virtual ::corto::lang::type::castable(type type) */
cx_bool cx_type_castable(cx_type _this, cx_type type);

/* ::corto::lang::type::castable(type type) */
cx_bool _cx_type_castable_v(cx_type _this, cx_type type);
#define cx_type_castable_v(_this, type) _cx_type_castable_v(cx_type(_this), cx_type(type))

/* ::corto::lang::type::checkAttr(attr attributes) */
cx_bool _cx_type_checkAttr(cx_any _this, cx_attr attributes);
#define cx_type_checkAttr(_this, attributes) _cx_type_checkAttr(_this, attributes)

/* ::corto::lang::type::checkState(state state) */
cx_bool _cx_type_checkState(cx_any _this, cx_state state);
#define cx_type_checkState(_this, state) _cx_type_checkState(_this, state)

/* ::corto::lang::type::compare(any value) */
cx_equalityKind _cx_type_compare(cx_any _this, cx_any value);
#define cx_type_compare(_this, value) _cx_type_compare(_this, value)

/* virtual ::corto::lang::type::compatible(type type) */
cx_bool cx_type_compatible(cx_type _this, cx_type type);

/* ::corto::lang::type::compatible(type type) */
cx_bool _cx_type_compatible_v(cx_type _this, cx_type type);
#define cx_type_compatible_v(_this, type) _cx_type_compatible_v(cx_type(_this), cx_type(type))

/* ::corto::lang::type::construct() */
cx_int16 _cx_type_construct(cx_type _this);
#define cx_type_construct(_this) _cx_type_construct(cx_type(_this))

/* ::corto::lang::type::copy(any value) */
cx_int16 _cx_type_copy(cx_any _this, cx_any value);
#define cx_type_copy(_this, value) _cx_type_copy(_this, value)

/* ::corto::lang::type::declare(string name,type type) */
cx_object _cx_type_declare(cx_any _this, cx_string name, cx_type type);
#define cx_type_declare(_this, name, type) _cx_type_declare(_this, name, cx_type(type))

/* ::corto::lang::type::define() */
cx_int16 _cx_type_define(cx_any _this);
#define cx_type_define(_this) _cx_type_define(_this)

/* ::corto::lang::type::delete() */
cx_void _cx_type_delete(cx_any _this);
#define cx_type_delete(_this) _cx_type_delete(_this)

/* ::corto::lang::type::destruct() */
cx_void _cx_type_destruct(cx_type _this);
#define cx_type_destruct(_this) _cx_type_destruct(cx_type(_this))

/* ::corto::lang::type::fullname() */
cx_string _cx_type_fullname(cx_any _this);
#define cx_type_fullname(_this) _cx_type_fullname(_this)

/* ::corto::lang::type::init() */
cx_int16 _cx_type_init(cx_type _this);
#define cx_type_init(_this) _cx_type_init(cx_type(_this))

/* ::corto::lang::type::instanceof(type type) */
cx_bool _cx_type_instanceof(cx_any _this, cx_type type);
#define cx_type_instanceof(_this, type) _cx_type_instanceof(_this, cx_type(type))

/* ::corto::lang::type::invalidate() */
cx_void _cx_type_invalidate(cx_any _this);
#define cx_type_invalidate(_this) _cx_type_invalidate(_this)

/* ::corto::lang::type::lookup(string name) */
cx_object _cx_type_lookup(cx_any _this, cx_string name);
#define cx_type_lookup(_this, name) _cx_type_lookup(_this, name)

/* ::corto::lang::type::nameof() */
cx_string _cx_type_nameof(cx_any _this);
#define cx_type_nameof(_this) _cx_type_nameof(_this)

/* ::corto::lang::type::parentof() */
cx_object _cx_type_parentof(cx_any _this);
#define cx_type_parentof(_this) _cx_type_parentof(_this)

/* ::corto::lang::type::relname(object from) */
cx_string _cx_type_relname(cx_any _this, cx_object from);
#define cx_type_relname(_this, from) _cx_type_relname(_this, from)

/* ::corto::lang::type::resolve(string name) */
cx_object _cx_type_resolve(cx_any _this, cx_string name);
#define cx_type_resolve(_this, name) _cx_type_resolve(_this, name)

/* ::corto::lang::type::resolveProcedure(string name) */
cx_function _cx_type_resolveProcedure(cx_type _this, cx_string name);
#define cx_type_resolveProcedure(_this, name) _cx_type_resolveProcedure(cx_type(_this), name)

/* ::corto::lang::type::sizeof() */
cx_uint32 _cx_type_sizeof(cx_type _this);
#define cx_type_sizeof(_this) _cx_type_sizeof(cx_type(_this))

/* ::corto::lang::type::toString() */
cx_string _cx_type_toString(cx_any _this);
#define cx_type_toString(_this) _cx_type_toString(_this)

/* ::corto::lang::type::typeof() */
cx_type _cx_type_typeof(cx_any _this);
#define cx_type_typeof(_this) _cx_type_typeof(_this)

#ifdef __cplusplus
}
#endif
#endif

