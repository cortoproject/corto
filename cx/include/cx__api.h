/* cx__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef cx__API_H
#define cx__API_H

#include "cx__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::lang::alias */
cx_alias cx_alias__new(void);
cx_alias cx_alias__declare(cx_object _parent, cx_string _name);
int cx_alias__define(cx_alias _this, cx_string typeName);
cx_alias cx_alias__create(cx_string typeName);

/* ::cortex::lang::array */
cx_array cx_array__new(void);
cx_array cx_array__declare(cx_object _parent, cx_string _name);
int cx_array__define(cx_array _this, cx_typedef elementType, cx_uint32 max);
cx_array cx_array__create(cx_typedef elementType, cx_uint32 max);

/* ::cortex::lang::binary */
cx_binary cx_binary__new(void);
cx_binary cx_binary__declare(cx_object _parent, cx_string _name);
int cx_binary__define(cx_binary _this, cx_width width);
cx_binary cx_binary__create(cx_width width);

/* ::cortex::lang::bitmask */
cx_bitmask cx_bitmask__new(void);
cx_bitmask cx_bitmask__declare(cx_object _parent, cx_string _name);
int cx_bitmask__define(cx_bitmask _this);
cx_bitmask cx_bitmask__create(void);

/* ::cortex::lang::boolean */
cx_boolean cx_boolean__new(void);
cx_boolean cx_boolean__declare(cx_object _parent, cx_string _name);
int cx_boolean__define(cx_boolean _this);
cx_boolean cx_boolean__create(void);

/* ::cortex::lang::callback */
cx_callback cx_callback__new(void);
cx_callback cx_callback__declare(cx_object _parent, cx_string _name);
int cx_callback__define(cx_callback _this, cx_typedef returnType, cx_bool returnsReference, cx_delegate delegate);
cx_callback cx_callback__create(cx_typedef returnType, cx_bool returnsReference, cx_delegate delegate);

/* ::cortex::lang::character */
cx_character cx_character__new(void);
cx_character cx_character__declare(cx_object _parent, cx_string _name);
int cx_character__define(cx_character _this, cx_width width);
cx_character cx_character__create(cx_width width);

/* ::cortex::lang::class */
cx_class cx_class__new(void);
cx_class cx_class__declare(cx_object _parent, cx_string _name);
int cx_class__define(cx_class _this, cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);
cx_class cx_class__create(cx_interface base, cx_modifier baseAccess, cx_interfaceSeq implements);

/* ::cortex::lang::collection */
cx_collection cx_collection__new(void);
cx_collection cx_collection__declare(cx_object _parent, cx_string _name);
int cx_collection__define(cx_collection _this, cx_typedef elementType, cx_uint32 max);
cx_collection cx_collection__create(cx_typedef elementType, cx_uint32 max);

/* ::cortex::lang::delegate */
cx_delegate cx_delegate__new(void);
cx_delegate cx_delegate__declare(cx_object _parent, cx_string _name);
int cx_delegate__define(cx_delegate _this, cx_typedef returnType, cx_bool returnsReference);
cx_delegate cx_delegate__create(cx_typedef returnType, cx_bool returnsReference);

/* ::cortex::lang::dispatcher */
cx_dispatcher cx_dispatcher__new(void);
cx_dispatcher cx_dispatcher__declare(cx_object _parent, cx_string _name);
int cx_dispatcher__define(cx_dispatcher _this);
cx_dispatcher cx_dispatcher__create(void);

/* ::cortex::lang::enum */
cx_enum cx_enum__new(void);
cx_enum cx_enum__declare(cx_object _parent, cx_string _name);
int cx_enum__define(cx_enum _this);
cx_enum cx_enum__create(void);

/* ::cortex::lang::event */
cx_event cx_event__new(void);
cx_event cx_event__declare(cx_object _parent, cx_string _name);
int cx_event__define(cx_event _this, cx_uint16 kind);
cx_event cx_event__create(cx_uint16 kind);

/* ::cortex::lang::float */
cx_float cx_float__new(void);
cx_float cx_float__declare(cx_object _parent, cx_string _name);
int cx_float__define(cx_float _this, cx_width width, cx_float64 min, cx_float64 max);
cx_float cx_float__create(cx_width width, cx_float64 min, cx_float64 max);

/* ::cortex::lang::function */
cx_function cx_function__new(void);
cx_function cx_function__declare(cx_object _parent, cx_string _name);
int cx_function__define(cx_function _this, cx_typedef returnType, cx_bool returnsReference);
cx_function cx_function__create(cx_typedef returnType, cx_bool returnsReference);

/* ::cortex::lang::int */
cx_int cx_int__new(void);
cx_int cx_int__declare(cx_object _parent, cx_string _name);
int cx_int__define(cx_int _this, cx_width width, cx_int64 min, cx_int64 max);
cx_int cx_int__create(cx_width width, cx_int64 min, cx_int64 max);

/* ::cortex::lang::interface */
cx_interface cx_interface__new(void);
cx_interface cx_interface__declare(cx_object _parent, cx_string _name);
int cx_interface__define(cx_interface _this, cx_interface base);
cx_interface cx_interface__create(cx_interface base);

/* ::cortex::lang::interfaceVector */
void cx_interfaceVector__init(cx_interfaceVector *_this, cx_interface interface, cx_vtable vector);
void cx_interfaceVector__deinit(cx_interfaceVector *_this);

/* ::cortex::lang::list */
cx_list cx_list__new(void);
cx_list cx_list__declare(cx_object _parent, cx_string _name);
int cx_list__define(cx_list _this, cx_typedef elementType, cx_uint32 max);
cx_list cx_list__create(cx_typedef elementType, cx_uint32 max);

/* ::cortex::lang::map */
cx_map cx_map__new(void);
cx_map cx_map__declare(cx_object _parent, cx_string _name);
int cx_map__define(cx_map _this, cx_typedef elementType, cx_typedef keyType, cx_uint32 max);
cx_map cx_map__create(cx_typedef elementType, cx_typedef keyType, cx_uint32 max);

/* ::cortex::lang::member */
cx_member cx_member__new(void);
cx_member cx_member__declare(cx_object _parent, cx_string _name);
int cx_member__define(cx_member _this, cx_typedef type, cx_modifier modifiers, cx_state state, cx_bool weak);
cx_member cx_member__create(cx_typedef type, cx_modifier modifiers, cx_state state, cx_bool weak);

/* ::cortex::lang::metaprocedure */
cx_metaprocedure cx_metaprocedure__new(void);
cx_metaprocedure cx_metaprocedure__declare(cx_object _parent, cx_string _name);
int cx_metaprocedure__define(cx_metaprocedure _this, cx_typedef returnType, cx_bool returnsReference, cx_bool referenceOnly);
cx_metaprocedure cx_metaprocedure__create(cx_typedef returnType, cx_bool returnsReference, cx_bool referenceOnly);

/* ::cortex::lang::method */
cx_method cx_method__new(void);
cx_method cx_method__declare(cx_object _parent, cx_string _name);
int cx_method__define(cx_method _this, cx_typedef returnType, cx_bool returnsReference, cx_bool virtual);
cx_method cx_method__create(cx_typedef returnType, cx_bool returnsReference, cx_bool virtual);

/* ::cortex::lang::observableEvent */
cx_observableEvent cx_observableEvent__new(void);
cx_observableEvent cx_observableEvent__declare(cx_object _parent, cx_string _name);
int cx_observableEvent__define(cx_observableEvent _this, cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);
cx_observableEvent cx_observableEvent__create(cx_uint16 kind, cx_observer observer, cx_object me, cx_object source, cx_object observable);

/* ::cortex::lang::observer */
cx_observer cx_observer__new(void);
cx_observer cx_observer__declare(cx_object _parent, cx_string _name);
int cx_observer__define(cx_observer _this, cx_object observable, cx_eventMask mask, cx_string expression, cx_uint32 template, cx_dispatcher dispatcher, cx_object me);
cx_observer cx_observer__create(cx_object observable, cx_eventMask mask, cx_string expression, cx_uint32 template, cx_dispatcher dispatcher, cx_object me);

/* ::cortex::lang::parameter */
void cx_parameter__init(cx_parameter *_this, cx_string name, cx_typedef type, cx_bool passByReference);
void cx_parameter__deinit(cx_parameter *_this);

/* ::cortex::lang::primitive */
cx_primitive cx_primitive__new(void);
cx_primitive cx_primitive__declare(cx_object _parent, cx_string _name);
int cx_primitive__define(cx_primitive _this, cx_width width);
cx_primitive cx_primitive__create(cx_width width);

/* ::cortex::lang::procedure */
cx_procedure cx_procedure__new(void);
cx_procedure cx_procedure__declare(cx_object _parent, cx_string _name);
int cx_procedure__define(cx_procedure _this, cx_interface base, cx_modifier baseAccess);
cx_procedure cx_procedure__create(cx_interface base, cx_modifier baseAccess);

/* ::cortex::lang::procptr */
cx_procptr cx_procptr__new(void);
cx_procptr cx_procptr__declare(cx_object _parent, cx_string _name);
int cx_procptr__define(cx_procptr _this, cx_typedef returnType, cx_bool returnsReference, cx_parameterSeq parameters);
cx_procptr cx_procptr__create(cx_typedef returnType, cx_bool returnsReference, cx_parameterSeq parameters);

/* ::cortex::lang::procptrdata */
void cx_procptrdata__init(cx_procptrdata *_this, cx_object instance, cx_function procedure);
void cx_procptrdata__deinit(cx_procptrdata *_this);

/* ::cortex::lang::sequence */
cx_sequence cx_sequence__new(void);
cx_sequence cx_sequence__declare(cx_object _parent, cx_string _name);
int cx_sequence__define(cx_sequence _this, cx_typedef elementType, cx_uint32 max);
cx_sequence cx_sequence__create(cx_typedef elementType, cx_uint32 max);

/* ::cortex::lang::struct */
cx_struct cx_struct__new(void);
cx_struct cx_struct__declare(cx_object _parent, cx_string _name);
int cx_struct__define(cx_struct _this, cx_interface base, cx_modifier baseAccess);
cx_struct cx_struct__create(cx_interface base, cx_modifier baseAccess);

/* ::cortex::lang::text */
cx_text cx_text__new(void);
cx_text cx_text__declare(cx_object _parent, cx_string _name);
int cx_text__define(cx_text _this, cx_width charWidth, cx_uint64 length);
cx_text cx_text__create(cx_width charWidth, cx_uint64 length);

/* ::cortex::lang::type */
cx_type cx_type__new(void);
cx_type cx_type__declare(cx_object _parent, cx_string _name);
int cx_type__define(cx_type _this, cx_typedef defaultType, cx_typedef parentType, cx_state parentState);
cx_type cx_type__create(cx_typedef defaultType, cx_typedef parentType, cx_state parentState);

/* ::cortex::lang::typedef */
cx_typedef cx_typedef__new(void);
cx_typedef cx_typedef__declare(cx_object _parent, cx_string _name);
int cx_typedef__define(cx_typedef _this, cx_typedef type);
cx_typedef cx_typedef__create(cx_typedef type);

/* ::cortex::lang::uint */
cx_uint cx_uint__new(void);
cx_uint cx_uint__declare(cx_object _parent, cx_string _name);
int cx_uint__define(cx_uint _this, cx_width width, cx_uint64 min, cx_uint64 max);
cx_uint cx_uint__create(cx_width width, cx_uint64 min, cx_uint64 max);

/* ::cortex::lang::virtual */
cx_virtual cx_virtual__new(void);
cx_virtual cx_virtual__declare(cx_object _parent, cx_string _name);
int cx_virtual__define(cx_virtual _this, cx_typedef returnType, cx_bool returnsReference, cx_bool virtual);
cx_virtual cx_virtual__create(cx_typedef returnType, cx_bool returnsReference, cx_bool virtual);


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

