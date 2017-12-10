/* Copyright (c) 2010-2018 the corto developers
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

/** @file 
 * @section value Value API
 * @brief API for dynamic access to corto values.
 *
 * The corto_value type contains meta-information in addition to a pointer
 * and a type that allows it to describe any possible value in corto. The most
 * commonly used values are objects, members and elements. 
 *
 * The corto_walk API in particular uses corto_value to communicate 
 * meta information about the value that is visited. A corto_value instance can
 * itself also be an input for the corto_walk API. The corto_value type also plays
 * a prominent role in the contentType interface. Whenever a value that is potentially
 * not an object needs to be shared between components, corto_value is the 
 * preferred carrier.
 *
 * The functions that are available for corto_value allow an application to
 * work with values of which the types are not known upfront. Beyond getting and
 * setting values dynamically, applications can use the corto_value API to cast
 * values dynamically, perform unary and binary operators and navigate and query
 * all scalar values of a value encapsulated by corto_value.
 *
 * In addition to describing corto values, a corto_value instance can also 
 * contain a literal value. Literal values can be used to represent constant
 * values in unary or binary operations.
 *
 * Each corto_value has a parent field which can point to another corto_value.
 * This allows a corto_value to express a hierarchy of values, as is often found
 * in nested (composite/collection) types. The walk API automatically populates 
 * the parent field so that walk callbacks have full access to all information 
 * about the value being serialized.
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
    CORTO_MEM = 3, /* used internally. allows copying non-object memory of reference type by value. */ 
    CORTO_LITERAL = 4,
    CORTO_MEMBER = 5,
    CORTO_ELEMENT = 6,
    CORTO_MAP_ELEMENT = 7,
    CORTO_CONSTANT = 8 /* must be last */
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

/** Get the type of a corto_value.
 * @param value A pointer to a corto_value.
 * @return The type of the specified value.
 * @see corto_value_ptrof
 */
CORTO_EXPORT 
corto_type corto_value_typeof(
    corto_value *value);

/** Get a pointer of a corto_value.
 * The resulting pointer can be used in corto_ptr_* functions, together with the
 * result of corto_value_typeof.
 *
 * @param value A pointer to a corto_value.
 * @return A pointer to the value represented by the corto_value.
 * @see corto_value_typeof corto_value_ptrset
 */
CORTO_EXPORT 
void* corto_value_ptrof(
    corto_value *val);

/** Set the corto_value to a new pointer.
 * This function will not modify the value of the current pointer, but overrides
 * the value encapsulated by the corto_value. For example, this function can set
 * a corto_value to a new object, or new member.
 *
 * It is important that the specified pointer is of the same type as the
 * corto_value. It is illegal to set the pointer of a corto_value instance of
 * the CORTO_LITERAL kind.
 *
 * @param value A pointer to a corto_value.
 * @param ptr The pointer to set for the corto_value.
 * @return 0 if success, -1 if failed.
 * @see corto_value_ptrof
 */
CORTO_EXPORT 
int16_t corto_value_ptrset(
    corto_value *val, 
    void *ptr);

/** Return the object associated with a specified corto_value.
 * Most corto_value instances point to values in a corto_object. This object is
 * stored as a separate field of the value, and can be obtained by this function.
 *
 * The function is invalid for corto_value instances of the CORTO_LITERAL kind.
 *
 * @param value A pointer to a corto_value.
 * @param ptr The pointer to set for the corto_value.
 * @return 0 if success, -1 if failed.
 * @see corto_value_ptrof
 */
CORTO_EXPORT 
corto_object corto_value_objectof(
    corto_value *val);

/** Get a member from an existing composite corto_value.
 * Initialize a new corto_value from an existing corto_value with a member of
 * the existing corto_value. The function accepts a member expression in the
 * form of `foo.bar.helloworld`. If the specified member is not valid for the
 * type of the corto_value instance, the function will fail.
 *
 * @param value A pointer to a corto_value.
 * @param member A valid member expression for the type of the specified value.
 * @param out The resulting corto_value.
 * @return 0 if success, -1 if failed.
 * @see corto_value_unaryOp corto_value_binaryOp corto_value_cast
 */
CORTO_EXPORT 
int16_t corto_value_memberExpr(
    corto_value *value, 
    char *member, 
    corto_value *out);

/** Perform unary operator on a corto_value.
 * The result corto_value has to at least be an initialized corto_value (use
 * corto_value_empty for new values). The value does not have to be of a 
 * matching type. If the result corto_value owned any resources, they will be 
 * deallocated / released before assigning the new value.
 * 
 * @param _operator The operator to perform.
 * @param value A pointer to the operand corto_value.
 * @param result A pointer to the result corto_value.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_binaryOp corto_ptr_cast corto_value_memberExpr
 */
CORTO_EXPORT 
int16_t corto_value_unaryOp(
    corto_operatorKind _operator, 
    corto_value *value, 
    corto_value *result);

/** Perform binary operator on two corto_values.
 * The result corto_value has to at least be an initialized corto_value (use
 * corto_value_empty for new values). The value does not have to be of a 
 * matching type. If the result corto_value owned any resources, they will be 
 * deallocated / released before assigning the new value.
 * 
 * @param _operator The operator to perform.
 * @param left A pointer to the leftoperand corto_value.
 * @param right A pointer to the right operand corto_value.
 * @param result A pointer to the result corto_value.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_unaryOp corto_ptr_cast corto_value_memberExpr
 */
CORTO_EXPORT 
int16_t corto_value_binaryOp(
    corto_operatorKind _operator, 
    corto_value *left, 
    corto_value *right, 
    corto_value *result);

/** Cast a value.
 * @param value A pointer to the value to cast.
 * @param resultType The type to cast to.
 * @param result A corto_value pointer to the result of the cast.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_unaryOp corto_ptr_binaryOp corto_value_memberExpr
 */
CORTO_EXPORT 
int16_t _corto_value_cast(
    corto_value *value,
    corto_type resultType, 
    corto_value *result);

CORTO_EXPORT 
void corto_value_free(
    corto_value *v);

/** Initialize a new corto_value instance.
 * @return A corto_value instance of kind CORTO_VALUE with ptr set to NULL.
 */
CORTO_EXPORT 
corto_value corto_value_empty(void);

/** Initialize a new corto_value instance holding an object.
 * A value representing an object in the corto object store.
 * 
 * @param object A valid object reference.
 * @param type The type of the new corto_value. 
 * The type may be different from the object type, but the object has to be an
 * instance of the specified type.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value _corto_value_object(
    corto_object object, 
    corto_type type);

/** Initialize a new corto_value instance holding a base value.
 * Base corto_value instances express the base value of a value that is of a type
 * that uses inheritance. This kind is typically used by the corto_walk API
 * when serializing the base of a value.
 *
 * Making base a separate kind, allows applications to differentiate between the
 * full value and a base value. Older versions of the walk API used a member kind
 * to express inheritance where the member was set to NULL, but this complicated
 * code and was less intuitive.
 *
 * It is good practice to make the parent field of a BASE corto_value (eventually)
 * point to a value of the CORTO_OBJECT kind for objects, or CORTO_VALUE for non-object
 * values.
 *
 * @param ptr A pointer to a value.
 * @param type The type of the new corto_value. 
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value _corto_value_base(
    void *ptr, 
    corto_type type);

/** Initialize a new corto_value instance holding a generic value.
 * A value representing any value that does not fall in any of the
 * other categories.
 *
 * @param ptr A pointer to a value.
 * @param type The type of the value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value _corto_value_value(
    void *ptr, 
    corto_type t);

/** Initialize a new corto_value instance holding a generic value.
 * Similar to corto_value_value, with the exception that if of a reference type,
 * and encountered by a walk routine, the routine initiates a walk by value instead
 * of invoking the reference callback.
 *
 * Reference values are otherwise only walked by value if of valueKind 
 * CORTO_OBJECT. Reference types mandate that they are instantiated as objects
 * which is consistent with this design.
 *
 * However, in case of the 'ptr' contentType, values are communicated in a 
 * memory representation consistent with objects, but without the overhead of an
 * actual object. To facilitate this usecase, a copy function is needed that can
 * walk over the value of a non-object pointer of a reference type.
 *
 * Value instances of kind CORTO_MEM explicitly do not have an associated object,
 * which is another difference with values of the CORTO_VALUE kind.
 * 
 * Given the exotic nature of this functionality it is recommended that
 * applications avoid it unless they have a keen understanding of what the
 * implications are.
 *
 * @param ptr A pointer to a value.
 * @param type The type of the value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value _corto_value_mem(
    void *ptr, 
    corto_type t);

/** Initialize a new corto_value instance holding a member value.
 * A value used to represent members of composite values.
 *
 * @param object The object containing the member (can be NULL).
 * @param member The member meta object.
 * @param ptr A pointer to the member value.
 * @param type The type of the value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_member(
    corto_object object, 
    corto_member member, 
    void *ptr);

/** Initialize a new corto_value instance holding a constant value.
 * A value used to represent enumeration or bitmask constants. This is typically
 * used by the metawalk API when serializing each constant of a bitmask or 
 * enumeration type.
 *
 * @param object The object containing the constant (can be NULL).
 * @param constant The constant meta object.
 * @param ptr A pointer to the constant value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_constant(
    corto_object object, 
    corto_constant *constant, 
    void *value);

/** Initialize a new corto_value instance holding an element value.
 * A value used to represent elements in a collection value.
 *
 * @param object The object containing the element (can be NULL).
 * @param type The type of the element.
 * @param index The index of the element.
 * @param ptr A pointer to the element value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value _corto_value_element(
    corto_object object, 
    corto_type type, 
    uint32_t index, 
    void *ptr);

/** Initialize a new corto_value instance holding a map element value.
 * A value used to represent map elements in a collection value.
 *
 * @param object The object containing the element (can be NULL).
 * @param type The type of the element.
 * @param keyType The type of the key.
 * @param key The key value
 * @param ptr A pointer to the element value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_mapElement(
    corto_object object, 
    corto_type type, 
    corto_type keyType, 
    void *key, 
    void *ptr);

/** Initialize a new corto_value instance holding a literal.
 * A value used to represent a literal of a scalar type. This function copies the
 * provided value into the corto_value structure.
 *
 * @param kind A literal kind (CORTO_LITERAL_BOOLEAN, CORTO_LITERAL_CHARACTER, CORTO_LITERAL_INTEGER, CORTO_LITERAL_UNSIGNED_INTEGER, CORTO_LITERAL_FLOATING_POINT, CORTO_LITERAL_STRING or CORTO_LITERAL_NULL)
 * @param ptr A pointer to the literal value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_literal(
    corto_literalKind kind, 
    void *ptr);

/** Initialize a new corto_value instance holding a boolean literal.
 * @param value A boolean value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_bool(
    bool value);

/** Initialize a new corto_value instance holding a character literal.
 * @param value A character value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_char(
    corto_char value);

/** Initialize a new corto_value instance holding an unsigned integer literal.
 * @param value An unsigned integer value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_uint(
    corto_uint64 value);

/** Initialize a new corto_value instance holding a signed integer literal.
 * @param value A signed integer value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_int(
    corto_uint64 value);

/** Initialize a new corto_value instance holding a floating point literal.
 * @param value A floating point value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_float(
    corto_float64 value);

/** Initialize a new corto_value instance holding a string literal.
 * This function copies the provided string into the corto_value structure.
 *
 * @param value A string value.
 * @return A new corto_value instance.
 */
CORTO_EXPORT 
corto_value corto_value_string(
    char *value);

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
#define corto_value_mem(v, t) _corto_value_mem(v, corto_type(t))
#define corto_value_element(o, t, i, v) _corto_value_element(o, corto_type(t), i, v)
#define corto_value_mapElement(o, t, kt, k, v) _corto_value_mapElement(o, corto_type(t), corto_type(kt), k, v)
#define corto_value_cast(in, dstType, out) _corto_value_cast(in, corto_type(dstType), out)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_VALUE_H_ */
