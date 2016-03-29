/*
 * corto_value.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#ifndef CORTO_VALUE_H_
#define CORTO_VALUE_H_

#include "corto/lang/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum corto_valueKind {
    CORTO_OBJECT = 0,
    CORTO_BASE = 1, /* serialize inheritance relation */
    CORTO_VALUE = 2,
    CORTO_LITERAL = 3,
    CORTO_MEMBER = 4,
    CORTO_ELEMENT = 5,
    CORTO_MAP_ELEMENT = 6,
    CORTO_CONSTANT = 7/* must be last */
}corto_valueKind;

typedef enum corto_literalKind {
    CORTO_LITERAL_BOOLEAN,
    CORTO_LITERAL_CHARACTER,
    CORTO_LITERAL_INTEGER,
    CORTO_LITERAL_UNSIGNED_INTEGER,
    CORTO_LITERAL_FLOATING_POINT,
    CORTO_LITERAL_STRING,
    CORTO_LITERAL_NULL
}corto_literalKind;

/* corto_value
 *  Structure that is capable of expressing values in a metadata-organized stack. Used by serializer and as expression result.
 */
typedef struct corto_value corto_value;
struct corto_value {
    corto_value* parent;
    corto_valueKind kind;
    union {
        struct {
            corto_object o;
            corto_type t;
        } object;
        struct {
            corto_object o;
            corto_type t;
            corto_void *v;
        } base;
        struct {
            corto_object o;
            corto_type t;
            corto_void* v;
            corto_uint64 storage; /* Optional storage for a value. */
        } value;
        struct {
            corto_literalKind kind;
            union {
                corto_bool _boolean;
                corto_char _character;
                corto_int64 _integer;
                corto_uint64 _unsigned_integer;
                corto_float64 _floating_point;
                corto_string _string;
            } v;
        } literal;
        struct {
            corto_object o;
            corto_member t;
            corto_void* v;
        } member;
        struct {
            corto_object o;
            corto_constant* t;
            corto_void* v;
        } constant;
        struct {
            corto_object o;
            struct {
                corto_type type;
                corto_uint32 index;
            } t;
            corto_void* v;
        } element;
        struct {
            corto_object o;
            struct {
                corto_type type;
                corto_type keyType;
                corto_void *key;
            }t;
            corto_void* v;
        } mapElement;
    } is;
};

typedef corto_value corto_valueStack[64];

corto_type corto_valueType(corto_value* val);
corto_void* corto_valueValue(corto_value* val);
corto_object corto_valueObject(corto_value* val);
corto_uint32 corto_valueIndex(corto_value* val);
char* corto_strving(corto_value* val, char* buffer, unsigned int length);
char* corto_valueExpr(corto_value* val, char* buffer, unsigned int length);
void corto_valueFree(corto_value* val);
void corto_valueStackFree(corto_value* valueStack, corto_uint32 count);

/* Initializers */
void corto_valueObjectInit(corto_value* val, corto_object o, corto_type t);
void corto_valueBaseInit(corto_value* val, corto_void *v, corto_type t);
void corto_valueValueInit(corto_value* val, corto_object o, corto_type t, corto_void* v);
void corto_valueMemberInit(corto_value* val, corto_object o, corto_member t, corto_void* v);
void corto_valueConstantInit(corto_value* val, corto_object o, corto_constant* c, corto_void* v);
void corto_valueElementInit(corto_value* val, corto_object o, corto_type t, corto_uint32 index, corto_void* v);
void corto_valueMapElementInit(corto_value* val, corto_object o, corto_type t, corto_type keyType, corto_void *key, corto_void* v);
void corto_valueLiteralInit(corto_value* val, corto_literalKind kind, corto_void* value);

/* Helpers */
void corto_valueSetValue(corto_value* val, corto_void* v);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_VALUE_H_ */
