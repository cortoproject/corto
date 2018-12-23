/* _interface.h
 * This file is generated. Do not modify the contents of this file.
 */

#ifndef CORTO_VSTORE_INTERFACE_H
#define CORTO_VSTORE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif



/* interface corto/vstore/dispatcher */

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


/* struct corto/vstore/invoke_event */

CORTO_EXPORT
void _corto_invoke_event_handle_v(
    corto_invoke_event* _this);


/* class corto/vstore/loader */

CORTO_EXPORT
int16_t _corto_loader_construct(
    corto_loader _this);

CORTO_EXPORT
void _corto_loader_destruct(
    corto_loader _this);

CORTO_EXPORT
corto_recordIter _corto_loader_on_query_v(
    corto_loader _this,
    corto_query *query);

CORTO_EXPORT
int16_t _corto_loader_on_resume(
    corto_loader _this,
    const char *parent,
    const char *id,
    corto_object *object);


/* class corto/vstore/mount */

CORTO_EXPORT
int16_t _corto_mount_construct(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_destruct(
    corto_mount _this);

CORTO_EXPORT
corto_recordIter _corto_mount_historyQuery(
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
    uint32_t event_count,
    corto_subscriber_eventIter events);

CORTO_EXPORT
void _corto_mount_on_history_batch_notify_v(
    corto_mount _this,
    uint32_t event_count,
    corto_subscriber_eventIter events);

CORTO_EXPORT
corto_recordIter _corto_mount_on_history_query_v(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
corto_string _corto_mount_on_id_v(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_on_invoke_v(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

CORTO_EXPORT
uintptr_t _corto_mount_on_mount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

CORTO_EXPORT
void _corto_mount_on_notify_v(
    corto_mount _this,
    corto_subscriber_event *event);

CORTO_EXPORT
corto_recordIter _corto_mount_on_query_v(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
int16_t _corto_mount_on_resume_v(
    corto_mount _this,
    const char *parent,
    const char *id,
    corto_object *object);

CORTO_EXPORT
uintptr_t _corto_mount_on_subscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

CORTO_EXPORT
uintptr_t _corto_mount_on_transaction_begin_v(
    corto_mount _this);

CORTO_EXPORT
void _corto_mount_on_transaction_end_v(
    corto_mount _this,
    corto_subscriber_eventIter events,
    uintptr_t ctx);

CORTO_EXPORT
void _corto_mount_on_unmount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

CORTO_EXPORT
void _corto_mount_on_unsubscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

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
corto_recordIter _corto_mount_query(
    corto_mount _this,
    corto_query *query);

CORTO_EXPORT
int16_t _corto_mount_resume(
    corto_mount _this,
    const char *parent,
    const char *id,
    corto_object *o_out);

CORTO_EXPORT
void _corto_mount_return(
    corto_mount _this,
    corto_record *r);

CORTO_EXPORT
int16_t _corto_mount_set_format(
    corto_mount _this,
    const char *type);

CORTO_EXPORT
int16_t _corto_mount_set_formatIn(
    corto_mount _this,
    const char *type);

CORTO_EXPORT
int16_t _corto_mount_set_formatOut(
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


/* struct corto/vstore/observer_event */

CORTO_EXPORT
void _corto_observer_event_deinit(
    corto_observer_event* _this);

CORTO_EXPORT
void _corto_observer_event_handle(
    corto_event *e);

CORTO_EXPORT
int16_t _corto_observer_event_init(
    corto_observer_event* _this);


/* struct corto/vstore/query */

CORTO_EXPORT
uint32_t _corto_query_cardinality(
    corto_query* _this);

CORTO_EXPORT
bool _corto_query_match(
    corto_query* _this,
    corto_record *record);


/* struct corto/vstore/record */

CORTO_EXPORT
corto_string _corto_record_contentof(
    corto_record* _this,
    const char *format);

CORTO_EXPORT
int16_t _corto_record_fromcontent(
    corto_record* _this,
    const char *format,
    const char *content);

CORTO_EXPORT
corto_string _corto_record_get_text(
    corto_record* _this);


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
corto_route _corto_routerimpl_find_route_v(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

CORTO_EXPORT
int32_t _corto_routerimpl_match_route_v(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);


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


/* struct corto/vstore/subscriber_event */

CORTO_EXPORT
void _corto_subscriber_event_deinit(
    corto_subscriber_event* _this);

CORTO_EXPORT
void _corto_subscriber_event_handle(
    corto_event *e);

CORTO_EXPORT
int16_t _corto_subscriber_event_init(
    corto_subscriber_event* _this);

#ifdef __cplusplus
}
#endif

#endif
