/*
 * db.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_H_
#define DB_H_

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
DB_CLASS(cx_typedef);
DB_CLASS(cx_type);
DB_CLASS(cx_template);
DB_CLASS(cx_primitive);
DB_CLASS(cx_interface);
DB_CLASS(cx_collection);
DB_CLASS(cx_binary);
DB_CLASS(cx_boolean);
DB_CLASS(cx_character);
DB_CLASS(cx_int);
DB_CLASS(cx_uint);
DB_CLASS(cx_float);
DB_CLASS(cx_text);
DB_CLASS(cx_enum);
DB_CLASS(cx_bitmask);
DB_CLASS(cx_alias);
DB_CLASS(cx_struct);
DB_CLASS(cx_class);
DB_CLASS(cx_procptr);
DB_CLASS(cx_procedure);
DB_CLASS(cx_array);
DB_CLASS(cx_sequence);
DB_CLASS(cx_list);
DB_CLASS(cx_map);
DB_CLASS(cx_virtual);
DB_CLASS(cx_member);
DB_CLASS(cx_event);
DB_CLASS(cx_observableEvent);

DB_INTERFACE(cx_dispatcher);

DB_STRUCT(cx_parameter);
DB_STRUCT(cx_procptrdata);
DB_STRUCT(cx_interfaceVector);

DB_PROCEDURE(cx_function);
DB_PROCEDURE(cx_method);
DB_PROCEDURE(cx_delegate);
DB_PROCEDURE(cx_callback);
DB_PROCEDURE(cx_observer);
DB_PROCEDURE(cx_metaprocedure);

/* any */
DB_ANY(cx_any);

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
#define cx_procptr(t) ((cx_procptr)t)
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
#define cx_callback(t) ((cx_callback)t)
#define cx_observer(t) ((cx_observer)t)
#define cx_delegate(t) ((cx_delegate)t)
#define cx_metaprocedure(t) ((cx_metaprocedure)t)

/* Void object */
typedef void cx_void;

/* Object */
typedef void* cx_object;

/* Enumeration declarations */
typedef enum cx_width {
    DB_WIDTH_8,
    DB_WIDTH_16,
    DB_WIDTH_32,
    DB_WIDTH_64,
    DB_WIDTH_WORD
}cx_width;

typedef enum cx_typeKind {
    DB_VOID,
    DB_ANY,
    DB_PRIMITIVE,
    DB_COMPOSITE,
    DB_COLLECTION
}cx_typeKind;

typedef enum cx_primitiveKind {
    DB_BINARY,
    DB_BOOLEAN,
    DB_CHARACTER,
    DB_INTEGER,
    DB_UINTEGER,
    DB_FLOAT,
    DB_TEXT,
    DB_ENUM,
    DB_BITMASK,
    DB_ALIAS
}cx_primitiveKind;

typedef enum cx_compositeKind {
    DB_INTERFACE,
    DB_STRUCT,
    DB_CLASS,
    DB_PROCPTR,
    DB_PROCEDURE,
}cx_compositeKind;

typedef enum cx_collectionKind {
    DB_ARRAY,
    DB_SEQUENCE,
    DB_LIST,
    DB_MAP
}cx_collectionKind;

typedef enum cx_procedureKind {
    DB_FUNCTION,
    DB_METHOD,
    DB_DELEGATE,
    DB_CALLBACK,
    DB_OBSERVER,
    DB_METAPROCEDURE
}cx_procedureKind;

typedef enum cx_equalityKind {
    DB_EQ = 0,
    DB_LT = -1,
    DB_GT = 1,
    DB_NEQ = 2
}cx_equalityKind;

typedef enum cx_operatorKind {
    DB_ASSIGN,
    DB_ADD,
    DB_SUB,
    DB_MUL,
    DB_DIV,
    DB_MOD,
    DB_INC,
    DB_DEC,
    DB_XOR,
    DB_OR,
    DB_AND,
    DB_NOT,
    DB_ASSIGN_ADD,
    DB_ASSIGN_SUB,
    DB_ASSIGN_MUL,
    DB_ASSIGN_DIV,
    DB_ASSIGN_MOD,
    DB_ASSIGN_XOR,
    DB_ASSIGN_OR,
    DB_ASSIGN_AND,
    DB_COND_OR,
    DB_COND_AND,
    DB_COND_NOT,
    DB_COND_EQ,
    DB_COND_NEQ,
    DB_COND_GT,
    DB_COND_LT,
    DB_COND_GTEQ,
    DB_COND_LTEQ,
    DB_SHIFT_LEFT,
    DB_SHIFT_RIGHT,
    DB_COMMA,
    DB_REF,
    DB_MEMBER_RESOLVE,
    DB_ELEMENT_OPEN,
    DB_ELEMENT_CLOSE,
    DB_BRACKET_OPEN,
    DB_BRACKET_CLOSE /* Must be last */
} cx_operatorKind;

DB_BITMASK(cx_state);
	/* defined in cx_object.h */
DB_BITMASK(cx_attr);
	/* defined in cx_object.h */
DB_BITMASK(cx_eventMask);
	/* defined in cx_object.h */

DB_BITMASK(cx_modifier);
	#define DB_GLOBAL	  (0) /* Member is global and public (no restrictions) */
    #define DB_LOCAL      (1) /* Member has local validity */
    #define DB_PRIVATE    (2) /* Member is not exposed for extern entities */
    #define DB_READONLY   (4) /* Member access is restricted to reading only */
	#define DB_CONST	  (8) /* Member assignment is restricted to DECLARED objects only */

/* Function types */
typedef cx_equalityKind (*cx_equalsAction)(cx_type _this, const void* o1, const void* o2);

/* Collections */
DB_SEQUENCE(cx_objectSeq, cx_object,);
DB_SEQUENCE(cx_interfaceSeq, cx_interface,);
DB_SEQUENCE(cx_memberSeq, cx_member,);
DB_SEQUENCE(cx_parameterSeq, cx_parameter,);
DB_SEQUENCE(cx_observerSeq, cx_observer,);
DB_SEQUENCE(cx_vtable, cx_function,);
DB_SEQUENCE(cx_interfaceVectorSeq, cx_interfaceVector,);

typedef cx_rbtree cx_scope;

/* ::cortex::lang::parameter */
DB_STRUCT_DEF(cx_parameter) {
    cx_string name;
    cx_typedef type;
    cx_bool passByReference;
};

/* function */
DB_PROCEDURE_DEF(cx_function) {
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
DB_PROCEDURE_DEF(cx_method) {
    DB_EXTEND(cx_function);
    cx_bool virtual;
};

/* virtual */
DB_PROCEDURE_DEF(cx_virtual) {
    DB_EXTEND(cx_method);
};

/* delegate */
DB_PROCEDURE_DEF(cx_delegate) {
    DB_EXTEND(cx_function);
    cx_uint32 id;
};

/* callback */
DB_PROCEDURE_DEF(cx_callback) {
    DB_EXTEND(cx_function);
    cx_delegate delegate;
};

DB_PROCEDURE_DEF(cx_metaprocedure) {
	DB_EXTEND(cx_function);
    cx_bool referenceOnly;
};

/* observer */
DB_PROCEDURE_DEF(cx_observer) {
	DB_EXTEND(cx_function);
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
DB_CLASS_DEF(cx_typedef) {
    cx_typedef type;
    cx_type real;
};

/* ::cortex::lang::type */
DB_CLASS_DEF(cx_type) {
    DB_EXTEND(cx_typedef);
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
};

/* ::cortex::lang::template */
DB_CLASS_DEF(cx_template) {
    DB_EXTEND(cx_type);
};

/* ::cortex::lang::primitive */
DB_CLASS_DEF(cx_primitive) {
    DB_EXTEND(cx_type);
    cx_primitiveKind kind;
    cx_width width;
    cx_uint8 convertId;
};

/* ::cortex::lang::interface */
DB_CLASS_DEF(cx_interface) {
    DB_EXTEND(cx_type);
    cx_compositeKind kind;
    cx_uint32 nextMemberId;
    cx_memberSeq members;
    cx_vtable methods;
    cx_interface base;
};

/* ::cortex::lang::collection */
DB_CLASS_DEF(cx_collection) {
    DB_EXTEND(cx_type);
    cx_collectionKind kind;
    cx_typedef elementType;
    cx_uint32 max;
};

/* ::cortex::lang::binary */
DB_CLASS_DEF(cx_binary) {
    DB_EXTEND(cx_primitive);
};

/* ::cortex::lang::boolean */
DB_CLASS_DEF(cx_boolean) {
    DB_EXTEND(cx_primitive);
};

/* ::cortex::lang::character */
DB_CLASS_DEF(cx_character) {
    DB_EXTEND(cx_primitive);
};

/* ::cortex::lang::int */
DB_CLASS_DEF(cx_int) {
    DB_EXTEND(cx_primitive);
    cx_int64 min;
    cx_int64 max;
};

/* ::cortex::lang::uint */
DB_CLASS_DEF(cx_uint) {
    DB_EXTEND(cx_primitive);
    cx_uint64 min;
    cx_uint64 max;
};

/* ::cortex::lang::float */
DB_CLASS_DEF(cx_float) {
    DB_EXTEND(cx_primitive);
    cx_float64 min;
    cx_float64 max;
};

/* ::cortex::lang::text */
DB_CLASS_DEF(cx_text) {
    DB_EXTEND(cx_primitive);
    cx_width charWidth;
    cx_uint64 length;
};

/* ::cortex::lang::enum */
DB_CLASS_DEF(cx_enum) {
    DB_EXTEND(cx_primitive);
    cx_objectSeq constants;
};

/* ::cortex::lang::bitmask */
DB_CLASS_DEF(cx_bitmask) {
    DB_EXTEND(cx_enum);
};

/* ::cortex::lang::alias */
DB_CLASS_DEF(cx_alias) {
	DB_EXTEND(cx_primitive);
	cx_string typeName;
};

/* ::cortex::lang::struct */
DB_CLASS_DEF(cx_struct) {
    DB_EXTEND(cx_interface);
    cx_modifier baseAccess;
    cx_uint16 delegateCount;
};

DB_STRUCT_DEF(cx_interfaceVector) {
	cx_interface interface;
	cx_vtable vector;
};

/* ::cortex::lang::class */
DB_CLASS_DEF(cx_class) {
    DB_EXTEND(cx_struct);
    cx_interfaceSeq implements;
    cx_interfaceVectorSeq interfaceVector;
    cx_observerSeq observers;
};

/* ::cortex::lang::procptrdata */
DB_STRUCT_DEF(cx_procptrdata) {
    cx_object instance;
    cx_function procedure;
};

/* ::cortex::lang::procptr */
DB_CLASS_DEF(cx_procptr) {
    DB_EXTEND(cx_struct);
    cx_typedef returnType;
    cx_bool returnsReference;
    cx_parameterSeq parameters;
};

/* ::cortex::lang::procedure */
DB_CLASS_DEF(cx_procedure) {
    DB_EXTEND(cx_struct);
    cx_procedureKind kind;
};

/* ::cortex::lang::array */
DB_CLASS_DEF(cx_array) {
    DB_EXTEND(cx_collection);
    cx_typedef elementType;
};

/* ::cortex::lang::sequence */
DB_CLASS_DEF(cx_sequence) {
    DB_EXTEND(cx_collection);
};

/* ::cortex::lang::list */
DB_CLASS_DEF(cx_list) {
  DB_EXTEND(cx_collection);
};

/* ::cortex::lang::map */
DB_CLASS_DEF(cx_map) {
    DB_EXTEND(cx_collection);
    cx_typedef elementType;
    cx_typedef keyType;
    cx_uint32 max;
};

/* ::cortex::lang::member */
DB_CLASS_DEF(cx_member) {
    cx_typedef type;
    cx_modifier modifiers;
    cx_state state;
    cx_bool weak;
    cx_uint32 id;
    cx_uint32 offset;
};

/* ::cortex::lang::event */
DB_CLASS_DEF(cx_event) {
	cx_uint16 kind;
	cx_bool handled;
};

/* ::cortex::lang::observableEvent */
DB_CLASS_DEF(cx_observableEvent) {
	DB_EXTEND(cx_event);
	cx_observer observer;
	cx_object me;
	cx_object source;
	cx_object observable;
};

#ifdef __cplusplus
}
#endif

#endif /* DB_H_ */
