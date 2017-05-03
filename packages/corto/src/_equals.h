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

#ifndef CORTO__EQUALS_H_
#define CORTO__EQUALS_H_

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_equalityKind corto_any_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_object_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_octet_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_bool_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_char_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint8_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint16_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_uint64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int8_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int16_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_int64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_float32_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_float64_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_word_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_constant_equals(corto_any value1, corto_any value2);
corto_equalityKind corto_string_equals(corto_any value1, corto_any value2);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__EQUALS_H_ */
