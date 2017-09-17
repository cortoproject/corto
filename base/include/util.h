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

#ifndef CORTO_UTIL_H_
#define CORTO_UTIL_H_

/* UNSTABLE API */

#ifdef __cplusplus
extern "C" {
#endif

/* Mark variable(parameter) as unused */
#define CORTO_UNUSED(p) (void)(p)

/* Calculate offset */
#define CORTO_OFFSET(o, offset) (void*)(((uintptr_t)(o)) + ((uintptr_t)(offset)))

/* Determine alignment of struct */
#define CORTO_ALIGNMENT(t) ((corto_word)(&((struct {corto_char dummy;t alignMember;}*)(void *)0)->alignMember))

/* Determine offset based on size of type and alignment */
#define CORTO_ALIGN(size, alignment) (((((size) - 1) / (alignment)) + 1) * (alignment))

/* Hash for primitive typekinds. Enables quick lookup of transformations and operators for primitive types. */
#define CORTO_PWIDTH(width) (((width) == CORTO_WIDTH_8) ? 0 : ((width) == CORTO_WIDTH_16) ? 1 : ((width) == CORTO_WIDTH_32) ? 2 : ((width) == CORTO_WIDTH_64) ? 3 : -1)
#define CORTO_TYPEHASH_VARWIDTH(kind, width) ((kind) * (CORTO_FLOAT+1)) + ((int[4]){0, CORTO_FLOAT, CORTO_FLOAT * 2, CORTO_FLOAT * 3}[CORTO_PWIDTH(width)])
#define CORTO_TYPEHASH(kind, width) ((kind) <= CORTO_FLOAT ? CORTO_TYPEHASH_VARWIDTH((kind), (width)) : CORTO_TYPEHASH_VARWIDTH(CORTO_FLOAT, CORTO_WIDTH_64) + ((kind) - CORTO_FLOAT))
#define CORTO_TYPEHASH_MAX (50)

#define CORTO_ISNAN(x) ((x) != (x))

/* Macros for memory allocation functions */
#define corto_calloc(n) calloc(n, 1)
#define corto_alloc(n) malloc(n)
#define corto_dealloc free
#define corto_realloc realloc

/* Benchmarking */
#if 0
CORTO_EXPORT int corto_benchmark_init(char* name);
CORTO_EXPORT void corto_benchmark_stop(int id);
CORTO_EXPORT void corto_benchmark_start(int id);
CORTO_EXPORT double corto_benchmark_fini(int id);
#else
#define corto_benchmark_init(name) (0)
#define corto_benchmark_stop(id) ((void)(id))
#define corto_benchmark_start(id) ((void)(id))
#define corto_benchmark_fini(id) ((void)0)
#endif

/* Set intern TLS string */
CORTO_EXPORT char* corto_setThreadString(char* string);

/* Split path into separate elements. Modifies 'path'. */
int32_t corto_pathToArray(char *path, char *elements[], char *sep);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_UTIL_H_ */
