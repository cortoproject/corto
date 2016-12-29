/* type.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_TYPE_H
#define CORTO_LANG_TYPE_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/lang/_type.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_uint16 _corto_type_alignmentof(
    corto_type _this);
#define corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
CORTO_EXPORT corto_bool _corto_type_castable(
    corto_type _this,
    corto_type type);
#define corto_type_castable(_this, type) _corto_type_castable(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_type_castable_v(
    corto_type _this,
    corto_type type);
#define corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
CORTO_EXPORT corto_bool _corto_type_compatible(
    corto_type _this,
    corto_type type);
#define corto_type_compatible(_this, type) _corto_type_compatible(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_type_compatible_v(
    corto_type _this,
    corto_type type);
#define corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_type_construct(
    corto_type _this);
#define corto_type_construct(_this) _corto_type_construct(corto_type(_this))

CORTO_EXPORT corto_void _corto_type_destruct(
    corto_type _this);
#define corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))

CORTO_EXPORT corto_int16 _corto_type_init(
    corto_type _this);
#define corto_type_init(_this) _corto_type_init(corto_type(_this))

CORTO_EXPORT corto_function _corto_type_resolveProcedure(
    corto_type _this,
    corto_string name);
#define corto_type_resolveProcedure(_this, name) _corto_type_resolveProcedure(corto_type(_this), name)

CORTO_EXPORT corto_uint32 _corto_type_sizeof(
    corto_type _this);
#define corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))

#ifdef __cplusplus
}
#endif
#endif

