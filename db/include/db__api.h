/* db__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef db__API_H
#define db__API_H

#include "db__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::lang::alias */
db_alias db_alias__new(void);
db_alias db_alias__declare(db_object _parent, db_string _name);
int db_alias__define(db_alias _this, db_string typeName);
db_alias db_alias__create(db_string typeName);

/* ::cortex::lang::array */
db_array db_array__new(void);
db_array db_array__declare(db_object _parent, db_string _name);
int db_array__define(db_array _this, db_typedef elementType, db_uint32 max);
db_array db_array__create(db_typedef elementType, db_uint32 max);

/* ::cortex::lang::binary */
db_binary db_binary__new(void);
db_binary db_binary__declare(db_object _parent, db_string _name);
int db_binary__define(db_binary _this, db_width width);
db_binary db_binary__create(db_width width);

/* ::cortex::lang::bitmask */
db_bitmask db_bitmask__new(void);
db_bitmask db_bitmask__declare(db_object _parent, db_string _name);
int db_bitmask__define(db_bitmask _this);
db_bitmask db_bitmask__create(void);

/* ::cortex::lang::boolean */
db_boolean db_boolean__new(void);
db_boolean db_boolean__declare(db_object _parent, db_string _name);
int db_boolean__define(db_boolean _this);
db_boolean db_boolean__create(void);

/* ::cortex::lang::callback */
db_callback db_callback__new(void);
db_callback db_callback__declare(db_object _parent, db_string _name);
int db_callback__define(db_callback _this, db_typedef returnType, db_bool returnsReference, db_delegate delegate);
db_callback db_callback__create(db_typedef returnType, db_bool returnsReference, db_delegate delegate);

/* ::cortex::lang::character */
db_character db_character__new(void);
db_character db_character__declare(db_object _parent, db_string _name);
int db_character__define(db_character _this, db_width width);
db_character db_character__create(db_width width);

/* ::cortex::lang::class */
db_class db_class__new(void);
db_class db_class__declare(db_object _parent, db_string _name);
int db_class__define(db_class _this, db_interface base, db_modifier baseAccess, db_interfaceSeq implements);
db_class db_class__create(db_interface base, db_modifier baseAccess, db_interfaceSeq implements);

/* ::cortex::lang::collection */
db_collection db_collection__new(void);
db_collection db_collection__declare(db_object _parent, db_string _name);
int db_collection__define(db_collection _this, db_typedef elementType, db_uint32 max);
db_collection db_collection__create(db_typedef elementType, db_uint32 max);

/* ::cortex::lang::delegate */
db_delegate db_delegate__new(void);
db_delegate db_delegate__declare(db_object _parent, db_string _name);
int db_delegate__define(db_delegate _this, db_typedef returnType, db_bool returnsReference);
db_delegate db_delegate__create(db_typedef returnType, db_bool returnsReference);

/* ::cortex::lang::dispatcher */
db_dispatcher db_dispatcher__new(void);
db_dispatcher db_dispatcher__declare(db_object _parent, db_string _name);
int db_dispatcher__define(db_dispatcher _this);
db_dispatcher db_dispatcher__create(void);

/* ::cortex::lang::enum */
db_enum db_enum__new(void);
db_enum db_enum__declare(db_object _parent, db_string _name);
int db_enum__define(db_enum _this);
db_enum db_enum__create(void);

/* ::cortex::lang::event */
db_event db_event__new(void);
db_event db_event__declare(db_object _parent, db_string _name);
int db_event__define(db_event _this, db_uint16 kind);
db_event db_event__create(db_uint16 kind);

/* ::cortex::lang::float */
db_float db_float__new(void);
db_float db_float__declare(db_object _parent, db_string _name);
int db_float__define(db_float _this, db_width width, db_float64 min, db_float64 max);
db_float db_float__create(db_width width, db_float64 min, db_float64 max);

/* ::cortex::lang::function */
db_function db_function__new(void);
db_function db_function__declare(db_object _parent, db_string _name);
int db_function__define(db_function _this, db_typedef returnType, db_bool returnsReference);
db_function db_function__create(db_typedef returnType, db_bool returnsReference);

/* ::cortex::lang::int */
db_int db_int__new(void);
db_int db_int__declare(db_object _parent, db_string _name);
int db_int__define(db_int _this, db_width width, db_int64 min, db_int64 max);
db_int db_int__create(db_width width, db_int64 min, db_int64 max);

/* ::cortex::lang::interface */
db_interface db_interface__new(void);
db_interface db_interface__declare(db_object _parent, db_string _name);
int db_interface__define(db_interface _this, db_interface base);
db_interface db_interface__create(db_interface base);

/* ::cortex::lang::interfaceVector */
void db_interfaceVector__init(db_interfaceVector *_this, db_interface interface, db_vtable vector);
void db_interfaceVector__deinit(db_interfaceVector *_this);

/* ::cortex::lang::list */
db_list db_list__new(void);
db_list db_list__declare(db_object _parent, db_string _name);
int db_list__define(db_list _this, db_typedef elementType, db_uint32 max);
db_list db_list__create(db_typedef elementType, db_uint32 max);

/* ::cortex::lang::map */
db_map db_map__new(void);
db_map db_map__declare(db_object _parent, db_string _name);
int db_map__define(db_map _this, db_typedef elementType, db_typedef keyType, db_uint32 max);
db_map db_map__create(db_typedef elementType, db_typedef keyType, db_uint32 max);

/* ::cortex::lang::member */
db_member db_member__new(void);
db_member db_member__declare(db_object _parent, db_string _name);
int db_member__define(db_member _this, db_typedef type, db_modifier modifiers, db_state state, db_bool weak);
db_member db_member__create(db_typedef type, db_modifier modifiers, db_state state, db_bool weak);

/* ::cortex::lang::metaprocedure */
db_metaprocedure db_metaprocedure__new(void);
db_metaprocedure db_metaprocedure__declare(db_object _parent, db_string _name);
int db_metaprocedure__define(db_metaprocedure _this, db_typedef returnType, db_bool returnsReference, db_bool referenceOnly);
db_metaprocedure db_metaprocedure__create(db_typedef returnType, db_bool returnsReference, db_bool referenceOnly);

/* ::cortex::lang::method */
db_method db_method__new(void);
db_method db_method__declare(db_object _parent, db_string _name);
int db_method__define(db_method _this, db_typedef returnType, db_bool returnsReference, db_bool virtual);
db_method db_method__create(db_typedef returnType, db_bool returnsReference, db_bool virtual);

/* ::cortex::lang::observableEvent */
db_observableEvent db_observableEvent__new(void);
db_observableEvent db_observableEvent__declare(db_object _parent, db_string _name);
int db_observableEvent__define(db_observableEvent _this, db_uint16 kind, db_observer observer, db_object me, db_object source, db_object observable);
db_observableEvent db_observableEvent__create(db_uint16 kind, db_observer observer, db_object me, db_object source, db_object observable);

/* ::cortex::lang::observer */
db_observer db_observer__new(void);
db_observer db_observer__declare(db_object _parent, db_string _name);
int db_observer__define(db_observer _this, db_object observable, db_eventMask mask, db_string expression, db_uint32 template, db_dispatcher dispatcher, db_object me);
db_observer db_observer__create(db_object observable, db_eventMask mask, db_string expression, db_uint32 template, db_dispatcher dispatcher, db_object me);

/* ::cortex::lang::parameter */
void db_parameter__init(db_parameter *_this, db_string name, db_typedef type, db_bool passByReference);
void db_parameter__deinit(db_parameter *_this);

/* ::cortex::lang::primitive */
db_primitive db_primitive__new(void);
db_primitive db_primitive__declare(db_object _parent, db_string _name);
int db_primitive__define(db_primitive _this, db_width width);
db_primitive db_primitive__create(db_width width);

/* ::cortex::lang::procedure */
db_procedure db_procedure__new(void);
db_procedure db_procedure__declare(db_object _parent, db_string _name);
int db_procedure__define(db_procedure _this, db_procedureKind kind);
db_procedure db_procedure__create(db_procedureKind kind);

/* ::cortex::lang::procptr */
db_procptr db_procptr__new(void);
db_procptr db_procptr__declare(db_object _parent, db_string _name);
int db_procptr__define(db_procptr _this, db_typedef returnType, db_bool returnsReference, db_parameterSeq parameters);
db_procptr db_procptr__create(db_typedef returnType, db_bool returnsReference, db_parameterSeq parameters);

/* ::cortex::lang::procptrdata */
void db_procptrdata__init(db_procptrdata *_this, db_object instance, db_function procedure);
void db_procptrdata__deinit(db_procptrdata *_this);

/* ::cortex::lang::sequence */
db_sequence db_sequence__new(void);
db_sequence db_sequence__declare(db_object _parent, db_string _name);
int db_sequence__define(db_sequence _this, db_typedef elementType, db_uint32 max);
db_sequence db_sequence__create(db_typedef elementType, db_uint32 max);

/* ::cortex::lang::struct */
db_struct db_struct__new(void);
db_struct db_struct__declare(db_object _parent, db_string _name);
int db_struct__define(db_struct _this, db_interface base, db_modifier baseAccess);
db_struct db_struct__create(db_interface base, db_modifier baseAccess);

/* ::cortex::lang::text */
db_text db_text__new(void);
db_text db_text__declare(db_object _parent, db_string _name);
int db_text__define(db_text _this, db_width charWidth, db_uint64 length);
db_text db_text__create(db_width charWidth, db_uint64 length);

/* ::cortex::lang::type */
db_type db_type__new(void);
db_type db_type__declare(db_object _parent, db_string _name);
int db_type__define(db_type _this, db_typedef defaultType, db_typedef parentType, db_state parentState);
db_type db_type__create(db_typedef defaultType, db_typedef parentType, db_state parentState);

/* ::cortex::lang::typedef */
db_typedef db_typedef__new(void);
db_typedef db_typedef__declare(db_object _parent, db_string _name);
int db_typedef__define(db_typedef _this, db_typedef type);
db_typedef db_typedef__create(db_typedef type);

/* ::cortex::lang::uint */
db_uint db_uint__new(void);
db_uint db_uint__declare(db_object _parent, db_string _name);
int db_uint__define(db_uint _this, db_width width, db_uint64 min, db_uint64 max);
db_uint db_uint__create(db_width width, db_uint64 min, db_uint64 max);

/* ::cortex::lang::virtual */
db_virtual db_virtual__new(void);
db_virtual db_virtual__declare(db_object _parent, db_string _name);
int db_virtual__define(db_virtual _this, db_typedef returnType, db_bool returnsReference, db_bool virtual);
db_virtual db_virtual__create(db_typedef returnType, db_bool returnsReference, db_bool virtual);


/* ::cortex::lang::interfaceSeq */
#define db_interfaceSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_interface elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_interface db_interfaceSeq__append(db_interfaceSeq *seq);
void db_interfaceSeq__size(db_interfaceSeq *seq, db_uint32 length);
void db_interfaceSeq__clear(db_interfaceSeq *seq);

/* ::cortex::lang::interfaceVectorSeq */
#define db_interfaceVectorSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_interfaceVector *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_interfaceVector* db_interfaceVectorSeq__append(db_interfaceVectorSeq *seq);
void db_interfaceVectorSeq__size(db_interfaceVectorSeq *seq, db_uint32 length);
void db_interfaceVectorSeq__clear(db_interfaceVectorSeq *seq);

/* ::cortex::lang::memberSeq */
#define db_memberSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_member elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_member db_memberSeq__append(db_memberSeq *seq);
void db_memberSeq__size(db_memberSeq *seq, db_uint32 length);
void db_memberSeq__clear(db_memberSeq *seq);

/* ::cortex::lang::objectSeq */
#define db_objectSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_object elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_object db_objectSeq__append(db_objectSeq *seq);
void db_objectSeq__size(db_objectSeq *seq, db_uint32 length);
void db_objectSeq__clear(db_objectSeq *seq);

/* ::cortex::lang::observerSeq */
#define db_observerSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_observer elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_observer db_observerSeq__append(db_observerSeq *seq);
void db_observerSeq__size(db_observerSeq *seq, db_uint32 length);
void db_observerSeq__clear(db_observerSeq *seq);

/* ::cortex::lang::parameterSeq */
#define db_parameterSeq__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_parameter *elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_parameter* db_parameterSeq__append(db_parameterSeq *seq);
void db_parameterSeq__size(db_parameterSeq *seq, db_uint32 length);
void db_parameterSeq__clear(db_parameterSeq *seq);

/* ::cortex::lang::vtable */
#define db_vtable__foreach(seq, elem) \
    db_uint32 elem##_iter;\
    db_function elem;\
    for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\
        elem = &seq.buffer[elem##_iter];

db_function db_vtable__append(db_vtable *seq);
void db_vtable__size(db_vtable *seq, db_uint32 length);
void db_vtable__clear(db_vtable *seq);

#ifdef __cplusplus
}
#endif
#endif

