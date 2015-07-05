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
/* ::cortex::lang::alias */
int cx_alias__define(cx_alias _this, cx_string typeName);
cx_alias cx_alias__create(cx_string typeName);
cx_alias cx_alias__new(void);
cx_alias cx_alias__declare(cx_object _parent, cx_string _name);
cx_string cx_alias__str(cx_alias value);

/* ::cortex::lang::any */
cx_any* cx_any__new(void);
cx_any* cx_any__declare(cx_object _parent, cx_string _name);
cx_string cx_any__str(cx_any value);

/* ::cortex::lang::array */
int cx_array__define(cx_array _this, cx_type elementType, cx_uint32 max);
cx_array cx_array__create(cx_type elementType, cx_uint32 max);
cx_array cx_array__new(void);
cx_array cx_array__declare(cx_object _parent, cx_string _name);
cx_string cx_array__str(cx_array value);

/* ::cortex::lang::attr */
cx_attr* cx_attr__new(void);
cx_attr* cx_attr__declare(cx_object _parent, cx_string _name);
cx_string cx_attr__str(cx_attr value);

/* ::cortex::lang::binary */
int cx_binary__define(cx_binary _this, cx_width width);
cx_binary cx_binary__create(cx_width width);
cx_binary cx_binary__new(void);
cx_binary cx_binary__declare(cx_object _parent, cx_string _name);
cx_string cx_binary__str(cx_binary value);

/* ::cortex::lang::bitmask */
int cx_bitmask__define(cx_bitmask _this);
cx_bitmask cx_bitmask__create(void);
cx_bitmask cx_bitmask__new(void);
cx_bitmask cx_bitmask__declare(cx_object _parent, cx_string _name);
cx_string cx_bitmask__str(cx_bitmask value);

/* ::cortex::lang::bool */
cx_bool* cx_bool__new(void);
cx_bool* cx_bool__declare(cx_object _parent, cx_string _name);
cx_string cx_bool__str(cx_bool value);

/* ::cortex::lang::boolean */
int cx_boolean__define(cx_boolean _this);
cx_boolean cx_boolean__create(void);
cx_boolean cx_boolean__new(void);
cx_boolean cx_boolean__declare(cx_object _parent, cx_string _name);
cx_string cx_boolean__str(cx_boolean value);

/* ::cortex::lang::callbackDestruct */
void cx_callbackDestruct__init(cx_callbackDestruct *_this);
void cx_callbackDestruct__deinit(cx_callbackDestruct *_this);
cx_callbackDestruct* cx_callbackDestruct__new(void);
cx_callbackDestruct* cx_callbackDestruct__declare(cx_object _parent, cx_string _name);
cx_string cx_callbackDestruct__str(cx_callbackDestruct value);

/* ::cortex::lang::callbackInit */
void cx_callbackInit__init(cx_callbackInit *_this);
void cx_callbackInit__deinit(cx_callbackInit *_this);
cx_callbackInit* cx_callbackInit__new(void);
cx_callbackInit* cx_callbackInit__declare(cx_object _parent, cx_string _name);
cx_string cx_callbackInit__str(cx_callbackInit value);

/* ::cortex::lang::char */
cx_char* cx_char__new(void);
cx_char* cx_char__declare(cx_object _parent, cx_string _name);
cx_string cx_char__str(cx_char value);

/* ::cortex::lang::character */
int cx_character__define(cx_character _this, cx_width width);
cx_character cx_character__create(cx_width width);
cx_character cx_character__new(void);
cx_character cx_character__declare(cx_object _parent, cx_string _name);
cx_string cx_character__str(cx_character value);

/* ::cortex::lang::class */
int cx_class__define(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_class cx_class__create(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_class cx_class__new(void);
cx_class cx_class__declare(cx_object _parent, cx_string _name);
cx_string cx_class__str(cx_class value);

/* ::cortex::lang::collection */
int cx_collection__define(cx_collection _this, cx_type elementType, cx_uint32 max);
cx_collection cx_collection__create(cx_type elementType, cx_uint32 max);
cx_collection cx_collection__new(void);
cx_collection cx_collection__declare(cx_object _parent, cx_string _name);
cx_string cx_collection__str(cx_collection value);

/* ::cortex::lang::collectionKind */
cx_collectionKind* cx_collectionKind__new(void);
cx_collectionKind* cx_collectionKind__declare(cx_object _parent, cx_string _name);
cx_string cx_collectionKind__str(cx_collectionKind value);

/* ::cortex::lang::compositeKind */
cx_compositeKind* cx_compositeKind__new(void);
cx_compositeKind* cx_compositeKind__declare(cx_object _parent, cx_string _name);
cx_string cx_compositeKind__str(cx_compositeKind value);

/* ::cortex::lang::constant */
cx_constant* cx_constant__new(void);
cx_constant* cx_constant__declare(cx_object _parent, cx_string _name);
cx_string cx_constant__str(cx_constant value);

/* ::cortex::lang::delegate */
int cx_delegate__define(cx_delegate _this, cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_delegate cx_delegate__create(cx_type returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_delegate cx_delegate__new(void);
cx_delegate cx_delegate__declare(cx_object _parent, cx_string _name);
cx_string cx_delegate__str(cx_delegate value);

/* ::cortex::lang::delegatedata */
void cx_delegatedata__init(cx_delegatedata *_this, cx_object instance, cx_function procedure);
void cx_delegatedata__deinit(cx_delegatedata *_this);
cx_delegatedata* cx_delegatedata__new(void);
cx_delegatedata* cx_delegatedata__declare(cx_object _parent, cx_string _name);
cx_string cx_delegatedata__str(cx_delegatedata value);

/* ::cortex::lang::dispatcher */
int cx_dispatcher__define(cx_dispatcher _this);
cx_dispatcher cx_dispatcher__create(void);
cx_dispatcher cx_dispatcher__new(void);
cx_dispatcher cx_dispatcher__declare(cx_object _parent, cx_string _name);
cx_string cx_dispatcher__str(cx_dispatcher value);

/* ::cortex::lang::enum */
int cx_enum__define(cx_enum _this);
cx_enum cx_enum__create(void);
cx_enum cx_enum__new(void);
cx_enum cx_enum__declare(cx_object _parent, cx_string _name);
cx_string cx_enum__str(cx_enum value);

/* ::cortex::lang::equalityKind */
cx_equalityKind* cx_equalityKind__new(void);
cx_equalityKind* cx_equalityKind__declare(cx_object _parent, cx_string _name);
cx_string cx_equalityKind__str(cx_equalityKind value);

/* ::cortex::lang::event */
int cx_event__define(cx_event _this, cx_uint16 kind);
cx_event cx_event__create(cx_uint16 kind);
cx_event cx_event__new(void);
cx_event cx_event__declare(cx_object _parent, cx_string _name);
cx_string cx_event__str(cx_event value);

/* ::cortex::lang::eventMask */
cx_eventMask* cx_eventMask__new(void);
cx_eventMask* cx_eventMask__declare(cx_object _parent, cx_string _name);
cx_string cx_eventMask__str(cx_eventMask value);

/* ::cortex::lang::float */
int cx_float__define(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
cx_float cx_float__create(cx_width width, cx_float64 min, cx_float64 max);
cx_float cx_float__new(void);
cx_float cx_float__declare(cx_object _parent, cx_string _name);
cx_string cx_float__str(cx_float value);

/* ::cortex::lang::float32 */
cx_float32* cx_float32__new(void);
cx_float32* cx_float32__declare(cx_object _parent, cx_string _name);
cx_string cx_float32__str(cx_float32 value);

/* ::cortex::lang::float64 */
cx_float64* cx_float64__new(void);
cx_float64* cx_float64__declare(cx_object _parent, cx_string _name);
cx_string cx_float64__str(cx_float64 value);

/* ::cortex::lang::function */
int cx_function__define(cx_function _this, cx_type returnType, cx_bool returnsReference);
cx_function cx_function__create(cx_type returnType, cx_bool returnsReference);
cx_function cx_function__new(void);
cx_function cx_function__declare(cx_object _parent, cx_string _name);
cx_string cx_function__str(cx_function value);

/* ::cortex::lang::int */
int cx_int__define(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_int__create(cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_int__new(void);
cx_int cx_int__declare(cx_object _parent, cx_string _name);
cx_string cx_int__str(cx_int value);

/* ::cortex::lang::int16 */
cx_int16* cx_int16__new(void);
cx_int16* cx_int16__declare(cx_object _parent, cx_string _name);
cx_string cx_int16__str(cx_int16 value);

/* ::cortex::lang::int32 */
cx_int32* cx_int32__new(void);
cx_int32* cx_int32__declare(cx_object _parent, cx_string _name);
cx_string cx_int32__str(cx_int32 value);

/* ::cortex::lang::int64 */
cx_int64* cx_int64__new(void);
cx_int64* cx_int64__declare(cx_object _parent, cx_string _name);
cx_string cx_int64__str(cx_int64 value);

/* ::cortex::lang::int8 */
cx_int8* cx_int8__new(void);
cx_int8* cx_int8__declare(cx_object _parent, cx_string _name);
cx_string cx_int8__str(cx_int8 value);

/* ::cortex::lang::interface */
int cx_interface__define(cx_interface _this, cx_interface base);
cx_interface cx_interface__create(cx_interface base);
cx_interface cx_interface__new(void);
cx_interface cx_interface__declare(cx_object _parent, cx_string _name);
cx_string cx_interface__str(cx_interface value);

/* ::cortex::lang::interfaceSeq */
cx_interfaceSeq* cx_interfaceSeq__new(void);
cx_interfaceSeq* cx_interfaceSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_interfaceSeq__str(cx_interfaceSeq value);

/* ::cortex::lang::interfaceVector */
void cx_interfaceVector__init(cx_interfaceVector *_this, cx_interface interface, cx_vtable vector);
void cx_interfaceVector__deinit(cx_interfaceVector *_this);
cx_interfaceVector* cx_interfaceVector__new(void);
cx_interfaceVector* cx_interfaceVector__declare(cx_object _parent, cx_string _name);
cx_string cx_interfaceVector__str(cx_interfaceVector value);

/* ::cortex::lang::interfaceVectorSeq */
cx_interfaceVectorSeq* cx_interfaceVectorSeq__new(void);
cx_interfaceVectorSeq* cx_interfaceVectorSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_interfaceVectorSeq__str(cx_interfaceVectorSeq value);

/* ::cortex::lang::iterator */
int cx_iterator__define(cx_iterator _this, cx_type elementType);
cx_iterator cx_iterator__create(cx_type elementType);
cx_iterator cx_iterator__new(void);
cx_iterator cx_iterator__declare(cx_object _parent, cx_string _name);
cx_string cx_iterator__str(cx_iterator value);

/* ::cortex::lang::list */
int cx_list__define(cx_list _this, cx_type elementType, cx_uint32 max);
cx_list cx_list__create(cx_type elementType, cx_uint32 max);
cx_list cx_list__new(void);
cx_list cx_list__declare(cx_object _parent, cx_string _name);
cx_string cx_list__str(cx_list value);

/* ::cortex::lang::map */
int cx_map__define(cx_map _this, cx_type elementType, cx_type keyType, cx_uint32 max);
cx_map cx_map__create(cx_type elementType, cx_type keyType, cx_uint32 max);
cx_map cx_map__new(void);
cx_map cx_map__declare(cx_object _parent, cx_string _name);
cx_string cx_map__str(cx_map value);

/* ::cortex::lang::member */
int cx_member__define(cx_member _this, cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_member__create(cx_type type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_member__new(void);
cx_member cx_member__declare(cx_object _parent, cx_string _name);
cx_string cx_member__str(cx_member value);

/* ::cortex::lang::memberSeq */
cx_memberSeq* cx_memberSeq__new(void);
cx_memberSeq* cx_memberSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_memberSeq__str(cx_memberSeq value);

/* ::cortex::lang::metaprocedure */
int cx_metaprocedure__define(cx_metaprocedure _this, cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedure__create(cx_type returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedure__new(void);
cx_metaprocedure cx_metaprocedure__declare(cx_object _parent, cx_string _name);
cx_string cx_metaprocedure__str(cx_metaprocedure value);

/* ::cortex::lang::method */
int cx_method__define(cx_method _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_method__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_method__new(void);
cx_method cx_method__declare(cx_object _parent, cx_string _name);
cx_string cx_method__str(cx_method value);

/* ::cortex::lang::modifier */
cx_modifier* cx_modifier__new(void);
cx_modifier* cx_modifier__declare(cx_object _parent, cx_string _name);
cx_string cx_modifier__str(cx_modifier value);

/* ::cortex::lang::object */
cx_object cx_object__new(void);
cx_object cx_object__declare(cx_object _parent, cx_string _name);

/* ::cortex::lang::objectSeq */
cx_objectSeq* cx_objectSeq__new(void);
cx_objectSeq* cx_objectSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_objectSeq__str(cx_objectSeq value);

/* ::cortex::lang::observableEvent */
int cx_observableEvent__define(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEvent__create(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEvent__new(void);
cx_observableEvent cx_observableEvent__declare(cx_object _parent, cx_string _name);
cx_string cx_observableEvent__str(cx_observableEvent value);

/* ::cortex::lang::observer */
int cx_observer__define(cx_observer _this, cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observer__create(cx_object observable, cx_eventMask mask, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observer__new(void);
cx_observer cx_observer__declare(cx_object _parent, cx_string _name);
cx_string cx_observer__str(cx_observer value);

/* ::cortex::lang::observerSeq */
cx_observerSeq* cx_observerSeq__new(void);
cx_observerSeq* cx_observerSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_observerSeq__str(cx_observerSeq value);

/* ::cortex::lang::octet */
cx_octet* cx_octet__new(void);
cx_octet* cx_octet__declare(cx_object _parent, cx_string _name);
cx_string cx_octet__str(cx_octet value);

/* ::cortex::lang::operatorKind */
cx_operatorKind* cx_operatorKind__new(void);
cx_operatorKind* cx_operatorKind__declare(cx_object _parent, cx_string _name);
cx_string cx_operatorKind__str(cx_operatorKind value);

/* ::cortex::lang::package */
int cx_package__define(cx_package _this, cx_string url);
cx_package cx_package__create(cx_string url);
cx_package cx_package__new(void);
cx_package cx_package__declare(cx_object _parent, cx_string _name);
cx_string cx_package__str(cx_package value);

/* ::cortex::lang::parameter */
void cx_parameter__init(cx_parameter *_this, cx_string name, cx_type type, cx_bool passByReference);
void cx_parameter__deinit(cx_parameter *_this);
cx_parameter* cx_parameter__new(void);
cx_parameter* cx_parameter__declare(cx_object _parent, cx_string _name);
cx_string cx_parameter__str(cx_parameter value);

/* ::cortex::lang::parameterSeq */
cx_parameterSeq* cx_parameterSeq__new(void);
cx_parameterSeq* cx_parameterSeq__declare(cx_object _parent, cx_string _name);
cx_string cx_parameterSeq__str(cx_parameterSeq value);

/* ::cortex::lang::primitive */
int cx_primitive__define(cx_primitive _this, cx_width width);
cx_primitive cx_primitive__create(cx_width width);
cx_primitive cx_primitive__new(void);
cx_primitive cx_primitive__declare(cx_object _parent, cx_string _name);
cx_string cx_primitive__str(cx_primitive value);

/* ::cortex::lang::primitiveKind */
cx_primitiveKind* cx_primitiveKind__new(void);
cx_primitiveKind* cx_primitiveKind__declare(cx_object _parent, cx_string _name);
cx_string cx_primitiveKind__str(cx_primitiveKind value);

/* ::cortex::lang::procedure */
int cx_procedure__define(cx_procedure _this, cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_procedure cx_procedure__create(cx_interface base, cx_modifier baseAccess, cx_procedureKind kind);
cx_procedure cx_procedure__new(void);
cx_procedure cx_procedure__declare(cx_object _parent, cx_string _name);
cx_string cx_procedure__str(cx_procedure value);

/* ::cortex::lang::procedureKind */
cx_procedureKind* cx_procedureKind__new(void);
cx_procedureKind* cx_procedureKind__declare(cx_object _parent, cx_string _name);
cx_string cx_procedureKind__str(cx_procedureKind value);

/* ::cortex::lang::sequence */
int cx_sequence__define(cx_sequence _this, cx_type elementType, cx_uint32 max);
cx_sequence cx_sequence__create(cx_type elementType, cx_uint32 max);
cx_sequence cx_sequence__new(void);
cx_sequence cx_sequence__declare(cx_object _parent, cx_string _name);
cx_string cx_sequence__str(cx_sequence value);

/* ::cortex::lang::state */
cx_state* cx_state__new(void);
cx_state* cx_state__declare(cx_object _parent, cx_string _name);
cx_string cx_state__str(cx_state value);

/* ::cortex::lang::string */
cx_string* cx_string__new(void);
cx_string* cx_string__declare(cx_object _parent, cx_string _name);
cx_string cx_string__str(cx_string value);

/* ::cortex::lang::struct */
int cx_struct__define(cx_struct _this, cx_interface base, cx_modifier baseAccess);
cx_struct cx_struct__create(cx_interface base, cx_modifier baseAccess);
cx_struct cx_struct__new(void);
cx_struct cx_struct__declare(cx_object _parent, cx_string _name);
cx_string cx_struct__str(cx_struct value);

/* ::cortex::lang::text */
int cx_text__define(cx_text _this, cx_width charWidth, cx_uint64 length);
cx_text cx_text__create(cx_width charWidth, cx_uint64 length);
cx_text cx_text__new(void);
cx_text cx_text__declare(cx_object _parent, cx_string _name);
cx_string cx_text__str(cx_text value);

/* ::cortex::lang::type */
int cx_type__define(cx_type _this, cx_type defaultType, cx_type parentType, cx_state parentState);
cx_type cx_type__create(cx_type defaultType, cx_type parentType, cx_state parentState);
cx_type cx_type__new(void);
cx_type cx_type__declare(cx_object _parent, cx_string _name);
cx_string cx_type__str(cx_type value);

/* ::cortex::lang::typeKind */
cx_typeKind* cx_typeKind__new(void);
cx_typeKind* cx_typeKind__declare(cx_object _parent, cx_string _name);
cx_string cx_typeKind__str(cx_typeKind value);

/* ::cortex::lang::uint */
int cx_uint__define(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
cx_uint cx_uint__create(cx_width width, cx_uint64 min, cx_uint64 max);
cx_uint cx_uint__new(void);
cx_uint cx_uint__declare(cx_object _parent, cx_string _name);
cx_string cx_uint__str(cx_uint value);

/* ::cortex::lang::uint16 */
cx_uint16* cx_uint16__new(void);
cx_uint16* cx_uint16__declare(cx_object _parent, cx_string _name);
cx_string cx_uint16__str(cx_uint16 value);

/* ::cortex::lang::uint32 */
cx_uint32* cx_uint32__new(void);
cx_uint32* cx_uint32__declare(cx_object _parent, cx_string _name);
cx_string cx_uint32__str(cx_uint32 value);

/* ::cortex::lang::uint64 */
cx_uint64* cx_uint64__new(void);
cx_uint64* cx_uint64__declare(cx_object _parent, cx_string _name);
cx_string cx_uint64__str(cx_uint64 value);

/* ::cortex::lang::uint8 */
cx_uint8* cx_uint8__new(void);
cx_uint8* cx_uint8__declare(cx_object _parent, cx_string _name);
cx_string cx_uint8__str(cx_uint8 value);

/* ::cortex::lang::virtual */
int cx_virtual__define(cx_virtual _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_virtual cx_virtual__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_virtual cx_virtual__new(void);
cx_virtual cx_virtual__declare(cx_object _parent, cx_string _name);
cx_string cx_virtual__str(cx_virtual value);

/* ::cortex::lang::void */
cx_void* cx_void__new(void);
cx_void* cx_void__declare(cx_object _parent, cx_string _name);

/* ::cortex::lang::vtable */
cx_vtable* cx_vtable__new(void);
cx_vtable* cx_vtable__declare(cx_object _parent, cx_string _name);
cx_string cx_vtable__str(cx_vtable value);

/* ::cortex::lang::width */
cx_width* cx_width__new(void);
cx_width* cx_width__declare(cx_object _parent, cx_string _name);
cx_string cx_width__str(cx_width value);

/* ::cortex::lang::word */
cx_word* cx_word__new(void);
cx_word* cx_word__declare(cx_object _parent, cx_string _name);
cx_string cx_word__str(cx_word value);


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

