/*
 * db.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_H_
#define DB_H_

#include "db_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Primitive declarations */
typedef char db_octet;
typedef char db_bool;
typedef char db_char;
typedef uint8_t db_uint8;
typedef uint16_t db_uint16;
typedef uint32_t db_uint32;
typedef uint64_t db_uint64;
typedef int8_t db_int8;
typedef int16_t db_int16;
typedef int32_t db_int32;
typedef int64_t db_int64;
typedef float db_float32;
typedef double db_float64;
typedef char* db_string;
typedef db_int32 db_constant;
typedef uintptr_t db_word;

/* Class declarations */
DB_CLASS(db_typedef);
DB_CLASS(db_type);
DB_CLASS(db_template);
DB_CLASS(db_primitive);
DB_CLASS(db_interface);
DB_CLASS(db_collection);
DB_CLASS(db_binary);
DB_CLASS(db_boolean);
DB_CLASS(db_character);
DB_CLASS(db_int);
DB_CLASS(db_uint);
DB_CLASS(db_float);
DB_CLASS(db_text);
DB_CLASS(db_enum);
DB_CLASS(db_bitmask);
DB_CLASS(db_alias);
DB_CLASS(db_struct);
DB_CLASS(db_class);
DB_CLASS(db_procptr);
DB_CLASS(db_procedure);
DB_CLASS(db_array);
DB_CLASS(db_sequence);
DB_CLASS(db_list);
DB_CLASS(db_map);
DB_CLASS(db_virtual);
DB_CLASS(db_member);
DB_CLASS(db_event);
DB_CLASS(db_observableEvent);

DB_INTERFACE(db_dispatcher);

DB_STRUCT(db_parameter);
DB_STRUCT(db_procptrdata);
DB_STRUCT(db_interfaceVector);

DB_PROCEDURE(db_function);
DB_PROCEDURE(db_method);
DB_PROCEDURE(db_delegate);
DB_PROCEDURE(db_callback);
DB_PROCEDURE(db_observer);
DB_PROCEDURE(db_metaprocedure);

/* any */
DB_ANY(db_any);

/* Class convenience macro's */
#define db_typedef(t) ((db_typedef)t)
#define db_type(t) ((db_type)t)
#define db_template(t) ((db_template)t)
#define db_primitive(t) ((db_primitive)t)
#define db_interface(t) ((db_interface)t)
#define db_collection(t) ((db_collection)t)
#define db_procedure(t) ((db_procedure)t)
#define db_int(t) ((db_int)t)
#define db_uint(t) ((db_uint)t)
#define db_float(t) ((db_float)t)
#define db_text(t) ((db_text)t)
#define db_enum(t) ((db_enum)t)
#define db_bitmask(t) ((db_bitmask)t)
#define db_alias(t) ((db_alias)t)
#define db_struct(t) ((db_struct)t)
#define db_class(t) ((db_class)t)
#define db_procptr(t) ((db_procptr)t)
#define db_array(t) ((db_array)t)
#define db_sequence(t) ((db_sequence)t)
#define db_list(t) ((db_list)t)
#define db_map(t) ((db_map)t)
#define db_member(t) ((db_member)t)
#define db_reference(t) ((db_reference)t)
#define db_event(t) ((db_event)t)
#define db_observableEvent(t) ((db_observableEvent)t)

#define db_function(t) ((db_function)t)
#define db_method(t) ((db_method)t)
#define db_virtual(t) ((db_virtual)t)
#define db_callback(t) ((db_callback)t)
#define db_observer(t) ((db_observer)t)
#define db_delegate(t) ((db_delegate)t)
#define db_metaprocedure(t) ((db_metaprocedure)t)

/* Void object */
typedef void db_void;

/* Object */
typedef void* db_object;

/* Enumeration declarations */
typedef enum db_width {
    DB_WIDTH_8,
    DB_WIDTH_16,
    DB_WIDTH_32,
    DB_WIDTH_64,
    DB_WIDTH_WORD
}db_width;

typedef enum db_typeKind {
    DB_VOID,
    DB_ANY,
    DB_PRIMITIVE,
    DB_COMPOSITE,
    DB_COLLECTION
}db_typeKind;

typedef enum db_primitiveKind {
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
}db_primitiveKind;

typedef enum db_compositeKind {
    DB_INTERFACE,
    DB_STRUCT,
    DB_CLASS,
    DB_PROCPTR,
    DB_PROCEDURE,
}db_compositeKind;

typedef enum db_collectionKind {
    DB_ARRAY,
    DB_SEQUENCE,
    DB_LIST,
    DB_MAP
}db_collectionKind;

typedef enum db_procedureKind {
    DB_FUNCTION,
    DB_METHOD,
    DB_DELEGATE,
    DB_CALLBACK,
    DB_OBSERVER,
    DB_METAPROCEDURE
}db_procedureKind;

typedef enum db_equalityKind {
    DB_EQ = 0,
    DB_LT = -1,
    DB_GT = 1,
    DB_NEQ = 2
}db_equalityKind;

typedef enum db_operatorKind {
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
} db_operatorKind;

DB_BITMASK(db_state);
	/* defined in db_object.h */
DB_BITMASK(db_attr);
	/* defined in db_object.h */
DB_BITMASK(db_eventMask);
	/* defined in db_object.h */

DB_BITMASK(db_modifier);
	#define DB_GLOBAL	  (0) /* Member is global and public (no restrictions) */
    #define DB_LOCAL      (1) /* Member has local validity */
    #define DB_PRIVATE    (2) /* Member is not exposed for extern entities */
    #define DB_READONLY   (4) /* Member access is restricted to reading only */
	#define DB_CONST	  (8) /* Member assignment is restricted to DECLARED objects only */

/* Function types */
typedef db_equalityKind (*db_equalsAction)(db_type _this, const void* o1, const void* o2);

/* Collections */
DB_SEQUENCE(db_objectSeq, db_object,);
DB_SEQUENCE(db_interfaceSeq, db_interface,);
DB_SEQUENCE(db_memberSeq, db_member,);
DB_SEQUENCE(db_parameterSeq, db_parameter,);
DB_SEQUENCE(db_observerSeq, db_observer,);
DB_SEQUENCE(db_vtable, db_function,);
DB_SEQUENCE(db_interfaceVectorSeq, db_interfaceVector,);

typedef db_rbtree db_scope;

/* ::cortex::lang::parameter */
DB_STRUCT_DEF(db_parameter) {
    db_string name;
    db_typedef type;
    db_bool passByReference;
};

/* function */
DB_PROCEDURE_DEF(db_function) {
    db_typedef returnType;
    db_bool returnsReference;
    db_bool overloaded;
    db_uint32 kind;
    db_word impl;       /* The language-binding specific call that is executed upon calling this function. */
    db_word implData;   /* Userdata for the language binding (usually a pointer to the function implemntation) */
    db_object resource;
    db_uint16 size;
    db_parameterSeq parameters;
    db_uint32 nextParameterId;
};

/* method */
DB_PROCEDURE_DEF(db_method) {
    DB_EXTEND(db_function);
    db_bool virtual;
};

/* virtual */
DB_PROCEDURE_DEF(db_virtual) {
    DB_EXTEND(db_method);
};

/* delegate */
DB_PROCEDURE_DEF(db_delegate) {
    DB_EXTEND(db_function);
    db_uint32 id;
};

/* callback */
DB_PROCEDURE_DEF(db_callback) {
    DB_EXTEND(db_function);
    db_delegate delegate;
};

DB_PROCEDURE_DEF(db_metaprocedure) {
	DB_EXTEND(db_function);
    db_bool referenceOnly;
};

/* observer */
DB_PROCEDURE_DEF(db_observer) {
	DB_EXTEND(db_function);
	db_object observable;       /* The object being observed */
	db_uint32 mask;             /* The interest mask */
	db_string expression;       /* Expression (must either resolve to an object or boolean) */
	db_uint32 template;         /* If nonzero, this observer is a class-template which is instantiated for all class-instances */
	db_dispatcher dispatcher;   /* If set, events for this observer are send through this dispatcher */
	db_object me;               /* Set to 'this' if observer is an instantiated class observer. Prevents loopback of events. */
	db_object observing;
	db_observer delayedBinder;
};

/* ::cortex::lang::typedef */
DB_CLASS_DEF(db_typedef) {
    db_typedef type;
    db_type real;
};

/* ::cortex::lang::type */
DB_CLASS_DEF(db_type) {
    DB_EXTEND(db_typedef);
    db_typeKind kind;           /* Is type a void, any, primitive, composite or collection */
    db_bool reference;          /* Is type a reference-type (meaning that an instance is always an object) */
    db_bool hasResources;       /* Optimization: does the type have allocated resources */
    db_uint32 templateId;       /* Optimization: enables quick lookups for type conversions */
    db_uint32 size;             /* The allocated size of a type */
    db_uint16 alignment;        /* The alignment of a type */
    db_typedef defaultType;     /* The default type for objects that are declared in scope of instances of this type */
    db_typedef parentType;      /* The mandatory parentType (if not set parentType can be anything) */
    db_state parentState;       /* The mandatory parentState */
    db_vtable metaprocedures;   /* Metaprocedures of type */
};

/* ::cortex::lang::template */
DB_CLASS_DEF(db_template) {
    DB_EXTEND(db_type);
};

/* ::cortex::lang::primitive */
DB_CLASS_DEF(db_primitive) {
    DB_EXTEND(db_type);
    db_primitiveKind kind;
    db_width width;
    db_uint8 convertId;
};

/* ::cortex::lang::interface */
DB_CLASS_DEF(db_interface) {
    DB_EXTEND(db_type);
    db_compositeKind kind;
    db_uint32 nextMemberId;
    db_memberSeq members;
    db_vtable methods;
    db_interface base;
};

/* ::cortex::lang::collection */
DB_CLASS_DEF(db_collection) {
    DB_EXTEND(db_type);
    db_collectionKind kind;
    db_typedef elementType;
    db_uint32 max;
};

/* ::cortex::lang::binary */
DB_CLASS_DEF(db_binary) {
    DB_EXTEND(db_primitive);
};

/* ::cortex::lang::boolean */
DB_CLASS_DEF(db_boolean) {
    DB_EXTEND(db_primitive);
};

/* ::cortex::lang::character */
DB_CLASS_DEF(db_character) {
    DB_EXTEND(db_primitive);
};

/* ::cortex::lang::int */
DB_CLASS_DEF(db_int) {
    DB_EXTEND(db_primitive);
    db_int64 min;
    db_int64 max;
};

/* ::cortex::lang::uint */
DB_CLASS_DEF(db_uint) {
    DB_EXTEND(db_primitive);
    db_uint64 min;
    db_uint64 max;
};

/* ::cortex::lang::float */
DB_CLASS_DEF(db_float) {
    DB_EXTEND(db_primitive);
    db_float64 min;
    db_float64 max;
};

/* ::cortex::lang::text */
DB_CLASS_DEF(db_text) {
    DB_EXTEND(db_primitive);
    db_width charWidth;
    db_uint64 length;
};

/* ::cortex::lang::enum */
DB_CLASS_DEF(db_enum) {
    DB_EXTEND(db_primitive);
    db_objectSeq constants;
};

/* ::cortex::lang::bitmask */
DB_CLASS_DEF(db_bitmask) {
    DB_EXTEND(db_enum);
};

/* ::cortex::lang::alias */
DB_CLASS_DEF(db_alias) {
	DB_EXTEND(db_primitive);
	db_string typeName;
};

/* ::cortex::lang::struct */
DB_CLASS_DEF(db_struct) {
    DB_EXTEND(db_interface);
    db_modifier baseAccess;
    db_uint16 delegateCount;
};

DB_STRUCT_DEF(db_interfaceVector) {
	db_interface interface;
	db_vtable vector;
};

/* ::cortex::lang::class */
DB_CLASS_DEF(db_class) {
    DB_EXTEND(db_struct);
    db_interfaceSeq implements;
    db_interfaceVectorSeq interfaceVector;
    db_observerSeq observers;
};

/* ::cortex::lang::procptrdata */
DB_STRUCT_DEF(db_procptrdata) {
    db_object instance;
    db_function procedure;
};

/* ::cortex::lang::procptr */
DB_CLASS_DEF(db_procptr) {
    DB_EXTEND(db_struct);
    db_typedef returnType;
    db_bool returnsReference;
    db_parameterSeq parameters;
};

/* ::cortex::lang::procedure */
DB_CLASS_DEF(db_procedure) {
    DB_EXTEND(db_struct);
    db_procedureKind kind;
};

/* ::cortex::lang::array */
DB_CLASS_DEF(db_array) {
    DB_EXTEND(db_collection);
    db_typedef elementType;
};

/* ::cortex::lang::sequence */
DB_CLASS_DEF(db_sequence) {
    DB_EXTEND(db_collection);
};

/* ::cortex::lang::list */
DB_CLASS_DEF(db_list) {
  DB_EXTEND(db_collection);
};

/* ::cortex::lang::map */
DB_CLASS_DEF(db_map) {
    DB_EXTEND(db_collection);
    db_typedef elementType;
    db_typedef keyType;
    db_uint32 max;
};

/* ::cortex::lang::member */
DB_CLASS_DEF(db_member) {
    db_typedef type;
    db_modifier modifiers;
    db_state state;
    db_bool weak;
    db_uint32 id;
    db_uint32 offset;
};

/* ::cortex::lang::event */
DB_CLASS_DEF(db_event) {
	db_uint16 kind;
	db_bool handled;
};

/* ::cortex::lang::observableEvent */
DB_CLASS_DEF(db_observableEvent) {
	DB_EXTEND(db_event);
	db_observer observer;
	db_object me;
	db_object source;
	db_object observable;
};

#ifdef __cplusplus
}
#endif

#endif /* DB_H_ */
