/* _interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_INTERFACE_H
#define CORTO_CORE_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif


#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
CORTO_EXPORT
void _corto_dispatcher_post_v(
    corto_dispatcher _this,
    corto_event *e);

#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), e)
CORTO_EXPORT
void _corto_dispatcher_post(
    corto_dispatcher _this,
    corto_event *e);

#define corto_event_handle(_this) _corto_event_handle(_this)
CORTO_EXPORT
void _corto_event_handle(
    corto_event* _this);

#define corto_event_uniqueKind() _corto_event_uniqueKind()
CORTO_EXPORT
int16_t _corto_event_uniqueKind(void);

#define corto_frame_getTime(_this) _corto_frame_getTime(_this)
CORTO_EXPORT
corto_time _corto_frame_getTime(
    corto_frame* _this);

#define corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(corto_invokeEvent(_this))
CORTO_EXPORT
void _corto_invokeEvent_handle_v(
    corto_invokeEvent _this);

#define corto_invokeEvent_handle(_this) _corto_invokeEvent_handle(corto_invokeEvent(_this))
CORTO_EXPORT
void _corto_invokeEvent_handle(
    corto_invokeEvent _this);

#define corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
CORTO_EXPORT
int16_t _corto_loader_construct(
    corto_loader _this);

#define corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
CORTO_EXPORT
void _corto_loader_destruct(
    corto_loader _this);

#define corto_loader_onRequest_v(_this, request) _corto_loader_onRequest_v(corto_loader(_this), request)
CORTO_EXPORT
corto_resultIter _corto_loader_onRequest_v(
    corto_loader _this,
    corto_request *request);

#define corto_loader_onRequest(_this, request) _corto_loader_onRequest(corto_loader(_this), request)
CORTO_EXPORT
corto_resultIter _corto_loader_onRequest(
    corto_loader _this,
    corto_request *request);

#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
CORTO_EXPORT
int16_t _corto_mount_construct(
    corto_mount _this);

#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
CORTO_EXPORT
void _corto_mount_destruct(
    corto_mount _this);

#define corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
CORTO_EXPORT
corto_string _corto_mount_id(
    corto_mount _this);

#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
CORTO_EXPORT
int16_t _corto_mount_init(
    corto_mount _this);

#define corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT
void _corto_mount_invoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

#define corto_mount_onId_v(_this) _corto_mount_onId_v(corto_mount(_this))
CORTO_EXPORT
corto_string _corto_mount_onId_v(
    corto_mount _this);

#define corto_mount_onId(_this) _corto_mount_onId(corto_mount(_this))
CORTO_EXPORT
corto_string _corto_mount_onId(
    corto_mount _this);

#define corto_mount_onInvoke_v(_this, instance, proc, argptrs) _corto_mount_onInvoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT
void _corto_mount_onInvoke_v(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

#define corto_mount_onInvoke(_this, instance, proc, argptrs) _corto_mount_onInvoke(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT
void _corto_mount_onInvoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

#define corto_mount_onNotify_v(_this, event, object) _corto_mount_onNotify_v(corto_mount(_this), event, object)
CORTO_EXPORT
void _corto_mount_onNotify_v(
    corto_mount _this,
    corto_eventMask event,
    corto_result *object);

#define corto_mount_onNotify(_this, event, object) _corto_mount_onNotify(corto_mount(_this), event, object)
CORTO_EXPORT
void _corto_mount_onNotify(
    corto_mount _this,
    corto_eventMask event,
    corto_result *object);

#define corto_mount_onPoll_v(_this) _corto_mount_onPoll_v(corto_mount(_this))
CORTO_EXPORT
void _corto_mount_onPoll_v(
    corto_mount _this);

#define corto_mount_onPoll(_this) _corto_mount_onPoll(corto_mount(_this))
CORTO_EXPORT
void _corto_mount_onPoll(
    corto_mount _this);

#define corto_mount_onRequest_v(_this, request) _corto_mount_onRequest_v(corto_mount(_this), request)
CORTO_EXPORT
corto_resultIter _corto_mount_onRequest_v(
    corto_mount _this,
    corto_request *request);

#define corto_mount_onRequest(_this, request) _corto_mount_onRequest(corto_mount(_this), request)
CORTO_EXPORT
corto_resultIter _corto_mount_onRequest(
    corto_mount _this,
    corto_request *request);

#define corto_mount_onResume_v(_this, parent, name, o) _corto_mount_onResume_v(corto_mount(_this), parent, name, o)
CORTO_EXPORT
corto_object _corto_mount_onResume_v(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);

#define corto_mount_onResume(_this, parent, name, o) _corto_mount_onResume(corto_mount(_this), parent, name, o)
CORTO_EXPORT
corto_object _corto_mount_onResume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);

#define corto_mount_onSubscribe_v(_this, parent, expr, ctx) _corto_mount_onSubscribe_v(corto_mount(_this), parent, expr, ctx)
CORTO_EXPORT
uintptr_t _corto_mount_onSubscribe_v(
    corto_mount _this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx);

#define corto_mount_onSubscribe(_this, parent, expr, ctx) _corto_mount_onSubscribe(corto_mount(_this), parent, expr, ctx)
CORTO_EXPORT
uintptr_t _corto_mount_onSubscribe(
    corto_mount _this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx);

#define corto_mount_onUnsubscribe_v(_this, parent, expr, ctx) _corto_mount_onUnsubscribe_v(corto_mount(_this), parent, expr, ctx)
CORTO_EXPORT
void _corto_mount_onUnsubscribe_v(
    corto_mount _this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx);

#define corto_mount_onUnsubscribe(_this, parent, expr, ctx) _corto_mount_onUnsubscribe(corto_mount(_this), parent, expr, ctx)
CORTO_EXPORT
void _corto_mount_onUnsubscribe(
    corto_mount _this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx);

#define corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), e)
CORTO_EXPORT
void _corto_mount_post(
    corto_mount _this,
    corto_event *e);

#define corto_mount_request(_this, request) _corto_mount_request(corto_mount(_this), request)
CORTO_EXPORT
corto_resultIter _corto_mount_request(
    corto_mount _this,
    corto_request *request);

#define corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)
CORTO_EXPORT
corto_object _corto_mount_resume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);

#define corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
CORTO_EXPORT
void _corto_mount_return(
    corto_mount _this,
    corto_result *r);

#define corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)
CORTO_EXPORT
int16_t _corto_mount_setContentType(
    corto_mount _this,
    corto_string type);

#define corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)
CORTO_EXPORT
int16_t _corto_mount_setContentTypeIn(
    corto_mount _this,
    corto_string type);

#define corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)
CORTO_EXPORT
int16_t _corto_mount_setContentTypeOut(
    corto_mount _this,
    corto_string type);

#define corto_mount_subscribe(_this, request) _corto_mount_subscribe(corto_mount(_this), request)
CORTO_EXPORT
void _corto_mount_subscribe(
    corto_mount _this,
    corto_request *request);

#define corto_mount_unsubscribe(_this, request) _corto_mount_unsubscribe(corto_mount(_this), request)
CORTO_EXPORT
void _corto_mount_unsubscribe(
    corto_mount _this,
    corto_request *request);

#define corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
CORTO_EXPORT
int16_t _corto_observer_construct(
    corto_observer _this);

#define corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
CORTO_EXPORT
void _corto_observer_destruct(
    corto_observer _this);

#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
CORTO_EXPORT
int16_t _corto_observer_init(
    corto_observer _this);

#define corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
CORTO_EXPORT
int16_t _corto_observer_observe(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

#define corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
CORTO_EXPORT
bool _corto_observer_observing(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

#define corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
CORTO_EXPORT
int16_t _corto_observer_unobserve(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

#define corto_observerEvent_deinit(_this) _corto_observerEvent_deinit(_this)
CORTO_EXPORT
void _corto_observerEvent_deinit(
    corto_observerEvent* _this);

#define corto_observerEvent_handle(e) _corto_observerEvent_handle(e)
CORTO_EXPORT
void _corto_observerEvent_handle(
    corto_event *e);

#define corto_observerEvent_init(_this) _corto_observerEvent_init(_this)
CORTO_EXPORT
int16_t _corto_observerEvent_init(
    corto_observerEvent* _this);

#define corto_package_construct(_this) _corto_package_construct(corto_package(_this))
CORTO_EXPORT
int16_t _corto_package_construct(
    corto_package _this);

#define corto_package_init(_this) _corto_package_init(corto_package(_this))
CORTO_EXPORT
int16_t _corto_package_init(
    corto_package _this);

#define corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)
CORTO_EXPORT
corto_string _corto_result_contentof(
    corto_result* _this,
    corto_string contentType);

#define corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)
CORTO_EXPORT
int16_t _corto_result_fromcontent(
    corto_result* _this,
    corto_string contentType,
    corto_string content);

#define corto_result_getText(_this) _corto_result_getText(_this)
CORTO_EXPORT
corto_string _corto_result_getText(
    corto_result* _this);

#define corto_route_construct(_this) _corto_route_construct(corto_route(_this))
CORTO_EXPORT
int16_t _corto_route_construct(
    corto_route _this);

#define corto_route_init(_this) _corto_route_init(corto_route(_this))
CORTO_EXPORT
int16_t _corto_route_init(
    corto_route _this);

#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))
CORTO_EXPORT
int16_t _corto_router_construct(
    corto_router _this);

#define corto_router_init(_this) _corto_router_init(corto_router(_this))
CORTO_EXPORT
int16_t _corto_router_init(
    corto_router _this);

#define corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
CORTO_EXPORT
int16_t _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any param,
    corto_any result,
    corto_route *matched);

#define corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
CORTO_EXPORT
int16_t _corto_routerimpl_construct(
    corto_routerimpl _this);

#define corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
CORTO_EXPORT
void _corto_routerimpl_destruct(
    corto_routerimpl _this);

#define corto_routerimpl_findRoute_v(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), instance, pattern, param, routerData)
CORTO_EXPORT
corto_route _corto_routerimpl_findRoute_v(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

#define corto_routerimpl_findRoute(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute(corto_routerimpl(_this), instance, pattern, param, routerData)
CORTO_EXPORT
corto_route _corto_routerimpl_findRoute(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

#define corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
CORTO_EXPORT
int32_t _corto_routerimpl_matchRoute_v(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

#define corto_routerimpl_matchRoute(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
CORTO_EXPORT
int32_t _corto_routerimpl_matchRoute(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

#define corto_stager_add(_this, id, type, contentType, content, childcount) _corto_stager_add(corto_stager(_this), id, type, contentType, content, childcount)
CORTO_EXPORT
int16_t _corto_stager_add(
    corto_stager _this,
    corto_string id,
    corto_string type,
    corto_string contentType,
    uintptr_t content,
    uint64_t childcount);

#define corto_stager_construct(_this) _corto_stager_construct(corto_stager(_this))
CORTO_EXPORT
int16_t _corto_stager_construct(
    corto_stager _this);

#define corto_stager_destruct(_this) _corto_stager_destruct(corto_stager(_this))
CORTO_EXPORT
void _corto_stager_destruct(
    corto_stager _this);

#define corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
CORTO_EXPORT
int16_t _corto_subscriber_construct(
    corto_subscriber _this);

#define corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
CORTO_EXPORT
void _corto_subscriber_deinit(
    corto_subscriber _this);

#define corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
CORTO_EXPORT
void _corto_subscriber_destruct(
    corto_subscriber _this);

#define corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
CORTO_EXPORT
int16_t _corto_subscriber_init(
    corto_subscriber _this);

#define corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
CORTO_EXPORT
int16_t _corto_subscriber_subscribe(
    corto_subscriber _this,
    corto_object instance);

#define corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
CORTO_EXPORT
int16_t _corto_subscriber_unsubscribe(
    corto_subscriber _this,
    corto_object instance);

#define corto_subscriberEvent_deinit(_this) _corto_subscriberEvent_deinit(_this)
CORTO_EXPORT
void _corto_subscriberEvent_deinit(
    corto_subscriberEvent* _this);

#define corto_subscriberEvent_handle(e) _corto_subscriberEvent_handle(e)
CORTO_EXPORT
void _corto_subscriberEvent_handle(
    corto_event *e);

#define corto_subscriberEvent_init(_this) _corto_subscriberEvent_init(_this)
CORTO_EXPORT
int16_t _corto_subscriberEvent_init(
    corto_subscriberEvent* _this);

#ifdef __cplusplus
}
#endif

#endif

