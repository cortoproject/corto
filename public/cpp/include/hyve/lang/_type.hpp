/* include/hyve/lang/_type.hpp
 *
 *  Generated on Oct 28 2014
 *    Type-definitions for C++ language.
 *    This file contains generated code. Do not modify!
 */

#ifndef lang__type_HPP
#define lang__type_HPP

#include "hyve/def.hpp"

namespace hyve {
    namespace lang {
        class Alias;
        class Array;
        class Binary;
        class Bitmask;
        class Boolean;
        class Callback;
        class Character;
        class Class;
        class Collection;
        class Delegate;
        class Dispatcher;
        class Enum;
        class Event;
        class Float;
        class Function;
        class Int;
        class Interface;
        class List;
        class Map;
        class Member;
        class Metaprocedure;
        class Method;
        class ObservableEvent;
        class Observer;
        class Primitive;
        class Procedure;
        class Sequence;
        class Struct;
        class Text;
        class Type;
        class Typedef;
        class Uint;
        class Virtual;
        
        /*  ::hyve::lang::typedef */
        DB_CLASS(_typedef);
        
        /*  ::hyve::lang::type */
        DB_CLASS(type);
        DB_CLASS_DEF(_typedef) {
            ::hyve::lang::_typedef type;
            ::hyve::lang::type real;
        };
        
        /* ::hyve::lang::typeKind */
        typedef enum typeKind {
            VOID = 0,
            ANY = 1,
            PRIMITIVE = 2,
            COMPOSITE = 3,
            COLLECTION = 4
        } typeKind;
        typedef bool _bool;
        typedef uint32_t uint32;
        typedef uint16_t uint16;
        
        /* ::hyve::lang::state */
        DB_BITMASK(state);
        extern int32_t VALID;
        extern int32_t DECLARED;
        extern int32_t DEFINED;
        typedef uintptr_t word;
        typedef void* object;
        typedef int16_t int16;
        typedef char* string;
        
        /*  ::hyve::lang::parameter */
        typedef struct parameter parameter;
        struct parameter {
            ::hyve::lang::string name;
            ::hyve::lang::_typedef type;
            ::hyve::lang::_bool passByReference;
        };
        DB_SEQUENCE(parameterSeq, ::hyve::lang::parameter,/* No postfix */);
        
        /*  ::hyve::lang::function */
        DB_PROCEDURE(function);
        DB_PROCEDURE_DEF(function) {
            ::hyve::lang::_typedef returnType;
            ::hyve::lang::_bool overloaded;
            ::hyve::lang::uint32 kind;
            ::hyve::lang::word impl;
            ::hyve::lang::word impludata;
            ::hyve::lang::object resource;
            ::hyve::lang::int16 size;
            ::hyve::lang::parameterSeq parameters;
            ::hyve::lang::uint32 nextParameterId;
        };
        DB_SEQUENCE(vtable, ::hyve::lang::function,/* No postfix */);
        DB_CLASS_DEF(type) {
            DB_EXTEND(::hyve::lang::_typedef);
            ::hyve::lang::typeKind kind;
            ::hyve::lang::_bool reference;
            ::hyve::lang::_bool hasResources;
            ::hyve::lang::uint32 templateId;
            ::hyve::lang::uint32 size;
            ::hyve::lang::uint16 alignment;
            ::hyve::lang::_typedef defaultType;
            ::hyve::lang::_typedef parentType;
            ::hyve::lang::state parentState;
            ::hyve::lang::vtable metaprocedures;
        };
        
        /* ::hyve::lang::primitiveKind */
        typedef enum primitiveKind {
            BINARY = 0,
            BOOLEAN = 1,
            CHARACTER = 2,
            INTEGER = 3,
            UINTEGER = 4,
            FLOAT = 5,
            TEXT = 6,
            ENUM = 7,
            BITMASK = 8,
            ALIAS = 9
        } primitiveKind;
        
        /* ::hyve::lang::width */
        typedef enum width {
            WIDTH_8 = 0,
            WIDTH_16 = 1,
            WIDTH_32 = 2,
            WIDTH_64 = 3,
            WIDTH_WORD = 4
        } width;
        typedef uint8_t uint8;
        
        /*  ::hyve::lang::primitive */
        DB_CLASS(primitive);
        DB_CLASS_DEF(primitive) {
            DB_EXTEND(::hyve::lang::type);
            ::hyve::lang::primitiveKind kind;
            ::hyve::lang::width width;
            ::hyve::lang::uint8 convertId;
        };
        
        /*  ::hyve::lang::alias */
        DB_CLASS(alias);
        DB_CLASS_DEF(alias) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::string typeName;
        };
        typedef bool _bool;
        struct any{
            hyve::lang::type type;
            void* value;
            hyve::lang::_bool owner;
        };
        
        /* ::hyve::lang::collectionKind */
        typedef enum collectionKind {
            ARRAY = 0,
            SEQUENCE = 1,
            LIST = 2,
            MAP = 3
        } collectionKind;
        
        /*  ::hyve::lang::collection */
        DB_CLASS(collection);
        DB_CLASS_DEF(collection) {
            DB_EXTEND(::hyve::lang::type);
            ::hyve::lang::collectionKind kind;
            ::hyve::lang::_typedef elementType;
            ::hyve::lang::uint32 max;
        };
        
        /*  ::hyve::lang::array */
        DB_CLASS(array);
        DB_CLASS_DEF(array) {
            DB_EXTEND(::hyve::lang::collection);
            ::hyve::lang::_typedef elementType;
        };
        
        /* ::hyve::lang::attr */
        DB_BITMASK(attr);
        extern int32_t ATTR_SCOPED;
        extern int32_t ATTR_WRITABLE;
        extern int32_t ATTR_OBSERVABLE;
        
        /*  ::hyve::lang::binary */
        DB_CLASS(binary);
        DB_CLASS_DEF(binary) {
            DB_EXTEND(::hyve::lang::primitive);
        };
        DB_SEQUENCE(objectSeq, ::hyve::lang::object,/* No postfix */);
        
        /*  ::hyve::lang::enum */
        DB_CLASS(_enum);
        DB_CLASS_DEF(_enum) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::objectSeq constants;
        };
        
        /*  ::hyve::lang::bitmask */
        DB_CLASS(bitmask);
        DB_CLASS_DEF(bitmask) {
            DB_EXTEND(::hyve::lang::_enum);
        };
        
        /*  ::hyve::lang::boolean */
        DB_CLASS(boolean);
        DB_CLASS_DEF(boolean) {
            DB_EXTEND(::hyve::lang::primitive);
        };
        
        /*  ::hyve::lang::delegate */
        DB_PROCEDURE(delegate);
        DB_PROCEDURE_DEF(delegate) {
            DB_EXTEND(function);
            ::hyve::lang::uint32 id;
        };
        
        /*  ::hyve::lang::callback */
        DB_PROCEDURE(callback);
        DB_PROCEDURE_DEF(callback) {
            DB_EXTEND(function);
            ::hyve::lang::delegate delegate;
        };
        typedef char _char;
        
        /*  ::hyve::lang::character */
        DB_CLASS(character);
        DB_CLASS_DEF(character) {
            DB_EXTEND(::hyve::lang::primitive);
        };
        
        /* ::hyve::lang::compositeKind */
        typedef enum compositeKind {
            INTERFACE = 0,
            STRUCT = 1,
            CLASS = 2,
            PROCEDURE = 3
        } compositeKind;
        
        /* ::hyve::lang::modifier */
        DB_BITMASK(modifier);
        extern int32_t GLOBAL;
        extern int32_t LOCAL;
        extern int32_t PRIVATE;
        extern int32_t READONLY;
        extern int32_t CONST;
        
        /*  ::hyve::lang::member */
        DB_CLASS(member);
        DB_CLASS_DEF(member) {
            ::hyve::lang::_typedef type;
            ::hyve::lang::modifier modifiers;
            ::hyve::lang::state state;
            ::hyve::lang::_bool weak;
            ::hyve::lang::uint32 id;
            ::hyve::lang::uint32 offset;
        };
        DB_SEQUENCE(memberSeq, ::hyve::lang::member,/* No postfix */);
        
        /*  ::hyve::lang::interface */
        DB_CLASS(interface);
        DB_CLASS_DEF(interface) {
            DB_EXTEND(::hyve::lang::type);
            ::hyve::lang::compositeKind kind;
            ::hyve::lang::uint32 nextMemberId;
            ::hyve::lang::memberSeq members;
            ::hyve::lang::vtable methods;
            ::hyve::lang::interface base;
        };
        
        /*  ::hyve::lang::struct */
        DB_CLASS(_struct);
        DB_CLASS_DEF(_struct) {
            DB_EXTEND(::hyve::lang::interface);
            ::hyve::lang::modifier baseAccess;
            ::hyve::lang::uint16 delegateCount;
        };
        DB_SEQUENCE(interfaceSeq, ::hyve::lang::interface,/* No postfix */);
        
        /*  ::hyve::lang::interfaceVector */
        typedef struct interfaceVector interfaceVector;
        struct interfaceVector {
            ::hyve::lang::word interface;
            ::hyve::lang::vtable vector;
        };
        DB_SEQUENCE(interfaceVectorSeq, ::hyve::lang::interfaceVector,/* No postfix */);
        
        /* ::hyve::lang::eventMask */
        DB_BITMASK(eventMask);
        extern int32_t ON_DECLARE;
        extern int32_t ON_DEFINE;
        extern int32_t ON_DESTRUCT;
        extern int32_t ON_INVALIDATE;
        extern int32_t ON_UPDATE;
        extern int32_t ON_SELF;
        extern int32_t ON_SCOPE;
        extern int32_t ON_VALUE;
        extern int32_t ON_METAVALUE;
        
        /*  ::hyve::lang::dispatcher */
        DB_INTERFACE(dispatcher);
        
        /*  ::hyve::lang::observer */
        DB_PROCEDURE(observer);
        DB_PROCEDURE_DEF(observer) {
            DB_EXTEND(function);
            ::hyve::lang::object observable;
            ::hyve::lang::eventMask mask;
            ::hyve::lang::string expression;
            ::hyve::lang::uint32 _template;
            ::hyve::lang::dispatcher dispatcher;
            ::hyve::lang::object me;
            ::hyve::lang::object observing;
            ::hyve::lang::observer delayedBinder;
        };
        DB_SEQUENCE(observerSeq, ::hyve::lang::observer,/* No postfix */);
        
        /*  ::hyve::lang::class */
        DB_CLASS(_class);
        DB_CLASS_DEF(_class) {
            DB_EXTEND(::hyve::lang::_struct);
            ::hyve::lang::interfaceSeq implements;
            ::hyve::lang::interfaceVectorSeq interfaceVector;
            ::hyve::lang::observerSeq observers;
        };
        typedef int32_t constant;
        
        /* ::hyve::lang::equalityKind */
        typedef enum equalityKind {
            EQ = 0,
            LT = -1,
            GT = 1,
            NEQ = 2
        } equalityKind;
        
        /*  ::hyve::lang::event */
        DB_CLASS(event);
        DB_CLASS_DEF(event) {
            ::hyve::lang::uint16 kind;
            ::hyve::lang::_bool handled;
        };
        typedef double float64;
        
        /*  ::hyve::lang::float */
        DB_CLASS(_float);
        DB_CLASS_DEF(_float) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::float64 min;
            ::hyve::lang::float64 max;
        };
        typedef float float32;
        typedef int64_t int64;
        
        /*  ::hyve::lang::int */
        DB_CLASS(_int);
        DB_CLASS_DEF(_int) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::int64 min;
            ::hyve::lang::int64 max;
        };
        typedef int32_t int32;
        typedef int8_t int8;
        
        /*  ::hyve::lang::list */
        DB_CLASS(list);
        DB_CLASS_DEF(list) {
            DB_EXTEND(::hyve::lang::collection);
        };
        
        /*  ::hyve::lang::map */
        DB_CLASS(map);
        DB_CLASS_DEF(map) {
            DB_EXTEND(::hyve::lang::collection);
            ::hyve::lang::_typedef elementType;
            ::hyve::lang::_typedef keyType;
            ::hyve::lang::uint32 max;
        };
        
        /*  ::hyve::lang::metaprocedure */
        DB_PROCEDURE(metaprocedure);
        DB_PROCEDURE_DEF(metaprocedure) {
            DB_EXTEND(function);
        };
        
        /*  ::hyve::lang::method */
        DB_PROCEDURE(method);
        DB_PROCEDURE_DEF(method) {
            DB_EXTEND(function);
            ::hyve::lang::_bool _virtual;
        };
        
        /*  ::hyve::lang::observableEvent */
        DB_CLASS(observableEvent);
        DB_CLASS_DEF(observableEvent) {
            DB_EXTEND(::hyve::lang::event);
            ::hyve::lang::observer observer;
            ::hyve::lang::object me;
            ::hyve::lang::object source;
            ::hyve::lang::object observable;
        };
        typedef uint8_t octet;
        
        /* ::hyve::lang::operatorKind */
        typedef enum operatorKind {
            ASSIGN = 0,
            ADD = 1,
            SUB = 2,
            MUL = 3,
            DIV = 4,
            MOD = 5,
            INC = 6,
            DEC = 7,
            XOR = 8,
            OR = 9,
            AND = 10,
            NOT = 11,
            ASSIGN_ADD = 12,
            ASSIGN_SUB = 13,
            ASSIGN_MUL = 14,
            ASSIGN_DIV = 15,
            ASSIGN_MOD = 16,
            ASSIGN_XOR = 17,
            ASSIGN_OR = 18,
            ASSIGN_AND = 19,
            COND_OR = 20,
            COND_AND = 21,
            COND_NOT = 22,
            COND_EQ = 23,
            COND_NEQ = 24,
            COND_GT = 25,
            COND_LT = 26,
            COND_GTEQ = 27,
            COND_LTEQ = 28,
            SHIFT_LEFT = 29,
            SHIFT_RIGHT = 30,
            COMMA = 31,
            REF = 32,
            MEMBER_RESOLVE = 33,
            ELEMENT_OPEN = 34,
            ELEMENT_CLOSE = 35,
            BRACKET_OPEN = 36,
            BRACKET_CLOSE = 37
        } operatorKind;
        
        /* ::hyve::lang::procedureKind */
        typedef enum procedureKind {
            FUNCTION = 0,
            METHOD = 1,
            DELEGATE = 2,
            CALLBACK = 3,
            OBSERVER = 4,
            METAPROCEDURE = 5
        } procedureKind;
        
        /*  ::hyve::lang::procedure */
        DB_CLASS(procedure);
        DB_CLASS_DEF(procedure) {
            DB_EXTEND(::hyve::lang::_struct);
            ::hyve::lang::procedureKind kind;
        };
        
        /*  ::hyve::lang::sequence */
        DB_CLASS(sequence);
        DB_CLASS_DEF(sequence) {
            DB_EXTEND(::hyve::lang::collection);
        };
        typedef uint64_t uint64;
        
        /*  ::hyve::lang::text */
        DB_CLASS(text);
        DB_CLASS_DEF(text) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::width charWidth;
            ::hyve::lang::uint64 length;
        };
        
        /*  ::hyve::lang::uint */
        DB_CLASS(uint);
        DB_CLASS_DEF(uint) {
            DB_EXTEND(::hyve::lang::primitive);
            ::hyve::lang::uint64 min;
            ::hyve::lang::uint64 max;
        };
        
        /*  ::hyve::lang::virtual */
        DB_PROCEDURE(_virtual);
        DB_PROCEDURE_DEF(_virtual) {
            DB_EXTEND(method);
        };
        typedef void _void;
    }
}

#endif

