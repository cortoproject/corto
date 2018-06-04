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
 * @section initializer Initializer API
 * @brief API that determines order of members in initializer and enforces
 *        typesystem modifiers like READONLY and PRIVATE. The API is also
 *        capable of assigning values to the currently selected member.
 */

#ifndef CORTO_INITIALIZER_H
#define CORTO_INITIALIZER_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_initializer_member {
    corto_member member;
} corto_initializer_member;

typedef struct corto_initializer_scope {
    /* Parent scope  (NULL for root_scope) */
    struct corto_initializer_scope *parent;

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
    corto_initializer_member *cache;

    /* Maximum index (set when initializing cache or pushing collection type) */
    uint32_t max_index;
} corto_initializer_scope;

typedef struct corto_initializer {
    corto_type initializer_type;
    void *initializer_ptr;
    corto_initializer_scope root_scope;
    corto_initializer_scope *current;
} corto_initializer;

/** Returns a new initializer.
 */
CORTO_EXPORT
corto_initializer _corto_initializer_init(
    corto_type type,
    void *ptr);

/** Deinitialize an initializer.
 */
CORTO_EXPORT
void corto_initializer_deinit(
    corto_initializer *_this);

/** Move to next member.
 */
CORTO_EXPORT
int16_t corto_initializer_next(
    corto_initializer *_this);

/** Check if scope has next member.
 */
CORTO_EXPORT
bool corto_initializer_has_next(
    corto_initializer *_this);

/** Move to index.
 */
CORTO_EXPORT
int16_t corto_initializer_index(
    corto_initializer *_this,
    uint32_t index);

/** Move to member by field expression.
 */
CORTO_EXPORT
int16_t corto_initializer_field(
    corto_initializer *_this,
    const char *field_expr);

/** Push scope of complex type (composite or collection).
 */
CORTO_EXPORT
int16_t corto_initializer_push(
    corto_initializer *_this,
    bool as_collection);

/** Pop scope.
 */
CORTO_EXPORT
int16_t corto_initializer_pop(
    corto_initializer *_this);

/** Get current scope type.
 */
CORTO_EXPORT
corto_type corto_initializer_get_scope_type(
    corto_initializer *_this);

/** Get current type.
 */
CORTO_EXPORT
corto_type corto_initializer_get_type(
    corto_initializer *_this);

/** Get current member.
 */
CORTO_EXPORT
corto_member corto_initializer_get_member(
    corto_initializer *_this);

/** Get current index.
 */
CORTO_EXPORT
int32_t corto_initializer_get_index(
    corto_initializer *_this);

/** Get current offset.
 */
CORTO_EXPORT
void* corto_initializer_get_ptr(
    corto_initializer *_this);

/** Set current member.
 */
CORTO_EXPORT
uintptr_t corto_initializer_set(
    corto_initializer *_this,
    corto_value value);


#define corto_initializer_init(type, ptr) _corto_initializer_init(corto_type(type), ptr)

#ifdef __cplusplus
}
#endif

#endif
