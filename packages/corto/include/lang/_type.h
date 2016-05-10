/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG__TYPE_H
#define CORTO_LANG__TYPE_H

#include "corto/def.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_typeKind(o) ((corto_typeKind*)corto_assertType((corto_type)corto_typeKind_o, o))
#define corto_bool(o) ((corto_bool*)corto_assertType((corto_type)corto_bool_o, o))
#define corto_uint32(o) ((corto_uint32*)corto_assertType((corto_type)corto_uint32_o, o))
#define corto_uint16(o) ((corto_uint16*)corto_assertType((corto_type)corto_uint16_o, o))
#define corto_state(o) ((corto_state*)corto_assertType((corto_type)corto_state_o, o))
#define corto_word(o) ((corto_word*)corto_assertType((corto_type)corto_word_o, o))
#define corto_object(o) ((corto_object)o)
#define corto_string(o) ((corto_string*)corto_assertType((corto_type)corto_string_o, o))
#define corto_parameter(o) ((corto_parameter*)corto_assertType((corto_type)corto_parameter_o, o))
#define corto_parameterseq(o) ((corto_parameterseq*)corto_assertType((corto_type)corto_parameterseq_o, o))
#define corto_function(o) ((corto_function)corto_assertType((corto_type)corto_function_o, o))
#define corto_vtable(o) ((corto_vtable*)corto_assertType((corto_type)corto_vtable_o, o))
#define corto_delegatedata(o) ((corto_delegatedata*)corto_assertType((corto_type)corto_delegatedata_o, o))
#define corto_initAction(o) ((corto_initAction*)corto_assertType((corto_type)corto_initAction_o, o))
#define corto_nameAction(o) ((corto_nameAction*)corto_assertType((corto_type)corto_nameAction_o, o))
#define corto_type(o) ((corto_type)corto_assertType((corto_type)corto_type_o, o))
#define corto_modifier(o) ((corto_modifier*)corto_assertType((corto_type)corto_modifier_o, o))
#define corto_member(o) ((corto_member)corto_assertType((corto_type)corto_member_o, o))
#define corto_alias(o) ((corto_alias)corto_assertType((corto_type)corto_alias_o, o))
#define corto_any(o) ((corto_any*)corto_assertType((corto_type)corto_any_o, o))
#define corto_collectionKind(o) ((corto_collectionKind*)corto_assertType((corto_type)corto_collectionKind_o, o))
#define corto_collection(o) ((corto_collection)corto_assertType((corto_type)corto_collection_o, o))
#define corto_array(o) ((corto_array)corto_assertType((corto_type)corto_array_o, o))
#define corto_primitiveKind(o) ((corto_primitiveKind*)corto_assertType((corto_type)corto_primitiveKind_o, o))
#define corto_width(o) ((corto_width*)corto_assertType((corto_type)corto_width_o, o))
#define corto_uint8(o) ((corto_uint8*)corto_assertType((corto_type)corto_uint8_o, o))
#define corto_primitive(o) ((corto_primitive)corto_assertType((corto_type)corto_primitive_o, o))
#define corto_binary(o) ((corto_binary)corto_assertType((corto_type)corto_binary_o, o))
#define corto_objectseq(o) ((corto_objectseq*)corto_assertType((corto_type)corto_objectseq_o, o))
#define corto_enum(o) ((corto_enum)corto_assertType((corto_type)corto_enum_o, o))
#define corto_bitmask(o) ((corto_bitmask)corto_assertType((corto_type)corto_bitmask_o, o))
#define corto_boolean(o) ((corto_boolean)corto_assertType((corto_type)corto_boolean_o, o))
#define corto_char(o) ((corto_char*)corto_assertType((corto_type)corto_char_o, o))
#define corto_character(o) ((corto_character)corto_assertType((corto_type)corto_character_o, o))
#define corto_compositeKind(o) ((corto_compositeKind*)corto_assertType((corto_type)corto_compositeKind_o, o))
#define corto_memberseq(o) ((corto_memberseq*)corto_assertType((corto_type)corto_memberseq_o, o))
#define corto_interface(o) ((corto_interface)corto_assertType((corto_type)corto_interface_o, o))
#define corto_struct(o) ((corto_struct)corto_assertType((corto_type)corto_struct_o, o))
#define corto_interfaceseq(o) ((corto_interfaceseq*)corto_assertType((corto_type)corto_interfaceseq_o, o))
#define corto_interfaceVector(o) ((corto_interfaceVector*)corto_assertType((corto_type)corto_interfaceVector_o, o))
#define corto_interfaceVectorseq(o) ((corto_interfaceVectorseq*)corto_assertType((corto_type)corto_interfaceVectorseq_o, o))
#define corto_destructAction(o) ((corto_destructAction*)corto_assertType((corto_type)corto_destructAction_o, o))
#define corto_class(o) ((corto_class)corto_assertType((corto_type)corto_class_o, o))
#define corto_constant(o) ((corto_constant*)corto_assertType((corto_type)corto_constant_o, o))
#define corto_delegate(o) ((corto_delegate)corto_assertType((corto_type)corto_delegate_o, o))
#define corto_equalityKind(o) ((corto_equalityKind*)corto_assertType((corto_type)corto_equalityKind_o, o))
#define corto_float64(o) ((corto_float64*)corto_assertType((corto_type)corto_float64_o, o))
#define corto_float(o) ((corto_float)corto_assertType((corto_type)corto_float_o, o))
#define corto_float32(o) ((corto_float32*)corto_assertType((corto_type)corto_float32_o, o))
#define corto_int64(o) ((corto_int64*)corto_assertType((corto_type)corto_int64_o, o))
#define corto_int(o) ((corto_int)corto_assertType((corto_type)corto_int_o, o))
#define corto_int16(o) ((corto_int16*)corto_assertType((corto_type)corto_int16_o, o))
#define corto_int32(o) ((corto_int32*)corto_assertType((corto_type)corto_int32_o, o))
#define corto_int8(o) ((corto_int8*)corto_assertType((corto_type)corto_int8_o, o))
#define corto_iterator(o) ((corto_iterator)corto_assertType((corto_type)corto_iterator_o, o))
#define corto_list(o) ((corto_list)corto_assertType((corto_type)corto_list_o, o))
#define corto_map(o) ((corto_map)corto_assertType((corto_type)corto_map_o, o))
#define corto_metaprocedure(o) ((corto_metaprocedure)corto_assertType((corto_type)corto_metaprocedure_o, o))
#define corto_method(o) ((corto_method)corto_assertType((corto_type)corto_method_o, o))
#define corto_octet(o) ((corto_octet*)corto_assertType((corto_type)corto_octet_o, o))
#define corto_octetseq(o) ((corto_octetseq*)corto_assertType((corto_type)corto_octetseq_o, o))
#define corto_procedureKind(o) ((corto_procedureKind*)corto_assertType((corto_type)corto_procedureKind_o, o))
#define corto_procedure(o) ((corto_procedure)corto_assertType((corto_type)corto_procedure_o, o))
#define corto_sequence(o) ((corto_sequence)corto_assertType((corto_type)corto_sequence_o, o))
#define corto_uint64(o) ((corto_uint64*)corto_assertType((corto_type)corto_uint64_o, o))
#define corto_text(o) ((corto_text)corto_assertType((corto_type)corto_text_o, o))
#define corto_uint(o) ((corto_uint)corto_assertType((corto_type)corto_uint_o, o))
#define corto_virtual(o) ((corto_virtual)corto_assertType((corto_type)corto_virtual_o, o))
#define corto_void(o) ((corto_void*)o)

/* Type definitions */
/* typeKind */
typedef enum corto_typeKind {
    CORTO_VOID = 0,
    CORTO_ANY = 1,
    CORTO_PRIMITIVE = 2,
    CORTO_COMPOSITE = 3,
    CORTO_COLLECTION = 4,
    CORTO_ITERATOR = 5
} corto_typeKind;

/* bool */
typedef char corto_bool;

/* uint32 */
typedef uint32_t corto_uint32;

/* uint16 */
typedef uint16_t corto_uint16;

/*  type */
CORTO_CLASS(corto_type);

/* state */
CORTO_BITMASK(corto_state);
    #define CORTO_VALID (0x1)
    #define CORTO_DECLARED (0x2)
    #define CORTO_DEFINED (0x4)
    #define CORTO_DESTRUCTED (0x8)

/* word */
typedef uintptr_t corto_word;

/* object */
typedef void *corto_object;

/* string */
typedef char* corto_string;

/*  parameter */
typedef struct corto_parameter corto_parameter;

struct corto_parameter {
    corto_string name;
    corto_type type;
    corto_bool passByReference;
};

CORTO_SEQUENCE(corto_parameterseq, corto_parameter,);

/*  function */
CORTO_CLASS(corto_function);

CORTO_CLASS_DEF(corto_function) {
    corto_type returnType;
    corto_bool returnsReference;
    corto_bool overloaded;
    corto_uint32 kind;
    corto_word impl;
    corto_word fptr;
    corto_word fdata;
    corto_object resource;
    corto_uint16 size;
    corto_parameterseq parameters;
    corto_uint32 nextParameterId;
};

CORTO_SEQUENCE(corto_vtable, corto_function,);

/*  delegatedata */
typedef struct corto_delegatedata corto_delegatedata;

struct corto_delegatedata {
    corto_object instance;
    corto_function procedure;
};

/*  initAction */
typedef struct corto_initAction corto_initAction;

struct corto_initAction {
    corto_delegatedata _parent;
};

/*  nameAction */
typedef struct corto_nameAction corto_nameAction;

struct corto_nameAction {
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
    corto_nameAction nameof;
};

/* modifier */
CORTO_BITMASK(corto_modifier);
    #define CORTO_GLOBAL (0x0)
    #define CORTO_LOCAL (0x1)
    #define CORTO_PRIVATE (0x2)
    #define CORTO_READONLY (0x4)
    #define CORTO_CONST (0x8)
    #define CORTO_HIDDEN (0x10)

/*  member */
CORTO_CLASS(corto_member);

CORTO_CLASS_DEF(corto_member) {
    corto_type type;
    corto_modifier modifiers;
    corto_state state;
    corto_bool weak;
    corto_uint32 id;
    corto_uint32 offset;
};

/*  alias */
CORTO_CLASS(corto_alias);

CORTO_CLASS_DEF(corto_alias) {
    CORTO_EXTEND(corto_member);
    corto_member member;
};

/* any */
CORTO_ANY(corto_any);

/* collectionKind */
typedef enum corto_collectionKind {
    CORTO_ARRAY = 0,
    CORTO_SEQUENCE = 1,
    CORTO_LIST = 2,
    CORTO_MAP = 3
} corto_collectionKind;

/*  collection */
CORTO_CLASS(corto_collection);

CORTO_CLASS_DEF(corto_collection) {
    CORTO_EXTEND(corto_type);
    corto_collectionKind kind;
    corto_type elementType;
    corto_uint32 max;
};

/*  array */
CORTO_CLASS(corto_array);

CORTO_CLASS_DEF(corto_array) {
    CORTO_EXTEND(corto_collection);
    corto_type elementType;
};

/* primitiveKind */
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

/* width */
typedef enum corto_width {
    CORTO_WIDTH_8 = 0,
    CORTO_WIDTH_16 = 1,
    CORTO_WIDTH_32 = 2,
    CORTO_WIDTH_64 = 3,
    CORTO_WIDTH_WORD = 4
} corto_width;

/* uint8 */
typedef uint8_t corto_uint8;

/*  primitive */
CORTO_CLASS(corto_primitive);

CORTO_CLASS_DEF(corto_primitive) {
    CORTO_EXTEND(corto_type);
    corto_primitiveKind kind;
    corto_width width;
    corto_uint8 convertId;
};

/*  binary */
CORTO_CLASS(corto_binary);

CORTO_CLASS_DEF(corto_binary) {
    CORTO_EXTEND(corto_primitive);
};

CORTO_SEQUENCE(corto_objectseq, corto_object,);

/*  enum */
CORTO_CLASS(corto_enum);

CORTO_CLASS_DEF(corto_enum) {
    CORTO_EXTEND(corto_primitive);
    corto_objectseq constants;
};

/*  bitmask */
CORTO_CLASS(corto_bitmask);

CORTO_CLASS_DEF(corto_bitmask) {
    CORTO_EXTEND(corto_enum);
};

/*  boolean */
CORTO_CLASS(corto_boolean);

CORTO_CLASS_DEF(corto_boolean) {
    CORTO_EXTEND(corto_primitive);
};

/* char */
typedef char corto_char;

/*  character */
CORTO_CLASS(corto_character);

CORTO_CLASS_DEF(corto_character) {
    CORTO_EXTEND(corto_primitive);
};

/* compositeKind */
typedef enum corto_compositeKind {
    CORTO_INTERFACE = 0,
    CORTO_STRUCT = 1,
    CORTO_CLASS = 2,
    CORTO_DELEGATE = 3,
    CORTO_PROCEDURE = 4
} corto_compositeKind;

CORTO_SEQUENCE(corto_memberseq, corto_member,);

/*  interface */
CORTO_CLASS(corto_interface);

CORTO_CLASS_DEF(corto_interface) {
    CORTO_EXTEND(corto_type);
    corto_compositeKind kind;
    corto_uint32 nextMemberId;
    corto_memberseq members;
    corto_vtable methods;
    corto_interface base;
};

/*  struct */
CORTO_CLASS(corto_struct);

CORTO_CLASS_DEF(corto_struct) {
    CORTO_EXTEND(corto_interface);
    corto_modifier baseAccess;
};

CORTO_SEQUENCE(corto_interfaceseq, corto_interface,);

/*  interfaceVector */
typedef struct corto_interfaceVector corto_interfaceVector;

struct corto_interfaceVector {
    corto_interface interface;
    corto_vtable vector;
};

CORTO_SEQUENCE(corto_interfaceVectorseq, corto_interfaceVector,);

/*  destructAction */
typedef struct corto_destructAction corto_destructAction;

struct corto_destructAction {
    corto_delegatedata _parent;
};

/*  class */
CORTO_CLASS(corto_class);

CORTO_CLASS_DEF(corto_class) {
    CORTO_EXTEND(corto_struct);
    corto_interfaceseq implements;
    corto_interfaceVectorseq interfaceVector;
    corto_initAction construct;
    corto_destructAction destruct;
};

/* constant */
typedef int32_t corto_constant;

/*  delegate */
CORTO_CLASS(corto_delegate);

CORTO_CLASS_DEF(corto_delegate) {
    CORTO_EXTEND(corto_struct);
    corto_type returnType;
    corto_bool returnsReference;
    corto_parameterseq parameters;
};

/* equalityKind */
typedef enum corto_equalityKind {
    CORTO_EQ = 0,
    CORTO_LT = -1,
    CORTO_GT = 1,
    CORTO_NEQ = 2
} corto_equalityKind;

/* float64 */
typedef double corto_float64;

/*  float */
CORTO_CLASS(corto_float);

CORTO_CLASS_DEF(corto_float) {
    CORTO_EXTEND(corto_primitive);
    corto_float64 min;
    corto_float64 max;
};

/* float32 */
typedef float corto_float32;

/* int64 */
typedef int64_t corto_int64;

/*  int */
CORTO_CLASS(corto_int);

CORTO_CLASS_DEF(corto_int) {
    CORTO_EXTEND(corto_primitive);
    corto_int64 min;
    corto_int64 max;
};

/* int16 */
typedef int16_t corto_int16;

/* int32 */
typedef int32_t corto_int32;

/* int8 */
typedef int8_t corto_int8;

/*  iterator */
CORTO_CLASS(corto_iterator);

CORTO_CLASS_DEF(corto_iterator) {
    CORTO_EXTEND(corto_type);
    corto_type elementType;
};

/*  list */
CORTO_CLASS(corto_list);

CORTO_CLASS_DEF(corto_list) {
    CORTO_EXTEND(corto_collection);
};

/*  map */
CORTO_CLASS(corto_map);

CORTO_CLASS_DEF(corto_map) {
    CORTO_EXTEND(corto_collection);
    corto_type elementType;
    corto_type keyType;
    corto_uint32 max;
};

/*  metaprocedure */
CORTO_CLASS(corto_metaprocedure);

CORTO_CLASS_DEF(corto_metaprocedure) {
    CORTO_EXTEND(corto_function);
    corto_bool referenceOnly;
};

/*  method */
CORTO_CLASS(corto_method);

CORTO_CLASS_DEF(corto_method) {
    CORTO_EXTEND(corto_function);
    corto_bool _virtual;
};

/* octet */
typedef uint8_t corto_octet;

CORTO_SEQUENCE(corto_octetseq, corto_octet,);

/* procedureKind */
typedef enum corto_procedureKind {
    CORTO_FUNCTION = 0,
    CORTO_METHOD = 1,
    CORTO_OBSERVER = 2,
    CORTO_METAPROCEDURE = 3
} corto_procedureKind;

/*  procedure */
CORTO_CLASS(corto_procedure);

CORTO_CLASS_DEF(corto_procedure) {
    CORTO_EXTEND(corto_struct);
    corto_procedureKind kind;
    corto_initAction bind;
};

/*  sequence */
CORTO_CLASS(corto_sequence);

CORTO_CLASS_DEF(corto_sequence) {
    CORTO_EXTEND(corto_collection);
};

/* uint64 */
typedef uint64_t corto_uint64;

/*  text */
CORTO_CLASS(corto_text);

CORTO_CLASS_DEF(corto_text) {
    CORTO_EXTEND(corto_primitive);
    corto_width charWidth;
    corto_uint64 length;
};

/*  uint */
CORTO_CLASS(corto_uint);

CORTO_CLASS_DEF(corto_uint) {
    CORTO_EXTEND(corto_primitive);
    corto_uint64 min;
    corto_uint64 max;
};

/*  virtual */
CORTO_CLASS(corto_virtual);

CORTO_CLASS_DEF(corto_virtual) {
    CORTO_EXTEND(corto_method);
};

/* void */
typedef void corto_void;

#ifdef __cplusplus
}
#endif
#endif
