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

#ifndef CORTO_FMT
#define CORTO_FMT

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_fmt_s *corto_fmt;

typedef struct corto_fmt_opt {
    const char *from;
} corto_fmt_opt;

CORTO_EXPORT
void* corto_fmt_from_value(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_value *v);

CORTO_EXPORT
int16_t corto_fmt_to_value(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_value *v,
    const void *data);

CORTO_EXPORT
void* corto_fmt_from_result(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_result *result);

CORTO_EXPORT
int16_t corto_fmt_to_result(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_result *result,
    const void *data);

CORTO_EXPORT
void* corto_fmt_from_object(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_object object);

CORTO_EXPORT
int16_t corto_fmt_to_object(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_object *object_out,
    const void *data);

CORTO_EXPORT
void* corto_fmt_copy(
    corto_fmt fmt,
    const void *data);

CORTO_EXPORT
void corto_fmt_release(
    corto_fmt fmt,
    void *data);

#ifdef __cplusplus
}
#endif

#endif
