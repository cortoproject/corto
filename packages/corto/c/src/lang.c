/* lang.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>
#include <corto/lang/_load.h>

corto_alias _corto_aliasCreate(corto_member member) {
    corto_alias _this;
    _this = corto_alias(corto_declare(corto_alias_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_alias)_this)->member, member);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_alias _corto_aliasCreateChild(corto_object _parent, corto_string _id, corto_member member) {
    corto_alias _this;
    _this = corto_alias(corto_declareChild(_parent, _id, corto_alias_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_alias)_this)->member, member);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_alias)((corto_alias)CORTO_OFFSET(_this, ((corto_type)corto_alias_o)->size)))->member, member);
        } else {
            corto_setref(&((corto_alias)_this)->member, member);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_alias _corto_aliasDeclare(void) {
    corto_alias _this;
    _this = corto_alias(corto_declare(corto_alias_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_alias _corto_aliasDeclareChild(corto_object _parent, corto_string _id) {
    corto_alias _this;
    _this = corto_alias(corto_declareChild(_parent, _id, corto_alias_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_aliasDefine(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_alias)_this)->member, member);
    return corto_define(_this);
}

corto_alias _corto_aliasAssign(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_alias)_this)->member, member);
    return _this;
}

corto_string _corto_aliasStr(corto_alias value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_alias_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_alias corto_aliasFromStr(corto_alias value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_alias_o), str);
    return value;
}

corto_equalityKind _corto_aliasCompare(corto_alias dst, corto_alias src) {
    return corto_compare(dst, src);
}

corto_any* _corto_anyCreate(corto_type type, void *value) {
    corto_any* _this;
    _this = corto_any(corto_declare(corto_any_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_any v;
        v.value = value;
        v.type = type;
        _this->owner = TRUE;
        corto_copyp(_this, corto_any_o, &v);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_any* _corto_anyCreateChild(corto_object _parent, corto_string _id, corto_type type, void *value) {
    corto_any* _this;
    _this = corto_any(corto_declareChild(_parent, _id, corto_any_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_any v;
        v.value = value;
        v.type = type;
        _this->owner = TRUE;
        corto_copyp(_this, corto_any_o, &v);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_anyUpdate(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_any v;
            v.value = value;
            v.type = type;
            ((corto_any*)CORTO_OFFSET(_this, ((corto_type)corto_any_o)->size))->owner = TRUE;
            corto_copyp(((corto_any*)CORTO_OFFSET(_this, ((corto_type)corto_any_o)->size)), corto_any_o, &v);
        } else {
            corto_any v;
            v.value = value;
            v.type = type;
            _this->owner = TRUE;
            corto_copyp(_this, corto_any_o, &v);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_any* _corto_anyDeclare(void) {
    corto_any* _this;
    _this = corto_any(corto_declare(corto_any_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_any* _corto_anyDeclareChild(corto_object _parent, corto_string _id) {
    corto_any* _this;
    _this = corto_any(corto_declareChild(_parent, _id, corto_any_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_anyDefine(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_copyp(_this, corto_any_o, &v);
    return corto_define(_this);
}

corto_any* _corto_anyAssign(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_copyp(_this, corto_any_o, &v);
    return _this;
}

corto_string _corto_anyStr(corto_any value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_any_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_any* corto_anyFromStr(corto_any* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_any_o), str);
    return value;
}

corto_equalityKind corto_anyCompare(corto_any dst, corto_any src) {
    return corto_comparep(&dst, corto_any_o, &src);
}

corto_int16 _corto_anyInit(corto_any* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_any_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_any_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_anyDeinit(corto_any* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_any_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_array _corto_arrayCreate(corto_type elementType, uint32_t max) {
    corto_array _this;
    _this = corto_array(corto_declare(corto_array_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_array _corto_arrayCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max) {
    corto_array _this;
    _this = corto_array(corto_declareChild(_parent, _id, corto_array_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_array)CORTO_OFFSET(_this, ((corto_type)corto_array_o)->size)))->max = max;
        } else {
            corto_setref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_array _corto_arrayDeclare(void) {
    corto_array _this;
    _this = corto_array(corto_declare(corto_array_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_array _corto_arrayDeclareChild(corto_object _parent, corto_string _id) {
    corto_array _this;
    _this = corto_array(corto_declareChild(_parent, _id, corto_array_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_array _corto_arrayAssign(corto_array _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_string _corto_arrayStr(corto_array value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_array_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_array corto_arrayFromStr(corto_array value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_array_o), str);
    return value;
}

corto_equalityKind _corto_arrayCompare(corto_array dst, corto_array src) {
    return corto_compare(dst, src);
}

corto_attr* _corto_attrCreate(corto_attr value) {
    corto_attr* _this;
    _this = corto_attr(corto_declare(corto_attr_o));
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

corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _id, corto_attr value) {
    corto_attr* _this;
    _this = corto_attr(corto_declareChild(_parent, _id, corto_attr_o));
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

corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_attr*)CORTO_OFFSET(_this, ((corto_type)corto_attr_o)->size)) = value;
        } else {
            *_this = value;
        }
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

corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _id) {
    corto_attr* _this;
    _this = corto_attr(corto_declareChild(_parent, _id, corto_attr_o));
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

corto_binary _corto_binaryCreate(corto_width width) {
    corto_binary _this;
    _this = corto_binary(corto_declare(corto_binary_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_binary _corto_binaryCreateChild(corto_object _parent, corto_string _id, corto_width width) {
    corto_binary _this;
    _this = corto_binary(corto_declareChild(_parent, _id, corto_binary_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_binary)CORTO_OFFSET(_this, ((corto_type)corto_binary_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_binary _corto_binaryDeclare(void) {
    corto_binary _this;
    _this = corto_binary(corto_declare(corto_binary_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_binary _corto_binaryDeclareChild(corto_object _parent, corto_string _id) {
    corto_binary _this;
    _this = corto_binary(corto_declareChild(_parent, _id, corto_binary_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_binaryDefine(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_binary _corto_binaryAssign(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_string _corto_binaryStr(corto_binary value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_binary_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_binary corto_binaryFromStr(corto_binary value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_binary_o), str);
    return value;
}

corto_equalityKind _corto_binaryCompare(corto_binary dst, corto_binary src) {
    return corto_compare(dst, src);
}

corto_bitmask _corto_bitmaskCreate(void) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declare(corto_bitmask_o));
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

corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, corto_string _id) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declareChild(_parent, _id, corto_bitmask_o));
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

corto_int16 _corto_bitmaskUpdate(corto_bitmask _this) {
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

corto_bitmask _corto_bitmaskDeclare(void) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declare(corto_bitmask_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, corto_string _id) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declareChild(_parent, _id, corto_bitmask_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_bitmaskDefine(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_bitmask _corto_bitmaskAssign(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_bitmaskStr(corto_bitmask value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_bitmask_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_bitmask corto_bitmaskFromStr(corto_bitmask value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_bitmask_o), str);
    return value;
}

corto_equalityKind _corto_bitmaskCompare(corto_bitmask dst, corto_bitmask src) {
    return corto_compare(dst, src);
}

bool* _corto_boolCreate(bool value) {
    bool* _this;
    _this = corto_bool(corto_declare(corto_bool_o));
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

bool* _corto_boolCreateChild(corto_object _parent, corto_string _id, bool value) {
    bool* _this;
    _this = corto_bool(corto_declareChild(_parent, _id, corto_bool_o));
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

corto_int16 _corto_boolUpdate(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((bool*)CORTO_OFFSET(_this, ((corto_type)corto_bool_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

bool* _corto_boolDeclare(void) {
    bool* _this;
    _this = corto_bool(corto_declare(corto_bool_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

bool* _corto_boolDeclareChild(corto_object _parent, corto_string _id) {
    bool* _this;
    _this = corto_bool(corto_declareChild(_parent, _id, corto_bool_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_boolDefine(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

bool* _corto_boolAssign(bool* _this, bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_boolStr(corto_bool value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_bool_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

bool* corto_boolFromStr(bool* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_bool_o), str);
    return value;
}

corto_equalityKind corto_boolCompare(corto_bool dst, corto_bool src) {
    return corto_comparep(&dst, corto_bool_o, &src);
}

corto_int16 _corto_boolInit(corto_bool* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_bool_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_bool_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_boolDeinit(corto_bool* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_bool_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_boolean _corto_booleanCreate(void) {
    corto_boolean _this;
    _this = corto_boolean(corto_declare(corto_boolean_o));
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

corto_boolean _corto_booleanCreateChild(corto_object _parent, corto_string _id) {
    corto_boolean _this;
    _this = corto_boolean(corto_declareChild(_parent, _id, corto_boolean_o));
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

corto_int16 _corto_booleanUpdate(corto_boolean _this) {
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

corto_boolean _corto_booleanDeclare(void) {
    corto_boolean _this;
    _this = corto_boolean(corto_declare(corto_boolean_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_boolean _corto_booleanDeclareChild(corto_object _parent, corto_string _id) {
    corto_boolean _this;
    _this = corto_boolean(corto_declareChild(_parent, _id, corto_boolean_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_booleanDefine(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_boolean _corto_booleanAssign(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_booleanStr(corto_boolean value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_boolean_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_boolean corto_booleanFromStr(corto_boolean value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_boolean_o), str);
    return value;
}

corto_equalityKind _corto_booleanCompare(corto_boolean dst, corto_boolean src) {
    return corto_compare(dst, src);
}

corto_case _corto_caseCreate(corto_int32seq discriminator, corto_type type) {
    corto_case _this;
    _this = corto_case(corto_declare(corto_case_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_copyp(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
        corto_setref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_case _corto_caseCreateChild(corto_object _parent, corto_string _id, corto_int32seq discriminator, corto_type type) {
    corto_case _this;
    _this = corto_case(corto_declareChild(_parent, _id, corto_case_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_copyp(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
        corto_setref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_caseUpdate(corto_case _this, corto_int32seq discriminator, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_copyp(&((corto_case)((corto_case)CORTO_OFFSET(_this, ((corto_type)corto_case_o)->size)))->discriminator, corto_int32seq_o, &discriminator);
            corto_setref(&((corto_member)((corto_case)CORTO_OFFSET(_this, ((corto_type)corto_case_o)->size)))->type, type);
        } else {
            corto_copyp(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
            corto_setref(&((corto_member)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_case _corto_caseDeclare(void) {
    corto_case _this;
    _this = corto_case(corto_declare(corto_case_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_case _corto_caseDeclareChild(corto_object _parent, corto_string _id) {
    corto_case _this;
    _this = corto_case(corto_declareChild(_parent, _id, corto_case_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_caseDefine(corto_case _this, corto_int32seq discriminator, corto_type type) {
    CORTO_UNUSED(_this);
    corto_copyp(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
    corto_setref(&((corto_member)_this)->type, type);
    return corto_define(_this);
}

corto_case _corto_caseAssign(corto_case _this, corto_int32seq discriminator, corto_type type) {
    CORTO_UNUSED(_this);
    corto_copyp(&((corto_case)_this)->discriminator, corto_int32seq_o, &discriminator);
    corto_setref(&((corto_member)_this)->type, type);
    return _this;
}

corto_string _corto_caseStr(corto_case value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_case_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_case corto_caseFromStr(corto_case value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_case_o), str);
    return value;
}

corto_equalityKind _corto_caseCompare(corto_case dst, corto_case src) {
    return corto_compare(dst, src);
}

char* _corto_charCreate(char value) {
    char* _this;
    _this = corto_char(corto_declare(corto_char_o));
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

char* _corto_charCreateChild(corto_object _parent, corto_string _id, char value) {
    char* _this;
    _this = corto_char(corto_declareChild(_parent, _id, corto_char_o));
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

corto_int16 _corto_charUpdate(char* _this, char value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((char*)CORTO_OFFSET(_this, ((corto_type)corto_char_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

char* _corto_charDeclare(void) {
    char* _this;
    _this = corto_char(corto_declare(corto_char_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

char* _corto_charDeclareChild(corto_object _parent, corto_string _id) {
    char* _this;
    _this = corto_char(corto_declareChild(_parent, _id, corto_char_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_charDefine(char* _this, char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

char* _corto_charAssign(char* _this, char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_charStr(corto_char value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_char_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

char* corto_charFromStr(char* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_char_o), str);
    return value;
}

corto_equalityKind corto_charCompare(corto_char dst, corto_char src) {
    return corto_comparep(&dst, corto_char_o, &src);
}

corto_int16 _corto_charInit(corto_char* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_char_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_char_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_charDeinit(corto_char* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_char_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_character _corto_characterCreate(corto_width width) {
    corto_character _this;
    _this = corto_character(corto_declare(corto_character_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_character _corto_characterCreateChild(corto_object _parent, corto_string _id, corto_width width) {
    corto_character _this;
    _this = corto_character(corto_declareChild(_parent, _id, corto_character_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_characterUpdate(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_character)CORTO_OFFSET(_this, ((corto_type)corto_character_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_character _corto_characterDeclare(void) {
    corto_character _this;
    _this = corto_character(corto_declare(corto_character_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_character _corto_characterDeclareChild(corto_object _parent, corto_string _id) {
    corto_character _this;
    _this = corto_character(corto_declareChild(_parent, _id, corto_character_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_characterDefine(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_character _corto_characterAssign(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_string _corto_characterStr(corto_character value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_character_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_character corto_characterFromStr(corto_character value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_character_o), str);
    return value;
}

corto_equalityKind _corto_characterCompare(corto_character dst, corto_character src) {
    return corto_compare(dst, src);
}

corto_class _corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_class _this;
    _this = corto_class(corto_declare(corto_class_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_class _corto_classCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_class _this;
    _this = corto_class(corto_declareChild(_parent, _id, corto_class_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->base, base);
            ((corto_struct)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->baseAccess = baseAccess;
            corto_copyp(&((corto_class)((corto_class)CORTO_OFFSET(_this, ((corto_type)corto_class_o)->size)))->implements, corto_interfaceseq_o, &implements);
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_class _corto_classDeclare(void) {
    corto_class _this;
    _this = corto_class(corto_declare(corto_class_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_class _corto_classDeclareChild(corto_object _parent, corto_string _id) {
    corto_class _this;
    _this = corto_class(corto_declareChild(_parent, _id, corto_class_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return corto_define(_this);
}

corto_class _corto_classAssign(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    return _this;
}

corto_string _corto_classStr(corto_class value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_class_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_class corto_classFromStr(corto_class value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_class_o), str);
    return value;
}

corto_equalityKind _corto_classCompare(corto_class dst, corto_class src) {
    return corto_compare(dst, src);
}

corto_collection _corto_collectionCreate(corto_type elementType, uint32_t max) {
    corto_collection _this;
    _this = corto_collection(corto_declare(corto_collection_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_collection _corto_collectionCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max) {
    corto_collection _this;
    _this = corto_collection(corto_declareChild(_parent, _id, corto_collection_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_collection)CORTO_OFFSET(_this, ((corto_type)corto_collection_o)->size)))->max = max;
        } else {
            corto_setref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_collection _corto_collectionDeclare(void) {
    corto_collection _this;
    _this = corto_collection(corto_declare(corto_collection_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_collection _corto_collectionDeclareChild(corto_object _parent, corto_string _id) {
    corto_collection _this;
    _this = corto_collection(corto_declareChild(_parent, _id, corto_collection_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_collection _corto_collectionAssign(corto_collection _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_string _corto_collectionStr(corto_collection value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_collection_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_collection corto_collectionFromStr(corto_collection value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_collection_o), str);
    return value;
}

corto_equalityKind _corto_collectionCompare(corto_collection dst, corto_collection src) {
    return corto_compare(dst, src);
}

corto_collectionKind* _corto_collectionKindCreate(corto_collectionKind value) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declare(corto_collectionKind_o));
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

corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, corto_string _id, corto_collectionKind value) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declareChild(_parent, _id, corto_collectionKind_o));
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

corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_collectionKind*)CORTO_OFFSET(_this, ((corto_type)corto_collectionKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_collectionKind* _corto_collectionKindDeclare(void) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declare(corto_collectionKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declareChild(_parent, _id, corto_collectionKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_collectionKind* _corto_collectionKindAssign(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_collectionKindStr(corto_collectionKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_collectionKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_collectionKind* corto_collectionKindFromStr(corto_collectionKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_collectionKind_o), str);
    return value;
}

corto_equalityKind corto_collectionKindCompare(corto_collectionKind dst, corto_collectionKind src) {
    return corto_comparep(&dst, corto_collectionKind_o, &src);
}

corto_int16 _corto_collectionKindInit(corto_collectionKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_collectionKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_collectionKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_collectionKindDeinit(corto_collectionKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_collectionKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_compositeKind* _corto_compositeKindCreate(corto_compositeKind value) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declare(corto_compositeKind_o));
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

corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, corto_string _id, corto_compositeKind value) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declareChild(_parent, _id, corto_compositeKind_o));
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

corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_compositeKind*)CORTO_OFFSET(_this, ((corto_type)corto_compositeKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_compositeKind* _corto_compositeKindDeclare(void) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declare(corto_compositeKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declareChild(_parent, _id, corto_compositeKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_compositeKind* _corto_compositeKindAssign(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_compositeKindStr(corto_compositeKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_compositeKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_compositeKind* corto_compositeKindFromStr(corto_compositeKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_compositeKind_o), str);
    return value;
}

corto_equalityKind corto_compositeKindCompare(corto_compositeKind dst, corto_compositeKind src) {
    return corto_comparep(&dst, corto_compositeKind_o, &src);
}

corto_int16 _corto_compositeKindInit(corto_compositeKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_compositeKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_compositeKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_compositeKindDeinit(corto_compositeKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_compositeKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

int32_t* _corto_constantCreate(int32_t value) {
    int32_t* _this;
    _this = corto_constant(corto_declare(corto_constant_o));
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

int32_t* _corto_constantCreateChild(corto_object _parent, corto_string _id, int32_t value) {
    int32_t* _this;
    _this = corto_constant(corto_declareChild(_parent, _id, corto_constant_o));
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

corto_int16 _corto_constantUpdate(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int32_t*)CORTO_OFFSET(_this, ((corto_type)corto_constant_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

int32_t* _corto_constantDeclare(void) {
    int32_t* _this;
    _this = corto_constant(corto_declare(corto_constant_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

int32_t* _corto_constantDeclareChild(corto_object _parent, corto_string _id) {
    int32_t* _this;
    _this = corto_constant(corto_declareChild(_parent, _id, corto_constant_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_constantDefine(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int32_t* _corto_constantAssign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_constantStr(corto_constant value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_constant_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

int32_t* corto_constantFromStr(int32_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_constant_o), str);
    return value;
}

corto_equalityKind corto_constantCompare(corto_constant dst, corto_constant src) {
    return corto_comparep(&dst, corto_constant_o, &src);
}

corto_int16 _corto_constantInit(corto_constant* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_constant_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_constant_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_constantDeinit(corto_constant* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_constant_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_container _corto_containerCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_container _this;
    _this = corto_container(corto_declare(corto_container_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_container _corto_containerCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_container _this;
    _this = corto_container(corto_declareChild(_parent, _id, corto_container_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_containerUpdate(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->base, base);
            ((corto_struct)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->baseAccess = baseAccess;
            corto_copyp(&((corto_class)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)((corto_container)CORTO_OFFSET(_this, ((corto_type)corto_container_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_container _corto_containerDeclare(void) {
    corto_container _this;
    _this = corto_container(corto_declare(corto_container_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_container _corto_containerDeclareChild(corto_object _parent, corto_string _id) {
    corto_container _this;
    _this = corto_container(corto_declareChild(_parent, _id, corto_container_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_containerDefine(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return corto_define(_this);
}

corto_container _corto_containerAssign(corto_container _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return _this;
}

corto_string _corto_containerStr(corto_container value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_container_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_container corto_containerFromStr(corto_container value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_container_o), str);
    return value;
}

corto_equalityKind _corto_containerCompare(corto_container dst, corto_container src) {
    return corto_compare(dst, src);
}

corto_default _corto_defaultCreate(corto_type type) {
    corto_default _this;
    _this = corto_default(corto_declare(corto_default_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_default _corto_defaultCreateChild(corto_object _parent, corto_string _id, corto_type type) {
    corto_default _this;
    _this = corto_default(corto_declareChild(_parent, _id, corto_default_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_member)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_defaultUpdate(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_member)((corto_default)CORTO_OFFSET(_this, ((corto_type)corto_default_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_member)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_default _corto_defaultDeclare(void) {
    corto_default _this;
    _this = corto_default(corto_declare(corto_default_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_default _corto_defaultDeclareChild(corto_object _parent, corto_string _id) {
    corto_default _this;
    _this = corto_default(corto_declareChild(_parent, _id, corto_default_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_defaultDefine(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_member)_this)->type, type);
    return corto_define(_this);
}

corto_default _corto_defaultAssign(corto_default _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_member)_this)->type, type);
    return _this;
}

corto_string _corto_defaultStr(corto_default value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_default_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_default corto_defaultFromStr(corto_default value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_default_o), str);
    return value;
}

corto_equalityKind _corto_defaultCompare(corto_default dst, corto_default src) {
    return corto_compare(dst, src);
}

corto_delegate _corto_delegateCreate(corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = corto_delegate(corto_declare(corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegate)_this)->returnType, returnType);
        ((corto_delegate)_this)->returnsReference = returnsReference;
        corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_delegate _corto_delegateCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = corto_delegate(corto_declareChild(_parent, _id, corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegate)_this)->returnType, returnType);
        ((corto_delegate)_this)->returnsReference = returnsReference;
        corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->returnType, returnType);
            ((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->returnsReference = returnsReference;
            corto_copyp(&((corto_delegate)((corto_delegate)CORTO_OFFSET(_this, ((corto_type)corto_delegate_o)->size)))->parameters, corto_parameterseq_o, &parameters);
        } else {
            corto_setref(&((corto_delegate)_this)->returnType, returnType);
            ((corto_delegate)_this)->returnsReference = returnsReference;
            corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_delegate _corto_delegateDeclare(void) {
    corto_delegate _this;
    _this = corto_delegate(corto_declare(corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_delegate _corto_delegateDeclareChild(corto_object _parent, corto_string _id) {
    corto_delegate _this;
    _this = corto_delegate(corto_declareChild(_parent, _id, corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return corto_define(_this);
}

corto_delegate _corto_delegateAssign(corto_delegate _this, corto_type returnType, bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return _this;
}

corto_string _corto_delegateStr(corto_delegate value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_delegate_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_delegate corto_delegateFromStr(corto_delegate value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_delegate_o), str);
    return value;
}

corto_equalityKind _corto_delegateCompare(corto_delegate dst, corto_delegate src) {
    return corto_compare(dst, src);
}

corto_delegatedata* _corto_delegatedataCreate(corto_object instance, corto_function procedure) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declare(corto_delegatedata_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declareChild(_parent, _id, corto_delegatedata_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_delegatedata*)((corto_delegatedata*)CORTO_OFFSET(_this, ((corto_type)corto_delegatedata_o)->size)))->instance, instance);
            corto_setref(&((corto_delegatedata*)((corto_delegatedata*)CORTO_OFFSET(_this, ((corto_type)corto_delegatedata_o)->size)))->procedure, procedure);
        } else {
            corto_setref(&((corto_delegatedata*)_this)->instance, instance);
            corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_delegatedata* _corto_delegatedataDeclare(void) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declare(corto_delegatedata_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, corto_string _id) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declareChild(_parent, _id, corto_delegatedata_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_delegatedata* _corto_delegatedataAssign(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_string _corto_delegatedataStr(corto_delegatedata* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_delegatedata_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_delegatedata* corto_delegatedataFromStr(corto_delegatedata* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_delegatedata_o), str);
    return value;
}

corto_equalityKind corto_delegatedataCompare(corto_delegatedata* dst, corto_delegatedata* src) {
    return corto_comparep(dst, corto_delegatedata_o, src);
}

corto_int16 _corto_delegatedataInit(corto_delegatedata* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_delegatedata_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_delegatedata_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_delegatedataDeinit(corto_delegatedata* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_delegatedata_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_destructAction* _corto_destructActionCreate(corto_object instance, corto_function procedure) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declare(corto_destructAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_destructAction* _corto_destructActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declareChild(_parent, _id, corto_destructAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_delegatedata*)((corto_destructAction*)CORTO_OFFSET(_this, ((corto_type)corto_destructAction_o)->size)))->instance, instance);
            corto_setref(&((corto_delegatedata*)((corto_destructAction*)CORTO_OFFSET(_this, ((corto_type)corto_destructAction_o)->size)))->procedure, procedure);
        } else {
            corto_setref(&((corto_delegatedata*)_this)->instance, instance);
            corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_destructAction* _corto_destructActionDeclare(void) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declare(corto_destructAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_destructAction* _corto_destructActionDeclareChild(corto_object _parent, corto_string _id) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declareChild(_parent, _id, corto_destructAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_destructActionDefine(corto_destructAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_destructAction* _corto_destructActionAssign(corto_destructAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_string _corto_destructActionStr(corto_destructAction* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_destructAction_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_destructAction* corto_destructActionFromStr(corto_destructAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_destructAction_o), str);
    return value;
}

corto_equalityKind corto_destructActionCompare(corto_destructAction* dst, corto_destructAction* src) {
    return corto_comparep(dst, corto_destructAction_o, src);
}

corto_int16 _corto_destructActionInit(corto_destructAction* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_destructAction_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_destructAction_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_destructActionDeinit(corto_destructAction* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_destructAction_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int16 corto_destructActionCall(corto_destructAction *_delegate) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_call(_delegate->super.procedure, NULL, _delegate->super.instance);
        } else {
            corto_call(_delegate->super.procedure, NULL);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_destructActionInitC(corto_destructAction *d, corto_void ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_destructActionInitCInstance(corto_destructAction *d, corto_object instance, corto_void ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_enum _corto_enumCreate(void) {
    corto_enum _this;
    _this = corto_enum(corto_declare(corto_enum_o));
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

corto_enum _corto_enumCreateChild(corto_object _parent, corto_string _id) {
    corto_enum _this;
    _this = corto_enum(corto_declareChild(_parent, _id, corto_enum_o));
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

corto_int16 _corto_enumUpdate(corto_enum _this) {
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

corto_enum _corto_enumDeclare(void) {
    corto_enum _this;
    _this = corto_enum(corto_declare(corto_enum_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_enum _corto_enumDeclareChild(corto_object _parent, corto_string _id) {
    corto_enum _this;
    _this = corto_enum(corto_declareChild(_parent, _id, corto_enum_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_enumDefine(corto_enum _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

corto_enum _corto_enumAssign(corto_enum _this) {
    CORTO_UNUSED(_this);
    return _this;
}

corto_string _corto_enumStr(corto_enum value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_enum_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_enum corto_enumFromStr(corto_enum value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_enum_o), str);
    return value;
}

corto_equalityKind _corto_enumCompare(corto_enum dst, corto_enum src) {
    return corto_compare(dst, src);
}

corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declare(corto_equalityKind_o));
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

corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _id, corto_equalityKind value) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declareChild(_parent, _id, corto_equalityKind_o));
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

corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_equalityKind*)CORTO_OFFSET(_this, ((corto_type)corto_equalityKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_equalityKind* _corto_equalityKindDeclare(void) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declare(corto_equalityKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declareChild(_parent, _id, corto_equalityKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_equalityKind* _corto_equalityKindAssign(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_equalityKindStr(corto_equalityKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_equalityKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_equalityKind* corto_equalityKindFromStr(corto_equalityKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_equalityKind_o), str);
    return value;
}

corto_equalityKind corto_equalityKindCompare(corto_equalityKind dst, corto_equalityKind src) {
    return corto_comparep(&dst, corto_equalityKind_o, &src);
}

corto_int16 _corto_equalityKindInit(corto_equalityKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_equalityKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_equalityKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_equalityKindDeinit(corto_equalityKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_equalityKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_float _corto_floatCreate(corto_width width, double min, double max) {
    corto_float _this;
    _this = corto_float(corto_declare(corto_float_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_float)_this)->min = min;
        ((corto_float)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_float _corto_floatCreateChild(corto_object _parent, corto_string _id, corto_width width, double min, double max) {
    corto_float _this;
    _this = corto_float(corto_declareChild(_parent, _id, corto_float_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_float)_this)->min = min;
        ((corto_float)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->width = width;
            ((corto_float)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->min = min;
            ((corto_float)((corto_float)CORTO_OFFSET(_this, ((corto_type)corto_float_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_float)_this)->min = min;
            ((corto_float)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_float _corto_floatDeclare(void) {
    corto_float _this;
    _this = corto_float(corto_declare(corto_float_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_float _corto_floatDeclareChild(corto_object _parent, corto_string _id) {
    corto_float _this;
    _this = corto_float(corto_declareChild(_parent, _id, corto_float_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_floatDefine(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return corto_define(_this);
}

corto_float _corto_floatAssign(corto_float _this, corto_width width, double min, double max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return _this;
}

corto_string _corto_floatStr(corto_float value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_float_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_float corto_floatFromStr(corto_float value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_float_o), str);
    return value;
}

corto_equalityKind _corto_floatCompare(corto_float dst, corto_float src) {
    return corto_compare(dst, src);
}

float* _corto_float32Create(float value) {
    float* _this;
    _this = corto_float32(corto_declare(corto_float32_o));
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

float* _corto_float32CreateChild(corto_object _parent, corto_string _id, float value) {
    float* _this;
    _this = corto_float32(corto_declareChild(_parent, _id, corto_float32_o));
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

corto_int16 _corto_float32Update(float* _this, float value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((float*)CORTO_OFFSET(_this, ((corto_type)corto_float32_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

float* _corto_float32Declare(void) {
    float* _this;
    _this = corto_float32(corto_declare(corto_float32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

float* _corto_float32DeclareChild(corto_object _parent, corto_string _id) {
    float* _this;
    _this = corto_float32(corto_declareChild(_parent, _id, corto_float32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float32Define(float* _this, float value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

float* _corto_float32Assign(float* _this, float value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_float32Str(corto_float32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

float* corto_float32FromStr(float* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_float32_o), str);
    return value;
}

corto_equalityKind corto_float32Compare(corto_float32 dst, corto_float32 src) {
    return corto_comparep(&dst, corto_float32_o, &src);
}

corto_int16 _corto_float32Init(corto_float32* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_float32_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_float32_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_float32Deinit(corto_float32* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float32_o), value);
    result = corto_deinitv(&v);
    return result;
}

double* _corto_float64Create(double value) {
    double* _this;
    _this = corto_float64(corto_declare(corto_float64_o));
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

double* _corto_float64CreateChild(corto_object _parent, corto_string _id, double value) {
    double* _this;
    _this = corto_float64(corto_declareChild(_parent, _id, corto_float64_o));
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

corto_int16 _corto_float64Update(double* _this, double value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((double*)CORTO_OFFSET(_this, ((corto_type)corto_float64_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

double* _corto_float64Declare(void) {
    double* _this;
    _this = corto_float64(corto_declare(corto_float64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

double* _corto_float64DeclareChild(corto_object _parent, corto_string _id) {
    double* _this;
    _this = corto_float64(corto_declareChild(_parent, _id, corto_float64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float64Define(double* _this, double value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

double* _corto_float64Assign(double* _this, double value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_float64Str(corto_float64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

double* corto_float64FromStr(double* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_float64_o), str);
    return value;
}

corto_equalityKind corto_float64Compare(corto_float64 dst, corto_float64 src) {
    return corto_comparep(&dst, corto_float64_o, &src);
}

corto_int16 _corto_float64Init(corto_float64* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_float64_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_float64_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_float64Deinit(corto_float64* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float64_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_function _corto_functionCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_function _this;
    _this = corto_function(corto_declare(corto_function_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_function _corto_functionCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_function _this;
    _this = corto_function(corto_declareChild(_parent, _id, corto_function_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->returnType, returnType);
            ((corto_function)((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_function)CORTO_OFFSET(_this, ((corto_type)corto_function_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_function _corto_functionDeclare(void) {
    corto_function _this;
    _this = corto_function(corto_declare(corto_function_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_function _corto_functionDeclareChild(corto_object _parent, corto_string _id) {
    corto_function _this;
    _this = corto_function(corto_declareChild(_parent, _id, corto_function_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_function _corto_functionAssign(corto_function _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_functionStr(corto_function value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_function_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_function corto_functionFromStr(corto_function value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_function_o), str);
    return value;
}

corto_equalityKind _corto_functionCompare(corto_function dst, corto_function src) {
    return corto_compare(dst, src);
}

corto_initAction* _corto_initActionCreate(corto_object instance, corto_function procedure) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declare(corto_initAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_initAction* _corto_initActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declareChild(_parent, _id, corto_initAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_delegatedata*)((corto_initAction*)CORTO_OFFSET(_this, ((corto_type)corto_initAction_o)->size)))->instance, instance);
            corto_setref(&((corto_delegatedata*)((corto_initAction*)CORTO_OFFSET(_this, ((corto_type)corto_initAction_o)->size)))->procedure, procedure);
        } else {
            corto_setref(&((corto_delegatedata*)_this)->instance, instance);
            corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_initAction* _corto_initActionDeclare(void) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declare(corto_initAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_initAction* _corto_initActionDeclareChild(corto_object _parent, corto_string _id) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declareChild(_parent, _id, corto_initAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_initActionDefine(corto_initAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_initAction* _corto_initActionAssign(corto_initAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_string _corto_initActionStr(corto_initAction* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_initAction_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_initAction* corto_initActionFromStr(corto_initAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_initAction_o), str);
    return value;
}

corto_equalityKind corto_initActionCompare(corto_initAction* dst, corto_initAction* src) {
    return corto_comparep(dst, corto_initAction_o, src);
}

corto_int16 _corto_initActionInit(corto_initAction* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_initAction_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_initAction_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_initActionDeinit(corto_initAction* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_initAction_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int16 corto_initActionCall(corto_initAction *_delegate, corto_int16* _result) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_call(_delegate->super.procedure, _result, _delegate->super.instance);
        } else {
            corto_call(_delegate->super.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_initActionInitC(corto_initAction *d, corto_int16 ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_initActionInitCInstance(corto_initAction *d, corto_object instance, corto_int16 ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_inout* _corto_inoutCreate(corto_inout value) {
    corto_inout* _this;
    _this = corto_inout(corto_declare(corto_inout_o));
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

corto_inout* _corto_inoutCreateChild(corto_object _parent, corto_string _id, corto_inout value) {
    corto_inout* _this;
    _this = corto_inout(corto_declareChild(_parent, _id, corto_inout_o));
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

corto_int16 _corto_inoutUpdate(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_inout*)CORTO_OFFSET(_this, ((corto_type)corto_inout_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_inout* _corto_inoutDeclare(void) {
    corto_inout* _this;
    _this = corto_inout(corto_declare(corto_inout_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_inout* _corto_inoutDeclareChild(corto_object _parent, corto_string _id) {
    corto_inout* _this;
    _this = corto_inout(corto_declareChild(_parent, _id, corto_inout_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_inoutDefine(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_inout* _corto_inoutAssign(corto_inout* _this, corto_inout value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_inoutStr(corto_inout value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_inout_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_inout* corto_inoutFromStr(corto_inout* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_inout_o), str);
    return value;
}

corto_equalityKind corto_inoutCompare(corto_inout dst, corto_inout src) {
    return corto_comparep(&dst, corto_inout_o, &src);
}

corto_int16 _corto_inoutInit(corto_inout* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_inout_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_inout_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_inoutDeinit(corto_inout* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_inout_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int _corto_intCreate(corto_width width, int64_t min, int64_t max) {
    corto_int _this;
    _this = corto_int(corto_declare(corto_int_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_int)_this)->min = min;
        ((corto_int)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int _corto_intCreateChild(corto_object _parent, corto_string _id, corto_width width, int64_t min, int64_t max) {
    corto_int _this;
    _this = corto_int(corto_declareChild(_parent, _id, corto_int_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_int)_this)->min = min;
        ((corto_int)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_intUpdate(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->width = width;
            ((corto_int)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->min = min;
            ((corto_int)((corto_int)CORTO_OFFSET(_this, ((corto_type)corto_int_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_int)_this)->min = min;
            ((corto_int)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int _corto_intDeclare(void) {
    corto_int _this;
    _this = corto_int(corto_declare(corto_int_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int _corto_intDeclareChild(corto_object _parent, corto_string _id) {
    corto_int _this;
    _this = corto_int(corto_declareChild(_parent, _id, corto_int_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_intDefine(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return corto_define(_this);
}

corto_int _corto_intAssign(corto_int _this, corto_width width, int64_t min, int64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return _this;
}

corto_string _corto_intStr(corto_int value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_int_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_int corto_intFromStr(corto_int value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int_o), str);
    return value;
}

corto_equalityKind _corto_intCompare(corto_int dst, corto_int src) {
    return corto_compare(dst, src);
}

int16_t* _corto_int16Create(int16_t value) {
    int16_t* _this;
    _this = corto_int16(corto_declare(corto_int16_o));
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

int16_t* _corto_int16CreateChild(corto_object _parent, corto_string _id, int16_t value) {
    int16_t* _this;
    _this = corto_int16(corto_declareChild(_parent, _id, corto_int16_o));
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

corto_int16 _corto_int16Update(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int16_t*)CORTO_OFFSET(_this, ((corto_type)corto_int16_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

int16_t* _corto_int16Declare(void) {
    int16_t* _this;
    _this = corto_int16(corto_declare(corto_int16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

int16_t* _corto_int16DeclareChild(corto_object _parent, corto_string _id) {
    int16_t* _this;
    _this = corto_int16(corto_declareChild(_parent, _id, corto_int16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int16Define(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int16_t* _corto_int16Assign(int16_t* _this, int16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_int16Str(corto_int16 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int16_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

int16_t* corto_int16FromStr(int16_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int16_o), str);
    return value;
}

corto_equalityKind corto_int16Compare(corto_int16 dst, corto_int16 src) {
    return corto_comparep(&dst, corto_int16_o, &src);
}

corto_int16 _corto_int16Init(corto_int16* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_int16_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_int16_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_int16Deinit(corto_int16* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int16_o), value);
    result = corto_deinitv(&v);
    return result;
}

int32_t* _corto_int32Create(int32_t value) {
    int32_t* _this;
    _this = corto_int32(corto_declare(corto_int32_o));
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

int32_t* _corto_int32CreateChild(corto_object _parent, corto_string _id, int32_t value) {
    int32_t* _this;
    _this = corto_int32(corto_declareChild(_parent, _id, corto_int32_o));
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

corto_int16 _corto_int32Update(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int32_t*)CORTO_OFFSET(_this, ((corto_type)corto_int32_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

int32_t* _corto_int32Declare(void) {
    int32_t* _this;
    _this = corto_int32(corto_declare(corto_int32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

int32_t* _corto_int32DeclareChild(corto_object _parent, corto_string _id) {
    int32_t* _this;
    _this = corto_int32(corto_declareChild(_parent, _id, corto_int32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int32Define(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int32_t* _corto_int32Assign(int32_t* _this, int32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_int32Str(corto_int32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

int32_t* corto_int32FromStr(int32_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int32_o), str);
    return value;
}

corto_equalityKind corto_int32Compare(corto_int32 dst, corto_int32 src) {
    return corto_comparep(&dst, corto_int32_o, &src);
}

corto_int16 _corto_int32Init(corto_int32* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_int32_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_int32_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_int32Deinit(corto_int32* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int32_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int32seq* _corto_int32seqCreate(corto_uint32 length, corto_int32* elements) {
    corto_int32seq* _this;
    _this = corto_int32seq(corto_declare(corto_int32seq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_int32seqSize(_this, length);
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

corto_int32seq* _corto_int32seqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32* elements) {
    corto_int32seq* _this;
    _this = corto_int32seq(corto_declareChild(_parent, _id, corto_int32seq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_int32seqSize(_this, length);
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

corto_int16 _corto_int32seqUpdate(corto_int32seq* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_int32seqSize(((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_int32seq*)CORTO_OFFSET(_this, ((corto_type)corto_int32seq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_int32seqSize(_this, length);
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

corto_int32seq* _corto_int32seqDeclare(void) {
    corto_int32seq* _this;
    _this = corto_int32seq(corto_declare(corto_int32seq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int32seq* _corto_int32seqDeclareChild(corto_object _parent, corto_string _id) {
    corto_int32seq* _this;
    _this = corto_int32seq(corto_declareChild(_parent, _id, corto_int32seq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int32seqDefine(corto_int32seq* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_int32seqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

corto_int32seq* _corto_int32seqAssign(corto_int32seq* _this, corto_uint32 length, corto_int32* elements) {
    CORTO_UNUSED(_this);
    corto_int32seqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

corto_string _corto_int32seqStr(corto_int32seq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int32seq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int32seq* corto_int32seqFromStr(corto_int32seq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int32seq_o), str);
    return value;
}

corto_equalityKind corto_int32seqCompare(corto_int32seq dst, corto_int32seq src) {
    return corto_comparep(&dst, corto_int32seq_o, &src);
}

corto_int16 _corto_int32seqInit(corto_int32seq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_int32seq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_int32seq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_int32seqDeinit(corto_int32seq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int32seq_o), value);
    result = corto_deinitv(&v);
    return result;
}

int64_t* _corto_int64Create(int64_t value) {
    int64_t* _this;
    _this = corto_int64(corto_declare(corto_int64_o));
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

int64_t* _corto_int64CreateChild(corto_object _parent, corto_string _id, int64_t value) {
    int64_t* _this;
    _this = corto_int64(corto_declareChild(_parent, _id, corto_int64_o));
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

corto_int16 _corto_int64Update(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int64_t*)CORTO_OFFSET(_this, ((corto_type)corto_int64_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

int64_t* _corto_int64Declare(void) {
    int64_t* _this;
    _this = corto_int64(corto_declare(corto_int64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

int64_t* _corto_int64DeclareChild(corto_object _parent, corto_string _id) {
    int64_t* _this;
    _this = corto_int64(corto_declareChild(_parent, _id, corto_int64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int64Define(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int64_t* _corto_int64Assign(int64_t* _this, int64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_int64Str(corto_int64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

int64_t* corto_int64FromStr(int64_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int64_o), str);
    return value;
}

corto_equalityKind corto_int64Compare(corto_int64 dst, corto_int64 src) {
    return corto_comparep(&dst, corto_int64_o, &src);
}

corto_int16 _corto_int64Init(corto_int64* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_int64_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_int64_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_int64Deinit(corto_int64* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int64_o), value);
    result = corto_deinitv(&v);
    return result;
}

int8_t* _corto_int8Create(int8_t value) {
    int8_t* _this;
    _this = corto_int8(corto_declare(corto_int8_o));
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

int8_t* _corto_int8CreateChild(corto_object _parent, corto_string _id, int8_t value) {
    int8_t* _this;
    _this = corto_int8(corto_declareChild(_parent, _id, corto_int8_o));
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

corto_int16 _corto_int8Update(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((int8_t*)CORTO_OFFSET(_this, ((corto_type)corto_int8_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

int8_t* _corto_int8Declare(void) {
    int8_t* _this;
    _this = corto_int8(corto_declare(corto_int8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

int8_t* _corto_int8DeclareChild(corto_object _parent, corto_string _id) {
    int8_t* _this;
    _this = corto_int8(corto_declareChild(_parent, _id, corto_int8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int8Define(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

int8_t* _corto_int8Assign(int8_t* _this, int8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_int8Str(corto_int8 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int8_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

int8_t* corto_int8FromStr(int8_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_int8_o), str);
    return value;
}

corto_equalityKind corto_int8Compare(corto_int8 dst, corto_int8 src) {
    return corto_comparep(&dst, corto_int8_o, &src);
}

corto_int16 _corto_int8Init(corto_int8* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_int8_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_int8_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_int8Deinit(corto_int8* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int8_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_interface _corto_interfaceCreate(corto_interface base) {
    corto_interface _this;
    _this = corto_interface(corto_declare(corto_interface_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interface _corto_interfaceCreateChild(corto_object _parent, corto_string _id, corto_interface base) {
    corto_interface _this;
    _this = corto_interface(corto_declareChild(_parent, _id, corto_interface_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_interface)CORTO_OFFSET(_this, ((corto_type)corto_interface_o)->size)))->base, base);
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_interface _corto_interfaceDeclare(void) {
    corto_interface _this;
    _this = corto_interface(corto_declare(corto_interface_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interface _corto_interfaceDeclareChild(corto_object _parent, corto_string _id) {
    corto_interface _this;
    _this = corto_interface(corto_declareChild(_parent, _id, corto_interface_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceDefine(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    return corto_define(_this);
}

corto_interface _corto_interfaceAssign(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    return _this;
}

corto_string _corto_interfaceStr(corto_interface value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_interface_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_interface corto_interfaceFromStr(corto_interface value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_interface_o), str);
    return value;
}

corto_equalityKind _corto_interfaceCompare(corto_interface dst, corto_interface src) {
    return corto_compare(dst, src);
}

corto_interfaceseq* _corto_interfaceseqCreate(corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declare(corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_interfaceseqSize(_this, length);
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

corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declareChild(_parent, _id, corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_interfaceseqSize(_this, length);
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

corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceseqSize(((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&((corto_interfaceseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_interfaceseqSize(_this, length);
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

corto_interfaceseq* _corto_interfaceseqDeclare(void) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declare(corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declareChild(_parent, _id, corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceseqDefine(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_interfaceseq* _corto_interfaceseqAssign(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _corto_interfaceseqStr(corto_interfaceseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_interfaceseq* corto_interfaceseqFromStr(corto_interfaceseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_interfaceseq_o), str);
    return value;
}

corto_equalityKind corto_interfaceseqCompare(corto_interfaceseq dst, corto_interfaceseq src) {
    return corto_comparep(&dst, corto_interfaceseq_o, &src);
}

corto_int16 _corto_interfaceseqInit(corto_interfaceseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_interfaceseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_interfaceseqDeinit(corto_interfaceseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_objectseq vector) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declare(corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
        corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, corto_string _id, corto_interface interface, corto_objectseq vector) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declareChild(_parent, _id, corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
        corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interfaceVector*)((corto_interfaceVector*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVector_o)->size)))->interface, interface);
            corto_copyp(&((corto_interfaceVector*)((corto_interfaceVector*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVector_o)->size)))->vector, corto_objectseq_o, &vector);
        } else {
            corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
            corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_interfaceVector* _corto_interfaceVectorDeclare(void) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declare(corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _id) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declareChild(_parent, _id, corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
    return corto_define(_this);
}

corto_interfaceVector* _corto_interfaceVectorAssign(corto_interfaceVector* _this, corto_interface interface, corto_objectseq vector) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_objectseq_o, &vector);
    return _this;
}

corto_string _corto_interfaceVectorStr(corto_interfaceVector* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVector_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_interfaceVector* corto_interfaceVectorFromStr(corto_interfaceVector* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_interfaceVector_o), str);
    return value;
}

corto_equalityKind corto_interfaceVectorCompare(corto_interfaceVector* dst, corto_interfaceVector* src) {
    return corto_comparep(dst, corto_interfaceVector_o, src);
}

corto_int16 _corto_interfaceVectorInit(corto_interfaceVector* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_interfaceVector_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVector_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_interfaceVectorDeinit(corto_interfaceVector* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVector_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqCreate(corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declare(corto_interfaceVectorseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_interfaceVectorseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declareChild(_parent, _id, corto_interfaceVectorseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_interfaceVectorseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_interfaceVectorseqSize(((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&((corto_interfaceVectorseq*)CORTO_OFFSET(_this, ((corto_type)corto_interfaceVectorseq_o)->size))->buffer[i], corto_interfaceVector_o, &elements[i]);
                }
            }
        } else {
            corto_interfaceVectorseqSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
                }
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqDeclare(void) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declare(corto_interfaceVectorseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declareChild(_parent, _id, corto_interfaceVectorseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

corto_interfaceVectorseq* _corto_interfaceVectorseqAssign(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
        }
    }
    return _this;
}

corto_string _corto_interfaceVectorseqStr(corto_interfaceVectorseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVectorseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_interfaceVectorseq* corto_interfaceVectorseqFromStr(corto_interfaceVectorseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_interfaceVectorseq_o), str);
    return value;
}

corto_equalityKind corto_interfaceVectorseqCompare(corto_interfaceVectorseq dst, corto_interfaceVectorseq src) {
    return corto_comparep(&dst, corto_interfaceVectorseq_o, &src);
}

corto_int16 _corto_interfaceVectorseqInit(corto_interfaceVectorseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_interfaceVectorseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVectorseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_interfaceVectorseqDeinit(corto_interfaceVectorseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_interfaceVectorseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_iterator _corto_iteratorCreate(corto_type elementType) {
    corto_iterator _this;
    _this = corto_iterator(corto_declare(corto_iterator_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_iterator)_this)->elementType, elementType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_iterator _corto_iteratorCreateChild(corto_object _parent, corto_string _id, corto_type elementType) {
    corto_iterator _this;
    _this = corto_iterator(corto_declareChild(_parent, _id, corto_iterator_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_iterator)_this)->elementType, elementType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_iterator)((corto_iterator)CORTO_OFFSET(_this, ((corto_type)corto_iterator_o)->size)))->elementType, elementType);
        } else {
            corto_setref(&((corto_iterator)_this)->elementType, elementType);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_iterator _corto_iteratorDeclare(void) {
    corto_iterator _this;
    _this = corto_iterator(corto_declare(corto_iterator_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_iterator _corto_iteratorDeclareChild(corto_object _parent, corto_string _id) {
    corto_iterator _this;
    _this = corto_iterator(corto_declareChild(_parent, _id, corto_iterator_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_iteratorDefine(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_iterator)_this)->elementType, elementType);
    return corto_define(_this);
}

corto_iterator _corto_iteratorAssign(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_iterator)_this)->elementType, elementType);
    return _this;
}

corto_string _corto_iteratorStr(corto_iterator value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_iterator_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_iterator corto_iteratorFromStr(corto_iterator value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_iterator_o), str);
    return value;
}

corto_equalityKind _corto_iteratorCompare(corto_iterator dst, corto_iterator src) {
    return corto_compare(dst, src);
}

corto_leaf _corto_leafCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_leaf _this;
    _this = corto_leaf(corto_declare(corto_leaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_leaf _corto_leafCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_leaf _this;
    _this = corto_leaf(corto_declareChild(_parent, _id, corto_leaf_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_leafUpdate(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->base, base);
            ((corto_struct)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->baseAccess = baseAccess;
            corto_copyp(&((corto_class)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)((corto_leaf)CORTO_OFFSET(_this, ((corto_type)corto_leaf_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_leaf _corto_leafDeclare(void) {
    corto_leaf _this;
    _this = corto_leaf(corto_declare(corto_leaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_leaf _corto_leafDeclareChild(corto_object _parent, corto_string _id) {
    corto_leaf _this;
    _this = corto_leaf(corto_declareChild(_parent, _id, corto_leaf_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_leafDefine(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return corto_define(_this);
}

corto_leaf _corto_leafAssign(corto_leaf _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return _this;
}

corto_string _corto_leafStr(corto_leaf value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_leaf_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_leaf corto_leafFromStr(corto_leaf value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_leaf_o), str);
    return value;
}

corto_equalityKind _corto_leafCompare(corto_leaf dst, corto_leaf src) {
    return corto_compare(dst, src);
}

corto_list _corto_listCreate(corto_type elementType, uint32_t max) {
    corto_list _this;
    _this = corto_list(corto_declare(corto_list_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_list _corto_listCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max) {
    corto_list _this;
    _this = corto_list(corto_declareChild(_parent, _id, corto_list_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_list)CORTO_OFFSET(_this, ((corto_type)corto_list_o)->size)))->max = max;
        } else {
            corto_setref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_list _corto_listDeclare(void) {
    corto_list _this;
    _this = corto_list(corto_declare(corto_list_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_list _corto_listDeclareChild(corto_object _parent, corto_string _id) {
    corto_list _this;
    _this = corto_list(corto_declareChild(_parent, _id, corto_list_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_list _corto_listAssign(corto_list _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_string _corto_listStr(corto_list value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_list_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_list corto_listFromStr(corto_list value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_list_o), str);
    return value;
}

corto_equalityKind _corto_listCompare(corto_list dst, corto_list src) {
    return corto_compare(dst, src);
}

corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, uint32_t max) {
    corto_map _this;
    _this = corto_map(corto_declare(corto_map_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_map)_this)->elementType, elementType);
        corto_setref(&((corto_map)_this)->keyType, keyType);
        ((corto_map)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_map _corto_mapCreateChild(corto_object _parent, corto_string _id, corto_type elementType, corto_type keyType, uint32_t max) {
    corto_map _this;
    _this = corto_map(corto_declareChild(_parent, _id, corto_map_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_map)_this)->elementType, elementType);
        corto_setref(&((corto_map)_this)->keyType, keyType);
        ((corto_map)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->elementType, elementType);
            corto_setref(&((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->keyType, keyType);
            ((corto_map)((corto_map)CORTO_OFFSET(_this, ((corto_type)corto_map_o)->size)))->max = max;
        } else {
            corto_setref(&((corto_map)_this)->elementType, elementType);
            corto_setref(&((corto_map)_this)->keyType, keyType);
            ((corto_map)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_map _corto_mapDeclare(void) {
    corto_map _this;
    _this = corto_map(corto_declare(corto_map_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_map _corto_mapDeclareChild(corto_object _parent, corto_string _id) {
    corto_map _this;
    _this = corto_map(corto_declareChild(_parent, _id, corto_map_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    return corto_define(_this);
}

corto_map _corto_mapAssign(corto_map _this, corto_type elementType, corto_type keyType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    return _this;
}

corto_string _corto_mapStr(corto_map value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_map_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_map corto_mapFromStr(corto_map value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_map_o), str);
    return value;
}

corto_equalityKind _corto_mapCompare(corto_map dst, corto_map src) {
    return corto_compare(dst, src);
}

corto_member _corto_memberCreate(corto_type type, corto_modifier modifiers) {
    corto_member _this;
    _this = corto_member(corto_declare(corto_member_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_member _corto_memberCreateChild(corto_object _parent, corto_string _id, corto_type type, corto_modifier modifiers) {
    corto_member _this;
    _this = corto_member(corto_declareChild(_parent, _id, corto_member_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_member)((corto_member)CORTO_OFFSET(_this, ((corto_type)corto_member_o)->size)))->type, type);
            ((corto_member)((corto_member)CORTO_OFFSET(_this, ((corto_type)corto_member_o)->size)))->modifiers = modifiers;
        } else {
            corto_setref(&((corto_member)_this)->type, type);
            ((corto_member)_this)->modifiers = modifiers;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_member _corto_memberDeclare(void) {
    corto_member _this;
    _this = corto_member(corto_declare(corto_member_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_member _corto_memberDeclareChild(corto_object _parent, corto_string _id) {
    corto_member _this;
    _this = corto_member(corto_declareChild(_parent, _id, corto_member_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return corto_define(_this);
}

corto_member _corto_memberAssign(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    return _this;
}

corto_string _corto_memberStr(corto_member value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_member_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_member corto_memberFromStr(corto_member value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_member_o), str);
    return value;
}

corto_equalityKind _corto_memberCompare(corto_member dst, corto_member src) {
    return corto_compare(dst, src);
}

corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declare(corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declareChild(_parent, _id, corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->returnType, returnType);
            ((corto_function)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->returnsReference = returnsReference;
            ((corto_metaprocedure)((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->referenceOnly = referenceOnly;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_metaprocedure)CORTO_OFFSET(_this, ((corto_type)corto_metaprocedure_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_metaprocedure _corto_metaprocedureDeclare(void) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declare(corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, corto_string _id) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declareChild(_parent, _id, corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_metaprocedure _corto_metaprocedureAssign(corto_metaprocedure _this, corto_type returnType, bool returnsReference, bool referenceOnly, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_metaprocedureStr(corto_metaprocedure value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_metaprocedure_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_metaprocedure corto_metaprocedureFromStr(corto_metaprocedure value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_metaprocedure_o), str);
    return value;
}

corto_equalityKind _corto_metaprocedureCompare(corto_metaprocedure dst, corto_metaprocedure src) {
    return corto_compare(dst, src);
}

corto_method _corto_methodCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_method _this;
    _this = corto_method(corto_declare(corto_method_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_method _corto_methodCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_method _this;
    _this = corto_method(corto_declareChild(_parent, _id, corto_method_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->returnType, returnType);
            ((corto_function)((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_method)CORTO_OFFSET(_this, ((corto_type)corto_method_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_method _corto_methodDeclare(void) {
    corto_method _this;
    _this = corto_method(corto_declare(corto_method_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_method _corto_methodDeclareChild(corto_object _parent, corto_string _id) {
    corto_method _this;
    _this = corto_method(corto_declareChild(_parent, _id, corto_method_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_method _corto_methodAssign(corto_method _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_methodStr(corto_method value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_method_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_method corto_methodFromStr(corto_method value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_method_o), str);
    return value;
}

corto_equalityKind _corto_methodCompare(corto_method dst, corto_method src) {
    return corto_compare(dst, src);
}

corto_modifier* _corto_modifierCreate(corto_modifier value) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declare(corto_modifier_o));
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

corto_modifier* _corto_modifierCreateChild(corto_object _parent, corto_string _id, corto_modifier value) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declareChild(_parent, _id, corto_modifier_o));
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

corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_modifier*)CORTO_OFFSET(_this, ((corto_type)corto_modifier_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_modifier* _corto_modifierDeclare(void) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declare(corto_modifier_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_modifier* _corto_modifierDeclareChild(corto_object _parent, corto_string _id) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declareChild(_parent, _id, corto_modifier_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_modifierDefine(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_modifier* _corto_modifierAssign(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_modifierStr(corto_modifier value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_modifier_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_modifier* corto_modifierFromStr(corto_modifier* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_modifier_o), str);
    return value;
}

corto_equalityKind corto_modifierCompare(corto_modifier dst, corto_modifier src) {
    return corto_comparep(&dst, corto_modifier_o, &src);
}

corto_int16 _corto_modifierInit(corto_modifier* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_modifier_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_modifier_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_modifierDeinit(corto_modifier* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_modifier_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_nameAction* _corto_nameActionCreate(corto_object instance, corto_function procedure) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declare(corto_nameAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_nameAction* _corto_nameActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declareChild(_parent, _id, corto_nameAction_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_delegatedata*)_this)->instance, instance);
        corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_nameActionUpdate(corto_nameAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_delegatedata*)((corto_nameAction*)CORTO_OFFSET(_this, ((corto_type)corto_nameAction_o)->size)))->instance, instance);
            corto_setref(&((corto_delegatedata*)((corto_nameAction*)CORTO_OFFSET(_this, ((corto_type)corto_nameAction_o)->size)))->procedure, procedure);
        } else {
            corto_setref(&((corto_delegatedata*)_this)->instance, instance);
            corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_nameAction* _corto_nameActionDeclare(void) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declare(corto_nameAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_nameAction* _corto_nameActionDeclareChild(corto_object _parent, corto_string _id) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declareChild(_parent, _id, corto_nameAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_nameActionDefine(corto_nameAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return corto_define(_this);
}

corto_nameAction* _corto_nameActionAssign(corto_nameAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    return _this;
}

corto_string _corto_nameActionStr(corto_nameAction* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_nameAction_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_nameAction* corto_nameActionFromStr(corto_nameAction* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_nameAction_o), str);
    return value;
}

corto_equalityKind corto_nameActionCompare(corto_nameAction* dst, corto_nameAction* src) {
    return corto_comparep(dst, corto_nameAction_o, src);
}

corto_int16 _corto_nameActionInit(corto_nameAction* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_nameAction_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_nameAction_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_nameActionDeinit(corto_nameAction* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_nameAction_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_int16 corto_nameActionCall(corto_nameAction *_delegate, corto_string* _result) {
    if (_delegate->super.procedure) {
        if (_delegate->super.instance) {
            corto_call(_delegate->super.procedure, _result, _delegate->super.instance);
        } else {
            corto_call(_delegate->super.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_nameActionInitC(corto_nameAction *d, corto_string ___ (*callback)(void)) {
    d->super.instance = NULL;
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "()");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_int16 corto_nameActionInitCInstance(corto_nameAction *d, corto_object instance, corto_string ___ (*callback)(corto_object)) {
    d->super.instance = instance;
    corto_claim(instance);
    d->super.procedure = corto_declare(corto_function_o);
    d->super.procedure->kind = CORTO_PROCEDURE_CDECL;
    corto_function_parseParamString(d->super.procedure, "(object instance)");
    d->super.procedure->fptr = (corto_word)callback;
    corto_define(d->super.procedure);
    return 0;
}

corto_object _corto_objectCreate(void) {
    corto_object _this;
    _this = corto_object(corto_declare(corto_object_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
    }
    return _this;
}

corto_object _corto_objectCreateChild(corto_object _parent, corto_string _id) {
    corto_object _this;
    _this = corto_object(corto_declareChild(_parent, _id, corto_object_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
    }
    return _this;
}

corto_int16 _corto_objectUpdate(corto_object _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_objectlist* _corto_objectlistCreate(corto_uint32 length, corto_object* elements) {
    corto_objectlist* _this;
    _this = corto_objectlist(corto_declare(corto_objectlist_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        corto_objectlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_objectlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_objectlist* _corto_objectlistCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements) {
    corto_objectlist* _this;
    _this = corto_objectlist(corto_declareChild(_parent, _id, corto_objectlist_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        corto_objectlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_objectlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_objectlistUpdate(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_objectlistClear(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_objectlistAppend(*((corto_objectlist*)CORTO_OFFSET(_this, ((corto_type)corto_objectlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_objectlistClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_objectlistAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_objectlist* _corto_objectlistDeclare(void) {
    corto_objectlist* _this;
    _this = corto_objectlist(corto_declare(corto_objectlist_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectlist* _corto_objectlistDeclareChild(corto_object _parent, corto_string _id) {
    corto_objectlist* _this;
    _this = corto_objectlist(corto_declareChild(_parent, _id, corto_objectlist_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectlistDefine(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_objectlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_objectlistAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

corto_objectlist* _corto_objectlistAssign(corto_objectlist* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_objectlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_objectlistAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _corto_objectlistStr(corto_objectlist value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_objectlist_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_objectlist* corto_objectlistFromStr(corto_objectlist* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_objectlist_o), str);
    return value;
}

corto_equalityKind corto_objectlistCompare(corto_objectlist dst, corto_objectlist src) {
    return corto_comparep(&dst, corto_objectlist_o, &src);
}

corto_int16 _corto_objectlistInit(corto_objectlist* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_objectlist_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_objectlist_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_objectlistDeinit(corto_objectlist* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_objectlist_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_objectseq* _corto_objectseqCreate(corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declare(corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_objectseqSize(_this, length);
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

corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declareChild(_parent, _id, corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_objectseqSize(_this, length);
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

corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_objectseqSize(((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setref(&((corto_objectseq*)CORTO_OFFSET(_this, ((corto_type)corto_objectseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_objectseqSize(_this, length);
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

corto_objectseq* _corto_objectseqDeclare(void) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declare(corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declareChild(_parent, _id, corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectseqDefine(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_objectseq* _corto_objectseqAssign(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _corto_objectseqStr(corto_objectseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_objectseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_objectseq* corto_objectseqFromStr(corto_objectseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_objectseq_o), str);
    return value;
}

corto_equalityKind corto_objectseqCompare(corto_objectseq dst, corto_objectseq src) {
    return corto_comparep(&dst, corto_objectseq_o, &src);
}

corto_int16 _corto_objectseqInit(corto_objectseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_objectseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_objectseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_objectseqDeinit(corto_objectseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_objectseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

uint8_t* _corto_octetCreate(uint8_t value) {
    uint8_t* _this;
    _this = corto_octet(corto_declare(corto_octet_o));
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

uint8_t* _corto_octetCreateChild(corto_object _parent, corto_string _id, uint8_t value) {
    uint8_t* _this;
    _this = corto_octet(corto_declareChild(_parent, _id, corto_octet_o));
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

corto_int16 _corto_octetUpdate(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint8_t*)CORTO_OFFSET(_this, ((corto_type)corto_octet_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uint8_t* _corto_octetDeclare(void) {
    uint8_t* _this;
    _this = corto_octet(corto_declare(corto_octet_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint8_t* _corto_octetDeclareChild(corto_object _parent, corto_string _id) {
    uint8_t* _this;
    _this = corto_octet(corto_declareChild(_parent, _id, corto_octet_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_octetDefine(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint8_t* _corto_octetAssign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_octetStr(corto_octet value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_octet_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uint8_t* corto_octetFromStr(uint8_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_octet_o), str);
    return value;
}

corto_equalityKind corto_octetCompare(corto_octet dst, corto_octet src) {
    return corto_comparep(&dst, corto_octet_o, &src);
}

corto_int16 _corto_octetInit(corto_octet* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_octet_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_octet_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_octetDeinit(corto_octet* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_octet_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_overridable _corto_overridableCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_overridable _this;
    _this = corto_overridable(corto_declare(corto_overridable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_overridable _corto_overridableCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_overridable _this;
    _this = corto_overridable(corto_declareChild(_parent, _id, corto_overridable_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_overridableUpdate(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->returnType, returnType);
            ((corto_function)((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_overridable)CORTO_OFFSET(_this, ((corto_type)corto_overridable_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_overridable _corto_overridableDeclare(void) {
    corto_overridable _this;
    _this = corto_overridable(corto_declare(corto_overridable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_overridable _corto_overridableDeclareChild(corto_object _parent, corto_string _id) {
    corto_overridable _this;
    _this = corto_overridable(corto_declareChild(_parent, _id, corto_overridable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_overridableDefine(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_overridable _corto_overridableAssign(corto_overridable _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_overridableStr(corto_overridable value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_overridable_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_overridable corto_overridableFromStr(corto_overridable value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_overridable_o), str);
    return value;
}

corto_equalityKind _corto_overridableCompare(corto_overridable dst, corto_overridable src) {
    return corto_compare(dst, src);
}

corto_override _corto_overrideCreate(corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_override _this;
    _this = corto_override(corto_declare(corto_override_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_override _corto_overrideCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    corto_override _this;
    _this = corto_override(corto_declareChild(_parent, _id, corto_override_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
        corto_function(_this)->fptr = (corto_word)_impl;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_overrideUpdate(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->returnType, returnType);
            ((corto_function)((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->returnsReference = returnsReference;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->kind = CORTO_PROCEDURE_CDECL;
            corto_function(((corto_override)CORTO_OFFSET(_this, ((corto_type)corto_override_o)->size)))->fptr = (corto_word)_impl;
        } else {
            corto_setref(&((corto_function)_this)->returnType, returnType);
            ((corto_function)_this)->returnsReference = returnsReference;
            corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
            corto_function(_this)->fptr = (corto_word)_impl;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_override _corto_overrideDeclare(void) {
    corto_override _this;
    _this = corto_override(corto_declare(corto_override_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_override _corto_overrideDeclareChild(corto_object _parent, corto_string _id) {
    corto_override _this;
    _this = corto_override(corto_declareChild(_parent, _id, corto_override_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_overrideDefine(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return corto_define(_this);
}

corto_override _corto_overrideAssign(corto_override _this, corto_type returnType, bool returnsReference, void(*_impl)(void)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(_this)->fptr = (corto_word)_impl;
    return _this;
}

corto_string _corto_overrideStr(corto_override value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_override_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_override corto_overrideFromStr(corto_override value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_override_o), str);
    return value;
}

corto_equalityKind _corto_overrideCompare(corto_override dst, corto_override src) {
    return corto_compare(dst, src);
}

corto_parameter* _corto_parameterCreate(corto_string name, corto_type type, corto_inout inout, bool passByReference) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declare(corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_parameter*)_this)->name, name);
        corto_setref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->inout = inout;
        ((corto_parameter*)_this)->passByReference = passByReference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_parameter* _corto_parameterCreateChild(corto_object _parent, corto_string _id, corto_string name, corto_type type, corto_inout inout, bool passByReference) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declareChild(_parent, _id, corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_parameter*)_this)->name, name);
        corto_setref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->inout = inout;
        ((corto_parameter*)_this)->passByReference = passByReference;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->name, name);
            corto_setref(&((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->type, type);
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->inout = inout;
            ((corto_parameter*)((corto_parameter*)CORTO_OFFSET(_this, ((corto_type)corto_parameter_o)->size)))->passByReference = passByReference;
        } else {
            corto_setstr(&((corto_parameter*)_this)->name, name);
            corto_setref(&((corto_parameter*)_this)->type, type);
            ((corto_parameter*)_this)->inout = inout;
            ((corto_parameter*)_this)->passByReference = passByReference;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_parameter* _corto_parameterDeclare(void) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declare(corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_parameter* _corto_parameterDeclareChild(corto_object _parent, corto_string _id) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declareChild(_parent, _id, corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->inout = inout;
    ((corto_parameter*)_this)->passByReference = passByReference;
    return corto_define(_this);
}

corto_parameter* _corto_parameterAssign(corto_parameter* _this, corto_string name, corto_type type, corto_inout inout, bool passByReference) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->inout = inout;
    ((corto_parameter*)_this)->passByReference = passByReference;
    return _this;
}

corto_string _corto_parameterStr(corto_parameter* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_parameter_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_parameter* corto_parameterFromStr(corto_parameter* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_parameter_o), str);
    return value;
}

corto_equalityKind corto_parameterCompare(corto_parameter* dst, corto_parameter* src) {
    return corto_comparep(dst, corto_parameter_o, src);
}

corto_int16 _corto_parameterInit(corto_parameter* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_parameter_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_parameter_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_parameterDeinit(corto_parameter* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_parameter_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_parameterseq* _corto_parameterseqCreate(corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declare(corto_parameterseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_parameterseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declareChild(_parent, _id, corto_parameterseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_parameterseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            if (&elements[i]) {
                corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
            }
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_parameterseqSize(((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&((corto_parameterseq*)CORTO_OFFSET(_this, ((corto_type)corto_parameterseq_o)->size))->buffer[i], corto_parameter_o, &elements[i]);
                }
            }
        } else {
            corto_parameterseqSize(_this, length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                if (&elements[i]) {
                    corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
                }
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_parameterseq* _corto_parameterseqDeclare(void) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declare(corto_parameterseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declareChild(_parent, _id, corto_parameterseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_parameterseqDefine(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
        }
    }
    return corto_define(_this);
}

corto_parameterseq* _corto_parameterseqAssign(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        if (&elements[i]) {
            corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
        }
    }
    return _this;
}

corto_string _corto_parameterseqStr(corto_parameterseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_parameterseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_parameterseq* corto_parameterseqFromStr(corto_parameterseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_parameterseq_o), str);
    return value;
}

corto_equalityKind corto_parameterseqCompare(corto_parameterseq dst, corto_parameterseq src) {
    return corto_comparep(&dst, corto_parameterseq_o, &src);
}

corto_int16 _corto_parameterseqInit(corto_parameterseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_parameterseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_parameterseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_parameterseqDeinit(corto_parameterseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_parameterseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_primitive _corto_primitiveCreate(corto_width width) {
    corto_primitive _this;
    _this = corto_primitive(corto_declare(corto_primitive_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_primitive _corto_primitiveCreateChild(corto_object _parent, corto_string _id, corto_width width) {
    corto_primitive _this;
    _this = corto_primitive(corto_declareChild(_parent, _id, corto_primitive_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_primitive)CORTO_OFFSET(_this, ((corto_type)corto_primitive_o)->size)))->width = width;
        } else {
            ((corto_primitive)_this)->width = width;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_primitive _corto_primitiveDeclare(void) {
    corto_primitive _this;
    _this = corto_primitive(corto_declare(corto_primitive_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_primitive _corto_primitiveDeclareChild(corto_object _parent, corto_string _id) {
    corto_primitive _this;
    _this = corto_primitive(corto_declareChild(_parent, _id, corto_primitive_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_primitiveDefine(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return corto_define(_this);
}

corto_primitive _corto_primitiveAssign(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    return _this;
}

corto_string _corto_primitiveStr(corto_primitive value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_primitive_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_primitive corto_primitiveFromStr(corto_primitive value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_primitive_o), str);
    return value;
}

corto_equalityKind _corto_primitiveCompare(corto_primitive dst, corto_primitive src) {
    return corto_compare(dst, src);
}

corto_primitiveKind* _corto_primitiveKindCreate(corto_primitiveKind value) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declare(corto_primitiveKind_o));
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

corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, corto_string _id, corto_primitiveKind value) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declareChild(_parent, _id, corto_primitiveKind_o));
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

corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_primitiveKind*)CORTO_OFFSET(_this, ((corto_type)corto_primitiveKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_primitiveKind* _corto_primitiveKindDeclare(void) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declare(corto_primitiveKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declareChild(_parent, _id, corto_primitiveKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_primitiveKind* _corto_primitiveKindAssign(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_primitiveKindStr(corto_primitiveKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_primitiveKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_primitiveKind* corto_primitiveKindFromStr(corto_primitiveKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_primitiveKind_o), str);
    return value;
}

corto_equalityKind corto_primitiveKindCompare(corto_primitiveKind dst, corto_primitiveKind src) {
    return corto_comparep(&dst, corto_primitiveKind_o, &src);
}

corto_int16 _corto_primitiveKindInit(corto_primitiveKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_primitiveKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_primitiveKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_primitiveKindDeinit(corto_primitiveKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_primitiveKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_procedure _corto_procedureCreate(bool hasThis, corto_type thisType) {
    corto_procedure _this;
    _this = corto_procedure(corto_declare(corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_procedure)_this)->hasThis = hasThis;
        corto_setref(&((corto_procedure)_this)->thisType, thisType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_procedure _corto_procedureCreateChild(corto_object _parent, corto_string _id, bool hasThis, corto_type thisType) {
    corto_procedure _this;
    _this = corto_procedure(corto_declareChild(_parent, _id, corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_procedure)_this)->hasThis = hasThis;
        corto_setref(&((corto_procedure)_this)->thisType, thisType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_procedureUpdate(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->hasThis = hasThis;
            corto_setref(&((corto_procedure)((corto_procedure)CORTO_OFFSET(_this, ((corto_type)corto_procedure_o)->size)))->thisType, thisType);
        } else {
            ((corto_procedure)_this)->hasThis = hasThis;
            corto_setref(&((corto_procedure)_this)->thisType, thisType);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_procedure _corto_procedureDeclare(void) {
    corto_procedure _this;
    _this = corto_procedure(corto_declare(corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_procedure _corto_procedureDeclareChild(corto_object _parent, corto_string _id) {
    corto_procedure _this;
    _this = corto_procedure(corto_declareChild(_parent, _id, corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_procedureDefine(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->hasThis = hasThis;
    corto_setref(&((corto_procedure)_this)->thisType, thisType);
    return corto_define(_this);
}

corto_procedure _corto_procedureAssign(corto_procedure _this, bool hasThis, corto_type thisType) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->hasThis = hasThis;
    corto_setref(&((corto_procedure)_this)->thisType, thisType);
    return _this;
}

corto_string _corto_procedureStr(corto_procedure value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_procedure_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_procedure corto_procedureFromStr(corto_procedure value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_procedure_o), str);
    return value;
}

corto_equalityKind _corto_procedureCompare(corto_procedure dst, corto_procedure src) {
    return corto_compare(dst, src);
}

corto_quantity _corto_quantityCreate(corto_string description) {
    corto_quantity _this;
    _this = corto_quantity(corto_declare(corto_quantity_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_quantity)_this)->description, description);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_quantity _corto_quantityCreateChild(corto_object _parent, corto_string _id, corto_string description) {
    corto_quantity _this;
    _this = corto_quantity(corto_declareChild(_parent, _id, corto_quantity_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_quantity)_this)->description, description);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_quantityUpdate(corto_quantity _this, corto_string description) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((corto_quantity)((corto_quantity)CORTO_OFFSET(_this, ((corto_type)corto_quantity_o)->size)))->description, description);
        } else {
            corto_setstr(&((corto_quantity)_this)->description, description);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_quantity _corto_quantityDeclare(void) {
    corto_quantity _this;
    _this = corto_quantity(corto_declare(corto_quantity_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_quantity _corto_quantityDeclareChild(corto_object _parent, corto_string _id) {
    corto_quantity _this;
    _this = corto_quantity(corto_declareChild(_parent, _id, corto_quantity_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_quantityDefine(corto_quantity _this, corto_string description) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_quantity)_this)->description, description);
    return corto_define(_this);
}

corto_quantity _corto_quantityAssign(corto_quantity _this, corto_string description) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_quantity)_this)->description, description);
    return _this;
}

corto_string _corto_quantityStr(corto_quantity value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_quantity_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_quantity corto_quantityFromStr(corto_quantity value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_quantity_o), str);
    return value;
}

corto_equalityKind _corto_quantityCompare(corto_quantity dst, corto_quantity src) {
    return corto_compare(dst, src);
}

corto_sequence _corto_sequenceCreate(corto_type elementType, uint32_t max) {
    corto_sequence _this;
    _this = corto_sequence(corto_declare(corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_sequence _corto_sequenceCreateChild(corto_object _parent, corto_string _id, corto_type elementType, uint32_t max) {
    corto_sequence _this;
    _this = corto_sequence(corto_declareChild(_parent, _id, corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->elementType, elementType);
            ((corto_collection)((corto_sequence)CORTO_OFFSET(_this, ((corto_type)corto_sequence_o)->size)))->max = max;
        } else {
            corto_setref(&((corto_collection)_this)->elementType, elementType);
            ((corto_collection)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_sequence _corto_sequenceDeclare(void) {
    corto_sequence _this;
    _this = corto_sequence(corto_declare(corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_sequence _corto_sequenceDeclareChild(corto_object _parent, corto_string _id) {
    corto_sequence _this;
    _this = corto_sequence(corto_declareChild(_parent, _id, corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

corto_sequence _corto_sequenceAssign(corto_sequence _this, corto_type elementType, uint32_t max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return _this;
}

corto_string _corto_sequenceStr(corto_sequence value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_sequence_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_sequence corto_sequenceFromStr(corto_sequence value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_sequence_o), str);
    return value;
}

corto_equalityKind _corto_sequenceCompare(corto_sequence dst, corto_sequence src) {
    return corto_compare(dst, src);
}

corto_state* _corto_stateCreate(corto_state value) {
    corto_state* _this;
    _this = corto_state(corto_declare(corto_state_o));
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

corto_state* _corto_stateCreateChild(corto_object _parent, corto_string _id, corto_state value) {
    corto_state* _this;
    _this = corto_state(corto_declareChild(_parent, _id, corto_state_o));
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

corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_state*)CORTO_OFFSET(_this, ((corto_type)corto_state_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_state* _corto_stateDeclare(void) {
    corto_state* _this;
    _this = corto_state(corto_declare(corto_state_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_state* _corto_stateDeclareChild(corto_object _parent, corto_string _id) {
    corto_state* _this;
    _this = corto_state(corto_declareChild(_parent, _id, corto_state_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stateDefine(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_state* _corto_stateAssign(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_stateStr(corto_state value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_state_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_state* corto_stateFromStr(corto_state* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_state_o), str);
    return value;
}

corto_equalityKind corto_stateCompare(corto_state dst, corto_state src) {
    return corto_comparep(&dst, corto_state_o, &src);
}

corto_int16 _corto_stateInit(corto_state* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_state_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_state_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_stateDeinit(corto_state* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_state_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_string* _corto_stringCreate(corto_string value) {
    corto_string* _this;
    _this = corto_string(corto_declare(corto_string_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_string* _corto_stringCreateChild(corto_object _parent, corto_string _id, corto_string value) {
    corto_string* _this;
    _this = corto_string(corto_declareChild(_parent, _id, corto_string_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(_this, value);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(((corto_string*)CORTO_OFFSET(_this, ((corto_type)corto_string_o)->size)), value);
        } else {
            corto_setstr(_this, value);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_string* _corto_stringDeclare(void) {
    corto_string* _this;
    _this = corto_string(corto_declare(corto_string_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_string* _corto_stringDeclareChild(corto_object _parent, corto_string _id) {
    corto_string* _this;
    _this = corto_string(corto_declareChild(_parent, _id, corto_string_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringDefine(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(_this, value);
    return corto_define(_this);
}

corto_string* _corto_stringAssign(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(_this, value);
    return _this;
}

corto_string _corto_stringStr(corto_string value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_string_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_string* corto_stringFromStr(corto_string* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_string_o), str);
    return value;
}

corto_equalityKind corto_stringCompare(corto_string dst, corto_string src) {
    return corto_comparep(&dst, corto_string_o, &src);
}

corto_int16 _corto_stringInit(corto_string* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_string_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_string_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_stringDeinit(corto_string* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_string_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_stringlist* _corto_stringlistCreate(corto_uint32 length, corto_string* elements) {
    corto_stringlist* _this;
    _this = corto_stringlist(corto_declare(corto_stringlist_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        corto_stringlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_stringlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_stringlist* _corto_stringlistCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements) {
    corto_stringlist* _this;
    _this = corto_stringlist(corto_declareChild(_parent, _id, corto_stringlist_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_uint32 i = 0;
        corto_stringlistClear(*_this);
        for (i = 0; i < length; i ++) {
            corto_stringlistAppend(*_this, elements[i]);
        }
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_stringlistUpdate(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_uint32 i = 0;
            corto_stringlistClear(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)));
            for (i = 0; i < length; i ++) {
                corto_stringlistAppend(*((corto_stringlist*)CORTO_OFFSET(_this, ((corto_type)corto_stringlist_o)->size)), elements[i]);
            }
        } else {
            corto_uint32 i = 0;
            corto_stringlistClear(*_this);
            for (i = 0; i < length; i ++) {
                corto_stringlistAppend(*_this, elements[i]);
            }
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_stringlist* _corto_stringlistDeclare(void) {
    corto_stringlist* _this;
    _this = corto_stringlist(corto_declare(corto_stringlist_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_stringlist* _corto_stringlistDeclareChild(corto_object _parent, corto_string _id) {
    corto_stringlist* _this;
    _this = corto_stringlist(corto_declareChild(_parent, _id, corto_stringlist_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringlistDefine(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_stringlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_stringlistAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

corto_stringlist* _corto_stringlistAssign(corto_stringlist* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    corto_stringlistClear(*_this);
    for (i = 0; i < length; i ++) {
        corto_stringlistAppend(*_this, elements[i]);
    }
    return _this;
}

corto_string _corto_stringlistStr(corto_stringlist value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_stringlist_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_stringlist* corto_stringlistFromStr(corto_stringlist* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_stringlist_o), str);
    return value;
}

corto_equalityKind corto_stringlistCompare(corto_stringlist dst, corto_stringlist src) {
    return corto_comparep(&dst, corto_stringlist_o, &src);
}

corto_int16 _corto_stringlistInit(corto_stringlist* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_stringlist_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_stringlist_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_stringlistDeinit(corto_stringlist* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_stringlist_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_stringseq* _corto_stringseqCreate(corto_uint32 length, corto_string* elements) {
    corto_stringseq* _this;
    _this = corto_stringseq(corto_declare(corto_stringseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_stringseqSize(_this, length);
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

corto_stringseq* _corto_stringseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements) {
    corto_stringseq* _this;
    _this = corto_stringseq(corto_declareChild(_parent, _id, corto_stringseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_stringseqSize(_this, length);
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

corto_int16 _corto_stringseqUpdate(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_stringseqSize(((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                corto_setstr(&((corto_stringseq*)CORTO_OFFSET(_this, ((corto_type)corto_stringseq_o)->size))->buffer[i], elements[i]);
            }
        } else {
            corto_stringseqSize(_this, length);
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

corto_stringseq* _corto_stringseqDeclare(void) {
    corto_stringseq* _this;
    _this = corto_stringseq(corto_declare(corto_stringseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_stringseq* _corto_stringseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_stringseq* _this;
    _this = corto_stringseq(corto_declareChild(_parent, _id, corto_stringseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_stringseqDefine(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_stringseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

corto_stringseq* _corto_stringseqAssign(corto_stringseq* _this, corto_uint32 length, corto_string* elements) {
    CORTO_UNUSED(_this);
    corto_stringseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setstr(&_this->buffer[i], elements[i]);
    }
    return _this;
}

corto_string _corto_stringseqStr(corto_stringseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_stringseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_stringseq* corto_stringseqFromStr(corto_stringseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_stringseq_o), str);
    return value;
}

corto_equalityKind corto_stringseqCompare(corto_stringseq dst, corto_stringseq src) {
    return corto_comparep(&dst, corto_stringseq_o, &src);
}

corto_int16 _corto_stringseqInit(corto_stringseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_stringseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_stringseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_stringseqDeinit(corto_stringseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_stringseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = corto_struct(corto_declare(corto_struct_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_struct _corto_structCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = corto_struct(corto_declareChild(_parent, _id, corto_struct_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->base, base);
            ((corto_struct)((corto_struct)CORTO_OFFSET(_this, ((corto_type)corto_struct_o)->size)))->baseAccess = baseAccess;
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_struct _corto_structDeclare(void) {
    corto_struct _this;
    _this = corto_struct(corto_declare(corto_struct_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_struct _corto_structDeclareChild(corto_object _parent, corto_string _id) {
    corto_struct _this;
    _this = corto_struct(corto_declareChild(_parent, _id, corto_struct_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    return corto_define(_this);
}

corto_struct _corto_structAssign(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    return _this;
}

corto_string _corto_structStr(corto_struct value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_struct_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_struct corto_structFromStr(corto_struct value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_struct_o), str);
    return value;
}

corto_equalityKind _corto_structCompare(corto_struct dst, corto_struct src) {
    return corto_compare(dst, src);
}

corto_table _corto_tableCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_table _this;
    _this = corto_table(corto_declare(corto_table_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_table _corto_tableCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    corto_table _this;
    _this = corto_table(corto_declareChild(_parent, _id, corto_table_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
        corto_setref(&((corto_container)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_tableUpdate(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_interface)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->base, base);
            ((corto_struct)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->baseAccess = baseAccess;
            corto_copyp(&((corto_class)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)((corto_table)CORTO_OFFSET(_this, ((corto_type)corto_table_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_interface)_this)->base, base);
            ((corto_struct)_this)->baseAccess = baseAccess;
            corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
            corto_setref(&((corto_container)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_table _corto_tableDeclare(void) {
    corto_table _this;
    _this = corto_table(corto_declare(corto_table_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_table _corto_tableDeclareChild(corto_object _parent, corto_string _id) {
    corto_table _this;
    _this = corto_table(corto_declareChild(_parent, _id, corto_table_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_tableDefine(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return corto_define(_this);
}

corto_table _corto_tableAssign(corto_table _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    corto_setref(&((corto_container)_this)->type, type);
    return _this;
}

corto_string _corto_tableStr(corto_table value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_table_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_table corto_tableFromStr(corto_table value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_table_o), str);
    return value;
}

corto_equalityKind _corto_tableCompare(corto_table dst, corto_table src) {
    return corto_compare(dst, src);
}

corto_tablescope _corto_tablescopeCreate(corto_struct type) {
    corto_tablescope _this;
    _this = corto_tablescope(corto_declare(corto_tablescope_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_tablescope)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_tablescope _corto_tablescopeCreateChild(corto_object _parent, corto_string _id, corto_struct type) {
    corto_tablescope _this;
    _this = corto_tablescope(corto_declareChild(_parent, _id, corto_tablescope_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_tablescope)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_tablescopeUpdate(corto_tablescope _this, corto_struct type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_tablescope)((corto_tablescope)CORTO_OFFSET(_this, ((corto_type)corto_tablescope_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_tablescope)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_tablescope _corto_tablescopeDeclare(void) {
    corto_tablescope _this;
    _this = corto_tablescope(corto_declare(corto_tablescope_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_tablescope _corto_tablescopeDeclareChild(corto_object _parent, corto_string _id) {
    corto_tablescope _this;
    _this = corto_tablescope(corto_declareChild(_parent, _id, corto_tablescope_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_tablescopeDefine(corto_tablescope _this, corto_struct type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_tablescope)_this)->type, type);
    return corto_define(_this);
}

corto_tablescope _corto_tablescopeAssign(corto_tablescope _this, corto_struct type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_tablescope)_this)->type, type);
    return _this;
}

corto_string _corto_tablescopeStr(corto_tablescope value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_tablescope_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_tablescope corto_tablescopeFromStr(corto_tablescope value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_tablescope_o), str);
    return value;
}

corto_equalityKind _corto_tablescopeCompare(corto_tablescope dst, corto_tablescope src) {
    return corto_compare(dst, src);
}

corto_target _corto_targetCreate(corto_type type) {
    corto_target _this;
    _this = corto_target(corto_declare(corto_target_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_target)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_target _corto_targetCreateChild(corto_object _parent, corto_string _id, corto_type type) {
    corto_target _this;
    _this = corto_target(corto_declareChild(_parent, _id, corto_target_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_target)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_targetUpdate(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_target)((corto_target)CORTO_OFFSET(_this, ((corto_type)corto_target_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_target)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_target _corto_targetDeclare(void) {
    corto_target _this;
    _this = corto_target(corto_declare(corto_target_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_target _corto_targetDeclareChild(corto_object _parent, corto_string _id) {
    corto_target _this;
    _this = corto_target(corto_declareChild(_parent, _id, corto_target_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_targetDefine(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_target)_this)->type, type);
    return corto_define(_this);
}

corto_target _corto_targetAssign(corto_target _this, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_target)_this)->type, type);
    return _this;
}

corto_string _corto_targetStr(corto_target value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_target_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_target corto_targetFromStr(corto_target value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_target_o), str);
    return value;
}

corto_equalityKind _corto_targetCompare(corto_target dst, corto_target src) {
    return corto_compare(dst, src);
}

corto_text _corto_textCreate(corto_width charWidth, uint64_t length) {
    corto_text _this;
    _this = corto_text(corto_declare(corto_text_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_text)_this)->charWidth = charWidth;
        ((corto_text)_this)->length = length;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_text _corto_textCreateChild(corto_object _parent, corto_string _id, corto_width charWidth, uint64_t length) {
    corto_text _this;
    _this = corto_text(corto_declareChild(_parent, _id, corto_text_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_text)_this)->charWidth = charWidth;
        ((corto_text)_this)->length = length;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->charWidth = charWidth;
            ((corto_text)((corto_text)CORTO_OFFSET(_this, ((corto_type)corto_text_o)->size)))->length = length;
        } else {
            ((corto_text)_this)->charWidth = charWidth;
            ((corto_text)_this)->length = length;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_text _corto_textDeclare(void) {
    corto_text _this;
    _this = corto_text(corto_declare(corto_text_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_text _corto_textDeclareChild(corto_object _parent, corto_string _id) {
    corto_text _this;
    _this = corto_text(corto_declareChild(_parent, _id, corto_text_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    return corto_define(_this);
}

corto_text _corto_textAssign(corto_text _this, corto_width charWidth, uint64_t length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    return _this;
}

corto_string _corto_textStr(corto_text value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_text_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_text corto_textFromStr(corto_text value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_text_o), str);
    return value;
}

corto_equalityKind _corto_textCompare(corto_text dst, corto_text src) {
    return corto_compare(dst, src);
}

corto_type _corto_typeCreate(corto_typeKind kind, bool reference, corto_attr attr) {
    corto_type _this;
    _this = corto_type(corto_declare(corto_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_type)_this)->kind = kind;
        ((corto_type)_this)->reference = reference;
        ((corto_type)_this)->attr = attr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_type _corto_typeCreateChild(corto_object _parent, corto_string _id, corto_typeKind kind, bool reference, corto_attr attr) {
    corto_type _this;
    _this = corto_type(corto_declareChild(_parent, _id, corto_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_type)_this)->kind = kind;
        ((corto_type)_this)->reference = reference;
        ((corto_type)_this)->attr = attr;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_typeUpdate(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->kind = kind;
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->reference = reference;
            ((corto_type)((corto_type)CORTO_OFFSET(_this, ((corto_type)corto_type_o)->size)))->attr = attr;
        } else {
            ((corto_type)_this)->kind = kind;
            ((corto_type)_this)->reference = reference;
            ((corto_type)_this)->attr = attr;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_type _corto_typeDeclare(void) {
    corto_type _this;
    _this = corto_type(corto_declare(corto_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_type _corto_typeDeclareChild(corto_object _parent, corto_string _id) {
    corto_type _this;
    _this = corto_type(corto_declareChild(_parent, _id, corto_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeDefine(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    ((corto_type)_this)->attr = attr;
    return corto_define(_this);
}

corto_type _corto_typeAssign(corto_type _this, corto_typeKind kind, bool reference, corto_attr attr) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    ((corto_type)_this)->attr = attr;
    return _this;
}

corto_string _corto_typeStr(corto_type value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_type_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_type corto_typeFromStr(corto_type value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_type_o), str);
    return value;
}

corto_equalityKind _corto_typeCompare(corto_type dst, corto_type src) {
    return corto_compare(dst, src);
}

corto_typeKind* _corto_typeKindCreate(corto_typeKind value) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declare(corto_typeKind_o));
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

corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, corto_string _id, corto_typeKind value) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declareChild(_parent, _id, corto_typeKind_o));
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

corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_typeKind*)CORTO_OFFSET(_this, ((corto_type)corto_typeKind_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_typeKind* _corto_typeKindDeclare(void) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declare(corto_typeKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, corto_string _id) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declareChild(_parent, _id, corto_typeKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_typeKind* _corto_typeKindAssign(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_typeKindStr(corto_typeKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_typeKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_typeKind* corto_typeKindFromStr(corto_typeKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_typeKind_o), str);
    return value;
}

corto_equalityKind corto_typeKindCompare(corto_typeKind dst, corto_typeKind src) {
    return corto_comparep(&dst, corto_typeKind_o, &src);
}

corto_int16 _corto_typeKindInit(corto_typeKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_typeKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_typeKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_typeKindDeinit(corto_typeKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_typeKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_typeOptions* _corto_typeOptionsCreate(corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    corto_typeOptions* _this;
    _this = corto_typeOptions(corto_declare(corto_typeOptions_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_typeOptions*)_this)->parentType, parentType);
        ((corto_typeOptions*)_this)->parentState = parentState;
        corto_setref(&((corto_typeOptions*)_this)->defaultType, defaultType);
        corto_setref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_typeOptions* _corto_typeOptionsCreateChild(corto_object _parent, corto_string _id, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    corto_typeOptions* _this;
    _this = corto_typeOptions(corto_declareChild(_parent, _id, corto_typeOptions_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_typeOptions*)_this)->parentType, parentType);
        ((corto_typeOptions*)_this)->parentState = parentState;
        corto_setref(&((corto_typeOptions*)_this)->defaultType, defaultType);
        corto_setref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_typeOptionsUpdate(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->parentType, parentType);
            ((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->parentState = parentState;
            corto_setref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->defaultType, defaultType);
            corto_setref(&((corto_typeOptions*)((corto_typeOptions*)CORTO_OFFSET(_this, ((corto_type)corto_typeOptions_o)->size)))->defaultProcedureType, defaultProcedureType);
        } else {
            corto_setref(&((corto_typeOptions*)_this)->parentType, parentType);
            ((corto_typeOptions*)_this)->parentState = parentState;
            corto_setref(&((corto_typeOptions*)_this)->defaultType, defaultType);
            corto_setref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_typeOptions* _corto_typeOptionsDeclare(void) {
    corto_typeOptions* _this;
    _this = corto_typeOptions(corto_declare(corto_typeOptions_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_typeOptions* _corto_typeOptionsDeclareChild(corto_object _parent, corto_string _id) {
    corto_typeOptions* _this;
    _this = corto_typeOptions(corto_declareChild(_parent, _id, corto_typeOptions_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeOptionsDefine(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_typeOptions*)_this)->parentType, parentType);
    ((corto_typeOptions*)_this)->parentState = parentState;
    corto_setref(&((corto_typeOptions*)_this)->defaultType, defaultType);
    corto_setref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
    return corto_define(_this);
}

corto_typeOptions* _corto_typeOptionsAssign(corto_typeOptions* _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_typeOptions*)_this)->parentType, parentType);
    ((corto_typeOptions*)_this)->parentState = parentState;
    corto_setref(&((corto_typeOptions*)_this)->defaultType, defaultType);
    corto_setref(&((corto_typeOptions*)_this)->defaultProcedureType, defaultProcedureType);
    return _this;
}

corto_string _corto_typeOptionsStr(corto_typeOptions* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_typeOptions_o), value);
    result = corto_strv(&v, 0);
    return result;
}

corto_typeOptions* corto_typeOptionsFromStr(corto_typeOptions* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_typeOptions_o), str);
    return value;
}

corto_equalityKind corto_typeOptionsCompare(corto_typeOptions* dst, corto_typeOptions* src) {
    return corto_comparep(dst, corto_typeOptions_o, src);
}

corto_int16 _corto_typeOptionsInit(corto_typeOptions* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_typeOptions_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_typeOptions_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_typeOptionsDeinit(corto_typeOptions* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_typeOptions_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_uint _corto_uintCreate(corto_width width, uint64_t min, uint64_t max) {
    corto_uint _this;
    _this = corto_uint(corto_declare(corto_uint_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_uint)_this)->min = min;
        ((corto_uint)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_uint _corto_uintCreateChild(corto_object _parent, corto_string _id, corto_width width, uint64_t min, uint64_t max) {
    corto_uint _this;
    _this = corto_uint(corto_declareChild(_parent, _id, corto_uint_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((corto_primitive)_this)->width = width;
        ((corto_uint)_this)->min = min;
        ((corto_uint)_this)->max = max;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((corto_primitive)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->width = width;
            ((corto_uint)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->min = min;
            ((corto_uint)((corto_uint)CORTO_OFFSET(_this, ((corto_type)corto_uint_o)->size)))->max = max;
        } else {
            ((corto_primitive)_this)->width = width;
            ((corto_uint)_this)->min = min;
            ((corto_uint)_this)->max = max;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_uint _corto_uintDeclare(void) {
    corto_uint _this;
    _this = corto_uint(corto_declare(corto_uint_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint _corto_uintDeclareChild(corto_object _parent, corto_string _id) {
    corto_uint _this;
    _this = corto_uint(corto_declareChild(_parent, _id, corto_uint_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return corto_define(_this);
}

corto_uint _corto_uintAssign(corto_uint _this, corto_width width, uint64_t min, uint64_t max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return _this;
}

corto_string _corto_uintStr(corto_uint value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_uint_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_uint corto_uintFromStr(corto_uint value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_uint_o), str);
    return value;
}

corto_equalityKind _corto_uintCompare(corto_uint dst, corto_uint src) {
    return corto_compare(dst, src);
}

uint16_t* _corto_uint16Create(uint16_t value) {
    uint16_t* _this;
    _this = corto_uint16(corto_declare(corto_uint16_o));
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

uint16_t* _corto_uint16CreateChild(corto_object _parent, corto_string _id, uint16_t value) {
    uint16_t* _this;
    _this = corto_uint16(corto_declareChild(_parent, _id, corto_uint16_o));
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

corto_int16 _corto_uint16Update(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint16_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint16_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uint16_t* _corto_uint16Declare(void) {
    uint16_t* _this;
    _this = corto_uint16(corto_declare(corto_uint16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint16_t* _corto_uint16DeclareChild(corto_object _parent, corto_string _id) {
    uint16_t* _this;
    _this = corto_uint16(corto_declareChild(_parent, _id, corto_uint16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint16Define(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint16_t* _corto_uint16Assign(uint16_t* _this, uint16_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_uint16Str(corto_uint16 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint16_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uint16_t* corto_uint16FromStr(uint16_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_uint16_o), str);
    return value;
}

corto_equalityKind corto_uint16Compare(corto_uint16 dst, corto_uint16 src) {
    return corto_comparep(&dst, corto_uint16_o, &src);
}

corto_int16 _corto_uint16Init(corto_uint16* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_uint16_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_uint16_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_uint16Deinit(corto_uint16* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint16_o), value);
    result = corto_deinitv(&v);
    return result;
}

uint32_t* _corto_uint32Create(uint32_t value) {
    uint32_t* _this;
    _this = corto_uint32(corto_declare(corto_uint32_o));
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

uint32_t* _corto_uint32CreateChild(corto_object _parent, corto_string _id, uint32_t value) {
    uint32_t* _this;
    _this = corto_uint32(corto_declareChild(_parent, _id, corto_uint32_o));
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

corto_int16 _corto_uint32Update(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint32_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint32_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uint32_t* _corto_uint32Declare(void) {
    uint32_t* _this;
    _this = corto_uint32(corto_declare(corto_uint32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint32_t* _corto_uint32DeclareChild(corto_object _parent, corto_string _id) {
    uint32_t* _this;
    _this = corto_uint32(corto_declareChild(_parent, _id, corto_uint32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint32Define(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint32_t* _corto_uint32Assign(uint32_t* _this, uint32_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_uint32Str(corto_uint32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uint32_t* corto_uint32FromStr(uint32_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_uint32_o), str);
    return value;
}

corto_equalityKind corto_uint32Compare(corto_uint32 dst, corto_uint32 src) {
    return corto_comparep(&dst, corto_uint32_o, &src);
}

corto_int16 _corto_uint32Init(corto_uint32* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_uint32_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_uint32_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_uint32Deinit(corto_uint32* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint32_o), value);
    result = corto_deinitv(&v);
    return result;
}

uint64_t* _corto_uint64Create(uint64_t value) {
    uint64_t* _this;
    _this = corto_uint64(corto_declare(corto_uint64_o));
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

uint64_t* _corto_uint64CreateChild(corto_object _parent, corto_string _id, uint64_t value) {
    uint64_t* _this;
    _this = corto_uint64(corto_declareChild(_parent, _id, corto_uint64_o));
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

corto_int16 _corto_uint64Update(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint64_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint64_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uint64_t* _corto_uint64Declare(void) {
    uint64_t* _this;
    _this = corto_uint64(corto_declare(corto_uint64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint64_t* _corto_uint64DeclareChild(corto_object _parent, corto_string _id) {
    uint64_t* _this;
    _this = corto_uint64(corto_declareChild(_parent, _id, corto_uint64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint64Define(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint64_t* _corto_uint64Assign(uint64_t* _this, uint64_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_uint64Str(corto_uint64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uint64_t* corto_uint64FromStr(uint64_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_uint64_o), str);
    return value;
}

corto_equalityKind corto_uint64Compare(corto_uint64 dst, corto_uint64 src) {
    return corto_comparep(&dst, corto_uint64_o, &src);
}

corto_int16 _corto_uint64Init(corto_uint64* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_uint64_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_uint64_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_uint64Deinit(corto_uint64* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint64_o), value);
    result = corto_deinitv(&v);
    return result;
}

uint8_t* _corto_uint8Create(uint8_t value) {
    uint8_t* _this;
    _this = corto_uint8(corto_declare(corto_uint8_o));
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

uint8_t* _corto_uint8CreateChild(corto_object _parent, corto_string _id, uint8_t value) {
    uint8_t* _this;
    _this = corto_uint8(corto_declareChild(_parent, _id, corto_uint8_o));
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

corto_int16 _corto_uint8Update(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uint8_t*)CORTO_OFFSET(_this, ((corto_type)corto_uint8_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uint8_t* _corto_uint8Declare(void) {
    uint8_t* _this;
    _this = corto_uint8(corto_declare(corto_uint8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uint8_t* _corto_uint8DeclareChild(corto_object _parent, corto_string _id) {
    uint8_t* _this;
    _this = corto_uint8(corto_declareChild(_parent, _id, corto_uint8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint8Define(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uint8_t* _corto_uint8Assign(uint8_t* _this, uint8_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_uint8Str(corto_uint8 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint8_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uint8_t* corto_uint8FromStr(uint8_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_uint8_o), str);
    return value;
}

corto_equalityKind corto_uint8Compare(corto_uint8 dst, corto_uint8 src) {
    return corto_comparep(&dst, corto_uint8_o, &src);
}

corto_int16 _corto_uint8Init(corto_uint8* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_uint8_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_uint8_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_uint8Deinit(corto_uint8* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint8_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_union _corto_unionCreate(corto_type discriminator) {
    corto_union _this;
    _this = corto_union(corto_declare(corto_union_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_union)_this)->discriminator, discriminator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_union _corto_unionCreateChild(corto_object _parent, corto_string _id, corto_type discriminator) {
    corto_union _this;
    _this = corto_union(corto_declareChild(_parent, _id, corto_union_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_union)_this)->discriminator, discriminator);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_unionUpdate(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_union)((corto_union)CORTO_OFFSET(_this, ((corto_type)corto_union_o)->size)))->discriminator, discriminator);
        } else {
            corto_setref(&((corto_union)_this)->discriminator, discriminator);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_union _corto_unionDeclare(void) {
    corto_union _this;
    _this = corto_union(corto_declare(corto_union_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_union _corto_unionDeclareChild(corto_object _parent, corto_string _id) {
    corto_union _this;
    _this = corto_union(corto_declareChild(_parent, _id, corto_union_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_unionDefine(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_union)_this)->discriminator, discriminator);
    return corto_define(_this);
}

corto_union _corto_unionAssign(corto_union _this, corto_type discriminator) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_union)_this)->discriminator, discriminator);
    return _this;
}

corto_string _corto_unionStr(corto_union value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_union_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_union corto_unionFromStr(corto_union value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_union_o), str);
    return value;
}

corto_equalityKind _corto_unionCompare(corto_union dst, corto_union src) {
    return corto_compare(dst, src);
}

corto_unit _corto_unitCreate(corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type) {
    corto_unit _this;
    _this = corto_unit(corto_declare(corto_unit_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_unit)_this)->quantity, quantity);
        corto_setstr(&((corto_unit)_this)->symbol, symbol);
        corto_setstr(&((corto_unit)_this)->conversion, conversion);
        corto_setref(&((corto_unit)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_unit _corto_unitCreateChild(corto_object _parent, corto_string _id, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type) {
    corto_unit _this;
    _this = corto_unit(corto_declareChild(_parent, _id, corto_unit_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setref(&((corto_unit)_this)->quantity, quantity);
        corto_setstr(&((corto_unit)_this)->symbol, symbol);
        corto_setstr(&((corto_unit)_this)->conversion, conversion);
        corto_setref(&((corto_unit)_this)->type, type);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_unitUpdate(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setref(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->quantity, quantity);
            corto_setstr(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->symbol, symbol);
            corto_setstr(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->conversion, conversion);
            corto_setref(&((corto_unit)((corto_unit)CORTO_OFFSET(_this, ((corto_type)corto_unit_o)->size)))->type, type);
        } else {
            corto_setref(&((corto_unit)_this)->quantity, quantity);
            corto_setstr(&((corto_unit)_this)->symbol, symbol);
            corto_setstr(&((corto_unit)_this)->conversion, conversion);
            corto_setref(&((corto_unit)_this)->type, type);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_unit _corto_unitDeclare(void) {
    corto_unit _this;
    _this = corto_unit(corto_declare(corto_unit_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_unit _corto_unitDeclareChild(corto_object _parent, corto_string _id) {
    corto_unit _this;
    _this = corto_unit(corto_declareChild(_parent, _id, corto_unit_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_unitDefine(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_unit)_this)->quantity, quantity);
    corto_setstr(&((corto_unit)_this)->symbol, symbol);
    corto_setstr(&((corto_unit)_this)->conversion, conversion);
    corto_setref(&((corto_unit)_this)->type, type);
    return corto_define(_this);
}

corto_unit _corto_unitAssign(corto_unit _this, corto_quantity quantity, corto_string symbol, corto_string conversion, corto_type type) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_unit)_this)->quantity, quantity);
    corto_setstr(&((corto_unit)_this)->symbol, symbol);
    corto_setstr(&((corto_unit)_this)->conversion, conversion);
    corto_setref(&((corto_unit)_this)->type, type);
    return _this;
}

corto_string _corto_unitStr(corto_unit value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_unit_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_unit corto_unitFromStr(corto_unit value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_unit_o), str);
    return value;
}

corto_equalityKind _corto_unitCompare(corto_unit dst, corto_unit src) {
    return corto_compare(dst, src);
}

corto_verbatim _corto_verbatimCreate(corto_string contentType) {
    corto_verbatim _this;
    _this = corto_verbatim(corto_declare(corto_verbatim_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_verbatim)_this)->contentType, contentType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_verbatim _corto_verbatimCreateChild(corto_object _parent, corto_string _id, corto_string contentType) {
    corto_verbatim _this;
    _this = corto_verbatim(corto_declareChild(_parent, _id, corto_verbatim_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_setstr(&((corto_verbatim)_this)->contentType, contentType);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_verbatimUpdate(corto_verbatim _this, corto_string contentType) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_setstr(&((corto_verbatim)((corto_verbatim)CORTO_OFFSET(_this, ((corto_type)corto_verbatim_o)->size)))->contentType, contentType);
        } else {
            corto_setstr(&((corto_verbatim)_this)->contentType, contentType);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_verbatim _corto_verbatimDeclare(void) {
    corto_verbatim _this;
    _this = corto_verbatim(corto_declare(corto_verbatim_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_verbatim _corto_verbatimDeclareChild(corto_object _parent, corto_string _id) {
    corto_verbatim _this;
    _this = corto_verbatim(corto_declareChild(_parent, _id, corto_verbatim_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_verbatimDefine(corto_verbatim _this, corto_string contentType) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_verbatim)_this)->contentType, contentType);
    return corto_define(_this);
}

corto_verbatim _corto_verbatimAssign(corto_verbatim _this, corto_string contentType) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_verbatim)_this)->contentType, contentType);
    return _this;
}

corto_string _corto_verbatimStr(corto_verbatim value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_verbatim_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_verbatim corto_verbatimFromStr(corto_verbatim value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_verbatim_o), str);
    return value;
}

corto_equalityKind _corto_verbatimCompare(corto_verbatim dst, corto_verbatim src) {
    return corto_compare(dst, src);
}

corto_void* _corto_voidCreate(void) {
    corto_void* _this;
    _this = corto_void(corto_declare(corto_void_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
    }
    return _this;
}

corto_void* _corto_voidCreateChild(corto_object _parent, corto_string _id) {
    corto_void* _this;
    _this = corto_void(corto_declareChild(_parent, _id, corto_void_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
    }
    return _this;
}

corto_int16 _corto_voidUpdate(corto_void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_width* _corto_widthCreate(corto_width value) {
    corto_width* _this;
    _this = corto_width(corto_declare(corto_width_o));
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

corto_width* _corto_widthCreateChild(corto_object _parent, corto_string _id, corto_width value) {
    corto_width* _this;
    _this = corto_width(corto_declareChild(_parent, _id, corto_width_o));
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

corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((corto_width*)CORTO_OFFSET(_this, ((corto_type)corto_width_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_width* _corto_widthDeclare(void) {
    corto_width* _this;
    _this = corto_width(corto_declare(corto_width_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_width* _corto_widthDeclareChild(corto_object _parent, corto_string _id) {
    corto_width* _this;
    _this = corto_width(corto_declareChild(_parent, _id, corto_width_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_widthDefine(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

corto_width* _corto_widthAssign(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_widthStr(corto_width value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_width_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_width* corto_widthFromStr(corto_width* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_width_o), str);
    return value;
}

corto_equalityKind corto_widthCompare(corto_width dst, corto_width src) {
    return corto_comparep(&dst, corto_width_o, &src);
}

corto_int16 _corto_widthInit(corto_width* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_width_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_width_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_widthDeinit(corto_width* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_width_o), value);
    result = corto_deinitv(&v);
    return result;
}

uintptr_t* _corto_wordCreate(uintptr_t value) {
    uintptr_t* _this;
    _this = corto_word(corto_declare(corto_word_o));
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

uintptr_t* _corto_wordCreateChild(corto_object _parent, corto_string _id, uintptr_t value) {
    uintptr_t* _this;
    _this = corto_word(corto_declareChild(_parent, _id, corto_word_o));
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

corto_int16 _corto_wordUpdate(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            *((uintptr_t*)CORTO_OFFSET(_this, ((corto_type)corto_word_o)->size)) = value;
        } else {
            *_this = value;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

uintptr_t* _corto_wordDeclare(void) {
    uintptr_t* _this;
    _this = corto_word(corto_declare(corto_word_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

uintptr_t* _corto_wordDeclareChild(corto_object _parent, corto_string _id) {
    uintptr_t* _this;
    _this = corto_word(corto_declareChild(_parent, _id, corto_word_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_wordDefine(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

uintptr_t* _corto_wordAssign(uintptr_t* _this, uintptr_t value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return _this;
}

corto_string _corto_wordStr(corto_word value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_word_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

uintptr_t* corto_wordFromStr(uintptr_t* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_word_o), str);
    return value;
}

corto_equalityKind corto_wordCompare(corto_word dst, corto_word src) {
    return corto_comparep(&dst, corto_word_o, &src);
}

corto_int16 _corto_wordInit(corto_word* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_word_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_word_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_wordDeinit(corto_word* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_word_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_wordseq* _corto_wordseqCreate(corto_uint32 length, corto_word* elements) {
    corto_wordseq* _this;
    _this = corto_wordseq(corto_declare(corto_wordseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_wordseqSize(_this, length);
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

corto_wordseq* _corto_wordseqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_word* elements) {
    corto_wordseq* _this;
    _this = corto_wordseq(corto_declareChild(_parent, _id, corto_wordseq_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_wordseqSize(_this, length);
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

corto_int16 _corto_wordseqUpdate(corto_wordseq* _this, corto_uint32 length, corto_word* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_wordseqSize(((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size)), length);
            corto_uint32 i = 0;
            for (i = 0; i < length; i ++) {
                ((corto_wordseq*)CORTO_OFFSET(_this, ((corto_type)corto_wordseq_o)->size))->buffer[i] = elements[i];
            }
        } else {
            corto_wordseqSize(_this, length);
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

corto_wordseq* _corto_wordseqDeclare(void) {
    corto_wordseq* _this;
    _this = corto_wordseq(corto_declare(corto_wordseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_wordseq* _corto_wordseqDeclareChild(corto_object _parent, corto_string _id) {
    corto_wordseq* _this;
    _this = corto_wordseq(corto_declareChild(_parent, _id, corto_wordseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_wordseqDefine(corto_wordseq* _this, corto_uint32 length, corto_word* elements) {
    CORTO_UNUSED(_this);
    corto_wordseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

corto_wordseq* _corto_wordseqAssign(corto_wordseq* _this, corto_uint32 length, corto_word* elements) {
    CORTO_UNUSED(_this);
    corto_wordseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return _this;
}

corto_string _corto_wordseqStr(corto_wordseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_wordseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_wordseq* corto_wordseqFromStr(corto_wordseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_wordseq_o), str);
    return value;
}

corto_equalityKind corto_wordseqCompare(corto_wordseq dst, corto_wordseq src) {
    return corto_comparep(&dst, corto_wordseq_o, &src);
}

corto_int16 _corto_wordseqInit(corto_wordseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_wordseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_wordseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_wordseqDeinit(corto_wordseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_wordseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

