/* enum.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ENUM_H
#define CORTO_LANG_ENUM_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_object _corto_enum_constant(
    corto_enum _this,
    corto_int32 value);
#define corto_enum_constant(_this, value) _corto_enum_constant(corto_enum(_this), value)

CORTO_EXPORT corto_int16 _corto_enum_construct(
    corto_enum _this);
#define corto_enum_construct(_this) _corto_enum_construct(corto_enum(_this))

CORTO_EXPORT corto_void _corto_enum_destruct(
    corto_enum _this);
#define corto_enum_destruct(_this) _corto_enum_destruct(corto_enum(_this))

CORTO_EXPORT corto_int16 _corto_enum_init(
    corto_enum _this);
#define corto_enum_init(_this) _corto_enum_init(corto_enum(_this))

#ifdef __cplusplus
}
#endif
#endif

