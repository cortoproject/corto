/* routerimpl.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_ROUTERIMPL_H
#define CORTO_CORE_ROUTERIMPL_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_routerimpl_construct(
    corto_routerimpl _this);
#define corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))

CORTO_EXPORT corto_void _corto_routerimpl_destruct(
    corto_routerimpl _this);
#define corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
CORTO_EXPORT corto_route _corto_routerimpl_findRoute(
    corto_routerimpl _this,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);
#define corto_routerimpl_findRoute(_this, pattern, param, routerData) _corto_routerimpl_findRoute(corto_routerimpl(_this), pattern, param, routerData)

CORTO_EXPORT corto_route _corto_routerimpl_findRoute_v(
    corto_routerimpl _this,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);
#define corto_routerimpl_findRoute_v(_this, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), pattern, param, routerData)
CORTO_EXPORT corto_int32 _corto_routerimpl_matchRoute(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);
#define corto_routerimpl_matchRoute(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)

CORTO_EXPORT corto_int32 _corto_routerimpl_matchRoute_v(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);
#define corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)

#ifdef __cplusplus
}
#endif
#endif

