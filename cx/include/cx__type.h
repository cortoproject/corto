/* cx__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef cx__type_H
#define cx__type_H

#include "cx_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define cx_alias(o) ((cx_alias)cx_assertType((cx_type)cx_alias_o, o))
#define cx_array(o) ((cx_array)cx_assertType((cx_type)cx_array_o, o))
#define cx_binary(o) ((cx_binary)cx_assertType((cx_type)cx_binary_o, o))
#define cx_bitmask(o) ((cx_bitmask)cx_assertType((cx_type)cx_bitmask_o, o))
#define cx_boolean(o) ((cx_boolean)cx_assertType((cx_type)cx_boolean_o, o))
#define cx_character(o) ((cx_character)cx_assertType((cx_type)cx_character_o, o))
#define cx_class(o) ((cx_class)cx_assertType((cx_type)cx_class_o, o))
#define cx_collection(o) ((cx_collection)cx_assertType((cx_type)cx_collection_o, o))
#define cx_delegate(o) ((cx_delegate)cx_assertType((cx_type)cx_delegate_o, o))
#define cx_dispatcher(o) ((cx_dispatcher)cx_assertType((cx_type)cx_dispatcher_o, o))
#define cx_enum(o) ((cx_enum)cx_assertType((cx_type)cx_enum_o, o))
#define cx_event(o) ((cx_event)cx_assertType((cx_type)cx_event_o, o))
#define cx_float(o) ((cx_float)cx_assertType((cx_type)cx_float_o, o))
#define cx_function(o) ((cx_function)cx_assertType((cx_type)cx_function_o, o))
#define cx_int(o) ((cx_int)cx_assertType((cx_type)cx_int_o, o))
#define cx_interface(o) ((cx_interface)cx_assertType((cx_type)cx_interface_o, o))
#define cx_iterator(o) ((cx_iterator)cx_assertType((cx_type)cx_iterator_o, o))
#define cx_list(o) ((cx_list)cx_assertType((cx_type)cx_list_o, o))
#define cx_map(o) ((cx_map)cx_assertType((cx_type)cx_map_o, o))
#define cx_member(o) ((cx_member)cx_assertType((cx_type)cx_member_o, o))
#define cx_metaprocedure(o) ((cx_metaprocedure)cx_assertType((cx_type)cx_metaprocedure_o, o))
#define cx_method(o) ((cx_method)cx_assertType((cx_type)cx_method_o, o))
#define cx_observableEvent(o) ((cx_observableEvent)cx_assertType((cx_type)cx_observableEvent_o, o))
#define cx_observer(o) ((cx_observer)cx_assertType((cx_type)cx_observer_o, o))
#define cx_package(o) ((cx_package)cx_assertType((cx_type)cx_package_o, o))
#define cx_primitive(o) ((cx_primitive)cx_assertType((cx_type)cx_primitive_o, o))
#define cx_procedure(o) ((cx_procedure)cx_assertType((cx_type)cx_procedure_o, o))
#define cx_sequence(o) ((cx_sequence)cx_assertType((cx_type)cx_sequence_o, o))
#define cx_struct(o) ((cx_struct)cx_assertType((cx_type)cx_struct_o, o))
#define cx_text(o) ((cx_text)cx_assertType((cx_type)cx_text_o, o))
#define cx_type(o) ((cx_type)cx_assertType((cx_type)cx_type_o, o))
#define cx_uint(o) ((cx_uint)cx_assertType((cx_type)cx_uint_o, o))
#define cx_virtual(o) ((cx_virtual)cx_assertType((cx_type)cx_virtual_o, o))

/* Type definitions */
/* ::cortex::lang::typeKind */
typedef enum cx_typeKind {
    CX_VOID = 0,
    CX_ANY = 1,
    CX_PRIMITIVE = 2,
    CX_COMPOSITE = 3,
    CX_COLLECTION = 4,
    CX_ITERATOR = 5
} cx_typeKind;

/* ::cortex::lang::bool */
typedef char cx_bool;

/* ::cortex::lang::uint32 */
typedef uint32_t cx_uint32;

/* ::cortex::lang::uint16 */
typedef uint16_t cx_uint16;

/*  ::cortex::lang::type */
CX_CLASS(cx_type);

/* ::cortex::lang::state */
CX_BITMASK(cx_state);
    #define CX_VALID (0x1)
    #define CX_DECLARED (0x2)
    #define CX_DEFINED (0x4)
    #define CX_DESTRUCTED (0x8)

/* ::cortex::lang::word */
typedef uintptr_t cx_word;

/* ::cortex::lang::object */
typedef void *cx_object;

/* ::cortex::lang::int16 */
typedef int16_t cx_int16;

/* ::cortex::lang::string */
typedef char* cx_string;

/*  ::cortex::lang::parameter */
typedef struct cx_parameter cx_parameter;

struct cx_parameter {
    cx_string name;
    cx_type type;
    cx_bool passByReference;
};

CX_SEQUENCE(cx_parameterSeq, cx_parameter,);

/*  ::cortex::lang::function */
CX_CLASS(cx_function);

CX_CLASS_DEF(cx_function) {
    cx_type returnType;
    cx_bool returnsReference;
    cx_bool overloaded;
    cx_uint32 kind;
    cx_word impl;
    cx_word implData;
    cx_object resource;
    cx_int16 size;
    cx_parameterSeq parameters;
    cx_uint32 nextParameterId;
};

CX_SEQUENCE(cx_vtable, cx_function,);

/*  ::cortex::lang::delegatedata */
typedef struct cx_delegatedata cx_delegatedata;

struct cx_delegatedata {
    cx_object instance;
    cx_function procedure;
};

/*  ::cortex::lang::callbackInit */
typedef struct cx_callbackInit cx_callbackInit;

struct cx_callbackInit {
    cx_delegatedata _parent;
};

CX_CLASS_DEF(cx_type) {
    cx_typeKind kind;
    cx_bool reference;
    cx_bool hasResources;
    cx_uint32 templateId;
    cx_uint32 size;
    cx_uint16 alignment;
    cx_type defaultType;
    cx_type parentType;
    cx_state parentState;
    cx_vtable metaprocedures;
    cx_callbackInit init;
};

/* ::cortex::lang::primitiveKind */
typedef enum cx_primitiveKind {
    CX_BINARY = 0,
    CX_BOOLEAN = 1,
    CX_CHARACTER = 2,
    CX_INTEGER = 3,
    CX_UINTEGER = 4,
    CX_FLOAT = 5,
    CX_TEXT = 6,
    CX_ENUM = 7,
    CX_BITMASK = 8,
    CX_ALIAS = 9
} cx_primitiveKind;

/* ::cortex::lang::width */
typedef enum cx_width {
    CX_WIDTH_8 = 0,
    CX_WIDTH_16 = 1,
    CX_WIDTH_32 = 2,
    CX_WIDTH_64 = 3,
    CX_WIDTH_WORD = 4
} cx_width;

/* ::cortex::lang::uint8 */
typedef uint8_t cx_uint8;

/*  ::cortex::lang::primitive */
CX_CLASS(cx_primitive);

CX_CLASS_DEF(cx_primitive) {
    CX_EXTEND(cx_type);
    cx_primitiveKind kind;
    cx_width width;
    cx_uint8 convertId;
};

/*  ::cortex::lang::alias */
CX_CLASS(cx_alias);

CX_CLASS_DEF(cx_alias) {
    CX_EXTEND(cx_primitive);
    cx_string typeName;
};

/* ::cortex::lang::any */
CX_ANY(cx_any);

/* ::cortex::lang::collectionKind */
typedef enum cx_collectionKind {
    CX_ARRAY = 0,
    CX_SEQUENCE = 1,
    CX_LIST = 2,
    CX_MAP = 3
} cx_collectionKind;

/*  ::cortex::lang::collection */
CX_CLASS(cx_collection);

CX_CLASS_DEF(cx_collection) {
    CX_EXTEND(cx_type);
    cx_collectionKind kind;
    cx_type elementType;
    cx_uint32 max;
};

/*  ::cortex::lang::array */
CX_CLASS(cx_array);

CX_CLASS_DEF(cx_array) {
    CX_EXTEND(cx_collection);
    cx_type elementType;
};

/* ::cortex::lang::attr */
CX_BITMASK(cx_attr);
    #define CX_ATTR_SCOPED (0x1)
    #define CX_ATTR_WRITABLE (0x2)
    #define CX_ATTR_OBSERVABLE (0x4)

/*  ::cortex::lang::binary */
CX_CLASS(cx_binary);

CX_CLASS_DEF(cx_binary) {
    CX_EXTEND(cx_primitive);
};

CX_SEQUENCE(cx_objectSeq, cx_object,);

/*  ::cortex::lang::enum */
CX_CLASS(cx_enum);

CX_CLASS_DEF(cx_enum) {
    CX_EXTEND(cx_primitive);
    cx_objectSeq constants;
};

/*  ::cortex::lang::bitmask */
CX_CLASS(cx_bitmask);

CX_CLASS_DEF(cx_bitmask) {
    CX_EXTEND(cx_enum);
};

/*  ::cortex::lang::boolean */
CX_CLASS(cx_boolean);

CX_CLASS_DEF(cx_boolean) {
    CX_EXTEND(cx_primitive);
};

/*  ::cortex::lang::callbackDestruct */
typedef struct cx_callbackDestruct cx_callbackDestruct;

struct cx_callbackDestruct {
    cx_delegatedata _parent;
};

/* ::cortex::lang::char */
typedef char cx_char;

/*  ::cortex::lang::character */
CX_CLASS(cx_character);

CX_CLASS_DEF(cx_character) {
    CX_EXTEND(cx_primitive);
};

/* ::cortex::lang::compositeKind */
typedef enum cx_compositeKind {
    CX_INTERFACE = 0,
    CX_STRUCT = 1,
    CX_CLASS = 2,
    CX_DELEGATE = 3,
    CX_PROCEDURE = 4
} cx_compositeKind;

/* ::cortex::lang::modifier */
CX_BITMASK(cx_modifier);
    #define CX_GLOBAL (0x0)
    #define CX_LOCAL (0x1)
    #define CX_PRIVATE (0x2)
    #define CX_READONLY (0x4)
    #define CX_CONST (0x8)

/*  ::cortex::lang::member */
CX_CLASS(cx_member);

CX_CLASS_DEF(cx_member) {
    cx_type type;
    cx_modifier modifiers;
    cx_state state;
    cx_bool weak;
    cx_uint32 id;
    cx_uint32 offset;
};

CX_SEQUENCE(cx_memberSeq, cx_member,);

/*  ::cortex::lang::interface */
CX_CLASS(cx_interface);

CX_CLASS_DEF(cx_interface) {
    CX_EXTEND(cx_type);
    cx_compositeKind kind;
    cx_uint32 nextMemberId;
    cx_memberSeq members;
    cx_vtable methods;
    cx_interface base;
};

/*  ::cortex::lang::struct */
CX_CLASS(cx_struct);

CX_CLASS_DEF(cx_struct) {
    CX_EXTEND(cx_interface);
    cx_modifier baseAccess;
};

CX_SEQUENCE(cx_interfaceSeq, cx_interface,);

/*  ::cortex::lang::interfaceVector */
typedef struct cx_interfaceVector cx_interfaceVector;

struct cx_interfaceVector {
    cx_interface interface;
    cx_vtable vector;
};

CX_SEQUENCE(cx_interfaceVectorSeq, cx_interfaceVector,);

/* ::cortex::lang::eventMask */
CX_BITMASK(cx_eventMask);
    #define CX_ON_DECLARE (0x1)
    #define CX_ON_DEFINE (0x2)
    #define CX_ON_DESTRUCT (0x4)
    #define CX_ON_INVALIDATE (0x8)
    #define CX_ON_UPDATE (0x10)
    #define CX_ON_SELF (0x20)
    #define CX_ON_SCOPE (0x40)
    #define CX_ON_VALUE (0x80)
    #define CX_ON_METAVALUE (0x100)

/*  ::cortex::lang::dispatcher */
CX_INTERFACE(cx_dispatcher);

/*  ::cortex::lang::observer */
CX_CLASS(cx_observer);

CX_CLASS_DEF(cx_observer) {
    CX_EXTEND(cx_function);
    cx_object observable;
    cx_eventMask mask;
    cx_string expression;
    cx_uint32 template;
    cx_dispatcher dispatcher;
    cx_object me;
    cx_object observing;
    cx_observer delayedBinder;
};

CX_SEQUENCE(cx_observerSeq, cx_observer,);

/*  ::cortex::lang::class */
CX_CLASS(cx_class);

CX_CLASS_DEF(cx_class) {
    CX_EXTEND(cx_struct);
    cx_interfaceSeq implements;
    cx_interfaceVectorSeq interfaceVector;
    cx_observerSeq observers;
    cx_callbackInit construct;
    cx_callbackDestruct destruct;
};

/* ::cortex::lang::constant */
typedef int32_t cx_constant;

/*  ::cortex::lang::delegate */
CX_CLASS(cx_delegate);

CX_CLASS_DEF(cx_delegate) {
    CX_EXTEND(cx_struct);
    cx_type returnType;
    cx_bool returnsReference;
    cx_parameterSeq parameters;
};

/* ::cortex::lang::equalityKind */
typedef enum cx_equalityKind {
    CX_EQ = 0,
    CX_LT = -1,
    CX_GT = 1,
    CX_NEQ = 2
} cx_equalityKind;

/*  ::cortex::lang::event */
CX_CLASS(cx_event);

CX_CLASS_DEF(cx_event) {
    cx_uint16 kind;
    cx_bool handled;
};

/* ::cortex::lang::float64 */
typedef double cx_float64;

/*  ::cortex::lang::float */
CX_CLASS(cx_float);

CX_CLASS_DEF(cx_float) {
    CX_EXTEND(cx_primitive);
    cx_float64 min;
    cx_float64 max;
};

/* ::cortex::lang::float32 */
typedef float cx_float32;

/* ::cortex::lang::int64 */
typedef int64_t cx_int64;

/*  ::cortex::lang::int */
CX_CLASS(cx_int);

CX_CLASS_DEF(cx_int) {
    CX_EXTEND(cx_primitive);
    cx_int64 min;
    cx_int64 max;
};

/* ::cortex::lang::int32 */
typedef int32_t cx_int32;

/* ::cortex::lang::int8 */
typedef int8_t cx_int8;

/*  ::cortex::lang::iterator */
CX_CLASS(cx_iterator);

CX_CLASS_DEF(cx_iterator) {
    CX_EXTEND(cx_type);
    cx_type elementType;
};

/*  ::cortex::lang::list */
CX_CLASS(cx_list);

CX_CLASS_DEF(cx_list) {
    CX_EXTEND(cx_collection);
};

/*  ::cortex::lang::map */
CX_CLASS(cx_map);

CX_CLASS_DEF(cx_map) {
    CX_EXTEND(cx_collection);
    cx_type elementType;
    cx_type keyType;
    cx_uint32 max;
};

/*  ::cortex::lang::metaprocedure */
CX_CLASS(cx_metaprocedure);

CX_CLASS_DEF(cx_metaprocedure) {
    CX_EXTEND(cx_function);
    cx_bool referenceOnly;
};

/*  ::cortex::lang::method */
CX_CLASS(cx_method);

CX_CLASS_DEF(cx_method) {
    CX_EXTEND(cx_function);
    cx_bool virtual;
};

/*  ::cortex::lang::observableEvent */
CX_CLASS(cx_observableEvent);

CX_CLASS_DEF(cx_observableEvent) {
    CX_EXTEND(cx_event);
    cx_observer observer;
    cx_object me;
    cx_object source;
    cx_object observable;
};

/* ::cortex::lang::octet */
typedef uint8_t cx_octet;

/* ::cortex::lang::operatorKind */
typedef enum cx_operatorKind {
    CX_ASSIGN = 0,
    CX_ASSIGN_ADD = 1,
    CX_ASSIGN_SUB = 2,
    CX_ASSIGN_MUL = 3,
    CX_ASSIGN_DIV = 4,
    CX_ASSIGN_MOD = 5,
    CX_ASSIGN_XOR = 6,
    CX_ASSIGN_OR = 7,
    CX_ASSIGN_AND = 8,
    CX_ASSIGN_UPDATE = 9,
    CX_ADD = 10,
    CX_SUB = 11,
    CX_MUL = 12,
    CX_DIV = 13,
    CX_MOD = 14,
    CX_INC = 15,
    CX_DEC = 16,
    CX_XOR = 17,
    CX_OR = 18,
    CX_AND = 19,
    CX_NOT = 20,
    CX_COND_OR = 21,
    CX_COND_AND = 22,
    CX_COND_NOT = 23,
    CX_COND_EQ = 24,
    CX_COND_NEQ = 25,
    CX_COND_GT = 26,
    CX_COND_LT = 27,
    CX_COND_GTEQ = 28,
    CX_COND_LTEQ = 29,
    CX_SHIFT_LEFT = 30,
    CX_SHIFT_RIGHT = 31,
    CX_REF = 32
} cx_operatorKind;

/*  ::cortex::lang::package */
CX_CLASS(cx_package);

CX_CLASS_DEF(cx_package) {
    cx_string url;
};

/* ::cortex::lang::procedureKind */
typedef enum cx_procedureKind {
    CX_FUNCTION = 0,
    CX_METHOD = 1,
    CX_OBSERVER = 2,
    CX_METAPROCEDURE = 3
} cx_procedureKind;

/*  ::cortex::lang::procedure */
CX_CLASS(cx_procedure);

CX_CLASS_DEF(cx_procedure) {
    CX_EXTEND(cx_struct);
    cx_procedureKind kind;
    cx_callbackInit bind;
};

/*  ::cortex::lang::sequence */
CX_CLASS(cx_sequence);

CX_CLASS_DEF(cx_sequence) {
    CX_EXTEND(cx_collection);
};

/* ::cortex::lang::uint64 */
typedef uint64_t cx_uint64;

/*  ::cortex::lang::text */
CX_CLASS(cx_text);

CX_CLASS_DEF(cx_text) {
    CX_EXTEND(cx_primitive);
    cx_width charWidth;
    cx_uint64 length;
};

/*  ::cortex::lang::uint */
CX_CLASS(cx_uint);

CX_CLASS_DEF(cx_uint) {
    CX_EXTEND(cx_primitive);
    cx_uint64 min;
    cx_uint64 max;
};

/*  ::cortex::lang::virtual */
CX_CLASS(cx_virtual);

CX_CLASS_DEF(cx_virtual) {
    CX_EXTEND(cx_method);
};

/* ::cortex::lang::void */
typedef void cx_void;

#ifdef __cplusplus
}
#endif
#endif

