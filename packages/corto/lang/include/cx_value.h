/*
 * cx_value.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#ifndef CX_VALUE_H_
#define CX_VALUE_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum cx_valueKind {
    CX_OBJECT = 0,
    CX_BASE = 1, /* serialize inheritance relation */
    CX_VALUE = 2,
    CX_LITERAL = 3,
    CX_MEMBER = 4,
    CX_CALL = 5,
    CX_ELEMENT = 6,
    CX_MAP_ELEMENT = 7,
    CX_CONSTANT = 8/* must be last */
}cx_valueKind;

typedef enum cx_literalKind {
    CX_LITERAL_BOOLEAN,
    CX_LITERAL_CHARACTER,
    CX_LITERAL_INTEGER,
    CX_LITERAL_UNSIGNED_INTEGER,
    CX_LITERAL_FLOATING_POINT,
    CX_LITERAL_STRING,
    CX_LITERAL_NULL
}cx_literalKind;

/* cx_value
 *  Structure that is capable of expressing values in a metadata-organized stack. Used by serializer and as expression result.
 */
typedef struct cx_value cx_value;
struct cx_value {
    cx_value* parent;
    cx_valueKind kind;
    union {
        struct {
            cx_object o;
            cx_type t;
        } object;
        struct {
            cx_object o;
            cx_type t;
            cx_void *v;
        } base;
        struct {
            cx_object o;
            cx_type t;
            cx_void* v;
            cx_uint64 storage; /* Optional storage for a value. */
        } value;
        struct {
            cx_literalKind kind;
            union {
                cx_bool _boolean;
                cx_char _character;
                cx_int64 _integer;
                cx_uint64 _unsigned_integer;
                cx_float64 _floating_point;
                cx_string _string;
            } v;
        } literal;
        struct {
            cx_object o;
            cx_member t;
            cx_void* v;
        } member;
        struct {
            cx_object o;
            cx_function t;
        } call;
        struct {
            cx_object o;
            cx_constant* t;
            cx_void* v;
        } constant;
        struct {
            cx_object o;
            struct {
                cx_type type;
                cx_uint32 index;
            } t;
            cx_void* v;
        } element;
        struct {
            cx_object o;
            struct {
                cx_type type;
                cx_type keyType;
                cx_void *key;
            }t;
            cx_void* v;
        } mapElement;
    } is;
};

typedef cx_value cx_valueStack[64];

cx_type cx_valueType(cx_value* val);
cx_void* cx_valueValue(cx_value* val);
cx_object cx_valueObject(cx_value* val);
cx_uint32 cx_valueIndex(cx_value* val);
cx_function cx_valueFunction(cx_value* val);
cx_void *cx_valueThis(cx_value* val);
char* cx_strving(cx_value* val, char* buffer, unsigned int length);
char* cx_valueExpr(cx_value* val, char* buffer, unsigned int length);
void cx_valueFree(cx_value* val);
void cx_valueStackFree(cx_value* valueStack, cx_uint32 count);

/* Initializers */
void cx_valueObjectInit(cx_value* val, cx_object o, cx_type t);
void cx_valueBaseInit(cx_value* val, cx_void *v, cx_type t);
void cx_valueValueInit(cx_value* val, cx_object o, cx_type t, cx_void* v);
void cx_valueMemberInit(cx_value* val, cx_object o, cx_member t, cx_void* v);
void cx_valueCallInit(cx_value* val, cx_object o, cx_function t);
void cx_valueConstantInit(cx_value* val, cx_object o, cx_constant* c, cx_void* v);
void cx_valueElementInit(cx_value* val, cx_object o, cx_type t, cx_uint32 index, cx_void* v);
void cx_valueMapElementInit(cx_value* val, cx_object o, cx_type t, cx_type keyType, cx_void *key, cx_void* v);
void cx_valueLiteralInit(cx_value* val, cx_literalKind kind, cx_void* value);

/* Helpers */
void cx_valueSetValue(cx_value* val, cx_void* v);

#ifdef __cplusplus
}
#endif

#endif /* CX_VALUE_H_ */
