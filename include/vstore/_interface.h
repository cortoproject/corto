/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_VSTORE_INTERFACE_H
#define CORTO_VSTORE_INTERFACE_H

#include <corto/_project.h>


#ifdef __cplusplus
extern "C" {
#endif

/* -- Procudure declarations -- */


/* package corto/vstore */



/* interface corto/vstore/dispatcher */

CORTO_EXPORT
void _corto_dispatcher_post_v(
    corto_dispatcher _this,
    corto_event *e);

#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), e)
CORTO_EXPORT
void _corto_dispatcher_post(
    corto_dispatcher _this,
    corto_event *e);


/* struct corto/vstore/event */

CORTO_EXPORT
void _corto_event_handle(
    corto_event* _this);


/* struct corto/vstore/fmt_data */

CORTO_EXPORT
void _corto_fmt_data_deinit(
    corto_fmt_data* _this);


/* struct corto/vstore/frame */

CORTO_EXPORT
corto_time _corto_frame_getTime(
    corto_frame* _this);


/* struct corto/vstore/invokeEvent */

CORTO_EXPORT
void _corto_invokeEvent_handle_v(
    corto_invokeEvent* _this);

/* void corto_invokeEvent_handle(corto_invokeEvent) */
#define corto_invokeEvent_handle(_this) ( \
    ((corto_function)corto_invokeEvent_handle_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_invokeEvent_handle_o)->index - 1])->fptr)(corto_invokeEvent(_this)) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_invokeEvent_handle_o)->index - 1], NULL, corto_invokeEvent(_this)) \
    )


/* class corto/vstore/loader */

CORTO_EXPORT
int16_t _corto_loader_construct(
    corto_loader _this);

CORTO_EXPORT
void _corto_loader_destruct(
    corto_loader _this);

CORTO_EXPORT
corto_resultIter _corto_loader_on_query_v(
    corto_loader _this,
    corto_query *query);

/* corto_resultIter corto_loader_on_query(corto_loader, corto_query *) */
#define corto_loader_on_query(_this, query) ( \
    ((corto_function)corto_loader_on_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1])->fptr)(corto_loader(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_loader(_this), query) \
    )


/* class corto/vstore/mount */

CORTO_EXPORT
int16_t _corto_mount_construct(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_destruct(
    corto_mount _this);

CORTO_EXPORT
corto_resultIter _corto_mount_historyQuery(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
corto_string _corto_mount_id(
    corto_mount _this);

CORTO_EXPORT
int16_t _corto_mount_init(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_invoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

CORTO_EXPORT
void _corto_mount_on_batch_notify_v(
    corto_mount _this,
    corto_subscriberEventIter events);

/* void corto_mount_on_batch_notify(corto_mount, corto_subscriberEventIter) */
#define corto_mount_on_batch_notify(_this, events) ( \
    ((corto_function)corto_mount_on_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriberEventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1], NULL, corto_mount(_this), events) \
    )

CORTO_EXPORT
void _corto_mount_on_history_batch_notify_v(
    corto_mount _this,
    corto_subscriberEventIter events);

/* void corto_mount_on_history_batch_notify(corto_mount, corto_subscriberEventIter) */
#define corto_mount_on_history_batch_notify(_this, events) ( \
    ((corto_function)corto_mount_on_history_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriberEventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1], NULL, corto_mount(_this), events) \
    )

CORTO_EXPORT
corto_resultIter _corto_mount_on_history_query_v(
    corto_mount _this,
    corto_query *query);

/* corto_resultIter corto_mount_on_history_query(corto_mount, corto_query *) */
#define corto_mount_on_history_query(_this, query) ( \
    ((corto_function)corto_mount_on_history_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_mount(_this), query) \
    )

CORTO_EXPORT
corto_string _corto_mount_on_id_v(
    corto_mount _this);

/* corto_string corto_mount_on_id(corto_mount) */
#define corto_mount_on_id(_this) ( \
    ((corto_function)corto_mount_on_id_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_string (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_id_o)->index - 1])->fptr)(corto_mount(_this)) \
    : *(corto_string*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_id_o)->index - 1], alloca(sizeof(corto_string)), corto_mount(_this)) \
    )

CORTO_EXPORT
void _corto_mount_on_invoke_v(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

/* void corto_mount_on_invoke(corto_mount, corto_object, corto_function, uintptr_t) */
#define corto_mount_on_invoke(_this, instance, proc, argptrs) ( \
    ((corto_function)corto_mount_on_invoke_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_object, corto_function, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_invoke_o)->index - 1])->fptr)(corto_mount(_this), instance, corto_function(proc), argptrs) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_invoke_o)->index - 1], NULL, corto_mount(_this), instance, corto_function(proc), argptrs) \
    )

CORTO_EXPORT
uintptr_t _corto_mount_on_mount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* uintptr_t corto_mount_on_mount(corto_mount, corto_query *, uintptr_t) */
#define corto_mount_on_mount(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_mount_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_mount_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_mount_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this), query, ctx) \
    )

CORTO_EXPORT
void _corto_mount_on_notify_v(
    corto_mount _this,
    corto_subscriberEvent *event);

/* void corto_mount_on_notify(corto_mount, corto_subscriberEvent *) */
#define corto_mount_on_notify(_this, event) ( \
    ((corto_function)corto_mount_on_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriberEvent *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_notify_o)->index - 1])->fptr)(corto_mount(_this), event) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_notify_o)->index - 1], NULL, corto_mount(_this), event) \
    )

CORTO_EXPORT
corto_resultIter _corto_mount_on_query_v(
    corto_mount _this,
    corto_query *query);

/* corto_resultIter corto_mount_on_query(corto_mount, corto_query *) */
#define corto_mount_on_query(_this, query) ( \
    ((corto_function)corto_mount_on_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_mount(_this), query) \
    )

CORTO_EXPORT
corto_object _corto_mount_on_resume_v(
    corto_mount _this,
    const char *parent,
    const char *id,
    corto_object object);

/* corto_object corto_mount_on_resume(corto_mount, const char *, const char *, corto_object) */
#define corto_mount_on_resume(_this, parent, id, object) ( \
    ((corto_function)corto_mount_on_resume_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_object (*)(corto_object, const char *, const char *, corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_resume_o)->index - 1])->fptr)(corto_mount(_this), parent, id, object) \
    : *(corto_object*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_resume_o)->index - 1], alloca(sizeof(corto_object)), corto_mount(_this), parent, id, object) \
    )

CORTO_EXPORT
uintptr_t _corto_mount_on_subscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* uintptr_t corto_mount_on_subscribe(corto_mount, corto_query *, uintptr_t) */
#define corto_mount_on_subscribe(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_subscribe_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_subscribe_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_subscribe_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this), query, ctx) \
    )

CORTO_EXPORT
uintptr_t _corto_mount_on_transaction_begin_v(
    corto_mount _this);

/* uintptr_t corto_mount_on_transaction_begin(corto_mount) */
#define corto_mount_on_transaction_begin(_this) ( \
    ((corto_function)corto_mount_on_transaction_begin_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_begin_o)->index - 1])->fptr)(corto_mount(_this)) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_begin_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this)) \
    )

CORTO_EXPORT
void _corto_mount_on_transaction_end_v(
    corto_mount _this,
    corto_subscriberEventIter events,
    uintptr_t ctx);

/* void corto_mount_on_transaction_end(corto_mount, corto_subscriberEventIter, uintptr_t) */
#define corto_mount_on_transaction_end(_this, events, ctx) ( \
    ((corto_function)corto_mount_on_transaction_end_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriberEventIter, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_end_o)->index - 1])->fptr)(corto_mount(_this), events, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_end_o)->index - 1], NULL, corto_mount(_this), events, ctx) \
    )

CORTO_EXPORT
void _corto_mount_on_unmount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* void corto_mount_on_unmount(corto_mount, corto_query *, uintptr_t) */
#define corto_mount_on_unmount(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_unmount_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unmount_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unmount_o)->index - 1], NULL, corto_mount(_this), query, ctx) \
    )

CORTO_EXPORT
void _corto_mount_on_unsubscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* void corto_mount_on_unsubscribe(corto_mount, corto_query *, uintptr_t) */
#define corto_mount_on_unsubscribe(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_unsubscribe_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unsubscribe_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unsubscribe_o)->index - 1], NULL, corto_mount(_this), query, ctx) \
    )

CORTO_EXPORT
void _corto_mount_onPoll(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_post(
    corto_mount _this,
    corto_event *e);

CORTO_EXPORT
void _corto_mount_publish(
    corto_mount _this,
    corto_eventMask event,
    const char *from,
    const char *id,
    const char *type,
    uintptr_t value);

CORTO_EXPORT
corto_resultIter _corto_mount_query(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
corto_object _corto_mount_resume(
    corto_mount _this,
    const char *parent,
    const char *name,
    corto_object o);

CORTO_EXPORT
void _corto_mount_return(
    corto_mount _this,
    corto_result *r);

CORTO_EXPORT
int16_t _corto_mount_setContentType(
    corto_mount _this,
    const char *type);

CORTO_EXPORT
int16_t _corto_mount_setContentTypeIn(
    corto_mount _this,
    const char *type);

CORTO_EXPORT
int16_t _corto_mount_setContentTypeOut(
    corto_mount _this,
    const char *type);

CORTO_EXPORT
void _corto_mount_subscribe(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
void _corto_mount_unsubscribe(
    corto_mount _this,
    corto_query *query);


/* procedure corto/vstore/observer */

CORTO_EXPORT
int16_t _corto_observer_construct(
    corto_observer _this);

CORTO_EXPORT
void _corto_observer_destruct(
    corto_observer _this);

CORTO_EXPORT
int16_t _corto_observer_init(
    corto_observer _this);

CORTO_EXPORT
int16_t _corto_observer_observe(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

CORTO_EXPORT
bool _corto_observer_observing(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

CORTO_EXPORT
int16_t _corto_observer_unobserve(
    corto_observer _this,
    corto_object instance,
    corto_object observable);


/* struct corto/vstore/observerEvent */

CORTO_EXPORT
void _corto_observerEvent_deinit(
    corto_observerEvent* _this);

CORTO_EXPORT
void _corto_observerEvent_handle(
    corto_event *e);

CORTO_EXPORT
int16_t _corto_observerEvent_init(
    corto_observerEvent* _this);


/* struct corto/vstore/query */

CORTO_EXPORT
uint32_t _corto_query_cardinality(
    corto_query* _this);

CORTO_EXPORT
bool _corto_query_match(
    corto_query* _this,
    corto_result *result);


/* struct corto/vstore/result */

CORTO_EXPORT
corto_string _corto_result_contentof(
    corto_result* _this,
    const char *contentType);

CORTO_EXPORT
int16_t _corto_result_fromcontent(
    corto_result* _this,
    const char *contentType,
    const char *content);

CORTO_EXPORT
corto_string _corto_result_getText(
    corto_result* _this);


/* procedure corto/vstore/route */

CORTO_EXPORT
int16_t _corto_route_construct(
    corto_route _this);

CORTO_EXPORT
int16_t _corto_route_init(
    corto_route _this);


/* class corto/vstore/router */

CORTO_EXPORT
int16_t _corto_router_construct(
    corto_router _this);

CORTO_EXPORT
int16_t _corto_router_init(
    corto_router _this);

CORTO_EXPORT
int16_t _corto_router_match(
    corto_object instance,
    const char *request,
    corto_any param,
    corto_any result,
    corto_route *matched);


/* class corto/vstore/routerimpl */

CORTO_EXPORT
int16_t _corto_routerimpl_construct(
    corto_routerimpl _this);

CORTO_EXPORT
void _corto_routerimpl_destruct(
    corto_routerimpl _this);

CORTO_EXPORT
corto_route _corto_routerimpl_findRoute_v(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* corto_route corto_routerimpl_findRoute(corto_routerimpl, corto_object, corto_stringseq, corto_any, corto_any *) */
#define corto_routerimpl_findRoute(_this, instance, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_findRoute_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_route (*)(corto_object, corto_object, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_findRoute_o)->index - 1])->fptr)(corto_routerimpl(_this), instance, pattern, param, routerData) \
    : *(corto_route*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_findRoute_o)->index - 1], alloca(sizeof(corto_route)), corto_routerimpl(_this), instance, pattern, param, routerData) \
    )

CORTO_EXPORT
int32_t _corto_routerimpl_matchRoute_v(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* int32_t corto_routerimpl_matchRoute(corto_routerimpl, corto_route, corto_stringseq, corto_any, corto_any *) */
#define corto_routerimpl_matchRoute(_this, route, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_matchRoute_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_int32 (*)(corto_object, corto_route, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_matchRoute_o)->index - 1])->fptr)(corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    : *(int32_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_matchRoute_o)->index - 1], alloca(sizeof(int32_t)), corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    )


/* procedure corto/vstore/subscriber */

CORTO_EXPORT
int16_t _corto_subscriber_construct(
    corto_subscriber _this);

CORTO_EXPORT
void _corto_subscriber_define(
    corto_subscriber _this);

CORTO_EXPORT
void _corto_subscriber_deinit(
    corto_subscriber _this);

CORTO_EXPORT
void _corto_subscriber_destruct(
    corto_subscriber _this);

CORTO_EXPORT
int16_t _corto_subscriber_init(
    corto_subscriber _this);

CORTO_EXPORT
int16_t _corto_subscriber_subscribe(
    corto_subscriber _this,
    corto_object instance);

CORTO_EXPORT
int16_t _corto_subscriber_unsubscribe(
    corto_subscriber _this,
    corto_object instance);


/* struct corto/vstore/subscriberEvent */

CORTO_EXPORT
void _corto_subscriberEvent_deinit(
    corto_subscriberEvent* _this);

CORTO_EXPORT
void _corto_subscriberEvent_handle(
    corto_event *e);

CORTO_EXPORT
int16_t _corto_subscriberEvent_init(
    corto_subscriberEvent* _this);

/* -- Support macro's -- */
#ifndef BUILDING_CORTO
#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
#define corto_event_handle(_this) _corto_event_handle(_this)
#define corto_fmt_data_deinit(_this) _corto_fmt_data_deinit(_this)
#define corto_frame_getTime(_this) _corto_frame_getTime(_this)
#define corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(_this)
#define corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
#define corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
#define corto_loader_on_query_v(_this, query) _corto_loader_on_query_v(corto_loader(_this), query)
#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
#define corto_mount_historyQuery(_this, query) _corto_mount_historyQuery(corto_mount(_this), query)
#define corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
#define corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
#define corto_mount_on_batch_notify_v(_this, events) _corto_mount_on_batch_notify_v(corto_mount(_this), events)
#define corto_mount_on_history_batch_notify_v(_this, events) _corto_mount_on_history_batch_notify_v(corto_mount(_this), events)
#define corto_mount_on_history_query_v(_this, query) _corto_mount_on_history_query_v(corto_mount(_this), query)
#define corto_mount_on_id_v(_this) _corto_mount_on_id_v(corto_mount(_this))
#define corto_mount_on_invoke_v(_this, instance, proc, argptrs) _corto_mount_on_invoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)
#define corto_mount_on_mount_v(_this, query, ctx) _corto_mount_on_mount_v(corto_mount(_this), query, ctx)
#define corto_mount_on_notify_v(_this, event) _corto_mount_on_notify_v(corto_mount(_this), event)
#define corto_mount_on_query_v(_this, query) _corto_mount_on_query_v(corto_mount(_this), query)
#define corto_mount_on_resume_v(_this, parent, id, object) _corto_mount_on_resume_v(corto_mount(_this), parent, id, object)
#define corto_mount_on_subscribe_v(_this, query, ctx) _corto_mount_on_subscribe_v(corto_mount(_this), query, ctx)
#define corto_mount_on_transaction_begin_v(_this) _corto_mount_on_transaction_begin_v(corto_mount(_this))
#define corto_mount_on_transaction_end_v(_this, events, ctx) _corto_mount_on_transaction_end_v(corto_mount(_this), events, ctx)
#define corto_mount_on_unmount_v(_this, query, ctx) _corto_mount_on_unmount_v(corto_mount(_this), query, ctx)
#define corto_mount_on_unsubscribe_v(_this, query, ctx) _corto_mount_on_unsubscribe_v(corto_mount(_this), query, ctx)
#define corto_mount_onPoll(_this) _corto_mount_onPoll(corto_mount(_this))
#define corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), e)
#define corto_mount_publish(_this, event, from, id, type, value) _corto_mount_publish(corto_mount(_this), event, from, id, type, value)
#define corto_mount_query(_this, query) _corto_mount_query(corto_mount(_this), query)
#define corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)
#define corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
#define corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)
#define corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)
#define corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)
#define corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)
#define corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)
#define corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
#define corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
#define corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
#define corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
#define corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
#define corto_observerEvent_deinit(_this) _corto_observerEvent_deinit(_this)
#define corto_observerEvent_handle(e) _corto_observerEvent_handle(e)
#define corto_observerEvent_init(_this) _corto_observerEvent_init(_this)
#define corto_query_cardinality(_this) _corto_query_cardinality(_this)
#define corto_query_match(_this, result) _corto_query_match(_this, result)
#define corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)
#define corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)
#define corto_result_getText(_this) _corto_result_getText(_this)
#define corto_route_construct(_this) _corto_route_construct(corto_route(_this))
#define corto_route_init(_this) _corto_route_init(corto_route(_this))
#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))
#define corto_router_init(_this) _corto_router_init(corto_router(_this))
#define corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
#define corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
#define corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
#define corto_routerimpl_findRoute_v(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), instance, pattern, param, routerData)
#define corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
#define corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
#define corto_subscriber_define(_this) _corto_subscriber_define(corto_subscriber(_this))
#define corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
#define corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
#define corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
#define corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
#define corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
#define corto_subscriberEvent_deinit(_this) _corto_subscriberEvent_deinit(_this)
#define corto_subscriberEvent_handle(e) _corto_subscriberEvent_handle(e)
#define corto_subscriberEvent_init(_this) _corto_subscriberEvent_init(_this)
#else
#define corto_dispatcher_post_v _corto_dispatcher_post_v
#define corto_event_handle _corto_event_handle
#define corto_fmt_data_deinit _corto_fmt_data_deinit
#define corto_frame_getTime _corto_frame_getTime
#define corto_invokeEvent_handle_v _corto_invokeEvent_handle_v
#define corto_loader_construct _corto_loader_construct
#define corto_loader_destruct _corto_loader_destruct
#define corto_loader_on_query_v _corto_loader_on_query_v
#define corto_mount_construct _corto_mount_construct
#define corto_mount_destruct _corto_mount_destruct
#define corto_mount_historyQuery _corto_mount_historyQuery
#define corto_mount_id _corto_mount_id
#define corto_mount_init _corto_mount_init
#define corto_mount_invoke _corto_mount_invoke
#define corto_mount_on_batch_notify_v _corto_mount_on_batch_notify_v
#define corto_mount_on_history_batch_notify_v _corto_mount_on_history_batch_notify_v
#define corto_mount_on_history_query_v _corto_mount_on_history_query_v
#define corto_mount_on_id_v _corto_mount_on_id_v
#define corto_mount_on_invoke_v _corto_mount_on_invoke_v
#define corto_mount_on_mount_v _corto_mount_on_mount_v
#define corto_mount_on_notify_v _corto_mount_on_notify_v
#define corto_mount_on_query_v _corto_mount_on_query_v
#define corto_mount_on_resume_v _corto_mount_on_resume_v
#define corto_mount_on_subscribe_v _corto_mount_on_subscribe_v
#define corto_mount_on_transaction_begin_v _corto_mount_on_transaction_begin_v
#define corto_mount_on_transaction_end_v _corto_mount_on_transaction_end_v
#define corto_mount_on_unmount_v _corto_mount_on_unmount_v
#define corto_mount_on_unsubscribe_v _corto_mount_on_unsubscribe_v
#define corto_mount_onPoll _corto_mount_onPoll
#define corto_mount_post _corto_mount_post
#define corto_mount_publish _corto_mount_publish
#define corto_mount_query _corto_mount_query
#define corto_mount_resume _corto_mount_resume
#define corto_mount_return _corto_mount_return
#define corto_mount_setContentType _corto_mount_setContentType
#define corto_mount_setContentTypeIn _corto_mount_setContentTypeIn
#define corto_mount_setContentTypeOut _corto_mount_setContentTypeOut
#define corto_mount_subscribe _corto_mount_subscribe
#define corto_mount_unsubscribe _corto_mount_unsubscribe
#define corto_observer_construct _corto_observer_construct
#define corto_observer_destruct _corto_observer_destruct
#define corto_observer_init _corto_observer_init
#define corto_observer_observe _corto_observer_observe
#define corto_observer_observing _corto_observer_observing
#define corto_observer_unobserve _corto_observer_unobserve
#define corto_observerEvent_deinit _corto_observerEvent_deinit
#define corto_observerEvent_handle _corto_observerEvent_handle
#define corto_observerEvent_init _corto_observerEvent_init
#define corto_query_cardinality _corto_query_cardinality
#define corto_query_match _corto_query_match
#define corto_result_contentof _corto_result_contentof
#define corto_result_fromcontent _corto_result_fromcontent
#define corto_result_getText _corto_result_getText
#define corto_route_construct _corto_route_construct
#define corto_route_init _corto_route_init
#define corto_router_construct _corto_router_construct
#define corto_router_init _corto_router_init
#define corto_router_match _corto_router_match
#define corto_routerimpl_construct _corto_routerimpl_construct
#define corto_routerimpl_destruct _corto_routerimpl_destruct
#define corto_routerimpl_findRoute_v _corto_routerimpl_findRoute_v
#define corto_routerimpl_matchRoute_v _corto_routerimpl_matchRoute_v
#define corto_subscriber_construct _corto_subscriber_construct
#define corto_subscriber_define _corto_subscriber_define
#define corto_subscriber_deinit _corto_subscriber_deinit
#define corto_subscriber_destruct _corto_subscriber_destruct
#define corto_subscriber_init _corto_subscriber_init
#define corto_subscriber_subscribe _corto_subscriber_subscribe
#define corto_subscriber_unsubscribe _corto_subscriber_unsubscribe
#define corto_subscriberEvent_deinit _corto_subscriberEvent_deinit
#define corto_subscriberEvent_handle _corto_subscriberEvent_handle
#define corto_subscriberEvent_init _corto_subscriberEvent_init
#ifndef __cplusplus
#endif
#endif
#define safe_corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
#define safe_corto_event_handle(_this) _corto_event_handle(_this)
#define safe_corto_fmt_data_deinit(_this) _corto_fmt_data_deinit(_this)
#define safe_corto_frame_getTime(_this) _corto_frame_getTime(_this)
#define safe_corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(_this)
#define safe_corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
#define safe_corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
#define safe_corto_loader_on_query_v(_this, query) _corto_loader_on_query_v(corto_loader(_this), query)
#define safe_corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
#define safe_corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
#define safe_corto_mount_historyQuery(_this, query) _corto_mount_historyQuery(corto_mount(_this), query)
#define safe_corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
#define safe_corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
#define safe_corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
#define safe_corto_mount_on_batch_notify_v(_this, events) _corto_mount_on_batch_notify_v(corto_mount(_this), events)
#define safe_corto_mount_on_history_batch_notify_v(_this, events) _corto_mount_on_history_batch_notify_v(corto_mount(_this), events)
#define safe_corto_mount_on_history_query_v(_this, query) _corto_mount_on_history_query_v(corto_mount(_this), query)
#define safe_corto_mount_on_id_v(_this) _corto_mount_on_id_v(corto_mount(_this))
#define safe_corto_mount_on_invoke_v(_this, instance, proc, argptrs) _corto_mount_on_invoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)
#define safe_corto_mount_on_mount_v(_this, query, ctx) _corto_mount_on_mount_v(corto_mount(_this), query, ctx)
#define safe_corto_mount_on_notify_v(_this, event) _corto_mount_on_notify_v(corto_mount(_this), event)
#define safe_corto_mount_on_query_v(_this, query) _corto_mount_on_query_v(corto_mount(_this), query)
#define safe_corto_mount_on_resume_v(_this, parent, id, object) _corto_mount_on_resume_v(corto_mount(_this), parent, id, object)
#define safe_corto_mount_on_subscribe_v(_this, query, ctx) _corto_mount_on_subscribe_v(corto_mount(_this), query, ctx)
#define safe_corto_mount_on_transaction_begin_v(_this) _corto_mount_on_transaction_begin_v(corto_mount(_this))
#define safe_corto_mount_on_transaction_end_v(_this, events, ctx) _corto_mount_on_transaction_end_v(corto_mount(_this), events, ctx)
#define safe_corto_mount_on_unmount_v(_this, query, ctx) _corto_mount_on_unmount_v(corto_mount(_this), query, ctx)
#define safe_corto_mount_on_unsubscribe_v(_this, query, ctx) _corto_mount_on_unsubscribe_v(corto_mount(_this), query, ctx)
#define safe_corto_mount_onPoll(_this) _corto_mount_onPoll(corto_mount(_this))
#define safe_corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), e)
#define safe_corto_mount_publish(_this, event, from, id, type, value) _corto_mount_publish(corto_mount(_this), event, from, id, type, value)
#define safe_corto_mount_query(_this, query) _corto_mount_query(corto_mount(_this), query)
#define safe_corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)
#define safe_corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
#define safe_corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)
#define safe_corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)
#define safe_corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)
#define safe_corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)
#define safe_corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)
#define safe_corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
#define safe_corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
#define safe_corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
#define safe_corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
#define safe_corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
#define safe_corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
#define safe_corto_observerEvent_deinit(_this) _corto_observerEvent_deinit(_this)
#define safe_corto_observerEvent_handle(e) _corto_observerEvent_handle(e)
#define safe_corto_observerEvent_init(_this) _corto_observerEvent_init(_this)
#define safe_corto_query_cardinality(_this) _corto_query_cardinality(_this)
#define safe_corto_query_match(_this, result) _corto_query_match(_this, result)
#define safe_corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)
#define safe_corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)
#define safe_corto_result_getText(_this) _corto_result_getText(_this)
#define safe_corto_route_construct(_this) _corto_route_construct(corto_route(_this))
#define safe_corto_route_init(_this) _corto_route_init(corto_route(_this))
#define safe_corto_router_construct(_this) _corto_router_construct(corto_router(_this))
#define safe_corto_router_init(_this) _corto_router_init(corto_router(_this))
#define safe_corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
#define safe_corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
#define safe_corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
#define safe_corto_routerimpl_findRoute_v(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), instance, pattern, param, routerData)
#define safe_corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
#define safe_corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
#define safe_corto_subscriber_define(_this) _corto_subscriber_define(corto_subscriber(_this))
#define safe_corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
#define safe_corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
#define safe_corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
#define safe_corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
#define safe_corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
#define safe_corto_subscriberEvent_deinit(_this) _corto_subscriberEvent_deinit(_this)
#define safe_corto_subscriberEvent_handle(e) _corto_subscriberEvent_handle(e)
#define safe_corto_subscriberEvent_init(_this) _corto_subscriberEvent_init(_this)

#ifdef __cplusplus
}
#endif

#endif

