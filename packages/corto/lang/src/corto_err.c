/*
 * corto_err.c
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#define corto_lang_LIB
#include "corto_err.h"
#include "corto_util.h"
#include "corto_async.h"
#include "corto_mem.h"

#include "stdio.h"
#include "time.h"
#include "stdarg.h"
#include "stdlib.h"
#include "execinfo.h"
#include "string.h"

// static char* corto_logKind[] = {"", "debug:    ", "trace:    ", "warning:  ", "error:    ", "critical: ", "assert:  "};
static corto_threadKey corto_errKey = 0;

#define MAX_ERRORS (20)

typedef struct corto_errThreadData {
    corto_string lastError;
} corto_errThreadData;

#define DEPTH 60

static void corto_lasterrorFree(void* tls) {
    if (tls) {
        if (((corto_errThreadData*)tls)->lastError) {
            corto_dealloc(((corto_errThreadData*)tls)->lastError);
        }
        corto_dealloc(tls);
    }
}

static corto_errThreadData* corto_getThreadData(void){
    corto_errThreadData* result;
    if (!corto_errKey) {
        corto_threadTlsKey(&corto_errKey, corto_lasterrorFree);
    }
    result = corto_threadTlsGet(corto_errKey);
    if (!result) {
        result = corto_alloc(sizeof(corto_errThreadData));
        memset(result, 0, sizeof(corto_errThreadData));
        corto_threadTlsSet(corto_errKey, result);
    }
    return result;
}

static char* corto_getLasterror(void) {
    corto_errThreadData *data = corto_getThreadData();
    return data->lastError;
}

static void corto_setLasterror(char* err) {
    corto_errThreadData *data = corto_getThreadData();
    if (data->lastError) corto_dealloc(data->lastError);
    data->lastError = err ? corto_strdup(err) : NULL;
}

void corto_printBacktrace(FILE* f, int nEntries, char** symbols) {
    int i;
    for(i=1; i<nEntries; i++) { /* Skip this function */
        fprintf(f, "  %s\n", symbols[i]);
    }
    fprintf(f, "\n");
}

void corto_backtrace(FILE* f) {
    int nEntries;
    void* buff[DEPTH];
    char** symbols;

    nEntries = backtrace(buff, DEPTH);
    if (nEntries) {
        symbols = backtrace_symbols(buff, DEPTH);

        corto_printBacktrace(f, nEntries, symbols);

        free(symbols);
    } else {
        fprintf(f, "obtaining backtrace failed.");
    }
}

char* corto_backtraceString(void) {
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

#define CORTO_MAX_LOG (1024)

corto_err corto_logv(corto_err kind, unsigned int level, char* fmt, va_list arg, FILE* f) {
    char buff[CORTO_MAX_LOG + 1];
    unsigned int written;
    size_t n = 0;
    corto_string alloc = NULL;
    corto_string msg = buff;
    va_list argcpy;
    va_copy(argcpy, arg); /* Make copy of arglist in 
                           * case vsnprintf needs to be called twice */

    CORTO_UNUSED(level);

    if ((n = (vsnprintf(buff, CORTO_MAX_LOG, fmt, arg) + 1)) > CORTO_MAX_LOG) {
        alloc = corto_alloc(n + 2);
        vsnprintf(alloc, n, fmt, argcpy);
        msg = alloc;
    }

    n = strlen(msg);

    strcat(msg, "\n");
    n++;

    if ((written = fwrite(msg, 1, n, f)) != n) {
        fprintf(f, 
            "Error in corto_logv: number of bytes written (%u)"\
            " does not match length of message (%zu).\n", written, n);
    }

    if (alloc) {
        corto_dealloc(alloc);
    }

    return kind;
}

void _corto_assertv(unsigned int condition, char* fmt, va_list args) {
    if (!condition) {
        corto_logv(CORTO_ASSERT, 0, fmt, args, stderr);
        corto_backtrace(stderr);
        abort();
    }
}

void corto_criticalv(char* fmt, va_list args) {
    corto_logv(CORTO_CRITICAL, 0, fmt, args, stdout);
    corto_backtrace(stdout);
    fflush(stdout);
    abort();
}

corto_err corto_debugv(char* fmt, va_list args) {
    return corto_logv(CORTO_DEBUG, 0, fmt, args, stdout);
}

corto_err corto_tracev(char* fmt, va_list args) {
    return corto_logv(CORTO_TRACE, 0, fmt, args, stdout);
}

corto_err corto_warningv(char* fmt, va_list args) {
    return corto_logv(CORTO_WARNING, 0, fmt, args, stderr);
}

corto_err corto_errorv(char* fmt, va_list args) {
    return corto_logv(CORTO_ERROR, 0, fmt, args, stderr);
}

void corto_printv(char* fmt, va_list args) {
    corto_logv(CORTO_OK, 0, fmt, args, stdout);
}

corto_err corto_debug(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_debugv(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err corto_trace(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_tracev(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err corto_warning(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_warningv(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err corto_error(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_errorv(fmt, arglist);
    va_end(arglist);

    return result;
}

void corto_print(char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    corto_printv(fmt, arglist);
    va_end(arglist);
}

void corto_critical(char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    corto_criticalv(fmt, arglist);
    va_end(arglist);
}

void _corto_assert(unsigned int condition, char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    _corto_assertv(condition, fmt, arglist);
    va_end(arglist);
}

char* corto_lasterr(void) {
    return corto_getLasterror();
}

void corto_seterr(char *fmt, ...) {
    va_list list;
    char *err = NULL;
    if (fmt) {
        va_start(list, fmt);
        corto_vasprintf(&err, fmt, list);
        va_end(list);
    }
    corto_setLasterror(err);
    corto_dealloc(err);
}
