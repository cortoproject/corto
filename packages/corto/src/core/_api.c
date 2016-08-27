/* _api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/corto.h>
corto_attr* _corto_attrCreate(corto_attr value) {
    corto_attr* _this;
    _this = corto_attr(corto_declare(corto_attr_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _name, corto_attr value) {
    corto_attr* _this;
    _this = corto_attr(corto_declareChild(_parent, _name, corto_attr_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_attr* _corto_attrDeclare(void) {
    corto_attr* _this;
    _this = corto_attr(corto_declare(corto_attr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _name) {
    corto_attr* _this;
    _this = corto_attr(corto_declareChild(_parent, _name, corto_attr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_attrDefine(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_attr* _corto_attrAssign(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_attrStr(corto_attr value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_attr_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_attr* corto_attrFromStr(corto_attr* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_attr_o), str);
    return value;
}

corto_equalityKind corto_attrCompare(corto_attr dst, corto_attr src) {
    return corto_comparep(&dst, corto_attr_o, &src);
}

corto_int16 _corto_attrInit(corto_attr* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_attr_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_attr_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_attrDeinit(corto_attr* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_attr_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_augmentData* _corto_augmentDataCreate(corto_string id, corto_word data) {
    corto_augmentData* _this;
    _this = corto_augmentData(corto_declare(corto_augmentData_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_augmentData*)_this)->id, id);
    ((corto_augmentData*)_this)->data = data;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_augmentData* _corto_augmentDataCreateChild(corto_object _parent, corto_string _name, corto_string id, corto_word data) {
    corto_augmentData* _this;
    _this = corto_augmentData(corto_declareChild(_parent, _name, corto_augmentData_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_augmentData*)_this)->id, id);
    ((corto_augmentData*)_this)->data = data;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_augmentDataUpdate(corto_augmentData* _this, corto_string id, corto_word data) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_augmentData*)_this)->id, id);
        ((corto_augmentData*)_this)->data = data;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_augmentData* _corto_augmentDataDeclare(void) {
    corto_augmentData* _this;
    _this = corto_augmentData(corto_declare(corto_augmentData_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_augmentData* _corto_augmentDataDeclareChild(corto_object _parent, corto_string _name) {
    corto_augmentData* _this;
    _this = corto_augmentData(corto_declareChild(_parent, _name, corto_augmentData_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_augmentDataDefine(corto_augmentData* _this, corto_string id, corto_word data) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_augmentData*)_this)->id, id);
    ((corto_augmentData*)_this)->data = data;
    return corto_define(_this);
}

corto_augmentData* _corto_augmentDataAssign(corto_augmentData* _this, corto_string id, corto_word data) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_augmentData*)_this)->id, id);
    ((corto_augmentData*)_this)->data = data;
    return _this;
}

corto_string _corto_augmentDataStr(corto_augmentData* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentData_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_augmentData* corto_augmentDataFromStr(corto_augmentData* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_augmentData_o), str);
    return value;
}

corto_equalityKind corto_augmentDataCompare(corto_augmentData* dst, corto_augmentData* src) {
    return corto_comparep(dst, corto_augmentData_o, src);
}

corto_int16 _corto_augmentDataInit(corto_augmentData* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_augmentData_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentData_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_augmentDataDeinit(corto_augmentData* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentData_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_augmentseq* _corto_augmentseqCreate(corto_uint32 length, corto_augmentData* elements) {
    corto_augmentseq* _this;
    _this = corto_augmentseq(corto_declare(corto_augmentseq_o));
    if (!_this) {
        return NULL;
    }
    corto_augmentseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_augmentData_o, &elements[i]);
        }
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_augmentseq* _corto_augmentseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_augmentData* elements) {
    corto_augmentseq* _this;
    _this = corto_augmentseq(corto_declareChild(_parent, _name, corto_augmentseq_o));
    if (!_this) {
        return NULL;
    }
    corto_augmentseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_augmentData_o, &elements[i]);
        }
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_augmentseqUpdate(corto_augmentseq* _this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_augmentseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], corto_augmentData_o, &elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_augmentseq* _corto_augmentseqDeclare(void) {
    corto_augmentseq* _this;
    _this = corto_augmentseq(corto_declare(corto_augmentseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_augmentseq* _corto_augmentseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_augmentseq* _this;
    _this = corto_augmentseq(corto_declareChild(_parent, _name, corto_augmentseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_augmentseqDefine(corto_augmentseq* _this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(_this);
    corto_augmentseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_augmentData_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

corto_augmentseq* _corto_augmentseqAssign(corto_augmentseq* _this, corto_uint32 length, corto_augmentData* elements) {
    CORTO_UNUSED(_this);
    corto_augmentseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_augmentData_o, &elements[i]);
        }
    }
    return _this;
}

corto_string _corto_augmentseqStr(corto_augmentseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_augmentseq* corto_augmentseqFromStr(corto_augmentseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_augmentseq_o), str);
    return value;
}

corto_equalityKind corto_augmentseqCompare(corto_augmentseq dst, corto_augmentseq src) {
    return corto_comparep(&dst, corto_augmentseq_o, &src);
}

corto_int16 _corto_augmentseqInit(corto_augmentseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_augmentseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_augmentseqDeinit(corto_augmentseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_augmentseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_dispatcher _corto_dispatcherCreate(void) {
    corto_dispatcher _this;
    _this = corto_dispatcher(corto_declare(corto_dispatcher_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _name) {
    corto_dispatcher _this;
    _this = corto_dispatcher(corto_declareChild(_parent, _name, corto_dispatcher_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_dispatcher _corto_dispatcherDeclare(void) {
    corto_dispatcher _this;
    _this = corto_dispatcher(corto_declare(corto_dispatcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _name) {
    corto_dispatcher _this;
    _this = corto_dispatcher(corto_declareChild(_parent, _name, corto_dispatcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_dispatcherDefine(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_dispatcher _corto_dispatcherAssign(corto_dispatcher _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_dispatcherStr(corto_dispatcher value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_dispatcher_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_dispatcher corto_dispatcherFromStr(corto_dispatcher value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_dispatcher_o), str);
    return value;
}

corto_equalityKind _corto_dispatcherCompare(corto_dispatcher dst, corto_dispatcher src) {
    return corto_compare(dst, src);
}

corto_event _corto_eventCreate(corto_uint16 kind) {
    corto_event _this;
    _this = corto_event(corto_declare(corto_event_o));
    if (!_this) {
        return NULL;
    }
    ((corto_event)_this)->kind = kind;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_event _corto_eventCreateChild(corto_object _parent, corto_string _name, corto_uint16 kind) {
    corto_event _this;
    _this = corto_event(corto_declareChild(_parent, _name, corto_event_o));
    if (!_this) {
        return NULL;
    }
    ((corto_event)_this)->kind = kind;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_eventUpdate(corto_event _this, corto_uint16 kind) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_event)_this)->kind = kind;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_event _corto_eventDeclare(void) {
    corto_event _this;
    _this = corto_event(corto_declare(corto_event_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_event _corto_eventDeclareChild(corto_object _parent, corto_string _name) {
    corto_event _this;
    _this = corto_event(corto_declareChild(_parent, _name, corto_event_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_eventDefine(corto_event _this, corto_uint16 kind) {
    CORTO_UNUSED(_this);
    ((corto_event)_this)->kind = kind;
    return corto_define(_this);
}

corto_event _corto_eventAssign(corto_event _this, corto_uint16 kind) {
    CORTO_UNUSED(_this);
    ((corto_event)_this)->kind = kind;
    return _this;
}

corto_string _corto_eventStr(corto_event value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_event_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_event corto_eventFromStr(corto_event value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_event_o), str);
    return value;
}

corto_equalityKind _corto_eventCompare(corto_event dst, corto_event src) {
    return corto_compare(dst, src);
}

corto_eventMask* _corto_eventMaskCreate(corto_eventMask value) {
    corto_eventMask* _this;
    _this = corto_eventMask(corto_declare(corto_eventMask_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _name, corto_eventMask value) {
    corto_eventMask* _this;
    _this = corto_eventMask(corto_declareChild(_parent, _name, corto_eventMask_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_eventMask* _corto_eventMaskDeclare(void) {
    corto_eventMask* _this;
    _this = corto_eventMask(corto_declare(corto_eventMask_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _name) {
    corto_eventMask* _this;
    _this = corto_eventMask(corto_declareChild(_parent, _name, corto_eventMask_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_eventMask* _corto_eventMaskAssign(corto_eventMask* _this, corto_eventMask value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_eventMaskStr(corto_eventMask value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_eventMask_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_eventMask* corto_eventMaskFromStr(corto_eventMask* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_eventMask_o), str);
    return value;
}

corto_equalityKind corto_eventMaskCompare(corto_eventMask dst, corto_eventMask src) {
    return corto_comparep(&dst, corto_eventMask_o, &src);
}

corto_int16 _corto_eventMaskInit(corto_eventMask* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_eventMask_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_eventMask_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_eventMaskDeinit(corto_eventMask* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_eventMask_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_frame* _corto_frameCreate(corto_frameKind kind, corto_uint64 value) {
    corto_frame* _this;
    _this = corto_frame(corto_declare(corto_frame_o));
    if (!_this) {
        return NULL;
    }
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_frame* _corto_frameCreateChild(corto_object _parent, corto_string _name, corto_frameKind kind, corto_uint64 value) {
    corto_frame* _this;
    _this = corto_frame(corto_declareChild(_parent, _name, corto_frame_o));
    if (!_this) {
        return NULL;
    }
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_frameUpdate(corto_frame* _this, corto_frameKind kind, corto_uint64 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_frame*)_this)->kind = kind;
        ((corto_frame*)_this)->value = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_frame* _corto_frameDeclare(void) {
    corto_frame* _this;
    _this = corto_frame(corto_declare(corto_frame_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_frame* _corto_frameDeclareChild(corto_object _parent, corto_string _name) {
    corto_frame* _this;
    _this = corto_frame(corto_declareChild(_parent, _name, corto_frame_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_frameDefine(corto_frame* _this, corto_frameKind kind, corto_uint64 value) {
    CORTO_UNUSED(_this);
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    return corto_define(_this);
}

corto_frame* _corto_frameAssign(corto_frame* _this, corto_frameKind kind, corto_uint64 value) {
    CORTO_UNUSED(_this);
    ((corto_frame*)_this)->kind = kind;
    ((corto_frame*)_this)->value = value;
    return _this;
}

corto_string _corto_frameStr(corto_frame* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_frame_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_frame* corto_frameFromStr(corto_frame* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_frame_o), str);
    return value;
}

corto_equalityKind corto_frameCompare(corto_frame* dst, corto_frame* src) {
    return corto_comparep(dst, corto_frame_o, src);
}

corto_int16 _corto_frameInit(corto_frame* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_frame_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_frame_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_frameDeinit(corto_frame* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_frame_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_frameKind* _corto_frameKindCreate(corto_frameKind value) {
    corto_frameKind* _this;
    _this = corto_frameKind(corto_declare(corto_frameKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_frameKind* _corto_frameKindCreateChild(corto_object _parent, corto_string _name, corto_frameKind value) {
    corto_frameKind* _this;
    _this = corto_frameKind(corto_declareChild(_parent, _name, corto_frameKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_frameKindUpdate(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_frameKind* _corto_frameKindDeclare(void) {
    corto_frameKind* _this;
    _this = corto_frameKind(corto_declare(corto_frameKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_frameKind* _corto_frameKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_frameKind* _this;
    _this = corto_frameKind(corto_declareChild(_parent, _name, corto_frameKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_frameKindDefine(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_frameKind* _corto_frameKindAssign(corto_frameKind* _this, corto_frameKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_frameKindStr(corto_frameKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_frameKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_frameKind* corto_frameKindFromStr(corto_frameKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_frameKind_o), str);
    return value;
}

corto_equalityKind corto_frameKindCompare(corto_frameKind dst, corto_frameKind src) {
    return corto_comparep(&dst, corto_frameKind_o, &src);
}

corto_int16 _corto_frameKindInit(corto_frameKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_frameKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_frameKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_frameKindDeinit(corto_frameKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_frameKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_invokeEvent _corto_invokeEventCreate(corto_mount mount, corto_object instance, corto_function function, corto_word args) {
    corto_invokeEvent _this;
    _this = corto_invokeEvent(corto_declare(corto_invokeEvent_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_invokeEvent)_this)->mount, mount);
    corto_setref(&((corto_invokeEvent)_this)->instance, instance);
    corto_setref(&((corto_invokeEvent)_this)->function, function);
    ((corto_invokeEvent)_this)->args = args;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_invokeEvent _corto_invokeEventCreateChild(corto_object _parent, corto_string _name, corto_mount mount, corto_object instance, corto_function function, corto_word args) {
    corto_invokeEvent _this;
    _this = corto_invokeEvent(corto_declareChild(_parent, _name, corto_invokeEvent_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_invokeEvent)_this)->mount, mount);
    corto_setref(&((corto_invokeEvent)_this)->instance, instance);
    corto_setref(&((corto_invokeEvent)_this)->function, function);
    ((corto_invokeEvent)_this)->args = args;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_invokeEventUpdate(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, corto_word args) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_invokeEvent)_this)->mount, mount);
        corto_setref(&((corto_invokeEvent)_this)->instance, instance);
        corto_setref(&((corto_invokeEvent)_this)->function, function);
        ((corto_invokeEvent)_this)->args = args;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_invokeEvent _corto_invokeEventDeclare(void) {
    corto_invokeEvent _this;
    _this = corto_invokeEvent(corto_declare(corto_invokeEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_invokeEvent _corto_invokeEventDeclareChild(corto_object _parent, corto_string _name) {
    corto_invokeEvent _this;
    _this = corto_invokeEvent(corto_declareChild(_parent, _name, corto_invokeEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_invokeEventDefine(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, corto_word args) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_invokeEvent)_this)->mount, mount);
    corto_setref(&((corto_invokeEvent)_this)->instance, instance);
    corto_setref(&((corto_invokeEvent)_this)->function, function);
    ((corto_invokeEvent)_this)->args = args;
    return corto_define(_this);
}

corto_invokeEvent _corto_invokeEventAssign(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, corto_word args) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_invokeEvent)_this)->mount, mount);
    corto_setref(&((corto_invokeEvent)_this)->instance, instance);
    corto_setref(&((corto_invokeEvent)_this)->function, function);
    ((corto_invokeEvent)_this)->args = args;
    return _this;
}

corto_string _corto_invokeEventStr(corto_invokeEvent value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_invokeEvent_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_invokeEvent corto_invokeEventFromStr(corto_invokeEvent value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_invokeEvent_o), str);
    return value;
}

corto_equalityKind _corto_invokeEventCompare(corto_invokeEvent dst, corto_invokeEvent src) {
    return corto_compare(dst, src);
}

corto_loader _corto_loaderCreate(void) {
    corto_loader _this;
    _this = corto_loader(corto_declare(corto_loader_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_loader _corto_loaderCreateChild(corto_object _parent, corto_string _name) {
    corto_loader _this;
    _this = corto_loader(corto_declareChild(_parent, _name, corto_loader_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_loaderUpdate(corto_loader _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_loader _corto_loaderDeclare(void) {
    corto_loader _this;
    _this = corto_loader(corto_declare(corto_loader_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_loader _corto_loaderDeclareChild(corto_object _parent, corto_string _name) {
    corto_loader _this;
    _this = corto_loader(corto_declareChild(_parent, _name, corto_loader_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_loaderDefine(corto_loader _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_loader _corto_loaderAssign(corto_loader _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_loaderStr(corto_loader value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_loader_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_loader corto_loaderFromStr(corto_loader value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_loader_o), str);
    return value;
}

corto_equalityKind _corto_loaderCompare(corto_loader dst, corto_loader src) {
    return corto_compare(dst, src);
}

corto_mount _corto_mountCreate(corto_object mount, corto_eventMask mask, corto_string type, corto_attr attr, corto_mountKind kind, corto_string contentType, corto_string policy) {
    corto_mount _this;
    _this = corto_mount(corto_declare(corto_mount_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_mount)_this)->mount, mount);
    ((corto_mount)_this)->mask = mask;
    corto_setstr(&((corto_mount)_this)->type, type);
    ((corto_mount)_this)->attr = attr;
    ((corto_mount)_this)->kind = kind;
    corto_setstr(&((corto_mount)_this)->contentType, contentType);
    corto_setstr(&((corto_mount)_this)->policy, policy);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mount _corto_mountCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_eventMask mask, corto_string type, corto_attr attr, corto_mountKind kind, corto_string contentType, corto_string policy) {
    corto_mount _this;
    _this = corto_mount(corto_declareChild(_parent, _name, corto_mount_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_mount)_this)->mount, mount);
    ((corto_mount)_this)->mask = mask;
    corto_setstr(&((corto_mount)_this)->type, type);
    ((corto_mount)_this)->attr = attr;
    ((corto_mount)_this)->kind = kind;
    corto_setstr(&((corto_mount)_this)->contentType, contentType);
    corto_setstr(&((corto_mount)_this)->policy, policy);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountUpdate(corto_mount _this, corto_object mount, corto_eventMask mask, corto_string type, corto_attr attr, corto_mountKind kind, corto_string contentType, corto_string policy) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_mount)_this)->mount, mount);
        ((corto_mount)_this)->mask = mask;
        corto_setstr(&((corto_mount)_this)->type, type);
        ((corto_mount)_this)->attr = attr;
        ((corto_mount)_this)->kind = kind;
        corto_setstr(&((corto_mount)_this)->contentType, contentType);
        corto_setstr(&((corto_mount)_this)->policy, policy);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mount _corto_mountDeclare(void) {
    corto_mount _this;
    _this = corto_mount(corto_declare(corto_mount_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mount _corto_mountDeclareChild(corto_object _parent, corto_string _name) {
    corto_mount _this;
    _this = corto_mount(corto_declareChild(_parent, _name, corto_mount_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountDefine(corto_mount _this, corto_object mount, corto_eventMask mask, corto_string type, corto_attr attr, corto_mountKind kind, corto_string contentType, corto_string policy) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_mount)_this)->mount, mount);
    ((corto_mount)_this)->mask = mask;
    corto_setstr(&((corto_mount)_this)->type, type);
    ((corto_mount)_this)->attr = attr;
    ((corto_mount)_this)->kind = kind;
    corto_setstr(&((corto_mount)_this)->contentType, contentType);
    corto_setstr(&((corto_mount)_this)->policy, policy);
    return corto_define(_this);
}

corto_mount _corto_mountAssign(corto_mount _this, corto_object mount, corto_eventMask mask, corto_string type, corto_attr attr, corto_mountKind kind, corto_string contentType, corto_string policy) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_mount)_this)->mount, mount);
    ((corto_mount)_this)->mask = mask;
    corto_setstr(&((corto_mount)_this)->type, type);
    ((corto_mount)_this)->attr = attr;
    ((corto_mount)_this)->kind = kind;
    corto_setstr(&((corto_mount)_this)->contentType, contentType);
    corto_setstr(&((corto_mount)_this)->policy, policy);
    return _this;
}

corto_string _corto_mountStr(corto_mount value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_mount_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_mount corto_mountFromStr(corto_mount value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mount_o), str);
    return value;
}

corto_equalityKind _corto_mountCompare(corto_mount dst, corto_mount src) {
    return corto_compare(dst, src);
}

corto_mountKind* _corto_mountKindCreate(corto_mountKind value) {
    corto_mountKind* _this;
    _this = corto_mountKind(corto_declare(corto_mountKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mountKind* _corto_mountKindCreateChild(corto_object _parent, corto_string _name, corto_mountKind value) {
    corto_mountKind* _this;
    _this = corto_mountKind(corto_declareChild(_parent, _name, corto_mountKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountKindUpdate(corto_mountKind* _this, corto_mountKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountKind* _corto_mountKindDeclare(void) {
    corto_mountKind* _this;
    _this = corto_mountKind(corto_declare(corto_mountKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountKind* _corto_mountKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_mountKind* _this;
    _this = corto_mountKind(corto_declareChild(_parent, _name, corto_mountKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountKindDefine(corto_mountKind* _this, corto_mountKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_mountKind* _corto_mountKindAssign(corto_mountKind* _this, corto_mountKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_mountKindStr(corto_mountKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_mountKind* corto_mountKindFromStr(corto_mountKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mountKind_o), str);
    return value;
}

corto_equalityKind corto_mountKindCompare(corto_mountKind dst, corto_mountKind src) {
    return corto_comparep(&dst, corto_mountKind_o, &src);
}

corto_int16 _corto_mountKindInit(corto_mountKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_mountKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_mountKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_mountKindDeinit(corto_mountKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_mountPolicy* _corto_mountPolicyCreate(corto_float64 sampleRate) {
    corto_mountPolicy* _this;
    _this = corto_mountPolicy(corto_declare(corto_mountPolicy_o));
    if (!_this) {
        return NULL;
    }
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mountPolicy* _corto_mountPolicyCreateChild(corto_object _parent, corto_string _name, corto_float64 sampleRate) {
    corto_mountPolicy* _this;
    _this = corto_mountPolicy(corto_declareChild(_parent, _name, corto_mountPolicy_o));
    if (!_this) {
        return NULL;
    }
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountPolicyUpdate(corto_mountPolicy* _this, corto_float64 sampleRate) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountPolicy* _corto_mountPolicyDeclare(void) {
    corto_mountPolicy* _this;
    _this = corto_mountPolicy(corto_declare(corto_mountPolicy_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountPolicy* _corto_mountPolicyDeclareChild(corto_object _parent, corto_string _name) {
    corto_mountPolicy* _this;
    _this = corto_mountPolicy(corto_declareChild(_parent, _name, corto_mountPolicy_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountPolicyDefine(corto_mountPolicy* _this, corto_float64 sampleRate) {
    CORTO_UNUSED(_this);
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    return corto_define(_this);
}

corto_mountPolicy* _corto_mountPolicyAssign(corto_mountPolicy* _this, corto_float64 sampleRate) {
    CORTO_UNUSED(_this);
    ((corto_mountPolicy*)_this)->sampleRate = sampleRate;
    return _this;
}

corto_string _corto_mountPolicyStr(corto_mountPolicy* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountPolicy_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_mountPolicy* corto_mountPolicyFromStr(corto_mountPolicy* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mountPolicy_o), str);
    return value;
}

corto_equalityKind corto_mountPolicyCompare(corto_mountPolicy* dst, corto_mountPolicy* src) {
    return corto_comparep(dst, corto_mountPolicy_o, src);
}

corto_int16 _corto_mountPolicyInit(corto_mountPolicy* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_mountPolicy_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_mountPolicy_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_mountPolicyDeinit(corto_mountPolicy* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountPolicy_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_mountStats* _corto_mountStatsCreate(corto_uint64 declares, corto_uint64 updates, corto_uint64 deletes) {
    corto_mountStats* _this;
    _this = corto_mountStats(corto_declare(corto_mountStats_o));
    if (!_this) {
        return NULL;
    }
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mountStats* _corto_mountStatsCreateChild(corto_object _parent, corto_string _name, corto_uint64 declares, corto_uint64 updates, corto_uint64 deletes) {
    corto_mountStats* _this;
    _this = corto_mountStats(corto_declareChild(_parent, _name, corto_mountStats_o));
    if (!_this) {
        return NULL;
    }
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountStatsUpdate(corto_mountStats* _this, corto_uint64 declares, corto_uint64 updates, corto_uint64 deletes) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_mountStats*)_this)->declares = declares;
        ((corto_mountStats*)_this)->updates = updates;
        ((corto_mountStats*)_this)->deletes = deletes;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountStats* _corto_mountStatsDeclare(void) {
    corto_mountStats* _this;
    _this = corto_mountStats(corto_declare(corto_mountStats_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountStats* _corto_mountStatsDeclareChild(corto_object _parent, corto_string _name) {
    corto_mountStats* _this;
    _this = corto_mountStats(corto_declareChild(_parent, _name, corto_mountStats_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountStatsDefine(corto_mountStats* _this, corto_uint64 declares, corto_uint64 updates, corto_uint64 deletes) {
    CORTO_UNUSED(_this);
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    return corto_define(_this);
}

corto_mountStats* _corto_mountStatsAssign(corto_mountStats* _this, corto_uint64 declares, corto_uint64 updates, corto_uint64 deletes) {
    CORTO_UNUSED(_this);
    ((corto_mountStats*)_this)->declares = declares;
    ((corto_mountStats*)_this)->updates = updates;
    ((corto_mountStats*)_this)->deletes = deletes;
    return _this;
}

corto_string _corto_mountStatsStr(corto_mountStats* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountStats_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_mountStats* corto_mountStatsFromStr(corto_mountStats* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mountStats_o), str);
    return value;
}

corto_equalityKind corto_mountStatsCompare(corto_mountStats* dst, corto_mountStats* src) {
    return corto_comparep(dst, corto_mountStats_o, src);
}

corto_int16 _corto_mountStatsInit(corto_mountStats* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_mountStats_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_mountStats_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_mountStatsDeinit(corto_mountStats* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountStats_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_mountSubscription* _corto_mountSubscriptionCreate(corto_string parent, corto_string expr, corto_eventMask mask, corto_uint32 count, corto_word userData) {
    corto_mountSubscription* _this;
    _this = corto_mountSubscription(corto_declare(corto_mountSubscription_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_mountSubscription*)_this)->parent, parent);
    corto_setstr(&((corto_mountSubscription*)_this)->expr, expr);
    ((corto_mountSubscription*)_this)->mask = mask;
    ((corto_mountSubscription*)_this)->count = count;
    ((corto_mountSubscription*)_this)->userData = userData;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mountSubscription* _corto_mountSubscriptionCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string expr, corto_eventMask mask, corto_uint32 count, corto_word userData) {
    corto_mountSubscription* _this;
    _this = corto_mountSubscription(corto_declareChild(_parent, _name, corto_mountSubscription_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_mountSubscription*)_this)->parent, parent);
    corto_setstr(&((corto_mountSubscription*)_this)->expr, expr);
    ((corto_mountSubscription*)_this)->mask = mask;
    ((corto_mountSubscription*)_this)->count = count;
    ((corto_mountSubscription*)_this)->userData = userData;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionUpdate(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, corto_uint32 count, corto_word userData) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_mountSubscription*)_this)->parent, parent);
        corto_setstr(&((corto_mountSubscription*)_this)->expr, expr);
        ((corto_mountSubscription*)_this)->mask = mask;
        ((corto_mountSubscription*)_this)->count = count;
        ((corto_mountSubscription*)_this)->userData = userData;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountSubscription* _corto_mountSubscriptionDeclare(void) {
    corto_mountSubscription* _this;
    _this = corto_mountSubscription(corto_declare(corto_mountSubscription_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountSubscription* _corto_mountSubscriptionDeclareChild(corto_object _parent, corto_string _name) {
    corto_mountSubscription* _this;
    _this = corto_mountSubscription(corto_declareChild(_parent, _name, corto_mountSubscription_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionDefine(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, corto_uint32 count, corto_word userData) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_mountSubscription*)_this)->parent, parent);
    corto_setstr(&((corto_mountSubscription*)_this)->expr, expr);
    ((corto_mountSubscription*)_this)->mask = mask;
    ((corto_mountSubscription*)_this)->count = count;
    ((corto_mountSubscription*)_this)->userData = userData;
    return corto_define(_this);
}

corto_mountSubscription* _corto_mountSubscriptionAssign(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, corto_uint32 count, corto_word userData) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_mountSubscription*)_this)->parent, parent);
    corto_setstr(&((corto_mountSubscription*)_this)->expr, expr);
    ((corto_mountSubscription*)_this)->mask = mask;
    ((corto_mountSubscription*)_this)->count = count;
    ((corto_mountSubscription*)_this)->userData = userData;
    return _this;
}

corto_string _corto_mountSubscriptionStr(corto_mountSubscription* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscription_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionFromStr(corto_mountSubscription* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mountSubscription_o), str);
    return value;
}

corto_equalityKind corto_mountSubscriptionCompare(corto_mountSubscription* dst, corto_mountSubscription* src) {
    return corto_comparep(dst, corto_mountSubscription_o, src);
}

corto_int16 _corto_mountSubscriptionInit(corto_mountSubscription* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_mountSubscription_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscription_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_mountSubscriptionDeinit(corto_mountSubscription* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscription_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListCreate(corto_uint32 length, corto_mountSubscription* elements) {
    corto_mountSubscriptionList* _this;
    _this = corto_mountSubscriptionList(corto_declare(corto_mountSubscriptionList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_mountSubscription* elements) {
    corto_mountSubscriptionList* _this;
    _this = corto_mountSubscriptionList(corto_declareChild(_parent, _name, corto_mountSubscriptionList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_uint32 i = 0;
        corto_mountSubscriptionListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_mountSubscriptionListAppend(*_this, &elements[i]);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListDeclare(void) {
    corto_mountSubscriptionList* _this;
    _this = corto_mountSubscriptionList(corto_declare(corto_mountSubscriptionList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_mountSubscriptionList* _corto_mountSubscriptionListDeclareChild(corto_object _parent, corto_string _name) {
    corto_mountSubscriptionList* _this;
    _this = corto_mountSubscriptionList(corto_declareChild(_parent, _name, corto_mountSubscriptionList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mountSubscriptionListDefine(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    return corto_define(_this);
}

corto_mountSubscriptionList* _corto_mountSubscriptionListAssign(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_mountSubscriptionListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_mountSubscriptionListAppend(*_this, &elements[i]);
    }
    return _this;
}

corto_string _corto_mountSubscriptionListStr(corto_mountSubscriptionList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscriptionList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_mountSubscriptionList* corto_mountSubscriptionListFromStr(corto_mountSubscriptionList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_mountSubscriptionList_o), str);
    return value;
}

corto_equalityKind corto_mountSubscriptionListCompare(corto_mountSubscriptionList dst, corto_mountSubscriptionList src) {
    return corto_comparep(&dst, corto_mountSubscriptionList_o, &src);
}

corto_int16 _corto_mountSubscriptionListInit(corto_mountSubscriptionList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_mountSubscriptionList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscriptionList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_mountSubscriptionListDeinit(corto_mountSubscriptionList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_mountSubscriptionList_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_notifyAction* _corto_notifyActionCreate(corto_object instance, corto_function procedure) {
    corto_notifyAction* _this;
    _this = corto_notifyAction(corto_declare(corto_notifyAction_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_notifyAction* _corto_notifyActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_notifyAction* _this;
    _this = corto_notifyAction(corto_declareChild(_parent, _name, corto_notifyAction_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_notifyActionUpdate(corto_notifyAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_notifyAction* _corto_notifyActionDeclare(void) {
    corto_notifyAction* _this;
    _this = corto_notifyAction(corto_declare(corto_notifyAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_notifyAction* _corto_notifyActionDeclareChild(corto_object _parent, corto_string _name) {
    corto_notifyAction* _this;
    _this = corto_notifyAction(corto_declareChild(_parent, _name, corto_notifyAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_notifyActionDefine(corto_notifyAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_notifyAction* _corto_notifyActionAssign(corto_notifyAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_string _corto_notifyActionStr(corto_notifyAction* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_notifyAction_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_notifyAction_o), str);
    return value;
}

corto_equalityKind corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src) {
    return corto_comparep(dst, corto_notifyAction_o, src);
}

corto_int16 _corto_notifyActionInit(corto_notifyAction* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_notifyAction_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_notifyAction_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_notifyActionDeinit(corto_notifyAction* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_notifyAction_o), value);
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
    d->_parent.instance = NULL;
    d->_parent.procedure = corto_functionDeclare();
    d->_parent.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->_parent.procedure, "(object observable)");
    d->_parent.procedure->fptr = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int16 corto_notifyActionInitCInstance(corto_notifyAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_object)) {
    d->_parent.instance = instance;
    corto_claim(instance);
    d->_parent.procedure = corto_functionDeclare();
    d->_parent.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->_parent.procedure, "(object instance, object observable)");
    d->_parent.procedure->fptr = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_observableEvent _corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    corto_observableEvent _this;
    _this = corto_observableEvent(corto_declare(corto_observableEvent_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_observableEvent)_this)->observer, observer);
    corto_setref(&((corto_observableEvent)_this)->me, me);
    corto_setref(&((corto_observableEvent)_this)->source, source);
    corto_setref(&((corto_observableEvent)_this)->observable, observable);
    ((corto_observableEvent)_this)->mask = mask;
    ((corto_observableEvent)_this)->thread = thread;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_observableEvent _corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    corto_observableEvent _this;
    _this = corto_observableEvent(corto_declareChild(_parent, _name, corto_observableEvent_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_observableEvent)_this)->observer, observer);
    corto_setref(&((corto_observableEvent)_this)->me, me);
    corto_setref(&((corto_observableEvent)_this)->source, source);
    corto_setref(&((corto_observableEvent)_this)->observable, observable);
    ((corto_observableEvent)_this)->mask = mask;
    ((corto_observableEvent)_this)->thread = thread;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_observableEventUpdate(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_observableEvent)_this)->observer, observer);
        corto_setref(&((corto_observableEvent)_this)->me, me);
        corto_setref(&((corto_observableEvent)_this)->source, source);
        corto_setref(&((corto_observableEvent)_this)->observable, observable);
        ((corto_observableEvent)_this)->mask = mask;
        ((corto_observableEvent)_this)->thread = thread;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_observableEvent _corto_observableEventDeclare(void) {
    corto_observableEvent _this;
    _this = corto_observableEvent(corto_declare(corto_observableEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_observableEvent _corto_observableEventDeclareChild(corto_object _parent, corto_string _name) {
    corto_observableEvent _this;
    _this = corto_observableEvent(corto_declareChild(_parent, _name, corto_observableEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_observableEventDefine(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_observableEvent)_this)->observer, observer);
    corto_setref(&((corto_observableEvent)_this)->me, me);
    corto_setref(&((corto_observableEvent)_this)->source, source);
    corto_setref(&((corto_observableEvent)_this)->observable, observable);
    ((corto_observableEvent)_this)->mask = mask;
    ((corto_observableEvent)_this)->thread = thread;
    return corto_define(_this);
}

corto_observableEvent _corto_observableEventAssign(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable, corto_eventMask mask, corto_word thread) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_observableEvent)_this)->observer, observer);
    corto_setref(&((corto_observableEvent)_this)->me, me);
    corto_setref(&((corto_observableEvent)_this)->source, source);
    corto_setref(&((corto_observableEvent)_this)->observable, observable);
    ((corto_observableEvent)_this)->mask = mask;
    ((corto_observableEvent)_this)->thread = thread;
    return _this;
}

corto_string _corto_observableEventStr(corto_observableEvent value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_observableEvent_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_observableEvent corto_observableEventFromStr(corto_observableEvent value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observableEvent_o), str);
    return value;
}

corto_equalityKind _corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src) {
    return corto_compare(dst, src);
}

corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(void)) {
    corto_observer _this;
    _this = corto_observer(corto_declare(corto_observer_o));
    if (!_this) {
        return NULL;
    }
    ((corto_observer)_this)->mask = mask;
    corto_setref(&((corto_observer)_this)->observable, observable);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _name, corto_eventMask mask, corto_object observable, void(*_impl)(void)) {
    corto_observer _this;
    _this = corto_observer(corto_declareChild(_parent, _name, corto_observer_o));
    if (!_this) {
        return NULL;
    }
    ((corto_observer)_this)->mask = mask;
    corto_setref(&((corto_observer)_this)->observable, observable);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_observer)_this)->mask = mask;
        corto_setref(&((corto_observer)_this)->observable, observable);
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_observer _corto_observerDeclare(void) {
    corto_observer _this;
    _this = corto_observer(corto_declare(corto_observer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _name) {
    corto_observer _this;
    _this = corto_observer(corto_declareChild(_parent, _name, corto_observer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    ((corto_observer)_this)->mask = mask;
    corto_setref(&((corto_observer)_this)->observable, observable);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_observer _corto_observerAssign(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    ((corto_observer)_this)->mask = mask;
    corto_setref(&((corto_observer)_this)->observable, observable);
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_observerStr(corto_observer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_observer_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_observer corto_observerFromStr(corto_observer value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observer_o), str);
    return value;
}

corto_equalityKind _corto_observerCompare(corto_observer dst, corto_observer src) {
    return corto_compare(dst, src);
}

corto_observerseq* _corto_observerseqCreate(corto_uint32 length, corto_observer* elements) {
    corto_observerseq* _this;
    _this = corto_observerseq(corto_declare(corto_observerseq_o));
    if (!_this) {
        return NULL;
    }
    corto_observerseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_observerseq* _corto_observerseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_observer* elements) {
    corto_observerseq* _this;
    _this = corto_observerseq(corto_declareChild(_parent, _name, corto_observerseq_o));
    if (!_this) {
        return NULL;
    }
    corto_observerseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_observerseqUpdate(corto_observerseq* _this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_observerseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&_this->buffer[i], elements[i]);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_observerseq* _corto_observerseqDeclare(void) {
    corto_observerseq* _this;
    _this = corto_observerseq(corto_declare(corto_observerseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_observerseq* _corto_observerseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_observerseq* _this;
    _this = corto_observerseq(corto_declareChild(_parent, _name, corto_observerseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_observerseqDefine(corto_observerseq* _this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(_this);
    corto_observerseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_observerseq* _corto_observerseqAssign(corto_observerseq* _this, corto_uint32 length, corto_observer* elements) {
    CORTO_UNUSED(_this);
    corto_observerseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _corto_observerseqStr(corto_observerseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_observerseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_observerseq* corto_observerseqFromStr(corto_observerseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_observerseq_o), str);
    return value;
}

corto_equalityKind corto_observerseqCompare(corto_observerseq dst, corto_observerseq src) {
    return corto_comparep(&dst, corto_observerseq_o, &src);
}

corto_int16 _corto_observerseqInit(corto_observerseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_observerseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_observerseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_observerseqDeinit(corto_observerseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_observerseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value) {
    corto_operatorKind* _this;
    _this = corto_operatorKind(corto_declare(corto_operatorKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _name, corto_operatorKind value) {
    corto_operatorKind* _this;
    _this = corto_operatorKind(corto_declareChild(_parent, _name, corto_operatorKind_o));
    if (!_this) {
        return NULL;
    }
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_operatorKind* _corto_operatorKindDeclare(void) {
    corto_operatorKind* _this;
    _this = corto_operatorKind(corto_declare(corto_operatorKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_operatorKind* _this;
    _this = corto_operatorKind(corto_declareChild(_parent, _name, corto_operatorKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_operatorKind* _corto_operatorKindAssign(corto_operatorKind* _this, corto_operatorKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_operatorKindStr(corto_operatorKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_operatorKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_operatorKind* corto_operatorKindFromStr(corto_operatorKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_operatorKind_o), str);
    return value;
}

corto_equalityKind corto_operatorKindCompare(corto_operatorKind dst, corto_operatorKind src) {
    return corto_comparep(&dst, corto_operatorKind_o, &src);
}

corto_int16 _corto_operatorKindInit(corto_operatorKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_operatorKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_operatorKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_operatorKindDeinit(corto_operatorKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_operatorKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_package _corto_packageCreate(corto_string url) {
    corto_package _this;
    _this = corto_package(corto_declare(corto_package_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_package)_this)->url, url);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_package _corto_packageCreateChild(corto_object _parent, corto_string _name, corto_string url) {
    corto_package _this;
    _this = corto_package(corto_declareChild(_parent, _name, corto_package_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_package)_this)->url, url);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_packageUpdate(corto_package _this, corto_string url) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_package)_this)->url, url);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_package _corto_packageDeclare(void) {
    corto_package _this;
    _this = corto_package(corto_declare(corto_package_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _name) {
    corto_package _this;
    _this = corto_package(corto_declareChild(_parent, _name, corto_package_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_packageDefine(corto_package _this, corto_string url) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_package)_this)->url, url);
    return corto_define(_this);
}

corto_package _corto_packageAssign(corto_package _this, corto_string url) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_package)_this)->url, url);
    return _this;
}

corto_string _corto_packageStr(corto_package value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_package_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_package corto_packageFromStr(corto_package value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_package_o), str);
    return value;
}

corto_equalityKind _corto_packageCompare(corto_package dst, corto_package src) {
    return corto_compare(dst, src);
}

corto_position* _corto_positionCreate(corto_float64 latitude, corto_float64 longitude) {
    corto_position* _this;
    _this = corto_position(corto_declare(corto_position_o));
    if (!_this) {
        return NULL;
    }
    ((corto_position*)_this)->latitude = latitude;
    ((corto_position*)_this)->longitude = longitude;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_position* _corto_positionCreateChild(corto_object _parent, corto_string _name, corto_float64 latitude, corto_float64 longitude) {
    corto_position* _this;
    _this = corto_position(corto_declareChild(_parent, _name, corto_position_o));
    if (!_this) {
        return NULL;
    }
    ((corto_position*)_this)->latitude = latitude;
    ((corto_position*)_this)->longitude = longitude;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_positionUpdate(corto_position* _this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_position*)_this)->latitude = latitude;
        ((corto_position*)_this)->longitude = longitude;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_position* _corto_positionDeclare(void) {
    corto_position* _this;
    _this = corto_position(corto_declare(corto_position_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_position* _corto_positionDeclareChild(corto_object _parent, corto_string _name) {
    corto_position* _this;
    _this = corto_position(corto_declareChild(_parent, _name, corto_position_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_positionDefine(corto_position* _this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(_this);
    ((corto_position*)_this)->latitude = latitude;
    ((corto_position*)_this)->longitude = longitude;
    return corto_define(_this);
}

corto_position* _corto_positionAssign(corto_position* _this, corto_float64 latitude, corto_float64 longitude) {
    CORTO_UNUSED(_this);
    ((corto_position*)_this)->latitude = latitude;
    ((corto_position*)_this)->longitude = longitude;
    return _this;
}

corto_string _corto_positionStr(corto_position* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_position_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_position* corto_positionFromStr(corto_position* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_position_o), str);
    return value;
}

corto_equalityKind corto_positionCompare(corto_position* dst, corto_position* src) {
    return corto_comparep(dst, corto_position_o, src);
}

corto_int16 _corto_positionInit(corto_position* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_position_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_position_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_positionDeinit(corto_position* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_position_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_remote _corto_remoteCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(void)) {
    corto_remote _this;
    _this = corto_remote(corto_declare(corto_remote_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_remote _corto_remoteCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(void)) {
    corto_remote _this;
    _this = corto_remote(corto_declareChild(_parent, _name, corto_remote_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_remoteUpdate(corto_remote _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_method)_this)->_virtual = _virtual;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_remote _corto_remoteDeclare(void) {
    corto_remote _this;
    _this = corto_remote(corto_declare(corto_remote_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_remote _corto_remoteDeclareChild(corto_object _parent, corto_string _name) {
    corto_remote _this;
    _this = corto_remote(corto_declareChild(_parent, _name, corto_remote_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_remoteDefine(corto_remote _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_remote _corto_remoteAssign(corto_remote _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_remoteStr(corto_remote value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_remote_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_remote corto_remoteFromStr(corto_remote value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_remote_o), str);
    return value;
}

corto_equalityKind _corto_remoteCompare(corto_remote dst, corto_remote src) {
    return corto_compare(dst, src);
}

corto_request* _corto_requestCreate(corto_string parent, corto_string expr, corto_string type, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_frame* from, corto_frame* to, corto_string param) {
    corto_request* _this;
    _this = corto_request(corto_declare(corto_request_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_request*)_this)->parent, parent);
    corto_setstr(&((corto_request*)_this)->expr, expr);
    corto_setstr(&((corto_request*)_this)->type, type);
    ((corto_request*)_this)->offset = offset;
    ((corto_request*)_this)->limit = limit;
    ((corto_request*)_this)->content = content;
    if (from) {
        corto_copyp(&((corto_request*)_this)->from, corto_frame_o, from);
    }
    if (to) {
        corto_copyp(&((corto_request*)_this)->to, corto_frame_o, to);
    }
    corto_setstr(&((corto_request*)_this)->param, param);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_request* _corto_requestCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string expr, corto_string type, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_frame* from, corto_frame* to, corto_string param) {
    corto_request* _this;
    _this = corto_request(corto_declareChild(_parent, _name, corto_request_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_request*)_this)->parent, parent);
    corto_setstr(&((corto_request*)_this)->expr, expr);
    corto_setstr(&((corto_request*)_this)->type, type);
    ((corto_request*)_this)->offset = offset;
    ((corto_request*)_this)->limit = limit;
    ((corto_request*)_this)->content = content;
    if (from) {
        corto_copyp(&((corto_request*)_this)->from, corto_frame_o, from);
    }
    if (to) {
        corto_copyp(&((corto_request*)_this)->to, corto_frame_o, to);
    }
    corto_setstr(&((corto_request*)_this)->param, param);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_requestUpdate(corto_request* _this, corto_string parent, corto_string expr, corto_string type, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_frame* from, corto_frame* to, corto_string param) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_request*)_this)->parent, parent);
        corto_setstr(&((corto_request*)_this)->expr, expr);
        corto_setstr(&((corto_request*)_this)->type, type);
        ((corto_request*)_this)->offset = offset;
        ((corto_request*)_this)->limit = limit;
        ((corto_request*)_this)->content = content;
        if (from) {
            corto_copyp(&((corto_request*)_this)->from, corto_frame_o, from);
        }
        if (to) {
            corto_copyp(&((corto_request*)_this)->to, corto_frame_o, to);
        }
        corto_setstr(&((corto_request*)_this)->param, param);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_request* _corto_requestDeclare(void) {
    corto_request* _this;
    _this = corto_request(corto_declare(corto_request_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_request* _corto_requestDeclareChild(corto_object _parent, corto_string _name) {
    corto_request* _this;
    _this = corto_request(corto_declareChild(_parent, _name, corto_request_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_requestDefine(corto_request* _this, corto_string parent, corto_string expr, corto_string type, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_frame* from, corto_frame* to, corto_string param) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_request*)_this)->parent, parent);
    corto_setstr(&((corto_request*)_this)->expr, expr);
    corto_setstr(&((corto_request*)_this)->type, type);
    ((corto_request*)_this)->offset = offset;
    ((corto_request*)_this)->limit = limit;
    ((corto_request*)_this)->content = content;
    if (from) {
        corto_copyp(&((corto_request*)_this)->from, corto_frame_o, from);
    }
    if (to) {
        corto_copyp(&((corto_request*)_this)->to, corto_frame_o, to);
    }
    corto_setstr(&((corto_request*)_this)->param, param);
    return corto_define(_this);
}

corto_request* _corto_requestAssign(corto_request* _this, corto_string parent, corto_string expr, corto_string type, corto_uint64 offset, corto_uint64 limit, corto_bool content, corto_frame* from, corto_frame* to, corto_string param) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_request*)_this)->parent, parent);
    corto_setstr(&((corto_request*)_this)->expr, expr);
    corto_setstr(&((corto_request*)_this)->type, type);
    ((corto_request*)_this)->offset = offset;
    ((corto_request*)_this)->limit = limit;
    ((corto_request*)_this)->content = content;
    if (from) {
        corto_copyp(&((corto_request*)_this)->from, corto_frame_o, from);
    }
    if (to) {
        corto_copyp(&((corto_request*)_this)->to, corto_frame_o, to);
    }
    corto_setstr(&((corto_request*)_this)->param, param);
    return _this;
}

corto_string _corto_requestStr(corto_request* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_request_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_request* corto_requestFromStr(corto_request* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_request_o), str);
    return value;
}

corto_equalityKind corto_requestCompare(corto_request* dst, corto_request* src) {
    return corto_comparep(dst, corto_request_o, src);
}

corto_int16 _corto_requestInit(corto_request* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_request_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_request_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_requestDeinit(corto_request* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_request_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_result* _corto_resultCreate(corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_bool crawl) {
    corto_result* _this;
    _this = corto_result(corto_declare(corto_result_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_result*)_this)->id, id);
    corto_setstr(&((corto_result*)_this)->name, name);
    corto_setstr(&((corto_result*)_this)->parent, parent);
    corto_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->crawl = crawl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _name, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_bool crawl) {
    corto_result* _this;
    _this = corto_result(corto_declareChild(_parent, _name, corto_result_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_result*)_this)->id, id);
    corto_setstr(&((corto_result*)_this)->name, name);
    corto_setstr(&((corto_result*)_this)->parent, parent);
    corto_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->crawl = crawl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_resultUpdate(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_bool crawl) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_result*)_this)->id, id);
        corto_setstr(&((corto_result*)_this)->name, name);
        corto_setstr(&((corto_result*)_this)->parent, parent);
        corto_setstr(&((corto_result*)_this)->type, type);
        ((corto_result*)_this)->value = value;
        ((corto_result*)_this)->crawl = crawl;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_result* _corto_resultDeclare(void) {
    corto_result* _this;
    _this = corto_result(corto_declare(corto_result_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_result* _corto_resultDeclareChild(corto_object _parent, corto_string _name) {
    corto_result* _this;
    _this = corto_result(corto_declareChild(_parent, _name, corto_result_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultDefine(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_bool crawl) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_result*)_this)->id, id);
    corto_setstr(&((corto_result*)_this)->name, name);
    corto_setstr(&((corto_result*)_this)->parent, parent);
    corto_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->crawl = crawl;
    return corto_define(_this);
}

corto_result* _corto_resultAssign(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, corto_word value, corto_bool crawl) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_result*)_this)->id, id);
    corto_setstr(&((corto_result*)_this)->name, name);
    corto_setstr(&((corto_result*)_this)->parent, parent);
    corto_setstr(&((corto_result*)_this)->type, type);
    ((corto_result*)_this)->value = value;
    ((corto_result*)_this)->crawl = crawl;
    return _this;
}

corto_string _corto_resultStr(corto_result* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_result_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_result* corto_resultFromStr(corto_result* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_result_o), str);
    return value;
}

corto_equalityKind corto_resultCompare(corto_result* dst, corto_result* src) {
    return corto_comparep(dst, corto_result_o, src);
}

corto_int16 _corto_resultInit(corto_result* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_result_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_result_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultDeinit(corto_result* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_result_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_resultIter* _corto_resultIterCreate(void) {
    corto_resultIter* _this;
    _this = corto_resultIter(corto_declare(corto_resultIter_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _name) {
    corto_resultIter* _this;
    _this = corto_resultIter(corto_declareChild(_parent, _name, corto_resultIter_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_resultIterUpdate(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultIter* _corto_resultIterDeclare(void) {
    corto_resultIter* _this;
    _this = corto_resultIter(corto_declare(corto_resultIter_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, corto_string _name) {
    corto_resultIter* _this;
    _this = corto_resultIter(corto_declareChild(_parent, _name, corto_resultIter_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultIterDefine(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_resultIter* _corto_resultIterAssign(corto_resultIter* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_resultIterStr(corto_resultIter value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_resultIter_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_resultIter* corto_resultIterFromStr(corto_resultIter* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_resultIter_o), str);
    return value;
}

corto_equalityKind corto_resultIterCompare(corto_resultIter dst, corto_resultIter src) {
    return corto_comparep(&dst, corto_resultIter_o, &src);
}

corto_int16 _corto_resultIterInit(corto_resultIter* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_resultIter_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_resultIter_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultIterDeinit(corto_resultIter* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_resultIter_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements) {
    corto_resultList* _this;
    _this = corto_resultList(corto_declare(corto_resultList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_result* elements) {
    corto_resultList* _this;
    _this = corto_resultList(corto_declareChild(_parent, _name, corto_resultList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_resultListUpdate(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_uint32 i = 0;
        corto_resultListClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_resultListAppend(*_this, &elements[i]);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_resultList* _corto_resultListDeclare(void) {
    corto_resultList* _this;
    _this = corto_resultList(corto_declare(corto_resultList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_resultList* _corto_resultListDeclareChild(corto_object _parent, corto_string _name) {
    corto_resultList* _this;
    _this = corto_resultList(corto_declareChild(_parent, _name, corto_resultList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_resultListDefine(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    return corto_define(_this);
}

corto_resultList* _corto_resultListAssign(corto_resultList* _this, corto_uint32 length, corto_result* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_resultListClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_resultListAppend(*_this, &elements[i]);
    }
    return _this;
}

corto_string _corto_resultListStr(corto_resultList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_resultList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_resultList* corto_resultListFromStr(corto_resultList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_resultList_o), str);
    return value;
}

corto_equalityKind corto_resultListCompare(corto_resultList dst, corto_resultList src) {
    return corto_comparep(&dst, corto_resultList_o, &src);
}

corto_int16 _corto_resultListInit(corto_resultList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_resultList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_resultList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_resultListDeinit(corto_resultList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_resultList_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_subscriber _corto_subscriberCreate(corto_string parent, corto_string expr, corto_eventMask mask) {
    corto_subscriber _this;
    _this = corto_subscriber(corto_declare(corto_subscriber_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_subscriber)_this)->parent, parent);
    corto_setstr(&((corto_subscriber)_this)->expr, expr);
    ((corto_subscriber)_this)->mask = mask;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_subscriber _corto_subscriberCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string expr, corto_eventMask mask) {
    corto_subscriber _this;
    _this = corto_subscriber(corto_declareChild(_parent, _name, corto_subscriber_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_subscriber)_this)->parent, parent);
    corto_setstr(&((corto_subscriber)_this)->expr, expr);
    ((corto_subscriber)_this)->mask = mask;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_subscriberUpdate(corto_subscriber _this, corto_string parent, corto_string expr, corto_eventMask mask) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_subscriber)_this)->parent, parent);
        corto_setstr(&((corto_subscriber)_this)->expr, expr);
        ((corto_subscriber)_this)->mask = mask;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_subscriber _corto_subscriberDeclare(void) {
    corto_subscriber _this;
    _this = corto_subscriber(corto_declare(corto_subscriber_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_subscriber _corto_subscriberDeclareChild(corto_object _parent, corto_string _name) {
    corto_subscriber _this;
    _this = corto_subscriber(corto_declareChild(_parent, _name, corto_subscriber_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_subscriberDefine(corto_subscriber _this, corto_string parent, corto_string expr, corto_eventMask mask) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_subscriber)_this)->parent, parent);
    corto_setstr(&((corto_subscriber)_this)->expr, expr);
    ((corto_subscriber)_this)->mask = mask;
    return corto_define(_this);
}

corto_subscriber _corto_subscriberAssign(corto_subscriber _this, corto_string parent, corto_string expr, corto_eventMask mask) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_subscriber)_this)->parent, parent);
    corto_setstr(&((corto_subscriber)_this)->expr, expr);
    ((corto_subscriber)_this)->mask = mask;
    return _this;
}

corto_string _corto_subscriberStr(corto_subscriber value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_subscriber_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_subscriber corto_subscriberFromStr(corto_subscriber value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_subscriber_o), str);
    return value;
}

corto_equalityKind _corto_subscriberCompare(corto_subscriber dst, corto_subscriber src) {
    return corto_compare(dst, src);
}

corto_time* _corto_timeCreate(corto_int32 sec, corto_uint32 nanosec) {
    corto_time* _this;
    _this = corto_time(corto_declare(corto_time_o));
    if (!_this) {
        return NULL;
    }
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_time* _corto_timeCreateChild(corto_object _parent, corto_string _name, corto_int32 sec, corto_uint32 nanosec) {
    corto_time* _this;
    _this = corto_time(corto_declareChild(_parent, _name, corto_time_o));
    if (!_this) {
        return NULL;
    }
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_timeUpdate(corto_time* _this, corto_int32 sec, corto_uint32 nanosec) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_time*)_this)->sec = sec;
        ((corto_time*)_this)->nanosec = nanosec;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_time* _corto_timeDeclare(void) {
    corto_time* _this;
    _this = corto_time(corto_declare(corto_time_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_time* _corto_timeDeclareChild(corto_object _parent, corto_string _name) {
    corto_time* _this;
    _this = corto_time(corto_declareChild(_parent, _name, corto_time_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_timeDefine(corto_time* _this, corto_int32 sec, corto_uint32 nanosec) {
    CORTO_UNUSED(_this);
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    return corto_define(_this);
}

corto_time* _corto_timeAssign(corto_time* _this, corto_int32 sec, corto_uint32 nanosec) {
    CORTO_UNUSED(_this);
    ((corto_time*)_this)->sec = sec;
    ((corto_time*)_this)->nanosec = nanosec;
    return _this;
}

corto_string _corto_timeStr(corto_time* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_time_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_time* corto_timeFromStr(corto_time* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_time_o), str);
    return value;
}

corto_equalityKind corto_timeCompare(corto_time* dst, corto_time* src) {
    return corto_comparep(dst, corto_time_o, src);
}

corto_int16 _corto_timeInit(corto_time* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_time_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_time_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_timeDeinit(corto_time* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_time_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_augmentData* corto_augmentseqAppend(corto_augmentseq *seq, corto_augmentData element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_augmentData*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_augmentData_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    corto_copyp(&seq->buffer[seq->length-1], corto_augmentData_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_augmentData* corto_augmentseqAppendAlloc(corto_augmentseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_augmentData*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_augmentData_o), &seq->buffer[seq->length-1]);
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
                v = corto_value_value(corto_type(corto_augmentData_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->buffer = (corto_augmentData*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_augmentData_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_augmentData_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_augmentseqClear(corto_augmentseq *seq) {
    corto_augmentseqSize(seq, 0);
}

corto_mountSubscription* corto_mountSubscriptionListInsertAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_mountSubscription_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListInsert(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListInsertAlloc(list);
    corto_copyp(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppendAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_mountSubscription_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppend(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListAppendAlloc(list);
    corto_copyp(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListTakeFirst(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_llTakeFirst(list);
}

corto_mountSubscription* corto_mountSubscriptionListLast(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_llLast(list);
}

corto_mountSubscription* corto_mountSubscriptionListGet(corto_mountSubscriptionList list, corto_uint32 index) {
    return (corto_mountSubscription*)corto_llGet(list, index);
}

corto_uint32 corto_mountSubscriptionListSize(corto_mountSubscriptionList list) {
    return corto_llSize(list);
}

void corto_mountSubscriptionListClear(corto_mountSubscriptionList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_mountSubscription_o);
        corto_dealloc(ptr);
    }
    corto_llClear(list);
}

corto_observer* corto_observerseqAppend(corto_observerseq *seq, corto_observer element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_observer*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_observer* corto_observerseqAppendAlloc(corto_observerseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_observer*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_observerseqSize(corto_observerseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_observer*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_observer_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_observer_o), &seq->buffer[i]);
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
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_result_o), result);
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
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_result_o), result);
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

