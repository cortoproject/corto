/* _binding.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_VSTORE_BINDING_H
#define CORTO_VSTORE_BINDING_H

/* -- Type casting -- */
#define corto_dispatcher(o) ((corto_dispatcher)ut_assert_type((corto_type)corto_dispatcher_o, o))
#define corto_handleAction(o) ((corto_handleAction*)ut_assert_type((corto_type)corto_handleAction_o, o))
#define corto_event(o) ((corto_event*)ut_assert_type((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask*)ut_assert_type((corto_type)corto_eventMask_o, o))
#define corto_fmt_data(o) ((corto_fmt_data*)ut_assert_type((corto_type)corto_fmt_data_o, o))
#define corto_frameKind(o) ((corto_frameKind*)ut_assert_type((corto_type)corto_frameKind_o, o))
#define corto_frame(o) ((corto_frame*)ut_assert_type((corto_type)corto_frame_o, o))
#define corto_observer(o) ((corto_observer)ut_assert_type((corto_type)corto_observer_o, o))
#define corto_query(o) ((corto_query*)ut_assert_type((corto_type)corto_query_o, o))
#define corto_subscriber(o) ((corto_subscriber)ut_assert_type((corto_type)corto_subscriber_o, o))
#define corto_ownership(o) ((corto_ownership*)ut_assert_type((corto_type)corto_ownership_o, o))
#define corto_mountCallbackMask(o) ((corto_mountCallbackMask*)ut_assert_type((corto_type)corto_mountCallbackMask_o, o))
#define corto_mount_subscription(o) ((corto_mount_subscription*)ut_assert_type((corto_type)corto_mount_subscription_o, o))
#define corto_mount_subscriptionList(o) ((corto_mount_subscriptionList*)ut_assert_type((corto_type)corto_mount_subscriptionList_o, o))
#define corto_time(o) ((corto_time*)ut_assert_type((corto_type)corto_time_o, o))
#define corto_mount(o) ((corto_mount)ut_assert_type((corto_type)corto_mount_o, o))
#define corto_invoke_event(o) ((corto_invoke_event*)ut_assert_type((corto_type)corto_invoke_event_o, o))
#define corto_loader(o) ((corto_loader)ut_assert_type((corto_type)corto_loader_o, o))
#define corto_objectIter(o) ((corto_objectIter*)ut_assert_type((corto_type)corto_objectIter_o, o))
#define corto_observer_event(o) ((corto_observer_event*)ut_assert_type((corto_type)corto_observer_event_o, o))
#define corto_operatorKind(o) ((corto_operatorKind*)ut_assert_type((corto_type)corto_operatorKind_o, o))
#define corto_recordMask(o) ((corto_recordMask*)ut_assert_type((corto_type)corto_recordMask_o, o))
#define corto_sample(o) ((corto_sample*)ut_assert_type((corto_type)corto_sample_o, o))
#define corto_sampleIter(o) ((corto_sampleIter*)ut_assert_type((corto_type)corto_sampleIter_o, o))
#define corto_record(o) ((corto_record*)ut_assert_type((corto_type)corto_record_o, o))
#define corto_recordIter(o) ((corto_recordIter*)ut_assert_type((corto_type)corto_recordIter_o, o))
#define corto_recordlist(o) ((corto_recordlist*)ut_assert_type((corto_type)corto_recordlist_o, o))
#define corto_remote(o) ((corto_remote)ut_assert_type((corto_type)corto_remote_o, o))
#define corto_route(o) ((corto_route)ut_assert_type((corto_type)corto_route_o, o))
#define corto_router(o) ((corto_router)ut_assert_type((corto_type)corto_router_o, o))
#define corto_routerimpl(o) ((corto_routerimpl)ut_assert_type((corto_type)corto_routerimpl_o, o))
#define corto_subscriber_event(o) ((corto_subscriber_event*)ut_assert_type((corto_type)corto_subscriber_event_o, o))
#define corto_subscriber_eventIter(o) ((corto_subscriber_eventIter*)ut_assert_type((corto_type)corto_subscriber_eventIter_o, o))

/* -- Non-expanding typedefs -- */
typedef corto_dispatcher _type_corto_dispatcher;
typedef corto_handleAction _type_corto_handleAction;
typedef corto_event _type_corto_event;
typedef corto_eventMask _type_corto_eventMask;
typedef corto_fmt_data _type_corto_fmt_data;
typedef corto_frameKind _type_corto_frameKind;
typedef corto_frame _type_corto_frame;
typedef corto_observer _type_corto_observer;
typedef corto_query _type_corto_query;
typedef corto_subscriber _type_corto_subscriber;
typedef corto_ownership _type_corto_ownership;
typedef corto_mountCallbackMask _type_corto_mountCallbackMask;
typedef corto_mount_subscription _type_corto_mount_subscription;
#ifndef _type_corto_mount_subscriptionList_DEFINED
#define _type_corto_mount_subscriptionList_DEFINED
typedef corto_mount_subscriptionList _type_corto_mount_subscriptionList;
#endif
typedef corto_time _type_corto_time;
typedef corto_mount _type_corto_mount;
typedef corto_invoke_event _type_corto_invoke_event;
typedef corto_loader _type_corto_loader;
#ifndef _type_corto_objectIter_DEFINED
#define _type_corto_objectIter_DEFINED
typedef corto_objectIter _type_corto_objectIter;
#endif
typedef corto_observer_event _type_corto_observer_event;
typedef corto_operatorKind _type_corto_operatorKind;
typedef corto_recordMask _type_corto_recordMask;
typedef corto_sample _type_corto_sample;
#ifndef _type_corto_sampleIter_DEFINED
#define _type_corto_sampleIter_DEFINED
typedef corto_sampleIter _type_corto_sampleIter;
#endif
typedef corto_record _type_corto_record;
#ifndef _type_corto_recordIter_DEFINED
#define _type_corto_recordIter_DEFINED
typedef corto_recordIter _type_corto_recordIter;
#endif
typedef corto_recordlist _type_corto_recordlist;
typedef corto_remote _type_corto_remote;
typedef corto_route _type_corto_route;
typedef corto_router _type_corto_router;
typedef corto_routerimpl _type_corto_routerimpl;
typedef corto_subscriber_event _type_corto_subscriber_event;
#ifndef _type_corto_subscriber_eventIter_DEFINED
#define _type_corto_subscriber_eventIter_DEFINED
typedef corto_subscriber_eventIter _type_corto_subscriber_eventIter;
#endif

/* -- Argument type casting -- */
#ifndef CORTO_IMPL
#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
#define corto_event_handle(_this) _corto_event_handle(_this)
#define corto_fmt_data_deinit(_this) _corto_fmt_data_deinit(_this)
#define corto_frame_getTime(_this) _corto_frame_getTime(_this)
#define corto_invoke_event_handle_v(_this) _corto_invoke_event_handle_v(_this)
#define corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
#define corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
#define corto_loader_on_query_v(_this, query) _corto_loader_on_query_v(corto_loader(_this), query)
#define corto_loader_on_resume(_this, parent, id, object) _corto_loader_on_resume(corto_loader(_this), parent, id, object)
#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
#define corto_mount_historyQuery(_this, query) _corto_mount_historyQuery(corto_mount(_this), query)
#define corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
#define corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
#define corto_mount_on_batch_notify_v(_this, event_count, events) _corto_mount_on_batch_notify_v(corto_mount(_this), event_count, events)
#define corto_mount_on_history_batch_notify_v(_this, event_count, events) _corto_mount_on_history_batch_notify_v(corto_mount(_this), event_count, events)
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
#define corto_mount_resume(_this, parent, id, o_out) _corto_mount_resume(corto_mount(_this), parent, id, o_out)
#define corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
#define corto_mount_set_format(_this, type) _corto_mount_set_format(corto_mount(_this), type)
#define corto_mount_set_formatIn(_this, type) _corto_mount_set_formatIn(corto_mount(_this), type)
#define corto_mount_set_formatOut(_this, type) _corto_mount_set_formatOut(corto_mount(_this), type)
#define corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)
#define corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)
#define corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
#define corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
#define corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
#define corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
#define corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
#define corto_observer_event_deinit(_this) _corto_observer_event_deinit(_this)
#define corto_observer_event_handle(e) _corto_observer_event_handle(e)
#define corto_observer_event_init(_this) _corto_observer_event_init(_this)
#define corto_query_cardinality(_this) _corto_query_cardinality(_this)
#define corto_query_match(_this, record) _corto_query_match(_this, record)
#define corto_record_contentof(_this, format) _corto_record_contentof(_this, format)
#define corto_record_fromcontent(_this, format, content) _corto_record_fromcontent(_this, format, content)
#define corto_record_get_text(_this) _corto_record_get_text(_this)
#define corto_route_construct(_this) _corto_route_construct(corto_route(_this))
#define corto_route_init(_this) _corto_route_init(corto_route(_this))
#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))
#define corto_router_init(_this) _corto_router_init(corto_router(_this))
#define corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
#define corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
#define corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
#define corto_routerimpl_find_route_v(_this, instance, pattern, param, routerData) _corto_routerimpl_find_route_v(corto_routerimpl(_this), instance, pattern, param, routerData)
#define corto_routerimpl_match_route_v(_this, route, pattern, param, routerData) _corto_routerimpl_match_route_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
#define corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
#define corto_subscriber_define(_this) _corto_subscriber_define(corto_subscriber(_this))
#define corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
#define corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
#define corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
#define corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
#define corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
#define corto_subscriber_event_deinit(_this) _corto_subscriber_event_deinit(_this)
#define corto_subscriber_event_handle(e) _corto_subscriber_event_handle(e)
#define corto_subscriber_event_init(_this) _corto_subscriber_event_init(_this)
#else
/* Can't use argument type casting macro's within project, as they would
 * substitute headers in implementation files. */
#define corto_dispatcher_post_v _corto_dispatcher_post_v
#define corto_event_handle _corto_event_handle
#define corto_fmt_data_deinit _corto_fmt_data_deinit
#define corto_frame_getTime _corto_frame_getTime
#define corto_invoke_event_handle_v _corto_invoke_event_handle_v
#define corto_loader_construct _corto_loader_construct
#define corto_loader_destruct _corto_loader_destruct
#define corto_loader_on_query_v _corto_loader_on_query_v
#define corto_loader_on_resume _corto_loader_on_resume
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
#define corto_mount_set_format _corto_mount_set_format
#define corto_mount_set_formatIn _corto_mount_set_formatIn
#define corto_mount_set_formatOut _corto_mount_set_formatOut
#define corto_mount_subscribe _corto_mount_subscribe
#define corto_mount_unsubscribe _corto_mount_unsubscribe
#define corto_observer_construct _corto_observer_construct
#define corto_observer_destruct _corto_observer_destruct
#define corto_observer_init _corto_observer_init
#define corto_observer_observe _corto_observer_observe
#define corto_observer_observing _corto_observer_observing
#define corto_observer_unobserve _corto_observer_unobserve
#define corto_observer_event_deinit _corto_observer_event_deinit
#define corto_observer_event_handle _corto_observer_event_handle
#define corto_observer_event_init _corto_observer_event_init
#define corto_query_cardinality _corto_query_cardinality
#define corto_query_match _corto_query_match
#define corto_record_contentof _corto_record_contentof
#define corto_record_fromcontent _corto_record_fromcontent
#define corto_record_get_text _corto_record_get_text
#define corto_route_construct _corto_route_construct
#define corto_route_init _corto_route_init
#define corto_router_construct _corto_router_construct
#define corto_router_init _corto_router_init
#define corto_router_match _corto_router_match
#define corto_routerimpl_construct _corto_routerimpl_construct
#define corto_routerimpl_destruct _corto_routerimpl_destruct
#define corto_routerimpl_find_route_v _corto_routerimpl_find_route_v
#define corto_routerimpl_match_route_v _corto_routerimpl_match_route_v
#define corto_subscriber_construct _corto_subscriber_construct
#define corto_subscriber_define _corto_subscriber_define
#define corto_subscriber_deinit _corto_subscriber_deinit
#define corto_subscriber_destruct _corto_subscriber_destruct
#define corto_subscriber_init _corto_subscriber_init
#define corto_subscriber_subscribe _corto_subscriber_subscribe
#define corto_subscriber_unsubscribe _corto_subscriber_unsubscribe
#define corto_subscriber_event_deinit _corto_subscriber_event_deinit
#define corto_subscriber_event_handle _corto_subscriber_event_handle
#define corto_subscriber_event_init _corto_subscriber_event_init
/* Macro for doing argument type casting within project. */
#define safe_corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
#define safe_corto_event_handle(_this) _corto_event_handle(_this)
#define safe_corto_fmt_data_deinit(_this) _corto_fmt_data_deinit(_this)
#define safe_corto_frame_getTime(_this) _corto_frame_getTime(_this)
#define safe_corto_invoke_event_handle_v(_this) _corto_invoke_event_handle_v(_this)
#define safe_corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
#define safe_corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
#define safe_corto_loader_on_query_v(_this, query) _corto_loader_on_query_v(corto_loader(_this), query)
#define safe_corto_loader_on_resume(_this, parent, id, object) _corto_loader_on_resume(corto_loader(_this), parent, id, object)
#define safe_corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
#define safe_corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
#define safe_corto_mount_historyQuery(_this, query) _corto_mount_historyQuery(corto_mount(_this), query)
#define safe_corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
#define safe_corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
#define safe_corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
#define safe_corto_mount_on_batch_notify_v(_this, event_count, events) _corto_mount_on_batch_notify_v(corto_mount(_this), event_count, events)
#define safe_corto_mount_on_history_batch_notify_v(_this, event_count, events) _corto_mount_on_history_batch_notify_v(corto_mount(_this), event_count, events)
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
#define safe_corto_mount_resume(_this, parent, id, o_out) _corto_mount_resume(corto_mount(_this), parent, id, o_out)
#define safe_corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
#define safe_corto_mount_set_format(_this, type) _corto_mount_set_format(corto_mount(_this), type)
#define safe_corto_mount_set_formatIn(_this, type) _corto_mount_set_formatIn(corto_mount(_this), type)
#define safe_corto_mount_set_formatOut(_this, type) _corto_mount_set_formatOut(corto_mount(_this), type)
#define safe_corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)
#define safe_corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)
#define safe_corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
#define safe_corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
#define safe_corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
#define safe_corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
#define safe_corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
#define safe_corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
#define safe_corto_observer_event_deinit(_this) _corto_observer_event_deinit(_this)
#define safe_corto_observer_event_handle(e) _corto_observer_event_handle(e)
#define safe_corto_observer_event_init(_this) _corto_observer_event_init(_this)
#define safe_corto_query_cardinality(_this) _corto_query_cardinality(_this)
#define safe_corto_query_match(_this, record) _corto_query_match(_this, record)
#define safe_corto_record_contentof(_this, format) _corto_record_contentof(_this, format)
#define safe_corto_record_fromcontent(_this, format, content) _corto_record_fromcontent(_this, format, content)
#define safe_corto_record_get_text(_this) _corto_record_get_text(_this)
#define safe_corto_route_construct(_this) _corto_route_construct(corto_route(_this))
#define safe_corto_route_init(_this) _corto_route_init(corto_route(_this))
#define safe_corto_router_construct(_this) _corto_router_construct(corto_router(_this))
#define safe_corto_router_init(_this) _corto_router_init(corto_router(_this))
#define safe_corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
#define safe_corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
#define safe_corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
#define safe_corto_routerimpl_find_route_v(_this, instance, pattern, param, routerData) _corto_routerimpl_find_route_v(corto_routerimpl(_this), instance, pattern, param, routerData)
#define safe_corto_routerimpl_match_route_v(_this, route, pattern, param, routerData) _corto_routerimpl_match_route_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
#define safe_corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
#define safe_corto_subscriber_define(_this) _corto_subscriber_define(corto_subscriber(_this))
#define safe_corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
#define safe_corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
#define safe_corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
#define safe_corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
#define safe_corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
#define safe_corto_subscriber_event_deinit(_this) _corto_subscriber_event_deinit(_this)
#define safe_corto_subscriber_event_handle(e) _corto_subscriber_event_handle(e)
#define safe_corto_subscriber_event_init(_this) _corto_subscriber_event_init(_this)
#endif
#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), e)

/* -- Overridable methods -- */
#define corto_invoke_event_handle(_this) ( \
    ((corto_function)corto_invoke_event_handle_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_invoke_event_handle_o)->index - 1])->fptr)(corto_invoke_event(_this)) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_invoke_event_handle_o)->index - 1], NULL, corto_invoke_event(_this)) \
    )
#define corto_loader_on_query(_this, query) ( \
    ((corto_function)corto_loader_on_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_recordIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1])->fptr)(corto_loader(_this), query) \
    : *(corto_recordIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1], alloca(sizeof(corto_recordIter)), corto_loader(_this), query) \
    )
#define corto_mount_on_batch_notify(_this, event_count, events) ( \
    ((corto_function)corto_mount_on_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, uint32_t, corto_subscriber_eventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), event_count, events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1], NULL, corto_mount(_this), event_count, events) \
    )
#define corto_mount_on_history_batch_notify(_this, event_count, events) ( \
    ((corto_function)corto_mount_on_history_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, uint32_t, corto_subscriber_eventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), event_count, events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1], NULL, corto_mount(_this), event_count, events) \
    )
#define corto_mount_on_history_query(_this, query) ( \
    ((corto_function)corto_mount_on_history_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_recordIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_recordIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1], alloca(sizeof(corto_recordIter)), corto_mount(_this), query) \
    )
#define corto_mount_on_id(_this) ( \
    ((corto_function)corto_mount_on_id_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_string (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_id_o)->index - 1])->fptr)(corto_mount(_this)) \
    : *(corto_string*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_id_o)->index - 1], alloca(sizeof(corto_string)), corto_mount(_this)) \
    )
#define corto_mount_on_invoke(_this, instance, proc, argptrs) ( \
    ((corto_function)corto_mount_on_invoke_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_object, corto_function, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_invoke_o)->index - 1])->fptr)(corto_mount(_this), instance, corto_function(proc), argptrs) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_invoke_o)->index - 1], NULL, corto_mount(_this), instance, corto_function(proc), argptrs) \
    )
#define corto_mount_on_mount(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_mount_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_mount_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_mount_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this), query, ctx) \
    )
#define corto_mount_on_notify(_this, event) ( \
    ((corto_function)corto_mount_on_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriber_event *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_notify_o)->index - 1])->fptr)(corto_mount(_this), event) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_notify_o)->index - 1], NULL, corto_mount(_this), event) \
    )
#define corto_mount_on_query(_this, query) ( \
    ((corto_function)corto_mount_on_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_recordIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_recordIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1], alloca(sizeof(corto_recordIter)), corto_mount(_this), query) \
    )
#define corto_mount_on_resume(_this, parent, id, object) ( \
    ((corto_function)corto_mount_on_resume_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_int16 (*)(corto_object, const char *, const char *, corto_object *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_resume_o)->index - 1])->fptr)(corto_mount(_this), parent, id, object) \
    : *(int16_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_resume_o)->index - 1], alloca(sizeof(int16_t)), corto_mount(_this), parent, id, object) \
    )
#define corto_mount_on_subscribe(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_subscribe_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_subscribe_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_subscribe_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this), query, ctx) \
    )
#define corto_mount_on_transaction_begin(_this) ( \
    ((corto_function)corto_mount_on_transaction_begin_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_word (*)(corto_object))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_begin_o)->index - 1])->fptr)(corto_mount(_this)) \
    : *(uintptr_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_begin_o)->index - 1], alloca(sizeof(uintptr_t)), corto_mount(_this)) \
    )
#define corto_mount_on_transaction_end(_this, events, ctx) ( \
    ((corto_function)corto_mount_on_transaction_end_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriber_eventIter, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_end_o)->index - 1])->fptr)(corto_mount(_this), events, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_transaction_end_o)->index - 1], NULL, corto_mount(_this), events, ctx) \
    )
#define corto_mount_on_unmount(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_unmount_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unmount_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unmount_o)->index - 1], NULL, corto_mount(_this), query, ctx) \
    )
#define corto_mount_on_unsubscribe(_this, query, ctx) ( \
    ((corto_function)corto_mount_on_unsubscribe_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_query *, uintptr_t))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unsubscribe_o)->index - 1])->fptr)(corto_mount(_this), query, ctx) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_unsubscribe_o)->index - 1], NULL, corto_mount(_this), query, ctx) \
    )
#define corto_routerimpl_find_route(_this, instance, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_find_route_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_route (*)(corto_object, corto_object, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_find_route_o)->index - 1])->fptr)(corto_routerimpl(_this), instance, pattern, param, routerData) \
    : *(corto_route*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_find_route_o)->index - 1], alloca(sizeof(corto_route)), corto_routerimpl(_this), instance, pattern, param, routerData) \
    )
#define corto_routerimpl_match_route(_this, route, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_match_route_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_int32 (*)(corto_object, corto_route, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_match_route_o)->index - 1])->fptr)(corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    : *(int32_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_match_route_o)->index - 1], alloca(sizeof(int32_t)), corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    )

/* -- Short identifier translation -- */

/* -- Short object variable translation -- */

#endif

