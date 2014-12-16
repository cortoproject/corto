/* db__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef db__type_H
#define db__type_H

#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define db_alias(o) ((db_alias)o)
#define db_array(o) ((db_array)o)
#define db_binary(o) ((db_binary)o)
#define db_bitmask(o) ((db_bitmask)o)
#define db_boolean(o) ((db_boolean)o)
#define db_character(o) ((db_character)o)
#define db_class(o) ((db_class)o)
#define db_collection(o) ((db_collection)o)
#define db_enum(o) ((db_enum)o)
#define db_event(o) ((db_event)o)
#define db_float(o) ((db_float)o)
#define db_int(o) ((db_int)o)
#define db_interface(o) ((db_interface)o)
#define db_list(o) ((db_list)o)
#define db_map(o) ((db_map)o)
#define db_member(o) ((db_member)o)
#define db_observableEvent(o) ((db_observableEvent)o)
#define db_primitive(o) ((db_primitive)o)
#define db_procedure(o) ((db_procedure)o)
#define db_sequence(o) ((db_sequence)o)
#define db_struct(o) ((db_struct)o)
#define db_text(o) ((db_text)o)
#define db_type(o) ((db_type)o)
#define db_typedef(o) ((db_typedef)o)
#define db_uint(o) ((db_uint)o)

/* Type definitions */
/*  ::hyve::lang::typedef */
DB_CLASS(db_typedef);

/*  ::hyve::lang::type */
DB_CLASS(db_type);

DB_CLASS_DEF(db_typedef) {
    db_typedef type;
    db_type real;
};

/* ::hyve::lang::typeKind */
typedef enum db_typeKind {
    DB_VOID = 0,
    DB_ANY = 1,
    DB_PRIMITIVE = 2,
    DB_COMPOSITE = 3,
    DB_COLLECTION = 4
} db_typeKind;

/* ::hyve::lang::bool */
typedef char db_bool;

/* ::hyve::lang::uint32 */
typedef uint32_t db_uint32;

/* ::hyve::lang::uint16 */
typedef uint16_t db_uint16;

/* ::hyve::lang::state */
DB_BITMASK(db_state);
    #define DB_VALID (0x1)
    #define DB_DECLARED (0x2)
    #define DB_DEFINED (0x4)

/* ::hyve::lang::word */
typedef uintptr_t db_word;

/* ::hyve::lang::object */
typedef db_object db_object;

/* ::hyve::lang::int16 */
typedef int16_t db_int16;

/* ::hyve::lang::string */
typedef char* db_string;

/*  ::hyve::lang::parameter */
typedef struct db_parameter db_parameter;

struct db_parameter {
    db_string name;
    db_typedef type;
    db_bool passByReference;
};

DB_SEQUENCE(db_parameterSeq, db_parameter,);

/*  ::hyve::lang::function */
DB_CLASS(db_function);

DB_CLASS_DEF(db_function) {
    db_typedef returnType;
    db_bool returnsReference;
    db_bool overloaded;
    db_uint32 kind;
    db_word impl;
    db_word implData;
    db_object resource;
    db_int16 size;
    db_parameterSeq parameters;
    db_uint32 nextParameterId;
};

DB_SEQUENCE(db_vtable, db_function,);

DB_CLASS_DEF(db_type) {
    DB_EXTEND(db_typedef);
    db_typeKind kind;
    db_bool reference;
    db_bool hasResources;
    db_uint32 templateId;
    db_uint32 size;
    db_uint16 alignment;
    db_typedef defaultType;
    db_typedef parentType;
    db_state parentState;
    db_vtable metaprocedures;
};

/* ::hyve::lang::primitiveKind */
typedef enum db_primitiveKind {
    DB_BINARY = 0,
    DB_BOOLEAN = 1,
    DB_CHARACTER = 2,
    DB_INTEGER = 3,
    DB_UINTEGER = 4,
    DB_FLOAT = 5,
    DB_TEXT = 6,
    DB_ENUM = 7,
    DB_BITMASK = 8,
    DB_ALIAS = 9
} db_primitiveKind;

/* ::hyve::lang::width */
typedef enum db_width {
    DB_WIDTH_8 = 0,
    DB_WIDTH_16 = 1,
    DB_WIDTH_32 = 2,
    DB_WIDTH_64 = 3,
    DB_WIDTH_WORD = 4
} db_width;

/* ::hyve::lang::uint8 */
typedef uint8_t db_uint8;

/*  ::hyve::lang::primitive */
DB_CLASS(db_primitive);

DB_CLASS_DEF(db_primitive) {
    DB_EXTEND(db_type);
    db_primitiveKind kind;
    db_width width;
    db_uint8 convertId;
};

/*  ::hyve::lang::alias */
DB_CLASS(db_alias);

DB_CLASS_DEF(db_alias) {
    DB_EXTEND(db_primitive);
    db_string typeName;
};

/* ::hyve::lang::bool */
typedef char db_bool;

/* ::hyve::lang::any */
typedef db_any db_any;

/* ::hyve::lang::collectionKind */
typedef enum db_collectionKind {
    DB_ARRAY = 0,
    DB_SEQUENCE = 1,
    DB_LIST = 2,
    DB_MAP = 3
} db_collectionKind;

/*  ::hyve::lang::collection */
DB_CLASS(db_collection);

DB_CLASS_DEF(db_collection) {
    DB_EXTEND(db_type);
    db_collectionKind kind;
    db_typedef elementType;
    db_uint32 max;
};

/*  ::hyve::lang::array */
DB_CLASS(db_array);

DB_CLASS_DEF(db_array) {
    DB_EXTEND(db_collection);
    db_typedef elementType;
};

/* ::hyve::lang::attr */
DB_BITMASK(db_attr);
    #define DB_ATTR_SCOPED (0x1)
    #define DB_ATTR_WRITABLE (0x2)
    #define DB_ATTR_OBSERVABLE (0x4)

/*  ::hyve::lang::binary */
DB_CLASS(db_binary);

DB_CLASS_DEF(db_binary) {
    DB_EXTEND(db_primitive);
};

DB_SEQUENCE(db_objectSeq, db_object,);

/*  ::hyve::lang::enum */
DB_CLASS(db_enum);

DB_CLASS_DEF(db_enum) {
    DB_EXTEND(db_primitive);
    db_objectSeq constants;
};

/*  ::hyve::lang::bitmask */
DB_CLASS(db_bitmask);

DB_CLASS_DEF(db_bitmask) {
    DB_EXTEND(db_enum);
};

/*  ::hyve::lang::boolean */
DB_CLASS(db_boolean);

DB_CLASS_DEF(db_boolean) {
    DB_EXTEND(db_primitive);
};

/*  ::hyve::lang::delegate */
DB_CLASS(db_delegate);

DB_CLASS_DEF(db_delegate) {
    DB_EXTEND(db_function);
    db_uint32 id;
};

/*  ::hyve::lang::callback */
DB_CLASS(db_callback);

DB_CLASS_DEF(db_callback) {
    DB_EXTEND(db_function);
    db_delegate delegate;
};

/* ::hyve::lang::char */
typedef char db_char;

/*  ::hyve::lang::character */
DB_CLASS(db_character);

DB_CLASS_DEF(db_character) {
    DB_EXTEND(db_primitive);
};

/* ::hyve::lang::compositeKind */
typedef enum db_compositeKind {
    DB_INTERFACE = 0,
    DB_STRUCT = 1,
    DB_CLASS = 2,
    DB_PROCEDURE = 3
} db_compositeKind;

/* ::hyve::lang::modifier */
DB_BITMASK(db_modifier);
    #define DB_GLOBAL (0x0)
    #define DB_LOCAL (0x1)
    #define DB_PRIVATE (0x2)
    #define DB_READONLY (0x4)
    #define DB_CONST (0x8)

/*  ::hyve::lang::member */
DB_CLASS(db_member);

DB_CLASS_DEF(db_member) {
    db_typedef type;
    db_modifier modifiers;
    db_state state;
    db_bool weak;
    db_uint32 id;
    db_uint32 offset;
};

DB_SEQUENCE(db_memberSeq, db_member,);

/*  ::hyve::lang::interface */
DB_CLASS(db_interface);

DB_CLASS_DEF(db_interface) {
    DB_EXTEND(db_type);
    db_compositeKind kind;
    db_uint32 nextMemberId;
    db_memberSeq members;
    db_vtable methods;
    db_interface base;
};

/*  ::hyve::lang::struct */
DB_CLASS(db_struct);

DB_CLASS_DEF(db_struct) {
    DB_EXTEND(db_interface);
    db_modifier baseAccess;
    db_uint16 delegateCount;
};

DB_SEQUENCE(db_interfaceSeq, db_interface,);

/*  ::hyve::lang::interfaceVector */
typedef struct db_interfaceVector db_interfaceVector;

struct db_interfaceVector {
    db_word interface;
    db_vtable vector;
};

DB_SEQUENCE(db_interfaceVectorSeq, db_interfaceVector,);

/* ::hyve::lang::eventMask */
DB_BITMASK(db_eventMask);
    #define DB_ON_DECLARE (0x1)
    #define DB_ON_DEFINE (0x2)
    #define DB_ON_DESTRUCT (0x4)
    #define DB_ON_INVALIDATE (0x8)
    #define DB_ON_UPDATE (0x10)
    #define DB_ON_SELF (0x20)
    #define DB_ON_SCOPE (0x40)
    #define DB_ON_VALUE (0x80)
    #define DB_ON_METAVALUE (0x100)

/*  ::hyve::lang::dispatcher */
DB_INTERFACE(db_dispatcher);

/*  ::hyve::lang::observer */
DB_CLASS(db_observer);

DB_CLASS_DEF(db_observer) {
    DB_EXTEND(db_function);
    db_object observable;
    db_eventMask mask;
    db_string expression;
    db_uint32 template;
    db_dispatcher dispatcher;
    db_object me;
    db_object observing;
    db_observer delayedBinder;
};

DB_SEQUENCE(db_observerSeq, db_observer,);

/*  ::hyve::lang::class */
DB_CLASS(db_class);

DB_CLASS_DEF(db_class) {
    DB_EXTEND(db_struct);
    db_interfaceSeq implements;
    db_interfaceVectorSeq interfaceVector;
    db_observerSeq observers;
};

/* ::hyve::lang::constant */
typedef int32_t db_constant;

/* ::hyve::lang::equalityKind */
typedef enum db_equalityKind {
    DB_EQ = 0,
    DB_LT = -1,
    DB_GT = 1,
    DB_NEQ = 2
} db_equalityKind;

/*  ::hyve::lang::event */
DB_CLASS(db_event);

DB_CLASS_DEF(db_event) {
    db_uint16 kind;
    db_bool handled;
};

/* ::hyve::lang::float64 */
typedef double db_float64;

/*  ::hyve::lang::float */
DB_CLASS(db_float);

DB_CLASS_DEF(db_float) {
    DB_EXTEND(db_primitive);
    db_float64 min;
    db_float64 max;
};

/* ::hyve::lang::float32 */
typedef float db_float32;

/* ::hyve::lang::int64 */
typedef int64_t db_int64;

/*  ::hyve::lang::int */
DB_CLASS(db_int);

DB_CLASS_DEF(db_int) {
    DB_EXTEND(db_primitive);
    db_int64 min;
    db_int64 max;
};

/* ::hyve::lang::int32 */
typedef int32_t db_int32;

/* ::hyve::lang::int8 */
typedef int8_t db_int8;

/*  ::hyve::lang::list */
DB_CLASS(db_list);

DB_CLASS_DEF(db_list) {
    DB_EXTEND(db_collection);
};

/*  ::hyve::lang::map */
DB_CLASS(db_map);

DB_CLASS_DEF(db_map) {
    DB_EXTEND(db_collection);
    db_typedef elementType;
    db_typedef keyType;
    db_uint32 max;
};

/*  ::hyve::lang::metaprocedure */
DB_CLASS(db_metaprocedure);

DB_CLASS_DEF(db_metaprocedure) {
    DB_EXTEND(db_function);
    db_bool referenceOnly;
};

/*  ::hyve::lang::method */
DB_CLASS(db_method);

DB_CLASS_DEF(db_method) {
    DB_EXTEND(db_function);
    db_bool virtual;
};

/*  ::hyve::lang::observableEvent */
DB_CLASS(db_observableEvent);

DB_CLASS_DEF(db_observableEvent) {
    DB_EXTEND(db_event);
    db_observer observer;
    db_object me;
    db_object source;
    db_object observable;
};

/* ::hyve::lang::octet */
typedef uint8_t db_octet;

/* ::hyve::lang::operatorKind */
typedef enum db_operatorKind {
    DB_ASSIGN = 0,
    DB_ADD = 1,
    DB_SUB = 2,
    DB_MUL = 3,
    DB_DIV = 4,
    DB_MOD = 5,
    DB_INC = 6,
    DB_DEC = 7,
    DB_XOR = 8,
    DB_OR = 9,
    DB_AND = 10,
    DB_NOT = 11,
    DB_ASSIGN_ADD = 12,
    DB_ASSIGN_SUB = 13,
    DB_ASSIGN_MUL = 14,
    DB_ASSIGN_DIV = 15,
    DB_ASSIGN_MOD = 16,
    DB_ASSIGN_XOR = 17,
    DB_ASSIGN_OR = 18,
    DB_ASSIGN_AND = 19,
    DB_COND_OR = 20,
    DB_COND_AND = 21,
    DB_COND_NOT = 22,
    DB_COND_EQ = 23,
    DB_COND_NEQ = 24,
    DB_COND_GT = 25,
    DB_COND_LT = 26,
    DB_COND_GTEQ = 27,
    DB_COND_LTEQ = 28,
    DB_SHIFT_LEFT = 29,
    DB_SHIFT_RIGHT = 30,
    DB_COMMA = 31,
    DB_REF = 32,
    DB_MEMBER_RESOLVE = 33,
    DB_ELEMENT_OPEN = 34,
    DB_ELEMENT_CLOSE = 35,
    DB_BRACKET_OPEN = 36,
    DB_BRACKET_CLOSE = 37
} db_operatorKind;

/* ::hyve::lang::procedureKind */
typedef enum db_procedureKind {
    DB_FUNCTION = 0,
    DB_METHOD = 1,
    DB_DELEGATE = 2,
    DB_CALLBACK = 3,
    DB_OBSERVER = 4,
    DB_METAPROCEDURE = 5
} db_procedureKind;

/*  ::hyve::lang::procedure */
DB_CLASS(db_procedure);

DB_CLASS_DEF(db_procedure) {
    DB_EXTEND(db_struct);
    db_procedureKind kind;
};

/*  ::hyve::lang::sequence */
DB_CLASS(db_sequence);

DB_CLASS_DEF(db_sequence) {
    DB_EXTEND(db_collection);
};

/* ::hyve::lang::uint64 */
typedef uint64_t db_uint64;

/*  ::hyve::lang::text */
DB_CLASS(db_text);

DB_CLASS_DEF(db_text) {
    DB_EXTEND(db_primitive);
    db_width charWidth;
    db_uint64 length;
};

/*  ::hyve::lang::uint */
DB_CLASS(db_uint);

DB_CLASS_DEF(db_uint) {
    DB_EXTEND(db_primitive);
    db_uint64 min;
    db_uint64 max;
};

/*  ::hyve::lang::virtual */
DB_CLASS(db_virtual);

DB_CLASS_DEF(db_virtual) {
    DB_EXTEND(db_method);
};

/* ::hyve::lang::void */
typedef void db_void;

#ifdef __cplusplus
}
#endif
#endif

