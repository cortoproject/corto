/* cx__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang__API_H
#define corto_lang__API_H

#include "corto.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#else
#include "corto/lang/cx__type.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::lang::alias */
cx_alias cx_aliasCreate(cx_member member);
cx_alias cx_aliasCreateChild(cx_object _parent, cx_string _name, cx_member member);

cx_alias cx_aliasDeclare(void);
cx_alias cx_aliasDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_aliasDefine(cx_alias this, cx_member member);
void cx_aliasUpdate(cx_alias this, cx_member member);
void cx_aliasSet(cx_alias this, cx_member member);
cx_string cx_aliasStr(cx_alias value);
cx_alias cx_aliasFromStr(cx_alias value, cx_string str);
cx_int16 cx_aliasCopy(cx_alias *dst, cx_alias src);
cx_int16 cx_aliasCompare(cx_alias dst, cx_alias src);

/* ::corto::lang::any */
cx_any* cx_anyCreate(cx_any value);
cx_any* cx_anyCreateChild(cx_object _parent, cx_string _name, cx_any value);

cx_any* cx_anyDeclare(void);
cx_any* cx_anyDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_anyDefine(cx_any* this, cx_any value);
void cx_anyUpdate(cx_any* this, cx_any value);
void cx_anySet(cx_any* this, cx_any value);
cx_string cx_anyStr(cx_any value);
cx_any* cx_anyFromStr(cx_any* value, cx_string str);
cx_int16 cx_anyCopy(cx_any* *dst, cx_any* src);
cx_int16 cx_anyCompare(cx_any* dst, cx_any* src);

cx_int16 cx_anyInit(cx_any* value);
cx_int16 cx_anyDeinit(cx_any* value);

/* ::corto::lang::array */
cx_array cx_arrayCreate(cx_type elementType, cx_uint32 max);
cx_array cx_arrayCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_array cx_arrayDeclare(void);
cx_array cx_arrayDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_arrayDefine(cx_array this, cx_type elementType, cx_uint32 max);
void cx_arrayUpdate(cx_array this, cx_type elementType, cx_uint32 max);
void cx_arraySet(cx_array this, cx_type elementType, cx_uint32 max);
cx_string cx_arrayStr(cx_array value);
cx_array cx_arrayFromStr(cx_array value, cx_string str);
cx_int16 cx_arrayCopy(cx_array *dst, cx_array src);
cx_int16 cx_arrayCompare(cx_array dst, cx_array src);

/* ::corto::lang::attr */
cx_attr* cx_attrCreate(cx_attr value);
cx_attr* cx_attrCreateChild(cx_object _parent, cx_string _name, cx_attr value);

cx_attr* cx_attrDeclare(void);
cx_attr* cx_attrDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_attrDefine(cx_attr* this, cx_attr value);
void cx_attrUpdate(cx_attr* this, cx_attr value);
void cx_attrSet(cx_attr* this, cx_attr value);
cx_string cx_attrStr(cx_attr value);
cx_attr* cx_attrFromStr(cx_attr* value, cx_string str);
cx_int16 cx_attrCopy(cx_attr* *dst, cx_attr* src);
cx_int16 cx_attrCompare(cx_attr* dst, cx_attr* src);

cx_int16 cx_attrInit(cx_attr* value);
cx_int16 cx_attrDeinit(cx_attr* value);

/* ::corto::lang::binary */
cx_binary cx_binaryCreate(cx_width width);
cx_binary cx_binaryCreateChild(cx_object _parent, cx_string _name, cx_width width);

cx_binary cx_binaryDeclare(void);
cx_binary cx_binaryDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_binaryDefine(cx_binary this, cx_width width);
void cx_binaryUpdate(cx_binary this, cx_width width);
void cx_binarySet(cx_binary this, cx_width width);
cx_string cx_binaryStr(cx_binary value);
cx_binary cx_binaryFromStr(cx_binary value, cx_string str);
cx_int16 cx_binaryCopy(cx_binary *dst, cx_binary src);
cx_int16 cx_binaryCompare(cx_binary dst, cx_binary src);

/* ::corto::lang::bitmask */
cx_bitmask cx_bitmaskCreate(void);
cx_bitmask cx_bitmaskCreateChild(cx_object _parent, cx_string _name);

cx_bitmask cx_bitmaskDeclare(void);
cx_bitmask cx_bitmaskDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_bitmaskDefine(cx_bitmask this);
void cx_bitmaskUpdate(cx_bitmask this);
void cx_bitmaskSet(cx_bitmask this);
cx_string cx_bitmaskStr(cx_bitmask value);
cx_bitmask cx_bitmaskFromStr(cx_bitmask value, cx_string str);
cx_int16 cx_bitmaskCopy(cx_bitmask *dst, cx_bitmask src);
cx_int16 cx_bitmaskCompare(cx_bitmask dst, cx_bitmask src);

/* ::corto::lang::bool */
cx_bool* cx_boolCreate(cx_bool value);
cx_bool* cx_boolCreateChild(cx_object _parent, cx_string _name, cx_bool value);

cx_bool* cx_boolDeclare(void);
cx_bool* cx_boolDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_boolDefine(cx_bool* this, cx_bool value);
void cx_boolUpdate(cx_bool* this, cx_bool value);
void cx_boolSet(cx_bool* this, cx_bool value);
cx_string cx_boolStr(cx_bool value);
cx_bool* cx_boolFromStr(cx_bool* value, cx_string str);
cx_int16 cx_boolCopy(cx_bool* *dst, cx_bool* src);
cx_int16 cx_boolCompare(cx_bool* dst, cx_bool* src);

cx_int16 cx_boolInit(cx_bool* value);
cx_int16 cx_boolDeinit(cx_bool* value);

/* ::corto::lang::boolean */
cx_boolean cx_booleanCreate(void);
cx_boolean cx_booleanCreateChild(cx_object _parent, cx_string _name);

cx_boolean cx_booleanDeclare(void);
cx_boolean cx_booleanDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_booleanDefine(cx_boolean this);
void cx_booleanUpdate(cx_boolean this);
void cx_booleanSet(cx_boolean this);
cx_string cx_booleanStr(cx_boolean value);
cx_boolean cx_booleanFromStr(cx_boolean value, cx_string str);
cx_int16 cx_booleanCopy(cx_boolean *dst, cx_boolean src);
cx_int16 cx_booleanCompare(cx_boolean dst, cx_boolean src);

/* ::corto::lang::callbackDestruct */
cx_callbackDestruct* cx_callbackDestructCreate(void);
cx_callbackDestruct* cx_callbackDestructCreateChild(cx_object _parent, cx_string _name);

cx_callbackDestruct* cx_callbackDestructDeclare(void);
cx_callbackDestruct* cx_callbackDestructDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_callbackDestructDefine(cx_callbackDestruct* this);
void cx_callbackDestructUpdate(cx_callbackDestruct* this);
void cx_callbackDestructSet(cx_callbackDestruct* this);
cx_string cx_callbackDestructStr(cx_callbackDestruct* value);
cx_callbackDestruct* cx_callbackDestructFromStr(cx_callbackDestruct* value, cx_string str);
cx_int16 cx_callbackDestructCopy(cx_callbackDestruct* *dst, cx_callbackDestruct* src);
cx_int16 cx_callbackDestructCompare(cx_callbackDestruct* dst, cx_callbackDestruct* src);

cx_int16 cx_callbackDestructInit(cx_callbackDestruct* value);
cx_int16 cx_callbackDestructDeinit(cx_callbackDestruct* value);

/* ::corto::lang::callbackInit */
cx_callbackInit* cx_callbackInitCreate(void);
cx_callbackInit* cx_callbackInitCreateChild(cx_object _parent, cx_string _name);

cx_callbackInit* cx_callbackInitDeclare(void);
cx_callbackInit* cx_callbackInitDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_callbackInitDefine(cx_callbackInit* this);
void cx_callbackInitUpdate(cx_callbackInit* this);
void cx_callbackInitSet(cx_callbackInit* this);
cx_string cx_callbackInitStr(cx_callbackInit* value);
cx_callbackInit* cx_callbackInitFromStr(cx_callbackInit* value, cx_string str);
cx_int16 cx_callbackInitCopy(cx_callbackInit* *dst, cx_callbackInit* src);
cx_int16 cx_callbackInitCompare(cx_callbackInit* dst, cx_callbackInit* src);

cx_int16 cx_callbackInitInit(cx_callbackInit* value);
cx_int16 cx_callbackInitDeinit(cx_callbackInit* value);

/* ::corto::lang::char */
cx_char* cx_charCreate(cx_char value);
cx_char* cx_charCreateChild(cx_object _parent, cx_string _name, cx_char value);

cx_char* cx_charDeclare(void);
cx_char* cx_charDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_charDefine(cx_char* this, cx_char value);
void cx_charUpdate(cx_char* this, cx_char value);
void cx_charSet(cx_char* this, cx_char value);
cx_string cx_charStr(cx_char value);
cx_char* cx_charFromStr(cx_char* value, cx_string str);
cx_int16 cx_charCopy(cx_char* *dst, cx_char* src);
cx_int16 cx_charCompare(cx_char* dst, cx_char* src);

cx_int16 cx_charInit(cx_char* value);
cx_int16 cx_charDeinit(cx_char* value);

/* ::corto::lang::character */
cx_character cx_characterCreate(cx_width width);
cx_character cx_characterCreateChild(cx_object _parent, cx_string _name, cx_width width);

cx_character cx_characterDeclare(void);
cx_character cx_characterDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_characterDefine(cx_character this, cx_width width);
void cx_characterUpdate(cx_character this, cx_width width);
void cx_characterSet(cx_character this, cx_width width);
cx_string cx_characterStr(cx_character value);
cx_character cx_characterFromStr(cx_character value, cx_string str);
cx_int16 cx_characterCopy(cx_character *dst, cx_character src);
cx_int16 cx_characterCompare(cx_character dst, cx_character src);

/* ::corto::lang::class */
cx_class cx_classCreate(cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_class cx_classCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType);

cx_class cx_classDeclare(void);
cx_class cx_classDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_classDefine(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_classUpdate(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_classSet(cx_class this, cx_interface base, cx_modifier baseAccess, cx_interfaceseq implements, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_string cx_classStr(cx_class value);
cx_class cx_classFromStr(cx_class value, cx_string str);
cx_int16 cx_classCopy(cx_class *dst, cx_class src);
cx_int16 cx_classCompare(cx_class dst, cx_class src);

/* ::corto::lang::collection */
cx_collection cx_collectionCreate(cx_type elementType, cx_uint32 max);
cx_collection cx_collectionCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_collection cx_collectionDeclare(void);
cx_collection cx_collectionDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collectionDefine(cx_collection this, cx_type elementType, cx_uint32 max);
void cx_collectionUpdate(cx_collection this, cx_type elementType, cx_uint32 max);
void cx_collectionSet(cx_collection this, cx_type elementType, cx_uint32 max);
cx_string cx_collectionStr(cx_collection value);
cx_collection cx_collectionFromStr(cx_collection value, cx_string str);
cx_int16 cx_collectionCopy(cx_collection *dst, cx_collection src);
cx_int16 cx_collectionCompare(cx_collection dst, cx_collection src);

/* ::corto::lang::collectionKind */
cx_collectionKind* cx_collectionKindCreate(cx_collectionKind value);
cx_collectionKind* cx_collectionKindCreateChild(cx_object _parent, cx_string _name, cx_collectionKind value);

cx_collectionKind* cx_collectionKindDeclare(void);
cx_collectionKind* cx_collectionKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collectionKindDefine(cx_collectionKind* this, cx_collectionKind value);
void cx_collectionKindUpdate(cx_collectionKind* this, cx_collectionKind value);
void cx_collectionKindSet(cx_collectionKind* this, cx_collectionKind value);
cx_string cx_collectionKindStr(cx_collectionKind value);
cx_collectionKind* cx_collectionKindFromStr(cx_collectionKind* value, cx_string str);
cx_int16 cx_collectionKindCopy(cx_collectionKind* *dst, cx_collectionKind* src);
cx_int16 cx_collectionKindCompare(cx_collectionKind* dst, cx_collectionKind* src);

cx_int16 cx_collectionKindInit(cx_collectionKind* value);
cx_int16 cx_collectionKindDeinit(cx_collectionKind* value);

/* ::corto::lang::compositeKind */
cx_compositeKind* cx_compositeKindCreate(cx_compositeKind value);
cx_compositeKind* cx_compositeKindCreateChild(cx_object _parent, cx_string _name, cx_compositeKind value);

cx_compositeKind* cx_compositeKindDeclare(void);
cx_compositeKind* cx_compositeKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_compositeKindDefine(cx_compositeKind* this, cx_compositeKind value);
void cx_compositeKindUpdate(cx_compositeKind* this, cx_compositeKind value);
void cx_compositeKindSet(cx_compositeKind* this, cx_compositeKind value);
cx_string cx_compositeKindStr(cx_compositeKind value);
cx_compositeKind* cx_compositeKindFromStr(cx_compositeKind* value, cx_string str);
cx_int16 cx_compositeKindCopy(cx_compositeKind* *dst, cx_compositeKind* src);
cx_int16 cx_compositeKindCompare(cx_compositeKind* dst, cx_compositeKind* src);

cx_int16 cx_compositeKindInit(cx_compositeKind* value);
cx_int16 cx_compositeKindDeinit(cx_compositeKind* value);

/* ::corto::lang::constant */
cx_constant* cx_constantCreate(cx_constant value);
cx_constant* cx_constantCreateChild(cx_object _parent, cx_string _name, cx_constant value);

cx_constant* cx_constantDeclare(void);
cx_constant* cx_constantDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_constantDefine(cx_constant* this, cx_constant value);
void cx_constantUpdate(cx_constant* this, cx_constant value);
void cx_constantSet(cx_constant* this, cx_constant value);
cx_string cx_constantStr(cx_constant value);
cx_constant* cx_constantFromStr(cx_constant* value, cx_string str);
cx_int16 cx_constantCopy(cx_constant* *dst, cx_constant* src);
cx_int16 cx_constantCompare(cx_constant* dst, cx_constant* src);

cx_int16 cx_constantInit(cx_constant* value);
cx_int16 cx_constantDeinit(cx_constant* value);

/* ::corto::lang::delegate */
cx_delegate cx_delegateCreate(cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
cx_delegate cx_delegateCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);

cx_delegate cx_delegateDeclare(void);
cx_delegate cx_delegateDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegateDefine(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
void cx_delegateUpdate(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
void cx_delegateSet(cx_delegate this, cx_type returnType, cx_bool returnsReference, cx_parameterseq parameters);
cx_string cx_delegateStr(cx_delegate value);
cx_delegate cx_delegateFromStr(cx_delegate value, cx_string str);
cx_int16 cx_delegateCopy(cx_delegate *dst, cx_delegate src);
cx_int16 cx_delegateCompare(cx_delegate dst, cx_delegate src);

/* ::corto::lang::delegatedata */
cx_delegatedata* cx_delegatedataCreate(cx_object instance, cx_function procedure);
cx_delegatedata* cx_delegatedataCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

cx_delegatedata* cx_delegatedataDeclare(void);
cx_delegatedata* cx_delegatedataDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegatedataDefine(cx_delegatedata* this, cx_object instance, cx_function procedure);
void cx_delegatedataUpdate(cx_delegatedata* this, cx_object instance, cx_function procedure);
void cx_delegatedataSet(cx_delegatedata* this, cx_object instance, cx_function procedure);
cx_string cx_delegatedataStr(cx_delegatedata* value);
cx_delegatedata* cx_delegatedataFromStr(cx_delegatedata* value, cx_string str);
cx_int16 cx_delegatedataCopy(cx_delegatedata* *dst, cx_delegatedata* src);
cx_int16 cx_delegatedataCompare(cx_delegatedata* dst, cx_delegatedata* src);

cx_int16 cx_delegatedataInit(cx_delegatedata* value);
cx_int16 cx_delegatedataDeinit(cx_delegatedata* value);

/* ::corto::lang::dispatcher */
cx_dispatcher cx_dispatcherCreate(void);
cx_dispatcher cx_dispatcherCreateChild(cx_object _parent, cx_string _name);

cx_dispatcher cx_dispatcherDeclare(void);
cx_dispatcher cx_dispatcherDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_dispatcherDefine(cx_dispatcher this);
void cx_dispatcherUpdate(cx_dispatcher this);
void cx_dispatcherSet(cx_dispatcher this);
cx_string cx_dispatcherStr(cx_dispatcher value);
cx_dispatcher cx_dispatcherFromStr(cx_dispatcher value, cx_string str);
cx_int16 cx_dispatcherCopy(cx_dispatcher *dst, cx_dispatcher src);
cx_int16 cx_dispatcherCompare(cx_dispatcher dst, cx_dispatcher src);

/* ::corto::lang::enum */
cx_enum cx_enumCreate(void);
cx_enum cx_enumCreateChild(cx_object _parent, cx_string _name);

cx_enum cx_enumDeclare(void);
cx_enum cx_enumDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_enumDefine(cx_enum this);
void cx_enumUpdate(cx_enum this);
void cx_enumSet(cx_enum this);
cx_string cx_enumStr(cx_enum value);
cx_enum cx_enumFromStr(cx_enum value, cx_string str);
cx_int16 cx_enumCopy(cx_enum *dst, cx_enum src);
cx_int16 cx_enumCompare(cx_enum dst, cx_enum src);

/* ::corto::lang::equalityKind */
cx_equalityKind* cx_equalityKindCreate(cx_equalityKind value);
cx_equalityKind* cx_equalityKindCreateChild(cx_object _parent, cx_string _name, cx_equalityKind value);

cx_equalityKind* cx_equalityKindDeclare(void);
cx_equalityKind* cx_equalityKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_equalityKindDefine(cx_equalityKind* this, cx_equalityKind value);
void cx_equalityKindUpdate(cx_equalityKind* this, cx_equalityKind value);
void cx_equalityKindSet(cx_equalityKind* this, cx_equalityKind value);
cx_string cx_equalityKindStr(cx_equalityKind value);
cx_equalityKind* cx_equalityKindFromStr(cx_equalityKind* value, cx_string str);
cx_int16 cx_equalityKindCopy(cx_equalityKind* *dst, cx_equalityKind* src);
cx_int16 cx_equalityKindCompare(cx_equalityKind* dst, cx_equalityKind* src);

cx_int16 cx_equalityKindInit(cx_equalityKind* value);
cx_int16 cx_equalityKindDeinit(cx_equalityKind* value);

/* ::corto::lang::event */
cx_event cx_eventCreate(cx_uint16 kind);
cx_event cx_eventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind);

cx_event cx_eventDeclare(void);
cx_event cx_eventDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_eventDefine(cx_event this, cx_uint16 kind);
void cx_eventUpdate(cx_event this, cx_uint16 kind);
void cx_eventSet(cx_event this, cx_uint16 kind);
cx_string cx_eventStr(cx_event value);
cx_event cx_eventFromStr(cx_event value, cx_string str);
cx_int16 cx_eventCopy(cx_event *dst, cx_event src);
cx_int16 cx_eventCompare(cx_event dst, cx_event src);

/* ::corto::lang::eventMask */
cx_eventMask* cx_eventMaskCreate(cx_eventMask value);
cx_eventMask* cx_eventMaskCreateChild(cx_object _parent, cx_string _name, cx_eventMask value);

cx_eventMask* cx_eventMaskDeclare(void);
cx_eventMask* cx_eventMaskDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_eventMaskDefine(cx_eventMask* this, cx_eventMask value);
void cx_eventMaskUpdate(cx_eventMask* this, cx_eventMask value);
void cx_eventMaskSet(cx_eventMask* this, cx_eventMask value);
cx_string cx_eventMaskStr(cx_eventMask value);
cx_eventMask* cx_eventMaskFromStr(cx_eventMask* value, cx_string str);
cx_int16 cx_eventMaskCopy(cx_eventMask* *dst, cx_eventMask* src);
cx_int16 cx_eventMaskCompare(cx_eventMask* dst, cx_eventMask* src);

cx_int16 cx_eventMaskInit(cx_eventMask* value);
cx_int16 cx_eventMaskDeinit(cx_eventMask* value);

/* ::corto::lang::float */
cx_float cx_floatCreate(cx_width width, cx_float64 min, cx_float64 max);
cx_float cx_floatCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_float64 min, cx_float64 max);

cx_float cx_floatDeclare(void);
cx_float cx_floatDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_floatDefine(cx_float this, cx_width width, cx_float64 min, cx_float64 max);
void cx_floatUpdate(cx_float this, cx_width width, cx_float64 min, cx_float64 max);
void cx_floatSet(cx_float this, cx_width width, cx_float64 min, cx_float64 max);
cx_string cx_floatStr(cx_float value);
cx_float cx_floatFromStr(cx_float value, cx_string str);
cx_int16 cx_floatCopy(cx_float *dst, cx_float src);
cx_int16 cx_floatCompare(cx_float dst, cx_float src);

/* ::corto::lang::float32 */
cx_float32* cx_float32Create(cx_float32 value);
cx_float32* cx_float32CreateChild(cx_object _parent, cx_string _name, cx_float32 value);

cx_float32* cx_float32Declare(void);
cx_float32* cx_float32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float32Define(cx_float32* this, cx_float32 value);
void cx_float32Update(cx_float32* this, cx_float32 value);
void cx_float32Set(cx_float32* this, cx_float32 value);
cx_string cx_float32Str(cx_float32 value);
cx_float32* cx_float32FromStr(cx_float32* value, cx_string str);
cx_int16 cx_float32Copy(cx_float32* *dst, cx_float32* src);
cx_int16 cx_float32Compare(cx_float32* dst, cx_float32* src);

cx_int16 cx_float32Init(cx_float32* value);
cx_int16 cx_float32Deinit(cx_float32* value);

/* ::corto::lang::float64 */
cx_float64* cx_float64Create(cx_float64 value);
cx_float64* cx_float64CreateChild(cx_object _parent, cx_string _name, cx_float64 value);

cx_float64* cx_float64Declare(void);
cx_float64* cx_float64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float64Define(cx_float64* this, cx_float64 value);
void cx_float64Update(cx_float64* this, cx_float64 value);
void cx_float64Set(cx_float64* this, cx_float64 value);
cx_string cx_float64Str(cx_float64 value);
cx_float64* cx_float64FromStr(cx_float64* value, cx_string str);
cx_int16 cx_float64Copy(cx_float64* *dst, cx_float64* src);
cx_int16 cx_float64Compare(cx_float64* dst, cx_float64* src);

cx_int16 cx_float64Init(cx_float64* value);
cx_int16 cx_float64Deinit(cx_float64* value);

/* ::corto::lang::function */
cx_function cx_functionCreate(cx_type returnType, cx_bool returnsReference);
cx_function cx_functionCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference);

cx_function cx_functionDeclare(void);
cx_function cx_functionDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_functionDefine(cx_function this, cx_type returnType, cx_bool returnsReference);
void cx_functionUpdate(cx_function this, cx_type returnType, cx_bool returnsReference);
void cx_functionSet(cx_function this, cx_type returnType, cx_bool returnsReference);
cx_string cx_functionStr(cx_function value);
cx_function cx_functionFromStr(cx_function value, cx_string str);
cx_int16 cx_functionCopy(cx_function *dst, cx_function src);
cx_int16 cx_functionCompare(cx_function dst, cx_function src);

/* ::corto::lang::int */
cx_int cx_intCreate(cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_intCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max);

cx_int cx_intDeclare(void);
cx_int cx_intDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_intDefine(cx_int this, cx_width width, cx_int64 min, cx_int64 max);
void cx_intUpdate(cx_int this, cx_width width, cx_int64 min, cx_int64 max);
void cx_intSet(cx_int this, cx_width width, cx_int64 min, cx_int64 max);
cx_string cx_intStr(cx_int value);
cx_int cx_intFromStr(cx_int value, cx_string str);
cx_int16 cx_intCopy(cx_int *dst, cx_int src);
cx_int16 cx_intCompare(cx_int dst, cx_int src);

/* ::corto::lang::int16 */
cx_int16* cx_int16Create(cx_int16 value);
cx_int16* cx_int16CreateChild(cx_object _parent, cx_string _name, cx_int16 value);

cx_int16* cx_int16Declare(void);
cx_int16* cx_int16DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int16Define(cx_int16* this, cx_int16 value);
void cx_int16Update(cx_int16* this, cx_int16 value);
void cx_int16Set(cx_int16* this, cx_int16 value);
cx_string cx_int16Str(cx_int16 value);
cx_int16* cx_int16FromStr(cx_int16* value, cx_string str);
cx_int16 cx_int16Copy(cx_int16* *dst, cx_int16* src);
cx_int16 cx_int16Compare(cx_int16* dst, cx_int16* src);

cx_int16 cx_int16Init(cx_int16* value);
cx_int16 cx_int16Deinit(cx_int16* value);

/* ::corto::lang::int32 */
cx_int32* cx_int32Create(cx_int32 value);
cx_int32* cx_int32CreateChild(cx_object _parent, cx_string _name, cx_int32 value);

cx_int32* cx_int32Declare(void);
cx_int32* cx_int32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int32Define(cx_int32* this, cx_int32 value);
void cx_int32Update(cx_int32* this, cx_int32 value);
void cx_int32Set(cx_int32* this, cx_int32 value);
cx_string cx_int32Str(cx_int32 value);
cx_int32* cx_int32FromStr(cx_int32* value, cx_string str);
cx_int16 cx_int32Copy(cx_int32* *dst, cx_int32* src);
cx_int16 cx_int32Compare(cx_int32* dst, cx_int32* src);

cx_int16 cx_int32Init(cx_int32* value);
cx_int16 cx_int32Deinit(cx_int32* value);

/* ::corto::lang::int64 */
cx_int64* cx_int64Create(cx_int64 value);
cx_int64* cx_int64CreateChild(cx_object _parent, cx_string _name, cx_int64 value);

cx_int64* cx_int64Declare(void);
cx_int64* cx_int64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int64Define(cx_int64* this, cx_int64 value);
void cx_int64Update(cx_int64* this, cx_int64 value);
void cx_int64Set(cx_int64* this, cx_int64 value);
cx_string cx_int64Str(cx_int64 value);
cx_int64* cx_int64FromStr(cx_int64* value, cx_string str);
cx_int16 cx_int64Copy(cx_int64* *dst, cx_int64* src);
cx_int16 cx_int64Compare(cx_int64* dst, cx_int64* src);

cx_int16 cx_int64Init(cx_int64* value);
cx_int16 cx_int64Deinit(cx_int64* value);

/* ::corto::lang::int8 */
cx_int8* cx_int8Create(cx_int8 value);
cx_int8* cx_int8CreateChild(cx_object _parent, cx_string _name, cx_int8 value);

cx_int8* cx_int8Declare(void);
cx_int8* cx_int8DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int8Define(cx_int8* this, cx_int8 value);
void cx_int8Update(cx_int8* this, cx_int8 value);
void cx_int8Set(cx_int8* this, cx_int8 value);
cx_string cx_int8Str(cx_int8 value);
cx_int8* cx_int8FromStr(cx_int8* value, cx_string str);
cx_int16 cx_int8Copy(cx_int8* *dst, cx_int8* src);
cx_int16 cx_int8Compare(cx_int8* dst, cx_int8* src);

cx_int16 cx_int8Init(cx_int8* value);
cx_int16 cx_int8Deinit(cx_int8* value);

/* ::corto::lang::interface */
cx_interface cx_interfaceCreate(cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_interface cx_interfaceCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType);

cx_interface cx_interfaceDeclare(void);
cx_interface cx_interfaceDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceDefine(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_interfaceUpdate(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_interfaceSet(cx_interface this, cx_interface base, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_string cx_interfaceStr(cx_interface value);
cx_interface cx_interfaceFromStr(cx_interface value, cx_string str);
cx_int16 cx_interfaceCopy(cx_interface *dst, cx_interface src);
cx_int16 cx_interfaceCompare(cx_interface dst, cx_interface src);

/* ::corto::lang::interfaceseq */
cx_interfaceseq* cx_interfaceseqCreate(void);
cx_interfaceseq* cx_interfaceseqCreateChild(cx_object _parent, cx_string _name);

cx_interfaceseq* cx_interfaceseqDeclare(void);
cx_interfaceseq* cx_interfaceseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceseqDefine(cx_interfaceseq* this, cx_interfaceseq value);
void cx_interfaceseqUpdate(cx_interfaceseq* this, cx_interfaceseq value);
void cx_interfaceseqSet(cx_interfaceseq* this, cx_interfaceseq value);
cx_string cx_interfaceseqStr(cx_interfaceseq value);
cx_interfaceseq* cx_interfaceseqFromStr(cx_interfaceseq* value, cx_string str);
cx_int16 cx_interfaceseqCopy(cx_interfaceseq* *dst, cx_interfaceseq* src);
cx_int16 cx_interfaceseqCompare(cx_interfaceseq* dst, cx_interfaceseq* src);

cx_int16 cx_interfaceseqInit(cx_interfaceseq* value);
cx_int16 cx_interfaceseqDeinit(cx_interfaceseq* value);

/* ::corto::lang::interfaceVector */
cx_interfaceVector* cx_interfaceVectorCreate(cx_interface interface, cx_vtable vector);
cx_interfaceVector* cx_interfaceVectorCreateChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector);

cx_interfaceVector* cx_interfaceVectorDeclare(void);
cx_interfaceVector* cx_interfaceVectorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVectorDefine(cx_interfaceVector* this, cx_interface interface, cx_vtable vector);
void cx_interfaceVectorUpdate(cx_interfaceVector* this, cx_interface interface, cx_vtable vector);
void cx_interfaceVectorSet(cx_interfaceVector* this, cx_interface interface, cx_vtable vector);
cx_string cx_interfaceVectorStr(cx_interfaceVector* value);
cx_interfaceVector* cx_interfaceVectorFromStr(cx_interfaceVector* value, cx_string str);
cx_int16 cx_interfaceVectorCopy(cx_interfaceVector* *dst, cx_interfaceVector* src);
cx_int16 cx_interfaceVectorCompare(cx_interfaceVector* dst, cx_interfaceVector* src);

cx_int16 cx_interfaceVectorInit(cx_interfaceVector* value);
cx_int16 cx_interfaceVectorDeinit(cx_interfaceVector* value);

/* ::corto::lang::interfaceVectorseq */
cx_interfaceVectorseq* cx_interfaceVectorseqCreate(void);
cx_interfaceVectorseq* cx_interfaceVectorseqCreateChild(cx_object _parent, cx_string _name);

cx_interfaceVectorseq* cx_interfaceVectorseqDeclare(void);
cx_interfaceVectorseq* cx_interfaceVectorseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVectorseqDefine(cx_interfaceVectorseq* this, cx_interfaceVectorseq value);
void cx_interfaceVectorseqUpdate(cx_interfaceVectorseq* this, cx_interfaceVectorseq value);
void cx_interfaceVectorseqSet(cx_interfaceVectorseq* this, cx_interfaceVectorseq value);
cx_string cx_interfaceVectorseqStr(cx_interfaceVectorseq value);
cx_interfaceVectorseq* cx_interfaceVectorseqFromStr(cx_interfaceVectorseq* value, cx_string str);
cx_int16 cx_interfaceVectorseqCopy(cx_interfaceVectorseq* *dst, cx_interfaceVectorseq* src);
cx_int16 cx_interfaceVectorseqCompare(cx_interfaceVectorseq* dst, cx_interfaceVectorseq* src);

cx_int16 cx_interfaceVectorseqInit(cx_interfaceVectorseq* value);
cx_int16 cx_interfaceVectorseqDeinit(cx_interfaceVectorseq* value);

/* ::corto::lang::iterator */
cx_iterator cx_iteratorCreate(cx_type elementType);
cx_iterator cx_iteratorCreateChild(cx_object _parent, cx_string _name, cx_type elementType);

cx_iterator cx_iteratorDeclare(void);
cx_iterator cx_iteratorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_iteratorDefine(cx_iterator this, cx_type elementType);
void cx_iteratorUpdate(cx_iterator this, cx_type elementType);
void cx_iteratorSet(cx_iterator this, cx_type elementType);
cx_string cx_iteratorStr(cx_iterator value);
cx_iterator cx_iteratorFromStr(cx_iterator value, cx_string str);
cx_int16 cx_iteratorCopy(cx_iterator *dst, cx_iterator src);
cx_int16 cx_iteratorCompare(cx_iterator dst, cx_iterator src);

/* ::corto::lang::list */
cx_list cx_listCreate(cx_type elementType, cx_uint32 max);
cx_list cx_listCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_list cx_listDeclare(void);
cx_list cx_listDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_listDefine(cx_list this, cx_type elementType, cx_uint32 max);
void cx_listUpdate(cx_list this, cx_type elementType, cx_uint32 max);
void cx_listSet(cx_list this, cx_type elementType, cx_uint32 max);
cx_string cx_listStr(cx_list value);
cx_list cx_listFromStr(cx_list value, cx_string str);
cx_int16 cx_listCopy(cx_list *dst, cx_list src);
cx_int16 cx_listCompare(cx_list dst, cx_list src);

/* ::corto::lang::map */
cx_map cx_mapCreate(cx_type elementType, cx_type keyType, cx_uint32 max);
cx_map cx_mapCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max);

cx_map cx_mapDeclare(void);
cx_map cx_mapDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_mapDefine(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_mapUpdate(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_mapSet(cx_map this, cx_type elementType, cx_type keyType, cx_uint32 max);
cx_string cx_mapStr(cx_map value);
cx_map cx_mapFromStr(cx_map value, cx_string str);
cx_int16 cx_mapCopy(cx_map *dst, cx_map src);
cx_int16 cx_mapCompare(cx_map dst, cx_map src);

/* ::corto::lang::member */
cx_member cx_memberCreate(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_memberCreateChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);

cx_member cx_memberDeclare(void);
cx_member cx_memberDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_memberDefine(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_memberUpdate(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_memberSet(cx_member this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_string cx_memberStr(cx_member value);
cx_member cx_memberFromStr(cx_member value, cx_string str);
cx_int16 cx_memberCopy(cx_member *dst, cx_member src);
cx_int16 cx_memberCompare(cx_member dst, cx_member src);

/* ::corto::lang::memberseq */
cx_memberseq* cx_memberseqCreate(void);
cx_memberseq* cx_memberseqCreateChild(cx_object _parent, cx_string _name);

cx_memberseq* cx_memberseqDeclare(void);
cx_memberseq* cx_memberseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_memberseqDefine(cx_memberseq* this, cx_memberseq value);
void cx_memberseqUpdate(cx_memberseq* this, cx_memberseq value);
void cx_memberseqSet(cx_memberseq* this, cx_memberseq value);
cx_string cx_memberseqStr(cx_memberseq value);
cx_memberseq* cx_memberseqFromStr(cx_memberseq* value, cx_string str);
cx_int16 cx_memberseqCopy(cx_memberseq* *dst, cx_memberseq* src);
cx_int16 cx_memberseqCompare(cx_memberseq* dst, cx_memberseq* src);

cx_int16 cx_memberseqInit(cx_memberseq* value);
cx_int16 cx_memberseqDeinit(cx_memberseq* value);

/* ::corto::lang::metaprocedure */
cx_metaprocedure cx_metaprocedureCreate(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedureCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);

cx_metaprocedure cx_metaprocedureDeclare(void);
cx_metaprocedure cx_metaprocedureDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_metaprocedureDefine(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedureUpdate(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedureSet(cx_metaprocedure this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_string cx_metaprocedureStr(cx_metaprocedure value);
cx_metaprocedure cx_metaprocedureFromStr(cx_metaprocedure value, cx_string str);
cx_int16 cx_metaprocedureCopy(cx_metaprocedure *dst, cx_metaprocedure src);
cx_int16 cx_metaprocedureCompare(cx_metaprocedure dst, cx_metaprocedure src);

/* ::corto::lang::method */
cx_method cx_methodCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_methodCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

cx_method cx_methodDeclare(void);
cx_method cx_methodDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_methodDefine(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_methodUpdate(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_methodSet(cx_method this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string cx_methodStr(cx_method value);
cx_method cx_methodFromStr(cx_method value, cx_string str);
cx_int16 cx_methodCopy(cx_method *dst, cx_method src);
cx_int16 cx_methodCompare(cx_method dst, cx_method src);

/* ::corto::lang::modifier */
cx_modifier* cx_modifierCreate(cx_modifier value);
cx_modifier* cx_modifierCreateChild(cx_object _parent, cx_string _name, cx_modifier value);

cx_modifier* cx_modifierDeclare(void);
cx_modifier* cx_modifierDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_modifierDefine(cx_modifier* this, cx_modifier value);
void cx_modifierUpdate(cx_modifier* this, cx_modifier value);
void cx_modifierSet(cx_modifier* this, cx_modifier value);
cx_string cx_modifierStr(cx_modifier value);
cx_modifier* cx_modifierFromStr(cx_modifier* value, cx_string str);
cx_int16 cx_modifierCopy(cx_modifier* *dst, cx_modifier* src);
cx_int16 cx_modifierCompare(cx_modifier* dst, cx_modifier* src);

cx_int16 cx_modifierInit(cx_modifier* value);
cx_int16 cx_modifierDeinit(cx_modifier* value);

/* ::corto::lang::object */
cx_object cx_objectCreate(void);
cx_object cx_objectCreateChild(cx_object _parent, cx_string _name);

/* ::corto::lang::objectseq */
cx_objectseq* cx_objectseqCreate(void);
cx_objectseq* cx_objectseqCreateChild(cx_object _parent, cx_string _name);

cx_objectseq* cx_objectseqDeclare(void);
cx_objectseq* cx_objectseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_objectseqDefine(cx_objectseq* this, cx_objectseq value);
void cx_objectseqUpdate(cx_objectseq* this, cx_objectseq value);
void cx_objectseqSet(cx_objectseq* this, cx_objectseq value);
cx_string cx_objectseqStr(cx_objectseq value);
cx_objectseq* cx_objectseqFromStr(cx_objectseq* value, cx_string str);
cx_int16 cx_objectseqCopy(cx_objectseq* *dst, cx_objectseq* src);
cx_int16 cx_objectseqCompare(cx_objectseq* dst, cx_objectseq* src);

cx_int16 cx_objectseqInit(cx_objectseq* value);
cx_int16 cx_objectseqDeinit(cx_objectseq* value);

/* ::corto::lang::observableEvent */
cx_observableEvent cx_observableEventCreate(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);

cx_observableEvent cx_observableEventDeclare(void);
cx_observableEvent cx_observableEventDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observableEventDefine(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEventUpdate(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEventSet(cx_observableEvent this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_string cx_observableEventStr(cx_observableEvent value);
cx_observableEvent cx_observableEventFromStr(cx_observableEvent value, cx_string str);
cx_int16 cx_observableEventCopy(cx_observableEvent *dst, cx_observableEvent src);
cx_int16 cx_observableEventCompare(cx_observableEvent dst, cx_observableEvent src);

/* ::corto::lang::observer */
cx_observer cx_observerCreate(cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observerCreateChild(cx_object _parent, cx_string _name, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);

cx_observer cx_observerDeclare(void);
cx_observer cx_observerDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observerDefine(cx_observer this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observerUpdate(cx_observer this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observerSet(cx_observer this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_string cx_observerStr(cx_observer value);
cx_observer cx_observerFromStr(cx_observer value, cx_string str);
cx_int16 cx_observerCopy(cx_observer *dst, cx_observer src);
cx_int16 cx_observerCompare(cx_observer dst, cx_observer src);

/* ::corto::lang::observerseq */
cx_observerseq* cx_observerseqCreate(void);
cx_observerseq* cx_observerseqCreateChild(cx_object _parent, cx_string _name);

cx_observerseq* cx_observerseqDeclare(void);
cx_observerseq* cx_observerseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observerseqDefine(cx_observerseq* this, cx_observerseq value);
void cx_observerseqUpdate(cx_observerseq* this, cx_observerseq value);
void cx_observerseqSet(cx_observerseq* this, cx_observerseq value);
cx_string cx_observerseqStr(cx_observerseq value);
cx_observerseq* cx_observerseqFromStr(cx_observerseq* value, cx_string str);
cx_int16 cx_observerseqCopy(cx_observerseq* *dst, cx_observerseq* src);
cx_int16 cx_observerseqCompare(cx_observerseq* dst, cx_observerseq* src);

cx_int16 cx_observerseqInit(cx_observerseq* value);
cx_int16 cx_observerseqDeinit(cx_observerseq* value);

/* ::corto::lang::octet */
cx_octet* cx_octetCreate(cx_octet value);
cx_octet* cx_octetCreateChild(cx_object _parent, cx_string _name, cx_octet value);

cx_octet* cx_octetDeclare(void);
cx_octet* cx_octetDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_octetDefine(cx_octet* this, cx_octet value);
void cx_octetUpdate(cx_octet* this, cx_octet value);
void cx_octetSet(cx_octet* this, cx_octet value);
cx_string cx_octetStr(cx_octet value);
cx_octet* cx_octetFromStr(cx_octet* value, cx_string str);
cx_int16 cx_octetCopy(cx_octet* *dst, cx_octet* src);
cx_int16 cx_octetCompare(cx_octet* dst, cx_octet* src);

cx_int16 cx_octetInit(cx_octet* value);
cx_int16 cx_octetDeinit(cx_octet* value);

/* ::corto::lang::operatorKind */
cx_operatorKind* cx_operatorKindCreate(cx_operatorKind value);
cx_operatorKind* cx_operatorKindCreateChild(cx_object _parent, cx_string _name, cx_operatorKind value);

cx_operatorKind* cx_operatorKindDeclare(void);
cx_operatorKind* cx_operatorKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_operatorKindDefine(cx_operatorKind* this, cx_operatorKind value);
void cx_operatorKindUpdate(cx_operatorKind* this, cx_operatorKind value);
void cx_operatorKindSet(cx_operatorKind* this, cx_operatorKind value);
cx_string cx_operatorKindStr(cx_operatorKind value);
cx_operatorKind* cx_operatorKindFromStr(cx_operatorKind* value, cx_string str);
cx_int16 cx_operatorKindCopy(cx_operatorKind* *dst, cx_operatorKind* src);
cx_int16 cx_operatorKindCompare(cx_operatorKind* dst, cx_operatorKind* src);

cx_int16 cx_operatorKindInit(cx_operatorKind* value);
cx_int16 cx_operatorKindDeinit(cx_operatorKind* value);

/* ::corto::lang::package */
cx_package cx_packageCreate(cx_string url);
cx_package cx_packageCreateChild(cx_object _parent, cx_string _name, cx_string url);

cx_package cx_packageDeclare(void);
cx_package cx_packageDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_packageDefine(cx_package this, cx_string url);
void cx_packageUpdate(cx_package this, cx_string url);
void cx_packageSet(cx_package this, cx_string url);
cx_string cx_packageStr(cx_package value);
cx_package cx_packageFromStr(cx_package value, cx_string str);
cx_int16 cx_packageCopy(cx_package *dst, cx_package src);
cx_int16 cx_packageCompare(cx_package dst, cx_package src);

/* ::corto::lang::parameter */
cx_parameter* cx_parameterCreate(cx_string name, cx_type type, cx_bool passByReference);
cx_parameter* cx_parameterCreateChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference);

cx_parameter* cx_parameterDeclare(void);
cx_parameter* cx_parameterDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameterDefine(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameterUpdate(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameterSet(cx_parameter* this, cx_string name, cx_type type, cx_bool passByReference);
cx_string cx_parameterStr(cx_parameter* value);
cx_parameter* cx_parameterFromStr(cx_parameter* value, cx_string str);
cx_int16 cx_parameterCopy(cx_parameter* *dst, cx_parameter* src);
cx_int16 cx_parameterCompare(cx_parameter* dst, cx_parameter* src);

cx_int16 cx_parameterInit(cx_parameter* value);
cx_int16 cx_parameterDeinit(cx_parameter* value);

/* ::corto::lang::parameterseq */
cx_parameterseq* cx_parameterseqCreate(void);
cx_parameterseq* cx_parameterseqCreateChild(cx_object _parent, cx_string _name);

cx_parameterseq* cx_parameterseqDeclare(void);
cx_parameterseq* cx_parameterseqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameterseqDefine(cx_parameterseq* this, cx_parameterseq value);
void cx_parameterseqUpdate(cx_parameterseq* this, cx_parameterseq value);
void cx_parameterseqSet(cx_parameterseq* this, cx_parameterseq value);
cx_string cx_parameterseqStr(cx_parameterseq value);
cx_parameterseq* cx_parameterseqFromStr(cx_parameterseq* value, cx_string str);
cx_int16 cx_parameterseqCopy(cx_parameterseq* *dst, cx_parameterseq* src);
cx_int16 cx_parameterseqCompare(cx_parameterseq* dst, cx_parameterseq* src);

cx_int16 cx_parameterseqInit(cx_parameterseq* value);
cx_int16 cx_parameterseqDeinit(cx_parameterseq* value);

/* ::corto::lang::primitive */
cx_primitive cx_primitiveCreate(cx_width width);
cx_primitive cx_primitiveCreateChild(cx_object _parent, cx_string _name, cx_width width);

cx_primitive cx_primitiveDeclare(void);
cx_primitive cx_primitiveDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitiveDefine(cx_primitive this, cx_width width);
void cx_primitiveUpdate(cx_primitive this, cx_width width);
void cx_primitiveSet(cx_primitive this, cx_width width);
cx_string cx_primitiveStr(cx_primitive value);
cx_primitive cx_primitiveFromStr(cx_primitive value, cx_string str);
cx_int16 cx_primitiveCopy(cx_primitive *dst, cx_primitive src);
cx_int16 cx_primitiveCompare(cx_primitive dst, cx_primitive src);

/* ::corto::lang::primitiveKind */
cx_primitiveKind* cx_primitiveKindCreate(cx_primitiveKind value);
cx_primitiveKind* cx_primitiveKindCreateChild(cx_object _parent, cx_string _name, cx_primitiveKind value);

cx_primitiveKind* cx_primitiveKindDeclare(void);
cx_primitiveKind* cx_primitiveKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitiveKindDefine(cx_primitiveKind* this, cx_primitiveKind value);
void cx_primitiveKindUpdate(cx_primitiveKind* this, cx_primitiveKind value);
void cx_primitiveKindSet(cx_primitiveKind* this, cx_primitiveKind value);
cx_string cx_primitiveKindStr(cx_primitiveKind value);
cx_primitiveKind* cx_primitiveKindFromStr(cx_primitiveKind* value, cx_string str);
cx_int16 cx_primitiveKindCopy(cx_primitiveKind* *dst, cx_primitiveKind* src);
cx_int16 cx_primitiveKindCompare(cx_primitiveKind* dst, cx_primitiveKind* src);

cx_int16 cx_primitiveKindInit(cx_primitiveKind* value);
cx_int16 cx_primitiveKindDeinit(cx_primitiveKind* value);

/* ::corto::lang::procedure */
cx_procedure cx_procedureCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind);
cx_procedure cx_procedureCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind);

cx_procedure cx_procedureDeclare(void);
cx_procedure cx_procedureDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedureDefine(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind);
void cx_procedureUpdate(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind);
void cx_procedureSet(cx_procedure this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType, cx_procedureKind kind);
cx_string cx_procedureStr(cx_procedure value);
cx_procedure cx_procedureFromStr(cx_procedure value, cx_string str);
cx_int16 cx_procedureCopy(cx_procedure *dst, cx_procedure src);
cx_int16 cx_procedureCompare(cx_procedure dst, cx_procedure src);

/* ::corto::lang::procedureKind */
cx_procedureKind* cx_procedureKindCreate(cx_procedureKind value);
cx_procedureKind* cx_procedureKindCreateChild(cx_object _parent, cx_string _name, cx_procedureKind value);

cx_procedureKind* cx_procedureKindDeclare(void);
cx_procedureKind* cx_procedureKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedureKindDefine(cx_procedureKind* this, cx_procedureKind value);
void cx_procedureKindUpdate(cx_procedureKind* this, cx_procedureKind value);
void cx_procedureKindSet(cx_procedureKind* this, cx_procedureKind value);
cx_string cx_procedureKindStr(cx_procedureKind value);
cx_procedureKind* cx_procedureKindFromStr(cx_procedureKind* value, cx_string str);
cx_int16 cx_procedureKindCopy(cx_procedureKind* *dst, cx_procedureKind* src);
cx_int16 cx_procedureKindCompare(cx_procedureKind* dst, cx_procedureKind* src);

cx_int16 cx_procedureKindInit(cx_procedureKind* value);
cx_int16 cx_procedureKindDeinit(cx_procedureKind* value);

/* ::corto::lang::sequence */
cx_sequence cx_sequenceCreate(cx_type elementType, cx_uint32 max);
cx_sequence cx_sequenceCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_sequence cx_sequenceDeclare(void);
cx_sequence cx_sequenceDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_sequenceDefine(cx_sequence this, cx_type elementType, cx_uint32 max);
void cx_sequenceUpdate(cx_sequence this, cx_type elementType, cx_uint32 max);
void cx_sequenceSet(cx_sequence this, cx_type elementType, cx_uint32 max);
cx_string cx_sequenceStr(cx_sequence value);
cx_sequence cx_sequenceFromStr(cx_sequence value, cx_string str);
cx_int16 cx_sequenceCopy(cx_sequence *dst, cx_sequence src);
cx_int16 cx_sequenceCompare(cx_sequence dst, cx_sequence src);

/* ::corto::lang::state */
cx_state* cx_stateCreate(cx_state value);
cx_state* cx_stateCreateChild(cx_object _parent, cx_string _name, cx_state value);

cx_state* cx_stateDeclare(void);
cx_state* cx_stateDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_stateDefine(cx_state* this, cx_state value);
void cx_stateUpdate(cx_state* this, cx_state value);
void cx_stateSet(cx_state* this, cx_state value);
cx_string cx_stateStr(cx_state value);
cx_state* cx_stateFromStr(cx_state* value, cx_string str);
cx_int16 cx_stateCopy(cx_state* *dst, cx_state* src);
cx_int16 cx_stateCompare(cx_state* dst, cx_state* src);

cx_int16 cx_stateInit(cx_state* value);
cx_int16 cx_stateDeinit(cx_state* value);

/* ::corto::lang::string */
cx_string* cx_stringCreate(cx_string value);
cx_string* cx_stringCreateChild(cx_object _parent, cx_string _name, cx_string value);

cx_string* cx_stringDeclare(void);
cx_string* cx_stringDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_stringDefine(cx_string* this, cx_string value);
void cx_stringUpdate(cx_string* this, cx_string value);
void cx_stringSet(cx_string* this, cx_string value);
cx_string cx_stringStr(cx_string value);
cx_string* cx_stringFromStr(cx_string* value, cx_string str);
cx_int16 cx_stringCopy(cx_string* *dst, cx_string* src);
cx_int16 cx_stringCompare(cx_string* dst, cx_string* src);

cx_int16 cx_stringInit(cx_string* value);
cx_int16 cx_stringDeinit(cx_string* value);

/* ::corto::lang::struct */
cx_struct cx_structCreate(cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_struct cx_structCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType);

cx_struct cx_structDeclare(void);
cx_struct cx_structDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_structDefine(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_structUpdate(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_structSet(cx_struct this, cx_interface base, cx_modifier baseAccess, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_string cx_structStr(cx_struct value);
cx_struct cx_structFromStr(cx_struct value, cx_string str);
cx_int16 cx_structCopy(cx_struct *dst, cx_struct src);
cx_int16 cx_structCompare(cx_struct dst, cx_struct src);

/* ::corto::lang::text */
cx_text cx_textCreate(cx_width charWidth, cx_uint64 length);
cx_text cx_textCreateChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length);

cx_text cx_textDeclare(void);
cx_text cx_textDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_textDefine(cx_text this, cx_width charWidth, cx_uint64 length);
void cx_textUpdate(cx_text this, cx_width charWidth, cx_uint64 length);
void cx_textSet(cx_text this, cx_width charWidth, cx_uint64 length);
cx_string cx_textStr(cx_text value);
cx_text cx_textFromStr(cx_text value, cx_string str);
cx_int16 cx_textCopy(cx_text *dst, cx_text src);
cx_int16 cx_textCompare(cx_text dst, cx_text src);

/* ::corto::lang::type */
cx_type cx_typeCreate(cx_type parentType, cx_state parentState, cx_type defaultType);
cx_type cx_typeCreateChild(cx_object _parent, cx_string _name, cx_type parentType, cx_state parentState, cx_type defaultType);

cx_type cx_typeDeclare(void);
cx_type cx_typeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_typeDefine(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_typeUpdate(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType);
void cx_typeSet(cx_type this, cx_type parentType, cx_state parentState, cx_type defaultType);
cx_string cx_typeStr(cx_type value);
cx_type cx_typeFromStr(cx_type value, cx_string str);
cx_int16 cx_typeCopy(cx_type *dst, cx_type src);
cx_int16 cx_typeCompare(cx_type dst, cx_type src);

/* ::corto::lang::typeKind */
cx_typeKind* cx_typeKindCreate(cx_typeKind value);
cx_typeKind* cx_typeKindCreateChild(cx_object _parent, cx_string _name, cx_typeKind value);

cx_typeKind* cx_typeKindDeclare(void);
cx_typeKind* cx_typeKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_typeKindDefine(cx_typeKind* this, cx_typeKind value);
void cx_typeKindUpdate(cx_typeKind* this, cx_typeKind value);
void cx_typeKindSet(cx_typeKind* this, cx_typeKind value);
cx_string cx_typeKindStr(cx_typeKind value);
cx_typeKind* cx_typeKindFromStr(cx_typeKind* value, cx_string str);
cx_int16 cx_typeKindCopy(cx_typeKind* *dst, cx_typeKind* src);
cx_int16 cx_typeKindCompare(cx_typeKind* dst, cx_typeKind* src);

cx_int16 cx_typeKindInit(cx_typeKind* value);
cx_int16 cx_typeKindDeinit(cx_typeKind* value);

/* ::corto::lang::uint */
cx_uint cx_uintCreate(cx_width width, cx_uint64 min, cx_uint64 max);
cx_uint cx_uintCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_uint64 min, cx_uint64 max);

cx_uint cx_uintDeclare(void);
cx_uint cx_uintDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uintDefine(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uintUpdate(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uintSet(cx_uint this, cx_width width, cx_uint64 min, cx_uint64 max);
cx_string cx_uintStr(cx_uint value);
cx_uint cx_uintFromStr(cx_uint value, cx_string str);
cx_int16 cx_uintCopy(cx_uint *dst, cx_uint src);
cx_int16 cx_uintCompare(cx_uint dst, cx_uint src);

/* ::corto::lang::uint16 */
cx_uint16* cx_uint16Create(cx_uint16 value);
cx_uint16* cx_uint16CreateChild(cx_object _parent, cx_string _name, cx_uint16 value);

cx_uint16* cx_uint16Declare(void);
cx_uint16* cx_uint16DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint16Define(cx_uint16* this, cx_uint16 value);
void cx_uint16Update(cx_uint16* this, cx_uint16 value);
void cx_uint16Set(cx_uint16* this, cx_uint16 value);
cx_string cx_uint16Str(cx_uint16 value);
cx_uint16* cx_uint16FromStr(cx_uint16* value, cx_string str);
cx_int16 cx_uint16Copy(cx_uint16* *dst, cx_uint16* src);
cx_int16 cx_uint16Compare(cx_uint16* dst, cx_uint16* src);

cx_int16 cx_uint16Init(cx_uint16* value);
cx_int16 cx_uint16Deinit(cx_uint16* value);

/* ::corto::lang::uint32 */
cx_uint32* cx_uint32Create(cx_uint32 value);
cx_uint32* cx_uint32CreateChild(cx_object _parent, cx_string _name, cx_uint32 value);

cx_uint32* cx_uint32Declare(void);
cx_uint32* cx_uint32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint32Define(cx_uint32* this, cx_uint32 value);
void cx_uint32Update(cx_uint32* this, cx_uint32 value);
void cx_uint32Set(cx_uint32* this, cx_uint32 value);
cx_string cx_uint32Str(cx_uint32 value);
cx_uint32* cx_uint32FromStr(cx_uint32* value, cx_string str);
cx_int16 cx_uint32Copy(cx_uint32* *dst, cx_uint32* src);
cx_int16 cx_uint32Compare(cx_uint32* dst, cx_uint32* src);

cx_int16 cx_uint32Init(cx_uint32* value);
cx_int16 cx_uint32Deinit(cx_uint32* value);

/* ::corto::lang::uint64 */
cx_uint64* cx_uint64Create(cx_uint64 value);
cx_uint64* cx_uint64CreateChild(cx_object _parent, cx_string _name, cx_uint64 value);

cx_uint64* cx_uint64Declare(void);
cx_uint64* cx_uint64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint64Define(cx_uint64* this, cx_uint64 value);
void cx_uint64Update(cx_uint64* this, cx_uint64 value);
void cx_uint64Set(cx_uint64* this, cx_uint64 value);
cx_string cx_uint64Str(cx_uint64 value);
cx_uint64* cx_uint64FromStr(cx_uint64* value, cx_string str);
cx_int16 cx_uint64Copy(cx_uint64* *dst, cx_uint64* src);
cx_int16 cx_uint64Compare(cx_uint64* dst, cx_uint64* src);

cx_int16 cx_uint64Init(cx_uint64* value);
cx_int16 cx_uint64Deinit(cx_uint64* value);

/* ::corto::lang::uint8 */
cx_uint8* cx_uint8Create(cx_uint8 value);
cx_uint8* cx_uint8CreateChild(cx_object _parent, cx_string _name, cx_uint8 value);

cx_uint8* cx_uint8Declare(void);
cx_uint8* cx_uint8DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint8Define(cx_uint8* this, cx_uint8 value);
void cx_uint8Update(cx_uint8* this, cx_uint8 value);
void cx_uint8Set(cx_uint8* this, cx_uint8 value);
cx_string cx_uint8Str(cx_uint8 value);
cx_uint8* cx_uint8FromStr(cx_uint8* value, cx_string str);
cx_int16 cx_uint8Copy(cx_uint8* *dst, cx_uint8* src);
cx_int16 cx_uint8Compare(cx_uint8* dst, cx_uint8* src);

cx_int16 cx_uint8Init(cx_uint8* value);
cx_int16 cx_uint8Deinit(cx_uint8* value);

/* ::corto::lang::virtual */
cx_virtual cx_virtualCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_virtual cx_virtualCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

cx_virtual cx_virtualDeclare(void);
cx_virtual cx_virtualDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_virtualDefine(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtualUpdate(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtualSet(cx_virtual this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string cx_virtualStr(cx_virtual value);
cx_virtual cx_virtualFromStr(cx_virtual value, cx_string str);
cx_int16 cx_virtualCopy(cx_virtual *dst, cx_virtual src);
cx_int16 cx_virtualCompare(cx_virtual dst, cx_virtual src);

/* ::corto::lang::void */
cx_void* cx_voidCreate(void);
cx_void* cx_voidCreateChild(cx_object _parent, cx_string _name);

/* ::corto::lang::vtable */
cx_vtable* cx_vtableCreate(void);
cx_vtable* cx_vtableCreateChild(cx_object _parent, cx_string _name);

cx_vtable* cx_vtableDeclare(void);
cx_vtable* cx_vtableDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_vtableDefine(cx_vtable* this, cx_vtable value);
void cx_vtableUpdate(cx_vtable* this, cx_vtable value);
void cx_vtableSet(cx_vtable* this, cx_vtable value);
cx_string cx_vtableStr(cx_vtable value);
cx_vtable* cx_vtableFromStr(cx_vtable* value, cx_string str);
cx_int16 cx_vtableCopy(cx_vtable* *dst, cx_vtable* src);
cx_int16 cx_vtableCompare(cx_vtable* dst, cx_vtable* src);

cx_int16 cx_vtableInit(cx_vtable* value);
cx_int16 cx_vtableDeinit(cx_vtable* value);

/* ::corto::lang::width */
cx_width* cx_widthCreate(cx_width value);
cx_width* cx_widthCreateChild(cx_object _parent, cx_string _name, cx_width value);

cx_width* cx_widthDeclare(void);
cx_width* cx_widthDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_widthDefine(cx_width* this, cx_width value);
void cx_widthUpdate(cx_width* this, cx_width value);
void cx_widthSet(cx_width* this, cx_width value);
cx_string cx_widthStr(cx_width value);
cx_width* cx_widthFromStr(cx_width* value, cx_string str);
cx_int16 cx_widthCopy(cx_width* *dst, cx_width* src);
cx_int16 cx_widthCompare(cx_width* dst, cx_width* src);

cx_int16 cx_widthInit(cx_width* value);
cx_int16 cx_widthDeinit(cx_width* value);

/* ::corto::lang::word */
cx_word* cx_wordCreate(cx_word value);
cx_word* cx_wordCreateChild(cx_object _parent, cx_string _name, cx_word value);

cx_word* cx_wordDeclare(void);
cx_word* cx_wordDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_wordDefine(cx_word* this, cx_word value);
void cx_wordUpdate(cx_word* this, cx_word value);
void cx_wordSet(cx_word* this, cx_word value);
cx_string cx_wordStr(cx_word value);
cx_word* cx_wordFromStr(cx_word* value, cx_string str);
cx_int16 cx_wordCopy(cx_word* *dst, cx_word* src);
cx_int16 cx_wordCompare(cx_word* dst, cx_word* src);

cx_int16 cx_wordInit(cx_word* value);
cx_int16 cx_wordDeinit(cx_word* value);


/* ::corto::lang::interfaceseq */
#define cx_interfaceseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interface elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_interface cx_interfaceseqAppend(cx_interfaceseq *seq);
void cx_interfaceseqSize(cx_interfaceseq *seq, cx_uint32 length);
void cx_interfaceseqClear(cx_interfaceseq *seq);

/* ::corto::lang::interfaceVectorseq */
#define cx_interfaceVectorseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interfaceVector elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_interfaceVector* cx_interfaceVectorseqAppend(cx_interfaceVectorseq *seq);
void cx_interfaceVectorseqSize(cx_interfaceVectorseq *seq, cx_uint32 length);
void cx_interfaceVectorseqClear(cx_interfaceVectorseq *seq);

/* ::corto::lang::memberseq */
#define cx_memberseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_member elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_member cx_memberseqAppend(cx_memberseq *seq);
void cx_memberseqSize(cx_memberseq *seq, cx_uint32 length);
void cx_memberseqClear(cx_memberseq *seq);

/* ::corto::lang::objectseq */
#define cx_objectseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_object elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_object cx_objectseqAppend(cx_objectseq *seq);
void cx_objectseqSize(cx_objectseq *seq, cx_uint32 length);
void cx_objectseqClear(cx_objectseq *seq);

/* ::corto::lang::observerseq */
#define cx_observerseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_observer elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_observer cx_observerseqAppend(cx_observerseq *seq);
void cx_observerseqSize(cx_observerseq *seq, cx_uint32 length);
void cx_observerseqClear(cx_observerseq *seq);

/* ::corto::lang::parameterseq */
#define cx_parameterseqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_parameter* cx_parameterseqAppend(cx_parameterseq *seq);
void cx_parameterseqSize(cx_parameterseq *seq, cx_uint32 length);
void cx_parameterseqClear(cx_parameterseq *seq);

/* ::corto::lang::vtable */
#define cx_vtableForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_function elem;\
    for(elem##_iter=0; elem = seq.buffer[elem##_iter], elem##_iter<seq.length; elem##_iter++)\

cx_function cx_vtableAppend(cx_vtable *seq);
void cx_vtableSize(cx_vtable *seq, cx_uint32 length);
void cx_vtableClear(cx_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

