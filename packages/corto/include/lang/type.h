/* type.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_TYPE_H
#define CORTO_LANG_TYPE_H

#include "corto/corto__interface.h"
#include "corto/lang/lang__type.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_uint16 _corto_type_alignmentof(corto_type _this);
#define corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))

CORTO_EXPORT corto_uint32 _corto_type_allocSize(corto_type _this);
#define corto_type_allocSize(_this) _corto_type_allocSize(corto_type(_this))

CORTO_EXPORT corto_uint32 _corto_type_allocSize_v(corto_type _this);
#define corto_type_allocSize_v(_this) _corto_type_allocSize_v(corto_type(_this))

CORTO_EXPORT corto_bool _corto_type_castable(corto_type _this, corto_type type);
#define corto_type_castable(_this, type) _corto_type_castable(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_type_castable_v(corto_type _this, corto_type type);
#define corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_type_checkAttr(corto_any _this, corto_attr attributes);
#define corto_type_checkAttr(_this, attributes) _corto_type_checkAttr(_this, attributes)

CORTO_EXPORT corto_bool _corto_type_checkState(corto_any _this, corto_state state);
#define corto_type_checkState(_this, state) _corto_type_checkState(_this, state)

CORTO_EXPORT corto_equalityKind _corto_type_compare(corto_any _this, corto_any value);
#define corto_type_compare(_this, value) _corto_type_compare(_this, value)

CORTO_EXPORT corto_bool _corto_type_compatible(corto_type _this, corto_type type);
#define corto_type_compatible(_this, type) _corto_type_compatible(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_type_compatible_v(corto_type _this, corto_type type);
#define corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_type_construct(corto_type _this);
#define corto_type_construct(_this) _corto_type_construct(corto_type(_this))

CORTO_EXPORT corto_int16 _corto_type_copy(corto_any _this, corto_any value);
#define corto_type_copy(_this, value) _corto_type_copy(_this, value)

CORTO_EXPORT corto_object _corto_type_declare(corto_any _this, corto_string name, corto_type type);
#define corto_type_declare(_this, name, type) _corto_type_declare(_this, name, corto_type(type))

CORTO_EXPORT corto_int16 _corto_type_define(corto_any _this);
#define corto_type_define(_this) _corto_type_define(_this)

CORTO_EXPORT corto_void _corto_type_delete(corto_any _this);
#define corto_type_delete(_this) _corto_type_delete(_this)

CORTO_EXPORT corto_void _corto_type_destruct(corto_type _this);
#define corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))

CORTO_EXPORT corto_string _corto_type_fullname(corto_any _this);
#define corto_type_fullname(_this) _corto_type_fullname(_this)

CORTO_EXPORT corto_int16 _corto_type_init(corto_type _this);
#define corto_type_init(_this) _corto_type_init(corto_type(_this))

CORTO_EXPORT corto_bool _corto_type_instanceof(corto_any _this, corto_type type);
#define corto_type_instanceof(_this, type) _corto_type_instanceof(_this, corto_type(type))

CORTO_EXPORT corto_void _corto_type_invalidate(corto_any _this);
#define corto_type_invalidate(_this) _corto_type_invalidate(_this)

CORTO_EXPORT corto_object _corto_type_lookup(corto_any _this, corto_string name);
#define corto_type_lookup(_this, name) _corto_type_lookup(_this, name)

CORTO_EXPORT corto_string _corto_type_nameof(corto_any _this);
#define corto_type_nameof(_this) _corto_type_nameof(_this)

CORTO_EXPORT corto_object _corto_type_parentof(corto_any _this);
#define corto_type_parentof(_this) _corto_type_parentof(_this)

CORTO_EXPORT corto_string _corto_type_relname(corto_any _this, corto_object from);
#define corto_type_relname(_this, from) _corto_type_relname(_this, from)

CORTO_EXPORT corto_object _corto_type_resolve(corto_any _this, corto_string name);
#define corto_type_resolve(_this, name) _corto_type_resolve(_this, name)

CORTO_EXPORT corto_function _corto_type_resolveProcedure(corto_type _this, corto_string name);
#define corto_type_resolveProcedure(_this, name) _corto_type_resolveProcedure(corto_type(_this), name)

CORTO_EXPORT corto_uint32 _corto_type_sizeof(corto_type _this);
#define corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))

CORTO_EXPORT corto_string _corto_type_toString(corto_any _this);
#define corto_type_toString(_this) _corto_type_toString(_this)

CORTO_EXPORT corto_type _corto_type_typeof(corto_any _this);
#define corto_type_typeof(_this) _corto_type_typeof(_this)

#ifdef __cplusplus
}
#endif
#endif
