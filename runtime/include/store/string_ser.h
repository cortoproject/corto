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

#ifndef CORTO_STRING_SER_H_
#define CORTO_STRING_SER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct corto_string_ser_t {
    /* Public */
    corto_buffer buffer;
    corto_bool prefixType;
    corto_bool enableColors;

    /* Private */
    char* ptr;
    unsigned int itemCount;
    corto_bool compactNotation;
    corto_ll anonymousObjects;
} corto_string_ser_t;

CORTO_EXPORT corto_walk_opt corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_STRING_SER_H_ */
