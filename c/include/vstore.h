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
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreate(void);
#define corto_dispatcherCreate() _corto_dispatcherCreate()
#define corto_dispatcherCreate_auto(_id) corto_dispatcher _id = corto_dispatcherCreate(); (void)_id
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, const char *_id);
#define corto_dispatcherCreateChild(_parent, _id) _corto_dispatcherCreateChild(_parent, _id)
#define corto_dispatcherCreateChild_auto(_parent, _id) corto_dispatcher _id = corto_dispatcherCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this);
#define corto_dispatcherUpdate(_this) _corto_dispatcherUpdate(corto_dispatcher(_this))

CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclare(void);
#define corto_dispatcherDeclare() _corto_dispatcherDeclare()
#define corto_dispatcherDeclare_auto(_id) corto_dispatcher _id = corto_dispatcherDeclare(); (void)_id
CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, const char *_id);
#define corto_dispatcherDeclareChild(_parent, _id) _corto_dispatcherDeclareChild(_parent, _id)
#define corto_dispatcherDeclareChild_auto(_parent, _id) corto_dispatcher _id = corto_dispatcherDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_dispatcherDefine(corto_dispatcher _this);
#define corto_dispatcherDefine(_this) _corto_dispatcherDefine(corto_dispatcher(_this))
CORTO_EXPORT corto_dispatcher _corto_dispatcherAssign(corto_dispatcher _this);
#define corto_dispatcher__optional_NotSet NULL
#define corto_dispatcher__optional_Set() (corto_dispatcher*)corto_dispatcherAssign((corto_dispatcher*)corto_ptr_new(corto_dispatcher_o))
#define corto_dispatcher__optional_SetCond(cond) cond ? (corto_dispatcher*)corto_dispatcherAssign((corto_dispatcher*)corto_ptr_new(corto_dispatcher_o)) : NULL
#define corto_dispatcherUnset(_this) _this ? corto_ptr_free(_this, corto_dispatcher_o), 0 : 0; _this = NULL;
#define corto_dispatcherAssign(_this) _corto_dispatcherAssign(_this)
#define corto_dispatcherSet(_this) _this = _this ? _this : (corto_dispatcher*)corto_ptr_new(corto_dispatcher_o); _corto_dispatcherAssign(_this)

/* /corto/vstore/event */
CORTO_EXPORT corto_event* _corto_eventCreate(void);
#define corto_eventCreate() _corto_eventCreate()
#define corto_eventCreate_auto(_id) corto_event* _id = corto_eventCreate(); (void)_id
CORTO_EXPORT corto_event* _corto_eventCreateChild(corto_object _parent, const char *_id);
#define corto_eventCreateChild(_parent, _id) _corto_eventCreateChild(_parent, _id)
#define corto_eventCreateChild_auto(_parent, _id) corto_event* _id = corto_eventCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_eventUpdate(corto_event* _this);
#define corto_eventUpdate(_this) _corto_eventUpdate(corto_event(_this))

CORTO_EXPORT corto_event* _corto_eventDeclare(void);
#define corto_eventDeclare() _corto_eventDeclare()
#define corto_eventDeclare_auto(_id) corto_event* _id = corto_eventDeclare(); (void)_id
CORTO_EXPORT corto_event* _corto_eventDeclareChild(corto_object _parent, const char *_id);
#define corto_eventDeclareChild(_parent, _id) _corto_eventDeclareChild(_parent, _id)
#define corto_eventDeclareChild_auto(_parent, _id) corto_event* _id = corto_eventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_eventDefine(corto_event* _this);
#define corto_eventDefine(_this) _corto_eventDefine(corto_event(_this))
CORTO_EXPORT corto_event* _corto_eventAssign(corto_event* _this);
#define corto_event__optional_NotSet NULL
#define corto_event__optional_Set() (corto_event*)corto_eventAssign((corto_event*)corto_ptr_new(corto_event_o))
#define corto_event__optional_SetCond(cond) cond ? (corto_event*)corto_eventAssign((corto_event*)corto_ptr_new(corto_event_o)) : NULL
#define corto_eventUnset(_this) _this ? corto_ptr_free(_this, corto_event_o), 0 : 0; _this = NULL;
#define corto_eventAssign(_this) _corto_eventAssign(_this)
#define corto_eventSet(_this) _this = _this ? _this : (corto_event*)corto_ptr_new(corto_event_o); _corto_eventAssign(_this)

/* /corto/vstore/eventMask */
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreate(corto_eventMask value);
#define corto_eventMaskCreate(value) _corto_eventMaskCreate(value)
#define corto_eventMaskCreate_auto(_id, value) corto_eventMask* _id = corto_eventMaskCreate(value); (void)_id
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, const char *_id, corto_eventMask value);
#define corto_eventMaskCreateChild(_parent, _id, value) _corto_eventMaskCreateChild(_parent, _id, value)
#define corto_eventMaskCreateChild_auto(_parent, _id, value) corto_eventMask* _id = corto_eventMaskCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskUpdate(_this, value) _corto_eventMaskUpdate(corto_eventMask(_this), value)

CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclare(void);
#define corto_eventMaskDeclare() _corto_eventMaskDeclare()
#define corto_eventMaskDeclare_auto(_id) corto_eventMask* _id = corto_eventMaskDeclare(); (void)_id
CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, const char *_id);
#define corto_eventMaskDeclareChild(_parent, _id) _corto_eventMaskDeclareChild(_parent, _id)
#define corto_eventMaskDeclareChild_auto(_parent, _id) corto_eventMask* _id = corto_eventMaskDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskDefine(_this, value) _corto_eventMaskDefine(corto_eventMask(_this), value)
CORTO_EXPORT corto_eventMask* _corto_eventMaskAssign(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMask__optional_NotSet NULL
#define corto_eventMask__optional_Set(value) (corto_eventMask*)corto_eventMaskAssign((corto_eventMask*)corto_ptr_new(corto_eventMask_o), value)
#define corto_eventMask__optional_SetCond(cond, value) cond ? (corto_eventMask*)corto_eventMaskAssign((corto_eventMask*)corto_ptr_new(corto_eventMask_o), value) : NULL
#define corto_eventMaskUnset(_this) _this ? corto_ptr_free(_this, corto_eventMask_o), 0 : 0; _this = NULL;
#define corto_eventMaskAssign(_this, value) _corto_eventMaskAssign(_this, value)
#define corto_eventMaskSet(_this, value) _this = _this ? _this : (corto_eventMask*)corto_ptr_new(corto_eventMask_o); _corto_eventMaskAssign(_this, value)

/* /corto/vstore/frame */
CORTO_EXPORT corto_frame* _corto_frameCreate(corto_frameKind kind, int64_t value);
#define corto_frameCreate(kind, value) _corto_frameCreate(kind, value)
#define corto_frameCreate_auto(_id, kind, value) corto_frame* _id = corto_frameCreate(kind, value); (void)_id
CORTO_EXPORT corto_frame* _corto_frameCreateChild(corto_object _parent, const char *_id, corto_frameKind kind, int64_t value);
#define corto_frameCreateChild(_parent, _id, kind, value) _corto_frameCreateChild(_parent, _id, kind, value)
#define corto_frameCreateChild_auto(_parent, _id, kind, value) corto_frame* _id = corto_frameCreateChild(_parent, #_id, kind, value); (void)_id
CORTO_EXPORT corto_int16 _corto_frameUpdate(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frameUpdate(_this, kind, value) _corto_frameUpdate(corto_frame(_this), kind, value)

CORTO_EXPORT corto_frame* _corto_frameDeclare(void);
#define corto_frameDeclare() _corto_frameDeclare()
#define corto_frameDeclare_auto(_id) corto_frame* _id = corto_frameDeclare(); (void)_id
CORTO_EXPORT corto_frame* _corto_frameDeclareChild(corto_object _parent, const char *_id);
#define corto_frameDeclareChild(_parent, _id) _corto_frameDeclareChild(_parent, _id)
#define corto_frameDeclareChild_auto(_parent, _id) corto_frame* _id = corto_frameDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_frameDefine(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frameDefine(_this, kind, value) _corto_frameDefine(corto_frame(_this), kind, value)
CORTO_EXPORT corto_frame* _corto_frameAssign(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frame__optional_NotSet NULL
#define corto_frame__optional_Set(kind, value) (corto_frame*)corto_frameAssign((corto_frame*)corto_ptr_new(corto_frame_o), kind, value)
#define corto_frame__optional_SetCond(cond, kind, value) cond ? (corto_frame*)corto_frameAssign((corto_frame*)corto_ptr_new(corto_frame_o), kind, value) : NULL
#define corto_frameUnset(_this) _this ? corto_ptr_free(_this, corto_frame_o), 0 : 0; _this = NULL;
#define corto_frameAssign(_this, kind, value) _corto_frameAssign(_this, kind, value)
#define corto_frameSet(_this, kind, value) _this = _this ? _this : (corto_frame*)corto_ptr_new(corto_frame_o); _corto_frameAssign(_this, kind, value)

/* /corto/vstore/frameKind */
CORTO_EXPORT corto_frameKind* _corto_frameKindCreate(corto_frameKind value);
#define corto_frameKindCreate(value) _corto_frameKindCreate(value)
#define corto_frameKindCreate_auto(_id, value) corto_frameKind* _id = corto_frameKindCreate(value); (void)_id
CORTO_EXPORT corto_frameKind* _corto_frameKindCreateChild(corto_object _parent, const char *_id, corto_frameKind value);
#define corto_frameKindCreateChild(_parent, _id, value) _corto_frameKindCreateChild(_parent, _id, value)
#define corto_frameKindCreateChild_auto(_parent, _id, value) corto_frameKind* _id = corto_frameKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_frameKindUpdate(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKindUpdate(_this, value) _corto_frameKindUpdate(corto_frameKind(_this), value)

CORTO_EXPORT corto_frameKind* _corto_frameKindDeclare(void);
#define corto_frameKindDeclare() _corto_frameKindDeclare()
#define corto_frameKindDeclare_auto(_id) corto_frameKind* _id = corto_frameKindDeclare(); (void)_id
CORTO_EXPORT corto_frameKind* _corto_frameKindDeclareChild(corto_object _parent, const char *_id);
#define corto_frameKindDeclareChild(_parent, _id) _corto_frameKindDeclareChild(_parent, _id)
#define corto_frameKindDeclareChild_auto(_parent, _id) corto_frameKind* _id = corto_frameKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_frameKindDefine(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKindDefine(_this, value) _corto_frameKindDefine(corto_frameKind(_this), value)
CORTO_EXPORT corto_frameKind* _corto_frameKindAssign(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKind__optional_NotSet NULL
#define corto_frameKind__optional_Set(value) (corto_frameKind*)corto_frameKindAssign((corto_frameKind*)corto_ptr_new(corto_frameKind_o), value)
#define corto_frameKind__optional_SetCond(cond, value) cond ? (corto_frameKind*)corto_frameKindAssign((corto_frameKind*)corto_ptr_new(corto_frameKind_o), value) : NULL
#define corto_frameKindUnset(_this) _this ? corto_ptr_free(_this, corto_frameKind_o), 0 : 0; _this = NULL;
#define corto_frameKindAssign(_this, value) _corto_frameKindAssign(_this, value)
#define corto_frameKindSet(_this, value) _this = _this ? _this : (corto_frameKind*)corto_ptr_new(corto_frameKind_o); _corto_frameKindAssign(_this, value)

/* /corto/vstore/handleAction */
CORTO_EXPORT corto_handleAction* _corto_handleActionCreate(corto_object instance, corto_function procedure);
#define corto_handleActionCreate(instance, procedure) _corto_handleActionCreate(instance, corto_function(procedure))
#define corto_handleActionCreate_auto(_id, instance, procedure) corto_handleAction* _id = corto_handleActionCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_handleAction* _corto_handleActionCreateChild(corto_object _parent, const char *_id, corto_object instance, corto_function procedure);
#define corto_handleActionCreateChild(_parent, _id, instance, procedure) _corto_handleActionCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_handleActionCreateChild_auto(_parent, _id, instance, procedure) corto_handleAction* _id = corto_handleActionCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_handleActionUpdate(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleActionUpdate(_this, instance, procedure) _corto_handleActionUpdate(corto_handleAction(_this), instance, corto_function(procedure))

CORTO_EXPORT corto_handleAction* _corto_handleActionDeclare(void);
#define corto_handleActionDeclare() _corto_handleActionDeclare()
#define corto_handleActionDeclare_auto(_id) corto_handleAction* _id = corto_handleActionDeclare(); (void)_id
CORTO_EXPORT corto_handleAction* _corto_handleActionDeclareChild(corto_object _parent, const char *_id);
#define corto_handleActionDeclareChild(_parent, _id) _corto_handleActionDeclareChild(_parent, _id)
#define corto_handleActionDeclareChild_auto(_parent, _id) corto_handleAction* _id = corto_handleActionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_handleActionDefine(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleActionDefine(_this, instance, procedure) _corto_handleActionDefine(corto_handleAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_handleAction* _corto_handleActionAssign(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleAction__optional_NotSet NULL
#define corto_handleAction__optional_Set(instance, procedure) (corto_handleAction*)corto_handleActionAssign((corto_handleAction*)corto_ptr_new(corto_handleAction_o), instance, procedure)
#define corto_handleAction__optional_SetCond(cond, instance, procedure) cond ? (corto_handleAction*)corto_handleActionAssign((corto_handleAction*)corto_ptr_new(corto_handleAction_o), instance, procedure) : NULL
#define corto_handleActionUnset(_this) _this ? corto_ptr_free(_this, corto_handleAction_o), 0 : 0; _this = NULL;
#define corto_handleActionAssign(_this, instance, procedure) _corto_handleActionAssign(_this, instance, corto_function(procedure))
#define corto_handleActionSet(_this, instance, procedure) _this = _this ? _this : (corto_handleAction*)corto_ptr_new(corto_handleAction_o); _corto_handleActionAssign(_this, instance, corto_function(procedure))

corto_int16 corto_handleActionCall(corto_handleAction *_delegate, corto_event* event);
#define corto_handleActionInitC_auto(d, callback) corto_handleAction d; corto_handleActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_handleActionInitC(corto_handleAction *d, corto_void ___ (*callback)(corto_event*));
#define corto_handleActionInitCInstance_auto(d, instance, callback)corto_handleAction d; corto_handleActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_handleActionInitCInstance(corto_handleAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_event*));
/* /corto/vstore/invokeEvent */
CORTO_EXPORT corto_invokeEvent* _corto_invokeEventCreate(corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventCreate(mount, instance, function, args) _corto_invokeEventCreate(corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventCreate_auto(_id, mount, instance, function, args) corto_invokeEvent* _id = corto_invokeEventCreate(mount, instance, function, args); (void)_id
CORTO_EXPORT corto_invokeEvent* _corto_invokeEventCreateChild(corto_object _parent, const char *_id, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventCreateChild(_parent, _id, mount, instance, function, args) _corto_invokeEventCreateChild(_parent, _id, corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventCreateChild_auto(_parent, _id, mount, instance, function, args) corto_invokeEvent* _id = corto_invokeEventCreateChild(_parent, #_id, mount, instance, function, args); (void)_id
CORTO_EXPORT corto_int16 _corto_invokeEventUpdate(corto_invokeEvent* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventUpdate(_this, mount, instance, function, args) _corto_invokeEventUpdate(corto_invokeEvent(_this), corto_mount(mount), instance, corto_function(function), args)

CORTO_EXPORT corto_invokeEvent* _corto_invokeEventDeclare(void);
#define corto_invokeEventDeclare() _corto_invokeEventDeclare()
#define corto_invokeEventDeclare_auto(_id) corto_invokeEvent* _id = corto_invokeEventDeclare(); (void)_id
CORTO_EXPORT corto_invokeEvent* _corto_invokeEventDeclareChild(corto_object _parent, const char *_id);
#define corto_invokeEventDeclareChild(_parent, _id) _corto_invokeEventDeclareChild(_parent, _id)
#define corto_invokeEventDeclareChild_auto(_parent, _id) corto_invokeEvent* _id = corto_invokeEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_invokeEventDefine(corto_invokeEvent* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventDefine(_this, mount, instance, function, args) _corto_invokeEventDefine(corto_invokeEvent(_this), corto_mount(mount), instance, corto_function(function), args)
CORTO_EXPORT corto_invokeEvent* _corto_invokeEventAssign(corto_invokeEvent* _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEvent__optional_NotSet NULL
#define corto_invokeEvent__optional_Set(mount, instance, function, args) (corto_invokeEvent*)corto_invokeEventAssign((corto_invokeEvent*)corto_ptr_new(corto_invokeEvent_o), mount, instance, function, args)
#define corto_invokeEvent__optional_SetCond(cond, mount, instance, function, args) cond ? (corto_invokeEvent*)corto_invokeEventAssign((corto_invokeEvent*)corto_ptr_new(corto_invokeEvent_o), mount, instance, function, args) : NULL
#define corto_invokeEventUnset(_this) _this ? corto_ptr_free(_this, corto_invokeEvent_o), 0 : 0; _this = NULL;
#define corto_invokeEventAssign(_this, mount, instance, function, args) _corto_invokeEventAssign(_this, corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventSet(_this, mount, instance, function, args) _this = _this ? _this : (corto_invokeEvent*)corto_ptr_new(corto_invokeEvent_o); _corto_invokeEventAssign(_this, corto_mount(mount), instance, corto_function(function), args)

/* /corto/vstore/loader */
CORTO_EXPORT corto_loader _corto_loaderCreate(bool autoLoad);
#define corto_loaderCreate(autoLoad) _corto_loaderCreate(autoLoad)
#define corto_loaderCreate_auto(_id, autoLoad) corto_loader _id = corto_loaderCreate(autoLoad); (void)_id
CORTO_EXPORT corto_loader _corto_loaderCreateChild(corto_object _parent, const char *_id, bool autoLoad);
#define corto_loaderCreateChild(_parent, _id, autoLoad) _corto_loaderCreateChild(_parent, _id, autoLoad)
#define corto_loaderCreateChild_auto(_parent, _id, autoLoad) corto_loader _id = corto_loaderCreateChild(_parent, #_id, autoLoad); (void)_id
CORTO_EXPORT corto_int16 _corto_loaderUpdate(corto_loader _this, bool autoLoad);
#define corto_loaderUpdate(_this, autoLoad) _corto_loaderUpdate(corto_loader(_this), autoLoad)

CORTO_EXPORT corto_loader _corto_loaderDeclare(void);
#define corto_loaderDeclare() _corto_loaderDeclare()
#define corto_loaderDeclare_auto(_id) corto_loader _id = corto_loaderDeclare(); (void)_id
CORTO_EXPORT corto_loader _corto_loaderDeclareChild(corto_object _parent, const char *_id);
#define corto_loaderDeclareChild(_parent, _id) _corto_loaderDeclareChild(_parent, _id)
#define corto_loaderDeclareChild_auto(_parent, _id) corto_loader _id = corto_loaderDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_loaderDefine(corto_loader _this, bool autoLoad);
#define corto_loaderDefine(_this, autoLoad) _corto_loaderDefine(corto_loader(_this), autoLoad)
CORTO_EXPORT corto_loader _corto_loaderAssign(corto_loader _this, bool autoLoad);
#define corto_loader__optional_NotSet NULL
#define corto_loader__optional_Set(autoLoad) (corto_loader*)corto_loaderAssign((corto_loader*)corto_ptr_new(corto_loader_o), autoLoad)
#define corto_loader__optional_SetCond(cond, autoLoad) cond ? (corto_loader*)corto_loaderAssign((corto_loader*)corto_ptr_new(corto_loader_o), autoLoad) : NULL
#define corto_loaderUnset(_this) _this ? corto_ptr_free(_this, corto_loader_o), 0 : 0; _this = NULL;
#define corto_loaderAssign(_this, autoLoad) _corto_loaderAssign(_this, autoLoad)
#define corto_loaderSet(_this, autoLoad) _this = _this ? _this : (corto_loader*)corto_ptr_new(corto_loader_o); _corto_loaderAssign(_this, autoLoad)

/* /corto/vstore/mount */
CORTO_EXPORT corto_mount _corto_mountCreate(corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mountCreate(query, contentType, policy) _corto_mountCreate(query, contentType, policy)
#define corto_mountCreate_auto(_id, query, contentType, policy) corto_mount _id = corto_mountCreate(query, contentType, policy); (void)_id
CORTO_EXPORT corto_mount _corto_mountCreateChild(corto_object _parent, const char *_id, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mountCreateChild(_parent, _id, query, contentType, policy) _corto_mountCreateChild(_parent, _id, query, contentType, policy)
#define corto_mountCreateChild_auto(_parent, _id, query, contentType, policy) corto_mount _id = corto_mountCreateChild(_parent, #_id, query, contentType, policy); (void)_id
CORTO_EXPORT corto_int16 _corto_mountUpdate(corto_mount _this, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mountUpdate(_this, query, contentType, policy) _corto_mountUpdate(corto_mount(_this), query, contentType, policy)

CORTO_EXPORT corto_mount _corto_mountDeclare(void);
#define corto_mountDeclare() _corto_mountDeclare()
#define corto_mountDeclare_auto(_id) corto_mount _id = corto_mountDeclare(); (void)_id
CORTO_EXPORT corto_mount _corto_mountDeclareChild(corto_object _parent, const char *_id);
#define corto_mountDeclareChild(_parent, _id) _corto_mountDeclareChild(_parent, _id)
#define corto_mountDeclareChild_auto(_parent, _id) corto_mount _id = corto_mountDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountDefine(corto_mount _this, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mountDefine(_this, query, contentType, policy) _corto_mountDefine(corto_mount(_this), query, contentType, policy)
CORTO_EXPORT corto_mount _corto_mountAssign(corto_mount _this, corto_query* query, const char * contentType, corto_mountPolicy* policy);
#define corto_mount__optional_NotSet NULL
#define corto_mount__optional_Set(query, contentType, policy) (corto_mount*)corto_mountAssign((corto_mount*)corto_ptr_new(corto_mount_o), query, contentType, policy)
#define corto_mount__optional_SetCond(cond, query, contentType, policy) cond ? (corto_mount*)corto_mountAssign((corto_mount*)corto_ptr_new(corto_mount_o), query, contentType, policy) : NULL
#define corto_mountUnset(_this) _this ? corto_ptr_free(_this, corto_mount_o), 0 : 0; _this = NULL;
#define corto_mountAssign(_this, query, contentType, policy) _corto_mountAssign(_this, query, contentType, policy)
#define corto_mountSet(_this, query, contentType, policy) _this = _this ? _this : (corto_mount*)corto_ptr_new(corto_mount_o); _corto_mountAssign(_this, query, contentType, policy)

/* /corto/vstore/mountMask */
CORTO_EXPORT corto_mountMask* _corto_mountMaskCreate(corto_mountMask value);
#define corto_mountMaskCreate(value) _corto_mountMaskCreate(value)
#define corto_mountMaskCreate_auto(_id, value) corto_mountMask* _id = corto_mountMaskCreate(value); (void)_id
CORTO_EXPORT corto_mountMask* _corto_mountMaskCreateChild(corto_object _parent, const char *_id, corto_mountMask value);
#define corto_mountMaskCreateChild(_parent, _id, value) _corto_mountMaskCreateChild(_parent, _id, value)
#define corto_mountMaskCreateChild_auto(_parent, _id, value) corto_mountMask* _id = corto_mountMaskCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_mountMaskUpdate(corto_mountMask* _this, corto_mountMask value);
#define corto_mountMaskUpdate(_this, value) _corto_mountMaskUpdate(corto_mountMask(_this), value)

CORTO_EXPORT corto_mountMask* _corto_mountMaskDeclare(void);
#define corto_mountMaskDeclare() _corto_mountMaskDeclare()
#define corto_mountMaskDeclare_auto(_id) corto_mountMask* _id = corto_mountMaskDeclare(); (void)_id
CORTO_EXPORT corto_mountMask* _corto_mountMaskDeclareChild(corto_object _parent, const char *_id);
#define corto_mountMaskDeclareChild(_parent, _id) _corto_mountMaskDeclareChild(_parent, _id)
#define corto_mountMaskDeclareChild_auto(_parent, _id) corto_mountMask* _id = corto_mountMaskDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountMaskDefine(corto_mountMask* _this, corto_mountMask value);
#define corto_mountMaskDefine(_this, value) _corto_mountMaskDefine(corto_mountMask(_this), value)
CORTO_EXPORT corto_mountMask* _corto_mountMaskAssign(corto_mountMask* _this, corto_mountMask value);
#define corto_mountMask__optional_NotSet NULL
#define corto_mountMask__optional_Set(value) (corto_mountMask*)corto_mountMaskAssign((corto_mountMask*)corto_ptr_new(corto_mountMask_o), value)
#define corto_mountMask__optional_SetCond(cond, value) cond ? (corto_mountMask*)corto_mountMaskAssign((corto_mountMask*)corto_ptr_new(corto_mountMask_o), value) : NULL
#define corto_mountMaskUnset(_this) _this ? corto_ptr_free(_this, corto_mountMask_o), 0 : 0; _this = NULL;
#define corto_mountMaskAssign(_this, value) _corto_mountMaskAssign(_this, value)
#define corto_mountMaskSet(_this, value) _this = _this ? _this : (corto_mountMask*)corto_ptr_new(corto_mountMask_o); _corto_mountMaskAssign(_this, value)

/* /corto/vstore/mountPolicy */
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyCreate(corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicyCreate(ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicyCreate(ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicyCreate_auto(_id, ownership, mask, sampleRate, queue, expiryTime, filterResults) corto_mountPolicy* _id = corto_mountPolicyCreate(ownership, mask, sampleRate, queue, expiryTime, filterResults); (void)_id
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyCreateChild(corto_object _parent, const char *_id, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicyCreateChild(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicyCreateChild(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicyCreateChild_auto(_parent, _id, ownership, mask, sampleRate, queue, expiryTime, filterResults) corto_mountPolicy* _id = corto_mountPolicyCreateChild(_parent, #_id, ownership, mask, sampleRate, queue, expiryTime, filterResults); (void)_id
CORTO_EXPORT corto_int16 _corto_mountPolicyUpdate(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicyUpdate(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicyUpdate(corto_mountPolicy(_this), ownership, mask, sampleRate, queue, expiryTime, filterResults)

CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyDeclare(void);
#define corto_mountPolicyDeclare() _corto_mountPolicyDeclare()
#define corto_mountPolicyDeclare_auto(_id) corto_mountPolicy* _id = corto_mountPolicyDeclare(); (void)_id
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyDeclareChild(corto_object _parent, const char *_id);
#define corto_mountPolicyDeclareChild(_parent, _id) _corto_mountPolicyDeclareChild(_parent, _id)
#define corto_mountPolicyDeclareChild_auto(_parent, _id) corto_mountPolicy* _id = corto_mountPolicyDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountPolicyDefine(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicyDefine(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicyDefine(corto_mountPolicy(_this), ownership, mask, sampleRate, queue, expiryTime, filterResults)
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyAssign(corto_mountPolicy* _this, corto_ownership ownership, corto_mountMask mask, double sampleRate, corto_queuePolicy* queue, uint64_t expiryTime, bool filterResults);
#define corto_mountPolicy__optional_NotSet NULL
#define corto_mountPolicy__optional_Set(ownership, mask, sampleRate, queue, expiryTime, filterResults) (corto_mountPolicy*)corto_mountPolicyAssign((corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o), ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicy__optional_SetCond(cond, ownership, mask, sampleRate, queue, expiryTime, filterResults) cond ? (corto_mountPolicy*)corto_mountPolicyAssign((corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o), ownership, mask, sampleRate, queue, expiryTime, filterResults) : NULL
#define corto_mountPolicyUnset(_this) _this ? corto_ptr_free(_this, corto_mountPolicy_o), 0 : 0; _this = NULL;
#define corto_mountPolicyAssign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _corto_mountPolicyAssign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults)
#define corto_mountPolicySet(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults) _this = _this ? _this : (corto_mountPolicy*)corto_ptr_new(corto_mountPolicy_o); _corto_mountPolicyAssign(_this, ownership, mask, sampleRate, queue, expiryTime, filterResults)

/* /corto/vstore/mountSubscription */
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionCreate(corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscriptionCreate(query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscriptionCreate(query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscriptionCreate_auto(_id, query, mountCount, subscriberCount, mountCtx, subscriberCtx) corto_mountSubscription* _id = corto_mountSubscriptionCreate(query, mountCount, subscriberCount, mountCtx, subscriberCtx); (void)_id
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionCreateChild(corto_object _parent, const char *_id, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscriptionCreateChild(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscriptionCreateChild(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscriptionCreateChild_auto(_parent, _id, query, mountCount, subscriberCount, mountCtx, subscriberCtx) corto_mountSubscription* _id = corto_mountSubscriptionCreateChild(_parent, #_id, query, mountCount, subscriberCount, mountCtx, subscriberCtx); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionUpdate(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscriptionUpdate(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscriptionUpdate(corto_mountSubscription(_this), query, mountCount, subscriberCount, mountCtx, subscriberCtx)

CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionDeclare(void);
#define corto_mountSubscriptionDeclare() _corto_mountSubscriptionDeclare()
#define corto_mountSubscriptionDeclare_auto(_id) corto_mountSubscription* _id = corto_mountSubscriptionDeclare(); (void)_id
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionDeclareChild(corto_object _parent, const char *_id);
#define corto_mountSubscriptionDeclareChild(_parent, _id) _corto_mountSubscriptionDeclareChild(_parent, _id)
#define corto_mountSubscriptionDeclareChild_auto(_parent, _id) corto_mountSubscription* _id = corto_mountSubscriptionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionDefine(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscriptionDefine(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscriptionDefine(corto_mountSubscription(_this), query, mountCount, subscriberCount, mountCtx, subscriberCtx)
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionAssign(corto_mountSubscription* _this, corto_query* query, uint32_t mountCount, uint32_t subscriberCount, uintptr_t mountCtx, uintptr_t subscriberCtx);
#define corto_mountSubscription__optional_NotSet NULL
#define corto_mountSubscription__optional_Set(query, mountCount, subscriberCount, mountCtx, subscriberCtx) (corto_mountSubscription*)corto_mountSubscriptionAssign((corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o), query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscription__optional_SetCond(cond, query, mountCount, subscriberCount, mountCtx, subscriberCtx) cond ? (corto_mountSubscription*)corto_mountSubscriptionAssign((corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o), query, mountCount, subscriberCount, mountCtx, subscriberCtx) : NULL
#define corto_mountSubscriptionUnset(_this) _this ? corto_ptr_free(_this, corto_mountSubscription_o), 0 : 0; _this = NULL;
#define corto_mountSubscriptionAssign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _corto_mountSubscriptionAssign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx)
#define corto_mountSubscriptionSet(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx) _this = _this ? _this : (corto_mountSubscription*)corto_ptr_new(corto_mountSubscription_o); _corto_mountSubscriptionAssign(_this, query, mountCount, subscriberCount, mountCtx, subscriberCtx)

/* /corto/vstore/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListCreate(corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListCreate(length, elements) _corto_mountSubscriptionListCreate(length, elements)
#define corto_mountSubscriptionListCreate_auto(_id, length, elements) corto_mountSubscriptionList* _id = corto_mountSubscriptionListCreate(length, elements); (void)_id
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListCreateChild(_parent, _id, length, elements) _corto_mountSubscriptionListCreateChild(_parent, _id, length, elements)
#define corto_mountSubscriptionListCreateChild_auto(_parent, _id, length, elements) corto_mountSubscriptionList* _id = corto_mountSubscriptionListCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListUpdate(_this, length, elements) _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList(_this), length, elements)

CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListDeclare(void);
#define corto_mountSubscriptionListDeclare() _corto_mountSubscriptionListDeclare()
#define corto_mountSubscriptionListDeclare_auto(_id) corto_mountSubscriptionList* _id = corto_mountSubscriptionListDeclare(); (void)_id
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListDeclareChild(corto_object _parent, const char *_id);
#define corto_mountSubscriptionListDeclareChild(_parent, _id) _corto_mountSubscriptionListDeclareChild(_parent, _id)
#define corto_mountSubscriptionListDeclareChild_auto(_parent, _id) corto_mountSubscriptionList* _id = corto_mountSubscriptionListDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionListDefine(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListDefine(_this, length, elements) _corto_mountSubscriptionListDefine(corto_mountSubscriptionList(_this), length, elements)
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListAssign(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionList__optional_NotSet NULL
#define corto_mountSubscriptionList__optional_Set(length, elements) (corto_mountSubscriptionList*)corto_mountSubscriptionListAssign((corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o), length, elements)
#define corto_mountSubscriptionList__optional_SetCond(cond, length, elements) cond ? (corto_mountSubscriptionList*)corto_mountSubscriptionListAssign((corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o), length, elements) : NULL
#define corto_mountSubscriptionListUnset(_this) _this ? corto_ptr_free(_this, corto_mountSubscriptionList_o), 0 : 0; _this = NULL;
#define corto_mountSubscriptionListAssign(_this, length, elements) _corto_mountSubscriptionListAssign(_this, length, elements)
#define corto_mountSubscriptionListSet(_this, length, elements) _this = _this ? _this : (corto_mountSubscriptionList*)corto_ptr_new(corto_mountSubscriptionList_o); _corto_mountSubscriptionListAssign(_this, length, elements)

/* /corto/vstore/objectIter */
CORTO_EXPORT corto_objectIter* _corto_objectIterCreate(void);
#define corto_objectIterCreate() _corto_objectIterCreate()
#define corto_objectIterCreate_auto(_id) corto_objectIter* _id = corto_objectIterCreate(); (void)_id
CORTO_EXPORT corto_objectIter* _corto_objectIterCreateChild(corto_object _parent, const char *_id);
#define corto_objectIterCreateChild(_parent, _id) _corto_objectIterCreateChild(_parent, _id)
#define corto_objectIterCreateChild_auto(_parent, _id) corto_objectIter* _id = corto_objectIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectIterUpdate(corto_objectIter* _this);
#define corto_objectIterUpdate(_this) _corto_objectIterUpdate(corto_objectIter(_this))

CORTO_EXPORT corto_objectIter* _corto_objectIterDeclare(void);
#define corto_objectIterDeclare() _corto_objectIterDeclare()
#define corto_objectIterDeclare_auto(_id) corto_objectIter* _id = corto_objectIterDeclare(); (void)_id
CORTO_EXPORT corto_objectIter* _corto_objectIterDeclareChild(corto_object _parent, const char *_id);
#define corto_objectIterDeclareChild(_parent, _id) _corto_objectIterDeclareChild(_parent, _id)
#define corto_objectIterDeclareChild_auto(_parent, _id) corto_objectIter* _id = corto_objectIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectIterDefine(corto_objectIter* _this);
#define corto_objectIterDefine(_this) _corto_objectIterDefine(corto_objectIter(_this))
CORTO_EXPORT corto_objectIter* _corto_objectIterAssign(corto_objectIter* _this);
#define corto_objectIter__optional_NotSet NULL
#define corto_objectIter__optional_Set() (corto_objectIter*)corto_objectIterAssign((corto_objectIter*)corto_ptr_new(corto_objectIter_o))
#define corto_objectIter__optional_SetCond(cond) cond ? (corto_objectIter*)corto_objectIterAssign((corto_objectIter*)corto_ptr_new(corto_objectIter_o)) : NULL
#define corto_objectIterUnset(_this) _this ? corto_ptr_free(_this, corto_objectIter_o), 0 : 0; _this = NULL;
#define corto_objectIterAssign(_this) _corto_objectIterAssign(_this)
#define corto_objectIterSet(_this) _this = _this ? _this : (corto_objectIter*)corto_ptr_new(corto_objectIter_o); _corto_objectIterAssign(_this)

/* /corto/vstore/observer */
CORTO_EXPORT corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observerCreate(mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerCreate(mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
#define corto_observerCreate_auto(_id, mask, observable, instance, dispatcher, type, enabled, _impl) corto_observer _id = corto_observerCreate(mask, observable, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_observer _corto_observerCreateChild(corto_object _parent, const char *_id, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observerCreateChild(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerCreateChild(_parent, _id, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
#define corto_observerCreateChild_auto(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) corto_observer _id = corto_observerCreateChild(_parent, #_id, mask, observable, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observerUpdate(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerUpdate(corto_observer(_this), mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)

CORTO_EXPORT corto_observer _corto_observerDeclare(void);
#define corto_observerDeclare() _corto_observerDeclare()
#define corto_observerDeclare_auto(_id) corto_observer _id = corto_observerDeclare(); (void)_id
CORTO_EXPORT corto_observer _corto_observerDeclareChild(corto_object _parent, const char *_id);
#define corto_observerDeclareChild(_parent, _id) _corto_observerDeclareChild(_parent, _id)
#define corto_observerDeclareChild_auto(_parent, _id) corto_observer _id = corto_observerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observerDefine(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerDefine(corto_observer(_this), mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_observer _corto_observerAssign(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_type type, bool enabled, void(*_impl)(void));
#define corto_observer__optional_NotSet NULL
#define corto_observer__optional_Set(mask, observable, instance, dispatcher, type, enabled, _impl) (corto_observer*)corto_observerAssign((corto_observer*)corto_ptr_new(corto_observer_o), mask, observable, instance, dispatcher, type, enabled, _impl)
#define corto_observer__optional_SetCond(cond, mask, observable, instance, dispatcher, type, enabled, _impl) cond ? (corto_observer*)corto_observerAssign((corto_observer*)corto_ptr_new(corto_observer_o), mask, observable, instance, dispatcher, type, enabled, _impl) : NULL
#define corto_observerUnset(_this) _this ? corto_ptr_free(_this, corto_observer_o), 0 : 0; _this = NULL;
#define corto_observerAssign(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerAssign(_this, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)
#define corto_observerSet(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _this = _this ? _this : (corto_observer*)corto_ptr_new(corto_observer_o); _corto_observerAssign(_this, mask, observable, instance, corto_dispatcher(dispatcher), corto_type(type), enabled, (void(*)(void))_impl)

/* /corto/vstore/observerEvent */
CORTO_EXPORT corto_observerEvent* _corto_observerEventCreate(corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventCreate(observer, instance, source, event, data, thread) _corto_observerEventCreate(corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventCreate_auto(_id, observer, instance, source, event, data, thread) corto_observerEvent* _id = corto_observerEventCreate(observer, instance, source, event, data, thread); (void)_id
CORTO_EXPORT corto_observerEvent* _corto_observerEventCreateChild(corto_object _parent, const char *_id, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventCreateChild(_parent, _id, observer, instance, source, event, data, thread) _corto_observerEventCreateChild(_parent, _id, corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventCreateChild_auto(_parent, _id, observer, instance, source, event, data, thread) corto_observerEvent* _id = corto_observerEventCreateChild(_parent, #_id, observer, instance, source, event, data, thread); (void)_id
CORTO_EXPORT corto_int16 _corto_observerEventUpdate(corto_observerEvent* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventUpdate(_this, observer, instance, source, event, data, thread) _corto_observerEventUpdate(corto_observerEvent(_this), corto_observer(observer), instance, source, event, data, thread)

CORTO_EXPORT corto_observerEvent* _corto_observerEventDeclare(void);
#define corto_observerEventDeclare() _corto_observerEventDeclare()
#define corto_observerEventDeclare_auto(_id) corto_observerEvent* _id = corto_observerEventDeclare(); (void)_id
CORTO_EXPORT corto_observerEvent* _corto_observerEventDeclareChild(corto_object _parent, const char *_id);
#define corto_observerEventDeclareChild(_parent, _id) _corto_observerEventDeclareChild(_parent, _id)
#define corto_observerEventDeclareChild_auto(_parent, _id) corto_observerEvent* _id = corto_observerEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_observerEventDefine(corto_observerEvent* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventDefine(_this, observer, instance, source, event, data, thread) _corto_observerEventDefine(corto_observerEvent(_this), corto_observer(observer), instance, source, event, data, thread)
CORTO_EXPORT corto_observerEvent* _corto_observerEventAssign(corto_observerEvent* _this, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEvent__optional_NotSet NULL
#define corto_observerEvent__optional_Set(observer, instance, source, event, data, thread) (corto_observerEvent*)corto_observerEventAssign((corto_observerEvent*)corto_ptr_new(corto_observerEvent_o), observer, instance, source, event, data, thread)
#define corto_observerEvent__optional_SetCond(cond, observer, instance, source, event, data, thread) cond ? (corto_observerEvent*)corto_observerEventAssign((corto_observerEvent*)corto_ptr_new(corto_observerEvent_o), observer, instance, source, event, data, thread) : NULL
#define corto_observerEventUnset(_this) _this ? corto_ptr_free(_this, corto_observerEvent_o), 0 : 0; _this = NULL;
#define corto_observerEventAssign(_this, observer, instance, source, event, data, thread) _corto_observerEventAssign(_this, corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventSet(_this, observer, instance, source, event, data, thread) _this = _this ? _this : (corto_observerEvent*)corto_ptr_new(corto_observerEvent_o); _corto_observerEventAssign(_this, corto_observer(observer), instance, source, event, data, thread)

/* /corto/vstore/operatorKind */
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value);
#define corto_operatorKindCreate(value) _corto_operatorKindCreate(value)
#define corto_operatorKindCreate_auto(_id, value) corto_operatorKind* _id = corto_operatorKindCreate(value); (void)_id
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, const char *_id, corto_operatorKind value);
#define corto_operatorKindCreateChild(_parent, _id, value) _corto_operatorKindCreateChild(_parent, _id, value)
#define corto_operatorKindCreateChild_auto(_parent, _id, value) corto_operatorKind* _id = corto_operatorKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindUpdate(_this, value) _corto_operatorKindUpdate(corto_operatorKind(_this), value)

CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclare(void);
#define corto_operatorKindDeclare() _corto_operatorKindDeclare()
#define corto_operatorKindDeclare_auto(_id) corto_operatorKind* _id = corto_operatorKindDeclare(); (void)_id
CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, const char *_id);
#define corto_operatorKindDeclareChild(_parent, _id) _corto_operatorKindDeclareChild(_parent, _id)
#define corto_operatorKindDeclareChild_auto(_parent, _id) corto_operatorKind* _id = corto_operatorKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindDefine(_this, value) _corto_operatorKindDefine(corto_operatorKind(_this), value)
CORTO_EXPORT corto_operatorKind* _corto_operatorKindAssign(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKind__optional_NotSet NULL
#define corto_operatorKind__optional_Set(value) (corto_operatorKind*)corto_operatorKindAssign((corto_operatorKind*)corto_ptr_new(corto_operatorKind_o), value)
#define corto_operatorKind__optional_SetCond(cond, value) cond ? (corto_operatorKind*)corto_operatorKindAssign((corto_operatorKind*)corto_ptr_new(corto_operatorKind_o), value) : NULL
#define corto_operatorKindUnset(_this) _this ? corto_ptr_free(_this, corto_operatorKind_o), 0 : 0; _this = NULL;
#define corto_operatorKindAssign(_this, value) _corto_operatorKindAssign(_this, value)
#define corto_operatorKindSet(_this, value) _this = _this ? _this : (corto_operatorKind*)corto_ptr_new(corto_operatorKind_o); _corto_operatorKindAssign(_this, value)

/* /corto/vstore/ownership */
CORTO_EXPORT corto_ownership* _corto_ownershipCreate(corto_ownership value);
#define corto_ownershipCreate(value) _corto_ownershipCreate(value)
#define corto_ownershipCreate_auto(_id, value) corto_ownership* _id = corto_ownershipCreate(value); (void)_id
CORTO_EXPORT corto_ownership* _corto_ownershipCreateChild(corto_object _parent, const char *_id, corto_ownership value);
#define corto_ownershipCreateChild(_parent, _id, value) _corto_ownershipCreateChild(_parent, _id, value)
#define corto_ownershipCreateChild_auto(_parent, _id, value) corto_ownership* _id = corto_ownershipCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_ownershipUpdate(corto_ownership* _this, corto_ownership value);
#define corto_ownershipUpdate(_this, value) _corto_ownershipUpdate(corto_ownership(_this), value)

CORTO_EXPORT corto_ownership* _corto_ownershipDeclare(void);
#define corto_ownershipDeclare() _corto_ownershipDeclare()
#define corto_ownershipDeclare_auto(_id) corto_ownership* _id = corto_ownershipDeclare(); (void)_id
CORTO_EXPORT corto_ownership* _corto_ownershipDeclareChild(corto_object _parent, const char *_id);
#define corto_ownershipDeclareChild(_parent, _id) _corto_ownershipDeclareChild(_parent, _id)
#define corto_ownershipDeclareChild_auto(_parent, _id) corto_ownership* _id = corto_ownershipDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_ownershipDefine(corto_ownership* _this, corto_ownership value);
#define corto_ownershipDefine(_this, value) _corto_ownershipDefine(corto_ownership(_this), value)
CORTO_EXPORT corto_ownership* _corto_ownershipAssign(corto_ownership* _this, corto_ownership value);
#define corto_ownership__optional_NotSet NULL
#define corto_ownership__optional_Set(value) (corto_ownership*)corto_ownershipAssign((corto_ownership*)corto_ptr_new(corto_ownership_o), value)
#define corto_ownership__optional_SetCond(cond, value) cond ? (corto_ownership*)corto_ownershipAssign((corto_ownership*)corto_ptr_new(corto_ownership_o), value) : NULL
#define corto_ownershipUnset(_this) _this ? corto_ptr_free(_this, corto_ownership_o), 0 : 0; _this = NULL;
#define corto_ownershipAssign(_this, value) _corto_ownershipAssign(_this, value)
#define corto_ownershipSet(_this, value) _this = _this ? _this : (corto_ownership*)corto_ptr_new(corto_ownership_o); _corto_ownershipAssign(_this, value)

/* /corto/vstore/query */
CORTO_EXPORT corto_query* _corto_queryCreate(const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_queryCreate(select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_queryCreate(select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_queryCreate_auto(_id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) corto_query* _id = corto_queryCreate(select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd); (void)_id
CORTO_EXPORT corto_query* _corto_queryCreateChild(corto_object _parent, const char *_id, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_queryCreateChild(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_queryCreateChild(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_queryCreateChild_auto(_parent, _id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) corto_query* _id = corto_queryCreateChild(_parent, #_id, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd); (void)_id
CORTO_EXPORT corto_int16 _corto_queryUpdate(corto_query* _this, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_queryUpdate(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_queryUpdate(corto_query(_this), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)

CORTO_EXPORT corto_query* _corto_queryDeclare(void);
#define corto_queryDeclare() _corto_queryDeclare()
#define corto_queryDeclare_auto(_id) corto_query* _id = corto_queryDeclare(); (void)_id
CORTO_EXPORT corto_query* _corto_queryDeclareChild(corto_object _parent, const char *_id);
#define corto_queryDeclareChild(_parent, _id) _corto_queryDeclareChild(_parent, _id)
#define corto_queryDeclareChild_auto(_parent, _id) corto_query* _id = corto_queryDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_queryDefine(corto_query* _this, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_queryDefine(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_queryDefine(corto_query(_this), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
CORTO_EXPORT corto_query* _corto_queryAssign(corto_query* _this, const char * select, const char * from, const char * type, const char * member, const char * where, uint64_t offset, uint64_t limit, uint64_t soffset, uint64_t slimit, corto_frame* timeBegin, corto_frame* timeEnd);
#define corto_query__optional_NotSet NULL
#define corto_query__optional_Set(select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) (corto_query*)corto_queryAssign((corto_query*)corto_ptr_new(corto_query_o), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_query__optional_SetCond(cond, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) cond ? (corto_query*)corto_queryAssign((corto_query*)corto_ptr_new(corto_query_o), select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) : NULL
#define corto_queryUnset(_this) _this ? corto_ptr_free(_this, corto_query_o), 0 : 0; _this = NULL;
#define corto_queryAssign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _corto_queryAssign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)
#define corto_querySet(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd) _this = _this ? _this : (corto_query*)corto_ptr_new(corto_query_o); _corto_queryAssign(_this, select, from, type, member, where, offset, limit, soffset, slimit, timeBegin, timeEnd)

/* /corto/vstore/queuePolicy */
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicyCreate(uint32_t max);
#define corto_queuePolicyCreate(max) _corto_queuePolicyCreate(max)
#define corto_queuePolicyCreate_auto(_id, max) corto_queuePolicy* _id = corto_queuePolicyCreate(max); (void)_id
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicyCreateChild(corto_object _parent, const char *_id, uint32_t max);
#define corto_queuePolicyCreateChild(_parent, _id, max) _corto_queuePolicyCreateChild(_parent, _id, max)
#define corto_queuePolicyCreateChild_auto(_parent, _id, max) corto_queuePolicy* _id = corto_queuePolicyCreateChild(_parent, #_id, max); (void)_id
CORTO_EXPORT corto_int16 _corto_queuePolicyUpdate(corto_queuePolicy* _this, uint32_t max);
#define corto_queuePolicyUpdate(_this, max) _corto_queuePolicyUpdate(corto_queuePolicy(_this), max)

CORTO_EXPORT corto_queuePolicy* _corto_queuePolicyDeclare(void);
#define corto_queuePolicyDeclare() _corto_queuePolicyDeclare()
#define corto_queuePolicyDeclare_auto(_id) corto_queuePolicy* _id = corto_queuePolicyDeclare(); (void)_id
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicyDeclareChild(corto_object _parent, const char *_id);
#define corto_queuePolicyDeclareChild(_parent, _id) _corto_queuePolicyDeclareChild(_parent, _id)
#define corto_queuePolicyDeclareChild_auto(_parent, _id) corto_queuePolicy* _id = corto_queuePolicyDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_queuePolicyDefine(corto_queuePolicy* _this, uint32_t max);
#define corto_queuePolicyDefine(_this, max) _corto_queuePolicyDefine(corto_queuePolicy(_this), max)
CORTO_EXPORT corto_queuePolicy* _corto_queuePolicyAssign(corto_queuePolicy* _this, uint32_t max);
#define corto_queuePolicy__optional_NotSet NULL
#define corto_queuePolicy__optional_Set(max) (corto_queuePolicy*)corto_queuePolicyAssign((corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o), max)
#define corto_queuePolicy__optional_SetCond(cond, max) cond ? (corto_queuePolicy*)corto_queuePolicyAssign((corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o), max) : NULL
#define corto_queuePolicyUnset(_this) _this ? corto_ptr_free(_this, corto_queuePolicy_o), 0 : 0; _this = NULL;
#define corto_queuePolicyAssign(_this, max) _corto_queuePolicyAssign(_this, max)
#define corto_queuePolicySet(_this, max) _this = _this ? _this : (corto_queuePolicy*)corto_ptr_new(corto_queuePolicy_o); _corto_queuePolicyAssign(_this, max)

/* /corto/vstore/remote */
CORTO_EXPORT corto_remote _corto_remoteCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteCreate(returnType, returnsReference, _impl) _corto_remoteCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteCreate_auto(_id, returnType, returnsReference, _impl) corto_remote _id = corto_remoteCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_remote _corto_remoteCreateChild(corto_object _parent, const char *_id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_remoteCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_remote _id = corto_remoteCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_remoteUpdate(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteUpdate(_this, returnType, returnsReference, _impl) _corto_remoteUpdate(corto_remote(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_remote _corto_remoteDeclare(void);
#define corto_remoteDeclare() _corto_remoteDeclare()
#define corto_remoteDeclare_auto(_id) corto_remote _id = corto_remoteDeclare(); (void)_id
CORTO_EXPORT corto_remote _corto_remoteDeclareChild(corto_object _parent, const char *_id);
#define corto_remoteDeclareChild(_parent, _id) _corto_remoteDeclareChild(_parent, _id)
#define corto_remoteDeclareChild_auto(_parent, _id) corto_remote _id = corto_remoteDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_remoteDefine(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteDefine(_this, returnType, returnsReference, _impl) _corto_remoteDefine(corto_remote(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_remote _corto_remoteAssign(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remote__optional_NotSet NULL
#define corto_remote__optional_Set(returnType, returnsReference, _impl) (corto_remote*)corto_remoteAssign((corto_remote*)corto_ptr_new(corto_remote_o), returnType, returnsReference, _impl)
#define corto_remote__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? (corto_remote*)corto_remoteAssign((corto_remote*)corto_ptr_new(corto_remote_o), returnType, returnsReference, _impl) : NULL
#define corto_remoteUnset(_this) _this ? corto_ptr_free(_this, corto_remote_o), 0 : 0; _this = NULL;
#define corto_remoteAssign(_this, returnType, returnsReference, _impl) _corto_remoteAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_remote*)corto_ptr_new(corto_remote_o); _corto_remoteAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* /corto/vstore/result */
CORTO_EXPORT corto_result* _corto_resultCreate(const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_resultCreate(id, name, parent, type, value, flags) _corto_resultCreate(id, name, parent, type, value, flags)
#define corto_resultCreate_auto(_id, id, name, parent, type, value, flags) corto_result* _id = corto_resultCreate(id, name, parent, type, value, flags); (void)_id
CORTO_EXPORT corto_result* _corto_resultCreateChild(corto_object _parent, const char *_id, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_resultCreateChild(_parent, _id, id, name, parent, type, value, flags) _corto_resultCreateChild(_parent, _id, id, name, parent, type, value, flags)
#define corto_resultCreateChild_auto(_parent, _id, id, name, parent, type, value, flags) corto_result* _id = corto_resultCreateChild(_parent, #_id, id, name, parent, type, value, flags); (void)_id
CORTO_EXPORT corto_int16 _corto_resultUpdate(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_resultUpdate(_this, id, name, parent, type, value, flags) _corto_resultUpdate(corto_result(_this), id, name, parent, type, value, flags)

CORTO_EXPORT corto_result* _corto_resultDeclare(void);
#define corto_resultDeclare() _corto_resultDeclare()
#define corto_resultDeclare_auto(_id) corto_result* _id = corto_resultDeclare(); (void)_id
CORTO_EXPORT corto_result* _corto_resultDeclareChild(corto_object _parent, const char *_id);
#define corto_resultDeclareChild(_parent, _id) _corto_resultDeclareChild(_parent, _id)
#define corto_resultDeclareChild_auto(_parent, _id) corto_result* _id = corto_resultDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultDefine(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_resultDefine(_this, id, name, parent, type, value, flags) _corto_resultDefine(corto_result(_this), id, name, parent, type, value, flags)
CORTO_EXPORT corto_result* _corto_resultAssign(corto_result* _this, const char * id, const char * name, const char * parent, const char * type, uintptr_t value, corto_resultMask flags);
#define corto_result__optional_NotSet NULL
#define corto_result__optional_Set(id, name, parent, type, value, flags) (corto_result*)corto_resultAssign((corto_result*)corto_ptr_new(corto_result_o), id, name, parent, type, value, flags)
#define corto_result__optional_SetCond(cond, id, name, parent, type, value, flags) cond ? (corto_result*)corto_resultAssign((corto_result*)corto_ptr_new(corto_result_o), id, name, parent, type, value, flags) : NULL
#define corto_resultUnset(_this) _this ? corto_ptr_free(_this, corto_result_o), 0 : 0; _this = NULL;
#define corto_resultAssign(_this, id, name, parent, type, value, flags) _corto_resultAssign(_this, id, name, parent, type, value, flags)
#define corto_resultSet(_this, id, name, parent, type, value, flags) _this = _this ? _this : (corto_result*)corto_ptr_new(corto_result_o); _corto_resultAssign(_this, id, name, parent, type, value, flags)

/* /corto/vstore/resultIter */
CORTO_EXPORT corto_resultIter* _corto_resultIterCreate(void);
#define corto_resultIterCreate() _corto_resultIterCreate()
#define corto_resultIterCreate_auto(_id) corto_resultIter* _id = corto_resultIterCreate(); (void)_id
CORTO_EXPORT corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, const char *_id);
#define corto_resultIterCreateChild(_parent, _id) _corto_resultIterCreateChild(_parent, _id)
#define corto_resultIterCreateChild_auto(_parent, _id) corto_resultIter* _id = corto_resultIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultIterUpdate(corto_resultIter* _this);
#define corto_resultIterUpdate(_this) _corto_resultIterUpdate(corto_resultIter(_this))

CORTO_EXPORT corto_resultIter* _corto_resultIterDeclare(void);
#define corto_resultIterDeclare() _corto_resultIterDeclare()
#define corto_resultIterDeclare_auto(_id) corto_resultIter* _id = corto_resultIterDeclare(); (void)_id
CORTO_EXPORT corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, const char *_id);
#define corto_resultIterDeclareChild(_parent, _id) _corto_resultIterDeclareChild(_parent, _id)
#define corto_resultIterDeclareChild_auto(_parent, _id) corto_resultIter* _id = corto_resultIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultIterDefine(corto_resultIter* _this);
#define corto_resultIterDefine(_this) _corto_resultIterDefine(corto_resultIter(_this))
CORTO_EXPORT corto_resultIter* _corto_resultIterAssign(corto_resultIter* _this);
#define corto_resultIter__optional_NotSet NULL
#define corto_resultIter__optional_Set() (corto_resultIter*)corto_resultIterAssign((corto_resultIter*)corto_ptr_new(corto_resultIter_o))
#define corto_resultIter__optional_SetCond(cond) cond ? (corto_resultIter*)corto_resultIterAssign((corto_resultIter*)corto_ptr_new(corto_resultIter_o)) : NULL
#define corto_resultIterUnset(_this) _this ? corto_ptr_free(_this, corto_resultIter_o), 0 : 0; _this = NULL;
#define corto_resultIterAssign(_this) _corto_resultIterAssign(_this)
#define corto_resultIterSet(_this) _this = _this ? _this : (corto_resultIter*)corto_ptr_new(corto_resultIter_o); _corto_resultIterAssign(_this)

/* /corto/vstore/resultList */
CORTO_EXPORT corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements);
#define corto_resultListCreate(length, elements) _corto_resultListCreate(length, elements)
#define corto_resultListCreate_auto(_id, length, elements) corto_resultList* _id = corto_resultListCreate(length, elements); (void)_id
CORTO_EXPORT corto_resultList* _corto_resultListCreateChild(corto_object _parent, const char *_id, corto_uint32 length, corto_result* elements);
#define corto_resultListCreateChild(_parent, _id, length, elements) _corto_resultListCreateChild(_parent, _id, length, elements)
#define corto_resultListCreateChild_auto(_parent, _id, length, elements) corto_resultList* _id = corto_resultListCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_resultListUpdate(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListUpdate(_this, length, elements) _corto_resultListUpdate(corto_resultList(_this), length, elements)

CORTO_EXPORT corto_resultList* _corto_resultListDeclare(void);
#define corto_resultListDeclare() _corto_resultListDeclare()
#define corto_resultListDeclare_auto(_id) corto_resultList* _id = corto_resultListDeclare(); (void)_id
CORTO_EXPORT corto_resultList* _corto_resultListDeclareChild(corto_object _parent, const char *_id);
#define corto_resultListDeclareChild(_parent, _id) _corto_resultListDeclareChild(_parent, _id)
#define corto_resultListDeclareChild_auto(_parent, _id) corto_resultList* _id = corto_resultListDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultListDefine(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListDefine(_this, length, elements) _corto_resultListDefine(corto_resultList(_this), length, elements)
CORTO_EXPORT corto_resultList* _corto_resultListAssign(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultList__optional_NotSet NULL
#define corto_resultList__optional_Set(length, elements) (corto_resultList*)corto_resultListAssign((corto_resultList*)corto_ptr_new(corto_resultList_o), length, elements)
#define corto_resultList__optional_SetCond(cond, length, elements) cond ? (corto_resultList*)corto_resultListAssign((corto_resultList*)corto_ptr_new(corto_resultList_o), length, elements) : NULL
#define corto_resultListUnset(_this) _this ? corto_ptr_free(_this, corto_resultList_o), 0 : 0; _this = NULL;
#define corto_resultListAssign(_this, length, elements) _corto_resultListAssign(_this, length, elements)
#define corto_resultListSet(_this, length, elements) _this = _this ? _this : (corto_resultList*)corto_ptr_new(corto_resultList_o); _corto_resultListAssign(_this, length, elements)

/* /corto/vstore/resultMask */
CORTO_EXPORT corto_resultMask* _corto_resultMaskCreate(corto_resultMask value);
#define corto_resultMaskCreate(value) _corto_resultMaskCreate(value)
#define corto_resultMaskCreate_auto(_id, value) corto_resultMask* _id = corto_resultMaskCreate(value); (void)_id
CORTO_EXPORT corto_resultMask* _corto_resultMaskCreateChild(corto_object _parent, const char *_id, corto_resultMask value);
#define corto_resultMaskCreateChild(_parent, _id, value) _corto_resultMaskCreateChild(_parent, _id, value)
#define corto_resultMaskCreateChild_auto(_parent, _id, value) corto_resultMask* _id = corto_resultMaskCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_resultMaskUpdate(corto_resultMask* _this, corto_resultMask value);
#define corto_resultMaskUpdate(_this, value) _corto_resultMaskUpdate(corto_resultMask(_this), value)

CORTO_EXPORT corto_resultMask* _corto_resultMaskDeclare(void);
#define corto_resultMaskDeclare() _corto_resultMaskDeclare()
#define corto_resultMaskDeclare_auto(_id) corto_resultMask* _id = corto_resultMaskDeclare(); (void)_id
CORTO_EXPORT corto_resultMask* _corto_resultMaskDeclareChild(corto_object _parent, const char *_id);
#define corto_resultMaskDeclareChild(_parent, _id) _corto_resultMaskDeclareChild(_parent, _id)
#define corto_resultMaskDeclareChild_auto(_parent, _id) corto_resultMask* _id = corto_resultMaskDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultMaskDefine(corto_resultMask* _this, corto_resultMask value);
#define corto_resultMaskDefine(_this, value) _corto_resultMaskDefine(corto_resultMask(_this), value)
CORTO_EXPORT corto_resultMask* _corto_resultMaskAssign(corto_resultMask* _this, corto_resultMask value);
#define corto_resultMask__optional_NotSet NULL
#define corto_resultMask__optional_Set(value) (corto_resultMask*)corto_resultMaskAssign((corto_resultMask*)corto_ptr_new(corto_resultMask_o), value)
#define corto_resultMask__optional_SetCond(cond, value) cond ? (corto_resultMask*)corto_resultMaskAssign((corto_resultMask*)corto_ptr_new(corto_resultMask_o), value) : NULL
#define corto_resultMaskUnset(_this) _this ? corto_ptr_free(_this, corto_resultMask_o), 0 : 0; _this = NULL;
#define corto_resultMaskAssign(_this, value) _corto_resultMaskAssign(_this, value)
#define corto_resultMaskSet(_this, value) _this = _this ? _this : (corto_resultMask*)corto_ptr_new(corto_resultMask_o); _corto_resultMaskAssign(_this, value)

/* /corto/vstore/route */
CORTO_EXPORT corto_route _corto_routeCreate(const char * pattern, void(*_impl)(void));
#define corto_routeCreate(pattern, _impl) _corto_routeCreate(pattern, (void(*)(void))_impl)
#define corto_routeCreate_auto(_id, pattern, _impl) corto_route _id = corto_routeCreate(pattern, _impl); (void)_id
CORTO_EXPORT corto_route _corto_routeCreateChild(corto_object _parent, const char *_id, const char * pattern, void(*_impl)(void));
#define corto_routeCreateChild(_parent, _id, pattern, _impl) _corto_routeCreateChild(_parent, _id, pattern, (void(*)(void))_impl)
#define corto_routeCreateChild_auto(_parent, _id, pattern, _impl) corto_route _id = corto_routeCreateChild(_parent, #_id, pattern, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_routeUpdate(corto_route _this, const char * pattern, void(*_impl)(void));
#define corto_routeUpdate(_this, pattern, _impl) _corto_routeUpdate(corto_route(_this), pattern, (void(*)(void))_impl)

CORTO_EXPORT corto_route _corto_routeDeclare(void);
#define corto_routeDeclare() _corto_routeDeclare()
#define corto_routeDeclare_auto(_id) corto_route _id = corto_routeDeclare(); (void)_id
CORTO_EXPORT corto_route _corto_routeDeclareChild(corto_object _parent, const char *_id);
#define corto_routeDeclareChild(_parent, _id) _corto_routeDeclareChild(_parent, _id)
#define corto_routeDeclareChild_auto(_parent, _id) corto_route _id = corto_routeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routeDefine(corto_route _this, const char * pattern, void(*_impl)(void));
#define corto_routeDefine(_this, pattern, _impl) _corto_routeDefine(corto_route(_this), pattern, (void(*)(void))_impl)
CORTO_EXPORT corto_route _corto_routeAssign(corto_route _this, const char * pattern, void(*_impl)(void));
#define corto_route__optional_NotSet NULL
#define corto_route__optional_Set(pattern, _impl) (corto_route*)corto_routeAssign((corto_route*)corto_ptr_new(corto_route_o), pattern, _impl)
#define corto_route__optional_SetCond(cond, pattern, _impl) cond ? (corto_route*)corto_routeAssign((corto_route*)corto_ptr_new(corto_route_o), pattern, _impl) : NULL
#define corto_routeUnset(_this) _this ? corto_ptr_free(_this, corto_route_o), 0 : 0; _this = NULL;
#define corto_routeAssign(_this, pattern, _impl) _corto_routeAssign(_this, pattern, (void(*)(void))_impl)
#define corto_routeSet(_this, pattern, _impl) _this = _this ? _this : (corto_route*)corto_ptr_new(corto_route_o); _corto_routeAssign(_this, pattern, (void(*)(void))_impl)

/* /corto/vstore/router */
CORTO_EXPORT corto_router _corto_routerCreate(corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_routerCreate(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerCreate(corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerCreate_auto(_id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_router _id = corto_routerCreate(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator); (void)_id
CORTO_EXPORT corto_router _corto_routerCreateChild(corto_object _parent, const char *_id, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_routerCreateChild(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerCreateChild(_parent, _id, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerCreateChild_auto(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_router _id = corto_routerCreateChild(_parent, #_id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator); (void)_id
CORTO_EXPORT corto_int16 _corto_routerUpdate(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_routerUpdate(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerUpdate(corto_router(_this), corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)

CORTO_EXPORT corto_router _corto_routerDeclare(void);
#define corto_routerDeclare() _corto_routerDeclare()
#define corto_routerDeclare_auto(_id) corto_router _id = corto_routerDeclare(); (void)_id
CORTO_EXPORT corto_router _corto_routerDeclareChild(corto_object _parent, const char *_id);
#define corto_routerDeclareChild(_parent, _id) _corto_routerDeclareChild(_parent, _id)
#define corto_routerDeclareChild_auto(_parent, _id) corto_router _id = corto_routerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routerDefine(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_routerDefine(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerDefine(corto_router(_this), corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
CORTO_EXPORT corto_router _corto_routerAssign(corto_router _this, corto_type returnType, corto_type paramType, const char * paramName, corto_type routerDataType, const char * routerDataName, const char * elementSeparator);
#define corto_router__optional_NotSet NULL
#define corto_router__optional_Set(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) (corto_router*)corto_routerAssign((corto_router*)corto_ptr_new(corto_router_o), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator)
#define corto_router__optional_SetCond(cond, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) cond ? (corto_router*)corto_routerAssign((corto_router*)corto_ptr_new(corto_router_o), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) : NULL
#define corto_routerUnset(_this) _this ? corto_ptr_free(_this, corto_router_o), 0 : 0; _this = NULL;
#define corto_routerAssign(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerAssign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerSet(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _this = _this ? _this : (corto_router*)corto_ptr_new(corto_router_o); _corto_routerAssign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)

/* /corto/vstore/routerimpl */
CORTO_EXPORT corto_routerimpl _corto_routerimplCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplCreate(base, baseAccess, implements) _corto_routerimplCreate(corto_interface(base), baseAccess, implements)
#define corto_routerimplCreate_auto(_id, base, baseAccess, implements) corto_routerimpl _id = corto_routerimplCreate(base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_routerimpl _corto_routerimplCreateChild(corto_object _parent, const char *_id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplCreateChild(_parent, _id, base, baseAccess, implements) _corto_routerimplCreateChild(_parent, _id, corto_interface(base), baseAccess, implements)
#define corto_routerimplCreateChild_auto(_parent, _id, base, baseAccess, implements) corto_routerimpl _id = corto_routerimplCreateChild(_parent, #_id, base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_int16 _corto_routerimplUpdate(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplUpdate(_this, base, baseAccess, implements) _corto_routerimplUpdate(corto_routerimpl(_this), corto_interface(base), baseAccess, implements)

CORTO_EXPORT corto_routerimpl _corto_routerimplDeclare(void);
#define corto_routerimplDeclare() _corto_routerimplDeclare()
#define corto_routerimplDeclare_auto(_id) corto_routerimpl _id = corto_routerimplDeclare(); (void)_id
CORTO_EXPORT corto_routerimpl _corto_routerimplDeclareChild(corto_object _parent, const char *_id);
#define corto_routerimplDeclareChild(_parent, _id) _corto_routerimplDeclareChild(_parent, _id)
#define corto_routerimplDeclareChild_auto(_parent, _id) corto_routerimpl _id = corto_routerimplDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routerimplDefine(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplDefine(_this, base, baseAccess, implements) _corto_routerimplDefine(corto_routerimpl(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT corto_routerimpl _corto_routerimplAssign(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimpl__optional_NotSet NULL
#define corto_routerimpl__optional_Set(base, baseAccess, implements) (corto_routerimpl*)corto_routerimplAssign((corto_routerimpl*)corto_ptr_new(corto_routerimpl_o), base, baseAccess, implements)
#define corto_routerimpl__optional_SetCond(cond, base, baseAccess, implements) cond ? (corto_routerimpl*)corto_routerimplAssign((corto_routerimpl*)corto_ptr_new(corto_routerimpl_o), base, baseAccess, implements) : NULL
#define corto_routerimplUnset(_this) _this ? corto_ptr_free(_this, corto_routerimpl_o), 0 : 0; _this = NULL;
#define corto_routerimplAssign(_this, base, baseAccess, implements) _corto_routerimplAssign(_this, corto_interface(base), baseAccess, implements)
#define corto_routerimplSet(_this, base, baseAccess, implements) _this = _this ? _this : (corto_routerimpl*)corto_ptr_new(corto_routerimpl_o); _corto_routerimplAssign(_this, corto_interface(base), baseAccess, implements)

/* /corto/vstore/sample */
CORTO_EXPORT corto_sample* _corto_sampleCreate(corto_time* timestamp, uintptr_t value);
#define corto_sampleCreate(timestamp, value) _corto_sampleCreate(timestamp, value)
#define corto_sampleCreate_auto(_id, timestamp, value) corto_sample* _id = corto_sampleCreate(timestamp, value); (void)_id
CORTO_EXPORT corto_sample* _corto_sampleCreateChild(corto_object _parent, const char *_id, corto_time* timestamp, uintptr_t value);
#define corto_sampleCreateChild(_parent, _id, timestamp, value) _corto_sampleCreateChild(_parent, _id, timestamp, value)
#define corto_sampleCreateChild_auto(_parent, _id, timestamp, value) corto_sample* _id = corto_sampleCreateChild(_parent, #_id, timestamp, value); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleUpdate(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sampleUpdate(_this, timestamp, value) _corto_sampleUpdate(corto_sample(_this), timestamp, value)

CORTO_EXPORT corto_sample* _corto_sampleDeclare(void);
#define corto_sampleDeclare() _corto_sampleDeclare()
#define corto_sampleDeclare_auto(_id) corto_sample* _id = corto_sampleDeclare(); (void)_id
CORTO_EXPORT corto_sample* _corto_sampleDeclareChild(corto_object _parent, const char *_id);
#define corto_sampleDeclareChild(_parent, _id) _corto_sampleDeclareChild(_parent, _id)
#define corto_sampleDeclareChild_auto(_parent, _id) corto_sample* _id = corto_sampleDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleDefine(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sampleDefine(_this, timestamp, value) _corto_sampleDefine(corto_sample(_this), timestamp, value)
CORTO_EXPORT corto_sample* _corto_sampleAssign(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sample__optional_NotSet NULL
#define corto_sample__optional_Set(timestamp, value) (corto_sample*)corto_sampleAssign((corto_sample*)corto_ptr_new(corto_sample_o), timestamp, value)
#define corto_sample__optional_SetCond(cond, timestamp, value) cond ? (corto_sample*)corto_sampleAssign((corto_sample*)corto_ptr_new(corto_sample_o), timestamp, value) : NULL
#define corto_sampleUnset(_this) _this ? corto_ptr_free(_this, corto_sample_o), 0 : 0; _this = NULL;
#define corto_sampleAssign(_this, timestamp, value) _corto_sampleAssign(_this, timestamp, value)
#define corto_sampleSet(_this, timestamp, value) _this = _this ? _this : (corto_sample*)corto_ptr_new(corto_sample_o); _corto_sampleAssign(_this, timestamp, value)

/* /corto/vstore/sampleIter */
CORTO_EXPORT corto_sampleIter* _corto_sampleIterCreate(void);
#define corto_sampleIterCreate() _corto_sampleIterCreate()
#define corto_sampleIterCreate_auto(_id) corto_sampleIter* _id = corto_sampleIterCreate(); (void)_id
CORTO_EXPORT corto_sampleIter* _corto_sampleIterCreateChild(corto_object _parent, const char *_id);
#define corto_sampleIterCreateChild(_parent, _id) _corto_sampleIterCreateChild(_parent, _id)
#define corto_sampleIterCreateChild_auto(_parent, _id) corto_sampleIter* _id = corto_sampleIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleIterUpdate(corto_sampleIter* _this);
#define corto_sampleIterUpdate(_this) _corto_sampleIterUpdate(corto_sampleIter(_this))

CORTO_EXPORT corto_sampleIter* _corto_sampleIterDeclare(void);
#define corto_sampleIterDeclare() _corto_sampleIterDeclare()
#define corto_sampleIterDeclare_auto(_id) corto_sampleIter* _id = corto_sampleIterDeclare(); (void)_id
CORTO_EXPORT corto_sampleIter* _corto_sampleIterDeclareChild(corto_object _parent, const char *_id);
#define corto_sampleIterDeclareChild(_parent, _id) _corto_sampleIterDeclareChild(_parent, _id)
#define corto_sampleIterDeclareChild_auto(_parent, _id) corto_sampleIter* _id = corto_sampleIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleIterDefine(corto_sampleIter* _this);
#define corto_sampleIterDefine(_this) _corto_sampleIterDefine(corto_sampleIter(_this))
CORTO_EXPORT corto_sampleIter* _corto_sampleIterAssign(corto_sampleIter* _this);
#define corto_sampleIter__optional_NotSet NULL
#define corto_sampleIter__optional_Set() (corto_sampleIter*)corto_sampleIterAssign((corto_sampleIter*)corto_ptr_new(corto_sampleIter_o))
#define corto_sampleIter__optional_SetCond(cond) cond ? (corto_sampleIter*)corto_sampleIterAssign((corto_sampleIter*)corto_ptr_new(corto_sampleIter_o)) : NULL
#define corto_sampleIterUnset(_this) _this ? corto_ptr_free(_this, corto_sampleIter_o), 0 : 0; _this = NULL;
#define corto_sampleIterAssign(_this) _corto_sampleIterAssign(_this)
#define corto_sampleIterSet(_this) _this = _this ? _this : (corto_sampleIter*)corto_ptr_new(corto_sampleIter_o); _corto_sampleIterAssign(_this)

/* /corto/vstore/subscriber */
CORTO_EXPORT corto_subscriber _corto_subscriberCreate(corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriberCreate(query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriberCreate(query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
#define corto_subscriberCreate_auto(_id, query, contentType, instance, dispatcher, enabled, _impl) corto_subscriber _id = corto_subscriberCreate(query, contentType, instance, dispatcher, enabled, _impl); (void)_id
CORTO_EXPORT corto_subscriber _corto_subscriberCreateChild(corto_object _parent, const char *_id, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriberCreateChild(_parent, _id, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriberCreateChild(_parent, _id, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
#define corto_subscriberCreateChild_auto(_parent, _id, query, contentType, instance, dispatcher, enabled, _impl) corto_subscriber _id = corto_subscriberCreateChild(_parent, #_id, query, contentType, instance, dispatcher, enabled, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberUpdate(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriberUpdate(_this, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriberUpdate(corto_subscriber(_this), query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)

CORTO_EXPORT corto_subscriber _corto_subscriberDeclare(void);
#define corto_subscriberDeclare() _corto_subscriberDeclare()
#define corto_subscriberDeclare_auto(_id) corto_subscriber _id = corto_subscriberDeclare(); (void)_id
CORTO_EXPORT corto_subscriber _corto_subscriberDeclareChild(corto_object _parent, const char *_id);
#define corto_subscriberDeclareChild(_parent, _id) _corto_subscriberDeclareChild(_parent, _id)
#define corto_subscriberDeclareChild_auto(_parent, _id) corto_subscriber _id = corto_subscriberDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberDefine(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriberDefine(_this, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriberDefine(corto_subscriber(_this), query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_subscriber _corto_subscriberAssign(corto_subscriber _this, corto_query* query, const char * contentType, corto_object instance, corto_dispatcher dispatcher, bool enabled, void(*_impl)(void));
#define corto_subscriber__optional_NotSet NULL
#define corto_subscriber__optional_Set(query, contentType, instance, dispatcher, enabled, _impl) (corto_subscriber*)corto_subscriberAssign((corto_subscriber*)corto_ptr_new(corto_subscriber_o), query, contentType, instance, dispatcher, enabled, _impl)
#define corto_subscriber__optional_SetCond(cond, query, contentType, instance, dispatcher, enabled, _impl) cond ? (corto_subscriber*)corto_subscriberAssign((corto_subscriber*)corto_ptr_new(corto_subscriber_o), query, contentType, instance, dispatcher, enabled, _impl) : NULL
#define corto_subscriberUnset(_this) _this ? corto_ptr_free(_this, corto_subscriber_o), 0 : 0; _this = NULL;
#define corto_subscriberAssign(_this, query, contentType, instance, dispatcher, enabled, _impl) _corto_subscriberAssign(_this, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)
#define corto_subscriberSet(_this, query, contentType, instance, dispatcher, enabled, _impl) _this = _this ? _this : (corto_subscriber*)corto_ptr_new(corto_subscriber_o); _corto_subscriberAssign(_this, query, contentType, instance, corto_dispatcher(dispatcher), enabled, (void(*)(void))_impl)

/* /corto/vstore/subscriberEvent */
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventCreate(corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventCreate(subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventCreate(corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventCreate_auto(_id, subscriber, instance, source, event, data, contentTypeHandle) corto_subscriberEvent* _id = corto_subscriberEventCreate(subscriber, instance, source, event, data, contentTypeHandle); (void)_id
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventCreateChild(corto_object _parent, const char *_id, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventCreateChild(_parent, _id, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventCreateChild(_parent, _id, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventCreateChild_auto(_parent, _id, subscriber, instance, source, event, data, contentTypeHandle) corto_subscriberEvent* _id = corto_subscriberEventCreateChild(_parent, #_id, subscriber, instance, source, event, data, contentTypeHandle); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventUpdate(corto_subscriberEvent* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventUpdate(_this, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventUpdate(corto_subscriberEvent(_this), corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)

CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventDeclare(void);
#define corto_subscriberEventDeclare() _corto_subscriberEventDeclare()
#define corto_subscriberEventDeclare_auto(_id) corto_subscriberEvent* _id = corto_subscriberEventDeclare(); (void)_id
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventDeclareChild(corto_object _parent, const char *_id);
#define corto_subscriberEventDeclareChild(_parent, _id) _corto_subscriberEventDeclareChild(_parent, _id)
#define corto_subscriberEventDeclareChild_auto(_parent, _id) corto_subscriberEvent* _id = corto_subscriberEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventDefine(corto_subscriberEvent* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventDefine(_this, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventDefine(corto_subscriberEvent(_this), corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventAssign(corto_subscriberEvent* _this, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEvent__optional_NotSet NULL
#define corto_subscriberEvent__optional_Set(subscriber, instance, source, event, data, contentTypeHandle) (corto_subscriberEvent*)corto_subscriberEventAssign((corto_subscriberEvent*)corto_ptr_new(corto_subscriberEvent_o), subscriber, instance, source, event, data, contentTypeHandle)
#define corto_subscriberEvent__optional_SetCond(cond, subscriber, instance, source, event, data, contentTypeHandle) cond ? (corto_subscriberEvent*)corto_subscriberEventAssign((corto_subscriberEvent*)corto_ptr_new(corto_subscriberEvent_o), subscriber, instance, source, event, data, contentTypeHandle) : NULL
#define corto_subscriberEventUnset(_this) _this ? corto_ptr_free(_this, corto_subscriberEvent_o), 0 : 0; _this = NULL;
#define corto_subscriberEventAssign(_this, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventAssign(_this, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventSet(_this, subscriber, instance, source, event, data, contentTypeHandle) _this = _this ? _this : (corto_subscriberEvent*)corto_ptr_new(corto_subscriberEvent_o); _corto_subscriberEventAssign(_this, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)

/* /corto/vstore/subscriberEventIter */
CORTO_EXPORT corto_subscriberEventIter* _corto_subscriberEventIterCreate(void);
#define corto_subscriberEventIterCreate() _corto_subscriberEventIterCreate()
#define corto_subscriberEventIterCreate_auto(_id) corto_subscriberEventIter* _id = corto_subscriberEventIterCreate(); (void)_id
CORTO_EXPORT corto_subscriberEventIter* _corto_subscriberEventIterCreateChild(corto_object _parent, const char *_id);
#define corto_subscriberEventIterCreateChild(_parent, _id) _corto_subscriberEventIterCreateChild(_parent, _id)
#define corto_subscriberEventIterCreateChild_auto(_parent, _id) corto_subscriberEventIter* _id = corto_subscriberEventIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventIterUpdate(corto_subscriberEventIter* _this);
#define corto_subscriberEventIterUpdate(_this) _corto_subscriberEventIterUpdate(corto_subscriberEventIter(_this))

CORTO_EXPORT corto_subscriberEventIter* _corto_subscriberEventIterDeclare(void);
#define corto_subscriberEventIterDeclare() _corto_subscriberEventIterDeclare()
#define corto_subscriberEventIterDeclare_auto(_id) corto_subscriberEventIter* _id = corto_subscriberEventIterDeclare(); (void)_id
CORTO_EXPORT corto_subscriberEventIter* _corto_subscriberEventIterDeclareChild(corto_object _parent, const char *_id);
#define corto_subscriberEventIterDeclareChild(_parent, _id) _corto_subscriberEventIterDeclareChild(_parent, _id)
#define corto_subscriberEventIterDeclareChild_auto(_parent, _id) corto_subscriberEventIter* _id = corto_subscriberEventIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventIterDefine(corto_subscriberEventIter* _this);
#define corto_subscriberEventIterDefine(_this) _corto_subscriberEventIterDefine(corto_subscriberEventIter(_this))
CORTO_EXPORT corto_subscriberEventIter* _corto_subscriberEventIterAssign(corto_subscriberEventIter* _this);
#define corto_subscriberEventIter__optional_NotSet NULL
#define corto_subscriberEventIter__optional_Set() (corto_subscriberEventIter*)corto_subscriberEventIterAssign((corto_subscriberEventIter*)corto_ptr_new(corto_subscriberEventIter_o))
#define corto_subscriberEventIter__optional_SetCond(cond) cond ? (corto_subscriberEventIter*)corto_subscriberEventIterAssign((corto_subscriberEventIter*)corto_ptr_new(corto_subscriberEventIter_o)) : NULL
#define corto_subscriberEventIterUnset(_this) _this ? corto_ptr_free(_this, corto_subscriberEventIter_o), 0 : 0; _this = NULL;
#define corto_subscriberEventIterAssign(_this) _corto_subscriberEventIterAssign(_this)
#define corto_subscriberEventIterSet(_this) _this = _this ? _this : (corto_subscriberEventIter*)corto_ptr_new(corto_subscriberEventIter_o); _corto_subscriberEventIterAssign(_this)

/* /corto/vstore/time */
CORTO_EXPORT corto_time* _corto_timeCreate(int32_t sec, uint32_t nanosec);
#define corto_timeCreate(sec, nanosec) _corto_timeCreate(sec, nanosec)
#define corto_timeCreate_auto(_id, sec, nanosec) corto_time* _id = corto_timeCreate(sec, nanosec); (void)_id
CORTO_EXPORT corto_time* _corto_timeCreateChild(corto_object _parent, const char *_id, int32_t sec, uint32_t nanosec);
#define corto_timeCreateChild(_parent, _id, sec, nanosec) _corto_timeCreateChild(_parent, _id, sec, nanosec)
#define corto_timeCreateChild_auto(_parent, _id, sec, nanosec) corto_time* _id = corto_timeCreateChild(_parent, #_id, sec, nanosec); (void)_id
CORTO_EXPORT corto_int16 _corto_timeUpdate(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_timeUpdate(_this, sec, nanosec) _corto_timeUpdate(corto_time(_this), sec, nanosec)

CORTO_EXPORT corto_time* _corto_timeDeclare(void);
#define corto_timeDeclare() _corto_timeDeclare()
#define corto_timeDeclare_auto(_id) corto_time* _id = corto_timeDeclare(); (void)_id
CORTO_EXPORT corto_time* _corto_timeDeclareChild(corto_object _parent, const char *_id);
#define corto_timeDeclareChild(_parent, _id) _corto_timeDeclareChild(_parent, _id)
#define corto_timeDeclareChild_auto(_parent, _id) corto_time* _id = corto_timeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_timeDefine(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_timeDefine(_this, sec, nanosec) _corto_timeDefine(corto_time(_this), sec, nanosec)
CORTO_EXPORT corto_time* _corto_timeAssign(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_time__optional_NotSet NULL
#define corto_time__optional_Set(sec, nanosec) (corto_time*)corto_timeAssign((corto_time*)corto_ptr_new(corto_time_o), sec, nanosec)
#define corto_time__optional_SetCond(cond, sec, nanosec) cond ? (corto_time*)corto_timeAssign((corto_time*)corto_ptr_new(corto_time_o), sec, nanosec) : NULL
#define corto_timeUnset(_this) _this ? corto_ptr_free(_this, corto_time_o), 0 : 0; _this = NULL;
#define corto_timeAssign(_this, sec, nanosec) _corto_timeAssign(_this, sec, nanosec)
#define corto_timeSet(_this, sec, nanosec) _this = _this ? _this : (corto_time*)corto_ptr_new(corto_time_o); _corto_timeAssign(_this, sec, nanosec)


/* /corto/vstore/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListInsertAlloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListInsert(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListAppendAlloc(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListAppend(corto_mountSubscriptionList list, corto_mountSubscription* element);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListTakeFirst(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListLast(corto_mountSubscriptionList list);
CORTO_EXPORT corto_mountSubscription* corto_mountSubscriptionListGet(corto_mountSubscriptionList list, corto_uint32 index);
CORTO_EXPORT void corto_mountSubscriptionListClear(corto_mountSubscriptionList list);

/* /corto/vstore/resultList */
CORTO_EXPORT corto_result* corto_resultListInsertAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListInsert(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListAppendAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListAppend(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListTakeFirst(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListLast(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index);
CORTO_EXPORT void corto_resultListClear(corto_resultList list);
#define corto_objectIterForeach(iter, elem) \
    corto_object elem;\
    while(corto_iter_hasNext(&iter) ? elem = (corto_object)corto_iter_next(&iter), TRUE : FALSE)

#define corto_resultIterForeach(iter, elem) \
    corto_result elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_result*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)

#define corto_sampleIterForeach(iter, elem) \
    corto_sample elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_sample*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)

#define corto_subscriberEventIterForeach(iter, elem) \
    corto_subscriberEvent elem;\
    while(corto_iter_hasNext(&iter) ? elem = *(corto_subscriberEvent*)(corto_word)corto_iter_next(&iter), TRUE : FALSE)


#ifdef __cplusplus
}
#endif
#endif

