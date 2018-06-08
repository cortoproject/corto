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
 * @section field Field API
 * @brief API that resolves fields from values using field expressions. Field
 *        expressions may contain one or more members separated by a dot, and
 *        contain one or more element indices, inside brackets ([]).
 *
 *        An example expression: 'route.waypoints[10].latitude'
 */

#ifndef CORTO_FIELD_H
#define CORTO_FIELD_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_field {
    void *ptr;
    corto_type type;
    corto_member member;
    uint32_t index;
    bool is_super;
} corto_field;

/** Lookup a field.
 */
int16_t _corto_field_lookup(
    const char *field,
    corto_type type,
    void *ptr,
    corto_field *field_out);

/** Lookup a field by index.
 */
int16_t _corto_field_lookup_index(
    uint32_t index,
    corto_collection type,
    void *ptr,
    corto_field *field_out);

#define corto_field_lookup(field, type, ptr, field_out) _corto_field_lookup(field, corto_type(type), ptr, field_out)
#define corto_field_lookup_index(field, type, ptr, field_out) _corto_field_lookup_index(field, corto_collection(type), ptr, field_out)

#ifdef __cplusplus
}
#endif

#endif
