/* cx__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang__API_H
#define corto_lang__API_H

#include "corto.h"
#include "cx__interface.h"
#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::lang::alias */
CORTO_LANG_EXPORT cx_alias cx_aliasCreate(cx_member member);
CORTO_LANG_EXPORT cx_alias cx_aliasCreateChild(cx_object _parent, cx_string _name, cx_member member);

CORTO_LANG_EXPORT cx_alias cx_aliasDeclare(void);
CORTO_LANG_EXPORT cx_alias cx_aliasDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_aliasDefine(cx_alias _this, cx_member member);
CORTO_LANG_EXPORT void cx_aliasUpdate(cx_alias _this, cx_member member);
CORTO_LANG_EXPORT void cx_aliasSet(cx_alias _this, cx_member member);
CORTO_LANG_EXPORT cx_string cx_aliasStr(cx_alias value);
CORTO_LANG_EXPORT cx_alias cx_aliasFromStr(cx_alias value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_aliasCopy(cx_alias *dst, cx_alias src);
CORTO_LANG_EXPORT cx_int16 cx_aliasCompare(cx_alias dst, cx_alias src);

/* ::corto::lang::any */
CORTO_LANG_EXPORT cx_any* cx_anyCreate(cx_any value);
CORTO_LANG_EXPORT cx_any* cx_anyCreateChild(cx_object _parent, cx_string _name, cx_any value);

CORTO_LANG_EXPORT cx_any* cx_anyDeclare(void);
CORTO_LANG_EXPORT cx_any* cx_anyDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_anyDefine(cx_any* _this, cx_any value);
CORTO_LANG_EXPORT void cx_anyUpdate(cx_any* _this, cx_any value);
CORTO_LANG_EXPORT void cx_anySet(cx_any* _this, cx_any value);
CORTO_LANG_EXPORT cx_string cx_anyStr(cx_any value);
CORTO_LANG_EXPORT cx_any* cx_anyFromStr(cx_any* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_anyCopy(cx_any* *dst, cx_any* src);
CORTO_LANG_EXPORT cx_int16 cx_anyCompare(cx_any* dst, cx_any* src);

CORTO_LANG_EXPORT cx_int16 cx_anyInit(cx_any* value);
CORTO_LANG_EXPORT cx_int16 cx_anyDeinit(cx_any* value);

/* ::corto::lang::array */
CORTO_LANG_EXPORT cx_array cx_arrayCreate(cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_array cx_arrayCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

CORTO_LANG_EXPORT cx_array cx_arrayDeclare(void);
CORTO_LANG_EXPORT cx_array cx_arrayDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_arrayDefine(cx_array _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_arrayUpdate(cx_array _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_arraySet(cx_array _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_string cx_arrayStr(cx_array value);
CORTO_LANG_EXPORT cx_array cx_arrayFromStr(cx_array value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_arrayCopy(cx_array *dst, cx_array src);
CORTO_LANG_EXPORT cx_int16 cx_arrayCompare(cx_array dst, cx_array src);

/* ::corto::lang::attr */
CORTO_LANG_EXPORT cx_attr* cx_attrCreate(cx_attr value);
CORTO_LANG_EXPORT cx_attr* cx_attrCreateChild(cx_object _parent, cx_string _name, cx_attr value);

CORTO_LANG_EXPORT cx_attr* cx_attrDeclare(void);
CORTO_LANG_EXPORT cx_attr* cx_attrDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_attrDefine(cx_attr* _this, cx_attr value);
CORTO_LANG_EXPORT void cx_attrUpdate(cx_attr* _this, cx_attr value);
CORTO_LANG_EXPORT void cx_attrSet(cx_attr* _this, cx_attr value);
CORTO_LANG_EXPORT cx_string cx_attrStr(cx_attr value);
CORTO_LANG_EXPORT cx_attr* cx_attrFromStr(cx_attr* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_attrCopy(cx_attr* *dst, cx_attr* src);
CORTO_LANG_EXPORT cx_int16 cx_attrCompare(cx_attr* dst, cx_attr* src);

CORTO_LANG_EXPORT cx_int16 cx_attrInit(cx_attr* value);
CORTO_LANG_EXPORT cx_int16 cx_attrDeinit(cx_attr* value);

/* ::corto::lang::binary */
CORTO_LANG_EXPORT cx_binary cx_binaryCreate(cx_width width);
CORTO_LANG_EXPORT cx_binary cx_binaryCreateChild(cx_object _parent, cx_string _name, cx_width width);

CORTO_LANG_EXPORT cx_binary cx_binaryDeclare(void);
CORTO_LANG_EXPORT cx_binary cx_binaryDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_binaryDefine(cx_binary _this, cx_width width);
CORTO_LANG_EXPORT void cx_binaryUpdate(cx_binary _this, cx_width width);
CORTO_LANG_EXPORT void cx_binarySet(cx_binary _this, cx_width width);
CORTO_LANG_EXPORT cx_string cx_binaryStr(cx_binary value);
CORTO_LANG_EXPORT cx_binary cx_binaryFromStr(cx_binary value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_binaryCopy(cx_binary *dst, cx_binary src);
CORTO_LANG_EXPORT cx_int16 cx_binaryCompare(cx_binary dst, cx_binary src);

/* ::corto::lang::bitmask */
CORTO_LANG_EXPORT cx_bitmask cx_bitmaskCreate(void);
CORTO_LANG_EXPORT cx_bitmask cx_bitmaskCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_bitmask cx_bitmaskDeclare(void);
CORTO_LANG_EXPORT cx_bitmask cx_bitmaskDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_bitmaskDefine(cx_bitmask _this);
CORTO_LANG_EXPORT void cx_bitmaskUpdate(cx_bitmask _this);
CORTO_LANG_EXPORT void cx_bitmaskSet(cx_bitmask _this);
CORTO_LANG_EXPORT cx_string cx_bitmaskStr(cx_bitmask value);
CORTO_LANG_EXPORT cx_bitmask cx_bitmaskFromStr(cx_bitmask value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_bitmaskCopy(cx_bitmask *dst, cx_bitmask src);
CORTO_LANG_EXPORT cx_int16 cx_bitmaskCompare(cx_bitmask dst, cx_bitmask src);

/* ::corto::lang::bool */
CORTO_LANG_EXPORT cx_bool* cx_boolCreate(cx_bool value);
CORTO_LANG_EXPORT cx_bool* cx_boolCreateChild(cx_object _parent, cx_string _name, cx_bool value);

CORTO_LANG_EXPORT cx_bool* cx_boolDeclare(void);
CORTO_LANG_EXPORT cx_bool* cx_boolDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_boolDefine(cx_bool* _this, cx_bool value);
CORTO_LANG_EXPORT void cx_boolUpdate(cx_bool* _this, cx_bool value);
CORTO_LANG_EXPORT void cx_boolSet(cx_bool* _this, cx_bool value);
CORTO_LANG_EXPORT cx_string cx_boolStr(cx_bool value);
CORTO_LANG_EXPORT cx_bool* cx_boolFromStr(cx_bool* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_boolCopy(cx_bool* *dst, cx_bool* src);
CORTO_LANG_EXPORT cx_int16 cx_boolCompare(cx_bool* dst, cx_bool* src);

CORTO_LANG_EXPORT cx_int16 cx_boolInit(cx_bool* value);
CORTO_LANG_EXPORT cx_int16 cx_boolDeinit(cx_bool* value);

/* ::corto::lang::boolean */
CORTO_LANG_EXPORT cx_boolean cx_booleanCreate(void);
CORTO_LANG_EXPORT cx_boolean cx_booleanCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_boolean cx_booleanDeclare(void);
CORTO_LANG_EXPORT cx_boolean cx_booleanDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_booleanDefine(cx_boolean _this);
CORTO_LANG_EXPORT void cx_booleanUpdate(cx_boolean _this);
CORTO_LANG_EXPORT void cx_booleanSet(cx_boolean _this);
CORTO_LANG_EXPORT cx_string cx_booleanStr(cx_boolean value);
CORTO_LANG_EXPORT cx_boolean cx_booleanFromStr(cx_boolean value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_booleanCopy(cx_boolean *dst, cx_boolean src);
CORTO_LANG_EXPORT cx_int16 cx_booleanCompare(cx_boolean dst, cx_boolean src);

/* ::corto::lang::char */
CORTO_LANG_EXPORT cx_char* cx_charCreate(cx_char value);
CORTO_LANG_EXPORT cx_char* cx_charCreateChild(cx_object _parent, cx_string _name, cx_char value);

CORTO_LANG_EXPORT cx_char* cx_charDeclare(void);
CORTO_LANG_EXPORT cx_char* cx_charDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_charDefine(cx_char* _this, cx_char value);
CORTO_LANG_EXPORT void cx_charUpdate(cx_char* _this, cx_char value);
CORTO_LANG_EXPORT void cx_charSet(cx_char* _this, cx_char value);
CORTO_LANG_EXPORT cx_string cx_charStr(cx_char value);
CORTO_LANG_EXPORT cx_char* cx_charFromStr(cx_char* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_charCopy(cx_char* *dst, cx_char* src);
CORTO_LANG_EXPORT cx_int16 cx_charCompare(cx_char* dst, cx_char* src);

CORTO_LANG_EXPORT cx_int16 cx_charInit(cx_char* value);
CORTO_LANG_EXPORT cx_int16 cx_charDeinit(cx_char* value);

/* ::corto::lang::character */
CORTO_LANG_EXPORT cx_character cx_characterCreate(cx_width width);
CORTO_LANG_EXPORT cx_character cx_characterCreateChild(cx_object _parent, cx_string _name, cx_width width);

CORTO_LANG_EXPORT cx_character cx_characterDeclare(void);
CORTO_LANG_EXPORT cx_character cx_characterDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_characterDefine(cx_character _this, cx_width width);
CORTO_LANG_EXPORT void cx_characterUpdate(cx_character _this, cx_width width);
CORTO_LANG_EXPORT void cx_characterSet(cx_character _this, cx_width width);
CORTO_LANG_EXPORT cx_string cx_characterStr(cx_character value);
CORTO_LANG_EXPORT cx_character cx_characterFromStr(cx_character value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_characterCopy(cx_character *dst, cx_character src);
CORTO_LANG_EXPORT cx_int16 cx_characterCompare(cx_character dst, cx_character src);

/* ::corto::lang::class */
CORTO_LANG_EXPORT cx_class cx_classCreate(cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_class cx_classCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);

CORTO_LANG_EXPORT cx_class cx_classDeclare(void);
CORTO_LANG_EXPORT cx_class cx_classDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_classDefine(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_classUpdate(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_classSet(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_string cx_classStr(cx_class value);
CORTO_LANG_EXPORT cx_class cx_classFromStr(cx_class value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_classCopy(cx_class *dst, cx_class src);
CORTO_LANG_EXPORT cx_int16 cx_classCompare(cx_class dst, cx_class src);

/* ::corto::lang::collection */
CORTO_LANG_EXPORT cx_collection cx_collectionCreate(cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_collection cx_collectionCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

CORTO_LANG_EXPORT cx_collection cx_collectionDeclare(void);
CORTO_LANG_EXPORT cx_collection cx_collectionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_collectionDefine(cx_collection _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_collectionUpdate(cx_collection _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_collectionSet(cx_collection _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_string cx_collectionStr(cx_collection value);
CORTO_LANG_EXPORT cx_collection cx_collectionFromStr(cx_collection value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_collectionCopy(cx_collection *dst, cx_collection src);
CORTO_LANG_EXPORT cx_int16 cx_collectionCompare(cx_collection dst, cx_collection src);

/* ::corto::lang::collectionKind */
CORTO_LANG_EXPORT cx_collectionKind* cx_collectionKindCreate(cx_collectionKind value);
CORTO_LANG_EXPORT cx_collectionKind* cx_collectionKindCreateChild(cx_object _parent, cx_string _name, cx_collectionKind value);

CORTO_LANG_EXPORT cx_collectionKind* cx_collectionKindDeclare(void);
CORTO_LANG_EXPORT cx_collectionKind* cx_collectionKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_collectionKindDefine(cx_collectionKind* _this, cx_collectionKind value);
CORTO_LANG_EXPORT void cx_collectionKindUpdate(cx_collectionKind* _this, cx_collectionKind value);
CORTO_LANG_EXPORT void cx_collectionKindSet(cx_collectionKind* _this, cx_collectionKind value);
CORTO_LANG_EXPORT cx_string cx_collectionKindStr(cx_collectionKind value);
CORTO_LANG_EXPORT cx_collectionKind* cx_collectionKindFromStr(cx_collectionKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_collectionKindCopy(cx_collectionKind* *dst, cx_collectionKind* src);
CORTO_LANG_EXPORT cx_int16 cx_collectionKindCompare(cx_collectionKind* dst, cx_collectionKind* src);

CORTO_LANG_EXPORT cx_int16 cx_collectionKindInit(cx_collectionKind* value);
CORTO_LANG_EXPORT cx_int16 cx_collectionKindDeinit(cx_collectionKind* value);

/* ::corto::lang::compositeKind */
CORTO_LANG_EXPORT cx_compositeKind* cx_compositeKindCreate(cx_compositeKind value);
CORTO_LANG_EXPORT cx_compositeKind* cx_compositeKindCreateChild(cx_object _parent, cx_string _name, cx_compositeKind value);

CORTO_LANG_EXPORT cx_compositeKind* cx_compositeKindDeclare(void);
CORTO_LANG_EXPORT cx_compositeKind* cx_compositeKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_compositeKindDefine(cx_compositeKind* _this, cx_compositeKind value);
CORTO_LANG_EXPORT void cx_compositeKindUpdate(cx_compositeKind* _this, cx_compositeKind value);
CORTO_LANG_EXPORT void cx_compositeKindSet(cx_compositeKind* _this, cx_compositeKind value);
CORTO_LANG_EXPORT cx_string cx_compositeKindStr(cx_compositeKind value);
CORTO_LANG_EXPORT cx_compositeKind* cx_compositeKindFromStr(cx_compositeKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_compositeKindCopy(cx_compositeKind* *dst, cx_compositeKind* src);
CORTO_LANG_EXPORT cx_int16 cx_compositeKindCompare(cx_compositeKind* dst, cx_compositeKind* src);

CORTO_LANG_EXPORT cx_int16 cx_compositeKindInit(cx_compositeKind* value);
CORTO_LANG_EXPORT cx_int16 cx_compositeKindDeinit(cx_compositeKind* value);

/* ::corto::lang::constant */
CORTO_LANG_EXPORT cx_constant* cx_constantCreate(cx_constant value);
CORTO_LANG_EXPORT cx_constant* cx_constantCreateChild(cx_object _parent, cx_string _name, cx_constant value);

CORTO_LANG_EXPORT cx_constant* cx_constantDeclare(void);
CORTO_LANG_EXPORT cx_constant* cx_constantDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_constantDefine(cx_constant* _this, cx_constant value);
CORTO_LANG_EXPORT void cx_constantUpdate(cx_constant* _this, cx_constant value);
CORTO_LANG_EXPORT void cx_constantSet(cx_constant* _this, cx_constant value);
CORTO_LANG_EXPORT cx_string cx_constantStr(cx_constant value);
CORTO_LANG_EXPORT cx_constant* cx_constantFromStr(cx_constant* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_constantCopy(cx_constant* *dst, cx_constant* src);
CORTO_LANG_EXPORT cx_int16 cx_constantCompare(cx_constant* dst, cx_constant* src);

CORTO_LANG_EXPORT cx_int16 cx_constantInit(cx_constant* value);
CORTO_LANG_EXPORT cx_int16 cx_constantDeinit(cx_constant* value);

/* ::corto::lang::delegate */
CORTO_LANG_EXPORT cx_delegate cx_delegateCreate(cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
CORTO_LANG_EXPORT cx_delegate cx_delegateCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);

CORTO_LANG_EXPORT cx_delegate cx_delegateDeclare(void);
CORTO_LANG_EXPORT cx_delegate cx_delegateDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_delegateDefine(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
CORTO_LANG_EXPORT void cx_delegateUpdate(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
CORTO_LANG_EXPORT void cx_delegateSet(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
CORTO_LANG_EXPORT cx_string cx_delegateStr(cx_delegate value);
CORTO_LANG_EXPORT cx_delegate cx_delegateFromStr(cx_delegate value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_delegateCopy(cx_delegate *dst, cx_delegate src);
CORTO_LANG_EXPORT cx_int16 cx_delegateCompare(cx_delegate dst, cx_delegate src);

/* ::corto::lang::delegatedata */
CORTO_LANG_EXPORT cx_delegatedata* cx_delegatedataCreate(cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_delegatedata* cx_delegatedataCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

CORTO_LANG_EXPORT cx_delegatedata* cx_delegatedataDeclare(void);
CORTO_LANG_EXPORT cx_delegatedata* cx_delegatedataDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_delegatedataDefine(cx_delegatedata* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_delegatedataUpdate(cx_delegatedata* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_delegatedataSet(cx_delegatedata* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_string cx_delegatedataStr(cx_delegatedata* value);
CORTO_LANG_EXPORT cx_delegatedata* cx_delegatedataFromStr(cx_delegatedata* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_delegatedataCopy(cx_delegatedata* *dst, cx_delegatedata* src);
CORTO_LANG_EXPORT cx_int16 cx_delegatedataCompare(cx_delegatedata* dst, cx_delegatedata* src);

CORTO_LANG_EXPORT cx_int16 cx_delegatedataInit(cx_delegatedata* value);
CORTO_LANG_EXPORT cx_int16 cx_delegatedataDeinit(cx_delegatedata* value);

/* ::corto::lang::destructAction */
CORTO_LANG_EXPORT cx_destructAction* cx_destructActionCreate(cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_destructAction* cx_destructActionCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

CORTO_LANG_EXPORT cx_destructAction* cx_destructActionDeclare(void);
CORTO_LANG_EXPORT cx_destructAction* cx_destructActionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_destructActionDefine(cx_destructAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_destructActionUpdate(cx_destructAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_destructActionSet(cx_destructAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_string cx_destructActionStr(cx_destructAction* value);
CORTO_LANG_EXPORT cx_destructAction* cx_destructActionFromStr(cx_destructAction* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_destructActionCopy(cx_destructAction* *dst, cx_destructAction* src);
CORTO_LANG_EXPORT cx_int16 cx_destructActionCompare(cx_destructAction* dst, cx_destructAction* src);

CORTO_LANG_EXPORT cx_int16 cx_destructActionInit(cx_destructAction* value);
CORTO_LANG_EXPORT cx_int16 cx_destructActionDeinit(cx_destructAction* value);

cx_int16 cx_destructActionCall(cx_destructAction *_delegate);
/* ::corto::lang::dispatcher */
CORTO_LANG_EXPORT cx_dispatcher cx_dispatcherCreate(void);
CORTO_LANG_EXPORT cx_dispatcher cx_dispatcherCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_dispatcher cx_dispatcherDeclare(void);
CORTO_LANG_EXPORT cx_dispatcher cx_dispatcherDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_dispatcherDefine(cx_dispatcher _this);
CORTO_LANG_EXPORT void cx_dispatcherUpdate(cx_dispatcher _this);
CORTO_LANG_EXPORT void cx_dispatcherSet(cx_dispatcher _this);
CORTO_LANG_EXPORT cx_string cx_dispatcherStr(cx_dispatcher value);
CORTO_LANG_EXPORT cx_dispatcher cx_dispatcherFromStr(cx_dispatcher value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_dispatcherCopy(cx_dispatcher *dst, cx_dispatcher src);
CORTO_LANG_EXPORT cx_int16 cx_dispatcherCompare(cx_dispatcher dst, cx_dispatcher src);

/* ::corto::lang::enum */
CORTO_LANG_EXPORT cx_enum cx_enumCreate(void);
CORTO_LANG_EXPORT cx_enum cx_enumCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_enum cx_enumDeclare(void);
CORTO_LANG_EXPORT cx_enum cx_enumDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_enumDefine(cx_enum _this);
CORTO_LANG_EXPORT void cx_enumUpdate(cx_enum _this);
CORTO_LANG_EXPORT void cx_enumSet(cx_enum _this);
CORTO_LANG_EXPORT cx_string cx_enumStr(cx_enum value);
CORTO_LANG_EXPORT cx_enum cx_enumFromStr(cx_enum value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_enumCopy(cx_enum *dst, cx_enum src);
CORTO_LANG_EXPORT cx_int16 cx_enumCompare(cx_enum dst, cx_enum src);

/* ::corto::lang::equalityKind */
CORTO_LANG_EXPORT cx_equalityKind* cx_equalityKindCreate(cx_equalityKind value);
CORTO_LANG_EXPORT cx_equalityKind* cx_equalityKindCreateChild(cx_object _parent, cx_string _name, cx_equalityKind value);

CORTO_LANG_EXPORT cx_equalityKind* cx_equalityKindDeclare(void);
CORTO_LANG_EXPORT cx_equalityKind* cx_equalityKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_equalityKindDefine(cx_equalityKind* _this, cx_equalityKind value);
CORTO_LANG_EXPORT void cx_equalityKindUpdate(cx_equalityKind* _this, cx_equalityKind value);
CORTO_LANG_EXPORT void cx_equalityKindSet(cx_equalityKind* _this, cx_equalityKind value);
CORTO_LANG_EXPORT cx_string cx_equalityKindStr(cx_equalityKind value);
CORTO_LANG_EXPORT cx_equalityKind* cx_equalityKindFromStr(cx_equalityKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_equalityKindCopy(cx_equalityKind* *dst, cx_equalityKind* src);
CORTO_LANG_EXPORT cx_int16 cx_equalityKindCompare(cx_equalityKind* dst, cx_equalityKind* src);

CORTO_LANG_EXPORT cx_int16 cx_equalityKindInit(cx_equalityKind* value);
CORTO_LANG_EXPORT cx_int16 cx_equalityKindDeinit(cx_equalityKind* value);

/* ::corto::lang::event */
CORTO_LANG_EXPORT cx_event cx_eventCreate(cx_uint16 kind);
CORTO_LANG_EXPORT cx_event cx_eventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind);

CORTO_LANG_EXPORT cx_event cx_eventDeclare(void);
CORTO_LANG_EXPORT cx_event cx_eventDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_eventDefine(cx_event _this, cx_uint16 kind);
CORTO_LANG_EXPORT void cx_eventUpdate(cx_event _this, cx_uint16 kind);
CORTO_LANG_EXPORT void cx_eventSet(cx_event _this, cx_uint16 kind);
CORTO_LANG_EXPORT cx_string cx_eventStr(cx_event value);
CORTO_LANG_EXPORT cx_event cx_eventFromStr(cx_event value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_eventCopy(cx_event *dst, cx_event src);
CORTO_LANG_EXPORT cx_int16 cx_eventCompare(cx_event dst, cx_event src);

/* ::corto::lang::eventMask */
CORTO_LANG_EXPORT cx_eventMask* cx_eventMaskCreate(cx_eventMask value);
CORTO_LANG_EXPORT cx_eventMask* cx_eventMaskCreateChild(cx_object _parent, cx_string _name, cx_eventMask value);

CORTO_LANG_EXPORT cx_eventMask* cx_eventMaskDeclare(void);
CORTO_LANG_EXPORT cx_eventMask* cx_eventMaskDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_eventMaskDefine(cx_eventMask* _this, cx_eventMask value);
CORTO_LANG_EXPORT void cx_eventMaskUpdate(cx_eventMask* _this, cx_eventMask value);
CORTO_LANG_EXPORT void cx_eventMaskSet(cx_eventMask* _this, cx_eventMask value);
CORTO_LANG_EXPORT cx_string cx_eventMaskStr(cx_eventMask value);
CORTO_LANG_EXPORT cx_eventMask* cx_eventMaskFromStr(cx_eventMask* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_eventMaskCopy(cx_eventMask* *dst, cx_eventMask* src);
CORTO_LANG_EXPORT cx_int16 cx_eventMaskCompare(cx_eventMask* dst, cx_eventMask* src);

CORTO_LANG_EXPORT cx_int16 cx_eventMaskInit(cx_eventMask* value);
CORTO_LANG_EXPORT cx_int16 cx_eventMaskDeinit(cx_eventMask* value);

/* ::corto::lang::float */
CORTO_LANG_EXPORT cx_float cx_floatCreate(cx_width width, cx_float64 min, cx_float64 max);
CORTO_LANG_EXPORT cx_float cx_floatCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_float64 min, cx_float64 max);

CORTO_LANG_EXPORT cx_float cx_floatDeclare(void);
CORTO_LANG_EXPORT cx_float cx_floatDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_floatDefine(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
CORTO_LANG_EXPORT void cx_floatUpdate(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
CORTO_LANG_EXPORT void cx_floatSet(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
CORTO_LANG_EXPORT cx_string cx_floatStr(cx_float value);
CORTO_LANG_EXPORT cx_float cx_floatFromStr(cx_float value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_floatCopy(cx_float *dst, cx_float src);
CORTO_LANG_EXPORT cx_int16 cx_floatCompare(cx_float dst, cx_float src);

/* ::corto::lang::float32 */
CORTO_LANG_EXPORT cx_float32* cx_float32Create(cx_float32 value);
CORTO_LANG_EXPORT cx_float32* cx_float32CreateChild(cx_object _parent, cx_string _name, cx_float32 value);

CORTO_LANG_EXPORT cx_float32* cx_float32Declare(void);
CORTO_LANG_EXPORT cx_float32* cx_float32DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_float32Define(cx_float32* _this, cx_float32 value);
CORTO_LANG_EXPORT void cx_float32Update(cx_float32* _this, cx_float32 value);
CORTO_LANG_EXPORT void cx_float32Set(cx_float32* _this, cx_float32 value);
CORTO_LANG_EXPORT cx_string cx_float32Str(cx_float32 value);
CORTO_LANG_EXPORT cx_float32* cx_float32FromStr(cx_float32* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_float32Copy(cx_float32* *dst, cx_float32* src);
CORTO_LANG_EXPORT cx_int16 cx_float32Compare(cx_float32* dst, cx_float32* src);

CORTO_LANG_EXPORT cx_int16 cx_float32Init(cx_float32* value);
CORTO_LANG_EXPORT cx_int16 cx_float32Deinit(cx_float32* value);

/* ::corto::lang::float64 */
CORTO_LANG_EXPORT cx_float64* cx_float64Create(cx_float64 value);
CORTO_LANG_EXPORT cx_float64* cx_float64CreateChild(cx_object _parent, cx_string _name, cx_float64 value);

CORTO_LANG_EXPORT cx_float64* cx_float64Declare(void);
CORTO_LANG_EXPORT cx_float64* cx_float64DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_float64Define(cx_float64* _this, cx_float64 value);
CORTO_LANG_EXPORT void cx_float64Update(cx_float64* _this, cx_float64 value);
CORTO_LANG_EXPORT void cx_float64Set(cx_float64* _this, cx_float64 value);
CORTO_LANG_EXPORT cx_string cx_float64Str(cx_float64 value);
CORTO_LANG_EXPORT cx_float64* cx_float64FromStr(cx_float64* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_float64Copy(cx_float64* *dst, cx_float64* src);
CORTO_LANG_EXPORT cx_int16 cx_float64Compare(cx_float64* dst, cx_float64* src);

CORTO_LANG_EXPORT cx_int16 cx_float64Init(cx_float64* value);
CORTO_LANG_EXPORT cx_int16 cx_float64Deinit(cx_float64* value);

/* ::corto::lang::function */
CORTO_LANG_EXPORT cx_function cx_functionCreate(cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT cx_function cx_functionCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args));

CORTO_LANG_EXPORT cx_function cx_functionDeclare(void);
CORTO_LANG_EXPORT cx_function cx_functionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_functionDefine(cx_function _this, cx_type returnType, cx_bool returnsReference, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT void cx_functionUpdate(cx_function _this, cx_type returnType, cx_bool returnsReference);
CORTO_LANG_EXPORT void cx_functionSet(cx_function _this, cx_type returnType, cx_bool returnsReference);
CORTO_LANG_EXPORT cx_string cx_functionStr(cx_function value);
CORTO_LANG_EXPORT cx_function cx_functionFromStr(cx_function value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_functionCopy(cx_function *dst, cx_function src);
CORTO_LANG_EXPORT cx_int16 cx_functionCompare(cx_function dst, cx_function src);

/* ::corto::lang::initAction */
CORTO_LANG_EXPORT cx_initAction* cx_initActionCreate(cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_initAction* cx_initActionCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

CORTO_LANG_EXPORT cx_initAction* cx_initActionDeclare(void);
CORTO_LANG_EXPORT cx_initAction* cx_initActionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_initActionDefine(cx_initAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_initActionUpdate(cx_initAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_initActionSet(cx_initAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_string cx_initActionStr(cx_initAction* value);
CORTO_LANG_EXPORT cx_initAction* cx_initActionFromStr(cx_initAction* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_initActionCopy(cx_initAction* *dst, cx_initAction* src);
CORTO_LANG_EXPORT cx_int16 cx_initActionCompare(cx_initAction* dst, cx_initAction* src);

CORTO_LANG_EXPORT cx_int16 cx_initActionInit(cx_initAction* value);
CORTO_LANG_EXPORT cx_int16 cx_initActionDeinit(cx_initAction* value);

cx_int16 cx_initActionCall(cx_initAction *_delegate, cx_int16* _result);
/* ::corto::lang::int */
CORTO_LANG_EXPORT cx_int cx_intCreate(cx_width width, cx_int64 min, cx_int64 max);
CORTO_LANG_EXPORT cx_int cx_intCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max);

CORTO_LANG_EXPORT cx_int cx_intDeclare(void);
CORTO_LANG_EXPORT cx_int cx_intDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_intDefine(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
CORTO_LANG_EXPORT void cx_intUpdate(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
CORTO_LANG_EXPORT void cx_intSet(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
CORTO_LANG_EXPORT cx_string cx_intStr(cx_int value);
CORTO_LANG_EXPORT cx_int cx_intFromStr(cx_int value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_intCopy(cx_int *dst, cx_int src);
CORTO_LANG_EXPORT cx_int16 cx_intCompare(cx_int dst, cx_int src);

/* ::corto::lang::int16 */
CORTO_LANG_EXPORT cx_int16* cx_int16Create(cx_int16 value);
CORTO_LANG_EXPORT cx_int16* cx_int16CreateChild(cx_object _parent, cx_string _name, cx_int16 value);

CORTO_LANG_EXPORT cx_int16* cx_int16Declare(void);
CORTO_LANG_EXPORT cx_int16* cx_int16DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_int16Define(cx_int16* _this, cx_int16 value);
CORTO_LANG_EXPORT void cx_int16Update(cx_int16* _this, cx_int16 value);
CORTO_LANG_EXPORT void cx_int16Set(cx_int16* _this, cx_int16 value);
CORTO_LANG_EXPORT cx_string cx_int16Str(cx_int16 value);
CORTO_LANG_EXPORT cx_int16* cx_int16FromStr(cx_int16* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_int16Copy(cx_int16* *dst, cx_int16* src);
CORTO_LANG_EXPORT cx_int16 cx_int16Compare(cx_int16* dst, cx_int16* src);

CORTO_LANG_EXPORT cx_int16 cx_int16Init(cx_int16* value);
CORTO_LANG_EXPORT cx_int16 cx_int16Deinit(cx_int16* value);

/* ::corto::lang::int32 */
CORTO_LANG_EXPORT cx_int32* cx_int32Create(cx_int32 value);
CORTO_LANG_EXPORT cx_int32* cx_int32CreateChild(cx_object _parent, cx_string _name, cx_int32 value);

CORTO_LANG_EXPORT cx_int32* cx_int32Declare(void);
CORTO_LANG_EXPORT cx_int32* cx_int32DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_int32Define(cx_int32* _this, cx_int32 value);
CORTO_LANG_EXPORT void cx_int32Update(cx_int32* _this, cx_int32 value);
CORTO_LANG_EXPORT void cx_int32Set(cx_int32* _this, cx_int32 value);
CORTO_LANG_EXPORT cx_string cx_int32Str(cx_int32 value);
CORTO_LANG_EXPORT cx_int32* cx_int32FromStr(cx_int32* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_int32Copy(cx_int32* *dst, cx_int32* src);
CORTO_LANG_EXPORT cx_int16 cx_int32Compare(cx_int32* dst, cx_int32* src);

CORTO_LANG_EXPORT cx_int16 cx_int32Init(cx_int32* value);
CORTO_LANG_EXPORT cx_int16 cx_int32Deinit(cx_int32* value);

/* ::corto::lang::int64 */
CORTO_LANG_EXPORT cx_int64* cx_int64Create(cx_int64 value);
CORTO_LANG_EXPORT cx_int64* cx_int64CreateChild(cx_object _parent, cx_string _name, cx_int64 value);

CORTO_LANG_EXPORT cx_int64* cx_int64Declare(void);
CORTO_LANG_EXPORT cx_int64* cx_int64DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_int64Define(cx_int64* _this, cx_int64 value);
CORTO_LANG_EXPORT void cx_int64Update(cx_int64* _this, cx_int64 value);
CORTO_LANG_EXPORT void cx_int64Set(cx_int64* _this, cx_int64 value);
CORTO_LANG_EXPORT cx_string cx_int64Str(cx_int64 value);
CORTO_LANG_EXPORT cx_int64* cx_int64FromStr(cx_int64* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_int64Copy(cx_int64* *dst, cx_int64* src);
CORTO_LANG_EXPORT cx_int16 cx_int64Compare(cx_int64* dst, cx_int64* src);

CORTO_LANG_EXPORT cx_int16 cx_int64Init(cx_int64* value);
CORTO_LANG_EXPORT cx_int16 cx_int64Deinit(cx_int64* value);

/* ::corto::lang::int8 */
CORTO_LANG_EXPORT cx_int8* cx_int8Create(cx_int8 value);
CORTO_LANG_EXPORT cx_int8* cx_int8CreateChild(cx_object _parent, cx_string _name, cx_int8 value);

CORTO_LANG_EXPORT cx_int8* cx_int8Declare(void);
CORTO_LANG_EXPORT cx_int8* cx_int8DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_int8Define(cx_int8* _this, cx_int8 value);
CORTO_LANG_EXPORT void cx_int8Update(cx_int8* _this, cx_int8 value);
CORTO_LANG_EXPORT void cx_int8Set(cx_int8* _this, cx_int8 value);
CORTO_LANG_EXPORT cx_string cx_int8Str(cx_int8 value);
CORTO_LANG_EXPORT cx_int8* cx_int8FromStr(cx_int8* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_int8Copy(cx_int8* *dst, cx_int8* src);
CORTO_LANG_EXPORT cx_int16 cx_int8Compare(cx_int8* dst, cx_int8* src);

CORTO_LANG_EXPORT cx_int16 cx_int8Init(cx_int8* value);
CORTO_LANG_EXPORT cx_int16 cx_int8Deinit(cx_int8* value);

/* ::corto::lang::interface */
CORTO_LANG_EXPORT cx_interface cx_interfaceCreate(cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_interface cx_interfaceCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);

CORTO_LANG_EXPORT cx_interface cx_interfaceDeclare(void);
CORTO_LANG_EXPORT cx_interface cx_interfaceDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_interfaceDefine(cx_interface _this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_interfaceUpdate(cx_interface _this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_interfaceSet(cx_interface _this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_string cx_interfaceStr(cx_interface value);
CORTO_LANG_EXPORT cx_interface cx_interfaceFromStr(cx_interface value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_interfaceCopy(cx_interface *dst, cx_interface src);
CORTO_LANG_EXPORT cx_int16 cx_interfaceCompare(cx_interface dst, cx_interface src);

/* ::corto::lang::interfaceseq */
CORTO_LANG_EXPORT cx_interfaceseq* cx_interfaceseqCreate(void);
CORTO_LANG_EXPORT cx_interfaceseq* cx_interfaceseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_interfaceseq* cx_interfaceseqDeclare(void);
CORTO_LANG_EXPORT cx_interfaceseq* cx_interfaceseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_interfaceseqDefine(cx_interfaceseq* _this, cx_interfaceseq value);
CORTO_LANG_EXPORT void cx_interfaceseqUpdate(cx_interfaceseq* _this, cx_interfaceseq value);
CORTO_LANG_EXPORT void cx_interfaceseqSet(cx_interfaceseq* _this, cx_interfaceseq value);
CORTO_LANG_EXPORT cx_string cx_interfaceseqStr(cx_interfaceseq value);
CORTO_LANG_EXPORT cx_interfaceseq* cx_interfaceseqFromStr(cx_interfaceseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_interfaceseqCopy(cx_interfaceseq* *dst, cx_interfaceseq* src);
CORTO_LANG_EXPORT cx_int16 cx_interfaceseqCompare(cx_interfaceseq* dst, cx_interfaceseq* src);

CORTO_LANG_EXPORT cx_int16 cx_interfaceseqInit(cx_interfaceseq* value);
CORTO_LANG_EXPORT cx_int16 cx_interfaceseqDeinit(cx_interfaceseq* value);

/* ::corto::lang::interfaceVector */
CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorCreate(cx_interface interface, cx_vtable vector);
CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorCreateChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector);

CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorDeclare(void);
CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorDefine(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
CORTO_LANG_EXPORT void cx_interfaceVectorUpdate(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
CORTO_LANG_EXPORT void cx_interfaceVectorSet(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
CORTO_LANG_EXPORT cx_string cx_interfaceVectorStr(cx_interfaceVector* value);
CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorFromStr(cx_interfaceVector* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorCopy(cx_interfaceVector* *dst, cx_interfaceVector* src);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorCompare(cx_interfaceVector* dst, cx_interfaceVector* src);

CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorInit(cx_interfaceVector* value);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorDeinit(cx_interfaceVector* value);

/* ::corto::lang::interfaceVectorseq */
CORTO_LANG_EXPORT cx_interfaceVectorseq* cx_interfaceVectorseqCreate(void);
CORTO_LANG_EXPORT cx_interfaceVectorseq* cx_interfaceVectorseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_interfaceVectorseq* cx_interfaceVectorseqDeclare(void);
CORTO_LANG_EXPORT cx_interfaceVectorseq* cx_interfaceVectorseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorseqDefine(cx_interfaceVectorseq* _this, cx_interfaceVectorseq value);
CORTO_LANG_EXPORT void cx_interfaceVectorseqUpdate(cx_interfaceVectorseq* _this, cx_interfaceVectorseq value);
CORTO_LANG_EXPORT void cx_interfaceVectorseqSet(cx_interfaceVectorseq* _this, cx_interfaceVectorseq value);
CORTO_LANG_EXPORT cx_string cx_interfaceVectorseqStr(cx_interfaceVectorseq value);
CORTO_LANG_EXPORT cx_interfaceVectorseq* cx_interfaceVectorseqFromStr(cx_interfaceVectorseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorseqCopy(cx_interfaceVectorseq* *dst, cx_interfaceVectorseq* src);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorseqCompare(cx_interfaceVectorseq* dst, cx_interfaceVectorseq* src);

CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorseqInit(cx_interfaceVectorseq* value);
CORTO_LANG_EXPORT cx_int16 cx_interfaceVectorseqDeinit(cx_interfaceVectorseq* value);

/* ::corto::lang::invokeAction */
CORTO_LANG_EXPORT cx_invokeAction* cx_invokeActionCreate(cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_invokeAction* cx_invokeActionCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

CORTO_LANG_EXPORT cx_invokeAction* cx_invokeActionDeclare(void);
CORTO_LANG_EXPORT cx_invokeAction* cx_invokeActionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_invokeActionDefine(cx_invokeAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_invokeActionUpdate(cx_invokeAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_invokeActionSet(cx_invokeAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_string cx_invokeActionStr(cx_invokeAction* value);
CORTO_LANG_EXPORT cx_invokeAction* cx_invokeActionFromStr(cx_invokeAction* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_invokeActionCopy(cx_invokeAction* *dst, cx_invokeAction* src);
CORTO_LANG_EXPORT cx_int16 cx_invokeActionCompare(cx_invokeAction* dst, cx_invokeAction* src);

CORTO_LANG_EXPORT cx_int16 cx_invokeActionInit(cx_invokeAction* value);
CORTO_LANG_EXPORT cx_int16 cx_invokeActionDeinit(cx_invokeAction* value);

cx_int16 cx_invokeActionCall(cx_invokeAction *_delegate, cx_object instance, cx_function function, cx_octetseq args);
/* ::corto::lang::invokeEvent */
CORTO_LANG_EXPORT cx_invokeEvent cx_invokeEventCreate(cx_replicator replicator, cx_object instance, cx_function function, cx_octetseq args);
CORTO_LANG_EXPORT cx_invokeEvent cx_invokeEventCreateChild(cx_object _parent, cx_string _name, cx_replicator replicator, cx_object instance, cx_function function, cx_octetseq args);

CORTO_LANG_EXPORT cx_invokeEvent cx_invokeEventDeclare(void);
CORTO_LANG_EXPORT cx_invokeEvent cx_invokeEventDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_invokeEventDefine(cx_invokeEvent _this, cx_replicator replicator, cx_object instance, cx_function function, cx_octetseq args);
CORTO_LANG_EXPORT void cx_invokeEventUpdate(cx_invokeEvent _this, cx_replicator replicator, cx_object instance, cx_function function, cx_octetseq args);
CORTO_LANG_EXPORT void cx_invokeEventSet(cx_invokeEvent _this, cx_replicator replicator, cx_object instance, cx_function function, cx_octetseq args);
CORTO_LANG_EXPORT cx_string cx_invokeEventStr(cx_invokeEvent value);
CORTO_LANG_EXPORT cx_invokeEvent cx_invokeEventFromStr(cx_invokeEvent value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_invokeEventCopy(cx_invokeEvent *dst, cx_invokeEvent src);
CORTO_LANG_EXPORT cx_int16 cx_invokeEventCompare(cx_invokeEvent dst, cx_invokeEvent src);

/* ::corto::lang::iterator */
CORTO_LANG_EXPORT cx_iterator cx_iteratorCreate(cx_type elementType);
CORTO_LANG_EXPORT cx_iterator cx_iteratorCreateChild(cx_object _parent, cx_string _name, cx_type elementType);

CORTO_LANG_EXPORT cx_iterator cx_iteratorDeclare(void);
CORTO_LANG_EXPORT cx_iterator cx_iteratorDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_iteratorDefine(cx_iterator _this, cx_type elementType);
CORTO_LANG_EXPORT void cx_iteratorUpdate(cx_iterator _this, cx_type elementType);
CORTO_LANG_EXPORT void cx_iteratorSet(cx_iterator _this, cx_type elementType);
CORTO_LANG_EXPORT cx_string cx_iteratorStr(cx_iterator value);
CORTO_LANG_EXPORT cx_iterator cx_iteratorFromStr(cx_iterator value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_iteratorCopy(cx_iterator *dst, cx_iterator src);
CORTO_LANG_EXPORT cx_int16 cx_iteratorCompare(cx_iterator dst, cx_iterator src);

/* ::corto::lang::list */
CORTO_LANG_EXPORT cx_list cx_listCreate(cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_list cx_listCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

CORTO_LANG_EXPORT cx_list cx_listDeclare(void);
CORTO_LANG_EXPORT cx_list cx_listDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_listDefine(cx_list _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_listUpdate(cx_list _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_listSet(cx_list _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_string cx_listStr(cx_list value);
CORTO_LANG_EXPORT cx_list cx_listFromStr(cx_list value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_listCopy(cx_list *dst, cx_list src);
CORTO_LANG_EXPORT cx_int16 cx_listCompare(cx_list dst, cx_list src);

/* ::corto::lang::map */
CORTO_LANG_EXPORT cx_map cx_mapCreate(cx_type elementType, cx_type keyType, cx_uint32 max);
CORTO_LANG_EXPORT cx_map cx_mapCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max);

CORTO_LANG_EXPORT cx_map cx_mapDeclare(void);
CORTO_LANG_EXPORT cx_map cx_mapDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_mapDefine(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_mapUpdate(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_mapSet(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
CORTO_LANG_EXPORT cx_string cx_mapStr(cx_map value);
CORTO_LANG_EXPORT cx_map cx_mapFromStr(cx_map value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_mapCopy(cx_map *dst, cx_map src);
CORTO_LANG_EXPORT cx_int16 cx_mapCompare(cx_map dst, cx_map src);

/* ::corto::lang::member */
CORTO_LANG_EXPORT cx_member cx_memberCreate(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
CORTO_LANG_EXPORT cx_member cx_memberCreateChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);

CORTO_LANG_EXPORT cx_member cx_memberDeclare(void);
CORTO_LANG_EXPORT cx_member cx_memberDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_memberDefine(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
CORTO_LANG_EXPORT void cx_memberUpdate(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
CORTO_LANG_EXPORT void cx_memberSet(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
CORTO_LANG_EXPORT cx_string cx_memberStr(cx_member value);
CORTO_LANG_EXPORT cx_member cx_memberFromStr(cx_member value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_memberCopy(cx_member *dst, cx_member src);
CORTO_LANG_EXPORT cx_int16 cx_memberCompare(cx_member dst, cx_member src);

/* ::corto::lang::memberseq */
CORTO_LANG_EXPORT cx_memberseq* cx_memberseqCreate(void);
CORTO_LANG_EXPORT cx_memberseq* cx_memberseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_memberseq* cx_memberseqDeclare(void);
CORTO_LANG_EXPORT cx_memberseq* cx_memberseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_memberseqDefine(cx_memberseq* _this, cx_memberseq value);
CORTO_LANG_EXPORT void cx_memberseqUpdate(cx_memberseq* _this, cx_memberseq value);
CORTO_LANG_EXPORT void cx_memberseqSet(cx_memberseq* _this, cx_memberseq value);
CORTO_LANG_EXPORT cx_string cx_memberseqStr(cx_memberseq value);
CORTO_LANG_EXPORT cx_memberseq* cx_memberseqFromStr(cx_memberseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_memberseqCopy(cx_memberseq* *dst, cx_memberseq* src);
CORTO_LANG_EXPORT cx_int16 cx_memberseqCompare(cx_memberseq* dst, cx_memberseq* src);

CORTO_LANG_EXPORT cx_int16 cx_memberseqInit(cx_memberseq* value);
CORTO_LANG_EXPORT cx_int16 cx_memberseqDeinit(cx_memberseq* value);

/* ::corto::lang::metaprocedure */
CORTO_LANG_EXPORT cx_metaprocedure cx_metaprocedureCreate(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT cx_metaprocedure cx_metaprocedureCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args));

CORTO_LANG_EXPORT cx_metaprocedure cx_metaprocedureDeclare(void);
CORTO_LANG_EXPORT cx_metaprocedure cx_metaprocedureDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_metaprocedureDefine(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT void cx_metaprocedureUpdate(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
CORTO_LANG_EXPORT void cx_metaprocedureSet(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
CORTO_LANG_EXPORT cx_string cx_metaprocedureStr(cx_metaprocedure value);
CORTO_LANG_EXPORT cx_metaprocedure cx_metaprocedureFromStr(cx_metaprocedure value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_metaprocedureCopy(cx_metaprocedure *dst, cx_metaprocedure src);
CORTO_LANG_EXPORT cx_int16 cx_metaprocedureCompare(cx_metaprocedure dst, cx_metaprocedure src);

/* ::corto::lang::method */
CORTO_LANG_EXPORT cx_method cx_methodCreate(cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT cx_method cx_methodCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));

CORTO_LANG_EXPORT cx_method cx_methodDeclare(void);
CORTO_LANG_EXPORT cx_method cx_methodDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_methodDefine(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT void cx_methodUpdate(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual);
CORTO_LANG_EXPORT void cx_methodSet(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual);
CORTO_LANG_EXPORT cx_string cx_methodStr(cx_method value);
CORTO_LANG_EXPORT cx_method cx_methodFromStr(cx_method value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_methodCopy(cx_method *dst, cx_method src);
CORTO_LANG_EXPORT cx_int16 cx_methodCompare(cx_method dst, cx_method src);

/* ::corto::lang::modifier */
CORTO_LANG_EXPORT cx_modifier* cx_modifierCreate(cx_modifier value);
CORTO_LANG_EXPORT cx_modifier* cx_modifierCreateChild(cx_object _parent, cx_string _name, cx_modifier value);

CORTO_LANG_EXPORT cx_modifier* cx_modifierDeclare(void);
CORTO_LANG_EXPORT cx_modifier* cx_modifierDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_modifierDefine(cx_modifier* _this, cx_modifier value);
CORTO_LANG_EXPORT void cx_modifierUpdate(cx_modifier* _this, cx_modifier value);
CORTO_LANG_EXPORT void cx_modifierSet(cx_modifier* _this, cx_modifier value);
CORTO_LANG_EXPORT cx_string cx_modifierStr(cx_modifier value);
CORTO_LANG_EXPORT cx_modifier* cx_modifierFromStr(cx_modifier* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_modifierCopy(cx_modifier* *dst, cx_modifier* src);
CORTO_LANG_EXPORT cx_int16 cx_modifierCompare(cx_modifier* dst, cx_modifier* src);

CORTO_LANG_EXPORT cx_int16 cx_modifierInit(cx_modifier* value);
CORTO_LANG_EXPORT cx_int16 cx_modifierDeinit(cx_modifier* value);

/* ::corto::lang::notifyAction */
CORTO_LANG_EXPORT cx_notifyAction* cx_notifyActionCreate(cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_notifyAction* cx_notifyActionCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

CORTO_LANG_EXPORT cx_notifyAction* cx_notifyActionDeclare(void);
CORTO_LANG_EXPORT cx_notifyAction* cx_notifyActionDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_notifyActionDefine(cx_notifyAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_notifyActionUpdate(cx_notifyAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT void cx_notifyActionSet(cx_notifyAction* _this, cx_object instance, cx_function procedure);
CORTO_LANG_EXPORT cx_string cx_notifyActionStr(cx_notifyAction* value);
CORTO_LANG_EXPORT cx_notifyAction* cx_notifyActionFromStr(cx_notifyAction* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_notifyActionCopy(cx_notifyAction* *dst, cx_notifyAction* src);
CORTO_LANG_EXPORT cx_int16 cx_notifyActionCompare(cx_notifyAction* dst, cx_notifyAction* src);

CORTO_LANG_EXPORT cx_int16 cx_notifyActionInit(cx_notifyAction* value);
CORTO_LANG_EXPORT cx_int16 cx_notifyActionDeinit(cx_notifyAction* value);

cx_int16 cx_notifyActionCall(cx_notifyAction *_delegate, cx_object observable);
/* ::corto::lang::object */
CORTO_LANG_EXPORT cx_object cx_objectCreate(void);
CORTO_LANG_EXPORT cx_object cx_objectCreateChild(cx_object _parent, cx_string _name);

/* ::corto::lang::objectseq */
CORTO_LANG_EXPORT cx_objectseq* cx_objectseqCreate(void);
CORTO_LANG_EXPORT cx_objectseq* cx_objectseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_objectseq* cx_objectseqDeclare(void);
CORTO_LANG_EXPORT cx_objectseq* cx_objectseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_objectseqDefine(cx_objectseq* _this, cx_objectseq value);
CORTO_LANG_EXPORT void cx_objectseqUpdate(cx_objectseq* _this, cx_objectseq value);
CORTO_LANG_EXPORT void cx_objectseqSet(cx_objectseq* _this, cx_objectseq value);
CORTO_LANG_EXPORT cx_string cx_objectseqStr(cx_objectseq value);
CORTO_LANG_EXPORT cx_objectseq* cx_objectseqFromStr(cx_objectseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_objectseqCopy(cx_objectseq* *dst, cx_objectseq* src);
CORTO_LANG_EXPORT cx_int16 cx_objectseqCompare(cx_objectseq* dst, cx_objectseq* src);

CORTO_LANG_EXPORT cx_int16 cx_objectseqInit(cx_objectseq* value);
CORTO_LANG_EXPORT cx_int16 cx_objectseqDeinit(cx_objectseq* value);

/* ::corto::lang::observableEvent */
CORTO_LANG_EXPORT cx_observableEvent cx_observableEventCreate(cx_observer observer, cx_object me, cx_object source, cx_object observable);
CORTO_LANG_EXPORT cx_observableEvent cx_observableEventCreateChild(cx_object _parent, cx_string _name, cx_observer observer, cx_object me, cx_object source, cx_object observable);

CORTO_LANG_EXPORT cx_observableEvent cx_observableEventDeclare(void);
CORTO_LANG_EXPORT cx_observableEvent cx_observableEventDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_observableEventDefine(cx_observableEvent _this, cx_observer observer, cx_object me, cx_object source, cx_object observable);
CORTO_LANG_EXPORT void cx_observableEventUpdate(cx_observableEvent _this, cx_observer observer, cx_object me, cx_object source, cx_object observable);
CORTO_LANG_EXPORT void cx_observableEventSet(cx_observableEvent _this, cx_observer observer, cx_object me, cx_object source, cx_object observable);
CORTO_LANG_EXPORT cx_string cx_observableEventStr(cx_observableEvent value);
CORTO_LANG_EXPORT cx_observableEvent cx_observableEventFromStr(cx_observableEvent value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_observableEventCopy(cx_observableEvent *dst, cx_observableEvent src);
CORTO_LANG_EXPORT cx_int16 cx_observableEventCompare(cx_observableEvent dst, cx_observableEvent src);

/* ::corto::lang::observer */
CORTO_LANG_EXPORT cx_observer cx_observerCreate(cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT cx_observer cx_observerCreateChild(cx_object _parent, cx_string _name, cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args));

CORTO_LANG_EXPORT cx_observer cx_observerDeclare(void);
CORTO_LANG_EXPORT cx_observer cx_observerDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_observerDefine(cx_observer _this, cx_eventMask mask, cx_object observable, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT void cx_observerUpdate(cx_observer _this, cx_eventMask mask, cx_object observable);
CORTO_LANG_EXPORT void cx_observerSet(cx_observer _this, cx_eventMask mask, cx_object observable);
CORTO_LANG_EXPORT cx_string cx_observerStr(cx_observer value);
CORTO_LANG_EXPORT cx_observer cx_observerFromStr(cx_observer value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_observerCopy(cx_observer *dst, cx_observer src);
CORTO_LANG_EXPORT cx_int16 cx_observerCompare(cx_observer dst, cx_observer src);

/* ::corto::lang::observerseq */
CORTO_LANG_EXPORT cx_observerseq* cx_observerseqCreate(void);
CORTO_LANG_EXPORT cx_observerseq* cx_observerseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_observerseq* cx_observerseqDeclare(void);
CORTO_LANG_EXPORT cx_observerseq* cx_observerseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_observerseqDefine(cx_observerseq* _this, cx_observerseq value);
CORTO_LANG_EXPORT void cx_observerseqUpdate(cx_observerseq* _this, cx_observerseq value);
CORTO_LANG_EXPORT void cx_observerseqSet(cx_observerseq* _this, cx_observerseq value);
CORTO_LANG_EXPORT cx_string cx_observerseqStr(cx_observerseq value);
CORTO_LANG_EXPORT cx_observerseq* cx_observerseqFromStr(cx_observerseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_observerseqCopy(cx_observerseq* *dst, cx_observerseq* src);
CORTO_LANG_EXPORT cx_int16 cx_observerseqCompare(cx_observerseq* dst, cx_observerseq* src);

CORTO_LANG_EXPORT cx_int16 cx_observerseqInit(cx_observerseq* value);
CORTO_LANG_EXPORT cx_int16 cx_observerseqDeinit(cx_observerseq* value);

/* ::corto::lang::octet */
CORTO_LANG_EXPORT cx_octet* cx_octetCreate(cx_octet value);
CORTO_LANG_EXPORT cx_octet* cx_octetCreateChild(cx_object _parent, cx_string _name, cx_octet value);

CORTO_LANG_EXPORT cx_octet* cx_octetDeclare(void);
CORTO_LANG_EXPORT cx_octet* cx_octetDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_octetDefine(cx_octet* _this, cx_octet value);
CORTO_LANG_EXPORT void cx_octetUpdate(cx_octet* _this, cx_octet value);
CORTO_LANG_EXPORT void cx_octetSet(cx_octet* _this, cx_octet value);
CORTO_LANG_EXPORT cx_string cx_octetStr(cx_octet value);
CORTO_LANG_EXPORT cx_octet* cx_octetFromStr(cx_octet* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_octetCopy(cx_octet* *dst, cx_octet* src);
CORTO_LANG_EXPORT cx_int16 cx_octetCompare(cx_octet* dst, cx_octet* src);

CORTO_LANG_EXPORT cx_int16 cx_octetInit(cx_octet* value);
CORTO_LANG_EXPORT cx_int16 cx_octetDeinit(cx_octet* value);

/* ::corto::lang::octetseq */
CORTO_LANG_EXPORT cx_octetseq* cx_octetseqCreate(void);
CORTO_LANG_EXPORT cx_octetseq* cx_octetseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_octetseq* cx_octetseqDeclare(void);
CORTO_LANG_EXPORT cx_octetseq* cx_octetseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_octetseqDefine(cx_octetseq* _this, cx_octetseq value);
CORTO_LANG_EXPORT void cx_octetseqUpdate(cx_octetseq* _this, cx_octetseq value);
CORTO_LANG_EXPORT void cx_octetseqSet(cx_octetseq* _this, cx_octetseq value);
CORTO_LANG_EXPORT cx_string cx_octetseqStr(cx_octetseq value);
CORTO_LANG_EXPORT cx_octetseq* cx_octetseqFromStr(cx_octetseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_octetseqCopy(cx_octetseq* *dst, cx_octetseq* src);
CORTO_LANG_EXPORT cx_int16 cx_octetseqCompare(cx_octetseq* dst, cx_octetseq* src);

CORTO_LANG_EXPORT cx_int16 cx_octetseqInit(cx_octetseq* value);
CORTO_LANG_EXPORT cx_int16 cx_octetseqDeinit(cx_octetseq* value);

/* ::corto::lang::operatorKind */
CORTO_LANG_EXPORT cx_operatorKind* cx_operatorKindCreate(cx_operatorKind value);
CORTO_LANG_EXPORT cx_operatorKind* cx_operatorKindCreateChild(cx_object _parent, cx_string _name, cx_operatorKind value);

CORTO_LANG_EXPORT cx_operatorKind* cx_operatorKindDeclare(void);
CORTO_LANG_EXPORT cx_operatorKind* cx_operatorKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_operatorKindDefine(cx_operatorKind* _this, cx_operatorKind value);
CORTO_LANG_EXPORT void cx_operatorKindUpdate(cx_operatorKind* _this, cx_operatorKind value);
CORTO_LANG_EXPORT void cx_operatorKindSet(cx_operatorKind* _this, cx_operatorKind value);
CORTO_LANG_EXPORT cx_string cx_operatorKindStr(cx_operatorKind value);
CORTO_LANG_EXPORT cx_operatorKind* cx_operatorKindFromStr(cx_operatorKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_operatorKindCopy(cx_operatorKind* *dst, cx_operatorKind* src);
CORTO_LANG_EXPORT cx_int16 cx_operatorKindCompare(cx_operatorKind* dst, cx_operatorKind* src);

CORTO_LANG_EXPORT cx_int16 cx_operatorKindInit(cx_operatorKind* value);
CORTO_LANG_EXPORT cx_int16 cx_operatorKindDeinit(cx_operatorKind* value);

/* ::corto::lang::package */
CORTO_LANG_EXPORT cx_package cx_packageCreate(cx_string url);
CORTO_LANG_EXPORT cx_package cx_packageCreateChild(cx_object _parent, cx_string _name, cx_string url);

CORTO_LANG_EXPORT cx_package cx_packageDeclare(void);
CORTO_LANG_EXPORT cx_package cx_packageDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_packageDefine(cx_package _this, cx_string url);
CORTO_LANG_EXPORT void cx_packageUpdate(cx_package _this, cx_string url);
CORTO_LANG_EXPORT void cx_packageSet(cx_package _this, cx_string url);
CORTO_LANG_EXPORT cx_string cx_packageStr(cx_package value);
CORTO_LANG_EXPORT cx_package cx_packageFromStr(cx_package value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_packageCopy(cx_package *dst, cx_package src);
CORTO_LANG_EXPORT cx_int16 cx_packageCompare(cx_package dst, cx_package src);

/* ::corto::lang::parameter */
CORTO_LANG_EXPORT cx_parameter* cx_parameterCreate(cx_string name, cx_type type, cx_bool passByReference);
CORTO_LANG_EXPORT cx_parameter* cx_parameterCreateChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference);

CORTO_LANG_EXPORT cx_parameter* cx_parameterDeclare(void);
CORTO_LANG_EXPORT cx_parameter* cx_parameterDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_parameterDefine(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
CORTO_LANG_EXPORT void cx_parameterUpdate(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
CORTO_LANG_EXPORT void cx_parameterSet(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
CORTO_LANG_EXPORT cx_string cx_parameterStr(cx_parameter* value);
CORTO_LANG_EXPORT cx_parameter* cx_parameterFromStr(cx_parameter* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_parameterCopy(cx_parameter* *dst, cx_parameter* src);
CORTO_LANG_EXPORT cx_int16 cx_parameterCompare(cx_parameter* dst, cx_parameter* src);

CORTO_LANG_EXPORT cx_int16 cx_parameterInit(cx_parameter* value);
CORTO_LANG_EXPORT cx_int16 cx_parameterDeinit(cx_parameter* value);

/* ::corto::lang::parameterseq */
CORTO_LANG_EXPORT cx_parameterseq* cx_parameterseqCreate(void);
CORTO_LANG_EXPORT cx_parameterseq* cx_parameterseqCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_parameterseq* cx_parameterseqDeclare(void);
CORTO_LANG_EXPORT cx_parameterseq* cx_parameterseqDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_parameterseqDefine(cx_parameterseq* _this, cx_parameterseq value);
CORTO_LANG_EXPORT void cx_parameterseqUpdate(cx_parameterseq* _this, cx_parameterseq value);
CORTO_LANG_EXPORT void cx_parameterseqSet(cx_parameterseq* _this, cx_parameterseq value);
CORTO_LANG_EXPORT cx_string cx_parameterseqStr(cx_parameterseq value);
CORTO_LANG_EXPORT cx_parameterseq* cx_parameterseqFromStr(cx_parameterseq* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_parameterseqCopy(cx_parameterseq* *dst, cx_parameterseq* src);
CORTO_LANG_EXPORT cx_int16 cx_parameterseqCompare(cx_parameterseq* dst, cx_parameterseq* src);

CORTO_LANG_EXPORT cx_int16 cx_parameterseqInit(cx_parameterseq* value);
CORTO_LANG_EXPORT cx_int16 cx_parameterseqDeinit(cx_parameterseq* value);

/* ::corto::lang::primitive */
CORTO_LANG_EXPORT cx_primitive cx_primitiveCreate(cx_width width);
CORTO_LANG_EXPORT cx_primitive cx_primitiveCreateChild(cx_object _parent, cx_string _name, cx_width width);

CORTO_LANG_EXPORT cx_primitive cx_primitiveDeclare(void);
CORTO_LANG_EXPORT cx_primitive cx_primitiveDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_primitiveDefine(cx_primitive _this, cx_width width);
CORTO_LANG_EXPORT void cx_primitiveUpdate(cx_primitive _this, cx_width width);
CORTO_LANG_EXPORT void cx_primitiveSet(cx_primitive _this, cx_width width);
CORTO_LANG_EXPORT cx_string cx_primitiveStr(cx_primitive value);
CORTO_LANG_EXPORT cx_primitive cx_primitiveFromStr(cx_primitive value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_primitiveCopy(cx_primitive *dst, cx_primitive src);
CORTO_LANG_EXPORT cx_int16 cx_primitiveCompare(cx_primitive dst, cx_primitive src);

/* ::corto::lang::primitiveKind */
CORTO_LANG_EXPORT cx_primitiveKind* cx_primitiveKindCreate(cx_primitiveKind value);
CORTO_LANG_EXPORT cx_primitiveKind* cx_primitiveKindCreateChild(cx_object _parent, cx_string _name, cx_primitiveKind value);

CORTO_LANG_EXPORT cx_primitiveKind* cx_primitiveKindDeclare(void);
CORTO_LANG_EXPORT cx_primitiveKind* cx_primitiveKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_primitiveKindDefine(cx_primitiveKind* _this, cx_primitiveKind value);
CORTO_LANG_EXPORT void cx_primitiveKindUpdate(cx_primitiveKind* _this, cx_primitiveKind value);
CORTO_LANG_EXPORT void cx_primitiveKindSet(cx_primitiveKind* _this, cx_primitiveKind value);
CORTO_LANG_EXPORT cx_string cx_primitiveKindStr(cx_primitiveKind value);
CORTO_LANG_EXPORT cx_primitiveKind* cx_primitiveKindFromStr(cx_primitiveKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_primitiveKindCopy(cx_primitiveKind* *dst, cx_primitiveKind* src);
CORTO_LANG_EXPORT cx_int16 cx_primitiveKindCompare(cx_primitiveKind* dst, cx_primitiveKind* src);

CORTO_LANG_EXPORT cx_int16 cx_primitiveKindInit(cx_primitiveKind* value);
CORTO_LANG_EXPORT cx_int16 cx_primitiveKindDeinit(cx_primitiveKind* value);

/* ::corto::lang::procedure */
CORTO_LANG_EXPORT cx_procedure cx_procedureCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType, cx_procedureKind kind);
CORTO_LANG_EXPORT cx_procedure cx_procedureCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType, cx_procedureKind kind);

CORTO_LANG_EXPORT cx_procedure cx_procedureDeclare(void);
CORTO_LANG_EXPORT cx_procedure cx_procedureDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_procedureDefine(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType, cx_procedureKind kind);
CORTO_LANG_EXPORT void cx_procedureUpdate(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType, cx_procedureKind kind);
CORTO_LANG_EXPORT void cx_procedureSet(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType, cx_procedureKind kind);
CORTO_LANG_EXPORT cx_string cx_procedureStr(cx_procedure value);
CORTO_LANG_EXPORT cx_procedure cx_procedureFromStr(cx_procedure value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_procedureCopy(cx_procedure *dst, cx_procedure src);
CORTO_LANG_EXPORT cx_int16 cx_procedureCompare(cx_procedure dst, cx_procedure src);

/* ::corto::lang::procedureKind */
CORTO_LANG_EXPORT cx_procedureKind* cx_procedureKindCreate(cx_procedureKind value);
CORTO_LANG_EXPORT cx_procedureKind* cx_procedureKindCreateChild(cx_object _parent, cx_string _name, cx_procedureKind value);

CORTO_LANG_EXPORT cx_procedureKind* cx_procedureKindDeclare(void);
CORTO_LANG_EXPORT cx_procedureKind* cx_procedureKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_procedureKindDefine(cx_procedureKind* _this, cx_procedureKind value);
CORTO_LANG_EXPORT void cx_procedureKindUpdate(cx_procedureKind* _this, cx_procedureKind value);
CORTO_LANG_EXPORT void cx_procedureKindSet(cx_procedureKind* _this, cx_procedureKind value);
CORTO_LANG_EXPORT cx_string cx_procedureKindStr(cx_procedureKind value);
CORTO_LANG_EXPORT cx_procedureKind* cx_procedureKindFromStr(cx_procedureKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_procedureKindCopy(cx_procedureKind* *dst, cx_procedureKind* src);
CORTO_LANG_EXPORT cx_int16 cx_procedureKindCompare(cx_procedureKind* dst, cx_procedureKind* src);

CORTO_LANG_EXPORT cx_int16 cx_procedureKindInit(cx_procedureKind* value);
CORTO_LANG_EXPORT cx_int16 cx_procedureKindDeinit(cx_procedureKind* value);

/* ::corto::lang::query */
CORTO_LANG_EXPORT cx_query cx_queryCreate(cx_object from, cx_eventMask mask);
CORTO_LANG_EXPORT cx_query cx_queryCreateChild(cx_object _parent, cx_string _name, cx_object from, cx_eventMask mask);

CORTO_LANG_EXPORT cx_query cx_queryDeclare(void);
CORTO_LANG_EXPORT cx_query cx_queryDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_queryDefine(cx_query _this, cx_object from, cx_eventMask mask);
CORTO_LANG_EXPORT void cx_queryUpdate(cx_query _this, cx_object from, cx_eventMask mask);
CORTO_LANG_EXPORT void cx_querySet(cx_query _this, cx_object from, cx_eventMask mask);
CORTO_LANG_EXPORT cx_string cx_queryStr(cx_query value);
CORTO_LANG_EXPORT cx_query cx_queryFromStr(cx_query value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_queryCopy(cx_query *dst, cx_query src);
CORTO_LANG_EXPORT cx_int16 cx_queryCompare(cx_query dst, cx_query src);

/* ::corto::lang::replicator */
CORTO_LANG_EXPORT cx_replicator cx_replicatorCreate(cx_object mount, cx_query query, cx_notifyAction onDeclare, cx_notifyAction onUpdate, cx_notifyAction onDelete, cx_invokeAction onInvoke);
CORTO_LANG_EXPORT cx_replicator cx_replicatorCreateChild(cx_object _parent, cx_string _name, cx_object mount, cx_query query, cx_notifyAction onDeclare, cx_notifyAction onUpdate, cx_notifyAction onDelete, cx_invokeAction onInvoke);

CORTO_LANG_EXPORT cx_replicator cx_replicatorDeclare(void);
CORTO_LANG_EXPORT cx_replicator cx_replicatorDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_replicatorDefine(cx_replicator _this, cx_object mount, cx_query query, cx_notifyAction onDeclare, cx_notifyAction onUpdate, cx_notifyAction onDelete, cx_invokeAction onInvoke);
CORTO_LANG_EXPORT void cx_replicatorUpdate(cx_replicator _this, cx_object mount, cx_query query, cx_notifyAction onDeclare, cx_notifyAction onUpdate, cx_notifyAction onDelete, cx_invokeAction onInvoke);
CORTO_LANG_EXPORT void cx_replicatorSet(cx_replicator _this, cx_object mount, cx_query query, cx_notifyAction onDeclare, cx_notifyAction onUpdate, cx_notifyAction onDelete, cx_invokeAction onInvoke);
CORTO_LANG_EXPORT cx_string cx_replicatorStr(cx_replicator value);
CORTO_LANG_EXPORT cx_replicator cx_replicatorFromStr(cx_replicator value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_replicatorCopy(cx_replicator *dst, cx_replicator src);
CORTO_LANG_EXPORT cx_int16 cx_replicatorCompare(cx_replicator dst, cx_replicator src);

/* ::corto::lang::sequence */
CORTO_LANG_EXPORT cx_sequence cx_sequenceCreate(cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_sequence cx_sequenceCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

CORTO_LANG_EXPORT cx_sequence cx_sequenceDeclare(void);
CORTO_LANG_EXPORT cx_sequence cx_sequenceDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_sequenceDefine(cx_sequence _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_sequenceUpdate(cx_sequence _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT void cx_sequenceSet(cx_sequence _this, cx_type elementType, cx_uint32 max);
CORTO_LANG_EXPORT cx_string cx_sequenceStr(cx_sequence value);
CORTO_LANG_EXPORT cx_sequence cx_sequenceFromStr(cx_sequence value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_sequenceCopy(cx_sequence *dst, cx_sequence src);
CORTO_LANG_EXPORT cx_int16 cx_sequenceCompare(cx_sequence dst, cx_sequence src);

/* ::corto::lang::state */
CORTO_LANG_EXPORT cx_state* cx_stateCreate(cx_state value);
CORTO_LANG_EXPORT cx_state* cx_stateCreateChild(cx_object _parent, cx_string _name, cx_state value);

CORTO_LANG_EXPORT cx_state* cx_stateDeclare(void);
CORTO_LANG_EXPORT cx_state* cx_stateDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_stateDefine(cx_state* _this, cx_state value);
CORTO_LANG_EXPORT void cx_stateUpdate(cx_state* _this, cx_state value);
CORTO_LANG_EXPORT void cx_stateSet(cx_state* _this, cx_state value);
CORTO_LANG_EXPORT cx_string cx_stateStr(cx_state value);
CORTO_LANG_EXPORT cx_state* cx_stateFromStr(cx_state* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_stateCopy(cx_state* *dst, cx_state* src);
CORTO_LANG_EXPORT cx_int16 cx_stateCompare(cx_state* dst, cx_state* src);

CORTO_LANG_EXPORT cx_int16 cx_stateInit(cx_state* value);
CORTO_LANG_EXPORT cx_int16 cx_stateDeinit(cx_state* value);

/* ::corto::lang::string */
CORTO_LANG_EXPORT cx_string* cx_stringCreate(cx_string value);
CORTO_LANG_EXPORT cx_string* cx_stringCreateChild(cx_object _parent, cx_string _name, cx_string value);

CORTO_LANG_EXPORT cx_string* cx_stringDeclare(void);
CORTO_LANG_EXPORT cx_string* cx_stringDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_stringDefine(cx_string* _this, cx_string value);
CORTO_LANG_EXPORT void cx_stringUpdate(cx_string* _this, cx_string value);
CORTO_LANG_EXPORT void cx_stringSet(cx_string* _this, cx_string value);
CORTO_LANG_EXPORT cx_string cx_stringStr(cx_string value);
CORTO_LANG_EXPORT cx_string* cx_stringFromStr(cx_string* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_stringCopy(cx_string* *dst, cx_string* src);
CORTO_LANG_EXPORT cx_int16 cx_stringCompare(cx_string* dst, cx_string* src);

CORTO_LANG_EXPORT cx_int16 cx_stringInit(cx_string* value);
CORTO_LANG_EXPORT cx_int16 cx_stringDeinit(cx_string* value);

/* ::corto::lang::struct */
CORTO_LANG_EXPORT cx_struct cx_structCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_struct cx_structCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);

CORTO_LANG_EXPORT cx_struct cx_structDeclare(void);
CORTO_LANG_EXPORT cx_struct cx_structDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_structDefine(cx_struct _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_structUpdate(cx_struct _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_structSet(cx_struct _this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_string cx_structStr(cx_struct value);
CORTO_LANG_EXPORT cx_struct cx_structFromStr(cx_struct value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_structCopy(cx_struct *dst, cx_struct src);
CORTO_LANG_EXPORT cx_int16 cx_structCompare(cx_struct dst, cx_struct src);

/* ::corto::lang::text */
CORTO_LANG_EXPORT cx_text cx_textCreate(cx_width charWidth, cx_uint64 length);
CORTO_LANG_EXPORT cx_text cx_textCreateChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length);

CORTO_LANG_EXPORT cx_text cx_textDeclare(void);
CORTO_LANG_EXPORT cx_text cx_textDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_textDefine(cx_text _this, cx_width charWidth, cx_uint64 length);
CORTO_LANG_EXPORT void cx_textUpdate(cx_text _this, cx_width charWidth, cx_uint64 length);
CORTO_LANG_EXPORT void cx_textSet(cx_text _this, cx_width charWidth, cx_uint64 length);
CORTO_LANG_EXPORT cx_string cx_textStr(cx_text value);
CORTO_LANG_EXPORT cx_text cx_textFromStr(cx_text value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_textCopy(cx_text *dst, cx_text src);
CORTO_LANG_EXPORT cx_int16 cx_textCompare(cx_text dst, cx_text src);

/* ::corto::lang::type */
CORTO_LANG_EXPORT cx_type cx_typeCreate(cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_type cx_typeCreateChild(cx_object _parent, cx_string _name, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);

CORTO_LANG_EXPORT cx_type cx_typeDeclare(void);
CORTO_LANG_EXPORT cx_type cx_typeDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_typeDefine(cx_type _this, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_typeUpdate(cx_type _this, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT void cx_typeSet(cx_type _this, cx_type parentType, cx_state parentState, cx_type defaultType, cx_type defaultProcedureType);
CORTO_LANG_EXPORT cx_string cx_typeStr(cx_type value);
CORTO_LANG_EXPORT cx_type cx_typeFromStr(cx_type value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_typeCopy(cx_type *dst, cx_type src);
CORTO_LANG_EXPORT cx_int16 cx_typeCompare(cx_type dst, cx_type src);

/* ::corto::lang::typeKind */
CORTO_LANG_EXPORT cx_typeKind* cx_typeKindCreate(cx_typeKind value);
CORTO_LANG_EXPORT cx_typeKind* cx_typeKindCreateChild(cx_object _parent, cx_string _name, cx_typeKind value);

CORTO_LANG_EXPORT cx_typeKind* cx_typeKindDeclare(void);
CORTO_LANG_EXPORT cx_typeKind* cx_typeKindDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_typeKindDefine(cx_typeKind* _this, cx_typeKind value);
CORTO_LANG_EXPORT void cx_typeKindUpdate(cx_typeKind* _this, cx_typeKind value);
CORTO_LANG_EXPORT void cx_typeKindSet(cx_typeKind* _this, cx_typeKind value);
CORTO_LANG_EXPORT cx_string cx_typeKindStr(cx_typeKind value);
CORTO_LANG_EXPORT cx_typeKind* cx_typeKindFromStr(cx_typeKind* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_typeKindCopy(cx_typeKind* *dst, cx_typeKind* src);
CORTO_LANG_EXPORT cx_int16 cx_typeKindCompare(cx_typeKind* dst, cx_typeKind* src);

CORTO_LANG_EXPORT cx_int16 cx_typeKindInit(cx_typeKind* value);
CORTO_LANG_EXPORT cx_int16 cx_typeKindDeinit(cx_typeKind* value);

/* ::corto::lang::uint */
CORTO_LANG_EXPORT cx_uint cx_uintCreate(cx_width width, cx_uint64 min, cx_uint64 max);
CORTO_LANG_EXPORT cx_uint cx_uintCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_uint64 min, cx_uint64 max);

CORTO_LANG_EXPORT cx_uint cx_uintDeclare(void);
CORTO_LANG_EXPORT cx_uint cx_uintDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_uintDefine(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
CORTO_LANG_EXPORT void cx_uintUpdate(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
CORTO_LANG_EXPORT void cx_uintSet(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
CORTO_LANG_EXPORT cx_string cx_uintStr(cx_uint value);
CORTO_LANG_EXPORT cx_uint cx_uintFromStr(cx_uint value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_uintCopy(cx_uint *dst, cx_uint src);
CORTO_LANG_EXPORT cx_int16 cx_uintCompare(cx_uint dst, cx_uint src);

/* ::corto::lang::uint16 */
CORTO_LANG_EXPORT cx_uint16* cx_uint16Create(cx_uint16 value);
CORTO_LANG_EXPORT cx_uint16* cx_uint16CreateChild(cx_object _parent, cx_string _name, cx_uint16 value);

CORTO_LANG_EXPORT cx_uint16* cx_uint16Declare(void);
CORTO_LANG_EXPORT cx_uint16* cx_uint16DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_uint16Define(cx_uint16* _this, cx_uint16 value);
CORTO_LANG_EXPORT void cx_uint16Update(cx_uint16* _this, cx_uint16 value);
CORTO_LANG_EXPORT void cx_uint16Set(cx_uint16* _this, cx_uint16 value);
CORTO_LANG_EXPORT cx_string cx_uint16Str(cx_uint16 value);
CORTO_LANG_EXPORT cx_uint16* cx_uint16FromStr(cx_uint16* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_uint16Copy(cx_uint16* *dst, cx_uint16* src);
CORTO_LANG_EXPORT cx_int16 cx_uint16Compare(cx_uint16* dst, cx_uint16* src);

CORTO_LANG_EXPORT cx_int16 cx_uint16Init(cx_uint16* value);
CORTO_LANG_EXPORT cx_int16 cx_uint16Deinit(cx_uint16* value);

/* ::corto::lang::uint32 */
CORTO_LANG_EXPORT cx_uint32* cx_uint32Create(cx_uint32 value);
CORTO_LANG_EXPORT cx_uint32* cx_uint32CreateChild(cx_object _parent, cx_string _name, cx_uint32 value);

CORTO_LANG_EXPORT cx_uint32* cx_uint32Declare(void);
CORTO_LANG_EXPORT cx_uint32* cx_uint32DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_uint32Define(cx_uint32* _this, cx_uint32 value);
CORTO_LANG_EXPORT void cx_uint32Update(cx_uint32* _this, cx_uint32 value);
CORTO_LANG_EXPORT void cx_uint32Set(cx_uint32* _this, cx_uint32 value);
CORTO_LANG_EXPORT cx_string cx_uint32Str(cx_uint32 value);
CORTO_LANG_EXPORT cx_uint32* cx_uint32FromStr(cx_uint32* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_uint32Copy(cx_uint32* *dst, cx_uint32* src);
CORTO_LANG_EXPORT cx_int16 cx_uint32Compare(cx_uint32* dst, cx_uint32* src);

CORTO_LANG_EXPORT cx_int16 cx_uint32Init(cx_uint32* value);
CORTO_LANG_EXPORT cx_int16 cx_uint32Deinit(cx_uint32* value);

/* ::corto::lang::uint64 */
CORTO_LANG_EXPORT cx_uint64* cx_uint64Create(cx_uint64 value);
CORTO_LANG_EXPORT cx_uint64* cx_uint64CreateChild(cx_object _parent, cx_string _name, cx_uint64 value);

CORTO_LANG_EXPORT cx_uint64* cx_uint64Declare(void);
CORTO_LANG_EXPORT cx_uint64* cx_uint64DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_uint64Define(cx_uint64* _this, cx_uint64 value);
CORTO_LANG_EXPORT void cx_uint64Update(cx_uint64* _this, cx_uint64 value);
CORTO_LANG_EXPORT void cx_uint64Set(cx_uint64* _this, cx_uint64 value);
CORTO_LANG_EXPORT cx_string cx_uint64Str(cx_uint64 value);
CORTO_LANG_EXPORT cx_uint64* cx_uint64FromStr(cx_uint64* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_uint64Copy(cx_uint64* *dst, cx_uint64* src);
CORTO_LANG_EXPORT cx_int16 cx_uint64Compare(cx_uint64* dst, cx_uint64* src);

CORTO_LANG_EXPORT cx_int16 cx_uint64Init(cx_uint64* value);
CORTO_LANG_EXPORT cx_int16 cx_uint64Deinit(cx_uint64* value);

/* ::corto::lang::uint8 */
CORTO_LANG_EXPORT cx_uint8* cx_uint8Create(cx_uint8 value);
CORTO_LANG_EXPORT cx_uint8* cx_uint8CreateChild(cx_object _parent, cx_string _name, cx_uint8 value);

CORTO_LANG_EXPORT cx_uint8* cx_uint8Declare(void);
CORTO_LANG_EXPORT cx_uint8* cx_uint8DeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_uint8Define(cx_uint8* _this, cx_uint8 value);
CORTO_LANG_EXPORT void cx_uint8Update(cx_uint8* _this, cx_uint8 value);
CORTO_LANG_EXPORT void cx_uint8Set(cx_uint8* _this, cx_uint8 value);
CORTO_LANG_EXPORT cx_string cx_uint8Str(cx_uint8 value);
CORTO_LANG_EXPORT cx_uint8* cx_uint8FromStr(cx_uint8* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_uint8Copy(cx_uint8* *dst, cx_uint8* src);
CORTO_LANG_EXPORT cx_int16 cx_uint8Compare(cx_uint8* dst, cx_uint8* src);

CORTO_LANG_EXPORT cx_int16 cx_uint8Init(cx_uint8* value);
CORTO_LANG_EXPORT cx_int16 cx_uint8Deinit(cx_uint8* value);

/* ::corto::lang::virtual */
CORTO_LANG_EXPORT cx_virtual cx_virtualCreate(cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT cx_virtual cx_virtualCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));

CORTO_LANG_EXPORT cx_virtual cx_virtualDeclare(void);
CORTO_LANG_EXPORT cx_virtual cx_virtualDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_virtualDefine(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual, void(*_impl)(cx_function f, void *result, void *args));
CORTO_LANG_EXPORT void cx_virtualUpdate(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual);
CORTO_LANG_EXPORT void cx_virtualSet(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool _virtual);
CORTO_LANG_EXPORT cx_string cx_virtualStr(cx_virtual value);
CORTO_LANG_EXPORT cx_virtual cx_virtualFromStr(cx_virtual value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_virtualCopy(cx_virtual *dst, cx_virtual src);
CORTO_LANG_EXPORT cx_int16 cx_virtualCompare(cx_virtual dst, cx_virtual src);

/* ::corto::lang::void */
CORTO_LANG_EXPORT cx_void* cx_voidCreate(void);
CORTO_LANG_EXPORT cx_void* cx_voidCreateChild(cx_object _parent, cx_string _name);

/* ::corto::lang::vtable */
CORTO_LANG_EXPORT cx_vtable* cx_vtableCreate(void);
CORTO_LANG_EXPORT cx_vtable* cx_vtableCreateChild(cx_object _parent, cx_string _name);

CORTO_LANG_EXPORT cx_vtable* cx_vtableDeclare(void);
CORTO_LANG_EXPORT cx_vtable* cx_vtableDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_vtableDefine(cx_vtable* _this, cx_vtable value);
CORTO_LANG_EXPORT void cx_vtableUpdate(cx_vtable* _this, cx_vtable value);
CORTO_LANG_EXPORT void cx_vtableSet(cx_vtable* _this, cx_vtable value);
CORTO_LANG_EXPORT cx_string cx_vtableStr(cx_vtable value);
CORTO_LANG_EXPORT cx_vtable* cx_vtableFromStr(cx_vtable* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_vtableCopy(cx_vtable* *dst, cx_vtable* src);
CORTO_LANG_EXPORT cx_int16 cx_vtableCompare(cx_vtable* dst, cx_vtable* src);

CORTO_LANG_EXPORT cx_int16 cx_vtableInit(cx_vtable* value);
CORTO_LANG_EXPORT cx_int16 cx_vtableDeinit(cx_vtable* value);

/* ::corto::lang::width */
CORTO_LANG_EXPORT cx_width* cx_widthCreate(cx_width value);
CORTO_LANG_EXPORT cx_width* cx_widthCreateChild(cx_object _parent, cx_string _name, cx_width value);

CORTO_LANG_EXPORT cx_width* cx_widthDeclare(void);
CORTO_LANG_EXPORT cx_width* cx_widthDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_widthDefine(cx_width* _this, cx_width value);
CORTO_LANG_EXPORT void cx_widthUpdate(cx_width* _this, cx_width value);
CORTO_LANG_EXPORT void cx_widthSet(cx_width* _this, cx_width value);
CORTO_LANG_EXPORT cx_string cx_widthStr(cx_width value);
CORTO_LANG_EXPORT cx_width* cx_widthFromStr(cx_width* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_widthCopy(cx_width* *dst, cx_width* src);
CORTO_LANG_EXPORT cx_int16 cx_widthCompare(cx_width* dst, cx_width* src);

CORTO_LANG_EXPORT cx_int16 cx_widthInit(cx_width* value);
CORTO_LANG_EXPORT cx_int16 cx_widthDeinit(cx_width* value);

/* ::corto::lang::word */
CORTO_LANG_EXPORT cx_word* cx_wordCreate(cx_word value);
CORTO_LANG_EXPORT cx_word* cx_wordCreateChild(cx_object _parent, cx_string _name, cx_word value);

CORTO_LANG_EXPORT cx_word* cx_wordDeclare(void);
CORTO_LANG_EXPORT cx_word* cx_wordDeclareChild(cx_object _parent, cx_string _name);
CORTO_LANG_EXPORT cx_int16 cx_wordDefine(cx_word* _this, cx_word value);
CORTO_LANG_EXPORT void cx_wordUpdate(cx_word* _this, cx_word value);
CORTO_LANG_EXPORT void cx_wordSet(cx_word* _this, cx_word value);
CORTO_LANG_EXPORT cx_string cx_wordStr(cx_word value);
CORTO_LANG_EXPORT cx_word* cx_wordFromStr(cx_word* value, cx_string str);
CORTO_LANG_EXPORT cx_int16 cx_wordCopy(cx_word* *dst, cx_word* src);
CORTO_LANG_EXPORT cx_int16 cx_wordCompare(cx_word* dst, cx_word* src);

CORTO_LANG_EXPORT cx_int16 cx_wordInit(cx_word* value);
CORTO_LANG_EXPORT cx_int16 cx_wordDeinit(cx_word* value);


/* ::corto::lang::interfaceseq */
#define cx_interfaceseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interface elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_interface cx_interfaceseqAppend(cx_interfaceseq *seq);
CORTO_LANG_EXPORT void cx_interfaceseqSize(cx_interfaceseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_interfaceseqClear(cx_interfaceseq *seq);

/* ::corto::lang::interfaceVectorseq */
#define cx_interfaceVectorseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interfaceVector elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_interfaceVector* cx_interfaceVectorseqAppend(cx_interfaceVectorseq *seq);
CORTO_LANG_EXPORT void cx_interfaceVectorseqSize(cx_interfaceVectorseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_interfaceVectorseqClear(cx_interfaceVectorseq *seq);

/* ::corto::lang::memberseq */
#define cx_memberseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_member elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_member cx_memberseqAppend(cx_memberseq *seq);
CORTO_LANG_EXPORT void cx_memberseqSize(cx_memberseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_memberseqClear(cx_memberseq *seq);

/* ::corto::lang::objectseq */
#define cx_objectseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_object elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_object cx_objectseqAppend(cx_objectseq *seq);
CORTO_LANG_EXPORT void cx_objectseqSize(cx_objectseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_objectseqClear(cx_objectseq *seq);

/* ::corto::lang::observerseq */
#define cx_observerseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_observer elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_observer cx_observerseqAppend(cx_observerseq *seq);
CORTO_LANG_EXPORT void cx_observerseqSize(cx_observerseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_observerseqClear(cx_observerseq *seq);

/* ::corto::lang::octetseq */
#define cx_octetseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_octet elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_octet* cx_octetseqAppend(cx_octetseq *seq);
CORTO_LANG_EXPORT void cx_octetseqSize(cx_octetseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_octetseqClear(cx_octetseq *seq);

/* ::corto::lang::parameterseq */
#define cx_parameterseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_parameter* cx_parameterseqAppend(cx_parameterseq *seq);
CORTO_LANG_EXPORT void cx_parameterseqSize(cx_parameterseq *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_parameterseqClear(cx_parameterseq *seq);

/* ::corto::lang::vtable */
#define cx_vtableForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_function elem;\
    for(elem##_iter=0; seq.buffer ? elem = seq.buffer[elem##_iter] : elem, elem##_iter<seq.length; elem##_iter++)\

CORTO_LANG_EXPORT cx_function cx_vtableAppend(cx_vtable *seq);
CORTO_LANG_EXPORT void cx_vtableSize(cx_vtable *seq, cx_uint32 length);
CORTO_LANG_EXPORT void cx_vtableClear(cx_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

