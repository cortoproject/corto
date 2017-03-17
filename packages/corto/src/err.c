/*
 * corto_err.c
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#include "corto/corto.h"

static corto_threadKey corto_errKey = 0;
extern corto_mutex_s corto_adminLock;
static corto_err CORTO_LOG_LEVEL = CORTO_INFO;
extern char *corto_appName;

#define DEPTH 60

typedef struct corto_errThreadData {
    corto_string lastInfo;
    corto_string lastError;
    corto_string backtrace;
    corto_bool viewed;
} corto_errThreadData;

struct corto_err_callback {
    corto_err min_level, max_level;
    char *category;
    char *auth_token;
    void *ctx;
    corto_err_callback_callback cb;
};


static void corto_lasterrorFree(void* tls) {
    corto_errThreadData* data = tls;
    if (data) {
        if (!data->viewed && data->lastError) {
            corto_warning("uncatched error (use corto_lasterr): %s%s%s",
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

static int corto_getLastErrorViewed(void) {
    corto_errThreadData *data = corto_getThreadData();
    return data->lastError ? data->viewed : TRUE;
}

static char* corto_getLastInfo(void) {
    corto_errThreadData *data = corto_getThreadData();
    data->viewed = TRUE;
    return data->lastInfo;
}

static void corto_setLastError(char* err) {
    corto_errThreadData *data = corto_getThreadData();
    if (!data->viewed && data->lastError) {
        data->viewed = TRUE; /* Prevent recursion */
        corto_warning("uncatched error (use corto_lasterr): %s%s%s",
          data->lastError, data->backtrace ? "\n" : "", data->backtrace ? data->backtrace : "");
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

static corto_ll corto_err_callbacks;

corto_err_callback corto_err_callbackRegister(
    corto_err min_level, 
    corto_err max_level,
    corto_string category, 
    corto_string auth_token,
    corto_err_callback_callback callback,
    void *ctx)
{
    struct corto_err_callback* result = corto_alloc(sizeof(struct corto_err_callback));

    result->min_level = min_level;
    result->max_level = max_level;
    result->category = category ? corto_strdup(category) : NULL;
    result->auth_token = auth_token ? corto_strdup(auth_token) : NULL;
    result->cb = callback;
    result->ctx = ctx;

    corto_mutexLock(&corto_adminLock);
    if (!corto_err_callbacks) {
        corto_err_callbacks = corto_llNew();
    }
    corto_llAppend(corto_err_callbacks, result);
    corto_mutexUnlock(&corto_adminLock);

    return result;
}

void corto_err_callbackUnregister(corto_err_callback cb)
{
    struct corto_err_callback* callback = cb;
    if (callback) {
        corto_mutexLock(&corto_adminLock);
        corto_llRemove(corto_err_callbacks, callback);
        if (!corto_llSize(corto_err_callbacks)) {
            corto_llFree(corto_err_callbacks);
            corto_err_callbacks = NULL;
        }
        corto_mutexUnlock(&corto_adminLock);

        if (callback->category) corto_dealloc(callback->category);
        if (callback->auth_token) corto_dealloc(callback->auth_token);
        corto_dealloc(callback);
    }
}

corto_bool corto_err_callbacksRegistered(void) {
    return corto_err_callbacks != NULL;
}

void corto_err_notifyCallkback(
    corto_err_callback cb,
    char *components[],
    corto_err level, 
    char *msg)
{
    struct corto_err_callback* callback = cb;
    if (level >= callback->min_level && level <= callback->max_level) {
        callback->cb(level, components, msg, callback->ctx);
    }
}

#define CORTO_MAX_LOG (1024)

static char* corto_log_componentString(char *components[]) {
    corto_int32 i = 0;
    corto_buffer buff = CORTO_BUFFER_INIT;

    if (corto_appName) {
        corto_buffer_append(&buff, "[%s%s%s] ", 
            CORTO_CYAN, corto_appName, CORTO_NORMAL);
    }

    while (components[i]) {
        corto_buffer_append(&buff, "%s%s%s: ", 
            CORTO_MAGENTA, components[i], CORTO_NORMAL);
        i ++;
    }

    return corto_buffer_str(&buff);
}

static char* corto_log_tokenize(char *msg) {
    corto_buffer buff = CORTO_BUFFER_INIT;
    char *ptr, ch, prev = '\0';
    corto_bool isNum = FALSE;
    char isStr = '\0';

    for (ptr = msg; (ch = *ptr); ptr++) {

        if (isNum && !isdigit(ch) && !isalpha(ch) && (ch != '.')) {
            corto_buffer_appendstr(&buff, CORTO_NORMAL);
            isNum = FALSE;
        }
        if (isStr && (isStr == ch) && !isalpha(ptr[1])) {
            isStr = '\0';
        } else if (((ch == '\'') || (ch == '"')) && !isStr && !isalpha(prev)) {
            corto_buffer_appendstr(&buff, CORTO_CYAN);
            isStr = ch;
        }

        if (isdigit(ch) && !isNum && !isStr && !isalpha(prev) && !isdigit(prev) && (prev != '_') && (prev != '.')) {
            corto_buffer_appendstr(&buff, CORTO_GREEN);
            isNum = TRUE;
        }

        corto_buffer_appendstrn(&buff, ptr, 1);

        if (((ch == '\'') || (ch == '"')) && !isStr) {
            corto_buffer_appendstr(&buff, CORTO_NORMAL);
        }

        prev = ch;
    }

    if (isNum || isStr) {
        corto_buffer_appendstr(&buff, CORTO_NORMAL);
    }

    return corto_buffer_str(&buff);
}

static void corto_logprint(FILE *f, corto_err kind, char *components[], char *msg) {
    size_t n = 0;
    int levelspace;
    char *color, *levelstr, *tokenized;
    corto_time now;
    corto_timeGet(&now);

    switch(kind) {
    case CORTO_ERROR: color = CORTO_RED; levelstr = "error"; break;
    case CORTO_WARNING: color = CORTO_YELLOW; levelstr = "warn"; break;
    case CORTO_INFO: color = CORTO_BLUE; levelstr = "info"; break;
    case CORTO_OK: color = CORTO_GREEN; levelstr = "ok"; break;
    case CORTO_TRACE: color = CORTO_GREY; levelstr = "trace"; break;
    case CORTO_DEBUG: color = CORTO_GREY; levelstr = "debug"; break;
    default: color = CORTO_NORMAL; levelstr = "critical"; break;
    }

    n = strlen(msg) + 1;
    if (n < 80) {
        n = 80 - n;
    } else {
        n = 0;
    }

    if (corto_verbosityGet() <= CORTO_TRACE) {
        levelspace = 5;
    } else {
        levelspace = 4;
    }

    char *componentStr = corto_log_componentString(components);

    /* If string already uses color coding, don't interfere */
    if (!strchr(msg, '\033')) {
        tokenized = corto_log_tokenize(msg);
    }

    fprintf(f, "%.9d.%.4d - %s%*s%s: %s%s%*s\n", 
        now.sec, now.nanosec / 100000, 
        color, levelspace, levelstr, CORTO_NORMAL, 
        componentStr ? componentStr : "", tokenized, (int)n, " ");

    if (tokenized != msg) {
        corto_dealloc(tokenized);
    }

    corto_dealloc(componentStr);
}

static char* corto_log_parseComponents(char *components[], char *msg) {
    char *ptr, *prev = msg, ch;
    int count = 0;

    for (ptr = msg; (ch = *ptr) && (isalpha(ch) || (ch == ':') || (ch == '/')); ptr++) {
        if ((ch == ':') && (ptr[1] == ' ')) {
            *ptr = '\0';
            components[count ++] = prev;
            ptr ++;
            prev = ptr + 1;
        }
    }

    components[count] = NULL;

    return prev;
}

corto_err corto_logv(corto_err kind, unsigned int level, char* fmt, va_list arg, FILE* f) {
    if (kind >= CORTO_LOG_LEVEL || corto_err_callbacks) {
        corto_string alloc = NULL;
        char buff[CORTO_MAX_LOG + 1];
        char *components[CORTO_MAX_LOG_COMPONENTS];
        size_t n = 0;

        corto_string msg = buff, msgBody;
        va_list argcpy;
        va_copy(argcpy, arg); /* Make copy of arglist in
                               * case vsnprintf needs to be called twice */

        CORTO_UNUSED(level);

        if ((n = (vsnprintf(buff, CORTO_MAX_LOG, fmt, arg) + 1)) > CORTO_MAX_LOG) {
            alloc = corto_alloc(n + 2);
            vsnprintf(alloc, n, fmt, argcpy);
            msg = alloc;
        }

        msgBody = corto_log_parseComponents(components, msg);

        if (kind >= CORTO_LOG_LEVEL) {
            corto_logprint(f, kind, components, msgBody);
        }

        if (corto_err_callbacks) {
            corto_mutexLock(&corto_adminLock);
            if (corto_err_callbacks) {
                corto_iter it = corto_llIter(corto_err_callbacks);
                while (corto_iterHasNext(&it)) {
                    corto_err_callback callback = corto_iterNext(&it);
                    corto_err_notifyCallkback(
                        callback,
                        components,
                        kind,
                        msg);
                }
            }
            corto_mutexUnlock(&corto_adminLock);
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
            corto_error("error raised while starting up: %s", corto_lasterr());
        } else if (CORTO_OPERATIONAL){
            corto_error("error raised while shutting down: %s", corto_lasterr());
        } else {
            corto_error("%s", err);
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

int corto_lasterrViewed(void) {
    return corto_getLastErrorViewed();
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
