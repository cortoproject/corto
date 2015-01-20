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

static char* cx_logKind[] = {"", "debug:    ", "trace:    ", "warning:  ", "error:    ", "critical: ", "assert:  "};
static cx_threadKey cx_errKey = 0;

typedef struct cx_errThreadData {
    cx_string lastError[64]; /* Retain 64 last errors */
    int count;
    int consumed;
    int echo;
} cx_errThreadData;

#define DEPTH 60

static void cx_lasterrorFree(void* tls) {
    if (tls) {
        cx_uint32 i;
        for (i = 0; i < 64; i++) {
            if (((cx_errThreadData*)tls)->lastError[i]) {
                cx_dealloc(((cx_errThreadData*)tls)->lastError[i]);
            }
        }
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
        memset(result, 0, sizeof(cx_errThreadData));
        result->echo = TRUE;
        cx_threadTlsSet(cx_errKey, result);
    }
    return result;
}

static char* cx_getLasterror(void) {
    cx_errThreadData *data = cx_getThreadData();

    if (data->consumed < data->count) {
        data->consumed++;
        return data->lastError[data->consumed-1];
    } else {
        data->consumed = 0;
        data->count = 0;
        return NULL;
    }
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
        return NULL;
    }
}

static void cx_setLasterror(char* err) {
    cx_errThreadData* data;

    data = cx_getThreadData();
    if (!data->echo) {
        if (data->lastError[data->count]) {
            cx_dealloc(data->lastError[data->count]);
        }
        data->lastError[data->count] = cx_strdup(err);
        data->count++;
    }
}

/* Enable or disable echo */
int cx_toggleEcho(int enable) {
    cx_errThreadData* data;
    int oldValue;

    data = cx_getThreadData();
    oldValue = data->echo;
    data->echo = enable;

    if (!enable && oldValue) {
        data->count = 0;
        data->consumed = 0;
    }

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
    char buff[CX_MAX_LOG + 1];
    unsigned int written;
    size_t n = 0, l = 0;
    cx_string alloc = NULL;
    cx_string msg = buff;

    CX_UNUSED(level);

    if ((n = (vsnprintf(buff, CX_MAX_LOG, fmt, arg) + 1 + (l = strlen(cx_logKind[kind])))) > CX_MAX_LOG) {
        alloc = cx_malloc(n + 2);
        strcpy(alloc, cx_logKind[kind]);
        vsnprintf(alloc + l, n - l, fmt, arg);
        msg = alloc;
    } else {
        char *ptr = buff;
        strcpy(buff, cx_logKind[kind]);
        vsprintf(ptr, fmt, arg);
    }
    n = strlen(msg);

    /* Set last error without \n */
    cx_setLasterror(msg);

    strcat(msg, "\n");
    n++;

    if (cx_getEcho() || ((kind == CX_CRITICAL) || (kind == CX_ASSERT))){
        if ((written = fwrite(msg, 1, n, f)) != n) {
            fprintf(f, "Error in cx_logv: number of bytes written (%u) does not match length of message (%zu).\n", written, n);
        }
    }

    if (alloc) {
        cx_dealloc(alloc);
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

void cx_printv(char* fmt, va_list args) {
    cx_logv(CX_OK, 0, fmt, args, stdout);
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

void cx_print(char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    cx_printv(fmt, arglist);
    va_end(arglist);
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
