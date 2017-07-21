/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_CORE_INTERFACE_H
#define CORTO_CORE_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif


/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_dispatcher_post_v(
    corto_dispatcher _this,
    corto_event *e);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)
#else
#define corto_dispatcher_post_v _corto_dispatcher_post_v
#endif

/* explicit type-safe macro */
#define safe_corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), e)

#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), e)
CORTO_EXPORT
void _corto_dispatcher_post(
    corto_dispatcher _this,
    corto_event *e);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_event_handle(
    corto_event* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_event_handle(_this) _corto_event_handle(_this)
#else
#define corto_event_handle _corto_event_handle
#endif

/* explicit type-safe macro */
#define safe_corto_event_handle(_this) _corto_event_handle(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_event_uniqueKind(void);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_event_uniqueKind() _corto_event_uniqueKind()
#else
#define corto_event_uniqueKind _corto_event_uniqueKind
#endif

/* explicit type-safe macro */
#define safe_corto_event_uniqueKind() _corto_event_uniqueKind()

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_time _corto_frame_getTime(
    corto_frame* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_frame_getTime(_this) _corto_frame_getTime(_this)
#else
#define corto_frame_getTime _corto_frame_getTime
#endif

/* explicit type-safe macro */
#define safe_corto_frame_getTime(_this) _corto_frame_getTime(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_invokeEvent_handle_v(
    corto_invokeEvent _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(corto_invokeEvent(_this))
#else
#define corto_invokeEvent_handle_v _corto_invokeEvent_handle_v
#endif

/* explicit type-safe macro */
#define safe_corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(corto_invokeEvent(_this))

#define corto_invokeEvent_handle(_this) _corto_invokeEvent_handle(corto_invokeEvent(_this))
CORTO_EXPORT
void _corto_invokeEvent_handle(
    corto_invokeEvent _this);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_loader_construct(
    corto_loader _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))
#else
#define corto_loader_construct _corto_loader_construct
#endif

/* explicit type-safe macro */
#define safe_corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_loader_destruct(
    corto_loader _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))
#else
#define corto_loader_destruct _corto_loader_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_resultIter _corto_loader_onQuery_v(
    corto_loader _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_loader_onQuery_v(_this, query) _corto_loader_onQuery_v(corto_loader(_this), query)
#else
#define corto_loader_onQuery_v _corto_loader_onQuery_v
#endif

/* explicit type-safe macro */
#define safe_corto_loader_onQuery_v(_this, query) _corto_loader_onQuery_v(corto_loader(_this), query)

#define corto_loader_onQuery(_this, query) _corto_loader_onQuery(corto_loader(_this), query)
CORTO_EXPORT
corto_resultIter _corto_loader_onQuery(
    corto_loader _this,
    corto_query *query);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_mount_construct(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))
#else
#define corto_mount_construct _corto_mount_construct
#endif

/* explicit type-safe macro */
#define safe_corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_destruct(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))
#else
#define corto_mount_destruct _corto_mount_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_string _corto_mount_id(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_id(_this) _corto_mount_id(corto_mount(_this))
#else
#define corto_mount_id _corto_mount_id
#endif

/* explicit type-safe macro */
#define safe_corto_mount_id(_this) _corto_mount_id(corto_mount(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_mount_init(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))
#else
#define corto_mount_init _corto_mount_init
#endif

/* explicit type-safe macro */
#define safe_corto_mount_init(_this) _corto_mount_init(corto_mount(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_invoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
#else
#define corto_mount_invoke _corto_mount_invoke
#endif

/* explicit type-safe macro */
#define safe_corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onBatchNotify_v(
    corto_mount _this,
    corto_subscriberEventIter data);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onBatchNotify_v(_this, data) _corto_mount_onBatchNotify_v(corto_mount(_this), data)
#else
#define corto_mount_onBatchNotify_v _corto_mount_onBatchNotify_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onBatchNotify_v(_this, data) _corto_mount_onBatchNotify_v(corto_mount(_this), data)

#define corto_mount_onBatchNotify(_this, data) _corto_mount_onBatchNotify(corto_mount(_this), data)
CORTO_EXPORT
void _corto_mount_onBatchNotify(
    corto_mount _this,
    corto_subscriberEventIter data);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_resultIter _corto_mount_onHistoryQuery_v(
    corto_mount _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onHistoryQuery_v(_this, query) _corto_mount_onHistoryQuery_v(corto_mount(_this), query)
#else
#define corto_mount_onHistoryQuery_v _corto_mount_onHistoryQuery_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onHistoryQuery_v(_this, query) _corto_mount_onHistoryQuery_v(corto_mount(_this), query)

#define corto_mount_onHistoryQuery(_this, query) _corto_mount_onHistoryQuery(corto_mount(_this), query)
CORTO_EXPORT
corto_resultIter _corto_mount_onHistoryQuery(
    corto_mount _this,
    corto_query *query);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_string _corto_mount_onId_v(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onId_v(_this) _corto_mount_onId_v(corto_mount(_this))
#else
#define corto_mount_onId_v _corto_mount_onId_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onId_v(_this) _corto_mount_onId_v(corto_mount(_this))

#define corto_mount_onId(_this) _corto_mount_onId(corto_mount(_this))
CORTO_EXPORT
corto_string _corto_mount_onId(
    corto_mount _this);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onInvoke_v(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onInvoke_v(_this, instance, proc, argptrs) _corto_mount_onInvoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)
#else
#define corto_mount_onInvoke_v _corto_mount_onInvoke_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onInvoke_v(_this, instance, proc, argptrs) _corto_mount_onInvoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)

#define corto_mount_onInvoke(_this, instance, proc, argptrs) _corto_mount_onInvoke(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT
void _corto_mount_onInvoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
uintptr_t _corto_mount_onMount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onMount_v(_this, query, ctx) _corto_mount_onMount_v(corto_mount(_this), query, ctx)
#else
#define corto_mount_onMount_v _corto_mount_onMount_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onMount_v(_this, query, ctx) _corto_mount_onMount_v(corto_mount(_this), query, ctx)

#define corto_mount_onMount(_this, query, ctx) _corto_mount_onMount(corto_mount(_this), query, ctx)
CORTO_EXPORT
uintptr_t _corto_mount_onMount(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onNotify_v(
    corto_mount _this,
    corto_subscriberEvent *event);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onNotify_v(_this, event) _corto_mount_onNotify_v(corto_mount(_this), event)
#else
#define corto_mount_onNotify_v _corto_mount_onNotify_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onNotify_v(_this, event) _corto_mount_onNotify_v(corto_mount(_this), event)

#define corto_mount_onNotify(_this, event) _corto_mount_onNotify(corto_mount(_this), event)
CORTO_EXPORT
void _corto_mount_onNotify(
    corto_mount _this,
    corto_subscriberEvent *event);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onPoll_v(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onPoll_v(_this) _corto_mount_onPoll_v(corto_mount(_this))
#else
#define corto_mount_onPoll_v _corto_mount_onPoll_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onPoll_v(_this) _corto_mount_onPoll_v(corto_mount(_this))

#define corto_mount_onPoll(_this) _corto_mount_onPoll(corto_mount(_this))
CORTO_EXPORT
void _corto_mount_onPoll(
    corto_mount _this);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_resultIter _corto_mount_onQuery_v(
    corto_mount _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onQuery_v(_this, query) _corto_mount_onQuery_v(corto_mount(_this), query)
#else
#define corto_mount_onQuery_v _corto_mount_onQuery_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onQuery_v(_this, query) _corto_mount_onQuery_v(corto_mount(_this), query)

#define corto_mount_onQuery(_this, query) _corto_mount_onQuery(corto_mount(_this), query)
CORTO_EXPORT
corto_resultIter _corto_mount_onQuery(
    corto_mount _this,
    corto_query *query);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_object _corto_mount_onResume_v(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object object);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onResume_v(_this, parent, name, object) _corto_mount_onResume_v(corto_mount(_this), parent, name, object)
#else
#define corto_mount_onResume_v _corto_mount_onResume_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onResume_v(_this, parent, name, object) _corto_mount_onResume_v(corto_mount(_this), parent, name, object)

#define corto_mount_onResume(_this, parent, name, object) _corto_mount_onResume(corto_mount(_this), parent, name, object)
CORTO_EXPORT
corto_object _corto_mount_onResume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object object);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
uintptr_t _corto_mount_onSubscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onSubscribe_v(_this, query, ctx) _corto_mount_onSubscribe_v(corto_mount(_this), query, ctx)
#else
#define corto_mount_onSubscribe_v _corto_mount_onSubscribe_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onSubscribe_v(_this, query, ctx) _corto_mount_onSubscribe_v(corto_mount(_this), query, ctx)

#define corto_mount_onSubscribe(_this, query, ctx) _corto_mount_onSubscribe(corto_mount(_this), query, ctx)
CORTO_EXPORT
uintptr_t _corto_mount_onSubscribe(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
uintptr_t _corto_mount_onTransactionBegin_v(
    corto_mount _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onTransactionBegin_v(_this) _corto_mount_onTransactionBegin_v(corto_mount(_this))
#else
#define corto_mount_onTransactionBegin_v _corto_mount_onTransactionBegin_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onTransactionBegin_v(_this) _corto_mount_onTransactionBegin_v(corto_mount(_this))

#define corto_mount_onTransactionBegin(_this) _corto_mount_onTransactionBegin(corto_mount(_this))
CORTO_EXPORT
uintptr_t _corto_mount_onTransactionBegin(
    corto_mount _this);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onTransactionEnd_v(
    corto_mount _this,
    corto_subscriberEventIter events,
    uintptr_t ctx);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onTransactionEnd_v(_this, events, ctx) _corto_mount_onTransactionEnd_v(corto_mount(_this), events, ctx)
#else
#define corto_mount_onTransactionEnd_v _corto_mount_onTransactionEnd_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onTransactionEnd_v(_this, events, ctx) _corto_mount_onTransactionEnd_v(corto_mount(_this), events, ctx)

#define corto_mount_onTransactionEnd(_this, events, ctx) _corto_mount_onTransactionEnd(corto_mount(_this), events, ctx)
CORTO_EXPORT
void _corto_mount_onTransactionEnd(
    corto_mount _this,
    corto_subscriberEventIter events,
    uintptr_t ctx);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onUnmount_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onUnmount_v(_this, query, ctx) _corto_mount_onUnmount_v(corto_mount(_this), query, ctx)
#else
#define corto_mount_onUnmount_v _corto_mount_onUnmount_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onUnmount_v(_this, query, ctx) _corto_mount_onUnmount_v(corto_mount(_this), query, ctx)

#define corto_mount_onUnmount(_this, query, ctx) _corto_mount_onUnmount(corto_mount(_this), query, ctx)
CORTO_EXPORT
void _corto_mount_onUnmount(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_onUnsubscribe_v(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_onUnsubscribe_v(_this, query, ctx) _corto_mount_onUnsubscribe_v(corto_mount(_this), query, ctx)
#else
#define corto_mount_onUnsubscribe_v _corto_mount_onUnsubscribe_v
#endif

/* explicit type-safe macro */
#define safe_corto_mount_onUnsubscribe_v(_this, query, ctx) _corto_mount_onUnsubscribe_v(corto_mount(_this), query, ctx)

#define corto_mount_onUnsubscribe(_this, query, ctx) _corto_mount_onUnsubscribe(corto_mount(_this), query, ctx)
CORTO_EXPORT
void _corto_mount_onUnsubscribe(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_post(
    corto_mount _this,
    corto_event *e);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), e)
#else
#define corto_mount_post _corto_mount_post
#endif

/* explicit type-safe macro */
#define safe_corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), e)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_publish(
    corto_mount _this,
    corto_eventMask event,
    corto_string from,
    corto_string id,
    corto_string type,
    uintptr_t value);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_publish(_this, event, from, id, type, value) _corto_mount_publish(corto_mount(_this), event, from, id, type, value)
#else
#define corto_mount_publish _corto_mount_publish
#endif

/* explicit type-safe macro */
#define safe_corto_mount_publish(_this, event, from, id, type, value) _corto_mount_publish(corto_mount(_this), event, from, id, type, value)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_resultIter _corto_mount_query(
    corto_mount _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_query(_this, query) _corto_mount_query(corto_mount(_this), query)
#else
#define corto_mount_query _corto_mount_query
#endif

/* explicit type-safe macro */
#define safe_corto_mount_query(_this, query) _corto_mount_query(corto_mount(_this), query)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_object _corto_mount_resume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)
#else
#define corto_mount_resume _corto_mount_resume
#endif

/* explicit type-safe macro */
#define safe_corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_return(
    corto_mount _this,
    corto_result *r);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)
#else
#define corto_mount_return _corto_mount_return
#endif

/* explicit type-safe macro */
#define safe_corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_mount_setContentType(
    corto_mount _this,
    corto_string type);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)
#else
#define corto_mount_setContentType _corto_mount_setContentType
#endif

/* explicit type-safe macro */
#define safe_corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_mount_setContentTypeIn(
    corto_mount _this,
    corto_string type);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)
#else
#define corto_mount_setContentTypeIn _corto_mount_setContentTypeIn
#endif

/* explicit type-safe macro */
#define safe_corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_mount_setContentTypeOut(
    corto_mount _this,
    corto_string type);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)
#else
#define corto_mount_setContentTypeOut _corto_mount_setContentTypeOut
#endif

/* explicit type-safe macro */
#define safe_corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_subscribe(
    corto_mount _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)
#else
#define corto_mount_subscribe _corto_mount_subscribe
#endif

/* explicit type-safe macro */
#define safe_corto_mount_subscribe(_this, query) _corto_mount_subscribe(corto_mount(_this), query)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_mount_unsubscribe(
    corto_mount _this,
    corto_query *query);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)
#else
#define corto_mount_unsubscribe _corto_mount_unsubscribe
#endif

/* explicit type-safe macro */
#define safe_corto_mount_unsubscribe(_this, query) _corto_mount_unsubscribe(corto_mount(_this), query)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_observer_construct(
    corto_observer _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))
#else
#define corto_observer_construct _corto_observer_construct
#endif

/* explicit type-safe macro */
#define safe_corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_observer_destruct(
    corto_observer _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))
#else
#define corto_observer_destruct _corto_observer_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_observer_init(
    corto_observer _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))
#else
#define corto_observer_init _corto_observer_init
#endif

/* explicit type-safe macro */
#define safe_corto_observer_init(_this) _corto_observer_init(corto_observer(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_observer_observe(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)
#else
#define corto_observer_observe _corto_observer_observe
#endif

/* explicit type-safe macro */
#define safe_corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
bool _corto_observer_observing(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)
#else
#define corto_observer_observing _corto_observer_observing
#endif

/* explicit type-safe macro */
#define safe_corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_observer_unobserve(
    corto_observer _this,
    corto_object instance,
    corto_object observable);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)
#else
#define corto_observer_unobserve _corto_observer_unobserve
#endif

/* explicit type-safe macro */
#define safe_corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_observerEvent_deinit(
    corto_observerEvent* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observerEvent_deinit(_this) _corto_observerEvent_deinit(_this)
#else
#define corto_observerEvent_deinit _corto_observerEvent_deinit
#endif

/* explicit type-safe macro */
#define safe_corto_observerEvent_deinit(_this) _corto_observerEvent_deinit(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_observerEvent_handle(
    corto_event *e);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observerEvent_handle(e) _corto_observerEvent_handle(e)
#else
#define corto_observerEvent_handle _corto_observerEvent_handle
#endif

/* explicit type-safe macro */
#define safe_corto_observerEvent_handle(e) _corto_observerEvent_handle(e)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_observerEvent_init(
    corto_observerEvent* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_observerEvent_init(_this) _corto_observerEvent_init(_this)
#else
#define corto_observerEvent_init _corto_observerEvent_init
#endif

/* explicit type-safe macro */
#define safe_corto_observerEvent_init(_this) _corto_observerEvent_init(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_package_construct(
    corto_package _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_package_construct(_this) _corto_package_construct(corto_package(_this))
#else
#define corto_package_construct _corto_package_construct
#endif

/* explicit type-safe macro */
#define safe_corto_package_construct(_this) _corto_package_construct(corto_package(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_package_init(
    corto_package _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_package_init(_this) _corto_package_init(corto_package(_this))
#else
#define corto_package_init _corto_package_init
#endif

/* explicit type-safe macro */
#define safe_corto_package_init(_this) _corto_package_init(corto_package(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
uint32_t _corto_query_cardinality(
    corto_query* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_query_cardinality(_this) _corto_query_cardinality(_this)
#else
#define corto_query_cardinality _corto_query_cardinality
#endif

/* explicit type-safe macro */
#define safe_corto_query_cardinality(_this) _corto_query_cardinality(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_string _corto_result_contentof(
    corto_result* _this,
    corto_string contentType);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)
#else
#define corto_result_contentof _corto_result_contentof
#endif

/* explicit type-safe macro */
#define safe_corto_result_contentof(_this, contentType) _corto_result_contentof(_this, contentType)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_result_fromcontent(
    corto_result* _this,
    corto_string contentType,
    corto_string content);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)
#else
#define corto_result_fromcontent _corto_result_fromcontent
#endif

/* explicit type-safe macro */
#define safe_corto_result_fromcontent(_this, contentType, content) _corto_result_fromcontent(_this, contentType, content)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_string _corto_result_getText(
    corto_result* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_result_getText(_this) _corto_result_getText(_this)
#else
#define corto_result_getText _corto_result_getText
#endif

/* explicit type-safe macro */
#define safe_corto_result_getText(_this) _corto_result_getText(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_route_construct(
    corto_route _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_route_construct(_this) _corto_route_construct(corto_route(_this))
#else
#define corto_route_construct _corto_route_construct
#endif

/* explicit type-safe macro */
#define safe_corto_route_construct(_this) _corto_route_construct(corto_route(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_route_init(
    corto_route _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_route_init(_this) _corto_route_init(corto_route(_this))
#else
#define corto_route_init _corto_route_init
#endif

/* explicit type-safe macro */
#define safe_corto_route_init(_this) _corto_route_init(corto_route(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_router_construct(
    corto_router _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_router_construct(_this) _corto_router_construct(corto_router(_this))
#else
#define corto_router_construct _corto_router_construct
#endif

/* explicit type-safe macro */
#define safe_corto_router_construct(_this) _corto_router_construct(corto_router(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_router_init(
    corto_router _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_router_init(_this) _corto_router_init(corto_router(_this))
#else
#define corto_router_init _corto_router_init
#endif

/* explicit type-safe macro */
#define safe_corto_router_init(_this) _corto_router_init(corto_router(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any param,
    corto_any result,
    corto_route *matched);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)
#else
#define corto_router_match _corto_router_match
#endif

/* explicit type-safe macro */
#define safe_corto_router_match(instance, request, param, result, matched) _corto_router_match(instance, request, param, result, matched)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_routerimpl_construct(
    corto_routerimpl _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))
#else
#define corto_routerimpl_construct _corto_routerimpl_construct
#endif

/* explicit type-safe macro */
#define safe_corto_routerimpl_construct(_this) _corto_routerimpl_construct(corto_routerimpl(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_routerimpl_destruct(
    corto_routerimpl _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))
#else
#define corto_routerimpl_destruct _corto_routerimpl_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_routerimpl_destruct(_this) _corto_routerimpl_destruct(corto_routerimpl(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_route _corto_routerimpl_findRoute_v(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_routerimpl_findRoute_v(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), instance, pattern, param, routerData)
#else
#define corto_routerimpl_findRoute_v _corto_routerimpl_findRoute_v
#endif

/* explicit type-safe macro */
#define safe_corto_routerimpl_findRoute_v(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute_v(corto_routerimpl(_this), instance, pattern, param, routerData)

#define corto_routerimpl_findRoute(_this, instance, pattern, param, routerData) _corto_routerimpl_findRoute(corto_routerimpl(_this), instance, pattern, param, routerData)
CORTO_EXPORT
corto_route _corto_routerimpl_findRoute(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int32_t _corto_routerimpl_matchRoute_v(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
#else
#define corto_routerimpl_matchRoute_v _corto_routerimpl_matchRoute_v
#endif

/* explicit type-safe macro */
#define safe_corto_routerimpl_matchRoute_v(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute_v(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)

#define corto_routerimpl_matchRoute(_this, route, pattern, param, routerData) _corto_routerimpl_matchRoute(corto_routerimpl(_this), corto_route(route), pattern, param, routerData)
CORTO_EXPORT
int32_t _corto_routerimpl_matchRoute(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_stager_add(
    corto_stager _this,
    corto_string id,
    corto_string type,
    corto_string contentType,
    uintptr_t content,
    uint64_t childcount);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_stager_add(_this, id, type, contentType, content, childcount) _corto_stager_add(corto_stager(_this), id, type, contentType, content, childcount)
#else
#define corto_stager_add _corto_stager_add
#endif

/* explicit type-safe macro */
#define safe_corto_stager_add(_this, id, type, contentType, content, childcount) _corto_stager_add(corto_stager(_this), id, type, contentType, content, childcount)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_stager_construct(
    corto_stager _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_stager_construct(_this) _corto_stager_construct(corto_stager(_this))
#else
#define corto_stager_construct _corto_stager_construct
#endif

/* explicit type-safe macro */
#define safe_corto_stager_construct(_this) _corto_stager_construct(corto_stager(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_stager_destruct(
    corto_stager _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_stager_destruct(_this) _corto_stager_destruct(corto_stager(_this))
#else
#define corto_stager_destruct _corto_stager_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_stager_destruct(_this) _corto_stager_destruct(corto_stager(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_subscriber_construct(
    corto_subscriber _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))
#else
#define corto_subscriber_construct _corto_subscriber_construct
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_subscriber_deinit(
    corto_subscriber _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))
#else
#define corto_subscriber_deinit _corto_subscriber_deinit
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_deinit(_this) _corto_subscriber_deinit(corto_subscriber(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_subscriber_destruct(
    corto_subscriber _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))
#else
#define corto_subscriber_destruct _corto_subscriber_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_subscriber_init(
    corto_subscriber _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))
#else
#define corto_subscriber_init _corto_subscriber_init
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_init(_this) _corto_subscriber_init(corto_subscriber(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_subscriber_subscribe(
    corto_subscriber _this,
    corto_object instance);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)
#else
#define corto_subscriber_subscribe _corto_subscriber_subscribe
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_subscribe(_this, instance) _corto_subscriber_subscribe(corto_subscriber(_this), instance)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_subscriber_unsubscribe(
    corto_subscriber _this,
    corto_object instance);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)
#else
#define corto_subscriber_unsubscribe _corto_subscriber_unsubscribe
#endif

/* explicit type-safe macro */
#define safe_corto_subscriber_unsubscribe(_this, instance) _corto_subscriber_unsubscribe(corto_subscriber(_this), instance)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_subscriberEvent_deinit(
    corto_subscriberEvent* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriberEvent_deinit(_this) _corto_subscriberEvent_deinit(_this)
#else
#define corto_subscriberEvent_deinit _corto_subscriberEvent_deinit
#endif

/* explicit type-safe macro */
#define safe_corto_subscriberEvent_deinit(_this) _corto_subscriberEvent_deinit(_this)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_subscriberEvent_handle(
    corto_event *e);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriberEvent_handle(e) _corto_subscriberEvent_handle(e)
#else
#define corto_subscriberEvent_handle _corto_subscriberEvent_handle
#endif

/* explicit type-safe macro */
#define safe_corto_subscriberEvent_handle(e) _corto_subscriberEvent_handle(e)

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_subscriberEvent_init(
    corto_subscriberEvent* _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_subscriberEvent_init(_this) _corto_subscriberEvent_init(_this)
#else
#define corto_subscriberEvent_init _corto_subscriberEvent_init
#endif

/* explicit type-safe macro */
#define safe_corto_subscriberEvent_init(_this) _corto_subscriberEvent_init(_this)

#ifdef __cplusplus
}
#endif

#endif

