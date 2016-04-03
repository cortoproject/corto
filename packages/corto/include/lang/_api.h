/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG__API_H
#define CORTO_LANG__API_H

#include "corto/corto.h"
#include "corto/_interface.h"
#ifdef __cplusplus
extern "C" {
#endif
/* alias */
CORTO_EXPORT corto_alias _corto_aliasCreate(corto_member member);
#define corto_aliasCreate(member) _corto_aliasCreate(corto_member(member))
#define corto_aliasCreate_auto(_name, member) corto_alias _name = corto_aliasCreate(member); (void)_name
CORTO_EXPORT corto_alias _corto_aliasCreateChild(corto_object _parent, corto_string _name, corto_member member);
#define corto_aliasCreateChild(_parent, _name, member) _corto_aliasCreateChild(_parent, _name, corto_member(member))
#define corto_aliasCreateChild_auto(_parent, _name, member) corto_alias _name = corto_aliasCreateChild(_parent, #_name, member); (void)_name
CORTO_EXPORT corto_int16 _corto_aliasUpdate(corto_alias _this, corto_member member);
#define corto_aliasUpdate(_this, member) _corto_aliasUpdate(corto_alias(_this), corto_member(member))

CORTO_EXPORT corto_alias _corto_aliasDeclare(void);
#define corto_aliasDeclare() _corto_aliasDeclare()
#define corto_aliasDeclare_auto(_name) corto_alias _name = corto_aliasDeclare(); (void)_name
CORTO_EXPORT corto_alias _corto_aliasDeclareChild(corto_object _parent, corto_string _name);
#define corto_aliasDeclareChild(_parent, _name) _corto_aliasDeclareChild(_parent, _name)
#define corto_aliasDeclareChild_auto(_parent, _name) corto_alias _name = corto_aliasDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_aliasDefine(corto_alias _this, corto_member member);
#define corto_aliasDefine(_this, member) _corto_aliasDefine(corto_alias(_this), corto_member(member))
CORTO_EXPORT void _corto_aliasSet(corto_alias _this, corto_member member);
#define corto_aliasSet(_this, member) _corto_aliasSet(corto_alias(_this), corto_member(member))
CORTO_EXPORT corto_string _corto_aliasStr(corto_alias value);
#define corto_aliasStr(value) _corto_aliasStr(corto_alias(value))
CORTO_EXPORT corto_alias corto_aliasFromStr(corto_alias value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_aliasCompare(corto_alias dst, corto_alias src);
#define corto_aliasCompare(dst, src) _corto_aliasCompare(corto_alias(dst), corto_alias(src))

/* any */
CORTO_EXPORT corto_any* _corto_anyCreate(corto_type type, void *value);
#define corto_anyCreate(type, value) _corto_anyCreate(corto_type(type), value)
#define corto_anyCreate_auto(_name, type, value) corto_any* _name = corto_anyCreate(type, value); (void)_name
CORTO_EXPORT corto_any* _corto_anyCreateChild(corto_object _parent, corto_string _name, corto_type type, void *value);
#define corto_anyCreateChild(_parent, _name, type, value) _corto_anyCreateChild(_parent, _name, corto_type(type), value)
#define corto_anyCreateChild_auto(_parent, _name, type, value) corto_any* _name = corto_anyCreateChild(_parent, #_name, type, value); (void)_name
CORTO_EXPORT corto_int16 _corto_anyUpdate(corto_any* _this, corto_type type, void *value);
#define corto_anyUpdate(_this, type, value) _corto_anyUpdate(_this, corto_type(type), value)

CORTO_EXPORT corto_any* _corto_anyDeclare(void);
#define corto_anyDeclare() _corto_anyDeclare()
#define corto_anyDeclare_auto(_name) corto_any* _name = corto_anyDeclare(); (void)_name
CORTO_EXPORT corto_any* _corto_anyDeclareChild(corto_object _parent, corto_string _name);
#define corto_anyDeclareChild(_parent, _name) _corto_anyDeclareChild(_parent, _name)
#define corto_anyDeclareChild_auto(_parent, _name) corto_any* _name = corto_anyDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_anyDefine(corto_any* _this, corto_type type, void *value);
#define corto_anyDefine(_this, type, value) _corto_anyDefine(_this, corto_type(type), value)
CORTO_EXPORT void _corto_anySet(corto_any* _this, corto_type type, void *value);
#define corto_anySet(_this, type, value) _corto_anySet(_this, corto_type(type), value)
CORTO_EXPORT corto_string _corto_anyStr(corto_any value);
#define corto_anyStr(value) _corto_anyStr(value)
CORTO_EXPORT corto_any* corto_anyFromStr(corto_any* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_anyCompare(corto_any dst, corto_any src);

CORTO_EXPORT corto_int16 _corto_anyInit(corto_any* value);
#define corto_anyInit(value) _corto_anyInit(value)
CORTO_EXPORT corto_int16 _corto_anyDeinit(corto_any* value);
#define corto_anyDeinit(value) _corto_anyDeinit(value)

/* array */
CORTO_EXPORT corto_array _corto_arrayCreate(corto_type elementType, corto_uint32 max);
#define corto_arrayCreate(elementType, max) _corto_arrayCreate(corto_type(elementType), max)
#define corto_arrayCreate_auto(_name, elementType, max) corto_array _name = corto_arrayCreate(elementType, max); (void)_name
CORTO_EXPORT corto_array _corto_arrayCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_arrayCreateChild(_parent, _name, elementType, max) _corto_arrayCreateChild(_parent, _name, corto_type(elementType), max)
#define corto_arrayCreateChild_auto(_parent, _name, elementType, max) corto_array _name = corto_arrayCreateChild(_parent, #_name, elementType, max); (void)_name
CORTO_EXPORT corto_int16 _corto_arrayUpdate(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arrayUpdate(_this, elementType, max) _corto_arrayUpdate(corto_array(_this), corto_type(elementType), max)

CORTO_EXPORT corto_array _corto_arrayDeclare(void);
#define corto_arrayDeclare() _corto_arrayDeclare()
#define corto_arrayDeclare_auto(_name) corto_array _name = corto_arrayDeclare(); (void)_name
CORTO_EXPORT corto_array _corto_arrayDeclareChild(corto_object _parent, corto_string _name);
#define corto_arrayDeclareChild(_parent, _name) _corto_arrayDeclareChild(_parent, _name)
#define corto_arrayDeclareChild_auto(_parent, _name) corto_array _name = corto_arrayDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_arrayDefine(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arrayDefine(_this, elementType, max) _corto_arrayDefine(corto_array(_this), corto_type(elementType), max)
CORTO_EXPORT void _corto_arraySet(corto_array _this, corto_type elementType, corto_uint32 max);
#define corto_arraySet(_this, elementType, max) _corto_arraySet(corto_array(_this), corto_type(elementType), max)
CORTO_EXPORT corto_string _corto_arrayStr(corto_array value);
#define corto_arrayStr(value) _corto_arrayStr(corto_array(value))
CORTO_EXPORT corto_array corto_arrayFromStr(corto_array value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_arrayCompare(corto_array dst, corto_array src);
#define corto_arrayCompare(dst, src) _corto_arrayCompare(corto_array(dst), corto_array(src))

/* binary */
CORTO_EXPORT corto_binary _corto_binaryCreate(corto_width width);
#define corto_binaryCreate(width) _corto_binaryCreate(width)
#define corto_binaryCreate_auto(_name, width) corto_binary _name = corto_binaryCreate(width); (void)_name
CORTO_EXPORT corto_binary _corto_binaryCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_binaryCreateChild(_parent, _name, width) _corto_binaryCreateChild(_parent, _name, width)
#define corto_binaryCreateChild_auto(_parent, _name, width) corto_binary _name = corto_binaryCreateChild(_parent, #_name, width); (void)_name
CORTO_EXPORT corto_int16 _corto_binaryUpdate(corto_binary _this, corto_width width);
#define corto_binaryUpdate(_this, width) _corto_binaryUpdate(corto_binary(_this), width)

CORTO_EXPORT corto_binary _corto_binaryDeclare(void);
#define corto_binaryDeclare() _corto_binaryDeclare()
#define corto_binaryDeclare_auto(_name) corto_binary _name = corto_binaryDeclare(); (void)_name
CORTO_EXPORT corto_binary _corto_binaryDeclareChild(corto_object _parent, corto_string _name);
#define corto_binaryDeclareChild(_parent, _name) _corto_binaryDeclareChild(_parent, _name)
#define corto_binaryDeclareChild_auto(_parent, _name) corto_binary _name = corto_binaryDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_binaryDefine(corto_binary _this, corto_width width);
#define corto_binaryDefine(_this, width) _corto_binaryDefine(corto_binary(_this), width)
CORTO_EXPORT void _corto_binarySet(corto_binary _this, corto_width width);
#define corto_binarySet(_this, width) _corto_binarySet(corto_binary(_this), width)
CORTO_EXPORT corto_string _corto_binaryStr(corto_binary value);
#define corto_binaryStr(value) _corto_binaryStr(corto_binary(value))
CORTO_EXPORT corto_binary corto_binaryFromStr(corto_binary value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_binaryCompare(corto_binary dst, corto_binary src);
#define corto_binaryCompare(dst, src) _corto_binaryCompare(corto_binary(dst), corto_binary(src))

/* bitmask */
CORTO_EXPORT corto_bitmask _corto_bitmaskCreate(void);
#define corto_bitmaskCreate() _corto_bitmaskCreate()
#define corto_bitmaskCreate_auto(_name) corto_bitmask _name = corto_bitmaskCreate(); (void)_name
CORTO_EXPORT corto_bitmask _corto_bitmaskCreateChild(corto_object _parent, corto_string _name);
#define corto_bitmaskCreateChild(_parent, _name) _corto_bitmaskCreateChild(_parent, _name)
#define corto_bitmaskCreateChild_auto(_parent, _name) corto_bitmask _name = corto_bitmaskCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_bitmaskUpdate(corto_bitmask _this);
#define corto_bitmaskUpdate(_this) _corto_bitmaskUpdate(corto_bitmask(_this))

CORTO_EXPORT corto_bitmask _corto_bitmaskDeclare(void);
#define corto_bitmaskDeclare() _corto_bitmaskDeclare()
#define corto_bitmaskDeclare_auto(_name) corto_bitmask _name = corto_bitmaskDeclare(); (void)_name
CORTO_EXPORT corto_bitmask _corto_bitmaskDeclareChild(corto_object _parent, corto_string _name);
#define corto_bitmaskDeclareChild(_parent, _name) _corto_bitmaskDeclareChild(_parent, _name)
#define corto_bitmaskDeclareChild_auto(_parent, _name) corto_bitmask _name = corto_bitmaskDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_bitmaskDefine(corto_bitmask _this);
#define corto_bitmaskDefine(_this) _corto_bitmaskDefine(corto_bitmask(_this))
CORTO_EXPORT void _corto_bitmaskSet(corto_bitmask _this);
#define corto_bitmaskSet(_this) _corto_bitmaskSet(corto_bitmask(_this))
CORTO_EXPORT corto_string _corto_bitmaskStr(corto_bitmask value);
#define corto_bitmaskStr(value) _corto_bitmaskStr(corto_bitmask(value))
CORTO_EXPORT corto_bitmask corto_bitmaskFromStr(corto_bitmask value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_bitmaskCompare(corto_bitmask dst, corto_bitmask src);
#define corto_bitmaskCompare(dst, src) _corto_bitmaskCompare(corto_bitmask(dst), corto_bitmask(src))

/* bool */
CORTO_EXPORT corto_bool* _corto_boolCreate(corto_bool value);
#define corto_boolCreate(value) _corto_boolCreate(value)
#define corto_boolCreate_auto(_name, value) corto_bool* _name = corto_boolCreate(value); (void)_name
CORTO_EXPORT corto_bool* _corto_boolCreateChild(corto_object _parent, corto_string _name, corto_bool value);
#define corto_boolCreateChild(_parent, _name, value) _corto_boolCreateChild(_parent, _name, value)
#define corto_boolCreateChild_auto(_parent, _name, value) corto_bool* _name = corto_boolCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_boolUpdate(corto_bool* _this, corto_bool value);
#define corto_boolUpdate(_this, value) _corto_boolUpdate(_this, value)

CORTO_EXPORT corto_bool* _corto_boolDeclare(void);
#define corto_boolDeclare() _corto_boolDeclare()
#define corto_boolDeclare_auto(_name) corto_bool* _name = corto_boolDeclare(); (void)_name
CORTO_EXPORT corto_bool* _corto_boolDeclareChild(corto_object _parent, corto_string _name);
#define corto_boolDeclareChild(_parent, _name) _corto_boolDeclareChild(_parent, _name)
#define corto_boolDeclareChild_auto(_parent, _name) corto_bool* _name = corto_boolDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_boolDefine(corto_bool* _this, corto_bool value);
#define corto_boolDefine(_this, value) _corto_boolDefine(_this, value)
CORTO_EXPORT void _corto_boolSet(corto_bool* _this, corto_bool value);
#define corto_boolSet(_this, value) _corto_boolSet(_this, value)
CORTO_EXPORT corto_string _corto_boolStr(corto_bool value);
#define corto_boolStr(value) _corto_boolStr(value)
CORTO_EXPORT corto_bool* corto_boolFromStr(corto_bool* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_boolCompare(corto_bool dst, corto_bool src);

CORTO_EXPORT corto_int16 _corto_boolInit(corto_bool* value);
#define corto_boolInit(value) _corto_boolInit(value)
CORTO_EXPORT corto_int16 _corto_boolDeinit(corto_bool* value);
#define corto_boolDeinit(value) _corto_boolDeinit(value)

/* boolean */
CORTO_EXPORT corto_boolean _corto_booleanCreate(void);
#define corto_booleanCreate() _corto_booleanCreate()
#define corto_booleanCreate_auto(_name) corto_boolean _name = corto_booleanCreate(); (void)_name
CORTO_EXPORT corto_boolean _corto_booleanCreateChild(corto_object _parent, corto_string _name);
#define corto_booleanCreateChild(_parent, _name) _corto_booleanCreateChild(_parent, _name)
#define corto_booleanCreateChild_auto(_parent, _name) corto_boolean _name = corto_booleanCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_booleanUpdate(corto_boolean _this);
#define corto_booleanUpdate(_this) _corto_booleanUpdate(corto_boolean(_this))

CORTO_EXPORT corto_boolean _corto_booleanDeclare(void);
#define corto_booleanDeclare() _corto_booleanDeclare()
#define corto_booleanDeclare_auto(_name) corto_boolean _name = corto_booleanDeclare(); (void)_name
CORTO_EXPORT corto_boolean _corto_booleanDeclareChild(corto_object _parent, corto_string _name);
#define corto_booleanDeclareChild(_parent, _name) _corto_booleanDeclareChild(_parent, _name)
#define corto_booleanDeclareChild_auto(_parent, _name) corto_boolean _name = corto_booleanDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_booleanDefine(corto_boolean _this);
#define corto_booleanDefine(_this) _corto_booleanDefine(corto_boolean(_this))
CORTO_EXPORT void _corto_booleanSet(corto_boolean _this);
#define corto_booleanSet(_this) _corto_booleanSet(corto_boolean(_this))
CORTO_EXPORT corto_string _corto_booleanStr(corto_boolean value);
#define corto_booleanStr(value) _corto_booleanStr(corto_boolean(value))
CORTO_EXPORT corto_boolean corto_booleanFromStr(corto_boolean value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_booleanCompare(corto_boolean dst, corto_boolean src);
#define corto_booleanCompare(dst, src) _corto_booleanCompare(corto_boolean(dst), corto_boolean(src))

/* char */
CORTO_EXPORT corto_char* _corto_charCreate(corto_char value);
#define corto_charCreate(value) _corto_charCreate(value)
#define corto_charCreate_auto(_name, value) corto_char* _name = corto_charCreate(value); (void)_name
CORTO_EXPORT corto_char* _corto_charCreateChild(corto_object _parent, corto_string _name, corto_char value);
#define corto_charCreateChild(_parent, _name, value) _corto_charCreateChild(_parent, _name, value)
#define corto_charCreateChild_auto(_parent, _name, value) corto_char* _name = corto_charCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_charUpdate(corto_char* _this, corto_char value);
#define corto_charUpdate(_this, value) _corto_charUpdate(_this, value)

CORTO_EXPORT corto_char* _corto_charDeclare(void);
#define corto_charDeclare() _corto_charDeclare()
#define corto_charDeclare_auto(_name) corto_char* _name = corto_charDeclare(); (void)_name
CORTO_EXPORT corto_char* _corto_charDeclareChild(corto_object _parent, corto_string _name);
#define corto_charDeclareChild(_parent, _name) _corto_charDeclareChild(_parent, _name)
#define corto_charDeclareChild_auto(_parent, _name) corto_char* _name = corto_charDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_charDefine(corto_char* _this, corto_char value);
#define corto_charDefine(_this, value) _corto_charDefine(_this, value)
CORTO_EXPORT void _corto_charSet(corto_char* _this, corto_char value);
#define corto_charSet(_this, value) _corto_charSet(_this, value)
CORTO_EXPORT corto_string _corto_charStr(corto_char value);
#define corto_charStr(value) _corto_charStr(value)
CORTO_EXPORT corto_char* corto_charFromStr(corto_char* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_charCompare(corto_char dst, corto_char src);

CORTO_EXPORT corto_int16 _corto_charInit(corto_char* value);
#define corto_charInit(value) _corto_charInit(value)
CORTO_EXPORT corto_int16 _corto_charDeinit(corto_char* value);
#define corto_charDeinit(value) _corto_charDeinit(value)

/* character */
CORTO_EXPORT corto_character _corto_characterCreate(corto_width width);
#define corto_characterCreate(width) _corto_characterCreate(width)
#define corto_characterCreate_auto(_name, width) corto_character _name = corto_characterCreate(width); (void)_name
CORTO_EXPORT corto_character _corto_characterCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_characterCreateChild(_parent, _name, width) _corto_characterCreateChild(_parent, _name, width)
#define corto_characterCreateChild_auto(_parent, _name, width) corto_character _name = corto_characterCreateChild(_parent, #_name, width); (void)_name
CORTO_EXPORT corto_int16 _corto_characterUpdate(corto_character _this, corto_width width);
#define corto_characterUpdate(_this, width) _corto_characterUpdate(corto_character(_this), width)

CORTO_EXPORT corto_character _corto_characterDeclare(void);
#define corto_characterDeclare() _corto_characterDeclare()
#define corto_characterDeclare_auto(_name) corto_character _name = corto_characterDeclare(); (void)_name
CORTO_EXPORT corto_character _corto_characterDeclareChild(corto_object _parent, corto_string _name);
#define corto_characterDeclareChild(_parent, _name) _corto_characterDeclareChild(_parent, _name)
#define corto_characterDeclareChild_auto(_parent, _name) corto_character _name = corto_characterDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_characterDefine(corto_character _this, corto_width width);
#define corto_characterDefine(_this, width) _corto_characterDefine(corto_character(_this), width)
CORTO_EXPORT void _corto_characterSet(corto_character _this, corto_width width);
#define corto_characterSet(_this, width) _corto_characterSet(corto_character(_this), width)
CORTO_EXPORT corto_string _corto_characterStr(corto_character value);
#define corto_characterStr(value) _corto_characterStr(corto_character(value))
CORTO_EXPORT corto_character corto_characterFromStr(corto_character value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_characterCompare(corto_character dst, corto_character src);
#define corto_characterCompare(dst, src) _corto_characterCompare(corto_character(dst), corto_character(src))

/* class */
CORTO_EXPORT corto_class _corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreate(base, baseAccess, implements) _corto_classCreate(corto_interface(base), baseAccess, implements)
#define corto_classCreate_auto(_name, base, baseAccess, implements) corto_class _name = corto_classCreate(base, baseAccess, implements); (void)_name
CORTO_EXPORT corto_class _corto_classCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classCreateChild(_parent, _name, base, baseAccess, implements) _corto_classCreateChild(_parent, _name, corto_interface(base), baseAccess, implements)
#define corto_classCreateChild_auto(_parent, _name, base, baseAccess, implements) corto_class _name = corto_classCreateChild(_parent, #_name, base, baseAccess, implements); (void)_name
CORTO_EXPORT corto_int16 _corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classUpdate(_this, base, baseAccess, implements) _corto_classUpdate(corto_class(_this), corto_interface(base), baseAccess, implements)

CORTO_EXPORT corto_class _corto_classDeclare(void);
#define corto_classDeclare() _corto_classDeclare()
#define corto_classDeclare_auto(_name) corto_class _name = corto_classDeclare(); (void)_name
CORTO_EXPORT corto_class _corto_classDeclareChild(corto_object _parent, corto_string _name);
#define corto_classDeclareChild(_parent, _name) _corto_classDeclareChild(_parent, _name)
#define corto_classDeclareChild_auto(_parent, _name) corto_class _name = corto_classDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classDefine(_this, base, baseAccess, implements) _corto_classDefine(corto_class(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT void _corto_classSet(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_classSet(_this, base, baseAccess, implements) _corto_classSet(corto_class(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT corto_string _corto_classStr(corto_class value);
#define corto_classStr(value) _corto_classStr(corto_class(value))
CORTO_EXPORT corto_class corto_classFromStr(corto_class value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_classCompare(corto_class dst, corto_class src);
#define corto_classCompare(dst, src) _corto_classCompare(corto_class(dst), corto_class(src))

/* collection */
CORTO_EXPORT corto_collection _corto_collectionCreate(corto_type elementType, corto_uint32 max);
#define corto_collectionCreate(elementType, max) _corto_collectionCreate(corto_type(elementType), max)
#define corto_collectionCreate_auto(_name, elementType, max) corto_collection _name = corto_collectionCreate(elementType, max); (void)_name
CORTO_EXPORT corto_collection _corto_collectionCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_collectionCreateChild(_parent, _name, elementType, max) _corto_collectionCreateChild(_parent, _name, corto_type(elementType), max)
#define corto_collectionCreateChild_auto(_parent, _name, elementType, max) corto_collection _name = corto_collectionCreateChild(_parent, #_name, elementType, max); (void)_name
CORTO_EXPORT corto_int16 _corto_collectionUpdate(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionUpdate(_this, elementType, max) _corto_collectionUpdate(corto_collection(_this), corto_type(elementType), max)

CORTO_EXPORT corto_collection _corto_collectionDeclare(void);
#define corto_collectionDeclare() _corto_collectionDeclare()
#define corto_collectionDeclare_auto(_name) corto_collection _name = corto_collectionDeclare(); (void)_name
CORTO_EXPORT corto_collection _corto_collectionDeclareChild(corto_object _parent, corto_string _name);
#define corto_collectionDeclareChild(_parent, _name) _corto_collectionDeclareChild(_parent, _name)
#define corto_collectionDeclareChild_auto(_parent, _name) corto_collection _name = corto_collectionDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_collectionDefine(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionDefine(_this, elementType, max) _corto_collectionDefine(corto_collection(_this), corto_type(elementType), max)
CORTO_EXPORT void _corto_collectionSet(corto_collection _this, corto_type elementType, corto_uint32 max);
#define corto_collectionSet(_this, elementType, max) _corto_collectionSet(corto_collection(_this), corto_type(elementType), max)
CORTO_EXPORT corto_string _corto_collectionStr(corto_collection value);
#define corto_collectionStr(value) _corto_collectionStr(corto_collection(value))
CORTO_EXPORT corto_collection corto_collectionFromStr(corto_collection value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_collectionCompare(corto_collection dst, corto_collection src);
#define corto_collectionCompare(dst, src) _corto_collectionCompare(corto_collection(dst), corto_collection(src))

/* collectionKind */
CORTO_EXPORT corto_collectionKind* _corto_collectionKindCreate(corto_collectionKind value);
#define corto_collectionKindCreate(value) _corto_collectionKindCreate(value)
#define corto_collectionKindCreate_auto(_name, value) corto_collectionKind* _name = corto_collectionKindCreate(value); (void)_name
CORTO_EXPORT corto_collectionKind* _corto_collectionKindCreateChild(corto_object _parent, corto_string _name, corto_collectionKind value);
#define corto_collectionKindCreateChild(_parent, _name, value) _corto_collectionKindCreateChild(_parent, _name, value)
#define corto_collectionKindCreateChild_auto(_parent, _name, value) corto_collectionKind* _name = corto_collectionKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindUpdate(_this, value) _corto_collectionKindUpdate(_this, value)

CORTO_EXPORT corto_collectionKind* _corto_collectionKindDeclare(void);
#define corto_collectionKindDeclare() _corto_collectionKindDeclare()
#define corto_collectionKindDeclare_auto(_name) corto_collectionKind* _name = corto_collectionKindDeclare(); (void)_name
CORTO_EXPORT corto_collectionKind* _corto_collectionKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_collectionKindDeclareChild(_parent, _name) _corto_collectionKindDeclareChild(_parent, _name)
#define corto_collectionKindDeclareChild_auto(_parent, _name) corto_collectionKind* _name = corto_collectionKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindDefine(_this, value) _corto_collectionKindDefine(_this, value)
CORTO_EXPORT void _corto_collectionKindSet(corto_collectionKind* _this, corto_collectionKind value);
#define corto_collectionKindSet(_this, value) _corto_collectionKindSet(_this, value)
CORTO_EXPORT corto_string _corto_collectionKindStr(corto_collectionKind value);
#define corto_collectionKindStr(value) _corto_collectionKindStr(value)
CORTO_EXPORT corto_collectionKind* corto_collectionKindFromStr(corto_collectionKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_collectionKindCompare(corto_collectionKind dst, corto_collectionKind src);

CORTO_EXPORT corto_int16 _corto_collectionKindInit(corto_collectionKind* value);
#define corto_collectionKindInit(value) _corto_collectionKindInit(value)
CORTO_EXPORT corto_int16 _corto_collectionKindDeinit(corto_collectionKind* value);
#define corto_collectionKindDeinit(value) _corto_collectionKindDeinit(value)

/* compositeKind */
CORTO_EXPORT corto_compositeKind* _corto_compositeKindCreate(corto_compositeKind value);
#define corto_compositeKindCreate(value) _corto_compositeKindCreate(value)
#define corto_compositeKindCreate_auto(_name, value) corto_compositeKind* _name = corto_compositeKindCreate(value); (void)_name
CORTO_EXPORT corto_compositeKind* _corto_compositeKindCreateChild(corto_object _parent, corto_string _name, corto_compositeKind value);
#define corto_compositeKindCreateChild(_parent, _name, value) _corto_compositeKindCreateChild(_parent, _name, value)
#define corto_compositeKindCreateChild_auto(_parent, _name, value) corto_compositeKind* _name = corto_compositeKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindUpdate(_this, value) _corto_compositeKindUpdate(_this, value)

CORTO_EXPORT corto_compositeKind* _corto_compositeKindDeclare(void);
#define corto_compositeKindDeclare() _corto_compositeKindDeclare()
#define corto_compositeKindDeclare_auto(_name) corto_compositeKind* _name = corto_compositeKindDeclare(); (void)_name
CORTO_EXPORT corto_compositeKind* _corto_compositeKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_compositeKindDeclareChild(_parent, _name) _corto_compositeKindDeclareChild(_parent, _name)
#define corto_compositeKindDeclareChild_auto(_parent, _name) corto_compositeKind* _name = corto_compositeKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindDefine(_this, value) _corto_compositeKindDefine(_this, value)
CORTO_EXPORT void _corto_compositeKindSet(corto_compositeKind* _this, corto_compositeKind value);
#define corto_compositeKindSet(_this, value) _corto_compositeKindSet(_this, value)
CORTO_EXPORT corto_string _corto_compositeKindStr(corto_compositeKind value);
#define corto_compositeKindStr(value) _corto_compositeKindStr(value)
CORTO_EXPORT corto_compositeKind* corto_compositeKindFromStr(corto_compositeKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_compositeKindCompare(corto_compositeKind dst, corto_compositeKind src);

CORTO_EXPORT corto_int16 _corto_compositeKindInit(corto_compositeKind* value);
#define corto_compositeKindInit(value) _corto_compositeKindInit(value)
CORTO_EXPORT corto_int16 _corto_compositeKindDeinit(corto_compositeKind* value);
#define corto_compositeKindDeinit(value) _corto_compositeKindDeinit(value)

/* constant */
CORTO_EXPORT corto_constant* _corto_constantCreate(corto_constant value);
#define corto_constantCreate(value) _corto_constantCreate(value)
#define corto_constantCreate_auto(_name, value) corto_constant* _name = corto_constantCreate(value); (void)_name
CORTO_EXPORT corto_constant* _corto_constantCreateChild(corto_object _parent, corto_string _name, corto_constant value);
#define corto_constantCreateChild(_parent, _name, value) _corto_constantCreateChild(_parent, _name, value)
#define corto_constantCreateChild_auto(_parent, _name, value) corto_constant* _name = corto_constantCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_constantUpdate(corto_constant* _this, corto_constant value);
#define corto_constantUpdate(_this, value) _corto_constantUpdate(_this, value)

CORTO_EXPORT corto_constant* _corto_constantDeclare(void);
#define corto_constantDeclare() _corto_constantDeclare()
#define corto_constantDeclare_auto(_name) corto_constant* _name = corto_constantDeclare(); (void)_name
CORTO_EXPORT corto_constant* _corto_constantDeclareChild(corto_object _parent, corto_string _name);
#define corto_constantDeclareChild(_parent, _name) _corto_constantDeclareChild(_parent, _name)
#define corto_constantDeclareChild_auto(_parent, _name) corto_constant* _name = corto_constantDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_constantDefine(corto_constant* _this, corto_constant value);
#define corto_constantDefine(_this, value) _corto_constantDefine(_this, value)
CORTO_EXPORT void _corto_constantSet(corto_constant* _this, corto_constant value);
#define corto_constantSet(_this, value) _corto_constantSet(_this, value)
CORTO_EXPORT corto_string _corto_constantStr(corto_constant value);
#define corto_constantStr(value) _corto_constantStr(value)
CORTO_EXPORT corto_constant* corto_constantFromStr(corto_constant* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_constantCompare(corto_constant dst, corto_constant src);

CORTO_EXPORT corto_int16 _corto_constantInit(corto_constant* value);
#define corto_constantInit(value) _corto_constantInit(value)
CORTO_EXPORT corto_int16 _corto_constantDeinit(corto_constant* value);
#define corto_constantDeinit(value) _corto_constantDeinit(value)

/* delegate */
CORTO_EXPORT corto_delegate _corto_delegateCreate(corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreate(returnType, returnsReference, parameters) _corto_delegateCreate(corto_type(returnType), returnsReference, parameters)
#define corto_delegateCreate_auto(_name, returnType, returnsReference, parameters) corto_delegate _name = corto_delegateCreate(returnType, returnsReference, parameters); (void)_name
CORTO_EXPORT corto_delegate _corto_delegateCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateCreateChild(_parent, _name, returnType, returnsReference, parameters) _corto_delegateCreateChild(_parent, _name, corto_type(returnType), returnsReference, parameters)
#define corto_delegateCreateChild_auto(_parent, _name, returnType, returnsReference, parameters) corto_delegate _name = corto_delegateCreateChild(_parent, #_name, returnType, returnsReference, parameters); (void)_name
CORTO_EXPORT corto_int16 _corto_delegateUpdate(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateUpdate(_this, returnType, returnsReference, parameters) _corto_delegateUpdate(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)

CORTO_EXPORT corto_delegate _corto_delegateDeclare(void);
#define corto_delegateDeclare() _corto_delegateDeclare()
#define corto_delegateDeclare_auto(_name) corto_delegate _name = corto_delegateDeclare(); (void)_name
CORTO_EXPORT corto_delegate _corto_delegateDeclareChild(corto_object _parent, corto_string _name);
#define corto_delegateDeclareChild(_parent, _name) _corto_delegateDeclareChild(_parent, _name)
#define corto_delegateDeclareChild_auto(_parent, _name) corto_delegate _name = corto_delegateDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_delegateDefine(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateDefine(_this, returnType, returnsReference, parameters) _corto_delegateDefine(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)
CORTO_EXPORT void _corto_delegateSet(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
#define corto_delegateSet(_this, returnType, returnsReference, parameters) _corto_delegateSet(corto_delegate(_this), corto_type(returnType), returnsReference, parameters)
CORTO_EXPORT corto_string _corto_delegateStr(corto_delegate value);
#define corto_delegateStr(value) _corto_delegateStr(corto_delegate(value))
CORTO_EXPORT corto_delegate corto_delegateFromStr(corto_delegate value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_delegateCompare(corto_delegate dst, corto_delegate src);
#define corto_delegateCompare(dst, src) _corto_delegateCompare(corto_delegate(dst), corto_delegate(src))

/* delegatedata */
CORTO_EXPORT corto_delegatedata* _corto_delegatedataCreate(corto_object instance, corto_function procedure);
#define corto_delegatedataCreate(instance, procedure) _corto_delegatedataCreate(instance, corto_function(procedure))
#define corto_delegatedataCreate_auto(_name, instance, procedure) corto_delegatedata* _name = corto_delegatedataCreate(instance, procedure); (void)_name
CORTO_EXPORT corto_delegatedata* _corto_delegatedataCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_delegatedataCreateChild(_parent, _name, instance, procedure) _corto_delegatedataCreateChild(_parent, _name, instance, corto_function(procedure))
#define corto_delegatedataCreateChild_auto(_parent, _name, instance, procedure) corto_delegatedata* _name = corto_delegatedataCreateChild(_parent, #_name, instance, procedure); (void)_name
CORTO_EXPORT corto_int16 _corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataUpdate(_this, instance, procedure) _corto_delegatedataUpdate(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_delegatedata* _corto_delegatedataDeclare(void);
#define corto_delegatedataDeclare() _corto_delegatedataDeclare()
#define corto_delegatedataDeclare_auto(_name) corto_delegatedata* _name = corto_delegatedataDeclare(); (void)_name
CORTO_EXPORT corto_delegatedata* _corto_delegatedataDeclareChild(corto_object _parent, corto_string _name);
#define corto_delegatedataDeclareChild(_parent, _name) _corto_delegatedataDeclareChild(_parent, _name)
#define corto_delegatedataDeclareChild_auto(_parent, _name) corto_delegatedata* _name = corto_delegatedataDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataDefine(_this, instance, procedure) _corto_delegatedataDefine(_this, instance, corto_function(procedure))
CORTO_EXPORT void _corto_delegatedataSet(corto_delegatedata* _this, corto_object instance, corto_function procedure);
#define corto_delegatedataSet(_this, instance, procedure) _corto_delegatedataSet(_this, instance, corto_function(procedure))
CORTO_EXPORT corto_string _corto_delegatedataStr(corto_delegatedata* value);
#define corto_delegatedataStr(value) _corto_delegatedataStr(value)
CORTO_EXPORT corto_delegatedata* corto_delegatedataFromStr(corto_delegatedata* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_delegatedataCompare(corto_delegatedata* dst, corto_delegatedata* src);

CORTO_EXPORT corto_int16 _corto_delegatedataInit(corto_delegatedata* value);
#define corto_delegatedataInit(value) _corto_delegatedataInit(value)
CORTO_EXPORT corto_int16 _corto_delegatedataDeinit(corto_delegatedata* value);
#define corto_delegatedataDeinit(value) _corto_delegatedataDeinit(value)

/* destructAction */
CORTO_EXPORT corto_destructAction* _corto_destructActionCreate(corto_object instance, corto_function procedure);
#define corto_destructActionCreate(instance, procedure) _corto_destructActionCreate(instance, corto_function(procedure))
#define corto_destructActionCreate_auto(_name, instance, procedure) corto_destructAction* _name = corto_destructActionCreate(instance, procedure); (void)_name
CORTO_EXPORT corto_destructAction* _corto_destructActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_destructActionCreateChild(_parent, _name, instance, procedure) _corto_destructActionCreateChild(_parent, _name, instance, corto_function(procedure))
#define corto_destructActionCreateChild_auto(_parent, _name, instance, procedure) corto_destructAction* _name = corto_destructActionCreateChild(_parent, #_name, instance, procedure); (void)_name
CORTO_EXPORT corto_int16 _corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionUpdate(_this, instance, procedure) _corto_destructActionUpdate(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_destructAction* _corto_destructActionDeclare(void);
#define corto_destructActionDeclare() _corto_destructActionDeclare()
#define corto_destructActionDeclare_auto(_name) corto_destructAction* _name = corto_destructActionDeclare(); (void)_name
CORTO_EXPORT corto_destructAction* _corto_destructActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_destructActionDeclareChild(_parent, _name) _corto_destructActionDeclareChild(_parent, _name)
#define corto_destructActionDeclareChild_auto(_parent, _name) corto_destructAction* _name = corto_destructActionDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_destructActionDefine(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionDefine(_this, instance, procedure) _corto_destructActionDefine(_this, instance, corto_function(procedure))
CORTO_EXPORT void _corto_destructActionSet(corto_destructAction* _this, corto_object instance, corto_function procedure);
#define corto_destructActionSet(_this, instance, procedure) _corto_destructActionSet(_this, instance, corto_function(procedure))
CORTO_EXPORT corto_string _corto_destructActionStr(corto_destructAction* value);
#define corto_destructActionStr(value) _corto_destructActionStr(value)
CORTO_EXPORT corto_destructAction* corto_destructActionFromStr(corto_destructAction* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_destructActionCompare(corto_destructAction* dst, corto_destructAction* src);

CORTO_EXPORT corto_int16 _corto_destructActionInit(corto_destructAction* value);
#define corto_destructActionInit(value) _corto_destructActionInit(value)
CORTO_EXPORT corto_int16 _corto_destructActionDeinit(corto_destructAction* value);
#define corto_destructActionDeinit(value) _corto_destructActionDeinit(value)

corto_int16 corto_destructActionCall(corto_destructAction *_delegate);
#define corto_destructActionInitC_auto(d, callback) corto_destructAction d; corto_destructActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_destructActionInitC(corto_destructAction *d, corto_void ___ (*callback)(void));
#define corto_destructActionInitCInstance_auto(d, instance, callback)corto_destructAction d; corto_destructActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_destructActionInitCInstance(corto_destructAction *d, corto_object instance, corto_void ___ (*callback)(corto_object));
/* enum */
CORTO_EXPORT corto_enum _corto_enumCreate(void);
#define corto_enumCreate() _corto_enumCreate()
#define corto_enumCreate_auto(_name) corto_enum _name = corto_enumCreate(); (void)_name
CORTO_EXPORT corto_enum _corto_enumCreateChild(corto_object _parent, corto_string _name);
#define corto_enumCreateChild(_parent, _name) _corto_enumCreateChild(_parent, _name)
#define corto_enumCreateChild_auto(_parent, _name) corto_enum _name = corto_enumCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_enumUpdate(corto_enum _this);
#define corto_enumUpdate(_this) _corto_enumUpdate(corto_enum(_this))

CORTO_EXPORT corto_enum _corto_enumDeclare(void);
#define corto_enumDeclare() _corto_enumDeclare()
#define corto_enumDeclare_auto(_name) corto_enum _name = corto_enumDeclare(); (void)_name
CORTO_EXPORT corto_enum _corto_enumDeclareChild(corto_object _parent, corto_string _name);
#define corto_enumDeclareChild(_parent, _name) _corto_enumDeclareChild(_parent, _name)
#define corto_enumDeclareChild_auto(_parent, _name) corto_enum _name = corto_enumDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_enumDefine(corto_enum _this);
#define corto_enumDefine(_this) _corto_enumDefine(corto_enum(_this))
CORTO_EXPORT void _corto_enumSet(corto_enum _this);
#define corto_enumSet(_this) _corto_enumSet(corto_enum(_this))
CORTO_EXPORT corto_string _corto_enumStr(corto_enum value);
#define corto_enumStr(value) _corto_enumStr(corto_enum(value))
CORTO_EXPORT corto_enum corto_enumFromStr(corto_enum value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_enumCompare(corto_enum dst, corto_enum src);
#define corto_enumCompare(dst, src) _corto_enumCompare(corto_enum(dst), corto_enum(src))

/* equalityKind */
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
CORTO_EXPORT corto_equalityKind corto_equalityKindCompare(corto_equalityKind dst, corto_equalityKind src);

CORTO_EXPORT corto_int16 _corto_equalityKindInit(corto_equalityKind* value);
#define corto_equalityKindInit(value) _corto_equalityKindInit(value)
CORTO_EXPORT corto_int16 _corto_equalityKindDeinit(corto_equalityKind* value);
#define corto_equalityKindDeinit(value) _corto_equalityKindDeinit(value)

/* float */
CORTO_EXPORT corto_float _corto_floatCreate(corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatCreate(width, min, max) _corto_floatCreate(width, min, max)
#define corto_floatCreate_auto(_name, width, min, max) corto_float _name = corto_floatCreate(width, min, max); (void)_name
CORTO_EXPORT corto_float _corto_floatCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatCreateChild(_parent, _name, width, min, max) _corto_floatCreateChild(_parent, _name, width, min, max)
#define corto_floatCreateChild_auto(_parent, _name, width, min, max) corto_float _name = corto_floatCreateChild(_parent, #_name, width, min, max); (void)_name
CORTO_EXPORT corto_int16 _corto_floatUpdate(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatUpdate(_this, width, min, max) _corto_floatUpdate(corto_float(_this), width, min, max)

CORTO_EXPORT corto_float _corto_floatDeclare(void);
#define corto_floatDeclare() _corto_floatDeclare()
#define corto_floatDeclare_auto(_name) corto_float _name = corto_floatDeclare(); (void)_name
CORTO_EXPORT corto_float _corto_floatDeclareChild(corto_object _parent, corto_string _name);
#define corto_floatDeclareChild(_parent, _name) _corto_floatDeclareChild(_parent, _name)
#define corto_floatDeclareChild_auto(_parent, _name) corto_float _name = corto_floatDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_floatDefine(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatDefine(_this, width, min, max) _corto_floatDefine(corto_float(_this), width, min, max)
CORTO_EXPORT void _corto_floatSet(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
#define corto_floatSet(_this, width, min, max) _corto_floatSet(corto_float(_this), width, min, max)
CORTO_EXPORT corto_string _corto_floatStr(corto_float value);
#define corto_floatStr(value) _corto_floatStr(corto_float(value))
CORTO_EXPORT corto_float corto_floatFromStr(corto_float value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_floatCompare(corto_float dst, corto_float src);
#define corto_floatCompare(dst, src) _corto_floatCompare(corto_float(dst), corto_float(src))

/* float32 */
CORTO_EXPORT corto_float32* _corto_float32Create(corto_float32 value);
#define corto_float32Create(value) _corto_float32Create(value)
#define corto_float32Create_auto(_name, value) corto_float32* _name = corto_float32Create(value); (void)_name
CORTO_EXPORT corto_float32* _corto_float32CreateChild(corto_object _parent, corto_string _name, corto_float32 value);
#define corto_float32CreateChild(_parent, _name, value) _corto_float32CreateChild(_parent, _name, value)
#define corto_float32CreateChild_auto(_parent, _name, value) corto_float32* _name = corto_float32CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_float32Update(corto_float32* _this, corto_float32 value);
#define corto_float32Update(_this, value) _corto_float32Update(_this, value)

CORTO_EXPORT corto_float32* _corto_float32Declare(void);
#define corto_float32Declare() _corto_float32Declare()
#define corto_float32Declare_auto(_name) corto_float32* _name = corto_float32Declare(); (void)_name
CORTO_EXPORT corto_float32* _corto_float32DeclareChild(corto_object _parent, corto_string _name);
#define corto_float32DeclareChild(_parent, _name) _corto_float32DeclareChild(_parent, _name)
#define corto_float32DeclareChild_auto(_parent, _name) corto_float32* _name = corto_float32DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_float32Define(corto_float32* _this, corto_float32 value);
#define corto_float32Define(_this, value) _corto_float32Define(_this, value)
CORTO_EXPORT void _corto_float32Set(corto_float32* _this, corto_float32 value);
#define corto_float32Set(_this, value) _corto_float32Set(_this, value)
CORTO_EXPORT corto_string _corto_float32Str(corto_float32 value);
#define corto_float32Str(value) _corto_float32Str(value)
CORTO_EXPORT corto_float32* corto_float32FromStr(corto_float32* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_float32Compare(corto_float32 dst, corto_float32 src);

CORTO_EXPORT corto_int16 _corto_float32Init(corto_float32* value);
#define corto_float32Init(value) _corto_float32Init(value)
CORTO_EXPORT corto_int16 _corto_float32Deinit(corto_float32* value);
#define corto_float32Deinit(value) _corto_float32Deinit(value)

/* float64 */
CORTO_EXPORT corto_float64* _corto_float64Create(corto_float64 value);
#define corto_float64Create(value) _corto_float64Create(value)
#define corto_float64Create_auto(_name, value) corto_float64* _name = corto_float64Create(value); (void)_name
CORTO_EXPORT corto_float64* _corto_float64CreateChild(corto_object _parent, corto_string _name, corto_float64 value);
#define corto_float64CreateChild(_parent, _name, value) _corto_float64CreateChild(_parent, _name, value)
#define corto_float64CreateChild_auto(_parent, _name, value) corto_float64* _name = corto_float64CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_float64Update(corto_float64* _this, corto_float64 value);
#define corto_float64Update(_this, value) _corto_float64Update(_this, value)

CORTO_EXPORT corto_float64* _corto_float64Declare(void);
#define corto_float64Declare() _corto_float64Declare()
#define corto_float64Declare_auto(_name) corto_float64* _name = corto_float64Declare(); (void)_name
CORTO_EXPORT corto_float64* _corto_float64DeclareChild(corto_object _parent, corto_string _name);
#define corto_float64DeclareChild(_parent, _name) _corto_float64DeclareChild(_parent, _name)
#define corto_float64DeclareChild_auto(_parent, _name) corto_float64* _name = corto_float64DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_float64Define(corto_float64* _this, corto_float64 value);
#define corto_float64Define(_this, value) _corto_float64Define(_this, value)
CORTO_EXPORT void _corto_float64Set(corto_float64* _this, corto_float64 value);
#define corto_float64Set(_this, value) _corto_float64Set(_this, value)
CORTO_EXPORT corto_string _corto_float64Str(corto_float64 value);
#define corto_float64Str(value) _corto_float64Str(value)
CORTO_EXPORT corto_float64* corto_float64FromStr(corto_float64* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_float64Compare(corto_float64 dst, corto_float64 src);

CORTO_EXPORT corto_int16 _corto_float64Init(corto_float64* value);
#define corto_float64Init(value) _corto_float64Init(value)
CORTO_EXPORT corto_int16 _corto_float64Deinit(corto_float64* value);
#define corto_float64Deinit(value) _corto_float64Deinit(value)

/* function */
CORTO_EXPORT corto_function _corto_functionCreate(corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionCreate(returnType, returnsReference, _impl) _corto_functionCreate(corto_type(returnType), returnsReference, _impl)
#define corto_functionCreate_auto(_name, returnType, returnsReference, _impl) corto_function _name = corto_functionCreate(returnType, returnsReference, _impl); (void)_name
CORTO_EXPORT corto_function _corto_functionCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionCreateChild(_parent, _name, returnType, returnsReference, _impl) _corto_functionCreateChild(_parent, _name, corto_type(returnType), returnsReference, _impl)
#define corto_functionCreateChild_auto(_parent, _name, returnType, returnsReference, _impl) corto_function _name = corto_functionCreateChild(_parent, #_name, returnType, returnsReference, _impl); (void)_name
CORTO_EXPORT corto_int16 _corto_functionUpdate(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionUpdate(_this, returnType, returnsReference, _impl) _corto_functionUpdate(corto_function(_this), corto_type(returnType), returnsReference, _impl)

CORTO_EXPORT corto_function _corto_functionDeclare(void);
#define corto_functionDeclare() _corto_functionDeclare()
#define corto_functionDeclare_auto(_name) corto_function _name = corto_functionDeclare(); (void)_name
CORTO_EXPORT corto_function _corto_functionDeclareChild(corto_object _parent, corto_string _name);
#define corto_functionDeclareChild(_parent, _name) _corto_functionDeclareChild(_parent, _name)
#define corto_functionDeclareChild_auto(_parent, _name) corto_function _name = corto_functionDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_functionDefine(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionDefine(_this, returnType, returnsReference, _impl) _corto_functionDefine(corto_function(_this), corto_type(returnType), returnsReference, _impl)
CORTO_EXPORT void _corto_functionSet(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
#define corto_functionSet(_this, returnType, returnsReference, _impl) _corto_functionSet(corto_function(_this), corto_type(returnType), returnsReference, _impl)
CORTO_EXPORT corto_string _corto_functionStr(corto_function value);
#define corto_functionStr(value) _corto_functionStr(corto_function(value))
CORTO_EXPORT corto_function corto_functionFromStr(corto_function value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_functionCompare(corto_function dst, corto_function src);
#define corto_functionCompare(dst, src) _corto_functionCompare(corto_function(dst), corto_function(src))

/* initAction */
CORTO_EXPORT corto_initAction* _corto_initActionCreate(corto_object instance, corto_function procedure);
#define corto_initActionCreate(instance, procedure) _corto_initActionCreate(instance, corto_function(procedure))
#define corto_initActionCreate_auto(_name, instance, procedure) corto_initAction* _name = corto_initActionCreate(instance, procedure); (void)_name
CORTO_EXPORT corto_initAction* _corto_initActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
#define corto_initActionCreateChild(_parent, _name, instance, procedure) _corto_initActionCreateChild(_parent, _name, instance, corto_function(procedure))
#define corto_initActionCreateChild_auto(_parent, _name, instance, procedure) corto_initAction* _name = corto_initActionCreateChild(_parent, #_name, instance, procedure); (void)_name
CORTO_EXPORT corto_int16 _corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionUpdate(_this, instance, procedure) _corto_initActionUpdate(_this, instance, corto_function(procedure))

CORTO_EXPORT corto_initAction* _corto_initActionDeclare(void);
#define corto_initActionDeclare() _corto_initActionDeclare()
#define corto_initActionDeclare_auto(_name) corto_initAction* _name = corto_initActionDeclare(); (void)_name
CORTO_EXPORT corto_initAction* _corto_initActionDeclareChild(corto_object _parent, corto_string _name);
#define corto_initActionDeclareChild(_parent, _name) _corto_initActionDeclareChild(_parent, _name)
#define corto_initActionDeclareChild_auto(_parent, _name) corto_initAction* _name = corto_initActionDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_initActionDefine(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionDefine(_this, instance, procedure) _corto_initActionDefine(_this, instance, corto_function(procedure))
CORTO_EXPORT void _corto_initActionSet(corto_initAction* _this, corto_object instance, corto_function procedure);
#define corto_initActionSet(_this, instance, procedure) _corto_initActionSet(_this, instance, corto_function(procedure))
CORTO_EXPORT corto_string _corto_initActionStr(corto_initAction* value);
#define corto_initActionStr(value) _corto_initActionStr(value)
CORTO_EXPORT corto_initAction* corto_initActionFromStr(corto_initAction* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_initActionCompare(corto_initAction* dst, corto_initAction* src);

CORTO_EXPORT corto_int16 _corto_initActionInit(corto_initAction* value);
#define corto_initActionInit(value) _corto_initActionInit(value)
CORTO_EXPORT corto_int16 _corto_initActionDeinit(corto_initAction* value);
#define corto_initActionDeinit(value) _corto_initActionDeinit(value)

corto_int16 corto_initActionCall(corto_initAction *_delegate, corto_int16* _result);
#define corto_initActionInitC_auto(d, callback) corto_initAction d; corto_initActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_initActionInitC(corto_initAction *d, corto_int16 ___ (*callback)(void));
#define corto_initActionInitCInstance_auto(d, instance, callback)corto_initAction d; corto_initActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_initActionInitCInstance(corto_initAction *d, corto_object instance, corto_int16 ___ (*callback)(corto_object));
/* int */
CORTO_EXPORT corto_int _corto_intCreate(corto_width width, corto_int64 min, corto_int64 max);
#define corto_intCreate(width, min, max) _corto_intCreate(width, min, max)
#define corto_intCreate_auto(_name, width, min, max) corto_int _name = corto_intCreate(width, min, max); (void)_name
CORTO_EXPORT corto_int _corto_intCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intCreateChild(_parent, _name, width, min, max) _corto_intCreateChild(_parent, _name, width, min, max)
#define corto_intCreateChild_auto(_parent, _name, width, min, max) corto_int _name = corto_intCreateChild(_parent, #_name, width, min, max); (void)_name
CORTO_EXPORT corto_int16 _corto_intUpdate(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intUpdate(_this, width, min, max) _corto_intUpdate(corto_int(_this), width, min, max)

CORTO_EXPORT corto_int _corto_intDeclare(void);
#define corto_intDeclare() _corto_intDeclare()
#define corto_intDeclare_auto(_name) corto_int _name = corto_intDeclare(); (void)_name
CORTO_EXPORT corto_int _corto_intDeclareChild(corto_object _parent, corto_string _name);
#define corto_intDeclareChild(_parent, _name) _corto_intDeclareChild(_parent, _name)
#define corto_intDeclareChild_auto(_parent, _name) corto_int _name = corto_intDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_intDefine(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intDefine(_this, width, min, max) _corto_intDefine(corto_int(_this), width, min, max)
CORTO_EXPORT void _corto_intSet(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
#define corto_intSet(_this, width, min, max) _corto_intSet(corto_int(_this), width, min, max)
CORTO_EXPORT corto_string _corto_intStr(corto_int value);
#define corto_intStr(value) _corto_intStr(corto_int(value))
CORTO_EXPORT corto_int corto_intFromStr(corto_int value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_intCompare(corto_int dst, corto_int src);
#define corto_intCompare(dst, src) _corto_intCompare(corto_int(dst), corto_int(src))

/* int16 */
CORTO_EXPORT corto_int16* _corto_int16Create(corto_int16 value);
#define corto_int16Create(value) _corto_int16Create(value)
#define corto_int16Create_auto(_name, value) corto_int16* _name = corto_int16Create(value); (void)_name
CORTO_EXPORT corto_int16* _corto_int16CreateChild(corto_object _parent, corto_string _name, corto_int16 value);
#define corto_int16CreateChild(_parent, _name, value) _corto_int16CreateChild(_parent, _name, value)
#define corto_int16CreateChild_auto(_parent, _name, value) corto_int16* _name = corto_int16CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_int16Update(corto_int16* _this, corto_int16 value);
#define corto_int16Update(_this, value) _corto_int16Update(_this, value)

CORTO_EXPORT corto_int16* _corto_int16Declare(void);
#define corto_int16Declare() _corto_int16Declare()
#define corto_int16Declare_auto(_name) corto_int16* _name = corto_int16Declare(); (void)_name
CORTO_EXPORT corto_int16* _corto_int16DeclareChild(corto_object _parent, corto_string _name);
#define corto_int16DeclareChild(_parent, _name) _corto_int16DeclareChild(_parent, _name)
#define corto_int16DeclareChild_auto(_parent, _name) corto_int16* _name = corto_int16DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_int16Define(corto_int16* _this, corto_int16 value);
#define corto_int16Define(_this, value) _corto_int16Define(_this, value)
CORTO_EXPORT void _corto_int16Set(corto_int16* _this, corto_int16 value);
#define corto_int16Set(_this, value) _corto_int16Set(_this, value)
CORTO_EXPORT corto_string _corto_int16Str(corto_int16 value);
#define corto_int16Str(value) _corto_int16Str(value)
CORTO_EXPORT corto_int16* corto_int16FromStr(corto_int16* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_int16Compare(corto_int16 dst, corto_int16 src);

CORTO_EXPORT corto_int16 _corto_int16Init(corto_int16* value);
#define corto_int16Init(value) _corto_int16Init(value)
CORTO_EXPORT corto_int16 _corto_int16Deinit(corto_int16* value);
#define corto_int16Deinit(value) _corto_int16Deinit(value)

/* int32 */
CORTO_EXPORT corto_int32* _corto_int32Create(corto_int32 value);
#define corto_int32Create(value) _corto_int32Create(value)
#define corto_int32Create_auto(_name, value) corto_int32* _name = corto_int32Create(value); (void)_name
CORTO_EXPORT corto_int32* _corto_int32CreateChild(corto_object _parent, corto_string _name, corto_int32 value);
#define corto_int32CreateChild(_parent, _name, value) _corto_int32CreateChild(_parent, _name, value)
#define corto_int32CreateChild_auto(_parent, _name, value) corto_int32* _name = corto_int32CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_int32Update(corto_int32* _this, corto_int32 value);
#define corto_int32Update(_this, value) _corto_int32Update(_this, value)

CORTO_EXPORT corto_int32* _corto_int32Declare(void);
#define corto_int32Declare() _corto_int32Declare()
#define corto_int32Declare_auto(_name) corto_int32* _name = corto_int32Declare(); (void)_name
CORTO_EXPORT corto_int32* _corto_int32DeclareChild(corto_object _parent, corto_string _name);
#define corto_int32DeclareChild(_parent, _name) _corto_int32DeclareChild(_parent, _name)
#define corto_int32DeclareChild_auto(_parent, _name) corto_int32* _name = corto_int32DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_int32Define(corto_int32* _this, corto_int32 value);
#define corto_int32Define(_this, value) _corto_int32Define(_this, value)
CORTO_EXPORT void _corto_int32Set(corto_int32* _this, corto_int32 value);
#define corto_int32Set(_this, value) _corto_int32Set(_this, value)
CORTO_EXPORT corto_string _corto_int32Str(corto_int32 value);
#define corto_int32Str(value) _corto_int32Str(value)
CORTO_EXPORT corto_int32* corto_int32FromStr(corto_int32* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_int32Compare(corto_int32 dst, corto_int32 src);

CORTO_EXPORT corto_int16 _corto_int32Init(corto_int32* value);
#define corto_int32Init(value) _corto_int32Init(value)
CORTO_EXPORT corto_int16 _corto_int32Deinit(corto_int32* value);
#define corto_int32Deinit(value) _corto_int32Deinit(value)

/* int64 */
CORTO_EXPORT corto_int64* _corto_int64Create(corto_int64 value);
#define corto_int64Create(value) _corto_int64Create(value)
#define corto_int64Create_auto(_name, value) corto_int64* _name = corto_int64Create(value); (void)_name
CORTO_EXPORT corto_int64* _corto_int64CreateChild(corto_object _parent, corto_string _name, corto_int64 value);
#define corto_int64CreateChild(_parent, _name, value) _corto_int64CreateChild(_parent, _name, value)
#define corto_int64CreateChild_auto(_parent, _name, value) corto_int64* _name = corto_int64CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_int64Update(corto_int64* _this, corto_int64 value);
#define corto_int64Update(_this, value) _corto_int64Update(_this, value)

CORTO_EXPORT corto_int64* _corto_int64Declare(void);
#define corto_int64Declare() _corto_int64Declare()
#define corto_int64Declare_auto(_name) corto_int64* _name = corto_int64Declare(); (void)_name
CORTO_EXPORT corto_int64* _corto_int64DeclareChild(corto_object _parent, corto_string _name);
#define corto_int64DeclareChild(_parent, _name) _corto_int64DeclareChild(_parent, _name)
#define corto_int64DeclareChild_auto(_parent, _name) corto_int64* _name = corto_int64DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_int64Define(corto_int64* _this, corto_int64 value);
#define corto_int64Define(_this, value) _corto_int64Define(_this, value)
CORTO_EXPORT void _corto_int64Set(corto_int64* _this, corto_int64 value);
#define corto_int64Set(_this, value) _corto_int64Set(_this, value)
CORTO_EXPORT corto_string _corto_int64Str(corto_int64 value);
#define corto_int64Str(value) _corto_int64Str(value)
CORTO_EXPORT corto_int64* corto_int64FromStr(corto_int64* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_int64Compare(corto_int64 dst, corto_int64 src);

CORTO_EXPORT corto_int16 _corto_int64Init(corto_int64* value);
#define corto_int64Init(value) _corto_int64Init(value)
CORTO_EXPORT corto_int16 _corto_int64Deinit(corto_int64* value);
#define corto_int64Deinit(value) _corto_int64Deinit(value)

/* int8 */
CORTO_EXPORT corto_int8* _corto_int8Create(corto_int8 value);
#define corto_int8Create(value) _corto_int8Create(value)
#define corto_int8Create_auto(_name, value) corto_int8* _name = corto_int8Create(value); (void)_name
CORTO_EXPORT corto_int8* _corto_int8CreateChild(corto_object _parent, corto_string _name, corto_int8 value);
#define corto_int8CreateChild(_parent, _name, value) _corto_int8CreateChild(_parent, _name, value)
#define corto_int8CreateChild_auto(_parent, _name, value) corto_int8* _name = corto_int8CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_int8Update(corto_int8* _this, corto_int8 value);
#define corto_int8Update(_this, value) _corto_int8Update(_this, value)

CORTO_EXPORT corto_int8* _corto_int8Declare(void);
#define corto_int8Declare() _corto_int8Declare()
#define corto_int8Declare_auto(_name) corto_int8* _name = corto_int8Declare(); (void)_name
CORTO_EXPORT corto_int8* _corto_int8DeclareChild(corto_object _parent, corto_string _name);
#define corto_int8DeclareChild(_parent, _name) _corto_int8DeclareChild(_parent, _name)
#define corto_int8DeclareChild_auto(_parent, _name) corto_int8* _name = corto_int8DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_int8Define(corto_int8* _this, corto_int8 value);
#define corto_int8Define(_this, value) _corto_int8Define(_this, value)
CORTO_EXPORT void _corto_int8Set(corto_int8* _this, corto_int8 value);
#define corto_int8Set(_this, value) _corto_int8Set(_this, value)
CORTO_EXPORT corto_string _corto_int8Str(corto_int8 value);
#define corto_int8Str(value) _corto_int8Str(value)
CORTO_EXPORT corto_int8* corto_int8FromStr(corto_int8* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_int8Compare(corto_int8 dst, corto_int8 src);

CORTO_EXPORT corto_int16 _corto_int8Init(corto_int8* value);
#define corto_int8Init(value) _corto_int8Init(value)
CORTO_EXPORT corto_int16 _corto_int8Deinit(corto_int8* value);
#define corto_int8Deinit(value) _corto_int8Deinit(value)

/* interface */
CORTO_EXPORT corto_interface _corto_interfaceCreate(corto_interface base);
#define corto_interfaceCreate(base) _corto_interfaceCreate(corto_interface(base))
#define corto_interfaceCreate_auto(_name, base) corto_interface _name = corto_interfaceCreate(base); (void)_name
CORTO_EXPORT corto_interface _corto_interfaceCreateChild(corto_object _parent, corto_string _name, corto_interface base);
#define corto_interfaceCreateChild(_parent, _name, base) _corto_interfaceCreateChild(_parent, _name, corto_interface(base))
#define corto_interfaceCreateChild_auto(_parent, _name, base) corto_interface _name = corto_interfaceCreateChild(_parent, #_name, base); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceUpdate(corto_interface _this, corto_interface base);
#define corto_interfaceUpdate(_this, base) _corto_interfaceUpdate(corto_interface(_this), corto_interface(base))

CORTO_EXPORT corto_interface _corto_interfaceDeclare(void);
#define corto_interfaceDeclare() _corto_interfaceDeclare()
#define corto_interfaceDeclare_auto(_name) corto_interface _name = corto_interfaceDeclare(); (void)_name
CORTO_EXPORT corto_interface _corto_interfaceDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceDeclareChild(_parent, _name) _corto_interfaceDeclareChild(_parent, _name)
#define corto_interfaceDeclareChild_auto(_parent, _name) corto_interface _name = corto_interfaceDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceDefine(corto_interface _this, corto_interface base);
#define corto_interfaceDefine(_this, base) _corto_interfaceDefine(corto_interface(_this), corto_interface(base))
CORTO_EXPORT void _corto_interfaceSet(corto_interface _this, corto_interface base);
#define corto_interfaceSet(_this, base) _corto_interfaceSet(corto_interface(_this), corto_interface(base))
CORTO_EXPORT corto_string _corto_interfaceStr(corto_interface value);
#define corto_interfaceStr(value) _corto_interfaceStr(corto_interface(value))
CORTO_EXPORT corto_interface corto_interfaceFromStr(corto_interface value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_interfaceCompare(corto_interface dst, corto_interface src);
#define corto_interfaceCompare(dst, src) _corto_interfaceCompare(corto_interface(dst), corto_interface(src))

/* interfaceseq */
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqCreate(corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqCreate(length, elements) _corto_interfaceseqCreate(length, elements)
#define corto_interfaceseqCreate_auto(_name, length, elements) corto_interfaceseq* _name = corto_interfaceseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqCreateChild(_parent, _name, length, elements) _corto_interfaceseqCreateChild(_parent, _name, length, elements)
#define corto_interfaceseqCreateChild_auto(_parent, _name, length, elements) corto_interfaceseq* _name = corto_interfaceseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqUpdate(_this, length, elements) _corto_interfaceseqUpdate(_this, length, elements)

CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqDeclare(void);
#define corto_interfaceseqDeclare() _corto_interfaceseqDeclare()
#define corto_interfaceseqDeclare_auto(_name) corto_interfaceseq* _name = corto_interfaceseqDeclare(); (void)_name
CORTO_EXPORT corto_interfaceseq* _corto_interfaceseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceseqDeclareChild(_parent, _name) _corto_interfaceseqDeclareChild(_parent, _name)
#define corto_interfaceseqDeclareChild_auto(_parent, _name) corto_interfaceseq* _name = corto_interfaceseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceseqDefine(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqDefine(_this, length, elements) _corto_interfaceseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_interfaceseqSet(corto_interfaceseq* _this, corto_uint32 length, corto_interface* elements);
#define corto_interfaceseqSet(_this, length, elements) _corto_interfaceseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_interfaceseqStr(corto_interfaceseq value);
#define corto_interfaceseqStr(value) _corto_interfaceseqStr(value)
CORTO_EXPORT corto_interfaceseq* corto_interfaceseqFromStr(corto_interfaceseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_interfaceseqCompare(corto_interfaceseq dst, corto_interfaceseq src);

CORTO_EXPORT corto_int16 _corto_interfaceseqInit(corto_interfaceseq* value);
#define corto_interfaceseqInit(value) _corto_interfaceseqInit(value)
CORTO_EXPORT corto_int16 _corto_interfaceseqDeinit(corto_interfaceseq* value);
#define corto_interfaceseqDeinit(value) _corto_interfaceseqDeinit(value)

/* interfaceVector */
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorCreate(corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorCreate(interface, vector) _corto_interfaceVectorCreate(corto_interface(interface), vector)
#define corto_interfaceVectorCreate_auto(_name, interface, vector) corto_interfaceVector* _name = corto_interfaceVectorCreate(interface, vector); (void)_name
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorCreateChild(corto_object _parent, corto_string _name, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorCreateChild(_parent, _name, interface, vector) _corto_interfaceVectorCreateChild(_parent, _name, corto_interface(interface), vector)
#define corto_interfaceVectorCreateChild_auto(_parent, _name, interface, vector) corto_interfaceVector* _name = corto_interfaceVectorCreateChild(_parent, #_name, interface, vector); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorUpdate(_this, interface, vector) _corto_interfaceVectorUpdate(_this, corto_interface(interface), vector)

CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclare(void);
#define corto_interfaceVectorDeclare() _corto_interfaceVectorDeclare()
#define corto_interfaceVectorDeclare_auto(_name) corto_interfaceVector* _name = corto_interfaceVectorDeclare(); (void)_name
CORTO_EXPORT corto_interfaceVector* _corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceVectorDeclareChild(_parent, _name) _corto_interfaceVectorDeclareChild(_parent, _name)
#define corto_interfaceVectorDeclareChild_auto(_parent, _name) corto_interfaceVector* _name = corto_interfaceVectorDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorDefine(_this, interface, vector) _corto_interfaceVectorDefine(_this, corto_interface(interface), vector)
CORTO_EXPORT void _corto_interfaceVectorSet(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
#define corto_interfaceVectorSet(_this, interface, vector) _corto_interfaceVectorSet(_this, corto_interface(interface), vector)
CORTO_EXPORT corto_string _corto_interfaceVectorStr(corto_interfaceVector* value);
#define corto_interfaceVectorStr(value) _corto_interfaceVectorStr(value)
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorFromStr(corto_interfaceVector* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_interfaceVectorCompare(corto_interfaceVector* dst, corto_interfaceVector* src);

CORTO_EXPORT corto_int16 _corto_interfaceVectorInit(corto_interfaceVector* value);
#define corto_interfaceVectorInit(value) _corto_interfaceVectorInit(value)
CORTO_EXPORT corto_int16 _corto_interfaceVectorDeinit(corto_interfaceVector* value);
#define corto_interfaceVectorDeinit(value) _corto_interfaceVectorDeinit(value)

/* interfaceVectorseq */
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreate(corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqCreate(length, elements) _corto_interfaceVectorseqCreate(length, elements)
#define corto_interfaceVectorseqCreate_auto(_name, length, elements) corto_interfaceVectorseq* _name = corto_interfaceVectorseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqCreateChild(_parent, _name, length, elements) _corto_interfaceVectorseqCreateChild(_parent, _name, length, elements)
#define corto_interfaceVectorseqCreateChild_auto(_parent, _name, length, elements) corto_interfaceVectorseq* _name = corto_interfaceVectorseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqUpdate(_this, length, elements) _corto_interfaceVectorseqUpdate(_this, length, elements)

CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclare(void);
#define corto_interfaceVectorseqDeclare() _corto_interfaceVectorseqDeclare()
#define corto_interfaceVectorseqDeclare_auto(_name) corto_interfaceVectorseq* _name = corto_interfaceVectorseqDeclare(); (void)_name
CORTO_EXPORT corto_interfaceVectorseq* _corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_interfaceVectorseqDeclareChild(_parent, _name) _corto_interfaceVectorseqDeclareChild(_parent, _name)
#define corto_interfaceVectorseqDeclareChild_auto(_parent, _name) corto_interfaceVectorseq* _name = corto_interfaceVectorseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqDefine(_this, length, elements) _corto_interfaceVectorseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_interfaceVectorseqSet(corto_interfaceVectorseq* _this, corto_uint32 length, corto_interfaceVector* elements);
#define corto_interfaceVectorseqSet(_this, length, elements) _corto_interfaceVectorseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_interfaceVectorseqStr(corto_interfaceVectorseq value);
#define corto_interfaceVectorseqStr(value) _corto_interfaceVectorseqStr(value)
CORTO_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqFromStr(corto_interfaceVectorseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_interfaceVectorseqCompare(corto_interfaceVectorseq dst, corto_interfaceVectorseq src);

CORTO_EXPORT corto_int16 _corto_interfaceVectorseqInit(corto_interfaceVectorseq* value);
#define corto_interfaceVectorseqInit(value) _corto_interfaceVectorseqInit(value)
CORTO_EXPORT corto_int16 _corto_interfaceVectorseqDeinit(corto_interfaceVectorseq* value);
#define corto_interfaceVectorseqDeinit(value) _corto_interfaceVectorseqDeinit(value)

/* iterator */
CORTO_EXPORT corto_iterator _corto_iteratorCreate(corto_type elementType);
#define corto_iteratorCreate(elementType) _corto_iteratorCreate(corto_type(elementType))
#define corto_iteratorCreate_auto(_name, elementType) corto_iterator _name = corto_iteratorCreate(elementType); (void)_name
CORTO_EXPORT corto_iterator _corto_iteratorCreateChild(corto_object _parent, corto_string _name, corto_type elementType);
#define corto_iteratorCreateChild(_parent, _name, elementType) _corto_iteratorCreateChild(_parent, _name, corto_type(elementType))
#define corto_iteratorCreateChild_auto(_parent, _name, elementType) corto_iterator _name = corto_iteratorCreateChild(_parent, #_name, elementType); (void)_name
CORTO_EXPORT corto_int16 _corto_iteratorUpdate(corto_iterator _this, corto_type elementType);
#define corto_iteratorUpdate(_this, elementType) _corto_iteratorUpdate(corto_iterator(_this), corto_type(elementType))

CORTO_EXPORT corto_iterator _corto_iteratorDeclare(void);
#define corto_iteratorDeclare() _corto_iteratorDeclare()
#define corto_iteratorDeclare_auto(_name) corto_iterator _name = corto_iteratorDeclare(); (void)_name
CORTO_EXPORT corto_iterator _corto_iteratorDeclareChild(corto_object _parent, corto_string _name);
#define corto_iteratorDeclareChild(_parent, _name) _corto_iteratorDeclareChild(_parent, _name)
#define corto_iteratorDeclareChild_auto(_parent, _name) corto_iterator _name = corto_iteratorDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_iteratorDefine(corto_iterator _this, corto_type elementType);
#define corto_iteratorDefine(_this, elementType) _corto_iteratorDefine(corto_iterator(_this), corto_type(elementType))
CORTO_EXPORT void _corto_iteratorSet(corto_iterator _this, corto_type elementType);
#define corto_iteratorSet(_this, elementType) _corto_iteratorSet(corto_iterator(_this), corto_type(elementType))
CORTO_EXPORT corto_string _corto_iteratorStr(corto_iterator value);
#define corto_iteratorStr(value) _corto_iteratorStr(corto_iterator(value))
CORTO_EXPORT corto_iterator corto_iteratorFromStr(corto_iterator value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_iteratorCompare(corto_iterator dst, corto_iterator src);
#define corto_iteratorCompare(dst, src) _corto_iteratorCompare(corto_iterator(dst), corto_iterator(src))

/* list */
CORTO_EXPORT corto_list _corto_listCreate(corto_type elementType, corto_uint32 max);
#define corto_listCreate(elementType, max) _corto_listCreate(corto_type(elementType), max)
#define corto_listCreate_auto(_name, elementType, max) corto_list _name = corto_listCreate(elementType, max); (void)_name
CORTO_EXPORT corto_list _corto_listCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_listCreateChild(_parent, _name, elementType, max) _corto_listCreateChild(_parent, _name, corto_type(elementType), max)
#define corto_listCreateChild_auto(_parent, _name, elementType, max) corto_list _name = corto_listCreateChild(_parent, #_name, elementType, max); (void)_name
CORTO_EXPORT corto_int16 _corto_listUpdate(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listUpdate(_this, elementType, max) _corto_listUpdate(corto_list(_this), corto_type(elementType), max)

CORTO_EXPORT corto_list _corto_listDeclare(void);
#define corto_listDeclare() _corto_listDeclare()
#define corto_listDeclare_auto(_name) corto_list _name = corto_listDeclare(); (void)_name
CORTO_EXPORT corto_list _corto_listDeclareChild(corto_object _parent, corto_string _name);
#define corto_listDeclareChild(_parent, _name) _corto_listDeclareChild(_parent, _name)
#define corto_listDeclareChild_auto(_parent, _name) corto_list _name = corto_listDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_listDefine(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listDefine(_this, elementType, max) _corto_listDefine(corto_list(_this), corto_type(elementType), max)
CORTO_EXPORT void _corto_listSet(corto_list _this, corto_type elementType, corto_uint32 max);
#define corto_listSet(_this, elementType, max) _corto_listSet(corto_list(_this), corto_type(elementType), max)
CORTO_EXPORT corto_string _corto_listStr(corto_list value);
#define corto_listStr(value) _corto_listStr(corto_list(value))
CORTO_EXPORT corto_list corto_listFromStr(corto_list value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_listCompare(corto_list dst, corto_list src);
#define corto_listCompare(dst, src) _corto_listCompare(corto_list(dst), corto_list(src))

/* map */
CORTO_EXPORT corto_map _corto_mapCreate(corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapCreate(elementType, keyType, max) _corto_mapCreate(corto_type(elementType), corto_type(keyType), max)
#define corto_mapCreate_auto(_name, elementType, keyType, max) corto_map _name = corto_mapCreate(elementType, keyType, max); (void)_name
CORTO_EXPORT corto_map _corto_mapCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapCreateChild(_parent, _name, elementType, keyType, max) _corto_mapCreateChild(_parent, _name, corto_type(elementType), corto_type(keyType), max)
#define corto_mapCreateChild_auto(_parent, _name, elementType, keyType, max) corto_map _name = corto_mapCreateChild(_parent, #_name, elementType, keyType, max); (void)_name
CORTO_EXPORT corto_int16 _corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapUpdate(_this, elementType, keyType, max) _corto_mapUpdate(corto_map(_this), corto_type(elementType), corto_type(keyType), max)

CORTO_EXPORT corto_map _corto_mapDeclare(void);
#define corto_mapDeclare() _corto_mapDeclare()
#define corto_mapDeclare_auto(_name) corto_map _name = corto_mapDeclare(); (void)_name
CORTO_EXPORT corto_map _corto_mapDeclareChild(corto_object _parent, corto_string _name);
#define corto_mapDeclareChild(_parent, _name) _corto_mapDeclareChild(_parent, _name)
#define corto_mapDeclareChild_auto(_parent, _name) corto_map _name = corto_mapDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapDefine(_this, elementType, keyType, max) _corto_mapDefine(corto_map(_this), corto_type(elementType), corto_type(keyType), max)
CORTO_EXPORT void _corto_mapSet(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
#define corto_mapSet(_this, elementType, keyType, max) _corto_mapSet(corto_map(_this), corto_type(elementType), corto_type(keyType), max)
CORTO_EXPORT corto_string _corto_mapStr(corto_map value);
#define corto_mapStr(value) _corto_mapStr(corto_map(value))
CORTO_EXPORT corto_map corto_mapFromStr(corto_map value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_mapCompare(corto_map dst, corto_map src);
#define corto_mapCompare(dst, src) _corto_mapCompare(corto_map(dst), corto_map(src))

/* member */
CORTO_EXPORT corto_member _corto_memberCreate(corto_type type, corto_modifier modifiers);
#define corto_memberCreate(type, modifiers) _corto_memberCreate(corto_type(type), modifiers)
#define corto_memberCreate_auto(_name, type, modifiers) corto_member _name = corto_memberCreate(type, modifiers); (void)_name
CORTO_EXPORT corto_member _corto_memberCreateChild(corto_object _parent, corto_string _name, corto_type type, corto_modifier modifiers);
#define corto_memberCreateChild(_parent, _name, type, modifiers) _corto_memberCreateChild(_parent, _name, corto_type(type), modifiers)
#define corto_memberCreateChild_auto(_parent, _name, type, modifiers) corto_member _name = corto_memberCreateChild(_parent, #_name, type, modifiers); (void)_name
CORTO_EXPORT corto_int16 _corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberUpdate(_this, type, modifiers) _corto_memberUpdate(corto_member(_this), corto_type(type), modifiers)

CORTO_EXPORT corto_member _corto_memberDeclare(void);
#define corto_memberDeclare() _corto_memberDeclare()
#define corto_memberDeclare_auto(_name) corto_member _name = corto_memberDeclare(); (void)_name
CORTO_EXPORT corto_member _corto_memberDeclareChild(corto_object _parent, corto_string _name);
#define corto_memberDeclareChild(_parent, _name) _corto_memberDeclareChild(_parent, _name)
#define corto_memberDeclareChild_auto(_parent, _name) corto_member _name = corto_memberDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberDefine(_this, type, modifiers) _corto_memberDefine(corto_member(_this), corto_type(type), modifiers)
CORTO_EXPORT void _corto_memberSet(corto_member _this, corto_type type, corto_modifier modifiers);
#define corto_memberSet(_this, type, modifiers) _corto_memberSet(corto_member(_this), corto_type(type), modifiers)
CORTO_EXPORT corto_string _corto_memberStr(corto_member value);
#define corto_memberStr(value) _corto_memberStr(corto_member(value))
CORTO_EXPORT corto_member corto_memberFromStr(corto_member value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_memberCompare(corto_member dst, corto_member src);
#define corto_memberCompare(dst, src) _corto_memberCompare(corto_member(dst), corto_member(src))

/* memberseq */
CORTO_EXPORT corto_memberseq* _corto_memberseqCreate(corto_uint32 length, corto_member* elements);
#define corto_memberseqCreate(length, elements) _corto_memberseqCreate(length, elements)
#define corto_memberseqCreate_auto(_name, length, elements) corto_memberseq* _name = corto_memberseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_memberseq* _corto_memberseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_member* elements);
#define corto_memberseqCreateChild(_parent, _name, length, elements) _corto_memberseqCreateChild(_parent, _name, length, elements)
#define corto_memberseqCreateChild_auto(_parent, _name, length, elements) corto_memberseq* _name = corto_memberseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_memberseqUpdate(corto_memberseq* _this, corto_uint32 length, corto_member* elements);
#define corto_memberseqUpdate(_this, length, elements) _corto_memberseqUpdate(_this, length, elements)

CORTO_EXPORT corto_memberseq* _corto_memberseqDeclare(void);
#define corto_memberseqDeclare() _corto_memberseqDeclare()
#define corto_memberseqDeclare_auto(_name) corto_memberseq* _name = corto_memberseqDeclare(); (void)_name
CORTO_EXPORT corto_memberseq* _corto_memberseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_memberseqDeclareChild(_parent, _name) _corto_memberseqDeclareChild(_parent, _name)
#define corto_memberseqDeclareChild_auto(_parent, _name) corto_memberseq* _name = corto_memberseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_memberseqDefine(corto_memberseq* _this, corto_uint32 length, corto_member* elements);
#define corto_memberseqDefine(_this, length, elements) _corto_memberseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_memberseqSet(corto_memberseq* _this, corto_uint32 length, corto_member* elements);
#define corto_memberseqSet(_this, length, elements) _corto_memberseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_memberseqStr(corto_memberseq value);
#define corto_memberseqStr(value) _corto_memberseqStr(value)
CORTO_EXPORT corto_memberseq* corto_memberseqFromStr(corto_memberseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_memberseqCompare(corto_memberseq dst, corto_memberseq src);

CORTO_EXPORT corto_int16 _corto_memberseqInit(corto_memberseq* value);
#define corto_memberseqInit(value) _corto_memberseqInit(value)
CORTO_EXPORT corto_int16 _corto_memberseqDeinit(corto_memberseq* value);
#define corto_memberseqDeinit(value) _corto_memberseqDeinit(value)

/* metaprocedure */
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureCreate(corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureCreate(returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreate(corto_type(returnType), returnsReference, referenceOnly, _impl)
#define corto_metaprocedureCreate_auto(_name, returnType, returnsReference, referenceOnly, _impl) corto_metaprocedure _name = corto_metaprocedureCreate(returnType, returnsReference, referenceOnly, _impl); (void)_name
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureCreateChild(_parent, _name, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureCreateChild(_parent, _name, corto_type(returnType), returnsReference, referenceOnly, _impl)
#define corto_metaprocedureCreateChild_auto(_parent, _name, returnType, returnsReference, referenceOnly, _impl) corto_metaprocedure _name = corto_metaprocedureCreateChild(_parent, #_name, returnType, returnsReference, referenceOnly, _impl); (void)_name
CORTO_EXPORT corto_int16 _corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureUpdate(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureUpdate(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, _impl)

CORTO_EXPORT corto_metaprocedure _corto_metaprocedureDeclare(void);
#define corto_metaprocedureDeclare() _corto_metaprocedureDeclare()
#define corto_metaprocedureDeclare_auto(_name) corto_metaprocedure _name = corto_metaprocedureDeclare(); (void)_name
CORTO_EXPORT corto_metaprocedure _corto_metaprocedureDeclareChild(corto_object _parent, corto_string _name);
#define corto_metaprocedureDeclareChild(_parent, _name) _corto_metaprocedureDeclareChild(_parent, _name)
#define corto_metaprocedureDeclareChild_auto(_parent, _name) corto_metaprocedure _name = corto_metaprocedureDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureDefine(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureDefine(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, _impl)
CORTO_EXPORT void _corto_metaprocedureSet(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
#define corto_metaprocedureSet(_this, returnType, returnsReference, referenceOnly, _impl) _corto_metaprocedureSet(corto_metaprocedure(_this), corto_type(returnType), returnsReference, referenceOnly, _impl)
CORTO_EXPORT corto_string _corto_metaprocedureStr(corto_metaprocedure value);
#define corto_metaprocedureStr(value) _corto_metaprocedureStr(corto_metaprocedure(value))
CORTO_EXPORT corto_metaprocedure corto_metaprocedureFromStr(corto_metaprocedure value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_metaprocedureCompare(corto_metaprocedure dst, corto_metaprocedure src);
#define corto_metaprocedureCompare(dst, src) _corto_metaprocedureCompare(corto_metaprocedure(dst), corto_metaprocedure(src))

/* method */
CORTO_EXPORT corto_method _corto_methodCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodCreate(returnType, returnsReference, _virtual, _impl) _corto_methodCreate(corto_type(returnType), returnsReference, _virtual, _impl)
#define corto_methodCreate_auto(_name, returnType, returnsReference, _virtual, _impl) corto_method _name = corto_methodCreate(returnType, returnsReference, _virtual, _impl); (void)_name
CORTO_EXPORT corto_method _corto_methodCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodCreateChild(_parent, _name, returnType, returnsReference, _virtual, _impl) _corto_methodCreateChild(_parent, _name, corto_type(returnType), returnsReference, _virtual, _impl)
#define corto_methodCreateChild_auto(_parent, _name, returnType, returnsReference, _virtual, _impl) corto_method _name = corto_methodCreateChild(_parent, #_name, returnType, returnsReference, _virtual, _impl); (void)_name
CORTO_EXPORT corto_int16 _corto_methodUpdate(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodUpdate(_this, returnType, returnsReference, _virtual, _impl) _corto_methodUpdate(corto_method(_this), corto_type(returnType), returnsReference, _virtual, _impl)

CORTO_EXPORT corto_method _corto_methodDeclare(void);
#define corto_methodDeclare() _corto_methodDeclare()
#define corto_methodDeclare_auto(_name) corto_method _name = corto_methodDeclare(); (void)_name
CORTO_EXPORT corto_method _corto_methodDeclareChild(corto_object _parent, corto_string _name);
#define corto_methodDeclareChild(_parent, _name) _corto_methodDeclareChild(_parent, _name)
#define corto_methodDeclareChild_auto(_parent, _name) corto_method _name = corto_methodDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_methodDefine(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodDefine(_this, returnType, returnsReference, _virtual, _impl) _corto_methodDefine(corto_method(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_EXPORT void _corto_methodSet(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_methodSet(_this, returnType, returnsReference, _virtual, _impl) _corto_methodSet(corto_method(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_EXPORT corto_string _corto_methodStr(corto_method value);
#define corto_methodStr(value) _corto_methodStr(corto_method(value))
CORTO_EXPORT corto_method corto_methodFromStr(corto_method value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_methodCompare(corto_method dst, corto_method src);
#define corto_methodCompare(dst, src) _corto_methodCompare(corto_method(dst), corto_method(src))

/* modifier */
CORTO_EXPORT corto_modifier* _corto_modifierCreate(corto_modifier value);
#define corto_modifierCreate(value) _corto_modifierCreate(value)
#define corto_modifierCreate_auto(_name, value) corto_modifier* _name = corto_modifierCreate(value); (void)_name
CORTO_EXPORT corto_modifier* _corto_modifierCreateChild(corto_object _parent, corto_string _name, corto_modifier value);
#define corto_modifierCreateChild(_parent, _name, value) _corto_modifierCreateChild(_parent, _name, value)
#define corto_modifierCreateChild_auto(_parent, _name, value) corto_modifier* _name = corto_modifierCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_modifierUpdate(corto_modifier* _this, corto_modifier value);
#define corto_modifierUpdate(_this, value) _corto_modifierUpdate(_this, value)

CORTO_EXPORT corto_modifier* _corto_modifierDeclare(void);
#define corto_modifierDeclare() _corto_modifierDeclare()
#define corto_modifierDeclare_auto(_name) corto_modifier* _name = corto_modifierDeclare(); (void)_name
CORTO_EXPORT corto_modifier* _corto_modifierDeclareChild(corto_object _parent, corto_string _name);
#define corto_modifierDeclareChild(_parent, _name) _corto_modifierDeclareChild(_parent, _name)
#define corto_modifierDeclareChild_auto(_parent, _name) corto_modifier* _name = corto_modifierDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_modifierDefine(corto_modifier* _this, corto_modifier value);
#define corto_modifierDefine(_this, value) _corto_modifierDefine(_this, value)
CORTO_EXPORT void _corto_modifierSet(corto_modifier* _this, corto_modifier value);
#define corto_modifierSet(_this, value) _corto_modifierSet(_this, value)
CORTO_EXPORT corto_string _corto_modifierStr(corto_modifier value);
#define corto_modifierStr(value) _corto_modifierStr(value)
CORTO_EXPORT corto_modifier* corto_modifierFromStr(corto_modifier* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_modifierCompare(corto_modifier dst, corto_modifier src);

CORTO_EXPORT corto_int16 _corto_modifierInit(corto_modifier* value);
#define corto_modifierInit(value) _corto_modifierInit(value)
CORTO_EXPORT corto_int16 _corto_modifierDeinit(corto_modifier* value);
#define corto_modifierDeinit(value) _corto_modifierDeinit(value)

/* object */
CORTO_EXPORT corto_object _corto_objectCreate(void);
#define corto_objectCreate() _corto_objectCreate()
#define corto_objectCreate_auto(_name) corto_object _name = corto_objectCreate(); (void)_name
CORTO_EXPORT corto_object _corto_objectCreateChild(corto_object _parent, corto_string _name);
#define corto_objectCreateChild(_parent, _name) _corto_objectCreateChild(_parent, _name)
#define corto_objectCreateChild_auto(_parent, _name) corto_object _name = corto_objectCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_objectUpdate(corto_object _this);
#define corto_objectUpdate(_this) _corto_objectUpdate(_this)

/* objectseq */
CORTO_EXPORT corto_objectseq* _corto_objectseqCreate(corto_uint32 length, corto_object* elements);
#define corto_objectseqCreate(length, elements) _corto_objectseqCreate(length, elements)
#define corto_objectseqCreate_auto(_name, length, elements) corto_objectseq* _name = corto_objectseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_objectseq* _corto_objectseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_object* elements);
#define corto_objectseqCreateChild(_parent, _name, length, elements) _corto_objectseqCreateChild(_parent, _name, length, elements)
#define corto_objectseqCreateChild_auto(_parent, _name, length, elements) corto_objectseq* _name = corto_objectseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_objectseqUpdate(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseqUpdate(_this, length, elements) _corto_objectseqUpdate(_this, length, elements)

CORTO_EXPORT corto_objectseq* _corto_objectseqDeclare(void);
#define corto_objectseqDeclare() _corto_objectseqDeclare()
#define corto_objectseqDeclare_auto(_name) corto_objectseq* _name = corto_objectseqDeclare(); (void)_name
CORTO_EXPORT corto_objectseq* _corto_objectseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_objectseqDeclareChild(_parent, _name) _corto_objectseqDeclareChild(_parent, _name)
#define corto_objectseqDeclareChild_auto(_parent, _name) corto_objectseq* _name = corto_objectseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_objectseqDefine(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseqDefine(_this, length, elements) _corto_objectseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_objectseqSet(corto_objectseq* _this, corto_uint32 length, corto_object* elements);
#define corto_objectseqSet(_this, length, elements) _corto_objectseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_objectseqStr(corto_objectseq value);
#define corto_objectseqStr(value) _corto_objectseqStr(value)
CORTO_EXPORT corto_objectseq* corto_objectseqFromStr(corto_objectseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_objectseqCompare(corto_objectseq dst, corto_objectseq src);

CORTO_EXPORT corto_int16 _corto_objectseqInit(corto_objectseq* value);
#define corto_objectseqInit(value) _corto_objectseqInit(value)
CORTO_EXPORT corto_int16 _corto_objectseqDeinit(corto_objectseq* value);
#define corto_objectseqDeinit(value) _corto_objectseqDeinit(value)

/* octet */
CORTO_EXPORT corto_octet* _corto_octetCreate(corto_octet value);
#define corto_octetCreate(value) _corto_octetCreate(value)
#define corto_octetCreate_auto(_name, value) corto_octet* _name = corto_octetCreate(value); (void)_name
CORTO_EXPORT corto_octet* _corto_octetCreateChild(corto_object _parent, corto_string _name, corto_octet value);
#define corto_octetCreateChild(_parent, _name, value) _corto_octetCreateChild(_parent, _name, value)
#define corto_octetCreateChild_auto(_parent, _name, value) corto_octet* _name = corto_octetCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_octetUpdate(corto_octet* _this, corto_octet value);
#define corto_octetUpdate(_this, value) _corto_octetUpdate(_this, value)

CORTO_EXPORT corto_octet* _corto_octetDeclare(void);
#define corto_octetDeclare() _corto_octetDeclare()
#define corto_octetDeclare_auto(_name) corto_octet* _name = corto_octetDeclare(); (void)_name
CORTO_EXPORT corto_octet* _corto_octetDeclareChild(corto_object _parent, corto_string _name);
#define corto_octetDeclareChild(_parent, _name) _corto_octetDeclareChild(_parent, _name)
#define corto_octetDeclareChild_auto(_parent, _name) corto_octet* _name = corto_octetDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_octetDefine(corto_octet* _this, corto_octet value);
#define corto_octetDefine(_this, value) _corto_octetDefine(_this, value)
CORTO_EXPORT void _corto_octetSet(corto_octet* _this, corto_octet value);
#define corto_octetSet(_this, value) _corto_octetSet(_this, value)
CORTO_EXPORT corto_string _corto_octetStr(corto_octet value);
#define corto_octetStr(value) _corto_octetStr(value)
CORTO_EXPORT corto_octet* corto_octetFromStr(corto_octet* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_octetCompare(corto_octet dst, corto_octet src);

CORTO_EXPORT corto_int16 _corto_octetInit(corto_octet* value);
#define corto_octetInit(value) _corto_octetInit(value)
CORTO_EXPORT corto_int16 _corto_octetDeinit(corto_octet* value);
#define corto_octetDeinit(value) _corto_octetDeinit(value)

/* octetseq */
CORTO_EXPORT corto_octetseq* _corto_octetseqCreate(corto_uint32 length, corto_octet* elements);
#define corto_octetseqCreate(length, elements) _corto_octetseqCreate(length, elements)
#define corto_octetseqCreate_auto(_name, length, elements) corto_octetseq* _name = corto_octetseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_octetseq* _corto_octetseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_octet* elements);
#define corto_octetseqCreateChild(_parent, _name, length, elements) _corto_octetseqCreateChild(_parent, _name, length, elements)
#define corto_octetseqCreateChild_auto(_parent, _name, length, elements) corto_octetseq* _name = corto_octetseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_octetseqUpdate(corto_octetseq* _this, corto_uint32 length, corto_octet* elements);
#define corto_octetseqUpdate(_this, length, elements) _corto_octetseqUpdate(_this, length, elements)

CORTO_EXPORT corto_octetseq* _corto_octetseqDeclare(void);
#define corto_octetseqDeclare() _corto_octetseqDeclare()
#define corto_octetseqDeclare_auto(_name) corto_octetseq* _name = corto_octetseqDeclare(); (void)_name
CORTO_EXPORT corto_octetseq* _corto_octetseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_octetseqDeclareChild(_parent, _name) _corto_octetseqDeclareChild(_parent, _name)
#define corto_octetseqDeclareChild_auto(_parent, _name) corto_octetseq* _name = corto_octetseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_octetseqDefine(corto_octetseq* _this, corto_uint32 length, corto_octet* elements);
#define corto_octetseqDefine(_this, length, elements) _corto_octetseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_octetseqSet(corto_octetseq* _this, corto_uint32 length, corto_octet* elements);
#define corto_octetseqSet(_this, length, elements) _corto_octetseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_octetseqStr(corto_octetseq value);
#define corto_octetseqStr(value) _corto_octetseqStr(value)
CORTO_EXPORT corto_octetseq* corto_octetseqFromStr(corto_octetseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_octetseqCompare(corto_octetseq dst, corto_octetseq src);

CORTO_EXPORT corto_int16 _corto_octetseqInit(corto_octetseq* value);
#define corto_octetseqInit(value) _corto_octetseqInit(value)
CORTO_EXPORT corto_int16 _corto_octetseqDeinit(corto_octetseq* value);
#define corto_octetseqDeinit(value) _corto_octetseqDeinit(value)

/* parameter */
CORTO_EXPORT corto_parameter* _corto_parameterCreate(corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterCreate(name, type, passByReference) _corto_parameterCreate(name, corto_type(type), passByReference)
#define corto_parameterCreate_auto(_name, name, type, passByReference) corto_parameter* _name = corto_parameterCreate(name, type, passByReference); (void)_name
CORTO_EXPORT corto_parameter* _corto_parameterCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterCreateChild(_parent, _name, name, type, passByReference) _corto_parameterCreateChild(_parent, _name, name, corto_type(type), passByReference)
#define corto_parameterCreateChild_auto(_parent, _name, name, type, passByReference) corto_parameter* _name = corto_parameterCreateChild(_parent, #_name, name, type, passByReference); (void)_name
CORTO_EXPORT corto_int16 _corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterUpdate(_this, name, type, passByReference) _corto_parameterUpdate(_this, name, corto_type(type), passByReference)

CORTO_EXPORT corto_parameter* _corto_parameterDeclare(void);
#define corto_parameterDeclare() _corto_parameterDeclare()
#define corto_parameterDeclare_auto(_name) corto_parameter* _name = corto_parameterDeclare(); (void)_name
CORTO_EXPORT corto_parameter* _corto_parameterDeclareChild(corto_object _parent, corto_string _name);
#define corto_parameterDeclareChild(_parent, _name) _corto_parameterDeclareChild(_parent, _name)
#define corto_parameterDeclareChild_auto(_parent, _name) corto_parameter* _name = corto_parameterDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterDefine(_this, name, type, passByReference) _corto_parameterDefine(_this, name, corto_type(type), passByReference)
CORTO_EXPORT void _corto_parameterSet(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
#define corto_parameterSet(_this, name, type, passByReference) _corto_parameterSet(_this, name, corto_type(type), passByReference)
CORTO_EXPORT corto_string _corto_parameterStr(corto_parameter* value);
#define corto_parameterStr(value) _corto_parameterStr(value)
CORTO_EXPORT corto_parameter* corto_parameterFromStr(corto_parameter* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_parameterCompare(corto_parameter* dst, corto_parameter* src);

CORTO_EXPORT corto_int16 _corto_parameterInit(corto_parameter* value);
#define corto_parameterInit(value) _corto_parameterInit(value)
CORTO_EXPORT corto_int16 _corto_parameterDeinit(corto_parameter* value);
#define corto_parameterDeinit(value) _corto_parameterDeinit(value)

/* parameterseq */
CORTO_EXPORT corto_parameterseq* _corto_parameterseqCreate(corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqCreate(length, elements) _corto_parameterseqCreate(length, elements)
#define corto_parameterseqCreate_auto(_name, length, elements) corto_parameterseq* _name = corto_parameterseqCreate(length, elements); (void)_name
CORTO_EXPORT corto_parameterseq* _corto_parameterseqCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqCreateChild(_parent, _name, length, elements) _corto_parameterseqCreateChild(_parent, _name, length, elements)
#define corto_parameterseqCreateChild_auto(_parent, _name, length, elements) corto_parameterseq* _name = corto_parameterseqCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_parameterseqUpdate(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqUpdate(_this, length, elements) _corto_parameterseqUpdate(_this, length, elements)

CORTO_EXPORT corto_parameterseq* _corto_parameterseqDeclare(void);
#define corto_parameterseqDeclare() _corto_parameterseqDeclare()
#define corto_parameterseqDeclare_auto(_name) corto_parameterseq* _name = corto_parameterseqDeclare(); (void)_name
CORTO_EXPORT corto_parameterseq* _corto_parameterseqDeclareChild(corto_object _parent, corto_string _name);
#define corto_parameterseqDeclareChild(_parent, _name) _corto_parameterseqDeclareChild(_parent, _name)
#define corto_parameterseqDeclareChild_auto(_parent, _name) corto_parameterseq* _name = corto_parameterseqDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_parameterseqDefine(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqDefine(_this, length, elements) _corto_parameterseqDefine(_this, length, elements)
CORTO_EXPORT void _corto_parameterseqSet(corto_parameterseq* _this, corto_uint32 length, corto_parameter* elements);
#define corto_parameterseqSet(_this, length, elements) _corto_parameterseqSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_parameterseqStr(corto_parameterseq value);
#define corto_parameterseqStr(value) _corto_parameterseqStr(value)
CORTO_EXPORT corto_parameterseq* corto_parameterseqFromStr(corto_parameterseq* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_parameterseqCompare(corto_parameterseq dst, corto_parameterseq src);

CORTO_EXPORT corto_int16 _corto_parameterseqInit(corto_parameterseq* value);
#define corto_parameterseqInit(value) _corto_parameterseqInit(value)
CORTO_EXPORT corto_int16 _corto_parameterseqDeinit(corto_parameterseq* value);
#define corto_parameterseqDeinit(value) _corto_parameterseqDeinit(value)

/* primitive */
CORTO_EXPORT corto_primitive _corto_primitiveCreate(corto_width width);
#define corto_primitiveCreate(width) _corto_primitiveCreate(width)
#define corto_primitiveCreate_auto(_name, width) corto_primitive _name = corto_primitiveCreate(width); (void)_name
CORTO_EXPORT corto_primitive _corto_primitiveCreateChild(corto_object _parent, corto_string _name, corto_width width);
#define corto_primitiveCreateChild(_parent, _name, width) _corto_primitiveCreateChild(_parent, _name, width)
#define corto_primitiveCreateChild_auto(_parent, _name, width) corto_primitive _name = corto_primitiveCreateChild(_parent, #_name, width); (void)_name
CORTO_EXPORT corto_int16 _corto_primitiveUpdate(corto_primitive _this, corto_width width);
#define corto_primitiveUpdate(_this, width) _corto_primitiveUpdate(corto_primitive(_this), width)

CORTO_EXPORT corto_primitive _corto_primitiveDeclare(void);
#define corto_primitiveDeclare() _corto_primitiveDeclare()
#define corto_primitiveDeclare_auto(_name) corto_primitive _name = corto_primitiveDeclare(); (void)_name
CORTO_EXPORT corto_primitive _corto_primitiveDeclareChild(corto_object _parent, corto_string _name);
#define corto_primitiveDeclareChild(_parent, _name) _corto_primitiveDeclareChild(_parent, _name)
#define corto_primitiveDeclareChild_auto(_parent, _name) corto_primitive _name = corto_primitiveDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_primitiveDefine(corto_primitive _this, corto_width width);
#define corto_primitiveDefine(_this, width) _corto_primitiveDefine(corto_primitive(_this), width)
CORTO_EXPORT void _corto_primitiveSet(corto_primitive _this, corto_width width);
#define corto_primitiveSet(_this, width) _corto_primitiveSet(corto_primitive(_this), width)
CORTO_EXPORT corto_string _corto_primitiveStr(corto_primitive value);
#define corto_primitiveStr(value) _corto_primitiveStr(corto_primitive(value))
CORTO_EXPORT corto_primitive corto_primitiveFromStr(corto_primitive value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_primitiveCompare(corto_primitive dst, corto_primitive src);
#define corto_primitiveCompare(dst, src) _corto_primitiveCompare(corto_primitive(dst), corto_primitive(src))

/* primitiveKind */
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindCreate(corto_primitiveKind value);
#define corto_primitiveKindCreate(value) _corto_primitiveKindCreate(value)
#define corto_primitiveKindCreate_auto(_name, value) corto_primitiveKind* _name = corto_primitiveKindCreate(value); (void)_name
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindCreateChild(corto_object _parent, corto_string _name, corto_primitiveKind value);
#define corto_primitiveKindCreateChild(_parent, _name, value) _corto_primitiveKindCreateChild(_parent, _name, value)
#define corto_primitiveKindCreateChild_auto(_parent, _name, value) corto_primitiveKind* _name = corto_primitiveKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindUpdate(_this, value) _corto_primitiveKindUpdate(_this, value)

CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindDeclare(void);
#define corto_primitiveKindDeclare() _corto_primitiveKindDeclare()
#define corto_primitiveKindDeclare_auto(_name) corto_primitiveKind* _name = corto_primitiveKindDeclare(); (void)_name
CORTO_EXPORT corto_primitiveKind* _corto_primitiveKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_primitiveKindDeclareChild(_parent, _name) _corto_primitiveKindDeclareChild(_parent, _name)
#define corto_primitiveKindDeclareChild_auto(_parent, _name) corto_primitiveKind* _name = corto_primitiveKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindDefine(_this, value) _corto_primitiveKindDefine(_this, value)
CORTO_EXPORT void _corto_primitiveKindSet(corto_primitiveKind* _this, corto_primitiveKind value);
#define corto_primitiveKindSet(_this, value) _corto_primitiveKindSet(_this, value)
CORTO_EXPORT corto_string _corto_primitiveKindStr(corto_primitiveKind value);
#define corto_primitiveKindStr(value) _corto_primitiveKindStr(value)
CORTO_EXPORT corto_primitiveKind* corto_primitiveKindFromStr(corto_primitiveKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_primitiveKindCompare(corto_primitiveKind dst, corto_primitiveKind src);

CORTO_EXPORT corto_int16 _corto_primitiveKindInit(corto_primitiveKind* value);
#define corto_primitiveKindInit(value) _corto_primitiveKindInit(value)
CORTO_EXPORT corto_int16 _corto_primitiveKindDeinit(corto_primitiveKind* value);
#define corto_primitiveKindDeinit(value) _corto_primitiveKindDeinit(value)

/* procedure */
CORTO_EXPORT corto_procedure _corto_procedureCreate(corto_procedureKind kind_1);
#define corto_procedureCreate(kind_1) _corto_procedureCreate(kind_1)
#define corto_procedureCreate_auto(_name, kind_1) corto_procedure _name = corto_procedureCreate(kind_1); (void)_name
CORTO_EXPORT corto_procedure _corto_procedureCreateChild(corto_object _parent, corto_string _name, corto_procedureKind kind_1);
#define corto_procedureCreateChild(_parent, _name, kind_1) _corto_procedureCreateChild(_parent, _name, kind_1)
#define corto_procedureCreateChild_auto(_parent, _name, kind_1) corto_procedure _name = corto_procedureCreateChild(_parent, #_name, kind_1); (void)_name
CORTO_EXPORT corto_int16 _corto_procedureUpdate(corto_procedure _this, corto_procedureKind kind_1);
#define corto_procedureUpdate(_this, kind_1) _corto_procedureUpdate(corto_procedure(_this), kind_1)

CORTO_EXPORT corto_procedure _corto_procedureDeclare(void);
#define corto_procedureDeclare() _corto_procedureDeclare()
#define corto_procedureDeclare_auto(_name) corto_procedure _name = corto_procedureDeclare(); (void)_name
CORTO_EXPORT corto_procedure _corto_procedureDeclareChild(corto_object _parent, corto_string _name);
#define corto_procedureDeclareChild(_parent, _name) _corto_procedureDeclareChild(_parent, _name)
#define corto_procedureDeclareChild_auto(_parent, _name) corto_procedure _name = corto_procedureDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_procedureDefine(corto_procedure _this, corto_procedureKind kind_1);
#define corto_procedureDefine(_this, kind_1) _corto_procedureDefine(corto_procedure(_this), kind_1)
CORTO_EXPORT void _corto_procedureSet(corto_procedure _this, corto_procedureKind kind_1);
#define corto_procedureSet(_this, kind_1) _corto_procedureSet(corto_procedure(_this), kind_1)
CORTO_EXPORT corto_string _corto_procedureStr(corto_procedure value);
#define corto_procedureStr(value) _corto_procedureStr(corto_procedure(value))
CORTO_EXPORT corto_procedure corto_procedureFromStr(corto_procedure value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_procedureCompare(corto_procedure dst, corto_procedure src);
#define corto_procedureCompare(dst, src) _corto_procedureCompare(corto_procedure(dst), corto_procedure(src))

/* procedureKind */
CORTO_EXPORT corto_procedureKind* _corto_procedureKindCreate(corto_procedureKind value);
#define corto_procedureKindCreate(value) _corto_procedureKindCreate(value)
#define corto_procedureKindCreate_auto(_name, value) corto_procedureKind* _name = corto_procedureKindCreate(value); (void)_name
CORTO_EXPORT corto_procedureKind* _corto_procedureKindCreateChild(corto_object _parent, corto_string _name, corto_procedureKind value);
#define corto_procedureKindCreateChild(_parent, _name, value) _corto_procedureKindCreateChild(_parent, _name, value)
#define corto_procedureKindCreateChild_auto(_parent, _name, value) corto_procedureKind* _name = corto_procedureKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_procedureKindUpdate(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindUpdate(_this, value) _corto_procedureKindUpdate(_this, value)

CORTO_EXPORT corto_procedureKind* _corto_procedureKindDeclare(void);
#define corto_procedureKindDeclare() _corto_procedureKindDeclare()
#define corto_procedureKindDeclare_auto(_name) corto_procedureKind* _name = corto_procedureKindDeclare(); (void)_name
CORTO_EXPORT corto_procedureKind* _corto_procedureKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_procedureKindDeclareChild(_parent, _name) _corto_procedureKindDeclareChild(_parent, _name)
#define corto_procedureKindDeclareChild_auto(_parent, _name) corto_procedureKind* _name = corto_procedureKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_procedureKindDefine(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindDefine(_this, value) _corto_procedureKindDefine(_this, value)
CORTO_EXPORT void _corto_procedureKindSet(corto_procedureKind* _this, corto_procedureKind value);
#define corto_procedureKindSet(_this, value) _corto_procedureKindSet(_this, value)
CORTO_EXPORT corto_string _corto_procedureKindStr(corto_procedureKind value);
#define corto_procedureKindStr(value) _corto_procedureKindStr(value)
CORTO_EXPORT corto_procedureKind* corto_procedureKindFromStr(corto_procedureKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_procedureKindCompare(corto_procedureKind dst, corto_procedureKind src);

CORTO_EXPORT corto_int16 _corto_procedureKindInit(corto_procedureKind* value);
#define corto_procedureKindInit(value) _corto_procedureKindInit(value)
CORTO_EXPORT corto_int16 _corto_procedureKindDeinit(corto_procedureKind* value);
#define corto_procedureKindDeinit(value) _corto_procedureKindDeinit(value)

/* sequence */
CORTO_EXPORT corto_sequence _corto_sequenceCreate(corto_type elementType, corto_uint32 max);
#define corto_sequenceCreate(elementType, max) _corto_sequenceCreate(corto_type(elementType), max)
#define corto_sequenceCreate_auto(_name, elementType, max) corto_sequence _name = corto_sequenceCreate(elementType, max); (void)_name
CORTO_EXPORT corto_sequence _corto_sequenceCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
#define corto_sequenceCreateChild(_parent, _name, elementType, max) _corto_sequenceCreateChild(_parent, _name, corto_type(elementType), max)
#define corto_sequenceCreateChild_auto(_parent, _name, elementType, max) corto_sequence _name = corto_sequenceCreateChild(_parent, #_name, elementType, max); (void)_name
CORTO_EXPORT corto_int16 _corto_sequenceUpdate(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceUpdate(_this, elementType, max) _corto_sequenceUpdate(corto_sequence(_this), corto_type(elementType), max)

CORTO_EXPORT corto_sequence _corto_sequenceDeclare(void);
#define corto_sequenceDeclare() _corto_sequenceDeclare()
#define corto_sequenceDeclare_auto(_name) corto_sequence _name = corto_sequenceDeclare(); (void)_name
CORTO_EXPORT corto_sequence _corto_sequenceDeclareChild(corto_object _parent, corto_string _name);
#define corto_sequenceDeclareChild(_parent, _name) _corto_sequenceDeclareChild(_parent, _name)
#define corto_sequenceDeclareChild_auto(_parent, _name) corto_sequence _name = corto_sequenceDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_sequenceDefine(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceDefine(_this, elementType, max) _corto_sequenceDefine(corto_sequence(_this), corto_type(elementType), max)
CORTO_EXPORT void _corto_sequenceSet(corto_sequence _this, corto_type elementType, corto_uint32 max);
#define corto_sequenceSet(_this, elementType, max) _corto_sequenceSet(corto_sequence(_this), corto_type(elementType), max)
CORTO_EXPORT corto_string _corto_sequenceStr(corto_sequence value);
#define corto_sequenceStr(value) _corto_sequenceStr(corto_sequence(value))
CORTO_EXPORT corto_sequence corto_sequenceFromStr(corto_sequence value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_sequenceCompare(corto_sequence dst, corto_sequence src);
#define corto_sequenceCompare(dst, src) _corto_sequenceCompare(corto_sequence(dst), corto_sequence(src))

/* state */
CORTO_EXPORT corto_state* _corto_stateCreate(corto_state value);
#define corto_stateCreate(value) _corto_stateCreate(value)
#define corto_stateCreate_auto(_name, value) corto_state* _name = corto_stateCreate(value); (void)_name
CORTO_EXPORT corto_state* _corto_stateCreateChild(corto_object _parent, corto_string _name, corto_state value);
#define corto_stateCreateChild(_parent, _name, value) _corto_stateCreateChild(_parent, _name, value)
#define corto_stateCreateChild_auto(_parent, _name, value) corto_state* _name = corto_stateCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_stateUpdate(corto_state* _this, corto_state value);
#define corto_stateUpdate(_this, value) _corto_stateUpdate(_this, value)

CORTO_EXPORT corto_state* _corto_stateDeclare(void);
#define corto_stateDeclare() _corto_stateDeclare()
#define corto_stateDeclare_auto(_name) corto_state* _name = corto_stateDeclare(); (void)_name
CORTO_EXPORT corto_state* _corto_stateDeclareChild(corto_object _parent, corto_string _name);
#define corto_stateDeclareChild(_parent, _name) _corto_stateDeclareChild(_parent, _name)
#define corto_stateDeclareChild_auto(_parent, _name) corto_state* _name = corto_stateDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_stateDefine(corto_state* _this, corto_state value);
#define corto_stateDefine(_this, value) _corto_stateDefine(_this, value)
CORTO_EXPORT void _corto_stateSet(corto_state* _this, corto_state value);
#define corto_stateSet(_this, value) _corto_stateSet(_this, value)
CORTO_EXPORT corto_string _corto_stateStr(corto_state value);
#define corto_stateStr(value) _corto_stateStr(value)
CORTO_EXPORT corto_state* corto_stateFromStr(corto_state* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_stateCompare(corto_state dst, corto_state src);

CORTO_EXPORT corto_int16 _corto_stateInit(corto_state* value);
#define corto_stateInit(value) _corto_stateInit(value)
CORTO_EXPORT corto_int16 _corto_stateDeinit(corto_state* value);
#define corto_stateDeinit(value) _corto_stateDeinit(value)

/* string */
CORTO_EXPORT corto_string* _corto_stringCreate(corto_string value);
#define corto_stringCreate(value) _corto_stringCreate(value)
#define corto_stringCreate_auto(_name, value) corto_string* _name = corto_stringCreate(value); (void)_name
CORTO_EXPORT corto_string* _corto_stringCreateChild(corto_object _parent, corto_string _name, corto_string value);
#define corto_stringCreateChild(_parent, _name, value) _corto_stringCreateChild(_parent, _name, value)
#define corto_stringCreateChild_auto(_parent, _name, value) corto_string* _name = corto_stringCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_stringUpdate(corto_string* _this, corto_string value);
#define corto_stringUpdate(_this, value) _corto_stringUpdate(_this, value)

CORTO_EXPORT corto_string* _corto_stringDeclare(void);
#define corto_stringDeclare() _corto_stringDeclare()
#define corto_stringDeclare_auto(_name) corto_string* _name = corto_stringDeclare(); (void)_name
CORTO_EXPORT corto_string* _corto_stringDeclareChild(corto_object _parent, corto_string _name);
#define corto_stringDeclareChild(_parent, _name) _corto_stringDeclareChild(_parent, _name)
#define corto_stringDeclareChild_auto(_parent, _name) corto_string* _name = corto_stringDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_stringDefine(corto_string* _this, corto_string value);
#define corto_stringDefine(_this, value) _corto_stringDefine(_this, value)
CORTO_EXPORT void _corto_stringSet(corto_string* _this, corto_string value);
#define corto_stringSet(_this, value) _corto_stringSet(_this, value)
CORTO_EXPORT corto_string _corto_stringStr(corto_string value);
#define corto_stringStr(value) _corto_stringStr(value)
CORTO_EXPORT corto_string* corto_stringFromStr(corto_string* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_stringCompare(corto_string dst, corto_string src);

CORTO_EXPORT corto_int16 _corto_stringInit(corto_string* value);
#define corto_stringInit(value) _corto_stringInit(value)
CORTO_EXPORT corto_int16 _corto_stringDeinit(corto_string* value);
#define corto_stringDeinit(value) _corto_stringDeinit(value)

/* struct */
CORTO_EXPORT corto_struct _corto_structCreate(corto_interface base, corto_modifier baseAccess);
#define corto_structCreate(base, baseAccess) _corto_structCreate(corto_interface(base), baseAccess)
#define corto_structCreate_auto(_name, base, baseAccess) corto_struct _name = corto_structCreate(base, baseAccess); (void)_name
CORTO_EXPORT corto_struct _corto_structCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess);
#define corto_structCreateChild(_parent, _name, base, baseAccess) _corto_structCreateChild(_parent, _name, corto_interface(base), baseAccess)
#define corto_structCreateChild_auto(_parent, _name, base, baseAccess) corto_struct _name = corto_structCreateChild(_parent, #_name, base, baseAccess); (void)_name
CORTO_EXPORT corto_int16 _corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structUpdate(_this, base, baseAccess) _corto_structUpdate(corto_struct(_this), corto_interface(base), baseAccess)

CORTO_EXPORT corto_struct _corto_structDeclare(void);
#define corto_structDeclare() _corto_structDeclare()
#define corto_structDeclare_auto(_name) corto_struct _name = corto_structDeclare(); (void)_name
CORTO_EXPORT corto_struct _corto_structDeclareChild(corto_object _parent, corto_string _name);
#define corto_structDeclareChild(_parent, _name) _corto_structDeclareChild(_parent, _name)
#define corto_structDeclareChild_auto(_parent, _name) corto_struct _name = corto_structDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structDefine(_this, base, baseAccess) _corto_structDefine(corto_struct(_this), corto_interface(base), baseAccess)
CORTO_EXPORT void _corto_structSet(corto_struct _this, corto_interface base, corto_modifier baseAccess);
#define corto_structSet(_this, base, baseAccess) _corto_structSet(corto_struct(_this), corto_interface(base), baseAccess)
CORTO_EXPORT corto_string _corto_structStr(corto_struct value);
#define corto_structStr(value) _corto_structStr(corto_struct(value))
CORTO_EXPORT corto_struct corto_structFromStr(corto_struct value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_structCompare(corto_struct dst, corto_struct src);
#define corto_structCompare(dst, src) _corto_structCompare(corto_struct(dst), corto_struct(src))

/* text */
CORTO_EXPORT corto_text _corto_textCreate(corto_width charWidth, corto_uint64 length);
#define corto_textCreate(charWidth, length) _corto_textCreate(charWidth, length)
#define corto_textCreate_auto(_name, charWidth, length) corto_text _name = corto_textCreate(charWidth, length); (void)_name
CORTO_EXPORT corto_text _corto_textCreateChild(corto_object _parent, corto_string _name, corto_width charWidth, corto_uint64 length);
#define corto_textCreateChild(_parent, _name, charWidth, length) _corto_textCreateChild(_parent, _name, charWidth, length)
#define corto_textCreateChild_auto(_parent, _name, charWidth, length) corto_text _name = corto_textCreateChild(_parent, #_name, charWidth, length); (void)_name
CORTO_EXPORT corto_int16 _corto_textUpdate(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textUpdate(_this, charWidth, length) _corto_textUpdate(corto_text(_this), charWidth, length)

CORTO_EXPORT corto_text _corto_textDeclare(void);
#define corto_textDeclare() _corto_textDeclare()
#define corto_textDeclare_auto(_name) corto_text _name = corto_textDeclare(); (void)_name
CORTO_EXPORT corto_text _corto_textDeclareChild(corto_object _parent, corto_string _name);
#define corto_textDeclareChild(_parent, _name) _corto_textDeclareChild(_parent, _name)
#define corto_textDeclareChild_auto(_parent, _name) corto_text _name = corto_textDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_textDefine(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textDefine(_this, charWidth, length) _corto_textDefine(corto_text(_this), charWidth, length)
CORTO_EXPORT void _corto_textSet(corto_text _this, corto_width charWidth, corto_uint64 length);
#define corto_textSet(_this, charWidth, length) _corto_textSet(corto_text(_this), charWidth, length)
CORTO_EXPORT corto_string _corto_textStr(corto_text value);
#define corto_textStr(value) _corto_textStr(corto_text(value))
CORTO_EXPORT corto_text corto_textFromStr(corto_text value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_textCompare(corto_text dst, corto_text src);
#define corto_textCompare(dst, src) _corto_textCompare(corto_text(dst), corto_text(src))

/* type */
CORTO_EXPORT corto_type _corto_typeCreate(corto_typeKind kind, corto_bool reference);
#define corto_typeCreate(kind, reference) _corto_typeCreate(kind, reference)
#define corto_typeCreate_auto(_name, kind, reference) corto_type _name = corto_typeCreate(kind, reference); (void)_name
CORTO_EXPORT corto_type _corto_typeCreateChild(corto_object _parent, corto_string _name, corto_typeKind kind, corto_bool reference);
#define corto_typeCreateChild(_parent, _name, kind, reference) _corto_typeCreateChild(_parent, _name, kind, reference)
#define corto_typeCreateChild_auto(_parent, _name, kind, reference) corto_type _name = corto_typeCreateChild(_parent, #_name, kind, reference); (void)_name
CORTO_EXPORT corto_int16 _corto_typeUpdate(corto_type _this, corto_typeKind kind, corto_bool reference);
#define corto_typeUpdate(_this, kind, reference) _corto_typeUpdate(corto_type(_this), kind, reference)

CORTO_EXPORT corto_type _corto_typeDeclare(void);
#define corto_typeDeclare() _corto_typeDeclare()
#define corto_typeDeclare_auto(_name) corto_type _name = corto_typeDeclare(); (void)_name
CORTO_EXPORT corto_type _corto_typeDeclareChild(corto_object _parent, corto_string _name);
#define corto_typeDeclareChild(_parent, _name) _corto_typeDeclareChild(_parent, _name)
#define corto_typeDeclareChild_auto(_parent, _name) corto_type _name = corto_typeDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_typeDefine(corto_type _this, corto_typeKind kind, corto_bool reference);
#define corto_typeDefine(_this, kind, reference) _corto_typeDefine(corto_type(_this), kind, reference)
CORTO_EXPORT void _corto_typeSet(corto_type _this, corto_typeKind kind, corto_bool reference);
#define corto_typeSet(_this, kind, reference) _corto_typeSet(corto_type(_this), kind, reference)
CORTO_EXPORT corto_string _corto_typeStr(corto_type value);
#define corto_typeStr(value) _corto_typeStr(corto_type(value))
CORTO_EXPORT corto_type corto_typeFromStr(corto_type value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_typeCompare(corto_type dst, corto_type src);
#define corto_typeCompare(dst, src) _corto_typeCompare(corto_type(dst), corto_type(src))

/* typeKind */
CORTO_EXPORT corto_typeKind* _corto_typeKindCreate(corto_typeKind value);
#define corto_typeKindCreate(value) _corto_typeKindCreate(value)
#define corto_typeKindCreate_auto(_name, value) corto_typeKind* _name = corto_typeKindCreate(value); (void)_name
CORTO_EXPORT corto_typeKind* _corto_typeKindCreateChild(corto_object _parent, corto_string _name, corto_typeKind value);
#define corto_typeKindCreateChild(_parent, _name, value) _corto_typeKindCreateChild(_parent, _name, value)
#define corto_typeKindCreateChild_auto(_parent, _name, value) corto_typeKind* _name = corto_typeKindCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindUpdate(_this, value) _corto_typeKindUpdate(_this, value)

CORTO_EXPORT corto_typeKind* _corto_typeKindDeclare(void);
#define corto_typeKindDeclare() _corto_typeKindDeclare()
#define corto_typeKindDeclare_auto(_name) corto_typeKind* _name = corto_typeKindDeclare(); (void)_name
CORTO_EXPORT corto_typeKind* _corto_typeKindDeclareChild(corto_object _parent, corto_string _name);
#define corto_typeKindDeclareChild(_parent, _name) _corto_typeKindDeclareChild(_parent, _name)
#define corto_typeKindDeclareChild_auto(_parent, _name) corto_typeKind* _name = corto_typeKindDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindDefine(_this, value) _corto_typeKindDefine(_this, value)
CORTO_EXPORT void _corto_typeKindSet(corto_typeKind* _this, corto_typeKind value);
#define corto_typeKindSet(_this, value) _corto_typeKindSet(_this, value)
CORTO_EXPORT corto_string _corto_typeKindStr(corto_typeKind value);
#define corto_typeKindStr(value) _corto_typeKindStr(value)
CORTO_EXPORT corto_typeKind* corto_typeKindFromStr(corto_typeKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_typeKindCompare(corto_typeKind dst, corto_typeKind src);

CORTO_EXPORT corto_int16 _corto_typeKindInit(corto_typeKind* value);
#define corto_typeKindInit(value) _corto_typeKindInit(value)
CORTO_EXPORT corto_int16 _corto_typeKindDeinit(corto_typeKind* value);
#define corto_typeKindDeinit(value) _corto_typeKindDeinit(value)

/* uint */
CORTO_EXPORT corto_uint _corto_uintCreate(corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintCreate(width, min, max) _corto_uintCreate(width, min, max)
#define corto_uintCreate_auto(_name, width, min, max) corto_uint _name = corto_uintCreate(width, min, max); (void)_name
CORTO_EXPORT corto_uint _corto_uintCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintCreateChild(_parent, _name, width, min, max) _corto_uintCreateChild(_parent, _name, width, min, max)
#define corto_uintCreateChild_auto(_parent, _name, width, min, max) corto_uint _name = corto_uintCreateChild(_parent, #_name, width, min, max); (void)_name
CORTO_EXPORT corto_int16 _corto_uintUpdate(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintUpdate(_this, width, min, max) _corto_uintUpdate(corto_uint(_this), width, min, max)

CORTO_EXPORT corto_uint _corto_uintDeclare(void);
#define corto_uintDeclare() _corto_uintDeclare()
#define corto_uintDeclare_auto(_name) corto_uint _name = corto_uintDeclare(); (void)_name
CORTO_EXPORT corto_uint _corto_uintDeclareChild(corto_object _parent, corto_string _name);
#define corto_uintDeclareChild(_parent, _name) _corto_uintDeclareChild(_parent, _name)
#define corto_uintDeclareChild_auto(_parent, _name) corto_uint _name = corto_uintDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_uintDefine(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintDefine(_this, width, min, max) _corto_uintDefine(corto_uint(_this), width, min, max)
CORTO_EXPORT void _corto_uintSet(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
#define corto_uintSet(_this, width, min, max) _corto_uintSet(corto_uint(_this), width, min, max)
CORTO_EXPORT corto_string _corto_uintStr(corto_uint value);
#define corto_uintStr(value) _corto_uintStr(corto_uint(value))
CORTO_EXPORT corto_uint corto_uintFromStr(corto_uint value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_uintCompare(corto_uint dst, corto_uint src);
#define corto_uintCompare(dst, src) _corto_uintCompare(corto_uint(dst), corto_uint(src))

/* uint16 */
CORTO_EXPORT corto_uint16* _corto_uint16Create(corto_uint16 value);
#define corto_uint16Create(value) _corto_uint16Create(value)
#define corto_uint16Create_auto(_name, value) corto_uint16* _name = corto_uint16Create(value); (void)_name
CORTO_EXPORT corto_uint16* _corto_uint16CreateChild(corto_object _parent, corto_string _name, corto_uint16 value);
#define corto_uint16CreateChild(_parent, _name, value) _corto_uint16CreateChild(_parent, _name, value)
#define corto_uint16CreateChild_auto(_parent, _name, value) corto_uint16* _name = corto_uint16CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_uint16Update(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Update(_this, value) _corto_uint16Update(_this, value)

CORTO_EXPORT corto_uint16* _corto_uint16Declare(void);
#define corto_uint16Declare() _corto_uint16Declare()
#define corto_uint16Declare_auto(_name) corto_uint16* _name = corto_uint16Declare(); (void)_name
CORTO_EXPORT corto_uint16* _corto_uint16DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint16DeclareChild(_parent, _name) _corto_uint16DeclareChild(_parent, _name)
#define corto_uint16DeclareChild_auto(_parent, _name) corto_uint16* _name = corto_uint16DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_uint16Define(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Define(_this, value) _corto_uint16Define(_this, value)
CORTO_EXPORT void _corto_uint16Set(corto_uint16* _this, corto_uint16 value);
#define corto_uint16Set(_this, value) _corto_uint16Set(_this, value)
CORTO_EXPORT corto_string _corto_uint16Str(corto_uint16 value);
#define corto_uint16Str(value) _corto_uint16Str(value)
CORTO_EXPORT corto_uint16* corto_uint16FromStr(corto_uint16* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_uint16Compare(corto_uint16 dst, corto_uint16 src);

CORTO_EXPORT corto_int16 _corto_uint16Init(corto_uint16* value);
#define corto_uint16Init(value) _corto_uint16Init(value)
CORTO_EXPORT corto_int16 _corto_uint16Deinit(corto_uint16* value);
#define corto_uint16Deinit(value) _corto_uint16Deinit(value)

/* uint32 */
CORTO_EXPORT corto_uint32* _corto_uint32Create(corto_uint32 value);
#define corto_uint32Create(value) _corto_uint32Create(value)
#define corto_uint32Create_auto(_name, value) corto_uint32* _name = corto_uint32Create(value); (void)_name
CORTO_EXPORT corto_uint32* _corto_uint32CreateChild(corto_object _parent, corto_string _name, corto_uint32 value);
#define corto_uint32CreateChild(_parent, _name, value) _corto_uint32CreateChild(_parent, _name, value)
#define corto_uint32CreateChild_auto(_parent, _name, value) corto_uint32* _name = corto_uint32CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_uint32Update(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Update(_this, value) _corto_uint32Update(_this, value)

CORTO_EXPORT corto_uint32* _corto_uint32Declare(void);
#define corto_uint32Declare() _corto_uint32Declare()
#define corto_uint32Declare_auto(_name) corto_uint32* _name = corto_uint32Declare(); (void)_name
CORTO_EXPORT corto_uint32* _corto_uint32DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint32DeclareChild(_parent, _name) _corto_uint32DeclareChild(_parent, _name)
#define corto_uint32DeclareChild_auto(_parent, _name) corto_uint32* _name = corto_uint32DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_uint32Define(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Define(_this, value) _corto_uint32Define(_this, value)
CORTO_EXPORT void _corto_uint32Set(corto_uint32* _this, corto_uint32 value);
#define corto_uint32Set(_this, value) _corto_uint32Set(_this, value)
CORTO_EXPORT corto_string _corto_uint32Str(corto_uint32 value);
#define corto_uint32Str(value) _corto_uint32Str(value)
CORTO_EXPORT corto_uint32* corto_uint32FromStr(corto_uint32* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_uint32Compare(corto_uint32 dst, corto_uint32 src);

CORTO_EXPORT corto_int16 _corto_uint32Init(corto_uint32* value);
#define corto_uint32Init(value) _corto_uint32Init(value)
CORTO_EXPORT corto_int16 _corto_uint32Deinit(corto_uint32* value);
#define corto_uint32Deinit(value) _corto_uint32Deinit(value)

/* uint64 */
CORTO_EXPORT corto_uint64* _corto_uint64Create(corto_uint64 value);
#define corto_uint64Create(value) _corto_uint64Create(value)
#define corto_uint64Create_auto(_name, value) corto_uint64* _name = corto_uint64Create(value); (void)_name
CORTO_EXPORT corto_uint64* _corto_uint64CreateChild(corto_object _parent, corto_string _name, corto_uint64 value);
#define corto_uint64CreateChild(_parent, _name, value) _corto_uint64CreateChild(_parent, _name, value)
#define corto_uint64CreateChild_auto(_parent, _name, value) corto_uint64* _name = corto_uint64CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_uint64Update(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Update(_this, value) _corto_uint64Update(_this, value)

CORTO_EXPORT corto_uint64* _corto_uint64Declare(void);
#define corto_uint64Declare() _corto_uint64Declare()
#define corto_uint64Declare_auto(_name) corto_uint64* _name = corto_uint64Declare(); (void)_name
CORTO_EXPORT corto_uint64* _corto_uint64DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint64DeclareChild(_parent, _name) _corto_uint64DeclareChild(_parent, _name)
#define corto_uint64DeclareChild_auto(_parent, _name) corto_uint64* _name = corto_uint64DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_uint64Define(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Define(_this, value) _corto_uint64Define(_this, value)
CORTO_EXPORT void _corto_uint64Set(corto_uint64* _this, corto_uint64 value);
#define corto_uint64Set(_this, value) _corto_uint64Set(_this, value)
CORTO_EXPORT corto_string _corto_uint64Str(corto_uint64 value);
#define corto_uint64Str(value) _corto_uint64Str(value)
CORTO_EXPORT corto_uint64* corto_uint64FromStr(corto_uint64* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_uint64Compare(corto_uint64 dst, corto_uint64 src);

CORTO_EXPORT corto_int16 _corto_uint64Init(corto_uint64* value);
#define corto_uint64Init(value) _corto_uint64Init(value)
CORTO_EXPORT corto_int16 _corto_uint64Deinit(corto_uint64* value);
#define corto_uint64Deinit(value) _corto_uint64Deinit(value)

/* uint8 */
CORTO_EXPORT corto_uint8* _corto_uint8Create(corto_uint8 value);
#define corto_uint8Create(value) _corto_uint8Create(value)
#define corto_uint8Create_auto(_name, value) corto_uint8* _name = corto_uint8Create(value); (void)_name
CORTO_EXPORT corto_uint8* _corto_uint8CreateChild(corto_object _parent, corto_string _name, corto_uint8 value);
#define corto_uint8CreateChild(_parent, _name, value) _corto_uint8CreateChild(_parent, _name, value)
#define corto_uint8CreateChild_auto(_parent, _name, value) corto_uint8* _name = corto_uint8CreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_uint8Update(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Update(_this, value) _corto_uint8Update(_this, value)

CORTO_EXPORT corto_uint8* _corto_uint8Declare(void);
#define corto_uint8Declare() _corto_uint8Declare()
#define corto_uint8Declare_auto(_name) corto_uint8* _name = corto_uint8Declare(); (void)_name
CORTO_EXPORT corto_uint8* _corto_uint8DeclareChild(corto_object _parent, corto_string _name);
#define corto_uint8DeclareChild(_parent, _name) _corto_uint8DeclareChild(_parent, _name)
#define corto_uint8DeclareChild_auto(_parent, _name) corto_uint8* _name = corto_uint8DeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_uint8Define(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Define(_this, value) _corto_uint8Define(_this, value)
CORTO_EXPORT void _corto_uint8Set(corto_uint8* _this, corto_uint8 value);
#define corto_uint8Set(_this, value) _corto_uint8Set(_this, value)
CORTO_EXPORT corto_string _corto_uint8Str(corto_uint8 value);
#define corto_uint8Str(value) _corto_uint8Str(value)
CORTO_EXPORT corto_uint8* corto_uint8FromStr(corto_uint8* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_uint8Compare(corto_uint8 dst, corto_uint8 src);

CORTO_EXPORT corto_int16 _corto_uint8Init(corto_uint8* value);
#define corto_uint8Init(value) _corto_uint8Init(value)
CORTO_EXPORT corto_int16 _corto_uint8Deinit(corto_uint8* value);
#define corto_uint8Deinit(value) _corto_uint8Deinit(value)

/* virtual */
CORTO_EXPORT corto_virtual _corto_virtualCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualCreate(returnType, returnsReference, _virtual, _impl) _corto_virtualCreate(corto_type(returnType), returnsReference, _virtual, _impl)
#define corto_virtualCreate_auto(_name, returnType, returnsReference, _virtual, _impl) corto_virtual _name = corto_virtualCreate(returnType, returnsReference, _virtual, _impl); (void)_name
CORTO_EXPORT corto_virtual _corto_virtualCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualCreateChild(_parent, _name, returnType, returnsReference, _virtual, _impl) _corto_virtualCreateChild(_parent, _name, corto_type(returnType), returnsReference, _virtual, _impl)
#define corto_virtualCreateChild_auto(_parent, _name, returnType, returnsReference, _virtual, _impl) corto_virtual _name = corto_virtualCreateChild(_parent, #_name, returnType, returnsReference, _virtual, _impl); (void)_name
CORTO_EXPORT corto_int16 _corto_virtualUpdate(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualUpdate(_this, returnType, returnsReference, _virtual, _impl) _corto_virtualUpdate(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual, _impl)

CORTO_EXPORT corto_virtual _corto_virtualDeclare(void);
#define corto_virtualDeclare() _corto_virtualDeclare()
#define corto_virtualDeclare_auto(_name) corto_virtual _name = corto_virtualDeclare(); (void)_name
CORTO_EXPORT corto_virtual _corto_virtualDeclareChild(corto_object _parent, corto_string _name);
#define corto_virtualDeclareChild(_parent, _name) _corto_virtualDeclareChild(_parent, _name)
#define corto_virtualDeclareChild_auto(_parent, _name) corto_virtual _name = corto_virtualDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_virtualDefine(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualDefine(_this, returnType, returnsReference, _virtual, _impl) _corto_virtualDefine(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_EXPORT void _corto_virtualSet(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
#define corto_virtualSet(_this, returnType, returnsReference, _virtual, _impl) _corto_virtualSet(corto_virtual(_this), corto_type(returnType), returnsReference, _virtual, _impl)
CORTO_EXPORT corto_string _corto_virtualStr(corto_virtual value);
#define corto_virtualStr(value) _corto_virtualStr(corto_virtual(value))
CORTO_EXPORT corto_virtual corto_virtualFromStr(corto_virtual value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_virtualCompare(corto_virtual dst, corto_virtual src);
#define corto_virtualCompare(dst, src) _corto_virtualCompare(corto_virtual(dst), corto_virtual(src))

/* void */
CORTO_EXPORT corto_void* _corto_voidCreate(void);
#define corto_voidCreate() _corto_voidCreate()
#define corto_voidCreate_auto(_name) corto_void* _name = corto_voidCreate(); (void)_name
CORTO_EXPORT corto_void* _corto_voidCreateChild(corto_object _parent, corto_string _name);
#define corto_voidCreateChild(_parent, _name) _corto_voidCreateChild(_parent, _name)
#define corto_voidCreateChild_auto(_parent, _name) corto_void* _name = corto_voidCreateChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_voidUpdate(corto_void* _this);
#define corto_voidUpdate(_this) _corto_voidUpdate(_this)

/* vtable */
CORTO_EXPORT corto_vtable* _corto_vtableCreate(corto_uint32 length, corto_function* elements);
#define corto_vtableCreate(length, elements) _corto_vtableCreate(length, elements)
#define corto_vtableCreate_auto(_name, length, elements) corto_vtable* _name = corto_vtableCreate(length, elements); (void)_name
CORTO_EXPORT corto_vtable* _corto_vtableCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, corto_function* elements);
#define corto_vtableCreateChild(_parent, _name, length, elements) _corto_vtableCreateChild(_parent, _name, length, elements)
#define corto_vtableCreateChild_auto(_parent, _name, length, elements) corto_vtable* _name = corto_vtableCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_EXPORT corto_int16 _corto_vtableUpdate(corto_vtable* _this, corto_uint32 length, corto_function* elements);
#define corto_vtableUpdate(_this, length, elements) _corto_vtableUpdate(_this, length, elements)

CORTO_EXPORT corto_vtable* _corto_vtableDeclare(void);
#define corto_vtableDeclare() _corto_vtableDeclare()
#define corto_vtableDeclare_auto(_name) corto_vtable* _name = corto_vtableDeclare(); (void)_name
CORTO_EXPORT corto_vtable* _corto_vtableDeclareChild(corto_object _parent, corto_string _name);
#define corto_vtableDeclareChild(_parent, _name) _corto_vtableDeclareChild(_parent, _name)
#define corto_vtableDeclareChild_auto(_parent, _name) corto_vtable* _name = corto_vtableDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_vtableDefine(corto_vtable* _this, corto_uint32 length, corto_function* elements);
#define corto_vtableDefine(_this, length, elements) _corto_vtableDefine(_this, length, elements)
CORTO_EXPORT void _corto_vtableSet(corto_vtable* _this, corto_uint32 length, corto_function* elements);
#define corto_vtableSet(_this, length, elements) _corto_vtableSet(_this, length, elements)
CORTO_EXPORT corto_string _corto_vtableStr(corto_vtable value);
#define corto_vtableStr(value) _corto_vtableStr(value)
CORTO_EXPORT corto_vtable* corto_vtableFromStr(corto_vtable* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_vtableCompare(corto_vtable dst, corto_vtable src);

CORTO_EXPORT corto_int16 _corto_vtableInit(corto_vtable* value);
#define corto_vtableInit(value) _corto_vtableInit(value)
CORTO_EXPORT corto_int16 _corto_vtableDeinit(corto_vtable* value);
#define corto_vtableDeinit(value) _corto_vtableDeinit(value)

/* width */
CORTO_EXPORT corto_width* _corto_widthCreate(corto_width value);
#define corto_widthCreate(value) _corto_widthCreate(value)
#define corto_widthCreate_auto(_name, value) corto_width* _name = corto_widthCreate(value); (void)_name
CORTO_EXPORT corto_width* _corto_widthCreateChild(corto_object _parent, corto_string _name, corto_width value);
#define corto_widthCreateChild(_parent, _name, value) _corto_widthCreateChild(_parent, _name, value)
#define corto_widthCreateChild_auto(_parent, _name, value) corto_width* _name = corto_widthCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_widthUpdate(corto_width* _this, corto_width value);
#define corto_widthUpdate(_this, value) _corto_widthUpdate(_this, value)

CORTO_EXPORT corto_width* _corto_widthDeclare(void);
#define corto_widthDeclare() _corto_widthDeclare()
#define corto_widthDeclare_auto(_name) corto_width* _name = corto_widthDeclare(); (void)_name
CORTO_EXPORT corto_width* _corto_widthDeclareChild(corto_object _parent, corto_string _name);
#define corto_widthDeclareChild(_parent, _name) _corto_widthDeclareChild(_parent, _name)
#define corto_widthDeclareChild_auto(_parent, _name) corto_width* _name = corto_widthDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_widthDefine(corto_width* _this, corto_width value);
#define corto_widthDefine(_this, value) _corto_widthDefine(_this, value)
CORTO_EXPORT void _corto_widthSet(corto_width* _this, corto_width value);
#define corto_widthSet(_this, value) _corto_widthSet(_this, value)
CORTO_EXPORT corto_string _corto_widthStr(corto_width value);
#define corto_widthStr(value) _corto_widthStr(value)
CORTO_EXPORT corto_width* corto_widthFromStr(corto_width* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_widthCompare(corto_width dst, corto_width src);

CORTO_EXPORT corto_int16 _corto_widthInit(corto_width* value);
#define corto_widthInit(value) _corto_widthInit(value)
CORTO_EXPORT corto_int16 _corto_widthDeinit(corto_width* value);
#define corto_widthDeinit(value) _corto_widthDeinit(value)

/* word */
CORTO_EXPORT corto_word* _corto_wordCreate(corto_word value);
#define corto_wordCreate(value) _corto_wordCreate(value)
#define corto_wordCreate_auto(_name, value) corto_word* _name = corto_wordCreate(value); (void)_name
CORTO_EXPORT corto_word* _corto_wordCreateChild(corto_object _parent, corto_string _name, corto_word value);
#define corto_wordCreateChild(_parent, _name, value) _corto_wordCreateChild(_parent, _name, value)
#define corto_wordCreateChild_auto(_parent, _name, value) corto_word* _name = corto_wordCreateChild(_parent, #_name, value); (void)_name
CORTO_EXPORT corto_int16 _corto_wordUpdate(corto_word* _this, corto_word value);
#define corto_wordUpdate(_this, value) _corto_wordUpdate(_this, value)

CORTO_EXPORT corto_word* _corto_wordDeclare(void);
#define corto_wordDeclare() _corto_wordDeclare()
#define corto_wordDeclare_auto(_name) corto_word* _name = corto_wordDeclare(); (void)_name
CORTO_EXPORT corto_word* _corto_wordDeclareChild(corto_object _parent, corto_string _name);
#define corto_wordDeclareChild(_parent, _name) _corto_wordDeclareChild(_parent, _name)
#define corto_wordDeclareChild_auto(_parent, _name) corto_word* _name = corto_wordDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_wordDefine(corto_word* _this, corto_word value);
#define corto_wordDefine(_this, value) _corto_wordDefine(_this, value)
CORTO_EXPORT void _corto_wordSet(corto_word* _this, corto_word value);
#define corto_wordSet(_this, value) _corto_wordSet(_this, value)
CORTO_EXPORT corto_string _corto_wordStr(corto_word value);
#define corto_wordStr(value) _corto_wordStr(value)
CORTO_EXPORT corto_word* corto_wordFromStr(corto_word* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_wordCompare(corto_word dst, corto_word src);

CORTO_EXPORT corto_int16 _corto_wordInit(corto_word* value);
#define corto_wordInit(value) _corto_wordInit(value)
CORTO_EXPORT corto_int16 _corto_wordDeinit(corto_word* value);
#define corto_wordDeinit(value) _corto_wordDeinit(value)


/* interfaceseq */
#define corto_interfaceseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interface elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element);
CORTO_EXPORT corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq);
CORTO_EXPORT void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceseqClear(corto_interfaceseq *seq);

/* interfaceVectorseq */
#define corto_interfaceVectorseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interfaceVector elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element);
CORTO_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq);
CORTO_EXPORT void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq);

/* memberseq */
#define corto_memberseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_member elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_member* corto_memberseqAppend(corto_memberseq *seq, corto_member element);
CORTO_EXPORT corto_member* corto_memberseqAppendAlloc(corto_memberseq *seq);
CORTO_EXPORT void corto_memberseqSize(corto_memberseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_memberseqClear(corto_memberseq *seq);

/* objectseq */
#define corto_objectseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_object elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element);
CORTO_EXPORT corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq);
CORTO_EXPORT void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_objectseqClear(corto_objectseq *seq);

/* octetseq */
#define corto_octetseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_octet elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_octet* corto_octetseqAppend(corto_octetseq *seq, corto_octet element);
CORTO_EXPORT corto_octet* corto_octetseqAppendAlloc(corto_octetseq *seq);
CORTO_EXPORT void corto_octetseqSize(corto_octetseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_octetseqClear(corto_octetseq *seq);

/* parameterseq */
#define corto_parameterseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_parameter elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element);
CORTO_EXPORT corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq);
CORTO_EXPORT void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length);
CORTO_EXPORT void corto_parameterseqClear(corto_parameterseq *seq);

/* vtable */
#define corto_vtableForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_function elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_EXPORT corto_function* corto_vtableAppend(corto_vtable *seq, corto_function element);
CORTO_EXPORT corto_function* corto_vtableAppendAlloc(corto_vtable *seq);
CORTO_EXPORT void corto_vtableSize(corto_vtable *seq, corto_uint32 length);
CORTO_EXPORT void corto_vtableClear(corto_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

