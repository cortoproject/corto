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
 * @section rw Reader/writer API
 * @brief API that dynamically reads/writes values without requiring compile
 *        time knowledge of the object type. The API enforces the rules of the
 *        corto typesystem, and offers a consistent way to refer to individual
 *        fields inside objects. It is therefore the recommended API for writing
 *        (de)serializers and other APIs that interact with object values.
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

    /* Index of current value (changes when setting or progressing index) */
    int32_t index;

    /* Member and pointer of current value (changes when setting field) */
    corto_member member;

    /* Pointer to current value (changes when setting index or field) */
    void *ptr;

    /* Member cache (only set when using index in composite types) */
    corto_rw_member *cache;

    /* Maximum index (set when initializing cache or pushing collection type) */
    uint32_t max_index;
} corto_rw_scope;

typedef struct corto_rw {
    corto_type rw_type;
    void *rw_ptr;
    corto_rw_scope root_scope;
    corto_rw_scope *current;
} corto_rw;

/** Initialize a writer.
 */
CORTO_EXPORT
corto_rw _corto_rw_init(
    corto_type type,
    void *ptr);

/** Deinitialize an writer.
 */
CORTO_EXPORT
void corto_rw_deinit(
    corto_rw *_this);

/** Move to next field.
 */
CORTO_EXPORT
int16_t corto_rw_next(
    corto_rw *_this);

/** Check if scope has next field.
 */
CORTO_EXPORT
bool corto_rw_has_next(
    corto_rw *_this);

/** Return number of fields in current scope.
 */
CORTO_EXPORT
int32_t corto_rw_count(
    corto_rw *_this);

/** Append new element to current scope.
 */
CORTO_EXPORT
int16_t corto_rw_append(
    corto_rw *_this);

/** Move to field at specified index.
 */
CORTO_EXPORT
int16_t corto_rw_index(
    corto_rw *_this,
    uint32_t index);

/** Move to field by expression.
 */
CORTO_EXPORT
int16_t corto_rw_field(
    corto_rw *_this,
    const char *field_expr);

/** Enter scope of composite / collection field.
 */
CORTO_EXPORT
int16_t corto_rw_push(
    corto_rw *_this,
    bool as_collection);

/** Leave scope of composite / collection field.
 */
CORTO_EXPORT
int16_t corto_rw_pop(
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
uintptr_t corto_rw_set(
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

#define corto_rw_init(type, ptr) _corto_rw_init(corto_type(type), ptr)

#ifdef __cplusplus
}
#endif

#endif
