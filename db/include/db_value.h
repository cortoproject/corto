/*
 * db_value.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

#ifndef DB_VALUE_H_
#define DB_VALUE_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum db_valueKind {
    DB_OBJECT = 0,
    DB_BASE = 1, /* serialize inheritance relation */
    DB_VALUE = 2,
    DB_LITERAL = 3,
    DB_MEMBER = 4,
    DB_CALL = 5,
    DB_ELEMENT = 6,
    DB_MAP_ELEMENT = 7,
    DB_CONSTANT = 8/* must be last */
}db_valueKind;

typedef enum db_literalKind {
	DB_LITERAL_BOOLEAN,
	DB_LITERAL_CHARACTER,
	DB_LITERAL_INTEGER,
	DB_LITERAL_UNSIGNED_INTEGER,
	DB_LITERAL_FLOATING_POINT,
	DB_LITERAL_STRING,
	DB_LITERAL_NULL
}db_literalKind;

/* db_value
 *  Structure that is capable of expressing values in a metadata-organized stack. Used by serializer and as expression result.
 */
typedef struct db_value db_value;
struct db_value {
    db_value* parent;
    db_valueKind kind;
    union {
        db_object o;
        struct {
            db_object o;
            db_typedef t;
            db_void *v;
        }base;
        struct {
            db_object o;
            db_typedef t;
            db_void* v;
            db_uint64 storage; /* Optional storage for a value. */
        }value;
        struct {
        	db_literalKind kind;
        	union {
        		db_bool _boolean;
        		db_char _character;
        		db_int64 _integer;
        		db_uint64 _unsigned_integer;
        		db_float64 _floating_point;
        		db_string _string;
        	}v;
        }literal;
        struct {
            db_object o;
            db_member t;
            db_void* v;
        }member;
        struct {
        	db_object o;
        	db_function t;
        }call;
        struct {
            db_object o;
            db_constant* t;
            db_void* v;
        }constant;
        struct {
            db_object o;
            struct {
                db_typedef type;
                db_uint32 index;
            } t;
            db_void* v;
        }element;
        struct {
            db_object o;
            struct {
                db_typedef type;
                db_typedef keyType;
                db_void *key;
            }t;
            db_void* v;
        }mapElement;
    } is;
};

typedef db_value db_valueStack[64];

db_typedef db_valueType(db_value* val);
db_void* db_valueValue(db_value* val);
db_object db_valueObject(db_value* val);
db_uint32 db_valueIndex(db_value* val);
db_function db_valueFunction(db_value* val);
db_void *db_valueThis(db_value* val);
char* db_valueString(db_value* val, char* buffer, unsigned int length);
char* db_valueExpr(db_value* val, char* buffer, unsigned int length);
void db_valueFree(db_value* val);
void db_valueStackFree(db_value* valueStack, db_uint32 count);

/* Initializers */
void db_valueObjectInit(db_value* val, db_object o);
void db_valueBaseInit(db_value* val, db_void *v, db_typedef t);
void db_valueValueInit(db_value* val, db_object o, db_typedef t, db_void* v);
void db_valueMemberInit(db_value* val, db_object o, db_member t, db_void* v);
void db_valueCallInit(db_value* val, db_object o, db_function t);
void db_valueConstantInit(db_value* val, db_object o, db_constant* c, db_void* v);
void db_valueElementInit(db_value* val, db_object o, db_typedef t, db_uint32 index, db_void* v);
void db_valueMapElementInit(db_value* val, db_object o, db_typedef t, db_typedef keyType, db_void *key, db_void* v);
void db_valueLiteralInit(db_value* val, db_literalKind kind, db_void* value);

/* Helpers */
void db_valueSetValue(db_value* val, db_void* v);

#ifdef __cplusplus
}
#endif

#endif /* DB_VALUE_H_ */
