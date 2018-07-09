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
 * @section rw Value Writer
 * @brief Metadata-based writing of data for deserializers
 *
 * This API enforces the rules of the
 * corto typesystem, and offers a consistent way to refer to individual
 * fields inside objects. It is therefore the recommended API for writing
 * (de)serializers and other APIs that interact with object values.
 *
 * The API allows applications to either iterate over fields in a value,
 * or to jump to specific locations. The API provides access to any corto
 * type.
 *
 * Complex (composite/collection) values need to be pushed before they
 * can be accessed. This "opens" the scope of the complex value, which
 * allows iteration over the members/elements in that scope. It also will
 * make field expressions relative to that scope. Pushing/popping scopes
 * is analogous to the `{}` and `[]` operators in cortoscript, as can be
 * seen in this example:
 *
 * `Line l = {start:{x:10, 20}, stop.x:30, stop.y:40}`
 *
 * This cortoscript example is equivalent to the following code:
 *
 ```
 corto_rw rw = corto_rw_init(Line_o, l_o);
 corto_rw_push(&rw);
 corto_rw_field(&rw, "start");
 corto_rw_push(&rw);
 corto_rw_field(&rw, "x");
 corto_rw_set_int(&rw, 10);
 corto_rw_next(&rw);
 corto_rw_set_int(&rw, 20);
 corto_rw_pop(&rw);
 corto_rw_next(&rw);
 corto_rw_field(&rw, "stop.x");
 corto_rw_set_int(&rw, 30);
 corto_rw_next(&rw); // not strictly necessary because the next call is rw_field
 corto_rw_field(&rw, "stop.y");
 corto_rw_set_int(&rw, 40);
 corto_rw_pop(&rw);
 ```
 *
 * Note that this is an UNSTABLE API.
 */

#ifndef CORTO_RW_H
#define CORTO_RW_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_rw_member {
    corto_member member;
} corto_rw_member;

typedef struct corto_rw_scope {
    /* Parent scope  (NULL for root_scope) */
    struct corto_rw_scope *parent;

    /* Type of scope */
    corto_type scope_type;

    /* Base pointer of scope */
    void *scope_ptr;

    /* Base modifiers of scope */
    corto_modifierMask scope_modifiers;

    /* Current field */
    corto_field field;

    /* Member cache (only set when using index in composite types) */
    corto_rw_member *cache;

    /* Maximum index (set when initializing cache or pushing collection type) */
    int32_t max_index;
} corto_rw_scope;

typedef struct corto_rw {
    corto_type rw_type;
    void *rw_ptr;
    corto_rw_scope root_scope;
    corto_rw_scope *current;
} corto_rw;

/** Initialize a reader/writer.
 *
 * @param type The type of the value that is read/written to.
 * @param ptr The pointer to the value that is read/written to.
 * @return An initialized reader/writer value.
 */
CORTO_EXPORT
corto_rw _corto_rw_init(
    corto_type type,
    void *ptr);

/** Deinitialize an reader/writer.
 *
 * @param this The reader/writer.
 */
CORTO_EXPORT
void corto_rw_deinit(
    corto_rw *_this);

/** Move the cursor to next field.
 *
 * This function will move the cursor to the next field. In the case of a
 * composite value, this will be the next member. The member order is
 * established by the order in which members are defined. If modifiers are
 * specified on members, like READONLY or PRIVATE, such members will be skipped.
 *
 * If the current type is a collection type, this will move the reader/writer to
 * the next element in the collection. If the reader/writer hits the end of the
 * collection, and the collection is growable (sequences, lists) a new element
 * will automatically be added to the collection. To use a reader/writer to just
 * walk over existing elements, use this function with `has_next`.
 *
 * When this function is used on composite scopes, it will require a member
 * cache to be initialized once for the current scope.
 *
 * @param this The reader/writer.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_next(
    corto_rw *_this);

/** Check if scope has a field after the cursor.
 *
 * Use this function in combination with `next` to iterate over the existing
 * fields in a reader/writer.
 *
 * When this function is used on composite scopes, it will require a member
 * cache to be initialized once for the current scope.
 *
 * @param this The reader/writer.
 * @return `true` if there is a next field, `false` if not.
 */
CORTO_EXPORT
bool corto_rw_has_next(
    corto_rw *_this);

/** Return number of fields in current scope.
 *
 * This returns the number of fields in the current scope, which in the case of
 * a composite value is the number of accessible members, and in the case of a
 * collection is the number of existing elements.
 *
 * When this function is used on composite scopes, it will require a member
 * cache to be initialized once for the current scope.
 *
 * @param this The reader/writer.
 * @return The number of fields in the current scope.
 */
CORTO_EXPORT
int32_t corto_rw_count(
    corto_rw *_this);

/** Append new element to current scope.
 *
 * This function only applies to collection scopes. After appending, the cursor
 * will be set to the new element.
 *
 * @param this The reader/writer.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_append(
    corto_rw *_this);

/** Move the cursor to the field at specified index.
 *
 * This function moves the cursor to either a member or an element, depending on
 * whether the current scope is of a composite or a collection type.
 *
 * When this function is used on composite scopes, it will require a member
 * cache to be initialized once for the current scope.
 *
 * @param this The reader/writer.
 * @param index The index to which to move the cursor to.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_index(
    corto_rw *_this,
    uint32_t index);

/** Move to field by expression.
 *
 * This function will move the reader/writer to the field as identified by the
 * specified field expression. Field expressions can address both members and
 * elements, and can refer to nested elements. A few examples:
 *
 * - foo
 * - foo.bar
 * - [1]
 * - foo.bar[1]
 *
 * This function does not rely on the internal cursor, and does thus not require
 * a member cache when used in composite scopes. Using this function _will_ move
 * the cursor when the addressed field is in the same scope as the
 * reader/writer, such that when `get_index` is called, it will return the index
 * where the member is located.
 *
 * When a field expression addresses a value in a nested scope (not the current
 * scope) the scope of the reader/writer will not be changed. Instead, the
 * cursor will be invalidated, so that subsequent usage of the cursor will
 * require an explicit action to set the cursor to a defined position.
 *
 * @param this The reader/writer.
 * @param field_expr The expression identifying the field to read/write.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_field(
    corto_rw *_this,
    const char *field_expr);

/** Enter scope of composite / collection field.
 *
 * This will move the scope to the current field, if the current field is a
 * complex (composite / collection) type. Pushing a scope enables the
 * reader/writer to read/write to fields in a complex value.
 *
 * Each scope has its own cursor. After pushing, the cursor for this scope is
 * initialized to 0 (initial position) and all rw API functions will now operte
 * on/relative to this scope.
 *
 * When this function is invoked on a `list` type that is `null`, a new ll
 * object will be assigned to the field.
 *
 * To return to the previous scope, use the `pop` function.
 *
 * @param this The reader/writer.
 * @param as_collection Force the scope to be a collection. Equivalent to [] operator.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_push(
    corto_rw *_this,
    bool as_collection);

/** Leave scope of composite / collection field.
 *
 * This will move the scope back to the parent scope. The cursor
 * of the parent scope does not automatically progress to the next field. To
 * move to the next field, an explicit call to `corto_rw_next` is needed.
 *
 * @param this The reader/writer.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t corto_rw_pop(
    corto_rw *_this);

/** Check if readerwriter is in a pushed scope.
 */
CORTO_EXPORT
bool corto_rw_in_scope(
    corto_rw *_this);

/** Get type of current scope.
 */
CORTO_EXPORT
corto_type corto_rw_get_scope_type(
    corto_rw *_this);

/** Get type of current field.
 */
CORTO_EXPORT
corto_type corto_rw_get_type(
    corto_rw *_this);

/** Get member object of current field.
 */
CORTO_EXPORT
corto_member corto_rw_get_member(
    corto_rw *_this);

/** Get index of current field.
 */
CORTO_EXPORT
int32_t corto_rw_get_index(
    corto_rw *_this);

/** Get pointer of current field.
 */
CORTO_EXPORT
void* corto_rw_get_ptr(
    corto_rw *_this);

/** Set current field to a corto_value.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_value(
    corto_rw *_this,
    corto_value *value);

/** Assign a boolean to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_bool(
    corto_rw *_this,
    bool value);

/** Assign a character to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_char(
    corto_rw *_this,
    char value);

/** Assign an integer to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_int(
    corto_rw *_this,
    int64_t value);

/** Assign an unsigned integer to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_uint(
    corto_rw *_this,
    uint64_t value);

/** Assign a signed integer to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_float(
    corto_rw *_this,
    double value);

/** Assign a string to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_string(
    corto_rw *_this,
    const char *value);

/** Assign a reference to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_ref(
    corto_rw *_this,
    corto_object value);

/** Assign null to the current field.
 */
CORTO_EXPORT
uintptr_t corto_rw_set_null(
    corto_rw *_this);

/** Unset a value (when optional).
 */
CORTO_EXPORT
uintptr_t corto_rw_unset(
    corto_rw *_this);

#define corto_rw_init(type, ptr) _corto_rw_init(corto_type(type), ptr)

#ifdef __cplusplus
}
#endif

#endif
