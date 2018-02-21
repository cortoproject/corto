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
#include <corto/platform.h>

/* Types must be included first because builtin packages cross reference */
#include <corto/vstore/_type.h>
#include <corto/lang/_type.h>
#include <corto/secure/_type.h>
#include <corto/native/_type.h>

/* Include main headers from builtin packages */
#include <corto/lang/lang.h>
#include <corto/vstore/vstore.h>
#include <corto/native/native.h>
#include <corto/secure/secure.h>
#include <corto/store/store.h>

#ifdef __cplusplus
extern "C" {
#endif


/* -- GLOBAL VARIABLES -- */

CORTO_EXPORT extern int8_t CORTO_DEBUG_ENABLED;
CORTO_EXPORT extern int8_t CORTO_TRACING_ENABLED;
CORTO_EXPORT extern int8_t CORTO_WARNING_ENABLED;

CORTO_EXPORT extern corto_string CORTO_TRACE_ID;
CORTO_EXPORT extern corto_object CORTO_TRACE_OBJECT;
CORTO_EXPORT extern int8_t CORTO_TRACE_NOTIFICATIONS;
CORTO_EXPORT extern int32_t CORTO_MEMTRACE_BREAKPOINT;

CORTO_EXPORT extern const char* BAKE_VERSION;
CORTO_EXPORT extern const char* BAKE_VERSION_MAJOR;
CORTO_EXPORT extern const char* BAKE_VERSION_MINOR;
CORTO_EXPORT extern const char* BAKE_VERSION_PATCH;
CORTO_EXPORT extern const char* BAKE_VERSION_SUFFIX;

CORTO_EXPORT extern bool CORTO_TRACE_MEM;


/* -- FRAMEWORK FUNCTIONS -- */

/** Start corto
 * This function will initialize the corto object store. Should only be called
 * once per process.
 *
 * @param appName Name of the application. Used in tracing.
 * @return 0 if success, nonzero if failed.
 */
CORTO_EXPORT
int corto_start(
    char *appName);

/** Stop corto
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
void corto_onexit(
    void(*handler)(void*),
    void* userData);


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
bool corto_enableload(
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


/* -- RUNTIME CONSISTENCY CHECKING -- */

/* Used in type checking macro */
CORTO_EXPORT
corto_object _corto_assert_type(
    corto_type type,
    corto_object o);

#ifndef NDEBUG
/* Is pointer a valid object */
CORTO_EXPORT
void _corto_assert_object(
    char const *file,
    unsigned int line,
    corto_object o);
#define corto_assert_object(o) _corto_assert_object(__FILE__, __LINE__, o)
#else
#define corto_assert_object(o)
#endif

#ifndef NDEBUG
/* Is object of specified type */
#define corto_assert_type(type, o) _corto_assert_type((type), (o))
#else
#define corto_assert_type(type, o) (o)
#endif

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
