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
 * @section buffer Corto
 * @brief Generic corto functions.
 */

#ifndef CORTO_H
#define CORTO_H

/* $header() */

/* Generic functionality (os abstraction, lockless admin) */
#include "prebaked.h"

/* Types must be included first because builtin packages cross reference */
#include "vstore/_type.h"
#include "lang/_type.h"
#include "secure/_type.h"
#include "native/_type.h"

/* Standard C library */
#include <alloca.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* OS-specific headers */
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#include <fnmatch.h>
#include <inttypes.h>
#include <execinfo.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <ftw.h>
#include <fcntl.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif
#endif

#ifndef NDEBUG
#define CORTO_MAGIC (0x6B6F7274)
#define CORTO_MAGIC_DESTRUCT (0x74726F6B)
#endif

/*
 * Configuration parameters
 *   Increasing these numbers will increase memory usage of Corto in various
 *   scenario's.
 */

/* The maximum nesting level of objects in the hierarchy. There are in total
 * 62 orders of magnitude in the universe, so 64 should be adequate to organize
 * most information sets.
 */
#define CORTO_MAX_SCOPE_DEPTH (64)

/* The maximum inheritance depth. Think 16 is too small? The Java world record
 * is set at 12 levels of inheritance:
 * http://www.javaspecialists.eu/records/index.jsp
 *
 * Please don't use 16 levels of inheritance.
 */
#define CORTO_MAX_INHERITANCE_DEPTH (16)

/* The maximum number of languages you can construct to a single Corto process. */
#define CORTO_MAX_BINDINGS (16)

/* The maximum number of threads that can make use of the Corto
 * API simultaneously. */
#define CORTO_MAX_THREADS (64)

/* The maximum number of nested notifications. */
#define CORTO_MAX_NOTIFY_DEPTH (16)

/* The max length of a scoped identifier (incl \0). When combining this with the
 * MAX_SCOPE_DEPTH, and taking into consideration the scope separator (/) you
 * can have a tree that is 64 levels deep, where each object has a 7-character
 * name, and one object with 6, to compensate for \0. Or, you can have an object
 * in the root with a 510 character name with no children. */
#define CORTO_MAX_PATH_LENGTH (512)

/* The maximum number of objects that a thread can wait for simultaneously */
#define CORTO_MAX_WAIT_FOR_OBJECTS (32)

/* Corto can't load files with extensions longer than 16 characters */
#define CORTO_MAX_FILE_EXTENSION (16)

/* Maximum number of OLS extensions that is supported by the core */
#define CORTO_MAX_OLS_KEY (256)

/* Maximum number of TLS keys that is supported by the core */
#define CORTO_MAX_THREAD_KEY (256)

/* The maximum number of arguments that can be passed to the Corto arg parser */
#define CORTO_ARG_MAX (256)

/* The maximum number of TLS strings that can exist simultaneously */
#define CORTO_MAX_TLS_STRINGS (5)

/* Maximum retained buffer length for TLS string. This ensures that when a very
 * large string is stored in TLS, it will be cleaned up eventually. Keeping it
 * around would be wasteful since chances are low that a string of similar
 * length will take advantage of the memory. */
#define CORTO_MAX_TLS_STRINGS_MAX (1024)

/* Maximum number of arguments for command */
#define CORTO_MAX_CMD_ARGS (256)

/* Maximum number of operations in an id expression */
#define CORTO_MATCHER_MAX_OP (32)

/* Maximum number of content types in a process */
#define CORTO_MAX_CONTENTTYPE (32)

/* Maximum number of simultaneous benchmarks */
#define CORTO_MAX_BENCHMARK (64)

/* Maximum number of categories in logmsg, like: "comp1: comp2: comp3: msg" */
#define CORTO_MAX_LOG_CATEGORIES (24)

/* Maximum number of code frames in logmsg */
#define CORTO_MAX_LOG_CODEFRAMES (16)

typedef char corto_id[CORTO_MAX_PATH_LENGTH];

/* Builtin procedure kinds */
#define CORTO_PROCEDURE_STUB (0)
#define CORTO_PROCEDURE_CDECL (1)

/* C language binding type definition macro's */
#define CORTO_ANY(__type) typedef struct __type {corto_type type; void *value; uint8_t owner;} __type
#define CORTO_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define CORTO_SEQUENCE_EMPTY(type) (type){0}

/* Macro's used to prevent type checking macro's from expanding */
#define ___

/* Macro used to annotate parameters in bootstrap.h */
#define _(txt)

/* Corto string representing null */
#define CORTO_NULL_STRING ("null")

/* Include main headers from builtin packages */
#include "lang/lang.h"
#include "vstore/vstore.h"
#include "native/native.h"
#include "secure/secure.h"
#include "store/store.h"

#ifdef __cplusplus
extern "C" {
#endif


/* -- GLOBAL VARIABLES -- */
CORTO_EXPORT extern const char* BAKE_VERSION;
CORTO_EXPORT extern const char* BAKE_VERSION_MAJOR;
CORTO_EXPORT extern const char* BAKE_VERSION_MINOR;
CORTO_EXPORT extern const char* BAKE_VERSION_PATCH;
CORTO_EXPORT extern const char* BAKE_VERSION_SUFFIX;

CORTO_EXPORT extern bool CORTO_TRACE_MEM;
CORTO_EXPORT extern bool CORTO_COLLECT_CYCLES;
CORTO_EXPORT extern bool CORTO_COLLECT_TLS;

/* -- FRAMEWORK FUNCTIONS -- */

/** Start corto.
 * This function will initialize the corto object store. Should only be called
 * once per process.
 *
 * @param appName Name of the application. Used in tracing.
 * @return 0 if success, nonzero if failed.
 */
CORTO_EXPORT
int corto_start(
    char *appName);

/** Stop corto.
 * This function deinitializes the corto object store. Should only be called once
 * per process, and after corto_start.
 */
CORTO_EXPORT
int corto_stop(void);

/** Load configuration.
 * This function loads configuration from the path configured in $CORTO_CONFIG
 * if this environment variable is set.
 */
CORTO_EXPORT
int corto_load_config(void);

/** Get a unique string that identifies the current corto build.
 * This function is used to determine whether a package is linked with the
 * correct corto library before allowing it to be loaded.
 *
 * @return String that uniquely identifies the current corto build
 */
CORTO_EXPORT
char* corto_get_build(void);

/** Specify function to be executed when corto exits.
 *
 * @param handler Pointer to function to be executed.
 */
CORTO_EXPORT
void corto_atexit(
    void(*handler)(void*),
    void* userData);


/* -- SECURITY -- */


/** Enable or disable security.
 * This function enables or disables corto security. When no instance of
 * corto/secure/key instance has been created this function does nothing.
 *
 * By default security is disabled, even after creation of a lock. The reason
 * for this is that a lock is typically created during loading of configuration
 * and other configuration items may be loaded after it.
 *
 * If the lock would be effective immediately after creating it, it could
 * prevent other configuration items from loading successfully, as they most
 * likely rely on data to which access will be restricted by the lock.
 *
 * @param enable Specifies whether to enable security.
 * @return true if security has been enabled, false if failed. The function will
 *         fail of no instance of corto/secure/key has been created.
 */
 CORTO_EXPORT
 bool corto_enable_security(
     bool enabled);


/* -- AUTOMATIC PACKAGE LOADING -- */

/** Mount package data
 * The package loader mounts corto packages into the corto hierarchy so they can
 * be discovered with corto_select and resolved with corto_lookup and
 * corto_resolve.
 *
 * @param enable Specifies whether to enable mounting package data.
 * @return Previous value.
 */
CORTO_EXPORT
bool corto_enable_load(
    corto_bool enable);

/** Enable automatic loading of packages
 * When enabled, an application that is requesting objects from a package will
 * trigger the package to be loaded into corto automatically.
 *
 * @param autoload Specifies whether to enable automatic package loading.
 * @return Previous value.
 */
CORTO_EXPORT
bool corto_autoload(
    corto_bool autoload);

/** Utility to generate random id */
CORTO_EXPORT
char* corto_random_id(
    uint16_t n);

/* -- RUNTIME CONSISTENCY CHECKING -- */

/* Used in type checking macro */
CORTO_EXPORT
corto_object _ut_assert_type(
    corto_type type,
    corto_object o);

    /* Is pointer a valid object */
#ifndef NDEBUG
CORTO_EXPORT
corto_object _ut_assert_object(
    char const *file,
    unsigned int line,
    corto_object o);
#define ut_assert_object(o) _ut_assert_object(__FILE__, __LINE__, o)
#else
#define ut_assert_object(o) o
#endif

/* Is object of specified type */
#ifndef NDEBUG
#define ut_assert_type(type, o) _ut_assert_type((type), (o))
#else
#define ut_assert_type(type, o) (o)
#endif

/* Mark variable(parameter) as unused */
#define CORTO_UNUSED(p) (void)(p)

/* Calculate offset */
#define CORTO_OFFSET(o, offset) (void*)(((uintptr_t)(o)) + ((uintptr_t)(offset)))

/* Determine alignment of struct */
#define CORTO_ALIGNMENT(t) ((uintptr_t)(&((struct {corto_char dummy;t alignMember;}*)(void *)0)->alignMember))

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

/* Set intern TLS string */
CORTO_EXPORT char* ut_setThreadString(char* string);

CORTO_EXPORT char* corto_itoa(int num, char* buff);
CORTO_EXPORT char* corto_ulltoa(uint64_t value, char *ptr, int base);

#ifdef __cplusplus
}
#endif
/* $end */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif
