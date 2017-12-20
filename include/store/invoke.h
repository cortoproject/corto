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
 * @section invoke Invoke corto functions.
 * @brief Invoke corto functions.
 */

#ifndef CORTO_INVOKE_H
#define CORTO_INVOKE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ffi_call compatible signature */
typedef
void (*corto_invokeInvoke)(
    void *fdata,
    void *fptr,
    corto_void *rvalue,
    void **args);

typedef
corto_int16 ___ (*corto_invoke_init_f)(
    corto_function f);

typedef
void (*corto_invoke_deinit_f)(
    corto_function f);

/* Call API */
CORTO_EXPORT
void _corto_invoke(
    corto_function f,
    corto_void* result, ...);

CORTO_EXPORT
void _corto_invokev(
    corto_function f,
    corto_void* result,
    va_list args);

CORTO_EXPORT
void _corto_invokeb(
    corto_function f,
    corto_void* result,
    void** argptrs);

/* Register binding */
CORTO_EXPORT
int corto_invoke_register(
    corto_invoke_init_f init,
    corto_invoke_deinit_f deinit);

CORTO_EXPORT
int16_t corto_invoke_init(
    corto_function f);

CORTO_EXPORT
void corto_invoke_deinit(
    corto_function f);

#define corto_invoke(f, ...) _corto_invoke(corto_function(f), __VA_ARGS__)
#define corto_invokev(f, result, args) _corto_invokev(corto_function(f), result, args)
#define corto_invokeb(f, result, argptrs) _corto_invokeb(corto_function(f), result, argptrs)

#ifdef __cplusplus
}
#endif

#endif
