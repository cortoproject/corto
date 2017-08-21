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

/* In place replacelemt of '::' with '/' */
CORTO_EXPORT corto_string corto_pathFromFullname(corto_id buffer);

/* Strip parent identifiers from fullname */
CORTO_EXPORT corto_string corto_nameFromFullname(corto_id buffer);

/* Set intern TLS string */
CORTO_EXPORT corto_string corto_setThreadString(corto_string string);

/* Check if object is a builtin package */
CORTO_EXPORT corto_bool corto_isBuiltinPackage(corto_object o);

/* Check if object is a builtin object */
CORTO_EXPORT corto_bool corto_isBuiltin(corto_object o);

/* Used in type checking macro */
CORTO_EXPORT corto_object _corto_assertType(corto_type type, corto_object o);
#ifndef NDEBUG
#define corto_assertType(type, o) _corto_assertType((type), (o))
#else
#define corto_assertType(type, o) (o)
#endif

/* Throws an assertion when invalid object in debugging */
#ifndef NDEBUG
CORTO_EXPORT void corto_assertObject(corto_object o);
#else
#define corto_assertObject(o)
#endif

/* Obtain documentation objects */
CORTO_EXPORT char* corto_manId(corto_object o, corto_id buffer);
CORTO_EXPORT corto_object corto_man(corto_object o);

/* Obtain pointer and type for deserializing member */
CORTO_EXPORT void* corto_getMemberPtr(corto_object o, void *ptr, corto_member m);

/* Benchmarking */
#if 0
CORTO_EXPORT int corto_benchmark_init(corto_string name);
CORTO_EXPORT void corto_benchmark_stop(int id);
CORTO_EXPORT void corto_benchmark_start(int id);
CORTO_EXPORT double corto_benchmark_fini(int id);
#else
#define corto_benchmark_init(name) (0)
#define corto_benchmark_stop(id) ((void)(id))
#define corto_benchmark_start(id) ((void)(id))
#define corto_benchmark_fini(id) ((void)0)
#endif

/* Overload utility functions */

/* Parameter kinds */
#define CORTO_PARAMETER_REFERENCE          (1)
#define CORTO_PARAMETER_FORCEREFERENCE     (2)
#define CORTO_PARAMETER_WILDCARD           (4)
#define CORTO_PARAMETER_NULL               (8)
#define CORTO_PARAMETER_IN                 (16)
#define CORTO_PARAMETER_OUT                (32)

/* Special distance values for corto_overload */
#define CORTO_OVERLOAD_ERROR               (-1)
#define CORTO_OVERLOAD_NOMATCH             (-2)
#define CORTO_OVERLOAD_NOMATCH_OVERLOAD    (-3)

/* Calculate the distance between a function and a request signature */
CORTO_EXPORT int16_t corto_overload(corto_object object, corto_string name, corto_int32* distance);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */
CORTO_EXPORT corto_int32 corto_signatureName(corto_string signature, corto_id buffer);
CORTO_EXPORT corto_int32 corto_signatureParamCount(corto_string signature);
CORTO_EXPORT corto_int32 corto_signatureParamName(corto_string signature, corto_uint32 id, corto_id buffer);
CORTO_EXPORT corto_int32 corto_signatureParamType(corto_string signature, corto_uint32 id, corto_id buffer, int* reference);

/* Create request signature */
CORTO_EXPORT corto_string corto_signatureOpen(corto_string name);
CORTO_EXPORT corto_string corto_signatureAdd(corto_string sig, corto_type type, int flags);
CORTO_EXPORT corto_string corto_signatureAddWildcard(corto_string sig, corto_bool isReference);
CORTO_EXPORT corto_string corto_signatureClose(corto_string sig);

/* Obtain signature from object */
CORTO_EXPORT char* corto_signature(corto_object o, corto_id buffer);

/* Find a function that matches a signature */
CORTO_EXPORT corto_object corto_lookupFunction(corto_object scope, corto_string requested, corto_int32 *d, corto_int32 *diff);
CORTO_EXPORT corto_object *corto_lookupFunctionFromSequence(corto_objectseq scopeContents, corto_string requested, corto_int32* d, corto_int32 *diff);

/* String utility functions */
/* Case insensitive string compare */
CORTO_EXPORT int stricmp(const char *str1, const char *str2);
CORTO_EXPORT int strnicmp(const char *str1, int length, const char *str2);

/* Compare case insensitive token */
CORTO_EXPORT int tokicmp(char ** const str_out, const char *str2, char tok);

/* Case insensitive string compare, stop at / instead of \0. Returns next
 * element, NULL when no match or "\0" when reached the end */
CORTO_EXPORT char* corto_elemcmp(char *path, char *elem);

/* Search element separator in id string. Stop when argument list is found. */
char *corto_strelem(char *str);

/* Convert characters in string to uppercase */
CORTO_EXPORT char* corto_strupper(char *str);

/* Convert characters in string to lowercase */
CORTO_EXPORT char* corto_strlower(char *str);

CORTO_EXPORT char *strappend(char *src, char *fmt, ...);
CORTO_EXPORT char *itostr(int value, char *result, int base);
CORTO_EXPORT char *utostr(unsigned int value, char *result, int base);

/*
 * Escapes a character `in` and prints it to `out`. Does not not include
 * surrounding single quotes.
 * Returns the next available location to write, usually out+1 or out+2.
 */
CORTO_EXPORT char *chresc(char *out, char in, char delimiter);

/*
 * Escapes a null-terminated string `in` and attempts to print it to `out`.
 * Does not include surrounding double quotes.
 * The maximum number of characters to be printed is `n` including the null
 * character, but it may be less if the following character requires escaping.
 * The resulting string is null terminated.
 */
CORTO_EXPORT size_t stresc(char *out, size_t n, const char *in);

/* Count the number of characters in a string that do not match a provided
 * mask. */
CORTO_EXPORT size_t strmask(char *str, char *mask);

/* Duplicate string */
CORTO_EXPORT char* corto_strdup(const char* str);

/* sprintf with automatic allocation */
CORTO_EXPORT int corto_asprintf (char **str, const char *fmt, ...);
CORTO_EXPORT int corto_vasprintf (char **str, const char *fmt, va_list args);

/* Replace substring in string */
CORTO_EXPORT char* corto_replace(char *s, char *old, char *_new);

/* Is object a builtin object */
CORTO_EXPORT corto_bool corto_isbuiltin(corto_object o);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_UTIL_H_ */
