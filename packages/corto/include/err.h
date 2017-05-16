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

#ifndef CORE_ERR_H_
#define CORE_ERR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define corto_critical(...) _corto_critical(__FILE__, __LINE__, __VA_ARGS__);
#define corto_error(...) _corto_error(__FILE__, __LINE__, __VA_ARGS__);
#define corto_warning(...) _corto_warning(__FILE__, __LINE__, __VA_ARGS__);

#define corto_error_fl(f, l, ...) _corto_error(f, l, __VA_ARGS__);
#define corto_warning_fl(f, l, ...) _corto_warning(f, l, __VA_ARGS__);

#ifndef NDEBUG
#define corto_assert(condition, ...) if (!(condition)){_corto_assert(__FILE__, __LINE__, condition, "(" #condition ") " __VA_ARGS__);}
#define corto_debug(...) if(corto_err_callbacksRegistered() || corto_verbosityGet() <= CORTO_DEBUG) { _corto_debug(__FILE__, __LINE__, __VA_ARGS__);}
#define corto_trace(...) if(corto_err_callbacksRegistered() || corto_verbosityGet() <= CORTO_TRACE) { _corto_trace(__FILE__, __LINE__, __VA_ARGS__);}
#define corto_info(...) if(corto_err_callbacksRegistered() || corto_verbosityGet() <= CORTO_INFO) { _corto_info(__FILE__, __LINE__, __VA_ARGS__);}
#define corto_ok(...) if(corto_err_callbacksRegistered() || corto_verbosityGet() <= CORTO_OK) { _corto_ok(__FILE__, __LINE__, __VA_ARGS__);}
#else
#define corto_assert(condition, ...) (void)(condition)
#define corto_debug(...)
#define corto_trace(...)
#define corto_info(...)
#define corto_ok(...)
#endif

/* Error verbosity levels */
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


/* Set / get console verbosity level */
CORTO_EXPORT void corto_verbosity(corto_err level);
CORTO_EXPORT corto_err corto_verbosityGet(void);

/* Report errors */
CORTO_EXPORT void _corto_assert(char *file, unsigned int line, unsigned int condition, char* fmt, ...);
CORTO_EXPORT corto_err _corto_debug(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT corto_err _corto_trace(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT corto_err _corto_info(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT corto_err _corto_ok(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT corto_err _corto_warning(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT corto_err _corto_error(char *file, unsigned int line, char* fmt, ...);
CORTO_EXPORT void _corto_critical(char *file, unsigned int line, char* fmt, ...);

/* Report errors (va_list as parameter) */
CORTO_EXPORT void _corto_assertv(char *file, unsigned int line, unsigned int condition, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_debugv(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_tracev(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_infov(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_okv(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_warningv(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT corto_err corto_errorv(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT void corto_criticalv(char *file, unsigned int line, char* fmt, va_list args);
CORTO_EXPORT void corto_seterrv(char *fmt, va_list args);

/* Set console error format */
#define CORTO_ERRFMT_DEFAULT "%k: [%a] %c: %m"
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

/* Get stack backtraces */
CORTO_EXPORT void corto_printBacktrace(FILE* f, int nEntries, char** symbols);
CORTO_EXPORT void corto_backtrace(FILE* f);
CORTO_EXPORT char* corto_backtraceString(void);

#ifdef __cplusplus
}
#endif

#endif /* CORE_ERR_H_ */
