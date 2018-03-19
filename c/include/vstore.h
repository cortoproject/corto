/* vstore.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_VSTORE__API_H
#define CORTO_VSTORE__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif

/* /corto/vstore/dispatcher */
CORTO_EXPORT corto_dispatcher _corto_dispatcher__create(corto_object _parent, const char *_id);
#define corto_dispatcher__create(_parent, _id) _corto_dispatcher__create(_parent, _id)
#define corto_dispatcher__create_auto(_parent, _id) corto_dispatcher _id = corto_dispatcher__create(_parent, #_id); (void)_id
#define corto_dispatcher__declare(parent, id) (corto_dispatcher)corto_declare(parent, id, corto_dispatcher_o)
CORTO_EXPORT corto_int16 _corto_dispatcher__update(corto_dispatcher _this);
#define corto_dispatcher__update(_this) _corto_dispatcher__update(corto_dispatcher(_this))
CORTO_EXPORT corto_dispatcher _corto_dispatcher__assign(corto_dispatcher _this);
#define corto_dispatcher__optional_not_set NULL
#define corto_dispatcher__optional_set() (corto_dispatcher*)corto_dispatcher__assign((corto_dispatcher*)corto_ptr_new(corto_dispatcher_o))
#define corto_dispatcher__optional_set_cond(__cond) __cond ? (corto_dispatcher*)corto_dispatcher__assign((corto_dispatcher*)corto_ptr_new(corto_dispatcher_o)) : NULL
#define corto_dispatcher__unset(_this) _this ? corto_ptr_free(_this, corto_dispatcher_o), 0 : 0; _this = NULL;
#define corto_dispatcher__assign(_this) _corto_dispatcher__assign(_this)
#define corto_dispatcher__set(_this) _this = _this ? _this : (corto_dispatcher*)corto_ptr_new(corto_dispatcher_o); _corto_dispatcher__assign(_this)

/* /corto/vstore/event */
CORTO_EXPORT corto_event* _corto_event__create(corto_object _parent, const char *_id);
#define corto_event__create(_parent, _id) _corto_event__create(_parent, _id)
#define corto_event__create_auto(_parent, _id) corto_event* _id = corto_event__create(_parent, #_id); (void)_id
#define corto_event__declare(parent, id) (corto_event*)corto_declare(parent, id, corto_event_o)
CORTO_EXPORT corto_int16 _corto_event__update(corto_event* _this);
#define corto_event__update(_this) _corto_event__update(corto_event(_this))
CORTO_EXPORT corto_event* _corto_event__assign(corto_event* _this);
#define corto_event__optional_not_set NULL
#define corto_event__optional_set() (corto_event*)corto_event__assign((corto_event*)corto_ptr_new(corto_event_o))
#define corto_event__optional_set_cond(__cond) __cond ? (corto_event*)corto_event__assign((corto_event*)corto_ptr_new(corto_event_o)) : NULL
#define corto_event__unset(_this) _this ? corto_ptr_free(_this, corto_event_o), 0 : 0; _this = NULL;
#define corto_event__assign(_this) _corto_event__assign(_this)
#define corto_event__set(_this) _this = _this ? _this : (corto_event*)corto_ptr_new(corto_event_o); _corto_event__assign(_this)

/* /corto/vstore/eventMask */
CORTO_EXPORT corto_eventMask* _corto_eventMask__create(corto_object _parent, const char *_id, corto_eventMask value);
#define corto_eventMask__create(_parent, _id, value) _corto_eventMask__create(_parent, _id, value)
#define corto_eventMask__create_auto(_parent, _id, value) corto_eventMask* _id = corto_eventMask__create(_parent, #_id, value); (void)_id
#define corto_eventMask__declare(parent, id) (corto_eventMask*)corto_declare(parent, id, corto_eventMask_o)
CORTO_EXPORT corto_int16 _corto_eventMask__update(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMask__update(_this, value) _corto_eventMask__update(corto_eventMask(_this), value)
CORTO_EXPORT corto_eventMask* _corto_eventMask__assign(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMask__optional_not_set NULL
#define corto_eventMask__optional_set(value) (corto_eventMask*)corto_eventMask__assign((corto_eventMask*)corto_ptr_new(corto_eventMask_o), value)
#define corto_eventMask__optional_set_cond(__cond, value) __cond ? (corto_eventMask*)corto_eventMask__assign((corto_eventMask*)corto_ptr_new(corto_eventMask_o), value) : NULL
#define corto_eventMask__unset(_this) _this ? corto_ptr_free(_this, corto_eventMask_o), 0 : 0; _this = NULL;
#define corto_eventMask__assign(_this, value) _corto_eventMask__assign(_this, value)
#define corto_eventMask__set(_this, value) _this = _this ? _this : (corto_eventMask*)corto_ptr_new(corto_eventMask_o); _corto_eventMask__assign(_this, value)

/* /corto/vstore/fmt_data */
CORTO_EXPORT corto_fmt_data* _corto_fmt_data__create(corto_object _parent, const char *_id);
#define corto_fmt_data__create(_parent, _id) _corto_fmt_data__create(_parent, _id)
#define corto_fmt_data__create_auto(_parent, _id) corto_fmt_data* _id = corto_fmt_data__create(_parent, #_id); (void)_id
#define corto_fmt_data__declare(parent, id) (corto_fmt_data*)corto_declare(parent, id, corto_fmt_data_o)
CORTO_EXPORT corto_int16 _corto_fmt_data__update(corto_fmt_data* _this);
#define corto_fmt_data__update(_this) _corto_fmt_data__update(corto_fmt_data(_this))
CORTO_EXPORT corto_fmt_data* _corto_fmt_data__assign(corto_fmt_data* _this);
#define corto_fmt_data__optional_not_set NULL
#define corto_fmt_data__optional_set() (corto_fmt_data*)corto_fmt_data__assign((corto_fmt_data*)corto_ptr_new(corto_fmt_data_o))
#define corto_fmt_data__optional_set_cond(__cond) __cond ? (corto_fmt_data*)corto_fmt_data__assign((corto_fmt_data*)corto_ptr_new(corto_fmt_data_o)) : NULL
#define corto_fmt_data__unset(_this) _this ? corto_ptr_free(_this, corto_fmt_data_o), 0 : 0; _this = NULL;
#define corto_fmt_data__assign(_this) _corto_fmt_data__assign(_this)
#define corto_fmt_data__set(_this) _this = _this ? _this : (corto_fmt_data*)corto_ptr_new(corto_fmt_data_o); _corto_fmt_data__assign(_this)

/* /corto/vstore/frame */
CORTO_EXPORT corto_frame* _corto_frame__create(corto_object _parent, const char *_id, corto_frameKind kind, int64_t value);
#define corto_frame__create(_parent, _id, kind, value) _corto_frame__create(_parent, _id, kind, value)
#define corto_frame__create_auto(_parent, _id, kind, value) corto_frame* _id = corto_frame__create(_parent, #_id, kind, value); (void)_id
#define corto_frame__declare(parent, id) (corto_frame*)corto_declare(parent, id, corto_frame_o)
CORTO_EXPORT corto_int16 _corto_frame__update(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frame__update(_this, kind, value) _corto_frame__update(corto_frame(_this), kind, value)
CORTO_EXPORT corto_frame* _corto_frame__assign(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frame__optional_not_set NULL
#define corto_frame__optional_set(kind, value) (corto_frame*)corto_frame__assign((corto_frame*)corto_ptr_new(corto_frame_o), kind, value)
#define corto_frame__optional_set_cond(__cond, kind, value) __cond ? (corto_frame*)corto_frame__assign((corto_frame*)corto_ptr_new(corto_frame_o), kind, value) : NULL
#define corto_frame__unset(_this) _this ? corto_ptr_free(_this, corto_frame_o), 0 : 0; _this = NULL;
#define corto_frame__assign(_this, kind, value) _corto_frame__assign(_this, kind, value)
#define corto_frame__set(_this, kind, value) _this = _this ? _this : (corto_frame*)corto_ptr_new(corto_frame_o); _corto_frame__assign(_this, kind, value)

/* /corto/vstore/frameKind */
CORTO_EXPORT corto_frameKind* _corto_frameKind__create(corto_object _parent, const char *_id, corto_frameKind value);
#define corto_frameKind__create(_parent, _id, value) _corto_frameKind__create(_parent, _id, value)
#define corto_frameKind__create_auto(_parent, _id, value) corto_frameKind* _id = corto_frameKind__create(_parent, #_id, value); (void)_id
#define corto_frameKind__declare(parent, id) (corto_frameKind*)corto_declare(parent, id, corto_frameKind_o)
CORTO_EXPORT corto_int16 _corto_frameKind__update(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKind__update(_this, value) _corto_frameKind__update(corto_frameKind(_this), value)
CORTO_EXPORT corto_frameKind* _corto_frameKind__assign(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKind__optional_not_set NULL
#define corto_frameKind__optional_set(value) (corto_frameKind*)corto_frameKind__assign((corto_frameKind*)corto_ptr_new(corto_frameKind_o), value)
#define corto_frameKind__optional_set_cond(__cond, value) __cond ? (corto_frameKind*)corto_frameKind__assign((corto_frameKind*)corto_ptr_new(corto_frameKind_o), value) : NULL
#define corto_frameKind__unset(_this) _this ? corto_ptr_free(_this, corto_frameKind_o), 0 : 0; _this = NULL;
#define corto_frameKind__assign(_this, value) _corto_frameKind__assign(_this, value)
#define corto_frameKind__set(_this, value) _this = _this ? _this : (corto_frameKind*)corto_ptr_new(corto_frameKind_o); _corto_frameKind__assign(_this, value)

/* /corto/vstore/handleAction */
CORTO_EXPORT corto_handleAction* _corto_handleAction__create(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_handleAction__create(_parent, _id, instance, procedure) _corto_handleAction__create(_parent, _id, instance, corto_function(procedure))
#define corto_handleAction__create_auto(_parent, _id, instance, procedure) corto_handleAction* _id = corto_handleAction__create(_parent, #_id, instance, procedure); (void)_id
#define corto_handleAction__declare(parent, id) (corto_handleAction*)corto_declare(parent, id, corto_handleAction_o)
CORTO_EXPORT corto_int16 _corto_handleAction__update(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleAction__update(_this, instance, procedure) _corto_handleAction__update(corto_handleAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_handleAction* _corto_handleAction__assign(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleAction__optional_not_set NULL
#define corto_handleAction__optional_set(instance, procedure) (corto_handleAction*)corto_handleAction__assign((corto_handleAction*)corto_ptr_new(corto_handleAction_o), instance, procedure)
#define corto_handleAction__optional_set_cond(__cond, instance, procedure) __cond ? (corto_handleAction*)corto_handleAction__assign((corto_handleAction*)corto_ptr_new(corto_handleAction_o), instance, procedure) : NULL
#define corto_handleAction__unset(_this) _this ? corto_ptr_free(_this, corto_handleAction_o), 0 : 0; _this = NULL;
#define corto_handleAction__assign(_this, instance, procedure) _corto_handleAction__assign(_this, instance, corto_function(procedure))
#define corto_handleAction__set(_this, instance, procedure) _this = _this ? _this : (corto_handleAction*)corto_ptr_new(corto_handleAction_o); _corto_handleAction__assign(_this, instance, corto_function(procedure))
corto_int16 corto_handleAction__call(corto_handleAction *_delegate, corto_event * event);
#define corto_handleAction__init_c_auto(d, callback) corto_handleAction d; corto_handleAction__init_c(&d, callback)
CORTO_EXPORT corto_int16 corto_handleAction__init_c(corto_handleAction *d, corto_void ___ (*callback)(corto_event*));
#define corto_handleAction_init_c_instance_auto(d, instance, callback)corto_handleAction d; corto_handleAction_init_c_instance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_handleAction_init_c_instance(corto_handleAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_event*));

/* /corto/vstore/invoke_event */
CORTO_EXPORT corto_invoke_event* _corto_invoke_event__create(corto_object _parent, const char *_id, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invoke_event__create(_parent, _id, mount, instance, function, args) _corto_invoke_event__create(_parent, _id, corto_mount(mount), instance, corto_function(function), args)
#define corto_invoke_event__create_auto(_parent, _id, mount, instance, function, args) corto_invoke_event* _id = corto_invoke_event__create(_parent, #_id, mount, instance, function, args); (void)_id
#define corto_invoke_event__declare(parent, id) (corto_invoke_event*)corto_declare(parent, id, corto_invoke_event_o)
CORTO_EXPORT corto_int16 _corto_invoke_event__update(corto_invoke_event* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invoke_event__update(_this, mount, instance, function, args) _corto_invoke_event__update(corto_invoke_event(_this), corto_mount(mount), instance, corto_function(function), args)
CORTO_EXPORT corto_invoke_event* _corto_invoke_event__assign(corto_invoke_event* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invoke_event__optional_not_set NULL
#define corto_invoke_event__optional_set(mount, instance, function, args) (corto_invoke_event*)corto_invoke_event__assign((corto_invoke_event*)corto_ptr_new(corto_invoke_event_o), mount, instance, function, args)
#define corto_invoke_event__optional_set_cond(__cond, mount, instance, function, args) __cond ? (corto_invoke_event*)corto_invoke_event__assign((corto_invoke_event*)corto_ptr_new(corto_invoke_event_o), mount, instance, function, args) : NULL
#define corto_invoke_event__unset(_this) _this ? corto_ptr_free(_this, corto_invoke_event_o), 0 : 0; _this = NULL;
#define corto_invoke_event__assign(_this, mount, instance, function, args) _corto_invoke_event__assign(_this, corto_mount(mount), instance, corto_function(function), args)
#define corto_invoke_event__set(_this, mount, instance, function, args) _this = _this ? _this : (corto_invoke_event*)corto_ptr_new(corto_invoke_event_o); _corto_invoke_event__assign(_this, corto_mount(mount), instance, corto_function(function), args)

/* /corto/vstore/loader */
CORTO_EXPORT corto_loader _corto_loader__create(corto_object _parent, const char *_id, bool autoLoad);
#define corto_loader__create(_parent, _id, autoLoad) _corto_loader__create(_parent, _id, autoLoad)
#define corto_loader__create_auto(_parent, _id, autoLoad) corto_loader _id = corto_loader__create(_parent, #_id, autoLoad); (void)_id
#define corto_loader__declare(parent, id) (corto_loader)corto_declare(parent, id, corto_loader_o)
CORTO_EXPORT corto_int16 _corto_loader__update(corto_loader _this, bool autoLoad);
#define corto_loader__update(_this, autoLoad) _corto_loader__update(corto_loader(_this), autoLoad)
CORTO_EXPORT corto_loader _corto_loader__assign(corto_loader _this, bool autoLoad);
#define corto_loader__optional_not_set NULL
#define corto_loader__optional_set(autoLoad) (corto_loader*)corto_loader__assign((corto_loader*)corto_ptr_new(corto_loader_o), autoLoad)
#define corto_loader__optional_set_cond(__cond, autoLoad) __cond ? (corto_loader*)corto_loader__assign((corto_loader*)corto_ptr_new(corto_loader_o), autoLoad) : NULL
#define corto_loader__unset(_this) _this ? corto_ptr_free(_this, corto_loader_o), 0 : 0; _this = NULL;
#define corto_loader__assign(_this, autoLoad) _corto_loader__assign(_this, autoLoad)
#define corto_loader__set(_this, autoLoad) _this = _this ? _this : (corto_loader*)corto_ptr_new(corto_loader_o); _corto_loader__assign(_this, autoLoad)

/* /corto/vstore/mount */
CORTO_EXPORT corto_mount _corto_mount__create(corto_object _parent, const char *_id, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mount__create(_parent, _id, query, contentType, policy) _corto_mount__create(_parent, _id, query, contentType, policy)
#define corto_mount__create_auto(_parent, _id, query, contentType, policy) corto_mount _id = corto_mount__create(_parent, #_id, query, contentType, policy); (void)_id
#define corto_mount__declare(parent, id) (corto_mount)corto_declare(parent, id, corto_mount_o)
CORTO_EXPORT corto_int16 _corto_mount__update(corto_mount _this, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mount__update(_this, query, contentType, policy) _corto_mount__update(corto_mount(_this), query, contentType, policy)
CORTO_EXPORT corto_mount _corto_mount__assign(corto_mount _this, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mount__optional_not_set NULL
#define corto_mount__optional_set(query, contentType, policy) (corto_mount*)corto_mount__assign((corto_mount*)corto_ptr_new(corto_mount_o), query, contentType, policy)
#define corto_mount__optional_set_cond(__cond, query, contentType, policy) __cond ? (corto_mount*)corto_mount__assign((corto_mount*)corto_ptr_new(corto_mount_o), query, contentType, policy) : NULL
#define corto_mount__unset(_this) _this ? corto_ptr_free(_this, corto_mount_o), 0 : 0; _this = NULL;
#define corto_mount__assign(_this, query, contentType, policy) _corto_mount__assign(_this, query, contentType, policy)
#define corto_mount__set(_this, query, contentType, policy) _this = _this ? _this : (corto_mount*)corto_ptr_new(corto_mount_o); _corto_mount__assign(_this, query, contentType, policy)

/* /corto/vstore/mountMask */
CORTO_EXPORT corto_mountMask* _corto_mountMask__create(corto_object _parent, const char *_id, corto_mountMask value);
#define corto_mountMask__create(_parent, _id, value) _corto_mountMask__create(_parent, _id, value)
#define corto_mountMask__create_auto(_parent, _id, value) corto_mountMask* _id = corto_mountMask__create(_parent, #_id, value); (void)_id
#define corto_mountMask__declare(parent, id) (corto_mountMask*)corto_declare(parent, id, corto_mountMask_o)
CORTO_EXPORT corto_int16 _corto_mountMask__update(corto_mountMask* _this, corto_mountMask value);
#define corto_mountMask__update(_this, value) _corto_mountMask__update(corto_mountMask(_this), value)
CORTO_EXPORT corto_mountMask* _corto_mountMask__assign(corto_mountMask* _this, corto_mountMask value);
#define corto_mountMask__optional_not_set NULL
#define corto_mountMask__optional_set(value) (corto_mountMask*)corto_mountMask__assign((corto_mountMask*)corto_ptr_new(corto_mountMask_o), value)
#define corto_mountMask__optional_set_cond(__cond, value) __cond ? (corto_mountMask*)corto_mountMask__assign((corto_mountMask*)corto_ptr_new(corto_mountMask_o), value) : NULL
#define corto_mountMask__unset(_this) _this ? corto_ptr_free(_this, corto_mountMask_o), 0 : 0; _this = NULL;
#define corto_mountMask__assign(_this, value) _corto_mountMask__assign(_this, value)
#define corto_mountMask__set(_this, value) _this = _this ? _this : (corto_mountMask*)corto_ptr_new(corto_mountMask_o); _corto_mountMask__assign(_this, value)

/* /corto/vstore/mountPolicy */
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicy__create(corto_object _parent, const char *_id, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicy__create(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicy__create(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicy__create_auto(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults) corto_mountPolicy* _id = corto_mountPolicy__create(_parent, #_id, ownership, mask, sampleRate, queue, expiryTime, filterResults); (void)_id
#define corto_mountPolicy__declare(parent, id) (corto_mountPolicy*)corto_declare(parent, id, corto_mountPolicy_o)
CORTO_EXPORT corto_int16 _corto_mountPolicy__update(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicy__update(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicy__update(corto_mountPolicy(_this), ownership, mask, sampleRate, queue, expiryTime, filterResults)
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicy__assign(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicy__optional_not_set NULL
#define corto_mountPolicy__optional_set(ownership, mask, sampleRate, queue, expiryTime, filterResults) (corto_mountPolicy*)corto_mountPolicy__assign((corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o), ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicy__optional_set_cond(__cond, ownership, mask, sampleRate, queue, expiryTime, filterResults) __cond ? (corto_mountPolicy*)corto_mountPolicy__assign((corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o), ownership, mask, sampleRate, queue, expiryTime, filterResults) : NULL
#define corto_mountPolicy__unset(_this) _this ? corto_ptr_free(_this, corto_mountPolicy_o), 0 : 0; _this = NULL;
#define corto_mountPolicy__assign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicy__assign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicy__set(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _this = _this ? _this : (corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o); _corto_mountPolicy__assign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults)

/* /corto/vstore/mountSubscription */
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscription__create(corto_object _parent, const char *_id, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscription__create(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscription__create(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscription__create_auto(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx) corto_mountSubscription* _id = corto_mountSubscription__create(_parent, #_id, query, mountCount, subscriberCount, mountCtx, subscriberCtx); (void)_id
#define corto_mountSubscription__declare(parent, id) (corto_mountSubscription*)corto_declare(parent, id, corto_mountSubscription_o)
CORTO_EXPORT corto_int16 _corto_mountSubscription__update(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscription__update(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscription__update(corto_mountSubscription(_this), query, mountCount, subscriberCount, mountCtx, subscriberCtx)
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscription__assign(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscription__optional_not_set NULL
#define corto_mountSubscription__optional_set(query, mountCount, subscriberCount, mountCtx, subscriberCtx) (corto_mountSubscription*)corto_mountSubscription__assign((corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o), query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscription__optional_set_cond(__cond, query, mountCount, subscriberCount, mountCtx, subscriberCtx) __cond ? (corto_mountSubscription*)corto_mountSubscription__assign((corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o), query, mountCount, subscriberCount, mountCtx, subscriberCtx) : NULL
#define corto_mountSubscription__unset(_this) _this ? corto_ptr_free(_this, corto_mountSubscription_o), 0 : 0; _this = NULL;
#define corto_mountSubscription__assign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscription__assign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscription__set(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _this = _this ? _this : (corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o); _corto_mountSubscription__assign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx)

/* /corto/vstore/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionList__create(corto_object _parent, const char *_id, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionList__create(_parent, _id, length, elements) _corto_mountSubscriptionList__create(_parent, _id, length, elements)
#define corto_mountSubscriptionList__create_auto(_parent, _id, length, elements) corto_mountSubscriptionList* _id = corto_mountSubscriptionList__create(_parent, #_id, length, elements); (void)_id
#define corto_mountSubscriptionList__declare(parent, id) (corto_mountSubscriptionList*)corto_declare(parent, id, corto_mountSubscriptionList_o)
CORTO_EXPORT corto_int16 _corto_mountSubscriptionList__update(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionList__update(_this, length, elements) _corto_mountSubscriptionList__update(corto_mountSubscriptionList(_this), length, elements)
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionList__assign(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionList__optional_not_set NULL
#define corto_mountSubscriptionList__optional_set(length, elements) (corto_mountSubscriptionList*)corto_mountSubscriptionList__assign((corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o), length, elements)
#define corto_mountSubscriptionList__optional_set_cond(__cond, length, elements) __cond ? (corto_mountSubscriptionList*)corto_mountSubscriptionList__assign((corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o), length, elements) : NULL
#define corto_mountSubscriptionList__unset(_this) _this ? corto_ptr_free(_this, corto_mountSubscriptionList_o), 0 : 0; _this = NULL;
#define corto_mountSubscriptionList__assign(_this, length, elements) _corto_mountSubscriptionList__assign(_this, length, elements)
#define corto_mountSubscriptionList__set(_this, length, elements) _this = _this ? _this : (corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o); _corto_mountSubscriptionList__assign(_this, length, elements)

/* /corto/vstore/objectIter */
CORTO_EXPORT corto_objectIter* _corto_objectIter__create(corto_object _parent, const char *_id);
#define corto_objectIter__create(_parent, _id) _corto_objectIter__create(_parent, _id)
#define corto_objectIter__create_auto(_parent, _id) corto_objectIter* _id = corto_objectIter__create(_parent, #_id); (void)_id
#define corto_objectIter__declare(parent, id) (corto_objectIter*)corto_declare(parent, id, corto_objectIter_o)
CORTO_EXPORT corto_int16 _corto_objectIter__update(corto_objectIter* _this);
#define corto_objectIter__update(_this) _corto_objectIter__update(corto_objectIter(_this))
CORTO_EXPORT corto_objectIter* _corto_objectIter__assign(corto_objectIter* _this);
#define corto_objectIter__optional_not_set NULL
#define corto_objectIter__optional_set() (corto_objectIter*)corto_objectIter__assign((corto_objectIter*)corto_ptr_new(corto_objectIter_o))
#define corto_objectIter__optional_set_cond(__cond) __cond ? (corto_objectIter*)corto_objectIter__assign((corto_objectIter*)corto_ptr_new(corto_objectIter_o)) : NULL
#define corto_objectIter__unset(_this) _this ? corto_ptr_free(_this, corto_objectIter_o), 0 : 0; _this = NULL;
#define corto_objectIter__assign(_this) _corto_objectIter__assign(_this)
#define corto_objectIter__set(_this) _this = _this ? _this : (corto_objectIter*)corto_ptr_new(corto_objectIter_o); _corto_objectIter__assign(_this)

/* /corto/vstore/observer */
CORTO_EXPORT corto_observer _corto_observer__create(corto_object _parent, const char *_id, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observer__create(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observer__create(_parent, _id, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
#define corto_observer__create_auto(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) corto_observer _id = corto_observer__create(_parent, #_id, mask, observable, instance, dispatcher, type, enabled, _impl); (void)_id
#define corto_observer__declare(parent, id) (corto_observer)corto_declare(parent, id, corto_observer_o)
CORTO_EXPORT corto_int16 _corto_observer__update(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observer__update(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observer__update(corto_observer(_this), mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_observer _corto_observer__assign(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observer__optional_not_set NULL
#define corto_observer__optional_set(mask, observable, instance, dispatcher, type, enabled, _impl) (corto_observer*)corto_observer__assign((corto_observer*)corto_ptr_new(corto_observer_o), mask, observable, instance, dispatcher, type, enabled, _impl)
#define corto_observer__optional_set_cond(__cond, mask, observable, instance, dispatcher, type, enabled, _impl) __cond ? (corto_observer*)corto_observer__assign((corto_observer*)corto_ptr_new(corto_observer_o), mask, observable, instance, dispatcher, type, enabled, _impl) : NULL
#define corto_observer__unset(_this) _this ? corto_ptr_free(_this, corto_observer_o), 0 : 0; _this = NULL;
#define corto_observer__assign(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observer__assign(_this, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
#define corto_observer__set(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _this = _this ? _this : (corto_observer*)corto_ptr_new(corto_observer_o); _corto_observer__assign(_this, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)

/* /corto/vstore/observer_event */
CORTO_EXPORT corto_observer_event* _corto_observer_event__create(corto_object _parent, const char *_id, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observer_event__create(_parent, _id, observer, instance, source, event, data, thread) _corto_observer_event__create(_parent, _id, corto_observer(observer), instance, source, event, data, thread)
#define corto_observer_event__create_auto(_parent, _id, observer, instance, source, event, data, thread) corto_observer_event* _id = corto_observer_event__create(_parent, #_id, observer, instance, source, event, data, thread); (void)_id
#define corto_observer_event__declare(parent, id) (corto_observer_event*)corto_declare(parent, id, corto_observer_event_o)
CORTO_EXPORT corto_int16 _corto_observer_event__update(corto_observer_event* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observer_event__update(_this, observer, instance, source, event, data, thread) _corto_observer_event__update(corto_observer_event(_this), corto_observer(observer), instance, source, event, data, thread)
CORTO_EXPORT corto_observer_event* _corto_observer_event__assign(corto_observer_event* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observer_event__optional_not_set NULL
#define corto_observer_event__optional_set(observer, instance, source, event, data, thread) (corto_observer_event*)corto_observer_event__assign((corto_observer_event*)corto_ptr_new(corto_observer_event_o), observer, instance, source, event, data, thread)
#define corto_observer_event__optional_set_cond(__cond, observer, instance, source, event, data, thread) __cond ? (corto_observer_event*)corto_observer_event__assign((corto_observer_event*)corto_ptr_new(corto_observer_event_o), observer, instance, source, event, data, thread) : NULL
#define corto_observer_event__unset(_this) _this ? corto_ptr_free(_this, corto_observer_event_o), 0 : 0; _this = NULL;
#define corto_observer_event__assign(_this, observer, instance, source, event, data, thread) _corto_observer_event__assign(_this, corto_observer(observer), instance, source, event, data, thread)
#define corto_observer_event__set(_this, observer, instance, source, event, data, thread) _this = _this ? _this : (corto_observer_event*)corto_ptr_new(corto_observer_event_o); _corto_observer_event__assign(_this, corto_observer(observer), instance, source, event, data, thread)

/* /corto/vstore/operatorKind */
CORTO_EXPORT corto_operatorKind* _corto_operatorKind__create(corto_object _parent, const char *_id, corto_operatorKind value);
#define corto_operatorKind__create(_parent, _id, value) _corto_operatorKind__create(_parent, _id, value)
#define corto_operatorKind__create_auto(_parent, _id, value) corto_operatorKind* _id = corto_operatorKind__create(_parent, #_id, value); (void)_id
#define corto_operatorKind__declare(parent, id) (corto_operatorKind*)corto_declare(parent, id, corto_operatorKind_o)
CORTO_EXPORT corto_int16 _corto_operatorKind__update(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKind__update(_this, value) _corto_operatorKind__update(corto_operatorKind(_this), value)
CORTO_EXPORT corto_operatorKind* _corto_operatorKind__assign(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKind__optional_not_set NULL
#define corto_operatorKind__optional_set(value) (corto_operatorKind*)corto_operatorKind__assign((corto_operatorKind*)corto_ptr_new(corto_operatorKind_o), value)
#define corto_operatorKind__optional_set_cond(__cond, value) __cond ? (corto_operatorKind*)corto_operatorKind__assign((corto_operatorKind*)corto_ptr_new(corto_operatorKind_o), value) : NULL
#define corto_operatorKind__unset(_this) _this ? corto_ptr_free(_this, corto_operatorKind_o), 0 : 0; _this = NULL;
#define corto_operatorKind__assign(_this, value) _corto_operatorKind__assign(_this, value)
#define corto_operatorKind__set(_this, value) _this = _this ? _this : (corto_operatorKind*)corto_ptr_new(corto_operatorKind_o); _corto_operatorKind__assign(_this, value)

/* /corto/vstore/ownership */
CORTO_EXPORT corto_ownership* _corto_ownership__create(corto_object _parent, const char *_id, corto_ownership value);
#define corto_ownership__create(_parent, _id, value) _corto_ownership__create(_parent, _id, value)
#define corto_ownership__create_auto(_parent, _id, value) corto_ownership* _id = corto_ownership__create(_parent, #_id, value); (void)_id
#define corto_ownership__declare(parent, id) (corto_ownership*)corto_declare(parent, id, corto_ownership_o)
CORTO_EXPORT corto_int16 _corto_ownership__update(corto_ownership* _this, corto_ownership value);
#define corto_ownership__update(_this, value) _corto_ownership__update(corto_ownership(_this), value)
CORTO_EXPORT corto_ownership* _corto_ownership__assign(corto_ownership* _this, corto_ownership value);
#define corto_ownership__optional_not_set NULL
#define corto_ownership__optional_set(value) (corto_ownership*)corto_ownership__assign((corto_ownership*)corto_ptr_new(corto_ownership_o), value)
#define corto_ownership__optional_set_cond(__cond, value) __cond ? (corto_ownership*)corto_ownership__assign((corto_ownership*)corto_ptr_new(corto_ownership_o), value) : NULL
#define corto_ownership__unset(_this) _this ? corto_ptr_free(_this, corto_ownership_o), 0 : 0; _this = NULL;
#define corto_ownership__assign(_this, value) _corto_ownership__assign(_this, value)
#define corto_ownership__set(_this, value) _this = _this ? _this : (corto_ownership*)corto_ptr_new(corto_ownership_o); _corto_ownership__assign(_this, value)

/* /corto/vstore/query */
CORTO_EXPORT corto_query* _corto_query__create(corto_object _parent, const char *_id, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_query__create(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_query__create(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_query__create_auto(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) corto_query* _id = corto_query__create(_parent, #_id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd); (void)_id
#define corto_query__declare(parent, id) (corto_query*)corto_declare(parent, id, corto_query_o)
CORTO_EXPORT corto_int16 _corto_query__update(corto_query* _this, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_query__update(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_query__update(corto_query(_this), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
CORTO_EXPORT corto_query* _corto_query__assign(corto_query* _this, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_query__optional_not_set NULL
#define corto_query__optional_set(select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) (corto_query*)corto_query__assign((corto_query*)corto_ptr_new(corto_query_o), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_query__optional_set_cond(__cond, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) __cond ? (corto_query*)corto_query__assign((corto_query*)corto_ptr_new(corto_query_o), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) : NULL
#define corto_query__unset(_this) _this ? corto_ptr_free(_this, corto_query_o), 0 : 0; _this = NULL;
#define corto_query__assign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_query__assign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_query__set(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _this = _this ? _this : (corto_query*)corto_ptr_new(corto_query_o); _corto_query__assign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)

/* /corto/vstore/queuePolicy */
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicy__create(corto_object _parent, const char *_id, uint32_t max);
#define corto_queuePolicy__create(_parent, _id, max) _corto_queuePolicy__create(_parent, _id, max)
#define corto_queuePolicy__create_auto(_parent, _id, max) corto_queuePolicy* _id = corto_queuePolicy__create(_parent, #_id, max); (void)_id
#define corto_queuePolicy__declare(parent, id) (corto_queuePolicy*)corto_declare(parent, id, corto_queuePolicy_o)
CORTO_EXPORT corto_int16 _corto_queuePolicy__update(corto_queuePolicy* _this, uint32_t max);
#define corto_queuePolicy__update(_this, max) _corto_queuePolicy__update(corto_queuePolicy(_this), max)
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicy__assign(corto_queuePolicy* _this, uint32_t max);
#define corto_queuePolicy__optional_not_set NULL
#define corto_queuePolicy__optional_set(max) (corto_queuePolicy*)corto_queuePolicy__assign((corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o), max)
#define corto_queuePolicy__optional_set_cond(__cond, max) __cond ? (corto_queuePolicy*)corto_queuePolicy__assign((corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o), max) : NULL
#define corto_queuePolicy__unset(_this) _this ? corto_ptr_free(_this, corto_queuePolicy_o), 0 : 0; _this = NULL;
#define corto_queuePolicy__assign(_this, max) _corto_queuePolicy__assign(_this, max)
#define corto_queuePolicy__set(_this, max) _this = _this ? _this : (corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o); _corto_queuePolicy__assign(_this, max)

/* /corto/vstore/remote */
CORTO_EXPORT corto_remote _corto_remote__create(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remote__create(_parent, _id, returnType, returnsReference, _impl) _corto_remote__create(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remote__create_auto(_parent, _id, returnType, returnsReference, _impl) corto_remote _id = corto_remote__create(_parent, #_id, returnType, returnsReference, _impl); (void)_id
#define corto_remote__declare(parent, id) (corto_remote)corto_declare(parent, id, corto_remote_o)
CORTO_EXPORT corto_int16 _corto_remote__update(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remote__update(_this, returnType, returnsReference, _impl) _corto_remote__update(corto_remote(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_remote _corto_remote__assign(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remote__optional_not_set NULL
#define corto_remote__optional_set(returnType, returnsReference, _impl) (corto_remote*)corto_remote__assign((corto_remote*)corto_ptr_new(corto_remote_o), returnType, returnsReference, _impl)
#define corto_remote__optional_set_cond(__cond, returnType, returnsReference, _impl) __cond ? (corto_remote*)corto_remote__assign((corto_remote*)corto_ptr_new(corto_remote_o), returnType, returnsReference, _impl) : NULL
#define corto_remote__unset(_this) _this ? corto_ptr_free(_this, corto_remote_o), 0 : 0; _this = NULL;
#define corto_remote__assign(_this, returnType, returnsReference, _impl) _corto_remote__assign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remote__set(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_remote*)corto_ptr_new(corto_remote_o); _corto_remote__assign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* /corto/vstore/result */
CORTO_EXPORT corto_result* _corto_result__create(corto_object _parent, const char *_id, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_result__create(_parent, _id, id, name, parent, type, value, flags) _corto_result__create(_parent, _id, id, name, parent, type, value, flags)
#define corto_result__create_auto(_parent, _id, id, name, parent, type, value, flags) corto_result* _id = corto_result__create(_parent, #_id, id, name, parent, type, value, flags); (void)_id
#define corto_result__declare(parent, id) (corto_result*)corto_declare(parent, id, corto_result_o)
CORTO_EXPORT corto_int16 _corto_result__update(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_result__update(_this, id, name, parent, type, value, flags) _corto_result__update(corto_result(_this), id, name, parent, type, value, flags)
CORTO_EXPORT corto_result* _corto_result__assign(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_result__optional_not_set NULL
#define corto_result__optional_set(id, name, parent, type, value, flags) (corto_result*)corto_result__assign((corto_result*)corto_ptr_new(corto_result_o), id, name, parent, type, value, flags)
#define corto_result__optional_set_cond(__cond, id, name, parent, type, value, flags) __cond ? (corto_result*)corto_result__assign((corto_result*)corto_ptr_new(corto_result_o), id, name, parent, type, value, flags) : NULL
#define corto_result__unset(_this) _this ? corto_ptr_free(_this, corto_result_o), 0 : 0; _this = NULL;
#define corto_result__assign(_this, id, name, parent, type, value, flags) _corto_result__assign(_this, id, name, parent, type, value, flags)
#define corto_result__set(_this, id, name, parent, type, value, flags) _this = _this ? _this : (corto_result*)corto_ptr_new(corto_result_o); _corto_result__assign(_this, id, name, parent, type, value, flags)

/* /corto/vstore/resultIter */
CORTO_EXPORT corto_resultIter* _corto_resultIter__create(corto_object _parent, const char *_id);
#define corto_resultIter__create(_parent, _id) _corto_resultIter__create(_parent, _id)
#define corto_resultIter__create_auto(_parent, _id) corto_resultIter* _id = corto_resultIter__create(_parent, #_id); (void)_id
#define corto_resultIter__declare(parent, id) (corto_resultIter*)corto_declare(parent, id, corto_resultIter_o)
CORTO_EXPORT corto_int16 _corto_resultIter__update(corto_resultIter* _this);
#define corto_resultIter__update(_this) _corto_resultIter__update(corto_resultIter(_this))
CORTO_EXPORT corto_resultIter* _corto_resultIter__assign(corto_resultIter* _this);
#define corto_resultIter__optional_not_set NULL
#define corto_resultIter__optional_set() (corto_resultIter*)corto_resultIter__assign((corto_resultIter*)corto_ptr_new(corto_resultIter_o))
#define corto_resultIter__optional_set_cond(__cond) __cond ? (corto_resultIter*)corto_resultIter__assign((corto_resultIter*)corto_ptr_new(corto_resultIter_o)) : NULL
#define corto_resultIter__unset(_this) _this ? corto_ptr_free(_this, corto_resultIter_o), 0 : 0; _this = NULL;
#define corto_resultIter__assign(_this) _corto_resultIter__assign(_this)
#define corto_resultIter__set(_this) _this = _this ? _this : (corto_resultIter*)corto_ptr_new(corto_resultIter_o); _corto_resultIter__assign(_this)

/* /corto/vstore/resultList */
CORTO_EXPORT corto_resultList* _corto_resultList__create(corto_object _parent, const char *_id, corto_uint32 length, corto_result* elements);
#define corto_resultList__create(_parent, _id, length, elements) _corto_resultList__create(_parent, _id, length, elements)
#define corto_resultList__create_auto(_parent, _id, length, elements) corto_resultList* _id = corto_resultList__create(_parent, #_id, length, elements); (void)_id
#define corto_resultList__declare(parent, id) (corto_resultList*)corto_declare(parent, id, corto_resultList_o)
CORTO_EXPORT corto_int16 _corto_resultList__update(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultList__update(_this, length, elements) _corto_resultList__update(corto_resultList(_this), length, elements)
CORTO_EXPORT corto_resultList* _corto_resultList__assign(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultList__optional_not_set NULL
#define corto_resultList__optional_set(length, elements) (corto_resultList*)corto_resultList__assign((corto_resultList*)corto_ptr_new(corto_resultList_o), length, elements)
#define corto_resultList__optional_set_cond(__cond, length, elements) __cond ? (corto_resultList*)corto_resultList__assign((corto_resultList*)corto_ptr_new(corto_resultList_o), length, elements) : NULL
#define corto_resultList__unset(_this) _this ? corto_ptr_free(_this, corto_resultList_o), 0 : 0; _this = NULL;
#define corto_resultList__assign(_this, length, elements) _corto_resultList__assign(_this, length, elements)
#define corto_resultList__set(_this, length, elements) _this = _this ? _this : (corto_resultList*)corto_ptr_new(corto_resultList_o); _corto_resultList__assign(_this, length, elements)

/* /corto/vstore/resultMask */
CORTO_EXPORT corto_resultMask* _corto_resultMask__create(corto_object _parent, const char *_id, corto_resultMask value);
#define corto_resultMask__create(_parent, _id, value) _corto_resultMask__create(_parent, _id, value)
#define corto_resultMask__create_auto(_parent, _id, value) corto_resultMask* _id = corto_resultMask__create(_parent, #_id, value); (void)_id
#define corto_resultMask__declare(parent, id) (corto_resultMask*)corto_declare(parent, id, corto_resultMask_o)
CORTO_EXPORT corto_int16 _corto_resultMask__update(corto_resultMask* _this, corto_resultMask value);
#define corto_resultMask__update(_this, value) _corto_resultMask__update(corto_resultMask(_this), value)
CORTO_EXPORT corto_resultMask* _corto_resultMask__assign(corto_resultMask* _this, corto_resultMask value);
#define corto_resultMask__optional_not_set NULL
#define corto_resultMask__optional_set(value) (corto_resultMask*)corto_resultMask__assign((corto_resultMask*)corto_ptr_new(corto_resultMask_o), value)
#define corto_resultMask__optional_set_cond(__cond, value) __cond ? (corto_resultMask*)corto_resultMask__assign((corto_resultMask*)corto_ptr_new(corto_resultMask_o), value) : NULL
#define corto_resultMask__unset(_this) _this ? corto_ptr_free(_this, corto_resultMask_o), 0 : 0; _this = NULL;
#define corto_resultMask__assign(_this, value) _corto_resultMask__assign(_this, value)
#define corto_resultMask__set(_this, value) _this = _this ? _this : (corto_resultMask*)corto_ptr_new(corto_resultMask_o); _corto_resultMask__assign(_this, value)

/* /corto/vstore/route */
CORTO_EXPORT corto_route _corto_route__create(corto_object _parent, const char *_id, const char * pattern, void(*_impl)(void));
#define corto_route__create(_parent, _id, pattern, _impl) _corto_route__create(_parent, _id, pattern, (void(*)(void))_impl)
#define corto_route__create_auto(_parent, _id, pattern, _impl) corto_route _id = corto_route__create(_parent, #_id, pattern, _impl); (void)_id
#define corto_route__declare(parent, id) (corto_route)corto_declare(parent, id, corto_route_o)
CORTO_EXPORT corto_int16 _corto_route__update(corto_route _this, const char * pattern, void(*_impl)(void));
#define corto_route__update(_this, pattern, _impl) _corto_route__update(corto_route(_this), pattern, (void(*)(void))_impl)
CORTO_EXPORT corto_route _corto_route__assign(corto_route _this, const char * pattern, void(*_impl)(void));
#define corto_route__optional_not_set NULL
#define corto_route__optional_set(pattern, _impl) (corto_route*)corto_route__assign((corto_route*)corto_ptr_new(corto_route_o), pattern, _impl)
#define corto_route__optional_set_cond(__cond, pattern, _impl) __cond ? (corto_route*)corto_route__assign((corto_route*)corto_ptr_new(corto_route_o), pattern, _impl) : NULL
#define corto_route__unset(_this) _this ? corto_ptr_free(_this, corto_route_o), 0 : 0; _this = NULL;
#define corto_route__assign(_this, pattern, _impl) _corto_route__assign(_this, pattern, (void(*)(void))_impl)
#define corto_route__set(_this, pattern, _impl) _this = _this ? _this : (corto_route*)corto_ptr_new(corto_route_o); _corto_route__assign(_this, pattern, (void(*)(void))_impl)

/* /corto/vstore/router */
CORTO_EXPORT corto_router _corto_router__create(corto_object _parent, const char *_id, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_router__create(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_router__create(_parent, _id, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_router__create_auto(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_router _id = corto_router__create(_parent, #_id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator); (void)_id
#define corto_router__declare(parent, id) (corto_router)corto_declare(parent, id, corto_router_o)
CORTO_EXPORT corto_int16 _corto_router__update(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_router__update(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_router__update(corto_router(_this), corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
CORTO_EXPORT corto_router _corto_router__assign(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_router__optional_not_set NULL
#define corto_router__optional_set(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) (corto_router*)corto_router__assign((corto_router*)corto_ptr_new(corto_router_o), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator)
#define corto_router__optional_set_cond(__cond, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) __cond ? (corto_router*)corto_router__assign((corto_router*)corto_ptr_new(corto_router_o), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) : NULL
#define corto_router__unset(_this) _this ? corto_ptr_free(_this, corto_router_o), 0 : 0; _this = NULL;
#define corto_router__assign(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_router__assign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_router__set(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _this = _this ? _this : (corto_router*)corto_ptr_new(corto_router_o); _corto_router__assign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)

/* /corto/vstore/routerimpl */
CORTO_EXPORT corto_routerimpl _corto_routerimpl__create(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimpl__create(_parent, _id, base, baseAccess, implements) _corto_routerimpl__create(_parent, _id, corto_interface(base), baseAccess, implements)
#define corto_routerimpl__create_auto(_parent, _id, base, baseAccess, implements) corto_routerimpl _id = corto_routerimpl__create(_parent, #_id, base, baseAccess, implements); (void)_id
#define corto_routerimpl__declare(parent, id) (corto_routerimpl)corto_declare(parent, id, corto_routerimpl_o)
CORTO_EXPORT corto_int16 _corto_routerimpl__update(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimpl__update(_this, base, baseAccess, implements) _corto_routerimpl__update(corto_routerimpl(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT corto_routerimpl _corto_routerimpl__assign(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimpl__optional_not_set NULL
#define corto_routerimpl__optional_set(base, baseAccess, implements) (corto_routerimpl*)corto_routerimpl__assign((corto_routerimpl*)corto_ptr_new(corto_routerimpl_o), base, baseAccess, implements)
#define corto_routerimpl__optional_set_cond(__cond, base, baseAccess, implements) __cond ? (corto_routerimpl*)corto_routerimpl__assign((corto_routerimpl*)corto_ptr_new(corto_routerimpl_o), base, baseAccess, implements) : NULL
#define corto_routerimpl__unset(_this) _this ? corto_ptr_free(_this, corto_routerimpl_o), 0 : 0; _this = NULL;
#define corto_routerimpl__assign(_this, base, baseAccess, implements) _corto_routerimpl__assign(_this, corto_interface(base), baseAccess, implements)
#define corto_routerimpl__set(_this, base, baseAccess, implements) _this = _this ? _this : (corto_routerimpl*)corto_ptr_new(corto_routerimpl_o); _corto_routerimpl__assign(_this, corto_interface(base), baseAccess, implements)

/* /corto/vstore/sample */
CORTO_EXPORT corto_sample* _corto_sample__create(corto_object _parent, const char *_id, corto_time* timestamp, uintptr_t value);
#define corto_sample__create(_parent, _id, timestamp, value) _corto_sample__create(_parent, _id, timestamp, value)
#define corto_sample__create_auto(_parent, _id, timestamp, value) corto_sample* _id = corto_sample__create(_parent, #_id, timestamp, value); (void)_id
#define corto_sample__declare(parent, id) (corto_sample*)corto_declare(parent, id, corto_sample_o)
CORTO_EXPORT corto_int16 _corto_sample__update(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sample__update(_this, timestamp, value) _corto_sample__update(corto_sample(_this), timestamp, value)
CORTO_EXPORT corto_sample* _corto_sample__assign(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sample__optional_not_set NULL
#define corto_sample__optional_set(timestamp, value) (corto_sample*)corto_sample__assign((corto_sample*)corto_ptr_new(corto_sample_o), timestamp, value)
#define corto_sample__optional_set_cond(__cond, timestamp, value) __cond ? (corto_sample*)corto_sample__assign((corto_sample*)corto_ptr_new(corto_sample_o), timestamp, value) : NULL
#define corto_sample__unset(_this) _this ? corto_ptr_free(_this, corto_sample_o), 0 : 0; _this = NULL;
#define corto_sample__assign(_this, timestamp, value) _corto_sample__assign(_this, timestamp, value)
#define corto_sample__set(_this, timestamp, value) _this = _this ? _this : (corto_sample*)corto_ptr_new(corto_sample_o); _corto_sample__assign(_this, timestamp, value)

/* /corto/vstore/sampleIter */
CORTO_EXPORT corto_sampleIter* _corto_sampleIter__create(corto_object _parent, const char *_id);
#define corto_sampleIter__create(_parent, _id) _corto_sampleIter__create(_parent, _id)
#define corto_sampleIter__create_auto(_parent, _id) corto_sampleIter* _id = corto_sampleIter__create(_parent, #_id); (void)_id
#define corto_sampleIter__declare(parent, id) (corto_sampleIter*)corto_declare(parent, id, corto_sampleIter_o)
CORTO_EXPORT corto_int16 _corto_sampleIter__update(corto_sampleIter* _this);
#define corto_sampleIter__update(_this) _corto_sampleIter__update(corto_sampleIter(_this))
CORTO_EXPORT corto_sampleIter* _corto_sampleIter__assign(corto_sampleIter* _this);
#define corto_sampleIter__optional_not_set NULL
#define corto_sampleIter__optional_set() (corto_sampleIter*)corto_sampleIter__assign((corto_sampleIter*)corto_ptr_new(corto_sampleIter_o))
#define corto_sampleIter__optional_set_cond(__cond) __cond ? (corto_sampleIter*)corto_sampleIter__assign((corto_sampleIter*)corto_ptr_new(corto_sampleIter_o)) : NULL
#define corto_sampleIter__unset(_this) _this ? corto_ptr_free(_this, corto_sampleIter_o), 0 : 0; _this = NULL;
#define corto_sampleIter__assign(_this) _corto_sampleIter__assign(_this)
#define corto_sampleIter__set(_this) _this = _this ? _this : (corto_sampleIter*)corto_ptr_new(corto_sampleIter_o); _corto_sampleIter__assign(_this)

/* /corto/vstore/subscriber */
CORTO_EXPORT corto_subscriber _corto_subscriber__create(corto_object _parent, const char *_id, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriber__create(_parent, _id, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriber__create(_parent, _id, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
#define corto_subscriber__create_auto(_parent, _id, query, contentType, instance, dispatcher, enabled, _impl) corto_subscriber _id = corto_subscriber__create(_parent, #_id, query, contentType, instance, dispatcher, enabled, _impl); (void)_id
#define corto_subscriber__declare(parent, id) (corto_subscriber)corto_declare(parent, id, corto_subscriber_o)
CORTO_EXPORT corto_int16 _corto_subscriber__update(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriber__update(_this, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriber__update(corto_subscriber(_this), query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_subscriber _corto_subscriber__assign(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriber__optional_not_set NULL
#define corto_subscriber__optional_set(query, contentType, instance, dispatcher, enabled, _impl) (corto_subscriber*)corto_subscriber__assign((corto_subscriber*)corto_ptr_new(corto_subscriber_o), query, contentType, instance, dispatcher, enabled, _impl)
#define corto_subscriber__optional_set_cond(__cond, query, contentType, instance, dispatcher, enabled, _impl) __cond ? (corto_subscriber*)corto_subscriber__assign((corto_subscriber*)corto_ptr_new(corto_subscriber_o), query, contentType, instance, dispatcher, enabled, _impl) : NULL
#define corto_subscriber__unset(_this) _this ? corto_ptr_free(_this, corto_subscriber_o), 0 : 0; _this = NULL;
#define corto_subscriber__assign(_this, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriber__assign(_this, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
#define corto_subscriber__set(_this, query, contentType, instance, dispatcher, enabled, _impl) _this = _this ? _this : (corto_subscriber*)corto_ptr_new(corto_subscriber_o); _corto_subscriber__assign(_this, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)

/* /corto/vstore/subscriber_event */
CORTO_EXPORT corto_subscriber_event* _corto_subscriber_event__create(corto_object _parent, const char *_id, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt);
#define corto_subscriber_event__create(_parent, _id, subscriber, instance, source, event, data, fmt) _corto_subscriber_event__create(_parent, _id, corto_subscriber(subscriber), instance, source, event, data, fmt)
#define corto_subscriber_event__create_auto(_parent, _id, subscriber, instance, source, event, data, fmt) corto_subscriber_event* _id = corto_subscriber_event__create(_parent, #_id, subscriber, instance, source, event, data, fmt); (void)_id
#define corto_subscriber_event__declare(parent, id) (corto_subscriber_event*)corto_declare(parent, id, corto_subscriber_event_o)
CORTO_EXPORT corto_int16 _corto_subscriber_event__update(corto_subscriber_event* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt);
#define corto_subscriber_event__update(_this, subscriber, instance, source, event, data, fmt) _corto_subscriber_event__update(corto_subscriber_event(_this), corto_subscriber(subscriber), instance, source, event, data, fmt)
CORTO_EXPORT corto_subscriber_event* _corto_subscriber_event__assign(corto_subscriber_event* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, corto_fmt_data* fmt);
#define corto_subscriber_event__optional_not_set NULL
#define corto_subscriber_event__optional_set(subscriber, instance, source, event, data, fmt) (corto_subscriber_event*)corto_subscriber_event__assign((corto_subscriber_event*)corto_ptr_new(corto_subscriber_event_o), subscriber, instance, source, event, data, fmt)
#define corto_subscriber_event__optional_set_cond(__cond, subscriber, instance, source, event, data, fmt) __cond ? (corto_subscriber_event*)corto_subscriber_event__assign((corto_subscriber_event*)corto_ptr_new(corto_subscriber_event_o), subscriber, instance, source, event, data, fmt) : NULL
#define corto_subscriber_event__unset(_this) _this ? corto_ptr_free(_this, corto_subscriber_event_o), 0 : 0; _this = NULL;
#define corto_subscriber_event__assign(_this, subscriber, instance, source, event, data, fmt) _corto_subscriber_event__assign(_this, corto_subscriber(subscriber), instance, source, event, data, fmt)
#define corto_subscriber_event__set(_this, subscriber, instance, source, event, data, fmt) _this = _this ? _this : (corto_subscriber_event*)corto_ptr_new(corto_subscriber_event_o); _corto_subscriber_event__assign(_this, corto_subscriber(subscriber), instance, source, event, data, fmt)

/* /corto/vstore/subscriber_eventIter */
CORTO_EXPORT corto_subscriber_eventIter* _corto_subscriber_eventIter__create(corto_object _parent, const char *_id);
#define corto_subscriber_eventIter__create(_parent, _id) _corto_subscriber_eventIter__create(_parent, _id)
#define corto_subscriber_eventIter__create_auto(_parent, _id) corto_subscriber_eventIter* _id = corto_subscriber_eventIter__create(_parent, #_id); (void)_id
#define corto_subscriber_eventIter__declare(parent, id) (corto_subscriber_eventIter*)corto_declare(parent, id, corto_subscriber_eventIter_o)
CORTO_EXPORT corto_int16 _corto_subscriber_eventIter__update(corto_subscriber_eventIter* _this);
#define corto_subscriber_eventIter__update(_this) _corto_subscriber_eventIter__update(corto_subscriber_eventIter(_this))
CORTO_EXPORT corto_subscriber_eventIter* _corto_subscriber_eventIter__assign(corto_subscriber_eventIter* _this);
#define corto_subscriber_eventIter__optional_not_set NULL
#define corto_subscriber_eventIter__optional_set() (corto_subscriber_eventIter*)corto_subscriber_eventIter__assign((corto_subscriber_eventIter*)corto_ptr_new(corto_subscriber_eventIter_o))
#define corto_subscriber_eventIter__optional_set_cond(__cond) __cond ? (corto_subscriber_eventIter*)corto_subscriber_eventIter__assign((corto_subscriber_eventIter*)corto_ptr_new(corto_subscriber_eventIter_o)) : NULL
#define corto_subscriber_eventIter__unset(_this) _this ? corto_ptr_free(_this, corto_subscriber_eventIter_o), 0 : 0; _this = NULL;
#define corto_subscriber_eventIter__assign(_this) _corto_subscriber_eventIter__assign(_this)
#define corto_subscriber_eventIter__set(_this) _this = _this ? _this : (corto_subscriber_eventIter*)corto_ptr_new(corto_subscriber_eventIter_o); _corto_subscriber_eventIter__assign(_this)

/* /corto/vstore/time */
CORTO_EXPORT corto_time* _corto_time__create(corto_object _parent, const char *_id, int32_t sec, uint32_t nanosec);
#define corto_time__create(_parent, _id, sec, nanosec) _corto_time__create(_parent, _id, sec, nanosec)
#define corto_time__create_auto(_parent, _id, sec, nanosec) corto_time* _id = corto_time__create(_parent, #_id, sec, nanosec); (void)_id
#define corto_time__declare(parent, id) (corto_time*)corto_declare(parent, id, corto_time_o)
CORTO_EXPORT corto_int16 _corto_time__update(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_time__update(_this, sec, nanosec) _corto_time__update(corto_time(_this), sec, nanosec)
CORTO_EXPORT corto_time* _corto_time__assign(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_time__optional_not_set NULL
#define corto_time__optional_set(sec, nanosec) (corto_time*)corto_time__assign((corto_time*)corto_ptr_new(corto_time_o), sec, nanosec)
#define corto_time__optional_set_cond(__cond, sec, nanosec) __cond ? (corto_time*)corto_time__assign((corto_time*)corto_ptr_new(corto_time_o), sec, nanosec) : NULL
#define corto_time__unset(_this) _this ? corto_ptr_free(_this, corto_time_o), 0 : 0; _this = NULL;
#define corto_time__assign(_this, sec, nanosec) _corto_time__assign(_this, sec, nanosec)
#define corto_time__set(_this, sec, nanosec) _this = _this ? _this : (corto_time*)corto_ptr_new(corto_time_o); _corto_time__assign(_this, sec, nanosec)


/* /corto/vstore/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__insert_alloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__insert(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__append_alloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__append(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__takeFirst(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__last(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionList__get(corto_mountSubscriptionList list, corto_uint32 index);
CORTO_EXPORT void corto_mountSubscriptionList__clear(corto_mountSubscriptionList list);

/* /corto/vstore/resultList */
CORTO_EXPORT corto_result* corto_resultList__insert_alloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultList__insert(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultList__append_alloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultList__append(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultList__takeFirst(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultList__last(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultList__get(corto_resultList list, corto_uint32 index);
CORTO_EXPORT void corto_resultList__clear(corto_resultList list);
#define corto_objectIter__foreach(iter, elem) \
    corto_object elem;\
    while(corto_iter_hasNext(&iter) ? elem = (corto_object)corto_iter_next(&iter), TRUE : FALSE)

#define corto_resultIter__foreach(iter, elem) \
    corto_result elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_result*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)

#define corto_sampleIter__foreach(iter, elem) \
    corto_sample elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_sample*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)

#define corto_subscriber_eventIter__foreach(iter, elem) \
    corto_subscriber_event elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_subscriber_event*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)


#ifdef __cplusplus
}
#endif
#endif

