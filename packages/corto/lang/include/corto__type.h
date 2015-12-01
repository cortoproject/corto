/* corto__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang__type_H
#define corto_lang__type_H

#include "corto_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define corto_alias(o) ((corto_alias)corto_assertType((corto_type)corto_alias_o, o))
#define corto_array(o) ((corto_array)corto_assertType((corto_type)corto_array_o, o))
#define corto_attr(o) ((corto_attr *)corto_assertType((corto_type)corto_attr_o, o))
#define corto_binary(o) ((corto_binary)corto_assertType((corto_type)corto_binary_o, o))
#define corto_bitmask(o) ((corto_bitmask)corto_assertType((corto_type)corto_bitmask_o, o))
#define corto_bool(o) ((corto_bool *)corto_assertType((corto_type)corto_bool_o, o))
#define corto_boolean(o) ((corto_boolean)corto_assertType((corto_type)corto_boolean_o, o))
#define corto_char(o) ((corto_char *)corto_assertType((corto_type)corto_char_o, o))
#define corto_character(o) ((corto_character)corto_assertType((corto_type)corto_character_o, o))
#define corto_class(o) ((corto_class)corto_assertType((corto_type)corto_class_o, o))
#define corto_collection(o) ((corto_collection)corto_assertType((corto_type)corto_collection_o, o))
#define corto_collectionKind(o) ((corto_collectionKind *)corto_assertType((corto_type)corto_collectionKind_o, o))
#define corto_compositeKind(o) ((corto_compositeKind *)corto_assertType((corto_type)corto_compositeKind_o, o))
#define corto_constant(o) ((corto_constant *)corto_assertType((corto_type)corto_constant_o, o))
#define corto_delegate(o) ((corto_delegate)corto_assertType((corto_type)corto_delegate_o, o))
#define corto_delegatedata(o) ((corto_delegatedata *)corto_assertType((corto_type)corto_delegatedata_o, o))
#define corto_destructAction(o) ((corto_destructAction *)corto_assertType((corto_type)corto_destructAction_o, o))
#define corto_dispatcher(o) ((corto_dispatcher)corto_assertType((corto_type)corto_dispatcher_o, o))
#define corto_enum(o) ((corto_enum)corto_assertType((corto_type)corto_enum_o, o))
#define corto_equalityKind(o) ((corto_equalityKind *)corto_assertType((corto_type)corto_equalityKind_o, o))
#define corto_event(o) ((corto_event)corto_assertType((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask *)corto_assertType((corto_type)corto_eventMask_o, o))
#define corto_float(o) ((corto_float)corto_assertType((corto_type)corto_float_o, o))
#define corto_float32(o) ((corto_float32 *)corto_assertType((corto_type)corto_float32_o, o))
#define corto_float64(o) ((corto_float64 *)corto_assertType((corto_type)corto_float64_o, o))
#define corto_function(o) ((corto_function)corto_assertType((corto_type)corto_function_o, o))
#define corto_initAction(o) ((corto_initAction *)corto_assertType((corto_type)corto_initAction_o, o))
#define corto_int(o) ((corto_int)corto_assertType((corto_type)corto_int_o, o))
#define corto_int16(o) ((corto_int16 *)corto_assertType((corto_type)corto_int16_o, o))
#define corto_int32(o) ((corto_int32 *)corto_assertType((corto_type)corto_int32_o, o))
#define corto_int64(o) ((corto_int64 *)corto_assertType((corto_type)corto_int64_o, o))
#define corto_int8(o) ((corto_int8 *)corto_assertType((corto_type)corto_int8_o, o))
#define corto_interface(o) ((corto_interface)corto_assertType((corto_type)corto_interface_o, o))
#define corto_interfaceseq(o) ((corto_interfaceseq *)corto_assertType((corto_type)corto_interfaceseq_o, o))
#define corto_interfaceVector(o) ((corto_interfaceVector *)corto_assertType((corto_type)corto_interfaceVector_o, o))
#define corto_interfaceVectorseq(o) ((corto_interfaceVectorseq *)corto_assertType((corto_type)corto_interfaceVectorseq_o, o))
#define corto_invokeAction(o) ((corto_invokeAction *)corto_assertType((corto_type)corto_invokeAction_o, o))
#define corto_invokeEvent(o) ((corto_invokeEvent)corto_assertType((corto_type)corto_invokeEvent_o, o))
#define corto_iterator(o) ((corto_iterator)corto_assertType((corto_type)corto_iterator_o, o))
#define corto_list(o) ((corto_list)corto_assertType((corto_type)corto_list_o, o))
#define corto_map(o) ((corto_map)corto_assertType((corto_type)corto_map_o, o))
#define corto_member(o) ((corto_member)corto_assertType((corto_type)corto_member_o, o))
#define corto_memberseq(o) ((corto_memberseq *)corto_assertType((corto_type)corto_memberseq_o, o))
#define corto_metaprocedure(o) ((corto_metaprocedure)corto_assertType((corto_type)corto_metaprocedure_o, o))
#define corto_method(o) ((corto_method)corto_assertType((corto_type)corto_method_o, o))
#define corto_modifier(o) ((corto_modifier *)corto_assertType((corto_type)corto_modifier_o, o))
#define corto_notifyAction(o) ((corto_notifyAction *)corto_assertType((corto_type)corto_notifyAction_o, o))
#define corto_objectseq(o) ((corto_objectseq *)corto_assertType((corto_type)corto_objectseq_o, o))
#define corto_observableEvent(o) ((corto_observableEvent)corto_assertType((corto_type)corto_observableEvent_o, o))
#define corto_observer(o) ((corto_observer)corto_assertType((corto_type)corto_observer_o, o))
#define corto_observerseq(o) ((corto_observerseq *)corto_assertType((corto_type)corto_observerseq_o, o))
#define corto_octet(o) ((corto_octet *)corto_assertType((corto_type)corto_octet_o, o))
#define corto_octetseq(o) ((corto_octetseq *)corto_assertType((corto_type)corto_octetseq_o, o))
#define corto_operatorKind(o) ((corto_operatorKind *)corto_assertType((corto_type)corto_operatorKind_o, o))
#define corto_package(o) ((corto_package)corto_assertType((corto_type)corto_package_o, o))
#define corto_parameter(o) ((corto_parameter *)corto_assertType((corto_type)corto_parameter_o, o))
#define corto_parameterseq(o) ((corto_parameterseq *)corto_assertType((corto_type)corto_parameterseq_o, o))
#define corto_primitive(o) ((corto_primitive)corto_assertType((corto_type)corto_primitive_o, o))
#define corto_primitiveKind(o) ((corto_primitiveKind *)corto_assertType((corto_type)corto_primitiveKind_o, o))
#define corto_procedure(o) ((corto_procedure)corto_assertType((corto_type)corto_procedure_o, o))
#define corto_procedureKind(o) ((corto_procedureKind *)corto_assertType((corto_type)corto_procedureKind_o, o))
#define corto_query(o) ((corto_query)corto_assertType((corto_type)corto_query_o, o))
#define corto_replicator(o) ((corto_replicator)corto_assertType((corto_type)corto_replicator_o, o))
#define corto_requestAction(o) ((corto_requestAction *)corto_assertType((corto_type)corto_requestAction_o, o))
#define corto_result(o) ((corto_result *)corto_assertType((corto_type)corto_result_o, o))
#define corto_resultIter(o) ((corto_resultIter *)corto_assertType((corto_type)corto_resultIter_o, o))
#define corto_sequence(o) ((corto_sequence)corto_assertType((corto_type)corto_sequence_o, o))
#define corto_state(o) ((corto_state *)corto_assertType((corto_type)corto_state_o, o))
#define corto_string(o) ((corto_string *)corto_assertType((corto_type)corto_string_o, o))
#define corto_struct(o) ((corto_struct)corto_assertType((corto_type)corto_struct_o, o))
#define corto_text(o) ((corto_text)corto_assertType((corto_type)corto_text_o, o))
#define corto_type(o) ((corto_type)corto_assertType((corto_type)corto_type_o, o))
#define corto_typeKind(o) ((corto_typeKind *)corto_assertType((corto_type)corto_typeKind_o, o))
#define corto_uint(o) ((corto_uint)corto_assertType((corto_type)corto_uint_o, o))
#define corto_uint16(o) ((corto_uint16 *)corto_assertType((corto_type)corto_uint16_o, o))
#define corto_uint32(o) ((corto_uint32 *)corto_assertType((corto_type)corto_uint32_o, o))
#define corto_uint64(o) ((corto_uint64 *)corto_assertType((corto_type)corto_uint64_o, o))
#define corto_uint8(o) ((corto_uint8 *)corto_assertType((corto_type)corto_uint8_o, o))
#define corto_virtual(o) ((corto_virtual)corto_assertType((corto_type)corto_virtual_o, o))
#define corto_vtable(o) ((corto_vtable *)corto_assertType((corto_type)corto_vtable_o, o))
#define corto_width(o) ((corto_width *)corto_assertType((corto_type)corto_width_o, o))
#define corto_word(o) ((corto_word *)corto_assertType((corto_type)corto_word_o, o))

/* Type definitions */
/* /corto/lang/typeKind */
typedef enum corto_typeKind {
    CORTO_VOID = 0,
    CORTO_ANY = 1,
    CORTO_PRIMITIVE = 2,
    CORTO_COMPOSITE = 3,
    CORTO_COLLECTION = 4,
    CORTO_ITERATOR = 5
} corto_typeKind;

/* /corto/lang/bool */
typedef char corto_bool;

/* /corto/lang/uint32 */
typedef uint32_t corto_uint32;

/* /corto/lang/uint16 */
typedef uint16_t corto_uint16;

/*  /corto/lang/type */
CORTO_CLASS(corto_type);

/* /corto/lang/state */
CORTO_BITMASK(corto_state);
    #define CORTO_VALID (0x1)
    #define CORTO_DECLARED (0x2)
    #define CORTO_DEFINED (0x4)
    #define CORTO_DESTRUCTED (0x8)

/* /corto/lang/word */
typedef uintptr_t corto_word;

/* /corto/lang/object */
typedef void *corto_object;

/* /corto/lang/string */
typedef char* corto_string;

/*  /corto/lang/parameter */
typedef struct corto_parameter corto_parameter;

struct corto_parameter {
    corto_string name;
    corto_type type;
    corto_bool passByReference;
};

CORTO_SEQUENCE(corto_parameterseq, corto_parameter,);

/*  /corto/lang/function */
CORTO_CLASS(corto_function);

CORTO_CLASS_DEF(corto_function) {
    corto_type returnType;
    corto_bool returnsReference;
    corto_bool overloaded;
    corto_uint32 kind;
    corto_word impl;
    corto_word implData;
    corto_object resource;
    corto_uint16 size;
    corto_parameterseq parameters;
    corto_uint32 nextParameterId;
};

CORTO_SEQUENCE(corto_vtable, corto_function,);

/*  /corto/lang/delegatedata */
typedef struct corto_delegatedata corto_delegatedata;

struct corto_delegatedata {
    corto_object instance;
    corto_function procedure;
};

/*  /corto/lang/initAction */
typedef struct corto_initAction corto_initAction;

struct corto_initAction {
    corto_delegatedata _parent;
};

CORTO_CLASS_DEF(corto_type) {
    corto_typeKind kind;
    corto_bool reference;
    corto_bool hasResources;
    corto_uint32 templateId;
    corto_uint32 size;
    corto_uint16 alignment;
    corto_type parentType;
    corto_state parentState;
    corto_type defaultType;
    corto_type defaultProcedureType;
    corto_vtable metaprocedures;
    corto_initAction init;
};

/* /corto/lang/modifier */
CORTO_BITMASK(corto_modifier);
    #define CORTO_GLOBAL (0x0)
    #define CORTO_LOCAL (0x1)
    #define CORTO_PRIVATE (0x2)
    #define CORTO_READONLY (0x4)
    #define CORTO_CONST (0x8)
    #define CORTO_HIDDEN (0x10)

/*  /corto/lang/member */
CORTO_CLASS(corto_member);

CORTO_CLASS_DEF(corto_member) {
    corto_type type;
    corto_modifier modifiers;
    corto_state state;
    corto_bool weak;
    corto_uint32 id;
    corto_uint32 offset;
};

/*  /corto/lang/alias */
CORTO_CLASS(corto_alias);

CORTO_CLASS_DEF(corto_alias) {
    CORTO_EXTEND(corto_member);
    corto_member member;
};

/* /corto/lang/any */
CORTO_ANY(corto_any);

/* /corto/lang/collectionKind */
typedef enum corto_collectionKind {
    CORTO_ARRAY = 0,
    CORTO_SEQUENCE = 1,
    CORTO_LIST = 2,
    CORTO_MAP = 3
} corto_collectionKind;

/*  /corto/lang/collection */
CORTO_CLASS(corto_collection);

CORTO_CLASS_DEF(corto_collection) {
    CORTO_EXTEND(corto_type);
    corto_collectionKind kind;
    corto_type elementType;
    corto_uint32 max;
};

/*  /corto/lang/array */
CORTO_CLASS(corto_array);

CORTO_CLASS_DEF(corto_array) {
    CORTO_EXTEND(corto_collection);
    corto_type elementType;
};

/* /corto/lang/attr */
CORTO_BITMASK(corto_attr);
    #define CORTO_ATTR_SCOPED (0x1)
    #define CORTO_ATTR_WRITABLE (0x2)
    #define CORTO_ATTR_OBSERVABLE (0x4)
    #define CORTO_ATTR_PERSISTENT (0x8)
    #define CORTO_ATTR_DEFAULT (0x10)

/* /corto/lang/primitiveKind */
typedef enum corto_primitiveKind {
    CORTO_BINARY = 0,
    CORTO_BOOLEAN = 1,
    CORTO_CHARACTER = 2,
    CORTO_INTEGER = 3,
    CORTO_UINTEGER = 4,
    CORTO_FLOAT = 5,
    CORTO_TEXT = 6,
    CORTO_ENUM = 7,
    CORTO_BITMASK = 8
} corto_primitiveKind;

/* /corto/lang/width */
typedef enum corto_width {
    CORTO_WIDTH_8 = 0,
    CORTO_WIDTH_16 = 1,
    CORTO_WIDTH_32 = 2,
    CORTO_WIDTH_64 = 3,
    CORTO_WIDTH_WORD = 4
} corto_width;

/* /corto/lang/uint8 */
typedef uint8_t corto_uint8;

/*  /corto/lang/primitive */
CORTO_CLASS(corto_primitive);

CORTO_CLASS_DEF(corto_primitive) {
    CORTO_EXTEND(corto_type);
    corto_primitiveKind kind;
    corto_width width;
    corto_uint8 convertId;
};

/*  /corto/lang/binary */
CORTO_CLASS(corto_binary);

CORTO_CLASS_DEF(corto_binary) {
    CORTO_EXTEND(corto_primitive);
};

CORTO_SEQUENCE(corto_objectseq, corto_object,);

/*  /corto/lang/enum */
CORTO_CLASS(corto_enum);

CORTO_CLASS_DEF(corto_enum) {
    CORTO_EXTEND(corto_primitive);
    corto_objectseq constants;
};

/*  /corto/lang/bitmask */
CORTO_CLASS(corto_bitmask);

CORTO_CLASS_DEF(corto_bitmask) {
    CORTO_EXTEND(corto_enum);
};

/*  /corto/lang/boolean */
CORTO_CLASS(corto_boolean);

CORTO_CLASS_DEF(corto_boolean) {
    CORTO_EXTEND(corto_primitive);
};

/* /corto/lang/char */
typedef char corto_char;

/*  /corto/lang/character */
CORTO_CLASS(corto_character);

CORTO_CLASS_DEF(corto_character) {
    CORTO_EXTEND(corto_primitive);
};

/* /corto/lang/compositeKind */
typedef enum corto_compositeKind {
    CORTO_INTERFACE = 0,
    CORTO_STRUCT = 1,
    CORTO_CLASS = 2,
    CORTO_DELEGATE = 3,
    CORTO_PROCEDURE = 4
} corto_compositeKind;

CORTO_SEQUENCE(corto_memberseq, corto_member,);

/*  /corto/lang/interface */
CORTO_CLASS(corto_interface);

CORTO_CLASS_DEF(corto_interface) {
    CORTO_EXTEND(corto_type);
    corto_compositeKind kind;
    corto_uint32 nextMemberId;
    corto_memberseq members;
    corto_vtable methods;
    corto_interface base;
};

/*  /corto/lang/struct */
CORTO_CLASS(corto_struct);

CORTO_CLASS_DEF(corto_struct) {
    CORTO_EXTEND(corto_interface);
    corto_modifier baseAccess;
};

CORTO_SEQUENCE(corto_interfaceseq, corto_interface,);

/*  /corto/lang/interfaceVector */
typedef struct corto_interfaceVector corto_interfaceVector;

struct corto_interfaceVector {
    corto_interface interface;
    corto_vtable vector;
};

CORTO_SEQUENCE(corto_interfaceVectorseq, corto_interfaceVector,);

/* /corto/lang/eventMask */
CORTO_BITMASK(corto_eventMask);
    #define CORTO_ON_DECLARE (0x1)
    #define CORTO_ON_DEFINE (0x2)
    #define CORTO_ON_DELETE (0x4)
    #define CORTO_ON_INVALIDATE (0x8)
    #define CORTO_ON_UPDATE (0x10)
    #define CORTO_ON_SELF (0x20)
    #define CORTO_ON_SCOPE (0x40)
    #define CORTO_ON_TREE (0x80)
    #define CORTO_ON_VALUE (0x100)
    #define CORTO_ON_METAVALUE (0x200)

/*  /corto/lang/dispatcher */
CORTO_INTERFACE(corto_dispatcher);

/*  /corto/lang/observer */
CORTO_CLASS(corto_observer);

CORTO_CLASS_DEF(corto_observer) {
    CORTO_EXTEND(corto_function);
    corto_eventMask mask;
    corto_object observable;
    corto_uint32 _template;
    corto_dispatcher dispatcher;
    corto_object me;
    corto_object observing;
    corto_observer delayedBinder;
};

CORTO_SEQUENCE(corto_observerseq, corto_observer,);

/*  /corto/lang/destructAction */
typedef struct corto_destructAction corto_destructAction;

struct corto_destructAction {
    corto_delegatedata _parent;
};

/*  /corto/lang/class */
CORTO_CLASS(corto_class);

CORTO_CLASS_DEF(corto_class) {
    CORTO_EXTEND(corto_struct);
    corto_interfaceseq implements;
    corto_interfaceVectorseq interfaceVector;
    corto_observerseq observers;
    corto_initAction construct;
    corto_destructAction destruct;
};

/* /corto/lang/constant */
typedef int32_t corto_constant;

/*  /corto/lang/delegate */
CORTO_CLASS(corto_delegate);

CORTO_CLASS_DEF(corto_delegate) {
    CORTO_EXTEND(corto_struct);
    corto_type returnType;
    corto_bool returnsReference;
    corto_parameterseq parameters;
};

/* /corto/lang/equalityKind */
typedef enum corto_equalityKind {
    CORTO_EQ = 0,
    CORTO_LT = -1,
    CORTO_GT = 1,
    CORTO_NEQ = 2
} corto_equalityKind;

/*  /corto/lang/event */
CORTO_CLASS(corto_event);

CORTO_CLASS_DEF(corto_event) {
    corto_uint16 kind;
    corto_bool handled;
};

/* /corto/lang/float64 */
typedef double corto_float64;

/*  /corto/lang/float */
CORTO_CLASS(corto_float);

CORTO_CLASS_DEF(corto_float) {
    CORTO_EXTEND(corto_primitive);
    corto_float64 min;
    corto_float64 max;
};

/* /corto/lang/float32 */
typedef float corto_float32;

/* /corto/lang/int64 */
typedef int64_t corto_int64;

/*  /corto/lang/int */
CORTO_CLASS(corto_int);

CORTO_CLASS_DEF(corto_int) {
    CORTO_EXTEND(corto_primitive);
    corto_int64 min;
    corto_int64 max;
};

/* /corto/lang/int16 */
typedef int16_t corto_int16;

/* /corto/lang/int32 */
typedef int32_t corto_int32;

/* /corto/lang/int8 */
typedef int8_t corto_int8;

/*  /corto/lang/invokeAction */
typedef struct corto_invokeAction corto_invokeAction;

struct corto_invokeAction {
    corto_delegatedata _parent;
};

/*  /corto/lang/query */
CORTO_CLASS(corto_query);

CORTO_CLASS_DEF(corto_query) {
    corto_object from;
    corto_eventMask mask;
};

/*  /corto/lang/notifyAction */
typedef struct corto_notifyAction corto_notifyAction;

struct corto_notifyAction {
    corto_delegatedata _parent;
};

/*  /corto/lang/requestAction */
typedef struct corto_requestAction corto_requestAction;

struct corto_requestAction {
    corto_delegatedata _parent;
};

/*  /corto/lang/replicator */
CORTO_CLASS(corto_replicator);

CORTO_CLASS_DEF(corto_replicator) {
    corto_object mount;
    corto_query query;
    corto_notifyAction onDeclare;
    corto_notifyAction onUpdate;
    corto_notifyAction onDelete;
    corto_invokeAction onInvoke;
    corto_requestAction onRequest;
};

/* /corto/lang/octet */
typedef uint8_t corto_octet;

CORTO_SEQUENCE(corto_octetseq, corto_octet,);

/*  /corto/lang/invokeEvent */
CORTO_CLASS(corto_invokeEvent);

CORTO_CLASS_DEF(corto_invokeEvent) {
    CORTO_EXTEND(corto_event);
    corto_replicator replicator;
    corto_object instance;
    corto_function function;
    corto_octetseq args;
};

/*  /corto/lang/iterator */
CORTO_CLASS(corto_iterator);

CORTO_CLASS_DEF(corto_iterator) {
    CORTO_EXTEND(corto_type);
    corto_type elementType;
};

/*  /corto/lang/list */
CORTO_CLASS(corto_list);

CORTO_CLASS_DEF(corto_list) {
    CORTO_EXTEND(corto_collection);
};

/*  /corto/lang/map */
CORTO_CLASS(corto_map);

CORTO_CLASS_DEF(corto_map) {
    CORTO_EXTEND(corto_collection);
    corto_type elementType;
    corto_type keyType;
    corto_uint32 max;
};

/*  /corto/lang/metaprocedure */
CORTO_CLASS(corto_metaprocedure);

CORTO_CLASS_DEF(corto_metaprocedure) {
    CORTO_EXTEND(corto_function);
    corto_bool referenceOnly;
};

/*  /corto/lang/method */
CORTO_CLASS(corto_method);

CORTO_CLASS_DEF(corto_method) {
    CORTO_EXTEND(corto_function);
    corto_bool _virtual;
};

/*  /corto/lang/observableEvent */
CORTO_CLASS(corto_observableEvent);

CORTO_CLASS_DEF(corto_observableEvent) {
    CORTO_EXTEND(corto_event);
    corto_observer observer;
    corto_object me;
    corto_object source;
    corto_object observable;
};

/* /corto/lang/operatorKind */
typedef enum corto_operatorKind {
    CORTO_ASSIGN = 0,
    CORTO_ASSIGN_ADD = 1,
    CORTO_ASSIGN_SUB = 2,
    CORTO_ASSIGN_MUL = 3,
    CORTO_ASSIGN_DIV = 4,
    CORTO_ASSIGN_MOD = 5,
    CORTO_ASSIGN_XOR = 6,
    CORTO_ASSIGN_OR = 7,
    CORTO_ASSIGN_AND = 8,
    CORTO_ASSIGN_UPDATE = 9,
    CORTO_ADD = 10,
    CORTO_SUB = 11,
    CORTO_MUL = 12,
    CORTO_DIV = 13,
    CORTO_MOD = 14,
    CORTO_INC = 15,
    CORTO_DEC = 16,
    CORTO_XOR = 17,
    CORTO_OR = 18,
    CORTO_AND = 19,
    CORTO_NOT = 20,
    CORTO_COND_OR = 21,
    CORTO_COND_AND = 22,
    CORTO_COND_NOT = 23,
    CORTO_COND_EQ = 24,
    CORTO_COND_NEQ = 25,
    CORTO_COND_GT = 26,
    CORTO_COND_LT = 27,
    CORTO_COND_GTEQ = 28,
    CORTO_COND_LTEQ = 29,
    CORTO_SHIFT_LEFT = 30,
    CORTO_SHIFT_RIGHT = 31,
    CORTO_REF = 32
} corto_operatorKind;

/*  /corto/lang/package */
CORTO_CLASS(corto_package);

CORTO_CLASS_DEF(corto_package) {
    corto_string url;
};

/* /corto/lang/procedureKind */
typedef enum corto_procedureKind {
    CORTO_FUNCTION = 0,
    CORTO_METHOD = 1,
    CORTO_OBSERVER = 2,
    CORTO_METAPROCEDURE = 3
} corto_procedureKind;

/*  /corto/lang/procedure */
CORTO_CLASS(corto_procedure);

CORTO_CLASS_DEF(corto_procedure) {
    CORTO_EXTEND(corto_struct);
    corto_procedureKind kind;
    corto_initAction bind;
};

/*  /corto/lang/result */
typedef struct corto_result corto_result;

struct corto_result {
    corto_string name;
    corto_string parent;
    corto_string type;
};

CORTO_ITERATOR(corto_resultIter);

/*  /corto/lang/sequence */
CORTO_CLASS(corto_sequence);

CORTO_CLASS_DEF(corto_sequence) {
    CORTO_EXTEND(corto_collection);
};

/* /corto/lang/uint64 */
typedef uint64_t corto_uint64;

/*  /corto/lang/text */
CORTO_CLASS(corto_text);

CORTO_CLASS_DEF(corto_text) {
    CORTO_EXTEND(corto_primitive);
    corto_width charWidth;
    corto_uint64 length;
};

/*  /corto/lang/uint */
CORTO_CLASS(corto_uint);

CORTO_CLASS_DEF(corto_uint) {
    CORTO_EXTEND(corto_primitive);
    corto_uint64 min;
    corto_uint64 max;
};

/*  /corto/lang/virtual */
CORTO_CLASS(corto_virtual);

CORTO_CLASS_DEF(corto_virtual) {
    CORTO_EXTEND(corto_method);
};

/* /corto/lang/void */
typedef void corto_void;

#ifdef __cplusplus
}
#endif
#endif

