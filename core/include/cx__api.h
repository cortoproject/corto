/* cx__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef cx__API_H
#define cx__API_H

#include "cx__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::lang::any */
cx_any* cx_any__create(void);
cx_any* cx_any__createChild(cx_object _parent, cx_string _name);

cx_any* cx_any__declare(void);
cx_any* cx_any__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_any__define(cx_any* _this, cx_any value);
void cx_any__update(cx_any* _this, cx_any value);
void cx_any__set(cx_any* _this, cx_any value);
cx_string cx_any__str(cx_any value);
cx_any* cx_any__fromStr(cx_any* value, cx_string str);
cx_int16 cx_any__copy(cx_any* *dst, cx_any* src);
cx_int16 cx_any__compare(cx_any* dst, cx_any* src);

cx_int16 cx_any__init(cx_any* value);
cx_int16 cx_any__deinit(cx_any* value);

/* ::cortex::lang::array */
cx_array cx_array__create(cx_type elementType, cx_uint32 max);
cx_array cx_array__createChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_array cx_array__declare(void);
cx_array cx_array__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_array__define(cx_array _this, cx_type elementType, cx_uint32 max);
void cx_array__update(cx_array _this, cx_type elementType, cx_uint32 max);
void cx_array__set(cx_array _this, cx_type elementType, cx_uint32 max);
cx_string cx_array__str(cx_array value);
cx_array cx_array__fromStr(cx_array value, cx_string str);
cx_int16 cx_array__copy(cx_array *dst, cx_array src);
cx_int16 cx_array__compare(cx_array dst, cx_array src);

/* ::cortex::lang::attr */
cx_attr* cx_attr__create(void);
cx_attr* cx_attr__createChild(cx_object _parent, cx_string _name);

cx_attr* cx_attr__declare(void);
cx_attr* cx_attr__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_attr__define(cx_attr* _this, cx_attr value);
void cx_attr__update(cx_attr* _this, cx_attr value);
void cx_attr__set(cx_attr* _this, cx_attr value);
cx_string cx_attr__str(cx_attr value);
cx_attr* cx_attr__fromStr(cx_attr* value, cx_string str);
cx_int16 cx_attr__copy(cx_attr* *dst, cx_attr* src);
cx_int16 cx_attr__compare(cx_attr* dst, cx_attr* src);

cx_int16 cx_attr__init(cx_attr* value);
cx_int16 cx_attr__deinit(cx_attr* value);

/* ::cortex::lang::binary */
cx_binary cx_binary__create(cx_width width);
cx_binary cx_binary__createChild(cx_object _parent, cx_string _name, cx_width width);

cx_binary cx_binary__declare(void);
cx_binary cx_binary__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_binary__define(cx_binary _this, cx_width width);
void cx_binary__update(cx_binary _this, cx_width width);
void cx_binary__set(cx_binary _this, cx_width width);
cx_string cx_binary__str(cx_binary value);
cx_binary cx_binary__fromStr(cx_binary value, cx_string str);
cx_int16 cx_binary__copy(cx_binary *dst, cx_binary src);
cx_int16 cx_binary__compare(cx_binary dst, cx_binary src);

/* ::cortex::lang::bitmask */
cx_bitmask cx_bitmask__create(void);
cx_bitmask cx_bitmask__createChild(cx_object _parent, cx_string _name);

cx_bitmask cx_bitmask__declare(void);
cx_bitmask cx_bitmask__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_bitmask__define(cx_bitmask _this);
void cx_bitmask__update(cx_bitmask _this);
void cx_bitmask__set(cx_bitmask _this);
cx_string cx_bitmask__str(cx_bitmask value);
cx_bitmask cx_bitmask__fromStr(cx_bitmask value, cx_string str);
cx_int16 cx_bitmask__copy(cx_bitmask *dst, cx_bitmask src);
cx_int16 cx_bitmask__compare(cx_bitmask dst, cx_bitmask src);

/* ::cortex::lang::bool */
cx_bool* cx_bool__create(void);
cx_bool* cx_bool__createChild(cx_object _parent, cx_string _name);

cx_bool* cx_bool__declare(void);
cx_bool* cx_bool__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_bool__define(cx_bool* _this, cx_bool value);
void cx_bool__update(cx_bool* _this, cx_bool value);
void cx_bool__set(cx_bool* _this, cx_bool value);
cx_string cx_bool__str(cx_bool value);
cx_bool* cx_bool__fromStr(cx_bool* value, cx_string str);
cx_int16 cx_bool__copy(cx_bool* *dst, cx_bool* src);
cx_int16 cx_bool__compare(cx_bool* dst, cx_bool* src);

cx_int16 cx_bool__init(cx_bool* value);
cx_int16 cx_bool__deinit(cx_bool* value);

/* ::cortex::lang::boolean */
cx_boolean cx_boolean__create(void);
cx_boolean cx_boolean__createChild(cx_object _parent, cx_string _name);

cx_boolean cx_boolean__declare(void);
cx_boolean cx_boolean__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_boolean__define(cx_boolean _this);
void cx_boolean__update(cx_boolean _this);
void cx_boolean__set(cx_boolean _this);
cx_string cx_boolean__str(cx_boolean value);
cx_boolean cx_boolean__fromStr(cx_boolean value, cx_string str);
cx_int16 cx_boolean__copy(cx_boolean *dst, cx_boolean src);
cx_int16 cx_boolean__compare(cx_boolean dst, cx_boolean src);

/* ::cortex::lang::callbackDestruct */
cx_callbackDestruct* cx_callbackDestruct__create(void);
cx_callbackDestruct* cx_callbackDestruct__createChild(cx_object _parent, cx_string _name);

cx_callbackDestruct* cx_callbackDestruct__declare(void);
cx_callbackDestruct* cx_callbackDestruct__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_callbackDestruct__define(cx_callbackDestruct* _this);
void cx_callbackDestruct__update(cx_callbackDestruct* _this);
void cx_callbackDestruct__set(cx_callbackDestruct* _this);
cx_string cx_callbackDestruct__str(cx_callbackDestruct* value);
cx_callbackDestruct* cx_callbackDestruct__fromStr(cx_callbackDestruct* value, cx_string str);
cx_int16 cx_callbackDestruct__copy(cx_callbackDestruct* *dst, cx_callbackDestruct* src);
cx_int16 cx_callbackDestruct__compare(cx_callbackDestruct* dst, cx_callbackDestruct* src);

cx_int16 cx_callbackDestruct__init(cx_callbackDestruct* value);
cx_int16 cx_callbackDestruct__deinit(cx_callbackDestruct* value);

/* ::cortex::lang::callbackInit */
cx_callbackInit* cx_callbackInit__create(void);
cx_callbackInit* cx_callbackInit__createChild(cx_object _parent, cx_string _name);

cx_callbackInit* cx_callbackInit__declare(void);
cx_callbackInit* cx_callbackInit__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_callbackInit__define(cx_callbackInit* _this);
void cx_callbackInit__update(cx_callbackInit* _this);
void cx_callbackInit__set(cx_callbackInit* _this);
cx_string cx_callbackInit__str(cx_callbackInit* value);
cx_callbackInit* cx_callbackInit__fromStr(cx_callbackInit* value, cx_string str);
cx_int16 cx_callbackInit__copy(cx_callbackInit* *dst, cx_callbackInit* src);
cx_int16 cx_callbackInit__compare(cx_callbackInit* dst, cx_callbackInit* src);

cx_int16 cx_callbackInit__init(cx_callbackInit* value);
cx_int16 cx_callbackInit__deinit(cx_callbackInit* value);

/* ::cortex::lang::char */
cx_char* cx_char__create(void);
cx_char* cx_char__createChild(cx_object _parent, cx_string _name);

cx_char* cx_char__declare(void);
cx_char* cx_char__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_char__define(cx_char* _this, cx_char value);
void cx_char__update(cx_char* _this, cx_char value);
void cx_char__set(cx_char* _this, cx_char value);
cx_string cx_char__str(cx_char value);
cx_char* cx_char__fromStr(cx_char* value, cx_string str);
cx_int16 cx_char__copy(cx_char* *dst, cx_char* src);
cx_int16 cx_char__compare(cx_char* dst, cx_char* src);

cx_int16 cx_char__init(cx_char* value);
cx_int16 cx_char__deinit(cx_char* value);

/* ::cortex::lang::character */
cx_character cx_character__create(cx_width width);
cx_character cx_character__createChild(cx_object _parent, cx_string _name, cx_width width);

cx_character cx_character__declare(void);
cx_character cx_character__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_character__define(cx_character _this, cx_width width);
void cx_character__update(cx_character _this, cx_width width);
void cx_character__set(cx_character _this, cx_width width);
cx_string cx_character__str(cx_character value);
cx_character cx_character__fromStr(cx_character value, cx_string str);
cx_int16 cx_character__copy(cx_character *dst, cx_character src);
cx_int16 cx_character__compare(cx_character dst, cx_character src);

/* ::cortex::lang::class */
cx_class cx_class__create(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_class cx_class__createChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);

cx_class cx_class__declare(void);
cx_class cx_class__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_class__define(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
void cx_class__update(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
void cx_class__set(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_string cx_class__str(cx_class value);
cx_class cx_class__fromStr(cx_class value, cx_string str);
cx_int16 cx_class__copy(cx_class *dst, cx_class src);
cx_int16 cx_class__compare(cx_class dst, cx_class src);

/* ::cortex::lang::collection */
cx_collection cx_collection__create(cx_type elementType, cx_uint32 max);
cx_collection cx_collection__createChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_collection cx_collection__declare(void);
cx_collection cx_collection__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collection__define(cx_collection _this, cx_type elementType, cx_uint32 max);
void cx_collection__update(cx_collection _this, cx_type elementType, cx_uint32 max);
void cx_collection__set(cx_collection _this, cx_type elementType, cx_uint32 max);
cx_string cx_collection__str(cx_collection value);
cx_collection cx_collection__fromStr(cx_collection value, cx_string str);
cx_int16 cx_collection__copy(cx_collection *dst, cx_collection src);
cx_int16 cx_collection__compare(cx_collection dst, cx_collection src);

/* ::cortex::lang::collectionKind */
cx_collectionKind* cx_collectionKind__create(void);
cx_collectionKind* cx_collectionKind__createChild(cx_object _parent, cx_string _name);

cx_collectionKind* cx_collectionKind__declare(void);
cx_collectionKind* cx_collectionKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_collectionKind__define(cx_collectionKind* _this, cx_collectionKind value);
void cx_collectionKind__update(cx_collectionKind* _this, cx_collectionKind value);
void cx_collectionKind__set(cx_collectionKind* _this, cx_collectionKind value);
cx_string cx_collectionKind__str(cx_collectionKind value);
cx_collectionKind* cx_collectionKind__fromStr(cx_collectionKind* value, cx_string str);
cx_int16 cx_collectionKind__copy(cx_collectionKind* *dst, cx_collectionKind* src);
cx_int16 cx_collectionKind__compare(cx_collectionKind* dst, cx_collectionKind* src);

cx_int16 cx_collectionKind__init(cx_collectionKind* value);
cx_int16 cx_collectionKind__deinit(cx_collectionKind* value);

/* ::cortex::lang::compositeKind */
cx_compositeKind* cx_compositeKind__create(void);
cx_compositeKind* cx_compositeKind__createChild(cx_object _parent, cx_string _name);

cx_compositeKind* cx_compositeKind__declare(void);
cx_compositeKind* cx_compositeKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_compositeKind__define(cx_compositeKind* _this, cx_compositeKind value);
void cx_compositeKind__update(cx_compositeKind* _this, cx_compositeKind value);
void cx_compositeKind__set(cx_compositeKind* _this, cx_compositeKind value);
cx_string cx_compositeKind__str(cx_compositeKind value);
cx_compositeKind* cx_compositeKind__fromStr(cx_compositeKind* value, cx_string str);
cx_int16 cx_compositeKind__copy(cx_compositeKind* *dst, cx_compositeKind* src);
cx_int16 cx_compositeKind__compare(cx_compositeKind* dst, cx_compositeKind* src);

cx_int16 cx_compositeKind__init(cx_compositeKind* value);
cx_int16 cx_compositeKind__deinit(cx_compositeKind* value);

/* ::cortex::lang::constant */
cx_constant* cx_constant__create(void);
cx_constant* cx_constant__createChild(cx_object _parent, cx_string _name);

cx_constant* cx_constant__declare(void);
cx_constant* cx_constant__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_constant__define(cx_constant* _this, cx_constant value);
void cx_constant__update(cx_constant* _this, cx_constant value);
void cx_constant__set(cx_constant* _this, cx_constant value);
cx_string cx_constant__str(cx_constant value);
cx_constant* cx_constant__fromStr(cx_constant* value, cx_string str);
cx_int16 cx_constant__copy(cx_constant* *dst, cx_constant* src);
cx_int16 cx_constant__compare(cx_constant* dst, cx_constant* src);

cx_int16 cx_constant__init(cx_constant* value);
cx_int16 cx_constant__deinit(cx_constant* value);

/* ::cortex::lang::delegate */
cx_delegate cx_delegate__create(cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_delegate cx_delegate__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);

cx_delegate cx_delegate__declare(void);
cx_delegate cx_delegate__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegate__define(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
void cx_delegate__update(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
void cx_delegate__set(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_string cx_delegate__str(cx_delegate value);
cx_delegate cx_delegate__fromStr(cx_delegate value, cx_string str);
cx_int16 cx_delegate__copy(cx_delegate *dst, cx_delegate src);
cx_int16 cx_delegate__compare(cx_delegate dst, cx_delegate src);

/* ::cortex::lang::delegatedata */
cx_delegatedata* cx_delegatedata__create(cx_object instance, cx_function procedure);
cx_delegatedata* cx_delegatedata__createChild(cx_object _parent, cx_string _name, cx_object instance, cx_function procedure);

cx_delegatedata* cx_delegatedata__declare(void);
cx_delegatedata* cx_delegatedata__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_delegatedata__define(cx_delegatedata* _this, cx_object instance, cx_function procedure);
void cx_delegatedata__update(cx_delegatedata* _this, cx_object instance, cx_function procedure);
void cx_delegatedata__set(cx_delegatedata* _this, cx_object instance, cx_function procedure);
cx_string cx_delegatedata__str(cx_delegatedata* value);
cx_delegatedata* cx_delegatedata__fromStr(cx_delegatedata* value, cx_string str);
cx_int16 cx_delegatedata__copy(cx_delegatedata* *dst, cx_delegatedata* src);
cx_int16 cx_delegatedata__compare(cx_delegatedata* dst, cx_delegatedata* src);

cx_int16 cx_delegatedata__init(cx_delegatedata* value);
cx_int16 cx_delegatedata__deinit(cx_delegatedata* value);

/* ::cortex::lang::dispatcher */
cx_dispatcher cx_dispatcher__create(void);
cx_dispatcher cx_dispatcher__createChild(cx_object _parent, cx_string _name);

cx_dispatcher cx_dispatcher__declare(void);
cx_dispatcher cx_dispatcher__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_dispatcher__define(cx_dispatcher _this);
void cx_dispatcher__update(cx_dispatcher _this);
void cx_dispatcher__set(cx_dispatcher _this);
cx_string cx_dispatcher__str(cx_dispatcher value);
cx_dispatcher cx_dispatcher__fromStr(cx_dispatcher value, cx_string str);
cx_int16 cx_dispatcher__copy(cx_dispatcher *dst, cx_dispatcher src);
cx_int16 cx_dispatcher__compare(cx_dispatcher dst, cx_dispatcher src);

/* ::cortex::lang::enum */
cx_enum cx_enum__create(void);
cx_enum cx_enum__createChild(cx_object _parent, cx_string _name);

cx_enum cx_enum__declare(void);
cx_enum cx_enum__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_enum__define(cx_enum _this);
void cx_enum__update(cx_enum _this);
void cx_enum__set(cx_enum _this);
cx_string cx_enum__str(cx_enum value);
cx_enum cx_enum__fromStr(cx_enum value, cx_string str);
cx_int16 cx_enum__copy(cx_enum *dst, cx_enum src);
cx_int16 cx_enum__compare(cx_enum dst, cx_enum src);

/* ::cortex::lang::equalityKind */
cx_equalityKind* cx_equalityKind__create(void);
cx_equalityKind* cx_equalityKind__createChild(cx_object _parent, cx_string _name);

cx_equalityKind* cx_equalityKind__declare(void);
cx_equalityKind* cx_equalityKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_equalityKind__define(cx_equalityKind* _this, cx_equalityKind value);
void cx_equalityKind__update(cx_equalityKind* _this, cx_equalityKind value);
void cx_equalityKind__set(cx_equalityKind* _this, cx_equalityKind value);
cx_string cx_equalityKind__str(cx_equalityKind value);
cx_equalityKind* cx_equalityKind__fromStr(cx_equalityKind* value, cx_string str);
cx_int16 cx_equalityKind__copy(cx_equalityKind* *dst, cx_equalityKind* src);
cx_int16 cx_equalityKind__compare(cx_equalityKind* dst, cx_equalityKind* src);

cx_int16 cx_equalityKind__init(cx_equalityKind* value);
cx_int16 cx_equalityKind__deinit(cx_equalityKind* value);

/* ::cortex::lang::event */
cx_event cx_event__create(cx_uint16 kind);
cx_event cx_event__createChild(cx_object _parent, cx_string _name, cx_uint16 kind);

cx_event cx_event__declare(void);
cx_event cx_event__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_event__define(cx_event _this, cx_uint16 kind);
void cx_event__update(cx_event _this, cx_uint16 kind);
void cx_event__set(cx_event _this, cx_uint16 kind);
cx_string cx_event__str(cx_event value);
cx_event cx_event__fromStr(cx_event value, cx_string str);
cx_int16 cx_event__copy(cx_event *dst, cx_event src);
cx_int16 cx_event__compare(cx_event dst, cx_event src);

/* ::cortex::lang::eventMask */
cx_eventMask* cx_eventMask__create(void);
cx_eventMask* cx_eventMask__createChild(cx_object _parent, cx_string _name);

cx_eventMask* cx_eventMask__declare(void);
cx_eventMask* cx_eventMask__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_eventMask__define(cx_eventMask* _this, cx_eventMask value);
void cx_eventMask__update(cx_eventMask* _this, cx_eventMask value);
void cx_eventMask__set(cx_eventMask* _this, cx_eventMask value);
cx_string cx_eventMask__str(cx_eventMask value);
cx_eventMask* cx_eventMask__fromStr(cx_eventMask* value, cx_string str);
cx_int16 cx_eventMask__copy(cx_eventMask* *dst, cx_eventMask* src);
cx_int16 cx_eventMask__compare(cx_eventMask* dst, cx_eventMask* src);

cx_int16 cx_eventMask__init(cx_eventMask* value);
cx_int16 cx_eventMask__deinit(cx_eventMask* value);

/* ::cortex::lang::float */
cx_float cx_float__create(cx_width width, cx_float64 min, cx_float64 max);
cx_float cx_float__createChild(cx_object _parent, cx_string _name, cx_width width, cx_float64 min, cx_float64 max);

cx_float cx_float__declare(void);
cx_float cx_float__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float__define(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
void cx_float__update(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
void cx_float__set(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
cx_string cx_float__str(cx_float value);
cx_float cx_float__fromStr(cx_float value, cx_string str);
cx_int16 cx_float__copy(cx_float *dst, cx_float src);
cx_int16 cx_float__compare(cx_float dst, cx_float src);

/* ::cortex::lang::float32 */
cx_float32* cx_float32__create(void);
cx_float32* cx_float32__createChild(cx_object _parent, cx_string _name);

cx_float32* cx_float32__declare(void);
cx_float32* cx_float32__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float32__define(cx_float32* _this, cx_float32 value);
void cx_float32__update(cx_float32* _this, cx_float32 value);
void cx_float32__set(cx_float32* _this, cx_float32 value);
cx_string cx_float32__str(cx_float32 value);
cx_float32* cx_float32__fromStr(cx_float32* value, cx_string str);
cx_int16 cx_float32__copy(cx_float32* *dst, cx_float32* src);
cx_int16 cx_float32__compare(cx_float32* dst, cx_float32* src);

cx_int16 cx_float32__init(cx_float32* value);
cx_int16 cx_float32__deinit(cx_float32* value);

/* ::cortex::lang::float64 */
cx_float64* cx_float64__create(void);
cx_float64* cx_float64__createChild(cx_object _parent, cx_string _name);

cx_float64* cx_float64__declare(void);
cx_float64* cx_float64__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_float64__define(cx_float64* _this, cx_float64 value);
void cx_float64__update(cx_float64* _this, cx_float64 value);
void cx_float64__set(cx_float64* _this, cx_float64 value);
cx_string cx_float64__str(cx_float64 value);
cx_float64* cx_float64__fromStr(cx_float64* value, cx_string str);
cx_int16 cx_float64__copy(cx_float64* *dst, cx_float64* src);
cx_int16 cx_float64__compare(cx_float64* dst, cx_float64* src);

cx_int16 cx_float64__init(cx_float64* value);
cx_int16 cx_float64__deinit(cx_float64* value);

/* ::cortex::lang::function */
cx_function cx_function__create(cx_type returnType, cx_bool returnsReference);
cx_function cx_function__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference);

cx_function cx_function__declare(void);
cx_function cx_function__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_function__define(cx_function _this, cx_type returnType, cx_bool returnsReference);
void cx_function__update(cx_function _this, cx_type returnType, cx_bool returnsReference);
void cx_function__set(cx_function _this, cx_type returnType, cx_bool returnsReference);
cx_string cx_function__str(cx_function value);
cx_function cx_function__fromStr(cx_function value, cx_string str);
cx_int16 cx_function__copy(cx_function *dst, cx_function src);
cx_int16 cx_function__compare(cx_function dst, cx_function src);

/* ::cortex::lang::int */
cx_int cx_int__create(cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_int__createChild(cx_object _parent, cx_string _name, cx_width width, cx_int64 min, cx_int64 max);

cx_int cx_int__declare(void);
cx_int cx_int__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int__define(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
void cx_int__update(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
void cx_int__set(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
cx_string cx_int__str(cx_int value);
cx_int cx_int__fromStr(cx_int value, cx_string str);
cx_int16 cx_int__copy(cx_int *dst, cx_int src);
cx_int16 cx_int__compare(cx_int dst, cx_int src);

/* ::cortex::lang::int16 */
cx_int16* cx_int16__create(void);
cx_int16* cx_int16__createChild(cx_object _parent, cx_string _name);

cx_int16* cx_int16__declare(void);
cx_int16* cx_int16__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int16__define(cx_int16* _this, cx_int16 value);
void cx_int16__update(cx_int16* _this, cx_int16 value);
void cx_int16__set(cx_int16* _this, cx_int16 value);
cx_string cx_int16__str(cx_int16 value);
cx_int16* cx_int16__fromStr(cx_int16* value, cx_string str);
cx_int16 cx_int16__copy(cx_int16* *dst, cx_int16* src);
cx_int16 cx_int16__compare(cx_int16* dst, cx_int16* src);

cx_int16 cx_int16__init(cx_int16* value);
cx_int16 cx_int16__deinit(cx_int16* value);

/* ::cortex::lang::int32 */
cx_int32* cx_int32__create(void);
cx_int32* cx_int32__createChild(cx_object _parent, cx_string _name);

cx_int32* cx_int32__declare(void);
cx_int32* cx_int32__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int32__define(cx_int32* _this, cx_int32 value);
void cx_int32__update(cx_int32* _this, cx_int32 value);
void cx_int32__set(cx_int32* _this, cx_int32 value);
cx_string cx_int32__str(cx_int32 value);
cx_int32* cx_int32__fromStr(cx_int32* value, cx_string str);
cx_int16 cx_int32__copy(cx_int32* *dst, cx_int32* src);
cx_int16 cx_int32__compare(cx_int32* dst, cx_int32* src);

cx_int16 cx_int32__init(cx_int32* value);
cx_int16 cx_int32__deinit(cx_int32* value);

/* ::cortex::lang::int64 */
cx_int64* cx_int64__create(void);
cx_int64* cx_int64__createChild(cx_object _parent, cx_string _name);

cx_int64* cx_int64__declare(void);
cx_int64* cx_int64__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int64__define(cx_int64* _this, cx_int64 value);
void cx_int64__update(cx_int64* _this, cx_int64 value);
void cx_int64__set(cx_int64* _this, cx_int64 value);
cx_string cx_int64__str(cx_int64 value);
cx_int64* cx_int64__fromStr(cx_int64* value, cx_string str);
cx_int16 cx_int64__copy(cx_int64* *dst, cx_int64* src);
cx_int16 cx_int64__compare(cx_int64* dst, cx_int64* src);

cx_int16 cx_int64__init(cx_int64* value);
cx_int16 cx_int64__deinit(cx_int64* value);

/* ::cortex::lang::int8 */
cx_int8* cx_int8__create(void);
cx_int8* cx_int8__createChild(cx_object _parent, cx_string _name);

cx_int8* cx_int8__declare(void);
cx_int8* cx_int8__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_int8__define(cx_int8* _this, cx_int8 value);
void cx_int8__update(cx_int8* _this, cx_int8 value);
void cx_int8__set(cx_int8* _this, cx_int8 value);
cx_string cx_int8__str(cx_int8 value);
cx_int8* cx_int8__fromStr(cx_int8* value, cx_string str);
cx_int16 cx_int8__copy(cx_int8* *dst, cx_int8* src);
cx_int16 cx_int8__compare(cx_int8* dst, cx_int8* src);

cx_int16 cx_int8__init(cx_int8* value);
cx_int16 cx_int8__deinit(cx_int8* value);

/* ::cortex::lang::interface */
cx_interface cx_interface__create(cx_interface base);
cx_interface cx_interface__createChild(cx_object _parent, cx_string _name, cx_interface base);

cx_interface cx_interface__declare(void);
cx_interface cx_interface__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interface__define(cx_interface _this, cx_interface base);
void cx_interface__update(cx_interface _this, cx_interface base);
void cx_interface__set(cx_interface _this, cx_interface base);
cx_string cx_interface__str(cx_interface value);
cx_interface cx_interface__fromStr(cx_interface value, cx_string str);
cx_int16 cx_interface__copy(cx_interface *dst, cx_interface src);
cx_int16 cx_interface__compare(cx_interface dst, cx_interface src);

/* ::cortex::lang::interfaceSeq */
cx_interfaceSeq* cx_interfaceSeq__create(void);
cx_interfaceSeq* cx_interfaceSeq__createChild(cx_object _parent, cx_string _name);

cx_interfaceSeq* cx_interfaceSeq__declare(void);
cx_interfaceSeq* cx_interfaceSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceSeq__define(cx_interfaceSeq* _this, cx_interfaceSeq value);
void cx_interfaceSeq__update(cx_interfaceSeq* _this, cx_interfaceSeq value);
void cx_interfaceSeq__set(cx_interfaceSeq* _this, cx_interfaceSeq value);
cx_string cx_interfaceSeq__str(cx_interfaceSeq value);
cx_interfaceSeq* cx_interfaceSeq__fromStr(cx_interfaceSeq* value, cx_string str);
cx_int16 cx_interfaceSeq__copy(cx_interfaceSeq* *dst, cx_interfaceSeq* src);
cx_int16 cx_interfaceSeq__compare(cx_interfaceSeq* dst, cx_interfaceSeq* src);

cx_int16 cx_interfaceSeq__init(cx_interfaceSeq* value);
cx_int16 cx_interfaceSeq__deinit(cx_interfaceSeq* value);

/* ::cortex::lang::interfaceVector */
cx_interfaceVector* cx_interfaceVector__create(cx_interface interface, cx_vtable vector);
cx_interfaceVector* cx_interfaceVector__createChild(cx_object _parent, cx_string _name, cx_interface interface, cx_vtable vector);

cx_interfaceVector* cx_interfaceVector__declare(void);
cx_interfaceVector* cx_interfaceVector__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVector__define(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
void cx_interfaceVector__update(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
void cx_interfaceVector__set(cx_interfaceVector* _this, cx_interface interface, cx_vtable vector);
cx_string cx_interfaceVector__str(cx_interfaceVector* value);
cx_interfaceVector* cx_interfaceVector__fromStr(cx_interfaceVector* value, cx_string str);
cx_int16 cx_interfaceVector__copy(cx_interfaceVector* *dst, cx_interfaceVector* src);
cx_int16 cx_interfaceVector__compare(cx_interfaceVector* dst, cx_interfaceVector* src);

cx_int16 cx_interfaceVector__init(cx_interfaceVector* value);
cx_int16 cx_interfaceVector__deinit(cx_interfaceVector* value);

/* ::cortex::lang::interfaceVectorSeq */
cx_interfaceVectorSeq* cx_interfaceVectorSeq__create(void);
cx_interfaceVectorSeq* cx_interfaceVectorSeq__createChild(cx_object _parent, cx_string _name);

cx_interfaceVectorSeq* cx_interfaceVectorSeq__declare(void);
cx_interfaceVectorSeq* cx_interfaceVectorSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_interfaceVectorSeq__define(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
void cx_interfaceVectorSeq__update(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
void cx_interfaceVectorSeq__set(cx_interfaceVectorSeq* _this, cx_interfaceVectorSeq value);
cx_string cx_interfaceVectorSeq__str(cx_interfaceVectorSeq value);
cx_interfaceVectorSeq* cx_interfaceVectorSeq__fromStr(cx_interfaceVectorSeq* value, cx_string str);
cx_int16 cx_interfaceVectorSeq__copy(cx_interfaceVectorSeq* *dst, cx_interfaceVectorSeq* src);
cx_int16 cx_interfaceVectorSeq__compare(cx_interfaceVectorSeq* dst, cx_interfaceVectorSeq* src);

cx_int16 cx_interfaceVectorSeq__init(cx_interfaceVectorSeq* value);
cx_int16 cx_interfaceVectorSeq__deinit(cx_interfaceVectorSeq* value);

/* ::cortex::lang::iterator */
cx_iterator cx_iterator__create(cx_type elementType);
cx_iterator cx_iterator__createChild(cx_object _parent, cx_string _name, cx_type elementType);

cx_iterator cx_iterator__declare(void);
cx_iterator cx_iterator__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_iterator__define(cx_iterator _this, cx_type elementType);
void cx_iterator__update(cx_iterator _this, cx_type elementType);
void cx_iterator__set(cx_iterator _this, cx_type elementType);
cx_string cx_iterator__str(cx_iterator value);
cx_iterator cx_iterator__fromStr(cx_iterator value, cx_string str);
cx_int16 cx_iterator__copy(cx_iterator *dst, cx_iterator src);
cx_int16 cx_iterator__compare(cx_iterator dst, cx_iterator src);

/* ::cortex::lang::list */
cx_list cx_list__create(cx_type elementType, cx_uint32 max);
cx_list cx_list__createChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_list cx_list__declare(void);
cx_list cx_list__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_list__define(cx_list _this, cx_type elementType, cx_uint32 max);
void cx_list__update(cx_list _this, cx_type elementType, cx_uint32 max);
void cx_list__set(cx_list _this, cx_type elementType, cx_uint32 max);
cx_string cx_list__str(cx_list value);
cx_list cx_list__fromStr(cx_list value, cx_string str);
cx_int16 cx_list__copy(cx_list *dst, cx_list src);
cx_int16 cx_list__compare(cx_list dst, cx_list src);

/* ::cortex::lang::map */
cx_map cx_map__create(cx_type elementType, cx_type keyType, cx_uint32 max);
cx_map cx_map__createChild(cx_object _parent, cx_string _name, cx_type elementType, cx_type keyType, cx_uint32 max);

cx_map cx_map__declare(void);
cx_map cx_map__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_map__define(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_map__update(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
void cx_map__set(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
cx_string cx_map__str(cx_map value);
cx_map cx_map__fromStr(cx_map value, cx_string str);
cx_int16 cx_map__copy(cx_map *dst, cx_map src);
cx_int16 cx_map__compare(cx_map dst, cx_map src);

/* ::cortex::lang::member */
cx_member cx_member__create(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_member__createChild(cx_object _parent, cx_string _name, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);

cx_member cx_member__declare(void);
cx_member cx_member__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_member__define(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_member__update(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
void cx_member__set(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_string cx_member__str(cx_member value);
cx_member cx_member__fromStr(cx_member value, cx_string str);
cx_int16 cx_member__copy(cx_member *dst, cx_member src);
cx_int16 cx_member__compare(cx_member dst, cx_member src);

/* ::cortex::lang::memberSeq */
cx_memberSeq* cx_memberSeq__create(void);
cx_memberSeq* cx_memberSeq__createChild(cx_object _parent, cx_string _name);

cx_memberSeq* cx_memberSeq__declare(void);
cx_memberSeq* cx_memberSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_memberSeq__define(cx_memberSeq* _this, cx_memberSeq value);
void cx_memberSeq__update(cx_memberSeq* _this, cx_memberSeq value);
void cx_memberSeq__set(cx_memberSeq* _this, cx_memberSeq value);
cx_string cx_memberSeq__str(cx_memberSeq value);
cx_memberSeq* cx_memberSeq__fromStr(cx_memberSeq* value, cx_string str);
cx_int16 cx_memberSeq__copy(cx_memberSeq* *dst, cx_memberSeq* src);
cx_int16 cx_memberSeq__compare(cx_memberSeq* dst, cx_memberSeq* src);

cx_int16 cx_memberSeq__init(cx_memberSeq* value);
cx_int16 cx_memberSeq__deinit(cx_memberSeq* value);

/* ::cortex::lang::metaprocedure */
cx_metaprocedure cx_metaprocedure__create(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedure__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);

cx_metaprocedure cx_metaprocedure__declare(void);
cx_metaprocedure cx_metaprocedure__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_metaprocedure__define(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedure__update(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
void cx_metaprocedure__set(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_string cx_metaprocedure__str(cx_metaprocedure value);
cx_metaprocedure cx_metaprocedure__fromStr(cx_metaprocedure value, cx_string str);
cx_int16 cx_metaprocedure__copy(cx_metaprocedure *dst, cx_metaprocedure src);
cx_int16 cx_metaprocedure__compare(cx_metaprocedure dst, cx_metaprocedure src);

/* ::cortex::lang::method */
cx_method cx_method__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_method__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

cx_method cx_method__declare(void);
cx_method cx_method__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_method__define(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_method__update(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_method__set(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string cx_method__str(cx_method value);
cx_method cx_method__fromStr(cx_method value, cx_string str);
cx_int16 cx_method__copy(cx_method *dst, cx_method src);
cx_int16 cx_method__compare(cx_method dst, cx_method src);

/* ::cortex::lang::modifier */
cx_modifier* cx_modifier__create(void);
cx_modifier* cx_modifier__createChild(cx_object _parent, cx_string _name);

cx_modifier* cx_modifier__declare(void);
cx_modifier* cx_modifier__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_modifier__define(cx_modifier* _this, cx_modifier value);
void cx_modifier__update(cx_modifier* _this, cx_modifier value);
void cx_modifier__set(cx_modifier* _this, cx_modifier value);
cx_string cx_modifier__str(cx_modifier value);
cx_modifier* cx_modifier__fromStr(cx_modifier* value, cx_string str);
cx_int16 cx_modifier__copy(cx_modifier* *dst, cx_modifier* src);
cx_int16 cx_modifier__compare(cx_modifier* dst, cx_modifier* src);

cx_int16 cx_modifier__init(cx_modifier* value);
cx_int16 cx_modifier__deinit(cx_modifier* value);

/* ::cortex::lang::object */
cx_object cx_object__create(void);
cx_object cx_object__createChild(cx_object _parent, cx_string _name);

/* ::cortex::lang::objectSeq */
cx_objectSeq* cx_objectSeq__create(void);
cx_objectSeq* cx_objectSeq__createChild(cx_object _parent, cx_string _name);

cx_objectSeq* cx_objectSeq__declare(void);
cx_objectSeq* cx_objectSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_objectSeq__define(cx_objectSeq* _this, cx_objectSeq value);
void cx_objectSeq__update(cx_objectSeq* _this, cx_objectSeq value);
void cx_objectSeq__set(cx_objectSeq* _this, cx_objectSeq value);
cx_string cx_objectSeq__str(cx_objectSeq value);
cx_objectSeq* cx_objectSeq__fromStr(cx_objectSeq* value, cx_string str);
cx_int16 cx_objectSeq__copy(cx_objectSeq* *dst, cx_objectSeq* src);
cx_int16 cx_objectSeq__compare(cx_objectSeq* dst, cx_objectSeq* src);

cx_int16 cx_objectSeq__init(cx_objectSeq* value);
cx_int16 cx_objectSeq__deinit(cx_objectSeq* value);

/* ::cortex::lang::observableEvent */
cx_observableEvent cx_observableEvent__create(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEvent__createChild(cx_object _parent, cx_string _name, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);

cx_observableEvent cx_observableEvent__declare(void);
cx_observableEvent cx_observableEvent__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observableEvent__define(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEvent__update(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
void cx_observableEvent__set(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_string cx_observableEvent__str(cx_observableEvent value);
cx_observableEvent cx_observableEvent__fromStr(cx_observableEvent value, cx_string str);
cx_int16 cx_observableEvent__copy(cx_observableEvent *dst, cx_observableEvent src);
cx_int16 cx_observableEvent__compare(cx_observableEvent dst, cx_observableEvent src);

/* ::cortex::lang::observer */
cx_observer cx_observer__create(cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observer__createChild(cx_object _parent, cx_string _name, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);

cx_observer cx_observer__declare(void);
cx_observer cx_observer__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observer__define(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observer__update(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
void cx_observer__set(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_string cx_observer__str(cx_observer value);
cx_observer cx_observer__fromStr(cx_observer value, cx_string str);
cx_int16 cx_observer__copy(cx_observer *dst, cx_observer src);
cx_int16 cx_observer__compare(cx_observer dst, cx_observer src);

/* ::cortex::lang::observerSeq */
cx_observerSeq* cx_observerSeq__create(void);
cx_observerSeq* cx_observerSeq__createChild(cx_object _parent, cx_string _name);

cx_observerSeq* cx_observerSeq__declare(void);
cx_observerSeq* cx_observerSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_observerSeq__define(cx_observerSeq* _this, cx_observerSeq value);
void cx_observerSeq__update(cx_observerSeq* _this, cx_observerSeq value);
void cx_observerSeq__set(cx_observerSeq* _this, cx_observerSeq value);
cx_string cx_observerSeq__str(cx_observerSeq value);
cx_observerSeq* cx_observerSeq__fromStr(cx_observerSeq* value, cx_string str);
cx_int16 cx_observerSeq__copy(cx_observerSeq* *dst, cx_observerSeq* src);
cx_int16 cx_observerSeq__compare(cx_observerSeq* dst, cx_observerSeq* src);

cx_int16 cx_observerSeq__init(cx_observerSeq* value);
cx_int16 cx_observerSeq__deinit(cx_observerSeq* value);

/* ::cortex::lang::octet */
cx_octet* cx_octet__create(void);
cx_octet* cx_octet__createChild(cx_object _parent, cx_string _name);

cx_octet* cx_octet__declare(void);
cx_octet* cx_octet__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_octet__define(cx_octet* _this, cx_octet value);
void cx_octet__update(cx_octet* _this, cx_octet value);
void cx_octet__set(cx_octet* _this, cx_octet value);
cx_string cx_octet__str(cx_octet value);
cx_octet* cx_octet__fromStr(cx_octet* value, cx_string str);
cx_int16 cx_octet__copy(cx_octet* *dst, cx_octet* src);
cx_int16 cx_octet__compare(cx_octet* dst, cx_octet* src);

cx_int16 cx_octet__init(cx_octet* value);
cx_int16 cx_octet__deinit(cx_octet* value);

/* ::cortex::lang::operatorKind */
cx_operatorKind* cx_operatorKind__create(void);
cx_operatorKind* cx_operatorKind__createChild(cx_object _parent, cx_string _name);

cx_operatorKind* cx_operatorKind__declare(void);
cx_operatorKind* cx_operatorKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_operatorKind__define(cx_operatorKind* _this, cx_operatorKind value);
void cx_operatorKind__update(cx_operatorKind* _this, cx_operatorKind value);
void cx_operatorKind__set(cx_operatorKind* _this, cx_operatorKind value);
cx_string cx_operatorKind__str(cx_operatorKind value);
cx_operatorKind* cx_operatorKind__fromStr(cx_operatorKind* value, cx_string str);
cx_int16 cx_operatorKind__copy(cx_operatorKind* *dst, cx_operatorKind* src);
cx_int16 cx_operatorKind__compare(cx_operatorKind* dst, cx_operatorKind* src);

cx_int16 cx_operatorKind__init(cx_operatorKind* value);
cx_int16 cx_operatorKind__deinit(cx_operatorKind* value);

/* ::cortex::lang::package */
cx_package cx_package__create(cx_string url);
cx_package cx_package__createChild(cx_object _parent, cx_string _name, cx_string url);

cx_package cx_package__declare(void);
cx_package cx_package__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_package__define(cx_package _this, cx_string url);
void cx_package__update(cx_package _this, cx_string url);
void cx_package__set(cx_package _this, cx_string url);
cx_string cx_package__str(cx_package value);
cx_package cx_package__fromStr(cx_package value, cx_string str);
cx_int16 cx_package__copy(cx_package *dst, cx_package src);
cx_int16 cx_package__compare(cx_package dst, cx_package src);

/* ::cortex::lang::parameter */
cx_parameter* cx_parameter__create(cx_string name, cx_type type, cx_bool passByReference);
cx_parameter* cx_parameter__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool passByReference);

cx_parameter* cx_parameter__declare(void);
cx_parameter* cx_parameter__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameter__define(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameter__update(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameter__set(cx_parameter* _this, cx_string name, cx_type type, cx_bool passByReference);
cx_string cx_parameter__str(cx_parameter* value);
cx_parameter* cx_parameter__fromStr(cx_parameter* value, cx_string str);
cx_int16 cx_parameter__copy(cx_parameter* *dst, cx_parameter* src);
cx_int16 cx_parameter__compare(cx_parameter* dst, cx_parameter* src);

cx_int16 cx_parameter__init(cx_parameter* value);
cx_int16 cx_parameter__deinit(cx_parameter* value);

/* ::cortex::lang::parameterSeq */
cx_parameterSeq* cx_parameterSeq__create(void);
cx_parameterSeq* cx_parameterSeq__createChild(cx_object _parent, cx_string _name);

cx_parameterSeq* cx_parameterSeq__declare(void);
cx_parameterSeq* cx_parameterSeq__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_parameterSeq__define(cx_parameterSeq* _this, cx_parameterSeq value);
void cx_parameterSeq__update(cx_parameterSeq* _this, cx_parameterSeq value);
void cx_parameterSeq__set(cx_parameterSeq* _this, cx_parameterSeq value);
cx_string cx_parameterSeq__str(cx_parameterSeq value);
cx_parameterSeq* cx_parameterSeq__fromStr(cx_parameterSeq* value, cx_string str);
cx_int16 cx_parameterSeq__copy(cx_parameterSeq* *dst, cx_parameterSeq* src);
cx_int16 cx_parameterSeq__compare(cx_parameterSeq* dst, cx_parameterSeq* src);

cx_int16 cx_parameterSeq__init(cx_parameterSeq* value);
cx_int16 cx_parameterSeq__deinit(cx_parameterSeq* value);

/* ::cortex::lang::primitive */
cx_primitive cx_primitive__create(cx_width width);
cx_primitive cx_primitive__createChild(cx_object _parent, cx_string _name, cx_width width);

cx_primitive cx_primitive__declare(void);
cx_primitive cx_primitive__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitive__define(cx_primitive _this, cx_width width);
void cx_primitive__update(cx_primitive _this, cx_width width);
void cx_primitive__set(cx_primitive _this, cx_width width);
cx_string cx_primitive__str(cx_primitive value);
cx_primitive cx_primitive__fromStr(cx_primitive value, cx_string str);
cx_int16 cx_primitive__copy(cx_primitive *dst, cx_primitive src);
cx_int16 cx_primitive__compare(cx_primitive dst, cx_primitive src);

/* ::cortex::lang::primitiveKind */
cx_primitiveKind* cx_primitiveKind__create(void);
cx_primitiveKind* cx_primitiveKind__createChild(cx_object _parent, cx_string _name);

cx_primitiveKind* cx_primitiveKind__declare(void);
cx_primitiveKind* cx_primitiveKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_primitiveKind__define(cx_primitiveKind* _this, cx_primitiveKind value);
void cx_primitiveKind__update(cx_primitiveKind* _this, cx_primitiveKind value);
void cx_primitiveKind__set(cx_primitiveKind* _this, cx_primitiveKind value);
cx_string cx_primitiveKind__str(cx_primitiveKind value);
cx_primitiveKind* cx_primitiveKind__fromStr(cx_primitiveKind* value, cx_string str);
cx_int16 cx_primitiveKind__copy(cx_primitiveKind* *dst, cx_primitiveKind* src);
cx_int16 cx_primitiveKind__compare(cx_primitiveKind* dst, cx_primitiveKind* src);

cx_int16 cx_primitiveKind__init(cx_primitiveKind* value);
cx_int16 cx_primitiveKind__deinit(cx_primitiveKind* value);

/* ::cortex::lang::procedure */
cx_procedure cx_procedure__create(cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_procedure cx_procedure__createChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);

cx_procedure cx_procedure__declare(void);
cx_procedure cx_procedure__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedure__define(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
void cx_procedure__update(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
void cx_procedure__set(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_string cx_procedure__str(cx_procedure value);
cx_procedure cx_procedure__fromStr(cx_procedure value, cx_string str);
cx_int16 cx_procedure__copy(cx_procedure *dst, cx_procedure src);
cx_int16 cx_procedure__compare(cx_procedure dst, cx_procedure src);

/* ::cortex::lang::procedureKind */
cx_procedureKind* cx_procedureKind__create(void);
cx_procedureKind* cx_procedureKind__createChild(cx_object _parent, cx_string _name);

cx_procedureKind* cx_procedureKind__declare(void);
cx_procedureKind* cx_procedureKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_procedureKind__define(cx_procedureKind* _this, cx_procedureKind value);
void cx_procedureKind__update(cx_procedureKind* _this, cx_procedureKind value);
void cx_procedureKind__set(cx_procedureKind* _this, cx_procedureKind value);
cx_string cx_procedureKind__str(cx_procedureKind value);
cx_procedureKind* cx_procedureKind__fromStr(cx_procedureKind* value, cx_string str);
cx_int16 cx_procedureKind__copy(cx_procedureKind* *dst, cx_procedureKind* src);
cx_int16 cx_procedureKind__compare(cx_procedureKind* dst, cx_procedureKind* src);

cx_int16 cx_procedureKind__init(cx_procedureKind* value);
cx_int16 cx_procedureKind__deinit(cx_procedureKind* value);

/* ::cortex::lang::sequence */
cx_sequence cx_sequence__create(cx_type elementType, cx_uint32 max);
cx_sequence cx_sequence__createChild(cx_object _parent, cx_string _name, cx_type elementType, cx_uint32 max);

cx_sequence cx_sequence__declare(void);
cx_sequence cx_sequence__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_sequence__define(cx_sequence _this, cx_type elementType, cx_uint32 max);
void cx_sequence__update(cx_sequence _this, cx_type elementType, cx_uint32 max);
void cx_sequence__set(cx_sequence _this, cx_type elementType, cx_uint32 max);
cx_string cx_sequence__str(cx_sequence value);
cx_sequence cx_sequence__fromStr(cx_sequence value, cx_string str);
cx_int16 cx_sequence__copy(cx_sequence *dst, cx_sequence src);
cx_int16 cx_sequence__compare(cx_sequence dst, cx_sequence src);

/* ::cortex::lang::state */
cx_state* cx_state__create(void);
cx_state* cx_state__createChild(cx_object _parent, cx_string _name);

cx_state* cx_state__declare(void);
cx_state* cx_state__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_state__define(cx_state* _this, cx_state value);
void cx_state__update(cx_state* _this, cx_state value);
void cx_state__set(cx_state* _this, cx_state value);
cx_string cx_state__str(cx_state value);
cx_state* cx_state__fromStr(cx_state* value, cx_string str);
cx_int16 cx_state__copy(cx_state* *dst, cx_state* src);
cx_int16 cx_state__compare(cx_state* dst, cx_state* src);

cx_int16 cx_state__init(cx_state* value);
cx_int16 cx_state__deinit(cx_state* value);

/* ::cortex::lang::string */
cx_string* cx_string__create(void);
cx_string* cx_string__createChild(cx_object _parent, cx_string _name);

cx_string* cx_string__declare(void);
cx_string* cx_string__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_string__define(cx_string* _this, cx_string value);
void cx_string__update(cx_string* _this, cx_string value);
void cx_string__set(cx_string* _this, cx_string value);
cx_string cx_string__str(cx_string value);
cx_string* cx_string__fromStr(cx_string* value, cx_string str);
cx_int16 cx_string__copy(cx_string* *dst, cx_string* src);
cx_int16 cx_string__compare(cx_string* dst, cx_string* src);

cx_int16 cx_string__init(cx_string* value);
cx_int16 cx_string__deinit(cx_string* value);

/* ::cortex::lang::struct */
cx_struct cx_struct__create(cx_interface base, cx_modifier baseAccess);
cx_struct cx_struct__createChild(cx_object _parent, cx_string _name, cx_interface base, cx_modifier baseAccess);

cx_struct cx_struct__declare(void);
cx_struct cx_struct__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_struct__define(cx_struct _this, cx_interface base, cx_modifier baseAccess);
void cx_struct__update(cx_struct _this, cx_interface base, cx_modifier baseAccess);
void cx_struct__set(cx_struct _this, cx_interface base, cx_modifier baseAccess);
cx_string cx_struct__str(cx_struct value);
cx_struct cx_struct__fromStr(cx_struct value, cx_string str);
cx_int16 cx_struct__copy(cx_struct *dst, cx_struct src);
cx_int16 cx_struct__compare(cx_struct dst, cx_struct src);

/* ::cortex::lang::text */
cx_text cx_text__create(cx_width charWidth, cx_uint64 length);
cx_text cx_text__createChild(cx_object _parent, cx_string _name, cx_width charWidth, cx_uint64 length);

cx_text cx_text__declare(void);
cx_text cx_text__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_text__define(cx_text _this, cx_width charWidth, cx_uint64 length);
void cx_text__update(cx_text _this, cx_width charWidth, cx_uint64 length);
void cx_text__set(cx_text _this, cx_width charWidth, cx_uint64 length);
cx_string cx_text__str(cx_text value);
cx_text cx_text__fromStr(cx_text value, cx_string str);
cx_int16 cx_text__copy(cx_text *dst, cx_text src);
cx_int16 cx_text__compare(cx_text dst, cx_text src);

/* ::cortex::lang::type */
cx_type cx_type__create(cx_type defaultType, cx_type parentType, cx_state parentState);
cx_type cx_type__createChild(cx_object _parent, cx_string _name, cx_type defaultType, cx_type parentType, cx_state parentState);

cx_type cx_type__declare(void);
cx_type cx_type__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_type__define(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
void cx_type__update(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
void cx_type__set(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
cx_string cx_type__str(cx_type value);
cx_type cx_type__fromStr(cx_type value, cx_string str);
cx_int16 cx_type__copy(cx_type *dst, cx_type src);
cx_int16 cx_type__compare(cx_type dst, cx_type src);

/* ::cortex::lang::typeKind */
cx_typeKind* cx_typeKind__create(void);
cx_typeKind* cx_typeKind__createChild(cx_object _parent, cx_string _name);

cx_typeKind* cx_typeKind__declare(void);
cx_typeKind* cx_typeKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_typeKind__define(cx_typeKind* _this, cx_typeKind value);
void cx_typeKind__update(cx_typeKind* _this, cx_typeKind value);
void cx_typeKind__set(cx_typeKind* _this, cx_typeKind value);
cx_string cx_typeKind__str(cx_typeKind value);
cx_typeKind* cx_typeKind__fromStr(cx_typeKind* value, cx_string str);
cx_int16 cx_typeKind__copy(cx_typeKind* *dst, cx_typeKind* src);
cx_int16 cx_typeKind__compare(cx_typeKind* dst, cx_typeKind* src);

cx_int16 cx_typeKind__init(cx_typeKind* value);
cx_int16 cx_typeKind__deinit(cx_typeKind* value);

/* ::cortex::lang::uint */
cx_uint cx_uint__create(cx_width width, cx_uint64 min, cx_uint64 max);
cx_uint cx_uint__createChild(cx_object _parent, cx_string _name, cx_width width, cx_uint64 min, cx_uint64 max);

cx_uint cx_uint__declare(void);
cx_uint cx_uint__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint__define(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uint__update(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
void cx_uint__set(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
cx_string cx_uint__str(cx_uint value);
cx_uint cx_uint__fromStr(cx_uint value, cx_string str);
cx_int16 cx_uint__copy(cx_uint *dst, cx_uint src);
cx_int16 cx_uint__compare(cx_uint dst, cx_uint src);

/* ::cortex::lang::uint16 */
cx_uint16* cx_uint16__create(void);
cx_uint16* cx_uint16__createChild(cx_object _parent, cx_string _name);

cx_uint16* cx_uint16__declare(void);
cx_uint16* cx_uint16__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint16__define(cx_uint16* _this, cx_uint16 value);
void cx_uint16__update(cx_uint16* _this, cx_uint16 value);
void cx_uint16__set(cx_uint16* _this, cx_uint16 value);
cx_string cx_uint16__str(cx_uint16 value);
cx_uint16* cx_uint16__fromStr(cx_uint16* value, cx_string str);
cx_int16 cx_uint16__copy(cx_uint16* *dst, cx_uint16* src);
cx_int16 cx_uint16__compare(cx_uint16* dst, cx_uint16* src);

cx_int16 cx_uint16__init(cx_uint16* value);
cx_int16 cx_uint16__deinit(cx_uint16* value);

/* ::cortex::lang::uint32 */
cx_uint32* cx_uint32__create(void);
cx_uint32* cx_uint32__createChild(cx_object _parent, cx_string _name);

cx_uint32* cx_uint32__declare(void);
cx_uint32* cx_uint32__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint32__define(cx_uint32* _this, cx_uint32 value);
void cx_uint32__update(cx_uint32* _this, cx_uint32 value);
void cx_uint32__set(cx_uint32* _this, cx_uint32 value);
cx_string cx_uint32__str(cx_uint32 value);
cx_uint32* cx_uint32__fromStr(cx_uint32* value, cx_string str);
cx_int16 cx_uint32__copy(cx_uint32* *dst, cx_uint32* src);
cx_int16 cx_uint32__compare(cx_uint32* dst, cx_uint32* src);

cx_int16 cx_uint32__init(cx_uint32* value);
cx_int16 cx_uint32__deinit(cx_uint32* value);

/* ::cortex::lang::uint64 */
cx_uint64* cx_uint64__create(void);
cx_uint64* cx_uint64__createChild(cx_object _parent, cx_string _name);

cx_uint64* cx_uint64__declare(void);
cx_uint64* cx_uint64__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint64__define(cx_uint64* _this, cx_uint64 value);
void cx_uint64__update(cx_uint64* _this, cx_uint64 value);
void cx_uint64__set(cx_uint64* _this, cx_uint64 value);
cx_string cx_uint64__str(cx_uint64 value);
cx_uint64* cx_uint64__fromStr(cx_uint64* value, cx_string str);
cx_int16 cx_uint64__copy(cx_uint64* *dst, cx_uint64* src);
cx_int16 cx_uint64__compare(cx_uint64* dst, cx_uint64* src);

cx_int16 cx_uint64__init(cx_uint64* value);
cx_int16 cx_uint64__deinit(cx_uint64* value);

/* ::cortex::lang::uint8 */
cx_uint8* cx_uint8__create(void);
cx_uint8* cx_uint8__createChild(cx_object _parent, cx_string _name);

cx_uint8* cx_uint8__declare(void);
cx_uint8* cx_uint8__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_uint8__define(cx_uint8* _this, cx_uint8 value);
void cx_uint8__update(cx_uint8* _this, cx_uint8 value);
void cx_uint8__set(cx_uint8* _this, cx_uint8 value);
cx_string cx_uint8__str(cx_uint8 value);
cx_uint8* cx_uint8__fromStr(cx_uint8* value, cx_string str);
cx_int16 cx_uint8__copy(cx_uint8* *dst, cx_uint8* src);
cx_int16 cx_uint8__compare(cx_uint8* dst, cx_uint8* src);

cx_int16 cx_uint8__init(cx_uint8* value);
cx_int16 cx_uint8__deinit(cx_uint8* value);

/* ::cortex::lang::virtual */
cx_virtual cx_virtual__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_virtual cx_virtual__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

cx_virtual cx_virtual__declare(void);
cx_virtual cx_virtual__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_virtual__define(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtual__update(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void cx_virtual__set(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string cx_virtual__str(cx_virtual value);
cx_virtual cx_virtual__fromStr(cx_virtual value, cx_string str);
cx_int16 cx_virtual__copy(cx_virtual *dst, cx_virtual src);
cx_int16 cx_virtual__compare(cx_virtual dst, cx_virtual src);

/* ::cortex::lang::void */
cx_void* cx_void__create(void);
cx_void* cx_void__createChild(cx_object _parent, cx_string _name);

/* ::cortex::lang::vtable */
cx_vtable* cx_vtable__create(void);
cx_vtable* cx_vtable__createChild(cx_object _parent, cx_string _name);

cx_vtable* cx_vtable__declare(void);
cx_vtable* cx_vtable__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_vtable__define(cx_vtable* _this, cx_vtable value);
void cx_vtable__update(cx_vtable* _this, cx_vtable value);
void cx_vtable__set(cx_vtable* _this, cx_vtable value);
cx_string cx_vtable__str(cx_vtable value);
cx_vtable* cx_vtable__fromStr(cx_vtable* value, cx_string str);
cx_int16 cx_vtable__copy(cx_vtable* *dst, cx_vtable* src);
cx_int16 cx_vtable__compare(cx_vtable* dst, cx_vtable* src);

cx_int16 cx_vtable__init(cx_vtable* value);
cx_int16 cx_vtable__deinit(cx_vtable* value);

/* ::cortex::lang::width */
cx_width* cx_width__create(void);
cx_width* cx_width__createChild(cx_object _parent, cx_string _name);

cx_width* cx_width__declare(void);
cx_width* cx_width__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_width__define(cx_width* _this, cx_width value);
void cx_width__update(cx_width* _this, cx_width value);
void cx_width__set(cx_width* _this, cx_width value);
cx_string cx_width__str(cx_width value);
cx_width* cx_width__fromStr(cx_width* value, cx_string str);
cx_int16 cx_width__copy(cx_width* *dst, cx_width* src);
cx_int16 cx_width__compare(cx_width* dst, cx_width* src);

cx_int16 cx_width__init(cx_width* value);
cx_int16 cx_width__deinit(cx_width* value);

/* ::cortex::lang::word */
cx_word* cx_word__create(void);
cx_word* cx_word__createChild(cx_object _parent, cx_string _name);

cx_word* cx_word__declare(void);
cx_word* cx_word__declareChild(cx_object _parent, cx_string _name);
cx_int16 cx_word__define(cx_word* _this, cx_word value);
void cx_word__update(cx_word* _this, cx_word value);
void cx_word__set(cx_word* _this, cx_word value);
cx_string cx_word__str(cx_word value);
cx_word* cx_word__fromStr(cx_word* value, cx_string str);
cx_int16 cx_word__copy(cx_word* *dst, cx_word* src);
cx_int16 cx_word__compare(cx_word* dst, cx_word* src);

cx_int16 cx_word__init(cx_word* value);
cx_int16 cx_word__deinit(cx_word* value);


/* ::cortex::lang::interfaceSeq */
#define cx_interfaceSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interface elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_interface cx_interfaceSeq__append(cx_interfaceSeq *seq);
void cx_interfaceSeq__size(cx_interfaceSeq *seq, cx_uint32 length);
void cx_interfaceSeq__clear(cx_interfaceSeq *seq);

/* ::cortex::lang::interfaceVectorSeq */
#define cx_interfaceVectorSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_interfaceVector *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_interfaceVector* cx_interfaceVectorSeq__append(cx_interfaceVectorSeq *seq);
void cx_interfaceVectorSeq__size(cx_interfaceVectorSeq *seq, cx_uint32 length);
void cx_interfaceVectorSeq__clear(cx_interfaceVectorSeq *seq);

/* ::cortex::lang::memberSeq */
#define cx_memberSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_member elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_member cx_memberSeq__append(cx_memberSeq *seq);
void cx_memberSeq__size(cx_memberSeq *seq, cx_uint32 length);
void cx_memberSeq__clear(cx_memberSeq *seq);

/* ::cortex::lang::objectSeq */
#define cx_objectSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_object elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_object cx_objectSeq__append(cx_objectSeq *seq);
void cx_objectSeq__size(cx_objectSeq *seq, cx_uint32 length);
void cx_objectSeq__clear(cx_objectSeq *seq);

/* ::cortex::lang::observerSeq */
#define cx_observerSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_observer elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_observer cx_observerSeq__append(cx_observerSeq *seq);
void cx_observerSeq__size(cx_observerSeq *seq, cx_uint32 length);
void cx_observerSeq__clear(cx_observerSeq *seq);

/* ::cortex::lang::parameterSeq */
#define cx_parameterSeq__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_parameter *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_parameter* cx_parameterSeq__append(cx_parameterSeq *seq);
void cx_parameterSeq__size(cx_parameterSeq *seq, cx_uint32 length);
void cx_parameterSeq__clear(cx_parameterSeq *seq);

/* ::cortex::lang::vtable */
#define cx_vtable__foreach(seq, elem) \
    cx_uint32 elem##_iter;\
    cx_function elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

cx_function cx_vtable__append(cx_vtable *seq);
void cx_vtable__size(cx_vtable *seq, cx_uint32 length);
void cx_vtable__clear(cx_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

