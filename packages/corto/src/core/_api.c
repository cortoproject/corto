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
    if (corto_define(this)) {
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
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_attrUpdate(corto_attr* this, corto_attr value) {
    CORTO_UNUSED(this);
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
    CORTO_UNUSED(this);
    *this = value;
    return corto_define(this);
}

void _corto_attrSet(corto_attr* this, corto_attr value) {
    CORTO_UNUSED(this);
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

corto_int16 corto_attrCompare(corto_attr dst, corto_attr src) {
    return corto_comparep(&dst, corto_attr_o, &src);
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

corto_augmentData* _corto_augmentDataCreate(corto_string id, corto_word data) {
    corto_augmentData* this;
    this = corto_declare(corto_augmentData_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_augmentData*)this)->id, id);
    ((corto_augmentData*)this)->data = data;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_augmentData* _corto_augmentDataCreateChild(corto_object _parent, corto_string _name, corto_string id, corto_word data) {
    corto_augmentData* this;
    this = corto_declareChild(_parent, _name, corto_augmentData_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_augmentData*)this)->id, id);
    ((corto_augmentData*)this)->data = data;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_augmentDataUpdate(corto_augmentData* this, corto_string id, corto_word data) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setstr(&((corto_augmentData*)this)->id, id);
        ((corto_augmentData*)this)->data = data;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_augmentData* _corto_augmentDataDeclare(void) {
    corto_augmentData* this;
    this = corto_declare(corto_augmentData_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_augmentData* _corto_augmentDataDeclareChild(corto_object _parent, corto_string _name) {
    corto_augmentData* this;
    this = corto_declareChild(_parent, _name, corto_augmentData_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_augmentDataDefine(corto_augmentData* this, corto_string id, corto_word data) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_augmentData*)this)->id, id);
    ((corto_augmentData*)this)->data = data;
    return corto_define(this);
}

void _corto_augmentDataSet(corto_augmentData* this, corto_string id, corto_word data) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_augmentData*)this)->id, id);
    ((corto_augmentData*)this)->data = data;
}

corto_string _corto_augmentDataStr(corto_augmentData* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_augmentData* corto_augmentDataFromStr(corto_augmentData* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_augmentData_o), str);
    return value;
}

corto_int16 corto_augmentDataCompare(corto_augmentData* dst, corto_augmentData* src) {
    return corto_comparep(dst, corto_augmentData_o, src);
}

corto_int16 _corto_augmentDataInit(corto_augmentData* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_augmentData_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_augmentDataDeinit(corto_augmentData* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_augmentseq* _corto_augmentseqCreate(corto_uint32 length, corto_augmentData* elements) {
    corto_augmentseq* this;
    this = corto_declare(corto_augmentseq_o);
    if (!this) {
        return NULL;
    }
    corto_augmentseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&this->buffer[i], corto_augmentData_o, &elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_augmentseq* _corto_augmentseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_augmentData* elements) {
    corto_augmentseq* this;
    this = corto_declareChild(_parent, _name, corto_augmentseq_o);
    if (!this) {
        return NULL;
    }
    corto_augmentseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&this->buffer[i], corto_augmentData_o, &elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_augmentseqUpdate(corto_augmentseq* this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_augmentseqSize(this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_copyp(&this->buffer[i], corto_augmentData_o, &elements[i]);
        }
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_augmentseq* _corto_augmentseqDeclare(void) {
    corto_augmentseq* this;
    this = corto_declare(corto_augmentseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_augmentseq* _corto_augmentseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_augmentseq* this;
    this = corto_declareChild(_parent, _name, corto_augmentseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_augmentseqDefine(corto_augmentseq* this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(this);
    corto_augmentseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&this->buffer[i], corto_augmentData_o, &elements[i]);
    }
    return corto_define(this);
}

void _corto_augmentseqSet(corto_augmentseq* this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(this);
    corto_augmentseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&this->buffer[i], corto_augmentData_o, &elements[i]);
    }
}

corto_string _corto_augmentseqStr(corto_augmentseq value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_augmentseq* corto_augmentseqFromStr(corto_augmentseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_augmentseq_o), str);
    return value;
}

corto_int16 corto_augmentseqCompare(corto_augmentseq dst, corto_augmentseq src) {
    return corto_comparep(&dst, corto_augmentseq_o, &src);
}

corto_int16 _corto_augmentseqInit(corto_augmentseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_augmentseq_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_augmentseqDeinit(corto_augmentseq* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_augmentseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_dispatcher _corto_dispatcherCreate(void) {
    corto_dispatcher this;
    this = corto_declare(corto_dispatcher_o);
    if (!this) {
        return NULL;
    }
    if (corto_define(this)) {
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
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_dispatcherUpdate(corto_dispatcher this) {
    CORTO_UNUSED(this);
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
    CORTO_UNUSED(this);
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
    if (corto_define(this)) {
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
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_equalityKindUpdate(corto_equalityKind* this, corto_equalityKind value) {
    CORTO_UNUSED(this);
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
    CORTO_UNUSED(this);
    *this = value;
    return corto_define(this);
}

void _corto_equalityKindSet(corto_equalityKind* this, corto_equalityKind value) {
    CORTO_UNUSED(this);
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

corto_int16 corto_equalityKindCompare(corto_equalityKind dst, corto_equalityKind src) {
    return corto_comparep(&dst, corto_equalityKind_o, &src);
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
    ((corto_event)this)->kind = kind;
    if (corto_define(this)) {
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
    ((corto_event)this)->kind = kind;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_eventUpdate(corto_event this, corto_uint16 kind) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        ((corto_event)this)->kind = kind;
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
    CORTO_UNUSED(this);
    ((corto_event)this)->kind = kind;
    return corto_define(this);
}

void _corto_eventSet(corto_event this, corto_uint16 kind) {
    CORTO_UNUSED(this);
    ((corto_event)this)->kind = kind;
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
    if (corto_define(this)) {
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
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_eventMaskUpdate(corto_eventMask* this, corto_eventMask value) {
    CORTO_UNUSED(this);
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
    CORTO_UNUSED(this);
    *this = value;
    return corto_define(this);
}

void _corto_eventMaskSet(corto_eventMask* this, corto_eventMask value) {
    CORTO_UNUSED(this);
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

corto_int16 corto_eventMaskCompare(corto_eventMask dst, corto_eventMask src) {
    return corto_comparep(&dst, corto_eventMask_o, &src);
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
    corto_setref(&((corto_invokeEvent)this)->replicator, replicator);
    corto_setref(&((corto_invokeEvent)this)->instance, instance);
    corto_setref(&((corto_invokeEvent)this)->function, function);
    corto_copyp(&((corto_invokeEvent)this)->args, corto_octetseq_o, &args);
    if (corto_define(this)) {
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
    corto_setref(&((corto_invokeEvent)this)->replicator, replicator);
    corto_setref(&((corto_invokeEvent)this)->instance, instance);
    corto_setref(&((corto_invokeEvent)this)->function, function);
    corto_copyp(&((corto_invokeEvent)this)->args, corto_octetseq_o, &args);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_invokeEventUpdate(corto_invokeEvent this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_invokeEvent)this)->replicator, replicator);
        corto_setref(&((corto_invokeEvent)this)->instance, instance);
        corto_setref(&((corto_invokeEvent)this)->function, function);
        corto_copyp(&((corto_invokeEvent)this)->args, corto_octetseq_o, &args);
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
    CORTO_UNUSED(this);
    corto_setref(&((corto_invokeEvent)this)->replicator, replicator);
    corto_setref(&((corto_invokeEvent)this)->instance, instance);
    corto_setref(&((corto_invokeEvent)this)->function, function);
    corto_copyp(&((corto_invokeEvent)this)->args, corto_octetseq_o, &args);
    return corto_define(this);
}

void _corto_invokeEventSet(corto_invokeEvent this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_invokeEvent)this)->replicator, replicator);
    corto_setref(&((corto_invokeEvent)this)->instance, instance);
    corto_setref(&((corto_invokeEvent)this)->function, function);
    corto_copyp(&((corto_invokeEvent)this)->args, corto_octetseq_o, &args);
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
    corto_setref(&((corto_delegatedata*)this)->procedure, procedure);
    if (corto_define(this)) {
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
    corto_setref(&((corto_delegatedata*)this)->procedure, procedure);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_notifyActionUpdate(corto_notifyAction* this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_delegatedata*)this)->instance, instance);
        corto_setref(&((corto_delegatedata*)this)->procedure, procedure);
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
    CORTO_UNUSED(this);
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, procedure);
    return corto_define(this);
}

void _corto_notifyActionSet(corto_notifyAction* this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_delegatedata*)this)->instance, instance);
    corto_setref(&((corto_delegatedata*)this)->procedure, procedure);
}

corto_string _corto_notifyActionStr(corto_notifyAction* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_notifyAction_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_notifyAction_o), str);
    return value;
}

corto_int16 corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src) {
    return corto_comparep(dst, corto_notifyAction_o, src);
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

corto_int16 corto_notifyActionInitC(corto_notifyAction *d, corto_void ___ (*callback)(corto_object)) {
    d->_parent.procedure = corto_functionDeclare();
    void __corto_notifyAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_notifyAction;
    corto_function_parseParamString(d->_parent.procedure, "(/corto/lang/object observable)");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int16 corto_notifyActionInitCInstance(corto_notifyAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_object)) {
    d->_parent.instance = instance;
    corto_claim(instance);
    d->_parent.procedure = corto_functionDeclare();
    void __corto_notifyAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_notifyAction;
    corto_function_parseParamString(d->_parent.procedure, "(object instance, /corto/lang/object observable)");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_observableEvent _corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    corto_observableEvent this;
    this = corto_declare(corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_observableEvent)this)->observer, observer);
    corto_setref(&((corto_observableEvent)this)->me, me);
    corto_setref(&((corto_observableEvent)this)->source, source);
    corto_setref(&((corto_observableEvent)this)->observable, observable);
    ((corto_observableEvent)this)->mask = mask;
    ((corto_observableEvent)this)->thread = thread;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_observableEvent _corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    corto_observableEvent this;
    this = corto_declareChild(_parent, _name, corto_observableEvent_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_observableEvent)this)->observer, observer);
    corto_setref(&((corto_observableEvent)this)->me, me);
    corto_setref(&((corto_observableEvent)this)->source, source);
    corto_setref(&((corto_observableEvent)this)->observable, observable);
    ((corto_observableEvent)this)->mask = mask;
    ((corto_observableEvent)this)->thread = thread;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observableEventUpdate(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_observableEvent)this)->observer, observer);
        corto_setref(&((corto_observableEvent)this)->me, me);
        corto_setref(&((corto_observableEvent)this)->source, source);
        corto_setref(&((corto_observableEvent)this)->observable, observable);
        ((corto_observableEvent)this)->mask = mask;
        ((corto_observableEvent)this)->thread = thread;
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

corto_int16 _corto_observableEventDefine(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_observableEvent)this)->observer, observer);
    corto_setref(&((corto_observableEvent)this)->me, me);
    corto_setref(&((corto_observableEvent)this)->source, source);
    corto_setref(&((corto_observableEvent)this)->observable, observable);
    ((corto_observableEvent)this)->mask = mask;
    ((corto_observableEvent)this)->thread = thread;
    return corto_define(this);
}

void _corto_observableEventSet(corto_observableEvent this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_observableEvent)this)->observer, observer);
    corto_setref(&((corto_observableEvent)this)->me, me);
    corto_setref(&((corto_observableEvent)this)->source, source);
    corto_setref(&((corto_observableEvent)this)->observable, observable);
    ((corto_observableEvent)this)->mask = mask;
    ((corto_observableEvent)this)->thread = thread;
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

corto_int16 _corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src) {
    return corto_compare(dst, src);
}

corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_observer this;
    this = corto_declare(corto_observer_o);
    if (!this) {
        return NULL;
    }
    ((corto_observer)this)->mask = mask;
    corto_setref(&((corto_observer)this)->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    if (corto_define(this)) {
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
    ((corto_observer)this)->mask = mask;
    corto_setref(&((corto_observer)this)->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observerUpdate(corto_observer this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        ((corto_observer)this)->mask = mask;
        corto_setref(&((corto_observer)this)->observable, observable);
        corto_function(this)->impl = (corto_word)_impl;
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
    CORTO_UNUSED(this);
    ((corto_observer)this)->mask = mask;
    corto_setref(&((corto_observer)this)->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
    return corto_define(this);
}

void _corto_observerSet(corto_observer this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(this);
    ((corto_observer)this)->mask = mask;
    corto_setref(&((corto_observer)this)->observable, observable);
    corto_function(this)->impl = (corto_word)_impl;
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

corto_int16 _corto_observerCompare(corto_observer dst, corto_observer src) {
    return corto_compare(dst, src);
}

corto_observerseq* _corto_observerseqCreate(corto_uint32 length, corto_observer* elements) {
    corto_observerseq* this;
    this = corto_declare(corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    corto_observerseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&this->buffer[i], elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_observerseq* _corto_observerseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_observer* elements) {
    corto_observerseq* this;
    this = corto_declareChild(_parent, _name, corto_observerseq_o);
    if (!this) {
        return NULL;
    }
    corto_observerseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&this->buffer[i], elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_observerseqUpdate(corto_observerseq* this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_observerseqSize(this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&this->buffer[i], elements[i]);
        }
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

corto_int16 _corto_observerseqDefine(corto_observerseq* this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(this);
    corto_observerseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&this->buffer[i], elements[i]);
    }
    return corto_define(this);
}

void _corto_observerseqSet(corto_observerseq* this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(this);
    corto_observerseqSize(this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&this->buffer[i], elements[i]);
    }
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

corto_int16 corto_observerseqCompare(corto_observerseq dst, corto_observerseq src) {
    return corto_comparep(&dst, corto_observerseq_o, &src);
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
    if (corto_define(this)) {
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
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_operatorKindUpdate(corto_operatorKind* this, corto_operatorKind value) {
    CORTO_UNUSED(this);
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
    CORTO_UNUSED(this);
    *this = value;
    return corto_define(this);
}

void _corto_operatorKindSet(corto_operatorKind* this, corto_operatorKind value) {
    CORTO_UNUSED(this);
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

corto_int16 corto_operatorKindCompare(corto_operatorKind dst, corto_operatorKind src) {
    return corto_comparep(&dst, corto_operatorKind_o, &src);
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
    corto_setstr(&((corto_package)this)->url, url);
    if (corto_define(this)) {
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
    corto_setstr(&((corto_package)this)->url, url);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_packageUpdate(corto_package this, corto_string url) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setstr(&((corto_package)this)->url, url);
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
    CORTO_UNUSED(this);
    corto_setstr(&((corto_package)this)->url, url);
    return corto_define(this);
}

void _corto_packageSet(corto_package this, corto_string url) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_package)this)->url, url);
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

corto_int16 _corto_packageCompare(corto_package dst, corto_package src) {
    return corto_compare(dst, src);
}

corto_position* _corto_positionCreate(corto_float64 latitude, corto_float64 longitude) {
    corto_position* this;
    this = corto_declare(corto_position_o);
    if (!this) {
        return NULL;
    }
    ((corto_position*)this)->latitude = latitude;
    ((corto_position*)this)->longitude = longitude;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_position* _corto_positionCreateChild(corto_object _parent, corto_string _name, corto_float64 latitude, corto_float64 longitude) {
    corto_position* this;
    this = corto_declareChild(_parent, _name, corto_position_o);
    if (!this) {
        return NULL;
    }
    ((corto_position*)this)->latitude = latitude;
    ((corto_position*)this)->longitude = longitude;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_positionUpdate(corto_position* this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        ((corto_position*)this)->latitude = latitude;
        ((corto_position*)this)->longitude = longitude;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_position* _corto_positionDeclare(void) {
    corto_position* this;
    this = corto_declare(corto_position_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_position* _corto_positionDeclareChild(corto_object _parent, corto_string _name) {
    corto_position* this;
    this = corto_declareChild(_parent, _name, corto_position_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_positionDefine(corto_position* this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(this);
    ((corto_position*)this)->latitude = latitude;
    ((corto_position*)this)->longitude = longitude;
    return corto_define(this);
}

void _corto_positionSet(corto_position* this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(this);
    ((corto_position*)this)->latitude = latitude;
    ((corto_position*)this)->longitude = longitude;
}

corto_string _corto_positionStr(corto_position* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_position_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_position* corto_positionFromStr(corto_position* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_position_o), str);
    return value;
}

corto_int16 corto_positionCompare(corto_position* dst, corto_position* src) {
    return corto_comparep(dst, corto_position_o, src);
}

corto_int16 _corto_positionInit(corto_position* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_position_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_position_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_positionDeinit(corto_position* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_position_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_query _corto_queryCreate(corto_object from, corto_eventMask mask) {
    corto_query this;
    this = corto_declare(corto_query_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_query)this)->from, from);
    ((corto_query)this)->mask = mask;
    if (corto_define(this)) {
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
    corto_setref(&((corto_query)this)->from, from);
    ((corto_query)this)->mask = mask;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_queryUpdate(corto_query this, corto_object from, corto_eventMask mask) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_query)this)->from, from);
        ((corto_query)this)->mask = mask;
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
    CORTO_UNUSED(this);
    corto_setref(&((corto_query)this)->from, from);
    ((corto_query)this)->mask = mask;
    return corto_define(this);
}

void _corto_querySet(corto_query this, corto_object from, corto_eventMask mask) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_query)this)->from, from);
    ((corto_query)this)->mask = mask;
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

corto_int16 _corto_queryCompare(corto_query dst, corto_query src) {
    return corto_compare(dst, src);
}

corto_replicator _corto_replicatorCreate(corto_object mount, corto_query query, corto_replicatorKind kind, corto_string contentType) {
    corto_replicator this;
    this = corto_declare(corto_replicator_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_replicator)this)->mount, mount);
    corto_setref(&((corto_replicator)this)->query, query);
    ((corto_replicator)this)->kind = kind;
    corto_setstr(&((corto_replicator)this)->contentType, contentType);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_replicator _corto_replicatorCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_query query, corto_replicatorKind kind, corto_string contentType) {
    corto_replicator this;
    this = corto_declareChild(_parent, _name, corto_replicator_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&((corto_replicator)this)->mount, mount);
    corto_setref(&((corto_replicator)this)->query, query);
    ((corto_replicator)this)->kind = kind;
    corto_setstr(&((corto_replicator)this)->contentType, contentType);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_replicatorUpdate(corto_replicator this, corto_object mount, corto_query query, corto_replicatorKind kind, corto_string contentType) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setref(&((corto_replicator)this)->mount, mount);
        corto_setref(&((corto_replicator)this)->query, query);
        ((corto_replicator)this)->kind = kind;
        corto_setstr(&((corto_replicator)this)->contentType, contentType);
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

corto_int16 _corto_replicatorDefine(corto_replicator this, corto_object mount, corto_query query, corto_replicatorKind kind, corto_string contentType) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_replicator)this)->mount, mount);
    corto_setref(&((corto_replicator)this)->query, query);
    ((corto_replicator)this)->kind = kind;
    corto_setstr(&((corto_replicator)this)->contentType, contentType);
    return corto_define(this);
}

void _corto_replicatorSet(corto_replicator this, corto_object mount, corto_query query, corto_replicatorKind kind, corto_string contentType) {
    CORTO_UNUSED(this);
    corto_setref(&((corto_replicator)this)->mount, mount);
    corto_setref(&((corto_replicator)this)->query, query);
    ((corto_replicator)this)->kind = kind;
    corto_setstr(&((corto_replicator)this)->contentType, contentType);
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

corto_int16 _corto_replicatorCompare(corto_replicator dst, corto_replicator src) {
    return corto_compare(dst, src);
}

corto_replicatorKind* _corto_replicatorKindCreate(corto_replicatorKind value) {
    corto_replicatorKind* this;
    this = corto_declare(corto_replicatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_replicatorKind* _corto_replicatorKindCreateChild(corto_object _parent, corto_string _name, corto_replicatorKind value) {
    corto_replicatorKind* this;
    this = corto_declareChild(_parent, _name, corto_replicatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_replicatorKindUpdate(corto_replicatorKind* this, corto_replicatorKind value) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_replicatorKind* _corto_replicatorKindDeclare(void) {
    corto_replicatorKind* this;
    this = corto_declare(corto_replicatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_replicatorKind* _corto_replicatorKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_replicatorKind* this;
    this = corto_declareChild(_parent, _name, corto_replicatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_replicatorKindDefine(corto_replicatorKind* this, corto_replicatorKind value) {
    CORTO_UNUSED(this);
    *this = value;
    return corto_define(this);
}

void _corto_replicatorKindSet(corto_replicatorKind* this, corto_replicatorKind value) {
    CORTO_UNUSED(this);
    *this = value;
}

corto_string _corto_replicatorKindStr(corto_replicatorKind value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_replicatorKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_replicatorKind* corto_replicatorKindFromStr(corto_replicatorKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_replicatorKind_o), str);
    return value;
}

corto_int16 corto_replicatorKindCompare(corto_replicatorKind dst, corto_replicatorKind src) {
    return corto_comparep(&dst, corto_replicatorKind_o, &src);
}

corto_int16 _corto_replicatorKindInit(corto_replicatorKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_replicatorKind_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_replicatorKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_replicatorKindDeinit(corto_replicatorKind* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_replicatorKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_request* _corto_requestCreate(corto_string parent, corto_string expr, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_string param) {
    corto_request* this;
    this = corto_declare(corto_request_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_request*)this)->parent, parent);
    corto_setstr(&((corto_request*)this)->expr, expr);
    ((corto_request*)this)->offset = offset;
    ((corto_request*)this)->limit = limit;
    ((corto_request*)this)->content = content;
    corto_setstr(&((corto_request*)this)->param, param);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_request* _corto_requestCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string expr, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_string param) {
    corto_request* this;
    this = corto_declareChild(_parent, _name, corto_request_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_request*)this)->parent, parent);
    corto_setstr(&((corto_request*)this)->expr, expr);
    ((corto_request*)this)->offset = offset;
    ((corto_request*)this)->limit = limit;
    ((corto_request*)this)->content = content;
    corto_setstr(&((corto_request*)this)->param, param);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_requestUpdate(corto_request* this, corto_string parent, corto_string expr, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_string param) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setstr(&((corto_request*)this)->parent, parent);
        corto_setstr(&((corto_request*)this)->expr, expr);
        ((corto_request*)this)->offset = offset;
        ((corto_request*)this)->limit = limit;
        ((corto_request*)this)->content = content;
        corto_setstr(&((corto_request*)this)->param, param);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_request* _corto_requestDeclare(void) {
    corto_request* this;
    this = corto_declare(corto_request_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_request* _corto_requestDeclareChild(corto_object _parent, corto_string _name) {
    corto_request* this;
    this = corto_declareChild(_parent, _name, corto_request_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_requestDefine(corto_request* this, corto_string parent, corto_string expr, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_string param) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_request*)this)->parent, parent);
    corto_setstr(&((corto_request*)this)->expr, expr);
    ((corto_request*)this)->offset = offset;
    ((corto_request*)this)->limit = limit;
    ((corto_request*)this)->content = content;
    corto_setstr(&((corto_request*)this)->param, param);
    return corto_define(this);
}

void _corto_requestSet(corto_request* this, corto_string parent, corto_string expr, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_string param) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_request*)this)->parent, parent);
    corto_setstr(&((corto_request*)this)->expr, expr);
    ((corto_request*)this)->offset = offset;
    ((corto_request*)this)->limit = limit;
    ((corto_request*)this)->content = content;
    corto_setstr(&((corto_request*)this)->param, param);
}

corto_string _corto_requestStr(corto_request* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_request_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_request* corto_requestFromStr(corto_request* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_request_o), str);
    return value;
}

corto_int16 corto_requestCompare(corto_request* dst, corto_request* src) {
    return corto_comparep(dst, corto_request_o, src);
}

corto_int16 _corto_requestInit(corto_request* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_request_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_request_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_requestDeinit(corto_request* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_request_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_result* _corto_resultCreate(corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_augmentseq augments) {
    corto_result* this;
    this = corto_declare(corto_result_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_result*)this)->id, id);
    corto_setstr(&((corto_result*)this)->name, name);
    corto_setstr(&((corto_result*)this)->parent, parent);
    corto_setstr(&((corto_result*)this)->type, type);
    ((corto_result*)this)->value = value;
    corto_copyp(&((corto_result*)this)->augments, corto_augmentseq_o, &augments);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _name, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_augmentseq augments) {
    corto_result* this;
    this = corto_declareChild(_parent, _name, corto_result_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&((corto_result*)this)->id, id);
    corto_setstr(&((corto_result*)this)->name, name);
    corto_setstr(&((corto_result*)this)->parent, parent);
    corto_setstr(&((corto_result*)this)->type, type);
    ((corto_result*)this)->value = value;
    corto_copyp(&((corto_result*)this)->augments, corto_augmentseq_o, &augments);
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultUpdate(corto_result* this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_augmentseq augments) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_setstr(&((corto_result*)this)->id, id);
        corto_setstr(&((corto_result*)this)->name, name);
        corto_setstr(&((corto_result*)this)->parent, parent);
        corto_setstr(&((corto_result*)this)->type, type);
        ((corto_result*)this)->value = value;
        corto_copyp(&((corto_result*)this)->augments, corto_augmentseq_o, &augments);
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

corto_int16 _corto_resultDefine(corto_result* this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_augmentseq augments) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_result*)this)->id, id);
    corto_setstr(&((corto_result*)this)->name, name);
    corto_setstr(&((corto_result*)this)->parent, parent);
    corto_setstr(&((corto_result*)this)->type, type);
    ((corto_result*)this)->value = value;
    corto_copyp(&((corto_result*)this)->augments, corto_augmentseq_o, &augments);
    return corto_define(this);
}

void _corto_resultSet(corto_result* this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_augmentseq augments) {
    CORTO_UNUSED(this);
    corto_setstr(&((corto_result*)this)->id, id);
    corto_setstr(&((corto_result*)this)->name, name);
    corto_setstr(&((corto_result*)this)->parent, parent);
    corto_setstr(&((corto_result*)this)->type, type);
    ((corto_result*)this)->value = value;
    corto_copyp(&((corto_result*)this)->augments, corto_augmentseq_o, &augments);
}

corto_string _corto_resultStr(corto_result* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_result_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_result* corto_resultFromStr(corto_result* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_result_o), str);
    return value;
}

corto_int16 corto_resultCompare(corto_result* dst, corto_result* src) {
    return corto_comparep(dst, corto_result_o, src);
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

corto_resultIter* _corto_resultIterCreate(void) {
    corto_resultIter* this;
    this = corto_declare(corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _name) {
    corto_resultIter* this;
    this = corto_declareChild(_parent, _name, corto_resultIter_o);
    if (!this) {
        return NULL;
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultIterUpdate(corto_resultIter* this) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
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

corto_int16 _corto_resultIterDefine(corto_resultIter* this) {
    CORTO_UNUSED(this);
    return corto_define(this);
}

void _corto_resultIterSet(corto_resultIter* this) {
    CORTO_UNUSED(this);
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

corto_int16 corto_resultIterCompare(corto_resultIter dst, corto_resultIter src) {
    return corto_comparep(&dst, corto_resultIter_o, &src);
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

corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements) {
    corto_resultList* this;
    this = corto_declare(corto_resultList_o);
    if (!this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_resultListClear(*this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*this, &elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_result* elements) {
    corto_resultList* this;
    this = corto_declareChild(_parent, _name, corto_resultList_o);
    if (!this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_resultListClear(*this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*this, &elements[i]);
    }
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_resultListUpdate(corto_resultList* this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        corto_uint32 i = 0;
        corto_resultListClear(*this);
        for (i = 0; i < length; i ++) {
            corto_resultListAppend(*this, &elements[i]);
        }
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

corto_int16 _corto_resultListDefine(corto_resultList* this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(this);
    corto_uint32 i = 0;
    corto_resultListClear(*this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*this, &elements[i]);
    }
    return corto_define(this);
}

void _corto_resultListSet(corto_resultList* this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(this);
    corto_uint32 i = 0;
    corto_resultListClear(*this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*this, &elements[i]);
    }
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

corto_int16 corto_resultListCompare(corto_resultList dst, corto_resultList src) {
    return corto_comparep(&dst, corto_resultList_o, &src);
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

corto_time* _corto_timeCreate(corto_int32 sec, corto_int32 nanosec) {
    corto_time* this;
    this = corto_declare(corto_time_o);
    if (!this) {
        return NULL;
    }
    ((corto_time*)this)->sec = sec;
    ((corto_time*)this)->nanosec = nanosec;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_time* _corto_timeCreateChild(corto_object _parent, corto_string _name, corto_int32 sec, corto_int32 nanosec) {
    corto_time* this;
    this = corto_declareChild(_parent, _name, corto_time_o);
    if (!this) {
        return NULL;
    }
    ((corto_time*)this)->sec = sec;
    ((corto_time*)this)->nanosec = nanosec;
    if (corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _corto_timeUpdate(corto_time* this, corto_int32 sec, corto_int32 nanosec) {
    CORTO_UNUSED(this);
    if (!corto_updateBegin(this)) {
        ((corto_time*)this)->sec = sec;
        ((corto_time*)this)->nanosec = nanosec;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

corto_time* _corto_timeDeclare(void) {
    corto_time* this;
    this = corto_declare(corto_time_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_time* _corto_timeDeclareChild(corto_object _parent, corto_string _name) {
    corto_time* this;
    this = corto_declareChild(_parent, _name, corto_time_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _corto_timeDefine(corto_time* this, corto_int32 sec, corto_int32 nanosec) {
    CORTO_UNUSED(this);
    ((corto_time*)this)->sec = sec;
    ((corto_time*)this)->nanosec = nanosec;
    return corto_define(this);
}

void _corto_timeSet(corto_time* this, corto_int32 sec, corto_int32 nanosec) {
    CORTO_UNUSED(this);
    ((corto_time*)this)->sec = sec;
    ((corto_time*)this)->nanosec = nanosec;
}

corto_string _corto_timeStr(corto_time* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_time_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_time* corto_timeFromStr(corto_time* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_time_o), str);
    return value;
}

corto_int16 corto_timeCompare(corto_time* dst, corto_time* src) {
    return corto_comparep(dst, corto_time_o, src);
}

corto_int16 _corto_timeInit(corto_time* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_time_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_time_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_timeDeinit(corto_time* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(corto_time_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_augmentData* corto_augmentseqAppend(corto_augmentseq *seq, corto_augmentData element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    corto_copyp(&seq->buffer[seq->length-1], corto_augmentData_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_augmentData* corto_augmentseqAppendAlloc(corto_augmentseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void corto_augmentseqSize(corto_augmentseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                corto_valueValueInit(&v, NULL, corto_type(corto_augmentData_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_augmentseqClear(corto_augmentseq *seq) {
    corto_augmentseqSize(seq, 0);
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

corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index) {
    return (corto_result*)corto_llGet(list, index);
}

corto_uint32 corto_resultListSize(corto_resultList list) {
    return corto_llSize(list);
}

void corto_resultListClear(corto_resultList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_result_o);
        corto_dealloc(ptr);
    }
    corto_llClear(list);
}

