/* _binding.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_VSTORE_BINDING_H
#define CORTO_VSTORE_BINDING_H

/* -- Type casting -- */
#define corto_dispatcher(o) ((corto_dispatcher)corto_assert_type((corto_type)corto_dispatcher_o, o))
#define corto_handleAction(o) ((corto_handleAction*)corto_assert_type((corto_type)corto_handleAction_o, o))
#define corto_event(o) ((corto_event*)corto_assert_type((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask*)corto_assert_type((corto_type)corto_eventMask_o, o))
#define corto_fmt_data(o) ((corto_fmt_data*)corto_assert_type((corto_type)corto_fmt_data_o, o))
#define corto_frameKind(o) ((corto_frameKind*)corto_assert_type((corto_type)corto_frameKind_o, o))
#define corto_frame(o) ((corto_frame*)corto_assert_type((corto_type)corto_frame_o, o))
#define corto_observer(o) ((corto_observer)corto_assert_type((corto_type)corto_observer_o, o))
#define corto_query(o) ((corto_query*)corto_assert_type((corto_type)corto_query_o, o))
#define corto_subscriber(o) ((corto_subscriber)corto_assert_type((corto_type)corto_subscriber_o, o))
#define corto_ownership(o) ((corto_ownership*)corto_assert_type((corto_type)corto_ownership_o, o))
#define corto_mountMask(o) ((corto_mountMask*)corto_assert_type((corto_type)corto_mountMask_o, o))
#define corto_queuePolicy(o) ((corto_queuePolicy*)corto_assert_type((corto_type)corto_queuePolicy_o, o))
#define corto_mountPolicy(o) ((corto_mountPolicy*)corto_assert_type((corto_type)corto_mountPolicy_o, o))
#define corto_mountSubscription(o) ((corto_mountSubscription*)corto_assert_type((corto_type)corto_mountSubscription_o, o))
#define corto_mountSubscriptionList(o) ((corto_mountSubscriptionList*)corto_assert_type((corto_type)corto_mountSubscriptionList_o, o))
#define corto_time(o) ((corto_time*)corto_assert_type((corto_type)corto_time_o, o))
#define corto_mount(o) ((corto_mount)corto_assert_type((corto_type)corto_mount_o, o))
#define corto_invoke_event(o) ((corto_invoke_event*)corto_assert_type((corto_type)corto_invoke_event_o, o))
#define corto_loader(o) ((corto_loader)corto_assert_type((corto_type)corto_loader_o, o))
#define corto_objectIter(o) ((corto_objectIter*)corto_assert_type((corto_type)corto_objectIter_o, o))
#define corto_observer_event(o) ((corto_observer_event*)corto_assert_type((corto_type)corto_observer_event_o, o))
#define corto_operatorKind(o) ((corto_operatorKind*)corto_assert_type((corto_type)corto_operatorKind_o, o))
#define corto_remote(o) ((corto_remote)corto_assert_type((corto_type)corto_remote_o, o))
#define corto_resultMask(o) ((corto_resultMask*)corto_assert_type((corto_type)corto_resultMask_o, o))
#define corto_sample(o) ((corto_sample*)corto_assert_type((corto_type)corto_sample_o, o))
#define corto_sampleIter(o) ((corto_sampleIter*)corto_assert_type((corto_type)corto_sampleIter_o, o))
#define corto_result(o) ((corto_result*)corto_assert_type((corto_type)corto_result_o, o))
#define corto_resultIter(o) ((corto_resultIter*)corto_assert_type((corto_type)corto_resultIter_o, o))
#define corto_resultlist(o) ((corto_resultlist*)corto_assert_type((corto_type)corto_resultlist_o, o))
#define corto_route(o) ((corto_route)corto_assert_type((corto_type)corto_route_o, o))
#define corto_router(o) ((corto_router)corto_assert_type((corto_type)corto_router_o, o))
#define corto_routerimpl(o) ((corto_routerimpl)corto_assert_type((corto_type)corto_routerimpl_o, o))
#define corto_subscriber_event(o) ((corto_subscriber_event*)corto_assert_type((corto_type)corto_subscriber_event_o, o))
#define corto_subscriber_eventIter(o) ((corto_subscriber_eventIter*)corto_assert_type((corto_type)corto_subscriber_eventIter_o, o))

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
typedef corto_mountMask _type_corto_mountMask;
typedef corto_queuePolicy _type_corto_queuePolicy;
typedef corto_mountPolicy _type_corto_mountPolicy;
typedef corto_mountSubscription _type_corto_mountSubscription;
typedef corto_mountSubscriptionList _type_corto_mountSubscriptionList;
typedef corto_time _type_corto_time;
typedef corto_mount _type_corto_mount;
typedef corto_invoke_event _type_corto_invoke_event;
typedef corto_loader _type_corto_loader;
typedef corto_objectIter _type_corto_objectIter;
typedef corto_observer_event _type_corto_observer_event;
typedef corto_operatorKind _type_corto_operatorKind;
typedef corto_remote _type_corto_remote;
typedef corto_resultMask _type_corto_resultMask;
typedef corto_sample _type_corto_sample;
typedef corto_sampleIter _type_corto_sampleIter;
typedef corto_result _type_corto_result;
typedef corto_resultIter _type_corto_resultIter;
typedef corto_resultlist _type_corto_resultlist;
typedef corto_route _type_corto_route;
typedef corto_router _type_corto_router;
typedef corto_routerimpl _type_corto_routerimpl;
typedef corto_subscriber_event _type_corto_subscriber_event;
typedef corto_subscriber_eventIter _type_corto_subscriber_eventIter;

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
#define corto_mount_resume(_this, parent, id, o_out) _corto_mount_resume(corto_mount(_this), parent, id, o_out)
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
#define corto_observer_event_deinit(_this) _corto_observer_event_deinit(_this)
#define corto_observer_event_handle(e) _corto_observer_event_handle(e)
#define corto_observer_event_init(_this) _corto_observer_event_init(_this)
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
#define corto_observer_event_deinit _corto_observer_event_deinit
#define corto_observer_event_handle _corto_observer_event_handle
#define corto_observer_event_init _corto_observer_event_init
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
#define safe_corto_mount_resume(_this, parent, id, o_out) _corto_mount_resume(corto_mount(_this), parent, id, o_out)
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
#define safe_corto_observer_event_deinit(_this) _corto_observer_event_deinit(_this)
#define safe_corto_observer_event_handle(e) _corto_observer_event_handle(e)
#define safe_corto_observer_event_init(_this) _corto_observer_event_init(_this)
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
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1])->fptr)(corto_loader(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_loader_on_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_loader(_this), query) \
    )
#define corto_mount_on_batch_notify(_this, events) ( \
    ((corto_function)corto_mount_on_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriber_eventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_batch_notify_o)->index - 1], NULL, corto_mount(_this), events) \
    )
#define corto_mount_on_history_batch_notify(_this, events) ( \
    ((corto_function)corto_mount_on_history_batch_notify_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, corto_subscriber_eventIter))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1])->fptr)(corto_mount(_this), events) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_batch_notify_o)->index - 1], NULL, corto_mount(_this), events) \
    )
#define corto_mount_on_history_query(_this, query) ( \
    ((corto_function)corto_mount_on_history_query_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_history_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_mount(_this), query) \
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
    ? ((_type_corto_resultIter (*)(corto_object, corto_query *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1])->fptr)(corto_mount(_this), query) \
    : *(corto_resultIter*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_mount_on_query_o)->index - 1], alloca(sizeof(corto_resultIter)), corto_mount(_this), query) \
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
#define corto_routerimpl_findRoute(_this, instance, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_findRoute_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_route (*)(corto_object, corto_object, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_findRoute_o)->index - 1])->fptr)(corto_routerimpl(_this), instance, pattern, param, routerData) \
    : *(corto_route*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_findRoute_o)->index - 1], alloca(sizeof(corto_route)), corto_routerimpl(_this), instance, pattern, param, routerData) \
    )
#define corto_routerimpl_matchRoute(_this, route, pattern, param, routerData) ( \
    ((corto_function)corto_routerimpl_matchRoute_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_int32 (*)(corto_object, corto_route, corto_stringseq, corto_any, corto_any *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_matchRoute_o)->index - 1])->fptr)(corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    : *(int32_t*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_routerimpl_matchRoute_o)->index - 1], alloca(sizeof(int32_t)), corto_routerimpl(_this), corto_route(route), pattern, param, routerData) \
    )

/* -- Short identifier translation -- */

/* -- Short object variable translation -- */

#endif
