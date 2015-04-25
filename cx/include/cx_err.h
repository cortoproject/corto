/*
 * cx_err.h
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

typedef enum cx_err {
    CX_OK = 0,
    CX_DEBUG = 1,
    CX_TRACE = 2,
    CX_WARNING = 3,
    CX_ERROR = 4,
    CX_CRITICAL = 5,
    CX_ASSERT = 6
}cx_err;

#define cx_assert(condition, ...) if (!(condition)){_cx_assert(condition, "(" #condition ") " __VA_ARGS__);}

void _cx_assert(unsigned int condition, char* fmt, ...);
cx_err cx_debug(char* fmt, ...);
cx_err cx_trace(char* fmt, ...);
cx_err cx_warning(char* fmt, ...);
cx_err cx_error(char* fmt, ...);
void cx_print(char* fmt, ...);

void _cx_assertv(unsigned int condition, char* fmt, va_list args);
cx_err cx_debugv(char* fmt, va_list args);
cx_err cx_tracev(char* fmt, va_list args);
cx_err cx_warningv(char* fmt, va_list args);
cx_err cx_errorv(char* fmt, va_list args);
void cx_printv(char *fmt, va_list args);
void cx_criticalv(char* fmt, va_list args);

/* A critical error will print a backtrace and quit the application. */
void cx_critical(char* fmt, ...);

/* Return last error */
char* cx_lasterror(void);

/* Enable or disable echo */
int cx_toggleEcho(int enable);

void cx_printBacktrace(FILE* f, int nEntries, char** symbols);
void cx_backtrace(FILE* f);
char* cx_backtraceString(void);

#ifdef __cplusplus
}
#endif

#endif /* CORE_ERR_H_ */
