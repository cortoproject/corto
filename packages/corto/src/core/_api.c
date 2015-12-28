/* _api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include "corto/core/core.h"
corto_attr* _corto_attrCreate(corto_attr value) {
    corto_attr* this;
    this = corto_declare(corto_attr_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _name, corto_attr value) {
    corto_attr* this;
    this = corto_declareChild(_parent, _name, corto_attr_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_attrUpdate(corto_attr* this, corto_attr value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_attr* _corto_attrDeclare(void) {
    corto_attr* this;
    this = corto_declare(corto_attr_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _name) {
    corto_attr* this;
    this = corto_declareChild(_parent, _name, corto_attr_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_attrDefine(corto_attr* this, corto_attr value) {
    *this = value;
    return corto_define(this);
}

void _corto_attrSet(corto_attr* this, corto_attr value) {
    *this = value;
}

corto_string _corto_attrStr(corto_attr value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_attr_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_attr* corto_attrFromStr(corto_attr* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_attr_o), str);
    return value;
}

corto_int16 _corto_attrCopy(corto_attr* *dst, corto_attr* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_attr_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_attr_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_attrCompare(corto_attr* dst, corto_attr* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_attr_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_attr_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_attrInit(corto_attr* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_attr_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_attr_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_attrDeinit(corto_attr* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_attr_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_dispatcher _corto_dispatcherCreate(void) {
    corto_dispatcher this;
    this = corto_declare(corto_dispatcher_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _name) {
    corto_dispatcher this;
    this = corto_declareChild(_parent, _name, corto_dispatcher_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_dispatcherUpdate(corto_dispatcher this) {
    if (!corto_updateBegin(this)) {
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_dispatcher _corto_dispatcherDeclare(void) {
    corto_dispatcher this;
    this = corto_declare(corto_dispatcher_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _name) {
    corto_dispatcher this;
    this = corto_declareChild(_parent, _name, corto_dispatcher_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_dispatcherDefine(corto_dispatcher this) {
    return corto_define(this);
}

void _corto_dispatcherSet(corto_dispatcher this) {
    CORTO_UNUSED(this);
}

corto_string _corto_dispatcherStr(corto_dispatcher value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_dispatcher_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_dispatcher corto_dispatcherFromStr(corto_dispatcher value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_dispatcher_o), str);
    return value;
}

corto_int16 _corto_dispatcherCopy(corto_dispatcher *dst, corto_dispatcher src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_dispatcherCompare(corto_dispatcher dst, corto_dispatcher src) {
    return corto_compare(dst, src);
}

corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value) {
    corto_equalityKind* this;
    this = corto_declare(corto_equalityKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _name, corto_equalityKind value) {
    corto_equalityKind* this;
    this = corto_declareChild(_parent, _name, corto_equalityKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_equalityKindUpdate(corto_equalityKind* this, corto_equalityKind value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_equalityKind* _corto_equalityKindDeclare(void) {
    corto_equalityKind* this;
    this = corto_declare(corto_equalityKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_equalityKind* this;
    this = corto_declareChild(_parent, _name, corto_equalityKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_equalityKindDefine(corto_equalityKind* this, corto_equalityKind value) {
    *this = value;
    return corto_define(this);
}

void _corto_equalityKindSet(corto_equalityKind* this, corto_equalityKind value) {
    *this = value;
}

corto_string _corto_equalityKindStr(corto_equalityKind value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_equalityKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_equalityKind* corto_equalityKindFromStr(corto_equalityKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_equalityKind_o), str);
    return value;
}

corto_int16 _corto_equalityKindCopy(corto_equalityKind* *dst, corto_equalityKind* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_equalityKind_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_equalityKind_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_equalityKindCompare(corto_equalityKind* dst, corto_equalityKind* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_equalityKind_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_equalityKind_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_equalityKindInit(corto_equalityKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_equalityKind_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_equalityKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_equalityKindDeinit(corto_equalityKind* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_equalityKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_event _corto_eventCreate(corto_uint16 kind) {
    corto_event this;
    this = corto_declare(corto_event_o);
    if (!this) {
        return NULL;
    }
    this->kind = kind;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_event _corto_eventCreateChild(corto_object _parent, corto_string _name, corto_uint16 kind) {
    corto_event this;
    this = corto_declareChild(_parent, _name, corto_event_o);
    if (!this) {
        return NULL;
    }
    this->kind = kind;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_eventUpdate(corto_event this, corto_uint16 kind) {
    if (!corto_updateBegin(this)) {
        this->kind = kind;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_event _corto_eventDeclare(void) {
    corto_event this;
    this = corto_declare(corto_event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_event _corto_eventDeclareChild(corto_object _parent, corto_string _name) {
    corto_event this;
    this = corto_declareChild(_parent, _name, corto_event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_eventDefine(corto_event this, corto_uint16 kind) {
    this->kind = kind;
    return corto_define(this);
}

void _corto_eventSet(corto_event this, corto_uint16 kind) {
    this->kind = kind;
}

corto_string _corto_eventStr(corto_event value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_event_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_event corto_eventFromStr(corto_event value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_event_o), str);
    return value;
}

corto_int16 _corto_eventCopy(corto_event *dst, corto_event src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_eventCompare(corto_event dst, corto_event src) {
    return corto_compare(dst, src);
}

corto_eventMask* _corto_eventMaskCreate(corto_eventMask value) {
    corto_eventMask* this;
    this = corto_declare(corto_eventMask_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _name, corto_eventMask value) {
    corto_eventMask* this;
    this = corto_declareChild(_parent, _name, corto_eventMask_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_eventMaskUpdate(corto_eventMask* this, corto_eventMask value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_eventMask* _corto_eventMaskDeclare(void) {
    corto_eventMask* this;
    this = corto_declare(corto_eventMask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _name) {
    corto_eventMask* this;
    this = corto_declareChild(_parent, _name, corto_eventMask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_eventMaskDefine(corto_eventMask* this, corto_eventMask value) {
    *this = value;
    return corto_define(this);
}

void _corto_eventMaskSet(corto_eventMask* this, corto_eventMask value) {
    *this = value;
}

corto_string _corto_eventMaskStr(corto_eventMask value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_eventMask_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_eventMask* corto_eventMaskFromStr(corto_eventMask* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_eventMask_o), str);
    return value;
}

corto_int16 _corto_eventMaskCopy(corto_eventMask* *dst, corto_eventMask* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_eventMask_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_eventMask_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_eventMaskCompare(corto_eventMask* dst, corto_eventMask* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_eventMask_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_eventMask_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_eventMaskInit(corto_eventMask* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_eventMask_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_eventMask_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_eventMaskDeinit(corto_eventMask* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_eventMask_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_invokeEvent _corto_invokeEventCreate(corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    corto_invokeEvent this;
    this = corto_declare(corto_invokeEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->replicator, corto_replicator(replicator));
    corto_setref(&this->instance, instance);
    corto_setref(&this->function, corto_function(function));
    this->args = args;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_invokeEvent _corto_invokeEventCreateChild(corto_object _parent, corto_string _name, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    corto_invokeEvent this;
    this = corto_declareChild(_parent, _name, corto_invokeEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->replicator, corto_replicator(replicator));
    corto_setref(&this->instance, instance);
    corto_setref(&this->function, corto_function(function));
    this->args = args;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_invokeEventUpdate(corto_invokeEvent this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    if (!corto_updateBegin(this)) {
        corto_setref(&this->replicator, corto_replicator(replicator));
        corto_setref(&this->instance, instance);
        corto_setref(&this->function, corto_function(function));
        this->args = args;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_invokeEvent _corto_invokeEventDeclare(void) {
    corto_invokeEvent this;
    this = corto_declare(corto_invokeEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_invokeEvent _corto_invokeEventDeclareChild(corto_object _parent, corto_string _name) {
    corto_invokeEvent this;
    this = corto_declareChild(_parent, _name, corto_invokeEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_invokeEventDefine(corto_invokeEvent this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    corto_setref(&this->replicator, corto_replicator(replicator));
    corto_setref(&this->instance, instance);
    corto_setref(&this->function, corto_function(function));
    this->args = args;
    return corto_define(this);
}

void _corto_invokeEventSet(corto_invokeEvent this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    corto_setref(&this->replicator, corto_replicator(replicator));
    corto_setref(&this->instance, instance);
    corto_setref(&this->function, corto_function(function));
    this->args = args;
}

corto_string _corto_invokeEventStr(corto_invokeEvent value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_invokeEvent_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_invokeEvent corto_invokeEventFromStr(corto_invokeEvent value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_invokeEvent_o), str);
    return value;
}

corto_int16 _corto_invokeEventCopy(corto_invokeEvent *dst, corto_invokeEvent src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_invokeEventCompare(corto_invokeEvent dst, corto_invokeEvent src) {
    return corto_compare(dst, src);
}

corto_notifyAction* _corto_notifyActionCreate(corto_object instance, corto_function procedure) {
    corto_notifyAction* this;
    this = corto_declare(corto_notifyAction_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, corto_function(procedure));
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_notifyAction* _corto_notifyActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_notifyAction* this;
    this = corto_declareChild(_parent, _name, corto_notifyAction_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, corto_function(procedure));
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_notifyActionUpdate(corto_notifyAction* this, corto_object instance, corto_function procedure) {
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_delegatedata*)this)->instance, instance);
        corto_setref(&((corto_delegatedata*)this)->procedure, corto_function(procedure));
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_notifyAction* _corto_notifyActionDeclare(void) {
    corto_notifyAction* this;
    this = corto_declare(corto_notifyAction_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_notifyAction* _corto_notifyActionDeclareChild(corto_object _parent, corto_string _name) {
    corto_notifyAction* this;
    this = corto_declareChild(_parent, _name, corto_notifyAction_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_notifyActionDefine(corto_notifyAction* this, corto_object instance, corto_function procedure) {
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, corto_function(procedure));
    return corto_define(this);
}

void _corto_notifyActionSet(corto_notifyAction* this, corto_object instance, corto_function procedure) {
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, corto_function(procedure));
}

corto_string _corto_notifyActionStr(corto_notifyAction* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_notifyAction_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_notifyAction_o), str);
    return value;
}

corto_int16 _corto_notifyActionCopy(corto_notifyAction* *dst, corto_notifyAction* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_notifyAction_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_notifyAction_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_notifyAction_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_notifyAction_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_notifyActionInit(corto_notifyAction* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_notifyAction_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_notifyAction_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_notifyActionDeinit(corto_notifyAction* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_notifyAction_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int16 corto_notifyActionCall(corto_notifyAction *_delegate, corto_object observable) {
    if (_delegate->_parent.procedure) {
        if (_delegate->_parent.instance) {
            corto_call(_delegate->_parent.procedure, NULL, _delegate->_parent.instance, observable);
        } else {
            corto_call(_delegate->_parent.procedure, NULL, observable);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_observableEvent _corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable) {
    corto_observableEvent this;
    this = corto_declare(corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->observer, corto_observer(observer));
    corto_setref(&this->me, me);
    corto_setref(&this->source, source);
    corto_setref(&this->observable, observable);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_observableEvent _corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable) {
    corto_observableEvent this;
    this = corto_declareChild(_parent, _name, corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->observer, corto_observer(observer));
    corto_setref(&this->me, me);
    corto_setref(&this->source, source);
    corto_setref(&this->observable, observable);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observableEventUpdate(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable) {
    if (!corto_updateBegin(this)) {
        corto_setref(&this->observer, corto_observer(observer));
        corto_setref(&this->me, me);
        corto_setref(&this->source, source);
        corto_setref(&this->observable, observable);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_observableEvent _corto_observableEventDeclare(void) {
    corto_observableEvent this;
    this = corto_declare(corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_observableEvent _corto_observableEventDeclareChild(corto_object _parent, corto_string _name) {
    corto_observableEvent this;
    this = corto_declareChild(_parent, _name, corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_observableEventDefine(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable) {
    corto_setref(&this->observer, corto_observer(observer));
    corto_setref(&this->me, me);
    corto_setref(&this->source, source);
    corto_setref(&this->observable, observable);
    return corto_define(this);
}

void _corto_observableEventSet(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable) {
    corto_setref(&this->observer, corto_observer(observer));
    corto_setref(&this->me, me);
    corto_setref(&this->source, source);
    corto_setref(&this->observable, observable);
}

corto_string _corto_observableEventStr(corto_observableEvent value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_observableEvent_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_observableEvent corto_observableEventFromStr(corto_observableEvent value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observableEvent_o), str);
    return value;
}

corto_int16 _corto_observableEventCopy(corto_observableEvent *dst, corto_observableEvent src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src) {
    return corto_compare(dst, src);
}

corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_observer this;
    this = corto_declare(corto_observer_o);
    if (!this) {
        return NULL;
    }
    this->mask = mask;
    corto_setref(&this->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _name, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_observer this;
    this = corto_declareChild(_parent, _name, corto_observer_o);
    if (!this) {
        return NULL;
    }
    this->mask = mask;
    corto_setref(&this->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observerUpdate(corto_observer this, corto_eventMask mask, corto_object observable) {
    if (!corto_updateBegin(this)) {
        this->mask = mask;
        corto_setref(&this->observable, observable);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_observer _corto_observerDeclare(void) {
    corto_observer this;
    this = corto_declare(corto_observer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _name) {
    corto_observer this;
    this = corto_declareChild(_parent, _name, corto_observer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_observerDefine(corto_observer this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    this->mask = mask;
    corto_setref(&this->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    return corto_define(this);
}

void _corto_observerSet(corto_observer this, corto_eventMask mask, corto_object observable) {
    this->mask = mask;
    corto_setref(&this->observable, observable);
}

corto_string _corto_observerStr(corto_observer value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_observer_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_observer corto_observerFromStr(corto_observer value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observer_o), str);
    return value;
}

corto_int16 _corto_observerCopy(corto_observer *dst, corto_observer src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_observerCompare(corto_observer dst, corto_observer src) {
    return corto_compare(dst, src);
}

corto_observerseq* _corto_observerseqCreate(void) {
    corto_observerseq* this;
    this = corto_declare(corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_observerseq* _corto_observerseqCreateChild(corto_object _parent, corto_string _name) {
    corto_observerseq* this;
    this = corto_declareChild(_parent, _name, corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observerseqUpdate(corto_observerseq* this, corto_observerseq value) {
    if (!corto_updateBegin(this)) {
        corto_copyp(this, corto_observerseq_o, &value);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_observerseq* _corto_observerseqDeclare(void) {
    corto_observerseq* this;
    this = corto_declare(corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_observerseq* _corto_observerseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_observerseq* this;
    this = corto_declareChild(_parent, _name, corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_observerseqDefine(corto_observerseq* this, corto_observerseq value) {
    corto_copyp(this, corto_observerseq_o, &value);
    return corto_define(this);
}

void _corto_observerseqSet(corto_observerseq* this, corto_observerseq value) {
    corto_copyp(this, corto_observerseq_o, &value);
}

corto_string _corto_observerseqStr(corto_observerseq value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_observerseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_observerseq* corto_observerseqFromStr(corto_observerseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observerseq_o), str);
    return value;
}

corto_int16 _corto_observerseqCopy(corto_observerseq* *dst, corto_observerseq* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_observerseq_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_observerseq_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_observerseqCompare(corto_observerseq* dst, corto_observerseq* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_observerseq_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_observerseq_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_observerseqInit(corto_observerseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_observerseq_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_observerseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_observerseqDeinit(corto_observerseq* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_observerseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value) {
    corto_operatorKind* this;
    this = corto_declare(corto_operatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _name, corto_operatorKind value) {
    corto_operatorKind* this;
    this = corto_declareChild(_parent, _name, corto_operatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_operatorKindUpdate(corto_operatorKind* this, corto_operatorKind value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_operatorKind* _corto_operatorKindDeclare(void) {
    corto_operatorKind* this;
    this = corto_declare(corto_operatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_operatorKind* this;
    this = corto_declareChild(_parent, _name, corto_operatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_operatorKindDefine(corto_operatorKind* this, corto_operatorKind value) {
    *this = value;
    return corto_define(this);
}

void _corto_operatorKindSet(corto_operatorKind* this, corto_operatorKind value) {
    *this = value;
}

corto_string _corto_operatorKindStr(corto_operatorKind value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_operatorKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_operatorKind* corto_operatorKindFromStr(corto_operatorKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_operatorKind_o), str);
    return value;
}

corto_int16 _corto_operatorKindCopy(corto_operatorKind* *dst, corto_operatorKind* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_operatorKind_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_operatorKind_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_operatorKindCompare(corto_operatorKind* dst, corto_operatorKind* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_operatorKind_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_operatorKind_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_operatorKindInit(corto_operatorKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_operatorKind_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_operatorKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_operatorKindDeinit(corto_operatorKind* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_operatorKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_package _corto_packageCreate(corto_string url) {
    corto_package this;
    this = corto_declare(corto_package_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->url, url);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_package _corto_packageCreateChild(corto_object _parent, corto_string _name, corto_string url) {
    corto_package this;
    this = corto_declareChild(_parent, _name, corto_package_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->url, url);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_packageUpdate(corto_package this, corto_string url) {
    if (!corto_updateBegin(this)) {
        corto_setstr(&this->url, url);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_package _corto_packageDeclare(void) {
    corto_package this;
    this = corto_declare(corto_package_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _name) {
    corto_package this;
    this = corto_declareChild(_parent, _name, corto_package_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_packageDefine(corto_package this, corto_string url) {
    corto_setstr(&this->url, url);
    return corto_define(this);
}

void _corto_packageSet(corto_package this, corto_string url) {
    corto_setstr(&this->url, url);
}

corto_string _corto_packageStr(corto_package value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_package_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_package corto_packageFromStr(corto_package value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_package_o), str);
    return value;
}

corto_int16 _corto_packageCopy(corto_package *dst, corto_package src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_packageCompare(corto_package dst, corto_package src) {
    return corto_compare(dst, src);
}

corto_query _corto_queryCreate(corto_object from, corto_eventMask mask) {
    corto_query this;
    this = corto_declare(corto_query_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->from, from);
    this->mask = mask;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_query _corto_queryCreateChild(corto_object _parent, corto_string _name, corto_object from, corto_eventMask mask) {
    corto_query this;
    this = corto_declareChild(_parent, _name, corto_query_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->from, from);
    this->mask = mask;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_queryUpdate(corto_query this, corto_object from, corto_eventMask mask) {
    if (!corto_updateBegin(this)) {
        corto_setref(&this->from, from);
        this->mask = mask;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_query _corto_queryDeclare(void) {
    corto_query this;
    this = corto_declare(corto_query_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_query _corto_queryDeclareChild(corto_object _parent, corto_string _name) {
    corto_query this;
    this = corto_declareChild(_parent, _name, corto_query_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_queryDefine(corto_query this, corto_object from, corto_eventMask mask) {
    corto_setref(&this->from, from);
    this->mask = mask;
    return corto_define(this);
}

void _corto_querySet(corto_query this, corto_object from, corto_eventMask mask) {
    corto_setref(&this->from, from);
    this->mask = mask;
}

corto_string _corto_queryStr(corto_query value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_query_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_query corto_queryFromStr(corto_query value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_query_o), str);
    return value;
}

corto_int16 _corto_queryCopy(corto_query *dst, corto_query src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_queryCompare(corto_query dst, corto_query src) {
    return corto_compare(dst, src);
}

corto_replicator _corto_replicatorCreate(corto_object mount, corto_query query, corto_string contentType) {
    corto_replicator this;
    this = corto_declare(corto_replicator_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->mount, mount);
    corto_setref(&this->query, corto_query(query));
    corto_setstr(&this->contentType, contentType);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_replicator _corto_replicatorCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_query query, corto_string contentType) {
    corto_replicator this;
    this = corto_declareChild(_parent, _name, corto_replicator_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->mount, mount);
    corto_setref(&this->query, corto_query(query));
    corto_setstr(&this->contentType, contentType);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_replicatorUpdate(corto_replicator this, corto_object mount, corto_query query, corto_string contentType) {
    if (!corto_updateBegin(this)) {
        corto_setref(&this->mount, mount);
        corto_setref(&this->query, corto_query(query));
        corto_setstr(&this->contentType, contentType);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_replicator _corto_replicatorDeclare(void) {
    corto_replicator this;
    this = corto_declare(corto_replicator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_replicator _corto_replicatorDeclareChild(corto_object _parent, corto_string _name) {
    corto_replicator this;
    this = corto_declareChild(_parent, _name, corto_replicator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_replicatorDefine(corto_replicator this, corto_object mount, corto_query query, corto_string contentType) {
    corto_setref(&this->mount, mount);
    corto_setref(&this->query, corto_query(query));
    corto_setstr(&this->contentType, contentType);
    return corto_define(this);
}

void _corto_replicatorSet(corto_replicator this, corto_object mount, corto_query query, corto_string contentType) {
    corto_setref(&this->mount, mount);
    corto_setref(&this->query, corto_query(query));
    corto_setstr(&this->contentType, contentType);
}

corto_string _corto_replicatorStr(corto_replicator value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(corto_replicator_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_replicator corto_replicatorFromStr(corto_replicator value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_replicator_o), str);
    return value;
}

corto_int16 _corto_replicatorCopy(corto_replicator *dst, corto_replicator src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _corto_replicatorCompare(corto_replicator dst, corto_replicator src) {
    return corto_compare(dst, src);
}

corto_result* _corto_resultCreate(corto_string name, corto_string parent, corto_string type, corto_word value) {
    corto_result* this;
    this = corto_declare(corto_result_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->name, name);
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->type, type);
    this->value = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_string parent, corto_string type, corto_word value) {
    corto_result* this;
    this = corto_declareChild(_parent, _name, corto_result_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->name, name);
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->type, type);
    this->value = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultUpdate(corto_result* this, corto_string name, corto_string parent, corto_string type, corto_word value) {
    if (!corto_updateBegin(this)) {
        corto_setstr(&this->name, name);
        corto_setstr(&this->parent, parent);
        corto_setstr(&this->type, type);
        this->value = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_result* _corto_resultDeclare(void) {
    corto_result* this;
    this = corto_declare(corto_result_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_result* _corto_resultDeclareChild(corto_object _parent, corto_string _name) {
    corto_result* this;
    this = corto_declareChild(_parent, _name, corto_result_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_resultDefine(corto_result* this, corto_string name, corto_string parent, corto_string type, corto_word value) {
    corto_setstr(&this->name, name);
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->type, type);
    this->value = value;
    return corto_define(this);
}

void _corto_resultSet(corto_result* this, corto_string name, corto_string parent, corto_string type, corto_word value) {
    corto_setstr(&this->name, name);
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->type, type);
    this->value = value;
}

corto_string _corto_resultStr(corto_result* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_result_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_result* corto_resultFromStr(corto_result* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_result_o), str);
    return value;
}

corto_int16 _corto_resultCopy(corto_result* *dst, corto_result* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_result_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_result_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_resultCompare(corto_result* dst, corto_result* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_result_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_result_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_resultInit(corto_result* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_result_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_result_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultDeinit(corto_result* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_result_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_resultIter* _corto_resultIterCreate(corto_resultIter value) {
    corto_resultIter* this;
    this = corto_declare(corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _name, corto_resultIter value) {
    corto_resultIter* this;
    this = corto_declareChild(_parent, _name, corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultIterUpdate(corto_resultIter* this, corto_resultIter value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultIter* _corto_resultIterDeclare(void) {
    corto_resultIter* this;
    this = corto_declare(corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, corto_string _name) {
    corto_resultIter* this;
    this = corto_declareChild(_parent, _name, corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_resultIterDefine(corto_resultIter* this, corto_resultIter value) {
    *this = value;
    return corto_define(this);
}

void _corto_resultIterSet(corto_resultIter* this, corto_resultIter value) {
    *this = value;
}

corto_string _corto_resultIterStr(corto_resultIter value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultIter_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_resultIter* corto_resultIterFromStr(corto_resultIter* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_resultIter_o), str);
    return value;
}

corto_int16 _corto_resultIterCopy(corto_resultIter* *dst, corto_resultIter* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_resultIter_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_resultIter_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_resultIterCompare(corto_resultIter* dst, corto_resultIter* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_resultIter_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_resultIter_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_resultIterInit(corto_resultIter* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_resultIter_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultIter_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultIterDeinit(corto_resultIter* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultIter_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_resultList* _corto_resultListCreate(void) {
    corto_resultList* this;
    this = corto_declare(corto_resultList_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _name) {
    corto_resultList* this;
    this = corto_declareChild(_parent, _name, corto_resultList_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultListUpdate(corto_resultList* this, corto_resultList value) {
    if (!corto_updateBegin(this)) {
        corto_copyp(this, corto_resultList_o, value);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultList* _corto_resultListDeclare(void) {
    corto_resultList* this;
    this = corto_declare(corto_resultList_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_resultList* _corto_resultListDeclareChild(corto_object _parent, corto_string _name) {
    corto_resultList* this;
    this = corto_declareChild(_parent, _name, corto_resultList_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_resultListDefine(corto_resultList* this, corto_resultList value) {
    corto_copyp(this, corto_resultList_o, value);
    return corto_define(this);
}

void _corto_resultListSet(corto_resultList* this, corto_resultList value) {
    corto_copyp(this, corto_resultList_o, value);
}

corto_string _corto_resultListStr(corto_resultList value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_resultList* corto_resultListFromStr(corto_resultList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_resultList_o), str);
    return value;
}

corto_int16 _corto_resultListCopy(corto_resultList* *dst, corto_resultList* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_resultList_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_resultList_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _corto_resultListCompare(corto_resultList* dst, corto_resultList* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(corto_resultList_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(corto_resultList_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _corto_resultListInit(corto_resultList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_resultList_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultListDeinit(corto_resultList* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_resultList_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_observer* corto_observerseqAppend(corto_observerseq *seq, corto_observer element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_observer* corto_observerseqAppendAlloc(corto_observerseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_observerseqSize(corto_observerseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                corto_valueValueInit(&v, NULL, corto_type(corto_observer_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_observerseqClear(corto_observerseq *seq) {
    corto_observerseqSize(seq, 0);
}

corto_result* corto_resultListInsertAlloc(corto_resultList list) {
    corto_result* result;
    result = corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(corto_result_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

corto_result* corto_resultListInsert(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListInsertAlloc(list);
    corto_copyp(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListAppendAlloc(corto_resultList list) {
    corto_result* result;
    result = corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(corto_result_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

corto_result* corto_resultListAppend(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListAppendAlloc(list);
    corto_copyp(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListTakeFirst(corto_resultList list) {
    return (corto_result*)(corto_word)corto_llTakeFirst(list);
}

corto_result* corto_resultListLast(corto_resultList list) {
    return (corto_result*)(corto_word)corto_llLast(list);
}

void corto_resultListClear(corto_resultList list) {
    void *element;

    while((element = corto_llTakeFirst(list))) {
        {
            corto_value v;
            corto_valueValueInit(&v, NULL, corto_type(corto_result_o), element);
            corto_deinitv(&v);
        }
        corto_dealloc(element);
    }
}

corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index) {
    return (corto_result*)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_resultListSize(corto_resultList list) {
    return corto_llSize(list);
}

