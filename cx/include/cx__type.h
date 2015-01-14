/*
 * cx.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CX_H_
#define CX_H_

#include "cx_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Primitive declarations */
typedef char cx_octet;
typedef char cx_bool;
typedef char cx_char;
typedef uint8_t cx_uint8;
typedef uint16_t cx_uint16;
typedef uint32_t cx_uint32;
typedef uint64_t cx_uint64;
typedef int8_t cx_int8;
typedef int16_t cx_int16;
typedef int32_t cx_int32;
typedef int64_t cx_int64;
typedef float cx_float32;
typedef double cx_float64;
typedef char* cx_string;
typedef cx_int32 cx_constant;
typedef uintptr_t cx_word;

/* Class declarations */
CX_CLASS(cx_typedef);
CX_CLASS(cx_type);
CX_CLASS(cx_template);
CX_CLASS(cx_primitive);
CX_CLASS(cx_interface);
CX_CLASS(cx_collection);
CX_CLASS(cx_binary);
CX_CLASS(cx_boolean);
CX_CLASS(cx_character);
CX_CLASS(cx_int);
CX_CLASS(cx_uint);
CX_CLASS(cx_float);
CX_CLASS(cx_text);
CX_CLASS(cx_enum);
CX_CLASS(cx_bitmask);
CX_CLASS(cx_alias);
CX_CLASS(cx_struct);
CX_CLASS(cx_class);
CX_CLASS(cx_delegate);
CX_CLASS(cx_procedure);
CX_CLASS(cx_array);
CX_CLASS(cx_sequence);
CX_CLASS(cx_list);
CX_CLASS(cx_map);
CX_CLASS(cx_virtual);
CX_CLASS(cx_member);
CX_CLASS(cx_event);
CX_CLASS(cx_observableEvent);

CX_INTERFACE(cx_dispatcher);

CX_STRUCT(cx_parameter);
CX_STRUCT(cx_delegatedata);
CX_STRUCT(cx_interfaceVector);
CX_STRUCT(cx_callbackInit);
CX_STRUCT(cx_callbackDestruct);

CX_PROCEDURE(cx_function);
CX_PROCEDURE(cx_method);
CX_PROCEDURE(cx_observer);
CX_PROCEDURE(cx_metaprocedure);

/* any */
CX_ANY(cx_any);

/* Class convenience macro's */
#define cx_typedef(t) ((cx_typedef)t)
#define cx_type(t) ((cx_type)t)
#define cx_template(t) ((cx_template)t)
#define cx_primitive(t) ((cx_primitive)t)
#define cx_interface(t) ((cx_interface)t)
#define cx_collection(t) ((cx_collection)t)
#define cx_procedure(t) ((cx_procedure)t)
#define cx_int(t) ((cx_int)t)
#define cx_uint(t) ((cx_uint)t)
#define cx_float(t) ((cx_float)t)
#define cx_text(t) ((cx_text)t)
#define cx_enum(t) ((cx_enum)t)
#define cx_bitmask(t) ((cx_bitmask)t)
#define cx_alias(t) ((cx_alias)t)
#define cx_struct(t) ((cx_struct)t)
#define cx_class(t) ((cx_class)t)
#define cx_delegate(t) ((cx_delegate)t)
#define cx_array(t) ((cx_array)t)
#define cx_sequence(t) ((cx_sequence)t)
#define cx_list(t) ((cx_list)t)
#define cx_map(t) ((cx_map)t)
#define cx_member(t) ((cx_member)t)
#define cx_reference(t) ((cx_reference)t)
#define cx_event(t) ((cx_event)t)
#define cx_observableEvent(t) ((cx_observableEvent)t)

#define cx_function(t) ((cx_function)t)
#define cx_method(t) ((cx_method)t)
#define cx_virtual(t) ((cx_virtual)t)
#define cx_observer(t) ((cx_observer)t)
#define cx_metaprocedure(t) ((cx_metaprocedure)t)

/* Void object */
typedef void cx_void;

/* Object */
typedef void* cx_object;

/* Enumeration declarations */
typedef enum cx_width {
    CX_WIDTH_8,
    CX_WIDTH_16,
    CX_WIDTH_32,
    CX_WIDTH_64,
    CX_WIDTH_WORD
}cx_width;

typedef enum cx_typeKind {
    CX_VOID,
    CX_ANY,
    CX_PRIMITIVE,
    CX_COMPOSITE,
    CX_COLLECTION
}cx_typeKind;

typedef enum cx_primitiveKind {
    CX_BINARY,
    CX_BOOLEAN,
    CX_CHARACTER,
    CX_INTEGER,
    CX_UINTEGER,
    CX_FLOAT,
    CX_TEXT,
    CX_ENUM,
    CX_BITMASK,
    CX_ALIAS
}cx_primitiveKind;

typedef enum cx_compositeKind {
    CX_INTERFACE,
    CX_STRUCT,
    CX_CLASS,
    CX_DELEGATE,
    CX_PROCEDURE,
}cx_compositeKind;

typedef enum cx_collectionKind {
    CX_ARRAY,
    CX_SEQUENCE,
    CX_LIST,
    CX_MAP
}cx_collectionKind;

typedef enum cx_procedureKind {
    CX_FUNCTION,
    CX_METHOD,
    CX_OBSERVER,
    CX_METAPROCEDURE
}cx_procedureKind;

typedef enum cx_equalityKind {
    CX_EQ = 0,
    CX_LT = -1,
    CX_GT = 1,
    CX_NEQ = 2
}cx_equalityKind;

typedef enum cx_operatorKind {
    CX_ASSIGN,
    CX_ADD,
    CX_SUB,
    CX_MUL,
    CX_DIV,
    CX_MOD,
    CX_INC,
    CX_DEC,
    CX_XOR,
    CX_OR,
    CX_AND,
    CX_NOT,
    CX_ASSIGN_ADD,
    CX_ASSIGN_SUB,
    CX_ASSIGN_MUL,
    CX_ASSIGN_DIV,
    CX_ASSIGN_MOD,
    CX_ASSIGN_XOR,
    CX_ASSIGN_OR,
    CX_ASSIGN_AND,
    CX_COND_OR,
    CX_COND_AND,
    CX_COND_NOT,
    CX_COND_EQ,
    CX_COND_NEQ,
    CX_COND_GT,
    CX_COND_LT,
    CX_COND_GTEQ,
    CX_COND_LTEQ,
    CX_SHIFT_LEFT,
    CX_SHIFT_RIGHT,
    CX_COMMA,
    CX_REF,
    CX_MEMBER_RESOLVE,
    CX_ELEMENT_OPEN,
    CX_ELEMENT_CLOSE,
    CX_BRACKET_OPEN,
    CX_BRACKET_CLOSE /* Must be last */
} cx_operatorKind;

CX_BITMASK(cx_state);
    /* defined in cx_object.h */
CX_BITMASK(cx_attr);
    /* defined in cx_object.h */
CX_BITMASK(cx_eventMask);
    /* defined in cx_object.h */

CX_BITMASK(cx_modifier);
    #define CX_GLOBAL      (0) /* Member is global and public (no restrictions) */
    #define CX_LOCAL      (1) /* Member has local validity */
    #define CX_PRIVATE    (2) /* Member is not exposed for extern entities */
    #define CX_READONLY   (4) /* Member access is restricted to reading only */
    #define CX_CONST      (8) /* Member assignment is restricted to DECLARED objects only */

/* Function types */
typedef cx_equalityKind (*cx_equalsAction)(cx_type _this, const void* o1, const void* o2);

/* Collections */
CX_SEQUENCE(cx_objectSeq, cx_object,);
CX_SEQUENCE(cx_interfaceSeq, cx_interface,);
CX_SEQUENCE(cx_memberSeq, cx_member,);
CX_SEQUENCE(cx_parameterSeq, cx_parameter,);
CX_SEQUENCE(cx_observerSeq, cx_observer,);
CX_SEQUENCE(cx_vtable, cx_function,);
CX_SEQUENCE(cx_interfaceVectorSeq, cx_interfaceVector,);

typedef cx_rbtree cx_scope;

/* parameter */
CX_STRUCT_DEF(cx_parameter) {
    cx_string name;
    cx_typedef type;
    cx_bool passByReference;
};

/* delegatedata */
CX_STRUCT_DEF(cx_delegatedata) {
    cx_object instance;
    cx_function procedure;
};

/* callbackInit */
CX_STRUCT_DEF(cx_callbackInit) {
    cx_delegatedata _parent;
};

/* callbackDestruct */
CX_STRUCT_DEF(cx_callbackDestruct) {
    cx_delegatedata _parent;
};

/* function */
CX_PROCEDURE_DEF(cx_function) {
    cx_typedef returnType;
    cx_bool returnsReference;
    cx_bool overloaded;
    cx_uint32 kind;
    cx_word impl;       /* The language-binding specific call that is executed upon calling this function. */
    cx_word implData;   /* Userdata for the language binding (usually a pointer to the function implemntation) */
    cx_object resource;
    cx_uint16 size;
    cx_parameterSeq parameters;
    cx_uint32 nextParameterId;
};

/* method */
CX_PROCEDURE_DEF(cx_method) {
    CX_EXTEND(cx_function);
    cx_bool virtual;
};

/* virtual */
CX_PROCEDURE_DEF(cx_virtual) {
    CX_EXTEND(cx_method);
};

CX_PROCEDURE_DEF(cx_metaprocedure) {
    CX_EXTEND(cx_function);
    cx_bool referenceOnly;
};

/* observer */
CX_PROCEDURE_DEF(cx_observer) {
    CX_EXTEND(cx_function);
    cx_object observable;       /* The object being observed */
    cx_uint32 mask;             /* The interest mask */
    cx_string expression;       /* Expression (must either resolve to an object or boolean) */
    cx_uint32 template;         /* If nonzero, this observer is a class-template which is instantiated for all class-instances */
    cx_dispatcher dispatcher;   /* If set, events for this observer are send through this dispatcher */
    cx_object me;               /* Set to 'this' if observer is an instantiated class observer. Prevents loopback of events. */
    cx_object observing;
    cx_observer delayedBinder;
};

/* ::cortex::lang::typedef */
CX_CLASS_DEF(cx_typedef) {
    cx_typedef type;
    cx_type real;
};

/* ::cortex::lang::type */
CX_CLASS_DEF(cx_type) {
    CX_EXTEND(cx_typedef);
    cx_typeKind kind;           /* Is type a void, any, primitive, composite or collection */
    cx_bool reference;          /* Is type a reference-type (meaning that an instance is always an object) */
    cx_bool hasResources;       /* Optimization: does the type have allocated resources */
    cx_uint32 templateId;       /* Optimization: enables quick lookups for type conversions */
    cx_uint32 size;             /* The allocated size of a type */
    cx_uint16 alignment;        /* The alignment of a type */
    cx_typedef defaultType;     /* The default type for objects that are declared in scope of instances of this type */
    cx_typedef parentType;      /* The mandatory parentType (if not set parentType can be anything) */
    cx_state parentState;       /* The mandatory parentState */
    cx_vtable metaprocedures;   /* Metaprocedures of type */
    cx_callbackInit init;       /* Init delegate */
};

/* ::cortex::lang::template */
CX_CLASS_DEF(cx_template) {
    CX_EXTEND(cx_type);
};

/* ::cortex::lang::primitive */
CX_CLASS_DEF(cx_primitive) {
    CX_EXTEND(cx_type);
    cx_primitiveKind kind;
    cx_width width;
    cx_uint8 convertId;
};

/* ::cortex::lang::interface */
CX_CLASS_DEF(cx_interface) {
    CX_EXTEND(cx_type);
    cx_compositeKind kind;
    cx_uint32 nextMemberId;
    cx_memberSeq members;
    cx_vtable methods;
    cx_interface base;
};

/* ::cortex::lang::collection */
CX_CLASS_DEF(cx_collection) {
    CX_EXTEND(cx_type);
    cx_collectionKind kind;
    cx_typedef elementType;
    cx_uint32 max;
};

/* ::cortex::lang::binary */
CX_CLASS_DEF(cx_binary) {
    CX_EXTEND(cx_primitive);
};

/* ::cortex::lang::boolean */
CX_CLASS_DEF(cx_boolean) {
    CX_EXTEND(cx_primitive);
};

/* ::cortex::lang::character */
CX_CLASS_DEF(cx_character) {
    CX_EXTEND(cx_primitive);
};

/* ::cortex::lang::int */
CX_CLASS_DEF(cx_int) {
    CX_EXTEND(cx_primitive);
    cx_int64 min;
    cx_int64 max;
};

/* ::cortex::lang::uint */
CX_CLASS_DEF(cx_uint) {
    CX_EXTEND(cx_primitive);
    cx_uint64 min;
    cx_uint64 max;
};

/* ::cortex::lang::float */
CX_CLASS_DEF(cx_float) {
    CX_EXTEND(cx_primitive);
    cx_float64 min;
    cx_float64 max;
};

/* ::cortex::lang::text */
CX_CLASS_DEF(cx_text) {
    CX_EXTEND(cx_primitive);
    cx_width charWidth;
    cx_uint64 length;
};

/* ::cortex::lang::enum */
CX_CLASS_DEF(cx_enum) {
    CX_EXTEND(cx_primitive);
    cx_objectSeq constants;
};

/* ::cortex::lang::bitmask */
CX_CLASS_DEF(cx_bitmask) {
    CX_EXTEND(cx_enum);
};

/* ::cortex::lang::alias */
CX_CLASS_DEF(cx_alias) {
    CX_EXTEND(cx_primitive);
    cx_string typeName;
};

/* ::cortex::lang::struct */
CX_CLASS_DEF(cx_struct) {
    CX_EXTEND(cx_interface);
    cx_modifier baseAccess;
};

CX_STRUCT_DEF(cx_interfaceVector) {
    cx_interface interface;
    cx_vtable vector;
};

/* ::cortex::lang::class */
CX_CLASS_DEF(cx_class) {
    CX_EXTEND(cx_struct);
    cx_interfaceSeq implements;
    cx_interfaceVectorSeq interfaceVector;
    cx_observerSeq observers;
    cx_callbackInit construct;
    cx_callbackDestruct destruct;
};

/* ::cortex::lang::delegate */
CX_CLASS_DEF(cx_delegate) {
    CX_EXTEND(cx_struct);
    cx_typedef returnType;
    cx_bool returnsReference;
    cx_parameterSeq parameters;
};

/* ::cortex::lang::procedure */
CX_CLASS_DEF(cx_procedure) {
    CX_EXTEND(cx_struct);
    cx_procedureKind kind;
    cx_callbackInit bind;
};

/* ::cortex::lang::array */
CX_CLASS_DEF(cx_array) {
    CX_EXTEND(cx_collection);
    cx_typedef elementType;
};

/* ::cortex::lang::sequence */
CX_CLASS_DEF(cx_sequence) {
    CX_EXTEND(cx_collection);
};

/* ::cortex::lang::list */
CX_CLASS_DEF(cx_list) {
  CX_EXTEND(cx_collection);
};

/* ::cortex::lang::map */
CX_CLASS_DEF(cx_map) {
    CX_EXTEND(cx_collection);
    cx_typedef elementType;
    cx_typedef keyType;
    cx_uint32 max;
};

/* ::cortex::lang::member */
CX_CLASS_DEF(cx_member) {
    cx_typedef type;
    cx_modifier modifiers;
    cx_state state;
    cx_bool weak;
    cx_uint32 id;
    cx_uint32 offset;
};

/* ::cortex::lang::event */
CX_CLASS_DEF(cx_event) {
    cx_uint16 kind;
    cx_bool handled;
};

/* ::cortex::lang::observableEvent */
CX_CLASS_DEF(cx_observableEvent) {
    CX_EXTEND(cx_event);
    cx_observer observer;
    cx_object me;
    cx_object source;
    cx_object observable;
};

#ifdef __cplusplus
}
#endif

#endif /* CX_H_ */
