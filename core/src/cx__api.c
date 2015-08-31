/* cx__api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include "cx.h"

cx_any* cx_anyCreate(void) {
    cx_any* _this;
    _this = cx_declare(cx_any_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_any* cx_anyCreateChild(cx_object _parent, cx_string _name) {
    cx_any* _this;
    _this = cx_declareChild(_parent, _name, cx_any_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_any* cx_anyDeclare(void) {
    cx_any* _this;
    _this = cx_declare(cx_any_o);
    return _this;
}

cx_any* cx_anyDeclareChild(cx_object _parent, cx_string _name) {
    cx_any* _this;
    _this = cx_declareChild(_parent, _name, cx_any_o);
    return _this;
}

cx_int16 cx_anyDefine(cx_any* _this, cx_any value) {
    *_this = value;
    return cx_define(_this);
}

void cx_anyUpdate(cx_any* _this, cx_any value) {
    *_this = value;
    cx_update(_this);
}

void cx_anySet(cx_any* _this, cx_any value) {
    *_this = value;
}

cx_string cx_anyStr(cx_any value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_any_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_any* cx_anyFromStr(cx_any* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_any_o), str);
    return value;
}

cx_int16 cx_anyCopy(cx_any* *dst, cx_any* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_any_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_any_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_anyCompare(cx_any* dst, cx_any* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_any_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_any_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_anyInit(cx_any* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_any_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_any_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_anyDeinit(cx_any* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_any_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_array cx_arrayCreate(cx_type elementType, cx_uint32 max) {
    cx_array _this;
    _this = cx_declare(cx_array_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_array cx_arrayCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_array _this;
    _this = cx_declareChild(_parent, _name, cx_array_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_array cx_arrayDeclare(void) {
    cx_array _this;
    _this = cx_declare(cx_array_o);
    return _this;
}

cx_array cx_arrayDeclareChild(cx_object _parent, cx_string _name) {
    cx_array _this;
    _this = cx_declareChild(_parent, _name, cx_array_o);
    return _this;
}

cx_int16 cx_arrayDefine(cx_array _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

void cx_arrayUpdate(cx_array _this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(_this);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    cx_updateEnd(_this);
}

void cx_arraySet(cx_array _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
}

cx_string cx_arrayStr(cx_array value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_array_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_array cx_arrayFromStr(cx_array value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_array_o), str);
    return value;
}

cx_int16 cx_arrayCopy(cx_array *dst, cx_array src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_arrayCompare(cx_array dst, cx_array src) {
    return cx_compare(dst, src);
}

cx_attr* cx_attrCreate(void) {
    cx_attr* _this;
    _this = cx_declare(cx_attr_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_attr* cx_attrCreateChild(cx_object _parent, cx_string _name) {
    cx_attr* _this;
    _this = cx_declareChild(_parent, _name, cx_attr_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_attr* cx_attrDeclare(void) {
    cx_attr* _this;
    _this = cx_declare(cx_attr_o);
    return _this;
}

cx_attr* cx_attrDeclareChild(cx_object _parent, cx_string _name) {
    cx_attr* _this;
    _this = cx_declareChild(_parent, _name, cx_attr_o);
    return _this;
}

cx_int16 cx_attrDefine(cx_attr* _this, cx_attr value) {
    *_this = value;
    return cx_define(_this);
}

void cx_attrUpdate(cx_attr* _this, cx_attr value) {
    *_this = value;
    cx_update(_this);
}

void cx_attrSet(cx_attr* _this, cx_attr value) {
    *_this = value;
}

cx_string cx_attrStr(cx_attr value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_attr_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_attr* cx_attrFromStr(cx_attr* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_attr_o), str);
    return value;
}

cx_int16 cx_attrCopy(cx_attr* *dst, cx_attr* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_attr_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_attr_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_attrCompare(cx_attr* dst, cx_attr* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_attr_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_attr_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_attrInit(cx_attr* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_attr_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_attr_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_attrDeinit(cx_attr* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_attr_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_binary cx_binaryCreate(cx_width width) {
    cx_binary _this;
    _this = cx_declare(cx_binary_o);
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_binary cx_binaryCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_binary _this;
    _this = cx_declareChild(_parent, _name, cx_binary_o);
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_binary cx_binaryDeclare(void) {
    cx_binary _this;
    _this = cx_declare(cx_binary_o);
    return _this;
}

cx_binary cx_binaryDeclareChild(cx_object _parent, cx_string _name) {
    cx_binary _this;
    _this = cx_declareChild(_parent, _name, cx_binary_o);
    return _this;
}

cx_int16 cx_binaryDefine(cx_binary _this, cx_width width) {
    cx_primitive(_this)->width = width;
    return cx_define(_this);
}

void cx_binaryUpdate(cx_binary _this, cx_width width) {
    cx_updateBegin(_this);
    cx_primitive(_this)->width = width;
    cx_updateEnd(_this);
}

void cx_binarySet(cx_binary _this, cx_width width) {
    cx_primitive(_this)->width = width;
}

cx_string cx_binaryStr(cx_binary value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_binary_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_binary cx_binaryFromStr(cx_binary value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_binary_o), str);
    return value;
}

cx_int16 cx_binaryCopy(cx_binary *dst, cx_binary src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_binaryCompare(cx_binary dst, cx_binary src) {
    return cx_compare(dst, src);
}

cx_bitmask cx_bitmaskCreate(void) {
    cx_bitmask _this;
    _this = cx_declare(cx_bitmask_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_bitmask cx_bitmaskCreateChild(cx_object _parent, cx_string _name) {
    cx_bitmask _this;
    _this = cx_declareChild(_parent, _name, cx_bitmask_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_bitmask cx_bitmaskDeclare(void) {
    cx_bitmask _this;
    _this = cx_declare(cx_bitmask_o);
    return _this;
}

cx_bitmask cx_bitmaskDeclareChild(cx_object _parent, cx_string _name) {
    cx_bitmask _this;
    _this = cx_declareChild(_parent, _name, cx_bitmask_o);
    return _this;
}

cx_int16 cx_bitmaskDefine(cx_bitmask _this) {
    return cx_define(_this);
}

void cx_bitmaskUpdate(cx_bitmask _this) {
    cx_update(_this);
}

void cx_bitmaskSet(cx_bitmask _this) {
    CX_UNUSED(_this);
}

cx_string cx_bitmaskStr(cx_bitmask value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_bitmask_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_bitmask cx_bitmaskFromStr(cx_bitmask value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_bitmask_o), str);
    return value;
}

cx_int16 cx_bitmaskCopy(cx_bitmask *dst, cx_bitmask src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_bitmaskCompare(cx_bitmask dst, cx_bitmask src) {
    return cx_compare(dst, src);
}

cx_bool* cx_boolCreate(void) {
    cx_bool* _this;
    _this = cx_declare(cx_bool_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_bool* cx_boolCreateChild(cx_object _parent, cx_string _name) {
    cx_bool* _this;
    _this = cx_declareChild(_parent, _name, cx_bool_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_bool* cx_boolDeclare(void) {
    cx_bool* _this;
    _this = cx_declare(cx_bool_o);
    return _this;
}

cx_bool* cx_boolDeclareChild(cx_object _parent, cx_string _name) {
    cx_bool* _this;
    _this = cx_declareChild(_parent, _name, cx_bool_o);
    return _this;
}

cx_int16 cx_boolDefine(cx_bool* _this, cx_bool value) {
    *_this = value;
    return cx_define(_this);
}

void cx_boolUpdate(cx_bool* _this, cx_bool value) {
    *_this = value;
    cx_update(_this);
}

void cx_boolSet(cx_bool* _this, cx_bool value) {
    *_this = value;
}

cx_string cx_boolStr(cx_bool value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_bool_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_bool* cx_boolFromStr(cx_bool* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_bool_o), str);
    return value;
}

cx_int16 cx_boolCopy(cx_bool* *dst, cx_bool* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_bool_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_bool_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_boolCompare(cx_bool* dst, cx_bool* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_bool_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_bool_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_boolInit(cx_bool* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_bool_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_bool_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_boolDeinit(cx_bool* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_bool_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_boolean cx_booleanCreate(void) {
    cx_boolean _this;
    _this = cx_declare(cx_boolean_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_boolean cx_booleanCreateChild(cx_object _parent, cx_string _name) {
    cx_boolean _this;
    _this = cx_declareChild(_parent, _name, cx_boolean_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_boolean cx_booleanDeclare(void) {
    cx_boolean _this;
    _this = cx_declare(cx_boolean_o);
    return _this;
}

cx_boolean cx_booleanDeclareChild(cx_object _parent, cx_string _name) {
    cx_boolean _this;
    _this = cx_declareChild(_parent, _name, cx_boolean_o);
    return _this;
}

cx_int16 cx_booleanDefine(cx_boolean _this) {
    return cx_define(_this);
}

void cx_booleanUpdate(cx_boolean _this) {
    cx_update(_this);
}

void cx_booleanSet(cx_boolean _this) {
    CX_UNUSED(_this);
}

cx_string cx_booleanStr(cx_boolean value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_boolean_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_boolean cx_booleanFromStr(cx_boolean value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_boolean_o), str);
    return value;
}

cx_int16 cx_booleanCopy(cx_boolean *dst, cx_boolean src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_booleanCompare(cx_boolean dst, cx_boolean src) {
    return cx_compare(dst, src);
}

cx_callbackDestruct* cx_callbackDestructCreate(void) {
    cx_callbackDestruct* _this;
    _this = cx_declare(cx_callbackDestruct_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_callbackDestruct* cx_callbackDestructCreateChild(cx_object _parent, cx_string _name) {
    cx_callbackDestruct* _this;
    _this = cx_declareChild(_parent, _name, cx_callbackDestruct_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_callbackDestruct* cx_callbackDestructDeclare(void) {
    cx_callbackDestruct* _this;
    _this = cx_declare(cx_callbackDestruct_o);
    return _this;
}

cx_callbackDestruct* cx_callbackDestructDeclareChild(cx_object _parent, cx_string _name) {
    cx_callbackDestruct* _this;
    _this = cx_declareChild(_parent, _name, cx_callbackDestruct_o);
    return _this;
}

cx_int16 cx_callbackDestructDefine(cx_callbackDestruct* _this) {
    return cx_define(_this);
}

void cx_callbackDestructUpdate(cx_callbackDestruct* _this) {
    cx_update(_this);
}

void cx_callbackDestructSet(cx_callbackDestruct* _this) {
    CX_UNUSED(_this);
}

cx_string cx_callbackDestructStr(cx_callbackDestruct* value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_callbackDestruct* cx_callbackDestructFromStr(cx_callbackDestruct* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_callbackDestruct_o), str);
    return value;
}

cx_int16 cx_callbackDestructCopy(cx_callbackDestruct* *dst, cx_callbackDestruct* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_callbackDestruct_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_callbackDestruct_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_callbackDestructCompare(cx_callbackDestruct* dst, cx_callbackDestruct* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_callbackDestruct_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_callbackDestruct_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_callbackDestructInit(cx_callbackDestruct* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_callbackDestruct_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_callbackDestructDeinit(cx_callbackDestruct* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackDestruct_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_callbackInit* cx_callbackInitCreate(void) {
    cx_callbackInit* _this;
    _this = cx_declare(cx_callbackInit_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_callbackInit* cx_callbackInitCreateChild(cx_object _parent, cx_string _name) {
    cx_callbackInit* _this;
    _this = cx_declareChild(_parent, _name, cx_callbackInit_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_callbackInit* cx_callbackInitDeclare(void) {
    cx_callbackInit* _this;
    _this = cx_declare(cx_callbackInit_o);
    return _this;
}

cx_callbackInit* cx_callbackInitDeclareChild(cx_object _parent, cx_string _name) {
    cx_callbackInit* _this;
    _this = cx_declareChild(_parent, _name, cx_callbackInit_o);
    return _this;
}

cx_int16 cx_callbackInitDefine(cx_callbackInit* _this) {
    return cx_define(_this);
}

void cx_callbackInitUpdate(cx_callbackInit* _this) {
    cx_update(_this);
}

void cx_callbackInitSet(cx_callbackInit* _this) {
    CX_UNUSED(_this);
}

cx_string cx_callbackInitStr(cx_callbackInit* value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_callbackInit* cx_callbackInitFromStr(cx_callbackInit* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_callbackInit_o), str);
    return value;
}

cx_int16 cx_callbackInitCopy(cx_callbackInit* *dst, cx_callbackInit* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_callbackInit_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_callbackInit_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_callbackInitCompare(cx_callbackInit* dst, cx_callbackInit* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_callbackInit_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_callbackInit_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_callbackInitInit(cx_callbackInit* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_callbackInit_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_callbackInitDeinit(cx_callbackInit* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_callbackInit_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_char* cx_charCreate(void) {
    cx_char* _this;
    _this = cx_declare(cx_char_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_char* cx_charCreateChild(cx_object _parent, cx_string _name) {
    cx_char* _this;
    _this = cx_declareChild(_parent, _name, cx_char_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_char* cx_charDeclare(void) {
    cx_char* _this;
    _this = cx_declare(cx_char_o);
    return _this;
}

cx_char* cx_charDeclareChild(cx_object _parent, cx_string _name) {
    cx_char* _this;
    _this = cx_declareChild(_parent, _name, cx_char_o);
    return _this;
}

cx_int16 cx_charDefine(cx_char* _this, cx_char value) {
    *_this = value;
    return cx_define(_this);
}

void cx_charUpdate(cx_char* _this, cx_char value) {
    *_this = value;
    cx_update(_this);
}

void cx_charSet(cx_char* _this, cx_char value) {
    *_this = value;
}

cx_string cx_charStr(cx_char value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_char_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_char* cx_charFromStr(cx_char* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_char_o), str);
    return value;
}

cx_int16 cx_charCopy(cx_char* *dst, cx_char* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_char_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_char_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_charCompare(cx_char* dst, cx_char* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_char_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_char_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_charInit(cx_char* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_char_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_char_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_charDeinit(cx_char* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_char_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_character cx_characterCreate(cx_width width) {
    cx_character _this;
    _this = cx_declare(cx_character_o);
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_character cx_characterCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_character _this;
    _this = cx_declareChild(_parent, _name, cx_character_o);
    cx_primitive(_this)->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_character cx_characterDeclare(void) {
    cx_character _this;
    _this = cx_declare(cx_character_o);
    return _this;
}

cx_character cx_characterDeclareChild(cx_object _parent, cx_string _name) {
    cx_character _this;
    _this = cx_declareChild(_parent, _name, cx_character_o);
    return _this;
}

cx_int16 cx_characterDefine(cx_character _this, cx_width width) {
    cx_primitive(_this)->width = width;
    return cx_define(_this);
}

void cx_characterUpdate(cx_character _this, cx_width width) {
    cx_updateBegin(_this);
    cx_primitive(_this)->width = width;
    cx_updateEnd(_this);
}

void cx_characterSet(cx_character _this, cx_width width) {
    cx_primitive(_this)->width = width;
}

cx_string cx_characterStr(cx_character value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_character_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_character cx_characterFromStr(cx_character value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_character_o), str);
    return value;
}

cx_int16 cx_characterCopy(cx_character *dst, cx_character src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_characterCompare(cx_character dst, cx_character src) {
    return cx_compare(dst, src);
}

cx_class cx_classCreate(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_class _this;
    _this = cx_declare(cx_class_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_class cx_classCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_class _this;
    _this = cx_declareChild(_parent, _name, cx_class_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_class cx_classDeclare(void) {
    cx_class _this;
    _this = cx_declare(cx_class_o);
    return _this;
}

cx_class cx_classDeclareChild(cx_object _parent, cx_string _name) {
    cx_class _this;
    _this = cx_declareChild(_parent, _name, cx_class_o);
    return _this;
}

cx_int16 cx_classDefine(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    return cx_define(_this);
}

void cx_classUpdate(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_updateBegin(_this);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
    cx_updateEnd(_this);
}

void cx_classSet(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->implements = implements;
}

cx_string cx_classStr(cx_class value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_class_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_class cx_classFromStr(cx_class value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_class_o), str);
    return value;
}

cx_int16 cx_classCopy(cx_class *dst, cx_class src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_classCompare(cx_class dst, cx_class src) {
    return cx_compare(dst, src);
}

cx_collection cx_collectionCreate(cx_type elementType, cx_uint32 max) {
    cx_collection _this;
    _this = cx_declare(cx_collection_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_collection cx_collectionCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_collection _this;
    _this = cx_declareChild(_parent, _name, cx_collection_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_collection cx_collectionDeclare(void) {
    cx_collection _this;
    _this = cx_declare(cx_collection_o);
    return _this;
}

cx_collection cx_collectionDeclareChild(cx_object _parent, cx_string _name) {
    cx_collection _this;
    _this = cx_declareChild(_parent, _name, cx_collection_o);
    return _this;
}

cx_int16 cx_collectionDefine(cx_collection _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&_this->elementType, cx_type(elementType));
    _this->max = max;
    return cx_define(_this);
}

void cx_collectionUpdate(cx_collection _this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(_this);
    cx_setref(&_this->elementType, cx_type(elementType));
    _this->max = max;
    cx_updateEnd(_this);
}

void cx_collectionSet(cx_collection _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&_this->elementType, cx_type(elementType));
    _this->max = max;
}

cx_string cx_collectionStr(cx_collection value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_collection_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_collection cx_collectionFromStr(cx_collection value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_collection_o), str);
    return value;
}

cx_int16 cx_collectionCopy(cx_collection *dst, cx_collection src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_collectionCompare(cx_collection dst, cx_collection src) {
    return cx_compare(dst, src);
}

cx_collectionKind* cx_collectionKindCreate(void) {
    cx_collectionKind* _this;
    _this = cx_declare(cx_collectionKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_collectionKind* cx_collectionKindCreateChild(cx_object _parent, cx_string _name) {
    cx_collectionKind* _this;
    _this = cx_declareChild(_parent, _name, cx_collectionKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_collectionKind* cx_collectionKindDeclare(void) {
    cx_collectionKind* _this;
    _this = cx_declare(cx_collectionKind_o);
    return _this;
}

cx_collectionKind* cx_collectionKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_collectionKind* _this;
    _this = cx_declareChild(_parent, _name, cx_collectionKind_o);
    return _this;
}

cx_int16 cx_collectionKindDefine(cx_collectionKind* _this, cx_collectionKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_collectionKindUpdate(cx_collectionKind* _this, cx_collectionKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_collectionKindSet(cx_collectionKind* _this, cx_collectionKind value) {
    *_this = value;
}

cx_string cx_collectionKindStr(cx_collectionKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_collectionKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_collectionKind* cx_collectionKindFromStr(cx_collectionKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_collectionKind_o), str);
    return value;
}

cx_int16 cx_collectionKindCopy(cx_collectionKind* *dst, cx_collectionKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_collectionKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_collectionKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_collectionKindCompare(cx_collectionKind* dst, cx_collectionKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_collectionKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_collectionKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_collectionKindInit(cx_collectionKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_collectionKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_collectionKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_collectionKindDeinit(cx_collectionKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_collectionKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_compositeKind* cx_compositeKindCreate(void) {
    cx_compositeKind* _this;
    _this = cx_declare(cx_compositeKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_compositeKind* cx_compositeKindCreateChild(cx_object _parent, cx_string _name) {
    cx_compositeKind* _this;
    _this = cx_declareChild(_parent, _name, cx_compositeKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_compositeKind* cx_compositeKindDeclare(void) {
    cx_compositeKind* _this;
    _this = cx_declare(cx_compositeKind_o);
    return _this;
}

cx_compositeKind* cx_compositeKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_compositeKind* _this;
    _this = cx_declareChild(_parent, _name, cx_compositeKind_o);
    return _this;
}

cx_int16 cx_compositeKindDefine(cx_compositeKind* _this, cx_compositeKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_compositeKindUpdate(cx_compositeKind* _this, cx_compositeKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_compositeKindSet(cx_compositeKind* _this, cx_compositeKind value) {
    *_this = value;
}

cx_string cx_compositeKindStr(cx_compositeKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_compositeKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_compositeKind* cx_compositeKindFromStr(cx_compositeKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_compositeKind_o), str);
    return value;
}

cx_int16 cx_compositeKindCopy(cx_compositeKind* *dst, cx_compositeKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_compositeKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_compositeKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_compositeKindCompare(cx_compositeKind* dst, cx_compositeKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_compositeKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_compositeKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_compositeKindInit(cx_compositeKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_compositeKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_compositeKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_compositeKindDeinit(cx_compositeKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_compositeKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_constant* cx_constantCreate(void) {
    cx_constant* _this;
    _this = cx_declare(cx_constant_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_constant* cx_constantCreateChild(cx_object _parent, cx_string _name) {
    cx_constant* _this;
    _this = cx_declareChild(_parent, _name, cx_constant_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_constant* cx_constantDeclare(void) {
    cx_constant* _this;
    _this = cx_declare(cx_constant_o);
    return _this;
}

cx_constant* cx_constantDeclareChild(cx_object _parent, cx_string _name) {
    cx_constant* _this;
    _this = cx_declareChild(_parent, _name, cx_constant_o);
    return _this;
}

cx_int16 cx_constantDefine(cx_constant* _this, cx_constant value) {
    *_this = value;
    return cx_define(_this);
}

void cx_constantUpdate(cx_constant* _this, cx_constant value) {
    *_this = value;
    cx_update(_this);
}

void cx_constantSet(cx_constant* _this, cx_constant value) {
    *_this = value;
}

cx_string cx_constantStr(cx_constant value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_constant_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_constant* cx_constantFromStr(cx_constant* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_constant_o), str);
    return value;
}

cx_int16 cx_constantCopy(cx_constant* *dst, cx_constant* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_constant_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_constant_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_constantCompare(cx_constant* dst, cx_constant* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_constant_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_constant_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_constantInit(cx_constant* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_constant_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_constant_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_constantDeinit(cx_constant* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_constant_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_delegate cx_delegateCreate(cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_delegate _this;
    _this = cx_declare(cx_delegate_o);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_delegate cx_delegateCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_delegate _this;
    _this = cx_declareChild(_parent, _name, cx_delegate_o);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_delegate cx_delegateDeclare(void) {
    cx_delegate _this;
    _this = cx_declare(cx_delegate_o);
    return _this;
}

cx_delegate cx_delegateDeclareChild(cx_object _parent, cx_string _name) {
    cx_delegate _this;
    _this = cx_declareChild(_parent, _name, cx_delegate_o);
    return _this;
}

cx_int16 cx_delegateDefine(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    return cx_define(_this);
}

void cx_delegateUpdate(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_updateBegin(_this);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
    cx_updateEnd(_this);
}

void cx_delegateSet(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters) {
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    _this->parameters = parameters;
}

cx_string cx_delegateStr(cx_delegate value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_delegate_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_delegate cx_delegateFromStr(cx_delegate value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_delegate_o), str);
    return value;
}

cx_int16 cx_delegateCopy(cx_delegate *dst, cx_delegate src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_delegateCompare(cx_delegate dst, cx_delegate src) {
    return cx_compare(dst, src);
}

cx_delegatedata* cx_delegatedataCreate(cx_object instance, cx_function procedure) {
    cx_delegatedata* _this;
    _this = cx_declare(cx_delegatedata_o);
    cx_setref(&_this->instance, instance);
    cx_setref(&_this->procedure, cx_function(procedure));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_delegatedata* cx_delegatedataCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure) {
    cx_delegatedata* _this;
    _this = cx_declareChild(_parent, _name, cx_delegatedata_o);
    cx_setref(&_this->instance, instance);
    cx_setref(&_this->procedure, cx_function(procedure));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_delegatedata* cx_delegatedataDeclare(void) {
    cx_delegatedata* _this;
    _this = cx_declare(cx_delegatedata_o);
    return _this;
}

cx_delegatedata* cx_delegatedataDeclareChild(cx_object _parent, cx_string _name) {
    cx_delegatedata* _this;
    _this = cx_declareChild(_parent, _name, cx_delegatedata_o);
    return _this;
}

cx_int16 cx_delegatedataDefine(cx_delegatedata* _this, cx_object instance, cx_function procedure) {
    cx_setref(&_this->instance, instance);
    cx_setref(&_this->procedure, cx_function(procedure));
    return cx_define(_this);
}

void cx_delegatedataUpdate(cx_delegatedata* _this, cx_object instance, cx_function procedure) {
    cx_updateBegin(_this);
    cx_setref(&_this->instance, instance);
    cx_setref(&_this->procedure, cx_function(procedure));
    cx_updateEnd(_this);
}

void cx_delegatedataSet(cx_delegatedata* _this, cx_object instance, cx_function procedure) {
    cx_setref(&_this->instance, instance);
    cx_setref(&_this->procedure, cx_function(procedure));
}

cx_string cx_delegatedataStr(cx_delegatedata* value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_delegatedata* cx_delegatedataFromStr(cx_delegatedata* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_delegatedata_o), str);
    return value;
}

cx_int16 cx_delegatedataCopy(cx_delegatedata* *dst, cx_delegatedata* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_delegatedata_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_delegatedata_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_delegatedataCompare(cx_delegatedata* dst, cx_delegatedata* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_delegatedata_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_delegatedata_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_delegatedataInit(cx_delegatedata* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_delegatedata_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_delegatedataDeinit(cx_delegatedata* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_delegatedata_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_dispatcher cx_dispatcherCreate(void) {
    cx_dispatcher _this;
    _this = cx_declare(cx_dispatcher_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_dispatcher cx_dispatcherCreateChild(cx_object _parent, cx_string _name) {
    cx_dispatcher _this;
    _this = cx_declareChild(_parent, _name, cx_dispatcher_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_dispatcher cx_dispatcherDeclare(void) {
    cx_dispatcher _this;
    _this = cx_declare(cx_dispatcher_o);
    return _this;
}

cx_dispatcher cx_dispatcherDeclareChild(cx_object _parent, cx_string _name) {
    cx_dispatcher _this;
    _this = cx_declareChild(_parent, _name, cx_dispatcher_o);
    return _this;
}

cx_int16 cx_dispatcherDefine(cx_dispatcher _this) {
    return cx_define(_this);
}

void cx_dispatcherUpdate(cx_dispatcher _this) {
    cx_update(_this);
}

void cx_dispatcherSet(cx_dispatcher _this) {
    CX_UNUSED(_this);
}

cx_string cx_dispatcherStr(cx_dispatcher value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_dispatcher_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_dispatcher cx_dispatcherFromStr(cx_dispatcher value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_dispatcher_o), str);
    return value;
}

cx_int16 cx_dispatcherCopy(cx_dispatcher *dst, cx_dispatcher src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_dispatcherCompare(cx_dispatcher dst, cx_dispatcher src) {
    return cx_compare(dst, src);
}

cx_enum cx_enumCreate(void) {
    cx_enum _this;
    _this = cx_declare(cx_enum_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_enum cx_enumCreateChild(cx_object _parent, cx_string _name) {
    cx_enum _this;
    _this = cx_declareChild(_parent, _name, cx_enum_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_enum cx_enumDeclare(void) {
    cx_enum _this;
    _this = cx_declare(cx_enum_o);
    return _this;
}

cx_enum cx_enumDeclareChild(cx_object _parent, cx_string _name) {
    cx_enum _this;
    _this = cx_declareChild(_parent, _name, cx_enum_o);
    return _this;
}

cx_int16 cx_enumDefine(cx_enum _this) {
    return cx_define(_this);
}

void cx_enumUpdate(cx_enum _this) {
    cx_update(_this);
}

void cx_enumSet(cx_enum _this) {
    CX_UNUSED(_this);
}

cx_string cx_enumStr(cx_enum value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_enum_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_enum cx_enumFromStr(cx_enum value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_enum_o), str);
    return value;
}

cx_int16 cx_enumCopy(cx_enum *dst, cx_enum src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_enumCompare(cx_enum dst, cx_enum src) {
    return cx_compare(dst, src);
}

cx_equalityKind* cx_equalityKindCreate(void) {
    cx_equalityKind* _this;
    _this = cx_declare(cx_equalityKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_equalityKind* cx_equalityKindCreateChild(cx_object _parent, cx_string _name) {
    cx_equalityKind* _this;
    _this = cx_declareChild(_parent, _name, cx_equalityKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_equalityKind* cx_equalityKindDeclare(void) {
    cx_equalityKind* _this;
    _this = cx_declare(cx_equalityKind_o);
    return _this;
}

cx_equalityKind* cx_equalityKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_equalityKind* _this;
    _this = cx_declareChild(_parent, _name, cx_equalityKind_o);
    return _this;
}

cx_int16 cx_equalityKindDefine(cx_equalityKind* _this, cx_equalityKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_equalityKindUpdate(cx_equalityKind* _this, cx_equalityKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_equalityKindSet(cx_equalityKind* _this, cx_equalityKind value) {
    *_this = value;
}

cx_string cx_equalityKindStr(cx_equalityKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_equalityKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_equalityKind* cx_equalityKindFromStr(cx_equalityKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_equalityKind_o), str);
    return value;
}

cx_int16 cx_equalityKindCopy(cx_equalityKind* *dst, cx_equalityKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_equalityKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_equalityKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_equalityKindCompare(cx_equalityKind* dst, cx_equalityKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_equalityKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_equalityKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_equalityKindInit(cx_equalityKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_equalityKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_equalityKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_equalityKindDeinit(cx_equalityKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_equalityKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_event cx_eventCreate(cx_uint16 kind) {
    cx_event _this;
    _this = cx_declare(cx_event_o);
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_event cx_eventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind) {
    cx_event _this;
    _this = cx_declareChild(_parent, _name, cx_event_o);
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_event cx_eventDeclare(void) {
    cx_event _this;
    _this = cx_declare(cx_event_o);
    return _this;
}

cx_event cx_eventDeclareChild(cx_object _parent, cx_string _name) {
    cx_event _this;
    _this = cx_declareChild(_parent, _name, cx_event_o);
    return _this;
}

cx_int16 cx_eventDefine(cx_event _this, cx_uint16 kind) {
    _this->kind = kind;
    return cx_define(_this);
}

void cx_eventUpdate(cx_event _this, cx_uint16 kind) {
    cx_updateBegin(_this);
    _this->kind = kind;
    cx_updateEnd(_this);
}

void cx_eventSet(cx_event _this, cx_uint16 kind) {
    _this->kind = kind;
}

cx_string cx_eventStr(cx_event value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_event_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_event cx_eventFromStr(cx_event value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_event_o), str);
    return value;
}

cx_int16 cx_eventCopy(cx_event *dst, cx_event src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_eventCompare(cx_event dst, cx_event src) {
    return cx_compare(dst, src);
}

cx_eventMask* cx_eventMaskCreate(void) {
    cx_eventMask* _this;
    _this = cx_declare(cx_eventMask_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_eventMask* cx_eventMaskCreateChild(cx_object _parent, cx_string _name) {
    cx_eventMask* _this;
    _this = cx_declareChild(_parent, _name, cx_eventMask_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_eventMask* cx_eventMaskDeclare(void) {
    cx_eventMask* _this;
    _this = cx_declare(cx_eventMask_o);
    return _this;
}

cx_eventMask* cx_eventMaskDeclareChild(cx_object _parent, cx_string _name) {
    cx_eventMask* _this;
    _this = cx_declareChild(_parent, _name, cx_eventMask_o);
    return _this;
}

cx_int16 cx_eventMaskDefine(cx_eventMask* _this, cx_eventMask value) {
    *_this = value;
    return cx_define(_this);
}

void cx_eventMaskUpdate(cx_eventMask* _this, cx_eventMask value) {
    *_this = value;
    cx_update(_this);
}

void cx_eventMaskSet(cx_eventMask* _this, cx_eventMask value) {
    *_this = value;
}

cx_string cx_eventMaskStr(cx_eventMask value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_eventMask_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_eventMask* cx_eventMaskFromStr(cx_eventMask* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_eventMask_o), str);
    return value;
}

cx_int16 cx_eventMaskCopy(cx_eventMask* *dst, cx_eventMask* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_eventMask_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_eventMask_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_eventMaskCompare(cx_eventMask* dst, cx_eventMask* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_eventMask_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_eventMask_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_eventMaskInit(cx_eventMask* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_eventMask_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_eventMask_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_eventMaskDeinit(cx_eventMask* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_eventMask_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_float cx_floatCreate(cx_width width, cx_float64 min, cx_float64 max) {
    cx_float _this;
    _this = cx_declare(cx_float_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float cx_floatCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_float64 min, cx_float64 max) {
    cx_float _this;
    _this = cx_declareChild(_parent, _name, cx_float_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float cx_floatDeclare(void) {
    cx_float _this;
    _this = cx_declare(cx_float_o);
    return _this;
}

cx_float cx_floatDeclareChild(cx_object _parent, cx_string _name) {
    cx_float _this;
    _this = cx_declareChild(_parent, _name, cx_float_o);
    return _this;
}

cx_int16 cx_floatDefine(cx_float _this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

void cx_floatUpdate(cx_float _this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_updateBegin(_this);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    cx_updateEnd(_this);
}

void cx_floatSet(cx_float _this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
}

cx_string cx_floatStr(cx_float value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_float_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_float cx_floatFromStr(cx_float value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_float_o), str);
    return value;
}

cx_int16 cx_floatCopy(cx_float *dst, cx_float src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_floatCompare(cx_float dst, cx_float src) {
    return cx_compare(dst, src);
}

cx_float32* cx_float32Create(void) {
    cx_float32* _this;
    _this = cx_declare(cx_float32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float32* cx_float32CreateChild(cx_object _parent, cx_string _name) {
    cx_float32* _this;
    _this = cx_declareChild(_parent, _name, cx_float32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float32* cx_float32Declare(void) {
    cx_float32* _this;
    _this = cx_declare(cx_float32_o);
    return _this;
}

cx_float32* cx_float32DeclareChild(cx_object _parent, cx_string _name) {
    cx_float32* _this;
    _this = cx_declareChild(_parent, _name, cx_float32_o);
    return _this;
}

cx_int16 cx_float32Define(cx_float32* _this, cx_float32 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_float32Update(cx_float32* _this, cx_float32 value) {
    *_this = value;
    cx_update(_this);
}

void cx_float32Set(cx_float32* _this, cx_float32 value) {
    *_this = value;
}

cx_string cx_float32Str(cx_float32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float32_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_float32* cx_float32FromStr(cx_float32* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_float32_o), str);
    return value;
}

cx_int16 cx_float32Copy(cx_float32* *dst, cx_float32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_float32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_float32_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_float32Compare(cx_float32* dst, cx_float32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_float32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_float32_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_float32Init(cx_float32* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_float32_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float32_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_float32Deinit(cx_float32* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float32_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_float64* cx_float64Create(void) {
    cx_float64* _this;
    _this = cx_declare(cx_float64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float64* cx_float64CreateChild(cx_object _parent, cx_string _name) {
    cx_float64* _this;
    _this = cx_declareChild(_parent, _name, cx_float64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_float64* cx_float64Declare(void) {
    cx_float64* _this;
    _this = cx_declare(cx_float64_o);
    return _this;
}

cx_float64* cx_float64DeclareChild(cx_object _parent, cx_string _name) {
    cx_float64* _this;
    _this = cx_declareChild(_parent, _name, cx_float64_o);
    return _this;
}

cx_int16 cx_float64Define(cx_float64* _this, cx_float64 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_float64Update(cx_float64* _this, cx_float64 value) {
    *_this = value;
    cx_update(_this);
}

void cx_float64Set(cx_float64* _this, cx_float64 value) {
    *_this = value;
}

cx_string cx_float64Str(cx_float64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float64_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_float64* cx_float64FromStr(cx_float64* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_float64_o), str);
    return value;
}

cx_int16 cx_float64Copy(cx_float64* *dst, cx_float64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_float64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_float64_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_float64Compare(cx_float64* dst, cx_float64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_float64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_float64_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_float64Init(cx_float64* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_float64_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float64_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_float64Deinit(cx_float64* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_float64_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_function cx_functionCreate(cx_type returnType, cx_bool returnsReference) {
    cx_function _this;
    _this = cx_declare(cx_function_o);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_function cx_functionCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference) {
    cx_function _this;
    _this = cx_declareChild(_parent, _name, cx_function_o);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_function cx_functionDeclare(void) {
    cx_function _this;
    _this = cx_declare(cx_function_o);
    return _this;
}

cx_function cx_functionDeclareChild(cx_object _parent, cx_string _name) {
    cx_function _this;
    _this = cx_declareChild(_parent, _name, cx_function_o);
    return _this;
}

cx_int16 cx_functionDefine(cx_function _this, cx_type returnType, cx_bool returnsReference) {
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    return cx_define(_this);
}

void cx_functionUpdate(cx_function _this, cx_type returnType, cx_bool returnsReference) {
    cx_updateBegin(_this);
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
    cx_updateEnd(_this);
}

void cx_functionSet(cx_function _this, cx_type returnType, cx_bool returnsReference) {
    cx_setref(&_this->returnType, cx_type(returnType));
    _this->returnsReference = returnsReference;
}

cx_string cx_functionStr(cx_function value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_function_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_function cx_functionFromStr(cx_function value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_function_o), str);
    return value;
}

cx_int16 cx_functionCopy(cx_function *dst, cx_function src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_functionCompare(cx_function dst, cx_function src) {
    return cx_compare(dst, src);
}

cx_int cx_intCreate(cx_width width, cx_int64 min, cx_int64 max) {
    cx_int _this;
    _this = cx_declare(cx_int_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int cx_intCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max) {
    cx_int _this;
    _this = cx_declareChild(_parent, _name, cx_int_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int cx_intDeclare(void) {
    cx_int _this;
    _this = cx_declare(cx_int_o);
    return _this;
}

cx_int cx_intDeclareChild(cx_object _parent, cx_string _name) {
    cx_int _this;
    _this = cx_declareChild(_parent, _name, cx_int_o);
    return _this;
}

cx_int16 cx_intDefine(cx_int _this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

void cx_intUpdate(cx_int _this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_updateBegin(_this);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    cx_updateEnd(_this);
}

void cx_intSet(cx_int _this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
}

cx_string cx_intStr(cx_int value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_int_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_int cx_intFromStr(cx_int value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_int_o), str);
    return value;
}

cx_int16 cx_intCopy(cx_int *dst, cx_int src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_intCompare(cx_int dst, cx_int src) {
    return cx_compare(dst, src);
}

cx_int16* cx_int16Create(void) {
    cx_int16* _this;
    _this = cx_declare(cx_int16_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int16* cx_int16CreateChild(cx_object _parent, cx_string _name) {
    cx_int16* _this;
    _this = cx_declareChild(_parent, _name, cx_int16_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int16* cx_int16Declare(void) {
    cx_int16* _this;
    _this = cx_declare(cx_int16_o);
    return _this;
}

cx_int16* cx_int16DeclareChild(cx_object _parent, cx_string _name) {
    cx_int16* _this;
    _this = cx_declareChild(_parent, _name, cx_int16_o);
    return _this;
}

cx_int16 cx_int16Define(cx_int16* _this, cx_int16 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_int16Update(cx_int16* _this, cx_int16 value) {
    *_this = value;
    cx_update(_this);
}

void cx_int16Set(cx_int16* _this, cx_int16 value) {
    *_this = value;
}

cx_string cx_int16Str(cx_int16 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int16_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_int16* cx_int16FromStr(cx_int16* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_int16_o), str);
    return value;
}

cx_int16 cx_int16Copy(cx_int16* *dst, cx_int16* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int16_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int16_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_int16Compare(cx_int16* dst, cx_int16* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int16_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int16_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_int16Init(cx_int16* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_int16_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int16_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_int16Deinit(cx_int16* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int16_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_int32* cx_int32Create(void) {
    cx_int32* _this;
    _this = cx_declare(cx_int32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int32* cx_int32CreateChild(cx_object _parent, cx_string _name) {
    cx_int32* _this;
    _this = cx_declareChild(_parent, _name, cx_int32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int32* cx_int32Declare(void) {
    cx_int32* _this;
    _this = cx_declare(cx_int32_o);
    return _this;
}

cx_int32* cx_int32DeclareChild(cx_object _parent, cx_string _name) {
    cx_int32* _this;
    _this = cx_declareChild(_parent, _name, cx_int32_o);
    return _this;
}

cx_int16 cx_int32Define(cx_int32* _this, cx_int32 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_int32Update(cx_int32* _this, cx_int32 value) {
    *_this = value;
    cx_update(_this);
}

void cx_int32Set(cx_int32* _this, cx_int32 value) {
    *_this = value;
}

cx_string cx_int32Str(cx_int32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int32_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_int32* cx_int32FromStr(cx_int32* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_int32_o), str);
    return value;
}

cx_int16 cx_int32Copy(cx_int32* *dst, cx_int32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int32_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_int32Compare(cx_int32* dst, cx_int32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int32_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_int32Init(cx_int32* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_int32_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int32_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_int32Deinit(cx_int32* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int32_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_int64* cx_int64Create(void) {
    cx_int64* _this;
    _this = cx_declare(cx_int64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int64* cx_int64CreateChild(cx_object _parent, cx_string _name) {
    cx_int64* _this;
    _this = cx_declareChild(_parent, _name, cx_int64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int64* cx_int64Declare(void) {
    cx_int64* _this;
    _this = cx_declare(cx_int64_o);
    return _this;
}

cx_int64* cx_int64DeclareChild(cx_object _parent, cx_string _name) {
    cx_int64* _this;
    _this = cx_declareChild(_parent, _name, cx_int64_o);
    return _this;
}

cx_int16 cx_int64Define(cx_int64* _this, cx_int64 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_int64Update(cx_int64* _this, cx_int64 value) {
    *_this = value;
    cx_update(_this);
}

void cx_int64Set(cx_int64* _this, cx_int64 value) {
    *_this = value;
}

cx_string cx_int64Str(cx_int64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int64_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_int64* cx_int64FromStr(cx_int64* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_int64_o), str);
    return value;
}

cx_int16 cx_int64Copy(cx_int64* *dst, cx_int64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int64_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_int64Compare(cx_int64* dst, cx_int64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int64_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_int64Init(cx_int64* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_int64_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int64_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_int64Deinit(cx_int64* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int64_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_int8* cx_int8Create(void) {
    cx_int8* _this;
    _this = cx_declare(cx_int8_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int8* cx_int8CreateChild(cx_object _parent, cx_string _name) {
    cx_int8* _this;
    _this = cx_declareChild(_parent, _name, cx_int8_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_int8* cx_int8Declare(void) {
    cx_int8* _this;
    _this = cx_declare(cx_int8_o);
    return _this;
}

cx_int8* cx_int8DeclareChild(cx_object _parent, cx_string _name) {
    cx_int8* _this;
    _this = cx_declareChild(_parent, _name, cx_int8_o);
    return _this;
}

cx_int16 cx_int8Define(cx_int8* _this, cx_int8 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_int8Update(cx_int8* _this, cx_int8 value) {
    *_this = value;
    cx_update(_this);
}

void cx_int8Set(cx_int8* _this, cx_int8 value) {
    *_this = value;
}

cx_string cx_int8Str(cx_int8 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int8_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_int8* cx_int8FromStr(cx_int8* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_int8_o), str);
    return value;
}

cx_int16 cx_int8Copy(cx_int8* *dst, cx_int8* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int8_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int8_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_int8Compare(cx_int8* dst, cx_int8* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_int8_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_int8_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_int8Init(cx_int8* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_int8_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int8_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_int8Deinit(cx_int8* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_int8_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_interface cx_interfaceCreate(cx_interface base) {
    cx_interface _this;
    _this = cx_declare(cx_interface_o);
    cx_setref(&_this->base, cx_interface(base));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interface cx_interfaceCreateChild(cx_object _parent, cx_string _name, cx_interface base) {
    cx_interface _this;
    _this = cx_declareChild(_parent, _name, cx_interface_o);
    cx_setref(&_this->base, cx_interface(base));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interface cx_interfaceDeclare(void) {
    cx_interface _this;
    _this = cx_declare(cx_interface_o);
    return _this;
}

cx_interface cx_interfaceDeclareChild(cx_object _parent, cx_string _name) {
    cx_interface _this;
    _this = cx_declareChild(_parent, _name, cx_interface_o);
    return _this;
}

cx_int16 cx_interfaceDefine(cx_interface _this, cx_interface base) {
    cx_setref(&_this->base, cx_interface(base));
    return cx_define(_this);
}

void cx_interfaceUpdate(cx_interface _this, cx_interface base) {
    cx_updateBegin(_this);
    cx_setref(&_this->base, cx_interface(base));
    cx_updateEnd(_this);
}

void cx_interfaceSet(cx_interface _this, cx_interface base) {
    cx_setref(&_this->base, cx_interface(base));
}

cx_string cx_interfaceStr(cx_interface value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_interface_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_interface cx_interfaceFromStr(cx_interface value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interface_o), str);
    return value;
}

cx_int16 cx_interfaceCopy(cx_interface *dst, cx_interface src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_interfaceCompare(cx_interface dst, cx_interface src) {
    return cx_compare(dst, src);
}

cx_interfaceSeq* cx_interfaceSeqCreate(void) {
    cx_interfaceSeq* _this;
    _this = cx_declare(cx_interfaceSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceSeq* cx_interfaceSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_interfaceSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceSeq* cx_interfaceSeqDeclare(void) {
    cx_interfaceSeq* _this;
    _this = cx_declare(cx_interfaceSeq_o);
    return _this;
}

cx_interfaceSeq* cx_interfaceSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceSeq_o);
    return _this;
}

cx_int16 cx_interfaceSeqDefine(cx_interfaceSeq* _this, cx_interfaceSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_interfaceSeqUpdate(cx_interfaceSeq* _this, cx_interfaceSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_interfaceSeqSet(cx_interfaceSeq* _this, cx_interfaceSeq value) {
    *_this = value;
}

cx_string cx_interfaceSeqStr(cx_interfaceSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_interfaceSeq* cx_interfaceSeqFromStr(cx_interfaceSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interfaceSeq_o), str);
    return value;
}

cx_int16 cx_interfaceSeqCopy(cx_interfaceSeq* *dst, cx_interfaceSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_interfaceSeqCompare(cx_interfaceSeq* dst, cx_interfaceSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_interfaceSeqInit(cx_interfaceSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_interfaceSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_interfaceSeqDeinit(cx_interfaceSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_interfaceVector* cx_interfaceVectorCreate(cx_interface interface, cx_vtable vector) {
    cx_interfaceVector* _this;
    _this = cx_declare(cx_interfaceVector_o);
    cx_setref(&_this->interface, cx_interface(interface));
    _this->vector = vector;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceVector* cx_interfaceVectorCreateChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector) {
    cx_interfaceVector* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceVector_o);
    cx_setref(&_this->interface, cx_interface(interface));
    _this->vector = vector;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceVector* cx_interfaceVectorDeclare(void) {
    cx_interfaceVector* _this;
    _this = cx_declare(cx_interfaceVector_o);
    return _this;
}

cx_interfaceVector* cx_interfaceVectorDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceVector* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceVector_o);
    return _this;
}

cx_int16 cx_interfaceVectorDefine(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector) {
    cx_setref(&_this->interface, cx_interface(interface));
    _this->vector = vector;
    return cx_define(_this);
}

void cx_interfaceVectorUpdate(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector) {
    cx_updateBegin(_this);
    cx_setref(&_this->interface, cx_interface(interface));
    _this->vector = vector;
    cx_updateEnd(_this);
}

void cx_interfaceVectorSet(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector) {
    cx_setref(&_this->interface, cx_interface(interface));
    _this->vector = vector;
}

cx_string cx_interfaceVectorStr(cx_interfaceVector* value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_interfaceVector* cx_interfaceVectorFromStr(cx_interfaceVector* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interfaceVector_o), str);
    return value;
}

cx_int16 cx_interfaceVectorCopy(cx_interfaceVector* *dst, cx_interfaceVector* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVector_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVector_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_interfaceVectorCompare(cx_interfaceVector* dst, cx_interfaceVector* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVector_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVector_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_interfaceVectorInit(cx_interfaceVector* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_interfaceVector_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_interfaceVectorDeinit(cx_interfaceVector* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_interfaceVectorSeq* cx_interfaceVectorSeqCreate(void) {
    cx_interfaceVectorSeq* _this;
    _this = cx_declare(cx_interfaceVectorSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceVectorSeq* cx_interfaceVectorSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_interfaceVectorSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceVectorSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_interfaceVectorSeq* cx_interfaceVectorSeqDeclare(void) {
    cx_interfaceVectorSeq* _this;
    _this = cx_declare(cx_interfaceVectorSeq_o);
    return _this;
}

cx_interfaceVectorSeq* cx_interfaceVectorSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceVectorSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_interfaceVectorSeq_o);
    return _this;
}

cx_int16 cx_interfaceVectorSeqDefine(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_interfaceVectorSeqUpdate(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_interfaceVectorSeqSet(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value) {
    *_this = value;
}

cx_string cx_interfaceVectorSeqStr(cx_interfaceVectorSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_interfaceVectorSeq* cx_interfaceVectorSeqFromStr(cx_interfaceVectorSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interfaceVectorSeq_o), str);
    return value;
}

cx_int16 cx_interfaceVectorSeqCopy(cx_interfaceVectorSeq* *dst, cx_interfaceVectorSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVectorSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVectorSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_interfaceVectorSeqCompare(cx_interfaceVectorSeq* dst, cx_interfaceVectorSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVectorSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVectorSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_interfaceVectorSeqInit(cx_interfaceVectorSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_interfaceVectorSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_interfaceVectorSeqDeinit(cx_interfaceVectorSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_iterator cx_iteratorCreate(cx_type elementType) {
    cx_iterator _this;
    _this = cx_declare(cx_iterator_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_iterator cx_iteratorCreateChild(cx_object _parent, cx_string _name, cx_type elementType) {
    cx_iterator _this;
    _this = cx_declareChild(_parent, _name, cx_iterator_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_iterator cx_iteratorDeclare(void) {
    cx_iterator _this;
    _this = cx_declare(cx_iterator_o);
    return _this;
}

cx_iterator cx_iteratorDeclareChild(cx_object _parent, cx_string _name) {
    cx_iterator _this;
    _this = cx_declareChild(_parent, _name, cx_iterator_o);
    return _this;
}

cx_int16 cx_iteratorDefine(cx_iterator _this, cx_type elementType) {
    cx_setref(&_this->elementType, cx_type(elementType));
    return cx_define(_this);
}

void cx_iteratorUpdate(cx_iterator _this, cx_type elementType) {
    cx_updateBegin(_this);
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_updateEnd(_this);
}

void cx_iteratorSet(cx_iterator _this, cx_type elementType) {
    cx_setref(&_this->elementType, cx_type(elementType));
}

cx_string cx_iteratorStr(cx_iterator value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_iterator_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_iterator cx_iteratorFromStr(cx_iterator value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_iterator_o), str);
    return value;
}

cx_int16 cx_iteratorCopy(cx_iterator *dst, cx_iterator src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_iteratorCompare(cx_iterator dst, cx_iterator src) {
    return cx_compare(dst, src);
}

cx_list cx_listCreate(cx_type elementType, cx_uint32 max) {
    cx_list _this;
    _this = cx_declare(cx_list_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_list cx_listCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_list _this;
    _this = cx_declareChild(_parent, _name, cx_list_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_list cx_listDeclare(void) {
    cx_list _this;
    _this = cx_declare(cx_list_o);
    return _this;
}

cx_list cx_listDeclareChild(cx_object _parent, cx_string _name) {
    cx_list _this;
    _this = cx_declareChild(_parent, _name, cx_list_o);
    return _this;
}

cx_int16 cx_listDefine(cx_list _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

void cx_listUpdate(cx_list _this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(_this);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    cx_updateEnd(_this);
}

void cx_listSet(cx_list _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
}

cx_string cx_listStr(cx_list value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_list_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_list cx_listFromStr(cx_list value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_list_o), str);
    return value;
}

cx_int16 cx_listCopy(cx_list *dst, cx_list src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_listCompare(cx_list dst, cx_list src) {
    return cx_compare(dst, src);
}

cx_map cx_mapCreate(cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_map _this;
    _this = cx_declare(cx_map_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_setref(&_this->keyType, cx_type(keyType));
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_map cx_mapCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_map _this;
    _this = cx_declareChild(_parent, _name, cx_map_o);
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_setref(&_this->keyType, cx_type(keyType));
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_map cx_mapDeclare(void) {
    cx_map _this;
    _this = cx_declare(cx_map_o);
    return _this;
}

cx_map cx_mapDeclareChild(cx_object _parent, cx_string _name) {
    cx_map _this;
    _this = cx_declareChild(_parent, _name, cx_map_o);
    return _this;
}

cx_int16 cx_mapDefine(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_setref(&_this->keyType, cx_type(keyType));
    _this->max = max;
    return cx_define(_this);
}

void cx_mapUpdate(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_updateBegin(_this);
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_setref(&_this->keyType, cx_type(keyType));
    _this->max = max;
    cx_updateEnd(_this);
}

void cx_mapSet(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_setref(&_this->elementType, cx_type(elementType));
    cx_setref(&_this->keyType, cx_type(keyType));
    _this->max = max;
}

cx_string cx_mapStr(cx_map value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_map_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_map cx_mapFromStr(cx_map value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_map_o), str);
    return value;
}

cx_int16 cx_mapCopy(cx_map *dst, cx_map src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_mapCompare(cx_map dst, cx_map src) {
    return cx_compare(dst, src);
}

cx_member cx_memberCreate(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_member _this;
    _this = cx_declare(cx_member_o);
    cx_setref(&_this->type, cx_type(type));
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_member cx_memberCreateChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_member _this;
    _this = cx_declareChild(_parent, _name, cx_member_o);
    cx_setref(&_this->type, cx_type(type));
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_member cx_memberDeclare(void) {
    cx_member _this;
    _this = cx_declare(cx_member_o);
    return _this;
}

cx_member cx_memberDeclareChild(cx_object _parent, cx_string _name) {
    cx_member _this;
    _this = cx_declareChild(_parent, _name, cx_member_o);
    return _this;
}

cx_int16 cx_memberDefine(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_setref(&_this->type, cx_type(type));
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    return cx_define(_this);
}

void cx_memberUpdate(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_updateBegin(_this);
    cx_setref(&_this->type, cx_type(type));
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
    cx_updateEnd(_this);
}

void cx_memberSet(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_setref(&_this->type, cx_type(type));
    _this->modifiers = modifiers;
    _this->state = state;
    _this->weak = weak;
}

cx_string cx_memberStr(cx_member value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_member_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_member cx_memberFromStr(cx_member value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_member_o), str);
    return value;
}

cx_int16 cx_memberCopy(cx_member *dst, cx_member src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_memberCompare(cx_member dst, cx_member src) {
    return cx_compare(dst, src);
}

cx_memberSeq* cx_memberSeqCreate(void) {
    cx_memberSeq* _this;
    _this = cx_declare(cx_memberSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_memberSeq* cx_memberSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_memberSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_memberSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_memberSeq* cx_memberSeqDeclare(void) {
    cx_memberSeq* _this;
    _this = cx_declare(cx_memberSeq_o);
    return _this;
}

cx_memberSeq* cx_memberSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_memberSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_memberSeq_o);
    return _this;
}

cx_int16 cx_memberSeqDefine(cx_memberSeq* _this, cx_memberSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_memberSeqUpdate(cx_memberSeq* _this, cx_memberSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_memberSeqSet(cx_memberSeq* _this, cx_memberSeq value) {
    *_this = value;
}

cx_string cx_memberSeqStr(cx_memberSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_memberSeq* cx_memberSeqFromStr(cx_memberSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_memberSeq_o), str);
    return value;
}

cx_int16 cx_memberSeqCopy(cx_memberSeq* *dst, cx_memberSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_memberSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_memberSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_memberSeqCompare(cx_memberSeq* dst, cx_memberSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_memberSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_memberSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_memberSeqInit(cx_memberSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_memberSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_memberSeqDeinit(cx_memberSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_metaprocedure cx_metaprocedureCreate(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_metaprocedure _this;
    _this = cx_declare(cx_metaprocedure_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_metaprocedure cx_metaprocedureCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_metaprocedure _this;
    _this = cx_declareChild(_parent, _name, cx_metaprocedure_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_metaprocedure cx_metaprocedureDeclare(void) {
    cx_metaprocedure _this;
    _this = cx_declare(cx_metaprocedure_o);
    return _this;
}

cx_metaprocedure cx_metaprocedureDeclareChild(cx_object _parent, cx_string _name) {
    cx_metaprocedure _this;
    _this = cx_declareChild(_parent, _name, cx_metaprocedure_o);
    return _this;
}

cx_int16 cx_metaprocedureDefine(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    return cx_define(_this);
}

void cx_metaprocedureUpdate(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_updateBegin(_this);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
    cx_updateEnd(_this);
}

void cx_metaprocedureSet(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->referenceOnly = referenceOnly;
}

cx_string cx_metaprocedureStr(cx_metaprocedure value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_metaprocedure_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_metaprocedure cx_metaprocedureFromStr(cx_metaprocedure value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_metaprocedure_o), str);
    return value;
}

cx_int16 cx_metaprocedureCopy(cx_metaprocedure *dst, cx_metaprocedure src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_metaprocedureCompare(cx_metaprocedure dst, cx_metaprocedure src) {
    return cx_compare(dst, src);
}

cx_method cx_methodCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_method _this;
    _this = cx_declare(cx_method_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_method cx_methodCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_method _this;
    _this = cx_declareChild(_parent, _name, cx_method_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_method cx_methodDeclare(void) {
    cx_method _this;
    _this = cx_declare(cx_method_o);
    return _this;
}

cx_method cx_methodDeclareChild(cx_object _parent, cx_string _name) {
    cx_method _this;
    _this = cx_declareChild(_parent, _name, cx_method_o);
    return _this;
}

cx_int16 cx_methodDefine(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    return cx_define(_this);
}

void cx_methodUpdate(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_updateBegin(_this);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
    cx_updateEnd(_this);
}

void cx_methodSet(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    _this->virtual = virtual;
}

cx_string cx_methodStr(cx_method value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_method_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_method cx_methodFromStr(cx_method value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_method_o), str);
    return value;
}

cx_int16 cx_methodCopy(cx_method *dst, cx_method src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_methodCompare(cx_method dst, cx_method src) {
    return cx_compare(dst, src);
}

cx_modifier* cx_modifierCreate(void) {
    cx_modifier* _this;
    _this = cx_declare(cx_modifier_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_modifier* cx_modifierCreateChild(cx_object _parent, cx_string _name) {
    cx_modifier* _this;
    _this = cx_declareChild(_parent, _name, cx_modifier_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_modifier* cx_modifierDeclare(void) {
    cx_modifier* _this;
    _this = cx_declare(cx_modifier_o);
    return _this;
}

cx_modifier* cx_modifierDeclareChild(cx_object _parent, cx_string _name) {
    cx_modifier* _this;
    _this = cx_declareChild(_parent, _name, cx_modifier_o);
    return _this;
}

cx_int16 cx_modifierDefine(cx_modifier* _this, cx_modifier value) {
    *_this = value;
    return cx_define(_this);
}

void cx_modifierUpdate(cx_modifier* _this, cx_modifier value) {
    *_this = value;
    cx_update(_this);
}

void cx_modifierSet(cx_modifier* _this, cx_modifier value) {
    *_this = value;
}

cx_string cx_modifierStr(cx_modifier value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_modifier_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_modifier* cx_modifierFromStr(cx_modifier* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_modifier_o), str);
    return value;
}

cx_int16 cx_modifierCopy(cx_modifier* *dst, cx_modifier* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_modifier_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_modifier_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_modifierCompare(cx_modifier* dst, cx_modifier* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_modifier_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_modifier_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_modifierInit(cx_modifier* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_modifier_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_modifier_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_modifierDeinit(cx_modifier* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_modifier_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_object cx_objectCreate(void) {
    cx_object _this;
    _this = cx_declare(cx_object_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_object cx_objectCreateChild(cx_object _parent, cx_string _name) {
    cx_object _this;
    _this = cx_declareChild(_parent, _name, cx_object_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_objectSeq* cx_objectSeqCreate(void) {
    cx_objectSeq* _this;
    _this = cx_declare(cx_objectSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_objectSeq* cx_objectSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_objectSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_objectSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_objectSeq* cx_objectSeqDeclare(void) {
    cx_objectSeq* _this;
    _this = cx_declare(cx_objectSeq_o);
    return _this;
}

cx_objectSeq* cx_objectSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_objectSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_objectSeq_o);
    return _this;
}

cx_int16 cx_objectSeqDefine(cx_objectSeq* _this, cx_objectSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_objectSeqUpdate(cx_objectSeq* _this, cx_objectSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_objectSeqSet(cx_objectSeq* _this, cx_objectSeq value) {
    *_this = value;
}

cx_string cx_objectSeqStr(cx_objectSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_objectSeq* cx_objectSeqFromStr(cx_objectSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_objectSeq_o), str);
    return value;
}

cx_int16 cx_objectSeqCopy(cx_objectSeq* *dst, cx_objectSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_objectSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_objectSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_objectSeqCompare(cx_objectSeq* dst, cx_objectSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_objectSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_objectSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_objectSeqInit(cx_objectSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_objectSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_objectSeqDeinit(cx_objectSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_observableEvent cx_observableEventCreate(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_observableEvent _this;
    _this = cx_declare(cx_observableEvent_o);
    cx_event(_this)->kind = kind;
    cx_setref(&_this->observer, cx_observer(observer));
    cx_setref(&_this->me, me);
    cx_setref(&_this->source, source);
    cx_setref(&_this->observable, observable);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observableEvent cx_observableEventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_observableEvent _this;
    _this = cx_declareChild(_parent, _name, cx_observableEvent_o);
    cx_event(_this)->kind = kind;
    cx_setref(&_this->observer, cx_observer(observer));
    cx_setref(&_this->me, me);
    cx_setref(&_this->source, source);
    cx_setref(&_this->observable, observable);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observableEvent cx_observableEventDeclare(void) {
    cx_observableEvent _this;
    _this = cx_declare(cx_observableEvent_o);
    return _this;
}

cx_observableEvent cx_observableEventDeclareChild(cx_object _parent, cx_string _name) {
    cx_observableEvent _this;
    _this = cx_declareChild(_parent, _name, cx_observableEvent_o);
    return _this;
}

cx_int16 cx_observableEventDefine(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_event(_this)->kind = kind;
    cx_setref(&_this->observer, cx_observer(observer));
    cx_setref(&_this->me, me);
    cx_setref(&_this->source, source);
    cx_setref(&_this->observable, observable);
    return cx_define(_this);
}

void cx_observableEventUpdate(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_updateBegin(_this);
    cx_event(_this)->kind = kind;
    cx_setref(&_this->observer, cx_observer(observer));
    cx_setref(&_this->me, me);
    cx_setref(&_this->source, source);
    cx_setref(&_this->observable, observable);
    cx_updateEnd(_this);
}

void cx_observableEventSet(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_event(_this)->kind = kind;
    cx_setref(&_this->observer, cx_observer(observer));
    cx_setref(&_this->me, me);
    cx_setref(&_this->source, source);
    cx_setref(&_this->observable, observable);
}

cx_string cx_observableEventStr(cx_observableEvent value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_observableEvent_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_observableEvent cx_observableEventFromStr(cx_observableEvent value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_observableEvent_o), str);
    return value;
}

cx_int16 cx_observableEventCopy(cx_observableEvent *dst, cx_observableEvent src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_observableEventCompare(cx_observableEvent dst, cx_observableEvent src) {
    return cx_compare(dst, src);
}

cx_observer cx_observerCreate(cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me) {
    cx_observer _this;
    _this = cx_declare(cx_observer_o);
    cx_setref(&_this->observable, observable);
    _this->mask = mask;
    cx_setref(&_this->dispatcher, cx_dispatcher(dispatcher));
    cx_setref(&_this->me, me);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observer cx_observerCreateChild(cx_object _parent, cx_string _name, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me) {
    cx_observer _this;
    _this = cx_declareChild(_parent, _name, cx_observer_o);
    cx_setref(&_this->observable, observable);
    _this->mask = mask;
    cx_setref(&_this->dispatcher, cx_dispatcher(dispatcher));
    cx_setref(&_this->me, me);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observer cx_observerDeclare(void) {
    cx_observer _this;
    _this = cx_declare(cx_observer_o);
    return _this;
}

cx_observer cx_observerDeclareChild(cx_object _parent, cx_string _name) {
    cx_observer _this;
    _this = cx_declareChild(_parent, _name, cx_observer_o);
    return _this;
}

cx_int16 cx_observerDefine(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me) {
    cx_setref(&_this->observable, observable);
    _this->mask = mask;
    cx_setref(&_this->dispatcher, cx_dispatcher(dispatcher));
    cx_setref(&_this->me, me);
    return cx_define(_this);
}

void cx_observerUpdate(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me) {
    cx_updateBegin(_this);
    cx_setref(&_this->observable, observable);
    _this->mask = mask;
    cx_setref(&_this->dispatcher, cx_dispatcher(dispatcher));
    cx_setref(&_this->me, me);
    cx_updateEnd(_this);
}

void cx_observerSet(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me) {
    cx_setref(&_this->observable, observable);
    _this->mask = mask;
    cx_setref(&_this->dispatcher, cx_dispatcher(dispatcher));
    cx_setref(&_this->me, me);
}

cx_string cx_observerStr(cx_observer value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_observer_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_observer cx_observerFromStr(cx_observer value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_observer_o), str);
    return value;
}

cx_int16 cx_observerCopy(cx_observer *dst, cx_observer src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_observerCompare(cx_observer dst, cx_observer src) {
    return cx_compare(dst, src);
}

cx_observerSeq* cx_observerSeqCreate(void) {
    cx_observerSeq* _this;
    _this = cx_declare(cx_observerSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observerSeq* cx_observerSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_observerSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_observerSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_observerSeq* cx_observerSeqDeclare(void) {
    cx_observerSeq* _this;
    _this = cx_declare(cx_observerSeq_o);
    return _this;
}

cx_observerSeq* cx_observerSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_observerSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_observerSeq_o);
    return _this;
}

cx_int16 cx_observerSeqDefine(cx_observerSeq* _this, cx_observerSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_observerSeqUpdate(cx_observerSeq* _this, cx_observerSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_observerSeqSet(cx_observerSeq* _this, cx_observerSeq value) {
    *_this = value;
}

cx_string cx_observerSeqStr(cx_observerSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_observerSeq* cx_observerSeqFromStr(cx_observerSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_observerSeq_o), str);
    return value;
}

cx_int16 cx_observerSeqCopy(cx_observerSeq* *dst, cx_observerSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_observerSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_observerSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_observerSeqCompare(cx_observerSeq* dst, cx_observerSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_observerSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_observerSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_observerSeqInit(cx_observerSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_observerSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_observerSeqDeinit(cx_observerSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_octet* cx_octetCreate(void) {
    cx_octet* _this;
    _this = cx_declare(cx_octet_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_octet* cx_octetCreateChild(cx_object _parent, cx_string _name) {
    cx_octet* _this;
    _this = cx_declareChild(_parent, _name, cx_octet_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_octet* cx_octetDeclare(void) {
    cx_octet* _this;
    _this = cx_declare(cx_octet_o);
    return _this;
}

cx_octet* cx_octetDeclareChild(cx_object _parent, cx_string _name) {
    cx_octet* _this;
    _this = cx_declareChild(_parent, _name, cx_octet_o);
    return _this;
}

cx_int16 cx_octetDefine(cx_octet* _this, cx_octet value) {
    *_this = value;
    return cx_define(_this);
}

void cx_octetUpdate(cx_octet* _this, cx_octet value) {
    *_this = value;
    cx_update(_this);
}

void cx_octetSet(cx_octet* _this, cx_octet value) {
    *_this = value;
}

cx_string cx_octetStr(cx_octet value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_octet_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_octet* cx_octetFromStr(cx_octet* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_octet_o), str);
    return value;
}

cx_int16 cx_octetCopy(cx_octet* *dst, cx_octet* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_octet_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_octet_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_octetCompare(cx_octet* dst, cx_octet* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_octet_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_octet_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_octetInit(cx_octet* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_octet_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_octet_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_octetDeinit(cx_octet* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_octet_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_operatorKind* cx_operatorKindCreate(void) {
    cx_operatorKind* _this;
    _this = cx_declare(cx_operatorKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_operatorKind* cx_operatorKindCreateChild(cx_object _parent, cx_string _name) {
    cx_operatorKind* _this;
    _this = cx_declareChild(_parent, _name, cx_operatorKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_operatorKind* cx_operatorKindDeclare(void) {
    cx_operatorKind* _this;
    _this = cx_declare(cx_operatorKind_o);
    return _this;
}

cx_operatorKind* cx_operatorKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_operatorKind* _this;
    _this = cx_declareChild(_parent, _name, cx_operatorKind_o);
    return _this;
}

cx_int16 cx_operatorKindDefine(cx_operatorKind* _this, cx_operatorKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_operatorKindUpdate(cx_operatorKind* _this, cx_operatorKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_operatorKindSet(cx_operatorKind* _this, cx_operatorKind value) {
    *_this = value;
}

cx_string cx_operatorKindStr(cx_operatorKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_operatorKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_operatorKind* cx_operatorKindFromStr(cx_operatorKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_operatorKind_o), str);
    return value;
}

cx_int16 cx_operatorKindCopy(cx_operatorKind* *dst, cx_operatorKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_operatorKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_operatorKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_operatorKindCompare(cx_operatorKind* dst, cx_operatorKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_operatorKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_operatorKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_operatorKindInit(cx_operatorKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_operatorKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_operatorKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_operatorKindDeinit(cx_operatorKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_operatorKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_package cx_packageCreate(cx_string url) {
    cx_package _this;
    _this = cx_declare(cx_package_o);
    cx_setstr(&_this->url, url);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_package cx_packageCreateChild(cx_object _parent, cx_string _name, cx_string url) {
    cx_package _this;
    _this = cx_declareChild(_parent, _name, cx_package_o);
    cx_setstr(&_this->url, url);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_package cx_packageDeclare(void) {
    cx_package _this;
    _this = cx_declare(cx_package_o);
    return _this;
}

cx_package cx_packageDeclareChild(cx_object _parent, cx_string _name) {
    cx_package _this;
    _this = cx_declareChild(_parent, _name, cx_package_o);
    return _this;
}

cx_int16 cx_packageDefine(cx_package _this, cx_string url) {
    cx_setstr(&_this->url, url);
    return cx_define(_this);
}

void cx_packageUpdate(cx_package _this, cx_string url) {
    cx_updateBegin(_this);
    cx_setstr(&_this->url, url);
    cx_updateEnd(_this);
}

void cx_packageSet(cx_package _this, cx_string url) {
    cx_setstr(&_this->url, url);
}

cx_string cx_packageStr(cx_package value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_package_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_package cx_packageFromStr(cx_package value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_package_o), str);
    return value;
}

cx_int16 cx_packageCopy(cx_package *dst, cx_package src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_packageCompare(cx_package dst, cx_package src) {
    return cx_compare(dst, src);
}

cx_parameter* cx_parameterCreate(cx_string name, cx_type type, cx_bool passByReference) {
    cx_parameter* _this;
    _this = cx_declare(cx_parameter_o);
    cx_setstr(&_this->name, name);
    cx_setref(&_this->type, cx_type(type));
    _this->passByReference = passByReference;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_parameter* cx_parameterCreateChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference) {
    cx_parameter* _this;
    _this = cx_declareChild(_parent, _name, cx_parameter_o);
    cx_setstr(&_this->name, name);
    cx_setref(&_this->type, cx_type(type));
    _this->passByReference = passByReference;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_parameter* cx_parameterDeclare(void) {
    cx_parameter* _this;
    _this = cx_declare(cx_parameter_o);
    return _this;
}

cx_parameter* cx_parameterDeclareChild(cx_object _parent, cx_string _name) {
    cx_parameter* _this;
    _this = cx_declareChild(_parent, _name, cx_parameter_o);
    return _this;
}

cx_int16 cx_parameterDefine(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_setstr(&_this->name, name);
    cx_setref(&_this->type, cx_type(type));
    _this->passByReference = passByReference;
    return cx_define(_this);
}

void cx_parameterUpdate(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_updateBegin(_this);
    cx_setstr(&_this->name, name);
    cx_setref(&_this->type, cx_type(type));
    _this->passByReference = passByReference;
    cx_updateEnd(_this);
}

void cx_parameterSet(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_setstr(&_this->name, name);
    cx_setref(&_this->type, cx_type(type));
    _this->passByReference = passByReference;
}

cx_string cx_parameterStr(cx_parameter* value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_parameter* cx_parameterFromStr(cx_parameter* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_parameter_o), str);
    return value;
}

cx_int16 cx_parameterCopy(cx_parameter* *dst, cx_parameter* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameter_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameter_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_parameterCompare(cx_parameter* dst, cx_parameter* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameter_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameter_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_parameterInit(cx_parameter* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_parameter_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_parameterDeinit(cx_parameter* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_parameterSeq* cx_parameterSeqCreate(void) {
    cx_parameterSeq* _this;
    _this = cx_declare(cx_parameterSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_parameterSeq* cx_parameterSeqCreateChild(cx_object _parent, cx_string _name) {
    cx_parameterSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_parameterSeq_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_parameterSeq* cx_parameterSeqDeclare(void) {
    cx_parameterSeq* _this;
    _this = cx_declare(cx_parameterSeq_o);
    return _this;
}

cx_parameterSeq* cx_parameterSeqDeclareChild(cx_object _parent, cx_string _name) {
    cx_parameterSeq* _this;
    _this = cx_declareChild(_parent, _name, cx_parameterSeq_o);
    return _this;
}

cx_int16 cx_parameterSeqDefine(cx_parameterSeq* _this, cx_parameterSeq value) {
    *_this = value;
    return cx_define(_this);
}

void cx_parameterSeqUpdate(cx_parameterSeq* _this, cx_parameterSeq value) {
    *_this = value;
    cx_update(_this);
}

void cx_parameterSeqSet(cx_parameterSeq* _this, cx_parameterSeq value) {
    *_this = value;
}

cx_string cx_parameterSeqStr(cx_parameterSeq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterSeq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_parameterSeq* cx_parameterSeqFromStr(cx_parameterSeq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_parameterSeq_o), str);
    return value;
}

cx_int16 cx_parameterSeqCopy(cx_parameterSeq* *dst, cx_parameterSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameterSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameterSeq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_parameterSeqCompare(cx_parameterSeq* dst, cx_parameterSeq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameterSeq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameterSeq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_parameterSeqInit(cx_parameterSeq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_parameterSeq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterSeq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_parameterSeqDeinit(cx_parameterSeq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterSeq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_primitive cx_primitiveCreate(cx_width width) {
    cx_primitive _this;
    _this = cx_declare(cx_primitive_o);
    _this->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_primitive cx_primitiveCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_primitive _this;
    _this = cx_declareChild(_parent, _name, cx_primitive_o);
    _this->width = width;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_primitive cx_primitiveDeclare(void) {
    cx_primitive _this;
    _this = cx_declare(cx_primitive_o);
    return _this;
}

cx_primitive cx_primitiveDeclareChild(cx_object _parent, cx_string _name) {
    cx_primitive _this;
    _this = cx_declareChild(_parent, _name, cx_primitive_o);
    return _this;
}

cx_int16 cx_primitiveDefine(cx_primitive _this, cx_width width) {
    _this->width = width;
    return cx_define(_this);
}

void cx_primitiveUpdate(cx_primitive _this, cx_width width) {
    cx_updateBegin(_this);
    _this->width = width;
    cx_updateEnd(_this);
}

void cx_primitiveSet(cx_primitive _this, cx_width width) {
    _this->width = width;
}

cx_string cx_primitiveStr(cx_primitive value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_primitive_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_primitive cx_primitiveFromStr(cx_primitive value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_primitive_o), str);
    return value;
}

cx_int16 cx_primitiveCopy(cx_primitive *dst, cx_primitive src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_primitiveCompare(cx_primitive dst, cx_primitive src) {
    return cx_compare(dst, src);
}

cx_primitiveKind* cx_primitiveKindCreate(void) {
    cx_primitiveKind* _this;
    _this = cx_declare(cx_primitiveKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_primitiveKind* cx_primitiveKindCreateChild(cx_object _parent, cx_string _name) {
    cx_primitiveKind* _this;
    _this = cx_declareChild(_parent, _name, cx_primitiveKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_primitiveKind* cx_primitiveKindDeclare(void) {
    cx_primitiveKind* _this;
    _this = cx_declare(cx_primitiveKind_o);
    return _this;
}

cx_primitiveKind* cx_primitiveKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_primitiveKind* _this;
    _this = cx_declareChild(_parent, _name, cx_primitiveKind_o);
    return _this;
}

cx_int16 cx_primitiveKindDefine(cx_primitiveKind* _this, cx_primitiveKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_primitiveKindUpdate(cx_primitiveKind* _this, cx_primitiveKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_primitiveKindSet(cx_primitiveKind* _this, cx_primitiveKind value) {
    *_this = value;
}

cx_string cx_primitiveKindStr(cx_primitiveKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_primitiveKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_primitiveKind* cx_primitiveKindFromStr(cx_primitiveKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_primitiveKind_o), str);
    return value;
}

cx_int16 cx_primitiveKindCopy(cx_primitiveKind* *dst, cx_primitiveKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_primitiveKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_primitiveKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_primitiveKindCompare(cx_primitiveKind* dst, cx_primitiveKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_primitiveKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_primitiveKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_primitiveKindInit(cx_primitiveKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_primitiveKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_primitiveKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_primitiveKindDeinit(cx_primitiveKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_primitiveKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_procedure cx_procedureCreate(cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_procedure _this;
    _this = cx_declare(cx_procedure_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_procedure cx_procedureCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_procedure _this;
    _this = cx_declareChild(_parent, _name, cx_procedure_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_procedure cx_procedureDeclare(void) {
    cx_procedure _this;
    _this = cx_declare(cx_procedure_o);
    return _this;
}

cx_procedure cx_procedureDeclareChild(cx_object _parent, cx_string _name) {
    cx_procedure _this;
    _this = cx_declareChild(_parent, _name, cx_procedure_o);
    return _this;
}

cx_int16 cx_procedureDefine(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    return cx_define(_this);
}

void cx_procedureUpdate(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_updateBegin(_this);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
    cx_updateEnd(_this);
}

void cx_procedureSet(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    cx_struct(_this)->baseAccess = baseAccess;
    _this->kind = kind;
}

cx_string cx_procedureStr(cx_procedure value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_procedure_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_procedure cx_procedureFromStr(cx_procedure value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_procedure_o), str);
    return value;
}

cx_int16 cx_procedureCopy(cx_procedure *dst, cx_procedure src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_procedureCompare(cx_procedure dst, cx_procedure src) {
    return cx_compare(dst, src);
}

cx_procedureKind* cx_procedureKindCreate(void) {
    cx_procedureKind* _this;
    _this = cx_declare(cx_procedureKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_procedureKind* cx_procedureKindCreateChild(cx_object _parent, cx_string _name) {
    cx_procedureKind* _this;
    _this = cx_declareChild(_parent, _name, cx_procedureKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_procedureKind* cx_procedureKindDeclare(void) {
    cx_procedureKind* _this;
    _this = cx_declare(cx_procedureKind_o);
    return _this;
}

cx_procedureKind* cx_procedureKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_procedureKind* _this;
    _this = cx_declareChild(_parent, _name, cx_procedureKind_o);
    return _this;
}

cx_int16 cx_procedureKindDefine(cx_procedureKind* _this, cx_procedureKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_procedureKindUpdate(cx_procedureKind* _this, cx_procedureKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_procedureKindSet(cx_procedureKind* _this, cx_procedureKind value) {
    *_this = value;
}

cx_string cx_procedureKindStr(cx_procedureKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_procedureKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_procedureKind* cx_procedureKindFromStr(cx_procedureKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_procedureKind_o), str);
    return value;
}

cx_int16 cx_procedureKindCopy(cx_procedureKind* *dst, cx_procedureKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_procedureKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_procedureKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_procedureKindCompare(cx_procedureKind* dst, cx_procedureKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_procedureKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_procedureKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_procedureKindInit(cx_procedureKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_procedureKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_procedureKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_procedureKindDeinit(cx_procedureKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_procedureKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_sequence cx_sequenceCreate(cx_type elementType, cx_uint32 max) {
    cx_sequence _this;
    _this = cx_declare(cx_sequence_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_sequence cx_sequenceCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_sequence _this;
    _this = cx_declareChild(_parent, _name, cx_sequence_o);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_sequence cx_sequenceDeclare(void) {
    cx_sequence _this;
    _this = cx_declare(cx_sequence_o);
    return _this;
}

cx_sequence cx_sequenceDeclareChild(cx_object _parent, cx_string _name) {
    cx_sequence _this;
    _this = cx_declareChild(_parent, _name, cx_sequence_o);
    return _this;
}

cx_int16 cx_sequenceDefine(cx_sequence _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    return cx_define(_this);
}

void cx_sequenceUpdate(cx_sequence _this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(_this);
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
    cx_updateEnd(_this);
}

void cx_sequenceSet(cx_sequence _this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(_this)->elementType, cx_type(elementType));
    cx_collection(_this)->max = max;
}

cx_string cx_sequenceStr(cx_sequence value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_sequence_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_sequence cx_sequenceFromStr(cx_sequence value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_sequence_o), str);
    return value;
}

cx_int16 cx_sequenceCopy(cx_sequence *dst, cx_sequence src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_sequenceCompare(cx_sequence dst, cx_sequence src) {
    return cx_compare(dst, src);
}

cx_state* cx_stateCreate(void) {
    cx_state* _this;
    _this = cx_declare(cx_state_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_state* cx_stateCreateChild(cx_object _parent, cx_string _name) {
    cx_state* _this;
    _this = cx_declareChild(_parent, _name, cx_state_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_state* cx_stateDeclare(void) {
    cx_state* _this;
    _this = cx_declare(cx_state_o);
    return _this;
}

cx_state* cx_stateDeclareChild(cx_object _parent, cx_string _name) {
    cx_state* _this;
    _this = cx_declareChild(_parent, _name, cx_state_o);
    return _this;
}

cx_int16 cx_stateDefine(cx_state* _this, cx_state value) {
    *_this = value;
    return cx_define(_this);
}

void cx_stateUpdate(cx_state* _this, cx_state value) {
    *_this = value;
    cx_update(_this);
}

void cx_stateSet(cx_state* _this, cx_state value) {
    *_this = value;
}

cx_string cx_stateStr(cx_state value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_state_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_state* cx_stateFromStr(cx_state* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_state_o), str);
    return value;
}

cx_int16 cx_stateCopy(cx_state* *dst, cx_state* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_state_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_state_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_stateCompare(cx_state* dst, cx_state* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_state_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_state_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_stateInit(cx_state* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_state_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_state_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_stateDeinit(cx_state* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_state_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_string* cx_stringCreate(void) {
    cx_string* _this;
    _this = cx_declare(cx_string_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_string* cx_stringCreateChild(cx_object _parent, cx_string _name) {
    cx_string* _this;
    _this = cx_declareChild(_parent, _name, cx_string_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_string* cx_stringDeclare(void) {
    cx_string* _this;
    _this = cx_declare(cx_string_o);
    return _this;
}

cx_string* cx_stringDeclareChild(cx_object _parent, cx_string _name) {
    cx_string* _this;
    _this = cx_declareChild(_parent, _name, cx_string_o);
    return _this;
}

cx_int16 cx_stringDefine(cx_string* _this, cx_string value) {
    *_this = value;
    return cx_define(_this);
}

void cx_stringUpdate(cx_string* _this, cx_string value) {
    *_this = value;
    cx_update(_this);
}

void cx_stringSet(cx_string* _this, cx_string value) {
    *_this = value;
}

cx_string cx_stringStr(cx_string value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_string_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_string* cx_stringFromStr(cx_string* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_string_o), str);
    return value;
}

cx_int16 cx_stringCopy(cx_string* *dst, cx_string* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_string_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_string_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_stringCompare(cx_string* dst, cx_string* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_string_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_string_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_stringInit(cx_string* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_string_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_string_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_stringDeinit(cx_string* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_string_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_struct cx_structCreate(cx_interface base, cx_modifier baseAccess) {
    cx_struct _this;
    _this = cx_declare(cx_struct_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    _this->baseAccess = baseAccess;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_struct cx_structCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess) {
    cx_struct _this;
    _this = cx_declareChild(_parent, _name, cx_struct_o);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    _this->baseAccess = baseAccess;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_struct cx_structDeclare(void) {
    cx_struct _this;
    _this = cx_declare(cx_struct_o);
    return _this;
}

cx_struct cx_structDeclareChild(cx_object _parent, cx_string _name) {
    cx_struct _this;
    _this = cx_declareChild(_parent, _name, cx_struct_o);
    return _this;
}

cx_int16 cx_structDefine(cx_struct _this, cx_interface base, cx_modifier baseAccess) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    _this->baseAccess = baseAccess;
    return cx_define(_this);
}

void cx_structUpdate(cx_struct _this, cx_interface base, cx_modifier baseAccess) {
    cx_updateBegin(_this);
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    _this->baseAccess = baseAccess;
    cx_updateEnd(_this);
}

void cx_structSet(cx_struct _this, cx_interface base, cx_modifier baseAccess) {
    cx_setref(&cx_interface(_this)->base, cx_interface(base));
    _this->baseAccess = baseAccess;
}

cx_string cx_structStr(cx_struct value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_struct_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_struct cx_structFromStr(cx_struct value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_struct_o), str);
    return value;
}

cx_int16 cx_structCopy(cx_struct *dst, cx_struct src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_structCompare(cx_struct dst, cx_struct src) {
    return cx_compare(dst, src);
}

cx_text cx_textCreate(cx_width charWidth, cx_uint64 length) {
    cx_text _this;
    _this = cx_declare(cx_text_o);
    _this->charWidth = charWidth;
    _this->length = length;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_text cx_textCreateChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length) {
    cx_text _this;
    _this = cx_declareChild(_parent, _name, cx_text_o);
    _this->charWidth = charWidth;
    _this->length = length;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_text cx_textDeclare(void) {
    cx_text _this;
    _this = cx_declare(cx_text_o);
    return _this;
}

cx_text cx_textDeclareChild(cx_object _parent, cx_string _name) {
    cx_text _this;
    _this = cx_declareChild(_parent, _name, cx_text_o);
    return _this;
}

cx_int16 cx_textDefine(cx_text _this, cx_width charWidth, cx_uint64 length) {
    _this->charWidth = charWidth;
    _this->length = length;
    return cx_define(_this);
}

void cx_textUpdate(cx_text _this, cx_width charWidth, cx_uint64 length) {
    cx_updateBegin(_this);
    _this->charWidth = charWidth;
    _this->length = length;
    cx_updateEnd(_this);
}

void cx_textSet(cx_text _this, cx_width charWidth, cx_uint64 length) {
    _this->charWidth = charWidth;
    _this->length = length;
}

cx_string cx_textStr(cx_text value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_text_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_text cx_textFromStr(cx_text value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_text_o), str);
    return value;
}

cx_int16 cx_textCopy(cx_text *dst, cx_text src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_textCompare(cx_text dst, cx_text src) {
    return cx_compare(dst, src);
}

cx_type cx_typeCreate(cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_type _this;
    _this = cx_declare(cx_type_o);
    cx_setref(&_this->defaultType, cx_type(defaultType));
    cx_setref(&_this->parentType, cx_type(parentType));
    _this->parentState = parentState;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_type cx_typeCreateChild(cx_object _parent, cx_string _name, cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_type _this;
    _this = cx_declareChild(_parent, _name, cx_type_o);
    cx_setref(&_this->defaultType, cx_type(defaultType));
    cx_setref(&_this->parentType, cx_type(parentType));
    _this->parentState = parentState;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_type cx_typeDeclare(void) {
    cx_type _this;
    _this = cx_declare(cx_type_o);
    return _this;
}

cx_type cx_typeDeclareChild(cx_object _parent, cx_string _name) {
    cx_type _this;
    _this = cx_declareChild(_parent, _name, cx_type_o);
    return _this;
}

cx_int16 cx_typeDefine(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_setref(&_this->defaultType, cx_type(defaultType));
    cx_setref(&_this->parentType, cx_type(parentType));
    _this->parentState = parentState;
    return cx_define(_this);
}

void cx_typeUpdate(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_updateBegin(_this);
    cx_setref(&_this->defaultType, cx_type(defaultType));
    cx_setref(&_this->parentType, cx_type(parentType));
    _this->parentState = parentState;
    cx_updateEnd(_this);
}

void cx_typeSet(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState) {
    cx_setref(&_this->defaultType, cx_type(defaultType));
    cx_setref(&_this->parentType, cx_type(parentType));
    _this->parentState = parentState;
}

cx_string cx_typeStr(cx_type value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_type_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_type cx_typeFromStr(cx_type value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_type_o), str);
    return value;
}

cx_int16 cx_typeCopy(cx_type *dst, cx_type src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_typeCompare(cx_type dst, cx_type src) {
    return cx_compare(dst, src);
}

cx_typeKind* cx_typeKindCreate(void) {
    cx_typeKind* _this;
    _this = cx_declare(cx_typeKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_typeKind* cx_typeKindCreateChild(cx_object _parent, cx_string _name) {
    cx_typeKind* _this;
    _this = cx_declareChild(_parent, _name, cx_typeKind_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_typeKind* cx_typeKindDeclare(void) {
    cx_typeKind* _this;
    _this = cx_declare(cx_typeKind_o);
    return _this;
}

cx_typeKind* cx_typeKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_typeKind* _this;
    _this = cx_declareChild(_parent, _name, cx_typeKind_o);
    return _this;
}

cx_int16 cx_typeKindDefine(cx_typeKind* _this, cx_typeKind value) {
    *_this = value;
    return cx_define(_this);
}

void cx_typeKindUpdate(cx_typeKind* _this, cx_typeKind value) {
    *_this = value;
    cx_update(_this);
}

void cx_typeKindSet(cx_typeKind* _this, cx_typeKind value) {
    *_this = value;
}

cx_string cx_typeKindStr(cx_typeKind value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_typeKind_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_typeKind* cx_typeKindFromStr(cx_typeKind* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_typeKind_o), str);
    return value;
}

cx_int16 cx_typeKindCopy(cx_typeKind* *dst, cx_typeKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_typeKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_typeKind_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_typeKindCompare(cx_typeKind* dst, cx_typeKind* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_typeKind_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_typeKind_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_typeKindInit(cx_typeKind* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_typeKind_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_typeKind_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_typeKindDeinit(cx_typeKind* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_typeKind_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_uint cx_uintCreate(cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_uint _this;
    _this = cx_declare(cx_uint_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint cx_uintCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_uint _this;
    _this = cx_declareChild(_parent, _name, cx_uint_o);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint cx_uintDeclare(void) {
    cx_uint _this;
    _this = cx_declare(cx_uint_o);
    return _this;
}

cx_uint cx_uintDeclareChild(cx_object _parent, cx_string _name) {
    cx_uint _this;
    _this = cx_declareChild(_parent, _name, cx_uint_o);
    return _this;
}

cx_int16 cx_uintDefine(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    return cx_define(_this);
}

void cx_uintUpdate(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_updateBegin(_this);
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
    cx_updateEnd(_this);
}

void cx_uintSet(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_primitive(_this)->width = width;
    _this->min = min;
    _this->max = max;
}

cx_string cx_uintStr(cx_uint value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_uint_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_uint cx_uintFromStr(cx_uint value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_uint_o), str);
    return value;
}

cx_int16 cx_uintCopy(cx_uint *dst, cx_uint src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_uintCompare(cx_uint dst, cx_uint src) {
    return cx_compare(dst, src);
}

cx_uint16* cx_uint16Create(void) {
    cx_uint16* _this;
    _this = cx_declare(cx_uint16_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint16* cx_uint16CreateChild(cx_object _parent, cx_string _name) {
    cx_uint16* _this;
    _this = cx_declareChild(_parent, _name, cx_uint16_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint16* cx_uint16Declare(void) {
    cx_uint16* _this;
    _this = cx_declare(cx_uint16_o);
    return _this;
}

cx_uint16* cx_uint16DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint16* _this;
    _this = cx_declareChild(_parent, _name, cx_uint16_o);
    return _this;
}

cx_int16 cx_uint16Define(cx_uint16* _this, cx_uint16 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_uint16Update(cx_uint16* _this, cx_uint16 value) {
    *_this = value;
    cx_update(_this);
}

void cx_uint16Set(cx_uint16* _this, cx_uint16 value) {
    *_this = value;
}

cx_string cx_uint16Str(cx_uint16 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint16_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_uint16* cx_uint16FromStr(cx_uint16* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_uint16_o), str);
    return value;
}

cx_int16 cx_uint16Copy(cx_uint16* *dst, cx_uint16* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint16_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint16_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_uint16Compare(cx_uint16* dst, cx_uint16* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint16_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint16_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_uint16Init(cx_uint16* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_uint16_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint16_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_uint16Deinit(cx_uint16* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint16_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_uint32* cx_uint32Create(void) {
    cx_uint32* _this;
    _this = cx_declare(cx_uint32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint32* cx_uint32CreateChild(cx_object _parent, cx_string _name) {
    cx_uint32* _this;
    _this = cx_declareChild(_parent, _name, cx_uint32_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint32* cx_uint32Declare(void) {
    cx_uint32* _this;
    _this = cx_declare(cx_uint32_o);
    return _this;
}

cx_uint32* cx_uint32DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint32* _this;
    _this = cx_declareChild(_parent, _name, cx_uint32_o);
    return _this;
}

cx_int16 cx_uint32Define(cx_uint32* _this, cx_uint32 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_uint32Update(cx_uint32* _this, cx_uint32 value) {
    *_this = value;
    cx_update(_this);
}

void cx_uint32Set(cx_uint32* _this, cx_uint32 value) {
    *_this = value;
}

cx_string cx_uint32Str(cx_uint32 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint32_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_uint32* cx_uint32FromStr(cx_uint32* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_uint32_o), str);
    return value;
}

cx_int16 cx_uint32Copy(cx_uint32* *dst, cx_uint32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint32_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_uint32Compare(cx_uint32* dst, cx_uint32* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint32_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint32_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_uint32Init(cx_uint32* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_uint32_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint32_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_uint32Deinit(cx_uint32* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint32_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_uint64* cx_uint64Create(void) {
    cx_uint64* _this;
    _this = cx_declare(cx_uint64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint64* cx_uint64CreateChild(cx_object _parent, cx_string _name) {
    cx_uint64* _this;
    _this = cx_declareChild(_parent, _name, cx_uint64_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint64* cx_uint64Declare(void) {
    cx_uint64* _this;
    _this = cx_declare(cx_uint64_o);
    return _this;
}

cx_uint64* cx_uint64DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint64* _this;
    _this = cx_declareChild(_parent, _name, cx_uint64_o);
    return _this;
}

cx_int16 cx_uint64Define(cx_uint64* _this, cx_uint64 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_uint64Update(cx_uint64* _this, cx_uint64 value) {
    *_this = value;
    cx_update(_this);
}

void cx_uint64Set(cx_uint64* _this, cx_uint64 value) {
    *_this = value;
}

cx_string cx_uint64Str(cx_uint64 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint64_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_uint64* cx_uint64FromStr(cx_uint64* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_uint64_o), str);
    return value;
}

cx_int16 cx_uint64Copy(cx_uint64* *dst, cx_uint64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint64_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_uint64Compare(cx_uint64* dst, cx_uint64* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint64_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint64_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_uint64Init(cx_uint64* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_uint64_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint64_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_uint64Deinit(cx_uint64* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint64_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_uint8* cx_uint8Create(void) {
    cx_uint8* _this;
    _this = cx_declare(cx_uint8_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint8* cx_uint8CreateChild(cx_object _parent, cx_string _name) {
    cx_uint8* _this;
    _this = cx_declareChild(_parent, _name, cx_uint8_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_uint8* cx_uint8Declare(void) {
    cx_uint8* _this;
    _this = cx_declare(cx_uint8_o);
    return _this;
}

cx_uint8* cx_uint8DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint8* _this;
    _this = cx_declareChild(_parent, _name, cx_uint8_o);
    return _this;
}

cx_int16 cx_uint8Define(cx_uint8* _this, cx_uint8 value) {
    *_this = value;
    return cx_define(_this);
}

void cx_uint8Update(cx_uint8* _this, cx_uint8 value) {
    *_this = value;
    cx_update(_this);
}

void cx_uint8Set(cx_uint8* _this, cx_uint8 value) {
    *_this = value;
}

cx_string cx_uint8Str(cx_uint8 value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint8_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_uint8* cx_uint8FromStr(cx_uint8* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_uint8_o), str);
    return value;
}

cx_int16 cx_uint8Copy(cx_uint8* *dst, cx_uint8* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint8_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint8_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_uint8Compare(cx_uint8* dst, cx_uint8* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_uint8_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_uint8_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_uint8Init(cx_uint8* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_uint8_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint8_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_uint8Deinit(cx_uint8* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_uint8_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_virtual cx_virtualCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_virtual _this;
    _this = cx_declare(cx_virtual_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_virtual cx_virtualCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_virtual _this;
    _this = cx_declareChild(_parent, _name, cx_virtual_o);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_virtual cx_virtualDeclare(void) {
    cx_virtual _this;
    _this = cx_declare(cx_virtual_o);
    return _this;
}

cx_virtual cx_virtualDeclareChild(cx_object _parent, cx_string _name) {
    cx_virtual _this;
    _this = cx_declareChild(_parent, _name, cx_virtual_o);
    return _this;
}

cx_int16 cx_virtualDefine(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    return cx_define(_this);
}

void cx_virtualUpdate(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_updateBegin(_this);
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
    cx_updateEnd(_this);
}

void cx_virtualSet(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(_this)->returnType, cx_type(returnType));
    cx_function(_this)->returnsReference = returnsReference;
    cx_method(_this)->virtual = virtual;
}

cx_string cx_virtualStr(cx_virtual value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_virtual_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_virtual cx_virtualFromStr(cx_virtual value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_virtual_o), str);
    return value;
}

cx_int16 cx_virtualCopy(cx_virtual *dst, cx_virtual src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_virtualCompare(cx_virtual dst, cx_virtual src) {
    return cx_compare(dst, src);
}

cx_void* cx_voidCreate(void) {
    cx_void* _this;
    _this = cx_declare(cx_void_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_void* cx_voidCreateChild(cx_object _parent, cx_string _name) {
    cx_void* _this;
    _this = cx_declareChild(_parent, _name, cx_void_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_vtable* cx_vtableCreate(void) {
    cx_vtable* _this;
    _this = cx_declare(cx_vtable_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_vtable* cx_vtableCreateChild(cx_object _parent, cx_string _name) {
    cx_vtable* _this;
    _this = cx_declareChild(_parent, _name, cx_vtable_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_vtable* cx_vtableDeclare(void) {
    cx_vtable* _this;
    _this = cx_declare(cx_vtable_o);
    return _this;
}

cx_vtable* cx_vtableDeclareChild(cx_object _parent, cx_string _name) {
    cx_vtable* _this;
    _this = cx_declareChild(_parent, _name, cx_vtable_o);
    return _this;
}

cx_int16 cx_vtableDefine(cx_vtable* _this, cx_vtable value) {
    *_this = value;
    return cx_define(_this);
}

void cx_vtableUpdate(cx_vtable* _this, cx_vtable value) {
    *_this = value;
    cx_update(_this);
}

void cx_vtableSet(cx_vtable* _this, cx_vtable value) {
    *_this = value;
}

cx_string cx_vtableStr(cx_vtable value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_vtable_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_vtable* cx_vtableFromStr(cx_vtable* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_vtable_o), str);
    return value;
}

cx_int16 cx_vtableCopy(cx_vtable* *dst, cx_vtable* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_vtable_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_vtable_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_vtableCompare(cx_vtable* dst, cx_vtable* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_vtable_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_vtable_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_vtableInit(cx_vtable* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_vtable_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_vtable_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_vtableDeinit(cx_vtable* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_vtable_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_width* cx_widthCreate(void) {
    cx_width* _this;
    _this = cx_declare(cx_width_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_width* cx_widthCreateChild(cx_object _parent, cx_string _name) {
    cx_width* _this;
    _this = cx_declareChild(_parent, _name, cx_width_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_width* cx_widthDeclare(void) {
    cx_width* _this;
    _this = cx_declare(cx_width_o);
    return _this;
}

cx_width* cx_widthDeclareChild(cx_object _parent, cx_string _name) {
    cx_width* _this;
    _this = cx_declareChild(_parent, _name, cx_width_o);
    return _this;
}

cx_int16 cx_widthDefine(cx_width* _this, cx_width value) {
    *_this = value;
    return cx_define(_this);
}

void cx_widthUpdate(cx_width* _this, cx_width value) {
    *_this = value;
    cx_update(_this);
}

void cx_widthSet(cx_width* _this, cx_width value) {
    *_this = value;
}

cx_string cx_widthStr(cx_width value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_width_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_width* cx_widthFromStr(cx_width* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_width_o), str);
    return value;
}

cx_int16 cx_widthCopy(cx_width* *dst, cx_width* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_width_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_width_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_widthCompare(cx_width* dst, cx_width* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_width_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_width_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_widthInit(cx_width* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_width_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_width_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_widthDeinit(cx_width* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_width_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_word* cx_wordCreate(void) {
    cx_word* _this;
    _this = cx_declare(cx_word_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_word* cx_wordCreateChild(cx_object _parent, cx_string _name) {
    cx_word* _this;
    _this = cx_declareChild(_parent, _name, cx_word_o);
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

cx_word* cx_wordDeclare(void) {
    cx_word* _this;
    _this = cx_declare(cx_word_o);
    return _this;
}

cx_word* cx_wordDeclareChild(cx_object _parent, cx_string _name) {
    cx_word* _this;
    _this = cx_declareChild(_parent, _name, cx_word_o);
    return _this;
}

cx_int16 cx_wordDefine(cx_word* _this, cx_word value) {
    *_this = value;
    return cx_define(_this);
}

void cx_wordUpdate(cx_word* _this, cx_word value) {
    *_this = value;
    cx_update(_this);
}

void cx_wordSet(cx_word* _this, cx_word value) {
    *_this = value;
}

cx_string cx_wordStr(cx_word value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_word_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_word* cx_wordFromStr(cx_word* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_word_o), str);
    return value;
}

cx_int16 cx_wordCopy(cx_word* *dst, cx_word* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_word_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_word_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_wordCompare(cx_word* dst, cx_word* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_word_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_word_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_wordInit(cx_word* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_word_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_word_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_wordDeinit(cx_word* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_word_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_interface cx_interfaceSeqAppend(cx_interfaceSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_interfaceSeqSize(cx_interfaceSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_interface_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interface_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_interfaceSeq__clear(cx_interfaceSeq *seq) {
    cx_interfaceSeqSize(seq, 0);
}

cx_interfaceVector* cx_interfaceVectorSeqAppend(cx_interfaceVectorSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[seq->length-1]);
        cx_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void cx_interfaceVectorSeqSize(cx_interfaceVectorSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_interfaceVector_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVector_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_interfaceVectorSeq__clear(cx_interfaceVectorSeq *seq) {
    cx_interfaceVectorSeqSize(seq, 0);
}

cx_member cx_memberSeqAppend(cx_memberSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_memberSeqSize(cx_memberSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_member_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_member_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_memberSeq__clear(cx_memberSeq *seq) {
    cx_memberSeqSize(seq, 0);
}

cx_object cx_objectSeqAppend(cx_objectSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_objectSeqSize(cx_objectSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_object_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_object_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_objectSeq__clear(cx_objectSeq *seq) {
    cx_objectSeqSize(seq, 0);
}

cx_observer cx_observerSeqAppend(cx_observerSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_observerSeqSize(cx_observerSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_observer_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_observer_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_observerSeq__clear(cx_observerSeq *seq) {
    cx_observerSeqSize(seq, 0);
}

cx_parameter* cx_parameterSeqAppend(cx_parameterSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[seq->length-1]);
        cx_initv(&v);
    }
    return &seq->buffer[seq->length-1];
}

void cx_parameterSeqSize(cx_parameterSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_parameterSeq__clear(cx_parameterSeq *seq) {
    cx_parameterSeqSize(seq, 0);
}

cx_function cx_vtableAppend(cx_vtable *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_function_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_vtableSize(cx_vtable *seq, cx_uint32 length) {
    cx_uint32 size;
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_function_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_function_o), &seq->buffer[i]);
                cx_deinitv(&v);
            }
        }
    }
    seq->length = length;
}

void cx_vtable__clear(cx_vtable *seq) {
    cx_vtableSize(seq, 0);
}

