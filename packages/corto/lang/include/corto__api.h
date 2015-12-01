/* corto__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang__API_H
#define corto_lang__API_H

#include "corto.h"
#include "corto__interface.h"
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/lang/alias */
CORTO_LANG_EXPORT corto_alias _corto_aliasCreate(corto_member member);
#define corto_aliasCreate(member) _corto_aliasCreate(corto_member(member))
CORTO_LANG_EXPORT corto_alias _corto_aliasCreateChild(corto_object _parent, corto_string _name, corto_member member);
#define corto_aliasCreateChild(_parent, _name, member) _corto_aliasCreateChild(_parent, _name, corto_member(member))
CORTO_LANG_EXPORT corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member);
#define corto_aliasUpdate(_this, member) _corto_aliasUpdate(corto_alias(_this), corto_member(member))

CORTO_LANG_EXPORT corto_alias _corto_aliasDeclare(void);
#define corto_aliasDeclare() _corto_aliasDeclare()
CORTO_LANG_EXPORT corto_alias _corto_aliasDeclareChild(corto_object _parent, corto_string _name);
#define corto_aliasDeclareChild(_parent, _name) _corto_aliasDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_aliasDefine(corto_alias _this, corto_member member);
#define corto_aliasDefine(_this, member) _corto_aliasDefine(corto_alias(_this), corto_member(member))
CORTO_LANG_EXPORT void _corto_aliasSet(corto_alias _this, corto_member member);
#define corto_aliasSet(_this, member) _corto_aliasSet(corto_alias(_this), corto_member(member))
CORTO_LANG_EXPORT corto_string _corto_aliasStr(corto_alias value);
#define corto_aliasStr(value) _corto_aliasStr(corto_alias(value))
CORTO_LANG_EXPORT corto_alias corto_aliasFromStr(corto_alias value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_aliasCopy(corto_alias *dst, corto_alias src);
#define corto_aliasCopy(dst, src) _corto_aliasCopy(dst, corto_alias(src))
CORTO_LANG_EXPORT corto_int16 _corto_aliasCompare(corto_alias dst, corto_alias src);
#define corto_aliasCompare(dst, src) _corto_aliasCompare(corto_alias(dst), corto_alias(src))

/* /corto/lang/any */
CORTO_LANG_EXPORT corto_any* _corto_anyCreate(corto_any value);
#define corto_anyCreate(value) _corto_anyCreate(value)
CORTO_LANG_EXPORT corto_any* _corto_anyCreateChild(corto_object _parent, corto_string _name, corto_any value);
#define corto_anyCreateChild(_parent, _name, value) _corto_anyCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_anyUpdate(corto_any* _this, corto_any value);
#define corto_anyUpdate(_this, value) _corto_anyUpdate(_this, value)

CORTO_LANG_EXPORT corto_any* _corto_anyDeclare(void);
#define corto_anyDeclare() _corto_anyDeclare()
CORTO_LANG_EXPORT corto_any* _corto_anyDeclareChild(corto_object _parent, corto_string _name);
#define corto_anyDeclareChild(_parent, _name) _corto_anyDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_anyDefine(corto_any* _this, corto_any value);
#define corto_anyDefine(_this, value) _corto_anyDefine(_this, value)
CORTO_LANG_EXPORT void _corto_anySet(corto_any* _this, corto_any value);
#define corto_anySet(_this, value) _corto_anySet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_anyStr(corto_any value);
#define corto_anyStr(value) _corto_anyStr(value)
CORTO_LANG_EXPORT corto_any* corto_anyFromStr(corto_any* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_anyCopy(corto_any* *dst, corto_any* src);
#define corto_anyCopy(dst, src) _corto_anyCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_anyCompare(corto_any* dst, corto_any* src);
#define corto_anyCompare(dst, src) _corto_anyCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_anyInit(corto_any* value);
#define corto_anyInit(value) _corto_anyInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_anyDeinit(corto_any* value);
#define corto_anyDeinit(value) _corto_anyDeinit(value)

/* /corto/lang/array */
CORTO_LANG_EXPORT corto_array _corto_arrayCreate(corto_type elementType, corto_uint32 max);
#define corto_arrayCreate(elementType, max) _corto_arrayCreate(corto_type(elementType), max)
CORTO_LANG_EXPORT corto_array _corto_arrayCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_arrayCreateChild(_parent, _name, elementType, max) _corto_arrayCreateChild(_parent, _name, corto_type(elementType), max)
CORTO_LANG_EXPORT corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arrayUpdate(_this, elementType, max) _corto_arrayUpdate(corto_array(_this), corto_type(elementType), max)

CORTO_LANG_EXPORT corto_array _corto_arrayDeclare(void);
#define corto_arrayDeclare() _corto_arrayDeclare()
CORTO_LANG_EXPORT corto_array _corto_arrayDeclareChild(corto_object _parent, corto_string _name);
#define corto_arrayDeclareChild(_parent, _name) _corto_arrayDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arrayDefine(_this, elementType, max) _corto_arrayDefine(corto_array(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT void _corto_arraySet(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arraySet(_this, elementType, max) _corto_arraySet(corto_array(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT corto_string _corto_arrayStr(corto_array value);
#define corto_arrayStr(value) _corto_arrayStr(corto_array(value))
CORTO_LANG_EXPORT corto_array corto_arrayFromStr(corto_array value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_arrayCopy(corto_array *dst, corto_array src);
#define corto_arrayCopy(dst, src) _corto_arrayCopy(dst, corto_array(src))
CORTO_LANG_EXPORT corto_int16 _corto_arrayCompare(corto_array dst, corto_array src);
#define corto_arrayCompare(dst, src) _corto_arrayCompare(corto_array(dst), corto_array(src))

/* /corto/lang/attr */
CORTO_LANG_EXPORT corto_attr* _corto_attrCreate(corto_attr value);
#define corto_attrCreate(value) _corto_attrCreate(value)
CORTO_LANG_EXPORT corto_attr* _corto_attrCreateChild(corto_object _parent, corto_string _name, corto_attr value);
#define corto_attrCreateChild(_parent, _name, value) _corto_attrCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_attrUpdate(corto_attr* _this, corto_attr value);
#define corto_attrUpdate(_this, value) _corto_attrUpdate(_this, value)

CORTO_LANG_EXPORT corto_attr* _corto_attrDeclare(void);
#define corto_attrDeclare() _corto_attrDeclare()
CORTO_LANG_EXPORT corto_attr* _corto_attrDeclareChild(corto_object _parent, corto_string _name);
#define corto_attrDeclareChild(_parent, _name) _corto_attrDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_attrDefine(corto_attr* _this, corto_attr value);
#define corto_attrDefine(_this, value) _corto_attrDefine(_this, value)
CORTO_LANG_EXPORT void _corto_attrSet(corto_attr* _this, corto_attr value);
#define corto_attrSet(_this, value) _corto_attrSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_attrStr(corto_attr value);
#define corto_attrStr(value) _corto_attrStr(value)
CORTO_LANG_EXPORT corto_attr* corto_attrFromStr(corto_attr* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_attrCopy(corto_attr* *dst, corto_attr* src);
#define corto_attrCopy(dst, src) _corto_attrCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_attrCompare(corto_attr* dst, corto_attr* src);
#define corto_attrCompare(dst, src) _corto_attrCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_attrInit(corto_attr* value);
#define corto_attrInit(value) _corto_attrInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_attrDeinit(corto_attr* value);
#define corto_attrDeinit(value) _corto_attrDeinit(value)

/* /corto/lang/binary */
CORTO_LANG_EXPORT corto_binary _corto_binaryCreate(corto_width width);
#define corto_binaryCreate(width) _corto_binaryCreate(width)
CORTO_LANG_EXPORT corto_binary _corto_binaryCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_binaryCreateChild(_parent, _name, width) _corto_binaryCreateChild(_parent, _name, width)
CORTO_LANG_EXPORT corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width);
#define corto_binaryUpdate(_this, width) _corto_binaryUpdate(corto_binary(_this), width)

CORTO_LANG_EXPORT corto_binary _corto_binaryDeclare(void);
#define corto_binaryDeclare() _corto_binaryDeclare()
CORTO_LANG_EXPORT corto_binary _corto_binaryDeclareChild(corto_object _parent, corto_string _name);
#define corto_binaryDeclareChild(_parent, _name) _corto_binaryDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_binaryDefine(corto_binary _this, corto_width width);
#define corto_binaryDefine(_this, width) _corto_binaryDefine(corto_binary(_this), width)
CORTO_LANG_EXPORT void _corto_binarySet(corto_binary _this, corto_width width);
#define corto_binarySet(_this, width) _corto_binarySet(corto_binary(_this), width)
CORTO_LANG_EXPORT corto_string _corto_binaryStr(corto_binary value);
#define corto_binaryStr(value) _corto_binaryStr(corto_binary(value))
CORTO_LANG_EXPORT corto_binary corto_binaryFromStr(corto_binary value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_binaryCopy(corto_binary *dst, corto_binary src);
#define corto_binaryCopy(dst, src) _corto_binaryCopy(dst, corto_binary(src))
CORTO_LANG_EXPORT corto_int16 _corto_binaryCompare(corto_binary dst, corto_binary src);
#define corto_binaryCompare(dst, src) _corto_binaryCompare(corto_binary(dst), corto_binary(src))

/* /corto/lang/bitmask */
CORTO_LANG_EXPORT corto_bitmask _corto_bitmaskCreate(void);
#define corto_bitmaskCreate() _corto_bitmaskCreate()
CORTO_LANG_EXPORT corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, corto_string _name);
#define corto_bitmaskCreateChild(_parent, _name) _corto_bitmaskCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_bitmaskUpdate(corto_bitmask _this);
#define corto_bitmaskUpdate(_this) _corto_bitmaskUpdate(corto_bitmask(_this))

CORTO_LANG_EXPORT corto_bitmask _corto_bitmaskDeclare(void);
#define corto_bitmaskDeclare() _corto_bitmaskDeclare()
CORTO_LANG_EXPORT corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, corto_string _name);
#define corto_bitmaskDeclareChild(_parent, _name) _corto_bitmaskDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_bitmaskDefine(corto_bitmask _this);
#define corto_bitmaskDefine(_this) _corto_bitmaskDefine(corto_bitmask(_this))
CORTO_LANG_EXPORT void _corto_bitmaskSet(corto_bitmask _this);
#define corto_bitmaskSet(_this) _corto_bitmaskSet(corto_bitmask(_this))
CORTO_LANG_EXPORT corto_string _corto_bitmaskStr(corto_bitmask value);
#define corto_bitmaskStr(value) _corto_bitmaskStr(corto_bitmask(value))
CORTO_LANG_EXPORT corto_bitmask corto_bitmaskFromStr(corto_bitmask value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_bitmaskCopy(corto_bitmask *dst, corto_bitmask src);
#define corto_bitmaskCopy(dst, src) _corto_bitmaskCopy(dst, corto_bitmask(src))
CORTO_LANG_EXPORT corto_int16 _corto_bitmaskCompare(corto_bitmask dst, corto_bitmask src);
#define corto_bitmaskCompare(dst, src) _corto_bitmaskCompare(corto_bitmask(dst), corto_bitmask(src))

/* /corto/lang/bool */
CORTO_LANG_EXPORT corto_bool* _corto_boolCreate(corto_bool value);
#define corto_boolCreate(value) _corto_boolCreate(value)
CORTO_LANG_EXPORT corto_bool* _corto_boolCreateChild(corto_object _parent, corto_string _name, corto_bool value);
#define corto_boolCreateChild(_parent, _name, value) _corto_boolCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_boolUpdate(corto_bool* _this, corto_bool value);
#define corto_boolUpdate(_this, value) _corto_boolUpdate(_this, value)

CORTO_LANG_EXPORT corto_bool* _corto_boolDeclare(void);
#define corto_boolDeclare() _corto_boolDeclare()
CORTO_LANG_EXPORT corto_bool* _corto_boolDeclareChild(corto_object _parent, corto_string _name);
#define corto_boolDeclareChild(_parent, _name) _corto_boolDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_boolDefine(corto_bool* _this, corto_bool value);
#define corto_boolDefine(_this, value) _corto_boolDefine(_this, value)
CORTO_LANG_EXPORT void _corto_boolSet(corto_bool* _this, corto_bool value);
#define corto_boolSet(_this, value) _corto_boolSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_boolStr(corto_bool value);
#define corto_boolStr(value) _corto_boolStr(value)
CORTO_LANG_EXPORT corto_bool* corto_boolFromStr(corto_bool* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_boolCopy(corto_bool* *dst, corto_bool* src);
#define corto_boolCopy(dst, src) _corto_boolCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_boolCompare(corto_bool* dst, corto_bool* src);
#define corto_boolCompare(dst, src) _corto_boolCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_boolInit(corto_bool* value);
#define corto_boolInit(value) _corto_boolInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_boolDeinit(corto_bool* value);
#define corto_boolDeinit(value) _corto_boolDeinit(value)

/* /corto/lang/boolean */
CORTO_LANG_EXPORT corto_boolean _corto_booleanCreate(void);
#define corto_booleanCreate() _corto_booleanCreate()
CORTO_LANG_EXPORT corto_boolean _corto_booleanCreateChild(corto_object _parent, corto_string _name);
#define corto_booleanCreateChild(_parent, _name) _corto_booleanCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_booleanUpdate(corto_boolean _this);
#define corto_booleanUpdate(_this) _corto_booleanUpdate(corto_boolean(_this))

CORTO_LANG_EXPORT corto_boolean _corto_booleanDeclare(void);
#define corto_booleanDeclare() _corto_booleanDeclare()
CORTO_LANG_EXPORT corto_boolean _corto_booleanDeclareChild(corto_object _parent, corto_string _name);
#define corto_booleanDeclareChild(_parent, _name) _corto_booleanDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_booleanDefine(corto_boolean _this);
#define corto_booleanDefine(_this) _corto_booleanDefine(corto_boolean(_this))
CORTO_LANG_EXPORT void _corto_booleanSet(corto_boolean _this);
#define corto_booleanSet(_this) _corto_booleanSet(corto_boolean(_this))
CORTO_LANG_EXPORT corto_string _corto_booleanStr(corto_boolean value);
#define corto_booleanStr(value) _corto_booleanStr(corto_boolean(value))
CORTO_LANG_EXPORT corto_boolean corto_booleanFromStr(corto_boolean value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_booleanCopy(corto_boolean *dst, corto_boolean src);
#define corto_booleanCopy(dst, src) _corto_booleanCopy(dst, corto_boolean(src))
CORTO_LANG_EXPORT corto_int16 _corto_booleanCompare(corto_boolean dst, corto_boolean src);
#define corto_booleanCompare(dst, src) _corto_booleanCompare(corto_boolean(dst), corto_boolean(src))

/* /corto/lang/char */
CORTO_LANG_EXPORT corto_char* _corto_charCreate(corto_char value);
#define corto_charCreate(value) _corto_charCreate(value)
CORTO_LANG_EXPORT corto_char* _corto_charCreateChild(corto_object _parent, corto_string _name, corto_char value);
#define corto_charCreateChild(_parent, _name, value) _corto_charCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_charUpdate(corto_char* _this, corto_char value);
#define corto_charUpdate(_this, value) _corto_charUpdate(_this, value)

CORTO_LANG_EXPORT corto_char* _corto_charDeclare(void);
#define corto_charDeclare() _corto_charDeclare()
CORTO_LANG_EXPORT corto_char* _corto_charDeclareChild(corto_object _parent, corto_string _name);
#define corto_charDeclareChild(_parent, _name) _corto_charDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_charDefine(corto_char* _this, corto_char value);
#define corto_charDefine(_this, value) _corto_charDefine(_this, value)
CORTO_LANG_EXPORT void _corto_charSet(corto_char* _this, corto_char value);
#define corto_charSet(_this, value) _corto_charSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_charStr(corto_char value);
#define corto_charStr(value) _corto_charStr(value)
CORTO_LANG_EXPORT corto_char* corto_charFromStr(corto_char* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_charCopy(corto_char* *dst, corto_char* src);
#define corto_charCopy(dst, src) _corto_charCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_charCompare(corto_char* dst, corto_char* src);
#define corto_charCompare(dst, src) _corto_charCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_charInit(corto_char* value);
#define corto_charInit(value) _corto_charInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_charDeinit(corto_char* value);
#define corto_charDeinit(value) _corto_charDeinit(value)

/* /corto/lang/character */
CORTO_LANG_EXPORT corto_character _corto_characterCreate(corto_width width);
#define corto_characterCreate(width) _corto_characterCreate(width)
CORTO_LANG_EXPORT corto_character _corto_characterCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_characterCreateChild(_parent, _name, width) _corto_characterCreateChild(_parent, _name, width)
CORTO_LANG_EXPORT corto_int16 _corto_characterUpdate(corto_character _this, corto_width width);
#define corto_characterUpdate(_this, width) _corto_characterUpdate(corto_character(_this), width)

CORTO_LANG_EXPORT corto_character _corto_characterDeclare(void);
#define corto_characterDeclare() _corto_characterDeclare()
CORTO_LANG_EXPORT corto_character _corto_characterDeclareChild(corto_object _parent, corto_string _name);
#define corto_characterDeclareChild(_parent, _name) _corto_characterDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_characterDefine(corto_character _this, corto_width width);
#define corto_characterDefine(_this, width) _corto_characterDefine(corto_character(_this), width)
CORTO_LANG_EXPORT void _corto_characterSet(corto_character _this, corto_width width);
#define corto_characterSet(_this, width) _corto_characterSet(corto_character(_this), width)
CORTO_LANG_EXPORT corto_string _corto_characterStr(corto_character value);
#define corto_characterStr(value) _corto_characterStr(corto_character(value))
CORTO_LANG_EXPORT corto_character corto_characterFromStr(corto_character value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_characterCopy(corto_character *dst, corto_character src);
#define corto_characterCopy(dst, src) _corto_characterCopy(dst, corto_character(src))
CORTO_LANG_EXPORT corto_int16 _corto_characterCompare(corto_character dst, corto_character src);
#define corto_characterCompare(dst, src) _corto_characterCompare(corto_character(dst), corto_character(src))

/* /corto/lang/class */
CORTO_LANG_EXPORT corto_class _corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreate(base, baseAccess, implements) _corto_classCreate(corto_interface(base), baseAccess, implements)
CORTO_LANG_EXPORT corto_class _corto_classCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreateChild(_parent, _name, base, baseAccess, implements) _corto_classCreateChild(_parent, _name, corto_interface(base), baseAccess, implements)
CORTO_LANG_EXPORT corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classUpdate(_this, base, baseAccess, implements) _corto_classUpdate(corto_class(_this), corto_interface(base), baseAccess, implements)

CORTO_LANG_EXPORT corto_class _corto_classDeclare(void);
#define corto_classDeclare() _corto_classDeclare()
CORTO_LANG_EXPORT corto_class _corto_classDeclareChild(corto_object _parent, corto_string _name);
#define corto_classDeclareChild(_parent, _name) _corto_classDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classDefine(_this, base, baseAccess, implements) _corto_classDefine(corto_class(_this), corto_interface(base), baseAccess, implements)
CORTO_LANG_EXPORT void _corto_classSet(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classSet(_this, base, baseAccess, implements) _corto_classSet(corto_class(_this), corto_interface(base), baseAccess, implements)
CORTO_LANG_EXPORT corto_string _corto_classStr(corto_class value);
#define corto_classStr(value) _corto_classStr(corto_class(value))
CORTO_LANG_EXPORT corto_class corto_classFromStr(corto_class value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_classCopy(corto_class *dst, corto_class src);
#define corto_classCopy(dst, src) _corto_classCopy(dst, corto_class(src))
CORTO_LANG_EXPORT corto_int16 _corto_classCompare(corto_class dst, corto_class src);
#define corto_classCompare(dst, src) _corto_classCompare(corto_class(dst), corto_class(src))

/* /corto/lang/collection */
CORTO_LANG_EXPORT corto_collection _corto_collectionCreate(corto_type elementType, corto_uint32 max);
#define corto_collectionCreate(elementType, max) _corto_collectionCreate(corto_type(elementType), max)
CORTO_LANG_EXPORT corto_collection _corto_collectionCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_collectionCreateChild(_parent, _name, elementType, max) _corto_collectionCreateChild(_parent, _name, corto_type(elementType), max)
CORTO_LANG_EXPORT corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionUpdate(_this, elementType, max) _corto_collectionUpdate(corto_collection(_this), corto_type(elementType), max)

CORTO_LANG_EXPORT corto_collection _corto_collectionDeclare(void);
#define corto_collectionDeclare() _corto_collectionDeclare()
CORTO_LANG_EXPORT corto_collection _corto_collectionDeclareChild(corto_object _parent, corto_string _name);
#define corto_collectionDeclareChild(_parent, _name) _corto_collectionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionDefine(_this, elementType, max) _corto_collectionDefine(corto_collection(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT void _corto_collectionSet(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionSet(_this, elementType, max) _corto_collectionSet(corto_collection(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT corto_string _corto_collectionStr(corto_collection value);
#define corto_collectionStr(value) _corto_collectionStr(corto_collection(value))
CORTO_LANG_EXPORT corto_collection corto_collectionFromStr(corto_collection value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_collectionCopy(corto_collection *dst, corto_collection src);
#define corto_collectionCopy(dst, src) _corto_collectionCopy(dst, corto_collection(src))
CORTO_LANG_EXPORT corto_int16 _corto_collectionCompare(corto_collection dst, corto_collection src);
#define corto_collectionCompare(dst, src) _corto_collectionCompare(corto_collection(dst), corto_collection(src))

/* /corto/lang/collectionKind */
CORTO_LANG_EXPORT corto_collectionKind* _corto_collectionKindCreate(corto_collectionKind value);
#define corto_collectionKindCreate(value) _corto_collectionKindCreate(value)
CORTO_LANG_EXPORT corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, corto_string _name, corto_collectionKind value);
#define corto_collectionKindCreateChild(_parent, _name, value) _corto_collectionKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindUpdate(_this, value) _corto_collectionKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_collectionKind* _corto_collectionKindDeclare(void);
#define corto_collectionKindDeclare() _corto_collectionKindDeclare()
CORTO_LANG_EXPORT corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_collectionKindDeclareChild(_parent, _name) _corto_collectionKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindDefine(_this, value) _corto_collectionKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_collectionKindSet(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindSet(_this, value) _corto_collectionKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_collectionKindStr(corto_collectionKind value);
#define corto_collectionKindStr(value) _corto_collectionKindStr(value)
CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindFromStr(corto_collectionKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_collectionKindCopy(corto_collectionKind* *dst, corto_collectionKind* src);
#define corto_collectionKindCopy(dst, src) _corto_collectionKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_collectionKindCompare(corto_collectionKind* dst, corto_collectionKind* src);
#define corto_collectionKindCompare(dst, src) _corto_collectionKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_collectionKindInit(corto_collectionKind* value);
#define corto_collectionKindInit(value) _corto_collectionKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_collectionKindDeinit(corto_collectionKind* value);
#define corto_collectionKindDeinit(value) _corto_collectionKindDeinit(value)

/* /corto/lang/compositeKind */
CORTO_LANG_EXPORT corto_compositeKind* _corto_compositeKindCreate(corto_compositeKind value);
#define corto_compositeKindCreate(value) _corto_compositeKindCreate(value)
CORTO_LANG_EXPORT corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, corto_string _name, corto_compositeKind value);
#define corto_compositeKindCreateChild(_parent, _name, value) _corto_compositeKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindUpdate(_this, value) _corto_compositeKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_compositeKind* _corto_compositeKindDeclare(void);
#define corto_compositeKindDeclare() _corto_compositeKindDeclare()
CORTO_LANG_EXPORT corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_compositeKindDeclareChild(_parent, _name) _corto_compositeKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindDefine(_this, value) _corto_compositeKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_compositeKindSet(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindSet(_this, value) _corto_compositeKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_compositeKindStr(corto_compositeKind value);
#define corto_compositeKindStr(value) _corto_compositeKindStr(value)
CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindFromStr(corto_compositeKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_compositeKindCopy(corto_compositeKind* *dst, corto_compositeKind* src);
#define corto_compositeKindCopy(dst, src) _corto_compositeKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_compositeKindCompare(corto_compositeKind* dst, corto_compositeKind* src);
#define corto_compositeKindCompare(dst, src) _corto_compositeKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_compositeKindInit(corto_compositeKind* value);
#define corto_compositeKindInit(value) _corto_compositeKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_compositeKindDeinit(corto_compositeKind* value);
#define corto_compositeKindDeinit(value) _corto_compositeKindDeinit(value)

/* /corto/lang/constant */
CORTO_LANG_EXPORT corto_constant* _corto_constantCreate(corto_constant value);
#define corto_constantCreate(value) _corto_constantCreate(value)
CORTO_LANG_EXPORT corto_constant* _corto_constantCreateChild(corto_object _parent, corto_string _name, corto_constant value);
#define corto_constantCreateChild(_parent, _name, value) _corto_constantCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_constantUpdate(corto_constant* _this, corto_constant value);
#define corto_constantUpdate(_this, value) _corto_constantUpdate(_this, value)

CORTO_LANG_EXPORT corto_constant* _corto_constantDeclare(void);
#define corto_constantDeclare() _corto_constantDeclare()
CORTO_LANG_EXPORT corto_constant* _corto_constantDeclareChild(corto_object _parent, corto_string _name);
#define corto_constantDeclareChild(_parent, _name) _corto_constantDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_constantDefine(corto_constant* _this, corto_constant value);
#define corto_constantDefine(_this, value) _corto_constantDefine(_this, value)
CORTO_LANG_EXPORT void _corto_constantSet(corto_constant* _this, corto_constant value);
#define corto_constantSet(_this, value) _corto_constantSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_constantStr(corto_constant value);
#define corto_constantStr(value) _corto_constantStr(value)
CORTO_LANG_EXPORT corto_constant* corto_constantFromStr(corto_constant* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_constantCopy(corto_constant* *dst, corto_constant* src);
#define corto_constantCopy(dst, src) _corto_constantCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_constantCompare(corto_constant* dst, corto_constant* src);
#define corto_constantCompare(dst, src) _corto_constantCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_constantInit(corto_constant* value);
#define corto_constantInit(value) _corto_constantInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_constantDeinit(corto_constant* value);
#define corto_constantDeinit(value) _corto_constantDeinit(value)

/* /corto/lang/delegate */
CORTO_LANG_EXPORT corto_delegate _corto_delegateCreate(corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreate(returnType, returnsReference, parameters) _corto_delegateCreate(corto_type(returnType), returnsReference, parameters)
CORTO_LANG_EXPORT corto_delegate _corto_delegateCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreateChild(_parent, _name, returnType, returnsReference, parameters) _corto_delegateCreateChild(_parent, _name, corto_type(returnType), returnsReference, parameters)
CORTO_LANG_EXPORT corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateUpdate(_this, returnType, returnsReference, parameters) _corto_delegateUpdate(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)

CORTO_LANG_EXPORT corto_delegate _corto_delegateDeclare(void);
#define corto_delegateDeclare() _corto_delegateDeclare()
CORTO_LANG_EXPORT corto_delegate _corto_delegateDeclareChild(corto_object _parent, corto_string _name);
#define corto_delegateDeclareChild(_parent, _name) _corto_delegateDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateDefine(_this, returnType, returnsReference, parameters) _corto_delegateDefine(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)
CORTO_LANG_EXPORT void _corto_delegateSet(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateSet(_this, returnType, returnsReference, parameters) _corto_delegateSet(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)
CORTO_LANG_EXPORT corto_string _corto_delegateStr(corto_delegate value);
#define corto_delegateStr(value) _corto_delegateStr(corto_delegate(value))
CORTO_LANG_EXPORT corto_delegate corto_delegateFromStr(corto_delegate value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_delegateCopy(corto_delegate *dst, corto_delegate src);
#define corto_delegateCopy(dst, src) _corto_delegateCopy(dst, corto_delegate(src))
CORTO_LANG_EXPORT corto_int16 _corto_delegateCompare(corto_delegate dst, corto_delegate src);
#define corto_delegateCompare(dst, src) _corto_delegateCompare(corto_delegate(dst), corto_delegate(src))

/* /corto/lang/delegatedata */
CORTO_LANG_EXPORT corto_delegatedata* _corto_delegatedataCreate(corto_object instance, corto_function procedure);
#define corto_delegatedataCreate(instance, procedure) _corto_delegatedataCreate(instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_delegatedataCreateChild(_parent, _name, instance, procedure) _corto_delegatedataCreateChild(_parent, _name, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataUpdate(_this, instance, procedure) _corto_delegatedataUpdate(_this, instance, corto_function(procedure))

CORTO_LANG_EXPORT corto_delegatedata* _corto_delegatedataDeclare(void);
#define corto_delegatedataDeclare() _corto_delegatedataDeclare()
CORTO_LANG_EXPORT corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, corto_string _name);
#define corto_delegatedataDeclareChild(_parent, _name) _corto_delegatedataDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataDefine(_this, instance, procedure) _corto_delegatedataDefine(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT void _corto_delegatedataSet(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataSet(_this, instance, procedure) _corto_delegatedataSet(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_string _corto_delegatedataStr(corto_delegatedata* value);
#define corto_delegatedataStr(value) _corto_delegatedataStr(value)
CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataFromStr(corto_delegatedata* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_delegatedataCopy(corto_delegatedata* *dst, corto_delegatedata* src);
#define corto_delegatedataCopy(dst, src) _corto_delegatedataCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_delegatedataCompare(corto_delegatedata* dst, corto_delegatedata* src);
#define corto_delegatedataCompare(dst, src) _corto_delegatedataCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_delegatedataInit(corto_delegatedata* value);
#define corto_delegatedataInit(value) _corto_delegatedataInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_delegatedataDeinit(corto_delegatedata* value);
#define corto_delegatedataDeinit(value) _corto_delegatedataDeinit(value)

/* /corto/lang/destructAction */
CORTO_LANG_EXPORT corto_destructAction* _corto_destructActionCreate(corto_object instance, corto_function procedure);
#define corto_destructActionCreate(instance, procedure) _corto_destructActionCreate(instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_destructAction* _corto_destructActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_destructActionCreateChild(_parent, _name, instance, procedure) _corto_destructActionCreateChild(_parent, _name, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_int16 _corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionUpdate(_this, instance, procedure) _corto_destructActionUpdate(_this, instance, corto_function(procedure))

CORTO_LANG_EXPORT corto_destructAction* _corto_destructActionDeclare(void);
#define corto_destructActionDeclare() _corto_destructActionDeclare()
CORTO_LANG_EXPORT corto_destructAction* _corto_destructActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_destructActionDeclareChild(_parent, _name) _corto_destructActionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_destructActionDefine(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionDefine(_this, instance, procedure) _corto_destructActionDefine(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT void _corto_destructActionSet(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionSet(_this, instance, procedure) _corto_destructActionSet(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_string _corto_destructActionStr(corto_destructAction* value);
#define corto_destructActionStr(value) _corto_destructActionStr(value)
CORTO_LANG_EXPORT corto_destructAction* corto_destructActionFromStr(corto_destructAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_destructActionCopy(corto_destructAction* *dst, corto_destructAction* src);
#define corto_destructActionCopy(dst, src) _corto_destructActionCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_destructActionCompare(corto_destructAction* dst, corto_destructAction* src);
#define corto_destructActionCompare(dst, src) _corto_destructActionCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_destructActionInit(corto_destructAction* value);
#define corto_destructActionInit(value) _corto_destructActionInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_destructActionDeinit(corto_destructAction* value);
#define corto_destructActionDeinit(value) _corto_destructActionDeinit(value)

corto_int16 corto_destructActionCall(corto_destructAction *_delegate);
/* /corto/lang/dispatcher */
CORTO_LANG_EXPORT corto_dispatcher _corto_dispatcherCreate(void);
#define corto_dispatcherCreate() _corto_dispatcherCreate()
CORTO_LANG_EXPORT corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _name);
#define corto_dispatcherCreateChild(_parent, _name) _corto_dispatcherCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this);
#define corto_dispatcherUpdate(_this) _corto_dispatcherUpdate(corto_dispatcher(_this))

CORTO_LANG_EXPORT corto_dispatcher _corto_dispatcherDeclare(void);
#define corto_dispatcherDeclare() _corto_dispatcherDeclare()
CORTO_LANG_EXPORT corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _name);
#define corto_dispatcherDeclareChild(_parent, _name) _corto_dispatcherDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_dispatcherDefine(corto_dispatcher _this);
#define corto_dispatcherDefine(_this) _corto_dispatcherDefine(corto_dispatcher(_this))
CORTO_LANG_EXPORT void _corto_dispatcherSet(corto_dispatcher _this);
#define corto_dispatcherSet(_this) _corto_dispatcherSet(corto_dispatcher(_this))
CORTO_LANG_EXPORT corto_string _corto_dispatcherStr(corto_dispatcher value);
#define corto_dispatcherStr(value) _corto_dispatcherStr(corto_dispatcher(value))
CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherFromStr(corto_dispatcher value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_dispatcherCopy(corto_dispatcher *dst, corto_dispatcher src);
#define corto_dispatcherCopy(dst, src) _corto_dispatcherCopy(dst, corto_dispatcher(src))
CORTO_LANG_EXPORT corto_int16 _corto_dispatcherCompare(corto_dispatcher dst, corto_dispatcher src);
#define corto_dispatcherCompare(dst, src) _corto_dispatcherCompare(corto_dispatcher(dst), corto_dispatcher(src))

/* /corto/lang/enum */
CORTO_LANG_EXPORT corto_enum _corto_enumCreate(void);
#define corto_enumCreate() _corto_enumCreate()
CORTO_LANG_EXPORT corto_enum _corto_enumCreateChild(corto_object _parent, corto_string _name);
#define corto_enumCreateChild(_parent, _name) _corto_enumCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_enumUpdate(corto_enum _this);
#define corto_enumUpdate(_this) _corto_enumUpdate(corto_enum(_this))

CORTO_LANG_EXPORT corto_enum _corto_enumDeclare(void);
#define corto_enumDeclare() _corto_enumDeclare()
CORTO_LANG_EXPORT corto_enum _corto_enumDeclareChild(corto_object _parent, corto_string _name);
#define corto_enumDeclareChild(_parent, _name) _corto_enumDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_enumDefine(corto_enum _this);
#define corto_enumDefine(_this) _corto_enumDefine(corto_enum(_this))
CORTO_LANG_EXPORT void _corto_enumSet(corto_enum _this);
#define corto_enumSet(_this) _corto_enumSet(corto_enum(_this))
CORTO_LANG_EXPORT corto_string _corto_enumStr(corto_enum value);
#define corto_enumStr(value) _corto_enumStr(corto_enum(value))
CORTO_LANG_EXPORT corto_enum corto_enumFromStr(corto_enum value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_enumCopy(corto_enum *dst, corto_enum src);
#define corto_enumCopy(dst, src) _corto_enumCopy(dst, corto_enum(src))
CORTO_LANG_EXPORT corto_int16 _corto_enumCompare(corto_enum dst, corto_enum src);
#define corto_enumCompare(dst, src) _corto_enumCompare(corto_enum(dst), corto_enum(src))

/* /corto/lang/equalityKind */
CORTO_LANG_EXPORT corto_equalityKind* _corto_equalityKindCreate(corto_equalityKind value);
#define corto_equalityKindCreate(value) _corto_equalityKindCreate(value)
CORTO_LANG_EXPORT corto_equalityKind* _corto_equalityKindCreateChild(corto_object _parent, corto_string _name, corto_equalityKind value);
#define corto_equalityKindCreateChild(_parent, _name, value) _corto_equalityKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindUpdate(_this, value) _corto_equalityKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_equalityKind* _corto_equalityKindDeclare(void);
#define corto_equalityKindDeclare() _corto_equalityKindDeclare()
CORTO_LANG_EXPORT corto_equalityKind* _corto_equalityKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_equalityKindDeclareChild(_parent, _name) _corto_equalityKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindDefine(_this, value) _corto_equalityKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_equalityKindSet(corto_equalityKind* _this, corto_equalityKind value);
#define corto_equalityKindSet(_this, value) _corto_equalityKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_equalityKindStr(corto_equalityKind value);
#define corto_equalityKindStr(value) _corto_equalityKindStr(value)
CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindFromStr(corto_equalityKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_equalityKindCopy(corto_equalityKind* *dst, corto_equalityKind* src);
#define corto_equalityKindCopy(dst, src) _corto_equalityKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_equalityKindCompare(corto_equalityKind* dst, corto_equalityKind* src);
#define corto_equalityKindCompare(dst, src) _corto_equalityKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_equalityKindInit(corto_equalityKind* value);
#define corto_equalityKindInit(value) _corto_equalityKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_equalityKindDeinit(corto_equalityKind* value);
#define corto_equalityKindDeinit(value) _corto_equalityKindDeinit(value)

/* /corto/lang/event */
CORTO_LANG_EXPORT corto_event _corto_eventCreate(corto_uint16 kind);
#define corto_eventCreate(kind) _corto_eventCreate(kind)
CORTO_LANG_EXPORT corto_event _corto_eventCreateChild(corto_object _parent, corto_string _name, corto_uint16 kind);
#define corto_eventCreateChild(_parent, _name, kind) _corto_eventCreateChild(_parent, _name, kind)
CORTO_LANG_EXPORT corto_int16 _corto_eventUpdate(corto_event _this, corto_uint16 kind);
#define corto_eventUpdate(_this, kind) _corto_eventUpdate(corto_event(_this), kind)

CORTO_LANG_EXPORT corto_event _corto_eventDeclare(void);
#define corto_eventDeclare() _corto_eventDeclare()
CORTO_LANG_EXPORT corto_event _corto_eventDeclareChild(corto_object _parent, corto_string _name);
#define corto_eventDeclareChild(_parent, _name) _corto_eventDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_eventDefine(corto_event _this, corto_uint16 kind);
#define corto_eventDefine(_this, kind) _corto_eventDefine(corto_event(_this), kind)
CORTO_LANG_EXPORT void _corto_eventSet(corto_event _this, corto_uint16 kind);
#define corto_eventSet(_this, kind) _corto_eventSet(corto_event(_this), kind)
CORTO_LANG_EXPORT corto_string _corto_eventStr(corto_event value);
#define corto_eventStr(value) _corto_eventStr(corto_event(value))
CORTO_LANG_EXPORT corto_event corto_eventFromStr(corto_event value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_eventCopy(corto_event *dst, corto_event src);
#define corto_eventCopy(dst, src) _corto_eventCopy(dst, corto_event(src))
CORTO_LANG_EXPORT corto_int16 _corto_eventCompare(corto_event dst, corto_event src);
#define corto_eventCompare(dst, src) _corto_eventCompare(corto_event(dst), corto_event(src))

/* /corto/lang/eventMask */
CORTO_LANG_EXPORT corto_eventMask* _corto_eventMaskCreate(corto_eventMask value);
#define corto_eventMaskCreate(value) _corto_eventMaskCreate(value)
CORTO_LANG_EXPORT corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _name, corto_eventMask value);
#define corto_eventMaskCreateChild(_parent, _name, value) _corto_eventMaskCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskUpdate(_this, value) _corto_eventMaskUpdate(_this, value)

CORTO_LANG_EXPORT corto_eventMask* _corto_eventMaskDeclare(void);
#define corto_eventMaskDeclare() _corto_eventMaskDeclare()
CORTO_LANG_EXPORT corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _name);
#define corto_eventMaskDeclareChild(_parent, _name) _corto_eventMaskDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskDefine(_this, value) _corto_eventMaskDefine(_this, value)
CORTO_LANG_EXPORT void _corto_eventMaskSet(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskSet(_this, value) _corto_eventMaskSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_eventMaskStr(corto_eventMask value);
#define corto_eventMaskStr(value) _corto_eventMaskStr(value)
CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskFromStr(corto_eventMask* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_eventMaskCopy(corto_eventMask* *dst, corto_eventMask* src);
#define corto_eventMaskCopy(dst, src) _corto_eventMaskCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_eventMaskCompare(corto_eventMask* dst, corto_eventMask* src);
#define corto_eventMaskCompare(dst, src) _corto_eventMaskCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_eventMaskInit(corto_eventMask* value);
#define corto_eventMaskInit(value) _corto_eventMaskInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_eventMaskDeinit(corto_eventMask* value);
#define corto_eventMaskDeinit(value) _corto_eventMaskDeinit(value)

/* /corto/lang/float */
CORTO_LANG_EXPORT corto_float _corto_floatCreate(corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatCreate(width, min, max) _corto_floatCreate(width, min, max)
CORTO_LANG_EXPORT corto_float _corto_floatCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatCreateChild(_parent, _name, width, min, max) _corto_floatCreateChild(_parent, _name, width, min, max)
CORTO_LANG_EXPORT corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatUpdate(_this, width, min, max) _corto_floatUpdate(corto_float(_this), width, min, max)

CORTO_LANG_EXPORT corto_float _corto_floatDeclare(void);
#define corto_floatDeclare() _corto_floatDeclare()
CORTO_LANG_EXPORT corto_float _corto_floatDeclareChild(corto_object _parent, corto_string _name);
#define corto_floatDeclareChild(_parent, _name) _corto_floatDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_floatDefine(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatDefine(_this, width, min, max) _corto_floatDefine(corto_float(_this), width, min, max)
CORTO_LANG_EXPORT void _corto_floatSet(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatSet(_this, width, min, max) _corto_floatSet(corto_float(_this), width, min, max)
CORTO_LANG_EXPORT corto_string _corto_floatStr(corto_float value);
#define corto_floatStr(value) _corto_floatStr(corto_float(value))
CORTO_LANG_EXPORT corto_float corto_floatFromStr(corto_float value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_floatCopy(corto_float *dst, corto_float src);
#define corto_floatCopy(dst, src) _corto_floatCopy(dst, corto_float(src))
CORTO_LANG_EXPORT corto_int16 _corto_floatCompare(corto_float dst, corto_float src);
#define corto_floatCompare(dst, src) _corto_floatCompare(corto_float(dst), corto_float(src))

/* /corto/lang/float32 */
CORTO_LANG_EXPORT corto_float32* _corto_float32Create(corto_float32 value);
#define corto_float32Create(value) _corto_float32Create(value)
CORTO_LANG_EXPORT corto_float32* _corto_float32CreateChild(corto_object _parent, corto_string _name, corto_float32 value);
#define corto_float32CreateChild(_parent, _name, value) _corto_float32CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_float32Update(corto_float32* _this, corto_float32 value);
#define corto_float32Update(_this, value) _corto_float32Update(_this, value)

CORTO_LANG_EXPORT corto_float32* _corto_float32Declare(void);
#define corto_float32Declare() _corto_float32Declare()
CORTO_LANG_EXPORT corto_float32* _corto_float32DeclareChild(corto_object _parent, corto_string _name);
#define corto_float32DeclareChild(_parent, _name) _corto_float32DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_float32Define(corto_float32* _this, corto_float32 value);
#define corto_float32Define(_this, value) _corto_float32Define(_this, value)
CORTO_LANG_EXPORT void _corto_float32Set(corto_float32* _this, corto_float32 value);
#define corto_float32Set(_this, value) _corto_float32Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_float32Str(corto_float32 value);
#define corto_float32Str(value) _corto_float32Str(value)
CORTO_LANG_EXPORT corto_float32* corto_float32FromStr(corto_float32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_float32Copy(corto_float32* *dst, corto_float32* src);
#define corto_float32Copy(dst, src) _corto_float32Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_float32Compare(corto_float32* dst, corto_float32* src);
#define corto_float32Compare(dst, src) _corto_float32Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_float32Init(corto_float32* value);
#define corto_float32Init(value) _corto_float32Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_float32Deinit(corto_float32* value);
#define corto_float32Deinit(value) _corto_float32Deinit(value)

/* /corto/lang/float64 */
CORTO_LANG_EXPORT corto_float64* _corto_float64Create(corto_float64 value);
#define corto_float64Create(value) _corto_float64Create(value)
CORTO_LANG_EXPORT corto_float64* _corto_float64CreateChild(corto_object _parent, corto_string _name, corto_float64 value);
#define corto_float64CreateChild(_parent, _name, value) _corto_float64CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_float64Update(corto_float64* _this, corto_float64 value);
#define corto_float64Update(_this, value) _corto_float64Update(_this, value)

CORTO_LANG_EXPORT corto_float64* _corto_float64Declare(void);
#define corto_float64Declare() _corto_float64Declare()
CORTO_LANG_EXPORT corto_float64* _corto_float64DeclareChild(corto_object _parent, corto_string _name);
#define corto_float64DeclareChild(_parent, _name) _corto_float64DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_float64Define(corto_float64* _this, corto_float64 value);
#define corto_float64Define(_this, value) _corto_float64Define(_this, value)
CORTO_LANG_EXPORT void _corto_float64Set(corto_float64* _this, corto_float64 value);
#define corto_float64Set(_this, value) _corto_float64Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_float64Str(corto_float64 value);
#define corto_float64Str(value) _corto_float64Str(value)
CORTO_LANG_EXPORT corto_float64* corto_float64FromStr(corto_float64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_float64Copy(corto_float64* *dst, corto_float64* src);
#define corto_float64Copy(dst, src) _corto_float64Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_float64Compare(corto_float64* dst, corto_float64* src);
#define corto_float64Compare(dst, src) _corto_float64Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_float64Init(corto_float64* value);
#define corto_float64Init(value) _corto_float64Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_float64Deinit(corto_float64* value);
#define corto_float64Deinit(value) _corto_float64Deinit(value)

/* /corto/lang/function */
CORTO_LANG_EXPORT corto_function _corto_functionCreate(corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionCreate(returnType, returnsReference, _impl) _corto_functionCreate(corto_type(returnType), returnsReference, _impl)
CORTO_LANG_EXPORT corto_function _corto_functionCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionCreateChild(_parent, _name, returnType, returnsReference, _impl) _corto_functionCreateChild(_parent, _name, corto_type(returnType), returnsReference, _impl)
CORTO_LANG_EXPORT corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, corto_bool returnsReference);
#define corto_functionUpdate(_this, returnType, returnsReference) _corto_functionUpdate(corto_function(_this), corto_type(returnType), returnsReference)

CORTO_LANG_EXPORT corto_function _corto_functionDeclare(void);
#define corto_functionDeclare() _corto_functionDeclare()
CORTO_LANG_EXPORT corto_function _corto_functionDeclareChild(corto_object _parent, corto_string _name);
#define corto_functionDeclareChild(_parent, _name) _corto_functionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionDefine(_this, returnType, returnsReference, _impl) _corto_functionDefine(corto_function(_this), corto_type(returnType), returnsReference, _impl)
CORTO_LANG_EXPORT void _corto_functionSet(corto_function _this, corto_type returnType, corto_bool returnsReference);
#define corto_functionSet(_this, returnType, returnsReference) _corto_functionSet(corto_function(_this), corto_type(returnType), returnsReference)
CORTO_LANG_EXPORT corto_string _corto_functionStr(corto_function value);
#define corto_functionStr(value) _corto_functionStr(corto_function(value))
CORTO_LANG_EXPORT corto_function corto_functionFromStr(corto_function value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_functionCopy(corto_function *dst, corto_function src);
#define corto_functionCopy(dst, src) _corto_functionCopy(dst, corto_function(src))
CORTO_LANG_EXPORT corto_int16 _corto_functionCompare(corto_function dst, corto_function src);
#define corto_functionCompare(dst, src) _corto_functionCompare(corto_function(dst), corto_function(src))

/* /corto/lang/initAction */
CORTO_LANG_EXPORT corto_initAction* _corto_initActionCreate(corto_object instance, corto_function procedure);
#define corto_initActionCreate(instance, procedure) _corto_initActionCreate(instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_initAction* _corto_initActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_initActionCreateChild(_parent, _name, instance, procedure) _corto_initActionCreateChild(_parent, _name, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_int16 _corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionUpdate(_this, instance, procedure) _corto_initActionUpdate(_this, instance, corto_function(procedure))

CORTO_LANG_EXPORT corto_initAction* _corto_initActionDeclare(void);
#define corto_initActionDeclare() _corto_initActionDeclare()
CORTO_LANG_EXPORT corto_initAction* _corto_initActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_initActionDeclareChild(_parent, _name) _corto_initActionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_initActionDefine(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionDefine(_this, instance, procedure) _corto_initActionDefine(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT void _corto_initActionSet(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionSet(_this, instance, procedure) _corto_initActionSet(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_string _corto_initActionStr(corto_initAction* value);
#define corto_initActionStr(value) _corto_initActionStr(value)
CORTO_LANG_EXPORT corto_initAction* corto_initActionFromStr(corto_initAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_initActionCopy(corto_initAction* *dst, corto_initAction* src);
#define corto_initActionCopy(dst, src) _corto_initActionCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_initActionCompare(corto_initAction* dst, corto_initAction* src);
#define corto_initActionCompare(dst, src) _corto_initActionCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_initActionInit(corto_initAction* value);
#define corto_initActionInit(value) _corto_initActionInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_initActionDeinit(corto_initAction* value);
#define corto_initActionDeinit(value) _corto_initActionDeinit(value)

corto_int16 corto_initActionCall(corto_initAction *_delegate, corto_int16* _result);
/* /corto/lang/int */
CORTO_LANG_EXPORT corto_int _corto_intCreate(corto_width width, corto_int64 min, corto_int64 max);
#define corto_intCreate(width, min, max) _corto_intCreate(width, min, max)
CORTO_LANG_EXPORT corto_int _corto_intCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intCreateChild(_parent, _name, width, min, max) _corto_intCreateChild(_parent, _name, width, min, max)
CORTO_LANG_EXPORT corto_int16 _corto_intUpdate(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intUpdate(_this, width, min, max) _corto_intUpdate(corto_int(_this), width, min, max)

CORTO_LANG_EXPORT corto_int _corto_intDeclare(void);
#define corto_intDeclare() _corto_intDeclare()
CORTO_LANG_EXPORT corto_int _corto_intDeclareChild(corto_object _parent, corto_string _name);
#define corto_intDeclareChild(_parent, _name) _corto_intDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_intDefine(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intDefine(_this, width, min, max) _corto_intDefine(corto_int(_this), width, min, max)
CORTO_LANG_EXPORT void _corto_intSet(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intSet(_this, width, min, max) _corto_intSet(corto_int(_this), width, min, max)
CORTO_LANG_EXPORT corto_string _corto_intStr(corto_int value);
#define corto_intStr(value) _corto_intStr(corto_int(value))
CORTO_LANG_EXPORT corto_int corto_intFromStr(corto_int value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_intCopy(corto_int *dst, corto_int src);
#define corto_intCopy(dst, src) _corto_intCopy(dst, corto_int(src))
CORTO_LANG_EXPORT corto_int16 _corto_intCompare(corto_int dst, corto_int src);
#define corto_intCompare(dst, src) _corto_intCompare(corto_int(dst), corto_int(src))

/* /corto/lang/int16 */
CORTO_LANG_EXPORT corto_int16* _corto_int16Create(corto_int16 value);
#define corto_int16Create(value) _corto_int16Create(value)
CORTO_LANG_EXPORT corto_int16* _corto_int16CreateChild(corto_object _parent, corto_string _name, corto_int16 value);
#define corto_int16CreateChild(_parent, _name, value) _corto_int16CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_int16Update(corto_int16* _this, corto_int16 value);
#define corto_int16Update(_this, value) _corto_int16Update(_this, value)

CORTO_LANG_EXPORT corto_int16* _corto_int16Declare(void);
#define corto_int16Declare() _corto_int16Declare()
CORTO_LANG_EXPORT corto_int16* _corto_int16DeclareChild(corto_object _parent, corto_string _name);
#define corto_int16DeclareChild(_parent, _name) _corto_int16DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_int16Define(corto_int16* _this, corto_int16 value);
#define corto_int16Define(_this, value) _corto_int16Define(_this, value)
CORTO_LANG_EXPORT void _corto_int16Set(corto_int16* _this, corto_int16 value);
#define corto_int16Set(_this, value) _corto_int16Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_int16Str(corto_int16 value);
#define corto_int16Str(value) _corto_int16Str(value)
CORTO_LANG_EXPORT corto_int16* corto_int16FromStr(corto_int16* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_int16Copy(corto_int16* *dst, corto_int16* src);
#define corto_int16Copy(dst, src) _corto_int16Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_int16Compare(corto_int16* dst, corto_int16* src);
#define corto_int16Compare(dst, src) _corto_int16Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_int16Init(corto_int16* value);
#define corto_int16Init(value) _corto_int16Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_int16Deinit(corto_int16* value);
#define corto_int16Deinit(value) _corto_int16Deinit(value)

/* /corto/lang/int32 */
CORTO_LANG_EXPORT corto_int32* _corto_int32Create(corto_int32 value);
#define corto_int32Create(value) _corto_int32Create(value)
CORTO_LANG_EXPORT corto_int32* _corto_int32CreateChild(corto_object _parent, corto_string _name, corto_int32 value);
#define corto_int32CreateChild(_parent, _name, value) _corto_int32CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_int32Update(corto_int32* _this, corto_int32 value);
#define corto_int32Update(_this, value) _corto_int32Update(_this, value)

CORTO_LANG_EXPORT corto_int32* _corto_int32Declare(void);
#define corto_int32Declare() _corto_int32Declare()
CORTO_LANG_EXPORT corto_int32* _corto_int32DeclareChild(corto_object _parent, corto_string _name);
#define corto_int32DeclareChild(_parent, _name) _corto_int32DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_int32Define(corto_int32* _this, corto_int32 value);
#define corto_int32Define(_this, value) _corto_int32Define(_this, value)
CORTO_LANG_EXPORT void _corto_int32Set(corto_int32* _this, corto_int32 value);
#define corto_int32Set(_this, value) _corto_int32Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_int32Str(corto_int32 value);
#define corto_int32Str(value) _corto_int32Str(value)
CORTO_LANG_EXPORT corto_int32* corto_int32FromStr(corto_int32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_int32Copy(corto_int32* *dst, corto_int32* src);
#define corto_int32Copy(dst, src) _corto_int32Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_int32Compare(corto_int32* dst, corto_int32* src);
#define corto_int32Compare(dst, src) _corto_int32Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_int32Init(corto_int32* value);
#define corto_int32Init(value) _corto_int32Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_int32Deinit(corto_int32* value);
#define corto_int32Deinit(value) _corto_int32Deinit(value)

/* /corto/lang/int64 */
CORTO_LANG_EXPORT corto_int64* _corto_int64Create(corto_int64 value);
#define corto_int64Create(value) _corto_int64Create(value)
CORTO_LANG_EXPORT corto_int64* _corto_int64CreateChild(corto_object _parent, corto_string _name, corto_int64 value);
#define corto_int64CreateChild(_parent, _name, value) _corto_int64CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_int64Update(corto_int64* _this, corto_int64 value);
#define corto_int64Update(_this, value) _corto_int64Update(_this, value)

CORTO_LANG_EXPORT corto_int64* _corto_int64Declare(void);
#define corto_int64Declare() _corto_int64Declare()
CORTO_LANG_EXPORT corto_int64* _corto_int64DeclareChild(corto_object _parent, corto_string _name);
#define corto_int64DeclareChild(_parent, _name) _corto_int64DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_int64Define(corto_int64* _this, corto_int64 value);
#define corto_int64Define(_this, value) _corto_int64Define(_this, value)
CORTO_LANG_EXPORT void _corto_int64Set(corto_int64* _this, corto_int64 value);
#define corto_int64Set(_this, value) _corto_int64Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_int64Str(corto_int64 value);
#define corto_int64Str(value) _corto_int64Str(value)
CORTO_LANG_EXPORT corto_int64* corto_int64FromStr(corto_int64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_int64Copy(corto_int64* *dst, corto_int64* src);
#define corto_int64Copy(dst, src) _corto_int64Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_int64Compare(corto_int64* dst, corto_int64* src);
#define corto_int64Compare(dst, src) _corto_int64Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_int64Init(corto_int64* value);
#define corto_int64Init(value) _corto_int64Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_int64Deinit(corto_int64* value);
#define corto_int64Deinit(value) _corto_int64Deinit(value)

/* /corto/lang/int8 */
CORTO_LANG_EXPORT corto_int8* _corto_int8Create(corto_int8 value);
#define corto_int8Create(value) _corto_int8Create(value)
CORTO_LANG_EXPORT corto_int8* _corto_int8CreateChild(corto_object _parent, corto_string _name, corto_int8 value);
#define corto_int8CreateChild(_parent, _name, value) _corto_int8CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_int8Update(corto_int8* _this, corto_int8 value);
#define corto_int8Update(_this, value) _corto_int8Update(_this, value)

CORTO_LANG_EXPORT corto_int8* _corto_int8Declare(void);
#define corto_int8Declare() _corto_int8Declare()
CORTO_LANG_EXPORT corto_int8* _corto_int8DeclareChild(corto_object _parent, corto_string _name);
#define corto_int8DeclareChild(_parent, _name) _corto_int8DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_int8Define(corto_int8* _this, corto_int8 value);
#define corto_int8Define(_this, value) _corto_int8Define(_this, value)
CORTO_LANG_EXPORT void _corto_int8Set(corto_int8* _this, corto_int8 value);
#define corto_int8Set(_this, value) _corto_int8Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_int8Str(corto_int8 value);
#define corto_int8Str(value) _corto_int8Str(value)
CORTO_LANG_EXPORT corto_int8* corto_int8FromStr(corto_int8* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_int8Copy(corto_int8* *dst, corto_int8* src);
#define corto_int8Copy(dst, src) _corto_int8Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_int8Compare(corto_int8* dst, corto_int8* src);
#define corto_int8Compare(dst, src) _corto_int8Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_int8Init(corto_int8* value);
#define corto_int8Init(value) _corto_int8Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_int8Deinit(corto_int8* value);
#define corto_int8Deinit(value) _corto_int8Deinit(value)

/* /corto/lang/interface */
CORTO_LANG_EXPORT corto_interface _corto_interfaceCreate(corto_interface base);
#define corto_interfaceCreate(base) _corto_interfaceCreate(corto_interface(base))
CORTO_LANG_EXPORT corto_interface _corto_interfaceCreateChild(corto_object _parent, corto_string _name, corto_interface base);
#define corto_interfaceCreateChild(_parent, _name, base) _corto_interfaceCreateChild(_parent, _name, corto_interface(base))
CORTO_LANG_EXPORT corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base);
#define corto_interfaceUpdate(_this, base) _corto_interfaceUpdate(corto_interface(_this), corto_interface(base))

CORTO_LANG_EXPORT corto_interface _corto_interfaceDeclare(void);
#define corto_interfaceDeclare() _corto_interfaceDeclare()
CORTO_LANG_EXPORT corto_interface _corto_interfaceDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceDeclareChild(_parent, _name) _corto_interfaceDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceDefine(corto_interface _this, corto_interface base);
#define corto_interfaceDefine(_this, base) _corto_interfaceDefine(corto_interface(_this), corto_interface(base))
CORTO_LANG_EXPORT void _corto_interfaceSet(corto_interface _this, corto_interface base);
#define corto_interfaceSet(_this, base) _corto_interfaceSet(corto_interface(_this), corto_interface(base))
CORTO_LANG_EXPORT corto_string _corto_interfaceStr(corto_interface value);
#define corto_interfaceStr(value) _corto_interfaceStr(corto_interface(value))
CORTO_LANG_EXPORT corto_interface corto_interfaceFromStr(corto_interface value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_interfaceCopy(corto_interface *dst, corto_interface src);
#define corto_interfaceCopy(dst, src) _corto_interfaceCopy(dst, corto_interface(src))
CORTO_LANG_EXPORT corto_int16 _corto_interfaceCompare(corto_interface dst, corto_interface src);
#define corto_interfaceCompare(dst, src) _corto_interfaceCompare(corto_interface(dst), corto_interface(src))

/* /corto/lang/interfaceseq */
CORTO_LANG_EXPORT corto_interfaceseq* _corto_interfaceseqCreate(void);
#define corto_interfaceseqCreate() _corto_interfaceseqCreate()
CORTO_LANG_EXPORT corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, corto_string _name);
#define corto_interfaceseqCreateChild(_parent, _name) _corto_interfaceseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_interfaceseq value);
#define corto_interfaceseqUpdate(_this, value) _corto_interfaceseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_interfaceseq* _corto_interfaceseqDeclare(void);
#define corto_interfaceseqDeclare() _corto_interfaceseqDeclare()
CORTO_LANG_EXPORT corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceseqDeclareChild(_parent, _name) _corto_interfaceseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqDefine(corto_interfaceseq* _this, corto_interfaceseq value);
#define corto_interfaceseqDefine(_this, value) _corto_interfaceseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_interfaceseqSet(corto_interfaceseq* _this, corto_interfaceseq value);
#define corto_interfaceseqSet(_this, value) _corto_interfaceseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_interfaceseqStr(corto_interfaceseq value);
#define corto_interfaceseqStr(value) _corto_interfaceseqStr(value)
CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqFromStr(corto_interfaceseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqCopy(corto_interfaceseq* *dst, corto_interfaceseq* src);
#define corto_interfaceseqCopy(dst, src) _corto_interfaceseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqCompare(corto_interfaceseq* dst, corto_interfaceseq* src);
#define corto_interfaceseqCompare(dst, src) _corto_interfaceseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqInit(corto_interfaceseq* value);
#define corto_interfaceseqInit(value) _corto_interfaceseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceseqDeinit(corto_interfaceseq* value);
#define corto_interfaceseqDeinit(value) _corto_interfaceseqDeinit(value)

/* /corto/lang/interfaceVector */
CORTO_LANG_EXPORT corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorCreate(interface, vector) _corto_interfaceVectorCreate(corto_interface(interface), vector)
CORTO_LANG_EXPORT corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, corto_string _name, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorCreateChild(_parent, _name, interface, vector) _corto_interfaceVectorCreateChild(_parent, _name, corto_interface(interface), vector)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorUpdate(_this, interface, vector) _corto_interfaceVectorUpdate(_this, corto_interface(interface), vector)

CORTO_LANG_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclare(void);
#define corto_interfaceVectorDeclare() _corto_interfaceVectorDeclare()
CORTO_LANG_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceVectorDeclareChild(_parent, _name) _corto_interfaceVectorDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorDefine(_this, interface, vector) _corto_interfaceVectorDefine(_this, corto_interface(interface), vector)
CORTO_LANG_EXPORT void _corto_interfaceVectorSet(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorSet(_this, interface, vector) _corto_interfaceVectorSet(_this, corto_interface(interface), vector)
CORTO_LANG_EXPORT corto_string _corto_interfaceVectorStr(corto_interfaceVector* value);
#define corto_interfaceVectorStr(value) _corto_interfaceVectorStr(value)
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorFromStr(corto_interfaceVector* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorCopy(corto_interfaceVector* *dst, corto_interfaceVector* src);
#define corto_interfaceVectorCopy(dst, src) _corto_interfaceVectorCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorCompare(corto_interfaceVector* dst, corto_interfaceVector* src);
#define corto_interfaceVectorCompare(dst, src) _corto_interfaceVectorCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorInit(corto_interfaceVector* value);
#define corto_interfaceVectorInit(value) _corto_interfaceVectorInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorDeinit(corto_interfaceVector* value);
#define corto_interfaceVectorDeinit(value) _corto_interfaceVectorDeinit(value)

/* /corto/lang/interfaceVectorseq */
CORTO_LANG_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreate(void);
#define corto_interfaceVectorseqCreate() _corto_interfaceVectorseqCreate()
CORTO_LANG_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _name);
#define corto_interfaceVectorseqCreateChild(_parent, _name) _corto_interfaceVectorseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);
#define corto_interfaceVectorseqUpdate(_this, value) _corto_interfaceVectorseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclare(void);
#define corto_interfaceVectorseqDeclare() _corto_interfaceVectorseqDeclare()
CORTO_LANG_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceVectorseqDeclareChild(_parent, _name) _corto_interfaceVectorseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);
#define corto_interfaceVectorseqDefine(_this, value) _corto_interfaceVectorseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_interfaceVectorseqSet(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);
#define corto_interfaceVectorseqSet(_this, value) _corto_interfaceVectorseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_interfaceVectorseqStr(corto_interfaceVectorseq value);
#define corto_interfaceVectorseqStr(value) _corto_interfaceVectorseqStr(value)
CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqFromStr(corto_interfaceVectorseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqCopy(corto_interfaceVectorseq* *dst, corto_interfaceVectorseq* src);
#define corto_interfaceVectorseqCopy(dst, src) _corto_interfaceVectorseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqCompare(corto_interfaceVectorseq* dst, corto_interfaceVectorseq* src);
#define corto_interfaceVectorseqCompare(dst, src) _corto_interfaceVectorseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqInit(corto_interfaceVectorseq* value);
#define corto_interfaceVectorseqInit(value) _corto_interfaceVectorseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_interfaceVectorseqDeinit(corto_interfaceVectorseq* value);
#define corto_interfaceVectorseqDeinit(value) _corto_interfaceVectorseqDeinit(value)

/* /corto/lang/invokeAction */
CORTO_LANG_EXPORT corto_invokeAction* _corto_invokeActionCreate(corto_object instance, corto_function procedure);
#define corto_invokeActionCreate(instance, procedure) _corto_invokeActionCreate(instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_invokeAction* _corto_invokeActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_invokeActionCreateChild(_parent, _name, instance, procedure) _corto_invokeActionCreateChild(_parent, _name, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_int16 _corto_invokeActionUpdate(corto_invokeAction* _this, corto_object instance, corto_function procedure);
#define corto_invokeActionUpdate(_this, instance, procedure) _corto_invokeActionUpdate(_this, instance, corto_function(procedure))

CORTO_LANG_EXPORT corto_invokeAction* _corto_invokeActionDeclare(void);
#define corto_invokeActionDeclare() _corto_invokeActionDeclare()
CORTO_LANG_EXPORT corto_invokeAction* _corto_invokeActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_invokeActionDeclareChild(_parent, _name) _corto_invokeActionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_invokeActionDefine(corto_invokeAction* _this, corto_object instance, corto_function procedure);
#define corto_invokeActionDefine(_this, instance, procedure) _corto_invokeActionDefine(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT void _corto_invokeActionSet(corto_invokeAction* _this, corto_object instance, corto_function procedure);
#define corto_invokeActionSet(_this, instance, procedure) _corto_invokeActionSet(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_string _corto_invokeActionStr(corto_invokeAction* value);
#define corto_invokeActionStr(value) _corto_invokeActionStr(value)
CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionFromStr(corto_invokeAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_invokeActionCopy(corto_invokeAction* *dst, corto_invokeAction* src);
#define corto_invokeActionCopy(dst, src) _corto_invokeActionCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_invokeActionCompare(corto_invokeAction* dst, corto_invokeAction* src);
#define corto_invokeActionCompare(dst, src) _corto_invokeActionCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_invokeActionInit(corto_invokeAction* value);
#define corto_invokeActionInit(value) _corto_invokeActionInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_invokeActionDeinit(corto_invokeAction* value);
#define corto_invokeActionDeinit(value) _corto_invokeActionDeinit(value)

corto_int16 corto_invokeActionCall(corto_invokeAction *_delegate, corto_object instance, corto_function function, corto_octetseq args);
/* /corto/lang/invokeEvent */
CORTO_LANG_EXPORT corto_invokeEvent _corto_invokeEventCreate(corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventCreate(replicator, instance, function, args) _corto_invokeEventCreate(corto_replicator(replicator), instance, corto_function(function), args)
CORTO_LANG_EXPORT corto_invokeEvent _corto_invokeEventCreateChild(corto_object _parent, corto_string _name, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventCreateChild(_parent, _name, replicator, instance, function, args) _corto_invokeEventCreateChild(_parent, _name, corto_replicator(replicator), instance, corto_function(function), args)
CORTO_LANG_EXPORT corto_int16 _corto_invokeEventUpdate(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventUpdate(_this, replicator, instance, function, args) _corto_invokeEventUpdate(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)

CORTO_LANG_EXPORT corto_invokeEvent _corto_invokeEventDeclare(void);
#define corto_invokeEventDeclare() _corto_invokeEventDeclare()
CORTO_LANG_EXPORT corto_invokeEvent _corto_invokeEventDeclareChild(corto_object _parent, corto_string _name);
#define corto_invokeEventDeclareChild(_parent, _name) _corto_invokeEventDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_invokeEventDefine(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventDefine(_this, replicator, instance, function, args) _corto_invokeEventDefine(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)
CORTO_LANG_EXPORT void _corto_invokeEventSet(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
#define corto_invokeEventSet(_this, replicator, instance, function, args) _corto_invokeEventSet(corto_invokeEvent(_this), corto_replicator(replicator), instance, corto_function(function), args)
CORTO_LANG_EXPORT corto_string _corto_invokeEventStr(corto_invokeEvent value);
#define corto_invokeEventStr(value) _corto_invokeEventStr(corto_invokeEvent(value))
CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventFromStr(corto_invokeEvent value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_invokeEventCopy(corto_invokeEvent *dst, corto_invokeEvent src);
#define corto_invokeEventCopy(dst, src) _corto_invokeEventCopy(dst, corto_invokeEvent(src))
CORTO_LANG_EXPORT corto_int16 _corto_invokeEventCompare(corto_invokeEvent dst, corto_invokeEvent src);
#define corto_invokeEventCompare(dst, src) _corto_invokeEventCompare(corto_invokeEvent(dst), corto_invokeEvent(src))

/* /corto/lang/iterator */
CORTO_LANG_EXPORT corto_iterator _corto_iteratorCreate(corto_type elementType);
#define corto_iteratorCreate(elementType) _corto_iteratorCreate(corto_type(elementType))
CORTO_LANG_EXPORT corto_iterator _corto_iteratorCreateChild(corto_object _parent, corto_string _name, corto_type elementType);
#define corto_iteratorCreateChild(_parent, _name, elementType) _corto_iteratorCreateChild(_parent, _name, corto_type(elementType))
CORTO_LANG_EXPORT corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType);
#define corto_iteratorUpdate(_this, elementType) _corto_iteratorUpdate(corto_iterator(_this), corto_type(elementType))

CORTO_LANG_EXPORT corto_iterator _corto_iteratorDeclare(void);
#define corto_iteratorDeclare() _corto_iteratorDeclare()
CORTO_LANG_EXPORT corto_iterator _corto_iteratorDeclareChild(corto_object _parent, corto_string _name);
#define corto_iteratorDeclareChild(_parent, _name) _corto_iteratorDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_iteratorDefine(corto_iterator _this, corto_type elementType);
#define corto_iteratorDefine(_this, elementType) _corto_iteratorDefine(corto_iterator(_this), corto_type(elementType))
CORTO_LANG_EXPORT void _corto_iteratorSet(corto_iterator _this, corto_type elementType);
#define corto_iteratorSet(_this, elementType) _corto_iteratorSet(corto_iterator(_this), corto_type(elementType))
CORTO_LANG_EXPORT corto_string _corto_iteratorStr(corto_iterator value);
#define corto_iteratorStr(value) _corto_iteratorStr(corto_iterator(value))
CORTO_LANG_EXPORT corto_iterator corto_iteratorFromStr(corto_iterator value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_iteratorCopy(corto_iterator *dst, corto_iterator src);
#define corto_iteratorCopy(dst, src) _corto_iteratorCopy(dst, corto_iterator(src))
CORTO_LANG_EXPORT corto_int16 _corto_iteratorCompare(corto_iterator dst, corto_iterator src);
#define corto_iteratorCompare(dst, src) _corto_iteratorCompare(corto_iterator(dst), corto_iterator(src))

/* /corto/lang/list */
CORTO_LANG_EXPORT corto_list _corto_listCreate(corto_type elementType, corto_uint32 max);
#define corto_listCreate(elementType, max) _corto_listCreate(corto_type(elementType), max)
CORTO_LANG_EXPORT corto_list _corto_listCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_listCreateChild(_parent, _name, elementType, max) _corto_listCreateChild(_parent, _name, corto_type(elementType), max)
CORTO_LANG_EXPORT corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listUpdate(_this, elementType, max) _corto_listUpdate(corto_list(_this), corto_type(elementType), max)

CORTO_LANG_EXPORT corto_list _corto_listDeclare(void);
#define corto_listDeclare() _corto_listDeclare()
CORTO_LANG_EXPORT corto_list _corto_listDeclareChild(corto_object _parent, corto_string _name);
#define corto_listDeclareChild(_parent, _name) _corto_listDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listDefine(_this, elementType, max) _corto_listDefine(corto_list(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT void _corto_listSet(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listSet(_this, elementType, max) _corto_listSet(corto_list(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT corto_string _corto_listStr(corto_list value);
#define corto_listStr(value) _corto_listStr(corto_list(value))
CORTO_LANG_EXPORT corto_list corto_listFromStr(corto_list value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_listCopy(corto_list *dst, corto_list src);
#define corto_listCopy(dst, src) _corto_listCopy(dst, corto_list(src))
CORTO_LANG_EXPORT corto_int16 _corto_listCompare(corto_list dst, corto_list src);
#define corto_listCompare(dst, src) _corto_listCompare(corto_list(dst), corto_list(src))

/* /corto/lang/map */
CORTO_LANG_EXPORT corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapCreate(elementType, keyType, max) _corto_mapCreate(corto_type(elementType), corto_type(keyType), max)
CORTO_LANG_EXPORT corto_map _corto_mapCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapCreateChild(_parent, _name, elementType, keyType, max) _corto_mapCreateChild(_parent, _name, corto_type(elementType), corto_type(keyType), max)
CORTO_LANG_EXPORT corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapUpdate(_this, elementType, keyType, max) _corto_mapUpdate(corto_map(_this), corto_type(elementType), corto_type(keyType), max)

CORTO_LANG_EXPORT corto_map _corto_mapDeclare(void);
#define corto_mapDeclare() _corto_mapDeclare()
CORTO_LANG_EXPORT corto_map _corto_mapDeclareChild(corto_object _parent, corto_string _name);
#define corto_mapDeclareChild(_parent, _name) _corto_mapDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapDefine(_this, elementType, keyType, max) _corto_mapDefine(corto_map(_this), corto_type(elementType), corto_type(keyType), max)
CORTO_LANG_EXPORT void _corto_mapSet(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapSet(_this, elementType, keyType, max) _corto_mapSet(corto_map(_this), corto_type(elementType), corto_type(keyType), max)
CORTO_LANG_EXPORT corto_string _corto_mapStr(corto_map value);
#define corto_mapStr(value) _corto_mapStr(corto_map(value))
CORTO_LANG_EXPORT corto_map corto_mapFromStr(corto_map value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_mapCopy(corto_map *dst, corto_map src);
#define corto_mapCopy(dst, src) _corto_mapCopy(dst, corto_map(src))
CORTO_LANG_EXPORT corto_int16 _corto_mapCompare(corto_map dst, corto_map src);
#define corto_mapCompare(dst, src) _corto_mapCompare(corto_map(dst), corto_map(src))

/* /corto/lang/member */
CORTO_LANG_EXPORT corto_member _corto_memberCreate(corto_type type, corto_modifier modifiers);
#define corto_memberCreate(type, modifiers) _corto_memberCreate(corto_type(type), modifiers)
CORTO_LANG_EXPORT corto_member _corto_memberCreateChild(corto_object _parent, corto_string _name, corto_type type, corto_modifier modifiers);
#define corto_memberCreateChild(_parent, _name, type, modifiers) _corto_memberCreateChild(_parent, _name, corto_type(type), modifiers)
CORTO_LANG_EXPORT corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberUpdate(_this, type, modifiers) _corto_memberUpdate(corto_member(_this), corto_type(type), modifiers)

CORTO_LANG_EXPORT corto_member _corto_memberDeclare(void);
#define corto_memberDeclare() _corto_memberDeclare()
CORTO_LANG_EXPORT corto_member _corto_memberDeclareChild(corto_object _parent, corto_string _name);
#define corto_memberDeclareChild(_parent, _name) _corto_memberDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberDefine(_this, type, modifiers) _corto_memberDefine(corto_member(_this), corto_type(type), modifiers)
CORTO_LANG_EXPORT void _corto_memberSet(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberSet(_this, type, modifiers) _corto_memberSet(corto_member(_this), corto_type(type), modifiers)
CORTO_LANG_EXPORT corto_string _corto_memberStr(corto_member value);
#define corto_memberStr(value) _corto_memberStr(corto_member(value))
CORTO_LANG_EXPORT corto_member corto_memberFromStr(corto_member value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_memberCopy(corto_member *dst, corto_member src);
#define corto_memberCopy(dst, src) _corto_memberCopy(dst, corto_member(src))
CORTO_LANG_EXPORT corto_int16 _corto_memberCompare(corto_member dst, corto_member src);
#define corto_memberCompare(dst, src) _corto_memberCompare(corto_member(dst), corto_member(src))

/* /corto/lang/memberseq */
CORTO_LANG_EXPORT corto_memberseq* _corto_memberseqCreate(void);
#define corto_memberseqCreate() _corto_memberseqCreate()
CORTO_LANG_EXPORT corto_memberseq* _corto_memberseqCreateChild(corto_object _parent, corto_string _name);
#define corto_memberseqCreateChild(_parent, _name) _corto_memberseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_memberseqUpdate(corto_memberseq* _this, corto_memberseq value);
#define corto_memberseqUpdate(_this, value) _corto_memberseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_memberseq* _corto_memberseqDeclare(void);
#define corto_memberseqDeclare() _corto_memberseqDeclare()
CORTO_LANG_EXPORT corto_memberseq* _corto_memberseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_memberseqDeclareChild(_parent, _name) _corto_memberseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_memberseqDefine(corto_memberseq* _this, corto_memberseq value);
#define corto_memberseqDefine(_this, value) _corto_memberseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_memberseqSet(corto_memberseq* _this, corto_memberseq value);
#define corto_memberseqSet(_this, value) _corto_memberseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_memberseqStr(corto_memberseq value);
#define corto_memberseqStr(value) _corto_memberseqStr(value)
CORTO_LANG_EXPORT corto_memberseq* corto_memberseqFromStr(corto_memberseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_memberseqCopy(corto_memberseq* *dst, corto_memberseq* src);
#define corto_memberseqCopy(dst, src) _corto_memberseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_memberseqCompare(corto_memberseq* dst, corto_memberseq* src);
#define corto_memberseqCompare(dst, src) _corto_memberseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_memberseqInit(corto_memberseq* value);
#define corto_memberseqInit(value) _corto_memberseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_memberseqDeinit(corto_memberseq* value);
#define corto_memberseqDeinit(value) _corto_memberseqDeinit(value)

/* /corto/lang/metaprocedure */
CORTO_LANG_EXPORT corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureCreate(returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreate(corto_type(returnType), returnsReference, referenceOnly, _impl)
CORTO_LANG_EXPORT corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureCreateChild(_parent, _name, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreateChild(_parent, _name, corto_type(returnType), returnsReference, referenceOnly, _impl)
CORTO_LANG_EXPORT corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly);
#define corto_metaprocedureUpdate(_this, returnType, returnsReference, referenceOnly) _corto_metaprocedureUpdate(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly)

CORTO_LANG_EXPORT corto_metaprocedure _corto_metaprocedureDeclare(void);
#define corto_metaprocedureDeclare() _corto_metaprocedureDeclare()
CORTO_LANG_EXPORT corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, corto_string _name);
#define corto_metaprocedureDeclareChild(_parent, _name) _corto_metaprocedureDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureDefine(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureDefine(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, _impl)
CORTO_LANG_EXPORT void _corto_metaprocedureSet(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly);
#define corto_metaprocedureSet(_this, returnType, returnsReference, referenceOnly) _corto_metaprocedureSet(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly)
CORTO_LANG_EXPORT corto_string _corto_metaprocedureStr(corto_metaprocedure value);
#define corto_metaprocedureStr(value) _corto_metaprocedureStr(corto_metaprocedure(value))
CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureFromStr(corto_metaprocedure value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_metaprocedureCopy(corto_metaprocedure *dst, corto_metaprocedure src);
#define corto_metaprocedureCopy(dst, src) _corto_metaprocedureCopy(dst, corto_metaprocedure(src))
CORTO_LANG_EXPORT corto_int16 _corto_metaprocedureCompare(corto_metaprocedure dst, corto_metaprocedure src);
#define corto_metaprocedureCompare(dst, src) _corto_metaprocedureCompare(corto_metaprocedure(dst), corto_metaprocedure(src))

/* /corto/lang/method */
CORTO_LANG_EXPORT corto_method _corto_methodCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodCreate(returnType, returnsReference, _virtual, _impl) _corto_methodCreate(corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT corto_method _corto_methodCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodCreateChild(_parent, _name, returnType, returnsReference, _virtual, _impl) _corto_methodCreateChild(_parent, _name, corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
#define corto_methodUpdate(_this, returnType, returnsReference, _virtual) _corto_methodUpdate(corto_method(_this), corto_type(returnType), returnsReference, _virtual)

CORTO_LANG_EXPORT corto_method _corto_methodDeclare(void);
#define corto_methodDeclare() _corto_methodDeclare()
CORTO_LANG_EXPORT corto_method _corto_methodDeclareChild(corto_object _parent, corto_string _name);
#define corto_methodDeclareChild(_parent, _name) _corto_methodDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodDefine(_this, returnType, returnsReference, _virtual, _impl) _corto_methodDefine(corto_method(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT void _corto_methodSet(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
#define corto_methodSet(_this, returnType, returnsReference, _virtual) _corto_methodSet(corto_method(_this), corto_type(returnType), returnsReference, _virtual)
CORTO_LANG_EXPORT corto_string _corto_methodStr(corto_method value);
#define corto_methodStr(value) _corto_methodStr(corto_method(value))
CORTO_LANG_EXPORT corto_method corto_methodFromStr(corto_method value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_methodCopy(corto_method *dst, corto_method src);
#define corto_methodCopy(dst, src) _corto_methodCopy(dst, corto_method(src))
CORTO_LANG_EXPORT corto_int16 _corto_methodCompare(corto_method dst, corto_method src);
#define corto_methodCompare(dst, src) _corto_methodCompare(corto_method(dst), corto_method(src))

/* /corto/lang/modifier */
CORTO_LANG_EXPORT corto_modifier* _corto_modifierCreate(corto_modifier value);
#define corto_modifierCreate(value) _corto_modifierCreate(value)
CORTO_LANG_EXPORT corto_modifier* _corto_modifierCreateChild(corto_object _parent, corto_string _name, corto_modifier value);
#define corto_modifierCreateChild(_parent, _name, value) _corto_modifierCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value);
#define corto_modifierUpdate(_this, value) _corto_modifierUpdate(_this, value)

CORTO_LANG_EXPORT corto_modifier* _corto_modifierDeclare(void);
#define corto_modifierDeclare() _corto_modifierDeclare()
CORTO_LANG_EXPORT corto_modifier* _corto_modifierDeclareChild(corto_object _parent, corto_string _name);
#define corto_modifierDeclareChild(_parent, _name) _corto_modifierDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_modifierDefine(corto_modifier* _this, corto_modifier value);
#define corto_modifierDefine(_this, value) _corto_modifierDefine(_this, value)
CORTO_LANG_EXPORT void _corto_modifierSet(corto_modifier* _this, corto_modifier value);
#define corto_modifierSet(_this, value) _corto_modifierSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_modifierStr(corto_modifier value);
#define corto_modifierStr(value) _corto_modifierStr(value)
CORTO_LANG_EXPORT corto_modifier* corto_modifierFromStr(corto_modifier* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_modifierCopy(corto_modifier* *dst, corto_modifier* src);
#define corto_modifierCopy(dst, src) _corto_modifierCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_modifierCompare(corto_modifier* dst, corto_modifier* src);
#define corto_modifierCompare(dst, src) _corto_modifierCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_modifierInit(corto_modifier* value);
#define corto_modifierInit(value) _corto_modifierInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_modifierDeinit(corto_modifier* value);
#define corto_modifierDeinit(value) _corto_modifierDeinit(value)

/* /corto/lang/notifyAction */
CORTO_LANG_EXPORT corto_notifyAction* _corto_notifyActionCreate(corto_object instance, corto_function procedure);
#define corto_notifyActionCreate(instance, procedure) _corto_notifyActionCreate(instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_notifyAction* _corto_notifyActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_notifyActionCreateChild(_parent, _name, instance, procedure) _corto_notifyActionCreateChild(_parent, _name, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_int16 _corto_notifyActionUpdate(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionUpdate(_this, instance, procedure) _corto_notifyActionUpdate(_this, instance, corto_function(procedure))

CORTO_LANG_EXPORT corto_notifyAction* _corto_notifyActionDeclare(void);
#define corto_notifyActionDeclare() _corto_notifyActionDeclare()
CORTO_LANG_EXPORT corto_notifyAction* _corto_notifyActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_notifyActionDeclareChild(_parent, _name) _corto_notifyActionDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_notifyActionDefine(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionDefine(_this, instance, procedure) _corto_notifyActionDefine(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT void _corto_notifyActionSet(corto_notifyAction* _this, corto_object instance, corto_function procedure);
#define corto_notifyActionSet(_this, instance, procedure) _corto_notifyActionSet(_this, instance, corto_function(procedure))
CORTO_LANG_EXPORT corto_string _corto_notifyActionStr(corto_notifyAction* value);
#define corto_notifyActionStr(value) _corto_notifyActionStr(value)
CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_notifyActionCopy(corto_notifyAction* *dst, corto_notifyAction* src);
#define corto_notifyActionCopy(dst, src) _corto_notifyActionCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src);
#define corto_notifyActionCompare(dst, src) _corto_notifyActionCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_notifyActionInit(corto_notifyAction* value);
#define corto_notifyActionInit(value) _corto_notifyActionInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_notifyActionDeinit(corto_notifyAction* value);
#define corto_notifyActionDeinit(value) _corto_notifyActionDeinit(value)

corto_int16 corto_notifyActionCall(corto_notifyAction *_delegate, corto_object observable);
/* /corto/lang/object */
CORTO_LANG_EXPORT corto_object _corto_objectCreate(void);
#define corto_objectCreate() _corto_objectCreate()
CORTO_LANG_EXPORT corto_object _corto_objectCreateChild(corto_object _parent, corto_string _name);
#define corto_objectCreateChild(_parent, _name) _corto_objectCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_objectUpdate(corto_object _this);
#define corto_objectUpdate(_this) _corto_objectUpdate(_this)

/* /corto/lang/objectseq */
CORTO_LANG_EXPORT corto_objectseq* _corto_objectseqCreate(void);
#define corto_objectseqCreate() _corto_objectseqCreate()
CORTO_LANG_EXPORT corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, corto_string _name);
#define corto_objectseqCreateChild(_parent, _name) _corto_objectseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_objectseq value);
#define corto_objectseqUpdate(_this, value) _corto_objectseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_objectseq* _corto_objectseqDeclare(void);
#define corto_objectseqDeclare() _corto_objectseqDeclare()
CORTO_LANG_EXPORT corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_objectseqDeclareChild(_parent, _name) _corto_objectseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_objectseqDefine(corto_objectseq* _this, corto_objectseq value);
#define corto_objectseqDefine(_this, value) _corto_objectseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_objectseqSet(corto_objectseq* _this, corto_objectseq value);
#define corto_objectseqSet(_this, value) _corto_objectseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_objectseqStr(corto_objectseq value);
#define corto_objectseqStr(value) _corto_objectseqStr(value)
CORTO_LANG_EXPORT corto_objectseq* corto_objectseqFromStr(corto_objectseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_objectseqCopy(corto_objectseq* *dst, corto_objectseq* src);
#define corto_objectseqCopy(dst, src) _corto_objectseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_objectseqCompare(corto_objectseq* dst, corto_objectseq* src);
#define corto_objectseqCompare(dst, src) _corto_objectseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_objectseqInit(corto_objectseq* value);
#define corto_objectseqInit(value) _corto_objectseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_objectseqDeinit(corto_objectseq* value);
#define corto_objectseqDeinit(value) _corto_objectseqDeinit(value)

/* /corto/lang/observableEvent */
CORTO_LANG_EXPORT corto_observableEvent _corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable);
#define corto_observableEventCreate(observer, me, source, observable) _corto_observableEventCreate(corto_observer(observer), me, source, observable)
CORTO_LANG_EXPORT corto_observableEvent _corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable);
#define corto_observableEventCreateChild(_parent, _name, observer, me, source, observable) _corto_observableEventCreateChild(_parent, _name, corto_observer(observer), me, source, observable)
CORTO_LANG_EXPORT corto_int16 _corto_observableEventUpdate(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);
#define corto_observableEventUpdate(_this, observer, me, source, observable) _corto_observableEventUpdate(corto_observableEvent(_this), corto_observer(observer), me, source, observable)

CORTO_LANG_EXPORT corto_observableEvent _corto_observableEventDeclare(void);
#define corto_observableEventDeclare() _corto_observableEventDeclare()
CORTO_LANG_EXPORT corto_observableEvent _corto_observableEventDeclareChild(corto_object _parent, corto_string _name);
#define corto_observableEventDeclareChild(_parent, _name) _corto_observableEventDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_observableEventDefine(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);
#define corto_observableEventDefine(_this, observer, me, source, observable) _corto_observableEventDefine(corto_observableEvent(_this), corto_observer(observer), me, source, observable)
CORTO_LANG_EXPORT void _corto_observableEventSet(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);
#define corto_observableEventSet(_this, observer, me, source, observable) _corto_observableEventSet(corto_observableEvent(_this), corto_observer(observer), me, source, observable)
CORTO_LANG_EXPORT corto_string _corto_observableEventStr(corto_observableEvent value);
#define corto_observableEventStr(value) _corto_observableEventStr(corto_observableEvent(value))
CORTO_LANG_EXPORT corto_observableEvent corto_observableEventFromStr(corto_observableEvent value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_observableEventCopy(corto_observableEvent *dst, corto_observableEvent src);
#define corto_observableEventCopy(dst, src) _corto_observableEventCopy(dst, corto_observableEvent(src))
CORTO_LANG_EXPORT corto_int16 _corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src);
#define corto_observableEventCompare(dst, src) _corto_observableEventCompare(corto_observableEvent(dst), corto_observableEvent(src))

/* /corto/lang/observer */
CORTO_LANG_EXPORT corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerCreate(mask, observable, _impl) _corto_observerCreate(mask, observable, _impl)
CORTO_LANG_EXPORT corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _name, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerCreateChild(_parent, _name, mask, observable, _impl) _corto_observerCreateChild(_parent, _name, mask, observable, _impl)
CORTO_LANG_EXPORT corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable);
#define corto_observerUpdate(_this, mask, observable) _corto_observerUpdate(corto_observer(_this), mask, observable)

CORTO_LANG_EXPORT corto_observer _corto_observerDeclare(void);
#define corto_observerDeclare() _corto_observerDeclare()
CORTO_LANG_EXPORT corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _name);
#define corto_observerDeclareChild(_parent, _name) _corto_observerDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
#define corto_observerDefine(_this, mask, observable, _impl) _corto_observerDefine(corto_observer(_this), mask, observable, _impl)
CORTO_LANG_EXPORT void _corto_observerSet(corto_observer _this, corto_eventMask mask, corto_object observable);
#define corto_observerSet(_this, mask, observable) _corto_observerSet(corto_observer(_this), mask, observable)
CORTO_LANG_EXPORT corto_string _corto_observerStr(corto_observer value);
#define corto_observerStr(value) _corto_observerStr(corto_observer(value))
CORTO_LANG_EXPORT corto_observer corto_observerFromStr(corto_observer value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_observerCopy(corto_observer *dst, corto_observer src);
#define corto_observerCopy(dst, src) _corto_observerCopy(dst, corto_observer(src))
CORTO_LANG_EXPORT corto_int16 _corto_observerCompare(corto_observer dst, corto_observer src);
#define corto_observerCompare(dst, src) _corto_observerCompare(corto_observer(dst), corto_observer(src))

/* /corto/lang/observerseq */
CORTO_LANG_EXPORT corto_observerseq* _corto_observerseqCreate(void);
#define corto_observerseqCreate() _corto_observerseqCreate()
CORTO_LANG_EXPORT corto_observerseq* _corto_observerseqCreateChild(corto_object _parent, corto_string _name);
#define corto_observerseqCreateChild(_parent, _name) _corto_observerseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_observerseqUpdate(corto_observerseq* _this, corto_observerseq value);
#define corto_observerseqUpdate(_this, value) _corto_observerseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_observerseq* _corto_observerseqDeclare(void);
#define corto_observerseqDeclare() _corto_observerseqDeclare()
CORTO_LANG_EXPORT corto_observerseq* _corto_observerseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_observerseqDeclareChild(_parent, _name) _corto_observerseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_observerseqDefine(corto_observerseq* _this, corto_observerseq value);
#define corto_observerseqDefine(_this, value) _corto_observerseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_observerseqSet(corto_observerseq* _this, corto_observerseq value);
#define corto_observerseqSet(_this, value) _corto_observerseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_observerseqStr(corto_observerseq value);
#define corto_observerseqStr(value) _corto_observerseqStr(value)
CORTO_LANG_EXPORT corto_observerseq* corto_observerseqFromStr(corto_observerseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_observerseqCopy(corto_observerseq* *dst, corto_observerseq* src);
#define corto_observerseqCopy(dst, src) _corto_observerseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_observerseqCompare(corto_observerseq* dst, corto_observerseq* src);
#define corto_observerseqCompare(dst, src) _corto_observerseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_observerseqInit(corto_observerseq* value);
#define corto_observerseqInit(value) _corto_observerseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_observerseqDeinit(corto_observerseq* value);
#define corto_observerseqDeinit(value) _corto_observerseqDeinit(value)

/* /corto/lang/octet */
CORTO_LANG_EXPORT corto_octet* _corto_octetCreate(corto_octet value);
#define corto_octetCreate(value) _corto_octetCreate(value)
CORTO_LANG_EXPORT corto_octet* _corto_octetCreateChild(corto_object _parent, corto_string _name, corto_octet value);
#define corto_octetCreateChild(_parent, _name, value) _corto_octetCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_octetUpdate(corto_octet* _this, corto_octet value);
#define corto_octetUpdate(_this, value) _corto_octetUpdate(_this, value)

CORTO_LANG_EXPORT corto_octet* _corto_octetDeclare(void);
#define corto_octetDeclare() _corto_octetDeclare()
CORTO_LANG_EXPORT corto_octet* _corto_octetDeclareChild(corto_object _parent, corto_string _name);
#define corto_octetDeclareChild(_parent, _name) _corto_octetDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_octetDefine(corto_octet* _this, corto_octet value);
#define corto_octetDefine(_this, value) _corto_octetDefine(_this, value)
CORTO_LANG_EXPORT void _corto_octetSet(corto_octet* _this, corto_octet value);
#define corto_octetSet(_this, value) _corto_octetSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_octetStr(corto_octet value);
#define corto_octetStr(value) _corto_octetStr(value)
CORTO_LANG_EXPORT corto_octet* corto_octetFromStr(corto_octet* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_octetCopy(corto_octet* *dst, corto_octet* src);
#define corto_octetCopy(dst, src) _corto_octetCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_octetCompare(corto_octet* dst, corto_octet* src);
#define corto_octetCompare(dst, src) _corto_octetCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_octetInit(corto_octet* value);
#define corto_octetInit(value) _corto_octetInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_octetDeinit(corto_octet* value);
#define corto_octetDeinit(value) _corto_octetDeinit(value)

/* /corto/lang/octetseq */
CORTO_LANG_EXPORT corto_octetseq* _corto_octetseqCreate(void);
#define corto_octetseqCreate() _corto_octetseqCreate()
CORTO_LANG_EXPORT corto_octetseq* _corto_octetseqCreateChild(corto_object _parent, corto_string _name);
#define corto_octetseqCreateChild(_parent, _name) _corto_octetseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_octetseqUpdate(corto_octetseq* _this, corto_octetseq value);
#define corto_octetseqUpdate(_this, value) _corto_octetseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_octetseq* _corto_octetseqDeclare(void);
#define corto_octetseqDeclare() _corto_octetseqDeclare()
CORTO_LANG_EXPORT corto_octetseq* _corto_octetseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_octetseqDeclareChild(_parent, _name) _corto_octetseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_octetseqDefine(corto_octetseq* _this, corto_octetseq value);
#define corto_octetseqDefine(_this, value) _corto_octetseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_octetseqSet(corto_octetseq* _this, corto_octetseq value);
#define corto_octetseqSet(_this, value) _corto_octetseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_octetseqStr(corto_octetseq value);
#define corto_octetseqStr(value) _corto_octetseqStr(value)
CORTO_LANG_EXPORT corto_octetseq* corto_octetseqFromStr(corto_octetseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_octetseqCopy(corto_octetseq* *dst, corto_octetseq* src);
#define corto_octetseqCopy(dst, src) _corto_octetseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_octetseqCompare(corto_octetseq* dst, corto_octetseq* src);
#define corto_octetseqCompare(dst, src) _corto_octetseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_octetseqInit(corto_octetseq* value);
#define corto_octetseqInit(value) _corto_octetseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_octetseqDeinit(corto_octetseq* value);
#define corto_octetseqDeinit(value) _corto_octetseqDeinit(value)

/* /corto/lang/operatorKind */
CORTO_LANG_EXPORT corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value);
#define corto_operatorKindCreate(value) _corto_operatorKindCreate(value)
CORTO_LANG_EXPORT corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _name, corto_operatorKind value);
#define corto_operatorKindCreateChild(_parent, _name, value) _corto_operatorKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindUpdate(_this, value) _corto_operatorKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_operatorKind* _corto_operatorKindDeclare(void);
#define corto_operatorKindDeclare() _corto_operatorKindDeclare()
CORTO_LANG_EXPORT corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_operatorKindDeclareChild(_parent, _name) _corto_operatorKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindDefine(_this, value) _corto_operatorKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_operatorKindSet(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindSet(_this, value) _corto_operatorKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_operatorKindStr(corto_operatorKind value);
#define corto_operatorKindStr(value) _corto_operatorKindStr(value)
CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindFromStr(corto_operatorKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_operatorKindCopy(corto_operatorKind* *dst, corto_operatorKind* src);
#define corto_operatorKindCopy(dst, src) _corto_operatorKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_operatorKindCompare(corto_operatorKind* dst, corto_operatorKind* src);
#define corto_operatorKindCompare(dst, src) _corto_operatorKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_operatorKindInit(corto_operatorKind* value);
#define corto_operatorKindInit(value) _corto_operatorKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_operatorKindDeinit(corto_operatorKind* value);
#define corto_operatorKindDeinit(value) _corto_operatorKindDeinit(value)

/* /corto/lang/package */
CORTO_LANG_EXPORT corto_package _corto_packageCreate(corto_string url);
#define corto_packageCreate(url) _corto_packageCreate(url)
CORTO_LANG_EXPORT corto_package _corto_packageCreateChild(corto_object _parent, corto_string _name, corto_string url);
#define corto_packageCreateChild(_parent, _name, url) _corto_packageCreateChild(_parent, _name, url)
CORTO_LANG_EXPORT corto_int16 _corto_packageUpdate(corto_package _this, corto_string url);
#define corto_packageUpdate(_this, url) _corto_packageUpdate(corto_package(_this), url)

CORTO_LANG_EXPORT corto_package _corto_packageDeclare(void);
#define corto_packageDeclare() _corto_packageDeclare()
CORTO_LANG_EXPORT corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _name);
#define corto_packageDeclareChild(_parent, _name) _corto_packageDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_packageDefine(corto_package _this, corto_string url);
#define corto_packageDefine(_this, url) _corto_packageDefine(corto_package(_this), url)
CORTO_LANG_EXPORT void _corto_packageSet(corto_package _this, corto_string url);
#define corto_packageSet(_this, url) _corto_packageSet(corto_package(_this), url)
CORTO_LANG_EXPORT corto_string _corto_packageStr(corto_package value);
#define corto_packageStr(value) _corto_packageStr(corto_package(value))
CORTO_LANG_EXPORT corto_package corto_packageFromStr(corto_package value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_packageCopy(corto_package *dst, corto_package src);
#define corto_packageCopy(dst, src) _corto_packageCopy(dst, corto_package(src))
CORTO_LANG_EXPORT corto_int16 _corto_packageCompare(corto_package dst, corto_package src);
#define corto_packageCompare(dst, src) _corto_packageCompare(corto_package(dst), corto_package(src))

/* /corto/lang/parameter */
CORTO_LANG_EXPORT corto_parameter* _corto_parameterCreate(corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterCreate(name, type, passByReference) _corto_parameterCreate(name, corto_type(type), passByReference)
CORTO_LANG_EXPORT corto_parameter* _corto_parameterCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterCreateChild(_parent, _name, name, type, passByReference) _corto_parameterCreateChild(_parent, _name, name, corto_type(type), passByReference)
CORTO_LANG_EXPORT corto_int16 _corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterUpdate(_this, name, type, passByReference) _corto_parameterUpdate(_this, name, corto_type(type), passByReference)

CORTO_LANG_EXPORT corto_parameter* _corto_parameterDeclare(void);
#define corto_parameterDeclare() _corto_parameterDeclare()
CORTO_LANG_EXPORT corto_parameter* _corto_parameterDeclareChild(corto_object _parent, corto_string _name);
#define corto_parameterDeclareChild(_parent, _name) _corto_parameterDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterDefine(_this, name, type, passByReference) _corto_parameterDefine(_this, name, corto_type(type), passByReference)
CORTO_LANG_EXPORT void _corto_parameterSet(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterSet(_this, name, type, passByReference) _corto_parameterSet(_this, name, corto_type(type), passByReference)
CORTO_LANG_EXPORT corto_string _corto_parameterStr(corto_parameter* value);
#define corto_parameterStr(value) _corto_parameterStr(value)
CORTO_LANG_EXPORT corto_parameter* corto_parameterFromStr(corto_parameter* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_parameterCopy(corto_parameter* *dst, corto_parameter* src);
#define corto_parameterCopy(dst, src) _corto_parameterCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_parameterCompare(corto_parameter* dst, corto_parameter* src);
#define corto_parameterCompare(dst, src) _corto_parameterCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_parameterInit(corto_parameter* value);
#define corto_parameterInit(value) _corto_parameterInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_parameterDeinit(corto_parameter* value);
#define corto_parameterDeinit(value) _corto_parameterDeinit(value)

/* /corto/lang/parameterseq */
CORTO_LANG_EXPORT corto_parameterseq* _corto_parameterseqCreate(void);
#define corto_parameterseqCreate() _corto_parameterseqCreate()
CORTO_LANG_EXPORT corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, corto_string _name);
#define corto_parameterseqCreateChild(_parent, _name) _corto_parameterseqCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_parameterseq value);
#define corto_parameterseqUpdate(_this, value) _corto_parameterseqUpdate(_this, value)

CORTO_LANG_EXPORT corto_parameterseq* _corto_parameterseqDeclare(void);
#define corto_parameterseqDeclare() _corto_parameterseqDeclare()
CORTO_LANG_EXPORT corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_parameterseqDeclareChild(_parent, _name) _corto_parameterseqDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_parameterseqDefine(corto_parameterseq* _this, corto_parameterseq value);
#define corto_parameterseqDefine(_this, value) _corto_parameterseqDefine(_this, value)
CORTO_LANG_EXPORT void _corto_parameterseqSet(corto_parameterseq* _this, corto_parameterseq value);
#define corto_parameterseqSet(_this, value) _corto_parameterseqSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_parameterseqStr(corto_parameterseq value);
#define corto_parameterseqStr(value) _corto_parameterseqStr(value)
CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqFromStr(corto_parameterseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_parameterseqCopy(corto_parameterseq* *dst, corto_parameterseq* src);
#define corto_parameterseqCopy(dst, src) _corto_parameterseqCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_parameterseqCompare(corto_parameterseq* dst, corto_parameterseq* src);
#define corto_parameterseqCompare(dst, src) _corto_parameterseqCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_parameterseqInit(corto_parameterseq* value);
#define corto_parameterseqInit(value) _corto_parameterseqInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_parameterseqDeinit(corto_parameterseq* value);
#define corto_parameterseqDeinit(value) _corto_parameterseqDeinit(value)

/* /corto/lang/primitive */
CORTO_LANG_EXPORT corto_primitive _corto_primitiveCreate(corto_width width);
#define corto_primitiveCreate(width) _corto_primitiveCreate(width)
CORTO_LANG_EXPORT corto_primitive _corto_primitiveCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_primitiveCreateChild(_parent, _name, width) _corto_primitiveCreateChild(_parent, _name, width)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width);
#define corto_primitiveUpdate(_this, width) _corto_primitiveUpdate(corto_primitive(_this), width)

CORTO_LANG_EXPORT corto_primitive _corto_primitiveDeclare(void);
#define corto_primitiveDeclare() _corto_primitiveDeclare()
CORTO_LANG_EXPORT corto_primitive _corto_primitiveDeclareChild(corto_object _parent, corto_string _name);
#define corto_primitiveDeclareChild(_parent, _name) _corto_primitiveDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveDefine(corto_primitive _this, corto_width width);
#define corto_primitiveDefine(_this, width) _corto_primitiveDefine(corto_primitive(_this), width)
CORTO_LANG_EXPORT void _corto_primitiveSet(corto_primitive _this, corto_width width);
#define corto_primitiveSet(_this, width) _corto_primitiveSet(corto_primitive(_this), width)
CORTO_LANG_EXPORT corto_string _corto_primitiveStr(corto_primitive value);
#define corto_primitiveStr(value) _corto_primitiveStr(corto_primitive(value))
CORTO_LANG_EXPORT corto_primitive corto_primitiveFromStr(corto_primitive value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_primitiveCopy(corto_primitive *dst, corto_primitive src);
#define corto_primitiveCopy(dst, src) _corto_primitiveCopy(dst, corto_primitive(src))
CORTO_LANG_EXPORT corto_int16 _corto_primitiveCompare(corto_primitive dst, corto_primitive src);
#define corto_primitiveCompare(dst, src) _corto_primitiveCompare(corto_primitive(dst), corto_primitive(src))

/* /corto/lang/primitiveKind */
CORTO_LANG_EXPORT corto_primitiveKind* _corto_primitiveKindCreate(corto_primitiveKind value);
#define corto_primitiveKindCreate(value) _corto_primitiveKindCreate(value)
CORTO_LANG_EXPORT corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, corto_string _name, corto_primitiveKind value);
#define corto_primitiveKindCreateChild(_parent, _name, value) _corto_primitiveKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindUpdate(_this, value) _corto_primitiveKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_primitiveKind* _corto_primitiveKindDeclare(void);
#define corto_primitiveKindDeclare() _corto_primitiveKindDeclare()
CORTO_LANG_EXPORT corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_primitiveKindDeclareChild(_parent, _name) _corto_primitiveKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindDefine(_this, value) _corto_primitiveKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_primitiveKindSet(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindSet(_this, value) _corto_primitiveKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_primitiveKindStr(corto_primitiveKind value);
#define corto_primitiveKindStr(value) _corto_primitiveKindStr(value)
CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindFromStr(corto_primitiveKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindCopy(corto_primitiveKind* *dst, corto_primitiveKind* src);
#define corto_primitiveKindCopy(dst, src) _corto_primitiveKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindCompare(corto_primitiveKind* dst, corto_primitiveKind* src);
#define corto_primitiveKindCompare(dst, src) _corto_primitiveKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindInit(corto_primitiveKind* value);
#define corto_primitiveKindInit(value) _corto_primitiveKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_primitiveKindDeinit(corto_primitiveKind* value);
#define corto_primitiveKindDeinit(value) _corto_primitiveKindDeinit(value)

/* /corto/lang/procedure */
CORTO_LANG_EXPORT corto_procedure _corto_procedureCreate(corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
#define corto_procedureCreate(base, baseAccess, kind) _corto_procedureCreate(corto_interface(base), baseAccess, kind)
CORTO_LANG_EXPORT corto_procedure _corto_procedureCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
#define corto_procedureCreateChild(_parent, _name, base, baseAccess, kind) _corto_procedureCreateChild(_parent, _name, corto_interface(base), baseAccess, kind)
CORTO_LANG_EXPORT corto_int16 _corto_procedureUpdate(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
#define corto_procedureUpdate(_this, base, baseAccess, kind) _corto_procedureUpdate(corto_procedure(_this), corto_interface(base), baseAccess, kind)

CORTO_LANG_EXPORT corto_procedure _corto_procedureDeclare(void);
#define corto_procedureDeclare() _corto_procedureDeclare()
CORTO_LANG_EXPORT corto_procedure _corto_procedureDeclareChild(corto_object _parent, corto_string _name);
#define corto_procedureDeclareChild(_parent, _name) _corto_procedureDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_procedureDefine(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
#define corto_procedureDefine(_this, base, baseAccess, kind) _corto_procedureDefine(corto_procedure(_this), corto_interface(base), baseAccess, kind)
CORTO_LANG_EXPORT void _corto_procedureSet(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
#define corto_procedureSet(_this, base, baseAccess, kind) _corto_procedureSet(corto_procedure(_this), corto_interface(base), baseAccess, kind)
CORTO_LANG_EXPORT corto_string _corto_procedureStr(corto_procedure value);
#define corto_procedureStr(value) _corto_procedureStr(corto_procedure(value))
CORTO_LANG_EXPORT corto_procedure corto_procedureFromStr(corto_procedure value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_procedureCopy(corto_procedure *dst, corto_procedure src);
#define corto_procedureCopy(dst, src) _corto_procedureCopy(dst, corto_procedure(src))
CORTO_LANG_EXPORT corto_int16 _corto_procedureCompare(corto_procedure dst, corto_procedure src);
#define corto_procedureCompare(dst, src) _corto_procedureCompare(corto_procedure(dst), corto_procedure(src))

/* /corto/lang/procedureKind */
CORTO_LANG_EXPORT corto_procedureKind* _corto_procedureKindCreate(corto_procedureKind value);
#define corto_procedureKindCreate(value) _corto_procedureKindCreate(value)
CORTO_LANG_EXPORT corto_procedureKind* _corto_procedureKindCreateChild(corto_object _parent, corto_string _name, corto_procedureKind value);
#define corto_procedureKindCreateChild(_parent, _name, value) _corto_procedureKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_procedureKindUpdate(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindUpdate(_this, value) _corto_procedureKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_procedureKind* _corto_procedureKindDeclare(void);
#define corto_procedureKindDeclare() _corto_procedureKindDeclare()
CORTO_LANG_EXPORT corto_procedureKind* _corto_procedureKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_procedureKindDeclareChild(_parent, _name) _corto_procedureKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_procedureKindDefine(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindDefine(_this, value) _corto_procedureKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_procedureKindSet(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindSet(_this, value) _corto_procedureKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_procedureKindStr(corto_procedureKind value);
#define corto_procedureKindStr(value) _corto_procedureKindStr(value)
CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindFromStr(corto_procedureKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_procedureKindCopy(corto_procedureKind* *dst, corto_procedureKind* src);
#define corto_procedureKindCopy(dst, src) _corto_procedureKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_procedureKindCompare(corto_procedureKind* dst, corto_procedureKind* src);
#define corto_procedureKindCompare(dst, src) _corto_procedureKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_procedureKindInit(corto_procedureKind* value);
#define corto_procedureKindInit(value) _corto_procedureKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_procedureKindDeinit(corto_procedureKind* value);
#define corto_procedureKindDeinit(value) _corto_procedureKindDeinit(value)

/* /corto/lang/query */
CORTO_LANG_EXPORT corto_query _corto_queryCreate(corto_object from, corto_eventMask mask);
#define corto_queryCreate(from, mask) _corto_queryCreate(from, mask)
CORTO_LANG_EXPORT corto_query _corto_queryCreateChild(corto_object _parent, corto_string _name, corto_object from, corto_eventMask mask);
#define corto_queryCreateChild(_parent, _name, from, mask) _corto_queryCreateChild(_parent, _name, from, mask)
CORTO_LANG_EXPORT corto_int16 _corto_queryUpdate(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_queryUpdate(_this, from, mask) _corto_queryUpdate(corto_query(_this), from, mask)

CORTO_LANG_EXPORT corto_query _corto_queryDeclare(void);
#define corto_queryDeclare() _corto_queryDeclare()
CORTO_LANG_EXPORT corto_query _corto_queryDeclareChild(corto_object _parent, corto_string _name);
#define corto_queryDeclareChild(_parent, _name) _corto_queryDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_queryDefine(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_queryDefine(_this, from, mask) _corto_queryDefine(corto_query(_this), from, mask)
CORTO_LANG_EXPORT void _corto_querySet(corto_query _this, corto_object from, corto_eventMask mask);
#define corto_querySet(_this, from, mask) _corto_querySet(corto_query(_this), from, mask)
CORTO_LANG_EXPORT corto_string _corto_queryStr(corto_query value);
#define corto_queryStr(value) _corto_queryStr(corto_query(value))
CORTO_LANG_EXPORT corto_query corto_queryFromStr(corto_query value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_queryCopy(corto_query *dst, corto_query src);
#define corto_queryCopy(dst, src) _corto_queryCopy(dst, corto_query(src))
CORTO_LANG_EXPORT corto_int16 _corto_queryCompare(corto_query dst, corto_query src);
#define corto_queryCompare(dst, src) _corto_queryCompare(corto_query(dst), corto_query(src))

/* /corto/lang/replicator */
CORTO_LANG_EXPORT corto_replicator _corto_replicatorCreate(corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
#define corto_replicatorCreate(mount, query, onDeclare, onUpdate, onDelete, onInvoke) _corto_replicatorCreate(mount, corto_query(query), onDeclare, onUpdate, onDelete, onInvoke)
CORTO_LANG_EXPORT corto_replicator _corto_replicatorCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
#define corto_replicatorCreateChild(_parent, _name, mount, query, onDeclare, onUpdate, onDelete, onInvoke) _corto_replicatorCreateChild(_parent, _name, mount, corto_query(query), onDeclare, onUpdate, onDelete, onInvoke)
CORTO_LANG_EXPORT corto_int16 _corto_replicatorUpdate(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
#define corto_replicatorUpdate(_this, mount, query, onDeclare, onUpdate, onDelete, onInvoke) _corto_replicatorUpdate(corto_replicator(_this), mount, corto_query(query), onDeclare, onUpdate, onDelete, onInvoke)

CORTO_LANG_EXPORT corto_replicator _corto_replicatorDeclare(void);
#define corto_replicatorDeclare() _corto_replicatorDeclare()
CORTO_LANG_EXPORT corto_replicator _corto_replicatorDeclareChild(corto_object _parent, corto_string _name);
#define corto_replicatorDeclareChild(_parent, _name) _corto_replicatorDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_replicatorDefine(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
#define corto_replicatorDefine(_this, mount, query, onDeclare, onUpdate, onDelete, onInvoke) _corto_replicatorDefine(corto_replicator(_this), mount, corto_query(query), onDeclare, onUpdate, onDelete, onInvoke)
CORTO_LANG_EXPORT void _corto_replicatorSet(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
#define corto_replicatorSet(_this, mount, query, onDeclare, onUpdate, onDelete, onInvoke) _corto_replicatorSet(corto_replicator(_this), mount, corto_query(query), onDeclare, onUpdate, onDelete, onInvoke)
CORTO_LANG_EXPORT corto_string _corto_replicatorStr(corto_replicator value);
#define corto_replicatorStr(value) _corto_replicatorStr(corto_replicator(value))
CORTO_LANG_EXPORT corto_replicator corto_replicatorFromStr(corto_replicator value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_replicatorCopy(corto_replicator *dst, corto_replicator src);
#define corto_replicatorCopy(dst, src) _corto_replicatorCopy(dst, corto_replicator(src))
CORTO_LANG_EXPORT corto_int16 _corto_replicatorCompare(corto_replicator dst, corto_replicator src);
#define corto_replicatorCompare(dst, src) _corto_replicatorCompare(corto_replicator(dst), corto_replicator(src))

/* /corto/lang/selectResult */
CORTO_LANG_EXPORT corto_selectResult* _corto_selectResultCreate(corto_string name, corto_string parent, corto_string type);
#define corto_selectResultCreate(name, parent, type) _corto_selectResultCreate(name, parent, type)
CORTO_LANG_EXPORT corto_selectResult* _corto_selectResultCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_string parent, corto_string type);
#define corto_selectResultCreateChild(_parent, _name, name, parent, type) _corto_selectResultCreateChild(_parent, _name, name, parent, type)
CORTO_LANG_EXPORT corto_int16 _corto_selectResultUpdate(corto_selectResult* _this, corto_string name, corto_string parent, corto_string type);
#define corto_selectResultUpdate(_this, name, parent, type) _corto_selectResultUpdate(_this, name, parent, type)

CORTO_LANG_EXPORT corto_selectResult* _corto_selectResultDeclare(void);
#define corto_selectResultDeclare() _corto_selectResultDeclare()
CORTO_LANG_EXPORT corto_selectResult* _corto_selectResultDeclareChild(corto_object _parent, corto_string _name);
#define corto_selectResultDeclareChild(_parent, _name) _corto_selectResultDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_selectResultDefine(corto_selectResult* _this, corto_string name, corto_string parent, corto_string type);
#define corto_selectResultDefine(_this, name, parent, type) _corto_selectResultDefine(_this, name, parent, type)
CORTO_LANG_EXPORT void _corto_selectResultSet(corto_selectResult* _this, corto_string name, corto_string parent, corto_string type);
#define corto_selectResultSet(_this, name, parent, type) _corto_selectResultSet(_this, name, parent, type)
CORTO_LANG_EXPORT corto_string _corto_selectResultStr(corto_selectResult* value);
#define corto_selectResultStr(value) _corto_selectResultStr(value)
CORTO_LANG_EXPORT corto_selectResult* corto_selectResultFromStr(corto_selectResult* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_selectResultCopy(corto_selectResult* *dst, corto_selectResult* src);
#define corto_selectResultCopy(dst, src) _corto_selectResultCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_selectResultCompare(corto_selectResult* dst, corto_selectResult* src);
#define corto_selectResultCompare(dst, src) _corto_selectResultCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_selectResultInit(corto_selectResult* value);
#define corto_selectResultInit(value) _corto_selectResultInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_selectResultDeinit(corto_selectResult* value);
#define corto_selectResultDeinit(value) _corto_selectResultDeinit(value)

/* /corto/lang/sequence */
CORTO_LANG_EXPORT corto_sequence _corto_sequenceCreate(corto_type elementType, corto_uint32 max);
#define corto_sequenceCreate(elementType, max) _corto_sequenceCreate(corto_type(elementType), max)
CORTO_LANG_EXPORT corto_sequence _corto_sequenceCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_sequenceCreateChild(_parent, _name, elementType, max) _corto_sequenceCreateChild(_parent, _name, corto_type(elementType), max)
CORTO_LANG_EXPORT corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceUpdate(_this, elementType, max) _corto_sequenceUpdate(corto_sequence(_this), corto_type(elementType), max)

CORTO_LANG_EXPORT corto_sequence _corto_sequenceDeclare(void);
#define corto_sequenceDeclare() _corto_sequenceDeclare()
CORTO_LANG_EXPORT corto_sequence _corto_sequenceDeclareChild(corto_object _parent, corto_string _name);
#define corto_sequenceDeclareChild(_parent, _name) _corto_sequenceDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceDefine(_this, elementType, max) _corto_sequenceDefine(corto_sequence(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT void _corto_sequenceSet(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceSet(_this, elementType, max) _corto_sequenceSet(corto_sequence(_this), corto_type(elementType), max)
CORTO_LANG_EXPORT corto_string _corto_sequenceStr(corto_sequence value);
#define corto_sequenceStr(value) _corto_sequenceStr(corto_sequence(value))
CORTO_LANG_EXPORT corto_sequence corto_sequenceFromStr(corto_sequence value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_sequenceCopy(corto_sequence *dst, corto_sequence src);
#define corto_sequenceCopy(dst, src) _corto_sequenceCopy(dst, corto_sequence(src))
CORTO_LANG_EXPORT corto_int16 _corto_sequenceCompare(corto_sequence dst, corto_sequence src);
#define corto_sequenceCompare(dst, src) _corto_sequenceCompare(corto_sequence(dst), corto_sequence(src))

/* /corto/lang/state */
CORTO_LANG_EXPORT corto_state* _corto_stateCreate(corto_state value);
#define corto_stateCreate(value) _corto_stateCreate(value)
CORTO_LANG_EXPORT corto_state* _corto_stateCreateChild(corto_object _parent, corto_string _name, corto_state value);
#define corto_stateCreateChild(_parent, _name, value) _corto_stateCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value);
#define corto_stateUpdate(_this, value) _corto_stateUpdate(_this, value)

CORTO_LANG_EXPORT corto_state* _corto_stateDeclare(void);
#define corto_stateDeclare() _corto_stateDeclare()
CORTO_LANG_EXPORT corto_state* _corto_stateDeclareChild(corto_object _parent, corto_string _name);
#define corto_stateDeclareChild(_parent, _name) _corto_stateDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_stateDefine(corto_state* _this, corto_state value);
#define corto_stateDefine(_this, value) _corto_stateDefine(_this, value)
CORTO_LANG_EXPORT void _corto_stateSet(corto_state* _this, corto_state value);
#define corto_stateSet(_this, value) _corto_stateSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_stateStr(corto_state value);
#define corto_stateStr(value) _corto_stateStr(value)
CORTO_LANG_EXPORT corto_state* corto_stateFromStr(corto_state* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_stateCopy(corto_state* *dst, corto_state* src);
#define corto_stateCopy(dst, src) _corto_stateCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_stateCompare(corto_state* dst, corto_state* src);
#define corto_stateCompare(dst, src) _corto_stateCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_stateInit(corto_state* value);
#define corto_stateInit(value) _corto_stateInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_stateDeinit(corto_state* value);
#define corto_stateDeinit(value) _corto_stateDeinit(value)

/* /corto/lang/string */
CORTO_LANG_EXPORT corto_string* _corto_stringCreate(corto_string value);
#define corto_stringCreate(value) _corto_stringCreate(value)
CORTO_LANG_EXPORT corto_string* _corto_stringCreateChild(corto_object _parent, corto_string _name, corto_string value);
#define corto_stringCreateChild(_parent, _name, value) _corto_stringCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value);
#define corto_stringUpdate(_this, value) _corto_stringUpdate(_this, value)

CORTO_LANG_EXPORT corto_string* _corto_stringDeclare(void);
#define corto_stringDeclare() _corto_stringDeclare()
CORTO_LANG_EXPORT corto_string* _corto_stringDeclareChild(corto_object _parent, corto_string _name);
#define corto_stringDeclareChild(_parent, _name) _corto_stringDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_stringDefine(corto_string* _this, corto_string value);
#define corto_stringDefine(_this, value) _corto_stringDefine(_this, value)
CORTO_LANG_EXPORT void _corto_stringSet(corto_string* _this, corto_string value);
#define corto_stringSet(_this, value) _corto_stringSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_stringStr(corto_string value);
#define corto_stringStr(value) _corto_stringStr(value)
CORTO_LANG_EXPORT corto_string* corto_stringFromStr(corto_string* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_stringCopy(corto_string* *dst, corto_string* src);
#define corto_stringCopy(dst, src) _corto_stringCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_stringCompare(corto_string* dst, corto_string* src);
#define corto_stringCompare(dst, src) _corto_stringCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_stringInit(corto_string* value);
#define corto_stringInit(value) _corto_stringInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_stringDeinit(corto_string* value);
#define corto_stringDeinit(value) _corto_stringDeinit(value)

/* /corto/lang/struct */
CORTO_LANG_EXPORT corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess);
#define corto_structCreate(base, baseAccess) _corto_structCreate(corto_interface(base), baseAccess)
CORTO_LANG_EXPORT corto_struct _corto_structCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess);
#define corto_structCreateChild(_parent, _name, base, baseAccess) _corto_structCreateChild(_parent, _name, corto_interface(base), baseAccess)
CORTO_LANG_EXPORT corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structUpdate(_this, base, baseAccess) _corto_structUpdate(corto_struct(_this), corto_interface(base), baseAccess)

CORTO_LANG_EXPORT corto_struct _corto_structDeclare(void);
#define corto_structDeclare() _corto_structDeclare()
CORTO_LANG_EXPORT corto_struct _corto_structDeclareChild(corto_object _parent, corto_string _name);
#define corto_structDeclareChild(_parent, _name) _corto_structDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structDefine(_this, base, baseAccess) _corto_structDefine(corto_struct(_this), corto_interface(base), baseAccess)
CORTO_LANG_EXPORT void _corto_structSet(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structSet(_this, base, baseAccess) _corto_structSet(corto_struct(_this), corto_interface(base), baseAccess)
CORTO_LANG_EXPORT corto_string _corto_structStr(corto_struct value);
#define corto_structStr(value) _corto_structStr(corto_struct(value))
CORTO_LANG_EXPORT corto_struct corto_structFromStr(corto_struct value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_structCopy(corto_struct *dst, corto_struct src);
#define corto_structCopy(dst, src) _corto_structCopy(dst, corto_struct(src))
CORTO_LANG_EXPORT corto_int16 _corto_structCompare(corto_struct dst, corto_struct src);
#define corto_structCompare(dst, src) _corto_structCompare(corto_struct(dst), corto_struct(src))

/* /corto/lang/text */
CORTO_LANG_EXPORT corto_text _corto_textCreate(corto_width charWidth, corto_uint64 length);
#define corto_textCreate(charWidth, length) _corto_textCreate(charWidth, length)
CORTO_LANG_EXPORT corto_text _corto_textCreateChild(corto_object _parent, corto_string _name, corto_width charWidth, corto_uint64 length);
#define corto_textCreateChild(_parent, _name, charWidth, length) _corto_textCreateChild(_parent, _name, charWidth, length)
CORTO_LANG_EXPORT corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textUpdate(_this, charWidth, length) _corto_textUpdate(corto_text(_this), charWidth, length)

CORTO_LANG_EXPORT corto_text _corto_textDeclare(void);
#define corto_textDeclare() _corto_textDeclare()
CORTO_LANG_EXPORT corto_text _corto_textDeclareChild(corto_object _parent, corto_string _name);
#define corto_textDeclareChild(_parent, _name) _corto_textDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textDefine(_this, charWidth, length) _corto_textDefine(corto_text(_this), charWidth, length)
CORTO_LANG_EXPORT void _corto_textSet(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textSet(_this, charWidth, length) _corto_textSet(corto_text(_this), charWidth, length)
CORTO_LANG_EXPORT corto_string _corto_textStr(corto_text value);
#define corto_textStr(value) _corto_textStr(corto_text(value))
CORTO_LANG_EXPORT corto_text corto_textFromStr(corto_text value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_textCopy(corto_text *dst, corto_text src);
#define corto_textCopy(dst, src) _corto_textCopy(dst, corto_text(src))
CORTO_LANG_EXPORT corto_int16 _corto_textCompare(corto_text dst, corto_text src);
#define corto_textCompare(dst, src) _corto_textCompare(corto_text(dst), corto_text(src))

/* /corto/lang/type */
CORTO_LANG_EXPORT corto_type _corto_typeCreate(corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeCreate(parentType, parentState, defaultType, defaultProcedureType) _corto_typeCreate(corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
CORTO_LANG_EXPORT corto_type _corto_typeCreateChild(corto_object _parent, corto_string _name, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeCreateChild(_parent, _name, parentType, parentState, defaultType, defaultProcedureType) _corto_typeCreateChild(_parent, _name, corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
CORTO_LANG_EXPORT corto_int16 _corto_typeUpdate(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeUpdate(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeUpdate(corto_type(_this), corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))

CORTO_LANG_EXPORT corto_type _corto_typeDeclare(void);
#define corto_typeDeclare() _corto_typeDeclare()
CORTO_LANG_EXPORT corto_type _corto_typeDeclareChild(corto_object _parent, corto_string _name);
#define corto_typeDeclareChild(_parent, _name) _corto_typeDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_typeDefine(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeDefine(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeDefine(corto_type(_this), corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
CORTO_LANG_EXPORT void _corto_typeSet(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
#define corto_typeSet(_this, parentType, parentState, defaultType, defaultProcedureType) _corto_typeSet(corto_type(_this), corto_type(parentType), parentState, corto_type(defaultType), corto_type(defaultProcedureType))
CORTO_LANG_EXPORT corto_string _corto_typeStr(corto_type value);
#define corto_typeStr(value) _corto_typeStr(corto_type(value))
CORTO_LANG_EXPORT corto_type corto_typeFromStr(corto_type value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_typeCopy(corto_type *dst, corto_type src);
#define corto_typeCopy(dst, src) _corto_typeCopy(dst, corto_type(src))
CORTO_LANG_EXPORT corto_int16 _corto_typeCompare(corto_type dst, corto_type src);
#define corto_typeCompare(dst, src) _corto_typeCompare(corto_type(dst), corto_type(src))

/* /corto/lang/typeKind */
CORTO_LANG_EXPORT corto_typeKind* _corto_typeKindCreate(corto_typeKind value);
#define corto_typeKindCreate(value) _corto_typeKindCreate(value)
CORTO_LANG_EXPORT corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, corto_string _name, corto_typeKind value);
#define corto_typeKindCreateChild(_parent, _name, value) _corto_typeKindCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindUpdate(_this, value) _corto_typeKindUpdate(_this, value)

CORTO_LANG_EXPORT corto_typeKind* _corto_typeKindDeclare(void);
#define corto_typeKindDeclare() _corto_typeKindDeclare()
CORTO_LANG_EXPORT corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_typeKindDeclareChild(_parent, _name) _corto_typeKindDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindDefine(_this, value) _corto_typeKindDefine(_this, value)
CORTO_LANG_EXPORT void _corto_typeKindSet(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindSet(_this, value) _corto_typeKindSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_typeKindStr(corto_typeKind value);
#define corto_typeKindStr(value) _corto_typeKindStr(value)
CORTO_LANG_EXPORT corto_typeKind* corto_typeKindFromStr(corto_typeKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_typeKindCopy(corto_typeKind* *dst, corto_typeKind* src);
#define corto_typeKindCopy(dst, src) _corto_typeKindCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_typeKindCompare(corto_typeKind* dst, corto_typeKind* src);
#define corto_typeKindCompare(dst, src) _corto_typeKindCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_typeKindInit(corto_typeKind* value);
#define corto_typeKindInit(value) _corto_typeKindInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_typeKindDeinit(corto_typeKind* value);
#define corto_typeKindDeinit(value) _corto_typeKindDeinit(value)

/* /corto/lang/uint */
CORTO_LANG_EXPORT corto_uint _corto_uintCreate(corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintCreate(width, min, max) _corto_uintCreate(width, min, max)
CORTO_LANG_EXPORT corto_uint _corto_uintCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintCreateChild(_parent, _name, width, min, max) _corto_uintCreateChild(_parent, _name, width, min, max)
CORTO_LANG_EXPORT corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintUpdate(_this, width, min, max) _corto_uintUpdate(corto_uint(_this), width, min, max)

CORTO_LANG_EXPORT corto_uint _corto_uintDeclare(void);
#define corto_uintDeclare() _corto_uintDeclare()
CORTO_LANG_EXPORT corto_uint _corto_uintDeclareChild(corto_object _parent, corto_string _name);
#define corto_uintDeclareChild(_parent, _name) _corto_uintDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintDefine(_this, width, min, max) _corto_uintDefine(corto_uint(_this), width, min, max)
CORTO_LANG_EXPORT void _corto_uintSet(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintSet(_this, width, min, max) _corto_uintSet(corto_uint(_this), width, min, max)
CORTO_LANG_EXPORT corto_string _corto_uintStr(corto_uint value);
#define corto_uintStr(value) _corto_uintStr(corto_uint(value))
CORTO_LANG_EXPORT corto_uint corto_uintFromStr(corto_uint value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_uintCopy(corto_uint *dst, corto_uint src);
#define corto_uintCopy(dst, src) _corto_uintCopy(dst, corto_uint(src))
CORTO_LANG_EXPORT corto_int16 _corto_uintCompare(corto_uint dst, corto_uint src);
#define corto_uintCompare(dst, src) _corto_uintCompare(corto_uint(dst), corto_uint(src))

/* /corto/lang/uint16 */
CORTO_LANG_EXPORT corto_uint16* _corto_uint16Create(corto_uint16 value);
#define corto_uint16Create(value) _corto_uint16Create(value)
CORTO_LANG_EXPORT corto_uint16* _corto_uint16CreateChild(corto_object _parent, corto_string _name, corto_uint16 value);
#define corto_uint16CreateChild(_parent, _name, value) _corto_uint16CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_uint16Update(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Update(_this, value) _corto_uint16Update(_this, value)

CORTO_LANG_EXPORT corto_uint16* _corto_uint16Declare(void);
#define corto_uint16Declare() _corto_uint16Declare()
CORTO_LANG_EXPORT corto_uint16* _corto_uint16DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint16DeclareChild(_parent, _name) _corto_uint16DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_uint16Define(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Define(_this, value) _corto_uint16Define(_this, value)
CORTO_LANG_EXPORT void _corto_uint16Set(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Set(_this, value) _corto_uint16Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_uint16Str(corto_uint16 value);
#define corto_uint16Str(value) _corto_uint16Str(value)
CORTO_LANG_EXPORT corto_uint16* corto_uint16FromStr(corto_uint16* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_uint16Copy(corto_uint16* *dst, corto_uint16* src);
#define corto_uint16Copy(dst, src) _corto_uint16Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_uint16Compare(corto_uint16* dst, corto_uint16* src);
#define corto_uint16Compare(dst, src) _corto_uint16Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_uint16Init(corto_uint16* value);
#define corto_uint16Init(value) _corto_uint16Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_uint16Deinit(corto_uint16* value);
#define corto_uint16Deinit(value) _corto_uint16Deinit(value)

/* /corto/lang/uint32 */
CORTO_LANG_EXPORT corto_uint32* _corto_uint32Create(corto_uint32 value);
#define corto_uint32Create(value) _corto_uint32Create(value)
CORTO_LANG_EXPORT corto_uint32* _corto_uint32CreateChild(corto_object _parent, corto_string _name, corto_uint32 value);
#define corto_uint32CreateChild(_parent, _name, value) _corto_uint32CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_uint32Update(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Update(_this, value) _corto_uint32Update(_this, value)

CORTO_LANG_EXPORT corto_uint32* _corto_uint32Declare(void);
#define corto_uint32Declare() _corto_uint32Declare()
CORTO_LANG_EXPORT corto_uint32* _corto_uint32DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint32DeclareChild(_parent, _name) _corto_uint32DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_uint32Define(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Define(_this, value) _corto_uint32Define(_this, value)
CORTO_LANG_EXPORT void _corto_uint32Set(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Set(_this, value) _corto_uint32Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_uint32Str(corto_uint32 value);
#define corto_uint32Str(value) _corto_uint32Str(value)
CORTO_LANG_EXPORT corto_uint32* corto_uint32FromStr(corto_uint32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_uint32Copy(corto_uint32* *dst, corto_uint32* src);
#define corto_uint32Copy(dst, src) _corto_uint32Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_uint32Compare(corto_uint32* dst, corto_uint32* src);
#define corto_uint32Compare(dst, src) _corto_uint32Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_uint32Init(corto_uint32* value);
#define corto_uint32Init(value) _corto_uint32Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_uint32Deinit(corto_uint32* value);
#define corto_uint32Deinit(value) _corto_uint32Deinit(value)

/* /corto/lang/uint64 */
CORTO_LANG_EXPORT corto_uint64* _corto_uint64Create(corto_uint64 value);
#define corto_uint64Create(value) _corto_uint64Create(value)
CORTO_LANG_EXPORT corto_uint64* _corto_uint64CreateChild(corto_object _parent, corto_string _name, corto_uint64 value);
#define corto_uint64CreateChild(_parent, _name, value) _corto_uint64CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_uint64Update(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Update(_this, value) _corto_uint64Update(_this, value)

CORTO_LANG_EXPORT corto_uint64* _corto_uint64Declare(void);
#define corto_uint64Declare() _corto_uint64Declare()
CORTO_LANG_EXPORT corto_uint64* _corto_uint64DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint64DeclareChild(_parent, _name) _corto_uint64DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_uint64Define(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Define(_this, value) _corto_uint64Define(_this, value)
CORTO_LANG_EXPORT void _corto_uint64Set(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Set(_this, value) _corto_uint64Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_uint64Str(corto_uint64 value);
#define corto_uint64Str(value) _corto_uint64Str(value)
CORTO_LANG_EXPORT corto_uint64* corto_uint64FromStr(corto_uint64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_uint64Copy(corto_uint64* *dst, corto_uint64* src);
#define corto_uint64Copy(dst, src) _corto_uint64Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_uint64Compare(corto_uint64* dst, corto_uint64* src);
#define corto_uint64Compare(dst, src) _corto_uint64Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_uint64Init(corto_uint64* value);
#define corto_uint64Init(value) _corto_uint64Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_uint64Deinit(corto_uint64* value);
#define corto_uint64Deinit(value) _corto_uint64Deinit(value)

/* /corto/lang/uint8 */
CORTO_LANG_EXPORT corto_uint8* _corto_uint8Create(corto_uint8 value);
#define corto_uint8Create(value) _corto_uint8Create(value)
CORTO_LANG_EXPORT corto_uint8* _corto_uint8CreateChild(corto_object _parent, corto_string _name, corto_uint8 value);
#define corto_uint8CreateChild(_parent, _name, value) _corto_uint8CreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_uint8Update(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Update(_this, value) _corto_uint8Update(_this, value)

CORTO_LANG_EXPORT corto_uint8* _corto_uint8Declare(void);
#define corto_uint8Declare() _corto_uint8Declare()
CORTO_LANG_EXPORT corto_uint8* _corto_uint8DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint8DeclareChild(_parent, _name) _corto_uint8DeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_uint8Define(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Define(_this, value) _corto_uint8Define(_this, value)
CORTO_LANG_EXPORT void _corto_uint8Set(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Set(_this, value) _corto_uint8Set(_this, value)
CORTO_LANG_EXPORT corto_string _corto_uint8Str(corto_uint8 value);
#define corto_uint8Str(value) _corto_uint8Str(value)
CORTO_LANG_EXPORT corto_uint8* corto_uint8FromStr(corto_uint8* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_uint8Copy(corto_uint8* *dst, corto_uint8* src);
#define corto_uint8Copy(dst, src) _corto_uint8Copy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_uint8Compare(corto_uint8* dst, corto_uint8* src);
#define corto_uint8Compare(dst, src) _corto_uint8Compare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_uint8Init(corto_uint8* value);
#define corto_uint8Init(value) _corto_uint8Init(value)
CORTO_LANG_EXPORT corto_int16 _corto_uint8Deinit(corto_uint8* value);
#define corto_uint8Deinit(value) _corto_uint8Deinit(value)

/* /corto/lang/virtual */
CORTO_LANG_EXPORT corto_virtual _corto_virtualCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualCreate(returnType, returnsReference, _virtual, _impl) _corto_virtualCreate(corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT corto_virtual _corto_virtualCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualCreateChild(_parent, _name, returnType, returnsReference, _virtual, _impl) _corto_virtualCreateChild(_parent, _name, corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT corto_int16 _corto_virtualUpdate(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
#define corto_virtualUpdate(_this, returnType, returnsReference, _virtual) _corto_virtualUpdate(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual)

CORTO_LANG_EXPORT corto_virtual _corto_virtualDeclare(void);
#define corto_virtualDeclare() _corto_virtualDeclare()
CORTO_LANG_EXPORT corto_virtual _corto_virtualDeclareChild(corto_object _parent, corto_string _name);
#define corto_virtualDeclareChild(_parent, _name) _corto_virtualDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_virtualDefine(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualDefine(_this, returnType, returnsReference, _virtual, _impl) _corto_virtualDefine(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_LANG_EXPORT void _corto_virtualSet(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
#define corto_virtualSet(_this, returnType, returnsReference, _virtual) _corto_virtualSet(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual)
CORTO_LANG_EXPORT corto_string _corto_virtualStr(corto_virtual value);
#define corto_virtualStr(value) _corto_virtualStr(corto_virtual(value))
CORTO_LANG_EXPORT corto_virtual corto_virtualFromStr(corto_virtual value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_virtualCopy(corto_virtual *dst, corto_virtual src);
#define corto_virtualCopy(dst, src) _corto_virtualCopy(dst, corto_virtual(src))
CORTO_LANG_EXPORT corto_int16 _corto_virtualCompare(corto_virtual dst, corto_virtual src);
#define corto_virtualCompare(dst, src) _corto_virtualCompare(corto_virtual(dst), corto_virtual(src))

/* /corto/lang/void */
CORTO_LANG_EXPORT corto_void* _corto_voidCreate(void);
#define corto_voidCreate() _corto_voidCreate()
CORTO_LANG_EXPORT corto_void* _corto_voidCreateChild(corto_object _parent, corto_string _name);
#define corto_voidCreateChild(_parent, _name) _corto_voidCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_voidUpdate(corto_void* _this);
#define corto_voidUpdate(_this) _corto_voidUpdate(_this)

/* /corto/lang/vtable */
CORTO_LANG_EXPORT corto_vtable* _corto_vtableCreate(void);
#define corto_vtableCreate() _corto_vtableCreate()
CORTO_LANG_EXPORT corto_vtable* _corto_vtableCreateChild(corto_object _parent, corto_string _name);
#define corto_vtableCreateChild(_parent, _name) _corto_vtableCreateChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_vtableUpdate(corto_vtable* _this, corto_vtable value);
#define corto_vtableUpdate(_this, value) _corto_vtableUpdate(_this, value)

CORTO_LANG_EXPORT corto_vtable* _corto_vtableDeclare(void);
#define corto_vtableDeclare() _corto_vtableDeclare()
CORTO_LANG_EXPORT corto_vtable* _corto_vtableDeclareChild(corto_object _parent, corto_string _name);
#define corto_vtableDeclareChild(_parent, _name) _corto_vtableDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_vtableDefine(corto_vtable* _this, corto_vtable value);
#define corto_vtableDefine(_this, value) _corto_vtableDefine(_this, value)
CORTO_LANG_EXPORT void _corto_vtableSet(corto_vtable* _this, corto_vtable value);
#define corto_vtableSet(_this, value) _corto_vtableSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_vtableStr(corto_vtable value);
#define corto_vtableStr(value) _corto_vtableStr(value)
CORTO_LANG_EXPORT corto_vtable* corto_vtableFromStr(corto_vtable* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_vtableCopy(corto_vtable* *dst, corto_vtable* src);
#define corto_vtableCopy(dst, src) _corto_vtableCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_vtableCompare(corto_vtable* dst, corto_vtable* src);
#define corto_vtableCompare(dst, src) _corto_vtableCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_vtableInit(corto_vtable* value);
#define corto_vtableInit(value) _corto_vtableInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_vtableDeinit(corto_vtable* value);
#define corto_vtableDeinit(value) _corto_vtableDeinit(value)

/* /corto/lang/width */
CORTO_LANG_EXPORT corto_width* _corto_widthCreate(corto_width value);
#define corto_widthCreate(value) _corto_widthCreate(value)
CORTO_LANG_EXPORT corto_width* _corto_widthCreateChild(corto_object _parent, corto_string _name, corto_width value);
#define corto_widthCreateChild(_parent, _name, value) _corto_widthCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value);
#define corto_widthUpdate(_this, value) _corto_widthUpdate(_this, value)

CORTO_LANG_EXPORT corto_width* _corto_widthDeclare(void);
#define corto_widthDeclare() _corto_widthDeclare()
CORTO_LANG_EXPORT corto_width* _corto_widthDeclareChild(corto_object _parent, corto_string _name);
#define corto_widthDeclareChild(_parent, _name) _corto_widthDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_widthDefine(corto_width* _this, corto_width value);
#define corto_widthDefine(_this, value) _corto_widthDefine(_this, value)
CORTO_LANG_EXPORT void _corto_widthSet(corto_width* _this, corto_width value);
#define corto_widthSet(_this, value) _corto_widthSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_widthStr(corto_width value);
#define corto_widthStr(value) _corto_widthStr(value)
CORTO_LANG_EXPORT corto_width* corto_widthFromStr(corto_width* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_widthCopy(corto_width* *dst, corto_width* src);
#define corto_widthCopy(dst, src) _corto_widthCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_widthCompare(corto_width* dst, corto_width* src);
#define corto_widthCompare(dst, src) _corto_widthCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_widthInit(corto_width* value);
#define corto_widthInit(value) _corto_widthInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_widthDeinit(corto_width* value);
#define corto_widthDeinit(value) _corto_widthDeinit(value)

/* /corto/lang/word */
CORTO_LANG_EXPORT corto_word* _corto_wordCreate(corto_word value);
#define corto_wordCreate(value) _corto_wordCreate(value)
CORTO_LANG_EXPORT corto_word* _corto_wordCreateChild(corto_object _parent, corto_string _name, corto_word value);
#define corto_wordCreateChild(_parent, _name, value) _corto_wordCreateChild(_parent, _name, value)
CORTO_LANG_EXPORT corto_int16 _corto_wordUpdate(corto_word* _this, corto_word value);
#define corto_wordUpdate(_this, value) _corto_wordUpdate(_this, value)

CORTO_LANG_EXPORT corto_word* _corto_wordDeclare(void);
#define corto_wordDeclare() _corto_wordDeclare()
CORTO_LANG_EXPORT corto_word* _corto_wordDeclareChild(corto_object _parent, corto_string _name);
#define corto_wordDeclareChild(_parent, _name) _corto_wordDeclareChild(_parent, _name)
CORTO_LANG_EXPORT corto_int16 _corto_wordDefine(corto_word* _this, corto_word value);
#define corto_wordDefine(_this, value) _corto_wordDefine(_this, value)
CORTO_LANG_EXPORT void _corto_wordSet(corto_word* _this, corto_word value);
#define corto_wordSet(_this, value) _corto_wordSet(_this, value)
CORTO_LANG_EXPORT corto_string _corto_wordStr(corto_word value);
#define corto_wordStr(value) _corto_wordStr(value)
CORTO_LANG_EXPORT corto_word* corto_wordFromStr(corto_word* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 _corto_wordCopy(corto_word* *dst, corto_word* src);
#define corto_wordCopy(dst, src) _corto_wordCopy(dst, src)
CORTO_LANG_EXPORT corto_int16 _corto_wordCompare(corto_word* dst, corto_word* src);
#define corto_wordCompare(dst, src) _corto_wordCompare(dst, src)

CORTO_LANG_EXPORT corto_int16 _corto_wordInit(corto_word* value);
#define corto_wordInit(value) _corto_wordInit(value)
CORTO_LANG_EXPORT corto_int16 _corto_wordDeinit(corto_word* value);
#define corto_wordDeinit(value) _corto_wordDeinit(value)


/* /corto/lang/interfaceseq */
#define corto_interfaceseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interface elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element);
CORTO_LANG_EXPORT corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq);
CORTO_LANG_EXPORT void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_interfaceseqClear(corto_interfaceseq *seq);

/* /corto/lang/interfaceVectorseq */
#define corto_interfaceVectorseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interfaceVector elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element);
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq);
CORTO_LANG_EXPORT void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq);

/* /corto/lang/memberseq */
#define corto_memberseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_member elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_member* corto_memberseqAppend(corto_memberseq *seq, corto_member element);
CORTO_LANG_EXPORT corto_member* corto_memberseqAppendAlloc(corto_memberseq *seq);
CORTO_LANG_EXPORT void corto_memberseqSize(corto_memberseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_memberseqClear(corto_memberseq *seq);

/* /corto/lang/objectseq */
#define corto_objectseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_object elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element);
CORTO_LANG_EXPORT corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq);
CORTO_LANG_EXPORT void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_objectseqClear(corto_objectseq *seq);

/* /corto/lang/observerseq */
#define corto_observerseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_observer elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_observer* corto_observerseqAppend(corto_observerseq *seq, corto_observer element);
CORTO_LANG_EXPORT corto_observer* corto_observerseqAppendAlloc(corto_observerseq *seq);
CORTO_LANG_EXPORT void corto_observerseqSize(corto_observerseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_observerseqClear(corto_observerseq *seq);

/* /corto/lang/octetseq */
#define corto_octetseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_octet elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_octet* corto_octetseqAppend(corto_octetseq *seq, corto_octet element);
CORTO_LANG_EXPORT corto_octet* corto_octetseqAppendAlloc(corto_octetseq *seq);
CORTO_LANG_EXPORT void corto_octetseqSize(corto_octetseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_octetseqClear(corto_octetseq *seq);

/* /corto/lang/parameterseq */
#define corto_parameterseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_parameter elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element);
CORTO_LANG_EXPORT corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq);
CORTO_LANG_EXPORT void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_parameterseqClear(corto_parameterseq *seq);

/* /corto/lang/vtable */
#define corto_vtableForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_function elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_function* corto_vtableAppend(corto_vtable *seq, corto_function element);
CORTO_LANG_EXPORT corto_function* corto_vtableAppendAlloc(corto_vtable *seq);
CORTO_LANG_EXPORT void corto_vtableSize(corto_vtable *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_vtableClear(corto_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

