/*
 * corto_err.h
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#ifndef CORE_ERR_H_
#define CORE_ERR_H_

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum corto_err {
    CORTO_THROW = -1,   /* used for internal debugging purposes */
    CORTO_DEBUG = 0,    /* implementation-specific tracing */
    CORTO_TRACE = 1,    /* progress/state of an application */
    CORTO_OK = 2,       /* successful completion of a task */
    CORTO_INFO = 3,     /* neutral message directed at user */
    CORTO_WARNING = 4,  /* issue that does not require immediate action */
    CORTO_ERROR = 5,    /* unsuccessful completion of a task */
    CORTO_CRITICAL = 6, /* task left application in undefined state (abort) */
    CORTO_ASSERT = 7    /* assertion failed (abort) */
} corto_err;

#ifndef NDEBUG
#define corto_assert(condition, ...) if (!(condition)){_corto_assert(condition, "(" #condition ") " __VA_ARGS__);}
#define corto_debug(...) if(corto_err_callbacksRegistered() || corto_verbosityGet() <= CORTO_DEBUG) { _corto_debug(__VA_ARGS__);}
#define corto_trace(...) if(corto_err_callbacksRegistered() ||corto_verbosityGet() <= CORTO_TRACE) { _corto_trace(__VA_ARGS__);}
#define corto_info(...) if(corto_err_callbacksRegistered() ||corto_verbosityGet() <= CORTO_INFO) { _corto_info(__VA_ARGS__);}
#define corto_ok(...) if(corto_err_callbacksRegistered() ||corto_verbosityGet() <= CORTO_OK) { _corto_ok(__VA_ARGS__);}
#else
#define corto_assert(condition, ...) (void)(condition)
#define corto_debug(...)
#define corto_trace(...)
#define corto_info(...)
#define corto_ok(...)
#endif

/* Set verbosity */
CORTO_EXPORT void corto_verbosity(corto_err level);
CORTO_EXPORT corto_err corto_verbosityGet(void);

/* Log errors to console */
CORTO_EXPORT void _corto_assert(unsigned int condition, char* fmt, ...);
CORTO_EXPORT corto_err _corto_debug(char* fmt, ...);
CORTO_EXPORT corto_err _corto_trace(char* fmt, ...);
CORTO_EXPORT corto_err _corto_info(char* fmt, ...);
CORTO_EXPORT corto_err _corto_ok(char* fmt, ...);
CORTO_EXPORT corto_err corto_warning(char* fmt, ...);
CORTO_EXPORT corto_err corto_error(char* fmt, ...);
CORTO_EXPORT void corto_critical(char* fmt, ...);

CORTO_EXPORT void _corto_assertv(unsigned int condition, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_debugv(char* fmt, va_list args);
CORTO_EXPORT corto_err corto_tracev(char* fmt, va_list args);
CORTO_EXPORT corto_err corto_infov(char* fmt, va_list args);
CORTO_EXPORT corto_err corto_okv(char* fmt, va_list args);
CORTO_EXPORT corto_err corto_warningv(char* fmt, va_list args);
CORTO_EXPORT corto_err corto_errorv(char* fmt, va_list args);
CORTO_EXPORT void corto_seterrv(char *fmt, va_list args);
CORTO_EXPORT void corto_criticalv(char* fmt, va_list args);

/* Set error format */
#define CORTO_ERRFMT_DEFAULT "%t - %l: [%a] %c%m"
CORTO_EXPORT void corto_errfmt(char *fmt);

/* Set & get last error */
CORTO_EXPORT char* corto_lasterr(void);
CORTO_EXPORT void corto_seterr(char *fmt, ...);
CORTO_EXPORT int corto_lasterrViewed(void);

/* Set & get last info, useful for when a function wants to communicate info that
 * does not represent an error */
CORTO_EXPORT char* corto_lastinfo(void);
CORTO_EXPORT void corto_setinfo(char *fmt, ...);

/* Register callback that catches log messages */
typedef void* corto_err_callback;
typedef void (*corto_err_callback_callback)(
    corto_err level, 
    char *component[], 
    char *msg, 
    void *ctx);

CORTO_EXPORT corto_err_callback corto_err_callbackRegister(
    corto_err min_level, 
    corto_err max_level,
    corto_string component_filter, // filter in corto_match expr format
    corto_string auth_token,
    corto_err_callback_callback callback,
    void *context);

CORTO_EXPORT void corto_err_callbackUnregister(corto_err_callback callback);
CORTO_EXPORT corto_bool corto_err_callbacksRegistered(void);

/* Get backtraces */
CORTO_EXPORT void corto_printBacktrace(FILE* f, int nEntries, char** symbols);
CORTO_EXPORT void corto_backtrace(FILE* f);
CORTO_EXPORT char* corto_backtraceString(void);

#ifdef __cplusplus
}
#endif

#endif /* CORE_ERR_H_ */
