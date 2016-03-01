/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE__API_H
#define CORTO_CORE__API_H

#include "corto/corto.h"
#include "corto/_interface.h"
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/core/attr */
CORTO_EXPORT corto_attr* _corto_attrCreate(corto_attr value);
#define corto_attrCreate(value) _corto_attrCreate(value)
#define corto_attrCreate_auto(_name, value) corto_attr* _name = corto_attrCreate(value); (void)_name
CORTO_EXPORT corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _name, corto_attr value);
#define corto_attrCreateChild(_parent, _name, value) _corto_attrCreateChild(_parent, _name, value)
#define corto_attrCreateChild_auto(_parent, _name, value) corto_attr* _name = corto_attrCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value);
#define corto_attrUpdate(_this, value) _corto_attrUpdate(_this, value)

CORTO_EXPORT corto_attr* _corto_attrDeclare(void);
#define corto_attrDeclare() _corto_attrDeclare()
#define corto_attrDeclare_auto(_name) corto_attr* _name = corto_attrDeclare(); (void)_name
CORTO_EXPORT corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _name);
#define corto_attrDeclareChild(_parent, _name) _corto_attrDeclareChild(_parent, _name)
#define corto_attrDeclareChild_auto(_parent, _name) corto_attr* _name = corto_attrDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_attrDefine(corto_attr* _this, corto_attr value);
#define corto_attrDefine(_this, value) _corto_attrDefine(_this, value)
CORTO_EXPORT void _corto_attrSet(corto_attr* _this, corto_attr value);
#define corto_attrSet(_this, value) _corto_attrSet(_this, value)
CORTO_EXPORT corto_string _corto_attrStr(corto_attr value);
#define corto_attrStr(value) _corto_attrStr(value)
CORTO_EXPORT corto_attr* corto_attrFromStr(corto_attr* value, corto_string str);
CORTO_EXPORT corto_int16 corto_attrCompare(corto_attr dst, corto_attr src);

CORTO_EXPORT corto_int16 _corto_attrInit(corto_attr* value);
#define corto_attrInit(value) _corto_attrInit(value)
CORTO_EXPORT corto_int16 _corto_attrDeinit(corto_attr* value);
#define corto_attrDeinit(value) _corto_attrDeinit(value)

/* /corto/core/dispatcher */
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreate(void);
#define corto_dispatcherCreate() _corto_dispatcherCreate()
#define corto_dispatcherCreate_auto(_name) corto_dispatcher _name = corto_dispatcherCreate(); (void)_name
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _name);
#define corto_dispatcherCreateChild(_parent, _name) _corto_dispatcherCreateChild(_parent, _name)
#define corto_dispatcherCreateChild_auto(_parent, _name) corto_dispatcher _name = corto_dispatcherCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this);
#define corto_dispatcherUpdate(_this) _corto_dispatcherUpdate(corto_dispatcher(_this))

CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclare(void);
#define corto_dispatcherDeclare() _corto_dispatcherDeclare()
#define corto_dispatcherDeclare_auto(_name) corto_dispatcher _name = corto_dispatcherDeclare(); (void)_name
CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _name);
#define corto_dispatcherDeclareChild(_parent, _name) _corto_dispatcherDeclareChild(_parent, _name)
#define corto_dispatcherDeclareChild_auto(_parent, _name) corto_dispatcher _name = corto_dispatcherDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_dispatcherDefine(corto_dispatcher _this);
#define corto_dispatcherDefine(_this) _corto_dispatcherDefine(corto_dispatcher(_this))
CORTO_EXPORT void _corto_dispatcherSet(corto_dispatcher _this);
#define corto_dispatcherSet(_this) _corto_dispatcherSet(corto_dispatcher(_this))
CORTO_EXPORT corto_string _corto_dispatcherStr(corto_dispatcher value);
#define corto_dispatcherStr(value) _corto_dispatcherStr(corto_dispatcher(value))
CORTO_EXPORT corto_dispatcher corto_dispatcherFromStr(corto_dispatcher value, corto_string str);
CORTO_EXPORT corto_int16 _corto_dispatcherCompare(corto_dispatcher dst, corto_dispatcher src);
#define corto_dispatcherCompare(dst, src) _corto_dispatcherCompare(corto_dispatcher(dst), corto_dispatcher(src))

/* /corto/core/equalityKind */
CORTO_EXPORT corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value);
#define corto_equalityKindCreate(value) _corto_equalityKindCreate(value)
#define corto_equalityKindCreate_auto(_name, value) corto_equalityKind* _name = corto_equalityKindCreate(value); (void)_name
CORTO_EXPORT corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _name, corto_equalityKind value);
#define corto_equalityKindCreateChild(_parent, _name, value) _corto_equalityKindCreateChild(_parent, _name, value)
#define corto_equalityKindCreateChild_auto(_parent, _name, value) corto_equalityKind* _name = corto_equalityKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindUpdate(_this, value) _corto_equalityKindUpdate(_this, value)

CORTO_EXPORT corto_equalityKind* _corto_equalityKindDeclare(void);
#define corto_equalityKindDeclare() _corto_equalityKindDeclare()
#define corto_equalityKindDeclare_auto(_name) corto_equalityKind* _name = corto_equalityKindDeclare(); (void)_name
CORTO_EXPORT corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_equalityKindDeclareChild(_parent, _name) _corto_equalityKindDeclareChild(_parent, _name)
#define corto_equalityKindDeclareChild_auto(_parent, _name) corto_equalityKind* _name = corto_equalityKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindDefine(_this, value) _corto_equalityKindDefine(_this, value)
CORTO_EXPORT void _corto_equalityKindSet(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindSet(_this, value) _corto_equalityKindSet(_this, value)
CORTO_EXPORT corto_string _corto_equalityKindStr(corto_equalityKind value);
#define corto_equalityKindStr(value) _corto_equalityKindStr(value)
CORTO_EXPORT corto_equalityKind* corto_equalityKindFromStr(corto_equalityKind* value, corto_string str);
CORTO_EXPORT corto_int16 corto_equalityKindCompare(corto_equalityKind dst, corto_equalityKind src);

CORTO_EXPORT corto_int16 _corto_equalityKindInit(corto_equalityKind* value);
#define corto_equalityKindInit(value) _corto_equalityKindInit(value)
CORTO_EXPORT corto_int16 _corto_equalityKindDeinit(corto_equalityKind* value);
#define corto_equalityKindDeinit(value) _corto_equalityKindDeinit(value)

/* /corto/core/event */
CORTO_EXPORT corto_event _corto_eventCreate(corto_uint16 kind);
#define corto_eventCreate(kind) _corto_eventCreate(kind)
#define corto_eventCreate_auto(_name, kind) corto_event _name = corto_eventCreate(kind); (void)_name
CORTO_EXPORT corto_event _corto_eventCreateChild(corto_object _parent, corto_string _name, corto_uint16 kind);
#define corto_eventCreateChild(_parent, _name, kind) _corto_eventCreateChild(_parent, _name, kind)
#define corto_eventCreateChild_auto(_parent, _name, kind) corto_event _name = corto_eventCreateChild(_parent, #_name, kind); (void)_name
CORTO_EXPORT corto_int16 _corto_eventUpdate(corto_event _this, corto_uint16 kind);
#define corto_eventUpdate(_this, kind) _corto_eventUpdate(corto_event(_this), kind)

CORTO_EXPORT corto_event _corto_eventDeclare(void);
#define corto_eventDeclare() _corto_eventDeclare()
#define corto_eventDeclare_auto(_name) corto_event _name = corto_eventDeclare(); (void)_name
CORTO_EXPORT corto_event _corto_eventDeclareChild(corto_object _parent, corto_string _name);
#define corto_eventDeclareChild(_parent, _name) _corto_eventDeclareChild(_parent, _name)
#define corto_eventDeclareChild_auto(_parent, _name) corto_event _name = corto_eventDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_eventDefine(corto_event _this, corto_uint16 kind);
#define corto_eventDefine(_this, kind) _corto_eventDefine(corto_event(_this), kind)
CORTO_EXPORT void _corto_eventSet(corto_event _this, corto_uint16 kind);
#define corto_eventSet(_this, kind) _corto_eventSet(corto_event(_this), kind)
CORTO_EXPORT corto_string _corto_eventStr(corto_event value);
#define corto_eventStr(value) _corto_eventStr(corto_event(value))
CORTO_EXPORT corto_event corto_eventFromStr(corto_event value, corto_string str);
CORTO_EXPORT corto_int16 _corto_eventCompare(corto_event dst, corto_event src);
#define corto_eventCompare(dst, src) _corto_eventCompare(corto_event(dst), corto_event(src))

/* /corto/core/eventMask */
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreate(corto_eventMask value);
#define corto_eventMaskCreate(value) _corto_eventMaskCreate(value)
#define corto_eventMaskCreate_auto(_name, value) corto_eventMask* _name = corto_eventMaskCreate(value); (void)_name
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _name, corto_eventMask value);
#define corto_eventMaskCreateChild(_parent, _name, value) _corto_eventMaskCreateChild(_parent, _name, value)
#define corto_eventMaskCreateChild_auto(_parent, _name, value) corto_eventMask* _name = corto_eventMaskCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskUpdate(_this, value) _corto_eventMaskUpdate(_this, value)

CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclare(void);
#define corto_eventMaskDeclare() _corto_eventMaskDeclare()
#define corto_eventMaskDeclare_auto(_name) corto_eventMask* _name = corto_eventMaskDeclare(); (void)_name
CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _name);
#define corto_eventMaskDeclareChild(_parent, _name) _corto_eventMaskDeclareChild(_parent, _name)
#define corto_eventMaskDeclareChild_auto(_parent, _name) corto_eventMask* _name = corto_eventMaskDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskDefine(_this, value) _corto_eventMaskDefine(_this, value)
CORTO_EXPORT void _corto_eventMaskSet(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskSet(_this, value) _corto_eventMaskSet(_this, value)
CORTO_EXPORT corto_string _corto_eventMaskStr(corto_eventMask value);
#define corto_eventMaskStr(value) _corto_eventMaskStr(value)
CORTO_EXPORT corto_eventMask* corto_eventMaskFromStr(corto_eventMask* value, corto_string str);
CORTO_EXPORT corto_int16 corto_eventMaskCompare(corto_eventMask dst, corto_eventMask src);

CORTO_EXPORT corto_int16 _corto_eventMaskInit(corto_eventMask* value);
#define corto_eventMaskInit(value) _corto_eventMaskInit(value)
CORTO_EXPORT corto_int16 _corto_eventMaskDeinit(corto_eventMask* value);
#define corto_eventMaskDeinit(value) _corto_eventMaskDeinit(value)

/* /corto/core/invokeEvent */
CORTO_EXPORT corto_invokeEvent _corto_invokeEventCreate(corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventCreate(replicator, instance, function, args) _corto_invokeEventCreate(corto_replicator(replicator), instance, corto_function(function), args)
#define corto_invokeEventCreate_auto(_name, replicator, instance, function, args) corto_invokeEvent _name = corto_invokeEventCreate(replicator, instance, function, args); (void)_name
CORTO_EXPORT corto_invokeEvent _corto_invokeEventCreateChild(corto_object _parent, corto_string _name, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventCreateChild(_parent, _name, replicator, instance, function, args) _corto_invokeEventCreateChild(_parent, _name, corto_replicator(replicator), instance, corto_function(function), args)
#define corto_invokeEventCreateChild_auto(_parent, _name, replicator, instance, function, args) corto_invokeEvent _name = corto_invokeEventCreateChild(_parent, #_name, replicator, instance, function, args); (void)_name
CORTO_EXPORT corto_int16 _corto_invokeEventUpdate(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventUpdate(_this, replicator, instance, function, args) _corto_invokeEventUpdate(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)

CORTO_EXPORT corto_invokeEvent _corto_invokeEventDeclare(void);
#define corto_invokeEventDeclare() _corto_invokeEventDeclare()
#define corto_invokeEventDeclare_auto(_name) corto_invokeEvent _name = corto_invokeEventDeclare(); (void)_name
CORTO_EXPORT corto_invokeEvent _corto_invokeEventDeclareChild(corto_object _parent, corto_string _name);
#define corto_invokeEventDeclareChild(_parent, _name) _corto_invokeEventDeclareChild(_parent, _name)
#define corto_invokeEventDeclareChild_auto(_parent, _name) corto_invokeEvent _name = corto_invokeEventDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_invokeEventDefine(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventDefine(_this, replicator, instance, function, args) _corto_invokeEventDefine(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)
CORTO_EXPORT void _corto_invokeEventSet(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventSet(_this, replicator, instance, function, args) _corto_invokeEventSet(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)
CORTO_EXPORT corto_string _corto_invokeEventStr(corto_invokeEvent value);
#define corto_invokeEventStr(value) _corto_invokeEventStr(corto_invokeEvent(value))
CORTO_EXPORT corto_invokeEvent corto_invokeEventFromStr(corto_invokeEvent value, corto_string str);
CORTO_EXPORT corto_int16 _corto_invokeEventCompare(corto_invokeEvent dst, corto_invokeEvent src);
#define corto_invokeEventCompare(dst, src) _corto_invokeEventCompare(corto_invokeEvent(dst), corto_invokeEvent(src))

/* /corto/core/notifyAction */
CORTO_EXPORT corto_notifyAction* _corto_notifyActionCreate(corto_object instance, corto_function procedure);
#define corto_notifyActionCreate(instance, procedure) _corto_notifyActionCreate(instance, corto_function(procedure))
#define corto_notifyActionCreate_auto(_name, instance, procedure) corto_notifyAction* _name = corto_notifyActionCreate(instance, procedure); (void)_name
CORTO_EXPORT corto_notifyAction* _corto_notifyActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_notifyActionCreateChild(_parent, _name, instance, procedure) _corto_notifyActionCreateChild(_parent, _name, instance, corto_function(procedure))
#define corto_notifyActionCreateChild_auto(_parent, _name, instance, procedure) corto_notifyAction* _name = corto_notifyActionCreateChild(_parent, #_name, instance, procedure); (void)_name
CORTO_EXPORT corto_int16 _corto_notifyActionUpdate(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionUpdate(_this, instance, procedure) _corto_notifyActionUpdate(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_notifyAction* _corto_notifyActionDeclare(void);
#define corto_notifyActionDeclare() _corto_notifyActionDeclare()
#define corto_notifyActionDeclare_auto(_name) corto_notifyAction* _name = corto_notifyActionDeclare(); (void)_name
CORTO_EXPORT corto_notifyAction* _corto_notifyActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_notifyActionDeclareChild(_parent, _name) _corto_notifyActionDeclareChild(_parent, _name)
#define corto_notifyActionDeclareChild_auto(_parent, _name) corto_notifyAction* _name = corto_notifyActionDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_notifyActionDefine(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionDefine(_this, instance, procedure) _corto_notifyActionDefine(_this, instance, corto_function(procedure))
CORTO_EXPORT void _corto_notifyActionSet(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionSet(_this, instance, procedure) _corto_notifyActionSet(_this, instance, corto_function(procedure))
CORTO_EXPORT corto_string _corto_notifyActionStr(corto_notifyAction* value);
#define corto_notifyActionStr(value) _corto_notifyActionStr(value)
CORTO_EXPORT corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str);
CORTO_EXPORT corto_int16 corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src);

CORTO_EXPORT corto_int16 _corto_notifyActionInit(corto_notifyAction* value);
#define corto_notifyActionInit(value) _corto_notifyActionInit(value)
CORTO_EXPORT corto_int16 _corto_notifyActionDeinit(corto_notifyAction* value);
#define corto_notifyActionDeinit(value) _corto_notifyActionDeinit(value)

corto_int16 corto_notifyActionCall(corto_notifyAction *_delegate, corto_object observable);
#define corto_notifyActionInitC_auto(d, callback) corto_notifyAction d; corto_notifyActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_notifyActionInitC(corto_notifyAction *d, corto_void ___ (*callback)(corto_object));
#define corto_notifyActionInitCInstance_auto(d, instance, callback)corto_notifyAction d; corto_notifyActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_notifyActionInitCInstance(corto_notifyAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_object));
/* /corto/core/observableEvent */
CORTO_EXPORT corto_observableEvent _corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread);
#define corto_observableEventCreate(observer, me, source, observable, mask, thread) _corto_observableEventCreate(corto_observer(observer), me, source, observable, mask, thread)
#define corto_observableEventCreate_auto(_name, observer, me, source, observable, mask, thread) corto_observableEvent _name = corto_observableEventCreate(observer, me, source, observable, mask, thread); (void)_name
CORTO_EXPORT corto_observableEvent _corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread);
#define corto_observableEventCreateChild(_parent, _name, observer, me, source, observable, mask, thread) _corto_observableEventCreateChild(_parent, _name, corto_observer(observer), me, source, observable, mask, thread)
#define corto_observableEventCreateChild_auto(_parent, _name, observer, me, source, observable, mask, thread) corto_observableEvent _name = corto_observableEventCreateChild(_parent, #_name, observer, me, source, observable, mask, thread); (void)_name
CORTO_EXPORT corto_int16 _corto_observableEventUpdate(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread);
#define corto_observableEventUpdate(_this, observer, me, source, observable, mask, thread) _corto_observableEventUpdate(corto_observableEvent(_this), corto_observer(observer), me, source, observable, mask, thread)

CORTO_EXPORT corto_observableEvent _corto_observableEventDeclare(void);
#define corto_observableEventDeclare() _corto_observableEventDeclare()
#define corto_observableEventDeclare_auto(_name) corto_observableEvent _name = corto_observableEventDeclare(); (void)_name
CORTO_EXPORT corto_observableEvent _corto_observableEventDeclareChild(corto_object _parent, corto_string _name);
#define corto_observableEventDeclareChild(_parent, _name) _corto_observableEventDeclareChild(_parent, _name)
#define corto_observableEventDeclareChild_auto(_parent, _name) corto_observableEvent _name = corto_observableEventDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_observableEventDefine(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread);
#define corto_observableEventDefine(_this, observer, me, source, observable, mask, thread) _corto_observableEventDefine(corto_observableEvent(_this), corto_observer(observer), me, source, observable, mask, thread)
CORTO_EXPORT void _corto_observableEventSet(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread);
#define corto_observableEventSet(_this, observer, me, source, observable, mask, thread) _corto_observableEventSet(corto_observableEvent(_this), corto_observer(observer), me, source, observable, mask, thread)
CORTO_EXPORT corto_string _corto_observableEventStr(corto_observableEvent value);
#define corto_observableEventStr(value) _corto_observableEventStr(corto_observableEvent(value))
CORTO_EXPORT corto_observableEvent corto_observableEventFromStr(corto_observableEvent value, corto_string str);
CORTO_EXPORT corto_int16 _corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src);
#define corto_observableEventCompare(dst, src) _corto_observableEventCompare(corto_observableEvent(dst), corto_observableEvent(src))

/* /corto/core/observer */
CORTO_EXPORT corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerCreate(mask, observable, _impl) _corto_observerCreate(mask, observable, _impl)
#define corto_observerCreate_auto(_name, mask, observable, _impl) corto_observer _name = corto_observerCreate(mask, observable, _impl); (void)_name
CORTO_EXPORT corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _name, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerCreateChild(_parent, _name, mask, observable, _impl) _corto_observerCreateChild(_parent, _name, mask, observable, _impl)
#define corto_observerCreateChild_auto(_parent, _name, mask, observable, _impl) corto_observer _name = corto_observerCreateChild(_parent, #_name, mask, observable, _impl); (void)_name
CORTO_EXPORT corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerUpdate(_this, mask, observable, _impl) _corto_observerUpdate(corto_observer(_this), mask, observable, _impl)

CORTO_EXPORT corto_observer _corto_observerDeclare(void);
#define corto_observerDeclare() _corto_observerDeclare()
#define corto_observerDeclare_auto(_name) corto_observer _name = corto_observerDeclare(); (void)_name
CORTO_EXPORT corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _name);
#define corto_observerDeclareChild(_parent, _name) _corto_observerDeclareChild(_parent, _name)
#define corto_observerDeclareChild_auto(_parent, _name) corto_observer _name = corto_observerDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerDefine(_this, mask, observable, _impl) _corto_observerDefine(corto_observer(_this), mask, observable, _impl)
CORTO_EXPORT void _corto_observerSet(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerSet(_this, mask, observable, _impl) _corto_observerSet(corto_observer(_this), mask, observable, _impl)
CORTO_EXPORT corto_string _corto_observerStr(corto_observer value);
#define corto_observerStr(value) _corto_observerStr(corto_observer(value))
CORTO_EXPORT corto_observer corto_observerFromStr(corto_observer value, corto_string str);
CORTO_EXPORT corto_int16 _corto_observerCompare(corto_observer dst, corto_observer src);
#define corto_observerCompare(dst, src) _corto_observerCompare(corto_observer(dst), corto_observer(src))

/* /corto/core/observerseq */
CORTO_EXPORT corto_observerseq* _corto_observerseqCreate(corto_uint32 length, corto_observer* elements);
#define corto_observerseqCreate(length, elements) _corto_observerseqCreate(length, elements)
#define corto_observerseqCreate_auto(_name, length, elements) corto_observerseq* _name = corto_observerseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_observerseq* _corto_observerseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_observer* elements);
#define corto_observerseqCreateChild(_parent, _name, length, elements) _corto_observerseqCreateChild(_parent, _name, length, elements)
#define corto_observerseqCreateChild_auto(_parent, _name, length, elements) corto_observerseq* _name = corto_observerseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_observerseqUpdate(corto_observerseq* _this, corto_uint32 length, corto_observer* elements);
#define corto_observerseqUpdate(_this, length, elements) _corto_observerseqUpdate(_this, length, elements)

CORTO_EXPORT corto_observerseq* _corto_observerseqDeclare(void);
#define corto_observerseqDeclare() _corto_observerseqDeclare()
#define corto_observerseqDeclare_auto(_name) corto_observerseq* _name = corto_observerseqDeclare(); (void)_name
CORTO_EXPORT corto_observerseq* _corto_observerseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_observerseqDeclareChild(_parent, _name) _corto_observerseqDeclareChild(_parent, _name)
#define corto_observerseqDeclareChild_auto(_parent, _name) corto_observerseq* _name = corto_observerseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_observerseqDefine(corto_observerseq* _this, corto_uint32 length, corto_observer* elements);
#define corto_observerseqDefine(_this, length, elements) _corto_observerseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_observerseqSet(corto_observerseq* _this, corto_uint32 length, corto_observer* elements);
#define corto_observerseqSet(_this, length, elements) _corto_observerseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_observerseqStr(corto_observerseq value);
#define corto_observerseqStr(value) _corto_observerseqStr(value)
CORTO_EXPORT corto_observerseq* corto_observerseqFromStr(corto_observerseq* value, corto_string str);
CORTO_EXPORT corto_int16 corto_observerseqCompare(corto_observerseq dst, corto_observerseq src);

CORTO_EXPORT corto_int16 _corto_observerseqInit(corto_observerseq* value);
#define corto_observerseqInit(value) _corto_observerseqInit(value)
CORTO_EXPORT corto_int16 _corto_observerseqDeinit(corto_observerseq* value);
#define corto_observerseqDeinit(value) _corto_observerseqDeinit(value)

/* /corto/core/operatorKind */
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value);
#define corto_operatorKindCreate(value) _corto_operatorKindCreate(value)
#define corto_operatorKindCreate_auto(_name, value) corto_operatorKind* _name = corto_operatorKindCreate(value); (void)_name
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _name, corto_operatorKind value);
#define corto_operatorKindCreateChild(_parent, _name, value) _corto_operatorKindCreateChild(_parent, _name, value)
#define corto_operatorKindCreateChild_auto(_parent, _name, value) corto_operatorKind* _name = corto_operatorKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindUpdate(_this, value) _corto_operatorKindUpdate(_this, value)

CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclare(void);
#define corto_operatorKindDeclare() _corto_operatorKindDeclare()
#define corto_operatorKindDeclare_auto(_name) corto_operatorKind* _name = corto_operatorKindDeclare(); (void)_name
CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_operatorKindDeclareChild(_parent, _name) _corto_operatorKindDeclareChild(_parent, _name)
#define corto_operatorKindDeclareChild_auto(_parent, _name) corto_operatorKind* _name = corto_operatorKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindDefine(_this, value) _corto_operatorKindDefine(_this, value)
CORTO_EXPORT void _corto_operatorKindSet(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindSet(_this, value) _corto_operatorKindSet(_this, value)
CORTO_EXPORT corto_string _corto_operatorKindStr(corto_operatorKind value);
#define corto_operatorKindStr(value) _corto_operatorKindStr(value)
CORTO_EXPORT corto_operatorKind* corto_operatorKindFromStr(corto_operatorKind* value, corto_string str);
CORTO_EXPORT corto_int16 corto_operatorKindCompare(corto_operatorKind dst, corto_operatorKind src);

CORTO_EXPORT corto_int16 _corto_operatorKindInit(corto_operatorKind* value);
#define corto_operatorKindInit(value) _corto_operatorKindInit(value)
CORTO_EXPORT corto_int16 _corto_operatorKindDeinit(corto_operatorKind* value);
#define corto_operatorKindDeinit(value) _corto_operatorKindDeinit(value)

/* /corto/core/package */
CORTO_EXPORT corto_package _corto_packageCreate(corto_string url);
#define corto_packageCreate(url) _corto_packageCreate(url)
#define corto_packageCreate_auto(_name, url) corto_package _name = corto_packageCreate(url); (void)_name
CORTO_EXPORT corto_package _corto_packageCreateChild(corto_object _parent, corto_string _name, corto_string url);
#define corto_packageCreateChild(_parent, _name, url) _corto_packageCreateChild(_parent, _name, url)
#define corto_packageCreateChild_auto(_parent, _name, url) corto_package _name = corto_packageCreateChild(_parent, #_name, url); (void)_name
CORTO_EXPORT corto_int16 _corto_packageUpdate(corto_package _this, corto_string url);
#define corto_packageUpdate(_this, url) _corto_packageUpdate(corto_package(_this), url)

CORTO_EXPORT corto_package _corto_packageDeclare(void);
#define corto_packageDeclare() _corto_packageDeclare()
#define corto_packageDeclare_auto(_name) corto_package _name = corto_packageDeclare(); (void)_name
CORTO_EXPORT corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _name);
#define corto_packageDeclareChild(_parent, _name) _corto_packageDeclareChild(_parent, _name)
#define corto_packageDeclareChild_auto(_parent, _name) corto_package _name = corto_packageDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_packageDefine(corto_package _this, corto_string url);
#define corto_packageDefine(_this, url) _corto_packageDefine(corto_package(_this), url)
CORTO_EXPORT void _corto_packageSet(corto_package _this, corto_string url);
#define corto_packageSet(_this, url) _corto_packageSet(corto_package(_this), url)
CORTO_EXPORT corto_string _corto_packageStr(corto_package value);
#define corto_packageStr(value) _corto_packageStr(corto_package(value))
CORTO_EXPORT corto_package corto_packageFromStr(corto_package value, corto_string str);
CORTO_EXPORT corto_int16 _corto_packageCompare(corto_package dst, corto_package src);
#define corto_packageCompare(dst, src) _corto_packageCompare(corto_package(dst), corto_package(src))

/* /corto/core/query */
CORTO_EXPORT corto_query _corto_queryCreate(corto_object from, corto_eventMask mask);
#define corto_queryCreate(from, mask) _corto_queryCreate(from, mask)
#define corto_queryCreate_auto(_name, from, mask) corto_query _name = corto_queryCreate(from, mask); (void)_name
CORTO_EXPORT corto_query _corto_queryCreateChild(corto_object _parent, corto_string _name, corto_object from, corto_eventMask mask);
#define corto_queryCreateChild(_parent, _name, from, mask) _corto_queryCreateChild(_parent, _name, from, mask)
#define corto_queryCreateChild_auto(_parent, _name, from, mask) corto_query _name = corto_queryCreateChild(_parent, #_name, from, mask); (void)_name
CORTO_EXPORT corto_int16 _corto_queryUpdate(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_queryUpdate(_this, from, mask) _corto_queryUpdate(corto_query(_this), from, mask)

CORTO_EXPORT corto_query _corto_queryDeclare(void);
#define corto_queryDeclare() _corto_queryDeclare()
#define corto_queryDeclare_auto(_name) corto_query _name = corto_queryDeclare(); (void)_name
CORTO_EXPORT corto_query _corto_queryDeclareChild(corto_object _parent, corto_string _name);
#define corto_queryDeclareChild(_parent, _name) _corto_queryDeclareChild(_parent, _name)
#define corto_queryDeclareChild_auto(_parent, _name) corto_query _name = corto_queryDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_queryDefine(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_queryDefine(_this, from, mask) _corto_queryDefine(corto_query(_this), from, mask)
CORTO_EXPORT void _corto_querySet(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_querySet(_this, from, mask) _corto_querySet(corto_query(_this), from, mask)
CORTO_EXPORT corto_string _corto_queryStr(corto_query value);
#define corto_queryStr(value) _corto_queryStr(corto_query(value))
CORTO_EXPORT corto_query corto_queryFromStr(corto_query value, corto_string str);
CORTO_EXPORT corto_int16 _corto_queryCompare(corto_query dst, corto_query src);
#define corto_queryCompare(dst, src) _corto_queryCompare(corto_query(dst), corto_query(src))

/* /corto/core/replicator */
CORTO_EXPORT corto_replicator _corto_replicatorCreate(corto_object mount, corto_query query, corto_string contentType);
#define corto_replicatorCreate(mount, query, contentType) _corto_replicatorCreate(mount, corto_query(query), contentType)
#define corto_replicatorCreate_auto(_name, mount, query, contentType) corto_replicator _name = corto_replicatorCreate(mount, query, contentType); (void)_name
CORTO_EXPORT corto_replicator _corto_replicatorCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_query query, corto_string contentType);
#define corto_replicatorCreateChild(_parent, _name, mount, query, contentType) _corto_replicatorCreateChild(_parent, _name, mount, corto_query(query), contentType)
#define corto_replicatorCreateChild_auto(_parent, _name, mount, query, contentType) corto_replicator _name = corto_replicatorCreateChild(_parent, #_name, mount, query, contentType); (void)_name
CORTO_EXPORT corto_int16 _corto_replicatorUpdate(corto_replicator _this, corto_object mount, corto_query query, corto_string contentType);
#define corto_replicatorUpdate(_this, mount, query, contentType) _corto_replicatorUpdate(corto_replicator(_this), mount, corto_query(query), contentType)

CORTO_EXPORT corto_replicator _corto_replicatorDeclare(void);
#define corto_replicatorDeclare() _corto_replicatorDeclare()
#define corto_replicatorDeclare_auto(_name) corto_replicator _name = corto_replicatorDeclare(); (void)_name
CORTO_EXPORT corto_replicator _corto_replicatorDeclareChild(corto_object _parent, corto_string _name);
#define corto_replicatorDeclareChild(_parent, _name) _corto_replicatorDeclareChild(_parent, _name)
#define corto_replicatorDeclareChild_auto(_parent, _name) corto_replicator _name = corto_replicatorDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_replicatorDefine(corto_replicator _this, corto_object mount, corto_query query, corto_string contentType);
#define corto_replicatorDefine(_this, mount, query, contentType) _corto_replicatorDefine(corto_replicator(_this), mount, corto_query(query), contentType)
CORTO_EXPORT void _corto_replicatorSet(corto_replicator _this, corto_object mount, corto_query query, corto_string contentType);
#define corto_replicatorSet(_this, mount, query, contentType) _corto_replicatorSet(corto_replicator(_this), mount, corto_query(query), contentType)
CORTO_EXPORT corto_string _corto_replicatorStr(corto_replicator value);
#define corto_replicatorStr(value) _corto_replicatorStr(corto_replicator(value))
CORTO_EXPORT corto_replicator corto_replicatorFromStr(corto_replicator value, corto_string str);
CORTO_EXPORT corto_int16 _corto_replicatorCompare(corto_replicator dst, corto_replicator src);
#define corto_replicatorCompare(dst, src) _corto_replicatorCompare(corto_replicator(dst), corto_replicator(src))

/* /corto/core/result */
CORTO_EXPORT corto_result* _corto_resultCreate(corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value);
#define corto_resultCreate(id, name, parent, type, value) _corto_resultCreate(id, name, parent, type, value)
#define corto_resultCreate_auto(_name, id, name, parent, type, value) corto_result* _name = corto_resultCreate(id, name, parent, type, value); (void)_name
CORTO_EXPORT corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _name, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value);
#define corto_resultCreateChild(_parent, _name, id, name, parent, type, value) _corto_resultCreateChild(_parent, _name, id, name, parent, type, value)
#define corto_resultCreateChild_auto(_parent, _name, id, name, parent, type, value) corto_result* _name = corto_resultCreateChild(_parent, #_name, id, name, parent, type, value); (void)_name
CORTO_EXPORT corto_int16 _corto_resultUpdate(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value);
#define corto_resultUpdate(_this, id, name, parent, type, value) _corto_resultUpdate(_this, id, name, parent, type, value)

CORTO_EXPORT corto_result* _corto_resultDeclare(void);
#define corto_resultDeclare() _corto_resultDeclare()
#define corto_resultDeclare_auto(_name) corto_result* _name = corto_resultDeclare(); (void)_name
CORTO_EXPORT corto_result* _corto_resultDeclareChild(corto_object _parent, corto_string _name);
#define corto_resultDeclareChild(_parent, _name) _corto_resultDeclareChild(_parent, _name)
#define corto_resultDeclareChild_auto(_parent, _name) corto_result* _name = corto_resultDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_resultDefine(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value);
#define corto_resultDefine(_this, id, name, parent, type, value) _corto_resultDefine(_this, id, name, parent, type, value)
CORTO_EXPORT void _corto_resultSet(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value);
#define corto_resultSet(_this, id, name, parent, type, value) _corto_resultSet(_this, id, name, parent, type, value)
CORTO_EXPORT corto_string _corto_resultStr(corto_result* value);
#define corto_resultStr(value) _corto_resultStr(value)
CORTO_EXPORT corto_result* corto_resultFromStr(corto_result* value, corto_string str);
CORTO_EXPORT corto_int16 corto_resultCompare(corto_result* dst, corto_result* src);

CORTO_EXPORT corto_int16 _corto_resultInit(corto_result* value);
#define corto_resultInit(value) _corto_resultInit(value)
CORTO_EXPORT corto_int16 _corto_resultDeinit(corto_result* value);
#define corto_resultDeinit(value) _corto_resultDeinit(value)

/* /corto/core/resultIter */
CORTO_EXPORT corto_resultIter* _corto_resultIterCreate(void);
#define corto_resultIterCreate() _corto_resultIterCreate()
#define corto_resultIterCreate_auto(_name) corto_resultIter* _name = corto_resultIterCreate(); (void)_name
CORTO_EXPORT corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _name);
#define corto_resultIterCreateChild(_parent, _name) _corto_resultIterCreateChild(_parent, _name)
#define corto_resultIterCreateChild_auto(_parent, _name) corto_resultIter* _name = corto_resultIterCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_resultIterUpdate(corto_resultIter* _this);
#define corto_resultIterUpdate(_this) _corto_resultIterUpdate(_this)

CORTO_EXPORT corto_resultIter* _corto_resultIterDeclare(void);
#define corto_resultIterDeclare() _corto_resultIterDeclare()
#define corto_resultIterDeclare_auto(_name) corto_resultIter* _name = corto_resultIterDeclare(); (void)_name
CORTO_EXPORT corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, corto_string _name);
#define corto_resultIterDeclareChild(_parent, _name) _corto_resultIterDeclareChild(_parent, _name)
#define corto_resultIterDeclareChild_auto(_parent, _name) corto_resultIter* _name = corto_resultIterDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_resultIterDefine(corto_resultIter* _this);
#define corto_resultIterDefine(_this) _corto_resultIterDefine(_this)
CORTO_EXPORT void _corto_resultIterSet(corto_resultIter* _this);
#define corto_resultIterSet(_this) _corto_resultIterSet(_this)
CORTO_EXPORT corto_string _corto_resultIterStr(corto_resultIter value);
#define corto_resultIterStr(value) _corto_resultIterStr(value)
CORTO_EXPORT corto_resultIter* corto_resultIterFromStr(corto_resultIter* value, corto_string str);
CORTO_EXPORT corto_int16 corto_resultIterCompare(corto_resultIter dst, corto_resultIter src);

CORTO_EXPORT corto_int16 _corto_resultIterInit(corto_resultIter* value);
#define corto_resultIterInit(value) _corto_resultIterInit(value)
CORTO_EXPORT corto_int16 _corto_resultIterDeinit(corto_resultIter* value);
#define corto_resultIterDeinit(value) _corto_resultIterDeinit(value)

/* /corto/core/resultList */
CORTO_EXPORT corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements);
#define corto_resultListCreate(length, elements) _corto_resultListCreate(length, elements)
#define corto_resultListCreate_auto(_name, length, elements) corto_resultList* _name = corto_resultListCreate(length, elements); (void)_name
CORTO_EXPORT corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_result* elements);
#define corto_resultListCreateChild(_parent, _name, length, elements) _corto_resultListCreateChild(_parent, _name, length, elements)
#define corto_resultListCreateChild_auto(_parent, _name, length, elements) corto_resultList* _name = corto_resultListCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_resultListUpdate(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListUpdate(_this, length, elements) _corto_resultListUpdate(_this, length, elements)

CORTO_EXPORT corto_resultList* _corto_resultListDeclare(void);
#define corto_resultListDeclare() _corto_resultListDeclare()
#define corto_resultListDeclare_auto(_name) corto_resultList* _name = corto_resultListDeclare(); (void)_name
CORTO_EXPORT corto_resultList* _corto_resultListDeclareChild(corto_object _parent, corto_string _name);
#define corto_resultListDeclareChild(_parent, _name) _corto_resultListDeclareChild(_parent, _name)
#define corto_resultListDeclareChild_auto(_parent, _name) corto_resultList* _name = corto_resultListDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_resultListDefine(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListDefine(_this, length, elements) _corto_resultListDefine(_this, length, elements)
CORTO_EXPORT void _corto_resultListSet(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListSet(_this, length, elements) _corto_resultListSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_resultListStr(corto_resultList value);
#define corto_resultListStr(value) _corto_resultListStr(value)
CORTO_EXPORT corto_resultList* corto_resultListFromStr(corto_resultList* value, corto_string str);
CORTO_EXPORT corto_int16 corto_resultListCompare(corto_resultList dst, corto_resultList src);

CORTO_EXPORT corto_int16 _corto_resultListInit(corto_resultList* value);
#define corto_resultListInit(value) _corto_resultListInit(value)
CORTO_EXPORT corto_int16 _corto_resultListDeinit(corto_resultList* value);
#define corto_resultListDeinit(value) _corto_resultListDeinit(value)

/* /corto/core/time */
CORTO_EXPORT corto_time* _corto_timeCreate(corto_int32 sec, corto_int32 nanosec);
#define corto_timeCreate(sec, nanosec) _corto_timeCreate(sec, nanosec)
#define corto_timeCreate_auto(_name, sec, nanosec) corto_time* _name = corto_timeCreate(sec, nanosec); (void)_name
CORTO_EXPORT corto_time* _corto_timeCreateChild(corto_object _parent, corto_string _name, corto_int32 sec, corto_int32 nanosec);
#define corto_timeCreateChild(_parent, _name, sec, nanosec) _corto_timeCreateChild(_parent, _name, sec, nanosec)
#define corto_timeCreateChild_auto(_parent, _name, sec, nanosec) corto_time* _name = corto_timeCreateChild(_parent, #_name, sec, nanosec); (void)_name
CORTO_EXPORT corto_int16 _corto_timeUpdate(corto_time* _this, corto_int32 sec, corto_int32 nanosec);
#define corto_timeUpdate(_this, sec, nanosec) _corto_timeUpdate(_this, sec, nanosec)

CORTO_EXPORT corto_time* _corto_timeDeclare(void);
#define corto_timeDeclare() _corto_timeDeclare()
#define corto_timeDeclare_auto(_name) corto_time* _name = corto_timeDeclare(); (void)_name
CORTO_EXPORT corto_time* _corto_timeDeclareChild(corto_object _parent, corto_string _name);
#define corto_timeDeclareChild(_parent, _name) _corto_timeDeclareChild(_parent, _name)
#define corto_timeDeclareChild_auto(_parent, _name) corto_time* _name = corto_timeDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_timeDefine(corto_time* _this, corto_int32 sec, corto_int32 nanosec);
#define corto_timeDefine(_this, sec, nanosec) _corto_timeDefine(_this, sec, nanosec)
CORTO_EXPORT void _corto_timeSet(corto_time* _this, corto_int32 sec, corto_int32 nanosec);
#define corto_timeSet(_this, sec, nanosec) _corto_timeSet(_this, sec, nanosec)
CORTO_EXPORT corto_string _corto_timeStr(corto_time* value);
#define corto_timeStr(value) _corto_timeStr(value)
CORTO_EXPORT corto_time* corto_timeFromStr(corto_time* value, corto_string str);
CORTO_EXPORT corto_int16 corto_timeCompare(corto_time* dst, corto_time* src);

CORTO_EXPORT corto_int16 _corto_timeInit(corto_time* value);
#define corto_timeInit(value) _corto_timeInit(value)
CORTO_EXPORT corto_int16 _corto_timeDeinit(corto_time* value);
#define corto_timeDeinit(value) _corto_timeDeinit(value)


/* /corto/core/observerseq */
#define corto_observerseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_observer elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_observer* corto_observerseqAppend(corto_observerseq *seq, corto_observer element);
CORTO_EXPORT corto_observer* corto_observerseqAppendAlloc(corto_observerseq *seq);
CORTO_EXPORT void corto_observerseqSize(corto_observerseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_observerseqClear(corto_observerseq *seq);

/* /corto/core/resultList */
#define corto_resultListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_result *elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_EXPORT corto_result* corto_resultListInsertAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListInsert(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListAppendAlloc(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListAppend(corto_resultList list, corto_result* element);
CORTO_EXPORT corto_result* corto_resultListTakeFirst(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListLast(corto_resultList list);
CORTO_EXPORT void corto_resultListClear(corto_resultList list);
CORTO_EXPORT corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index);
CORTO_EXPORT corto_uint32 corto_resultListSize(corto_resultList list);
#define corto_resultIterForeach(iter, elem) \
    corto_result elem;\
    while(corto_iterHasNext(&iter) ? elem = *(corto_result*)(corto_word)corto_iterNext(&iter), TRUE : FALSE)


#ifdef __cplusplus
}
#endif
#endif

