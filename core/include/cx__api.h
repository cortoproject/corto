/* cx__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef cx__API_H
#define cx__API_H

#include "cx__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::lang::any */
cx_any* cx_anyCreate(void);
cx_any* cx_anyCreateChild(cx_object _parent, cx_string _name);

cx_any* cx_anyDeclare(void);
cx_any* cx_anyDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_anyDefine(cx_any* _this, cx_any value);
void cx_anyUpdate(cx_any* _this, cx_any value);
void cx_anySet(cx_any* _this, cx_any value);
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
cx_int16 cx_arrayDefine(cx_array _this, cx_type elementType, cx_uint32 max);
void cx_arrayUpdate(cx_array _this, cx_type elementType, cx_uint32 max);
void cx_arraySet(cx_array _this, cx_type elementType, cx_uint32 max);
cx_string cx_arrayStr(cx_array value);
cx_array cx_arrayFromStr(cx_array value, cx_string str);
cx_int16 cx_arrayCopy(cx_array *dst, cx_array src);
cx_int16 cx_arrayCompare(cx_array dst, cx_array src);

/* ::corto::lang::attr */
cx_attr* cx_attrCreate(void);
cx_attr* cx_attrCreateChild(cx_object _parent, cx_string _name);

cx_attr* cx_attrDeclare(void);
cx_attr* cx_attrDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_attrDefine(cx_attr* _this, cx_attr value);
void cx_attrUpdate(cx_attr* _this, cx_attr value);
void cx_attrSet(cx_attr* _this, cx_attr value);
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
cx_int16 cx_binaryDefine(cx_binary _this, cx_width width);
void cx_binaryUpdate(cx_binary _this, cx_width width);
void cx_binarySet(cx_binary _this, cx_width width);
cx_string cx_binaryStr(cx_binary value);
cx_binary cx_binaryFromStr(cx_binary value, cx_string str);
cx_int16 cx_binaryCopy(cx_binary *dst, cx_binary src);
cx_int16 cx_binaryCompare(cx_binary dst, cx_binary src);

/* ::corto::lang::bitmask */
cx_bitmask cx_bitmaskCreate(void);
cx_bitmask cx_bitmaskCreateChild(cx_object _parent, cx_string _name);

cx_bitmask cx_bitmaskDeclare(void);
cx_bitmask cx_bitmaskDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_bitmaskDefine(cx_bitmask _this);
void cx_bitmaskUpdate(cx_bitmask _this);
void cx_bitmaskSet(cx_bitmask _this);
cx_string cx_bitmaskStr(cx_bitmask value);
cx_bitmask cx_bitmaskFromStr(cx_bitmask value, cx_string str);
cx_int16 cx_bitmaskCopy(cx_bitmask *dst, cx_bitmask src);
cx_int16 cx_bitmaskCompare(cx_bitmask dst, cx_bitmask src);

/* ::corto::lang::bool */
cx_bool* cx_boolCreate(void);
cx_bool* cx_boolCreateChild(cx_object _parent, cx_string _name);

cx_bool* cx_boolDeclare(void);
cx_bool* cx_boolDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_boolDefine(cx_bool* _this, cx_bool value);
void cx_boolUpdate(cx_bool* _this, cx_bool value);
void cx_boolSet(cx_bool* _this, cx_bool value);
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
cx_int16 cx_booleanDefine(cx_boolean _this);
void cx_booleanUpdate(cx_boolean _this);
void cx_booleanSet(cx_boolean _this);
cx_string cx_booleanStr(cx_boolean value);
cx_boolean cx_booleanFromStr(cx_boolean value, cx_string str);
cx_int16 cx_booleanCopy(cx_boolean *dst, cx_boolean src);
cx_int16 cx_booleanCompare(cx_boolean dst, cx_boolean src);

/* ::corto::lang::callbackDestruct */
cx_callbackDestruct* cx_callbackDestructCreate(void);
cx_callbackDestruct* cx_callbackDestructCreateChild(cx_object _parent, cx_string _name);

cx_callbackDestruct* cx_callbackDestructDeclare(void);
cx_callbackDestruct* cx_callbackDestructDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_callbackDestructDefine(cx_callbackDestruct* _this);
void cx_callbackDestructUpdate(cx_callbackDestruct* _this);
void cx_callbackDestructSet(cx_callbackDestruct* _this);
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
cx_int16 cx_callbackInitDefine(cx_callbackInit* _this);
void cx_callbackInitUpdate(cx_callbackInit* _this);
void cx_callbackInitSet(cx_callbackInit* _this);
cx_string cx_callbackInitStr(cx_callbackInit* value);
cx_callbackInit* cx_callbackInitFromStr(cx_callbackInit* value, cx_string str);
cx_int16 cx_callbackInitCopy(cx_callbackInit* *dst, cx_callbackInit* src);
cx_int16 cx_callbackInitCompare(cx_callbackInit* dst, cx_callbackInit* src);

cx_int16 cx_callbackInitInit(cx_callbackInit* value);
cx_int16 cx_callbackInitDeinit(cx_callbackInit* value);

/* ::corto::lang::char */
cx_char* cx_charCreate(void);
cx_char* cx_charCreateChild(cx_object _parent, cx_string _name);

cx_char* cx_charDeclare(void);
cx_char* cx_charDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_charDefine(cx_char* _this, cx_char value);
void cx_charUpdate(cx_char* _this, cx_char value);
void cx_charSet(cx_char* _this, cx_char value);
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
cx_int16 cx_characterDefine(cx_character _this, cx_width width);
void cx_characterUpdate(cx_character _this, cx_width width);
void cx_characterSet(cx_character _this, cx_width width);
cx_string cx_characterStr(cx_character value);
cx_character cx_characterFromStr(cx_character value, cx_string str);
cx_int16 cx_characterCopy(cx_character *dst, cx_character src);
cx_int16 cx_characterCompare(cx_character dst, cx_character src);

/* ::corto::lang::class */
cx_class cx_classCreate(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_class cx_classCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);

cx_class cx_classDeclare(void);
cx_class cx_classDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_classDefine(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
void cx_classUpdate(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
void cx_classSet(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_string cx_classStr(cx_class value);
cx_class cx_classFromStr(cx_class value, cx_string str);
cx_int16 cx_classCopy(cx_class *dst, cx_class src);
cx_int16 cx_classCompare(cx_class dst, cx_class src);

/* ::corto::lang::collection */
cx_collection cx_collectionCreate(cx_type elementType, cx_uint32 max);
cx_collection cx_collectionCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_collection cx_collectionDeclare(void);
cx_collection cx_collectionDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collectionDefine(cx_collection _this, cx_type elementType, cx_uint32 max);
void cx_collectionUpdate(cx_collection _this, cx_type elementType, cx_uint32 max);
void cx_collectionSet(cx_collection _this, cx_type elementType, cx_uint32 max);
cx_string cx_collectionStr(cx_collection value);
cx_collection cx_collectionFromStr(cx_collection value, cx_string str);
cx_int16 cx_collectionCopy(cx_collection *dst, cx_collection src);
cx_int16 cx_collectionCompare(cx_collection dst, cx_collection src);

/* ::corto::lang::collectionKind */
cx_collectionKind* cx_collectionKindCreate(void);
cx_collectionKind* cx_collectionKindCreateChild(cx_object _parent, cx_string _name);

cx_collectionKind* cx_collectionKindDeclare(void);
cx_collectionKind* cx_collectionKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collectionKindDefine(cx_collectionKind* _this, cx_collectionKind value);
void cx_collectionKindUpdate(cx_collectionKind* _this, cx_collectionKind value);
void cx_collectionKindSet(cx_collectionKind* _this, cx_collectionKind value);
cx_string cx_collectionKindStr(cx_collectionKind value);
cx_collectionKind* cx_collectionKindFromStr(cx_collectionKind* value, cx_string str);
cx_int16 cx_collectionKindCopy(cx_collectionKind* *dst, cx_collectionKind* src);
cx_int16 cx_collectionKindCompare(cx_collectionKind* dst, cx_collectionKind* src);

cx_int16 cx_collectionKindInit(cx_collectionKind* value);
cx_int16 cx_collectionKindDeinit(cx_collectionKind* value);

/* ::corto::lang::compositeKind */
cx_compositeKind* cx_compositeKindCreate(void);
cx_compositeKind* cx_compositeKindCreateChild(cx_object _parent, cx_string _name);

cx_compositeKind* cx_compositeKindDeclare(void);
cx_compositeKind* cx_compositeKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_compositeKindDefine(cx_compositeKind* _this, cx_compositeKind value);
void cx_compositeKindUpdate(cx_compositeKind* _this, cx_compositeKind value);
void cx_compositeKindSet(cx_compositeKind* _this, cx_compositeKind value);
cx_string cx_compositeKindStr(cx_compositeKind value);
cx_compositeKind* cx_compositeKindFromStr(cx_compositeKind* value, cx_string str);
cx_int16 cx_compositeKindCopy(cx_compositeKind* *dst, cx_compositeKind* src);
cx_int16 cx_compositeKindCompare(cx_compositeKind* dst, cx_compositeKind* src);

cx_int16 cx_compositeKindInit(cx_compositeKind* value);
cx_int16 cx_compositeKindDeinit(cx_compositeKind* value);

/* ::corto::lang::constant */
cx_constant* cx_constantCreate(void);
cx_constant* cx_constantCreateChild(cx_object _parent, cx_string _name);

cx_constant* cx_constantDeclare(void);
cx_constant* cx_constantDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_constantDefine(cx_constant* _this, cx_constant value);
void cx_constantUpdate(cx_constant* _this, cx_constant value);
void cx_constantSet(cx_constant* _this, cx_constant value);
cx_string cx_constantStr(cx_constant value);
cx_constant* cx_constantFromStr(cx_constant* value, cx_string str);
cx_int16 cx_constantCopy(cx_constant* *dst, cx_constant* src);
cx_int16 cx_constantCompare(cx_constant* dst, cx_constant* src);

cx_int16 cx_constantInit(cx_constant* value);
cx_int16 cx_constantDeinit(cx_constant* value);

/* ::corto::lang::delegate */
cx_delegate cx_delegateCreate(cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_delegate cx_delegateCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);

cx_delegate cx_delegateDeclare(void);
cx_delegate cx_delegateDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegateDefine(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
void cx_delegateUpdate(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
void cx_delegateSet(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_string cx_delegateStr(cx_delegate value);
cx_delegate cx_delegateFromStr(cx_delegate value, cx_string str);
cx_int16 cx_delegateCopy(cx_delegate *dst, cx_delegate src);
cx_int16 cx_delegateCompare(cx_delegate dst, cx_delegate src);

/* ::corto::lang::delegatedata */
cx_delegatedata* cx_delegatedataCreate(cx_object instance, cx_function procedure);
cx_delegatedata* cx_delegatedataCreateChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

cx_delegatedata* cx_delegatedataDeclare(void);
cx_delegatedata* cx_delegatedataDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegatedataDefine(cx_delegatedata* _this, cx_object instance, cx_function procedure);
void cx_delegatedataUpdate(cx_delegatedata* _this, cx_object instance, cx_function procedure);
void cx_delegatedataSet(cx_delegatedata* _this, cx_object instance, cx_function procedure);
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
cx_int16 cx_dispatcherDefine(cx_dispatcher _this);
void cx_dispatcherUpdate(cx_dispatcher _this);
void cx_dispatcherSet(cx_dispatcher _this);
cx_string cx_dispatcherStr(cx_dispatcher value);
cx_dispatcher cx_dispatcherFromStr(cx_dispatcher value, cx_string str);
cx_int16 cx_dispatcherCopy(cx_dispatcher *dst, cx_dispatcher src);
cx_int16 cx_dispatcherCompare(cx_dispatcher dst, cx_dispatcher src);

/* ::corto::lang::enum */
cx_enum cx_enumCreate(void);
cx_enum cx_enumCreateChild(cx_object _parent, cx_string _name);

cx_enum cx_enumDeclare(void);
cx_enum cx_enumDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_enumDefine(cx_enum _this);
void cx_enumUpdate(cx_enum _this);
void cx_enumSet(cx_enum _this);
cx_string cx_enumStr(cx_enum value);
cx_enum cx_enumFromStr(cx_enum value, cx_string str);
cx_int16 cx_enumCopy(cx_enum *dst, cx_enum src);
cx_int16 cx_enumCompare(cx_enum dst, cx_enum src);

/* ::corto::lang::equalityKind */
cx_equalityKind* cx_equalityKindCreate(void);
cx_equalityKind* cx_equalityKindCreateChild(cx_object _parent, cx_string _name);

cx_equalityKind* cx_equalityKindDeclare(void);
cx_equalityKind* cx_equalityKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_equalityKindDefine(cx_equalityKind* _this, cx_equalityKind value);
void cx_equalityKindUpdate(cx_equalityKind* _this, cx_equalityKind value);
void cx_equalityKindSet(cx_equalityKind* _this, cx_equalityKind value);
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
cx_int16 cx_eventDefine(cx_event _this, cx_uint16 kind);
void cx_eventUpdate(cx_event _this, cx_uint16 kind);
void cx_eventSet(cx_event _this, cx_uint16 kind);
cx_string cx_eventStr(cx_event value);
cx_event cx_eventFromStr(cx_event value, cx_string str);
cx_int16 cx_eventCopy(cx_event *dst, cx_event src);
cx_int16 cx_eventCompare(cx_event dst, cx_event src);

/* ::corto::lang::eventMask */
cx_eventMask* cx_eventMaskCreate(void);
cx_eventMask* cx_eventMaskCreateChild(cx_object _parent, cx_string _name);

cx_eventMask* cx_eventMaskDeclare(void);
cx_eventMask* cx_eventMaskDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_eventMaskDefine(cx_eventMask* _this, cx_eventMask value);
void cx_eventMaskUpdate(cx_eventMask* _this, cx_eventMask value);
void cx_eventMaskSet(cx_eventMask* _this, cx_eventMask value);
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
cx_int16 cx_floatDefine(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
void cx_floatUpdate(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
void cx_floatSet(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
cx_string cx_floatStr(cx_float value);
cx_float cx_floatFromStr(cx_float value, cx_string str);
cx_int16 cx_floatCopy(cx_float *dst, cx_float src);
cx_int16 cx_floatCompare(cx_float dst, cx_float src);

/* ::corto::lang::float32 */
cx_float32* cx_float32Create(void);
cx_float32* cx_float32CreateChild(cx_object _parent, cx_string _name);

cx_float32* cx_float32Declare(void);
cx_float32* cx_float32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float32Define(cx_float32* _this, cx_float32 value);
void cx_float32Update(cx_float32* _this, cx_float32 value);
void cx_float32Set(cx_float32* _this, cx_float32 value);
cx_string cx_float32Str(cx_float32 value);
cx_float32* cx_float32FromStr(cx_float32* value, cx_string str);
cx_int16 cx_float32Copy(cx_float32* *dst, cx_float32* src);
cx_int16 cx_float32Compare(cx_float32* dst, cx_float32* src);

cx_int16 cx_float32Init(cx_float32* value);
cx_int16 cx_float32Deinit(cx_float32* value);

/* ::corto::lang::float64 */
cx_float64* cx_float64Create(void);
cx_float64* cx_float64CreateChild(cx_object _parent, cx_string _name);

cx_float64* cx_float64Declare(void);
cx_float64* cx_float64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float64Define(cx_float64* _this, cx_float64 value);
void cx_float64Update(cx_float64* _this, cx_float64 value);
void cx_float64Set(cx_float64* _this, cx_float64 value);
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
cx_int16 cx_functionDefine(cx_function _this, cx_type returnType, cx_bool returnsReference);
void cx_functionUpdate(cx_function _this, cx_type returnType, cx_bool returnsReference);
void cx_functionSet(cx_function _this, cx_type returnType, cx_bool returnsReference);
cx_string cx_functionStr(cx_function value);
cx_function cx_functionFromStr(cx_function value, cx_string str);
cx_int16 cx_functionCopy(cx_function *dst, cx_function src);
cx_int16 cx_functionCompare(cx_function dst, cx_function src);

/* ::corto::lang::int */
cx_int cx_intCreate(cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_intCreateChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max);

cx_int cx_intDeclare(void);
cx_int cx_intDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_intDefine(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
void cx_intUpdate(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
void cx_intSet(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
cx_string cx_intStr(cx_int value);
cx_int cx_intFromStr(cx_int value, cx_string str);
cx_int16 cx_intCopy(cx_int *dst, cx_int src);
cx_int16 cx_intCompare(cx_int dst, cx_int src);

/* ::corto::lang::int16 */
cx_int16* cx_int16Create(void);
cx_int16* cx_int16CreateChild(cx_object _parent, cx_string _name);

cx_int16* cx_int16Declare(void);
cx_int16* cx_int16DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int16Define(cx_int16* _this, cx_int16 value);
void cx_int16Update(cx_int16* _this, cx_int16 value);
void cx_int16Set(cx_int16* _this, cx_int16 value);
cx_string cx_int16Str(cx_int16 value);
cx_int16* cx_int16FromStr(cx_int16* value, cx_string str);
cx_int16 cx_int16Copy(cx_int16* *dst, cx_int16* src);
cx_int16 cx_int16Compare(cx_int16* dst, cx_int16* src);

cx_int16 cx_int16Init(cx_int16* value);
cx_int16 cx_int16Deinit(cx_int16* value);

/* ::corto::lang::int32 */
cx_int32* cx_int32Create(void);
cx_int32* cx_int32CreateChild(cx_object _parent, cx_string _name);

cx_int32* cx_int32Declare(void);
cx_int32* cx_int32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int32Define(cx_int32* _this, cx_int32 value);
void cx_int32Update(cx_int32* _this, cx_int32 value);
void cx_int32Set(cx_int32* _this, cx_int32 value);
cx_string cx_int32Str(cx_int32 value);
cx_int32* cx_int32FromStr(cx_int32* value, cx_string str);
cx_int16 cx_int32Copy(cx_int32* *dst, cx_int32* src);
cx_int16 cx_int32Compare(cx_int32* dst, cx_int32* src);

cx_int16 cx_int32Init(cx_int32* value);
cx_int16 cx_int32Deinit(cx_int32* value);

/* ::corto::lang::int64 */
cx_int64* cx_int64Create(void);
cx_int64* cx_int64CreateChild(cx_object _parent, cx_string _name);

cx_int64* cx_int64Declare(void);
cx_int64* cx_int64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int64Define(cx_int64* _this, cx_int64 value);
void cx_int64Update(cx_int64* _this, cx_int64 value);
void cx_int64Set(cx_int64* _this, cx_int64 value);
cx_string cx_int64Str(cx_int64 value);
cx_int64* cx_int64FromStr(cx_int64* value, cx_string str);
cx_int16 cx_int64Copy(cx_int64* *dst, cx_int64* src);
cx_int16 cx_int64Compare(cx_int64* dst, cx_int64* src);

cx_int16 cx_int64Init(cx_int64* value);
cx_int16 cx_int64Deinit(cx_int64* value);

/* ::corto::lang::int8 */
cx_int8* cx_int8Create(void);
cx_int8* cx_int8CreateChild(cx_object _parent, cx_string _name);

cx_int8* cx_int8Declare(void);
cx_int8* cx_int8DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int8Define(cx_int8* _this, cx_int8 value);
void cx_int8Update(cx_int8* _this, cx_int8 value);
void cx_int8Set(cx_int8* _this, cx_int8 value);
cx_string cx_int8Str(cx_int8 value);
cx_int8* cx_int8FromStr(cx_int8* value, cx_string str);
cx_int16 cx_int8Copy(cx_int8* *dst, cx_int8* src);
cx_int16 cx_int8Compare(cx_int8* dst, cx_int8* src);

cx_int16 cx_int8Init(cx_int8* value);
cx_int16 cx_int8Deinit(cx_int8* value);

/* ::corto::lang::interface */
cx_interface cx_interfaceCreate(cx_interface base);
cx_interface cx_interfaceCreateChild(cx_object _parent, cx_string _name, cx_interface base);

cx_interface cx_interfaceDeclare(void);
cx_interface cx_interfaceDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceDefine(cx_interface _this, cx_interface base);
void cx_interfaceUpdate(cx_interface _this, cx_interface base);
void cx_interfaceSet(cx_interface _this, cx_interface base);
cx_string cx_interfaceStr(cx_interface value);
cx_interface cx_interfaceFromStr(cx_interface value, cx_string str);
cx_int16 cx_interfaceCopy(cx_interface *dst, cx_interface src);
cx_int16 cx_interfaceCompare(cx_interface dst, cx_interface src);

/* ::corto::lang::interfaceSeq */
cx_interfaceSeq* cx_interfaceSeqCreate(void);
cx_interfaceSeq* cx_interfaceSeqCreateChild(cx_object _parent, cx_string _name);

cx_interfaceSeq* cx_interfaceSeqDeclare(void);
cx_interfaceSeq* cx_interfaceSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceSeqDefine(cx_interfaceSeq* _this, cx_interfaceSeq value);
void cx_interfaceSeqUpdate(cx_interfaceSeq* _this, cx_interfaceSeq value);
void cx_interfaceSeqSet(cx_interfaceSeq* _this, cx_interfaceSeq value);
cx_string cx_interfaceSeqStr(cx_interfaceSeq value);
cx_interfaceSeq* cx_interfaceSeqFromStr(cx_interfaceSeq* value, cx_string str);
cx_int16 cx_interfaceSeqCopy(cx_interfaceSeq* *dst, cx_interfaceSeq* src);
cx_int16 cx_interfaceSeqCompare(cx_interfaceSeq* dst, cx_interfaceSeq* src);

cx_int16 cx_interfaceSeqInit(cx_interfaceSeq* value);
cx_int16 cx_interfaceSeqDeinit(cx_interfaceSeq* value);

/* ::corto::lang::interfaceVector */
cx_interfaceVector* cx_interfaceVectorCreate(cx_interface interface, cx_vtable vector);
cx_interfaceVector* cx_interfaceVectorCreateChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector);

cx_interfaceVector* cx_interfaceVectorDeclare(void);
cx_interfaceVector* cx_interfaceVectorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVectorDefine(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
void cx_interfaceVectorUpdate(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
void cx_interfaceVectorSet(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
cx_string cx_interfaceVectorStr(cx_interfaceVector* value);
cx_interfaceVector* cx_interfaceVectorFromStr(cx_interfaceVector* value, cx_string str);
cx_int16 cx_interfaceVectorCopy(cx_interfaceVector* *dst, cx_interfaceVector* src);
cx_int16 cx_interfaceVectorCompare(cx_interfaceVector* dst, cx_interfaceVector* src);

cx_int16 cx_interfaceVectorInit(cx_interfaceVector* value);
cx_int16 cx_interfaceVectorDeinit(cx_interfaceVector* value);

/* ::corto::lang::interfaceVectorSeq */
cx_interfaceVectorSeq* cx_interfaceVectorSeqCreate(void);
cx_interfaceVectorSeq* cx_interfaceVectorSeqCreateChild(cx_object _parent, cx_string _name);

cx_interfaceVectorSeq* cx_interfaceVectorSeqDeclare(void);
cx_interfaceVectorSeq* cx_interfaceVectorSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVectorSeqDefine(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
void cx_interfaceVectorSeqUpdate(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
void cx_interfaceVectorSeqSet(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
cx_string cx_interfaceVectorSeqStr(cx_interfaceVectorSeq value);
cx_interfaceVectorSeq* cx_interfaceVectorSeqFromStr(cx_interfaceVectorSeq* value, cx_string str);
cx_int16 cx_interfaceVectorSeqCopy(cx_interfaceVectorSeq* *dst, cx_interfaceVectorSeq* src);
cx_int16 cx_interfaceVectorSeqCompare(cx_interfaceVectorSeq* dst, cx_interfaceVectorSeq* src);

cx_int16 cx_interfaceVectorSeqInit(cx_interfaceVectorSeq* value);
cx_int16 cx_interfaceVectorSeqDeinit(cx_interfaceVectorSeq* value);

/* ::corto::lang::iterator */
cx_iterator cx_iteratorCreate(cx_type elementType);
cx_iterator cx_iteratorCreateChild(cx_object _parent, cx_string _name, cx_type elementType);

cx_iterator cx_iteratorDeclare(void);
cx_iterator cx_iteratorDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_iteratorDefine(cx_iterator _this, cx_type elementType);
void cx_iteratorUpdate(cx_iterator _this, cx_type elementType);
void cx_iteratorSet(cx_iterator _this, cx_type elementType);
cx_string cx_iteratorStr(cx_iterator value);
cx_iterator cx_iteratorFromStr(cx_iterator value, cx_string str);
cx_int16 cx_iteratorCopy(cx_iterator *dst, cx_iterator src);
cx_int16 cx_iteratorCompare(cx_iterator dst, cx_iterator src);

/* ::corto::lang::list */
cx_list cx_listCreate(cx_type elementType, cx_uint32 max);
cx_list cx_listCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_list cx_listDeclare(void);
cx_list cx_listDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_listDefine(cx_list _this, cx_type elementType, cx_uint32 max);
void cx_listUpdate(cx_list _this, cx_type elementType, cx_uint32 max);
void cx_listSet(cx_list _this, cx_type elementType, cx_uint32 max);
cx_string cx_listStr(cx_list value);
cx_list cx_listFromStr(cx_list value, cx_string str);
cx_int16 cx_listCopy(cx_list *dst, cx_list src);
cx_int16 cx_listCompare(cx_list dst, cx_list src);

/* ::corto::lang::map */
cx_map cx_mapCreate(cx_type elementType, cx_type keyType, cx_uint32 max);
cx_map cx_mapCreateChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max);

cx_map cx_mapDeclare(void);
cx_map cx_mapDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_mapDefine(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_mapUpdate(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_mapSet(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
cx_string cx_mapStr(cx_map value);
cx_map cx_mapFromStr(cx_map value, cx_string str);
cx_int16 cx_mapCopy(cx_map *dst, cx_map src);
cx_int16 cx_mapCompare(cx_map dst, cx_map src);

/* ::corto::lang::member */
cx_member cx_memberCreate(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_memberCreateChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);

cx_member cx_memberDeclare(void);
cx_member cx_memberDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_memberDefine(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_memberUpdate(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_memberSet(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_string cx_memberStr(cx_member value);
cx_member cx_memberFromStr(cx_member value, cx_string str);
cx_int16 cx_memberCopy(cx_member *dst, cx_member src);
cx_int16 cx_memberCompare(cx_member dst, cx_member src);

/* ::corto::lang::memberSeq */
cx_memberSeq* cx_memberSeqCreate(void);
cx_memberSeq* cx_memberSeqCreateChild(cx_object _parent, cx_string _name);

cx_memberSeq* cx_memberSeqDeclare(void);
cx_memberSeq* cx_memberSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_memberSeqDefine(cx_memberSeq* _this, cx_memberSeq value);
void cx_memberSeqUpdate(cx_memberSeq* _this, cx_memberSeq value);
void cx_memberSeqSet(cx_memberSeq* _this, cx_memberSeq value);
cx_string cx_memberSeqStr(cx_memberSeq value);
cx_memberSeq* cx_memberSeqFromStr(cx_memberSeq* value, cx_string str);
cx_int16 cx_memberSeqCopy(cx_memberSeq* *dst, cx_memberSeq* src);
cx_int16 cx_memberSeqCompare(cx_memberSeq* dst, cx_memberSeq* src);

cx_int16 cx_memberSeqInit(cx_memberSeq* value);
cx_int16 cx_memberSeqDeinit(cx_memberSeq* value);

/* ::corto::lang::metaprocedure */
cx_metaprocedure cx_metaprocedureCreate(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedureCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);

cx_metaprocedure cx_metaprocedureDeclare(void);
cx_metaprocedure cx_metaprocedureDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_metaprocedureDefine(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedureUpdate(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedureSet(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_string cx_metaprocedureStr(cx_metaprocedure value);
cx_metaprocedure cx_metaprocedureFromStr(cx_metaprocedure value, cx_string str);
cx_int16 cx_metaprocedureCopy(cx_metaprocedure *dst, cx_metaprocedure src);
cx_int16 cx_metaprocedureCompare(cx_metaprocedure dst, cx_metaprocedure src);

/* ::corto::lang::method */
cx_method cx_methodCreate(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_methodCreateChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

cx_method cx_methodDeclare(void);
cx_method cx_methodDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_methodDefine(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_methodUpdate(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_methodSet(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string cx_methodStr(cx_method value);
cx_method cx_methodFromStr(cx_method value, cx_string str);
cx_int16 cx_methodCopy(cx_method *dst, cx_method src);
cx_int16 cx_methodCompare(cx_method dst, cx_method src);

/* ::corto::lang::modifier */
cx_modifier* cx_modifierCreate(void);
cx_modifier* cx_modifierCreateChild(cx_object _parent, cx_string _name);

cx_modifier* cx_modifierDeclare(void);
cx_modifier* cx_modifierDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_modifierDefine(cx_modifier* _this, cx_modifier value);
void cx_modifierUpdate(cx_modifier* _this, cx_modifier value);
void cx_modifierSet(cx_modifier* _this, cx_modifier value);
cx_string cx_modifierStr(cx_modifier value);
cx_modifier* cx_modifierFromStr(cx_modifier* value, cx_string str);
cx_int16 cx_modifierCopy(cx_modifier* *dst, cx_modifier* src);
cx_int16 cx_modifierCompare(cx_modifier* dst, cx_modifier* src);

cx_int16 cx_modifierInit(cx_modifier* value);
cx_int16 cx_modifierDeinit(cx_modifier* value);

/* ::corto::lang::object */
cx_object cx_objectCreate(void);
cx_object cx_objectCreateChild(cx_object _parent, cx_string _name);

/* ::corto::lang::objectSeq */
cx_objectSeq* cx_objectSeqCreate(void);
cx_objectSeq* cx_objectSeqCreateChild(cx_object _parent, cx_string _name);

cx_objectSeq* cx_objectSeqDeclare(void);
cx_objectSeq* cx_objectSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_objectSeqDefine(cx_objectSeq* _this, cx_objectSeq value);
void cx_objectSeqUpdate(cx_objectSeq* _this, cx_objectSeq value);
void cx_objectSeqSet(cx_objectSeq* _this, cx_objectSeq value);
cx_string cx_objectSeqStr(cx_objectSeq value);
cx_objectSeq* cx_objectSeqFromStr(cx_objectSeq* value, cx_string str);
cx_int16 cx_objectSeqCopy(cx_objectSeq* *dst, cx_objectSeq* src);
cx_int16 cx_objectSeqCompare(cx_objectSeq* dst, cx_objectSeq* src);

cx_int16 cx_objectSeqInit(cx_objectSeq* value);
cx_int16 cx_objectSeqDeinit(cx_objectSeq* value);

/* ::corto::lang::observableEvent */
cx_observableEvent cx_observableEventCreate(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEventCreateChild(cx_object _parent, cx_string _name, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);

cx_observableEvent cx_observableEventDeclare(void);
cx_observableEvent cx_observableEventDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observableEventDefine(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEventUpdate(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEventSet(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_string cx_observableEventStr(cx_observableEvent value);
cx_observableEvent cx_observableEventFromStr(cx_observableEvent value, cx_string str);
cx_int16 cx_observableEventCopy(cx_observableEvent *dst, cx_observableEvent src);
cx_int16 cx_observableEventCompare(cx_observableEvent dst, cx_observableEvent src);

/* ::corto::lang::observer */
cx_observer cx_observerCreate(cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observerCreateChild(cx_object _parent, cx_string _name, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);

cx_observer cx_observerDeclare(void);
cx_observer cx_observerDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observerDefine(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observerUpdate(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observerSet(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_string cx_observerStr(cx_observer value);
cx_observer cx_observerFromStr(cx_observer value, cx_string str);
cx_int16 cx_observerCopy(cx_observer *dst, cx_observer src);
cx_int16 cx_observerCompare(cx_observer dst, cx_observer src);

/* ::corto::lang::observerSeq */
cx_observerSeq* cx_observerSeqCreate(void);
cx_observerSeq* cx_observerSeqCreateChild(cx_object _parent, cx_string _name);

cx_observerSeq* cx_observerSeqDeclare(void);
cx_observerSeq* cx_observerSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observerSeqDefine(cx_observerSeq* _this, cx_observerSeq value);
void cx_observerSeqUpdate(cx_observerSeq* _this, cx_observerSeq value);
void cx_observerSeqSet(cx_observerSeq* _this, cx_observerSeq value);
cx_string cx_observerSeqStr(cx_observerSeq value);
cx_observerSeq* cx_observerSeqFromStr(cx_observerSeq* value, cx_string str);
cx_int16 cx_observerSeqCopy(cx_observerSeq* *dst, cx_observerSeq* src);
cx_int16 cx_observerSeqCompare(cx_observerSeq* dst, cx_observerSeq* src);

cx_int16 cx_observerSeqInit(cx_observerSeq* value);
cx_int16 cx_observerSeqDeinit(cx_observerSeq* value);

/* ::corto::lang::octet */
cx_octet* cx_octetCreate(void);
cx_octet* cx_octetCreateChild(cx_object _parent, cx_string _name);

cx_octet* cx_octetDeclare(void);
cx_octet* cx_octetDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_octetDefine(cx_octet* _this, cx_octet value);
void cx_octetUpdate(cx_octet* _this, cx_octet value);
void cx_octetSet(cx_octet* _this, cx_octet value);
cx_string cx_octetStr(cx_octet value);
cx_octet* cx_octetFromStr(cx_octet* value, cx_string str);
cx_int16 cx_octetCopy(cx_octet* *dst, cx_octet* src);
cx_int16 cx_octetCompare(cx_octet* dst, cx_octet* src);

cx_int16 cx_octetInit(cx_octet* value);
cx_int16 cx_octetDeinit(cx_octet* value);

/* ::corto::lang::operatorKind */
cx_operatorKind* cx_operatorKindCreate(void);
cx_operatorKind* cx_operatorKindCreateChild(cx_object _parent, cx_string _name);

cx_operatorKind* cx_operatorKindDeclare(void);
cx_operatorKind* cx_operatorKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_operatorKindDefine(cx_operatorKind* _this, cx_operatorKind value);
void cx_operatorKindUpdate(cx_operatorKind* _this, cx_operatorKind value);
void cx_operatorKindSet(cx_operatorKind* _this, cx_operatorKind value);
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
cx_int16 cx_packageDefine(cx_package _this, cx_string url);
void cx_packageUpdate(cx_package _this, cx_string url);
void cx_packageSet(cx_package _this, cx_string url);
cx_string cx_packageStr(cx_package value);
cx_package cx_packageFromStr(cx_package value, cx_string str);
cx_int16 cx_packageCopy(cx_package *dst, cx_package src);
cx_int16 cx_packageCompare(cx_package dst, cx_package src);

/* ::corto::lang::parameter */
cx_parameter* cx_parameterCreate(cx_string name, cx_type type, cx_bool passByReference);
cx_parameter* cx_parameterCreateChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference);

cx_parameter* cx_parameterDeclare(void);
cx_parameter* cx_parameterDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameterDefine(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameterUpdate(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameterSet(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
cx_string cx_parameterStr(cx_parameter* value);
cx_parameter* cx_parameterFromStr(cx_parameter* value, cx_string str);
cx_int16 cx_parameterCopy(cx_parameter* *dst, cx_parameter* src);
cx_int16 cx_parameterCompare(cx_parameter* dst, cx_parameter* src);

cx_int16 cx_parameterInit(cx_parameter* value);
cx_int16 cx_parameterDeinit(cx_parameter* value);

/* ::corto::lang::parameterSeq */
cx_parameterSeq* cx_parameterSeqCreate(void);
cx_parameterSeq* cx_parameterSeqCreateChild(cx_object _parent, cx_string _name);

cx_parameterSeq* cx_parameterSeqDeclare(void);
cx_parameterSeq* cx_parameterSeqDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameterSeqDefine(cx_parameterSeq* _this, cx_parameterSeq value);
void cx_parameterSeqUpdate(cx_parameterSeq* _this, cx_parameterSeq value);
void cx_parameterSeqSet(cx_parameterSeq* _this, cx_parameterSeq value);
cx_string cx_parameterSeqStr(cx_parameterSeq value);
cx_parameterSeq* cx_parameterSeqFromStr(cx_parameterSeq* value, cx_string str);
cx_int16 cx_parameterSeqCopy(cx_parameterSeq* *dst, cx_parameterSeq* src);
cx_int16 cx_parameterSeqCompare(cx_parameterSeq* dst, cx_parameterSeq* src);

cx_int16 cx_parameterSeqInit(cx_parameterSeq* value);
cx_int16 cx_parameterSeqDeinit(cx_parameterSeq* value);

/* ::corto::lang::primitive */
cx_primitive cx_primitiveCreate(cx_width width);
cx_primitive cx_primitiveCreateChild(cx_object _parent, cx_string _name, cx_width width);

cx_primitive cx_primitiveDeclare(void);
cx_primitive cx_primitiveDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitiveDefine(cx_primitive _this, cx_width width);
void cx_primitiveUpdate(cx_primitive _this, cx_width width);
void cx_primitiveSet(cx_primitive _this, cx_width width);
cx_string cx_primitiveStr(cx_primitive value);
cx_primitive cx_primitiveFromStr(cx_primitive value, cx_string str);
cx_int16 cx_primitiveCopy(cx_primitive *dst, cx_primitive src);
cx_int16 cx_primitiveCompare(cx_primitive dst, cx_primitive src);

/* ::corto::lang::primitiveKind */
cx_primitiveKind* cx_primitiveKindCreate(void);
cx_primitiveKind* cx_primitiveKindCreateChild(cx_object _parent, cx_string _name);

cx_primitiveKind* cx_primitiveKindDeclare(void);
cx_primitiveKind* cx_primitiveKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitiveKindDefine(cx_primitiveKind* _this, cx_primitiveKind value);
void cx_primitiveKindUpdate(cx_primitiveKind* _this, cx_primitiveKind value);
void cx_primitiveKindSet(cx_primitiveKind* _this, cx_primitiveKind value);
cx_string cx_primitiveKindStr(cx_primitiveKind value);
cx_primitiveKind* cx_primitiveKindFromStr(cx_primitiveKind* value, cx_string str);
cx_int16 cx_primitiveKindCopy(cx_primitiveKind* *dst, cx_primitiveKind* src);
cx_int16 cx_primitiveKindCompare(cx_primitiveKind* dst, cx_primitiveKind* src);

cx_int16 cx_primitiveKindInit(cx_primitiveKind* value);
cx_int16 cx_primitiveKindDeinit(cx_primitiveKind* value);

/* ::corto::lang::procedure */
cx_procedure cx_procedureCreate(cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_procedure cx_procedureCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);

cx_procedure cx_procedureDeclare(void);
cx_procedure cx_procedureDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedureDefine(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
void cx_procedureUpdate(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
void cx_procedureSet(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_string cx_procedureStr(cx_procedure value);
cx_procedure cx_procedureFromStr(cx_procedure value, cx_string str);
cx_int16 cx_procedureCopy(cx_procedure *dst, cx_procedure src);
cx_int16 cx_procedureCompare(cx_procedure dst, cx_procedure src);

/* ::corto::lang::procedureKind */
cx_procedureKind* cx_procedureKindCreate(void);
cx_procedureKind* cx_procedureKindCreateChild(cx_object _parent, cx_string _name);

cx_procedureKind* cx_procedureKindDeclare(void);
cx_procedureKind* cx_procedureKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedureKindDefine(cx_procedureKind* _this, cx_procedureKind value);
void cx_procedureKindUpdate(cx_procedureKind* _this, cx_procedureKind value);
void cx_procedureKindSet(cx_procedureKind* _this, cx_procedureKind value);
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
cx_int16 cx_sequenceDefine(cx_sequence _this, cx_type elementType, cx_uint32 max);
void cx_sequenceUpdate(cx_sequence _this, cx_type elementType, cx_uint32 max);
void cx_sequenceSet(cx_sequence _this, cx_type elementType, cx_uint32 max);
cx_string cx_sequenceStr(cx_sequence value);
cx_sequence cx_sequenceFromStr(cx_sequence value, cx_string str);
cx_int16 cx_sequenceCopy(cx_sequence *dst, cx_sequence src);
cx_int16 cx_sequenceCompare(cx_sequence dst, cx_sequence src);

/* ::corto::lang::state */
cx_state* cx_stateCreate(void);
cx_state* cx_stateCreateChild(cx_object _parent, cx_string _name);

cx_state* cx_stateDeclare(void);
cx_state* cx_stateDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_stateDefine(cx_state* _this, cx_state value);
void cx_stateUpdate(cx_state* _this, cx_state value);
void cx_stateSet(cx_state* _this, cx_state value);
cx_string cx_stateStr(cx_state value);
cx_state* cx_stateFromStr(cx_state* value, cx_string str);
cx_int16 cx_stateCopy(cx_state* *dst, cx_state* src);
cx_int16 cx_stateCompare(cx_state* dst, cx_state* src);

cx_int16 cx_stateInit(cx_state* value);
cx_int16 cx_stateDeinit(cx_state* value);

/* ::corto::lang::string */
cx_string* cx_stringCreate(void);
cx_string* cx_stringCreateChild(cx_object _parent, cx_string _name);

cx_string* cx_stringDeclare(void);
cx_string* cx_stringDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_stringDefine(cx_string* _this, cx_string value);
void cx_stringUpdate(cx_string* _this, cx_string value);
void cx_stringSet(cx_string* _this, cx_string value);
cx_string cx_stringStr(cx_string value);
cx_string* cx_stringFromStr(cx_string* value, cx_string str);
cx_int16 cx_stringCopy(cx_string* *dst, cx_string* src);
cx_int16 cx_stringCompare(cx_string* dst, cx_string* src);

cx_int16 cx_stringInit(cx_string* value);
cx_int16 cx_stringDeinit(cx_string* value);

/* ::corto::lang::struct */
cx_struct cx_structCreate(cx_interface base, cx_modifier baseAccess);
cx_struct cx_structCreateChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess);

cx_struct cx_structDeclare(void);
cx_struct cx_structDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_structDefine(cx_struct _this, cx_interface base, cx_modifier baseAccess);
void cx_structUpdate(cx_struct _this, cx_interface base, cx_modifier baseAccess);
void cx_structSet(cx_struct _this, cx_interface base, cx_modifier baseAccess);
cx_string cx_structStr(cx_struct value);
cx_struct cx_structFromStr(cx_struct value, cx_string str);
cx_int16 cx_structCopy(cx_struct *dst, cx_struct src);
cx_int16 cx_structCompare(cx_struct dst, cx_struct src);

/* ::corto::lang::text */
cx_text cx_textCreate(cx_width charWidth, cx_uint64 length);
cx_text cx_textCreateChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length);

cx_text cx_textDeclare(void);
cx_text cx_textDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_textDefine(cx_text _this, cx_width charWidth, cx_uint64 length);
void cx_textUpdate(cx_text _this, cx_width charWidth, cx_uint64 length);
void cx_textSet(cx_text _this, cx_width charWidth, cx_uint64 length);
cx_string cx_textStr(cx_text value);
cx_text cx_textFromStr(cx_text value, cx_string str);
cx_int16 cx_textCopy(cx_text *dst, cx_text src);
cx_int16 cx_textCompare(cx_text dst, cx_text src);

/* ::corto::lang::type */
cx_type cx_typeCreate(cx_type defaultType, cx_type parentType, cx_state parentState);
cx_type cx_typeCreateChild(cx_object _parent, cx_string _name, cx_type defaultType, cx_type parentType, cx_state parentState);

cx_type cx_typeDeclare(void);
cx_type cx_typeDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_typeDefine(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
void cx_typeUpdate(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
void cx_typeSet(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
cx_string cx_typeStr(cx_type value);
cx_type cx_typeFromStr(cx_type value, cx_string str);
cx_int16 cx_typeCopy(cx_type *dst, cx_type src);
cx_int16 cx_typeCompare(cx_type dst, cx_type src);

/* ::corto::lang::typeKind */
cx_typeKind* cx_typeKindCreate(void);
cx_typeKind* cx_typeKindCreateChild(cx_object _parent, cx_string _name);

cx_typeKind* cx_typeKindDeclare(void);
cx_typeKind* cx_typeKindDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_typeKindDefine(cx_typeKind* _this, cx_typeKind value);
void cx_typeKindUpdate(cx_typeKind* _this, cx_typeKind value);
void cx_typeKindSet(cx_typeKind* _this, cx_typeKind value);
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
cx_int16 cx_uintDefine(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uintUpdate(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uintSet(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
cx_string cx_uintStr(cx_uint value);
cx_uint cx_uintFromStr(cx_uint value, cx_string str);
cx_int16 cx_uintCopy(cx_uint *dst, cx_uint src);
cx_int16 cx_uintCompare(cx_uint dst, cx_uint src);

/* ::corto::lang::uint16 */
cx_uint16* cx_uint16Create(void);
cx_uint16* cx_uint16CreateChild(cx_object _parent, cx_string _name);

cx_uint16* cx_uint16Declare(void);
cx_uint16* cx_uint16DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint16Define(cx_uint16* _this, cx_uint16 value);
void cx_uint16Update(cx_uint16* _this, cx_uint16 value);
void cx_uint16Set(cx_uint16* _this, cx_uint16 value);
cx_string cx_uint16Str(cx_uint16 value);
cx_uint16* cx_uint16FromStr(cx_uint16* value, cx_string str);
cx_int16 cx_uint16Copy(cx_uint16* *dst, cx_uint16* src);
cx_int16 cx_uint16Compare(cx_uint16* dst, cx_uint16* src);

cx_int16 cx_uint16Init(cx_uint16* value);
cx_int16 cx_uint16Deinit(cx_uint16* value);

/* ::corto::lang::uint32 */
cx_uint32* cx_uint32Create(void);
cx_uint32* cx_uint32CreateChild(cx_object _parent, cx_string _name);

cx_uint32* cx_uint32Declare(void);
cx_uint32* cx_uint32DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint32Define(cx_uint32* _this, cx_uint32 value);
void cx_uint32Update(cx_uint32* _this, cx_uint32 value);
void cx_uint32Set(cx_uint32* _this, cx_uint32 value);
cx_string cx_uint32Str(cx_uint32 value);
cx_uint32* cx_uint32FromStr(cx_uint32* value, cx_string str);
cx_int16 cx_uint32Copy(cx_uint32* *dst, cx_uint32* src);
cx_int16 cx_uint32Compare(cx_uint32* dst, cx_uint32* src);

cx_int16 cx_uint32Init(cx_uint32* value);
cx_int16 cx_uint32Deinit(cx_uint32* value);

/* ::corto::lang::uint64 */
cx_uint64* cx_uint64Create(void);
cx_uint64* cx_uint64CreateChild(cx_object _parent, cx_string _name);

cx_uint64* cx_uint64Declare(void);
cx_uint64* cx_uint64DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint64Define(cx_uint64* _this, cx_uint64 value);
void cx_uint64Update(cx_uint64* _this, cx_uint64 value);
void cx_uint64Set(cx_uint64* _this, cx_uint64 value);
cx_string cx_uint64Str(cx_uint64 value);
cx_uint64* cx_uint64FromStr(cx_uint64* value, cx_string str);
cx_int16 cx_uint64Copy(cx_uint64* *dst, cx_uint64* src);
cx_int16 cx_uint64Compare(cx_uint64* dst, cx_uint64* src);

cx_int16 cx_uint64Init(cx_uint64* value);
cx_int16 cx_uint64Deinit(cx_uint64* value);

/* ::corto::lang::uint8 */
cx_uint8* cx_uint8Create(void);
cx_uint8* cx_uint8CreateChild(cx_object _parent, cx_string _name);

cx_uint8* cx_uint8Declare(void);
cx_uint8* cx_uint8DeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint8Define(cx_uint8* _this, cx_uint8 value);
void cx_uint8Update(cx_uint8* _this, cx_uint8 value);
void cx_uint8Set(cx_uint8* _this, cx_uint8 value);
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
cx_int16 cx_virtualDefine(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtualUpdate(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtualSet(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
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
cx_int16 cx_vtableDefine(cx_vtable* _this, cx_vtable value);
void cx_vtableUpdate(cx_vtable* _this, cx_vtable value);
void cx_vtableSet(cx_vtable* _this, cx_vtable value);
cx_string cx_vtableStr(cx_vtable value);
cx_vtable* cx_vtableFromStr(cx_vtable* value, cx_string str);
cx_int16 cx_vtableCopy(cx_vtable* *dst, cx_vtable* src);
cx_int16 cx_vtableCompare(cx_vtable* dst, cx_vtable* src);

cx_int16 cx_vtableInit(cx_vtable* value);
cx_int16 cx_vtableDeinit(cx_vtable* value);

/* ::corto::lang::width */
cx_width* cx_widthCreate(void);
cx_width* cx_widthCreateChild(cx_object _parent, cx_string _name);

cx_width* cx_widthDeclare(void);
cx_width* cx_widthDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_widthDefine(cx_width* _this, cx_width value);
void cx_widthUpdate(cx_width* _this, cx_width value);
void cx_widthSet(cx_width* _this, cx_width value);
cx_string cx_widthStr(cx_width value);
cx_width* cx_widthFromStr(cx_width* value, cx_string str);
cx_int16 cx_widthCopy(cx_width* *dst, cx_width* src);
cx_int16 cx_widthCompare(cx_width* dst, cx_width* src);

cx_int16 cx_widthInit(cx_width* value);
cx_int16 cx_widthDeinit(cx_width* value);

/* ::corto::lang::word */
cx_word* cx_wordCreate(void);
cx_word* cx_wordCreateChild(cx_object _parent, cx_string _name);

cx_word* cx_wordDeclare(void);
cx_word* cx_wordDeclareChild(cx_object _parent, cx_string _name);
cx_int16 cx_wordDefine(cx_word* _this, cx_word value);
void cx_wordUpdate(cx_word* _this, cx_word value);
void cx_wordSet(cx_word* _this, cx_word value);
cx_string cx_wordStr(cx_word value);
cx_word* cx_wordFromStr(cx_word* value, cx_string str);
cx_int16 cx_wordCopy(cx_word* *dst, cx_word* src);
cx_int16 cx_wordCompare(cx_word* dst, cx_word* src);

cx_int16 cx_wordInit(cx_word* value);
cx_int16 cx_wordDeinit(cx_word* value);


/* ::corto::lang::interfaceSeq */
#define cx_interfaceSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interface elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_interface cx_interfaceSeqAppend(cx_interfaceSeq *seq);
void cx_interfaceSeqSize(cx_interfaceSeq *seq, cx_uint32 length);
void cx_interfaceSeq__clear(cx_interfaceSeq *seq);

/* ::corto::lang::interfaceVectorSeq */
#define cx_interfaceVectorSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interfaceVector *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_interfaceVector* cx_interfaceVectorSeqAppend(cx_interfaceVectorSeq *seq);
void cx_interfaceVectorSeqSize(cx_interfaceVectorSeq *seq, cx_uint32 length);
void cx_interfaceVectorSeq__clear(cx_interfaceVectorSeq *seq);

/* ::corto::lang::memberSeq */
#define cx_memberSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_member elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_member cx_memberSeqAppend(cx_memberSeq *seq);
void cx_memberSeqSize(cx_memberSeq *seq, cx_uint32 length);
void cx_memberSeq__clear(cx_memberSeq *seq);

/* ::corto::lang::objectSeq */
#define cx_objectSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_object elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_object cx_objectSeqAppend(cx_objectSeq *seq);
void cx_objectSeqSize(cx_objectSeq *seq, cx_uint32 length);
void cx_objectSeq__clear(cx_objectSeq *seq);

/* ::corto::lang::observerSeq */
#define cx_observerSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_observer elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_observer cx_observerSeqAppend(cx_observerSeq *seq);
void cx_observerSeqSize(cx_observerSeq *seq, cx_uint32 length);
void cx_observerSeq__clear(cx_observerSeq *seq);

/* ::corto::lang::parameterSeq */
#define cx_parameterSeqForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_parameter* cx_parameterSeqAppend(cx_parameterSeq *seq);
void cx_parameterSeqSize(cx_parameterSeq *seq, cx_uint32 length);
void cx_parameterSeq__clear(cx_parameterSeq *seq);

/* ::corto::lang::vtable */
#define cx_vtableForeach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_function elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_function cx_vtableAppend(cx_vtable *seq);
void cx_vtableSize(cx_vtable *seq, cx_uint32 length);
void cx_vtable__clear(cx_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

