/*
 * corto_err.c
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#include "corto/corto.h"


#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define GREY    "\033[0;37m"
#define NORMAL  "\033[0;49m"
#define BOLD    "\033[1;49m"

// static char* corto_logKind[] = {"", "debug:    ", "trace:    ", "warning:  ", "error:    ", "critical: ", "assert:  "};
static corto_threadKey corto_errKey = 0;
static corto_err CORTO_LOG_LEVEL = CORTO_INFO;

#define MAX_ERRORS (20)

typedef struct corto_errThreadData {
    corto_string lastInfo;
    corto_string lastError;
    corto_string backtrace;
    corto_bool viewed;
} corto_errThreadData;

#define DEPTH 60

static void corto_lasterrorFree(void* tls) {
    corto_errThreadData* data = tls;
    if (data) {
        if (!data->viewed && data->lastError) {
            corto_error("corto: uncatched error (use corto_lasterr): %s%s%s",
              data->lastError, data->backtrace ? "\n" : "", data->backtrace ? data->backtrace : "");
        }
        if (data->lastError) {
            corto_dealloc(data->lastError);
        }
        if (data->lastInfo) {
            corto_dealloc(data->lastInfo);
        }
        corto_dealloc(data);
    }
}

static corto_errThreadData* corto_getThreadData(void){
    corto_errThreadData* result;
    if (!corto_errKey) {
        corto_threadTlsKey(&corto_errKey, corto_lasterrorFree);
    }
    result = corto_threadTlsGet(corto_errKey);
    if (!result) {
        result = corto_calloc(sizeof(corto_errThreadData));
        corto_threadTlsSet(corto_errKey, result);
    }
    return result;
}

static char* corto_getLastError(void) {
    corto_errThreadData *data = corto_getThreadData();
    data->viewed = TRUE;
    return data->lastError;
}

static char* corto_getLastInfo(void) {
    corto_errThreadData *data = corto_getThreadData();
    data->viewed = TRUE;
    return data->lastInfo;
}

static void corto_setLastError(char* err) {
    corto_errThreadData *data = corto_getThreadData();
    if (!data->viewed && data->lastError) {
        fprintf(stderr, "%scorto: uncatched error (use corto_lasterr): %s%s%s%s\n",
          RED, data->lastError, NORMAL, data->backtrace ? "\n" : "", data->backtrace ? data->backtrace : "");
    }
    if (data->lastError) corto_dealloc(data->lastError);
    if (data->backtrace) corto_dealloc(data->backtrace);
    data->lastError = err ? corto_strdup(err) : NULL;
    if (corto_verbosityGet() == CORTO_DEBUG) {
        data->backtrace = corto_backtraceString();
    }
    data->viewed = FALSE;
}

static void corto_setLastMessage(char* err) {
    corto_errThreadData *data = corto_getThreadData();
    if (data->lastInfo) corto_dealloc(data->lastInfo);
    data->lastInfo = err ? corto_strdup(err) : NULL;
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
    if (kind >= CORTO_LOG_LEVEL) {
        char buff[CORTO_MAX_LOG + 1];
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

        n = strlen(msg) + 1;
        if (n < 80) {
            n = 80 - n;
        } else {
            n = 0;
        }

        if (kind == CORTO_ERROR) {
            fprintf(f, "%s%s%s%*s\n", RED, msg, NORMAL, (int)n, " ");
        } else if (kind == CORTO_WARNING) {
            fprintf(f, "%s%s%s%*s\n", YELLOW, msg, NORMAL, (int)n, " ");
        } else if (kind == CORTO_OK) {
            fprintf(f, "%s%s%s%*s\n", GREEN, msg, NORMAL, (int)n, " ");
        } else if (kind == CORTO_TRACE) {
            fprintf(f, "%s%s%s%*s\n", GREY, msg, NORMAL, (int)n, " ");
        } else if (kind == CORTO_DEBUG) {
            fprintf(f, "%s%s%s%*s\n", GREY, msg, NORMAL, (int)n, " ");
        } else {
            fprintf(f, "%s%*s\n", msg, (int)n, " ");
        }

        if (alloc) {
            corto_dealloc(alloc);
        }
    }

    corto_seterr(NULL);

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
    return corto_logv(CORTO_DEBUG, 0, fmt, args, stderr);
}

corto_err corto_tracev(char* fmt, va_list args) {
    return corto_logv(CORTO_TRACE, 0, fmt, args, stderr);
}

corto_err corto_warningv(char* fmt, va_list args) {
    return corto_logv(CORTO_WARNING, 0, fmt, args, stderr);
}

corto_err corto_errorv(char* fmt, va_list args) {
    return corto_logv(CORTO_ERROR, 0, fmt, args, stderr);
}

corto_err corto_okv(char* fmt, va_list args) {
    return corto_logv(CORTO_OK, 0, fmt, args, stderr);
}

corto_err corto_infov(char* fmt, va_list args) {
    return corto_logv(CORTO_INFO, 0, fmt, args, stdout);
}

void corto_seterrv(char *fmt, va_list args) {
    char *err = NULL;
    if (fmt) {
        corto_vasprintf(&err, fmt, args);
    }
    corto_setLastError(err);

    if (fmt && (CORTO_DEBUG_ENABLED || CORTO_OPERATIONAL)) {
        if (CORTO_OPERATIONAL == 1) {
            corto_error("error raised while starting up: %s", err);
        } else if (CORTO_OPERATIONAL){
            corto_error("error raised while shutting down: %s", err);
        } else {
            fprintf(stderr, "%s%s%s\n", RED, err, NORMAL);
        }
        corto_backtrace(stderr);
    }

    corto_dealloc(err);
}

void corto_setmsgv(char *fmt, va_list args) {
    char *err = NULL;
    if (fmt) {
        corto_vasprintf(&err, fmt, args);
    }
    corto_setLastMessage(err);
    corto_dealloc(err);
}

corto_err _corto_debug(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_debugv(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_trace(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_tracev(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_info(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_infov(fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_ok(char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_okv(fmt, arglist);
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
    return corto_getLastError();
}

char* corto_lastinfo(void) {
    return corto_getLastInfo();
}

void corto_seterr(char *fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    corto_seterrv(fmt, arglist);
    va_end(arglist);
}

void corto_setinfo(char *fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    corto_setmsgv(fmt, arglist);
    va_end(arglist);
}

void corto_verbosity(corto_err level) {
    CORTO_LOG_LEVEL = level;
    if (level == CORTO_DEBUG) {
        CORTO_DEBUG_ENABLED = 1;
        CORTO_TRACE_NOTIFICATIONS = 1;
    } else {
        CORTO_DEBUG_ENABLED = 0;
        CORTO_TRACE_NOTIFICATIONS = 0;
    }
}

corto_err corto_verbosityGet() {
    return CORTO_LOG_LEVEL;
}
