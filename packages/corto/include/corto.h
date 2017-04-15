/* corto.h
 *
 * This file is generated. Do not modify.
 */

#ifndef CORTO_H
#define CORTO_H

/* $header() */
#include <corto/lang/lang.h>
#include <corto/core/core.h>
#include <corto/native/native.h>
#include <corto/secure/secure.h>

#include <corto/async.h>
#include <corto/buffer.h>
#include <corto/call.h>
#include <corto/compare_ser.h>
#include <corto/convert.h>
#include <corto/copy_ser.h>
#include <corto/depresolver.h>
#include <corto/dl.h>
#include <corto/env.h>
#include <corto/err.h>
#include <corto/file.h>
#include <corto/init_ser.h>
#include <corto/loader.h>
#include <corto/iter.h>
#include <corto/ll.h>
#include <corto/loader.h>
#include <corto/mem.h>
#include <corto/memory_ser.h>
#include <corto/metawalk.h>
#include <corto/mm.h>
#include <corto/object.h>
#include <corto/operator.h>
#include <corto/os.h>
#include <corto/overload.h>
#include <corto/platform.h>
#include <corto/rbtree.h>
#include <corto/serializer.h>
#include <corto/string.h>
#include <corto/string_deser.h>
#include <corto/string_ser.h>
#include <corto/string.h>
#include <corto/time.h>
#include <corto/util.h>
#include <corto/value.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT int corto_start(char *appName);
CORTO_EXPORT int corto_stop(void);
CORTO_EXPORT corto_bool corto_enableload(corto_bool enable);
CORTO_EXPORT void corto_autoload(corto_bool autoload);
CORTO_EXPORT corto_string corto_getBuild(void);
CORTO_EXPORT corto_string corto_getLibrary(void);
CORTO_EXPORT corto_bool corto_isbuiltin(corto_object o);
CORTO_EXPORT void corto_onunload(void(*handler)(void*), void* userData);
CORTO_EXPORT void corto_onexit(void(*handler)(void*), void* userData);

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
