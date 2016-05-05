/* _api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include "corto/lang/lang.h"
corto_alias _corto_aliasCreate(corto_member member) {
    corto_alias _this;
    _this = corto_alias(corto_declare(corto_alias_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_alias)_this)->member, member);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_alias _corto_aliasCreateChild(corto_object _parent, corto_string _name, corto_member member) {
    corto_alias _this;
    _this = corto_alias(corto_declareChild(_parent, _name, corto_alias_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_alias)_this)->member, member);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_alias)_this)->member, member);
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

corto_alias _corto_aliasDeclareChild(corto_object _parent, corto_string _name) {
    corto_alias _this;
    _this = corto_alias(corto_declareChild(_parent, _name, corto_alias_o));
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

void _corto_aliasSet(corto_alias _this, corto_member member) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_alias)_this)->member, member);
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
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_copyp(_this, corto_any_o, &v);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_any* _corto_anyCreateChild(corto_object _parent, corto_string _name, corto_type type, void *value) {
    corto_any* _this;
    _this = corto_any(corto_declareChild(_parent, _name, corto_any_o));
    if (!_this) {
        return NULL;
    }
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_copyp(_this, corto_any_o, &v);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_anyUpdate(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_any v;
        v.value = value;
        v.type = type;
        _this->owner = TRUE;
        corto_copyp(_this, corto_any_o, &v);
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

corto_any* _corto_anyDeclareChild(corto_object _parent, corto_string _name) {
    corto_any* _this;
    _this = corto_any(corto_declareChild(_parent, _name, corto_any_o));
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

void _corto_anySet(corto_any* _this, corto_type type, void *value) {
    CORTO_UNUSED(_this);
    corto_any v;
    v.value = value;
    v.type = type;
    _this->owner = TRUE;
    corto_copyp(_this, corto_any_o, &v);
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

corto_array _corto_arrayCreate(corto_type elementType, corto_uint32 max) {
    corto_array _this;
    _this = corto_array(corto_declare(corto_array_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_array _corto_arrayCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max) {
    corto_array _this;
    _this = corto_array(corto_declareChild(_parent, _name, corto_array_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
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

corto_array _corto_arrayDeclareChild(corto_object _parent, corto_string _name) {
    corto_array _this;
    _this = corto_array(corto_declareChild(_parent, _name, corto_array_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

void _corto_arraySet(corto_array _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
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

corto_binary _corto_binaryCreate(corto_width width) {
    corto_binary _this;
    _this = corto_binary(corto_declare(corto_binary_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_binary _corto_binaryCreateChild(corto_object _parent, corto_string _name, corto_width width) {
    corto_binary _this;
    _this = corto_binary(corto_declareChild(_parent, _name, corto_binary_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
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

corto_binary _corto_binaryDeclareChild(corto_object _parent, corto_string _name) {
    corto_binary _this;
    _this = corto_binary(corto_declareChild(_parent, _name, corto_binary_o));
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

void _corto_binarySet(corto_binary _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
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
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, corto_string _name) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declareChild(_parent, _name, corto_bitmask_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_bitmaskUpdate(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
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

corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, corto_string _name) {
    corto_bitmask _this;
    _this = corto_bitmask(corto_declareChild(_parent, _name, corto_bitmask_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_bitmaskDefine(corto_bitmask _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

void _corto_bitmaskSet(corto_bitmask _this) {
    CORTO_UNUSED(_this);
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

corto_bool* _corto_boolCreate(corto_bool value) {
    corto_bool* _this;
    _this = corto_bool(corto_declare(corto_bool_o));
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

corto_bool* _corto_boolCreateChild(corto_object _parent, corto_string _name, corto_bool value) {
    corto_bool* _this;
    _this = corto_bool(corto_declareChild(_parent, _name, corto_bool_o));
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

corto_int16 _corto_boolUpdate(corto_bool* _this, corto_bool value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_bool* _corto_boolDeclare(void) {
    corto_bool* _this;
    _this = corto_bool(corto_declare(corto_bool_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_bool* _corto_boolDeclareChild(corto_object _parent, corto_string _name) {
    corto_bool* _this;
    _this = corto_bool(corto_declareChild(_parent, _name, corto_bool_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_boolDefine(corto_bool* _this, corto_bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_boolSet(corto_bool* _this, corto_bool value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_boolStr(corto_bool value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_bool_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_bool* corto_boolFromStr(corto_bool* value, corto_string str) {
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
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_boolean _corto_booleanCreateChild(corto_object _parent, corto_string _name) {
    corto_boolean _this;
    _this = corto_boolean(corto_declareChild(_parent, _name, corto_boolean_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_booleanUpdate(corto_boolean _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
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

corto_boolean _corto_booleanDeclareChild(corto_object _parent, corto_string _name) {
    corto_boolean _this;
    _this = corto_boolean(corto_declareChild(_parent, _name, corto_boolean_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_booleanDefine(corto_boolean _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

void _corto_booleanSet(corto_boolean _this) {
    CORTO_UNUSED(_this);
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

corto_char* _corto_charCreate(corto_char value) {
    corto_char* _this;
    _this = corto_char(corto_declare(corto_char_o));
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

corto_char* _corto_charCreateChild(corto_object _parent, corto_string _name, corto_char value) {
    corto_char* _this;
    _this = corto_char(corto_declareChild(_parent, _name, corto_char_o));
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

corto_int16 _corto_charUpdate(corto_char* _this, corto_char value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_char* _corto_charDeclare(void) {
    corto_char* _this;
    _this = corto_char(corto_declare(corto_char_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_char* _corto_charDeclareChild(corto_object _parent, corto_string _name) {
    corto_char* _this;
    _this = corto_char(corto_declareChild(_parent, _name, corto_char_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_charDefine(corto_char* _this, corto_char value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_charSet(corto_char* _this, corto_char value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_charStr(corto_char value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_char_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_char* corto_charFromStr(corto_char* value, corto_string str) {
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
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_character _corto_characterCreateChild(corto_object _parent, corto_string _name, corto_width width) {
    corto_character _this;
    _this = corto_character(corto_declareChild(_parent, _name, corto_character_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_characterUpdate(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
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

corto_character _corto_characterDeclareChild(corto_object _parent, corto_string _name) {
    corto_character _this;
    _this = corto_character(corto_declareChild(_parent, _name, corto_character_o));
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

void _corto_characterSet(corto_character _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
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
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_class _corto_classCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    corto_class _this;
    _this = corto_class(corto_declareChild(_parent, _name, corto_class_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
        corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
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

corto_class _corto_classDeclareChild(corto_object _parent, corto_string _name) {
    corto_class _this;
    _this = corto_class(corto_declareChild(_parent, _name, corto_class_o));
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

void _corto_classSet(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    corto_copyp(&((corto_class)_this)->implements, corto_interfaceseq_o, &implements);
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

corto_collection _corto_collectionCreate(corto_type elementType, corto_uint32 max) {
    corto_collection _this;
    _this = corto_collection(corto_declare(corto_collection_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_collection _corto_collectionCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max) {
    corto_collection _this;
    _this = corto_collection(corto_declareChild(_parent, _name, corto_collection_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
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

corto_collection _corto_collectionDeclareChild(corto_object _parent, corto_string _name) {
    corto_collection _this;
    _this = corto_collection(corto_declareChild(_parent, _name, corto_collection_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

void _corto_collectionSet(corto_collection _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, corto_string _name, corto_collectionKind value) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declareChild(_parent, _name, corto_collectionKind_o));
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

corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_collectionKind* _this;
    _this = corto_collectionKind(corto_declareChild(_parent, _name, corto_collectionKind_o));
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

void _corto_collectionKindSet(corto_collectionKind* _this, corto_collectionKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, corto_string _name, corto_compositeKind value) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declareChild(_parent, _name, corto_compositeKind_o));
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

corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_compositeKind* _this;
    _this = corto_compositeKind(corto_declareChild(_parent, _name, corto_compositeKind_o));
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

void _corto_compositeKindSet(corto_compositeKind* _this, corto_compositeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
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

corto_constant* _corto_constantCreate(corto_constant value) {
    corto_constant* _this;
    _this = corto_constant(corto_declare(corto_constant_o));
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

corto_constant* _corto_constantCreateChild(corto_object _parent, corto_string _name, corto_constant value) {
    corto_constant* _this;
    _this = corto_constant(corto_declareChild(_parent, _name, corto_constant_o));
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

corto_int16 _corto_constantUpdate(corto_constant* _this, corto_constant value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_constant* _corto_constantDeclare(void) {
    corto_constant* _this;
    _this = corto_constant(corto_declare(corto_constant_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_constant* _corto_constantDeclareChild(corto_object _parent, corto_string _name) {
    corto_constant* _this;
    _this = corto_constant(corto_declareChild(_parent, _name, corto_constant_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_constantDefine(corto_constant* _this, corto_constant value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_constantSet(corto_constant* _this, corto_constant value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_constantStr(corto_constant value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_constant_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_constant* corto_constantFromStr(corto_constant* value, corto_string str) {
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

corto_delegate _corto_delegateCreate(corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = corto_delegate(corto_declare(corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_delegate _corto_delegateCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters) {
    corto_delegate _this;
    _this = corto_delegate(corto_declareChild(_parent, _name, corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_delegate)_this)->returnType, returnType);
        ((corto_delegate)_this)->returnsReference = returnsReference;
        corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
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

corto_delegate _corto_delegateDeclareChild(corto_object _parent, corto_string _name) {
    corto_delegate _this;
    _this = corto_delegate(corto_declareChild(_parent, _name, corto_delegate_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
    return corto_define(_this);
}

void _corto_delegateSet(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegate)_this)->returnType, returnType);
    ((corto_delegate)_this)->returnsReference = returnsReference;
    corto_copyp(&((corto_delegate)_this)->parameters, corto_parameterseq_o, &parameters);
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
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declareChild(_parent, _name, corto_delegatedata_o));
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

corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
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

corto_delegatedata* _corto_delegatedataDeclare(void) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declare(corto_delegatedata_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, corto_string _name) {
    corto_delegatedata* _this;
    _this = corto_delegatedata(corto_declareChild(_parent, _name, corto_delegatedata_o));
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

void _corto_delegatedataSet(corto_delegatedata* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
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
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_destructAction* _corto_destructActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declareChild(_parent, _name, corto_destructAction_o));
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

corto_int16 _corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure) {
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

corto_destructAction* _corto_destructActionDeclare(void) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declare(corto_destructAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_destructAction* _corto_destructActionDeclareChild(corto_object _parent, corto_string _name) {
    corto_destructAction* _this;
    _this = corto_destructAction(corto_declareChild(_parent, _name, corto_destructAction_o));
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

void _corto_destructActionSet(corto_destructAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
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
    if (_delegate->_parent.procedure) {
        if (_delegate->_parent.instance) {
            corto_call(_delegate->_parent.procedure, NULL, _delegate->_parent.instance);
        } else {
            corto_call(_delegate->_parent.procedure, NULL);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_destructActionInitC(corto_destructAction *d, corto_void ___ (*callback)(void)) {
    d->_parent.procedure = corto_functionDeclare();
    void __corto_destructAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_destructAction;
    corto_function_parseParamString(d->_parent.procedure, "()");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int16 corto_destructActionInitCInstance(corto_destructAction *d, corto_object instance, corto_void ___ (*callback)(corto_object)) {
    d->_parent.instance = instance;
    corto_claim(instance);
    d->_parent.procedure = corto_functionDeclare();
    void __corto_destructAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_destructAction;
    corto_function_parseParamString(d->_parent.procedure, "(object instance)");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_enum _corto_enumCreate(void) {
    corto_enum _this;
    _this = corto_enum(corto_declare(corto_enum_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_enum _corto_enumCreateChild(corto_object _parent, corto_string _name) {
    corto_enum _this;
    _this = corto_enum(corto_declareChild(_parent, _name, corto_enum_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_enumUpdate(corto_enum _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
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

corto_enum _corto_enumDeclareChild(corto_object _parent, corto_string _name) {
    corto_enum _this;
    _this = corto_enum(corto_declareChild(_parent, _name, corto_enum_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_enumDefine(corto_enum _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

void _corto_enumSet(corto_enum _this) {
    CORTO_UNUSED(_this);
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _name, corto_equalityKind value) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declareChild(_parent, _name, corto_equalityKind_o));
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

corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_equalityKind* _this;
    _this = corto_equalityKind(corto_declareChild(_parent, _name, corto_equalityKind_o));
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

void _corto_equalityKindSet(corto_equalityKind* _this, corto_equalityKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
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

corto_float _corto_floatCreate(corto_width width, corto_float64 min, corto_float64 max) {
    corto_float _this;
    _this = corto_float(corto_declare(corto_float_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_float _corto_floatCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_float64 min, corto_float64 max) {
    corto_float _this;
    _this = corto_float(corto_declareChild(_parent, _name, corto_float_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, corto_float64 min, corto_float64 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
        ((corto_float)_this)->min = min;
        ((corto_float)_this)->max = max;
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

corto_float _corto_floatDeclareChild(corto_object _parent, corto_string _name) {
    corto_float _this;
    _this = corto_float(corto_declareChild(_parent, _name, corto_float_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_floatDefine(corto_float _this, corto_width width, corto_float64 min, corto_float64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
    return corto_define(_this);
}

void _corto_floatSet(corto_float _this, corto_width width, corto_float64 min, corto_float64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_float)_this)->min = min;
    ((corto_float)_this)->max = max;
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

corto_float32* _corto_float32Create(corto_float32 value) {
    corto_float32* _this;
    _this = corto_float32(corto_declare(corto_float32_o));
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

corto_float32* _corto_float32CreateChild(corto_object _parent, corto_string _name, corto_float32 value) {
    corto_float32* _this;
    _this = corto_float32(corto_declareChild(_parent, _name, corto_float32_o));
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

corto_int16 _corto_float32Update(corto_float32* _this, corto_float32 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_float32* _corto_float32Declare(void) {
    corto_float32* _this;
    _this = corto_float32(corto_declare(corto_float32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_float32* _corto_float32DeclareChild(corto_object _parent, corto_string _name) {
    corto_float32* _this;
    _this = corto_float32(corto_declareChild(_parent, _name, corto_float32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float32Define(corto_float32* _this, corto_float32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_float32Set(corto_float32* _this, corto_float32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_float32Str(corto_float32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_float32* corto_float32FromStr(corto_float32* value, corto_string str) {
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

corto_float64* _corto_float64Create(corto_float64 value) {
    corto_float64* _this;
    _this = corto_float64(corto_declare(corto_float64_o));
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

corto_float64* _corto_float64CreateChild(corto_object _parent, corto_string _name, corto_float64 value) {
    corto_float64* _this;
    _this = corto_float64(corto_declareChild(_parent, _name, corto_float64_o));
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

corto_int16 _corto_float64Update(corto_float64* _this, corto_float64 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_float64* _corto_float64Declare(void) {
    corto_float64* _this;
    _this = corto_float64(corto_declare(corto_float64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_float64* _corto_float64DeclareChild(corto_object _parent, corto_string _name) {
    corto_float64* _this;
    _this = corto_float64(corto_declareChild(_parent, _name, corto_float64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_float64Define(corto_float64* _this, corto_float64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_float64Set(corto_float64* _this, corto_float64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_float64Str(corto_float64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_float64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_float64* corto_float64FromStr(corto_float64* value, corto_string str) {
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

corto_function _corto_functionCreate(corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_function _this;
    _this = corto_function(corto_declare(corto_function_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_function _corto_functionCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_function _this;
    _this = corto_function(corto_declareChild(_parent, _name, corto_function_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        corto_function(_this)->impl = (corto_word)_impl;
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

corto_function _corto_functionDeclareChild(corto_object _parent, corto_string _name) {
    corto_function _this;
    _this = corto_function(corto_declareChild(_parent, _name, corto_function_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->impl = (corto_word)_impl;
    return corto_define(_this);
}

void _corto_functionSet(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    corto_function(_this)->impl = (corto_word)_impl;
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
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_initAction* _corto_initActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declareChild(_parent, _name, corto_initAction_o));
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

corto_int16 _corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure) {
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

corto_initAction* _corto_initActionDeclare(void) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declare(corto_initAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_initAction* _corto_initActionDeclareChild(corto_object _parent, corto_string _name) {
    corto_initAction* _this;
    _this = corto_initAction(corto_declareChild(_parent, _name, corto_initAction_o));
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

void _corto_initActionSet(corto_initAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
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
    if (_delegate->_parent.procedure) {
        if (_delegate->_parent.instance) {
            corto_call(_delegate->_parent.procedure, _result, _delegate->_parent.instance);
        } else {
            corto_call(_delegate->_parent.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_initActionInitC(corto_initAction *d, corto_int16 ___ (*callback)(void)) {
    d->_parent.procedure = corto_functionDeclare();
    void __corto_initAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_initAction;
    corto_function_parseParamString(d->_parent.procedure, "()");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int16 corto_initActionInitCInstance(corto_initAction *d, corto_object instance, corto_int16 ___ (*callback)(corto_object)) {
    d->_parent.instance = instance;
    corto_claim(instance);
    d->_parent.procedure = corto_functionDeclare();
    void __corto_initAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_initAction;
    corto_function_parseParamString(d->_parent.procedure, "(object instance)");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int _corto_intCreate(corto_width width, corto_int64 min, corto_int64 max) {
    corto_int _this;
    _this = corto_int(corto_declare(corto_int_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int _corto_intCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_int64 min, corto_int64 max) {
    corto_int _this;
    _this = corto_int(corto_declareChild(_parent, _name, corto_int_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_intUpdate(corto_int _this, corto_width width, corto_int64 min, corto_int64 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
        ((corto_int)_this)->min = min;
        ((corto_int)_this)->max = max;
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

corto_int _corto_intDeclareChild(corto_object _parent, corto_string _name) {
    corto_int _this;
    _this = corto_int(corto_declareChild(_parent, _name, corto_int_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_intDefine(corto_int _this, corto_width width, corto_int64 min, corto_int64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
    return corto_define(_this);
}

void _corto_intSet(corto_int _this, corto_width width, corto_int64 min, corto_int64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_int)_this)->min = min;
    ((corto_int)_this)->max = max;
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

corto_int16* _corto_int16Create(corto_int16 value) {
    corto_int16* _this;
    _this = corto_int16(corto_declare(corto_int16_o));
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

corto_int16* _corto_int16CreateChild(corto_object _parent, corto_string _name, corto_int16 value) {
    corto_int16* _this;
    _this = corto_int16(corto_declareChild(_parent, _name, corto_int16_o));
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

corto_int16 _corto_int16Update(corto_int16* _this, corto_int16 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int16* _corto_int16Declare(void) {
    corto_int16* _this;
    _this = corto_int16(corto_declare(corto_int16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16* _corto_int16DeclareChild(corto_object _parent, corto_string _name) {
    corto_int16* _this;
    _this = corto_int16(corto_declareChild(_parent, _name, corto_int16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int16Define(corto_int16* _this, corto_int16 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_int16Set(corto_int16* _this, corto_int16 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_int16Str(corto_int16 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int16_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int16* corto_int16FromStr(corto_int16* value, corto_string str) {
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

corto_int32* _corto_int32Create(corto_int32 value) {
    corto_int32* _this;
    _this = corto_int32(corto_declare(corto_int32_o));
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

corto_int32* _corto_int32CreateChild(corto_object _parent, corto_string _name, corto_int32 value) {
    corto_int32* _this;
    _this = corto_int32(corto_declareChild(_parent, _name, corto_int32_o));
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

corto_int16 _corto_int32Update(corto_int32* _this, corto_int32 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int32* _corto_int32Declare(void) {
    corto_int32* _this;
    _this = corto_int32(corto_declare(corto_int32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int32* _corto_int32DeclareChild(corto_object _parent, corto_string _name) {
    corto_int32* _this;
    _this = corto_int32(corto_declareChild(_parent, _name, corto_int32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int32Define(corto_int32* _this, corto_int32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_int32Set(corto_int32* _this, corto_int32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_int32Str(corto_int32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int32* corto_int32FromStr(corto_int32* value, corto_string str) {
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

corto_int64* _corto_int64Create(corto_int64 value) {
    corto_int64* _this;
    _this = corto_int64(corto_declare(corto_int64_o));
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

corto_int64* _corto_int64CreateChild(corto_object _parent, corto_string _name, corto_int64 value) {
    corto_int64* _this;
    _this = corto_int64(corto_declareChild(_parent, _name, corto_int64_o));
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

corto_int16 _corto_int64Update(corto_int64* _this, corto_int64 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int64* _corto_int64Declare(void) {
    corto_int64* _this;
    _this = corto_int64(corto_declare(corto_int64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int64* _corto_int64DeclareChild(corto_object _parent, corto_string _name) {
    corto_int64* _this;
    _this = corto_int64(corto_declareChild(_parent, _name, corto_int64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int64Define(corto_int64* _this, corto_int64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_int64Set(corto_int64* _this, corto_int64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_int64Str(corto_int64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int64* corto_int64FromStr(corto_int64* value, corto_string str) {
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

corto_int8* _corto_int8Create(corto_int8 value) {
    corto_int8* _this;
    _this = corto_int8(corto_declare(corto_int8_o));
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

corto_int8* _corto_int8CreateChild(corto_object _parent, corto_string _name, corto_int8 value) {
    corto_int8* _this;
    _this = corto_int8(corto_declareChild(_parent, _name, corto_int8_o));
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

corto_int16 _corto_int8Update(corto_int8* _this, corto_int8 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_int8* _corto_int8Declare(void) {
    corto_int8* _this;
    _this = corto_int8(corto_declare(corto_int8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int8* _corto_int8DeclareChild(corto_object _parent, corto_string _name) {
    corto_int8* _this;
    _this = corto_int8(corto_declareChild(_parent, _name, corto_int8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_int8Define(corto_int8* _this, corto_int8 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_int8Set(corto_int8* _this, corto_int8 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_int8Str(corto_int8 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_int8_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_int8* corto_int8FromStr(corto_int8* value, corto_string str) {
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
    corto_setref(&((corto_interface)_this)->base, base);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_interface _corto_interfaceCreateChild(corto_object _parent, corto_string _name, corto_interface base) {
    corto_interface _this;
    _this = corto_interface(corto_declareChild(_parent, _name, corto_interface_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interface)_this)->base, base);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_interface)_this)->base, base);
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

corto_interface _corto_interfaceDeclareChild(corto_object _parent, corto_string _name) {
    corto_interface _this;
    _this = corto_interface(corto_declareChild(_parent, _name, corto_interface_o));
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

void _corto_interfaceSet(corto_interface _this, corto_interface base) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
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
    corto_interfaceseqSize(_this, length);
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

corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_interface* elements) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declareChild(_parent, _name, corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    corto_interfaceseqSize(_this, length);
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

corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_interfaceseqSize(_this, length);
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

corto_interfaceseq* _corto_interfaceseqDeclare(void) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declare(corto_interfaceseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_interfaceseq* _this;
    _this = corto_interfaceseq(corto_declareChild(_parent, _name, corto_interfaceseq_o));
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

void _corto_interfaceseqSet(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
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

corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_vtable vector) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declare(corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_vtable_o, &vector);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, corto_string _name, corto_interface interface, corto_vtable vector) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declareChild(_parent, _name, corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_vtable_o, &vector);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
        corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_vtable_o, &vector);
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

corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _name) {
    corto_interfaceVector* _this;
    _this = corto_interfaceVector(corto_declareChild(_parent, _name, corto_interfaceVector_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_vtable_o, &vector);
    return corto_define(_this);
}

void _corto_interfaceVectorSet(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interfaceVector*)_this)->interface, interface);
    corto_copyp(&((corto_interfaceVector*)_this)->vector, corto_vtable_o, &vector);
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
    corto_interfaceVectorseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_interfaceVector* elements) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declareChild(_parent, _name, corto_interfaceVectorseq_o));
    if (!_this) {
        return NULL;
    }
    corto_interfaceVectorseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_interfaceVectorseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
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

corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_interfaceVectorseq* _this;
    _this = corto_interfaceVectorseq(corto_declareChild(_parent, _name, corto_interfaceVectorseq_o));
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
        corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
    }
    return corto_define(_this);
}

void _corto_interfaceVectorseqSet(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements) {
    CORTO_UNUSED(_this);
    corto_interfaceVectorseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_interfaceVector_o, &elements[i]);
    }
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
    corto_setref(&((corto_iterator)_this)->elementType, elementType);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_iterator _corto_iteratorCreateChild(corto_object _parent, corto_string _name, corto_type elementType) {
    corto_iterator _this;
    _this = corto_iterator(corto_declareChild(_parent, _name, corto_iterator_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_iterator)_this)->elementType, elementType);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_iterator)_this)->elementType, elementType);
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

corto_iterator _corto_iteratorDeclareChild(corto_object _parent, corto_string _name) {
    corto_iterator _this;
    _this = corto_iterator(corto_declareChild(_parent, _name, corto_iterator_o));
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

void _corto_iteratorSet(corto_iterator _this, corto_type elementType) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_iterator)_this)->elementType, elementType);
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

corto_list _corto_listCreate(corto_type elementType, corto_uint32 max) {
    corto_list _this;
    _this = corto_list(corto_declare(corto_list_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_list _corto_listCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max) {
    corto_list _this;
    _this = corto_list(corto_declareChild(_parent, _name, corto_list_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
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

corto_list _corto_listDeclareChild(corto_object _parent, corto_string _name) {
    corto_list _this;
    _this = corto_list(corto_declareChild(_parent, _name, corto_list_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

void _corto_listSet(corto_list _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
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

corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, corto_uint32 max) {
    corto_map _this;
    _this = corto_map(corto_declare(corto_map_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_map _corto_mapCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_type keyType, corto_uint32 max) {
    corto_map _this;
    _this = corto_map(corto_declareChild(_parent, _name, corto_map_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_map)_this)->elementType, elementType);
        corto_setref(&((corto_map)_this)->keyType, keyType);
        ((corto_map)_this)->max = max;
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

corto_map _corto_mapDeclareChild(corto_object _parent, corto_string _name) {
    corto_map _this;
    _this = corto_map(corto_declareChild(_parent, _name, corto_map_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
    return corto_define(_this);
}

void _corto_mapSet(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_map)_this)->elementType, elementType);
    corto_setref(&((corto_map)_this)->keyType, keyType);
    ((corto_map)_this)->max = max;
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
    corto_setref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_member _corto_memberCreateChild(corto_object _parent, corto_string _name, corto_type type, corto_modifier modifiers) {
    corto_member _this;
    _this = corto_member(corto_declareChild(_parent, _name, corto_member_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_member)_this)->type, type);
        ((corto_member)_this)->modifiers = modifiers;
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

corto_member _corto_memberDeclareChild(corto_object _parent, corto_string _name) {
    corto_member _this;
    _this = corto_member(corto_declareChild(_parent, _name, corto_member_o));
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

void _corto_memberSet(corto_member _this, corto_type type, corto_modifier modifiers) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_member)_this)->type, type);
    ((corto_member)_this)->modifiers = modifiers;
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

corto_memberseq* _corto_memberseqCreate(corto_uint32 length, corto_member* elements) {
    corto_memberseq* _this;
    _this = corto_memberseq(corto_declare(corto_memberseq_o));
    if (!_this) {
        return NULL;
    }
    corto_memberseqSize(_this, length);
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

corto_memberseq* _corto_memberseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_member* elements) {
    corto_memberseq* _this;
    _this = corto_memberseq(corto_declareChild(_parent, _name, corto_memberseq_o));
    if (!_this) {
        return NULL;
    }
    corto_memberseqSize(_this, length);
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

corto_int16 _corto_memberseqUpdate(corto_memberseq* _this, corto_uint32 length, corto_member* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_memberseqSize(_this, length);
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

corto_memberseq* _corto_memberseqDeclare(void) {
    corto_memberseq* _this;
    _this = corto_memberseq(corto_declare(corto_memberseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_memberseq* _corto_memberseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_memberseq* _this;
    _this = corto_memberseq(corto_declareChild(_parent, _name, corto_memberseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_memberseqDefine(corto_memberseq* _this, corto_uint32 length, corto_member* elements) {
    CORTO_UNUSED(_this);
    corto_memberseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

void _corto_memberseqSet(corto_memberseq* _this, corto_uint32 length, corto_member* elements) {
    CORTO_UNUSED(_this);
    corto_memberseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
}

corto_string _corto_memberseqStr(corto_memberseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_memberseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_memberseq* corto_memberseqFromStr(corto_memberseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_memberseq_o), str);
    return value;
}

corto_equalityKind corto_memberseqCompare(corto_memberseq dst, corto_memberseq src) {
    return corto_comparep(&dst, corto_memberseq_o, &src);
}

corto_int16 _corto_memberseqInit(corto_memberseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_memberseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_memberseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_memberseqDeinit(corto_memberseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_memberseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declare(corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declareChild(_parent, _name, corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
        corto_function(_this)->impl = (corto_word)_impl;
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

corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, corto_string _name) {
    corto_metaprocedure _this;
    _this = corto_metaprocedure(corto_declareChild(_parent, _name, corto_metaprocedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->impl = (corto_word)_impl;
    return corto_define(_this);
}

void _corto_metaprocedureSet(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_metaprocedure)_this)->referenceOnly = referenceOnly;
    corto_function(_this)->impl = (corto_word)_impl;
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

corto_method _corto_methodCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_method _this;
    _this = corto_method(corto_declare(corto_method_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_method _corto_methodCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_method _this;
    _this = corto_method(corto_declareChild(_parent, _name, corto_method_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_method)_this)->_virtual = _virtual;
        corto_function(_this)->impl = (corto_word)_impl;
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

corto_method _corto_methodDeclareChild(corto_object _parent, corto_string _name) {
    corto_method _this;
    _this = corto_method(corto_declareChild(_parent, _name, corto_method_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    return corto_define(_this);
}

void _corto_methodSet(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_modifier* _corto_modifierCreateChild(corto_object _parent, corto_string _name, corto_modifier value) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declareChild(_parent, _name, corto_modifier_o));
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

corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_modifier* _corto_modifierDeclareChild(corto_object _parent, corto_string _name) {
    corto_modifier* _this;
    _this = corto_modifier(corto_declareChild(_parent, _name, corto_modifier_o));
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

void _corto_modifierSet(corto_modifier* _this, corto_modifier value) {
    CORTO_UNUSED(_this);
    *_this = value;
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
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_nameAction* _corto_nameActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declareChild(_parent, _name, corto_nameAction_o));
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

corto_int16 _corto_nameActionUpdate(corto_nameAction* _this, corto_object instance, corto_function procedure) {
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

corto_nameAction* _corto_nameActionDeclare(void) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declare(corto_nameAction_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_nameAction* _corto_nameActionDeclareChild(corto_object _parent, corto_string _name) {
    corto_nameAction* _this;
    _this = corto_nameAction(corto_declareChild(_parent, _name, corto_nameAction_o));
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

void _corto_nameActionSet(corto_nameAction* _this, corto_object instance, corto_function procedure) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_delegatedata*)_this)->instance, instance);
    corto_setref(&((corto_delegatedata*)_this)->procedure, procedure);
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
    if (_delegate->_parent.procedure) {
        if (_delegate->_parent.instance) {
            corto_call(_delegate->_parent.procedure, _result, _delegate->_parent.instance);
        } else {
            corto_call(_delegate->_parent.procedure, _result);
        }
    } else {
        return -1;
    }
    return 0;
}

corto_int16 corto_nameActionInitC(corto_nameAction *d, corto_string ___ (*callback)(void)) {
    d->_parent.procedure = corto_functionDeclare();
    void __corto_nameAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_nameAction;
    corto_function_parseParamString(d->_parent.procedure, "()");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_int16 corto_nameActionInitCInstance(corto_nameAction *d, corto_object instance, corto_string ___ (*callback)(corto_object)) {
    d->_parent.instance = instance;
    corto_claim(instance);
    d->_parent.procedure = corto_functionDeclare();
    void __corto_nameAction(corto_function f, void *result, void *args);
    d->_parent.procedure->impl = (corto_word)__corto_nameAction;
    corto_function_parseParamString(d->_parent.procedure, "(object instance)");
    d->_parent.procedure->implData = (corto_word)callback;
    corto_define(d->_parent.procedure);
    return 0;
}

corto_object _corto_objectCreate(void) {
    corto_object _this;
    _this = corto_object(corto_declare(corto_object_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_object _corto_objectCreateChild(corto_object _parent, corto_string _name) {
    corto_object _this;
    _this = corto_object(corto_declareChild(_parent, _name, corto_object_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_objectUpdate(corto_object _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_objectseq* _corto_objectseqCreate(corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declare(corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    corto_objectseqSize(_this, length);
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

corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_object* elements) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declareChild(_parent, _name, corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    corto_objectseqSize(_this, length);
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

corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_objectseqSize(_this, length);
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

corto_objectseq* _corto_objectseqDeclare(void) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declare(corto_objectseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_objectseq* _this;
    _this = corto_objectseq(corto_declareChild(_parent, _name, corto_objectseq_o));
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

void _corto_objectseqSet(corto_objectseq* _this, corto_uint32 length, corto_object* elements) {
    CORTO_UNUSED(_this);
    corto_objectseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
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

corto_octet* _corto_octetCreate(corto_octet value) {
    corto_octet* _this;
    _this = corto_octet(corto_declare(corto_octet_o));
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

corto_octet* _corto_octetCreateChild(corto_object _parent, corto_string _name, corto_octet value) {
    corto_octet* _this;
    _this = corto_octet(corto_declareChild(_parent, _name, corto_octet_o));
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

corto_int16 _corto_octetUpdate(corto_octet* _this, corto_octet value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_octet* _corto_octetDeclare(void) {
    corto_octet* _this;
    _this = corto_octet(corto_declare(corto_octet_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_octet* _corto_octetDeclareChild(corto_object _parent, corto_string _name) {
    corto_octet* _this;
    _this = corto_octet(corto_declareChild(_parent, _name, corto_octet_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_octetDefine(corto_octet* _this, corto_octet value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_octetSet(corto_octet* _this, corto_octet value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_octetStr(corto_octet value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_octet_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_octet* corto_octetFromStr(corto_octet* value, corto_string str) {
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

corto_octetseq* _corto_octetseqCreate(corto_uint32 length, corto_octet* elements) {
    corto_octetseq* _this;
    _this = corto_octetseq(corto_declare(corto_octetseq_o));
    if (!_this) {
        return NULL;
    }
    corto_octetseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_octetseq* _corto_octetseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_octet* elements) {
    corto_octetseq* _this;
    _this = corto_octetseq(corto_declareChild(_parent, _name, corto_octetseq_o));
    if (!_this) {
        return NULL;
    }
    corto_octetseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_octetseqUpdate(corto_octetseq* _this, corto_uint32 length, corto_octet* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_octetseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            _this->buffer[i] = elements[i];
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_octetseq* _corto_octetseqDeclare(void) {
    corto_octetseq* _this;
    _this = corto_octetseq(corto_declare(corto_octetseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_octetseq* _corto_octetseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_octetseq* _this;
    _this = corto_octetseq(corto_declareChild(_parent, _name, corto_octetseq_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_octetseqDefine(corto_octetseq* _this, corto_uint32 length, corto_octet* elements) {
    CORTO_UNUSED(_this);
    corto_octetseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
    return corto_define(_this);
}

void _corto_octetseqSet(corto_octetseq* _this, corto_uint32 length, corto_octet* elements) {
    CORTO_UNUSED(_this);
    corto_octetseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        _this->buffer[i] = elements[i];
    }
}

corto_string _corto_octetseqStr(corto_octetseq value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_octetseq_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_octetseq* corto_octetseqFromStr(corto_octetseq* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_octetseq_o), str);
    return value;
}

corto_equalityKind corto_octetseqCompare(corto_octetseq dst, corto_octetseq src) {
    return corto_comparep(&dst, corto_octetseq_o, &src);
}

corto_int16 _corto_octetseqInit(corto_octetseq* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_octetseq_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_octetseq_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_octetseqDeinit(corto_octetseq* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_octetseq_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_parameter* _corto_parameterCreate(corto_string name, corto_type type, corto_bool passByReference) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declare(corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->passByReference = passByReference;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_parameter* _corto_parameterCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_type type, corto_bool passByReference) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declareChild(_parent, _name, corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->passByReference = passByReference;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(&((corto_parameter*)_this)->name, name);
        corto_setref(&((corto_parameter*)_this)->type, type);
        ((corto_parameter*)_this)->passByReference = passByReference;
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

corto_parameter* _corto_parameterDeclareChild(corto_object _parent, corto_string _name) {
    corto_parameter* _this;
    _this = corto_parameter(corto_declareChild(_parent, _name, corto_parameter_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->passByReference = passByReference;
    return corto_define(_this);
}

void _corto_parameterSet(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference) {
    CORTO_UNUSED(_this);
    corto_setstr(&((corto_parameter*)_this)->name, name);
    corto_setref(&((corto_parameter*)_this)->type, type);
    ((corto_parameter*)_this)->passByReference = passByReference;
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
    corto_parameterseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_parameter* elements) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declareChild(_parent, _name, corto_parameterseq_o));
    if (!_this) {
        return NULL;
    }
    corto_parameterseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_parameterseqSize(_this, length);
        corto_uint32 i = 0;
        for (i = 0; i < length; i ++) {
            corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
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

corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, corto_string _name) {
    corto_parameterseq* _this;
    _this = corto_parameterseq(corto_declareChild(_parent, _name, corto_parameterseq_o));
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
        corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
    }
    return corto_define(_this);
}

void _corto_parameterseqSet(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements) {
    CORTO_UNUSED(_this);
    corto_parameterseqSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_copyp(&_this->buffer[i], corto_parameter_o, &elements[i]);
    }
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
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_primitive _corto_primitiveCreateChild(corto_object _parent, corto_string _name, corto_width width) {
    corto_primitive _this;
    _this = corto_primitive(corto_declareChild(_parent, _name, corto_primitive_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
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

corto_primitive _corto_primitiveDeclareChild(corto_object _parent, corto_string _name) {
    corto_primitive _this;
    _this = corto_primitive(corto_declareChild(_parent, _name, corto_primitive_o));
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

void _corto_primitiveSet(corto_primitive _this, corto_width width) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, corto_string _name, corto_primitiveKind value) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declareChild(_parent, _name, corto_primitiveKind_o));
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

corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_primitiveKind* _this;
    _this = corto_primitiveKind(corto_declareChild(_parent, _name, corto_primitiveKind_o));
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

void _corto_primitiveKindSet(corto_primitiveKind* _this, corto_primitiveKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
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

corto_procedure _corto_procedureCreate(corto_procedureKind kind_1) {
    corto_procedure _this;
    _this = corto_procedure(corto_declare(corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    ((corto_procedure)_this)->kind = kind_1;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_procedure _corto_procedureCreateChild(corto_object _parent, corto_string _name, corto_procedureKind kind_1) {
    corto_procedure _this;
    _this = corto_procedure(corto_declareChild(_parent, _name, corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    ((corto_procedure)_this)->kind = kind_1;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_procedureUpdate(corto_procedure _this, corto_procedureKind kind_1) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_procedure)_this)->kind = kind_1;
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

corto_procedure _corto_procedureDeclareChild(corto_object _parent, corto_string _name) {
    corto_procedure _this;
    _this = corto_procedure(corto_declareChild(_parent, _name, corto_procedure_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_procedureDefine(corto_procedure _this, corto_procedureKind kind_1) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->kind = kind_1;
    return corto_define(_this);
}

void _corto_procedureSet(corto_procedure _this, corto_procedureKind kind_1) {
    CORTO_UNUSED(_this);
    ((corto_procedure)_this)->kind = kind_1;
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

corto_procedureKind* _corto_procedureKindCreate(corto_procedureKind value) {
    corto_procedureKind* _this;
    _this = corto_procedureKind(corto_declare(corto_procedureKind_o));
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

corto_procedureKind* _corto_procedureKindCreateChild(corto_object _parent, corto_string _name, corto_procedureKind value) {
    corto_procedureKind* _this;
    _this = corto_procedureKind(corto_declareChild(_parent, _name, corto_procedureKind_o));
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

corto_int16 _corto_procedureKindUpdate(corto_procedureKind* _this, corto_procedureKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_procedureKind* _corto_procedureKindDeclare(void) {
    corto_procedureKind* _this;
    _this = corto_procedureKind(corto_declare(corto_procedureKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_procedureKind* _corto_procedureKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_procedureKind* _this;
    _this = corto_procedureKind(corto_declareChild(_parent, _name, corto_procedureKind_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_procedureKindDefine(corto_procedureKind* _this, corto_procedureKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_procedureKindSet(corto_procedureKind* _this, corto_procedureKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_procedureKindStr(corto_procedureKind value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_procedureKind_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_procedureKind* corto_procedureKindFromStr(corto_procedureKind* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_procedureKind_o), str);
    return value;
}

corto_equalityKind corto_procedureKindCompare(corto_procedureKind dst, corto_procedureKind src) {
    return corto_comparep(&dst, corto_procedureKind_o, &src);
}

corto_int16 _corto_procedureKindInit(corto_procedureKind* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_procedureKind_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_procedureKind_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_procedureKindDeinit(corto_procedureKind* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_procedureKind_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_sequence _corto_sequenceCreate(corto_type elementType, corto_uint32 max) {
    corto_sequence _this;
    _this = corto_sequence(corto_declare(corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_sequence _corto_sequenceCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max) {
    corto_sequence _this;
    _this = corto_sequence(corto_declareChild(_parent, _name, corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_collection)_this)->elementType, elementType);
        ((corto_collection)_this)->max = max;
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

corto_sequence _corto_sequenceDeclareChild(corto_object _parent, corto_string _name) {
    corto_sequence _this;
    _this = corto_sequence(corto_declareChild(_parent, _name, corto_sequence_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
    return corto_define(_this);
}

void _corto_sequenceSet(corto_sequence _this, corto_type elementType, corto_uint32 max) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_collection)_this)->elementType, elementType);
    ((corto_collection)_this)->max = max;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_state* _corto_stateCreateChild(corto_object _parent, corto_string _name, corto_state value) {
    corto_state* _this;
    _this = corto_state(corto_declareChild(_parent, _name, corto_state_o));
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

corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_state* _corto_stateDeclareChild(corto_object _parent, corto_string _name) {
    corto_state* _this;
    _this = corto_state(corto_declareChild(_parent, _name, corto_state_o));
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

void _corto_stateSet(corto_state* _this, corto_state value) {
    CORTO_UNUSED(_this);
    *_this = value;
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
    corto_setstr(_this, value);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_string* _corto_stringCreateChild(corto_object _parent, corto_string _name, corto_string value) {
    corto_string* _this;
    _this = corto_string(corto_declareChild(_parent, _name, corto_string_o));
    if (!_this) {
        return NULL;
    }
    corto_setstr(_this, value);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setstr(_this, value);
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

corto_string* _corto_stringDeclareChild(corto_object _parent, corto_string _name) {
    corto_string* _this;
    _this = corto_string(corto_declareChild(_parent, _name, corto_string_o));
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

void _corto_stringSet(corto_string* _this, corto_string value) {
    CORTO_UNUSED(_this);
    corto_setstr(_this, value);
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

corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = corto_struct(corto_declare(corto_struct_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_struct _corto_structCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess) {
    corto_struct _this;
    _this = corto_struct(corto_declareChild(_parent, _name, corto_struct_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_interface)_this)->base, base);
        ((corto_struct)_this)->baseAccess = baseAccess;
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

corto_struct _corto_structDeclareChild(corto_object _parent, corto_string _name) {
    corto_struct _this;
    _this = corto_struct(corto_declareChild(_parent, _name, corto_struct_o));
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

void _corto_structSet(corto_struct _this, corto_interface base, corto_modifier baseAccess) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_interface)_this)->base, base);
    ((corto_struct)_this)->baseAccess = baseAccess;
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

corto_text _corto_textCreate(corto_width charWidth, corto_uint64 length) {
    corto_text _this;
    _this = corto_text(corto_declare(corto_text_o));
    if (!_this) {
        return NULL;
    }
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_text _corto_textCreateChild(corto_object _parent, corto_string _name, corto_width charWidth, corto_uint64 length) {
    corto_text _this;
    _this = corto_text(corto_declareChild(_parent, _name, corto_text_o));
    if (!_this) {
        return NULL;
    }
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, corto_uint64 length) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_text)_this)->charWidth = charWidth;
        ((corto_text)_this)->length = length;
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

corto_text _corto_textDeclareChild(corto_object _parent, corto_string _name) {
    corto_text _this;
    _this = corto_text(corto_declareChild(_parent, _name, corto_text_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, corto_uint64 length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
    return corto_define(_this);
}

void _corto_textSet(corto_text _this, corto_width charWidth, corto_uint64 length) {
    CORTO_UNUSED(_this);
    ((corto_text)_this)->charWidth = charWidth;
    ((corto_text)_this)->length = length;
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

corto_type _corto_typeCreate(corto_typeKind kind, corto_bool reference) {
    corto_type _this;
    _this = corto_type(corto_declare(corto_type_o));
    if (!_this) {
        return NULL;
    }
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_type _corto_typeCreateChild(corto_object _parent, corto_string _name, corto_typeKind kind, corto_bool reference) {
    corto_type _this;
    _this = corto_type(corto_declareChild(_parent, _name, corto_type_o));
    if (!_this) {
        return NULL;
    }
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_typeUpdate(corto_type _this, corto_typeKind kind, corto_bool reference) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_type)_this)->kind = kind;
        ((corto_type)_this)->reference = reference;
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

corto_type _corto_typeDeclareChild(corto_object _parent, corto_string _name) {
    corto_type _this;
    _this = corto_type(corto_declareChild(_parent, _name, corto_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_typeDefine(corto_type _this, corto_typeKind kind, corto_bool reference) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
    return corto_define(_this);
}

void _corto_typeSet(corto_type _this, corto_typeKind kind, corto_bool reference) {
    CORTO_UNUSED(_this);
    ((corto_type)_this)->kind = kind;
    ((corto_type)_this)->reference = reference;
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
    *_this = value;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, corto_string _name, corto_typeKind value) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declareChild(_parent, _name, corto_typeKind_o));
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

corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, corto_string _name) {
    corto_typeKind* _this;
    _this = corto_typeKind(corto_declareChild(_parent, _name, corto_typeKind_o));
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

void _corto_typeKindSet(corto_typeKind* _this, corto_typeKind value) {
    CORTO_UNUSED(_this);
    *_this = value;
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

corto_uint _corto_uintCreate(corto_width width, corto_uint64 min, corto_uint64 max) {
    corto_uint _this;
    _this = corto_uint(corto_declare(corto_uint_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_uint _corto_uintCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_uint64 min, corto_uint64 max) {
    corto_uint _this;
    _this = corto_uint(corto_declareChild(_parent, _name, corto_uint_o));
    if (!_this) {
        return NULL;
    }
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((corto_primitive)_this)->width = width;
        ((corto_uint)_this)->min = min;
        ((corto_uint)_this)->max = max;
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

corto_uint _corto_uintDeclareChild(corto_object _parent, corto_string _name) {
    corto_uint _this;
    _this = corto_uint(corto_declareChild(_parent, _name, corto_uint_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
    return corto_define(_this);
}

void _corto_uintSet(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max) {
    CORTO_UNUSED(_this);
    ((corto_primitive)_this)->width = width;
    ((corto_uint)_this)->min = min;
    ((corto_uint)_this)->max = max;
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

corto_uint16* _corto_uint16Create(corto_uint16 value) {
    corto_uint16* _this;
    _this = corto_uint16(corto_declare(corto_uint16_o));
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

corto_uint16* _corto_uint16CreateChild(corto_object _parent, corto_string _name, corto_uint16 value) {
    corto_uint16* _this;
    _this = corto_uint16(corto_declareChild(_parent, _name, corto_uint16_o));
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

corto_int16 _corto_uint16Update(corto_uint16* _this, corto_uint16 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_uint16* _corto_uint16Declare(void) {
    corto_uint16* _this;
    _this = corto_uint16(corto_declare(corto_uint16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint16* _corto_uint16DeclareChild(corto_object _parent, corto_string _name) {
    corto_uint16* _this;
    _this = corto_uint16(corto_declareChild(_parent, _name, corto_uint16_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint16Define(corto_uint16* _this, corto_uint16 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_uint16Set(corto_uint16* _this, corto_uint16 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_uint16Str(corto_uint16 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint16_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_uint16* corto_uint16FromStr(corto_uint16* value, corto_string str) {
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

corto_uint32* _corto_uint32Create(corto_uint32 value) {
    corto_uint32* _this;
    _this = corto_uint32(corto_declare(corto_uint32_o));
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

corto_uint32* _corto_uint32CreateChild(corto_object _parent, corto_string _name, corto_uint32 value) {
    corto_uint32* _this;
    _this = corto_uint32(corto_declareChild(_parent, _name, corto_uint32_o));
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

corto_int16 _corto_uint32Update(corto_uint32* _this, corto_uint32 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_uint32* _corto_uint32Declare(void) {
    corto_uint32* _this;
    _this = corto_uint32(corto_declare(corto_uint32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint32* _corto_uint32DeclareChild(corto_object _parent, corto_string _name) {
    corto_uint32* _this;
    _this = corto_uint32(corto_declareChild(_parent, _name, corto_uint32_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint32Define(corto_uint32* _this, corto_uint32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_uint32Set(corto_uint32* _this, corto_uint32 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_uint32Str(corto_uint32 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint32_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_uint32* corto_uint32FromStr(corto_uint32* value, corto_string str) {
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

corto_uint64* _corto_uint64Create(corto_uint64 value) {
    corto_uint64* _this;
    _this = corto_uint64(corto_declare(corto_uint64_o));
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

corto_uint64* _corto_uint64CreateChild(corto_object _parent, corto_string _name, corto_uint64 value) {
    corto_uint64* _this;
    _this = corto_uint64(corto_declareChild(_parent, _name, corto_uint64_o));
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

corto_int16 _corto_uint64Update(corto_uint64* _this, corto_uint64 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_uint64* _corto_uint64Declare(void) {
    corto_uint64* _this;
    _this = corto_uint64(corto_declare(corto_uint64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint64* _corto_uint64DeclareChild(corto_object _parent, corto_string _name) {
    corto_uint64* _this;
    _this = corto_uint64(corto_declareChild(_parent, _name, corto_uint64_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint64Define(corto_uint64* _this, corto_uint64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_uint64Set(corto_uint64* _this, corto_uint64 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_uint64Str(corto_uint64 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint64_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_uint64* corto_uint64FromStr(corto_uint64* value, corto_string str) {
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

corto_uint8* _corto_uint8Create(corto_uint8 value) {
    corto_uint8* _this;
    _this = corto_uint8(corto_declare(corto_uint8_o));
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

corto_uint8* _corto_uint8CreateChild(corto_object _parent, corto_string _name, corto_uint8 value) {
    corto_uint8* _this;
    _this = corto_uint8(corto_declareChild(_parent, _name, corto_uint8_o));
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

corto_int16 _corto_uint8Update(corto_uint8* _this, corto_uint8 value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_uint8* _corto_uint8Declare(void) {
    corto_uint8* _this;
    _this = corto_uint8(corto_declare(corto_uint8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_uint8* _corto_uint8DeclareChild(corto_object _parent, corto_string _name) {
    corto_uint8* _this;
    _this = corto_uint8(corto_declareChild(_parent, _name, corto_uint8_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_uint8Define(corto_uint8* _this, corto_uint8 value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_uint8Set(corto_uint8* _this, corto_uint8 value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_uint8Str(corto_uint8 value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_uint8_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_uint8* corto_uint8FromStr(corto_uint8* value, corto_string str) {
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

corto_virtual _corto_virtualCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_virtual _this;
    _this = corto_virtual(corto_declare(corto_virtual_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_virtual _corto_virtualCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    corto_virtual _this;
    _this = corto_virtual(corto_declareChild(_parent, _name, corto_virtual_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _corto_virtualUpdate(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((corto_function)_this)->returnType, returnType);
        ((corto_function)_this)->returnsReference = returnsReference;
        ((corto_method)_this)->_virtual = _virtual;
        corto_function(_this)->impl = (corto_word)_impl;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_virtual _corto_virtualDeclare(void) {
    corto_virtual _this;
    _this = corto_virtual(corto_declare(corto_virtual_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_virtual _corto_virtualDeclareChild(corto_object _parent, corto_string _name) {
    corto_virtual _this;
    _this = corto_virtual(corto_declareChild(_parent, _name, corto_virtual_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_virtualDefine(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
    return corto_define(_this);
}

void _corto_virtualSet(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args)) {
    CORTO_UNUSED(_this);
    corto_setref(&((corto_function)_this)->returnType, returnType);
    ((corto_function)_this)->returnsReference = returnsReference;
    ((corto_method)_this)->_virtual = _virtual;
    corto_function(_this)->impl = (corto_word)_impl;
}

corto_string _corto_virtualStr(corto_virtual value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(corto_virtual_o));
    result = corto_strv(&v, 0);
    return result;
}

corto_virtual corto_virtualFromStr(corto_virtual value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_virtual_o), str);
    return value;
}

corto_equalityKind _corto_virtualCompare(corto_virtual dst, corto_virtual src) {
    return corto_compare(dst, src);
}

corto_void* _corto_voidCreate(void) {
    corto_void* _this;
    _this = corto_void(corto_declare(corto_void_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_void* _corto_voidCreateChild(corto_object _parent, corto_string _name) {
    corto_void* _this;
    _this = corto_void(corto_declareChild(_parent, _name, corto_void_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_voidUpdate(corto_void* _this) {
    CORTO_UNUSED(_this);
    return corto_update(_this);
}

corto_vtable* _corto_vtableCreate(corto_uint32 length, corto_function* elements) {
    corto_vtable* _this;
    _this = corto_vtable(corto_declare(corto_vtable_o));
    if (!_this) {
        return NULL;
    }
    corto_vtableSize(_this, length);
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

corto_vtable* _corto_vtableCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_function* elements) {
    corto_vtable* _this;
    _this = corto_vtable(corto_declareChild(_parent, _name, corto_vtable_o));
    if (!_this) {
        return NULL;
    }
    corto_vtableSize(_this, length);
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

corto_int16 _corto_vtableUpdate(corto_vtable* _this, corto_uint32 length, corto_function* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_vtableSize(_this, length);
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

corto_vtable* _corto_vtableDeclare(void) {
    corto_vtable* _this;
    _this = corto_vtable(corto_declare(corto_vtable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_vtable* _corto_vtableDeclareChild(corto_object _parent, corto_string _name) {
    corto_vtable* _this;
    _this = corto_vtable(corto_declareChild(_parent, _name, corto_vtable_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_vtableDefine(corto_vtable* _this, corto_uint32 length, corto_function* elements) {
    CORTO_UNUSED(_this);
    corto_vtableSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
    return corto_define(_this);
}

void _corto_vtableSet(corto_vtable* _this, corto_uint32 length, corto_function* elements) {
    CORTO_UNUSED(_this);
    corto_vtableSize(_this, length);
    corto_uint32 i = 0;
    for (i = 0; i < length; i ++) {
        corto_setref(&_this->buffer[i], elements[i]);
    }
}

corto_string _corto_vtableStr(corto_vtable value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_vtable_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_vtable* corto_vtableFromStr(corto_vtable* value, corto_string str) {
    corto_fromStrp(&value, corto_type(corto_vtable_o), str);
    return value;
}

corto_equalityKind corto_vtableCompare(corto_vtable dst, corto_vtable src) {
    return corto_comparep(&dst, corto_vtable_o, &src);
}

corto_int16 _corto_vtableInit(corto_vtable* value) {
    corto_int16 result;
    memset(value, 0, corto_type(corto_vtable_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(corto_vtable_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _corto_vtableDeinit(corto_vtable* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(corto_vtable_o), value);
    result = corto_deinitv(&v);
    return result;
}

corto_width* _corto_widthCreate(corto_width value) {
    corto_width* _this;
    _this = corto_width(corto_declare(corto_width_o));
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

corto_width* _corto_widthCreateChild(corto_object _parent, corto_string _name, corto_width value) {
    corto_width* _this;
    _this = corto_width(corto_declareChild(_parent, _name, corto_width_o));
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

corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
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

corto_width* _corto_widthDeclareChild(corto_object _parent, corto_string _name) {
    corto_width* _this;
    _this = corto_width(corto_declareChild(_parent, _name, corto_width_o));
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

void _corto_widthSet(corto_width* _this, corto_width value) {
    CORTO_UNUSED(_this);
    *_this = value;
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

corto_word* _corto_wordCreate(corto_word value) {
    corto_word* _this;
    _this = corto_word(corto_declare(corto_word_o));
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

corto_word* _corto_wordCreateChild(corto_object _parent, corto_string _name, corto_word value) {
    corto_word* _this;
    _this = corto_word(corto_declareChild(_parent, _name, corto_word_o));
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

corto_int16 _corto_wordUpdate(corto_word* _this, corto_word value) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        *_this = value;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_word* _corto_wordDeclare(void) {
    corto_word* _this;
    _this = corto_word(corto_declare(corto_word_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_word* _corto_wordDeclareChild(corto_object _parent, corto_string _name) {
    corto_word* _this;
    _this = corto_word(corto_declareChild(_parent, _name, corto_word_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_wordDefine(corto_word* _this, corto_word value) {
    CORTO_UNUSED(_this);
    *_this = value;
    return corto_define(_this);
}

void _corto_wordSet(corto_word* _this, corto_word value) {
    CORTO_UNUSED(_this);
    *_this = value;
}

corto_string _corto_wordStr(corto_word value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(corto_word_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

corto_word* corto_wordFromStr(corto_word* value, corto_string str) {
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

corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_interface_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceseqClear(corto_interfaceseq *seq) {
    corto_interfaceseqSize(seq, 0);
}

corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_interfaceVector_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    corto_copyp(&seq->buffer[seq->length-1], corto_interfaceVector_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_interfaceVector_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_interfaceVector_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_interfaceVector_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq) {
    corto_interfaceVectorseqSize(seq, 0);
}

corto_member* corto_memberseqAppend(corto_memberseq *seq, corto_member element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_member* corto_memberseqAppendAlloc(corto_memberseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_memberseqSize(corto_memberseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_member_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_member_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_memberseqClear(corto_memberseq *seq) {
    corto_memberseqSize(seq, 0);
}

corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_object_o))));
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

void corto_objectseqClear(corto_objectseq *seq) {
    corto_objectseqSize(seq, 0);
}

corto_octet* corto_octetseqAppend(corto_octetseq *seq, corto_octet element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_octet_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_copyp(&seq->buffer[seq->length-1], corto_octet_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_octet* corto_octetseqAppendAlloc(corto_octetseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_octet_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_octetseqSize(corto_octetseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_octet_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_octetseqClear(corto_octetseq *seq) {
    corto_octetseqSize(seq, 0);
}

corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_parameter_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    corto_copyp(&seq->buffer[seq->length-1], corto_parameter_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(corto_type(corto_parameter_o), &seq->buffer[seq->length-1]);
        corto_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_parameter_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_parameter_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_parameterseqClear(corto_parameterseq *seq) {
    corto_parameterseqSize(seq, 0);
}

corto_function* corto_vtableAppend(corto_vtable *seq, corto_function element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_function_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_function* corto_vtableAppendAlloc(corto_vtable *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_function_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_vtableSize(corto_vtable *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_function_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(corto_type(corto_function_o), &seq->buffer[i]);
                corto_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void corto_vtableClear(corto_vtable *seq) {
    corto_vtableSize(seq, 0);
}
