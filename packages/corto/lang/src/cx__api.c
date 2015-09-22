/* cx__api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#define corto_lang_LIB
#include "cx.h"

cx_alias cx_aliasCreate(cx_member member) {
    cx_alias this;
    this = cx_declare(cx_alias_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->member, cx_member(member));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_alias cx_aliasCreateChild(cx_object _parent, cx_string _name, cx_member member) {
    cx_alias this;
    this = cx_declareChild(_parent, _name, cx_alias_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->member, cx_member(member));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_alias cx_aliasDeclare(void) {
    cx_alias this;
    this = cx_declare(cx_alias_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_alias cx_aliasDeclareChild(cx_object _parent, cx_string _name) {
    cx_alias this;
    this = cx_declareChild(_parent, _name, cx_alias_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_aliasDefine(cx_alias this, cx_member member) {
    cx_setref(&this->member, cx_member(member));
    return cx_define(this);
}

void cx_aliasUpdate(cx_alias this, cx_member member) {
    cx_updateBegin(this);
    cx_setref(&this->member, cx_member(member));
    cx_updateEnd(this);
}

void cx_aliasSet(cx_alias this, cx_member member) {
    cx_setref(&this->member, cx_member(member));
}

cx_string cx_aliasStr(cx_alias value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_alias_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_alias cx_aliasFromStr(cx_alias value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_alias_o), str);
    return value;
}

cx_int16 cx_aliasCopy(cx_alias *dst, cx_alias src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_aliasCompare(cx_alias dst, cx_alias src) {
    return cx_compare(dst, src);
}

cx_any* cx_anyCreate(cx_any value) {
    cx_any* this;
    this = cx_declare(cx_any_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_any* cx_anyCreateChild(cx_object _parent, cx_string _name, cx_any value) {
    cx_any* this;
    this = cx_declareChild(_parent, _name, cx_any_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_any* cx_anyDeclare(void) {
    cx_any* this;
    this = cx_declare(cx_any_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_any* cx_anyDeclareChild(cx_object _parent, cx_string _name) {
    cx_any* this;
    this = cx_declareChild(_parent, _name, cx_any_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_anyDefine(cx_any* this, cx_any value) {
    *this = value;
    return cx_define(this);
}

void cx_anyUpdate(cx_any* this, cx_any value) {
    *this = value;
    cx_update(this);
}

void cx_anySet(cx_any* this, cx_any value) {
    *this = value;
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
    cx_array this;
    this = cx_declare(cx_array_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_array cx_arrayCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_array this;
    this = cx_declareChild(_parent, _name, cx_array_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_array cx_arrayDeclare(void) {
    cx_array this;
    this = cx_declare(cx_array_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_array cx_arrayDeclareChild(cx_object _parent, cx_string _name) {
    cx_array this;
    this = cx_declareChild(_parent, _name, cx_array_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_arrayDefine(cx_array this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    return cx_define(this);
}

void cx_arrayUpdate(cx_array this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(this);
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    cx_updateEnd(this);
}

void cx_arraySet(cx_array this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
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

cx_attr* cx_attrCreate(cx_attr value) {
    cx_attr* this;
    this = cx_declare(cx_attr_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_attr* cx_attrCreateChild(cx_object _parent, cx_string _name, cx_attr value) {
    cx_attr* this;
    this = cx_declareChild(_parent, _name, cx_attr_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_attr* cx_attrDeclare(void) {
    cx_attr* this;
    this = cx_declare(cx_attr_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_attr* cx_attrDeclareChild(cx_object _parent, cx_string _name) {
    cx_attr* this;
    this = cx_declareChild(_parent, _name, cx_attr_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_attrDefine(cx_attr* this, cx_attr value) {
    *this = value;
    return cx_define(this);
}

void cx_attrUpdate(cx_attr* this, cx_attr value) {
    *this = value;
    cx_update(this);
}

void cx_attrSet(cx_attr* this, cx_attr value) {
    *this = value;
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
    cx_binary this;
    this = cx_declare(cx_binary_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_binary cx_binaryCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_binary this;
    this = cx_declareChild(_parent, _name, cx_binary_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_binary cx_binaryDeclare(void) {
    cx_binary this;
    this = cx_declare(cx_binary_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_binary cx_binaryDeclareChild(cx_object _parent, cx_string _name) {
    cx_binary this;
    this = cx_declareChild(_parent, _name, cx_binary_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_binaryDefine(cx_binary this, cx_width width) {
    cx_primitive(this)->width = width;
    return cx_define(this);
}

void cx_binaryUpdate(cx_binary this, cx_width width) {
    cx_updateBegin(this);
    cx_primitive(this)->width = width;
    cx_updateEnd(this);
}

void cx_binarySet(cx_binary this, cx_width width) {
    cx_primitive(this)->width = width;
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
    cx_bitmask this;
    this = cx_declare(cx_bitmask_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_bitmask cx_bitmaskCreateChild(cx_object _parent, cx_string _name) {
    cx_bitmask this;
    this = cx_declareChild(_parent, _name, cx_bitmask_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_bitmask cx_bitmaskDeclare(void) {
    cx_bitmask this;
    this = cx_declare(cx_bitmask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_bitmask cx_bitmaskDeclareChild(cx_object _parent, cx_string _name) {
    cx_bitmask this;
    this = cx_declareChild(_parent, _name, cx_bitmask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_bitmaskDefine(cx_bitmask this) {
    return cx_define(this);
}

void cx_bitmaskUpdate(cx_bitmask this) {
    cx_update(this);
}

void cx_bitmaskSet(cx_bitmask this) {
    CX_UNUSED(this);
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

cx_bool* cx_boolCreate(cx_bool value) {
    cx_bool* this;
    this = cx_declare(cx_bool_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_bool* cx_boolCreateChild(cx_object _parent, cx_string _name, cx_bool value) {
    cx_bool* this;
    this = cx_declareChild(_parent, _name, cx_bool_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_bool* cx_boolDeclare(void) {
    cx_bool* this;
    this = cx_declare(cx_bool_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_bool* cx_boolDeclareChild(cx_object _parent, cx_string _name) {
    cx_bool* this;
    this = cx_declareChild(_parent, _name, cx_bool_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_boolDefine(cx_bool* this, cx_bool value) {
    *this = value;
    return cx_define(this);
}

void cx_boolUpdate(cx_bool* this, cx_bool value) {
    *this = value;
    cx_update(this);
}

void cx_boolSet(cx_bool* this, cx_bool value) {
    *this = value;
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
    cx_boolean this;
    this = cx_declare(cx_boolean_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_boolean cx_booleanCreateChild(cx_object _parent, cx_string _name) {
    cx_boolean this;
    this = cx_declareChild(_parent, _name, cx_boolean_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_boolean cx_booleanDeclare(void) {
    cx_boolean this;
    this = cx_declare(cx_boolean_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_boolean cx_booleanDeclareChild(cx_object _parent, cx_string _name) {
    cx_boolean this;
    this = cx_declareChild(_parent, _name, cx_boolean_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_booleanDefine(cx_boolean this) {
    return cx_define(this);
}

void cx_booleanUpdate(cx_boolean this) {
    cx_update(this);
}

void cx_booleanSet(cx_boolean this) {
    CX_UNUSED(this);
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
    cx_callbackDestruct* this;
    this = cx_declare(cx_callbackDestruct_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_callbackDestruct* cx_callbackDestructCreateChild(cx_object _parent, cx_string _name) {
    cx_callbackDestruct* this;
    this = cx_declareChild(_parent, _name, cx_callbackDestruct_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_callbackDestruct* cx_callbackDestructDeclare(void) {
    cx_callbackDestruct* this;
    this = cx_declare(cx_callbackDestruct_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_callbackDestruct* cx_callbackDestructDeclareChild(cx_object _parent, cx_string _name) {
    cx_callbackDestruct* this;
    this = cx_declareChild(_parent, _name, cx_callbackDestruct_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_callbackDestructDefine(cx_callbackDestruct* this) {
    return cx_define(this);
}

void cx_callbackDestructUpdate(cx_callbackDestruct* this) {
    cx_update(this);
}

void cx_callbackDestructSet(cx_callbackDestruct* this) {
    CX_UNUSED(this);
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
    cx_callbackInit* this;
    this = cx_declare(cx_callbackInit_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_callbackInit* cx_callbackInitCreateChild(cx_object _parent, cx_string _name) {
    cx_callbackInit* this;
    this = cx_declareChild(_parent, _name, cx_callbackInit_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_callbackInit* cx_callbackInitDeclare(void) {
    cx_callbackInit* this;
    this = cx_declare(cx_callbackInit_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_callbackInit* cx_callbackInitDeclareChild(cx_object _parent, cx_string _name) {
    cx_callbackInit* this;
    this = cx_declareChild(_parent, _name, cx_callbackInit_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_callbackInitDefine(cx_callbackInit* this) {
    return cx_define(this);
}

void cx_callbackInitUpdate(cx_callbackInit* this) {
    cx_update(this);
}

void cx_callbackInitSet(cx_callbackInit* this) {
    CX_UNUSED(this);
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

cx_char* cx_charCreate(cx_char value) {
    cx_char* this;
    this = cx_declare(cx_char_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_char* cx_charCreateChild(cx_object _parent, cx_string _name, cx_char value) {
    cx_char* this;
    this = cx_declareChild(_parent, _name, cx_char_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_char* cx_charDeclare(void) {
    cx_char* this;
    this = cx_declare(cx_char_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_char* cx_charDeclareChild(cx_object _parent, cx_string _name) {
    cx_char* this;
    this = cx_declareChild(_parent, _name, cx_char_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_charDefine(cx_char* this, cx_char value) {
    *this = value;
    return cx_define(this);
}

void cx_charUpdate(cx_char* this, cx_char value) {
    *this = value;
    cx_update(this);
}

void cx_charSet(cx_char* this, cx_char value) {
    *this = value;
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
    cx_character this;
    this = cx_declare(cx_character_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_character cx_characterCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_character this;
    this = cx_declareChild(_parent, _name, cx_character_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_character cx_characterDeclare(void) {
    cx_character this;
    this = cx_declare(cx_character_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_character cx_characterDeclareChild(cx_object _parent, cx_string _name) {
    cx_character this;
    this = cx_declareChild(_parent, _name, cx_character_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_characterDefine(cx_character this, cx_width width) {
    cx_primitive(this)->width = width;
    return cx_define(this);
}

void cx_characterUpdate(cx_character this, cx_width width) {
    cx_updateBegin(this);
    cx_primitive(this)->width = width;
    cx_updateEnd(this);
}

void cx_characterSet(cx_character this, cx_width width) {
    cx_primitive(this)->width = width;
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

cx_class cx_classCreate(cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_class this;
    this = cx_declare(cx_class_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    this->implements = implements;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_class cx_classCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_class this;
    this = cx_declareChild(_parent, _name, cx_class_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    this->implements = implements;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_class cx_classDeclare(void) {
    cx_class this;
    this = cx_declare(cx_class_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_class cx_classDeclareChild(cx_object _parent, cx_string _name) {
    cx_class this;
    this = cx_declareChild(_parent, _name, cx_class_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_classDefine(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    this->implements = implements;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    return cx_define(this);
}

void cx_classUpdate(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_updateBegin(this);
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    this->implements = implements;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    cx_updateEnd(this);
}

void cx_classSet(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    this->implements = implements;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
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
    cx_collection this;
    this = cx_declare(cx_collection_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_collection cx_collectionCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_collection this;
    this = cx_declareChild(_parent, _name, cx_collection_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_collection cx_collectionDeclare(void) {
    cx_collection this;
    this = cx_declare(cx_collection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_collection cx_collectionDeclareChild(cx_object _parent, cx_string _name) {
    cx_collection this;
    this = cx_declareChild(_parent, _name, cx_collection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_collectionDefine(cx_collection this, cx_type elementType, cx_uint32 max) {
    cx_setref(&this->elementType, cx_type(elementType));
    this->max = max;
    return cx_define(this);
}

void cx_collectionUpdate(cx_collection this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(this);
    cx_setref(&this->elementType, cx_type(elementType));
    this->max = max;
    cx_updateEnd(this);
}

void cx_collectionSet(cx_collection this, cx_type elementType, cx_uint32 max) {
    cx_setref(&this->elementType, cx_type(elementType));
    this->max = max;
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

cx_collectionKind* cx_collectionKindCreate(cx_collectionKind value) {
    cx_collectionKind* this;
    this = cx_declare(cx_collectionKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_collectionKind* cx_collectionKindCreateChild(cx_object _parent, cx_string _name, cx_collectionKind value) {
    cx_collectionKind* this;
    this = cx_declareChild(_parent, _name, cx_collectionKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_collectionKind* cx_collectionKindDeclare(void) {
    cx_collectionKind* this;
    this = cx_declare(cx_collectionKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_collectionKind* cx_collectionKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_collectionKind* this;
    this = cx_declareChild(_parent, _name, cx_collectionKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_collectionKindDefine(cx_collectionKind* this, cx_collectionKind value) {
    *this = value;
    return cx_define(this);
}

void cx_collectionKindUpdate(cx_collectionKind* this, cx_collectionKind value) {
    *this = value;
    cx_update(this);
}

void cx_collectionKindSet(cx_collectionKind* this, cx_collectionKind value) {
    *this = value;
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

cx_compositeKind* cx_compositeKindCreate(cx_compositeKind value) {
    cx_compositeKind* this;
    this = cx_declare(cx_compositeKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_compositeKind* cx_compositeKindCreateChild(cx_object _parent, cx_string _name, cx_compositeKind value) {
    cx_compositeKind* this;
    this = cx_declareChild(_parent, _name, cx_compositeKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_compositeKind* cx_compositeKindDeclare(void) {
    cx_compositeKind* this;
    this = cx_declare(cx_compositeKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_compositeKind* cx_compositeKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_compositeKind* this;
    this = cx_declareChild(_parent, _name, cx_compositeKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_compositeKindDefine(cx_compositeKind* this, cx_compositeKind value) {
    *this = value;
    return cx_define(this);
}

void cx_compositeKindUpdate(cx_compositeKind* this, cx_compositeKind value) {
    *this = value;
    cx_update(this);
}

void cx_compositeKindSet(cx_compositeKind* this, cx_compositeKind value) {
    *this = value;
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

cx_constant* cx_constantCreate(cx_constant value) {
    cx_constant* this;
    this = cx_declare(cx_constant_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_constant* cx_constantCreateChild(cx_object _parent, cx_string _name, cx_constant value) {
    cx_constant* this;
    this = cx_declareChild(_parent, _name, cx_constant_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_constant* cx_constantDeclare(void) {
    cx_constant* this;
    this = cx_declare(cx_constant_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_constant* cx_constantDeclareChild(cx_object _parent, cx_string _name) {
    cx_constant* this;
    this = cx_declareChild(_parent, _name, cx_constant_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_constantDefine(cx_constant* this, cx_constant value) {
    *this = value;
    return cx_define(this);
}

void cx_constantUpdate(cx_constant* this, cx_constant value) {
    *this = value;
    cx_update(this);
}

void cx_constantSet(cx_constant* this, cx_constant value) {
    *this = value;
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

cx_delegate cx_delegateCreate(cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters) {
    cx_delegate this;
    this = cx_declare(cx_delegate_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    this->parameters = parameters;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_delegate cx_delegateCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters) {
    cx_delegate this;
    this = cx_declareChild(_parent, _name, cx_delegate_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    this->parameters = parameters;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_delegate cx_delegateDeclare(void) {
    cx_delegate this;
    this = cx_declare(cx_delegate_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_delegate cx_delegateDeclareChild(cx_object _parent, cx_string _name) {
    cx_delegate this;
    this = cx_declareChild(_parent, _name, cx_delegate_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_delegateDefine(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters) {
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    this->parameters = parameters;
    return cx_define(this);
}

void cx_delegateUpdate(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters) {
    cx_updateBegin(this);
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    this->parameters = parameters;
    cx_updateEnd(this);
}

void cx_delegateSet(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters) {
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    this->parameters = parameters;
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
    cx_delegatedata* this;
    this = cx_declare(cx_delegatedata_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->instance, instance);
    cx_setref(&this->procedure, cx_function(procedure));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_delegatedata* cx_delegatedataCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure) {
    cx_delegatedata* this;
    this = cx_declareChild(_parent, _name, cx_delegatedata_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->instance, instance);
    cx_setref(&this->procedure, cx_function(procedure));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_delegatedata* cx_delegatedataDeclare(void) {
    cx_delegatedata* this;
    this = cx_declare(cx_delegatedata_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_delegatedata* cx_delegatedataDeclareChild(cx_object _parent, cx_string _name) {
    cx_delegatedata* this;
    this = cx_declareChild(_parent, _name, cx_delegatedata_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_delegatedataDefine(cx_delegatedata* this, cx_object instance, cx_function procedure) {
    cx_setref(&this->instance, instance);
    cx_setref(&this->procedure, cx_function(procedure));
    return cx_define(this);
}

void cx_delegatedataUpdate(cx_delegatedata* this, cx_object instance, cx_function procedure) {
    cx_updateBegin(this);
    cx_setref(&this->instance, instance);
    cx_setref(&this->procedure, cx_function(procedure));
    cx_updateEnd(this);
}

void cx_delegatedataSet(cx_delegatedata* this, cx_object instance, cx_function procedure) {
    cx_setref(&this->instance, instance);
    cx_setref(&this->procedure, cx_function(procedure));
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
    cx_dispatcher this;
    this = cx_declare(cx_dispatcher_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_dispatcher cx_dispatcherCreateChild(cx_object _parent, cx_string _name) {
    cx_dispatcher this;
    this = cx_declareChild(_parent, _name, cx_dispatcher_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_dispatcher cx_dispatcherDeclare(void) {
    cx_dispatcher this;
    this = cx_declare(cx_dispatcher_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_dispatcher cx_dispatcherDeclareChild(cx_object _parent, cx_string _name) {
    cx_dispatcher this;
    this = cx_declareChild(_parent, _name, cx_dispatcher_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_dispatcherDefine(cx_dispatcher this) {
    return cx_define(this);
}

void cx_dispatcherUpdate(cx_dispatcher this) {
    cx_update(this);
}

void cx_dispatcherSet(cx_dispatcher this) {
    CX_UNUSED(this);
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
    cx_enum this;
    this = cx_declare(cx_enum_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_enum cx_enumCreateChild(cx_object _parent, cx_string _name) {
    cx_enum this;
    this = cx_declareChild(_parent, _name, cx_enum_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_enum cx_enumDeclare(void) {
    cx_enum this;
    this = cx_declare(cx_enum_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_enum cx_enumDeclareChild(cx_object _parent, cx_string _name) {
    cx_enum this;
    this = cx_declareChild(_parent, _name, cx_enum_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_enumDefine(cx_enum this) {
    return cx_define(this);
}

void cx_enumUpdate(cx_enum this) {
    cx_update(this);
}

void cx_enumSet(cx_enum this) {
    CX_UNUSED(this);
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

cx_equalityKind* cx_equalityKindCreate(cx_equalityKind value) {
    cx_equalityKind* this;
    this = cx_declare(cx_equalityKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_equalityKind* cx_equalityKindCreateChild(cx_object _parent, cx_string _name, cx_equalityKind value) {
    cx_equalityKind* this;
    this = cx_declareChild(_parent, _name, cx_equalityKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_equalityKind* cx_equalityKindDeclare(void) {
    cx_equalityKind* this;
    this = cx_declare(cx_equalityKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_equalityKind* cx_equalityKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_equalityKind* this;
    this = cx_declareChild(_parent, _name, cx_equalityKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_equalityKindDefine(cx_equalityKind* this, cx_equalityKind value) {
    *this = value;
    return cx_define(this);
}

void cx_equalityKindUpdate(cx_equalityKind* this, cx_equalityKind value) {
    *this = value;
    cx_update(this);
}

void cx_equalityKindSet(cx_equalityKind* this, cx_equalityKind value) {
    *this = value;
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
    cx_event this;
    this = cx_declare(cx_event_o);
    if (!this) {
        return NULL;
    }
    this->kind = kind;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_event cx_eventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind) {
    cx_event this;
    this = cx_declareChild(_parent, _name, cx_event_o);
    if (!this) {
        return NULL;
    }
    this->kind = kind;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_event cx_eventDeclare(void) {
    cx_event this;
    this = cx_declare(cx_event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_event cx_eventDeclareChild(cx_object _parent, cx_string _name) {
    cx_event this;
    this = cx_declareChild(_parent, _name, cx_event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_eventDefine(cx_event this, cx_uint16 kind) {
    this->kind = kind;
    return cx_define(this);
}

void cx_eventUpdate(cx_event this, cx_uint16 kind) {
    cx_updateBegin(this);
    this->kind = kind;
    cx_updateEnd(this);
}

void cx_eventSet(cx_event this, cx_uint16 kind) {
    this->kind = kind;
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

cx_eventMask* cx_eventMaskCreate(cx_eventMask value) {
    cx_eventMask* this;
    this = cx_declare(cx_eventMask_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_eventMask* cx_eventMaskCreateChild(cx_object _parent, cx_string _name, cx_eventMask value) {
    cx_eventMask* this;
    this = cx_declareChild(_parent, _name, cx_eventMask_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_eventMask* cx_eventMaskDeclare(void) {
    cx_eventMask* this;
    this = cx_declare(cx_eventMask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_eventMask* cx_eventMaskDeclareChild(cx_object _parent, cx_string _name) {
    cx_eventMask* this;
    this = cx_declareChild(_parent, _name, cx_eventMask_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_eventMaskDefine(cx_eventMask* this, cx_eventMask value) {
    *this = value;
    return cx_define(this);
}

void cx_eventMaskUpdate(cx_eventMask* this, cx_eventMask value) {
    *this = value;
    cx_update(this);
}

void cx_eventMaskSet(cx_eventMask* this, cx_eventMask value) {
    *this = value;
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
    cx_float this;
    this = cx_declare(cx_float_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float cx_floatCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_float64 min, cx_float64 max) {
    cx_float this;
    this = cx_declareChild(_parent, _name, cx_float_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float cx_floatDeclare(void) {
    cx_float this;
    this = cx_declare(cx_float_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_float cx_floatDeclareChild(cx_object _parent, cx_string _name) {
    cx_float this;
    this = cx_declareChild(_parent, _name, cx_float_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_floatDefine(cx_float this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    return cx_define(this);
}

void cx_floatUpdate(cx_float this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_updateBegin(this);
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    cx_updateEnd(this);
}

void cx_floatSet(cx_float this, cx_width width, cx_float64 min, cx_float64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
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

cx_float32* cx_float32Create(cx_float32 value) {
    cx_float32* this;
    this = cx_declare(cx_float32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float32* cx_float32CreateChild(cx_object _parent, cx_string _name, cx_float32 value) {
    cx_float32* this;
    this = cx_declareChild(_parent, _name, cx_float32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float32* cx_float32Declare(void) {
    cx_float32* this;
    this = cx_declare(cx_float32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_float32* cx_float32DeclareChild(cx_object _parent, cx_string _name) {
    cx_float32* this;
    this = cx_declareChild(_parent, _name, cx_float32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_float32Define(cx_float32* this, cx_float32 value) {
    *this = value;
    return cx_define(this);
}

void cx_float32Update(cx_float32* this, cx_float32 value) {
    *this = value;
    cx_update(this);
}

void cx_float32Set(cx_float32* this, cx_float32 value) {
    *this = value;
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

cx_float64* cx_float64Create(cx_float64 value) {
    cx_float64* this;
    this = cx_declare(cx_float64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float64* cx_float64CreateChild(cx_object _parent, cx_string _name, cx_float64 value) {
    cx_float64* this;
    this = cx_declareChild(_parent, _name, cx_float64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_float64* cx_float64Declare(void) {
    cx_float64* this;
    this = cx_declare(cx_float64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_float64* cx_float64DeclareChild(cx_object _parent, cx_string _name) {
    cx_float64* this;
    this = cx_declareChild(_parent, _name, cx_float64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_float64Define(cx_float64* this, cx_float64 value) {
    *this = value;
    return cx_define(this);
}

void cx_float64Update(cx_float64* this, cx_float64 value) {
    *this = value;
    cx_update(this);
}

void cx_float64Set(cx_float64* this, cx_float64 value) {
    *this = value;
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

cx_function cx_functionCreate(cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_function this;
    this = cx_declare(cx_function_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_function cx_functionCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_function this;
    this = cx_declareChild(_parent, _name, cx_function_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_function cx_functionDeclare(void) {
    cx_function this;
    this = cx_declare(cx_function_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_function cx_functionDeclareChild(cx_object _parent, cx_string _name) {
    cx_function this;
    this = cx_declareChild(_parent, _name, cx_function_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_functionDefine(cx_function this, cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    cx_function(this)->impl = (cx_word)_impl;
    return cx_define(this);
}

void cx_functionUpdate(cx_function this, cx_type returnType, cx_bool returnsReference) {
    cx_updateBegin(this);
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
    cx_updateEnd(this);
}

void cx_functionSet(cx_function this, cx_type returnType, cx_bool returnsReference) {
    cx_setref(&this->returnType, cx_type(returnType));
    this->returnsReference = returnsReference;
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
    cx_int this;
    this = cx_declare(cx_int_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int cx_intCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max) {
    cx_int this;
    this = cx_declareChild(_parent, _name, cx_int_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int cx_intDeclare(void) {
    cx_int this;
    this = cx_declare(cx_int_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int cx_intDeclareChild(cx_object _parent, cx_string _name) {
    cx_int this;
    this = cx_declareChild(_parent, _name, cx_int_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_intDefine(cx_int this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    return cx_define(this);
}

void cx_intUpdate(cx_int this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_updateBegin(this);
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    cx_updateEnd(this);
}

void cx_intSet(cx_int this, cx_width width, cx_int64 min, cx_int64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
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

cx_int16* cx_int16Create(cx_int16 value) {
    cx_int16* this;
    this = cx_declare(cx_int16_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int16* cx_int16CreateChild(cx_object _parent, cx_string _name, cx_int16 value) {
    cx_int16* this;
    this = cx_declareChild(_parent, _name, cx_int16_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int16* cx_int16Declare(void) {
    cx_int16* this;
    this = cx_declare(cx_int16_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16* cx_int16DeclareChild(cx_object _parent, cx_string _name) {
    cx_int16* this;
    this = cx_declareChild(_parent, _name, cx_int16_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_int16Define(cx_int16* this, cx_int16 value) {
    *this = value;
    return cx_define(this);
}

void cx_int16Update(cx_int16* this, cx_int16 value) {
    *this = value;
    cx_update(this);
}

void cx_int16Set(cx_int16* this, cx_int16 value) {
    *this = value;
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

cx_int32* cx_int32Create(cx_int32 value) {
    cx_int32* this;
    this = cx_declare(cx_int32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int32* cx_int32CreateChild(cx_object _parent, cx_string _name, cx_int32 value) {
    cx_int32* this;
    this = cx_declareChild(_parent, _name, cx_int32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int32* cx_int32Declare(void) {
    cx_int32* this;
    this = cx_declare(cx_int32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int32* cx_int32DeclareChild(cx_object _parent, cx_string _name) {
    cx_int32* this;
    this = cx_declareChild(_parent, _name, cx_int32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_int32Define(cx_int32* this, cx_int32 value) {
    *this = value;
    return cx_define(this);
}

void cx_int32Update(cx_int32* this, cx_int32 value) {
    *this = value;
    cx_update(this);
}

void cx_int32Set(cx_int32* this, cx_int32 value) {
    *this = value;
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

cx_int64* cx_int64Create(cx_int64 value) {
    cx_int64* this;
    this = cx_declare(cx_int64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int64* cx_int64CreateChild(cx_object _parent, cx_string _name, cx_int64 value) {
    cx_int64* this;
    this = cx_declareChild(_parent, _name, cx_int64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int64* cx_int64Declare(void) {
    cx_int64* this;
    this = cx_declare(cx_int64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int64* cx_int64DeclareChild(cx_object _parent, cx_string _name) {
    cx_int64* this;
    this = cx_declareChild(_parent, _name, cx_int64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_int64Define(cx_int64* this, cx_int64 value) {
    *this = value;
    return cx_define(this);
}

void cx_int64Update(cx_int64* this, cx_int64 value) {
    *this = value;
    cx_update(this);
}

void cx_int64Set(cx_int64* this, cx_int64 value) {
    *this = value;
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

cx_int8* cx_int8Create(cx_int8 value) {
    cx_int8* this;
    this = cx_declare(cx_int8_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int8* cx_int8CreateChild(cx_object _parent, cx_string _name, cx_int8 value) {
    cx_int8* this;
    this = cx_declareChild(_parent, _name, cx_int8_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_int8* cx_int8Declare(void) {
    cx_int8* this;
    this = cx_declare(cx_int8_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int8* cx_int8DeclareChild(cx_object _parent, cx_string _name) {
    cx_int8* this;
    this = cx_declareChild(_parent, _name, cx_int8_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_int8Define(cx_int8* this, cx_int8 value) {
    *this = value;
    return cx_define(this);
}

void cx_int8Update(cx_int8* this, cx_int8 value) {
    *this = value;
    cx_update(this);
}

void cx_int8Set(cx_int8* this, cx_int8 value) {
    *this = value;
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

cx_interface cx_interfaceCreate(cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_interface this;
    this = cx_declare(cx_interface_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->base, cx_interface(base));
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interface cx_interfaceCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_interface this;
    this = cx_declareChild(_parent, _name, cx_interface_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->base, cx_interface(base));
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interface cx_interfaceDeclare(void) {
    cx_interface this;
    this = cx_declare(cx_interface_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_interface cx_interfaceDeclareChild(cx_object _parent, cx_string _name) {
    cx_interface this;
    this = cx_declareChild(_parent, _name, cx_interface_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_interfaceDefine(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&this->base, cx_interface(base));
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    return cx_define(this);
}

void cx_interfaceUpdate(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_updateBegin(this);
    cx_setref(&this->base, cx_interface(base));
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    cx_updateEnd(this);
}

void cx_interfaceSet(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&this->base, cx_interface(base));
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
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

cx_interfaceseq* cx_interfaceseqCreate(void) {
    cx_interfaceseq* this;
    this = cx_declare(cx_interfaceseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceseq* cx_interfaceseqCreateChild(cx_object _parent, cx_string _name) {
    cx_interfaceseq* this;
    this = cx_declareChild(_parent, _name, cx_interfaceseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceseq* cx_interfaceseqDeclare(void) {
    cx_interfaceseq* this;
    this = cx_declare(cx_interfaceseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_interfaceseq* cx_interfaceseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceseq* this;
    this = cx_declareChild(_parent, _name, cx_interfaceseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_interfaceseqDefine(cx_interfaceseq* this, cx_interfaceseq value) {
    cx_copyp(this, cx_interfaceseq_o, &value);
    return cx_define(this);
}

void cx_interfaceseqUpdate(cx_interfaceseq* this, cx_interfaceseq value) {
    cx_copyp(this, cx_interfaceseq_o, &value);
    cx_update(this);
}

void cx_interfaceseqSet(cx_interfaceseq* this, cx_interfaceseq value) {
    cx_copyp(this, cx_interfaceseq_o, &value);
}

cx_string cx_interfaceseqStr(cx_interfaceseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_interfaceseq* cx_interfaceseqFromStr(cx_interfaceseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interfaceseq_o), str);
    return value;
}

cx_int16 cx_interfaceseqCopy(cx_interfaceseq* *dst, cx_interfaceseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_interfaceseqCompare(cx_interfaceseq* dst, cx_interfaceseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_interfaceseqInit(cx_interfaceseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_interfaceseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_interfaceseqDeinit(cx_interfaceseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_interfaceVector* cx_interfaceVectorCreate(cx_interface interface, cx_vtable vector) {
    cx_interfaceVector* this;
    this = cx_declare(cx_interfaceVector_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->interface, cx_interface(interface));
    this->vector = vector;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceVector* cx_interfaceVectorCreateChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector) {
    cx_interfaceVector* this;
    this = cx_declareChild(_parent, _name, cx_interfaceVector_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->interface, cx_interface(interface));
    this->vector = vector;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceVector* cx_interfaceVectorDeclare(void) {
    cx_interfaceVector* this;
    this = cx_declare(cx_interfaceVector_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_interfaceVector* cx_interfaceVectorDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceVector* this;
    this = cx_declareChild(_parent, _name, cx_interfaceVector_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_interfaceVectorDefine(cx_interfaceVector* this, cx_interface interface, cx_vtable vector) {
    cx_setref(&this->interface, cx_interface(interface));
    this->vector = vector;
    return cx_define(this);
}

void cx_interfaceVectorUpdate(cx_interfaceVector* this, cx_interface interface, cx_vtable vector) {
    cx_updateBegin(this);
    cx_setref(&this->interface, cx_interface(interface));
    this->vector = vector;
    cx_updateEnd(this);
}

void cx_interfaceVectorSet(cx_interfaceVector* this, cx_interface interface, cx_vtable vector) {
    cx_setref(&this->interface, cx_interface(interface));
    this->vector = vector;
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

cx_interfaceVectorseq* cx_interfaceVectorseqCreate(void) {
    cx_interfaceVectorseq* this;
    this = cx_declare(cx_interfaceVectorseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceVectorseq* cx_interfaceVectorseqCreateChild(cx_object _parent, cx_string _name) {
    cx_interfaceVectorseq* this;
    this = cx_declareChild(_parent, _name, cx_interfaceVectorseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_interfaceVectorseq* cx_interfaceVectorseqDeclare(void) {
    cx_interfaceVectorseq* this;
    this = cx_declare(cx_interfaceVectorseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_interfaceVectorseq* cx_interfaceVectorseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_interfaceVectorseq* this;
    this = cx_declareChild(_parent, _name, cx_interfaceVectorseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_interfaceVectorseqDefine(cx_interfaceVectorseq* this, cx_interfaceVectorseq value) {
    cx_copyp(this, cx_interfaceVectorseq_o, &value);
    return cx_define(this);
}

void cx_interfaceVectorseqUpdate(cx_interfaceVectorseq* this, cx_interfaceVectorseq value) {
    cx_copyp(this, cx_interfaceVectorseq_o, &value);
    cx_update(this);
}

void cx_interfaceVectorseqSet(cx_interfaceVectorseq* this, cx_interfaceVectorseq value) {
    cx_copyp(this, cx_interfaceVectorseq_o, &value);
}

cx_string cx_interfaceVectorseqStr(cx_interfaceVectorseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_interfaceVectorseq* cx_interfaceVectorseqFromStr(cx_interfaceVectorseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_interfaceVectorseq_o), str);
    return value;
}

cx_int16 cx_interfaceVectorseqCopy(cx_interfaceVectorseq* *dst, cx_interfaceVectorseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVectorseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVectorseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_interfaceVectorseqCompare(cx_interfaceVectorseq* dst, cx_interfaceVectorseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_interfaceVectorseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_interfaceVectorseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_interfaceVectorseqInit(cx_interfaceVectorseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_interfaceVectorseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_interfaceVectorseqDeinit(cx_interfaceVectorseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_interfaceVectorseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_iterator cx_iteratorCreate(cx_type elementType) {
    cx_iterator this;
    this = cx_declare(cx_iterator_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_iterator cx_iteratorCreateChild(cx_object _parent, cx_string _name, cx_type elementType) {
    cx_iterator this;
    this = cx_declareChild(_parent, _name, cx_iterator_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_iterator cx_iteratorDeclare(void) {
    cx_iterator this;
    this = cx_declare(cx_iterator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_iterator cx_iteratorDeclareChild(cx_object _parent, cx_string _name) {
    cx_iterator this;
    this = cx_declareChild(_parent, _name, cx_iterator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_iteratorDefine(cx_iterator this, cx_type elementType) {
    cx_setref(&this->elementType, cx_type(elementType));
    return cx_define(this);
}

void cx_iteratorUpdate(cx_iterator this, cx_type elementType) {
    cx_updateBegin(this);
    cx_setref(&this->elementType, cx_type(elementType));
    cx_updateEnd(this);
}

void cx_iteratorSet(cx_iterator this, cx_type elementType) {
    cx_setref(&this->elementType, cx_type(elementType));
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
    cx_list this;
    this = cx_declare(cx_list_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_list cx_listCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_list this;
    this = cx_declareChild(_parent, _name, cx_list_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_list cx_listDeclare(void) {
    cx_list this;
    this = cx_declare(cx_list_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_list cx_listDeclareChild(cx_object _parent, cx_string _name) {
    cx_list this;
    this = cx_declareChild(_parent, _name, cx_list_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_listDefine(cx_list this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    return cx_define(this);
}

void cx_listUpdate(cx_list this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(this);
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    cx_updateEnd(this);
}

void cx_listSet(cx_list this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
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
    cx_map this;
    this = cx_declare(cx_map_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    cx_setref(&this->keyType, cx_type(keyType));
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_map cx_mapCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_map this;
    this = cx_declareChild(_parent, _name, cx_map_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->elementType, cx_type(elementType));
    cx_setref(&this->keyType, cx_type(keyType));
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_map cx_mapDeclare(void) {
    cx_map this;
    this = cx_declare(cx_map_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_map cx_mapDeclareChild(cx_object _parent, cx_string _name) {
    cx_map this;
    this = cx_declareChild(_parent, _name, cx_map_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_mapDefine(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_setref(&this->elementType, cx_type(elementType));
    cx_setref(&this->keyType, cx_type(keyType));
    this->max = max;
    return cx_define(this);
}

void cx_mapUpdate(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_updateBegin(this);
    cx_setref(&this->elementType, cx_type(elementType));
    cx_setref(&this->keyType, cx_type(keyType));
    this->max = max;
    cx_updateEnd(this);
}

void cx_mapSet(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max) {
    cx_setref(&this->elementType, cx_type(elementType));
    cx_setref(&this->keyType, cx_type(keyType));
    this->max = max;
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
    cx_member this;
    this = cx_declare(cx_member_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->type, cx_type(type));
    this->modifiers = modifiers;
    this->state = state;
    this->weak = weak;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_member cx_memberCreateChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_member this;
    this = cx_declareChild(_parent, _name, cx_member_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->type, cx_type(type));
    this->modifiers = modifiers;
    this->state = state;
    this->weak = weak;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_member cx_memberDeclare(void) {
    cx_member this;
    this = cx_declare(cx_member_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_member cx_memberDeclareChild(cx_object _parent, cx_string _name) {
    cx_member this;
    this = cx_declareChild(_parent, _name, cx_member_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_memberDefine(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_setref(&this->type, cx_type(type));
    this->modifiers = modifiers;
    this->state = state;
    this->weak = weak;
    return cx_define(this);
}

void cx_memberUpdate(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_updateBegin(this);
    cx_setref(&this->type, cx_type(type));
    this->modifiers = modifiers;
    this->state = state;
    this->weak = weak;
    cx_updateEnd(this);
}

void cx_memberSet(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak) {
    cx_setref(&this->type, cx_type(type));
    this->modifiers = modifiers;
    this->state = state;
    this->weak = weak;
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

cx_memberseq* cx_memberseqCreate(void) {
    cx_memberseq* this;
    this = cx_declare(cx_memberseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_memberseq* cx_memberseqCreateChild(cx_object _parent, cx_string _name) {
    cx_memberseq* this;
    this = cx_declareChild(_parent, _name, cx_memberseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_memberseq* cx_memberseqDeclare(void) {
    cx_memberseq* this;
    this = cx_declare(cx_memberseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_memberseq* cx_memberseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_memberseq* this;
    this = cx_declareChild(_parent, _name, cx_memberseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_memberseqDefine(cx_memberseq* this, cx_memberseq value) {
    cx_copyp(this, cx_memberseq_o, &value);
    return cx_define(this);
}

void cx_memberseqUpdate(cx_memberseq* this, cx_memberseq value) {
    cx_copyp(this, cx_memberseq_o, &value);
    cx_update(this);
}

void cx_memberseqSet(cx_memberseq* this, cx_memberseq value) {
    cx_copyp(this, cx_memberseq_o, &value);
}

cx_string cx_memberseqStr(cx_memberseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_memberseq* cx_memberseqFromStr(cx_memberseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_memberseq_o), str);
    return value;
}

cx_int16 cx_memberseqCopy(cx_memberseq* *dst, cx_memberseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_memberseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_memberseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_memberseqCompare(cx_memberseq* dst, cx_memberseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_memberseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_memberseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_memberseqInit(cx_memberseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_memberseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_memberseqDeinit(cx_memberseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_memberseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_metaprocedure cx_metaprocedureCreate(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_metaprocedure this;
    this = cx_declare(cx_metaprocedure_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->referenceOnly = referenceOnly;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_metaprocedure cx_metaprocedureCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_metaprocedure this;
    this = cx_declareChild(_parent, _name, cx_metaprocedure_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->referenceOnly = referenceOnly;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_metaprocedure cx_metaprocedureDeclare(void) {
    cx_metaprocedure this;
    this = cx_declare(cx_metaprocedure_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_metaprocedure cx_metaprocedureDeclareChild(cx_object _parent, cx_string _name) {
    cx_metaprocedure this;
    this = cx_declareChild(_parent, _name, cx_metaprocedure_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_metaprocedureDefine(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->referenceOnly = referenceOnly;
    cx_function(this)->impl = (cx_word)_impl;
    return cx_define(this);
}

void cx_metaprocedureUpdate(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_updateBegin(this);
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->referenceOnly = referenceOnly;
    cx_updateEnd(this);
}

void cx_metaprocedureSet(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->referenceOnly = referenceOnly;
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

cx_method cx_methodCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_method this;
    this = cx_declare(cx_method_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_method cx_methodCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_method this;
    this = cx_declareChild(_parent, _name, cx_method_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_method cx_methodDeclare(void) {
    cx_method this;
    this = cx_declare(cx_method_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_method cx_methodDeclareChild(cx_object _parent, cx_string _name) {
    cx_method this;
    this = cx_declareChild(_parent, _name, cx_method_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_methodDefine(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    return cx_define(this);
}

void cx_methodUpdate(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_updateBegin(this);
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->virtual = virtual;
    cx_updateEnd(this);
}

void cx_methodSet(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    this->virtual = virtual;
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

cx_modifier* cx_modifierCreate(cx_modifier value) {
    cx_modifier* this;
    this = cx_declare(cx_modifier_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_modifier* cx_modifierCreateChild(cx_object _parent, cx_string _name, cx_modifier value) {
    cx_modifier* this;
    this = cx_declareChild(_parent, _name, cx_modifier_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_modifier* cx_modifierDeclare(void) {
    cx_modifier* this;
    this = cx_declare(cx_modifier_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_modifier* cx_modifierDeclareChild(cx_object _parent, cx_string _name) {
    cx_modifier* this;
    this = cx_declareChild(_parent, _name, cx_modifier_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_modifierDefine(cx_modifier* this, cx_modifier value) {
    *this = value;
    return cx_define(this);
}

void cx_modifierUpdate(cx_modifier* this, cx_modifier value) {
    *this = value;
    cx_update(this);
}

void cx_modifierSet(cx_modifier* this, cx_modifier value) {
    *this = value;
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
    cx_object this;
    this = cx_declare(cx_object_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_object cx_objectCreateChild(cx_object _parent, cx_string _name) {
    cx_object this;
    this = cx_declareChild(_parent, _name, cx_object_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_objectseq* cx_objectseqCreate(void) {
    cx_objectseq* this;
    this = cx_declare(cx_objectseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_objectseq* cx_objectseqCreateChild(cx_object _parent, cx_string _name) {
    cx_objectseq* this;
    this = cx_declareChild(_parent, _name, cx_objectseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_objectseq* cx_objectseqDeclare(void) {
    cx_objectseq* this;
    this = cx_declare(cx_objectseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_objectseq* cx_objectseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_objectseq* this;
    this = cx_declareChild(_parent, _name, cx_objectseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_objectseqDefine(cx_objectseq* this, cx_objectseq value) {
    cx_copyp(this, cx_objectseq_o, &value);
    return cx_define(this);
}

void cx_objectseqUpdate(cx_objectseq* this, cx_objectseq value) {
    cx_copyp(this, cx_objectseq_o, &value);
    cx_update(this);
}

void cx_objectseqSet(cx_objectseq* this, cx_objectseq value) {
    cx_copyp(this, cx_objectseq_o, &value);
}

cx_string cx_objectseqStr(cx_objectseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_objectseq* cx_objectseqFromStr(cx_objectseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_objectseq_o), str);
    return value;
}

cx_int16 cx_objectseqCopy(cx_objectseq* *dst, cx_objectseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_objectseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_objectseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_objectseqCompare(cx_objectseq* dst, cx_objectseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_objectseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_objectseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_objectseqInit(cx_objectseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_objectseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_objectseqDeinit(cx_objectseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_objectseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_observableEvent cx_observableEventCreate(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_observableEvent this;
    this = cx_declare(cx_observableEvent_o);
    if (!this) {
        return NULL;
    }
    cx_event(this)->kind = kind;
    cx_setref(&this->observer, cx_observer(observer));
    cx_setref(&this->me, me);
    cx_setref(&this->source, source);
    cx_setref(&this->observable, observable);
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observableEvent cx_observableEventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_observableEvent this;
    this = cx_declareChild(_parent, _name, cx_observableEvent_o);
    if (!this) {
        return NULL;
    }
    cx_event(this)->kind = kind;
    cx_setref(&this->observer, cx_observer(observer));
    cx_setref(&this->me, me);
    cx_setref(&this->source, source);
    cx_setref(&this->observable, observable);
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observableEvent cx_observableEventDeclare(void) {
    cx_observableEvent this;
    this = cx_declare(cx_observableEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_observableEvent cx_observableEventDeclareChild(cx_object _parent, cx_string _name) {
    cx_observableEvent this;
    this = cx_declareChild(_parent, _name, cx_observableEvent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_observableEventDefine(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_event(this)->kind = kind;
    cx_setref(&this->observer, cx_observer(observer));
    cx_setref(&this->me, me);
    cx_setref(&this->source, source);
    cx_setref(&this->observable, observable);
    return cx_define(this);
}

void cx_observableEventUpdate(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_updateBegin(this);
    cx_event(this)->kind = kind;
    cx_setref(&this->observer, cx_observer(observer));
    cx_setref(&this->me, me);
    cx_setref(&this->source, source);
    cx_setref(&this->observable, observable);
    cx_updateEnd(this);
}

void cx_observableEventSet(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable) {
    cx_event(this)->kind = kind;
    cx_setref(&this->observer, cx_observer(observer));
    cx_setref(&this->me, me);
    cx_setref(&this->source, source);
    cx_setref(&this->observable, observable);
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

cx_observer cx_observerCreate(cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_observer this;
    this = cx_declare(cx_observer_o);
    if (!this) {
        return NULL;
    }
    this->mask = mask;
    cx_setref(&this->observable, observable);
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observer cx_observerCreateChild(cx_object _parent, cx_string _name, cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_observer this;
    this = cx_declareChild(_parent, _name, cx_observer_o);
    if (!this) {
        return NULL;
    }
    this->mask = mask;
    cx_setref(&this->observable, observable);
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observer cx_observerDeclare(void) {
    cx_observer this;
    this = cx_declare(cx_observer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_observer cx_observerDeclareChild(cx_object _parent, cx_string _name) {
    cx_observer this;
    this = cx_declareChild(_parent, _name, cx_observer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_observerDefine(cx_observer this, cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args)) {
    this->mask = mask;
    cx_setref(&this->observable, observable);
    cx_function(this)->impl = (cx_word)_impl;
    return cx_define(this);
}

void cx_observerUpdate(cx_observer this, cx_eventMask mask, cx_object observable) {
    cx_updateBegin(this);
    this->mask = mask;
    cx_setref(&this->observable, observable);
    cx_updateEnd(this);
}

void cx_observerSet(cx_observer this, cx_eventMask mask, cx_object observable) {
    this->mask = mask;
    cx_setref(&this->observable, observable);
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

cx_observerseq* cx_observerseqCreate(void) {
    cx_observerseq* this;
    this = cx_declare(cx_observerseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observerseq* cx_observerseqCreateChild(cx_object _parent, cx_string _name) {
    cx_observerseq* this;
    this = cx_declareChild(_parent, _name, cx_observerseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_observerseq* cx_observerseqDeclare(void) {
    cx_observerseq* this;
    this = cx_declare(cx_observerseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_observerseq* cx_observerseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_observerseq* this;
    this = cx_declareChild(_parent, _name, cx_observerseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_observerseqDefine(cx_observerseq* this, cx_observerseq value) {
    cx_copyp(this, cx_observerseq_o, &value);
    return cx_define(this);
}

void cx_observerseqUpdate(cx_observerseq* this, cx_observerseq value) {
    cx_copyp(this, cx_observerseq_o, &value);
    cx_update(this);
}

void cx_observerseqSet(cx_observerseq* this, cx_observerseq value) {
    cx_copyp(this, cx_observerseq_o, &value);
}

cx_string cx_observerseqStr(cx_observerseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_observerseq* cx_observerseqFromStr(cx_observerseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_observerseq_o), str);
    return value;
}

cx_int16 cx_observerseqCopy(cx_observerseq* *dst, cx_observerseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_observerseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_observerseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_observerseqCompare(cx_observerseq* dst, cx_observerseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_observerseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_observerseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_observerseqInit(cx_observerseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_observerseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_observerseqDeinit(cx_observerseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_observerseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_octet* cx_octetCreate(cx_octet value) {
    cx_octet* this;
    this = cx_declare(cx_octet_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_octet* cx_octetCreateChild(cx_object _parent, cx_string _name, cx_octet value) {
    cx_octet* this;
    this = cx_declareChild(_parent, _name, cx_octet_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_octet* cx_octetDeclare(void) {
    cx_octet* this;
    this = cx_declare(cx_octet_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_octet* cx_octetDeclareChild(cx_object _parent, cx_string _name) {
    cx_octet* this;
    this = cx_declareChild(_parent, _name, cx_octet_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_octetDefine(cx_octet* this, cx_octet value) {
    *this = value;
    return cx_define(this);
}

void cx_octetUpdate(cx_octet* this, cx_octet value) {
    *this = value;
    cx_update(this);
}

void cx_octetSet(cx_octet* this, cx_octet value) {
    *this = value;
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

cx_operatorKind* cx_operatorKindCreate(cx_operatorKind value) {
    cx_operatorKind* this;
    this = cx_declare(cx_operatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_operatorKind* cx_operatorKindCreateChild(cx_object _parent, cx_string _name, cx_operatorKind value) {
    cx_operatorKind* this;
    this = cx_declareChild(_parent, _name, cx_operatorKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_operatorKind* cx_operatorKindDeclare(void) {
    cx_operatorKind* this;
    this = cx_declare(cx_operatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_operatorKind* cx_operatorKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_operatorKind* this;
    this = cx_declareChild(_parent, _name, cx_operatorKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_operatorKindDefine(cx_operatorKind* this, cx_operatorKind value) {
    *this = value;
    return cx_define(this);
}

void cx_operatorKindUpdate(cx_operatorKind* this, cx_operatorKind value) {
    *this = value;
    cx_update(this);
}

void cx_operatorKindSet(cx_operatorKind* this, cx_operatorKind value) {
    *this = value;
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
    cx_package this;
    this = cx_declare(cx_package_o);
    if (!this) {
        return NULL;
    }
    cx_setstr(&this->url, url);
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_package cx_packageCreateChild(cx_object _parent, cx_string _name, cx_string url) {
    cx_package this;
    this = cx_declareChild(_parent, _name, cx_package_o);
    if (!this) {
        return NULL;
    }
    cx_setstr(&this->url, url);
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_package cx_packageDeclare(void) {
    cx_package this;
    this = cx_declare(cx_package_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_package cx_packageDeclareChild(cx_object _parent, cx_string _name) {
    cx_package this;
    this = cx_declareChild(_parent, _name, cx_package_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_packageDefine(cx_package this, cx_string url) {
    cx_setstr(&this->url, url);
    return cx_define(this);
}

void cx_packageUpdate(cx_package this, cx_string url) {
    cx_updateBegin(this);
    cx_setstr(&this->url, url);
    cx_updateEnd(this);
}

void cx_packageSet(cx_package this, cx_string url) {
    cx_setstr(&this->url, url);
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
    cx_parameter* this;
    this = cx_declare(cx_parameter_o);
    if (!this) {
        return NULL;
    }
    cx_setstr(&this->name, name);
    cx_setref(&this->type, cx_type(type));
    this->passByReference = passByReference;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_parameter* cx_parameterCreateChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference) {
    cx_parameter* this;
    this = cx_declareChild(_parent, _name, cx_parameter_o);
    if (!this) {
        return NULL;
    }
    cx_setstr(&this->name, name);
    cx_setref(&this->type, cx_type(type));
    this->passByReference = passByReference;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_parameter* cx_parameterDeclare(void) {
    cx_parameter* this;
    this = cx_declare(cx_parameter_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_parameter* cx_parameterDeclareChild(cx_object _parent, cx_string _name) {
    cx_parameter* this;
    this = cx_declareChild(_parent, _name, cx_parameter_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_parameterDefine(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_setstr(&this->name, name);
    cx_setref(&this->type, cx_type(type));
    this->passByReference = passByReference;
    return cx_define(this);
}

void cx_parameterUpdate(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_updateBegin(this);
    cx_setstr(&this->name, name);
    cx_setref(&this->type, cx_type(type));
    this->passByReference = passByReference;
    cx_updateEnd(this);
}

void cx_parameterSet(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference) {
    cx_setstr(&this->name, name);
    cx_setref(&this->type, cx_type(type));
    this->passByReference = passByReference;
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

cx_parameterseq* cx_parameterseqCreate(void) {
    cx_parameterseq* this;
    this = cx_declare(cx_parameterseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_parameterseq* cx_parameterseqCreateChild(cx_object _parent, cx_string _name) {
    cx_parameterseq* this;
    this = cx_declareChild(_parent, _name, cx_parameterseq_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_parameterseq* cx_parameterseqDeclare(void) {
    cx_parameterseq* this;
    this = cx_declare(cx_parameterseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_parameterseq* cx_parameterseqDeclareChild(cx_object _parent, cx_string _name) {
    cx_parameterseq* this;
    this = cx_declareChild(_parent, _name, cx_parameterseq_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_parameterseqDefine(cx_parameterseq* this, cx_parameterseq value) {
    cx_copyp(this, cx_parameterseq_o, &value);
    return cx_define(this);
}

void cx_parameterseqUpdate(cx_parameterseq* this, cx_parameterseq value) {
    cx_copyp(this, cx_parameterseq_o, &value);
    cx_update(this);
}

void cx_parameterseqSet(cx_parameterseq* this, cx_parameterseq value) {
    cx_copyp(this, cx_parameterseq_o, &value);
}

cx_string cx_parameterseqStr(cx_parameterseq value) {
    cx_string result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterseq_o), &value);
    result = cx_strv(&v, 0);
    return result;
}

cx_parameterseq* cx_parameterseqFromStr(cx_parameterseq* value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_parameterseq_o), str);
    return value;
}

cx_int16 cx_parameterseqCopy(cx_parameterseq* *dst, cx_parameterseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameterseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameterseq_o), src);
    return cx_copyv(&v1, &v2);
}

cx_int16 cx_parameterseqCompare(cx_parameterseq* dst, cx_parameterseq* src) {
    cx_value v1, v2;
    cx_valueValueInit(&v1, NULL, cx_type(cx_parameterseq_o), dst);
    cx_valueValueInit(&v2, NULL, cx_type(cx_parameterseq_o), src);
    return cx_comparev(&v1, &v2);
}

cx_int16 cx_parameterseqInit(cx_parameterseq* value) {
    cx_int16 result;
    memset(value, 0, cx_type(cx_parameterseq_o)->size);
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterseq_o), value);
    result = cx_initv(&v);
    return result;
}

cx_int16 cx_parameterseqDeinit(cx_parameterseq* value) {
    cx_int16 result;
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(cx_parameterseq_o), value);
    result = cx_deinitv(&v);
    return result;
}

cx_primitive cx_primitiveCreate(cx_width width) {
    cx_primitive this;
    this = cx_declare(cx_primitive_o);
    if (!this) {
        return NULL;
    }
    this->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_primitive cx_primitiveCreateChild(cx_object _parent, cx_string _name, cx_width width) {
    cx_primitive this;
    this = cx_declareChild(_parent, _name, cx_primitive_o);
    if (!this) {
        return NULL;
    }
    this->width = width;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_primitive cx_primitiveDeclare(void) {
    cx_primitive this;
    this = cx_declare(cx_primitive_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_primitive cx_primitiveDeclareChild(cx_object _parent, cx_string _name) {
    cx_primitive this;
    this = cx_declareChild(_parent, _name, cx_primitive_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_primitiveDefine(cx_primitive this, cx_width width) {
    this->width = width;
    return cx_define(this);
}

void cx_primitiveUpdate(cx_primitive this, cx_width width) {
    cx_updateBegin(this);
    this->width = width;
    cx_updateEnd(this);
}

void cx_primitiveSet(cx_primitive this, cx_width width) {
    this->width = width;
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

cx_primitiveKind* cx_primitiveKindCreate(cx_primitiveKind value) {
    cx_primitiveKind* this;
    this = cx_declare(cx_primitiveKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_primitiveKind* cx_primitiveKindCreateChild(cx_object _parent, cx_string _name, cx_primitiveKind value) {
    cx_primitiveKind* this;
    this = cx_declareChild(_parent, _name, cx_primitiveKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_primitiveKind* cx_primitiveKindDeclare(void) {
    cx_primitiveKind* this;
    this = cx_declare(cx_primitiveKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_primitiveKind* cx_primitiveKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_primitiveKind* this;
    this = cx_declareChild(_parent, _name, cx_primitiveKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_primitiveKindDefine(cx_primitiveKind* this, cx_primitiveKind value) {
    *this = value;
    return cx_define(this);
}

void cx_primitiveKindUpdate(cx_primitiveKind* this, cx_primitiveKind value) {
    *this = value;
    cx_update(this);
}

void cx_primitiveKindSet(cx_primitiveKind* this, cx_primitiveKind value) {
    *this = value;
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

cx_procedure cx_procedureCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind) {
    cx_procedure this;
    this = cx_declare(cx_procedure_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    this->kind = kind;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_procedure cx_procedureCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind) {
    cx_procedure this;
    this = cx_declareChild(_parent, _name, cx_procedure_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    this->kind = kind;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_procedure cx_procedureDeclare(void) {
    cx_procedure this;
    this = cx_declare(cx_procedure_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_procedure cx_procedureDeclareChild(cx_object _parent, cx_string _name) {
    cx_procedure this;
    this = cx_declareChild(_parent, _name, cx_procedure_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_procedureDefine(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    this->kind = kind;
    return cx_define(this);
}

void cx_procedureUpdate(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind) {
    cx_updateBegin(this);
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    this->kind = kind;
    cx_updateEnd(this);
}

void cx_procedureSet(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    cx_struct(this)->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    this->kind = kind;
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

cx_procedureKind* cx_procedureKindCreate(cx_procedureKind value) {
    cx_procedureKind* this;
    this = cx_declare(cx_procedureKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_procedureKind* cx_procedureKindCreateChild(cx_object _parent, cx_string _name, cx_procedureKind value) {
    cx_procedureKind* this;
    this = cx_declareChild(_parent, _name, cx_procedureKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_procedureKind* cx_procedureKindDeclare(void) {
    cx_procedureKind* this;
    this = cx_declare(cx_procedureKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_procedureKind* cx_procedureKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_procedureKind* this;
    this = cx_declareChild(_parent, _name, cx_procedureKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_procedureKindDefine(cx_procedureKind* this, cx_procedureKind value) {
    *this = value;
    return cx_define(this);
}

void cx_procedureKindUpdate(cx_procedureKind* this, cx_procedureKind value) {
    *this = value;
    cx_update(this);
}

void cx_procedureKindSet(cx_procedureKind* this, cx_procedureKind value) {
    *this = value;
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

cx_replicator cx_replicatorCreate(void) {
    cx_replicator this;
    this = cx_declare(cx_replicator_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_replicator cx_replicatorCreateChild(cx_object _parent, cx_string _name) {
    cx_replicator this;
    this = cx_declareChild(_parent, _name, cx_replicator_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_replicator cx_replicatorDeclare(void) {
    cx_replicator this;
    this = cx_declare(cx_replicator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_replicator cx_replicatorDeclareChild(cx_object _parent, cx_string _name) {
    cx_replicator this;
    this = cx_declareChild(_parent, _name, cx_replicator_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_replicatorDefine(cx_replicator this) {
    return cx_define(this);
}

void cx_replicatorUpdate(cx_replicator this) {
    cx_update(this);
}

void cx_replicatorSet(cx_replicator this) {
    CX_UNUSED(this);
}

cx_string cx_replicatorStr(cx_replicator value) {
    cx_string result;
    cx_value v;
    cx_valueObjectInit(&v, value, cx_type(cx_replicator_o));
    result = cx_strv(&v, 0);
    return result;
}

cx_replicator cx_replicatorFromStr(cx_replicator value, cx_string str) {
    cx_fromStrp(&value, cx_type(cx_replicator_o), str);
    return value;
}

cx_int16 cx_replicatorCopy(cx_replicator *dst, cx_replicator src) {
    return cx_copy((cx_object*)dst, src);
}

cx_int16 cx_replicatorCompare(cx_replicator dst, cx_replicator src) {
    return cx_compare(dst, src);
}

cx_sequence cx_sequenceCreate(cx_type elementType, cx_uint32 max) {
    cx_sequence this;
    this = cx_declare(cx_sequence_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_sequence cx_sequenceCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max) {
    cx_sequence this;
    this = cx_declareChild(_parent, _name, cx_sequence_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_sequence cx_sequenceDeclare(void) {
    cx_sequence this;
    this = cx_declare(cx_sequence_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_sequence cx_sequenceDeclareChild(cx_object _parent, cx_string _name) {
    cx_sequence this;
    this = cx_declareChild(_parent, _name, cx_sequence_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_sequenceDefine(cx_sequence this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    return cx_define(this);
}

void cx_sequenceUpdate(cx_sequence this, cx_type elementType, cx_uint32 max) {
    cx_updateBegin(this);
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
    cx_updateEnd(this);
}

void cx_sequenceSet(cx_sequence this, cx_type elementType, cx_uint32 max) {
    cx_setref(&cx_collection(this)->elementType, cx_type(elementType));
    cx_collection(this)->max = max;
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

cx_state* cx_stateCreate(cx_state value) {
    cx_state* this;
    this = cx_declare(cx_state_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_state* cx_stateCreateChild(cx_object _parent, cx_string _name, cx_state value) {
    cx_state* this;
    this = cx_declareChild(_parent, _name, cx_state_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_state* cx_stateDeclare(void) {
    cx_state* this;
    this = cx_declare(cx_state_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_state* cx_stateDeclareChild(cx_object _parent, cx_string _name) {
    cx_state* this;
    this = cx_declareChild(_parent, _name, cx_state_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_stateDefine(cx_state* this, cx_state value) {
    *this = value;
    return cx_define(this);
}

void cx_stateUpdate(cx_state* this, cx_state value) {
    *this = value;
    cx_update(this);
}

void cx_stateSet(cx_state* this, cx_state value) {
    *this = value;
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

cx_string* cx_stringCreate(cx_string value) {
    cx_string* this;
    this = cx_declare(cx_string_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_string* cx_stringCreateChild(cx_object _parent, cx_string _name, cx_string value) {
    cx_string* this;
    this = cx_declareChild(_parent, _name, cx_string_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_string* cx_stringDeclare(void) {
    cx_string* this;
    this = cx_declare(cx_string_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_string* cx_stringDeclareChild(cx_object _parent, cx_string _name) {
    cx_string* this;
    this = cx_declareChild(_parent, _name, cx_string_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_stringDefine(cx_string* this, cx_string value) {
    *this = value;
    return cx_define(this);
}

void cx_stringUpdate(cx_string* this, cx_string value) {
    *this = value;
    cx_update(this);
}

void cx_stringSet(cx_string* this, cx_string value) {
    *this = value;
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

cx_struct cx_structCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_struct this;
    this = cx_declare(cx_struct_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    this->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_struct cx_structCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_struct this;
    this = cx_declareChild(_parent, _name, cx_struct_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    this->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_struct cx_structDeclare(void) {
    cx_struct this;
    this = cx_declare(cx_struct_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_struct cx_structDeclareChild(cx_object _parent, cx_string _name) {
    cx_struct this;
    this = cx_declareChild(_parent, _name, cx_struct_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_structDefine(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    this->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    return cx_define(this);
}

void cx_structUpdate(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_updateBegin(this);
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    this->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
    cx_updateEnd(this);
}

void cx_structSet(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&cx_interface(this)->base, cx_interface(base));
    this->baseAccess = baseAccess;
    cx_setref(&cx_type(this)->parentType, cx_type(parentType));
    cx_type(this)->parentState = parentState;
    cx_setref(&cx_type(this)->defaultType, cx_type(defaultType));
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
    cx_text this;
    this = cx_declare(cx_text_o);
    if (!this) {
        return NULL;
    }
    this->charWidth = charWidth;
    this->length = length;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_text cx_textCreateChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length) {
    cx_text this;
    this = cx_declareChild(_parent, _name, cx_text_o);
    if (!this) {
        return NULL;
    }
    this->charWidth = charWidth;
    this->length = length;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_text cx_textDeclare(void) {
    cx_text this;
    this = cx_declare(cx_text_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_text cx_textDeclareChild(cx_object _parent, cx_string _name) {
    cx_text this;
    this = cx_declareChild(_parent, _name, cx_text_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_textDefine(cx_text this, cx_width charWidth, cx_uint64 length) {
    this->charWidth = charWidth;
    this->length = length;
    return cx_define(this);
}

void cx_textUpdate(cx_text this, cx_width charWidth, cx_uint64 length) {
    cx_updateBegin(this);
    this->charWidth = charWidth;
    this->length = length;
    cx_updateEnd(this);
}

void cx_textSet(cx_text this, cx_width charWidth, cx_uint64 length) {
    this->charWidth = charWidth;
    this->length = length;
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

cx_type cx_typeCreate(cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_type this;
    this = cx_declare(cx_type_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->parentType, cx_type(parentType));
    this->parentState = parentState;
    cx_setref(&this->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_type cx_typeCreateChild(cx_object _parent, cx_string _name, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_type this;
    this = cx_declareChild(_parent, _name, cx_type_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&this->parentType, cx_type(parentType));
    this->parentState = parentState;
    cx_setref(&this->defaultType, cx_type(defaultType));
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_type cx_typeDeclare(void) {
    cx_type this;
    this = cx_declare(cx_type_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_type cx_typeDeclareChild(cx_object _parent, cx_string _name) {
    cx_type this;
    this = cx_declareChild(_parent, _name, cx_type_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_typeDefine(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&this->parentType, cx_type(parentType));
    this->parentState = parentState;
    cx_setref(&this->defaultType, cx_type(defaultType));
    return cx_define(this);
}

void cx_typeUpdate(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_updateBegin(this);
    cx_setref(&this->parentType, cx_type(parentType));
    this->parentState = parentState;
    cx_setref(&this->defaultType, cx_type(defaultType));
    cx_updateEnd(this);
}

void cx_typeSet(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType) {
    cx_setref(&this->parentType, cx_type(parentType));
    this->parentState = parentState;
    cx_setref(&this->defaultType, cx_type(defaultType));
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

cx_typeKind* cx_typeKindCreate(cx_typeKind value) {
    cx_typeKind* this;
    this = cx_declare(cx_typeKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_typeKind* cx_typeKindCreateChild(cx_object _parent, cx_string _name, cx_typeKind value) {
    cx_typeKind* this;
    this = cx_declareChild(_parent, _name, cx_typeKind_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_typeKind* cx_typeKindDeclare(void) {
    cx_typeKind* this;
    this = cx_declare(cx_typeKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_typeKind* cx_typeKindDeclareChild(cx_object _parent, cx_string _name) {
    cx_typeKind* this;
    this = cx_declareChild(_parent, _name, cx_typeKind_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_typeKindDefine(cx_typeKind* this, cx_typeKind value) {
    *this = value;
    return cx_define(this);
}

void cx_typeKindUpdate(cx_typeKind* this, cx_typeKind value) {
    *this = value;
    cx_update(this);
}

void cx_typeKindSet(cx_typeKind* this, cx_typeKind value) {
    *this = value;
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
    cx_uint this;
    this = cx_declare(cx_uint_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint cx_uintCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_uint this;
    this = cx_declareChild(_parent, _name, cx_uint_o);
    if (!this) {
        return NULL;
    }
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint cx_uintDeclare(void) {
    cx_uint this;
    this = cx_declare(cx_uint_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_uint cx_uintDeclareChild(cx_object _parent, cx_string _name) {
    cx_uint this;
    this = cx_declareChild(_parent, _name, cx_uint_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_uintDefine(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    return cx_define(this);
}

void cx_uintUpdate(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_updateBegin(this);
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
    cx_updateEnd(this);
}

void cx_uintSet(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max) {
    cx_primitive(this)->width = width;
    this->min = min;
    this->max = max;
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

cx_uint16* cx_uint16Create(cx_uint16 value) {
    cx_uint16* this;
    this = cx_declare(cx_uint16_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint16* cx_uint16CreateChild(cx_object _parent, cx_string _name, cx_uint16 value) {
    cx_uint16* this;
    this = cx_declareChild(_parent, _name, cx_uint16_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint16* cx_uint16Declare(void) {
    cx_uint16* this;
    this = cx_declare(cx_uint16_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_uint16* cx_uint16DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint16* this;
    this = cx_declareChild(_parent, _name, cx_uint16_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_uint16Define(cx_uint16* this, cx_uint16 value) {
    *this = value;
    return cx_define(this);
}

void cx_uint16Update(cx_uint16* this, cx_uint16 value) {
    *this = value;
    cx_update(this);
}

void cx_uint16Set(cx_uint16* this, cx_uint16 value) {
    *this = value;
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

cx_uint32* cx_uint32Create(cx_uint32 value) {
    cx_uint32* this;
    this = cx_declare(cx_uint32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint32* cx_uint32CreateChild(cx_object _parent, cx_string _name, cx_uint32 value) {
    cx_uint32* this;
    this = cx_declareChild(_parent, _name, cx_uint32_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint32* cx_uint32Declare(void) {
    cx_uint32* this;
    this = cx_declare(cx_uint32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_uint32* cx_uint32DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint32* this;
    this = cx_declareChild(_parent, _name, cx_uint32_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_uint32Define(cx_uint32* this, cx_uint32 value) {
    *this = value;
    return cx_define(this);
}

void cx_uint32Update(cx_uint32* this, cx_uint32 value) {
    *this = value;
    cx_update(this);
}

void cx_uint32Set(cx_uint32* this, cx_uint32 value) {
    *this = value;
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

cx_uint64* cx_uint64Create(cx_uint64 value) {
    cx_uint64* this;
    this = cx_declare(cx_uint64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint64* cx_uint64CreateChild(cx_object _parent, cx_string _name, cx_uint64 value) {
    cx_uint64* this;
    this = cx_declareChild(_parent, _name, cx_uint64_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint64* cx_uint64Declare(void) {
    cx_uint64* this;
    this = cx_declare(cx_uint64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_uint64* cx_uint64DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint64* this;
    this = cx_declareChild(_parent, _name, cx_uint64_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_uint64Define(cx_uint64* this, cx_uint64 value) {
    *this = value;
    return cx_define(this);
}

void cx_uint64Update(cx_uint64* this, cx_uint64 value) {
    *this = value;
    cx_update(this);
}

void cx_uint64Set(cx_uint64* this, cx_uint64 value) {
    *this = value;
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

cx_uint8* cx_uint8Create(cx_uint8 value) {
    cx_uint8* this;
    this = cx_declare(cx_uint8_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint8* cx_uint8CreateChild(cx_object _parent, cx_string _name, cx_uint8 value) {
    cx_uint8* this;
    this = cx_declareChild(_parent, _name, cx_uint8_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_uint8* cx_uint8Declare(void) {
    cx_uint8* this;
    this = cx_declare(cx_uint8_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_uint8* cx_uint8DeclareChild(cx_object _parent, cx_string _name) {
    cx_uint8* this;
    this = cx_declareChild(_parent, _name, cx_uint8_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_uint8Define(cx_uint8* this, cx_uint8 value) {
    *this = value;
    return cx_define(this);
}

void cx_uint8Update(cx_uint8* this, cx_uint8 value) {
    *this = value;
    cx_update(this);
}

void cx_uint8Set(cx_uint8* this, cx_uint8 value) {
    *this = value;
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

cx_virtual cx_virtualCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_virtual this;
    this = cx_declare(cx_virtual_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    cx_method(this)->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_virtual cx_virtualCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_virtual this;
    this = cx_declareChild(_parent, _name, cx_virtual_o);
    if (!this) {
        return NULL;
    }
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    cx_method(this)->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_virtual cx_virtualDeclare(void) {
    cx_virtual this;
    this = cx_declare(cx_virtual_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_virtual cx_virtualDeclareChild(cx_object _parent, cx_string _name) {
    cx_virtual this;
    this = cx_declareChild(_parent, _name, cx_virtual_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_virtualDefine(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual, void(*_impl)(cx_function f, void *result, void *args)) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    cx_method(this)->virtual = virtual;
    cx_function(this)->impl = (cx_word)_impl;
    return cx_define(this);
}

void cx_virtualUpdate(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_updateBegin(this);
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    cx_method(this)->virtual = virtual;
    cx_updateEnd(this);
}

void cx_virtualSet(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual) {
    cx_setref(&cx_function(this)->returnType, cx_type(returnType));
    cx_function(this)->returnsReference = returnsReference;
    cx_method(this)->virtual = virtual;
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
    cx_void* this;
    this = cx_declare(cx_void_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_void* cx_voidCreateChild(cx_object _parent, cx_string _name) {
    cx_void* this;
    this = cx_declareChild(_parent, _name, cx_void_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_vtable* cx_vtableCreate(void) {
    cx_vtable* this;
    this = cx_declare(cx_vtable_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_vtable* cx_vtableCreateChild(cx_object _parent, cx_string _name) {
    cx_vtable* this;
    this = cx_declareChild(_parent, _name, cx_vtable_o);
    if (!this) {
        return NULL;
    }
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_vtable* cx_vtableDeclare(void) {
    cx_vtable* this;
    this = cx_declare(cx_vtable_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_vtable* cx_vtableDeclareChild(cx_object _parent, cx_string _name) {
    cx_vtable* this;
    this = cx_declareChild(_parent, _name, cx_vtable_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_vtableDefine(cx_vtable* this, cx_vtable value) {
    cx_copyp(this, cx_vtable_o, &value);
    return cx_define(this);
}

void cx_vtableUpdate(cx_vtable* this, cx_vtable value) {
    cx_copyp(this, cx_vtable_o, &value);
    cx_update(this);
}

void cx_vtableSet(cx_vtable* this, cx_vtable value) {
    cx_copyp(this, cx_vtable_o, &value);
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

cx_width* cx_widthCreate(cx_width value) {
    cx_width* this;
    this = cx_declare(cx_width_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_width* cx_widthCreateChild(cx_object _parent, cx_string _name, cx_width value) {
    cx_width* this;
    this = cx_declareChild(_parent, _name, cx_width_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_width* cx_widthDeclare(void) {
    cx_width* this;
    this = cx_declare(cx_width_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_width* cx_widthDeclareChild(cx_object _parent, cx_string _name) {
    cx_width* this;
    this = cx_declareChild(_parent, _name, cx_width_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_widthDefine(cx_width* this, cx_width value) {
    *this = value;
    return cx_define(this);
}

void cx_widthUpdate(cx_width* this, cx_width value) {
    *this = value;
    cx_update(this);
}

void cx_widthSet(cx_width* this, cx_width value) {
    *this = value;
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

cx_word* cx_wordCreate(cx_word value) {
    cx_word* this;
    this = cx_declare(cx_word_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_word* cx_wordCreateChild(cx_object _parent, cx_string _name, cx_word value) {
    cx_word* this;
    this = cx_declareChild(_parent, _name, cx_word_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

cx_word* cx_wordDeclare(void) {
    cx_word* this;
    this = cx_declare(cx_word_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_word* cx_wordDeclareChild(cx_object _parent, cx_string _name) {
    cx_word* this;
    this = cx_declareChild(_parent, _name, cx_word_o);
    if (!this) {
        return NULL;
    }
    return this;
}

cx_int16 cx_wordDefine(cx_word* this, cx_word value) {
    *this = value;
    return cx_define(this);
}

void cx_wordUpdate(cx_word* this, cx_word value) {
    *this = value;
    cx_update(this);
}

void cx_wordSet(cx_word* this, cx_word value) {
    *this = value;
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

cx_interface cx_interfaceseqAppend(cx_interfaceseq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_interfaceseqSize(cx_interfaceseq *seq, cx_uint32 length) {
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

void cx_interfaceseqClear(cx_interfaceseq *seq) {
    cx_interfaceseqSize(seq, 0);
}

cx_interfaceVector* cx_interfaceVectorseqAppend(cx_interfaceVectorseq *seq) {
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

void cx_interfaceVectorseqSize(cx_interfaceVectorseq *seq, cx_uint32 length) {
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

void cx_interfaceVectorseqClear(cx_interfaceVectorseq *seq) {
    cx_interfaceVectorseqSize(seq, 0);
}

cx_member cx_memberseqAppend(cx_memberseq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_member_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_memberseqSize(cx_memberseq *seq, cx_uint32 length) {
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

void cx_memberseqClear(cx_memberseq *seq) {
    cx_memberseqSize(seq, 0);
}

cx_object cx_objectseqAppend(cx_objectseq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_objectseqSize(cx_objectseq *seq, cx_uint32 length) {
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

void cx_objectseqClear(cx_objectseq *seq) {
    cx_objectseqSize(seq, 0);
}

cx_observer cx_observerseqAppend(cx_observerseq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_observer_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return seq->buffer[seq->length-1];
}

void cx_observerseqSize(cx_observerseq *seq, cx_uint32 length) {
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

void cx_observerseqClear(cx_observerseq *seq) {
    cx_observerseqSize(seq, 0);
}

cx_parameter* cx_parameterseqAppend(cx_parameterseq *seq) {
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

void cx_parameterseqSize(cx_parameterseq *seq, cx_uint32 length) {
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

void cx_parameterseqClear(cx_parameterseq *seq) {
    cx_parameterseqSize(seq, 0);
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

void cx_vtableClear(cx_vtable *seq) {
    cx_vtableSize(seq, 0);
}

