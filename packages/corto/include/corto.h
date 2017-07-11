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

/** Load a resource.
 * The corto_load function provides a single interface to loading files or 
 * packages into corto. The function accepts any filetype known to corto (types
 * are registered as packages in the corto/ext scope).
 *
 * When a provided resource identifier contains a '.', the string after the '.'
 * is treated as a file extension, and `corto_load` will treat the identifier as
 * a filename. If the identifier contains multiple dots, the last dot will be
 * used to extract the extension.
 *
 * If the identifier contains no dots, `corto_load` will treat the identifier as
 * a logical package name. In this case, `corto_load` will use `corto_locate` to
 * find the package image. Each identifier will only be looked up once, after
 * which the result is cached.
 *
 * The argc and argv parameters can be optionally passed to the resource if the
 * resource type supports it. This is most commonly used for passing parameters
 * to the `cortomain` function of packages.
 *
 * If a resource is found, the handler for the resource type will be executed.
 * This mechanism is used by library loader to invoke the `cortomain` function,
 * but can also involve loading an XML file or executing a corto script,
 * depending on how the resource type is implemented.
 *
 * Resource types are regular packages located in the `corto/ext` scope. They 
 * need to call `corto_load_register` in their `cortomain` function to register
 * the resource type handler, which determines how a resource is loaded.
 *
 * @param identifier The resource identifier (either a file or a package)
 * @param argc The number of arguments to pass to the resource
 * @param argv The arguments to pass to the resource (array must be NULL terminated).
 * @return Zero if success, nonzero if failed.
 * @see corto_locate corto_load_register
 */
CORTO_EXPORT 
int corto_load(
    char *identifier, 
    int argc, 
    char* argv[]);


typedef enum corto_load_locateKind {
    CORTO_LOCATION_ENV,
    CORTO_LOCATION_LIB,
    CORTO_LOCATION_LIBPATH,
    CORTO_LOCATION_INCLUDE,
    CORTO_LOCATION_NAME,
    CORTO_LOCATION_FULLNAME
} corto_load_locateKind;

/** Locate a resource.
 * The `corto_locate` function can be used to locate a package on disk, and to
 * obtain information about the various locations associated with a package.
 * 
 * The function accepts a logical package identifier. Local package identifiers
 * are the same across platforms and are equal to the identifier of the package
 * object once loaded into the corto object store. A package identifier is
 * formatted like any other object identifier, in the form `/foo/bar`. The
 * initial `/` is optional.
 *
 * The function looks in three locations, `$CORTO_HOME`, `$CORTO_TARGET` and
 * the global package repository (`/usr/local` on Linux based systems). From
 * these locations `corto_locate` selects the newest version of the package it can
 * find. It also performs a test to ensure that the package has been compiled
 * with the same corto library.
 *
 * A package is only located once. After the first lookup, the result is cached.
 * That means that if a newer version of a package is installed while applications
 * are running, these applications will have to be restarted to see the new 
 * package if it is in a different location.
 *
 * If the package has already been loaded by `corto_load` or equivalent function,
 * the function returns a pointer to the library object through the `dl_out`
 * parameter.
 *
 * Through the `kind` parameter, the `corto_locate` function can return 
 * information about the environment the package is installed in 
 * (`CORTO_LOCATE_ENV`), the full library path (`CORTO_LOCATE_LIB`), the library
 * path without filename (`CORTO_LOCATE_LIBPATH`), the include path for the
 * package (`CORTO_LOCATE_INCLUDE`), the project name of the package 
 * (`CORTO_LOCATE_NAME`) and the logical name of the package 
 * (`CORTO_LOCATE_FULLNAME`).
 *
 * @param package A logical package name.
 * @param dl_out Will be set to library object, if already loaded.
 * @param kind Specify which information should be obtained from package.
 * @return The requested information. 
 */
CORTO_EXPORT 
char* corto_locate(
    char *package, 
    corto_dl *dl_out, 
    corto_load_locateKind kind);

/** Load a resource from a library.
 * The `corto_load_sym` function looks up a function or global variable from a
 * package. The function takes a logical package identifier which is internally
 * passed to `corto_lookup` to find the corresponding library.
 *
 * If `dl_out` is set to an existing library object, the `package` parameter is
 * ignored and the function will perform a lookup on the library directly. If
 * `dl_out` has no been set, the function will lookup the library, and assign the
 * `dl_out` parameter to the library object, if found. This facilitates doing
 * efficient repeated lookups on the same package, while also allowing for doing
 * lookups on non-package libraries (pass NULL to `package` and specify a
 * library for `dl_out`). 
 *
 * The symbol must point to a global symbol. Different platforms have different
 * rules for which symbols are made visible. If using a corto package, you can
 * use the <package name>_EXPORT macro to make symbols globally visible.
 *
 * @param package A logical package identifier.
 * @param dl_out Cached pointer to library to avoid doing repeated `corto_lookup`'s
 * @param symbol Name of the symbol to lookup.
 */
CORTO_EXPORT 
void* corto_load_sym(
    char *package, 
    corto_dl *dl_out, 
    char *symbol);

/** Register a load action.
 * The `corto_load_register` function registers a load action that needs to be
 * invoked when loading a resource of a specified extension.
 * 
 * To load a file of a specified extension, corto will first look in the 
 * `corto/ext` scope if a package with the extension name can be found. If it
 * has found one, it will load the package library as an ordinary package, which
 * means the `cortomain` will be invoked.
 *
 * In the `cortomain` function, the package should call `corto_load_register` to
 * register the load action with corto for the specific extension. If a package
 * in the `corto/ext` scope did not register the extension after running the
 * `cortomain` function, an error will be thrown.
 *
 * The load action specifies how to load a file of a specific extension. For 
 * example, a library will be loaded with `dlopen` while an XML file will be
 * loaded as text file, and is then parsed with an XML parser.
 *
 * @param ext The extension for which to register the load action.
 * @param action The callback to invoke when loading a file of the specified extension
 * @param userData Data passed to the callback.
 * @return Zero if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_load_register(
    corto_string ext, 
    corto_loadAction action, 
    void* userData);

/* Legacy functions for handling deprecated packages.txt */
CORTO_EXPORT corto_ll corto_loadGetDependencies(corto_string file);
CORTO_EXPORT corto_ll corto_loadGetPackages(void);
CORTO_EXPORT void corto_loadFreePackages(corto_ll packages);
CORTO_EXPORT corto_bool corto_loadRequiresPackage(corto_string package);
CORTO_EXPORT int corto_loadPackages(void);

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
