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
    CORTO_OK = 0,
    CORTO_DEBUG = 1,
    CORTO_TRACE = 2,
    CORTO_WARNING = 3,
    CORTO_ERROR = 4,
    CORTO_CRITICAL = 5,
    CORTO_ASSERT = 6
}corto_err;

#ifndef NDEBUG
#define corto_assert(condition, ...) if (!(condition)){_corto_assert(condition, "(" #condition ") " __VA_ARGS__);}
#else
#define corto_assert(condition, ...) (void)(condition)
#endif

/* Log errors to console */
void _corto_assert(unsigned int condition, char* fmt, ...);
corto_err corto_debug(char* fmt, ...);
corto_err corto_trace(char* fmt, ...);
corto_err corto_warning(char* fmt, ...);
corto_err corto_error(char* fmt, ...);
void corto_print(char* fmt, ...);
void corto_critical(char* fmt, ...);

void _corto_assertv(unsigned int condition, char* fmt, va_list args);
corto_err corto_debugv(char* fmt, va_list args);
corto_err corto_tracev(char* fmt, va_list args);
corto_err corto_warningv(char* fmt, va_list args);
corto_err corto_errorv(char* fmt, va_list args);
void corto_printv(char *fmt, va_list args);
void corto_criticalv(char* fmt, va_list args);

/* Set & get last error */
char* corto_lasterr(void);
void corto_seterr(char *fmt, ...);

void corto_printBacktrace(FILE* f, int nEntries, char** symbols);
void corto_backtrace(FILE* f);
char* corto_backtraceString(void);

#ifdef __cplusplus
}
#endif

#endif /* CORE_ERR_H_ */
