/* router.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_ROUTER_H
#define CORTO_CORE_ROUTER_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/core/_type.h>
#include <corto/core/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))
CORTO_EXPORT
corto_int16 _corto_router_construct(
    corto_router _this);

#define corto_router_init(_this) _corto_router_init(corto_router(_this))
CORTO_EXPORT
corto_int16 _corto_router_init(
    corto_router _this);

#define corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
CORTO_EXPORT
corto_int16 _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any param,
    corto_any result,
    corto_route *matched);

#ifdef __cplusplus
}
#endif

#endif

