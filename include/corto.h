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

/** @file
 * @section buffer Corto
 * @brief Generic corto store functions.
 */

#ifndef CORTO_H
#define CORTO_H

/* $header() */
#include <corto/base.h>

#include <corto/lang/lang.h>
#include <corto/vstore/vstore.h>
#include <corto/native/native.h>
#include <corto/secure/secure.h>

/* Callback used to walk contents of scope */
typedef int (*corto_scopeWalk_cb)(corto_object o, void* userData);

#include <corto/util.h>
#include <corto/entityadmin.h>
#include <corto/rb.h>

#include <corto/store/store.h>
#include <corto/vstore/vstore.h>

#ifdef __cplusplus
extern "C" {
#endif

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

/** Mount package data
 * The package loader mounts corto packages into the corto hierarchy so they can
 * be discovered with corto_select and resolved with corto_lookup and
 * corto_resolve.
 *
 * @param enable Specifiies whether to enable mounting package data.
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

/** Get a unique string that identifies the current corto build.
 * This function is used to determine whether a package is linked with the
 * correct corto library before allowing it to be loaded.
 *
 * @return String that uniquely identifies the current corto build
 */
CORTO_EXPORT
char* corto_getBuild(void);

/** Get filename of corto library that current process links with.
 * This function can be used to debug scenarios in which a package has a corto
 * build that does not match the build of the application.
 *
 * @return path + filename of the corto library that the application links with.
 */
CORTO_EXPORT
char* corto_getLibrary(void);

/** Specify function to be executed when corto exits.
 *
 * @param handler Pointer to function to be executed.
 */
CORTO_EXPORT
void corto_onexit(
    void(*handler)(void*), void* userData);

/* ffi_call compatible signature */
typedef void (*corto_callInvoke)(void *fdata, void *fptr, corto_void *rvalue, void **args);

typedef corto_int16 ___ (*corto_callInit_f)(corto_function f);
typedef void (*corto_callDeinit_f)(corto_function f);

/* Call API */
CORTO_EXPORT void _corto_call(corto_function f, corto_void* result, ...);
CORTO_EXPORT void _corto_callv(corto_function f, corto_void* result, va_list args);
CORTO_EXPORT void _corto_callb(corto_function f, corto_void* result, void** argptrs);

/* Register binding */
CORTO_EXPORT int corto_callRegister(corto_callInit_f init, corto_callDeinit_f deinit);
CORTO_EXPORT int16_t corto_callInit(corto_function f);
CORTO_EXPORT void corto_callDeinit(corto_function f);

#define corto_call(f, ...) _corto_call(corto_function(f), __VA_ARGS__)
#define corto_callv(f, result, args) _corto_callv(corto_function(f), result, args)
#define corto_callb(f, result, argptrs) _corto_callb(corto_function(f), result, argptrs)

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

CORTO_EXPORT extern int8_t CORTO_DEBUG_ENABLED;
CORTO_EXPORT extern int8_t CORTO_TRACING_ENABLED;
CORTO_EXPORT extern int8_t CORTO_WARNING_ENABLED;

CORTO_EXPORT extern corto_string CORTO_TRACE_ID;
CORTO_EXPORT extern corto_object CORTO_TRACE_OBJECT;
CORTO_EXPORT extern int8_t CORTO_TRACE_NOTIFICATIONS;
CORTO_EXPORT extern int32_t CORTO_MEMTRACE_BREAKPOINT;

CORTO_EXPORT extern const char* CORTO_VERSION;
CORTO_EXPORT extern const char* CORTO_VERSION_MAJOR;
CORTO_EXPORT extern const char* CORTO_VERSION_MINOR;
CORTO_EXPORT extern const char* CORTO_VERSION_PATCH;
CORTO_EXPORT extern const char* CORTO_VERSION_SUFFIX;

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
