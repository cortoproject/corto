/*
 * corto_util.h
 *
 *  Created on: Apr 10, 2012
 *      Author: sander
 */

#ifndef CORTO_UTIL_H_
#define CORTO_UTIL_H_

#include "corto/object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Mark variable(parameter) as unused */
#define CORTO_UNUSED(p) (void)p

/* Calculate offset */
#define CORTO_OFFSET(o, offset) (void*)(((uintptr_t)o) + ((uintptr_t)offset))

/* Determine alignment of struct */
#define CORTO_ALIGNMENT(t) ((corto_word)(&((struct {corto_char dummy;t alignMember;}*)(void *)0)->alignMember))

/* Determine offset based on size of type and alignment */
#define CORTO_ALIGN(size,alignment) ((((size-1)/alignment)+1)*alignment)

/* Hash for primitive typekinds. Enables quick lookup of transformations and operators for primitive types. */
#define CORTO_PWIDTH(width) ((width == CORTO_WIDTH_8) ? 0 : (width == CORTO_WIDTH_16) ? 1 : (width == CORTO_WIDTH_32) ? 2 : (width == CORTO_WIDTH_64) ? 3 : -1)
#define CORTO_TYPEHASH_VARWIDTH(kind, width) (kind * (CORTO_FLOAT+1)) + ((int[4]){0, CORTO_FLOAT, CORTO_FLOAT * 2, CORTO_FLOAT * 3}[CORTO_PWIDTH(width)])
#define CORTO_TYPEHASH(kind, width) (kind <= CORTO_FLOAT ? CORTO_TYPEHASH_VARWIDTH(kind, width) : CORTO_TYPEHASH_VARWIDTH(CORTO_FLOAT, CORTO_WIDTH_64) + (kind-CORTO_FLOAT))
#define CORTO_TYPEHASH_MAX (50)

/* 16bit value for convenient matching on scope-characters */
#define CORTO_SCOPE_HEX ((corto_uint16)(0x3A3A)) /* '::' */

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
#define corto_assertType(type, o) _corto_assertType(type, o)
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
#ifdef CORTO_BENCHMARK
CORTO_EXPORT int corto_benchmark_init(corto_string name);
CORTO_EXPORT void corto_benchmark_stop(int id);
CORTO_EXPORT void corto_benchmark_start(int id);
CORTO_EXPORT double corto_benchmark_fini(int id);
#else
#define corto_benchmark_init(name) (0)
#define corto_benchmark_stop(id) ((void)id)
#define corto_benchmark_start(id) ((void)id)
#define corto_benchmark_fini(id) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* CORTO_UTIL_H_ */
