/* router.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_ROUTER_H
#define CORTO_CORE_ROUTER_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_router_construct(
    corto_router _this);
#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))

CORTO_EXPORT corto_int16 _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any param,
    corto_any result);
#define corto_router_match(instance, request, param, result) _corto_router_match(instance, request, param, result)

#ifdef __cplusplus
}
#endif
#endif

