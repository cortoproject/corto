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
/* ::corto::lang::alias */
CORTO_LANG_EXPORT corto_alias corto_aliasCreate(corto_member member);
CORTO_LANG_EXPORT corto_alias corto_aliasCreateChild(corto_object _parent, corto_string _name, corto_member member);
CORTO_LANG_EXPORT corto_int16 corto_aliasUpdate(corto_alias _this, corto_member member);

CORTO_LANG_EXPORT corto_alias corto_aliasDeclare(void);
CORTO_LANG_EXPORT corto_alias corto_aliasDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_aliasDefine(corto_alias _this, corto_member member);
CORTO_LANG_EXPORT void corto_aliasSet(corto_alias _this, corto_member member);
CORTO_LANG_EXPORT corto_string corto_aliasStr(corto_alias value);
CORTO_LANG_EXPORT corto_alias corto_aliasFromStr(corto_alias value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_aliasCopy(corto_alias *dst, corto_alias src);
CORTO_LANG_EXPORT corto_int16 corto_aliasCompare(corto_alias dst, corto_alias src);

/* ::corto::lang::any */
CORTO_LANG_EXPORT corto_any* corto_anyCreate(corto_any value);
CORTO_LANG_EXPORT corto_any* corto_anyCreateChild(corto_object _parent, corto_string _name, corto_any value);
CORTO_LANG_EXPORT corto_int16 corto_anyUpdate(corto_any* _this, corto_any value);

CORTO_LANG_EXPORT corto_any* corto_anyDeclare(void);
CORTO_LANG_EXPORT corto_any* corto_anyDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_anyDefine(corto_any* _this, corto_any value);
CORTO_LANG_EXPORT void corto_anySet(corto_any* _this, corto_any value);
CORTO_LANG_EXPORT corto_string corto_anyStr(corto_any value);
CORTO_LANG_EXPORT corto_any* corto_anyFromStr(corto_any* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_anyCopy(corto_any* *dst, corto_any* src);
CORTO_LANG_EXPORT corto_int16 corto_anyCompare(corto_any* dst, corto_any* src);

CORTO_LANG_EXPORT corto_int16 corto_anyInit(corto_any* value);
CORTO_LANG_EXPORT corto_int16 corto_anyDeinit(corto_any* value);

/* ::corto::lang::array */
CORTO_LANG_EXPORT corto_array corto_arrayCreate(corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_array corto_arrayCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_int16 corto_arrayUpdate(corto_array _this, corto_type elementType, corto_uint32 max);

CORTO_LANG_EXPORT corto_array corto_arrayDeclare(void);
CORTO_LANG_EXPORT corto_array corto_arrayDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_arrayDefine(corto_array _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT void corto_arraySet(corto_array _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_string corto_arrayStr(corto_array value);
CORTO_LANG_EXPORT corto_array corto_arrayFromStr(corto_array value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_arrayCopy(corto_array *dst, corto_array src);
CORTO_LANG_EXPORT corto_int16 corto_arrayCompare(corto_array dst, corto_array src);

/* ::corto::lang::attr */
CORTO_LANG_EXPORT corto_attr* corto_attrCreate(corto_attr value);
CORTO_LANG_EXPORT corto_attr* corto_attrCreateChild(corto_object _parent, corto_string _name, corto_attr value);
CORTO_LANG_EXPORT corto_int16 corto_attrUpdate(corto_attr* _this, corto_attr value);

CORTO_LANG_EXPORT corto_attr* corto_attrDeclare(void);
CORTO_LANG_EXPORT corto_attr* corto_attrDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_attrDefine(corto_attr* _this, corto_attr value);
CORTO_LANG_EXPORT void corto_attrSet(corto_attr* _this, corto_attr value);
CORTO_LANG_EXPORT corto_string corto_attrStr(corto_attr value);
CORTO_LANG_EXPORT corto_attr* corto_attrFromStr(corto_attr* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_attrCopy(corto_attr* *dst, corto_attr* src);
CORTO_LANG_EXPORT corto_int16 corto_attrCompare(corto_attr* dst, corto_attr* src);

CORTO_LANG_EXPORT corto_int16 corto_attrInit(corto_attr* value);
CORTO_LANG_EXPORT corto_int16 corto_attrDeinit(corto_attr* value);

/* ::corto::lang::binary */
CORTO_LANG_EXPORT corto_binary corto_binaryCreate(corto_width width);
CORTO_LANG_EXPORT corto_binary corto_binaryCreateChild(corto_object _parent, corto_string _name, corto_width width);
CORTO_LANG_EXPORT corto_int16 corto_binaryUpdate(corto_binary _this, corto_width width);

CORTO_LANG_EXPORT corto_binary corto_binaryDeclare(void);
CORTO_LANG_EXPORT corto_binary corto_binaryDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_binaryDefine(corto_binary _this, corto_width width);
CORTO_LANG_EXPORT void corto_binarySet(corto_binary _this, corto_width width);
CORTO_LANG_EXPORT corto_string corto_binaryStr(corto_binary value);
CORTO_LANG_EXPORT corto_binary corto_binaryFromStr(corto_binary value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_binaryCopy(corto_binary *dst, corto_binary src);
CORTO_LANG_EXPORT corto_int16 corto_binaryCompare(corto_binary dst, corto_binary src);

/* ::corto::lang::bitmask */
CORTO_LANG_EXPORT corto_bitmask corto_bitmaskCreate(void);
CORTO_LANG_EXPORT corto_bitmask corto_bitmaskCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_bitmaskUpdate(corto_bitmask _this);

CORTO_LANG_EXPORT corto_bitmask corto_bitmaskDeclare(void);
CORTO_LANG_EXPORT corto_bitmask corto_bitmaskDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_bitmaskDefine(corto_bitmask _this);
CORTO_LANG_EXPORT void corto_bitmaskSet(corto_bitmask _this);
CORTO_LANG_EXPORT corto_string corto_bitmaskStr(corto_bitmask value);
CORTO_LANG_EXPORT corto_bitmask corto_bitmaskFromStr(corto_bitmask value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_bitmaskCopy(corto_bitmask *dst, corto_bitmask src);
CORTO_LANG_EXPORT corto_int16 corto_bitmaskCompare(corto_bitmask dst, corto_bitmask src);

/* ::corto::lang::bool */
CORTO_LANG_EXPORT corto_bool* corto_boolCreate(corto_bool value);
CORTO_LANG_EXPORT corto_bool* corto_boolCreateChild(corto_object _parent, corto_string _name, corto_bool value);
CORTO_LANG_EXPORT corto_int16 corto_boolUpdate(corto_bool* _this, corto_bool value);

CORTO_LANG_EXPORT corto_bool* corto_boolDeclare(void);
CORTO_LANG_EXPORT corto_bool* corto_boolDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_boolDefine(corto_bool* _this, corto_bool value);
CORTO_LANG_EXPORT void corto_boolSet(corto_bool* _this, corto_bool value);
CORTO_LANG_EXPORT corto_string corto_boolStr(corto_bool value);
CORTO_LANG_EXPORT corto_bool* corto_boolFromStr(corto_bool* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_boolCopy(corto_bool* *dst, corto_bool* src);
CORTO_LANG_EXPORT corto_int16 corto_boolCompare(corto_bool* dst, corto_bool* src);

CORTO_LANG_EXPORT corto_int16 corto_boolInit(corto_bool* value);
CORTO_LANG_EXPORT corto_int16 corto_boolDeinit(corto_bool* value);

/* ::corto::lang::boolean */
CORTO_LANG_EXPORT corto_boolean corto_booleanCreate(void);
CORTO_LANG_EXPORT corto_boolean corto_booleanCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_booleanUpdate(corto_boolean _this);

CORTO_LANG_EXPORT corto_boolean corto_booleanDeclare(void);
CORTO_LANG_EXPORT corto_boolean corto_booleanDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_booleanDefine(corto_boolean _this);
CORTO_LANG_EXPORT void corto_booleanSet(corto_boolean _this);
CORTO_LANG_EXPORT corto_string corto_booleanStr(corto_boolean value);
CORTO_LANG_EXPORT corto_boolean corto_booleanFromStr(corto_boolean value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_booleanCopy(corto_boolean *dst, corto_boolean src);
CORTO_LANG_EXPORT corto_int16 corto_booleanCompare(corto_boolean dst, corto_boolean src);

/* ::corto::lang::char */
CORTO_LANG_EXPORT corto_char* corto_charCreate(corto_char value);
CORTO_LANG_EXPORT corto_char* corto_charCreateChild(corto_object _parent, corto_string _name, corto_char value);
CORTO_LANG_EXPORT corto_int16 corto_charUpdate(corto_char* _this, corto_char value);

CORTO_LANG_EXPORT corto_char* corto_charDeclare(void);
CORTO_LANG_EXPORT corto_char* corto_charDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_charDefine(corto_char* _this, corto_char value);
CORTO_LANG_EXPORT void corto_charSet(corto_char* _this, corto_char value);
CORTO_LANG_EXPORT corto_string corto_charStr(corto_char value);
CORTO_LANG_EXPORT corto_char* corto_charFromStr(corto_char* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_charCopy(corto_char* *dst, corto_char* src);
CORTO_LANG_EXPORT corto_int16 corto_charCompare(corto_char* dst, corto_char* src);

CORTO_LANG_EXPORT corto_int16 corto_charInit(corto_char* value);
CORTO_LANG_EXPORT corto_int16 corto_charDeinit(corto_char* value);

/* ::corto::lang::character */
CORTO_LANG_EXPORT corto_character corto_characterCreate(corto_width width);
CORTO_LANG_EXPORT corto_character corto_characterCreateChild(corto_object _parent, corto_string _name, corto_width width);
CORTO_LANG_EXPORT corto_int16 corto_characterUpdate(corto_character _this, corto_width width);

CORTO_LANG_EXPORT corto_character corto_characterDeclare(void);
CORTO_LANG_EXPORT corto_character corto_characterDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_characterDefine(corto_character _this, corto_width width);
CORTO_LANG_EXPORT void corto_characterSet(corto_character _this, corto_width width);
CORTO_LANG_EXPORT corto_string corto_characterStr(corto_character value);
CORTO_LANG_EXPORT corto_character corto_characterFromStr(corto_character value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_characterCopy(corto_character *dst, corto_character src);
CORTO_LANG_EXPORT corto_int16 corto_characterCompare(corto_character dst, corto_character src);

/* ::corto::lang::class */
CORTO_LANG_EXPORT corto_class corto_classCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
CORTO_LANG_EXPORT corto_class corto_classCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
CORTO_LANG_EXPORT corto_int16 corto_classUpdate(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);

CORTO_LANG_EXPORT corto_class corto_classDeclare(void);
CORTO_LANG_EXPORT corto_class corto_classDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_classDefine(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
CORTO_LANG_EXPORT void corto_classSet(corto_class _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
CORTO_LANG_EXPORT corto_string corto_classStr(corto_class value);
CORTO_LANG_EXPORT corto_class corto_classFromStr(corto_class value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_classCopy(corto_class *dst, corto_class src);
CORTO_LANG_EXPORT corto_int16 corto_classCompare(corto_class dst, corto_class src);

/* ::corto::lang::collection */
CORTO_LANG_EXPORT corto_collection corto_collectionCreate(corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_collection corto_collectionCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_int16 corto_collectionUpdate(corto_collection _this, corto_type elementType, corto_uint32 max);

CORTO_LANG_EXPORT corto_collection corto_collectionDeclare(void);
CORTO_LANG_EXPORT corto_collection corto_collectionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_collectionDefine(corto_collection _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT void corto_collectionSet(corto_collection _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_string corto_collectionStr(corto_collection value);
CORTO_LANG_EXPORT corto_collection corto_collectionFromStr(corto_collection value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_collectionCopy(corto_collection *dst, corto_collection src);
CORTO_LANG_EXPORT corto_int16 corto_collectionCompare(corto_collection dst, corto_collection src);

/* ::corto::lang::collectionKind */
CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindCreate(corto_collectionKind value);
CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindCreateChild(corto_object _parent, corto_string _name, corto_collectionKind value);
CORTO_LANG_EXPORT corto_int16 corto_collectionKindUpdate(corto_collectionKind* _this, corto_collectionKind value);

CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindDeclare(void);
CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_collectionKindDefine(corto_collectionKind* _this, corto_collectionKind value);
CORTO_LANG_EXPORT void corto_collectionKindSet(corto_collectionKind* _this, corto_collectionKind value);
CORTO_LANG_EXPORT corto_string corto_collectionKindStr(corto_collectionKind value);
CORTO_LANG_EXPORT corto_collectionKind* corto_collectionKindFromStr(corto_collectionKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_collectionKindCopy(corto_collectionKind* *dst, corto_collectionKind* src);
CORTO_LANG_EXPORT corto_int16 corto_collectionKindCompare(corto_collectionKind* dst, corto_collectionKind* src);

CORTO_LANG_EXPORT corto_int16 corto_collectionKindInit(corto_collectionKind* value);
CORTO_LANG_EXPORT corto_int16 corto_collectionKindDeinit(corto_collectionKind* value);

/* ::corto::lang::compositeKind */
CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindCreate(corto_compositeKind value);
CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindCreateChild(corto_object _parent, corto_string _name, corto_compositeKind value);
CORTO_LANG_EXPORT corto_int16 corto_compositeKindUpdate(corto_compositeKind* _this, corto_compositeKind value);

CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindDeclare(void);
CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_compositeKindDefine(corto_compositeKind* _this, corto_compositeKind value);
CORTO_LANG_EXPORT void corto_compositeKindSet(corto_compositeKind* _this, corto_compositeKind value);
CORTO_LANG_EXPORT corto_string corto_compositeKindStr(corto_compositeKind value);
CORTO_LANG_EXPORT corto_compositeKind* corto_compositeKindFromStr(corto_compositeKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_compositeKindCopy(corto_compositeKind* *dst, corto_compositeKind* src);
CORTO_LANG_EXPORT corto_int16 corto_compositeKindCompare(corto_compositeKind* dst, corto_compositeKind* src);

CORTO_LANG_EXPORT corto_int16 corto_compositeKindInit(corto_compositeKind* value);
CORTO_LANG_EXPORT corto_int16 corto_compositeKindDeinit(corto_compositeKind* value);

/* ::corto::lang::constant */
CORTO_LANG_EXPORT corto_constant* corto_constantCreate(corto_constant value);
CORTO_LANG_EXPORT corto_constant* corto_constantCreateChild(corto_object _parent, corto_string _name, corto_constant value);
CORTO_LANG_EXPORT corto_int16 corto_constantUpdate(corto_constant* _this, corto_constant value);

CORTO_LANG_EXPORT corto_constant* corto_constantDeclare(void);
CORTO_LANG_EXPORT corto_constant* corto_constantDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_constantDefine(corto_constant* _this, corto_constant value);
CORTO_LANG_EXPORT void corto_constantSet(corto_constant* _this, corto_constant value);
CORTO_LANG_EXPORT corto_string corto_constantStr(corto_constant value);
CORTO_LANG_EXPORT corto_constant* corto_constantFromStr(corto_constant* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_constantCopy(corto_constant* *dst, corto_constant* src);
CORTO_LANG_EXPORT corto_int16 corto_constantCompare(corto_constant* dst, corto_constant* src);

CORTO_LANG_EXPORT corto_int16 corto_constantInit(corto_constant* value);
CORTO_LANG_EXPORT corto_int16 corto_constantDeinit(corto_constant* value);

/* ::corto::lang::delegate */
CORTO_LANG_EXPORT corto_delegate corto_delegateCreate(corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
CORTO_LANG_EXPORT corto_delegate corto_delegateCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
CORTO_LANG_EXPORT corto_int16 corto_delegateUpdate(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);

CORTO_LANG_EXPORT corto_delegate corto_delegateDeclare(void);
CORTO_LANG_EXPORT corto_delegate corto_delegateDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_delegateDefine(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
CORTO_LANG_EXPORT void corto_delegateSet(corto_delegate _this, corto_type returnType, corto_bool returnsReference, corto_parameterseq parameters);
CORTO_LANG_EXPORT corto_string corto_delegateStr(corto_delegate value);
CORTO_LANG_EXPORT corto_delegate corto_delegateFromStr(corto_delegate value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_delegateCopy(corto_delegate *dst, corto_delegate src);
CORTO_LANG_EXPORT corto_int16 corto_delegateCompare(corto_delegate dst, corto_delegate src);

/* ::corto::lang::delegatedata */
CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataCreate(corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_int16 corto_delegatedataUpdate(corto_delegatedata* _this, corto_object instance, corto_function procedure);

CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataDeclare(void);
CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_delegatedataDefine(corto_delegatedata* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT void corto_delegatedataSet(corto_delegatedata* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_string corto_delegatedataStr(corto_delegatedata* value);
CORTO_LANG_EXPORT corto_delegatedata* corto_delegatedataFromStr(corto_delegatedata* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_delegatedataCopy(corto_delegatedata* *dst, corto_delegatedata* src);
CORTO_LANG_EXPORT corto_int16 corto_delegatedataCompare(corto_delegatedata* dst, corto_delegatedata* src);

CORTO_LANG_EXPORT corto_int16 corto_delegatedataInit(corto_delegatedata* value);
CORTO_LANG_EXPORT corto_int16 corto_delegatedataDeinit(corto_delegatedata* value);

/* ::corto::lang::destructAction */
CORTO_LANG_EXPORT corto_destructAction* corto_destructActionCreate(corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_destructAction* corto_destructActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_int16 corto_destructActionUpdate(corto_destructAction* _this, corto_object instance, corto_function procedure);

CORTO_LANG_EXPORT corto_destructAction* corto_destructActionDeclare(void);
CORTO_LANG_EXPORT corto_destructAction* corto_destructActionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_destructActionDefine(corto_destructAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT void corto_destructActionSet(corto_destructAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_string corto_destructActionStr(corto_destructAction* value);
CORTO_LANG_EXPORT corto_destructAction* corto_destructActionFromStr(corto_destructAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_destructActionCopy(corto_destructAction* *dst, corto_destructAction* src);
CORTO_LANG_EXPORT corto_int16 corto_destructActionCompare(corto_destructAction* dst, corto_destructAction* src);

CORTO_LANG_EXPORT corto_int16 corto_destructActionInit(corto_destructAction* value);
CORTO_LANG_EXPORT corto_int16 corto_destructActionDeinit(corto_destructAction* value);

corto_int16 corto_destructActionCall(corto_destructAction *_delegate);
/* ::corto::lang::dispatcher */
CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherCreate(void);
CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_dispatcherUpdate(corto_dispatcher _this);

CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherDeclare(void);
CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_dispatcherDefine(corto_dispatcher _this);
CORTO_LANG_EXPORT void corto_dispatcherSet(corto_dispatcher _this);
CORTO_LANG_EXPORT corto_string corto_dispatcherStr(corto_dispatcher value);
CORTO_LANG_EXPORT corto_dispatcher corto_dispatcherFromStr(corto_dispatcher value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_dispatcherCopy(corto_dispatcher *dst, corto_dispatcher src);
CORTO_LANG_EXPORT corto_int16 corto_dispatcherCompare(corto_dispatcher dst, corto_dispatcher src);

/* ::corto::lang::enum */
CORTO_LANG_EXPORT corto_enum corto_enumCreate(void);
CORTO_LANG_EXPORT corto_enum corto_enumCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_enumUpdate(corto_enum _this);

CORTO_LANG_EXPORT corto_enum corto_enumDeclare(void);
CORTO_LANG_EXPORT corto_enum corto_enumDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_enumDefine(corto_enum _this);
CORTO_LANG_EXPORT void corto_enumSet(corto_enum _this);
CORTO_LANG_EXPORT corto_string corto_enumStr(corto_enum value);
CORTO_LANG_EXPORT corto_enum corto_enumFromStr(corto_enum value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_enumCopy(corto_enum *dst, corto_enum src);
CORTO_LANG_EXPORT corto_int16 corto_enumCompare(corto_enum dst, corto_enum src);

/* ::corto::lang::equalityKind */
CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindCreate(corto_equalityKind value);
CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindCreateChild(corto_object _parent, corto_string _name, corto_equalityKind value);
CORTO_LANG_EXPORT corto_int16 corto_equalityKindUpdate(corto_equalityKind* _this, corto_equalityKind value);

CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindDeclare(void);
CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_equalityKindDefine(corto_equalityKind* _this, corto_equalityKind value);
CORTO_LANG_EXPORT void corto_equalityKindSet(corto_equalityKind* _this, corto_equalityKind value);
CORTO_LANG_EXPORT corto_string corto_equalityKindStr(corto_equalityKind value);
CORTO_LANG_EXPORT corto_equalityKind* corto_equalityKindFromStr(corto_equalityKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_equalityKindCopy(corto_equalityKind* *dst, corto_equalityKind* src);
CORTO_LANG_EXPORT corto_int16 corto_equalityKindCompare(corto_equalityKind* dst, corto_equalityKind* src);

CORTO_LANG_EXPORT corto_int16 corto_equalityKindInit(corto_equalityKind* value);
CORTO_LANG_EXPORT corto_int16 corto_equalityKindDeinit(corto_equalityKind* value);

/* ::corto::lang::event */
CORTO_LANG_EXPORT corto_event corto_eventCreate(corto_uint16 kind);
CORTO_LANG_EXPORT corto_event corto_eventCreateChild(corto_object _parent, corto_string _name, corto_uint16 kind);
CORTO_LANG_EXPORT corto_int16 corto_eventUpdate(corto_event _this, corto_uint16 kind);

CORTO_LANG_EXPORT corto_event corto_eventDeclare(void);
CORTO_LANG_EXPORT corto_event corto_eventDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_eventDefine(corto_event _this, corto_uint16 kind);
CORTO_LANG_EXPORT void corto_eventSet(corto_event _this, corto_uint16 kind);
CORTO_LANG_EXPORT corto_string corto_eventStr(corto_event value);
CORTO_LANG_EXPORT corto_event corto_eventFromStr(corto_event value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_eventCopy(corto_event *dst, corto_event src);
CORTO_LANG_EXPORT corto_int16 corto_eventCompare(corto_event dst, corto_event src);

/* ::corto::lang::eventMask */
CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskCreate(corto_eventMask value);
CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskCreateChild(corto_object _parent, corto_string _name, corto_eventMask value);
CORTO_LANG_EXPORT corto_int16 corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value);

CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskDeclare(void);
CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value);
CORTO_LANG_EXPORT void corto_eventMaskSet(corto_eventMask* _this, corto_eventMask value);
CORTO_LANG_EXPORT corto_string corto_eventMaskStr(corto_eventMask value);
CORTO_LANG_EXPORT corto_eventMask* corto_eventMaskFromStr(corto_eventMask* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_eventMaskCopy(corto_eventMask* *dst, corto_eventMask* src);
CORTO_LANG_EXPORT corto_int16 corto_eventMaskCompare(corto_eventMask* dst, corto_eventMask* src);

CORTO_LANG_EXPORT corto_int16 corto_eventMaskInit(corto_eventMask* value);
CORTO_LANG_EXPORT corto_int16 corto_eventMaskDeinit(corto_eventMask* value);

/* ::corto::lang::float */
CORTO_LANG_EXPORT corto_float corto_floatCreate(corto_width width, corto_float64 min, corto_float64 max);
CORTO_LANG_EXPORT corto_float corto_floatCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_float64 min, corto_float64 max);
CORTO_LANG_EXPORT corto_int16 corto_floatUpdate(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);

CORTO_LANG_EXPORT corto_float corto_floatDeclare(void);
CORTO_LANG_EXPORT corto_float corto_floatDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_floatDefine(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
CORTO_LANG_EXPORT void corto_floatSet(corto_float _this, corto_width width, corto_float64 min, corto_float64 max);
CORTO_LANG_EXPORT corto_string corto_floatStr(corto_float value);
CORTO_LANG_EXPORT corto_float corto_floatFromStr(corto_float value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_floatCopy(corto_float *dst, corto_float src);
CORTO_LANG_EXPORT corto_int16 corto_floatCompare(corto_float dst, corto_float src);

/* ::corto::lang::float32 */
CORTO_LANG_EXPORT corto_float32* corto_float32Create(corto_float32 value);
CORTO_LANG_EXPORT corto_float32* corto_float32CreateChild(corto_object _parent, corto_string _name, corto_float32 value);
CORTO_LANG_EXPORT corto_int16 corto_float32Update(corto_float32* _this, corto_float32 value);

CORTO_LANG_EXPORT corto_float32* corto_float32Declare(void);
CORTO_LANG_EXPORT corto_float32* corto_float32DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_float32Define(corto_float32* _this, corto_float32 value);
CORTO_LANG_EXPORT void corto_float32Set(corto_float32* _this, corto_float32 value);
CORTO_LANG_EXPORT corto_string corto_float32Str(corto_float32 value);
CORTO_LANG_EXPORT corto_float32* corto_float32FromStr(corto_float32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_float32Copy(corto_float32* *dst, corto_float32* src);
CORTO_LANG_EXPORT corto_int16 corto_float32Compare(corto_float32* dst, corto_float32* src);

CORTO_LANG_EXPORT corto_int16 corto_float32Init(corto_float32* value);
CORTO_LANG_EXPORT corto_int16 corto_float32Deinit(corto_float32* value);

/* ::corto::lang::float64 */
CORTO_LANG_EXPORT corto_float64* corto_float64Create(corto_float64 value);
CORTO_LANG_EXPORT corto_float64* corto_float64CreateChild(corto_object _parent, corto_string _name, corto_float64 value);
CORTO_LANG_EXPORT corto_int16 corto_float64Update(corto_float64* _this, corto_float64 value);

CORTO_LANG_EXPORT corto_float64* corto_float64Declare(void);
CORTO_LANG_EXPORT corto_float64* corto_float64DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_float64Define(corto_float64* _this, corto_float64 value);
CORTO_LANG_EXPORT void corto_float64Set(corto_float64* _this, corto_float64 value);
CORTO_LANG_EXPORT corto_string corto_float64Str(corto_float64 value);
CORTO_LANG_EXPORT corto_float64* corto_float64FromStr(corto_float64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_float64Copy(corto_float64* *dst, corto_float64* src);
CORTO_LANG_EXPORT corto_int16 corto_float64Compare(corto_float64* dst, corto_float64* src);

CORTO_LANG_EXPORT corto_int16 corto_float64Init(corto_float64* value);
CORTO_LANG_EXPORT corto_int16 corto_float64Deinit(corto_float64* value);

/* ::corto::lang::function */
CORTO_LANG_EXPORT corto_function corto_functionCreate(corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_function corto_functionCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_int16 corto_functionUpdate(corto_function _this, corto_type returnType, corto_bool returnsReference);

CORTO_LANG_EXPORT corto_function corto_functionDeclare(void);
CORTO_LANG_EXPORT corto_function corto_functionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_functionDefine(corto_function _this, corto_type returnType, corto_bool returnsReference, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT void corto_functionSet(corto_function _this, corto_type returnType, corto_bool returnsReference);
CORTO_LANG_EXPORT corto_string corto_functionStr(corto_function value);
CORTO_LANG_EXPORT corto_function corto_functionFromStr(corto_function value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_functionCopy(corto_function *dst, corto_function src);
CORTO_LANG_EXPORT corto_int16 corto_functionCompare(corto_function dst, corto_function src);

/* ::corto::lang::initAction */
CORTO_LANG_EXPORT corto_initAction* corto_initActionCreate(corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_initAction* corto_initActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_int16 corto_initActionUpdate(corto_initAction* _this, corto_object instance, corto_function procedure);

CORTO_LANG_EXPORT corto_initAction* corto_initActionDeclare(void);
CORTO_LANG_EXPORT corto_initAction* corto_initActionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_initActionDefine(corto_initAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT void corto_initActionSet(corto_initAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_string corto_initActionStr(corto_initAction* value);
CORTO_LANG_EXPORT corto_initAction* corto_initActionFromStr(corto_initAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_initActionCopy(corto_initAction* *dst, corto_initAction* src);
CORTO_LANG_EXPORT corto_int16 corto_initActionCompare(corto_initAction* dst, corto_initAction* src);

CORTO_LANG_EXPORT corto_int16 corto_initActionInit(corto_initAction* value);
CORTO_LANG_EXPORT corto_int16 corto_initActionDeinit(corto_initAction* value);

corto_int16 corto_initActionCall(corto_initAction *_delegate, corto_int16* _result);
/* ::corto::lang::int */
CORTO_LANG_EXPORT corto_int corto_intCreate(corto_width width, corto_int64 min, corto_int64 max);
CORTO_LANG_EXPORT corto_int corto_intCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_int64 min, corto_int64 max);
CORTO_LANG_EXPORT corto_int16 corto_intUpdate(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);

CORTO_LANG_EXPORT corto_int corto_intDeclare(void);
CORTO_LANG_EXPORT corto_int corto_intDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_intDefine(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
CORTO_LANG_EXPORT void corto_intSet(corto_int _this, corto_width width, corto_int64 min, corto_int64 max);
CORTO_LANG_EXPORT corto_string corto_intStr(corto_int value);
CORTO_LANG_EXPORT corto_int corto_intFromStr(corto_int value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_intCopy(corto_int *dst, corto_int src);
CORTO_LANG_EXPORT corto_int16 corto_intCompare(corto_int dst, corto_int src);

/* ::corto::lang::int16 */
CORTO_LANG_EXPORT corto_int16* corto_int16Create(corto_int16 value);
CORTO_LANG_EXPORT corto_int16* corto_int16CreateChild(corto_object _parent, corto_string _name, corto_int16 value);
CORTO_LANG_EXPORT corto_int16 corto_int16Update(corto_int16* _this, corto_int16 value);

CORTO_LANG_EXPORT corto_int16* corto_int16Declare(void);
CORTO_LANG_EXPORT corto_int16* corto_int16DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_int16Define(corto_int16* _this, corto_int16 value);
CORTO_LANG_EXPORT void corto_int16Set(corto_int16* _this, corto_int16 value);
CORTO_LANG_EXPORT corto_string corto_int16Str(corto_int16 value);
CORTO_LANG_EXPORT corto_int16* corto_int16FromStr(corto_int16* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_int16Copy(corto_int16* *dst, corto_int16* src);
CORTO_LANG_EXPORT corto_int16 corto_int16Compare(corto_int16* dst, corto_int16* src);

CORTO_LANG_EXPORT corto_int16 corto_int16Init(corto_int16* value);
CORTO_LANG_EXPORT corto_int16 corto_int16Deinit(corto_int16* value);

/* ::corto::lang::int32 */
CORTO_LANG_EXPORT corto_int32* corto_int32Create(corto_int32 value);
CORTO_LANG_EXPORT corto_int32* corto_int32CreateChild(corto_object _parent, corto_string _name, corto_int32 value);
CORTO_LANG_EXPORT corto_int16 corto_int32Update(corto_int32* _this, corto_int32 value);

CORTO_LANG_EXPORT corto_int32* corto_int32Declare(void);
CORTO_LANG_EXPORT corto_int32* corto_int32DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_int32Define(corto_int32* _this, corto_int32 value);
CORTO_LANG_EXPORT void corto_int32Set(corto_int32* _this, corto_int32 value);
CORTO_LANG_EXPORT corto_string corto_int32Str(corto_int32 value);
CORTO_LANG_EXPORT corto_int32* corto_int32FromStr(corto_int32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_int32Copy(corto_int32* *dst, corto_int32* src);
CORTO_LANG_EXPORT corto_int16 corto_int32Compare(corto_int32* dst, corto_int32* src);

CORTO_LANG_EXPORT corto_int16 corto_int32Init(corto_int32* value);
CORTO_LANG_EXPORT corto_int16 corto_int32Deinit(corto_int32* value);

/* ::corto::lang::int64 */
CORTO_LANG_EXPORT corto_int64* corto_int64Create(corto_int64 value);
CORTO_LANG_EXPORT corto_int64* corto_int64CreateChild(corto_object _parent, corto_string _name, corto_int64 value);
CORTO_LANG_EXPORT corto_int16 corto_int64Update(corto_int64* _this, corto_int64 value);

CORTO_LANG_EXPORT corto_int64* corto_int64Declare(void);
CORTO_LANG_EXPORT corto_int64* corto_int64DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_int64Define(corto_int64* _this, corto_int64 value);
CORTO_LANG_EXPORT void corto_int64Set(corto_int64* _this, corto_int64 value);
CORTO_LANG_EXPORT corto_string corto_int64Str(corto_int64 value);
CORTO_LANG_EXPORT corto_int64* corto_int64FromStr(corto_int64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_int64Copy(corto_int64* *dst, corto_int64* src);
CORTO_LANG_EXPORT corto_int16 corto_int64Compare(corto_int64* dst, corto_int64* src);

CORTO_LANG_EXPORT corto_int16 corto_int64Init(corto_int64* value);
CORTO_LANG_EXPORT corto_int16 corto_int64Deinit(corto_int64* value);

/* ::corto::lang::int8 */
CORTO_LANG_EXPORT corto_int8* corto_int8Create(corto_int8 value);
CORTO_LANG_EXPORT corto_int8* corto_int8CreateChild(corto_object _parent, corto_string _name, corto_int8 value);
CORTO_LANG_EXPORT corto_int16 corto_int8Update(corto_int8* _this, corto_int8 value);

CORTO_LANG_EXPORT corto_int8* corto_int8Declare(void);
CORTO_LANG_EXPORT corto_int8* corto_int8DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_int8Define(corto_int8* _this, corto_int8 value);
CORTO_LANG_EXPORT void corto_int8Set(corto_int8* _this, corto_int8 value);
CORTO_LANG_EXPORT corto_string corto_int8Str(corto_int8 value);
CORTO_LANG_EXPORT corto_int8* corto_int8FromStr(corto_int8* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_int8Copy(corto_int8* *dst, corto_int8* src);
CORTO_LANG_EXPORT corto_int16 corto_int8Compare(corto_int8* dst, corto_int8* src);

CORTO_LANG_EXPORT corto_int16 corto_int8Init(corto_int8* value);
CORTO_LANG_EXPORT corto_int16 corto_int8Deinit(corto_int8* value);

/* ::corto::lang::interface */
CORTO_LANG_EXPORT corto_interface corto_interfaceCreate(corto_interface base);
CORTO_LANG_EXPORT corto_interface corto_interfaceCreateChild(corto_object _parent, corto_string _name, corto_interface base);
CORTO_LANG_EXPORT corto_int16 corto_interfaceUpdate(corto_interface _this, corto_interface base);

CORTO_LANG_EXPORT corto_interface corto_interfaceDeclare(void);
CORTO_LANG_EXPORT corto_interface corto_interfaceDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceDefine(corto_interface _this, corto_interface base);
CORTO_LANG_EXPORT void corto_interfaceSet(corto_interface _this, corto_interface base);
CORTO_LANG_EXPORT corto_string corto_interfaceStr(corto_interface value);
CORTO_LANG_EXPORT corto_interface corto_interfaceFromStr(corto_interface value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_interfaceCopy(corto_interface *dst, corto_interface src);
CORTO_LANG_EXPORT corto_int16 corto_interfaceCompare(corto_interface dst, corto_interface src);

/* ::corto::lang::interfaceseq */
CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqCreate(void);
CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceseqUpdate(corto_interfaceseq* _this, corto_interfaceseq value);

CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqDeclare(void);
CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceseqDefine(corto_interfaceseq* _this, corto_interfaceseq value);
CORTO_LANG_EXPORT void corto_interfaceseqSet(corto_interfaceseq* _this, corto_interfaceseq value);
CORTO_LANG_EXPORT corto_string corto_interfaceseqStr(corto_interfaceseq value);
CORTO_LANG_EXPORT corto_interfaceseq* corto_interfaceseqFromStr(corto_interfaceseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_interfaceseqCopy(corto_interfaceseq* *dst, corto_interfaceseq* src);
CORTO_LANG_EXPORT corto_int16 corto_interfaceseqCompare(corto_interfaceseq* dst, corto_interfaceseq* src);

CORTO_LANG_EXPORT corto_int16 corto_interfaceseqInit(corto_interfaceseq* value);
CORTO_LANG_EXPORT corto_int16 corto_interfaceseqDeinit(corto_interfaceseq* value);

/* ::corto::lang::interfaceVector */
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorCreate(corto_interface interface, corto_vtable vector);
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorCreateChild(corto_object _parent, corto_string _name, corto_interface interface, corto_vtable vector);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorUpdate(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);

CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorDeclare(void);
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorDefine(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
CORTO_LANG_EXPORT void corto_interfaceVectorSet(corto_interfaceVector* _this, corto_interface interface, corto_vtable vector);
CORTO_LANG_EXPORT corto_string corto_interfaceVectorStr(corto_interfaceVector* value);
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorFromStr(corto_interfaceVector* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorCopy(corto_interfaceVector* *dst, corto_interfaceVector* src);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorCompare(corto_interfaceVector* dst, corto_interfaceVector* src);

CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorInit(corto_interfaceVector* value);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorDeinit(corto_interfaceVector* value);

/* ::corto::lang::interfaceVectorseq */
CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqCreate(void);
CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqUpdate(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);

CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqDeclare(void);
CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqDefine(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);
CORTO_LANG_EXPORT void corto_interfaceVectorseqSet(corto_interfaceVectorseq* _this, corto_interfaceVectorseq value);
CORTO_LANG_EXPORT corto_string corto_interfaceVectorseqStr(corto_interfaceVectorseq value);
CORTO_LANG_EXPORT corto_interfaceVectorseq* corto_interfaceVectorseqFromStr(corto_interfaceVectorseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqCopy(corto_interfaceVectorseq* *dst, corto_interfaceVectorseq* src);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqCompare(corto_interfaceVectorseq* dst, corto_interfaceVectorseq* src);

CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqInit(corto_interfaceVectorseq* value);
CORTO_LANG_EXPORT corto_int16 corto_interfaceVectorseqDeinit(corto_interfaceVectorseq* value);

/* ::corto::lang::invokeAction */
CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionCreate(corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_int16 corto_invokeActionUpdate(corto_invokeAction* _this, corto_object instance, corto_function procedure);

CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionDeclare(void);
CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_invokeActionDefine(corto_invokeAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT void corto_invokeActionSet(corto_invokeAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_string corto_invokeActionStr(corto_invokeAction* value);
CORTO_LANG_EXPORT corto_invokeAction* corto_invokeActionFromStr(corto_invokeAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_invokeActionCopy(corto_invokeAction* *dst, corto_invokeAction* src);
CORTO_LANG_EXPORT corto_int16 corto_invokeActionCompare(corto_invokeAction* dst, corto_invokeAction* src);

CORTO_LANG_EXPORT corto_int16 corto_invokeActionInit(corto_invokeAction* value);
CORTO_LANG_EXPORT corto_int16 corto_invokeActionDeinit(corto_invokeAction* value);

corto_int16 corto_invokeActionCall(corto_invokeAction *_delegate, corto_object instance, corto_function function, corto_octetseq args);
/* ::corto::lang::invokeEvent */
CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventCreate(corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventCreateChild(corto_object _parent, corto_string _name, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
CORTO_LANG_EXPORT corto_int16 corto_invokeEventUpdate(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);

CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventDeclare(void);
CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_invokeEventDefine(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
CORTO_LANG_EXPORT void corto_invokeEventSet(corto_invokeEvent _this, corto_replicator replicator, corto_object instance, corto_function function, corto_octetseq args);
CORTO_LANG_EXPORT corto_string corto_invokeEventStr(corto_invokeEvent value);
CORTO_LANG_EXPORT corto_invokeEvent corto_invokeEventFromStr(corto_invokeEvent value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_invokeEventCopy(corto_invokeEvent *dst, corto_invokeEvent src);
CORTO_LANG_EXPORT corto_int16 corto_invokeEventCompare(corto_invokeEvent dst, corto_invokeEvent src);

/* ::corto::lang::iterator */
CORTO_LANG_EXPORT corto_iterator corto_iteratorCreate(corto_type elementType);
CORTO_LANG_EXPORT corto_iterator corto_iteratorCreateChild(corto_object _parent, corto_string _name, corto_type elementType);
CORTO_LANG_EXPORT corto_int16 corto_iteratorUpdate(corto_iterator _this, corto_type elementType);

CORTO_LANG_EXPORT corto_iterator corto_iteratorDeclare(void);
CORTO_LANG_EXPORT corto_iterator corto_iteratorDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_iteratorDefine(corto_iterator _this, corto_type elementType);
CORTO_LANG_EXPORT void corto_iteratorSet(corto_iterator _this, corto_type elementType);
CORTO_LANG_EXPORT corto_string corto_iteratorStr(corto_iterator value);
CORTO_LANG_EXPORT corto_iterator corto_iteratorFromStr(corto_iterator value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_iteratorCopy(corto_iterator *dst, corto_iterator src);
CORTO_LANG_EXPORT corto_int16 corto_iteratorCompare(corto_iterator dst, corto_iterator src);

/* ::corto::lang::list */
CORTO_LANG_EXPORT corto_list corto_listCreate(corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_list corto_listCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_int16 corto_listUpdate(corto_list _this, corto_type elementType, corto_uint32 max);

CORTO_LANG_EXPORT corto_list corto_listDeclare(void);
CORTO_LANG_EXPORT corto_list corto_listDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_listDefine(corto_list _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT void corto_listSet(corto_list _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_string corto_listStr(corto_list value);
CORTO_LANG_EXPORT corto_list corto_listFromStr(corto_list value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_listCopy(corto_list *dst, corto_list src);
CORTO_LANG_EXPORT corto_int16 corto_listCompare(corto_list dst, corto_list src);

/* ::corto::lang::map */
CORTO_LANG_EXPORT corto_map corto_mapCreate(corto_type elementType, corto_type keyType, corto_uint32 max);
CORTO_LANG_EXPORT corto_map corto_mapCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_type keyType, corto_uint32 max);
CORTO_LANG_EXPORT corto_int16 corto_mapUpdate(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);

CORTO_LANG_EXPORT corto_map corto_mapDeclare(void);
CORTO_LANG_EXPORT corto_map corto_mapDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_mapDefine(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
CORTO_LANG_EXPORT void corto_mapSet(corto_map _this, corto_type elementType, corto_type keyType, corto_uint32 max);
CORTO_LANG_EXPORT corto_string corto_mapStr(corto_map value);
CORTO_LANG_EXPORT corto_map corto_mapFromStr(corto_map value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_mapCopy(corto_map *dst, corto_map src);
CORTO_LANG_EXPORT corto_int16 corto_mapCompare(corto_map dst, corto_map src);

/* ::corto::lang::member */
CORTO_LANG_EXPORT corto_member corto_memberCreate(corto_type type, corto_modifier modifiers);
CORTO_LANG_EXPORT corto_member corto_memberCreateChild(corto_object _parent, corto_string _name, corto_type type, corto_modifier modifiers);
CORTO_LANG_EXPORT corto_int16 corto_memberUpdate(corto_member _this, corto_type type, corto_modifier modifiers);

CORTO_LANG_EXPORT corto_member corto_memberDeclare(void);
CORTO_LANG_EXPORT corto_member corto_memberDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_memberDefine(corto_member _this, corto_type type, corto_modifier modifiers);
CORTO_LANG_EXPORT void corto_memberSet(corto_member _this, corto_type type, corto_modifier modifiers);
CORTO_LANG_EXPORT corto_string corto_memberStr(corto_member value);
CORTO_LANG_EXPORT corto_member corto_memberFromStr(corto_member value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_memberCopy(corto_member *dst, corto_member src);
CORTO_LANG_EXPORT corto_int16 corto_memberCompare(corto_member dst, corto_member src);

/* ::corto::lang::memberseq */
CORTO_LANG_EXPORT corto_memberseq* corto_memberseqCreate(void);
CORTO_LANG_EXPORT corto_memberseq* corto_memberseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_memberseqUpdate(corto_memberseq* _this, corto_memberseq value);

CORTO_LANG_EXPORT corto_memberseq* corto_memberseqDeclare(void);
CORTO_LANG_EXPORT corto_memberseq* corto_memberseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_memberseqDefine(corto_memberseq* _this, corto_memberseq value);
CORTO_LANG_EXPORT void corto_memberseqSet(corto_memberseq* _this, corto_memberseq value);
CORTO_LANG_EXPORT corto_string corto_memberseqStr(corto_memberseq value);
CORTO_LANG_EXPORT corto_memberseq* corto_memberseqFromStr(corto_memberseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_memberseqCopy(corto_memberseq* *dst, corto_memberseq* src);
CORTO_LANG_EXPORT corto_int16 corto_memberseqCompare(corto_memberseq* dst, corto_memberseq* src);

CORTO_LANG_EXPORT corto_int16 corto_memberseqInit(corto_memberseq* value);
CORTO_LANG_EXPORT corto_int16 corto_memberseqDeinit(corto_memberseq* value);

/* ::corto::lang::metaprocedure */
CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureCreate(corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_int16 corto_metaprocedureUpdate(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly);

CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureDeclare(void);
CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_metaprocedureDefine(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT void corto_metaprocedureSet(corto_metaprocedure _this, corto_type returnType, corto_bool returnsReference, corto_bool referenceOnly);
CORTO_LANG_EXPORT corto_string corto_metaprocedureStr(corto_metaprocedure value);
CORTO_LANG_EXPORT corto_metaprocedure corto_metaprocedureFromStr(corto_metaprocedure value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_metaprocedureCopy(corto_metaprocedure *dst, corto_metaprocedure src);
CORTO_LANG_EXPORT corto_int16 corto_metaprocedureCompare(corto_metaprocedure dst, corto_metaprocedure src);

/* ::corto::lang::method */
CORTO_LANG_EXPORT corto_method corto_methodCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_method corto_methodCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_int16 corto_methodUpdate(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);

CORTO_LANG_EXPORT corto_method corto_methodDeclare(void);
CORTO_LANG_EXPORT corto_method corto_methodDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_methodDefine(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT void corto_methodSet(corto_method _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
CORTO_LANG_EXPORT corto_string corto_methodStr(corto_method value);
CORTO_LANG_EXPORT corto_method corto_methodFromStr(corto_method value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_methodCopy(corto_method *dst, corto_method src);
CORTO_LANG_EXPORT corto_int16 corto_methodCompare(corto_method dst, corto_method src);

/* ::corto::lang::modifier */
CORTO_LANG_EXPORT corto_modifier* corto_modifierCreate(corto_modifier value);
CORTO_LANG_EXPORT corto_modifier* corto_modifierCreateChild(corto_object _parent, corto_string _name, corto_modifier value);
CORTO_LANG_EXPORT corto_int16 corto_modifierUpdate(corto_modifier* _this, corto_modifier value);

CORTO_LANG_EXPORT corto_modifier* corto_modifierDeclare(void);
CORTO_LANG_EXPORT corto_modifier* corto_modifierDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_modifierDefine(corto_modifier* _this, corto_modifier value);
CORTO_LANG_EXPORT void corto_modifierSet(corto_modifier* _this, corto_modifier value);
CORTO_LANG_EXPORT corto_string corto_modifierStr(corto_modifier value);
CORTO_LANG_EXPORT corto_modifier* corto_modifierFromStr(corto_modifier* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_modifierCopy(corto_modifier* *dst, corto_modifier* src);
CORTO_LANG_EXPORT corto_int16 corto_modifierCompare(corto_modifier* dst, corto_modifier* src);

CORTO_LANG_EXPORT corto_int16 corto_modifierInit(corto_modifier* value);
CORTO_LANG_EXPORT corto_int16 corto_modifierDeinit(corto_modifier* value);

/* ::corto::lang::notifyAction */
CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionCreate(corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionCreateChild(corto_object _parent, corto_string _name, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_int16 corto_notifyActionUpdate(corto_notifyAction* _this, corto_object instance, corto_function procedure);

CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionDeclare(void);
CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_notifyActionDefine(corto_notifyAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT void corto_notifyActionSet(corto_notifyAction* _this, corto_object instance, corto_function procedure);
CORTO_LANG_EXPORT corto_string corto_notifyActionStr(corto_notifyAction* value);
CORTO_LANG_EXPORT corto_notifyAction* corto_notifyActionFromStr(corto_notifyAction* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_notifyActionCopy(corto_notifyAction* *dst, corto_notifyAction* src);
CORTO_LANG_EXPORT corto_int16 corto_notifyActionCompare(corto_notifyAction* dst, corto_notifyAction* src);

CORTO_LANG_EXPORT corto_int16 corto_notifyActionInit(corto_notifyAction* value);
CORTO_LANG_EXPORT corto_int16 corto_notifyActionDeinit(corto_notifyAction* value);

corto_int16 corto_notifyActionCall(corto_notifyAction *_delegate, corto_object observable);
/* ::corto::lang::object */
CORTO_LANG_EXPORT corto_object corto_objectCreate(void);
CORTO_LANG_EXPORT corto_object corto_objectCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_objectUpdate(corto_object _this);

/* ::corto::lang::objectseq */
CORTO_LANG_EXPORT corto_objectseq* corto_objectseqCreate(void);
CORTO_LANG_EXPORT corto_objectseq* corto_objectseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_objectseqUpdate(corto_objectseq* _this, corto_objectseq value);

CORTO_LANG_EXPORT corto_objectseq* corto_objectseqDeclare(void);
CORTO_LANG_EXPORT corto_objectseq* corto_objectseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_objectseqDefine(corto_objectseq* _this, corto_objectseq value);
CORTO_LANG_EXPORT void corto_objectseqSet(corto_objectseq* _this, corto_objectseq value);
CORTO_LANG_EXPORT corto_string corto_objectseqStr(corto_objectseq value);
CORTO_LANG_EXPORT corto_objectseq* corto_objectseqFromStr(corto_objectseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_objectseqCopy(corto_objectseq* *dst, corto_objectseq* src);
CORTO_LANG_EXPORT corto_int16 corto_objectseqCompare(corto_objectseq* dst, corto_objectseq* src);

CORTO_LANG_EXPORT corto_int16 corto_objectseqInit(corto_objectseq* value);
CORTO_LANG_EXPORT corto_int16 corto_objectseqDeinit(corto_objectseq* value);

/* ::corto::lang::observableEvent */
CORTO_LANG_EXPORT corto_observableEvent corto_observableEventCreate(corto_observer observer, corto_object me, corto_object source, corto_object observable);
CORTO_LANG_EXPORT corto_observableEvent corto_observableEventCreateChild(corto_object _parent, corto_string _name, corto_observer observer, corto_object me, corto_object source, corto_object observable);
CORTO_LANG_EXPORT corto_int16 corto_observableEventUpdate(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);

CORTO_LANG_EXPORT corto_observableEvent corto_observableEventDeclare(void);
CORTO_LANG_EXPORT corto_observableEvent corto_observableEventDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_observableEventDefine(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);
CORTO_LANG_EXPORT void corto_observableEventSet(corto_observableEvent _this, corto_observer observer, corto_object me, corto_object source, corto_object observable);
CORTO_LANG_EXPORT corto_string corto_observableEventStr(corto_observableEvent value);
CORTO_LANG_EXPORT corto_observableEvent corto_observableEventFromStr(corto_observableEvent value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_observableEventCopy(corto_observableEvent *dst, corto_observableEvent src);
CORTO_LANG_EXPORT corto_int16 corto_observableEventCompare(corto_observableEvent dst, corto_observableEvent src);

/* ::corto::lang::observer */
CORTO_LANG_EXPORT corto_observer corto_observerCreate(corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_observer corto_observerCreateChild(corto_object _parent, corto_string _name, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_int16 corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable);

CORTO_LANG_EXPORT corto_observer corto_observerDeclare(void);
CORTO_LANG_EXPORT corto_observer corto_observerDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT void corto_observerSet(corto_observer _this, corto_eventMask mask, corto_object observable);
CORTO_LANG_EXPORT corto_string corto_observerStr(corto_observer value);
CORTO_LANG_EXPORT corto_observer corto_observerFromStr(corto_observer value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_observerCopy(corto_observer *dst, corto_observer src);
CORTO_LANG_EXPORT corto_int16 corto_observerCompare(corto_observer dst, corto_observer src);

/* ::corto::lang::observerseq */
CORTO_LANG_EXPORT corto_observerseq* corto_observerseqCreate(void);
CORTO_LANG_EXPORT corto_observerseq* corto_observerseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_observerseqUpdate(corto_observerseq* _this, corto_observerseq value);

CORTO_LANG_EXPORT corto_observerseq* corto_observerseqDeclare(void);
CORTO_LANG_EXPORT corto_observerseq* corto_observerseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_observerseqDefine(corto_observerseq* _this, corto_observerseq value);
CORTO_LANG_EXPORT void corto_observerseqSet(corto_observerseq* _this, corto_observerseq value);
CORTO_LANG_EXPORT corto_string corto_observerseqStr(corto_observerseq value);
CORTO_LANG_EXPORT corto_observerseq* corto_observerseqFromStr(corto_observerseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_observerseqCopy(corto_observerseq* *dst, corto_observerseq* src);
CORTO_LANG_EXPORT corto_int16 corto_observerseqCompare(corto_observerseq* dst, corto_observerseq* src);

CORTO_LANG_EXPORT corto_int16 corto_observerseqInit(corto_observerseq* value);
CORTO_LANG_EXPORT corto_int16 corto_observerseqDeinit(corto_observerseq* value);

/* ::corto::lang::octet */
CORTO_LANG_EXPORT corto_octet* corto_octetCreate(corto_octet value);
CORTO_LANG_EXPORT corto_octet* corto_octetCreateChild(corto_object _parent, corto_string _name, corto_octet value);
CORTO_LANG_EXPORT corto_int16 corto_octetUpdate(corto_octet* _this, corto_octet value);

CORTO_LANG_EXPORT corto_octet* corto_octetDeclare(void);
CORTO_LANG_EXPORT corto_octet* corto_octetDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_octetDefine(corto_octet* _this, corto_octet value);
CORTO_LANG_EXPORT void corto_octetSet(corto_octet* _this, corto_octet value);
CORTO_LANG_EXPORT corto_string corto_octetStr(corto_octet value);
CORTO_LANG_EXPORT corto_octet* corto_octetFromStr(corto_octet* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_octetCopy(corto_octet* *dst, corto_octet* src);
CORTO_LANG_EXPORT corto_int16 corto_octetCompare(corto_octet* dst, corto_octet* src);

CORTO_LANG_EXPORT corto_int16 corto_octetInit(corto_octet* value);
CORTO_LANG_EXPORT corto_int16 corto_octetDeinit(corto_octet* value);

/* ::corto::lang::octetseq */
CORTO_LANG_EXPORT corto_octetseq* corto_octetseqCreate(void);
CORTO_LANG_EXPORT corto_octetseq* corto_octetseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_octetseqUpdate(corto_octetseq* _this, corto_octetseq value);

CORTO_LANG_EXPORT corto_octetseq* corto_octetseqDeclare(void);
CORTO_LANG_EXPORT corto_octetseq* corto_octetseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_octetseqDefine(corto_octetseq* _this, corto_octetseq value);
CORTO_LANG_EXPORT void corto_octetseqSet(corto_octetseq* _this, corto_octetseq value);
CORTO_LANG_EXPORT corto_string corto_octetseqStr(corto_octetseq value);
CORTO_LANG_EXPORT corto_octetseq* corto_octetseqFromStr(corto_octetseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_octetseqCopy(corto_octetseq* *dst, corto_octetseq* src);
CORTO_LANG_EXPORT corto_int16 corto_octetseqCompare(corto_octetseq* dst, corto_octetseq* src);

CORTO_LANG_EXPORT corto_int16 corto_octetseqInit(corto_octetseq* value);
CORTO_LANG_EXPORT corto_int16 corto_octetseqDeinit(corto_octetseq* value);

/* ::corto::lang::operatorKind */
CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindCreate(corto_operatorKind value);
CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindCreateChild(corto_object _parent, corto_string _name, corto_operatorKind value);
CORTO_LANG_EXPORT corto_int16 corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value);

CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindDeclare(void);
CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value);
CORTO_LANG_EXPORT void corto_operatorKindSet(corto_operatorKind* _this, corto_operatorKind value);
CORTO_LANG_EXPORT corto_string corto_operatorKindStr(corto_operatorKind value);
CORTO_LANG_EXPORT corto_operatorKind* corto_operatorKindFromStr(corto_operatorKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_operatorKindCopy(corto_operatorKind* *dst, corto_operatorKind* src);
CORTO_LANG_EXPORT corto_int16 corto_operatorKindCompare(corto_operatorKind* dst, corto_operatorKind* src);

CORTO_LANG_EXPORT corto_int16 corto_operatorKindInit(corto_operatorKind* value);
CORTO_LANG_EXPORT corto_int16 corto_operatorKindDeinit(corto_operatorKind* value);

/* ::corto::lang::package */
CORTO_LANG_EXPORT corto_package corto_packageCreate(corto_string url);
CORTO_LANG_EXPORT corto_package corto_packageCreateChild(corto_object _parent, corto_string _name, corto_string url);
CORTO_LANG_EXPORT corto_int16 corto_packageUpdate(corto_package _this, corto_string url);

CORTO_LANG_EXPORT corto_package corto_packageDeclare(void);
CORTO_LANG_EXPORT corto_package corto_packageDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_packageDefine(corto_package _this, corto_string url);
CORTO_LANG_EXPORT void corto_packageSet(corto_package _this, corto_string url);
CORTO_LANG_EXPORT corto_string corto_packageStr(corto_package value);
CORTO_LANG_EXPORT corto_package corto_packageFromStr(corto_package value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_packageCopy(corto_package *dst, corto_package src);
CORTO_LANG_EXPORT corto_int16 corto_packageCompare(corto_package dst, corto_package src);

/* ::corto::lang::parameter */
CORTO_LANG_EXPORT corto_parameter* corto_parameterCreate(corto_string name, corto_type type, corto_bool passByReference);
CORTO_LANG_EXPORT corto_parameter* corto_parameterCreateChild(corto_object _parent, corto_string _name, corto_string name, corto_type type, corto_bool passByReference);
CORTO_LANG_EXPORT corto_int16 corto_parameterUpdate(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);

CORTO_LANG_EXPORT corto_parameter* corto_parameterDeclare(void);
CORTO_LANG_EXPORT corto_parameter* corto_parameterDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_parameterDefine(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
CORTO_LANG_EXPORT void corto_parameterSet(corto_parameter* _this, corto_string name, corto_type type, corto_bool passByReference);
CORTO_LANG_EXPORT corto_string corto_parameterStr(corto_parameter* value);
CORTO_LANG_EXPORT corto_parameter* corto_parameterFromStr(corto_parameter* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_parameterCopy(corto_parameter* *dst, corto_parameter* src);
CORTO_LANG_EXPORT corto_int16 corto_parameterCompare(corto_parameter* dst, corto_parameter* src);

CORTO_LANG_EXPORT corto_int16 corto_parameterInit(corto_parameter* value);
CORTO_LANG_EXPORT corto_int16 corto_parameterDeinit(corto_parameter* value);

/* ::corto::lang::parameterseq */
CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqCreate(void);
CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_parameterseqUpdate(corto_parameterseq* _this, corto_parameterseq value);

CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqDeclare(void);
CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_parameterseqDefine(corto_parameterseq* _this, corto_parameterseq value);
CORTO_LANG_EXPORT void corto_parameterseqSet(corto_parameterseq* _this, corto_parameterseq value);
CORTO_LANG_EXPORT corto_string corto_parameterseqStr(corto_parameterseq value);
CORTO_LANG_EXPORT corto_parameterseq* corto_parameterseqFromStr(corto_parameterseq* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_parameterseqCopy(corto_parameterseq* *dst, corto_parameterseq* src);
CORTO_LANG_EXPORT corto_int16 corto_parameterseqCompare(corto_parameterseq* dst, corto_parameterseq* src);

CORTO_LANG_EXPORT corto_int16 corto_parameterseqInit(corto_parameterseq* value);
CORTO_LANG_EXPORT corto_int16 corto_parameterseqDeinit(corto_parameterseq* value);

/* ::corto::lang::primitive */
CORTO_LANG_EXPORT corto_primitive corto_primitiveCreate(corto_width width);
CORTO_LANG_EXPORT corto_primitive corto_primitiveCreateChild(corto_object _parent, corto_string _name, corto_width width);
CORTO_LANG_EXPORT corto_int16 corto_primitiveUpdate(corto_primitive _this, corto_width width);

CORTO_LANG_EXPORT corto_primitive corto_primitiveDeclare(void);
CORTO_LANG_EXPORT corto_primitive corto_primitiveDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_primitiveDefine(corto_primitive _this, corto_width width);
CORTO_LANG_EXPORT void corto_primitiveSet(corto_primitive _this, corto_width width);
CORTO_LANG_EXPORT corto_string corto_primitiveStr(corto_primitive value);
CORTO_LANG_EXPORT corto_primitive corto_primitiveFromStr(corto_primitive value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_primitiveCopy(corto_primitive *dst, corto_primitive src);
CORTO_LANG_EXPORT corto_int16 corto_primitiveCompare(corto_primitive dst, corto_primitive src);

/* ::corto::lang::primitiveKind */
CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindCreate(corto_primitiveKind value);
CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindCreateChild(corto_object _parent, corto_string _name, corto_primitiveKind value);
CORTO_LANG_EXPORT corto_int16 corto_primitiveKindUpdate(corto_primitiveKind* _this, corto_primitiveKind value);

CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindDeclare(void);
CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_primitiveKindDefine(corto_primitiveKind* _this, corto_primitiveKind value);
CORTO_LANG_EXPORT void corto_primitiveKindSet(corto_primitiveKind* _this, corto_primitiveKind value);
CORTO_LANG_EXPORT corto_string corto_primitiveKindStr(corto_primitiveKind value);
CORTO_LANG_EXPORT corto_primitiveKind* corto_primitiveKindFromStr(corto_primitiveKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_primitiveKindCopy(corto_primitiveKind* *dst, corto_primitiveKind* src);
CORTO_LANG_EXPORT corto_int16 corto_primitiveKindCompare(corto_primitiveKind* dst, corto_primitiveKind* src);

CORTO_LANG_EXPORT corto_int16 corto_primitiveKindInit(corto_primitiveKind* value);
CORTO_LANG_EXPORT corto_int16 corto_primitiveKindDeinit(corto_primitiveKind* value);

/* ::corto::lang::procedure */
CORTO_LANG_EXPORT corto_procedure corto_procedureCreate(corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
CORTO_LANG_EXPORT corto_procedure corto_procedureCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
CORTO_LANG_EXPORT corto_int16 corto_procedureUpdate(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);

CORTO_LANG_EXPORT corto_procedure corto_procedureDeclare(void);
CORTO_LANG_EXPORT corto_procedure corto_procedureDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_procedureDefine(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
CORTO_LANG_EXPORT void corto_procedureSet(corto_procedure _this, corto_interface base, corto_modifier baseAccess, corto_procedureKind kind);
CORTO_LANG_EXPORT corto_string corto_procedureStr(corto_procedure value);
CORTO_LANG_EXPORT corto_procedure corto_procedureFromStr(corto_procedure value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_procedureCopy(corto_procedure *dst, corto_procedure src);
CORTO_LANG_EXPORT corto_int16 corto_procedureCompare(corto_procedure dst, corto_procedure src);

/* ::corto::lang::procedureKind */
CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindCreate(corto_procedureKind value);
CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindCreateChild(corto_object _parent, corto_string _name, corto_procedureKind value);
CORTO_LANG_EXPORT corto_int16 corto_procedureKindUpdate(corto_procedureKind* _this, corto_procedureKind value);

CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindDeclare(void);
CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_procedureKindDefine(corto_procedureKind* _this, corto_procedureKind value);
CORTO_LANG_EXPORT void corto_procedureKindSet(corto_procedureKind* _this, corto_procedureKind value);
CORTO_LANG_EXPORT corto_string corto_procedureKindStr(corto_procedureKind value);
CORTO_LANG_EXPORT corto_procedureKind* corto_procedureKindFromStr(corto_procedureKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_procedureKindCopy(corto_procedureKind* *dst, corto_procedureKind* src);
CORTO_LANG_EXPORT corto_int16 corto_procedureKindCompare(corto_procedureKind* dst, corto_procedureKind* src);

CORTO_LANG_EXPORT corto_int16 corto_procedureKindInit(corto_procedureKind* value);
CORTO_LANG_EXPORT corto_int16 corto_procedureKindDeinit(corto_procedureKind* value);

/* ::corto::lang::query */
CORTO_LANG_EXPORT corto_query corto_queryCreate(corto_object from, corto_eventMask mask);
CORTO_LANG_EXPORT corto_query corto_queryCreateChild(corto_object _parent, corto_string _name, corto_object from, corto_eventMask mask);
CORTO_LANG_EXPORT corto_int16 corto_queryUpdate(corto_query _this, corto_object from, corto_eventMask mask);

CORTO_LANG_EXPORT corto_query corto_queryDeclare(void);
CORTO_LANG_EXPORT corto_query corto_queryDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_queryDefine(corto_query _this, corto_object from, corto_eventMask mask);
CORTO_LANG_EXPORT void corto_querySet(corto_query _this, corto_object from, corto_eventMask mask);
CORTO_LANG_EXPORT corto_string corto_queryStr(corto_query value);
CORTO_LANG_EXPORT corto_query corto_queryFromStr(corto_query value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_queryCopy(corto_query *dst, corto_query src);
CORTO_LANG_EXPORT corto_int16 corto_queryCompare(corto_query dst, corto_query src);

/* ::corto::lang::replicator */
CORTO_LANG_EXPORT corto_replicator corto_replicatorCreate(corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
CORTO_LANG_EXPORT corto_replicator corto_replicatorCreateChild(corto_object _parent, corto_string _name, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
CORTO_LANG_EXPORT corto_int16 corto_replicatorUpdate(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);

CORTO_LANG_EXPORT corto_replicator corto_replicatorDeclare(void);
CORTO_LANG_EXPORT corto_replicator corto_replicatorDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_replicatorDefine(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
CORTO_LANG_EXPORT void corto_replicatorSet(corto_replicator _this, corto_object mount, corto_query query, corto_notifyAction onDeclare, corto_notifyAction onUpdate, corto_notifyAction onDelete, corto_invokeAction onInvoke);
CORTO_LANG_EXPORT corto_string corto_replicatorStr(corto_replicator value);
CORTO_LANG_EXPORT corto_replicator corto_replicatorFromStr(corto_replicator value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_replicatorCopy(corto_replicator *dst, corto_replicator src);
CORTO_LANG_EXPORT corto_int16 corto_replicatorCompare(corto_replicator dst, corto_replicator src);

/* ::corto::lang::sequence */
CORTO_LANG_EXPORT corto_sequence corto_sequenceCreate(corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_sequence corto_sequenceCreateChild(corto_object _parent, corto_string _name, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_int16 corto_sequenceUpdate(corto_sequence _this, corto_type elementType, corto_uint32 max);

CORTO_LANG_EXPORT corto_sequence corto_sequenceDeclare(void);
CORTO_LANG_EXPORT corto_sequence corto_sequenceDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_sequenceDefine(corto_sequence _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT void corto_sequenceSet(corto_sequence _this, corto_type elementType, corto_uint32 max);
CORTO_LANG_EXPORT corto_string corto_sequenceStr(corto_sequence value);
CORTO_LANG_EXPORT corto_sequence corto_sequenceFromStr(corto_sequence value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_sequenceCopy(corto_sequence *dst, corto_sequence src);
CORTO_LANG_EXPORT corto_int16 corto_sequenceCompare(corto_sequence dst, corto_sequence src);

/* ::corto::lang::state */
CORTO_LANG_EXPORT corto_state* corto_stateCreate(corto_state value);
CORTO_LANG_EXPORT corto_state* corto_stateCreateChild(corto_object _parent, corto_string _name, corto_state value);
CORTO_LANG_EXPORT corto_int16 corto_stateUpdate(corto_state* _this, corto_state value);

CORTO_LANG_EXPORT corto_state* corto_stateDeclare(void);
CORTO_LANG_EXPORT corto_state* corto_stateDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_stateDefine(corto_state* _this, corto_state value);
CORTO_LANG_EXPORT void corto_stateSet(corto_state* _this, corto_state value);
CORTO_LANG_EXPORT corto_string corto_stateStr(corto_state value);
CORTO_LANG_EXPORT corto_state* corto_stateFromStr(corto_state* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_stateCopy(corto_state* *dst, corto_state* src);
CORTO_LANG_EXPORT corto_int16 corto_stateCompare(corto_state* dst, corto_state* src);

CORTO_LANG_EXPORT corto_int16 corto_stateInit(corto_state* value);
CORTO_LANG_EXPORT corto_int16 corto_stateDeinit(corto_state* value);

/* ::corto::lang::string */
CORTO_LANG_EXPORT corto_string* corto_stringCreate(corto_string value);
CORTO_LANG_EXPORT corto_string* corto_stringCreateChild(corto_object _parent, corto_string _name, corto_string value);
CORTO_LANG_EXPORT corto_int16 corto_stringUpdate(corto_string* _this, corto_string value);

CORTO_LANG_EXPORT corto_string* corto_stringDeclare(void);
CORTO_LANG_EXPORT corto_string* corto_stringDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_stringDefine(corto_string* _this, corto_string value);
CORTO_LANG_EXPORT void corto_stringSet(corto_string* _this, corto_string value);
CORTO_LANG_EXPORT corto_string corto_stringStr(corto_string value);
CORTO_LANG_EXPORT corto_string* corto_stringFromStr(corto_string* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_stringCopy(corto_string* *dst, corto_string* src);
CORTO_LANG_EXPORT corto_int16 corto_stringCompare(corto_string* dst, corto_string* src);

CORTO_LANG_EXPORT corto_int16 corto_stringInit(corto_string* value);
CORTO_LANG_EXPORT corto_int16 corto_stringDeinit(corto_string* value);

/* ::corto::lang::struct */
CORTO_LANG_EXPORT corto_struct corto_structCreate(corto_interface base, corto_modifier baseAccess);
CORTO_LANG_EXPORT corto_struct corto_structCreateChild(corto_object _parent, corto_string _name, corto_interface base, corto_modifier baseAccess);
CORTO_LANG_EXPORT corto_int16 corto_structUpdate(corto_struct _this, corto_interface base, corto_modifier baseAccess);

CORTO_LANG_EXPORT corto_struct corto_structDeclare(void);
CORTO_LANG_EXPORT corto_struct corto_structDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_structDefine(corto_struct _this, corto_interface base, corto_modifier baseAccess);
CORTO_LANG_EXPORT void corto_structSet(corto_struct _this, corto_interface base, corto_modifier baseAccess);
CORTO_LANG_EXPORT corto_string corto_structStr(corto_struct value);
CORTO_LANG_EXPORT corto_struct corto_structFromStr(corto_struct value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_structCopy(corto_struct *dst, corto_struct src);
CORTO_LANG_EXPORT corto_int16 corto_structCompare(corto_struct dst, corto_struct src);

/* ::corto::lang::text */
CORTO_LANG_EXPORT corto_text corto_textCreate(corto_width charWidth, corto_uint64 length);
CORTO_LANG_EXPORT corto_text corto_textCreateChild(corto_object _parent, corto_string _name, corto_width charWidth, corto_uint64 length);
CORTO_LANG_EXPORT corto_int16 corto_textUpdate(corto_text _this, corto_width charWidth, corto_uint64 length);

CORTO_LANG_EXPORT corto_text corto_textDeclare(void);
CORTO_LANG_EXPORT corto_text corto_textDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_textDefine(corto_text _this, corto_width charWidth, corto_uint64 length);
CORTO_LANG_EXPORT void corto_textSet(corto_text _this, corto_width charWidth, corto_uint64 length);
CORTO_LANG_EXPORT corto_string corto_textStr(corto_text value);
CORTO_LANG_EXPORT corto_text corto_textFromStr(corto_text value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_textCopy(corto_text *dst, corto_text src);
CORTO_LANG_EXPORT corto_int16 corto_textCompare(corto_text dst, corto_text src);

/* ::corto::lang::type */
CORTO_LANG_EXPORT corto_type corto_typeCreate(corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
CORTO_LANG_EXPORT corto_type corto_typeCreateChild(corto_object _parent, corto_string _name, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
CORTO_LANG_EXPORT corto_int16 corto_typeUpdate(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);

CORTO_LANG_EXPORT corto_type corto_typeDeclare(void);
CORTO_LANG_EXPORT corto_type corto_typeDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_typeDefine(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
CORTO_LANG_EXPORT void corto_typeSet(corto_type _this, corto_type parentType, corto_state parentState, corto_type defaultType, corto_type defaultProcedureType);
CORTO_LANG_EXPORT corto_string corto_typeStr(corto_type value);
CORTO_LANG_EXPORT corto_type corto_typeFromStr(corto_type value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_typeCopy(corto_type *dst, corto_type src);
CORTO_LANG_EXPORT corto_int16 corto_typeCompare(corto_type dst, corto_type src);

/* ::corto::lang::typeKind */
CORTO_LANG_EXPORT corto_typeKind* corto_typeKindCreate(corto_typeKind value);
CORTO_LANG_EXPORT corto_typeKind* corto_typeKindCreateChild(corto_object _parent, corto_string _name, corto_typeKind value);
CORTO_LANG_EXPORT corto_int16 corto_typeKindUpdate(corto_typeKind* _this, corto_typeKind value);

CORTO_LANG_EXPORT corto_typeKind* corto_typeKindDeclare(void);
CORTO_LANG_EXPORT corto_typeKind* corto_typeKindDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_typeKindDefine(corto_typeKind* _this, corto_typeKind value);
CORTO_LANG_EXPORT void corto_typeKindSet(corto_typeKind* _this, corto_typeKind value);
CORTO_LANG_EXPORT corto_string corto_typeKindStr(corto_typeKind value);
CORTO_LANG_EXPORT corto_typeKind* corto_typeKindFromStr(corto_typeKind* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_typeKindCopy(corto_typeKind* *dst, corto_typeKind* src);
CORTO_LANG_EXPORT corto_int16 corto_typeKindCompare(corto_typeKind* dst, corto_typeKind* src);

CORTO_LANG_EXPORT corto_int16 corto_typeKindInit(corto_typeKind* value);
CORTO_LANG_EXPORT corto_int16 corto_typeKindDeinit(corto_typeKind* value);

/* ::corto::lang::uint */
CORTO_LANG_EXPORT corto_uint corto_uintCreate(corto_width width, corto_uint64 min, corto_uint64 max);
CORTO_LANG_EXPORT corto_uint corto_uintCreateChild(corto_object _parent, corto_string _name, corto_width width, corto_uint64 min, corto_uint64 max);
CORTO_LANG_EXPORT corto_int16 corto_uintUpdate(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);

CORTO_LANG_EXPORT corto_uint corto_uintDeclare(void);
CORTO_LANG_EXPORT corto_uint corto_uintDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_uintDefine(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
CORTO_LANG_EXPORT void corto_uintSet(corto_uint _this, corto_width width, corto_uint64 min, corto_uint64 max);
CORTO_LANG_EXPORT corto_string corto_uintStr(corto_uint value);
CORTO_LANG_EXPORT corto_uint corto_uintFromStr(corto_uint value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_uintCopy(corto_uint *dst, corto_uint src);
CORTO_LANG_EXPORT corto_int16 corto_uintCompare(corto_uint dst, corto_uint src);

/* ::corto::lang::uint16 */
CORTO_LANG_EXPORT corto_uint16* corto_uint16Create(corto_uint16 value);
CORTO_LANG_EXPORT corto_uint16* corto_uint16CreateChild(corto_object _parent, corto_string _name, corto_uint16 value);
CORTO_LANG_EXPORT corto_int16 corto_uint16Update(corto_uint16* _this, corto_uint16 value);

CORTO_LANG_EXPORT corto_uint16* corto_uint16Declare(void);
CORTO_LANG_EXPORT corto_uint16* corto_uint16DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_uint16Define(corto_uint16* _this, corto_uint16 value);
CORTO_LANG_EXPORT void corto_uint16Set(corto_uint16* _this, corto_uint16 value);
CORTO_LANG_EXPORT corto_string corto_uint16Str(corto_uint16 value);
CORTO_LANG_EXPORT corto_uint16* corto_uint16FromStr(corto_uint16* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_uint16Copy(corto_uint16* *dst, corto_uint16* src);
CORTO_LANG_EXPORT corto_int16 corto_uint16Compare(corto_uint16* dst, corto_uint16* src);

CORTO_LANG_EXPORT corto_int16 corto_uint16Init(corto_uint16* value);
CORTO_LANG_EXPORT corto_int16 corto_uint16Deinit(corto_uint16* value);

/* ::corto::lang::uint32 */
CORTO_LANG_EXPORT corto_uint32* corto_uint32Create(corto_uint32 value);
CORTO_LANG_EXPORT corto_uint32* corto_uint32CreateChild(corto_object _parent, corto_string _name, corto_uint32 value);
CORTO_LANG_EXPORT corto_int16 corto_uint32Update(corto_uint32* _this, corto_uint32 value);

CORTO_LANG_EXPORT corto_uint32* corto_uint32Declare(void);
CORTO_LANG_EXPORT corto_uint32* corto_uint32DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_uint32Define(corto_uint32* _this, corto_uint32 value);
CORTO_LANG_EXPORT void corto_uint32Set(corto_uint32* _this, corto_uint32 value);
CORTO_LANG_EXPORT corto_string corto_uint32Str(corto_uint32 value);
CORTO_LANG_EXPORT corto_uint32* corto_uint32FromStr(corto_uint32* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_uint32Copy(corto_uint32* *dst, corto_uint32* src);
CORTO_LANG_EXPORT corto_int16 corto_uint32Compare(corto_uint32* dst, corto_uint32* src);

CORTO_LANG_EXPORT corto_int16 corto_uint32Init(corto_uint32* value);
CORTO_LANG_EXPORT corto_int16 corto_uint32Deinit(corto_uint32* value);

/* ::corto::lang::uint64 */
CORTO_LANG_EXPORT corto_uint64* corto_uint64Create(corto_uint64 value);
CORTO_LANG_EXPORT corto_uint64* corto_uint64CreateChild(corto_object _parent, corto_string _name, corto_uint64 value);
CORTO_LANG_EXPORT corto_int16 corto_uint64Update(corto_uint64* _this, corto_uint64 value);

CORTO_LANG_EXPORT corto_uint64* corto_uint64Declare(void);
CORTO_LANG_EXPORT corto_uint64* corto_uint64DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_uint64Define(corto_uint64* _this, corto_uint64 value);
CORTO_LANG_EXPORT void corto_uint64Set(corto_uint64* _this, corto_uint64 value);
CORTO_LANG_EXPORT corto_string corto_uint64Str(corto_uint64 value);
CORTO_LANG_EXPORT corto_uint64* corto_uint64FromStr(corto_uint64* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_uint64Copy(corto_uint64* *dst, corto_uint64* src);
CORTO_LANG_EXPORT corto_int16 corto_uint64Compare(corto_uint64* dst, corto_uint64* src);

CORTO_LANG_EXPORT corto_int16 corto_uint64Init(corto_uint64* value);
CORTO_LANG_EXPORT corto_int16 corto_uint64Deinit(corto_uint64* value);

/* ::corto::lang::uint8 */
CORTO_LANG_EXPORT corto_uint8* corto_uint8Create(corto_uint8 value);
CORTO_LANG_EXPORT corto_uint8* corto_uint8CreateChild(corto_object _parent, corto_string _name, corto_uint8 value);
CORTO_LANG_EXPORT corto_int16 corto_uint8Update(corto_uint8* _this, corto_uint8 value);

CORTO_LANG_EXPORT corto_uint8* corto_uint8Declare(void);
CORTO_LANG_EXPORT corto_uint8* corto_uint8DeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_uint8Define(corto_uint8* _this, corto_uint8 value);
CORTO_LANG_EXPORT void corto_uint8Set(corto_uint8* _this, corto_uint8 value);
CORTO_LANG_EXPORT corto_string corto_uint8Str(corto_uint8 value);
CORTO_LANG_EXPORT corto_uint8* corto_uint8FromStr(corto_uint8* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_uint8Copy(corto_uint8* *dst, corto_uint8* src);
CORTO_LANG_EXPORT corto_int16 corto_uint8Compare(corto_uint8* dst, corto_uint8* src);

CORTO_LANG_EXPORT corto_int16 corto_uint8Init(corto_uint8* value);
CORTO_LANG_EXPORT corto_int16 corto_uint8Deinit(corto_uint8* value);

/* ::corto::lang::virtual */
CORTO_LANG_EXPORT corto_virtual corto_virtualCreate(corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_virtual corto_virtualCreateChild(corto_object _parent, corto_string _name, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT corto_int16 corto_virtualUpdate(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);

CORTO_LANG_EXPORT corto_virtual corto_virtualDeclare(void);
CORTO_LANG_EXPORT corto_virtual corto_virtualDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_virtualDefine(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual, void(*_impl)(corto_function f, void *result, void *args));
CORTO_LANG_EXPORT void corto_virtualSet(corto_virtual _this, corto_type returnType, corto_bool returnsReference, corto_bool _virtual);
CORTO_LANG_EXPORT corto_string corto_virtualStr(corto_virtual value);
CORTO_LANG_EXPORT corto_virtual corto_virtualFromStr(corto_virtual value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_virtualCopy(corto_virtual *dst, corto_virtual src);
CORTO_LANG_EXPORT corto_int16 corto_virtualCompare(corto_virtual dst, corto_virtual src);

/* ::corto::lang::void */
CORTO_LANG_EXPORT corto_void* corto_voidCreate(void);
CORTO_LANG_EXPORT corto_void* corto_voidCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_voidUpdate(corto_void* _this);

/* ::corto::lang::vtable */
CORTO_LANG_EXPORT corto_vtable* corto_vtableCreate(void);
CORTO_LANG_EXPORT corto_vtable* corto_vtableCreateChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_vtableUpdate(corto_vtable* _this, corto_vtable value);

CORTO_LANG_EXPORT corto_vtable* corto_vtableDeclare(void);
CORTO_LANG_EXPORT corto_vtable* corto_vtableDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_vtableDefine(corto_vtable* _this, corto_vtable value);
CORTO_LANG_EXPORT void corto_vtableSet(corto_vtable* _this, corto_vtable value);
CORTO_LANG_EXPORT corto_string corto_vtableStr(corto_vtable value);
CORTO_LANG_EXPORT corto_vtable* corto_vtableFromStr(corto_vtable* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_vtableCopy(corto_vtable* *dst, corto_vtable* src);
CORTO_LANG_EXPORT corto_int16 corto_vtableCompare(corto_vtable* dst, corto_vtable* src);

CORTO_LANG_EXPORT corto_int16 corto_vtableInit(corto_vtable* value);
CORTO_LANG_EXPORT corto_int16 corto_vtableDeinit(corto_vtable* value);

/* ::corto::lang::width */
CORTO_LANG_EXPORT corto_width* corto_widthCreate(corto_width value);
CORTO_LANG_EXPORT corto_width* corto_widthCreateChild(corto_object _parent, corto_string _name, corto_width value);
CORTO_LANG_EXPORT corto_int16 corto_widthUpdate(corto_width* _this, corto_width value);

CORTO_LANG_EXPORT corto_width* corto_widthDeclare(void);
CORTO_LANG_EXPORT corto_width* corto_widthDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_widthDefine(corto_width* _this, corto_width value);
CORTO_LANG_EXPORT void corto_widthSet(corto_width* _this, corto_width value);
CORTO_LANG_EXPORT corto_string corto_widthStr(corto_width value);
CORTO_LANG_EXPORT corto_width* corto_widthFromStr(corto_width* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_widthCopy(corto_width* *dst, corto_width* src);
CORTO_LANG_EXPORT corto_int16 corto_widthCompare(corto_width* dst, corto_width* src);

CORTO_LANG_EXPORT corto_int16 corto_widthInit(corto_width* value);
CORTO_LANG_EXPORT corto_int16 corto_widthDeinit(corto_width* value);

/* ::corto::lang::word */
CORTO_LANG_EXPORT corto_word* corto_wordCreate(corto_word value);
CORTO_LANG_EXPORT corto_word* corto_wordCreateChild(corto_object _parent, corto_string _name, corto_word value);
CORTO_LANG_EXPORT corto_int16 corto_wordUpdate(corto_word* _this, corto_word value);

CORTO_LANG_EXPORT corto_word* corto_wordDeclare(void);
CORTO_LANG_EXPORT corto_word* corto_wordDeclareChild(corto_object _parent, corto_string _name);
CORTO_LANG_EXPORT corto_int16 corto_wordDefine(corto_word* _this, corto_word value);
CORTO_LANG_EXPORT void corto_wordSet(corto_word* _this, corto_word value);
CORTO_LANG_EXPORT corto_string corto_wordStr(corto_word value);
CORTO_LANG_EXPORT corto_word* corto_wordFromStr(corto_word* value, corto_string str);
CORTO_LANG_EXPORT corto_int16 corto_wordCopy(corto_word* *dst, corto_word* src);
CORTO_LANG_EXPORT corto_int16 corto_wordCompare(corto_word* dst, corto_word* src);

CORTO_LANG_EXPORT corto_int16 corto_wordInit(corto_word* value);
CORTO_LANG_EXPORT corto_int16 corto_wordDeinit(corto_word* value);


/* ::corto::lang::interfaceseq */
#define corto_interfaceseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interface elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element);
CORTO_LANG_EXPORT corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq);
CORTO_LANG_EXPORT void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_interfaceseqClear(corto_interfaceseq *seq);

/* ::corto::lang::interfaceVectorseq */
#define corto_interfaceVectorseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_interfaceVector elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element);
CORTO_LANG_EXPORT corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq);
CORTO_LANG_EXPORT void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq);

/* ::corto::lang::memberseq */
#define corto_memberseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_member elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_member* corto_memberseqAppend(corto_memberseq *seq, corto_member element);
CORTO_LANG_EXPORT corto_member* corto_memberseqAppendAlloc(corto_memberseq *seq);
CORTO_LANG_EXPORT void corto_memberseqSize(corto_memberseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_memberseqClear(corto_memberseq *seq);

/* ::corto::lang::objectseq */
#define corto_objectseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_object elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element);
CORTO_LANG_EXPORT corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq);
CORTO_LANG_EXPORT void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_objectseqClear(corto_objectseq *seq);

/* ::corto::lang::observerseq */
#define corto_observerseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_observer elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_observer* corto_observerseqAppend(corto_observerseq *seq, corto_observer element);
CORTO_LANG_EXPORT corto_observer* corto_observerseqAppendAlloc(corto_observerseq *seq);
CORTO_LANG_EXPORT void corto_observerseqSize(corto_observerseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_observerseqClear(corto_observerseq *seq);

/* ::corto::lang::octetseq */
#define corto_octetseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_octet elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_octet* corto_octetseqAppend(corto_octetseq *seq, corto_octet element);
CORTO_LANG_EXPORT corto_octet* corto_octetseqAppendAlloc(corto_octetseq *seq);
CORTO_LANG_EXPORT void corto_octetseqSize(corto_octetseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_octetseqClear(corto_octetseq *seq);

/* ::corto::lang::parameterseq */
#define corto_parameterseqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_parameter elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_LANG_EXPORT corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element);
CORTO_LANG_EXPORT corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq);
CORTO_LANG_EXPORT void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length);
CORTO_LANG_EXPORT void corto_parameterseqClear(corto_parameterseq *seq);

/* ::corto::lang::vtable */
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

