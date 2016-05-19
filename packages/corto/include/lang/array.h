/* array.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_ARRAY_H
#define CORTO_LANG_ARRAY_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_array_construct(
    corto_array this);
#define corto_array_construct(_this) _corto_array_construct(corto_array(_this))

CORTO_EXPORT corto_void _corto_array_destruct(
    corto_array this);
#define corto_array_destruct(_this) _corto_array_destruct(corto_array(_this))

CORTO_EXPORT corto_int16 _corto_array_init(
    corto_array this);
#define corto_array_init(_this) _corto_array_init(corto_array(_this))

#ifdef __cplusplus
}
#endif
#endif

