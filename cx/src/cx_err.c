/*
 * cx_err.c
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#include "cx_err.h"
#include "cx_util.h"
#include "cx_async.h"
#include "cx_mem.h"

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <execinfo.h>
#include <string.h>

static char* cx_logKind[] = {"ok:     ", "debug:   ", "trace:   ", "warning: ", "error:   ", "critical:", "assert: "};
static cx_threadKey cx_errKey = 0;

typedef struct cx_errThreadData {
	cx_string lastError;
	int echo;
} cx_errThreadData;

#define DEPTH 60

static void cx_lasterrorFree(void* tls) {
	if (tls) {
		cx_dealloc(((cx_errThreadData*)tls)->lastError);
		cx_dealloc(tls);
	}
}

static cx_errThreadData* cx_getThreadData(void){
	cx_errThreadData* result;
	if (!cx_errKey) {
		cx_threadTlsKey(&cx_errKey, cx_lasterrorFree);
	}
	result = cx_threadTlsGet(cx_errKey);
	if (!result) {
		result = cx_malloc(sizeof(cx_errThreadData));
		result->echo = TRUE;
		result->lastError = NULL;
		cx_threadTlsSet(cx_errKey, result);
	}
	return result;
}

static char* cx_getLasterror(void) {
	return cx_getThreadData()->lastError;
}

int cx_getEcho(void) {
	return cx_getThreadData()->echo;
}

char* cx_lasterror(void) {
	char* err;

	err = cx_getLasterror();
	if (err) {
		return err;
	} else {
		return "";
	}
}

static void cx_setLasterror(char* err) {
	cx_errThreadData* data;

	data = cx_getThreadData();
	if (data->lastError) {
		cx_dealloc(data->lastError);
	}
	data->lastError = cx_strdup(err);
}

/* Enable or disable echo */
int cx_toggleEcho(int enable) {
	cx_errThreadData* data;
	int oldValue;

	data = cx_getThreadData();
	oldValue = data->echo;
	data->echo = enable;

	return oldValue;
}

void cx_printBacktrace(FILE* f, int nEntries, char** symbols) {
	int i;
	for(i=1; i<nEntries; i++) { /* Skip this function */
		fprintf(f, "  %s\n", symbols[i]);
	}
	fprintf(f, "\n");
}

void cx_backtrace(FILE* f) {
	int nEntries;
	void* buff[DEPTH];
	char** symbols;

	nEntries = backtrace(buff, DEPTH);
	if (nEntries) {
		symbols = backtrace_symbols(buff, DEPTH);

		cx_printBacktrace(f, nEntries, symbols);

		free(symbols);
	} else {
		fprintf(f, "obtaining backtrace failed.");
	}
}

char* cx_backtraceString(void) {
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

#define CX_MAX_LOG (1024)

cx_err cx_logv(cx_err kind, unsigned int level, char* fmt, va_list arg, FILE* f) {
	char msg[512];
	char msg_hdr[512];
	struct timespec time;
	unsigned int length, written;

	CX_UNUSED(level);

	clock_gettime(CLOCK_REALTIME, &time);

	if (vsprintf(msg, fmt, arg) > CX_MAX_LOG) {
		cx_critical("Invalid parameter for cx_logv: message size exceeds 512 characters.");
	}

	/* If writing to stdout, don't write timestamps */
	if (f == stdout) {
        if ((length = sprintf(msg_hdr, "%s  %s\n", cx_logKind[kind], msg)) > CX_MAX_LOG) {
            printf("Invalid parameter for cx_logv: message (incl. header) exceeds 512 characters.\n");
            abort();
        }
	} else {
        if ((length = sprintf(msg_hdr, "%.9u.%.9u %s %s\n", (int)time.tv_sec, (int)time.tv_nsec, cx_logKind[kind], msg)) > CX_MAX_LOG) {
            printf("Invalid parameter for cx_logv: message (incl. header) exceeds 512 characters.\n");
            abort();
        }
	}

	if (kind == CX_ERROR) {
		cx_setLasterror(msg);
	}

	if (cx_getEcho() || ((kind == CX_CRITICAL) || (kind == CX_ASSERT))){
		if ((written = fwrite(msg_hdr, 1, length, f)) != length) {
			fprintf(f, "Error in cx_logv: number of bytes written (%d) does not match length of message (%d).\n", written, length);
		}
	}

	return kind;
}

void _cx_assertv(unsigned int condition, char* fmt, va_list args) {
    if (!condition) {
        cx_logv(CX_ASSERT, 0, fmt, args, stdout);
        cx_backtrace(stdout);
        abort();
    }
}

void cx_criticalv(char* fmt, va_list args) {
    cx_logv(CX_CRITICAL, 0, fmt, args, stdout);
    cx_backtrace(stdout);
    fflush(stdout);
    abort();
}

cx_err cx_debugv(char* fmt, va_list args) {
    return cx_logv(CX_DEBUG, 0, fmt, args, stdout);
}

cx_err cx_tracev(char* fmt, va_list args) {
    return cx_logv(CX_TRACE, 0, fmt, args, stdout);
}

cx_err cx_warningv(char* fmt, va_list args) {
    return cx_logv(CX_WARNING, 0, fmt, args, stdout);
}

cx_err cx_errorv(char* fmt, va_list args) {
    return cx_logv(CX_ERROR, 0, fmt, args, stdout);
}

cx_err cx_debug(char* fmt, ...) {
	va_list arglist;
	cx_err result;

	va_start(arglist, fmt);
	result = cx_debugv(fmt, arglist);
	va_end(arglist);

	return result;
}

cx_err cx_trace(char* fmt, ...) {
	va_list arglist;
	cx_err result;

	va_start(arglist, fmt);
	result = cx_tracev(fmt, arglist);
	va_end(arglist);

	return result;
}

cx_err cx_warning(char* fmt, ...) {
	va_list arglist;
	cx_err result;

	va_start(arglist, fmt);
	result = cx_warningv(fmt, arglist);
	va_end(arglist);

	return result;
}

cx_err cx_error(char* fmt, ...) {
	va_list arglist;
	cx_err result;

	va_start(arglist, fmt);
	result = cx_errorv(fmt, arglist);
	va_end(arglist);

	return result;
}

void cx_critical(char* fmt, ...) {
	va_list arglist;

	va_start(arglist, fmt);
	cx_criticalv(fmt, arglist);
	va_end(arglist);
}

void _cx_assert(unsigned int condition, char* fmt, ...) {
	va_list arglist;

    va_start(arglist, fmt);
    _cx_assertv(condition, fmt, arglist);
    va_end(arglist);
}
