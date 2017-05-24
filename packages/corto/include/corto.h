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

#ifndef CORTO_H
#define CORTO_H

/* $header() */
#include <corto/base.h>

#include <corto/lang/lang.h>
#include <corto/core/core.h>
#include <corto/native/native.h>
#include <corto/secure/secure.h>

/* Callback used to determine if value is smaller/larger/equal */
typedef corto_equalityKind ___ (*corto_equals_cb)(corto_type _this, const void* o1, const void* o2);
/* Callback used to copy value */
typedef void* ___ (*corto_duplicate_cb)(corto_type _this, const void* o1);
/* Callback used to release value */
typedef void ___ (*corto_release_cb)(corto_type _this, void* o1);

/* Callback used to walk contents of scope */
typedef int (*corto_scopeWalk_cb)(corto_object o, void* userData);

#include <corto/iter.h>
#include <corto/ll.h>
#include <corto/rb.h>
#include <corto/value.h>
#include <corto/walk.h>
#include <corto/os.h>
#include <corto/err.h>
#include <corto/buffer.h>
#include <corto/depresolver.h>
#include <corto/object.h>
#include <corto/ptr.h>
#include <corto/query.h>
#include <corto/string_deser.h>
#include <corto/string_ser.h>
#include <corto/util.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT int corto_start(char *appName);
CORTO_EXPORT int corto_stop(void);
CORTO_EXPORT bool corto_enableload(corto_bool enable);
CORTO_EXPORT bool corto_autoload(corto_bool autoload);
CORTO_EXPORT corto_string corto_getBuild(void);
CORTO_EXPORT corto_string corto_getLibrary(void);
CORTO_EXPORT corto_bool corto_isbuiltin(corto_object o);
CORTO_EXPORT void corto_onunload(void(*handler)(void*), void* userData);
CORTO_EXPORT void corto_onexit(void(*handler)(void*), void* userData);

typedef int (*corto_loadAction)(corto_string file, int argc, char* argv[], void* userData);

/* Load a package */
CORTO_EXPORT int corto_load(corto_string package, int argc, char* argv[]);

/* Load from a dynamic library */
CORTO_EXPORT corto_dl corto_loadValidLibrary(corto_string fileName, corto_string *build_out);
CORTO_EXPORT int corto_loadFromDl(corto_dl dl, char *fileName, int argc, char *argv[]);

/* Try loading a package (doesn't generate errors when not found) */
CORTO_EXPORT int corto_loadTry(corto_string str, int argc, char* argv[]);

CORTO_EXPORT corto_ll corto_loadGetDependencies(corto_string file);
CORTO_EXPORT corto_ll corto_loadGetPackages(void);
CORTO_EXPORT void corto_loadFreePackages(corto_ll packages);
CORTO_EXPORT corto_bool corto_loadRequiresPackage(corto_string package);
CORTO_EXPORT int corto_loadPackages(void);

CORTO_EXPORT int corto_loaderRegister(corto_string ext, corto_loadAction handler, void* userData);

CORTO_EXPORT void (*corto_loaderResolveProc(corto_string procName))(void);

typedef enum corto_loaderLocationKind {
    CORTO_LOCATION_ENV,
    CORTO_LOCATION_LIB,
    CORTO_LOCATION_LIBPATH,
    CORTO_LOCATION_INCLUDE,
    CORTO_LOCATION_NAME,
    CORTO_LOCATION_FULLNAME
} corto_loaderLocationKind;

CORTO_EXPORT corto_string corto_locate(corto_string package, corto_dl *dl_out, corto_loaderLocationKind kind);

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

CORTO_EXPORT extern int8_t CORTO_OPERATIONAL;
CORTO_EXPORT extern int8_t CORTO_DEBUG_ENABLED;
CORTO_EXPORT extern int8_t CORTO_TRACING_ENABLED;
CORTO_EXPORT extern int8_t CORTO_WARNING_ENABLED;

CORTO_EXPORT extern corto_string CORTO_TRACE_ID;
CORTO_EXPORT extern corto_object CORTO_TRACE_OBJECT;
CORTO_EXPORT extern int8_t CORTO_TRACE_NOTIFICATIONS;
CORTO_EXPORT extern int8_t CORTO_BACKTRACE_ENABLED;
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
