/*
 * db_err.h
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#ifndef CORE_ERR_H_
#define CORE_ERR_H_

#include "stdio.h"
#include "stdarg.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum db_err {
	DB_OK = 0,
	DB_DEBUG = 1,
	DB_TRACE = 2,
	DB_WARNING = 3,
	DB_ERROR = 4,
	DB_CRITICAL = 5,
	DB_ASSERT = 6
}db_err;

#define db_assert(condition, ...) if (!(condition)){_db_assert(condition, "(" #condition ") " __VA_ARGS__);}

void _db_assert(unsigned int condition, char* fmt, ...);
db_err db_debug(char* fmt, ...);
db_err db_trace(char* fmt, ...);
db_err db_warning(char* fmt, ...);
db_err db_error(char* fmt, ...);

void _db_assertv(unsigned int condition, char* fmt, va_list args);
db_err db_debugv(char* fmt, va_list args);
db_err db_tracev(char* fmt, va_list args);
db_err db_warningv(char* fmt, va_list args);
db_err db_errorv(char* fmt, va_list args);
void db_criticalv(char* fmt, va_list args);

/* A critical error will print a backtrace and quit the application. */
void db_critical(char* fmt, ...);

/* Return last error */
char* db_lasterror(void);

/* Enable or disable echo */
int db_toggleEcho(int enable);

void db_printBacktrace(FILE* f, int nEntries, char** symbols);
void db_backtrace(FILE* f);
char* db_backtraceString(void);

#ifdef __cplusplus
}
#endif

#endif /* CORE_ERR_H_ */
