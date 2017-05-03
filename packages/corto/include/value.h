/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CORTO_VALUE_H_
#define CORTO_VALUE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Base corto value kinds */
typedef enum corto_valueKind {
    CORTO_OBJECT = 0,
    CORTO_BASE = 1, /* serialize inheritance relation */
    CORTO_VALUE = 2,
    CORTO_LITERAL = 3,
    CORTO_MEMBER = 4,
    CORTO_ELEMENT = 5,
    CORTO_MAP_ELEMENT = 6,
    CORTO_CONSTANT = 7 /* must be last */
}corto_valueKind;

/* Base corto literal kinds */
typedef enum corto_literalKind {
    CORTO_LITERAL_BOOLEAN,
    CORTO_LITERAL_CHARACTER,
    CORTO_LITERAL_INTEGER,
    CORTO_LITERAL_UNSIGNED_INTEGER,
    CORTO_LITERAL_FLOATING_POINT,
    CORTO_LITERAL_STRING,
    CORTO_LITERAL_NULL
}corto_literalKind;

/* Struct capable of representing any corto value */
typedef struct corto_value corto_value;
struct corto_value {
    corto_value* parent; /* Used for nested values, like foo.bar (parent = foo) */
    corto_valueKind kind;
    union {
        struct {
            corto_object o;
            corto_type t; /* Can differ from typeof(o) when using inheritance */
        } object;
        struct {
            corto_object o;
            corto_type t;
            void *v;
        } base;
        struct {
            corto_object o;
            corto_type t;
            void* v;
            corto_uint64 storage; /* Optional storage for a value */
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
            void* v;
        } member;
        struct {
            corto_object o;
            corto_constant* t;
            void* v;
        } constant;
        struct {
            corto_object o;
            struct {
                corto_type type;
                uint32_t index;
            } t;
            void* v;
        } element;
        struct {
            corto_object o;
            struct {
                corto_type type;
                corto_type keyType;
                void *key;
            }t;
            void* v;
        } mapElement;
    } is;
};

/* value API */
CORTO_EXPORT corto_type corto_value_typeof(corto_value *val);
CORTO_EXPORT void* corto_value_ptrof(corto_value *val);
CORTO_EXPORT int16_t corto_value_ptrset(corto_value *val, void *ptr);
CORTO_EXPORT corto_object corto_value_objectof(corto_value *val);
CORTO_EXPORT uint32_t corto_value_indexof(corto_value *val);
CORTO_EXPORT int16_t corto_value_memberof(corto_value *val, char *member, corto_value *out);

/* value expression API */
CORTO_EXPORT int16_t corto_value_unaryOp(corto_operatorKind _operator, corto_value *value, corto_value *result);
CORTO_EXPORT int16_t corto_value_binaryOp(corto_operatorKind _operator, corto_value *operand1, corto_value *operand2, corto_value *result);
CORTO_EXPORT int16_t _corto_value_cast(corto_value *in, corto_type dstType, corto_value *out);

/* Initializers */
CORTO_EXPORT corto_value corto_value_empty(void);
CORTO_EXPORT void corto_value_free(corto_value *v);
CORTO_EXPORT corto_value _corto_value_object(corto_object o, corto_type t);
CORTO_EXPORT corto_value _corto_value_base(void *v, corto_type t);
CORTO_EXPORT corto_value _corto_value_value(void *v, corto_type t);
CORTO_EXPORT corto_value corto_value_member(corto_object o, corto_member t, void *v);
CORTO_EXPORT corto_value corto_value_constant(corto_object o, corto_constant *c, void *v);
CORTO_EXPORT corto_value _corto_value_element(corto_object o, corto_type t, uint32_t index, void *v);
CORTO_EXPORT corto_value corto_value_mapElement(corto_object o, corto_type t, corto_type keyType, void *key, void *v);
CORTO_EXPORT corto_value corto_value_literal(corto_literalKind kind, void *value);
CORTO_EXPORT corto_value corto_value_bool(bool value);
CORTO_EXPORT corto_value corto_value_char(corto_char value);
CORTO_EXPORT corto_value corto_value_uint(corto_uint64 value);
CORTO_EXPORT corto_value corto_value_int(corto_uint64 value);
CORTO_EXPORT corto_value corto_value_float(corto_float64 value);
CORTO_EXPORT corto_value corto_value_string(char *value);

/* Helpers */
CORTO_EXPORT char* corto_value_exprStr(corto_value *val, char *buffer, unsigned int length);
int16_t corto_binaryExpr_getType(
    corto_type leftType,
    bool t1ByRef,
    corto_type rightType,
    bool t2ByRef,
    corto_operatorKind _operator,
    corto_type *operandType,
    corto_type *resultType);

CORTO_EXPORT int16_t corto_value_fromcontent(corto_value *v, char *contentType, char *content);
CORTO_EXPORT char *corto_value_contentof(corto_value *v, char *contentType);
CORTO_EXPORT char *corto_value_str(corto_value* v, uint32_t maxLength);
CORTO_EXPORT int16_t corto_value_fromStr(corto_value *v, char *string);
CORTO_EXPORT int16_t corto_value_copy(corto_value *dst, corto_value *src);
CORTO_EXPORT corto_equalityKind corto_value_compare(corto_value *v1, corto_value *value2);
CORTO_EXPORT int16_t corto_value_init(corto_value *v);
CORTO_EXPORT int16_t corto_value_deinit(corto_value *v);

/* Type safe macro's */
#define corto_value_object(o, t) _corto_value_object(o, corto_type(t))
#define corto_value_base(v, t) _corto_value_base(v, corto_type(t))
#define corto_value_value(v, t) _corto_value_value(v, corto_type(t))
#define corto_value_element(o, t, i, v) _corto_value_element(o, corto_type(t), i, v)
#define corto_value_mapElement(o, t, kt, k, v) _corto_value_mapElement(o, corto_type(t), corto_type(kt), k, v)
#define corto_value_cast(in, dstType, out) _corto_value_cast(in, corto_type(dstType), out)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_VALUE_H_ */
