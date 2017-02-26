/* method.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_METHOD_H
#define CORTO_LANG_METHOD_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/lang/_type.h>
#include <corto/lang/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_method_construct(_this) _corto_method_construct(corto_method(_this))
CORTO_EXPORT
corto_int16 _corto_method_construct(
    corto_method _this);

#define corto_method_init(_this) _corto_method_init(corto_method(_this))
CORTO_EXPORT
corto_int16 _corto_method_init(
    corto_method _this);

#ifdef __cplusplus
}
#endif

#endif

