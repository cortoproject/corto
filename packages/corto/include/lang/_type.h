/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG__TYPE_H
#define CORTO_LANG__TYPE_H

#include <corto/def.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_typeKind(o) ((corto_typeKind*)corto_assertType((corto_type)corto_typeKind_o, o))
#define corto_bool(o) ((corto_bool*)corto_assertType((corto_type)corto_bool_o, o))
#define corto_attr(o) ((corto_attr*)corto_assertType((corto_type)corto_attr_o, o))
#define corto_state(o) ((corto_state*)corto_assertType((corto_type)corto_state_o, o))
#define corto_typeOptions(o) ((corto_typeOptions*)corto_assertType((corto_type)corto_typeOptions_o, o))
#define corto_uint32(o) ((corto_uint32*)corto_assertType((corto_type)corto_uint32_o, o))
#define corto_uint16(o) ((corto_uint16*)corto_assertType((corto_type)corto_uint16_o, o))
#define corto_object(o) ((corto_object)o)
#define corto_objectseq(o) ((corto_objectseq*)corto_assertType((corto_type)corto_objectseq_o, o))
#define corto_word(o) ((corto_word*)corto_assertType((corto_type)corto_word_o, o))
#define corto_string(o) ((corto_string*)corto_assertType((corto_type)corto_string_o, o))
#define corto_inout(o) ((corto_inout*)corto_assertType((corto_type)corto_inout_o, o))
#define corto_parameter(o) ((corto_parameter*)corto_assertType((corto_type)corto_parameter_o, o))
#define corto_parameterseq(o) ((corto_parameterseq*)corto_assertType((corto_type)corto_parameterseq_o, o))
#define corto_function(o) ((corto_function)corto_assertType((corto_type)corto_function_o, o))
#define corto_delegatedata(o) ((corto_delegatedata*)corto_assertType((corto_type)corto_delegatedata_o, o))
#define corto_initAction(o) ((corto_initAction*)corto_assertType((corto_type)corto_initAction_o, o))
#define corto_nameAction(o) ((corto_nameAction*)corto_assertType((corto_type)corto_nameAction_o, o))
#define corto_type(o) ((corto_type)corto_assertType((corto_type)corto_type_o, o))
#define corto_modifier(o) ((corto_modifier*)corto_assertType((corto_type)corto_modifier_o, o))
#define corto_compositeKind(o) ((corto_compositeKind*)corto_assertType((corto_type)corto_compositeKind_o, o))
#define corto_interface(o) ((corto_interface)corto_assertType((corto_type)corto_interface_o, o))
#define corto_stringseq(o) ((corto_stringseq*)corto_assertType((corto_type)corto_stringseq_o, o))
#define corto_struct(o) ((corto_struct)corto_assertType((corto_type)corto_struct_o, o))
#define corto_interfaceseq(o) ((corto_interfaceseq*)corto_assertType((corto_type)corto_interfaceseq_o, o))
#define corto_interfaceVector(o) ((corto_interfaceVector*)corto_assertType((corto_type)corto_interfaceVector_o, o))
#define corto_interfaceVectorseq(o) ((corto_interfaceVectorseq*)corto_assertType((corto_type)corto_interfaceVectorseq_o, o))
#define corto_destructAction(o) ((corto_destructAction*)corto_assertType((corto_type)corto_destructAction_o, o))
#define corto_class(o) ((corto_class)corto_assertType((corto_type)corto_class_o, o))
#define corto_quantity(o) ((corto_quantity)corto_assertType((corto_type)corto_quantity_o, o))
#define corto_unit(o) ((corto_unit)corto_assertType((corto_type)corto_unit_o, o))
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
#define corto_enum(o) ((corto_enum)corto_assertType((corto_type)corto_enum_o, o))
#define corto_bitmask(o) ((corto_bitmask)corto_assertType((corto_type)corto_bitmask_o, o))
#define corto_boolean(o) ((corto_boolean)corto_assertType((corto_type)corto_boolean_o, o))
#define corto_int32(o) ((corto_int32*)corto_assertType((corto_type)corto_int32_o, o))
#define corto_int32seq(o) ((corto_int32seq*)corto_assertType((corto_type)corto_int32seq_o, o))
#define corto_case(o) ((corto_case)corto_assertType((corto_type)corto_case_o, o))
#define corto_char(o) ((corto_char*)corto_assertType((corto_type)corto_char_o, o))
#define corto_character(o) ((corto_character)corto_assertType((corto_type)corto_character_o, o))
#define corto_constant(o) ((corto_constant*)corto_assertType((corto_type)corto_constant_o, o))
#define corto_container(o) ((corto_container)corto_assertType((corto_type)corto_container_o, o))
#define corto_default(o) ((corto_default)corto_assertType((corto_type)corto_default_o, o))
#define corto_delegate(o) ((corto_delegate)corto_assertType((corto_type)corto_delegate_o, o))
#define corto_equalityKind(o) ((corto_equalityKind*)corto_assertType((corto_type)corto_equalityKind_o, o))
#define corto_float64(o) ((corto_float64*)corto_assertType((corto_type)corto_float64_o, o))
#define corto_float(o) ((corto_float)corto_assertType((corto_type)corto_float_o, o))
#define corto_float32(o) ((corto_float32*)corto_assertType((corto_type)corto_float32_o, o))
#define corto_int64(o) ((corto_int64*)corto_assertType((corto_type)corto_int64_o, o))
#define corto_int(o) ((corto_int)corto_assertType((corto_type)corto_int_o, o))
#define corto_int16(o) ((corto_int16*)corto_assertType((corto_type)corto_int16_o, o))
#define corto_int8(o) ((corto_int8*)corto_assertType((corto_type)corto_int8_o, o))
#define corto_iterator(o) ((corto_iterator)corto_assertType((corto_type)corto_iterator_o, o))
#define corto_leaf(o) ((corto_leaf)corto_assertType((corto_type)corto_leaf_o, o))
#define corto_list(o) ((corto_list)corto_assertType((corto_type)corto_list_o, o))
#define corto_map(o) ((corto_map)corto_assertType((corto_type)corto_map_o, o))
#define corto_metaprocedure(o) ((corto_metaprocedure)corto_assertType((corto_type)corto_metaprocedure_o, o))
#define corto_method(o) ((corto_method)corto_assertType((corto_type)corto_method_o, o))
#define corto_objectlist(o) ((corto_objectlist*)corto_assertType((corto_type)corto_objectlist_o, o))
#define corto_octet(o) ((corto_octet*)corto_assertType((corto_type)corto_octet_o, o))
#define corto_procedureKind(o) ((corto_procedureKind*)corto_assertType((corto_type)corto_procedureKind_o, o))
#define corto_procedure(o) ((corto_procedure)corto_assertType((corto_type)corto_procedure_o, o))
#define corto_sequence(o) ((corto_sequence)corto_assertType((corto_type)corto_sequence_o, o))
#define corto_stringlist(o) ((corto_stringlist*)corto_assertType((corto_type)corto_stringlist_o, o))
#define corto_table(o) ((corto_table)corto_assertType((corto_type)corto_table_o, o))
#define corto_tablescope(o) ((corto_tablescope)corto_assertType((corto_type)corto_tablescope_o, o))
#define corto_target(o) ((corto_target)corto_assertType((corto_type)corto_target_o, o))
#define corto_uint64(o) ((corto_uint64*)corto_assertType((corto_type)corto_uint64_o, o))
#define corto_text(o) ((corto_text)corto_assertType((corto_type)corto_text_o, o))
#define corto_uint(o) ((corto_uint)corto_assertType((corto_type)corto_uint_o, o))
#define corto_union(o) ((corto_union)corto_assertType((corto_type)corto_union_o, o))
#define corto_virtual(o) ((corto_virtual)corto_assertType((corto_type)corto_virtual_o, o))
#define corto_void(o) ((corto_void*)o)
#define corto_wordseq(o) ((corto_wordseq*)corto_assertType((corto_type)corto_wordseq_o, o))

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

/* attr */
CORTO_BITMASK(corto_attr);
    #define CORTO_ATTR_SCOPED (0x1)
    #define CORTO_ATTR_WRITABLE (0x2)
    #define CORTO_ATTR_OBSERVABLE (0x4)
    #define CORTO_ATTR_PERSISTENT (0x8)
    #define CORTO_ATTR_DEFAULT (0x10)

/*  type */
typedef struct corto_type_s *corto_type;

/* state */
CORTO_BITMASK(corto_state);
    #define CORTO_VALID (0x1)
    #define CORTO_DECLARED (0x2)
    #define CORTO_DEFINED (0x4)
    #define CORTO_DESTRUCTED (0x8)

/*  typeOptions */
typedef struct corto_typeOptions corto_typeOptions;

struct corto_typeOptions {
    corto_type parentType;
    corto_state parentState;
    corto_type defaultType;
    corto_type defaultProcedureType;
};

/* uint32 */
typedef uint32_t corto_uint32;

/* uint16 */
typedef uint16_t corto_uint16;

/* object */
typedef void *corto_object;

CORTO_SEQUENCE(corto_objectseq, corto_object,);

/* word */
typedef uintptr_t corto_word;

/* string */
typedef char* corto_string;

/* inout */
typedef enum corto_inout {
    CORTO_IN = 0,
    CORTO_OUT = 1,
    CORTO_INOUT = 2
} corto_inout;

/*  parameter */
typedef struct corto_parameter corto_parameter;

struct corto_parameter {
    corto_string name;
    corto_type type;
    corto_inout inout;
    corto_bool passByReference;
};

CORTO_SEQUENCE(corto_parameterseq, corto_parameter,);

/*  function */
typedef struct corto_function_s *corto_function;

struct corto_function_s {
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

struct corto_type_s {
    corto_typeKind kind;
    corto_bool reference;
    corto_attr attr;
    corto_typeOptions options;
    corto_bool hasResources;
    corto_bool hasTarget;
    corto_uint32 size;
    corto_uint16 alignment;
    corto_objectseq metaprocedures;
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
    #define CORTO_OPTIONAL (0x20)
    #define CORTO_OBSERVABLE (0x40)
    #define CORTO_KEY (0x84)

/* compositeKind */
typedef enum corto_compositeKind {
    CORTO_INTERFACE = 0,
    CORTO_STRUCT = 1,
    CORTO_UNION = 2,
    CORTO_CLASS = 3,
    CORTO_DELEGATE = 4,
    CORTO_PROCEDURE = 5
} corto_compositeKind;

/*  interface */
typedef struct corto_interface_s *corto_interface;

struct corto_interface_s {
    struct corto_type_s _parent;
    corto_compositeKind kind;
    corto_uint32 nextMemberId;
    corto_objectseq members;
    corto_objectseq methods;
    corto_interface base;
};

CORTO_SEQUENCE(corto_stringseq, corto_string,);

/*  struct */
typedef struct corto_struct_s *corto_struct;

struct corto_struct_s {
    struct corto_interface_s _parent;
    corto_modifier baseAccess;
    corto_stringseq keys;
    corto_objectseq keycache;
};

CORTO_SEQUENCE(corto_interfaceseq, corto_interface,);

/*  interfaceVector */
typedef struct corto_interfaceVector corto_interfaceVector;

struct corto_interfaceVector {
    corto_interface interface;
    corto_objectseq vector;
};

CORTO_SEQUENCE(corto_interfaceVectorseq, corto_interfaceVector,);

/*  destructAction */
typedef struct corto_destructAction corto_destructAction;

struct corto_destructAction {
    corto_delegatedata _parent;
};

/*  class */
typedef struct corto_class_s *corto_class;

struct corto_class_s {
    struct corto_struct_s _parent;
    corto_interfaceseq implements;
    corto_interfaceVectorseq interfaceVector;
    corto_initAction construct;
    corto_destructAction destruct;
};

/*  quantity */
typedef struct corto_quantity_s *corto_quantity;

struct corto_quantity_s {
    corto_string description;
};

/*  unit */
typedef struct corto_unit_s *corto_unit;

struct corto_unit_s {
    struct corto_class_s _parent;
    corto_quantity quantity;
    corto_string symbol;
    corto_string conversion;
    corto_type type;
    corto_word toQuantity;
    corto_word fromQuantity;
};

/*  member */
typedef struct corto_member_s *corto_member;

struct corto_member_s {
    corto_type type;
    corto_modifier modifiers;
    corto_unit unit;
    corto_state state;
    corto_string stateCondExpr;
    corto_bool weak;
    corto_uint32 id;
    corto_uint32 offset;
};

/*  alias */
typedef struct corto_alias_s *corto_alias;

struct corto_alias_s {
    struct corto_member_s _parent;
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
typedef struct corto_collection_s *corto_collection;

struct corto_collection_s {
    struct corto_type_s _parent;
    corto_collectionKind kind;
    corto_type elementType;
    corto_uint32 max;
};

/*  array */
typedef struct corto_array_s *corto_array;

struct corto_array_s {
    struct corto_collection_s _parent;
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
typedef struct corto_primitive_s *corto_primitive;

struct corto_primitive_s {
    struct corto_type_s _parent;
    corto_primitiveKind kind;
    corto_width width;
    corto_uint8 convertId;
};

/*  binary */
typedef struct corto_binary_s *corto_binary;

struct corto_binary_s {
    struct corto_primitive_s _parent;
};

/*  enum */
typedef struct corto_enum_s *corto_enum;

struct corto_enum_s {
    struct corto_primitive_s _parent;
    corto_objectseq constants;
};

/*  bitmask */
typedef struct corto_bitmask_s *corto_bitmask;

struct corto_bitmask_s {
    struct corto_enum_s _parent;
};

/*  boolean */
typedef struct corto_boolean_s *corto_boolean;

struct corto_boolean_s {
    struct corto_primitive_s _parent;
};

/* int32 */
typedef int32_t corto_int32;

CORTO_SEQUENCE(corto_int32seq, corto_int32,);

/*  case */
typedef struct corto_case_s *corto_case;

struct corto_case_s {
    struct corto_member_s _parent;
    corto_int32seq discriminator;
};

/* char */
typedef char corto_char;

/*  character */
typedef struct corto_character_s *corto_character;

struct corto_character_s {
    struct corto_primitive_s _parent;
};

/* constant */
typedef int32_t corto_constant;

/*  container */
typedef struct corto_container_s *corto_container;

struct corto_container_s {
    struct corto_class_s _parent;
    corto_type type;
};

/*  default */
typedef struct corto_default_s *corto_default;

struct corto_default_s {
    struct corto_case_s _parent;
};

/*  delegate */
typedef struct corto_delegate_s *corto_delegate;

struct corto_delegate_s {
    struct corto_struct_s _parent;
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
typedef struct corto_float_s *corto_float;

struct corto_float_s {
    struct corto_primitive_s _parent;
    corto_float64 min;
    corto_float64 max;
};

/* float32 */
typedef float corto_float32;

/* int64 */
typedef int64_t corto_int64;

/*  int */
typedef struct corto_int_s *corto_int;

struct corto_int_s {
    struct corto_primitive_s _parent;
    corto_int64 min;
    corto_int64 max;
};

/* int16 */
typedef int16_t corto_int16;

/* int8 */
typedef int8_t corto_int8;

/*  iterator */
typedef struct corto_iterator_s *corto_iterator;

struct corto_iterator_s {
    struct corto_type_s _parent;
    corto_type elementType;
};

/*  leaf */
typedef struct corto_leaf_s *corto_leaf;

struct corto_leaf_s {
    struct corto_container_s _parent;
};

/*  list */
typedef struct corto_list_s *corto_list;

struct corto_list_s {
    struct corto_collection_s _parent;
};

/*  map */
typedef struct corto_map_s *corto_map;

struct corto_map_s {
    struct corto_collection_s _parent;
    corto_type elementType;
    corto_type keyType;
    corto_uint32 max;
};

/*  metaprocedure */
typedef struct corto_metaprocedure_s *corto_metaprocedure;

struct corto_metaprocedure_s {
    struct corto_function_s _parent;
    corto_bool referenceOnly;
};

/*  method */
typedef struct corto_method_s *corto_method;

struct corto_method_s {
    struct corto_function_s _parent;
    corto_bool _virtual;
};

CORTO_LIST(corto_objectlist);

/* octet */
typedef uint8_t corto_octet;

/* procedureKind */
typedef enum corto_procedureKind {
    CORTO_FUNCTION = 0,
    CORTO_METHOD = 1,
    CORTO_OBSERVER = 2,
    CORTO_METAPROCEDURE = 3
} corto_procedureKind;

/*  procedure */
typedef struct corto_procedure_s *corto_procedure;

struct corto_procedure_s {
    struct corto_class_s _parent;
    corto_procedureKind kind;
    corto_bool hasThis;
    corto_type thisType;
};

/*  sequence */
typedef struct corto_sequence_s *corto_sequence;

struct corto_sequence_s {
    struct corto_collection_s _parent;
};

CORTO_LIST(corto_stringlist);

/*  table */
typedef struct corto_table_s *corto_table;

struct corto_table_s {
    struct corto_container_s _parent;
};

/*  tablescope */
typedef struct corto_tablescope_s *corto_tablescope;

struct corto_tablescope_s {
    corto_struct type;
};

/*  target */
typedef struct corto_target_s *corto_target;

struct corto_target_s {
    struct corto_struct_s _parent;
    corto_type type;
};

/* uint64 */
typedef uint64_t corto_uint64;

/*  text */
typedef struct corto_text_s *corto_text;

struct corto_text_s {
    struct corto_primitive_s _parent;
    corto_width charWidth;
    corto_uint64 length;
};

/*  uint */
typedef struct corto_uint_s *corto_uint;

struct corto_uint_s {
    struct corto_primitive_s _parent;
    corto_uint64 min;
    corto_uint64 max;
};

/*  union */
typedef struct corto_union_s *corto_union;

struct corto_union_s {
    struct corto_interface_s _parent;
    corto_type discriminator;
};

/*  virtual */
typedef struct corto_virtual_s *corto_virtual;

struct corto_virtual_s {
    struct corto_method_s _parent;
};

/* void */
typedef void corto_void;

CORTO_SEQUENCE(corto_wordseq, corto_word,);

#ifdef __cplusplus
}
#endif
#endif

