/* _api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <include/_api.h>
#include <include/_load.h>

test_AccessRule* _test_AccessRuleCreate(corto_string user, corto_secure_actionKind action, corto_secure_accessKind access) {
    test_AccessRule* _this;
    _this = test_AccessRule(corto_declare(test_AccessRule_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_AccessRule*)_this)->user, user);
        ((test_AccessRule*)_this)->action = action;
        ((test_AccessRule*)_this)->access = access;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AccessRule* _test_AccessRuleCreateChild(corto_object _parent, corto_string _id, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access) {
    test_AccessRule* _this;
    _this = test_AccessRule(corto_declareChild(_parent, _id, test_AccessRule_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_AccessRule*)_this)->user, user);
        ((test_AccessRule*)_this)->action = action;
        ((test_AccessRule*)_this)->access = access;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AccessRuleUpdate(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_AccessRule*)((test_AccessRule*)CORTO_OFFSET(_this, ((corto_type)test_AccessRule_o)->size)))->user, user);
            ((test_AccessRule*)((test_AccessRule*)CORTO_OFFSET(_this, ((corto_type)test_AccessRule_o)->size)))->action = action;
            ((test_AccessRule*)((test_AccessRule*)CORTO_OFFSET(_this, ((corto_type)test_AccessRule_o)->size)))->access = access;
        } else {
            corto_setstr(&((test_AccessRule*)_this)->user, user);
            ((test_AccessRule*)_this)->action = action;
            ((test_AccessRule*)_this)->access = access;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AccessRule* _test_AccessRuleDeclare(void) {
    test_AccessRule* _this;
    _this = test_AccessRule(corto_declare(test_AccessRule_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AccessRule* _test_AccessRuleDeclareChild(corto_object _parent, corto_string _id) {
    test_AccessRule* _this;
    _this = test_AccessRule(corto_declareChild(_parent, _id, test_AccessRule_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AccessRuleDefine(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_AccessRule*)_this)->user, user);
    ((test_AccessRule*)_this)->action = action;
    ((test_AccessRule*)_this)->access = access;
    return corto_define(_this);
}

test_AccessRule* _test_AccessRuleAssign(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_AccessRule*)_this)->user, user);
    ((test_AccessRule*)_this)->action = action;
    ((test_AccessRule*)_this)->access = access;
    return _this;
}

corto_string _test_AccessRuleStr(test_AccessRule* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_AccessRule_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_AccessRule* test_AccessRuleFromStr(test_AccessRule* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AccessRule_o), str);
    return value;
}

corto_equalityKind test_AccessRuleCompare(test_AccessRule* dst, test_AccessRule* src) {
    return corto_comparep(dst, test_AccessRule_o, src);
}

corto_int16 _test_AccessRuleInit(test_AccessRule* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_AccessRule_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_AccessRule_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_AccessRuleDeinit(test_AccessRule* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_AccessRule_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int64* _test_AllocArrayCreate(corto_uint32 length, corto_int64* elements) {
    corto_int64* _this;
    _this = test_AllocArray(corto_declare(test_AllocArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int64* _test_AllocArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int64* elements) {
    corto_int64* _this;
    _this = test_AllocArray(corto_declareChild(_parent, _id, test_AllocArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AllocArrayUpdate(test_AllocArray _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_int64*)CORTO_OFFSET(_this, ((corto_type)test_AllocArray_o)->size))[i] = elements[i];
            }
        } else {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this[i] = elements[i];
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int64* _test_AllocArrayDeclare(void) {
    corto_int64* _this;
    _this = test_AllocArray(corto_declare(test_AllocArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int64* _test_AllocArrayDeclareChild(corto_object _parent, corto_string _id) {
    corto_int64* _this;
    _this = test_AllocArray(corto_declareChild(_parent, _id, test_AllocArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AllocArrayDefine(test_AllocArray _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this[i] = elements[i];
    }
    return corto_define(_this);
}

corto_int64* _test_AllocArrayAssign(test_AllocArray _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this[i] = elements[i];
    }
    return _this;
}

corto_string _test_AllocArrayStr(test_AllocArray value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocArray_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int64* test_AllocArrayFromStr(test_AllocArray value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AllocArray_o), str);
    return value;
}

corto_equalityKind test_AllocArrayCompare(test_AllocArray dst, test_AllocArray src) {
    return corto_comparep(dst, test_AllocArray_o, src);
}

corto_int16 _test_AllocArrayInit(test_AllocArray* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_AllocArray_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_AllocArray_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_AllocArrayDeinit(test_AllocArray* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocArray_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_AllocList* _test_AllocListCreate(corto_uint32 length, corto_int64* elements) {
    test_AllocList* _this;
    _this = test_AllocList(corto_declare(test_AllocList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_AllocListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_AllocListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AllocList* _test_AllocListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int64* elements) {
    test_AllocList* _this;
    _this = test_AllocList(corto_declareChild(_parent, _id, test_AllocList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_AllocListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_AllocListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AllocListUpdate(test_AllocList* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            test_AllocListClear(*((test_AllocList*)CORTO_OFFSET(_this, ((corto_type)test_AllocList_o)->size)));
            for (i = 0; i < length; i ++) {
                test_AllocListAppend(*((test_AllocList*)CORTO_OFFSET(_this, ((corto_type)test_AllocList_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            test_AllocListClear(*_this);
            for (i = 0; i < length; i ++) {
                test_AllocListAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AllocList* _test_AllocListDeclare(void) {
    test_AllocList* _this;
    _this = test_AllocList(corto_declare(test_AllocList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AllocList* _test_AllocListDeclareChild(corto_object _parent, corto_string _id) {
    test_AllocList* _this;
    _this = test_AllocList(corto_declareChild(_parent, _id, test_AllocList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AllocListDefine(test_AllocList* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_AllocListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_AllocListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

test_AllocList* _test_AllocListAssign(test_AllocList* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_AllocListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_AllocListAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _test_AllocListStr(test_AllocList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_AllocList* test_AllocListFromStr(test_AllocList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AllocList_o), str);
    return value;
}

corto_equalityKind test_AllocListCompare(test_AllocList dst, test_AllocList src) {
    return corto_comparep(&dst, test_AllocList_o, &src);
}

corto_int16 _test_AllocListInit(test_AllocList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_AllocList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_AllocList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_AllocListDeinit(test_AllocList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocList_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_AllocSequence* _test_AllocSequenceCreate(corto_uint32 length, corto_int64* elements) {
    test_AllocSequence* _this;
    _this = test_AllocSequence(corto_declare(test_AllocSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_AllocSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AllocSequence* _test_AllocSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int64* elements) {
    test_AllocSequence* _this;
    _this = test_AllocSequence(corto_declareChild(_parent, _id, test_AllocSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_AllocSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AllocSequenceUpdate(test_AllocSequence* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            test_AllocSequenceSize(((test_AllocSequence*)CORTO_OFFSET(_this, ((corto_type)test_AllocSequence_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((test_AllocSequence*)CORTO_OFFSET(_this, ((corto_type)test_AllocSequence_o)->size))->buffer[i] = elements[i];
            }
        } else {
            test_AllocSequenceSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this->buffer[i] = elements[i];
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AllocSequence* _test_AllocSequenceDeclare(void) {
    test_AllocSequence* _this;
    _this = test_AllocSequence(corto_declare(test_AllocSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AllocSequence* _test_AllocSequenceDeclareChild(corto_object _parent, corto_string _id) {
    test_AllocSequence* _this;
    _this = test_AllocSequence(corto_declareChild(_parent, _id, test_AllocSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AllocSequenceDefine(test_AllocSequence* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    test_AllocSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

test_AllocSequence* _test_AllocSequenceAssign(test_AllocSequence* _this, corto_uint32 length, corto_int64* elements) {
    CORTO_UNUSED(_this);
    test_AllocSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

corto_string _test_AllocSequenceStr(test_AllocSequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocSequence_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_AllocSequence* test_AllocSequenceFromStr(test_AllocSequence* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AllocSequence_o), str);
    return value;
}

corto_equalityKind test_AllocSequenceCompare(test_AllocSequence dst, test_AllocSequence src) {
    return corto_comparep(&dst, test_AllocSequence_o, &src);
}

corto_int16 _test_AllocSequenceInit(test_AllocSequence* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_AllocSequence_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_AllocSequence_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_AllocSequenceDeinit(test_AllocSequence* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_AllocSequence_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Animal _test_AnimalCreate(bool a) {
    test_Animal _this;
    _this = test_Animal(corto_declare(test_Animal_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Animal _test_AnimalCreateChild(corto_object _parent, corto_string _id, bool a) {
    test_Animal _this;
    _this = test_Animal(corto_declareChild(_parent, _id, test_Animal_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AnimalUpdate(test_Animal _this, bool a) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Animal)((test_Animal)CORTO_OFFSET(_this, ((corto_type)test_Animal_o)->size)))->a = a;
        } else {
            ((test_Animal)_this)->a = a;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Animal _test_AnimalDeclare(void) {
    test_Animal _this;
    _this = test_Animal(corto_declare(test_Animal_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Animal _test_AnimalDeclareChild(corto_object _parent, corto_string _id) {
    test_Animal _this;
    _this = test_Animal(corto_declareChild(_parent, _id, test_Animal_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AnimalDefine(test_Animal _this, bool a) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    return corto_define(_this);
}

test_Animal _test_AnimalAssign(test_Animal _this, bool a) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    return _this;
}

corto_string _test_AnimalStr(test_Animal value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Animal_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Animal test_AnimalFromStr(test_Animal value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Animal_o), str);
    return value;
}

corto_equalityKind _test_AnimalCompare(test_Animal dst, test_Animal src) {
    return corto_compare(dst, src);
}

test_AnonymousTest _test_AnonymousTestCreate(corto_objectList objects) {
    test_AnonymousTest _this;
    _this = test_AnonymousTest(corto_declare(test_AnonymousTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (objects) {
            corto_copyp(&((test_AnonymousTest)_this)->objects, corto_objectList_o, &objects);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AnonymousTest _test_AnonymousTestCreateChild(corto_object _parent, corto_string _id, corto_objectList objects) {
    test_AnonymousTest _this;
    _this = test_AnonymousTest(corto_declareChild(_parent, _id, test_AnonymousTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (objects) {
            corto_copyp(&((test_AnonymousTest)_this)->objects, corto_objectList_o, &objects);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AnonymousTestUpdate(test_AnonymousTest _this, corto_objectList objects) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (objects) {
                corto_copyp(&((test_AnonymousTest)((test_AnonymousTest)CORTO_OFFSET(_this, ((corto_type)test_AnonymousTest_o)->size)))->objects, corto_objectList_o, &objects);
            }
        } else {
            if (objects) {
                corto_copyp(&((test_AnonymousTest)_this)->objects, corto_objectList_o, &objects);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AnonymousTest _test_AnonymousTestDeclare(void) {
    test_AnonymousTest _this;
    _this = test_AnonymousTest(corto_declare(test_AnonymousTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AnonymousTest _test_AnonymousTestDeclareChild(corto_object _parent, corto_string _id) {
    test_AnonymousTest _this;
    _this = test_AnonymousTest(corto_declareChild(_parent, _id, test_AnonymousTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AnonymousTestDefine(test_AnonymousTest _this, corto_objectList objects) {
    CORTO_UNUSED(_this);
    if (objects) {
        corto_copyp(&((test_AnonymousTest)_this)->objects, corto_objectList_o, &objects);
    }
    return corto_define(_this);
}

test_AnonymousTest _test_AnonymousTestAssign(test_AnonymousTest _this, corto_objectList objects) {
    CORTO_UNUSED(_this);
    if (objects) {
        corto_copyp(&((test_AnonymousTest)_this)->objects, corto_objectList_o, &objects);
    }
    return _this;
}

corto_string _test_AnonymousTestStr(test_AnonymousTest value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_AnonymousTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_AnonymousTest test_AnonymousTestFromStr(test_AnonymousTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AnonymousTest_o), str);
    return value;
}

corto_equalityKind _test_AnonymousTestCompare(test_AnonymousTest dst, test_AnonymousTest src) {
    return corto_compare(dst, src);
}

test_AttrCheck _test_AttrCheckCreate(uint32_t assertCount) {
    test_AttrCheck _this;
    _this = test_AttrCheck(corto_declare(test_AttrCheck_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AttrCheck _test_AttrCheckCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_AttrCheck _this;
    _this = test_AttrCheck(corto_declareChild(_parent, _id, test_AttrCheck_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AttrCheckUpdate(test_AttrCheck _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_AttrCheck)CORTO_OFFSET(_this, ((corto_type)test_AttrCheck_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AttrCheck _test_AttrCheckDeclare(void) {
    test_AttrCheck _this;
    _this = test_AttrCheck(corto_declare(test_AttrCheck_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AttrCheck _test_AttrCheckDeclareChild(corto_object _parent, corto_string _id) {
    test_AttrCheck _this;
    _this = test_AttrCheck(corto_declareChild(_parent, _id, test_AttrCheck_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AttrCheckDefine(test_AttrCheck _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_AttrCheck _test_AttrCheckAssign(test_AttrCheck _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_AttrCheckStr(test_AttrCheck value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_AttrCheck_o));
    result = corto_strv(&v, 0);
    return result;
}

test_AttrCheck test_AttrCheckFromStr(test_AttrCheck value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AttrCheck_o), str);
    return value;
}

corto_equalityKind _test_AttrCheckCompare(test_AttrCheck dst, test_AttrCheck src) {
    return corto_compare(dst, src);
}

test_AttrConstructorTest _test_AttrConstructorTestCreate(void) {
    test_AttrConstructorTest _this;
    _this = test_AttrConstructorTest(corto_declare(test_AttrConstructorTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_AttrConstructorTest _test_AttrConstructorTestCreateChild(corto_object _parent, corto_string _id) {
    test_AttrConstructorTest _this;
    _this = test_AttrConstructorTest(corto_declareChild(_parent, _id, test_AttrConstructorTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AttrConstructorTestUpdate(test_AttrConstructorTest _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_AttrConstructorTest _test_AttrConstructorTestDeclare(void) {
    test_AttrConstructorTest _this;
    _this = test_AttrConstructorTest(corto_declare(test_AttrConstructorTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_AttrConstructorTest _test_AttrConstructorTestDeclareChild(corto_object _parent, corto_string _id) {
    test_AttrConstructorTest _this;
    _this = test_AttrConstructorTest(corto_declareChild(_parent, _id, test_AttrConstructorTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AttrConstructorTestDefine(test_AttrConstructorTest _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_AttrConstructorTest _test_AttrConstructorTestAssign(test_AttrConstructorTest _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_AttrConstructorTestStr(test_AttrConstructorTest value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_AttrConstructorTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_AttrConstructorTest test_AttrConstructorTestFromStr(test_AttrConstructorTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AttrConstructorTest_o), str);
    return value;
}

corto_equalityKind _test_AttrConstructorTestCompare(test_AttrConstructorTest dst, test_AttrConstructorTest src) {
    return corto_compare(dst, src);
}

test_Attributes _test_AttributesCreate(uint32_t assertCount) {
    test_Attributes _this;
    _this = test_Attributes(corto_declare(test_Attributes_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Attributes _test_AttributesCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Attributes _this;
    _this = test_Attributes(corto_declareChild(_parent, _id, test_Attributes_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_AttributesUpdate(test_Attributes _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Attributes)CORTO_OFFSET(_this, ((corto_type)test_Attributes_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Attributes _test_AttributesDeclare(void) {
    test_Attributes _this;
    _this = test_Attributes(corto_declare(test_Attributes_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Attributes _test_AttributesDeclareChild(corto_object _parent, corto_string _id) {
    test_Attributes _this;
    _this = test_Attributes(corto_declareChild(_parent, _id, test_Attributes_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_AttributesDefine(test_Attributes _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Attributes _test_AttributesAssign(test_Attributes _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_AttributesStr(test_Attributes value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Attributes_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Attributes test_AttributesFromStr(test_Attributes value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Attributes_o), str);
    return value;
}

corto_equalityKind _test_AttributesCompare(test_Attributes dst, test_Attributes src) {
    return corto_compare(dst, src);
}

test_Bar _test_BarCreate(void) {
    test_Bar _this;
    _this = test_Bar(corto_declare(test_Bar_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Bar _test_BarCreateChild(corto_object _parent, corto_string _id) {
    test_Bar _this;
    _this = test_Bar(corto_declareChild(_parent, _id, test_Bar_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_BarUpdate(test_Bar _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Bar _test_BarDeclare(void) {
    test_Bar _this;
    _this = test_Bar(corto_declare(test_Bar_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Bar _test_BarDeclareChild(corto_object _parent, corto_string _id) {
    test_Bar _this;
    _this = test_Bar(corto_declareChild(_parent, _id, test_Bar_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_BarDefine(test_Bar _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_Bar _test_BarAssign(test_Bar _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_BarStr(test_Bar value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Bar_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Bar test_BarFromStr(test_Bar value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Bar_o), str);
    return value;
}

corto_equalityKind _test_BarCompare(test_Bar dst, test_Bar src) {
    return corto_compare(dst, src);
}

test_Buffer _test_BufferCreate(uint32_t assertCount) {
    test_Buffer _this;
    _this = test_Buffer(corto_declare(test_Buffer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Buffer _test_BufferCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Buffer _this;
    _this = test_Buffer(corto_declareChild(_parent, _id, test_Buffer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_BufferUpdate(test_Buffer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Buffer)CORTO_OFFSET(_this, ((corto_type)test_Buffer_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Buffer _test_BufferDeclare(void) {
    test_Buffer _this;
    _this = test_Buffer(corto_declare(test_Buffer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Buffer _test_BufferDeclareChild(corto_object _parent, corto_string _id) {
    test_Buffer _this;
    _this = test_Buffer(corto_declareChild(_parent, _id, test_Buffer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_BufferDefine(test_Buffer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Buffer _test_BufferAssign(test_Buffer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_BufferStr(test_Buffer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Buffer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Buffer test_BufferFromStr(test_Buffer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Buffer_o), str);
    return value;
}

corto_equalityKind _test_BufferCompare(test_Buffer dst, test_Buffer src) {
    return corto_compare(dst, src);
}

test_Car _test_CarCreate(corto_string license_plate, uint16_t speed) {
    test_Car _this;
    _this = test_Car(corto_declare(test_Car_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_Car)_this)->license_plate, license_plate);
        ((test_Car)_this)->speed = speed;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Car _test_CarCreateChild(corto_object _parent, corto_string _id, corto_string license_plate, uint16_t speed) {
    test_Car _this;
    _this = test_Car(corto_declareChild(_parent, _id, test_Car_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_Car)_this)->license_plate, license_plate);
        ((test_Car)_this)->speed = speed;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CarUpdate(test_Car _this, corto_string license_plate, uint16_t speed) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_Car)((test_Car)CORTO_OFFSET(_this, ((corto_type)test_Car_o)->size)))->license_plate, license_plate);
            ((test_Car)((test_Car)CORTO_OFFSET(_this, ((corto_type)test_Car_o)->size)))->speed = speed;
        } else {
            corto_setstr(&((test_Car)_this)->license_plate, license_plate);
            ((test_Car)_this)->speed = speed;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Car _test_CarDeclare(void) {
    test_Car _this;
    _this = test_Car(corto_declare(test_Car_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Car _test_CarDeclareChild(corto_object _parent, corto_string _id) {
    test_Car _this;
    _this = test_Car(corto_declareChild(_parent, _id, test_Car_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CarDefine(test_Car _this, corto_string license_plate, uint16_t speed) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_Car)_this)->license_plate, license_plate);
    ((test_Car)_this)->speed = speed;
    return corto_define(_this);
}

test_Car _test_CarAssign(test_Car _this, corto_string license_plate, uint16_t speed) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_Car)_this)->license_plate, license_plate);
    ((test_Car)_this)->speed = speed;
    return _this;
}

corto_string _test_CarStr(test_Car value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Car_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Car test_CarFromStr(test_Car value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Car_o), str);
    return value;
}

corto_equalityKind _test_CarCompare(test_Car dst, test_Car src) {
    return corto_compare(dst, src);
}

test_Car_Engine _test_Car_EngineCreate(uint16_t rpm, uint16_t temperature) {
    test_Car_Engine _this;
    _this = test_Car_Engine(corto_declare(test_Car_Engine_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Car_Engine)_this)->rpm = rpm;
        ((test_Car_Engine)_this)->temperature = temperature;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Car_Engine _test_Car_EngineCreateChild(corto_object _parent, corto_string _id, uint16_t rpm, uint16_t temperature) {
    test_Car_Engine _this;
    _this = test_Car_Engine(corto_declareChild(_parent, _id, test_Car_Engine_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Car_Engine)_this)->rpm = rpm;
        ((test_Car_Engine)_this)->temperature = temperature;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_Car_EngineUpdate(test_Car_Engine _this, uint16_t rpm, uint16_t temperature) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Car_Engine)((test_Car_Engine)CORTO_OFFSET(_this, ((corto_type)test_Car_Engine_o)->size)))->rpm = rpm;
            ((test_Car_Engine)((test_Car_Engine)CORTO_OFFSET(_this, ((corto_type)test_Car_Engine_o)->size)))->temperature = temperature;
        } else {
            ((test_Car_Engine)_this)->rpm = rpm;
            ((test_Car_Engine)_this)->temperature = temperature;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Car_Engine _test_Car_EngineDeclare(void) {
    test_Car_Engine _this;
    _this = test_Car_Engine(corto_declare(test_Car_Engine_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Car_Engine _test_Car_EngineDeclareChild(corto_object _parent, corto_string _id) {
    test_Car_Engine _this;
    _this = test_Car_Engine(corto_declareChild(_parent, _id, test_Car_Engine_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_Car_EngineDefine(test_Car_Engine _this, uint16_t rpm, uint16_t temperature) {
    CORTO_UNUSED(_this);
    ((test_Car_Engine)_this)->rpm = rpm;
    ((test_Car_Engine)_this)->temperature = temperature;
    return corto_define(_this);
}

test_Car_Engine _test_Car_EngineAssign(test_Car_Engine _this, uint16_t rpm, uint16_t temperature) {
    CORTO_UNUSED(_this);
    ((test_Car_Engine)_this)->rpm = rpm;
    ((test_Car_Engine)_this)->temperature = temperature;
    return _this;
}

corto_string _test_Car_EngineStr(test_Car_Engine value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Car_Engine_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Car_Engine test_Car_EngineFromStr(test_Car_Engine value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Car_Engine_o), str);
    return value;
}

corto_equalityKind _test_Car_EngineCompare(test_Car_Engine dst, test_Car_Engine src) {
    return corto_compare(dst, src);
}

test_Car_Wheel _test_Car_WheelCreate(uint16_t position) {
    test_Car_Wheel _this;
    _this = test_Car_Wheel(corto_declare(test_Car_Wheel_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Car_Wheel)_this)->position = position;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Car_Wheel _test_Car_WheelCreateChild(corto_object _parent, corto_string _id, uint16_t position) {
    test_Car_Wheel _this;
    _this = test_Car_Wheel(corto_declareChild(_parent, _id, test_Car_Wheel_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Car_Wheel)_this)->position = position;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_Car_WheelUpdate(test_Car_Wheel _this, uint16_t position) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Car_Wheel)((test_Car_Wheel)CORTO_OFFSET(_this, ((corto_type)test_Car_Wheel_o)->size)))->position = position;
        } else {
            ((test_Car_Wheel)_this)->position = position;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Car_Wheel _test_Car_WheelDeclare(void) {
    test_Car_Wheel _this;
    _this = test_Car_Wheel(corto_declare(test_Car_Wheel_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Car_Wheel _test_Car_WheelDeclareChild(corto_object _parent, corto_string _id) {
    test_Car_Wheel _this;
    _this = test_Car_Wheel(corto_declareChild(_parent, _id, test_Car_Wheel_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_Car_WheelDefine(test_Car_Wheel _this, uint16_t position) {
    CORTO_UNUSED(_this);
    ((test_Car_Wheel)_this)->position = position;
    return corto_define(_this);
}

test_Car_Wheel _test_Car_WheelAssign(test_Car_Wheel _this, uint16_t position) {
    CORTO_UNUSED(_this);
    ((test_Car_Wheel)_this)->position = position;
    return _this;
}

corto_string _test_Car_WheelStr(test_Car_Wheel value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Car_Wheel_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Car_Wheel test_Car_WheelFromStr(test_Car_Wheel value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Car_Wheel_o), str);
    return value;
}

corto_equalityKind _test_Car_WheelCompare(test_Car_Wheel dst, test_Car_Wheel src) {
    return corto_compare(dst, src);
}

test_Car_Wheel_Tire _test_Car_Wheel_TireCreate(corto_string brand) {
    test_Car_Wheel_Tire _this;
    _this = test_Car_Wheel_Tire(corto_declare(test_Car_Wheel_Tire_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_Car_Wheel_Tire)_this)->brand, brand);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Car_Wheel_Tire _test_Car_Wheel_TireCreateChild(corto_object _parent, corto_string _id, corto_string brand) {
    test_Car_Wheel_Tire _this;
    _this = test_Car_Wheel_Tire(corto_declareChild(_parent, _id, test_Car_Wheel_Tire_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_Car_Wheel_Tire)_this)->brand, brand);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_Car_Wheel_TireUpdate(test_Car_Wheel_Tire _this, corto_string brand) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_Car_Wheel_Tire)((test_Car_Wheel_Tire)CORTO_OFFSET(_this, ((corto_type)test_Car_Wheel_Tire_o)->size)))->brand, brand);
        } else {
            corto_setstr(&((test_Car_Wheel_Tire)_this)->brand, brand);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Car_Wheel_Tire _test_Car_Wheel_TireDeclare(void) {
    test_Car_Wheel_Tire _this;
    _this = test_Car_Wheel_Tire(corto_declare(test_Car_Wheel_Tire_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Car_Wheel_Tire _test_Car_Wheel_TireDeclareChild(corto_object _parent, corto_string _id) {
    test_Car_Wheel_Tire _this;
    _this = test_Car_Wheel_Tire(corto_declareChild(_parent, _id, test_Car_Wheel_Tire_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_Car_Wheel_TireDefine(test_Car_Wheel_Tire _this, corto_string brand) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_Car_Wheel_Tire)_this)->brand, brand);
    return corto_define(_this);
}

test_Car_Wheel_Tire _test_Car_Wheel_TireAssign(test_Car_Wheel_Tire _this, corto_string brand) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_Car_Wheel_Tire)_this)->brand, brand);
    return _this;
}

corto_string _test_Car_Wheel_TireStr(test_Car_Wheel_Tire value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Car_Wheel_Tire_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Car_Wheel_Tire test_Car_Wheel_TireFromStr(test_Car_Wheel_Tire value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Car_Wheel_Tire_o), str);
    return value;
}

corto_equalityKind _test_Car_Wheel_TireCompare(test_Car_Wheel_Tire dst, test_Car_Wheel_Tire src) {
    return corto_compare(dst, src);
}

test_Car_WheelLocation* _test_Car_WheelLocationCreate(test_Car_WheelLocation value) {
    test_Car_WheelLocation* _this;
    _this = test_Car_WheelLocation(corto_declare(test_Car_WheelLocation_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Car_WheelLocation* _test_Car_WheelLocationCreateChild(corto_object _parent, corto_string _id, test_Car_WheelLocation value) {
    test_Car_WheelLocation* _this;
    _this = test_Car_WheelLocation(corto_declareChild(_parent, _id, test_Car_WheelLocation_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_Car_WheelLocationUpdate(test_Car_WheelLocation* _this, test_Car_WheelLocation value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((test_Car_WheelLocation*)CORTO_OFFSET(_this, ((corto_type)test_Car_WheelLocation_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Car_WheelLocation* _test_Car_WheelLocationDeclare(void) {
    test_Car_WheelLocation* _this;
    _this = test_Car_WheelLocation(corto_declare(test_Car_WheelLocation_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Car_WheelLocation* _test_Car_WheelLocationDeclareChild(corto_object _parent, corto_string _id) {
    test_Car_WheelLocation* _this;
    _this = test_Car_WheelLocation(corto_declareChild(_parent, _id, test_Car_WheelLocation_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_Car_WheelLocationDefine(test_Car_WheelLocation* _this, test_Car_WheelLocation value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

test_Car_WheelLocation* _test_Car_WheelLocationAssign(test_Car_WheelLocation* _this, test_Car_WheelLocation value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _test_Car_WheelLocationStr(test_Car_WheelLocation value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_Car_WheelLocation_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Car_WheelLocation* test_Car_WheelLocationFromStr(test_Car_WheelLocation* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Car_WheelLocation_o), str);
    return value;
}

corto_equalityKind test_Car_WheelLocationCompare(test_Car_WheelLocation dst, test_Car_WheelLocation src) {
    return corto_comparep(&dst, test_Car_WheelLocation_o, &src);
}

corto_int16 _test_Car_WheelLocationInit(test_Car_WheelLocation* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Car_WheelLocation_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_Car_WheelLocation_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_Car_WheelLocationDeinit(test_Car_WheelLocation* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_Car_WheelLocation_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Cat _test_CatCreate(bool a, bool b) {
    test_Cat _this;
    _this = test_Cat(corto_declare(test_Cat_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Cat)_this)->b = b;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Cat _test_CatCreateChild(corto_object _parent, corto_string _id, bool a, bool b) {
    test_Cat _this;
    _this = test_Cat(corto_declareChild(_parent, _id, test_Cat_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Cat)_this)->b = b;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CatUpdate(test_Cat _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Animal)((test_Cat)CORTO_OFFSET(_this, ((corto_type)test_Cat_o)->size)))->a = a;
            ((test_Cat)((test_Cat)CORTO_OFFSET(_this, ((corto_type)test_Cat_o)->size)))->b = b;
        } else {
            ((test_Animal)_this)->a = a;
            ((test_Cat)_this)->b = b;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Cat _test_CatDeclare(void) {
    test_Cat _this;
    _this = test_Cat(corto_declare(test_Cat_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Cat _test_CatDeclareChild(corto_object _parent, corto_string _id) {
    test_Cat _this;
    _this = test_Cat(corto_declareChild(_parent, _id, test_Cat_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CatDefine(test_Cat _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Cat)_this)->b = b;
    return corto_define(_this);
}

test_Cat _test_CatAssign(test_Cat _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Cat)_this)->b = b;
    return _this;
}

corto_string _test_CatStr(test_Cat value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Cat_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Cat test_CatFromStr(test_Cat value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Cat_o), str);
    return value;
}

corto_equalityKind _test_CatCompare(test_Cat dst, test_Cat src) {
    return corto_compare(dst, src);
}

test_Color* _test_ColorCreate(test_Color value) {
    test_Color* _this;
    _this = test_Color(corto_declare(test_Color_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Color* _test_ColorCreateChild(corto_object _parent, corto_string _id, test_Color value) {
    test_Color* _this;
    _this = test_Color(corto_declareChild(_parent, _id, test_Color_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ColorUpdate(test_Color* _this, test_Color value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((test_Color*)CORTO_OFFSET(_this, ((corto_type)test_Color_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Color* _test_ColorDeclare(void) {
    test_Color* _this;
    _this = test_Color(corto_declare(test_Color_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Color* _test_ColorDeclareChild(corto_object _parent, corto_string _id) {
    test_Color* _this;
    _this = test_Color(corto_declareChild(_parent, _id, test_Color_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ColorDefine(test_Color* _this, test_Color value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

test_Color* _test_ColorAssign(test_Color* _this, test_Color value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _test_ColorStr(test_Color value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_Color_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Color* test_ColorFromStr(test_Color* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Color_o), str);
    return value;
}

corto_equalityKind test_ColorCompare(test_Color dst, test_Color src) {
    return corto_comparep(&dst, test_Color_o, &src);
}

corto_int16 _test_ColorInit(test_Color* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Color_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_Color_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ColorDeinit(test_Color* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_Color_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Compare _test_CompareCreate(uint32_t assertCount) {
    test_Compare _this;
    _this = test_Compare(corto_declare(test_Compare_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Compare _test_CompareCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Compare _this;
    _this = test_Compare(corto_declareChild(_parent, _id, test_Compare_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CompareUpdate(test_Compare _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Compare)CORTO_OFFSET(_this, ((corto_type)test_Compare_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Compare _test_CompareDeclare(void) {
    test_Compare _this;
    _this = test_Compare(corto_declare(test_Compare_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Compare _test_CompareDeclareChild(corto_object _parent, corto_string _id) {
    test_Compare _this;
    _this = test_Compare(corto_declareChild(_parent, _id, test_Compare_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CompareDefine(test_Compare _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Compare _test_CompareAssign(test_Compare _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_CompareStr(test_Compare value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Compare_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Compare test_CompareFromStr(test_Compare value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Compare_o), str);
    return value;
}

corto_equalityKind _test_CompareCompare(test_Compare dst, test_Compare src) {
    return corto_compare(dst, src);
}

test_Point* _test_CompositeArrayCreate(corto_uint32 length, test_Point* elements) {
    test_Point* _this;
    _this = test_CompositeArray(corto_declare(test_CompositeArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this[i], test_Point_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Point* _test_CompositeArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements) {
    test_Point* _this;
    _this = test_CompositeArray(corto_declareChild(_parent, _id, test_CompositeArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this[i], test_Point_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CompositeArrayUpdate(test_CompositeArray _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&((test_Point*)CORTO_OFFSET(_this, ((corto_type)test_CompositeArray_o)->size))[i], test_Point_o, &elements[i]);
                }
            }
        } else {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&_this[i], test_Point_o, &elements[i]);
                }
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Point* _test_CompositeArrayDeclare(void) {
    test_Point* _this;
    _this = test_CompositeArray(corto_declare(test_CompositeArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Point* _test_CompositeArrayDeclareChild(corto_object _parent, corto_string _id) {
    test_Point* _this;
    _this = test_CompositeArray(corto_declareChild(_parent, _id, test_CompositeArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CompositeArrayDefine(test_CompositeArray _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this[i], test_Point_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

test_Point* _test_CompositeArrayAssign(test_CompositeArray _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this[i], test_Point_o, &elements[i]);
        }
    }
    return _this;
}

corto_string _test_CompositeArrayStr(test_CompositeArray value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeArray_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_Point* test_CompositeArrayFromStr(test_CompositeArray value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_CompositeArray_o), str);
    return value;
}

corto_equalityKind test_CompositeArrayCompare(test_CompositeArray dst, test_CompositeArray src) {
    return corto_comparep(dst, test_CompositeArray_o, src);
}

corto_int16 _test_CompositeArrayInit(test_CompositeArray* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_CompositeArray_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeArray_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_CompositeArrayDeinit(test_CompositeArray* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeArray_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_CompositeList* _test_CompositeListCreate(corto_uint32 length, test_Point* elements) {
    test_CompositeList* _this;
    _this = test_CompositeList(corto_declare(test_CompositeList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_CompositeListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_CompositeListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_CompositeList* _test_CompositeListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements) {
    test_CompositeList* _this;
    _this = test_CompositeList(corto_declareChild(_parent, _id, test_CompositeList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_CompositeListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_CompositeListAppend(*_this, &elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CompositeListUpdate(test_CompositeList* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            test_CompositeListClear(*((test_CompositeList*)CORTO_OFFSET(_this, ((corto_type)test_CompositeList_o)->size)));
            for (i = 0; i < length; i ++) {
                test_CompositeListAppend(*((test_CompositeList*)CORTO_OFFSET(_this, ((corto_type)test_CompositeList_o)->size)), &elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            test_CompositeListClear(*_this);
            for (i = 0; i < length; i ++) {
                test_CompositeListAppend(*_this, &elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_CompositeList* _test_CompositeListDeclare(void) {
    test_CompositeList* _this;
    _this = test_CompositeList(corto_declare(test_CompositeList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_CompositeList* _test_CompositeListDeclareChild(corto_object _parent, corto_string _id) {
    test_CompositeList* _this;
    _this = test_CompositeList(corto_declareChild(_parent, _id, test_CompositeList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CompositeListDefine(test_CompositeList* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_CompositeListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_CompositeListAppend(*_this, &elements[i]);
    }
    return corto_define(_this);
}

test_CompositeList* _test_CompositeListAssign(test_CompositeList* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_CompositeListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_CompositeListAppend(*_this, &elements[i]);
    }
    return _this;
}

corto_string _test_CompositeListStr(test_CompositeList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_CompositeList* test_CompositeListFromStr(test_CompositeList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_CompositeList_o), str);
    return value;
}

corto_equalityKind test_CompositeListCompare(test_CompositeList dst, test_CompositeList src) {
    return corto_comparep(&dst, test_CompositeList_o, &src);
}

corto_int16 _test_CompositeListInit(test_CompositeList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_CompositeList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_CompositeListDeinit(test_CompositeList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeList_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_CompositeSequence* _test_CompositeSequenceCreate(corto_uint32 length, test_Point* elements) {
    test_CompositeSequence* _this;
    _this = test_CompositeSequence(corto_declare(test_CompositeSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_CompositeSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], test_Point_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_CompositeSequence* _test_CompositeSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements) {
    test_CompositeSequence* _this;
    _this = test_CompositeSequence(corto_declareChild(_parent, _id, test_CompositeSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_CompositeSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], test_Point_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CompositeSequenceUpdate(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            test_CompositeSequenceSize(((test_CompositeSequence*)CORTO_OFFSET(_this, ((corto_type)test_CompositeSequence_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&((test_CompositeSequence*)CORTO_OFFSET(_this, ((corto_type)test_CompositeSequence_o)->size))->buffer[i], test_Point_o, &elements[i]);
                }
            }
        } else {
            test_CompositeSequenceSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&_this->buffer[i], test_Point_o, &elements[i]);
                }
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_CompositeSequence* _test_CompositeSequenceDeclare(void) {
    test_CompositeSequence* _this;
    _this = test_CompositeSequence(corto_declare(test_CompositeSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_CompositeSequence* _test_CompositeSequenceDeclareChild(corto_object _parent, corto_string _id) {
    test_CompositeSequence* _this;
    _this = test_CompositeSequence(corto_declareChild(_parent, _id, test_CompositeSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CompositeSequenceDefine(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    test_CompositeSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], test_Point_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

test_CompositeSequence* _test_CompositeSequenceAssign(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements) {
    CORTO_UNUSED(_this);
    test_CompositeSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], test_Point_o, &elements[i]);
        }
    }
    return _this;
}

corto_string _test_CompositeSequenceStr(test_CompositeSequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeSequence_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_CompositeSequence* test_CompositeSequenceFromStr(test_CompositeSequence* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_CompositeSequence_o), str);
    return value;
}

corto_equalityKind test_CompositeSequenceCompare(test_CompositeSequence dst, test_CompositeSequence src) {
    return corto_comparep(&dst, test_CompositeSequence_o, &src);
}

corto_int16 _test_CompositeSequenceInit(test_CompositeSequence* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_CompositeSequence_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeSequence_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_CompositeSequenceDeinit(test_CompositeSequence* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeSequence_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_CompositeWithString* _test_CompositeWithStringCreate(int32_t a, corto_string b, corto_string c, int32_t d) {
    test_CompositeWithString* _this;
    _this = test_CompositeWithString(corto_declare(test_CompositeWithString_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_CompositeWithString*)_this)->a = a;
        corto_setstr(&((test_CompositeWithString*)_this)->b, b);
        corto_setstr(&((test_CompositeWithString*)_this)->c, c);
        ((test_CompositeWithString*)_this)->d = d;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_CompositeWithString* _test_CompositeWithStringCreateChild(corto_object _parent, corto_string _id, int32_t a, corto_string b, corto_string c, int32_t d) {
    test_CompositeWithString* _this;
    _this = test_CompositeWithString(corto_declareChild(_parent, _id, test_CompositeWithString_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_CompositeWithString*)_this)->a = a;
        corto_setstr(&((test_CompositeWithString*)_this)->b, b);
        corto_setstr(&((test_CompositeWithString*)_this)->c, c);
        ((test_CompositeWithString*)_this)->d = d;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CompositeWithStringUpdate(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_CompositeWithString*)((test_CompositeWithString*)CORTO_OFFSET(_this, ((corto_type)test_CompositeWithString_o)->size)))->a = a;
            corto_setstr(&((test_CompositeWithString*)((test_CompositeWithString*)CORTO_OFFSET(_this, ((corto_type)test_CompositeWithString_o)->size)))->b, b);
            corto_setstr(&((test_CompositeWithString*)((test_CompositeWithString*)CORTO_OFFSET(_this, ((corto_type)test_CompositeWithString_o)->size)))->c, c);
            ((test_CompositeWithString*)((test_CompositeWithString*)CORTO_OFFSET(_this, ((corto_type)test_CompositeWithString_o)->size)))->d = d;
        } else {
            ((test_CompositeWithString*)_this)->a = a;
            corto_setstr(&((test_CompositeWithString*)_this)->b, b);
            corto_setstr(&((test_CompositeWithString*)_this)->c, c);
            ((test_CompositeWithString*)_this)->d = d;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_CompositeWithString* _test_CompositeWithStringDeclare(void) {
    test_CompositeWithString* _this;
    _this = test_CompositeWithString(corto_declare(test_CompositeWithString_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_CompositeWithString* _test_CompositeWithStringDeclareChild(corto_object _parent, corto_string _id) {
    test_CompositeWithString* _this;
    _this = test_CompositeWithString(corto_declareChild(_parent, _id, test_CompositeWithString_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CompositeWithStringDefine(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d) {
    CORTO_UNUSED(_this);
    ((test_CompositeWithString*)_this)->a = a;
    corto_setstr(&((test_CompositeWithString*)_this)->b, b);
    corto_setstr(&((test_CompositeWithString*)_this)->c, c);
    ((test_CompositeWithString*)_this)->d = d;
    return corto_define(_this);
}

test_CompositeWithString* _test_CompositeWithStringAssign(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d) {
    CORTO_UNUSED(_this);
    ((test_CompositeWithString*)_this)->a = a;
    corto_setstr(&((test_CompositeWithString*)_this)->b, b);
    corto_setstr(&((test_CompositeWithString*)_this)->c, c);
    ((test_CompositeWithString*)_this)->d = d;
    return _this;
}

corto_string _test_CompositeWithStringStr(test_CompositeWithString* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeWithString_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_CompositeWithString* test_CompositeWithStringFromStr(test_CompositeWithString* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_CompositeWithString_o), str);
    return value;
}

corto_equalityKind test_CompositeWithStringCompare(test_CompositeWithString* dst, test_CompositeWithString* src) {
    return corto_comparep(dst, test_CompositeWithString_o, src);
}

corto_int16 _test_CompositeWithStringInit(test_CompositeWithString* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_CompositeWithString_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeWithString_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_CompositeWithStringDeinit(test_CompositeWithString* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_CompositeWithString_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Container _test_ContainerCreate(uint32_t assertCount) {
    test_Container _this;
    _this = test_Container(corto_declare(test_Container_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Container _test_ContainerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Container _this;
    _this = test_Container(corto_declareChild(_parent, _id, test_Container_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerUpdate(test_Container _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Container)CORTO_OFFSET(_this, ((corto_type)test_Container_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Container _test_ContainerDeclare(void) {
    test_Container _this;
    _this = test_Container(corto_declare(test_Container_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Container _test_ContainerDeclareChild(corto_object _parent, corto_string _id) {
    test_Container _this;
    _this = test_Container(corto_declareChild(_parent, _id, test_Container_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerDefine(test_Container _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Container _test_ContainerAssign(test_Container _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_ContainerStr(test_Container value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Container_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Container test_ContainerFromStr(test_Container value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Container_o), str);
    return value;
}

corto_equalityKind _test_ContainerCompare(test_Container dst, test_Container src) {
    return corto_compare(dst, src);
}

test_ContainerEmpty _test_ContainerEmptyCreate(int32_t id, corto_string value) {
    test_ContainerEmpty _this;
    _this = test_ContainerEmpty(corto_declare(test_ContainerEmpty_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerEmpty)_this)->id = id;
        corto_setstr(&((test_ContainerEmpty)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerEmpty _test_ContainerEmptyCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerEmpty _this;
    _this = test_ContainerEmpty(corto_declareChild(_parent, _id, test_ContainerEmpty_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerEmpty)_this)->id = id;
        corto_setstr(&((test_ContainerEmpty)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerEmptyUpdate(test_ContainerEmpty _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerEmpty)((test_ContainerEmpty)CORTO_OFFSET(_this, ((corto_type)test_ContainerEmpty_o)->size)))->id = id;
            corto_setstr(&((test_ContainerEmpty)((test_ContainerEmpty)CORTO_OFFSET(_this, ((corto_type)test_ContainerEmpty_o)->size)))->value, value);
        } else {
            ((test_ContainerEmpty)_this)->id = id;
            corto_setstr(&((test_ContainerEmpty)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerEmpty _test_ContainerEmptyDeclare(void) {
    test_ContainerEmpty _this;
    _this = test_ContainerEmpty(corto_declare(test_ContainerEmpty_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerEmpty _test_ContainerEmptyDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerEmpty _this;
    _this = test_ContainerEmpty(corto_declareChild(_parent, _id, test_ContainerEmpty_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerEmptyDefine(test_ContainerEmpty _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerEmpty)_this)->id = id;
    corto_setstr(&((test_ContainerEmpty)_this)->value, value);
    return corto_define(_this);
}

test_ContainerEmpty _test_ContainerEmptyAssign(test_ContainerEmpty _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerEmpty)_this)->id = id;
    corto_setstr(&((test_ContainerEmpty)_this)->value, value);
    return _this;
}

corto_string _test_ContainerEmptyStr(test_ContainerEmpty value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerEmpty_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerEmpty test_ContainerEmptyFromStr(test_ContainerEmpty value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerEmpty_o), str);
    return value;
}

corto_equalityKind _test_ContainerEmptyCompare(test_ContainerEmpty dst, test_ContainerEmpty src) {
    return corto_compare(dst, src);
}

test_ContainerNestedContainer _test_ContainerNestedContainerCreate(int32_t id, corto_string value) {
    test_ContainerNestedContainer _this;
    _this = test_ContainerNestedContainer(corto_declare(test_ContainerNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedContainer _test_ContainerNestedContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedContainer _this;
    _this = test_ContainerNestedContainer(corto_declareChild(_parent, _id, test_ContainerNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainerUpdate(test_ContainerNestedContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedContainer)((test_ContainerNestedContainer)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedContainer)((test_ContainerNestedContainer)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedContainer)_this)->id = id;
            corto_setstr(&((test_ContainerNestedContainer)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedContainer _test_ContainerNestedContainerDeclare(void) {
    test_ContainerNestedContainer _this;
    _this = test_ContainerNestedContainer(corto_declare(test_ContainerNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedContainer _test_ContainerNestedContainerDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedContainer _this;
    _this = test_ContainerNestedContainer(corto_declareChild(_parent, _id, test_ContainerNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainerDefine(test_ContainerNestedContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedContainer _test_ContainerNestedContainerAssign(test_ContainerNestedContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedContainerStr(test_ContainerNestedContainer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedContainer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedContainer test_ContainerNestedContainerFromStr(test_ContainerNestedContainer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedContainer_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedContainerCompare(test_ContainerNestedContainer dst, test_ContainerNestedContainer src) {
    return corto_compare(dst, src);
}

test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerCreate(int32_t id, corto_string value) {
    test_ContainerNestedContainer_ChildContainer _this;
    _this = test_ContainerNestedContainer_ChildContainer(corto_declare(test_ContainerNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer_ChildContainer)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer_ChildContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedContainer_ChildContainer _this;
    _this = test_ContainerNestedContainer_ChildContainer(corto_declareChild(_parent, _id, test_ContainerNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer_ChildContainer)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer_ChildContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainer_ChildContainerUpdate(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedContainer_ChildContainer)((test_ContainerNestedContainer_ChildContainer)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_ChildContainer_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedContainer_ChildContainer)((test_ContainerNestedContainer_ChildContainer)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_ChildContainer_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedContainer_ChildContainer)_this)->id = id;
            corto_setstr(&((test_ContainerNestedContainer_ChildContainer)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerDeclare(void) {
    test_ContainerNestedContainer_ChildContainer _this;
    _this = test_ContainerNestedContainer_ChildContainer(corto_declare(test_ContainerNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedContainer_ChildContainer _this;
    _this = test_ContainerNestedContainer_ChildContainer(corto_declareChild(_parent, _id, test_ContainerNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainer_ChildContainerDefine(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer_ChildContainer)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer_ChildContainer)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerAssign(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer_ChildContainer)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer_ChildContainer)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedContainer_ChildContainerStr(test_ContainerNestedContainer_ChildContainer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedContainer_ChildContainer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedContainer_ChildContainer test_ContainerNestedContainer_ChildContainerFromStr(test_ContainerNestedContainer_ChildContainer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedContainer_ChildContainer_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedContainer_ChildContainerCompare(test_ContainerNestedContainer_ChildContainer dst, test_ContainerNestedContainer_ChildContainer src) {
    return corto_compare(dst, src);
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafCreate(int32_t id, corto_string value) {
    test_ContainerNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_ContainerNestedContainer_ChildContainer_ChildLeaf(corto_declare(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_ContainerNestedContainer_ChildContainer_ChildLeaf(corto_declareChild(_parent, _id, test_ContainerNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainer_ChildContainer_ChildLeafUpdate(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)((test_ContainerNestedContainer_ChildContainer_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_ChildContainer_ChildLeaf_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)((test_ContainerNestedContainer_ChildContainer_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedContainer_ChildContainer_ChildLeaf_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
            corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare(void) {
    test_ContainerNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_ContainerNestedContainer_ChildContainer_ChildLeaf(corto_declare(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_ContainerNestedContainer_ChildContainer_ChildLeaf(corto_declareChild(_parent, _id, test_ContainerNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedContainer_ChildContainer_ChildLeafDefine(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafAssign(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedContainer_ChildContainer_ChildLeafStr(test_ContainerNestedContainer_ChildContainer_ChildLeaf value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedContainer_ChildContainer_ChildLeaf test_ContainerNestedContainer_ChildContainer_ChildLeafFromStr(test_ContainerNestedContainer_ChildContainer_ChildLeaf value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedContainer_ChildContainer_ChildLeafCompare(test_ContainerNestedContainer_ChildContainer_ChildLeaf dst, test_ContainerNestedContainer_ChildContainer_ChildLeaf src) {
    return corto_compare(dst, src);
}

test_ContainerNestedLeaf _test_ContainerNestedLeafCreate(int32_t id, corto_string value) {
    test_ContainerNestedLeaf _this;
    _this = test_ContainerNestedLeaf(corto_declare(test_ContainerNestedLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedLeaf _test_ContainerNestedLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedLeaf _this;
    _this = test_ContainerNestedLeaf(corto_declareChild(_parent, _id, test_ContainerNestedLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedLeafUpdate(test_ContainerNestedLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedLeaf)((test_ContainerNestedLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedLeaf_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedLeaf)((test_ContainerNestedLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedLeaf_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedLeaf)_this)->id = id;
            corto_setstr(&((test_ContainerNestedLeaf)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedLeaf _test_ContainerNestedLeafDeclare(void) {
    test_ContainerNestedLeaf _this;
    _this = test_ContainerNestedLeaf(corto_declare(test_ContainerNestedLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedLeaf _test_ContainerNestedLeafDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedLeaf _this;
    _this = test_ContainerNestedLeaf(corto_declareChild(_parent, _id, test_ContainerNestedLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedLeafDefine(test_ContainerNestedLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedLeaf)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedLeaf _test_ContainerNestedLeafAssign(test_ContainerNestedLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedLeaf)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedLeafStr(test_ContainerNestedLeaf value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedLeaf_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedLeaf test_ContainerNestedLeafFromStr(test_ContainerNestedLeaf value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedLeaf_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedLeafCompare(test_ContainerNestedLeaf dst, test_ContainerNestedLeaf src) {
    return corto_compare(dst, src);
}

test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafCreate(int32_t id, corto_string value) {
    test_ContainerNestedLeaf_ChildLeaf _this;
    _this = test_ContainerNestedLeaf_ChildLeaf(corto_declare(test_ContainerNestedLeaf_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedLeaf_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedLeaf_ChildLeaf _this;
    _this = test_ContainerNestedLeaf_ChildLeaf(corto_declareChild(_parent, _id, test_ContainerNestedLeaf_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedLeaf_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedLeaf_ChildLeafUpdate(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedLeaf_ChildLeaf)((test_ContainerNestedLeaf_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedLeaf_ChildLeaf_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)((test_ContainerNestedLeaf_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedLeaf_ChildLeaf_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedLeaf_ChildLeaf)_this)->id = id;
            corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafDeclare(void) {
    test_ContainerNestedLeaf_ChildLeaf _this;
    _this = test_ContainerNestedLeaf_ChildLeaf(corto_declare(test_ContainerNestedLeaf_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedLeaf_ChildLeaf _this;
    _this = test_ContainerNestedLeaf_ChildLeaf(corto_declareChild(_parent, _id, test_ContainerNestedLeaf_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedLeaf_ChildLeafDefine(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedLeaf_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafAssign(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedLeaf_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_ContainerNestedLeaf_ChildLeaf)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedLeaf_ChildLeafStr(test_ContainerNestedLeaf_ChildLeaf value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedLeaf_ChildLeaf_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedLeaf_ChildLeaf test_ContainerNestedLeaf_ChildLeafFromStr(test_ContainerNestedLeaf_ChildLeaf value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedLeaf_ChildLeaf_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedLeaf_ChildLeafCompare(test_ContainerNestedLeaf_ChildLeaf dst, test_ContainerNestedLeaf_ChildLeaf src) {
    return corto_compare(dst, src);
}

test_ContainerNestedTable _test_ContainerNestedTableCreate(int32_t id, corto_string value) {
    test_ContainerNestedTable _this;
    _this = test_ContainerNestedTable(corto_declare(test_ContainerNestedTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedTable)_this)->id = id;
        corto_setstr(&((test_ContainerNestedTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedTable _test_ContainerNestedTableCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_ContainerNestedTable _this;
    _this = test_ContainerNestedTable(corto_declareChild(_parent, _id, test_ContainerNestedTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ContainerNestedTable)_this)->id = id;
        corto_setstr(&((test_ContainerNestedTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedTableUpdate(test_ContainerNestedTable _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ContainerNestedTable)((test_ContainerNestedTable)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedTable_o)->size)))->id = id;
            corto_setstr(&((test_ContainerNestedTable)((test_ContainerNestedTable)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedTable_o)->size)))->value, value);
        } else {
            ((test_ContainerNestedTable)_this)->id = id;
            corto_setstr(&((test_ContainerNestedTable)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedTable _test_ContainerNestedTableDeclare(void) {
    test_ContainerNestedTable _this;
    _this = test_ContainerNestedTable(corto_declare(test_ContainerNestedTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedTable _test_ContainerNestedTableDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedTable _this;
    _this = test_ContainerNestedTable(corto_declareChild(_parent, _id, test_ContainerNestedTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedTableDefine(test_ContainerNestedTable _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedTable)_this)->id = id;
    corto_setstr(&((test_ContainerNestedTable)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedTable _test_ContainerNestedTableAssign(test_ContainerNestedTable _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_ContainerNestedTable)_this)->id = id;
    corto_setstr(&((test_ContainerNestedTable)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedTableStr(test_ContainerNestedTable value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedTable_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedTable test_ContainerNestedTableFromStr(test_ContainerNestedTable value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedTable_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedTableCompare(test_ContainerNestedTable dst, test_ContainerNestedTable src) {
    return corto_compare(dst, src);
}

test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableCreate(corto_string value) {
    test_ContainerNestedTable_ChildTable _this;
    _this = test_ContainerNestedTable_ChildTable(corto_declare(test_ContainerNestedTable_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_ContainerNestedTable_ChildTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_ContainerNestedTable_ChildTable _this;
    _this = test_ContainerNestedTable_ChildTable(corto_declareChild(_parent, _id, test_ContainerNestedTable_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_ContainerNestedTable_ChildTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ContainerNestedTable_ChildTableUpdate(test_ContainerNestedTable_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_ContainerNestedTable_ChildTable)((test_ContainerNestedTable_ChildTable)CORTO_OFFSET(_this, ((corto_type)test_ContainerNestedTable_ChildTable_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_ContainerNestedTable_ChildTable)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableDeclare(void) {
    test_ContainerNestedTable_ChildTable _this;
    _this = test_ContainerNestedTable_ChildTable(corto_declare(test_ContainerNestedTable_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableDeclareChild(corto_object _parent, corto_string _id) {
    test_ContainerNestedTable_ChildTable _this;
    _this = test_ContainerNestedTable_ChildTable(corto_declareChild(_parent, _id, test_ContainerNestedTable_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ContainerNestedTable_ChildTableDefine(test_ContainerNestedTable_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_ContainerNestedTable_ChildTable)_this)->value, value);
    return corto_define(_this);
}

test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableAssign(test_ContainerNestedTable_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_ContainerNestedTable_ChildTable)_this)->value, value);
    return _this;
}

corto_string _test_ContainerNestedTable_ChildTableStr(test_ContainerNestedTable_ChildTable value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ContainerNestedTable_ChildTable_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ContainerNestedTable_ChildTable test_ContainerNestedTable_ChildTableFromStr(test_ContainerNestedTable_ChildTable value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ContainerNestedTable_ChildTable_o), str);
    return value;
}

corto_equalityKind _test_ContainerNestedTable_ChildTableCompare(test_ContainerNestedTable_ChildTable dst, test_ContainerNestedTable_ChildTable src) {
    return corto_compare(dst, src);
}

test_Copy _test_CopyCreate(uint32_t assertCount) {
    test_Copy _this;
    _this = test_Copy(corto_declare(test_Copy_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Copy _test_CopyCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Copy _this;
    _this = test_Copy(corto_declareChild(_parent, _id, test_Copy_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_CopyUpdate(test_Copy _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Copy)CORTO_OFFSET(_this, ((corto_type)test_Copy_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Copy _test_CopyDeclare(void) {
    test_Copy _this;
    _this = test_Copy(corto_declare(test_Copy_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Copy _test_CopyDeclareChild(corto_object _parent, corto_string _id) {
    test_Copy _this;
    _this = test_Copy(corto_declareChild(_parent, _id, test_Copy_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_CopyDefine(test_Copy _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Copy _test_CopyAssign(test_Copy _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_CopyStr(test_Copy value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Copy_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Copy test_CopyFromStr(test_Copy value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Copy_o), str);
    return value;
}

corto_equalityKind _test_CopyCompare(test_Copy dst, test_Copy src) {
    return corto_compare(dst, src);
}

test_DeclaredParent* _test_DeclaredParentCreate(int32_t Foo) {
    test_DeclaredParent* _this;
    _this = test_DeclaredParent(corto_declare(test_DeclaredParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_DeclaredParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_DeclaredParent* _test_DeclaredParentCreateChild(corto_object _parent, corto_string _id, int32_t Foo) {
    test_DeclaredParent* _this;
    _this = test_DeclaredParent(corto_declareChild(_parent, _id, test_DeclaredParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_DeclaredParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_DeclaredParentUpdate(test_DeclaredParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_DeclaredParent*)((test_DeclaredParent*)CORTO_OFFSET(_this, ((corto_type)test_DeclaredParent_o)->size)))->Foo = Foo;
        } else {
            ((test_DeclaredParent*)_this)->Foo = Foo;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_DeclaredParent* _test_DeclaredParentDeclare(void) {
    test_DeclaredParent* _this;
    _this = test_DeclaredParent(corto_declare(test_DeclaredParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_DeclaredParent* _test_DeclaredParentDeclareChild(corto_object _parent, corto_string _id) {
    test_DeclaredParent* _this;
    _this = test_DeclaredParent(corto_declareChild(_parent, _id, test_DeclaredParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_DeclaredParentDefine(test_DeclaredParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_DeclaredParent*)_this)->Foo = Foo;
    return corto_define(_this);
}

test_DeclaredParent* _test_DeclaredParentAssign(test_DeclaredParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_DeclaredParent*)_this)->Foo = Foo;
    return _this;
}

corto_string _test_DeclaredParentStr(test_DeclaredParent* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_DeclaredParent_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_DeclaredParent* test_DeclaredParentFromStr(test_DeclaredParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_DeclaredParent_o), str);
    return value;
}

corto_equalityKind test_DeclaredParentCompare(test_DeclaredParent* dst, test_DeclaredParent* src) {
    return corto_comparep(dst, test_DeclaredParent_o, src);
}

corto_int16 _test_DeclaredParentInit(test_DeclaredParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_DeclaredParent_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_DeclaredParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_DeclaredParentDeinit(test_DeclaredParent* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_DeclaredParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_DefinedParent* _test_DefinedParentCreate(int32_t Foo) {
    test_DefinedParent* _this;
    _this = test_DefinedParent(corto_declare(test_DefinedParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_DefinedParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_DefinedParent* _test_DefinedParentCreateChild(corto_object _parent, corto_string _id, int32_t Foo) {
    test_DefinedParent* _this;
    _this = test_DefinedParent(corto_declareChild(_parent, _id, test_DefinedParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_DefinedParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_DefinedParentUpdate(test_DefinedParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_DefinedParent*)((test_DefinedParent*)CORTO_OFFSET(_this, ((corto_type)test_DefinedParent_o)->size)))->Foo = Foo;
        } else {
            ((test_DefinedParent*)_this)->Foo = Foo;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_DefinedParent* _test_DefinedParentDeclare(void) {
    test_DefinedParent* _this;
    _this = test_DefinedParent(corto_declare(test_DefinedParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_DefinedParent* _test_DefinedParentDeclareChild(corto_object _parent, corto_string _id) {
    test_DefinedParent* _this;
    _this = test_DefinedParent(corto_declareChild(_parent, _id, test_DefinedParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_DefinedParentDefine(test_DefinedParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_DefinedParent*)_this)->Foo = Foo;
    return corto_define(_this);
}

test_DefinedParent* _test_DefinedParentAssign(test_DefinedParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_DefinedParent*)_this)->Foo = Foo;
    return _this;
}

corto_string _test_DefinedParentStr(test_DefinedParent* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_DefinedParent_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_DefinedParent* test_DefinedParentFromStr(test_DefinedParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_DefinedParent_o), str);
    return value;
}

corto_equalityKind test_DefinedParentCompare(test_DefinedParent* dst, test_DefinedParent* src) {
    return corto_comparep(dst, test_DefinedParent_o, src);
}

corto_int16 _test_DefinedParentInit(test_DefinedParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_DefinedParent_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_DefinedParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_DefinedParentDeinit(test_DefinedParent* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_DefinedParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Dog _test_DogCreate(bool a, bool b) {
    test_Dog _this;
    _this = test_Dog(corto_declare(test_Dog_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Dog)_this)->b = b;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Dog _test_DogCreateChild(corto_object _parent, corto_string _id, bool a, bool b) {
    test_Dog _this;
    _this = test_Dog(corto_declareChild(_parent, _id, test_Dog_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Dog)_this)->b = b;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_DogUpdate(test_Dog _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Animal)((test_Dog)CORTO_OFFSET(_this, ((corto_type)test_Dog_o)->size)))->a = a;
            ((test_Dog)((test_Dog)CORTO_OFFSET(_this, ((corto_type)test_Dog_o)->size)))->b = b;
        } else {
            ((test_Animal)_this)->a = a;
            ((test_Dog)_this)->b = b;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Dog _test_DogDeclare(void) {
    test_Dog _this;
    _this = test_Dog(corto_declare(test_Dog_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Dog _test_DogDeclareChild(corto_object _parent, corto_string _id) {
    test_Dog _this;
    _this = test_Dog(corto_declareChild(_parent, _id, test_Dog_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_DogDefine(test_Dog _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Dog)_this)->b = b;
    return corto_define(_this);
}

test_Dog _test_DogAssign(test_Dog _this, bool a, bool b) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Dog)_this)->b = b;
    return _this;
}

corto_string _test_DogStr(test_Dog value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Dog_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Dog test_DogFromStr(test_Dog value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Dog_o), str);
    return value;
}

corto_equalityKind _test_DogCompare(test_Dog dst, test_Dog src) {
    return corto_compare(dst, src);
}

test_Env _test_EnvCreate(uint32_t assertCount) {
    test_Env _this;
    _this = test_Env(corto_declare(test_Env_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Env _test_EnvCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Env _this;
    _this = test_Env(corto_declareChild(_parent, _id, test_Env_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_EnvUpdate(test_Env _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Env)CORTO_OFFSET(_this, ((corto_type)test_Env_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Env _test_EnvDeclare(void) {
    test_Env _this;
    _this = test_Env(corto_declare(test_Env_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Env _test_EnvDeclareChild(corto_object _parent, corto_string _id) {
    test_Env _this;
    _this = test_Env(corto_declareChild(_parent, _id, test_Env_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_EnvDefine(test_Env _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Env _test_EnvAssign(test_Env _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_EnvStr(test_Env value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Env_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Env test_EnvFromStr(test_Env value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Env_o), str);
    return value;
}

corto_equalityKind _test_EnvCompare(test_Env dst, test_Env src) {
    return corto_compare(dst, src);
}

test_Err _test_ErrCreate(uint32_t assertCount, int32_t level, corto_string msg, corto_string category) {
    test_Err _this;
    _this = test_Err(corto_declare(test_Err_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Err)_this)->level = level;
        corto_setstr(&((test_Err)_this)->msg, msg);
        corto_setstr(&((test_Err)_this)->category, category);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Err _test_ErrCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int32_t level, corto_string msg, corto_string category) {
    test_Err _this;
    _this = test_Err(corto_declareChild(_parent, _id, test_Err_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Err)_this)->level = level;
        corto_setstr(&((test_Err)_this)->msg, msg);
        corto_setstr(&((test_Err)_this)->category, category);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ErrUpdate(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Err)CORTO_OFFSET(_this, ((corto_type)test_Err_o)->size)))->assertCount = assertCount;
            ((test_Err)((test_Err)CORTO_OFFSET(_this, ((corto_type)test_Err_o)->size)))->level = level;
            corto_setstr(&((test_Err)((test_Err)CORTO_OFFSET(_this, ((corto_type)test_Err_o)->size)))->msg, msg);
            corto_setstr(&((test_Err)((test_Err)CORTO_OFFSET(_this, ((corto_type)test_Err_o)->size)))->category, category);
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            ((test_Err)_this)->level = level;
            corto_setstr(&((test_Err)_this)->msg, msg);
            corto_setstr(&((test_Err)_this)->category, category);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Err _test_ErrDeclare(void) {
    test_Err _this;
    _this = test_Err(corto_declare(test_Err_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Err _test_ErrDeclareChild(corto_object _parent, corto_string _id) {
    test_Err _this;
    _this = test_Err(corto_declareChild(_parent, _id, test_Err_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ErrDefine(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Err)_this)->level = level;
    corto_setstr(&((test_Err)_this)->msg, msg);
    corto_setstr(&((test_Err)_this)->category, category);
    return corto_define(_this);
}

test_Err _test_ErrAssign(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Err)_this)->level = level;
    corto_setstr(&((test_Err)_this)->msg, msg);
    corto_setstr(&((test_Err)_this)->category, category);
    return _this;
}

corto_string _test_ErrStr(test_Err value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Err_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Err test_ErrFromStr(test_Err value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Err_o), str);
    return value;
}

corto_equalityKind _test_ErrCompare(test_Err dst, test_Err src) {
    return corto_compare(dst, src);
}

test_Event _test_EventCreate(uint32_t assertCount, test_EventTest et, corto_attr prevAttr) {
    test_Event _this;
    _this = test_Event(corto_declare(test_Event_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_setref(&((test_Event)_this)->et, et);
        ((test_Event)_this)->prevAttr = prevAttr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Event _test_EventCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, test_EventTest et, corto_attr prevAttr) {
    test_Event _this;
    _this = test_Event(corto_declareChild(_parent, _id, test_Event_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_setref(&((test_Event)_this)->et, et);
        ((test_Event)_this)->prevAttr = prevAttr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_EventUpdate(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Event)CORTO_OFFSET(_this, ((corto_type)test_Event_o)->size)))->assertCount = assertCount;
            corto_setref(&((test_Event)((test_Event)CORTO_OFFSET(_this, ((corto_type)test_Event_o)->size)))->et, et);
            ((test_Event)((test_Event)CORTO_OFFSET(_this, ((corto_type)test_Event_o)->size)))->prevAttr = prevAttr;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            corto_setref(&((test_Event)_this)->et, et);
            ((test_Event)_this)->prevAttr = prevAttr;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Event _test_EventDeclare(void) {
    test_Event _this;
    _this = test_Event(corto_declare(test_Event_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Event _test_EventDeclareChild(corto_object _parent, corto_string _id) {
    test_Event _this;
    _this = test_Event(corto_declareChild(_parent, _id, test_Event_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_EventDefine(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_Event)_this)->et, et);
    ((test_Event)_this)->prevAttr = prevAttr;
    return corto_define(_this);
}

test_Event _test_EventAssign(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_Event)_this)->et, et);
    ((test_Event)_this)->prevAttr = prevAttr;
    return _this;
}

corto_string _test_EventStr(test_Event value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Event_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Event test_EventFromStr(test_Event value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Event_o), str);
    return value;
}

corto_equalityKind _test_EventCompare(test_Event dst, test_Event src) {
    return corto_compare(dst, src);
}

test_EventCount* _test_EventCountCreate(int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount) {
    test_EventCount* _this;
    _this = test_EventCount(corto_declare(test_EventCount_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_EventCount*)_this)->declareCount = declareCount;
        ((test_EventCount*)_this)->defineCount = defineCount;
        ((test_EventCount*)_this)->updateCount = updateCount;
        ((test_EventCount*)_this)->deleteCount = deleteCount;
        ((test_EventCount*)_this)->resumeCount = resumeCount;
        ((test_EventCount*)_this)->suspendCount = suspendCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_EventCount* _test_EventCountCreateChild(corto_object _parent, corto_string _id, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount) {
    test_EventCount* _this;
    _this = test_EventCount(corto_declareChild(_parent, _id, test_EventCount_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_EventCount*)_this)->declareCount = declareCount;
        ((test_EventCount*)_this)->defineCount = defineCount;
        ((test_EventCount*)_this)->updateCount = updateCount;
        ((test_EventCount*)_this)->deleteCount = deleteCount;
        ((test_EventCount*)_this)->resumeCount = resumeCount;
        ((test_EventCount*)_this)->suspendCount = suspendCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_EventCountUpdate(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->declareCount = declareCount;
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->defineCount = defineCount;
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->updateCount = updateCount;
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->deleteCount = deleteCount;
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->resumeCount = resumeCount;
            ((test_EventCount*)((test_EventCount*)CORTO_OFFSET(_this, ((corto_type)test_EventCount_o)->size)))->suspendCount = suspendCount;
        } else {
            ((test_EventCount*)_this)->declareCount = declareCount;
            ((test_EventCount*)_this)->defineCount = defineCount;
            ((test_EventCount*)_this)->updateCount = updateCount;
            ((test_EventCount*)_this)->deleteCount = deleteCount;
            ((test_EventCount*)_this)->resumeCount = resumeCount;
            ((test_EventCount*)_this)->suspendCount = suspendCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_EventCount* _test_EventCountDeclare(void) {
    test_EventCount* _this;
    _this = test_EventCount(corto_declare(test_EventCount_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_EventCount* _test_EventCountDeclareChild(corto_object _parent, corto_string _id) {
    test_EventCount* _this;
    _this = test_EventCount(corto_declareChild(_parent, _id, test_EventCount_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_EventCountDefine(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount) {
    CORTO_UNUSED(_this);
    ((test_EventCount*)_this)->declareCount = declareCount;
    ((test_EventCount*)_this)->defineCount = defineCount;
    ((test_EventCount*)_this)->updateCount = updateCount;
    ((test_EventCount*)_this)->deleteCount = deleteCount;
    ((test_EventCount*)_this)->resumeCount = resumeCount;
    ((test_EventCount*)_this)->suspendCount = suspendCount;
    return corto_define(_this);
}

test_EventCount* _test_EventCountAssign(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount) {
    CORTO_UNUSED(_this);
    ((test_EventCount*)_this)->declareCount = declareCount;
    ((test_EventCount*)_this)->defineCount = defineCount;
    ((test_EventCount*)_this)->updateCount = updateCount;
    ((test_EventCount*)_this)->deleteCount = deleteCount;
    ((test_EventCount*)_this)->resumeCount = resumeCount;
    ((test_EventCount*)_this)->suspendCount = suspendCount;
    return _this;
}

corto_string _test_EventCountStr(test_EventCount* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_EventCount_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_EventCount* test_EventCountFromStr(test_EventCount* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_EventCount_o), str);
    return value;
}

corto_equalityKind test_EventCountCompare(test_EventCount* dst, test_EventCount* src) {
    return corto_comparep(dst, test_EventCount_o, src);
}

corto_int16 _test_EventCountInit(test_EventCount* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_EventCount_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_EventCount_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_EventCountDeinit(test_EventCount* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_EventCount_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_EventTest _test_EventTestCreate(corto_object scope) {
    test_EventTest _this;
    _this = test_EventTest(corto_declare(test_EventTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_EventTest)_this)->scope, scope);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_EventTest _test_EventTestCreateChild(corto_object _parent, corto_string _id, corto_object scope) {
    test_EventTest _this;
    _this = test_EventTest(corto_declareChild(_parent, _id, test_EventTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_EventTest)_this)->scope, scope);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_EventTestUpdate(test_EventTest _this, corto_object scope) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((test_EventTest)((test_EventTest)CORTO_OFFSET(_this, ((corto_type)test_EventTest_o)->size)))->scope, scope);
        } else {
            corto_setref(&((test_EventTest)_this)->scope, scope);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_EventTest _test_EventTestDeclare(void) {
    test_EventTest _this;
    _this = test_EventTest(corto_declare(test_EventTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_EventTest _test_EventTestDeclareChild(corto_object _parent, corto_string _id) {
    test_EventTest _this;
    _this = test_EventTest(corto_declareChild(_parent, _id, test_EventTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_EventTestDefine(test_EventTest _this, corto_object scope) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_EventTest)_this)->scope, scope);
    return corto_define(_this);
}

test_EventTest _test_EventTestAssign(test_EventTest _this, corto_object scope) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_EventTest)_this)->scope, scope);
    return _this;
}

corto_string _test_EventTestStr(test_EventTest value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_EventTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_EventTest test_EventTestFromStr(test_EventTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_EventTest_o), str);
    return value;
}

corto_equalityKind _test_EventTestCompare(test_EventTest dst, test_EventTest src) {
    return corto_compare(dst, src);
}

test_Foo _test_FooCreate(int32_t x, int32_t y) {
    test_Foo _this;
    _this = test_Foo(corto_declare(test_Foo_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Foo)_this)->x = x;
        ((test_Foo)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Foo _test_FooCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y) {
    test_Foo _this;
    _this = test_Foo(corto_declareChild(_parent, _id, test_Foo_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Foo)_this)->x = x;
        ((test_Foo)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_FooUpdate(test_Foo _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Foo)((test_Foo)CORTO_OFFSET(_this, ((corto_type)test_Foo_o)->size)))->x = x;
            ((test_Foo)((test_Foo)CORTO_OFFSET(_this, ((corto_type)test_Foo_o)->size)))->y = y;
        } else {
            ((test_Foo)_this)->x = x;
            ((test_Foo)_this)->y = y;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Foo _test_FooDeclare(void) {
    test_Foo _this;
    _this = test_Foo(corto_declare(test_Foo_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Foo _test_FooDeclareChild(corto_object _parent, corto_string _id) {
    test_Foo _this;
    _this = test_Foo(corto_declareChild(_parent, _id, test_Foo_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_FooDefine(test_Foo _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    ((test_Foo)_this)->x = x;
    ((test_Foo)_this)->y = y;
    return corto_define(_this);
}

test_Foo _test_FooAssign(test_Foo _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    ((test_Foo)_this)->x = x;
    ((test_Foo)_this)->y = y;
    return _this;
}

corto_string _test_FooStr(test_Foo value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Foo_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Foo test_FooFromStr(test_Foo value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Foo_o), str);
    return value;
}

corto_equalityKind _test_FooCompare(test_Foo dst, test_Foo src) {
    return corto_compare(dst, src);
}

test_FooReplicator _test_FooReplicatorCreate(corto_object mount) {
    test_FooReplicator _this;
    _this = test_FooReplicator(corto_declare(test_FooReplicator_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_mount)_this)->mount, mount);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_FooReplicator _test_FooReplicatorCreateChild(corto_object _parent, corto_string _id, corto_object mount) {
    test_FooReplicator _this;
    _this = test_FooReplicator(corto_declareChild(_parent, _id, test_FooReplicator_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_mount)_this)->mount, mount);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_FooReplicatorUpdate(test_FooReplicator _this, corto_object mount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_mount)((test_FooReplicator)CORTO_OFFSET(_this, ((corto_type)test_FooReplicator_o)->size)))->mount, mount);
        } else {
            corto_setref(&((corto_mount)_this)->mount, mount);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_FooReplicator _test_FooReplicatorDeclare(void) {
    test_FooReplicator _this;
    _this = test_FooReplicator(corto_declare(test_FooReplicator_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_FooReplicator _test_FooReplicatorDeclareChild(corto_object _parent, corto_string _id) {
    test_FooReplicator _this;
    _this = test_FooReplicator(corto_declareChild(_parent, _id, test_FooReplicator_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_FooReplicatorDefine(test_FooReplicator _this, corto_object mount) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_mount)_this)->mount, mount);
    return corto_define(_this);
}

test_FooReplicator _test_FooReplicatorAssign(test_FooReplicator _this, corto_object mount) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_mount)_this)->mount, mount);
    return _this;
}

corto_string _test_FooReplicatorStr(test_FooReplicator value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_FooReplicator_o));
    result = corto_strv(&v, 0);
    return result;
}

test_FooReplicator test_FooReplicatorFromStr(test_FooReplicator value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_FooReplicator_o), str);
    return value;
}

corto_equalityKind _test_FooReplicatorCompare(test_FooReplicator dst, test_FooReplicator src) {
    return corto_compare(dst, src);
}

test_Fullname _test_FullnameCreate(uint32_t assertCount) {
    test_Fullname _this;
    _this = test_Fullname(corto_declare(test_Fullname_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Fullname _test_FullnameCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Fullname _this;
    _this = test_Fullname(corto_declareChild(_parent, _id, test_Fullname_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_FullnameUpdate(test_Fullname _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Fullname)CORTO_OFFSET(_this, ((corto_type)test_Fullname_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Fullname _test_FullnameDeclare(void) {
    test_Fullname _this;
    _this = test_Fullname(corto_declare(test_Fullname_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Fullname _test_FullnameDeclareChild(corto_object _parent, corto_string _id) {
    test_Fullname _this;
    _this = test_Fullname(corto_declareChild(_parent, _id, test_Fullname_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_FullnameDefine(test_Fullname _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Fullname _test_FullnameAssign(test_Fullname _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_FullnameStr(test_Fullname value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Fullname_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Fullname test_FullnameFromStr(test_Fullname value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Fullname_o), str);
    return value;
}

corto_equalityKind _test_FullnameCompare(test_Fullname dst, test_Fullname src) {
    return corto_compare(dst, src);
}

test_GoldenRetriever _test_GoldenRetrieverCreate(bool a, bool b, bool c) {
    test_GoldenRetriever _this;
    _this = test_GoldenRetriever(corto_declare(test_GoldenRetriever_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Dog)_this)->b = b;
        ((test_GoldenRetriever)_this)->c = c;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_GoldenRetriever _test_GoldenRetrieverCreateChild(corto_object _parent, corto_string _id, bool a, bool b, bool c) {
    test_GoldenRetriever _this;
    _this = test_GoldenRetriever(corto_declareChild(_parent, _id, test_GoldenRetriever_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Animal)_this)->a = a;
        ((test_Dog)_this)->b = b;
        ((test_GoldenRetriever)_this)->c = c;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_GoldenRetrieverUpdate(test_GoldenRetriever _this, bool a, bool b, bool c) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Animal)((test_GoldenRetriever)CORTO_OFFSET(_this, ((corto_type)test_GoldenRetriever_o)->size)))->a = a;
            ((test_Dog)((test_GoldenRetriever)CORTO_OFFSET(_this, ((corto_type)test_GoldenRetriever_o)->size)))->b = b;
            ((test_GoldenRetriever)((test_GoldenRetriever)CORTO_OFFSET(_this, ((corto_type)test_GoldenRetriever_o)->size)))->c = c;
        } else {
            ((test_Animal)_this)->a = a;
            ((test_Dog)_this)->b = b;
            ((test_GoldenRetriever)_this)->c = c;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_GoldenRetriever _test_GoldenRetrieverDeclare(void) {
    test_GoldenRetriever _this;
    _this = test_GoldenRetriever(corto_declare(test_GoldenRetriever_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_GoldenRetriever _test_GoldenRetrieverDeclareChild(corto_object _parent, corto_string _id) {
    test_GoldenRetriever _this;
    _this = test_GoldenRetriever(corto_declareChild(_parent, _id, test_GoldenRetriever_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_GoldenRetrieverDefine(test_GoldenRetriever _this, bool a, bool b, bool c) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Dog)_this)->b = b;
    ((test_GoldenRetriever)_this)->c = c;
    return corto_define(_this);
}

test_GoldenRetriever _test_GoldenRetrieverAssign(test_GoldenRetriever _this, bool a, bool b, bool c) {
    CORTO_UNUSED(_this);
    ((test_Animal)_this)->a = a;
    ((test_Dog)_this)->b = b;
    ((test_GoldenRetriever)_this)->c = c;
    return _this;
}

corto_string _test_GoldenRetrieverStr(test_GoldenRetriever value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_GoldenRetriever_o));
    result = corto_strv(&v, 0);
    return result;
}

test_GoldenRetriever test_GoldenRetrieverFromStr(test_GoldenRetriever value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_GoldenRetriever_o), str);
    return value;
}

corto_equalityKind _test_GoldenRetrieverCompare(test_GoldenRetriever dst, test_GoldenRetriever src) {
    return corto_compare(dst, src);
}

intptr_t* _test_intwCreate(intptr_t value) {
    intptr_t* _this;
    _this = test_intw(corto_declare(test_intw_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

intptr_t* _test_intwCreateChild(corto_object _parent, corto_string _id, intptr_t value) {
    intptr_t* _this;
    _this = test_intw(corto_declareChild(_parent, _id, test_intw_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_intwUpdate(intptr_t* _this, intptr_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((intptr_t*)CORTO_OFFSET(_this, ((corto_type)test_intw_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

intptr_t* _test_intwDeclare(void) {
    intptr_t* _this;
    _this = test_intw(corto_declare(test_intw_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

intptr_t* _test_intwDeclareChild(corto_object _parent, corto_string _id) {
    intptr_t* _this;
    _this = test_intw(corto_declareChild(_parent, _id, test_intw_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_intwDefine(intptr_t* _this, intptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

intptr_t* _test_intwAssign(intptr_t* _this, intptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _test_intwStr(test_intw value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_intw_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

intptr_t* test_intwFromStr(intptr_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_intw_o), str);
    return value;
}

corto_equalityKind test_intwCompare(test_intw dst, test_intw src) {
    return corto_comparep(&dst, test_intw_o, &src);
}

corto_int16 _test_intwInit(test_intw* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_intw_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_intw_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_intwDeinit(test_intw* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_intw_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_LeafRoot _test_LeafRootCreate(int32_t id, corto_string value) {
    test_LeafRoot _this;
    _this = test_LeafRoot(corto_declare(test_LeafRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_LeafRoot)_this)->id = id;
        corto_setstr(&((test_LeafRoot)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_LeafRoot _test_LeafRootCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_LeafRoot _this;
    _this = test_LeafRoot(corto_declareChild(_parent, _id, test_LeafRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_LeafRoot)_this)->id = id;
        corto_setstr(&((test_LeafRoot)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_LeafRootUpdate(test_LeafRoot _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_LeafRoot)((test_LeafRoot)CORTO_OFFSET(_this, ((corto_type)test_LeafRoot_o)->size)))->id = id;
            corto_setstr(&((test_LeafRoot)((test_LeafRoot)CORTO_OFFSET(_this, ((corto_type)test_LeafRoot_o)->size)))->value, value);
        } else {
            ((test_LeafRoot)_this)->id = id;
            corto_setstr(&((test_LeafRoot)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_LeafRoot _test_LeafRootDeclare(void) {
    test_LeafRoot _this;
    _this = test_LeafRoot(corto_declare(test_LeafRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_LeafRoot _test_LeafRootDeclareChild(corto_object _parent, corto_string _id) {
    test_LeafRoot _this;
    _this = test_LeafRoot(corto_declareChild(_parent, _id, test_LeafRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_LeafRootDefine(test_LeafRoot _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_LeafRoot)_this)->id = id;
    corto_setstr(&((test_LeafRoot)_this)->value, value);
    return corto_define(_this);
}

test_LeafRoot _test_LeafRootAssign(test_LeafRoot _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_LeafRoot)_this)->id = id;
    corto_setstr(&((test_LeafRoot)_this)->value, value);
    return _this;
}

corto_string _test_LeafRootStr(test_LeafRoot value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_LeafRoot_o));
    result = corto_strv(&v, 0);
    return result;
}

test_LeafRoot test_LeafRootFromStr(test_LeafRoot value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_LeafRoot_o), str);
    return value;
}

corto_equalityKind _test_LeafRootCompare(test_LeafRoot dst, test_LeafRoot src) {
    return corto_compare(dst, src);
}

test_Line* _test_LineCreate(test_Point* start, test_Point* stop) {
    test_Line* _this;
    _this = test_Line(corto_declare(test_Line_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (start) {
            corto_copyp(&((test_Line*)_this)->start, test_Point_o, start);
        }
        if (stop) {
            corto_copyp(&((test_Line*)_this)->stop, test_Point_o, stop);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Line* _test_LineCreateChild(corto_object _parent, corto_string _id, test_Point* start, test_Point* stop) {
    test_Line* _this;
    _this = test_Line(corto_declareChild(_parent, _id, test_Line_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (start) {
            corto_copyp(&((test_Line*)_this)->start, test_Point_o, start);
        }
        if (stop) {
            corto_copyp(&((test_Line*)_this)->stop, test_Point_o, stop);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_LineUpdate(test_Line* _this, test_Point* start, test_Point* stop) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            if (start) {
                corto_copyp(&((test_Line*)((test_Line*)CORTO_OFFSET(_this, ((corto_type)test_Line_o)->size)))->start, test_Point_o, start);
            }
            if (stop) {
                corto_copyp(&((test_Line*)((test_Line*)CORTO_OFFSET(_this, ((corto_type)test_Line_o)->size)))->stop, test_Point_o, stop);
            }
        } else {
            if (start) {
                corto_copyp(&((test_Line*)_this)->start, test_Point_o, start);
            }
            if (stop) {
                corto_copyp(&((test_Line*)_this)->stop, test_Point_o, stop);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Line* _test_LineDeclare(void) {
    test_Line* _this;
    _this = test_Line(corto_declare(test_Line_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Line* _test_LineDeclareChild(corto_object _parent, corto_string _id) {
    test_Line* _this;
    _this = test_Line(corto_declareChild(_parent, _id, test_Line_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_LineDefine(test_Line* _this, test_Point* start, test_Point* stop) {
    CORTO_UNUSED(_this);
    if (start) {
        corto_copyp(&((test_Line*)_this)->start, test_Point_o, start);
    }
    if (stop) {
        corto_copyp(&((test_Line*)_this)->stop, test_Point_o, stop);
    }
    return corto_define(_this);
}

test_Line* _test_LineAssign(test_Line* _this, test_Point* start, test_Point* stop) {
    CORTO_UNUSED(_this);
    if (start) {
        corto_copyp(&((test_Line*)_this)->start, test_Point_o, start);
    }
    if (stop) {
        corto_copyp(&((test_Line*)_this)->stop, test_Point_o, stop);
    }
    return _this;
}

corto_string _test_LineStr(test_Line* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_Line_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_Line* test_LineFromStr(test_Line* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Line_o), str);
    return value;
}

corto_equalityKind test_LineCompare(test_Line* dst, test_Line* src) {
    return corto_comparep(dst, test_Line_o, src);
}

corto_int16 _test_LineInit(test_Line* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Line_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_Line_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_LineDeinit(test_Line* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_Line_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Loader _test_LoaderCreate(uint32_t assertCount) {
    test_Loader _this;
    _this = test_Loader(corto_declare(test_Loader_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Loader _test_LoaderCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Loader _this;
    _this = test_Loader(corto_declareChild(_parent, _id, test_Loader_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_LoaderUpdate(test_Loader _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Loader)CORTO_OFFSET(_this, ((corto_type)test_Loader_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Loader _test_LoaderDeclare(void) {
    test_Loader _this;
    _this = test_Loader(corto_declare(test_Loader_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Loader _test_LoaderDeclareChild(corto_object _parent, corto_string _id) {
    test_Loader _this;
    _this = test_Loader(corto_declareChild(_parent, _id, test_Loader_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_LoaderDefine(test_Loader _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Loader _test_LoaderAssign(test_Loader _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_LoaderStr(test_Loader value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Loader_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Loader test_LoaderFromStr(test_Loader value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Loader_o), str);
    return value;
}

corto_equalityKind _test_LoaderCompare(test_Loader dst, test_Loader src) {
    return corto_compare(dst, src);
}

test_Lookup _test_LookupCreate(uint32_t assertCount) {
    test_Lookup _this;
    _this = test_Lookup(corto_declare(test_Lookup_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Lookup _test_LookupCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Lookup _this;
    _this = test_Lookup(corto_declareChild(_parent, _id, test_Lookup_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_LookupUpdate(test_Lookup _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Lookup)CORTO_OFFSET(_this, ((corto_type)test_Lookup_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Lookup _test_LookupDeclare(void) {
    test_Lookup _this;
    _this = test_Lookup(corto_declare(test_Lookup_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Lookup _test_LookupDeclareChild(corto_object _parent, corto_string _id) {
    test_Lookup _this;
    _this = test_Lookup(corto_declareChild(_parent, _id, test_Lookup_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_LookupDefine(test_Lookup _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Lookup _test_LookupAssign(test_Lookup _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_LookupStr(test_Lookup value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Lookup_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Lookup test_LookupFromStr(test_Lookup value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Lookup_o), str);
    return value;
}

corto_equalityKind _test_LookupCompare(test_Lookup dst, test_Lookup src) {
    return corto_compare(dst, src);
}

test_Matcher _test_MatcherCreate(uint32_t assertCount) {
    test_Matcher _this;
    _this = test_Matcher(corto_declare(test_Matcher_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Matcher _test_MatcherCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Matcher _this;
    _this = test_Matcher(corto_declareChild(_parent, _id, test_Matcher_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_MatcherUpdate(test_Matcher _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Matcher)CORTO_OFFSET(_this, ((corto_type)test_Matcher_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Matcher _test_MatcherDeclare(void) {
    test_Matcher _this;
    _this = test_Matcher(corto_declare(test_Matcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Matcher _test_MatcherDeclareChild(corto_object _parent, corto_string _id) {
    test_Matcher _this;
    _this = test_Matcher(corto_declareChild(_parent, _id, test_Matcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_MatcherDefine(test_Matcher _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Matcher _test_MatcherAssign(test_Matcher _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_MatcherStr(test_Matcher value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Matcher_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Matcher test_MatcherFromStr(test_Matcher value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Matcher_o), str);
    return value;
}

corto_equalityKind _test_MatcherCompare(test_Matcher dst, test_Matcher src) {
    return corto_compare(dst, src);
}

test_MethodForwardTest _test_MethodForwardTestCreate(void) {
    test_MethodForwardTest _this;
    _this = test_MethodForwardTest(corto_declare(test_MethodForwardTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_MethodForwardTest _test_MethodForwardTestCreateChild(corto_object _parent, corto_string _id) {
    test_MethodForwardTest _this;
    _this = test_MethodForwardTest(corto_declareChild(_parent, _id, test_MethodForwardTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_MethodForwardTestUpdate(test_MethodForwardTest _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodForwardTest _test_MethodForwardTestDeclare(void) {
    test_MethodForwardTest _this;
    _this = test_MethodForwardTest(corto_declare(test_MethodForwardTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_MethodForwardTest _test_MethodForwardTestDeclareChild(corto_object _parent, corto_string _id) {
    test_MethodForwardTest _this;
    _this = test_MethodForwardTest(corto_declareChild(_parent, _id, test_MethodForwardTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_MethodForwardTestDefine(test_MethodForwardTest _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_MethodForwardTest _test_MethodForwardTestAssign(test_MethodForwardTest _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_MethodForwardTestStr(test_MethodForwardTest value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_MethodForwardTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodForwardTest test_MethodForwardTestFromStr(test_MethodForwardTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodForwardTest_o), str);
    return value;
}

corto_equalityKind _test_MethodForwardTestCompare(test_MethodForwardTest dst, test_MethodForwardTest src) {
    return corto_compare(dst, src);
}

test_MethodResolver _test_MethodResolverCreate(uint32_t assertCount) {
    test_MethodResolver _this;
    _this = test_MethodResolver(corto_declare(test_MethodResolver_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_MethodResolver _test_MethodResolverCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_MethodResolver _this;
    _this = test_MethodResolver(corto_declareChild(_parent, _id, test_MethodResolver_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_MethodResolverUpdate(test_MethodResolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_MethodResolver)CORTO_OFFSET(_this, ((corto_type)test_MethodResolver_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodResolver _test_MethodResolverDeclare(void) {
    test_MethodResolver _this;
    _this = test_MethodResolver(corto_declare(test_MethodResolver_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_MethodResolver _test_MethodResolverDeclareChild(corto_object _parent, corto_string _id) {
    test_MethodResolver _this;
    _this = test_MethodResolver(corto_declareChild(_parent, _id, test_MethodResolver_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_MethodResolverDefine(test_MethodResolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_MethodResolver _test_MethodResolverAssign(test_MethodResolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_MethodResolverStr(test_MethodResolver value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_MethodResolver_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodResolver test_MethodResolverFromStr(test_MethodResolver value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodResolver_o), str);
    return value;
}

corto_equalityKind _test_MethodResolverCompare(test_MethodResolver dst, test_MethodResolver src) {
    return corto_compare(dst, src);
}

test_MethodTester _test_MethodTesterCreate(void) {
    test_MethodTester _this;
    _this = test_MethodTester(corto_declare(test_MethodTester_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_MethodTester _test_MethodTesterCreateChild(corto_object _parent, corto_string _id) {
    test_MethodTester _this;
    _this = test_MethodTester(corto_declareChild(_parent, _id, test_MethodTester_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_MethodTesterUpdate(test_MethodTester _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodTester _test_MethodTesterDeclare(void) {
    test_MethodTester _this;
    _this = test_MethodTester(corto_declare(test_MethodTester_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_MethodTester _test_MethodTesterDeclareChild(corto_object _parent, corto_string _id) {
    test_MethodTester _this;
    _this = test_MethodTester(corto_declareChild(_parent, _id, test_MethodTester_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_MethodTesterDefine(test_MethodTester _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_MethodTester _test_MethodTesterAssign(test_MethodTester _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_MethodTesterStr(test_MethodTester value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_MethodTester_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodTester test_MethodTesterFromStr(test_MethodTester value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodTester_o), str);
    return value;
}

corto_equalityKind _test_MethodTesterCompare(test_MethodTester dst, test_MethodTester src) {
    return corto_compare(dst, src);
}

test_MethodTesterInherit _test_MethodTesterInheritCreate(void) {
    test_MethodTesterInherit _this;
    _this = test_MethodTesterInherit(corto_declare(test_MethodTesterInherit_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_MethodTesterInherit _test_MethodTesterInheritCreateChild(corto_object _parent, corto_string _id) {
    test_MethodTesterInherit _this;
    _this = test_MethodTesterInherit(corto_declareChild(_parent, _id, test_MethodTesterInherit_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_MethodTesterInheritUpdate(test_MethodTesterInherit _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodTesterInherit _test_MethodTesterInheritDeclare(void) {
    test_MethodTesterInherit _this;
    _this = test_MethodTesterInherit(corto_declare(test_MethodTesterInherit_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_MethodTesterInherit _test_MethodTesterInheritDeclareChild(corto_object _parent, corto_string _id) {
    test_MethodTesterInherit _this;
    _this = test_MethodTesterInherit(corto_declareChild(_parent, _id, test_MethodTesterInherit_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_MethodTesterInheritDefine(test_MethodTesterInherit _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_MethodTesterInherit _test_MethodTesterInheritAssign(test_MethodTesterInherit _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_MethodTesterInheritStr(test_MethodTesterInherit value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_MethodTesterInherit_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodTesterInherit test_MethodTesterInheritFromStr(test_MethodTesterInherit value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodTesterInherit_o), str);
    return value;
}

corto_equalityKind _test_MethodTesterInheritCompare(test_MethodTesterInherit dst, test_MethodTesterInherit src) {
    return corto_compare(dst, src);
}

test_NestedConstructFailInRoot _test_NestedConstructFailInRootCreate(void) {
    test_NestedConstructFailInRoot _this;
    _this = test_NestedConstructFailInRoot(corto_declare(test_NestedConstructFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedConstructFailInRoot _test_NestedConstructFailInRootCreateChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInRoot _this;
    _this = test_NestedConstructFailInRoot(corto_declareChild(_parent, _id, test_NestedConstructFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInRootUpdate(test_NestedConstructFailInRoot _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedConstructFailInRoot _test_NestedConstructFailInRootDeclare(void) {
    test_NestedConstructFailInRoot _this;
    _this = test_NestedConstructFailInRoot(corto_declare(test_NestedConstructFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedConstructFailInRoot _test_NestedConstructFailInRootDeclareChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInRoot _this;
    _this = test_NestedConstructFailInRoot(corto_declareChild(_parent, _id, test_NestedConstructFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInRootDefine(test_NestedConstructFailInRoot _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedConstructFailInRoot _test_NestedConstructFailInRootAssign(test_NestedConstructFailInRoot _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedConstructFailInRootStr(test_NestedConstructFailInRoot value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_NestedConstructFailInRoot_o));
    result = corto_strv(&v, 0);
    return result;
}

test_NestedConstructFailInRoot test_NestedConstructFailInRootFromStr(test_NestedConstructFailInRoot value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedConstructFailInRoot_o), str);
    return value;
}

corto_equalityKind _test_NestedConstructFailInRootCompare(test_NestedConstructFailInRoot dst, test_NestedConstructFailInRoot src) {
    return corto_compare(dst, src);
}

test_NestedConstructFailInTier1 _test_NestedConstructFailInTier1Create(void) {
    test_NestedConstructFailInTier1 _this;
    _this = test_NestedConstructFailInTier1(corto_declare(test_NestedConstructFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedConstructFailInTier1 _test_NestedConstructFailInTier1CreateChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInTier1 _this;
    _this = test_NestedConstructFailInTier1(corto_declareChild(_parent, _id, test_NestedConstructFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInTier1Update(test_NestedConstructFailInTier1 _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedConstructFailInTier1 _test_NestedConstructFailInTier1Declare(void) {
    test_NestedConstructFailInTier1 _this;
    _this = test_NestedConstructFailInTier1(corto_declare(test_NestedConstructFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedConstructFailInTier1 _test_NestedConstructFailInTier1DeclareChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInTier1 _this;
    _this = test_NestedConstructFailInTier1(corto_declareChild(_parent, _id, test_NestedConstructFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInTier1Define(test_NestedConstructFailInTier1 _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedConstructFailInTier1 _test_NestedConstructFailInTier1Assign(test_NestedConstructFailInTier1 _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedConstructFailInTier1Str(test_NestedConstructFailInTier1 value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_NestedConstructFailInTier1_o));
    result = corto_strv(&v, 0);
    return result;
}

test_NestedConstructFailInTier1 test_NestedConstructFailInTier1FromStr(test_NestedConstructFailInTier1 value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedConstructFailInTier1_o), str);
    return value;
}

corto_equalityKind _test_NestedConstructFailInTier1Compare(test_NestedConstructFailInTier1 dst, test_NestedConstructFailInTier1 src) {
    return corto_compare(dst, src);
}

test_NestedConstructFailInTier2 _test_NestedConstructFailInTier2Create(void) {
    test_NestedConstructFailInTier2 _this;
    _this = test_NestedConstructFailInTier2(corto_declare(test_NestedConstructFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedConstructFailInTier2 _test_NestedConstructFailInTier2CreateChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInTier2 _this;
    _this = test_NestedConstructFailInTier2(corto_declareChild(_parent, _id, test_NestedConstructFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInTier2Update(test_NestedConstructFailInTier2 _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedConstructFailInTier2 _test_NestedConstructFailInTier2Declare(void) {
    test_NestedConstructFailInTier2 _this;
    _this = test_NestedConstructFailInTier2(corto_declare(test_NestedConstructFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedConstructFailInTier2 _test_NestedConstructFailInTier2DeclareChild(corto_object _parent, corto_string _id) {
    test_NestedConstructFailInTier2 _this;
    _this = test_NestedConstructFailInTier2(corto_declareChild(_parent, _id, test_NestedConstructFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedConstructFailInTier2Define(test_NestedConstructFailInTier2 _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedConstructFailInTier2 _test_NestedConstructFailInTier2Assign(test_NestedConstructFailInTier2 _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedConstructFailInTier2Str(test_NestedConstructFailInTier2 value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_NestedConstructFailInTier2_o));
    result = corto_strv(&v, 0);
    return result;
}

test_NestedConstructFailInTier2 test_NestedConstructFailInTier2FromStr(test_NestedConstructFailInTier2 value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedConstructFailInTier2_o), str);
    return value;
}

corto_equalityKind _test_NestedConstructFailInTier2Compare(test_NestedConstructFailInTier2 dst, test_NestedConstructFailInTier2 src) {
    return corto_compare(dst, src);
}

test_NestedInitFailInRoot* _test_NestedInitFailInRootCreate(void) {
    test_NestedInitFailInRoot* _this;
    _this = test_NestedInitFailInRoot(corto_declare(test_NestedInitFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedInitFailInRoot* _test_NestedInitFailInRootCreateChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInRoot* _this;
    _this = test_NestedInitFailInRoot(corto_declareChild(_parent, _id, test_NestedInitFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedInitFailInRootUpdate(test_NestedInitFailInRoot* _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedInitFailInRoot* _test_NestedInitFailInRootDeclare(void) {
    test_NestedInitFailInRoot* _this;
    _this = test_NestedInitFailInRoot(corto_declare(test_NestedInitFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedInitFailInRoot* _test_NestedInitFailInRootDeclareChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInRoot* _this;
    _this = test_NestedInitFailInRoot(corto_declareChild(_parent, _id, test_NestedInitFailInRoot_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedInitFailInRootDefine(test_NestedInitFailInRoot* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedInitFailInRoot* _test_NestedInitFailInRootAssign(test_NestedInitFailInRoot* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedInitFailInRootStr(test_NestedInitFailInRoot* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInRoot_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_NestedInitFailInRoot* test_NestedInitFailInRootFromStr(test_NestedInitFailInRoot* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedInitFailInRoot_o), str);
    return value;
}

corto_equalityKind test_NestedInitFailInRootCompare(test_NestedInitFailInRoot* dst, test_NestedInitFailInRoot* src) {
    return corto_comparep(dst, test_NestedInitFailInRoot_o, src);
}

corto_int16 _test_NestedInitFailInRootInit(test_NestedInitFailInRoot* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_NestedInitFailInRoot_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInRoot_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_NestedInitFailInRootDeinit(test_NestedInitFailInRoot* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInRoot_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_NestedInitFailInTier1* _test_NestedInitFailInTier1Create(void) {
    test_NestedInitFailInTier1* _this;
    _this = test_NestedInitFailInTier1(corto_declare(test_NestedInitFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedInitFailInTier1* _test_NestedInitFailInTier1CreateChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInTier1* _this;
    _this = test_NestedInitFailInTier1(corto_declareChild(_parent, _id, test_NestedInitFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedInitFailInTier1Update(test_NestedInitFailInTier1* _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedInitFailInTier1* _test_NestedInitFailInTier1Declare(void) {
    test_NestedInitFailInTier1* _this;
    _this = test_NestedInitFailInTier1(corto_declare(test_NestedInitFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedInitFailInTier1* _test_NestedInitFailInTier1DeclareChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInTier1* _this;
    _this = test_NestedInitFailInTier1(corto_declareChild(_parent, _id, test_NestedInitFailInTier1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedInitFailInTier1Define(test_NestedInitFailInTier1* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedInitFailInTier1* _test_NestedInitFailInTier1Assign(test_NestedInitFailInTier1* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedInitFailInTier1Str(test_NestedInitFailInTier1* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier1_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_NestedInitFailInTier1* test_NestedInitFailInTier1FromStr(test_NestedInitFailInTier1* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedInitFailInTier1_o), str);
    return value;
}

corto_equalityKind test_NestedInitFailInTier1Compare(test_NestedInitFailInTier1* dst, test_NestedInitFailInTier1* src) {
    return corto_comparep(dst, test_NestedInitFailInTier1_o, src);
}

corto_int16 _test_NestedInitFailInTier1Init(test_NestedInitFailInTier1* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_NestedInitFailInTier1_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier1_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_NestedInitFailInTier1Deinit(test_NestedInitFailInTier1* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier1_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_NestedInitFailInTier2* _test_NestedInitFailInTier2Create(void) {
    test_NestedInitFailInTier2* _this;
    _this = test_NestedInitFailInTier2(corto_declare(test_NestedInitFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_NestedInitFailInTier2* _test_NestedInitFailInTier2CreateChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInTier2* _this;
    _this = test_NestedInitFailInTier2(corto_declareChild(_parent, _id, test_NestedInitFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_NestedInitFailInTier2Update(test_NestedInitFailInTier2* _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_NestedInitFailInTier2* _test_NestedInitFailInTier2Declare(void) {
    test_NestedInitFailInTier2* _this;
    _this = test_NestedInitFailInTier2(corto_declare(test_NestedInitFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_NestedInitFailInTier2* _test_NestedInitFailInTier2DeclareChild(corto_object _parent, corto_string _id) {
    test_NestedInitFailInTier2* _this;
    _this = test_NestedInitFailInTier2(corto_declareChild(_parent, _id, test_NestedInitFailInTier2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_NestedInitFailInTier2Define(test_NestedInitFailInTier2* _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_NestedInitFailInTier2* _test_NestedInitFailInTier2Assign(test_NestedInitFailInTier2* _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_NestedInitFailInTier2Str(test_NestedInitFailInTier2* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier2_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_NestedInitFailInTier2* test_NestedInitFailInTier2FromStr(test_NestedInitFailInTier2* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_NestedInitFailInTier2_o), str);
    return value;
}

corto_equalityKind test_NestedInitFailInTier2Compare(test_NestedInitFailInTier2* dst, test_NestedInitFailInTier2* src) {
    return corto_comparep(dst, test_NestedInitFailInTier2_o, src);
}

corto_int16 _test_NestedInitFailInTier2Init(test_NestedInitFailInTier2* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_NestedInitFailInTier2_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier2_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_NestedInitFailInTier2Deinit(test_NestedInitFailInTier2* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_NestedInitFailInTier2_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_object* _test_ObjectArrayCreate(corto_uint32 length, corto_object* elements) {
    corto_object* _this;
    _this = test_ObjectArray(corto_declare(test_ObjectArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&_this[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_object* _test_ObjectArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements) {
    corto_object* _this;
    _this = test_ObjectArray(corto_declareChild(_parent, _id, test_ObjectArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&_this[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObjectArrayUpdate(test_ObjectArray _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&((corto_object*)CORTO_OFFSET(_this, ((corto_type)test_ObjectArray_o)->size))[i], elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&_this[i], elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_object* _test_ObjectArrayDeclare(void) {
    corto_object* _this;
    _this = test_ObjectArray(corto_declare(test_ObjectArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_object* _test_ObjectArrayDeclareChild(corto_object _parent, corto_string _id) {
    corto_object* _this;
    _this = test_ObjectArray(corto_declareChild(_parent, _id, test_ObjectArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObjectArrayDefine(test_ObjectArray _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this[i], elements[i]);
    }
    return corto_define(_this);
}

corto_object* _test_ObjectArrayAssign(test_ObjectArray _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this[i], elements[i]);
    }
    return _this;
}

corto_string _test_ObjectArrayStr(test_ObjectArray value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectArray_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_object* test_ObjectArrayFromStr(test_ObjectArray value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObjectArray_o), str);
    return value;
}

corto_equalityKind test_ObjectArrayCompare(test_ObjectArray dst, test_ObjectArray src) {
    return corto_comparep(dst, test_ObjectArray_o, src);
}

corto_int16 _test_ObjectArrayInit(test_ObjectArray* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_ObjectArray_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectArray_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ObjectArrayDeinit(test_ObjectArray* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectArray_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ObjectList* _test_ObjectListCreate(corto_uint32 length, corto_object* elements) {
    test_ObjectList* _this;
    _this = test_ObjectList(corto_declare(test_ObjectList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_ObjectListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_ObjectListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ObjectList* _test_ObjectListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements) {
    test_ObjectList* _this;
    _this = test_ObjectList(corto_declareChild(_parent, _id, test_ObjectList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_ObjectListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_ObjectListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObjectListUpdate(test_ObjectList* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            test_ObjectListClear(*((test_ObjectList*)CORTO_OFFSET(_this, ((corto_type)test_ObjectList_o)->size)));
            for (i = 0; i < length; i ++) {
                test_ObjectListAppend(*((test_ObjectList*)CORTO_OFFSET(_this, ((corto_type)test_ObjectList_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            test_ObjectListClear(*_this);
            for (i = 0; i < length; i ++) {
                test_ObjectListAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ObjectList* _test_ObjectListDeclare(void) {
    test_ObjectList* _this;
    _this = test_ObjectList(corto_declare(test_ObjectList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ObjectList* _test_ObjectListDeclareChild(corto_object _parent, corto_string _id) {
    test_ObjectList* _this;
    _this = test_ObjectList(corto_declareChild(_parent, _id, test_ObjectList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObjectListDefine(test_ObjectList* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_ObjectListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_ObjectListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

test_ObjectList* _test_ObjectListAssign(test_ObjectList* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_ObjectListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_ObjectListAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _test_ObjectListStr(test_ObjectList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_ObjectList* test_ObjectListFromStr(test_ObjectList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObjectList_o), str);
    return value;
}

corto_equalityKind test_ObjectListCompare(test_ObjectList dst, test_ObjectList src) {
    return corto_comparep(&dst, test_ObjectList_o, &src);
}

corto_int16 _test_ObjectListInit(test_ObjectList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_ObjectList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ObjectListDeinit(test_ObjectList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectList_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ObjectMgmt _test_ObjectMgmtCreate(uint32_t assertCount) {
    test_ObjectMgmt _this;
    _this = test_ObjectMgmt(corto_declare(test_ObjectMgmt_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ObjectMgmt _test_ObjectMgmtCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_ObjectMgmt _this;
    _this = test_ObjectMgmt(corto_declareChild(_parent, _id, test_ObjectMgmt_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObjectMgmtUpdate(test_ObjectMgmt _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_ObjectMgmt)CORTO_OFFSET(_this, ((corto_type)test_ObjectMgmt_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ObjectMgmt _test_ObjectMgmtDeclare(void) {
    test_ObjectMgmt _this;
    _this = test_ObjectMgmt(corto_declare(test_ObjectMgmt_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ObjectMgmt _test_ObjectMgmtDeclareChild(corto_object _parent, corto_string _id) {
    test_ObjectMgmt _this;
    _this = test_ObjectMgmt(corto_declareChild(_parent, _id, test_ObjectMgmt_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObjectMgmtDefine(test_ObjectMgmt _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_ObjectMgmt _test_ObjectMgmtAssign(test_ObjectMgmt _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_ObjectMgmtStr(test_ObjectMgmt value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ObjectMgmt_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ObjectMgmt test_ObjectMgmtFromStr(test_ObjectMgmt value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObjectMgmt_o), str);
    return value;
}

corto_equalityKind _test_ObjectMgmtCompare(test_ObjectMgmt dst, test_ObjectMgmt src) {
    return corto_compare(dst, src);
}

test_ObjectSequence* _test_ObjectSequenceCreate(corto_uint32 length, corto_object* elements) {
    test_ObjectSequence* _this;
    _this = test_ObjectSequence(corto_declare(test_ObjectSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_ObjectSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ObjectSequence* _test_ObjectSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements) {
    test_ObjectSequence* _this;
    _this = test_ObjectSequence(corto_declareChild(_parent, _id, test_ObjectSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_ObjectSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setref(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObjectSequenceUpdate(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            test_ObjectSequenceSize(((test_ObjectSequence*)CORTO_OFFSET(_this, ((corto_type)test_ObjectSequence_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&((test_ObjectSequence*)CORTO_OFFSET(_this, ((corto_type)test_ObjectSequence_o)->size))->buffer[i], elements[i]);
            }
        } else {
            test_ObjectSequenceSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&_this->buffer[i], elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ObjectSequence* _test_ObjectSequenceDeclare(void) {
    test_ObjectSequence* _this;
    _this = test_ObjectSequence(corto_declare(test_ObjectSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ObjectSequence* _test_ObjectSequenceDeclareChild(corto_object _parent, corto_string _id) {
    test_ObjectSequence* _this;
    _this = test_ObjectSequence(corto_declareChild(_parent, _id, test_ObjectSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObjectSequenceDefine(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    test_ObjectSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

test_ObjectSequence* _test_ObjectSequenceAssign(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    test_ObjectSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _test_ObjectSequenceStr(test_ObjectSequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectSequence_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_ObjectSequence* test_ObjectSequenceFromStr(test_ObjectSequence* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObjectSequence_o), str);
    return value;
}

corto_equalityKind test_ObjectSequenceCompare(test_ObjectSequence dst, test_ObjectSequence src) {
    return corto_comparep(&dst, test_ObjectSequence_o, &src);
}

corto_int16 _test_ObjectSequenceInit(test_ObjectSequence* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_ObjectSequence_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectSequence_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ObjectSequenceDeinit(test_ObjectSequence* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_ObjectSequence_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ObserverDispatcher _test_ObserverDispatcherCreate(bool called) {
    test_ObserverDispatcher _this;
    _this = test_ObserverDispatcher(corto_declare(test_ObserverDispatcher_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ObserverDispatcher)_this)->called = called;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ObserverDispatcher _test_ObserverDispatcherCreateChild(corto_object _parent, corto_string _id, bool called) {
    test_ObserverDispatcher _this;
    _this = test_ObserverDispatcher(corto_declareChild(_parent, _id, test_ObserverDispatcher_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_ObserverDispatcher)_this)->called = called;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObserverDispatcherUpdate(test_ObserverDispatcher _this, bool called) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_ObserverDispatcher)((test_ObserverDispatcher)CORTO_OFFSET(_this, ((corto_type)test_ObserverDispatcher_o)->size)))->called = called;
        } else {
            ((test_ObserverDispatcher)_this)->called = called;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ObserverDispatcher _test_ObserverDispatcherDeclare(void) {
    test_ObserverDispatcher _this;
    _this = test_ObserverDispatcher(corto_declare(test_ObserverDispatcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ObserverDispatcher _test_ObserverDispatcherDeclareChild(corto_object _parent, corto_string _id) {
    test_ObserverDispatcher _this;
    _this = test_ObserverDispatcher(corto_declareChild(_parent, _id, test_ObserverDispatcher_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObserverDispatcherDefine(test_ObserverDispatcher _this, bool called) {
    CORTO_UNUSED(_this);
    ((test_ObserverDispatcher)_this)->called = called;
    return corto_define(_this);
}

test_ObserverDispatcher _test_ObserverDispatcherAssign(test_ObserverDispatcher _this, bool called) {
    CORTO_UNUSED(_this);
    ((test_ObserverDispatcher)_this)->called = called;
    return _this;
}

corto_string _test_ObserverDispatcherStr(test_ObserverDispatcher value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ObserverDispatcher_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ObserverDispatcher test_ObserverDispatcherFromStr(test_ObserverDispatcher value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObserverDispatcher_o), str);
    return value;
}

corto_equalityKind _test_ObserverDispatcherCompare(test_ObserverDispatcher dst, test_ObserverDispatcher src) {
    return corto_compare(dst, src);
}

test_Observers _test_ObserversCreate(uint32_t assertCount, int32_t count) {
    test_Observers _this;
    _this = test_Observers(corto_declare(test_Observers_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Observers)_this)->count = count;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Observers _test_ObserversCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int32_t count) {
    test_Observers _this;
    _this = test_Observers(corto_declareChild(_parent, _id, test_Observers_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Observers)_this)->count = count;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ObserversUpdate(test_Observers _this, uint32_t assertCount, int32_t count) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Observers)CORTO_OFFSET(_this, ((corto_type)test_Observers_o)->size)))->assertCount = assertCount;
            ((test_Observers)((test_Observers)CORTO_OFFSET(_this, ((corto_type)test_Observers_o)->size)))->count = count;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            ((test_Observers)_this)->count = count;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Observers _test_ObserversDeclare(void) {
    test_Observers _this;
    _this = test_Observers(corto_declare(test_Observers_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Observers _test_ObserversDeclareChild(corto_object _parent, corto_string _id) {
    test_Observers _this;
    _this = test_Observers(corto_declareChild(_parent, _id, test_Observers_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ObserversDefine(test_Observers _this, uint32_t assertCount, int32_t count) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Observers)_this)->count = count;
    return corto_define(_this);
}

test_Observers _test_ObserversAssign(test_Observers _this, uint32_t assertCount, int32_t count) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Observers)_this)->count = count;
    return _this;
}

corto_string _test_ObserversStr(test_Observers value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Observers_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Observers test_ObserversFromStr(test_Observers value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Observers_o), str);
    return value;
}

corto_equalityKind _test_ObserversCompare(test_Observers dst, test_Observers src) {
    return corto_compare(dst, src);
}

test_Overload _test_OverloadCreate(uint32_t assertCount) {
    test_Overload _this;
    _this = test_Overload(corto_declare(test_Overload_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Overload _test_OverloadCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Overload _this;
    _this = test_Overload(corto_declareChild(_parent, _id, test_Overload_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_OverloadUpdate(test_Overload _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Overload)CORTO_OFFSET(_this, ((corto_type)test_Overload_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Overload _test_OverloadDeclare(void) {
    test_Overload _this;
    _this = test_Overload(corto_declare(test_Overload_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Overload _test_OverloadDeclareChild(corto_object _parent, corto_string _id) {
    test_Overload _this;
    _this = test_Overload(corto_declareChild(_parent, _id, test_Overload_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_OverloadDefine(test_Overload _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Overload _test_OverloadAssign(test_Overload _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_OverloadStr(test_Overload value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Overload_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Overload test_OverloadFromStr(test_Overload value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Overload_o), str);
    return value;
}

corto_equalityKind _test_OverloadCompare(test_Overload dst, test_Overload src) {
    return corto_compare(dst, src);
}

test_Ownership _test_OwnershipCreate(uint32_t assertCount, uintptr_t observable) {
    test_Ownership _this;
    _this = test_Ownership(corto_declare(test_Ownership_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Ownership)_this)->observable = observable;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Ownership _test_OwnershipCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, uintptr_t observable) {
    test_Ownership _this;
    _this = test_Ownership(corto_declareChild(_parent, _id, test_Ownership_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Ownership)_this)->observable = observable;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_OwnershipUpdate(test_Ownership _this, uint32_t assertCount, uintptr_t observable) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Ownership)CORTO_OFFSET(_this, ((corto_type)test_Ownership_o)->size)))->assertCount = assertCount;
            ((test_Ownership)((test_Ownership)CORTO_OFFSET(_this, ((corto_type)test_Ownership_o)->size)))->observable = observable;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            ((test_Ownership)_this)->observable = observable;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Ownership _test_OwnershipDeclare(void) {
    test_Ownership _this;
    _this = test_Ownership(corto_declare(test_Ownership_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Ownership _test_OwnershipDeclareChild(corto_object _parent, corto_string _id) {
    test_Ownership _this;
    _this = test_Ownership(corto_declareChild(_parent, _id, test_Ownership_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_OwnershipDefine(test_Ownership _this, uint32_t assertCount, uintptr_t observable) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Ownership)_this)->observable = observable;
    return corto_define(_this);
}

test_Ownership _test_OwnershipAssign(test_Ownership _this, uint32_t assertCount, uintptr_t observable) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Ownership)_this)->observable = observable;
    return _this;
}

corto_string _test_OwnershipStr(test_Ownership value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Ownership_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Ownership test_OwnershipFromStr(test_Ownership value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Ownership_o), str);
    return value;
}

corto_equalityKind _test_OwnershipCompare(test_Ownership dst, test_Ownership src) {
    return corto_compare(dst, src);
}

test_Point* _test_PointCreate(int32_t x, int32_t y) {
    test_Point* _this;
    _this = test_Point(corto_declare(test_Point_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Point*)_this)->x = x;
        ((test_Point*)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Point* _test_PointCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y) {
    test_Point* _this;
    _this = test_Point(corto_declareChild(_parent, _id, test_Point_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Point*)_this)->x = x;
        ((test_Point*)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_PointUpdate(test_Point* _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Point*)((test_Point*)CORTO_OFFSET(_this, ((corto_type)test_Point_o)->size)))->x = x;
            ((test_Point*)((test_Point*)CORTO_OFFSET(_this, ((corto_type)test_Point_o)->size)))->y = y;
        } else {
            ((test_Point*)_this)->x = x;
            ((test_Point*)_this)->y = y;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Point* _test_PointDeclare(void) {
    test_Point* _this;
    _this = test_Point(corto_declare(test_Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Point* _test_PointDeclareChild(corto_object _parent, corto_string _id) {
    test_Point* _this;
    _this = test_Point(corto_declareChild(_parent, _id, test_Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_PointDefine(test_Point* _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    ((test_Point*)_this)->x = x;
    ((test_Point*)_this)->y = y;
    return corto_define(_this);
}

test_Point* _test_PointAssign(test_Point* _this, int32_t x, int32_t y) {
    CORTO_UNUSED(_this);
    ((test_Point*)_this)->x = x;
    ((test_Point*)_this)->y = y;
    return _this;
}

corto_string _test_PointStr(test_Point* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_Point_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_Point* test_PointFromStr(test_Point* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Point_o), str);
    return value;
}

corto_equalityKind test_PointCompare(test_Point* dst, test_Point* src) {
    return corto_comparep(dst, test_Point_o, src);
}

corto_int16 _test_PointInit(test_Point* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Point_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_Point_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PointDeinit(test_Point* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_Point_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Point3D* _test_Point3DCreate(int32_t x, int32_t y, int32_t z) {
    test_Point3D* _this;
    _this = test_Point3D(corto_declare(test_Point3D_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Point*)_this)->x = x;
        ((test_Point*)_this)->y = y;
        ((test_Point3D*)_this)->z = z;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Point3D* _test_Point3DCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y, int32_t z) {
    test_Point3D* _this;
    _this = test_Point3D(corto_declareChild(_parent, _id, test_Point3D_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_Point*)_this)->x = x;
        ((test_Point*)_this)->y = y;
        ((test_Point3D*)_this)->z = z;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_Point3DUpdate(test_Point3D* _this, int32_t x, int32_t y, int32_t z) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_Point*)((test_Point3D*)CORTO_OFFSET(_this, ((corto_type)test_Point3D_o)->size)))->x = x;
            ((test_Point*)((test_Point3D*)CORTO_OFFSET(_this, ((corto_type)test_Point3D_o)->size)))->y = y;
            ((test_Point3D*)((test_Point3D*)CORTO_OFFSET(_this, ((corto_type)test_Point3D_o)->size)))->z = z;
        } else {
            ((test_Point*)_this)->x = x;
            ((test_Point*)_this)->y = y;
            ((test_Point3D*)_this)->z = z;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Point3D* _test_Point3DDeclare(void) {
    test_Point3D* _this;
    _this = test_Point3D(corto_declare(test_Point3D_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Point3D* _test_Point3DDeclareChild(corto_object _parent, corto_string _id) {
    test_Point3D* _this;
    _this = test_Point3D(corto_declareChild(_parent, _id, test_Point3D_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_Point3DDefine(test_Point3D* _this, int32_t x, int32_t y, int32_t z) {
    CORTO_UNUSED(_this);
    ((test_Point*)_this)->x = x;
    ((test_Point*)_this)->y = y;
    ((test_Point3D*)_this)->z = z;
    return corto_define(_this);
}

test_Point3D* _test_Point3DAssign(test_Point3D* _this, int32_t x, int32_t y, int32_t z) {
    CORTO_UNUSED(_this);
    ((test_Point*)_this)->x = x;
    ((test_Point*)_this)->y = y;
    ((test_Point3D*)_this)->z = z;
    return _this;
}

corto_string _test_Point3DStr(test_Point3D* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_Point3D_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_Point3D* test_Point3DFromStr(test_Point3D* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Point3D_o), str);
    return value;
}

corto_equalityKind test_Point3DCompare(test_Point3D* dst, test_Point3D* src) {
    return corto_comparep(dst, test_Point3D_o, src);
}

corto_int16 _test_Point3DInit(test_Point3D* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Point3D_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_Point3D_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_Point3DDeinit(test_Point3D* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_Point3D_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int32* _test_PrimitiveArrayCreate(corto_uint32 length, corto_int32* elements) {
    corto_int32* _this;
    _this = test_PrimitiveArray(corto_declare(test_PrimitiveArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int32* _test_PrimitiveArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32* elements) {
    corto_int32* _this;
    _this = test_PrimitiveArray(corto_declareChild(_parent, _id, test_PrimitiveArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_PrimitiveArrayUpdate(test_PrimitiveArray _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_int32*)CORTO_OFFSET(_this, ((corto_type)test_PrimitiveArray_o)->size))[i] = elements[i];
            }
        } else {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this[i] = elements[i];
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int32* _test_PrimitiveArrayDeclare(void) {
    corto_int32* _this;
    _this = test_PrimitiveArray(corto_declare(test_PrimitiveArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int32* _test_PrimitiveArrayDeclareChild(corto_object _parent, corto_string _id) {
    corto_int32* _this;
    _this = test_PrimitiveArray(corto_declareChild(_parent, _id, test_PrimitiveArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_PrimitiveArrayDefine(test_PrimitiveArray _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this[i] = elements[i];
    }
    return corto_define(_this);
}

corto_int32* _test_PrimitiveArrayAssign(test_PrimitiveArray _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this[i] = elements[i];
    }
    return _this;
}

corto_string _test_PrimitiveArrayStr(test_PrimitiveArray value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveArray_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int32* test_PrimitiveArrayFromStr(test_PrimitiveArray value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_PrimitiveArray_o), str);
    return value;
}

corto_equalityKind test_PrimitiveArrayCompare(test_PrimitiveArray dst, test_PrimitiveArray src) {
    return corto_comparep(dst, test_PrimitiveArray_o, src);
}

corto_int16 _test_PrimitiveArrayInit(test_PrimitiveArray* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_PrimitiveArray_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveArray_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PrimitiveArrayDeinit(test_PrimitiveArray* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveArray_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_PrimitiveList* _test_PrimitiveListCreate(corto_uint32 length, corto_int32* elements) {
    test_PrimitiveList* _this;
    _this = test_PrimitiveList(corto_declare(test_PrimitiveList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_PrimitiveListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_PrimitiveListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_PrimitiveList* _test_PrimitiveListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32* elements) {
    test_PrimitiveList* _this;
    _this = test_PrimitiveList(corto_declareChild(_parent, _id, test_PrimitiveList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_PrimitiveListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_PrimitiveListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_PrimitiveListUpdate(test_PrimitiveList* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            test_PrimitiveListClear(*((test_PrimitiveList*)CORTO_OFFSET(_this, ((corto_type)test_PrimitiveList_o)->size)));
            for (i = 0; i < length; i ++) {
                test_PrimitiveListAppend(*((test_PrimitiveList*)CORTO_OFFSET(_this, ((corto_type)test_PrimitiveList_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            test_PrimitiveListClear(*_this);
            for (i = 0; i < length; i ++) {
                test_PrimitiveListAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_PrimitiveList* _test_PrimitiveListDeclare(void) {
    test_PrimitiveList* _this;
    _this = test_PrimitiveList(corto_declare(test_PrimitiveList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_PrimitiveList* _test_PrimitiveListDeclareChild(corto_object _parent, corto_string _id) {
    test_PrimitiveList* _this;
    _this = test_PrimitiveList(corto_declareChild(_parent, _id, test_PrimitiveList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_PrimitiveListDefine(test_PrimitiveList* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_PrimitiveListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_PrimitiveListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

test_PrimitiveList* _test_PrimitiveListAssign(test_PrimitiveList* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_PrimitiveListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_PrimitiveListAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _test_PrimitiveListStr(test_PrimitiveList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_PrimitiveList* test_PrimitiveListFromStr(test_PrimitiveList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_PrimitiveList_o), str);
    return value;
}

corto_equalityKind test_PrimitiveListCompare(test_PrimitiveList dst, test_PrimitiveList src) {
    return corto_comparep(&dst, test_PrimitiveList_o, &src);
}

corto_int16 _test_PrimitiveListInit(test_PrimitiveList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_PrimitiveList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PrimitiveListDeinit(test_PrimitiveList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveList_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_PrimitiveSequence* _test_PrimitiveSequenceCreate(corto_uint32 length, corto_int32* elements) {
    test_PrimitiveSequence* _this;
    _this = test_PrimitiveSequence(corto_declare(test_PrimitiveSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_PrimitiveSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_PrimitiveSequence* _test_PrimitiveSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32* elements) {
    test_PrimitiveSequence* _this;
    _this = test_PrimitiveSequence(corto_declareChild(_parent, _id, test_PrimitiveSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_PrimitiveSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_PrimitiveSequenceUpdate(test_PrimitiveSequence* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            test_PrimitiveSequenceSize(((test_PrimitiveSequence*)CORTO_OFFSET(_this, ((corto_type)test_PrimitiveSequence_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((test_PrimitiveSequence*)CORTO_OFFSET(_this, ((corto_type)test_PrimitiveSequence_o)->size))->buffer[i] = elements[i];
            }
        } else {
            test_PrimitiveSequenceSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                _this->buffer[i] = elements[i];
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_PrimitiveSequence* _test_PrimitiveSequenceDeclare(void) {
    test_PrimitiveSequence* _this;
    _this = test_PrimitiveSequence(corto_declare(test_PrimitiveSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_PrimitiveSequence* _test_PrimitiveSequenceDeclareChild(corto_object _parent, corto_string _id) {
    test_PrimitiveSequence* _this;
    _this = test_PrimitiveSequence(corto_declareChild(_parent, _id, test_PrimitiveSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_PrimitiveSequenceDefine(test_PrimitiveSequence* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    test_PrimitiveSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

test_PrimitiveSequence* _test_PrimitiveSequenceAssign(test_PrimitiveSequence* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    test_PrimitiveSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

corto_string _test_PrimitiveSequenceStr(test_PrimitiveSequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveSequence_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_PrimitiveSequence* test_PrimitiveSequenceFromStr(test_PrimitiveSequence* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_PrimitiveSequence_o), str);
    return value;
}

corto_equalityKind test_PrimitiveSequenceCompare(test_PrimitiveSequence dst, test_PrimitiveSequence src) {
    return corto_comparep(&dst, test_PrimitiveSequence_o, &src);
}

corto_int16 _test_PrimitiveSequenceInit(test_PrimitiveSequence* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_PrimitiveSequence_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveSequence_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PrimitiveSequenceDeinit(test_PrimitiveSequence* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_PrimitiveSequence_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ReferenceMember* _test_ReferenceMemberCreate(corto_object m, int32_t n) {
    test_ReferenceMember* _this;
    _this = test_ReferenceMember(corto_declare(test_ReferenceMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_ReferenceMember*)_this)->m, m);
        ((test_ReferenceMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ReferenceMember* _test_ReferenceMemberCreateChild(corto_object _parent, corto_string _id, corto_object m, int32_t n) {
    test_ReferenceMember* _this;
    _this = test_ReferenceMember(corto_declareChild(_parent, _id, test_ReferenceMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_ReferenceMember*)_this)->m, m);
        ((test_ReferenceMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ReferenceMemberUpdate(test_ReferenceMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((test_ReferenceMember*)((test_ReferenceMember*)CORTO_OFFSET(_this, ((corto_type)test_ReferenceMember_o)->size)))->m, m);
            ((test_ReferenceMember*)((test_ReferenceMember*)CORTO_OFFSET(_this, ((corto_type)test_ReferenceMember_o)->size)))->n = n;
        } else {
            corto_setref(&((test_ReferenceMember*)_this)->m, m);
            ((test_ReferenceMember*)_this)->n = n;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ReferenceMember* _test_ReferenceMemberDeclare(void) {
    test_ReferenceMember* _this;
    _this = test_ReferenceMember(corto_declare(test_ReferenceMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ReferenceMember* _test_ReferenceMemberDeclareChild(corto_object _parent, corto_string _id) {
    test_ReferenceMember* _this;
    _this = test_ReferenceMember(corto_declareChild(_parent, _id, test_ReferenceMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ReferenceMemberDefine(test_ReferenceMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_ReferenceMember*)_this)->m, m);
    ((test_ReferenceMember*)_this)->n = n;
    return corto_define(_this);
}

test_ReferenceMember* _test_ReferenceMemberAssign(test_ReferenceMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_ReferenceMember*)_this)->m, m);
    ((test_ReferenceMember*)_this)->n = n;
    return _this;
}

corto_string _test_ReferenceMemberStr(test_ReferenceMember* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceMember_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_ReferenceMember* test_ReferenceMemberFromStr(test_ReferenceMember* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ReferenceMember_o), str);
    return value;
}

corto_equalityKind test_ReferenceMemberCompare(test_ReferenceMember* dst, test_ReferenceMember* src) {
    return corto_comparep(dst, test_ReferenceMember_o, src);
}

corto_int16 _test_ReferenceMemberInit(test_ReferenceMember* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_ReferenceMember_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceMember_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ReferenceMemberDeinit(test_ReferenceMember* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceMember_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ReferenceTargetMember* _test_ReferenceTargetMemberCreate(corto_object m, int32_t n) {
    test_ReferenceTargetMember* _this;
    _this = test_ReferenceTargetMember(corto_declare(test_ReferenceTargetMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_ReferenceTargetMember*)_this)->m->actual, m);
        ((test_ReferenceTargetMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ReferenceTargetMember* _test_ReferenceTargetMemberCreateChild(corto_object _parent, corto_string _id, corto_object m, int32_t n) {
    test_ReferenceTargetMember* _this;
    _this = test_ReferenceTargetMember(corto_declareChild(_parent, _id, test_ReferenceTargetMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((test_ReferenceTargetMember*)_this)->m->actual, m);
        ((test_ReferenceTargetMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ReferenceTargetMemberUpdate(test_ReferenceTargetMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((test_ReferenceTargetMember*)((test_ReferenceTargetMember*)CORTO_OFFSET(_this, ((corto_type)test_ReferenceTargetMember_o)->size)))->m->target, m);
            ((test_ReferenceTargetMember*)((test_ReferenceTargetMember*)CORTO_OFFSET(_this, ((corto_type)test_ReferenceTargetMember_o)->size)))->n = n;
        } else {
            corto_setref(&((test_ReferenceTargetMember*)_this)->m->actual, m);
            ((test_ReferenceTargetMember*)_this)->n = n;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ReferenceTargetMember* _test_ReferenceTargetMemberDeclare(void) {
    test_ReferenceTargetMember* _this;
    _this = test_ReferenceTargetMember(corto_declare(test_ReferenceTargetMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ReferenceTargetMember* _test_ReferenceTargetMemberDeclareChild(corto_object _parent, corto_string _id) {
    test_ReferenceTargetMember* _this;
    _this = test_ReferenceTargetMember(corto_declareChild(_parent, _id, test_ReferenceTargetMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ReferenceTargetMemberDefine(test_ReferenceTargetMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_ReferenceTargetMember*)_this)->m->actual, m);
    ((test_ReferenceTargetMember*)_this)->n = n;
    return corto_define(_this);
}

test_ReferenceTargetMember* _test_ReferenceTargetMemberAssign(test_ReferenceTargetMember* _this, corto_object m, int32_t n) {
    CORTO_UNUSED(_this);
    corto_setref(&((test_ReferenceTargetMember*)_this)->m->actual, m);
    ((test_ReferenceTargetMember*)_this)->n = n;
    return _this;
}

corto_string _test_ReferenceTargetMemberStr(test_ReferenceTargetMember* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceTargetMember_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_ReferenceTargetMember* test_ReferenceTargetMemberFromStr(test_ReferenceTargetMember* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ReferenceTargetMember_o), str);
    return value;
}

corto_equalityKind test_ReferenceTargetMemberCompare(test_ReferenceTargetMember* dst, test_ReferenceTargetMember* src) {
    return corto_comparep(dst, test_ReferenceTargetMember_o, src);
}

corto_int16 _test_ReferenceTargetMemberInit(test_ReferenceTargetMember* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_ReferenceTargetMember_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceTargetMember_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ReferenceTargetMemberDeinit(test_ReferenceTargetMember* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_ReferenceTargetMember_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_RelativeName _test_RelativeNameCreate(uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    test_RelativeName _this;
    _this = test_RelativeName(corto_declare(test_RelativeName_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_setref(&((test_RelativeName)_this)->tier1, tier1);
        corto_setref(&((test_RelativeName)_this)->tier2, tier2);
        corto_setref(&((test_RelativeName)_this)->tier3, tier3);
        corto_setref(&((test_RelativeName)_this)->obj, obj);
        corto_setref(&((test_RelativeName)_this)->disjunct, disjunct);
        corto_setref(&((test_RelativeName)_this)->child, child);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_RelativeName _test_RelativeNameCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    test_RelativeName _this;
    _this = test_RelativeName(corto_declareChild(_parent, _id, test_RelativeName_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_setref(&((test_RelativeName)_this)->tier1, tier1);
        corto_setref(&((test_RelativeName)_this)->tier2, tier2);
        corto_setref(&((test_RelativeName)_this)->tier3, tier3);
        corto_setref(&((test_RelativeName)_this)->obj, obj);
        corto_setref(&((test_RelativeName)_this)->disjunct, disjunct);
        corto_setref(&((test_RelativeName)_this)->child, child);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_RelativeNameUpdate(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->assertCount = assertCount;
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->tier1, tier1);
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->tier2, tier2);
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->tier3, tier3);
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->obj, obj);
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->disjunct, disjunct);
            corto_setref(&((test_RelativeName)((test_RelativeName)CORTO_OFFSET(_this, ((corto_type)test_RelativeName_o)->size)))->child, child);
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            corto_setref(&((test_RelativeName)_this)->tier1, tier1);
            corto_setref(&((test_RelativeName)_this)->tier2, tier2);
            corto_setref(&((test_RelativeName)_this)->tier3, tier3);
            corto_setref(&((test_RelativeName)_this)->obj, obj);
            corto_setref(&((test_RelativeName)_this)->disjunct, disjunct);
            corto_setref(&((test_RelativeName)_this)->child, child);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_RelativeName _test_RelativeNameDeclare(void) {
    test_RelativeName _this;
    _this = test_RelativeName(corto_declare(test_RelativeName_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_RelativeName _test_RelativeNameDeclareChild(corto_object _parent, corto_string _id) {
    test_RelativeName _this;
    _this = test_RelativeName(corto_declareChild(_parent, _id, test_RelativeName_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_RelativeNameDefine(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_RelativeName)_this)->tier1, tier1);
    corto_setref(&((test_RelativeName)_this)->tier2, tier2);
    corto_setref(&((test_RelativeName)_this)->tier3, tier3);
    corto_setref(&((test_RelativeName)_this)->obj, obj);
    corto_setref(&((test_RelativeName)_this)->disjunct, disjunct);
    corto_setref(&((test_RelativeName)_this)->child, child);
    return corto_define(_this);
}

test_RelativeName _test_RelativeNameAssign(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_RelativeName)_this)->tier1, tier1);
    corto_setref(&((test_RelativeName)_this)->tier2, tier2);
    corto_setref(&((test_RelativeName)_this)->tier3, tier3);
    corto_setref(&((test_RelativeName)_this)->obj, obj);
    corto_setref(&((test_RelativeName)_this)->disjunct, disjunct);
    corto_setref(&((test_RelativeName)_this)->child, child);
    return _this;
}

corto_string _test_RelativeNameStr(test_RelativeName value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_RelativeName_o));
    result = corto_strv(&v, 0);
    return result;
}

test_RelativeName test_RelativeNameFromStr(test_RelativeName value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_RelativeName_o), str);
    return value;
}

corto_equalityKind _test_RelativeNameCompare(test_RelativeName dst, test_RelativeName src) {
    return corto_compare(dst, src);
}

test_Resolver _test_ResolverCreate(uint32_t assertCount) {
    test_Resolver _this;
    _this = test_Resolver(corto_declare(test_Resolver_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Resolver _test_ResolverCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Resolver _this;
    _this = test_Resolver(corto_declareChild(_parent, _id, test_Resolver_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ResolverUpdate(test_Resolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Resolver)CORTO_OFFSET(_this, ((corto_type)test_Resolver_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Resolver _test_ResolverDeclare(void) {
    test_Resolver _this;
    _this = test_Resolver(corto_declare(test_Resolver_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Resolver _test_ResolverDeclareChild(corto_object _parent, corto_string _id) {
    test_Resolver _this;
    _this = test_Resolver(corto_declareChild(_parent, _id, test_Resolver_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ResolverDefine(test_Resolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Resolver _test_ResolverAssign(test_Resolver _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_ResolverStr(test_Resolver value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Resolver_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Resolver test_ResolverFromStr(test_Resolver value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Resolver_o), str);
    return value;
}

corto_equalityKind _test_ResolverCompare(test_Resolver dst, test_Resolver src) {
    return corto_compare(dst, src);
}

test_Security _test_SecurityCreate(uint32_t assertCount) {
    test_Security _this;
    _this = test_Security(corto_declare(test_Security_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Security _test_SecurityCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Security _this;
    _this = test_Security(corto_declareChild(_parent, _id, test_Security_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_SecurityUpdate(test_Security _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Security)CORTO_OFFSET(_this, ((corto_type)test_Security_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Security _test_SecurityDeclare(void) {
    test_Security _this;
    _this = test_Security(corto_declare(test_Security_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Security _test_SecurityDeclareChild(corto_object _parent, corto_string _id) {
    test_Security _this;
    _this = test_Security(corto_declareChild(_parent, _id, test_Security_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_SecurityDefine(test_Security _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Security _test_SecurityAssign(test_Security _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_SecurityStr(test_Security value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Security_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Security test_SecurityFromStr(test_Security value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Security_o), str);
    return value;
}

corto_equalityKind _test_SecurityCompare(test_Security dst, test_Security src) {
    return corto_compare(dst, src);
}

test_Select _test_SelectCreate(uint32_t assertCount) {
    test_Select _this;
    _this = test_Select(corto_declare(test_Select_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Select _test_SelectCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_Select _this;
    _this = test_Select(corto_declareChild(_parent, _id, test_Select_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_SelectUpdate(test_Select _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Select)CORTO_OFFSET(_this, ((corto_type)test_Select_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Select _test_SelectDeclare(void) {
    test_Select _this;
    _this = test_Select(corto_declare(test_Select_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Select _test_SelectDeclareChild(corto_object _parent, corto_string _id) {
    test_Select _this;
    _this = test_Select(corto_declareChild(_parent, _id, test_Select_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_SelectDefine(test_Select _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_Select _test_SelectAssign(test_Select _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_SelectStr(test_Select value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Select_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Select test_SelectFromStr(test_Select value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Select_o), str);
    return value;
}

corto_equalityKind _test_SelectCompare(test_Select dst, test_Select src) {
    return corto_compare(dst, src);
}

corto_string* _test_StringArrayCreate(corto_uint32 length, corto_string* elements) {
    corto_string* _this;
    _this = test_StringArray(corto_declare(test_StringArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setstr(&_this[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_string* _test_StringArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements) {
    corto_string* _this;
    _this = test_StringArray(corto_declareChild(_parent, _id, test_StringArray_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setstr(&_this[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_StringArrayUpdate(test_StringArray _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setstr(&((corto_string*)CORTO_OFFSET(_this, ((corto_type)test_StringArray_o)->size))[i], elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setstr(&_this[i], elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_string* _test_StringArrayDeclare(void) {
    corto_string* _this;
    _this = test_StringArray(corto_declare(test_StringArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_string* _test_StringArrayDeclareChild(corto_object _parent, corto_string _id) {
    corto_string* _this;
    _this = test_StringArray(corto_declareChild(_parent, _id, test_StringArray_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_StringArrayDefine(test_StringArray _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this[i], elements[i]);
    }
    return corto_define(_this);
}

corto_string* _test_StringArrayAssign(test_StringArray _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this[i], elements[i]);
    }
    return _this;
}

corto_string _test_StringArrayStr(test_StringArray value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringArray_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_string* test_StringArrayFromStr(test_StringArray value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringArray_o), str);
    return value;
}

corto_equalityKind test_StringArrayCompare(test_StringArray dst, test_StringArray src) {
    return corto_comparep(dst, test_StringArray_o, src);
}

corto_int16 _test_StringArrayInit(test_StringArray* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_StringArray_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_StringArray_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_StringArrayDeinit(test_StringArray* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringArray_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_StringDeserializer _test_StringDeserializerCreate(uint32_t assertCount) {
    test_StringDeserializer _this;
    _this = test_StringDeserializer(corto_declare(test_StringDeserializer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_StringDeserializer _test_StringDeserializerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_StringDeserializer _this;
    _this = test_StringDeserializer(corto_declareChild(_parent, _id, test_StringDeserializer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_StringDeserializerUpdate(test_StringDeserializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_StringDeserializer)CORTO_OFFSET(_this, ((corto_type)test_StringDeserializer_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_StringDeserializer _test_StringDeserializerDeclare(void) {
    test_StringDeserializer _this;
    _this = test_StringDeserializer(corto_declare(test_StringDeserializer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_StringDeserializer _test_StringDeserializerDeclareChild(corto_object _parent, corto_string _id) {
    test_StringDeserializer _this;
    _this = test_StringDeserializer(corto_declareChild(_parent, _id, test_StringDeserializer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_StringDeserializerDefine(test_StringDeserializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_StringDeserializer _test_StringDeserializerAssign(test_StringDeserializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_StringDeserializerStr(test_StringDeserializer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_StringDeserializer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_StringDeserializer test_StringDeserializerFromStr(test_StringDeserializer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringDeserializer_o), str);
    return value;
}

corto_equalityKind _test_StringDeserializerCompare(test_StringDeserializer dst, test_StringDeserializer src) {
    return corto_compare(dst, src);
}

test_StringList* _test_StringListCreate(corto_uint32 length, corto_string* elements) {
    test_StringList* _this;
    _this = test_StringList(corto_declare(test_StringList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_StringListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_StringListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_StringList* _test_StringListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements) {
    test_StringList* _this;
    _this = test_StringList(corto_declareChild(_parent, _id, test_StringList_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        test_StringListClear(*_this);
        for (i = 0; i < length; i ++) {
            test_StringListAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_StringListUpdate(test_StringList* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            test_StringListClear(*((test_StringList*)CORTO_OFFSET(_this, ((corto_type)test_StringList_o)->size)));
            for (i = 0; i < length; i ++) {
                test_StringListAppend(*((test_StringList*)CORTO_OFFSET(_this, ((corto_type)test_StringList_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            test_StringListClear(*_this);
            for (i = 0; i < length; i ++) {
                test_StringListAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_StringList* _test_StringListDeclare(void) {
    test_StringList* _this;
    _this = test_StringList(corto_declare(test_StringList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_StringList* _test_StringListDeclareChild(corto_object _parent, corto_string _id) {
    test_StringList* _this;
    _this = test_StringList(corto_declareChild(_parent, _id, test_StringList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_StringListDefine(test_StringList* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_StringListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_StringListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

test_StringList* _test_StringListAssign(test_StringList* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    test_StringListClear(*_this);
    for (i = 0; i < length; i ++) {
        test_StringListAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _test_StringListStr(test_StringList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_StringList* test_StringListFromStr(test_StringList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringList_o), str);
    return value;
}

corto_equalityKind test_StringListCompare(test_StringList dst, test_StringList src) {
    return corto_comparep(&dst, test_StringList_o, &src);
}

corto_int16 _test_StringListInit(test_StringList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_StringList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_StringList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_StringListDeinit(test_StringList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringList_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_StringSequence* _test_StringSequenceCreate(corto_uint32 length, corto_string* elements) {
    test_StringSequence* _this;
    _this = test_StringSequence(corto_declare(test_StringSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_StringSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setstr(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_StringSequence* _test_StringSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements) {
    test_StringSequence* _this;
    _this = test_StringSequence(corto_declareChild(_parent, _id, test_StringSequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        test_StringSequenceSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_setstr(&_this->buffer[i], elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_StringSequenceUpdate(test_StringSequence* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            test_StringSequenceSize(((test_StringSequence*)CORTO_OFFSET(_this, ((corto_type)test_StringSequence_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setstr(&((test_StringSequence*)CORTO_OFFSET(_this, ((corto_type)test_StringSequence_o)->size))->buffer[i], elements[i]);
            }
        } else {
            test_StringSequenceSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setstr(&_this->buffer[i], elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_StringSequence* _test_StringSequenceDeclare(void) {
    test_StringSequence* _this;
    _this = test_StringSequence(corto_declare(test_StringSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_StringSequence* _test_StringSequenceDeclareChild(corto_object _parent, corto_string _id) {
    test_StringSequence* _this;
    _this = test_StringSequence(corto_declareChild(_parent, _id, test_StringSequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_StringSequenceDefine(test_StringSequence* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    test_StringSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

test_StringSequence* _test_StringSequenceAssign(test_StringSequence* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    test_StringSequenceSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _test_StringSequenceStr(test_StringSequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringSequence_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_StringSequence* test_StringSequenceFromStr(test_StringSequence* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringSequence_o), str);
    return value;
}

corto_equalityKind test_StringSequenceCompare(test_StringSequence dst, test_StringSequence src) {
    return corto_comparep(&dst, test_StringSequence_o, &src);
}

corto_int16 _test_StringSequenceInit(test_StringSequence* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_StringSequence_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_StringSequence_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_StringSequenceDeinit(test_StringSequence* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_StringSequence_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_StringSerializer _test_StringSerializerCreate(uint32_t assertCount) {
    test_StringSerializer _this;
    _this = test_StringSerializer(corto_declare(test_StringSerializer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_StringSerializer _test_StringSerializerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_StringSerializer _this;
    _this = test_StringSerializer(corto_declareChild(_parent, _id, test_StringSerializer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_StringSerializerUpdate(test_StringSerializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_StringSerializer)CORTO_OFFSET(_this, ((corto_type)test_StringSerializer_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_StringSerializer _test_StringSerializerDeclare(void) {
    test_StringSerializer _this;
    _this = test_StringSerializer(corto_declare(test_StringSerializer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_StringSerializer _test_StringSerializerDeclareChild(corto_object _parent, corto_string _id) {
    test_StringSerializer _this;
    _this = test_StringSerializer(corto_declareChild(_parent, _id, test_StringSerializer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_StringSerializerDefine(test_StringSerializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_StringSerializer _test_StringSerializerAssign(test_StringSerializer _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_StringSerializerStr(test_StringSerializer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_StringSerializer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_StringSerializer test_StringSerializerFromStr(test_StringSerializer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringSerializer_o), str);
    return value;
}

corto_equalityKind _test_StringSerializerCompare(test_StringSerializer dst, test_StringSerializer src) {
    return corto_compare(dst, src);
}

test_Subscribe _test_SubscribeCreate(uint32_t assertCount, uint8_t triggered, corto_object owner) {
    test_Subscribe _this;
    _this = test_Subscribe(corto_declare(test_Subscribe_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Subscribe)_this)->triggered = triggered;
        corto_setref(&((test_Subscribe)_this)->owner, owner);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_Subscribe _test_SubscribeCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, uint8_t triggered, corto_object owner) {
    test_Subscribe _this;
    _this = test_Subscribe(corto_declareChild(_parent, _id, test_Subscribe_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_Subscribe)_this)->triggered = triggered;
        corto_setref(&((test_Subscribe)_this)->owner, owner);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_SubscribeUpdate(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_Subscribe)CORTO_OFFSET(_this, ((corto_type)test_Subscribe_o)->size)))->assertCount = assertCount;
            ((test_Subscribe)((test_Subscribe)CORTO_OFFSET(_this, ((corto_type)test_Subscribe_o)->size)))->triggered = triggered;
            corto_setref(&((test_Subscribe)((test_Subscribe)CORTO_OFFSET(_this, ((corto_type)test_Subscribe_o)->size)))->owner, owner);
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            ((test_Subscribe)_this)->triggered = triggered;
            corto_setref(&((test_Subscribe)_this)->owner, owner);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Subscribe _test_SubscribeDeclare(void) {
    test_Subscribe _this;
    _this = test_Subscribe(corto_declare(test_Subscribe_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Subscribe _test_SubscribeDeclareChild(corto_object _parent, corto_string _id) {
    test_Subscribe _this;
    _this = test_Subscribe(corto_declareChild(_parent, _id, test_Subscribe_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_SubscribeDefine(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Subscribe)_this)->triggered = triggered;
    corto_setref(&((test_Subscribe)_this)->owner, owner);
    return corto_define(_this);
}

test_Subscribe _test_SubscribeAssign(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_Subscribe)_this)->triggered = triggered;
    corto_setref(&((test_Subscribe)_this)->owner, owner);
    return _this;
}

corto_string _test_SubscribeStr(test_Subscribe value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Subscribe_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Subscribe test_SubscribeFromStr(test_Subscribe value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Subscribe_o), str);
    return value;
}

corto_equalityKind _test_SubscribeCompare(test_Subscribe dst, test_Subscribe src) {
    return corto_compare(dst, src);
}

test_SubscriberEvent _test_SubscriberEventCreate(uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st) {
    test_SubscriberEvent _this;
    _this = test_SubscriberEvent(corto_declare(test_SubscriberEvent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_SubscriberEvent)_this)->prevAttr = prevAttr;
        corto_setref(&((test_SubscriberEvent)_this)->st, st);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_SubscriberEvent _test_SubscriberEventCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st) {
    test_SubscriberEvent _this;
    _this = test_SubscriberEvent(corto_declareChild(_parent, _id, test_SubscriberEvent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        ((test_SubscriberEvent)_this)->prevAttr = prevAttr;
        corto_setref(&((test_SubscriberEvent)_this)->st, st);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_SubscriberEventUpdate(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_SubscriberEvent)CORTO_OFFSET(_this, ((corto_type)test_SubscriberEvent_o)->size)))->assertCount = assertCount;
            ((test_SubscriberEvent)((test_SubscriberEvent)CORTO_OFFSET(_this, ((corto_type)test_SubscriberEvent_o)->size)))->prevAttr = prevAttr;
            corto_setref(&((test_SubscriberEvent)((test_SubscriberEvent)CORTO_OFFSET(_this, ((corto_type)test_SubscriberEvent_o)->size)))->st, st);
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
            ((test_SubscriberEvent)_this)->prevAttr = prevAttr;
            corto_setref(&((test_SubscriberEvent)_this)->st, st);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_SubscriberEvent _test_SubscriberEventDeclare(void) {
    test_SubscriberEvent _this;
    _this = test_SubscriberEvent(corto_declare(test_SubscriberEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_SubscriberEvent _test_SubscriberEventDeclareChild(corto_object _parent, corto_string _id) {
    test_SubscriberEvent _this;
    _this = test_SubscriberEvent(corto_declareChild(_parent, _id, test_SubscriberEvent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_SubscriberEventDefine(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_SubscriberEvent)_this)->prevAttr = prevAttr;
    corto_setref(&((test_SubscriberEvent)_this)->st, st);
    return corto_define(_this);
}

test_SubscriberEvent _test_SubscriberEventAssign(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    ((test_SubscriberEvent)_this)->prevAttr = prevAttr;
    corto_setref(&((test_SubscriberEvent)_this)->st, st);
    return _this;
}

corto_string _test_SubscriberEventStr(test_SubscriberEvent value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_SubscriberEvent_o));
    result = corto_strv(&v, 0);
    return result;
}

test_SubscriberEvent test_SubscriberEventFromStr(test_SubscriberEvent value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_SubscriberEvent_o), str);
    return value;
}

corto_equalityKind _test_SubscriberEventCompare(test_SubscriberEvent dst, test_SubscriberEvent src) {
    return corto_compare(dst, src);
}

test_SubscriberTest _test_SubscriberTestCreate(void) {
    test_SubscriberTest _this;
    _this = test_SubscriberTest(corto_declare(test_SubscriberTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_SubscriberTest _test_SubscriberTestCreateChild(corto_object _parent, corto_string _id) {
    test_SubscriberTest _this;
    _this = test_SubscriberTest(corto_declareChild(_parent, _id, test_SubscriberTest_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_SubscriberTestUpdate(test_SubscriberTest _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_SubscriberTest _test_SubscriberTestDeclare(void) {
    test_SubscriberTest _this;
    _this = test_SubscriberTest(corto_declare(test_SubscriberTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_SubscriberTest _test_SubscriberTestDeclareChild(corto_object _parent, corto_string _id) {
    test_SubscriberTest _this;
    _this = test_SubscriberTest(corto_declareChild(_parent, _id, test_SubscriberTest_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_SubscriberTestDefine(test_SubscriberTest _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_SubscriberTest _test_SubscriberTestAssign(test_SubscriberTest _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_SubscriberTestStr(test_SubscriberTest value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_SubscriberTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_SubscriberTest test_SubscriberTestFromStr(test_SubscriberTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_SubscriberTest_o), str);
    return value;
}

corto_equalityKind _test_SubscriberTestCompare(test_SubscriberTest dst, test_SubscriberTest src) {
    return corto_compare(dst, src);
}

test_TableMultiKey _test_TableMultiKeyCreate(corto_string value) {
    test_TableMultiKey _this;
    _this = test_TableMultiKey(corto_declare(test_TableMultiKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableMultiKey _test_TableMultiKeyCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableMultiKey _this;
    _this = test_TableMultiKey(corto_declareChild(_parent, _id, test_TableMultiKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableMultiKeyUpdate(test_TableMultiKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableMultiKey)((test_TableMultiKey)CORTO_OFFSET(_this, ((corto_type)test_TableMultiKey_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableMultiKey)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableMultiKey _test_TableMultiKeyDeclare(void) {
    test_TableMultiKey _this;
    _this = test_TableMultiKey(corto_declare(test_TableMultiKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableMultiKey _test_TableMultiKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TableMultiKey _this;
    _this = test_TableMultiKey(corto_declareChild(_parent, _id, test_TableMultiKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableMultiKeyDefine(test_TableMultiKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiKey)_this)->value, value);
    return corto_define(_this);
}

test_TableMultiKey _test_TableMultiKeyAssign(test_TableMultiKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiKey)_this)->value, value);
    return _this;
}

corto_string _test_TableMultiKeyStr(test_TableMultiKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableMultiKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableMultiKey test_TableMultiKeyFromStr(test_TableMultiKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableMultiKey_o), str);
    return value;
}

corto_equalityKind _test_TableMultiKeyCompare(test_TableMultiKey dst, test_TableMultiKey src) {
    return corto_compare(dst, src);
}

test_TableMultiMixedKey _test_TableMultiMixedKeyCreate(corto_string value) {
    test_TableMultiMixedKey _this;
    _this = test_TableMultiMixedKey(corto_declare(test_TableMultiMixedKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiMixedKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableMultiMixedKey _test_TableMultiMixedKeyCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableMultiMixedKey _this;
    _this = test_TableMultiMixedKey(corto_declareChild(_parent, _id, test_TableMultiMixedKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiMixedKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableMultiMixedKeyUpdate(test_TableMultiMixedKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableMultiMixedKey)((test_TableMultiMixedKey)CORTO_OFFSET(_this, ((corto_type)test_TableMultiMixedKey_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableMultiMixedKey)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableMultiMixedKey _test_TableMultiMixedKeyDeclare(void) {
    test_TableMultiMixedKey _this;
    _this = test_TableMultiMixedKey(corto_declare(test_TableMultiMixedKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableMultiMixedKey _test_TableMultiMixedKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TableMultiMixedKey _this;
    _this = test_TableMultiMixedKey(corto_declareChild(_parent, _id, test_TableMultiMixedKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableMultiMixedKeyDefine(test_TableMultiMixedKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiMixedKey)_this)->value, value);
    return corto_define(_this);
}

test_TableMultiMixedKey _test_TableMultiMixedKeyAssign(test_TableMultiMixedKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiMixedKey)_this)->value, value);
    return _this;
}

corto_string _test_TableMultiMixedKeyStr(test_TableMultiMixedKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableMultiMixedKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableMultiMixedKey test_TableMultiMixedKeyFromStr(test_TableMultiMixedKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableMultiMixedKey_o), str);
    return value;
}

corto_equalityKind _test_TableMultiMixedKeyCompare(test_TableMultiMixedKey dst, test_TableMultiMixedKey src) {
    return corto_compare(dst, src);
}

test_TableMultiStringKey _test_TableMultiStringKeyCreate(corto_string value) {
    test_TableMultiStringKey _this;
    _this = test_TableMultiStringKey(corto_declare(test_TableMultiStringKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiStringKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableMultiStringKey _test_TableMultiStringKeyCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableMultiStringKey _this;
    _this = test_TableMultiStringKey(corto_declareChild(_parent, _id, test_TableMultiStringKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableMultiStringKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableMultiStringKeyUpdate(test_TableMultiStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableMultiStringKey)((test_TableMultiStringKey)CORTO_OFFSET(_this, ((corto_type)test_TableMultiStringKey_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableMultiStringKey)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableMultiStringKey _test_TableMultiStringKeyDeclare(void) {
    test_TableMultiStringKey _this;
    _this = test_TableMultiStringKey(corto_declare(test_TableMultiStringKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableMultiStringKey _test_TableMultiStringKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TableMultiStringKey _this;
    _this = test_TableMultiStringKey(corto_declareChild(_parent, _id, test_TableMultiStringKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableMultiStringKeyDefine(test_TableMultiStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiStringKey)_this)->value, value);
    return corto_define(_this);
}

test_TableMultiStringKey _test_TableMultiStringKeyAssign(test_TableMultiStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableMultiStringKey)_this)->value, value);
    return _this;
}

corto_string _test_TableMultiStringKeyStr(test_TableMultiStringKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableMultiStringKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableMultiStringKey test_TableMultiStringKeyFromStr(test_TableMultiStringKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableMultiStringKey_o), str);
    return value;
}

corto_equalityKind _test_TableMultiStringKeyCompare(test_TableMultiStringKey dst, test_TableMultiStringKey src) {
    return corto_compare(dst, src);
}

test_TableNested _test_TableNestedCreate(corto_string value) {
    test_TableNested _this;
    _this = test_TableNested(corto_declare(test_TableNested_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNested)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNested _test_TableNestedCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableNested _this;
    _this = test_TableNested(corto_declareChild(_parent, _id, test_TableNested_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNested)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedUpdate(test_TableNested _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableNested)((test_TableNested)CORTO_OFFSET(_this, ((corto_type)test_TableNested_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableNested)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNested _test_TableNestedDeclare(void) {
    test_TableNested _this;
    _this = test_TableNested(corto_declare(test_TableNested_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNested _test_TableNestedDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNested _this;
    _this = test_TableNested(corto_declareChild(_parent, _id, test_TableNested_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedDefine(test_TableNested _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNested)_this)->value, value);
    return corto_define(_this);
}

test_TableNested _test_TableNestedAssign(test_TableNested _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNested)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedStr(test_TableNested value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNested_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNested test_TableNestedFromStr(test_TableNested value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNested_o), str);
    return value;
}

corto_equalityKind _test_TableNestedCompare(test_TableNested dst, test_TableNested src) {
    return corto_compare(dst, src);
}

test_TableNested_ChildTable _test_TableNested_ChildTableCreate(corto_string value) {
    test_TableNested_ChildTable _this;
    _this = test_TableNested_ChildTable(corto_declare(test_TableNested_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNested_ChildTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNested_ChildTable _test_TableNested_ChildTableCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableNested_ChildTable _this;
    _this = test_TableNested_ChildTable(corto_declareChild(_parent, _id, test_TableNested_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNested_ChildTable)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNested_ChildTableUpdate(test_TableNested_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableNested_ChildTable)((test_TableNested_ChildTable)CORTO_OFFSET(_this, ((corto_type)test_TableNested_ChildTable_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableNested_ChildTable)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNested_ChildTable _test_TableNested_ChildTableDeclare(void) {
    test_TableNested_ChildTable _this;
    _this = test_TableNested_ChildTable(corto_declare(test_TableNested_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNested_ChildTable _test_TableNested_ChildTableDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNested_ChildTable _this;
    _this = test_TableNested_ChildTable(corto_declareChild(_parent, _id, test_TableNested_ChildTable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNested_ChildTableDefine(test_TableNested_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNested_ChildTable)_this)->value, value);
    return corto_define(_this);
}

test_TableNested_ChildTable _test_TableNested_ChildTableAssign(test_TableNested_ChildTable _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNested_ChildTable)_this)->value, value);
    return _this;
}

corto_string _test_TableNested_ChildTableStr(test_TableNested_ChildTable value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNested_ChildTable_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNested_ChildTable test_TableNested_ChildTableFromStr(test_TableNested_ChildTable value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNested_ChildTable_o), str);
    return value;
}

corto_equalityKind _test_TableNested_ChildTableCompare(test_TableNested_ChildTable dst, test_TableNested_ChildTable src) {
    return corto_compare(dst, src);
}

test_TableNestedContainer _test_TableNestedContainerCreate(corto_string value) {
    test_TableNestedContainer _this;
    _this = test_TableNestedContainer(corto_declare(test_TableNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNestedContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedContainer _test_TableNestedContainerCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableNestedContainer _this;
    _this = test_TableNestedContainer(corto_declareChild(_parent, _id, test_TableNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNestedContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedContainerUpdate(test_TableNestedContainer _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableNestedContainer)((test_TableNestedContainer)CORTO_OFFSET(_this, ((corto_type)test_TableNestedContainer_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableNestedContainer)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedContainer _test_TableNestedContainerDeclare(void) {
    test_TableNestedContainer _this;
    _this = test_TableNestedContainer(corto_declare(test_TableNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedContainer _test_TableNestedContainerDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedContainer _this;
    _this = test_TableNestedContainer(corto_declareChild(_parent, _id, test_TableNestedContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedContainerDefine(test_TableNestedContainer _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNestedContainer)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedContainer _test_TableNestedContainerAssign(test_TableNestedContainer _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNestedContainer)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedContainerStr(test_TableNestedContainer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedContainer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedContainer test_TableNestedContainerFromStr(test_TableNestedContainer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedContainer_o), str);
    return value;
}

corto_equalityKind _test_TableNestedContainerCompare(test_TableNestedContainer dst, test_TableNestedContainer src) {
    return corto_compare(dst, src);
}

test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerCreate(int32_t id, corto_string value) {
    test_TableNestedContainer_ChildContainer _this;
    _this = test_TableNestedContainer_ChildContainer(corto_declare(test_TableNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedContainer_ChildContainer)_this)->id = id;
        corto_setstr(&((test_TableNestedContainer_ChildContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_TableNestedContainer_ChildContainer _this;
    _this = test_TableNestedContainer_ChildContainer(corto_declareChild(_parent, _id, test_TableNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedContainer_ChildContainer)_this)->id = id;
        corto_setstr(&((test_TableNestedContainer_ChildContainer)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedContainer_ChildContainerUpdate(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TableNestedContainer_ChildContainer)((test_TableNestedContainer_ChildContainer)CORTO_OFFSET(_this, ((corto_type)test_TableNestedContainer_ChildContainer_o)->size)))->id = id;
            corto_setstr(&((test_TableNestedContainer_ChildContainer)((test_TableNestedContainer_ChildContainer)CORTO_OFFSET(_this, ((corto_type)test_TableNestedContainer_ChildContainer_o)->size)))->value, value);
        } else {
            ((test_TableNestedContainer_ChildContainer)_this)->id = id;
            corto_setstr(&((test_TableNestedContainer_ChildContainer)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerDeclare(void) {
    test_TableNestedContainer_ChildContainer _this;
    _this = test_TableNestedContainer_ChildContainer(corto_declare(test_TableNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedContainer_ChildContainer _this;
    _this = test_TableNestedContainer_ChildContainer(corto_declareChild(_parent, _id, test_TableNestedContainer_ChildContainer_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedContainer_ChildContainerDefine(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedContainer_ChildContainer)_this)->id = id;
    corto_setstr(&((test_TableNestedContainer_ChildContainer)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerAssign(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedContainer_ChildContainer)_this)->id = id;
    corto_setstr(&((test_TableNestedContainer_ChildContainer)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedContainer_ChildContainerStr(test_TableNestedContainer_ChildContainer value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedContainer_ChildContainer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedContainer_ChildContainer test_TableNestedContainer_ChildContainerFromStr(test_TableNestedContainer_ChildContainer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedContainer_ChildContainer_o), str);
    return value;
}

corto_equalityKind _test_TableNestedContainer_ChildContainerCompare(test_TableNestedContainer_ChildContainer dst, test_TableNestedContainer_ChildContainer src) {
    return corto_compare(dst, src);
}

test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafCreate(int32_t id, corto_string value) {
    test_TableNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_TableNestedContainer_ChildContainer_ChildLeaf(corto_declare(test_TableNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_TableNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_TableNestedContainer_ChildContainer_ChildLeaf(corto_declareChild(_parent, _id, test_TableNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
        corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedContainer_ChildContainer_ChildLeafUpdate(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TableNestedContainer_ChildContainer_ChildLeaf)((test_TableNestedContainer_ChildContainer_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_TableNestedContainer_ChildContainer_ChildLeaf_o)->size)))->id = id;
            corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)((test_TableNestedContainer_ChildContainer_ChildLeaf)CORTO_OFFSET(_this, ((corto_type)test_TableNestedContainer_ChildContainer_ChildLeaf_o)->size)))->value, value);
        } else {
            ((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
            corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafDeclare(void) {
    test_TableNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_TableNestedContainer_ChildContainer_ChildLeaf(corto_declare(test_TableNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedContainer_ChildContainer_ChildLeaf _this;
    _this = test_TableNestedContainer_ChildContainer_ChildLeaf(corto_declareChild(_parent, _id, test_TableNestedContainer_ChildContainer_ChildLeaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedContainer_ChildContainer_ChildLeafDefine(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafAssign(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->id = id;
    corto_setstr(&((test_TableNestedContainer_ChildContainer_ChildLeaf)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedContainer_ChildContainer_ChildLeafStr(test_TableNestedContainer_ChildContainer_ChildLeaf value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedContainer_ChildContainer_ChildLeaf_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedContainer_ChildContainer_ChildLeaf test_TableNestedContainer_ChildContainer_ChildLeafFromStr(test_TableNestedContainer_ChildContainer_ChildLeaf value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedContainer_ChildContainer_ChildLeaf_o), str);
    return value;
}

corto_equalityKind _test_TableNestedContainer_ChildContainer_ChildLeafCompare(test_TableNestedContainer_ChildContainer_ChildLeaf dst, test_TableNestedContainer_ChildContainer_ChildLeaf src) {
    return corto_compare(dst, src);
}

test_TableNestedLeafs _test_TableNestedLeafsCreate(corto_string value) {
    test_TableNestedLeafs _this;
    _this = test_TableNestedLeafs(corto_declare(test_TableNestedLeafs_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNestedLeafs)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedLeafs _test_TableNestedLeafsCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableNestedLeafs _this;
    _this = test_TableNestedLeafs(corto_declareChild(_parent, _id, test_TableNestedLeafs_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableNestedLeafs)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedLeafsUpdate(test_TableNestedLeafs _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableNestedLeafs)((test_TableNestedLeafs)CORTO_OFFSET(_this, ((corto_type)test_TableNestedLeafs_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableNestedLeafs)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedLeafs _test_TableNestedLeafsDeclare(void) {
    test_TableNestedLeafs _this;
    _this = test_TableNestedLeafs(corto_declare(test_TableNestedLeafs_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedLeafs _test_TableNestedLeafsDeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedLeafs _this;
    _this = test_TableNestedLeafs(corto_declareChild(_parent, _id, test_TableNestedLeafs_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedLeafsDefine(test_TableNestedLeafs _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNestedLeafs)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedLeafs _test_TableNestedLeafsAssign(test_TableNestedLeafs _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableNestedLeafs)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedLeafsStr(test_TableNestedLeafs value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedLeafs_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedLeafs test_TableNestedLeafsFromStr(test_TableNestedLeafs value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedLeafs_o), str);
    return value;
}

corto_equalityKind _test_TableNestedLeafsCompare(test_TableNestedLeafs dst, test_TableNestedLeafs src) {
    return corto_compare(dst, src);
}

test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Create(int32_t id, corto_string value) {
    test_TableNestedLeafs_ChildLeaf1 _this;
    _this = test_TableNestedLeafs_ChildLeaf1(corto_declare(test_TableNestedLeafs_ChildLeaf1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedLeafs_ChildLeaf1)_this)->id = id;
        corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1CreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_TableNestedLeafs_ChildLeaf1 _this;
    _this = test_TableNestedLeafs_ChildLeaf1(corto_declareChild(_parent, _id, test_TableNestedLeafs_ChildLeaf1_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedLeafs_ChildLeaf1)_this)->id = id;
        corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedLeafs_ChildLeaf1Update(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TableNestedLeafs_ChildLeaf1)((test_TableNestedLeafs_ChildLeaf1)CORTO_OFFSET(_this, ((corto_type)test_TableNestedLeafs_ChildLeaf1_o)->size)))->id = id;
            corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)((test_TableNestedLeafs_ChildLeaf1)CORTO_OFFSET(_this, ((corto_type)test_TableNestedLeafs_ChildLeaf1_o)->size)))->value, value);
        } else {
            ((test_TableNestedLeafs_ChildLeaf1)_this)->id = id;
            corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Declare(void) {
    test_TableNestedLeafs_ChildLeaf1 _this;
    _this = test_TableNestedLeafs_ChildLeaf1(corto_declare(test_TableNestedLeafs_ChildLeaf1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1DeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedLeafs_ChildLeaf1 _this;
    _this = test_TableNestedLeafs_ChildLeaf1(corto_declareChild(_parent, _id, test_TableNestedLeafs_ChildLeaf1_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedLeafs_ChildLeaf1Define(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedLeafs_ChildLeaf1)_this)->id = id;
    corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Assign(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedLeafs_ChildLeaf1)_this)->id = id;
    corto_setstr(&((test_TableNestedLeafs_ChildLeaf1)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedLeafs_ChildLeaf1Str(test_TableNestedLeafs_ChildLeaf1 value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedLeafs_ChildLeaf1_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedLeafs_ChildLeaf1 test_TableNestedLeafs_ChildLeaf1FromStr(test_TableNestedLeafs_ChildLeaf1 value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedLeafs_ChildLeaf1_o), str);
    return value;
}

corto_equalityKind _test_TableNestedLeafs_ChildLeaf1Compare(test_TableNestedLeafs_ChildLeaf1 dst, test_TableNestedLeafs_ChildLeaf1 src) {
    return corto_compare(dst, src);
}

test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Create(int32_t id, corto_string value) {
    test_TableNestedLeafs_ChildLeaf2 _this;
    _this = test_TableNestedLeafs_ChildLeaf2(corto_declare(test_TableNestedLeafs_ChildLeaf2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedLeafs_ChildLeaf2)_this)->id = id;
        corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2CreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value) {
    test_TableNestedLeafs_ChildLeaf2 _this;
    _this = test_TableNestedLeafs_ChildLeaf2(corto_declareChild(_parent, _id, test_TableNestedLeafs_ChildLeaf2_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TableNestedLeafs_ChildLeaf2)_this)->id = id;
        corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableNestedLeafs_ChildLeaf2Update(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TableNestedLeafs_ChildLeaf2)((test_TableNestedLeafs_ChildLeaf2)CORTO_OFFSET(_this, ((corto_type)test_TableNestedLeafs_ChildLeaf2_o)->size)))->id = id;
            corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)((test_TableNestedLeafs_ChildLeaf2)CORTO_OFFSET(_this, ((corto_type)test_TableNestedLeafs_ChildLeaf2_o)->size)))->value, value);
        } else {
            ((test_TableNestedLeafs_ChildLeaf2)_this)->id = id;
            corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Declare(void) {
    test_TableNestedLeafs_ChildLeaf2 _this;
    _this = test_TableNestedLeafs_ChildLeaf2(corto_declare(test_TableNestedLeafs_ChildLeaf2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2DeclareChild(corto_object _parent, corto_string _id) {
    test_TableNestedLeafs_ChildLeaf2 _this;
    _this = test_TableNestedLeafs_ChildLeaf2(corto_declareChild(_parent, _id, test_TableNestedLeafs_ChildLeaf2_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableNestedLeafs_ChildLeaf2Define(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedLeafs_ChildLeaf2)_this)->id = id;
    corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)_this)->value, value);
    return corto_define(_this);
}

test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Assign(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value) {
    CORTO_UNUSED(_this);
    ((test_TableNestedLeafs_ChildLeaf2)_this)->id = id;
    corto_setstr(&((test_TableNestedLeafs_ChildLeaf2)_this)->value, value);
    return _this;
}

corto_string _test_TableNestedLeafs_ChildLeaf2Str(test_TableNestedLeafs_ChildLeaf2 value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableNestedLeafs_ChildLeaf2_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableNestedLeafs_ChildLeaf2 test_TableNestedLeafs_ChildLeaf2FromStr(test_TableNestedLeafs_ChildLeaf2 value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableNestedLeafs_ChildLeaf2_o), str);
    return value;
}

corto_equalityKind _test_TableNestedLeafs_ChildLeaf2Compare(test_TableNestedLeafs_ChildLeaf2 dst, test_TableNestedLeafs_ChildLeaf2 src) {
    return corto_compare(dst, src);
}

test_TableSingleKey _test_TableSingleKeyCreate(corto_string value) {
    test_TableSingleKey _this;
    _this = test_TableSingleKey(corto_declare(test_TableSingleKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableSingleKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableSingleKey _test_TableSingleKeyCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableSingleKey _this;
    _this = test_TableSingleKey(corto_declareChild(_parent, _id, test_TableSingleKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableSingleKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableSingleKeyUpdate(test_TableSingleKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableSingleKey)((test_TableSingleKey)CORTO_OFFSET(_this, ((corto_type)test_TableSingleKey_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableSingleKey)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableSingleKey _test_TableSingleKeyDeclare(void) {
    test_TableSingleKey _this;
    _this = test_TableSingleKey(corto_declare(test_TableSingleKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableSingleKey _test_TableSingleKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TableSingleKey _this;
    _this = test_TableSingleKey(corto_declareChild(_parent, _id, test_TableSingleKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableSingleKeyDefine(test_TableSingleKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableSingleKey)_this)->value, value);
    return corto_define(_this);
}

test_TableSingleKey _test_TableSingleKeyAssign(test_TableSingleKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableSingleKey)_this)->value, value);
    return _this;
}

corto_string _test_TableSingleKeyStr(test_TableSingleKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableSingleKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableSingleKey test_TableSingleKeyFromStr(test_TableSingleKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableSingleKey_o), str);
    return value;
}

corto_equalityKind _test_TableSingleKeyCompare(test_TableSingleKey dst, test_TableSingleKey src) {
    return corto_compare(dst, src);
}

test_TableStringKey _test_TableStringKeyCreate(corto_string value) {
    test_TableStringKey _this;
    _this = test_TableStringKey(corto_declare(test_TableStringKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableStringKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TableStringKey _test_TableStringKeyCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    test_TableStringKey _this;
    _this = test_TableStringKey(corto_declareChild(_parent, _id, test_TableStringKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((test_TableStringKey)_this)->value, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TableStringKeyUpdate(test_TableStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((test_TableStringKey)((test_TableStringKey)CORTO_OFFSET(_this, ((corto_type)test_TableStringKey_o)->size)))->value, value);
        } else {
            corto_setstr(&((test_TableStringKey)_this)->value, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TableStringKey _test_TableStringKeyDeclare(void) {
    test_TableStringKey _this;
    _this = test_TableStringKey(corto_declare(test_TableStringKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TableStringKey _test_TableStringKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TableStringKey _this;
    _this = test_TableStringKey(corto_declareChild(_parent, _id, test_TableStringKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TableStringKeyDefine(test_TableStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableStringKey)_this)->value, value);
    return corto_define(_this);
}

test_TableStringKey _test_TableStringKeyAssign(test_TableStringKey _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(&((test_TableStringKey)_this)->value, value);
    return _this;
}

corto_string _test_TableStringKeyStr(test_TableStringKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TableStringKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TableStringKey test_TableStringKeyFromStr(test_TableStringKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TableStringKey_o), str);
    return value;
}

corto_equalityKind _test_TableStringKeyCompare(test_TableStringKey dst, test_TableStringKey src) {
    return corto_compare(dst, src);
}

test_TargetActual _test_TargetActualCreate(int32_t actual, int32_t target, int32_t objective) {
    test_TargetActual _this;
    _this = test_TargetActual(corto_declare(test_TargetActual_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TargetActual)_this)->actual = actual;
        ((test_TargetActual)_this)->target = target;
        ((test_TargetActual)_this)->objective = objective;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TargetActual _test_TargetActualCreateChild(corto_object _parent, corto_string _id, int32_t actual, int32_t target, int32_t objective) {
    test_TargetActual _this;
    _this = test_TargetActual(corto_declareChild(_parent, _id, test_TargetActual_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TargetActual)_this)->actual = actual;
        ((test_TargetActual)_this)->target = target;
        ((test_TargetActual)_this)->objective = objective;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TargetActualUpdate(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TargetActual)((test_TargetActual)CORTO_OFFSET(_this, ((corto_type)test_TargetActual_o)->size)))->actual = actual;
            ((test_TargetActual)((test_TargetActual)CORTO_OFFSET(_this, ((corto_type)test_TargetActual_o)->size)))->target = target;
            ((test_TargetActual)((test_TargetActual)CORTO_OFFSET(_this, ((corto_type)test_TargetActual_o)->size)))->objective = objective;
        } else {
            ((test_TargetActual)_this)->actual = actual;
            ((test_TargetActual)_this)->target = target;
            ((test_TargetActual)_this)->objective = objective;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TargetActual _test_TargetActualDeclare(void) {
    test_TargetActual _this;
    _this = test_TargetActual(corto_declare(test_TargetActual_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TargetActual _test_TargetActualDeclareChild(corto_object _parent, corto_string _id) {
    test_TargetActual _this;
    _this = test_TargetActual(corto_declareChild(_parent, _id, test_TargetActual_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TargetActualDefine(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective) {
    CORTO_UNUSED(_this);
    ((test_TargetActual)_this)->actual = actual;
    ((test_TargetActual)_this)->target = target;
    ((test_TargetActual)_this)->objective = objective;
    return corto_define(_this);
}

test_TargetActual _test_TargetActualAssign(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective) {
    CORTO_UNUSED(_this);
    ((test_TargetActual)_this)->actual = actual;
    ((test_TargetActual)_this)->target = target;
    ((test_TargetActual)_this)->objective = objective;
    return _this;
}

corto_string _test_TargetActualStr(test_TargetActual value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TargetActual_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TargetActual test_TargetActualFromStr(test_TargetActual value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TargetActual_o), str);
    return value;
}

corto_equalityKind _test_TargetActualCompare(test_TargetActual dst, test_TargetActual src) {
    return corto_compare(dst, src);
}

test_TargetActualMember* _test_TargetActualMemberCreate(int32_t m, int32_t n) {
    test_TargetActualMember* _this;
    _this = test_TargetActualMember(corto_declare(test_TargetActualMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TargetActualMember*)_this)->m->actual = m;
        ((test_TargetActualMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TargetActualMember* _test_TargetActualMemberCreateChild(corto_object _parent, corto_string _id, int32_t m, int32_t n) {
    test_TargetActualMember* _this;
    _this = test_TargetActualMember(corto_declareChild(_parent, _id, test_TargetActualMember_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TargetActualMember*)_this)->m->actual = m;
        ((test_TargetActualMember*)_this)->n = n;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TargetActualMemberUpdate(test_TargetActualMember* _this, int32_t m, int32_t n) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TargetActualMember*)((test_TargetActualMember*)CORTO_OFFSET(_this, ((corto_type)test_TargetActualMember_o)->size)))->m->target = m;
            ((test_TargetActualMember*)((test_TargetActualMember*)CORTO_OFFSET(_this, ((corto_type)test_TargetActualMember_o)->size)))->n = n;
        } else {
            ((test_TargetActualMember*)_this)->m->actual = m;
            ((test_TargetActualMember*)_this)->n = n;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TargetActualMember* _test_TargetActualMemberDeclare(void) {
    test_TargetActualMember* _this;
    _this = test_TargetActualMember(corto_declare(test_TargetActualMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TargetActualMember* _test_TargetActualMemberDeclareChild(corto_object _parent, corto_string _id) {
    test_TargetActualMember* _this;
    _this = test_TargetActualMember(corto_declareChild(_parent, _id, test_TargetActualMember_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TargetActualMemberDefine(test_TargetActualMember* _this, int32_t m, int32_t n) {
    CORTO_UNUSED(_this);
    ((test_TargetActualMember*)_this)->m->actual = m;
    ((test_TargetActualMember*)_this)->n = n;
    return corto_define(_this);
}

test_TargetActualMember* _test_TargetActualMemberAssign(test_TargetActualMember* _this, int32_t m, int32_t n) {
    CORTO_UNUSED(_this);
    ((test_TargetActualMember*)_this)->m->actual = m;
    ((test_TargetActualMember*)_this)->n = n;
    return _this;
}

corto_string _test_TargetActualMemberStr(test_TargetActualMember* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_TargetActualMember_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_TargetActualMember* test_TargetActualMemberFromStr(test_TargetActualMember* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TargetActualMember_o), str);
    return value;
}

corto_equalityKind test_TargetActualMemberCompare(test_TargetActualMember* dst, test_TargetActualMember* src) {
    return corto_comparep(dst, test_TargetActualMember_o, src);
}

corto_int16 _test_TargetActualMemberInit(test_TargetActualMember* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_TargetActualMember_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_TargetActualMember_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_TargetActualMemberDeinit(test_TargetActualMember* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_TargetActualMember_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_TestKey _test_TestKeyCreate(void) {
    test_TestKey _this;
    _this = test_TestKey(corto_declare(test_TestKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TestKey _test_TestKeyCreateChild(corto_object _parent, corto_string _id) {
    test_TestKey _this;
    _this = test_TestKey(corto_declareChild(_parent, _id, test_TestKey_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TestKeyUpdate(test_TestKey _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
        } else {
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TestKey _test_TestKeyDeclare(void) {
    test_TestKey _this;
    _this = test_TestKey(corto_declare(test_TestKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TestKey _test_TestKeyDeclareChild(corto_object _parent, corto_string _id) {
    test_TestKey _this;
    _this = test_TestKey(corto_declareChild(_parent, _id, test_TestKey_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TestKeyDefine(test_TestKey _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

test_TestKey _test_TestKeyAssign(test_TestKey _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _test_TestKeyStr(test_TestKey value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TestKey_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TestKey test_TestKeyFromStr(test_TestKey value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TestKey_o), str);
    return value;
}

corto_equalityKind _test_TestKeyCompare(test_TestKey dst, test_TestKey src) {
    return corto_compare(dst, src);
}

test_TestLock _test_TestLockCreate(corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules) {
    test_TestLock _this;
    _this = test_TestLock(corto_declare(test_TestLock_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_setstr(&((corto_secure_lock)_this)->expr, expr);
        ((corto_secure_lock)_this)->priority = priority;
        if (rules) {
            corto_copyp(&((test_TestLock)_this)->rules, test_AccessRuleList_o, &rules);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TestLock _test_TestLockCreateChild(corto_object _parent, corto_string _id, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules) {
    test_TestLock _this;
    _this = test_TestLock(corto_declareChild(_parent, _id, test_TestLock_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_secure_lock)_this)->mount, mount);
        corto_setstr(&((corto_secure_lock)_this)->expr, expr);
        ((corto_secure_lock)_this)->priority = priority;
        if (rules) {
            corto_copyp(&((test_TestLock)_this)->rules, test_AccessRuleList_o, &rules);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TestLockUpdate(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((corto_secure_lock)((test_TestLock)CORTO_OFFSET(_this, ((corto_type)test_TestLock_o)->size)))->mount, mount);
            corto_setstr(&((corto_secure_lock)((test_TestLock)CORTO_OFFSET(_this, ((corto_type)test_TestLock_o)->size)))->expr, expr);
            ((corto_secure_lock)((test_TestLock)CORTO_OFFSET(_this, ((corto_type)test_TestLock_o)->size)))->priority = priority;
            if (rules) {
                corto_copyp(&((test_TestLock)((test_TestLock)CORTO_OFFSET(_this, ((corto_type)test_TestLock_o)->size)))->rules, test_AccessRuleList_o, &rules);
            }
        } else {
            corto_setstr(&((corto_secure_lock)_this)->mount, mount);
            corto_setstr(&((corto_secure_lock)_this)->expr, expr);
            ((corto_secure_lock)_this)->priority = priority;
            if (rules) {
                corto_copyp(&((test_TestLock)_this)->rules, test_AccessRuleList_o, &rules);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TestLock _test_TestLockDeclare(void) {
    test_TestLock _this;
    _this = test_TestLock(corto_declare(test_TestLock_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TestLock _test_TestLockDeclareChild(corto_object _parent, corto_string _id) {
    test_TestLock _this;
    _this = test_TestLock(corto_declareChild(_parent, _id, test_TestLock_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TestLockDefine(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    if (rules) {
        corto_copyp(&((test_TestLock)_this)->rules, test_AccessRuleList_o, &rules);
    }
    return corto_define(_this);
}

test_TestLock _test_TestLockAssign(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_secure_lock)_this)->mount, mount);
    corto_setstr(&((corto_secure_lock)_this)->expr, expr);
    ((corto_secure_lock)_this)->priority = priority;
    if (rules) {
        corto_copyp(&((test_TestLock)_this)->rules, test_AccessRuleList_o, &rules);
    }
    return _this;
}

corto_string _test_TestLockStr(test_TestLock value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TestLock_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TestLock test_TestLockFromStr(test_TestLock value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TestLock_o), str);
    return value;
}

corto_equalityKind _test_TestLockCompare(test_TestLock dst, test_TestLock src) {
    return corto_compare(dst, src);
}

test_TypeAttr* _test_TypeAttrCreate(int32_t Foo) {
    test_TypeAttr* _this;
    _this = test_TypeAttr(corto_declare(test_TypeAttr_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TypeAttr*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_TypeAttr* _test_TypeAttrCreateChild(corto_object _parent, corto_string _id, int32_t Foo) {
    test_TypeAttr* _this;
    _this = test_TypeAttr(corto_declareChild(_parent, _id, test_TypeAttr_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_TypeAttr*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_TypeAttrUpdate(test_TypeAttr* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_TypeAttr*)((test_TypeAttr*)CORTO_OFFSET(_this, ((corto_type)test_TypeAttr_o)->size)))->Foo = Foo;
        } else {
            ((test_TypeAttr*)_this)->Foo = Foo;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TypeAttr* _test_TypeAttrDeclare(void) {
    test_TypeAttr* _this;
    _this = test_TypeAttr(corto_declare(test_TypeAttr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TypeAttr* _test_TypeAttrDeclareChild(corto_object _parent, corto_string _id) {
    test_TypeAttr* _this;
    _this = test_TypeAttr(corto_declareChild(_parent, _id, test_TypeAttr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TypeAttrDefine(test_TypeAttr* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_TypeAttr*)_this)->Foo = Foo;
    return corto_define(_this);
}

test_TypeAttr* _test_TypeAttrAssign(test_TypeAttr* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_TypeAttr*)_this)->Foo = Foo;
    return _this;
}

corto_string _test_TypeAttrStr(test_TypeAttr* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_TypeAttr_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_TypeAttr* test_TypeAttrFromStr(test_TypeAttr* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TypeAttr_o), str);
    return value;
}

corto_equalityKind test_TypeAttrCompare(test_TypeAttr* dst, test_TypeAttr* src) {
    return corto_comparep(dst, test_TypeAttr_o, src);
}

corto_int16 _test_TypeAttrInit(test_TypeAttr* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_TypeAttr_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_TypeAttr_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_TypeAttrDeinit(test_TypeAttr* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_TypeAttr_o), value);
    result = corto_deinitv(&v);
    return result;
}

uintptr_t* _test_uintwCreate(uintptr_t value) {
    uintptr_t* _this;
    _this = test_uintw(corto_declare(test_uintw_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

uintptr_t* _test_uintwCreateChild(corto_object _parent, corto_string _id, uintptr_t value) {
    uintptr_t* _this;
    _this = test_uintw(corto_declareChild(_parent, _id, test_uintw_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        *_this = value;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_uintwUpdate(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uintptr_t*)CORTO_OFFSET(_this, ((corto_type)test_uintw_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uintptr_t* _test_uintwDeclare(void) {
    uintptr_t* _this;
    _this = test_uintw(corto_declare(test_uintw_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uintptr_t* _test_uintwDeclareChild(corto_object _parent, corto_string _id) {
    uintptr_t* _this;
    _this = test_uintw(corto_declareChild(_parent, _id, test_uintw_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_uintwDefine(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uintptr_t* _test_uintwAssign(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _test_uintwStr(test_uintw value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_uintw_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uintptr_t* test_uintwFromStr(uintptr_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_uintw_o), str);
    return value;
}

corto_equalityKind test_uintwCompare(test_uintw dst, test_uintw src) {
    return corto_comparep(&dst, test_uintw_o, &src);
}

corto_int16 _test_uintwInit(test_uintw* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_uintw_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_uintw_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_uintwDeinit(test_uintw* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_uintw_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_ValueCast _test_ValueCastCreate(uint32_t assertCount) {
    test_ValueCast _this;
    _this = test_ValueCast(corto_declare(test_ValueCast_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ValueCast _test_ValueCastCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_ValueCast _this;
    _this = test_ValueCast(corto_declareChild(_parent, _id, test_ValueCast_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ValueCastUpdate(test_ValueCast _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_ValueCast)CORTO_OFFSET(_this, ((corto_type)test_ValueCast_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ValueCast _test_ValueCastDeclare(void) {
    test_ValueCast _this;
    _this = test_ValueCast(corto_declare(test_ValueCast_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ValueCast _test_ValueCastDeclareChild(corto_object _parent, corto_string _id) {
    test_ValueCast _this;
    _this = test_ValueCast(corto_declareChild(_parent, _id, test_ValueCast_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ValueCastDefine(test_ValueCast _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_ValueCast _test_ValueCastAssign(test_ValueCast _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_ValueCastStr(test_ValueCast value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ValueCast_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ValueCast test_ValueCastFromStr(test_ValueCast value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ValueCast_o), str);
    return value;
}

corto_equalityKind _test_ValueCastCompare(test_ValueCast dst, test_ValueCast src) {
    return corto_compare(dst, src);
}

test_ValueExpr _test_ValueExprCreate(uint32_t assertCount) {
    test_ValueExpr _this;
    _this = test_ValueExpr(corto_declare(test_ValueExpr_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_ValueExpr _test_ValueExprCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount) {
    test_ValueExpr _this;
    _this = test_ValueExpr(corto_declareChild(_parent, _id, test_ValueExpr_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_ValueExprUpdate(test_ValueExpr _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_SuiteData)((test_ValueExpr)CORTO_OFFSET(_this, ((corto_type)test_ValueExpr_o)->size)))->assertCount = assertCount;
        } else {
            ((test_SuiteData)_this)->assertCount = assertCount;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_ValueExpr _test_ValueExprDeclare(void) {
    test_ValueExpr _this;
    _this = test_ValueExpr(corto_declare(test_ValueExpr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_ValueExpr _test_ValueExprDeclareChild(corto_object _parent, corto_string _id) {
    test_ValueExpr _this;
    _this = test_ValueExpr(corto_declareChild(_parent, _id, test_ValueExpr_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_ValueExprDefine(test_ValueExpr _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

test_ValueExpr _test_ValueExprAssign(test_ValueExpr _this, uint32_t assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return _this;
}

corto_string _test_ValueExprStr(test_ValueExpr value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_ValueExpr_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ValueExpr test_ValueExprFromStr(test_ValueExpr value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ValueExpr_o), str);
    return value;
}

corto_equalityKind _test_ValueExprCompare(test_ValueExpr dst, test_ValueExpr src) {
    return corto_compare(dst, src);
}

test_VoidParent* _test_VoidParentCreate(int32_t Foo) {
    test_VoidParent* _this;
    _this = test_VoidParent(corto_declare(test_VoidParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_VoidParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

test_VoidParent* _test_VoidParentCreateChild(corto_object _parent, corto_string _id, int32_t Foo) {
    test_VoidParent* _this;
    _this = test_VoidParent(corto_declareChild(_parent, _id, test_VoidParent_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((test_VoidParent*)_this)->Foo = Foo;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _test_VoidParentUpdate(test_VoidParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((test_VoidParent*)((test_VoidParent*)CORTO_OFFSET(_this, ((corto_type)test_VoidParent_o)->size)))->Foo = Foo;
        } else {
            ((test_VoidParent*)_this)->Foo = Foo;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_VoidParent* _test_VoidParentDeclare(void) {
    test_VoidParent* _this;
    _this = test_VoidParent(corto_declare(test_VoidParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_VoidParent* _test_VoidParentDeclareChild(corto_object _parent, corto_string _id) {
    test_VoidParent* _this;
    _this = test_VoidParent(corto_declareChild(_parent, _id, test_VoidParent_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_VoidParentDefine(test_VoidParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_VoidParent*)_this)->Foo = Foo;
    return corto_define(_this);
}

test_VoidParent* _test_VoidParentAssign(test_VoidParent* _this, int32_t Foo) {
    CORTO_UNUSED(_this);
    ((test_VoidParent*)_this)->Foo = Foo;
    return _this;
}

corto_string _test_VoidParentStr(test_VoidParent* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(test_VoidParent_o), value);
    result = corto_strv(&v, 0);
    return result;
}

test_VoidParent* test_VoidParentFromStr(test_VoidParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_VoidParent_o), str);
    return value;
}

corto_equalityKind test_VoidParentCompare(test_VoidParent* dst, test_VoidParent* src) {
    return corto_comparep(dst, test_VoidParent_o, src);
}

corto_int16 _test_VoidParentInit(test_VoidParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_VoidParent_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(test_VoidParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_VoidParentDeinit(test_VoidParent* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(test_VoidParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_AccessRule* test_AccessRuleListInsertAlloc(test_AccessRuleList list) {
    test_AccessRule* result;
    result = (test_AccessRule*)corto_calloc(corto_type_sizeof(corto_type(test_AccessRule_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(test_AccessRule_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

test_AccessRule* test_AccessRuleListInsert(test_AccessRuleList list, test_AccessRule* element) {
    test_AccessRule *result = test_AccessRuleListInsertAlloc(list);
    corto_copyp(result, test_AccessRule_o, element);
    return result;
}

test_AccessRule* test_AccessRuleListAppendAlloc(test_AccessRuleList list) {
    test_AccessRule* result;
    result = (test_AccessRule*)corto_calloc(corto_type_sizeof(corto_type(test_AccessRule_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(test_AccessRule_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

test_AccessRule* test_AccessRuleListAppend(test_AccessRuleList list, test_AccessRule* element) {
    test_AccessRule *result = test_AccessRuleListAppendAlloc(list);
    corto_copyp(result, test_AccessRule_o, element);
    return result;
}

test_AccessRule* test_AccessRuleListTakeFirst(test_AccessRuleList list) {
    return (test_AccessRule*)(corto_word)corto_llTakeFirst(list);
}

test_AccessRule* test_AccessRuleListLast(test_AccessRuleList list) {
    return (test_AccessRule*)(corto_word)corto_llLast(list);
}

test_AccessRule* test_AccessRuleListGet(test_AccessRuleList list, corto_uint32 index) {
    return (test_AccessRule*)corto_llGet(list, index);
}

corto_uint32 test_AccessRuleListSize(test_AccessRuleList list) {
    return corto_llSize(list);
}

void test_AccessRuleListClear(test_AccessRuleList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, test_AccessRule_o);
        corto_dealloc(ptr);
    }
    corto_llClear(list);
}

int64_t* test_AllocListInsertAlloc(test_AllocList list) {
    int64_t* result;
    result = (int64_t*)corto_calloc(corto_type_sizeof(corto_type(corto_int64_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_int64_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

int64_t* test_AllocListInsert(test_AllocList list, int64_t element) {
    int64_t *result = test_AllocListInsertAlloc(list);
    corto_copyp(result, corto_int64_o, &element);
    return result;
}

int64_t* test_AllocListAppendAlloc(test_AllocList list) {
    int64_t* result;
    result = (int64_t*)corto_calloc(corto_type_sizeof(corto_type(corto_int64_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_int64_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

int64_t* test_AllocListAppend(test_AllocList list, int64_t element) {
    int64_t *result = test_AllocListAppendAlloc(list);
    corto_copyp(result, corto_int64_o, &element);
    return result;
}

int64_t* test_AllocListTakeFirst(test_AllocList list) {
    return (int64_t*)(corto_word)corto_llTakeFirst(list);
}

int64_t* test_AllocListLast(test_AllocList list) {
    return (int64_t*)(corto_word)corto_llLast(list);
}

int64_t test_AllocListGet(test_AllocList list, corto_uint32 index) {
    return *(int64_t*)corto_llGet(list, index);
}

corto_uint32 test_AllocListSize(test_AllocList list) {
    return corto_llSize(list);
}

void test_AllocListClear(test_AllocList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_int64_o);
        corto_dealloc(ptr);
    }
    corto_llClear(list);
}

int64_t* test_AllocSequenceAppend(test_AllocSequence *seq, int64_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int64_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int64_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_copyp(&seq->buffer[seq->length-1], corto_int64_o, &element);
    return &seq->buffer[seq->length-1];
}

int64_t* test_AllocSequenceAppendAlloc(test_AllocSequence *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int64_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int64_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void test_AllocSequenceSize(test_AllocSequence *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (int64_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_int64_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void test_AllocSequenceClear(test_AllocSequence *seq) {
    test_AllocSequenceSize(seq, 0);
}

test_Point* test_CompositeListInsertAlloc(test_CompositeList list) {
    test_Point* result;
    result = (test_Point*)corto_calloc(corto_type_sizeof(corto_type(test_Point_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(test_Point_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

test_Point* test_CompositeListInsert(test_CompositeList list, test_Point* element) {
    test_Point *result = test_CompositeListInsertAlloc(list);
    corto_copyp(result, test_Point_o, element);
    return result;
}

test_Point* test_CompositeListAppendAlloc(test_CompositeList list) {
    test_Point* result;
    result = (test_Point*)corto_calloc(corto_type_sizeof(corto_type(test_Point_o)));
    {
        corto_value v;
        v = corto_value_value(corto_type(test_Point_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

test_Point* test_CompositeListAppend(test_CompositeList list, test_Point* element) {
    test_Point *result = test_CompositeListAppendAlloc(list);
    corto_copyp(result, test_Point_o, element);
    return result;
}

test_Point* test_CompositeListTakeFirst(test_CompositeList list) {
    return (test_Point*)(corto_word)corto_llTakeFirst(list);
}

test_Point* test_CompositeListLast(test_CompositeList list) {
    return (test_Point*)(corto_word)corto_llLast(list);
}

test_Point* test_CompositeListGet(test_CompositeList list, corto_uint32 index) {
    return (test_Point*)corto_llGet(list, index);
}

corto_uint32 test_CompositeListSize(test_CompositeList list) {
    return corto_llSize(list);
}

void test_CompositeListClear(test_CompositeList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, test_Point_o);
        corto_dealloc(ptr);
    }
    corto_llClear(list);
}

test_Point* test_CompositeSequenceAppend(test_CompositeSequence *seq, test_Point element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (test_Point*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(test_Point_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(test_Point_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    corto_copyp(&seq->buffer[seq->length-1], test_Point_o, &element);
    return &seq->buffer[seq->length-1];
}

test_Point* test_CompositeSequenceAppendAlloc(test_CompositeSequence *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (test_Point*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(test_Point_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(test_Point_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void test_CompositeSequenceSize(test_CompositeSequence *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(test_Point_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->buffer = (test_Point*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(test_Point_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(test_Point_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void test_CompositeSequenceClear(test_CompositeSequence *seq) {
    test_CompositeSequenceSize(seq, 0);
}

void test_ObjectListInsert(test_ObjectList list, corto_object element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void test_ObjectListAppend(test_ObjectList list, corto_object element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

void test_ObjectListRemove(test_ObjectList list, corto_object element) {
    corto_llRemove(list, element);
    corto_release(element);
}

corto_object test_ObjectListTakeFirst(test_ObjectList list) {
    return (corto_object)(corto_word)corto_llTakeFirst(list);
}

corto_object test_ObjectListLast(test_ObjectList list) {
    return (corto_object)(corto_word)corto_llLast(list);
}

corto_object test_ObjectListGet(test_ObjectList list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_llGet(list, index);
}

corto_uint32 test_ObjectListSize(test_ObjectList list) {
    return corto_llSize(list);
}

void test_ObjectListClear(test_ObjectList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_release(ptr);
    }
    corto_llClear(list);
}

corto_object* test_ObjectSequenceAppend(test_ObjectSequence *seq, corto_object element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_object* test_ObjectSequenceAppendAlloc(test_ObjectSequence *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void test_ObjectSequenceSize(test_ObjectSequence *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_object_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void test_ObjectSequenceClear(test_ObjectSequence *seq) {
    test_ObjectSequenceSize(seq, 0);
}

void test_PrimitiveListInsert(test_PrimitiveList list, int32_t element) {
    corto_llInsert(list, (void*)(corto_word)element);
}

void test_PrimitiveListAppend(test_PrimitiveList list, int32_t element) {
    corto_llAppend(list, (void*)(corto_word)element);
}

int32_t test_PrimitiveListTakeFirst(test_PrimitiveList list) {
    return (int32_t)(corto_word)corto_llTakeFirst(list);
}

int32_t test_PrimitiveListLast(test_PrimitiveList list) {
    return (int32_t)(corto_word)corto_llLast(list);
}

int32_t test_PrimitiveListGet(test_PrimitiveList list, corto_uint32 index) {
    return (int32_t)(corto_word)corto_llGet(list, index);
}

corto_uint32 test_PrimitiveListSize(test_PrimitiveList list) {
    return corto_llSize(list);
}

void test_PrimitiveListClear(test_PrimitiveList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_int32_o);
    }
    corto_llClear(list);
}

int32_t* test_PrimitiveSequenceAppend(test_PrimitiveSequence *seq, int32_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_copyp(&seq->buffer[seq->length-1], corto_int32_o, &element);
    return &seq->buffer[seq->length-1];
}

int32_t* test_PrimitiveSequenceAppendAlloc(test_PrimitiveSequence *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void test_PrimitiveSequenceSize(test_PrimitiveSequence *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void test_PrimitiveSequenceClear(test_PrimitiveSequence *seq) {
    test_PrimitiveSequenceSize(seq, 0);
}

void test_StringListInsert(test_StringList list, corto_string element) {
    corto_llInsert(list, (void*)corto_strdup(element));
}

void test_StringListAppend(test_StringList list, corto_string element) {
    corto_llAppend(list, (void*)corto_strdup(element));
}

corto_string test_StringListTakeFirst(test_StringList list) {
    return (corto_string)(corto_word)corto_llTakeFirst(list);
}

corto_string test_StringListLast(test_StringList list) {
    return (corto_string)(corto_word)corto_llLast(list);
}

corto_string test_StringListGet(test_StringList list, corto_uint32 index) {
    return (corto_string)(corto_word)corto_llGet(list, index);
}

corto_uint32 test_StringListSize(test_StringList list) {
    return corto_llSize(list);
}

void test_StringListClear(test_StringList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_string_o);
    }
    corto_llClear(list);
}

corto_string* test_StringSequenceAppend(test_StringSequence *seq, corto_string element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_copyp(&seq->buffer[seq->length-1], corto_string_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_string* test_StringSequenceAppendAlloc(test_StringSequence *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void test_StringSequenceSize(test_StringSequence *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void test_StringSequenceClear(test_StringSequence *seq) {
    test_StringSequenceSize(seq, 0);
}

void corto_objectListInsert(corto_objectList list, corto_object element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_objectListAppend(corto_objectList list, corto_object element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_objectListRemove(corto_objectList list, corto_object element) {
    corto_llRemove(list, element);
    corto_release(element);
}

corto_object corto_objectListTakeFirst(corto_objectList list) {
    return (corto_object)(corto_word)corto_llTakeFirst(list);
}

corto_object corto_objectListLast(corto_objectList list) {
    return (corto_object)(corto_word)corto_llLast(list);
}

corto_object corto_objectListGet(corto_objectList list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_objectListSize(corto_objectList list) {
    return corto_llSize(list);
}

void corto_objectListClear(corto_objectList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_release(ptr);
    }
    corto_llClear(list);
}

void corto_subscriberListInsert(corto_subscriberList list, corto_subscriber element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_subscriberListAppend(corto_subscriberList list, corto_subscriber element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_subscriberListRemove(corto_subscriberList list, corto_subscriber element) {
    corto_llRemove(list, element);
    corto_release(element);
}

corto_subscriber corto_subscriberListTakeFirst(corto_subscriberList list) {
    return (corto_subscriber)(corto_word)corto_llTakeFirst(list);
}

corto_subscriber corto_subscriberListLast(corto_subscriberList list) {
    return (corto_subscriber)(corto_word)corto_llLast(list);
}

corto_subscriber corto_subscriberListGet(corto_subscriberList list, corto_uint32 index) {
    return (corto_subscriber)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_subscriberListSize(corto_subscriberList list) {
    return corto_llSize(list);
}

void corto_subscriberListClear(corto_subscriberList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_release(ptr);
    }
    corto_llClear(list);
}

