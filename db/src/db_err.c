/*
 * db_err.c
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#include "db_err.h"
#include "db_util.h"
#include "db_async.h"
#include "db_mem.h"

#include "stdio.h"
#include "time.h"
#include "stdarg.h"
#include "stdlib.h"
#include "execinfo.h"
#include "string.h"

static char* db_logKind[] = {"ok:     ", "debug:   ", "trace:   ", "warning: ", "error:   ", "critical:", "assert: "};
static db_threadKey db_errKey = 0;

typedef struct db_errThreadData {
	db_string lastError;
	int echo;
} db_errThreadData;

#define DEPTH 60

static void db_lasterrorFree(void* tls) {
	if (tls) {
		db_dealloc(((db_errThreadData*)tls)->lastError);
		db_dealloc(tls);
	}
}

static db_errThreadData* db_getThreadData(void){
	db_errThreadData* result;
	if (!db_errKey) {
		db_threadTlsKey(&db_errKey, db_lasterrorFree);
	}
	result = db_threadTlsGet(db_errKey);
	if (!result) {
		result = db_malloc(sizeof(db_errThreadData));
		result->echo = TRUE;
		result->lastError = NULL;
		db_threadTlsSet(db_errKey, result);
	}
	return result;
}

static char* db_getLasterror(void) {
	return db_getThreadData()->lastError;
}

int db_getEcho(void) {
	return db_getThreadData()->echo;
}

char* db_lasterror(void) {
	char* err;

	err = db_getLasterror();
	if (err) {
		return err;
	} else {
		return "";
	}
}

static void db_setLasterror(char* err) {
	db_errThreadData* data;

	data = db_getThreadData();
	if (data->lastError) {
		db_dealloc(data->lastError);
	}
	data->lastError = db_strdup(err);
}

/* Enable or disable echo */
int db_toggleEcho(int enable) {
	db_errThreadData* data;
	int oldValue;

	data = db_getThreadData();
	oldValue = data->echo;
	data->echo = enable;

	return oldValue;
}

void db_printBacktrace(FILE* f, int nEntries, char** symbols) {
	int i;
	for(i=1; i<nEntries; i++) { /* Skip this function */
		fprintf(f, "  %s\n", symbols[i]);
	}
	fprintf(f, "\n");
}

void db_backtrace(FILE* f) {
	int nEntries;
	void* buff[DEPTH];
	char** symbols;

	nEntries = backtrace(buff, DEPTH);
	if (nEntries) {
		symbols = backtrace_symbols(buff, DEPTH);

		db_printBacktrace(f, nEntries, symbols);

		free(symbols);
	} else {
		fprintf(f, "obtaining backtrace failed.");
	}
}

char* db_backtraceString(void) {
    int nEntries;
    void* buff[DEPTH];
    char** symbols;
    char* result;

    result = malloc(10000);
    *result = '\0';

    nEntries = backtrace(buff, DEPTH);
    if (nEntries) {
        symbols = backtrace_symbols(buff, DEPTH);

        int i;
        for(i=1; i<nEntries; i++) { /* Skip this function */
            sprintf(result, "%s  %s\n", result, symbols[i]);
        }
        strcat(result, "\n");

        free(symbols);
    } else {
        printf("obtaining backtrace failed.");
    }

    return result;
}

#define DB_MAX_LOG (1024)

db_err db_logv(db_err kind, unsigned int level, char* fmt, va_list arg, FILE* f) {
	char msg[512];
	char msg_hdr[512];
	struct timespec time;
	unsigned int length, written;

	DB_UNUSED(level);

	clock_gettime(CLOCK_REALTIME, &time);

	if (vsprintf(msg, fmt, arg) > DB_MAX_LOG) {
		db_critical("Invalid parameter for db_logv: message size exceeds 512 characters.");
	}

	/* If writing to stdout, don't write timestamps */
	if (f == stdout) {
        if ((length = sprintf(msg_hdr, "%s  %s\n", db_logKind[kind], msg)) > DB_MAX_LOG) {
            printf("Invalid parameter for db_logv: message (incl. header) exceeds 512 characters.\n");
            abort();
        }
	} else {
        if ((length = sprintf(msg_hdr, "%.9u.%.9u %s %s\n", (int)time.tv_sec, (int)time.tv_nsec, db_logKind[kind], msg)) > DB_MAX_LOG) {
            printf("Invalid parameter for db_logv: message (incl. header) exceeds 512 characters.\n");
            abort();
        }
	}

	if (kind == DB_ERROR) {
		db_setLasterror(msg);
	}

	if (db_getEcho() || ((kind == DB_CRITICAL) || (kind == DB_ASSERT))){
		if ((written = fwrite(msg_hdr, 1, length, f)) != length) {
			fprintf(f, "Error in db_logv: number of bytes written (%d) does not match length of message (%d).\n", written, length);
		}
	}

	return kind;
}

void _db_assertv(unsigned int condition, char* fmt, va_list args) {
    if (!condition) {
        db_logv(DB_ASSERT, 0, fmt, args, stdout);
        db_backtrace(stdout);
        abort();
    }
}

void db_criticalv(char* fmt, va_list args) {
    db_logv(DB_CRITICAL, 0, fmt, args, stdout);
    db_backtrace(stdout);
    fflush(stdout);
    abort();
}

db_err db_debugv(char* fmt, va_list args) {
    return db_logv(DB_DEBUG, 0, fmt, args, stdout);
}

db_err db_tracev(char* fmt, va_list args) {
    return db_logv(DB_TRACE, 0, fmt, args, stdout);
}

db_err db_warningv(char* fmt, va_list args) {
    return db_logv(DB_WARNING, 0, fmt, args, stdout);
}

db_err db_errorv(char* fmt, va_list args) {
    return db_logv(DB_ERROR, 0, fmt, args, stdout);
}

db_err db_debug(char* fmt, ...) {
	va_list arglist;
	db_err result;

	va_start(arglist, fmt);
	result = db_debugv(fmt, arglist);
	va_end(arglist);

	return result;
}

db_err db_trace(char* fmt, ...) {
	va_list arglist;
	db_err result;

	va_start(arglist, fmt);
	result = db_tracev(fmt, arglist);
	va_end(arglist);

	return result;
}

db_err db_warning(char* fmt, ...) {
	va_list arglist;
	db_err result;

	va_start(arglist, fmt);
	result = db_warningv(fmt, arglist);
	va_end(arglist);

	return result;
}

db_err db_error(char* fmt, ...) {
	va_list arglist;
	db_err result;

	va_start(arglist, fmt);
	result = db_errorv(fmt, arglist);
	va_end(arglist);

	return result;
}

void db_critical(char* fmt, ...) {
	va_list arglist;

	va_start(arglist, fmt);
	db_criticalv(fmt, arglist);
	va_end(arglist);
}

void _db_assert(unsigned int condition, char* fmt, ...) {
	va_list arglist;

    va_start(arglist, fmt);
    _db_assertv(condition, fmt, arglist);
    va_end(arglist);
}
