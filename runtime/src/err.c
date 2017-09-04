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

#include <corto/corto.h>

static corto_threadKey corto_errKey = 0;
extern corto_mutex_s corto_adminLock;
static corto_err CORTO_LOG_LEVEL = CORTO_INFO;
extern char *corto_appName;
static char *corto_errfmt_application;
static char *corto_errfmt_current = CORTO_ERRFMT_DEFAULT;

#define DEPTH 60

typedef struct corto_errThreadData {
    corto_string lastInfo;
    corto_string lastError;
    corto_string backtrace;
    corto_bool viewed;
} corto_errThreadData;

struct corto_err_callback {
    corto_err min_level, max_level;
    char *component_filter;
    corto_idmatch_program compiled_component_filter;
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
    corto_string component_filter, 
    corto_string auth_token,
    corto_err_callback_callback callback,
    void *ctx)
{
    struct corto_err_callback* result = corto_alloc(sizeof(struct corto_err_callback));

    result->min_level = min_level;
    result->max_level = max_level;
    result->component_filter = component_filter ? corto_strdup(component_filter) : NULL;
    result->auth_token = auth_token ? corto_strdup(auth_token) : NULL;
    result->cb = callback;
    result->ctx = ctx;

    if (result->component_filter) {
        result->compiled_component_filter = 
            corto_idmatch_compile(result->component_filter, TRUE, TRUE);
        if (!result->compiled_component_filter) {
            corto_seterr("invalid filter: %s", corto_lasterr());
            goto error;
        }
    } else {
        result->compiled_component_filter = NULL;
    }

    corto_mutexLock(&corto_adminLock);
    if (!corto_err_callbacks) {
        corto_err_callbacks = corto_ll_new();
    }
    corto_ll_append(corto_err_callbacks, result);
    corto_mutexUnlock(&corto_adminLock);

    return result;
error:
    if (result) corto_dealloc(result);
    return NULL;
}

void corto_err_callbackUnregister(corto_err_callback cb)
{
    struct corto_err_callback* callback = cb;
    if (callback) {
        corto_mutexLock(&corto_adminLock);
        corto_ll_remove(corto_err_callbacks, callback);
        if (!corto_ll_size(corto_err_callbacks)) {
            corto_ll_free(corto_err_callbacks);
            corto_err_callbacks = NULL;
        }
        corto_mutexUnlock(&corto_adminLock);

        if (callback->component_filter) corto_dealloc(callback->component_filter);
        if (callback->auth_token) corto_dealloc(callback->auth_token);
        if (callback->compiled_component_filter) corto_idmatch_free(callback->compiled_component_filter);
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
    corto_bool filterMatch = TRUE;
    if (level >= callback->min_level && level <= callback->max_level) {
        if (callback->compiled_component_filter) {
            corto_buffer buff = CORTO_BUFFER_INIT;
            corto_int32 i;
            for (i = 0; components[i]; i++) {
                if (i) corto_buffer_appendstr(&buff, "/");
                corto_buffer_appendstr(&buff, components[i]);
            }
            char *str = corto_buffer_str(&buff);
            if (!corto_idmatch_run(callback->compiled_component_filter, str)) {
                filterMatch = FALSE;
            }
            corto_dealloc(str);
        }

        if (filterMatch) {
            callback->cb(level, components, msg, callback->ctx);
        }
    }
}

#define CORTO_MAX_LOG (1024)

static char* corto_log_componentString(char *components[]) {
    corto_int32 i = 0;
    corto_buffer buff = CORTO_BUFFER_INIT;

    while (components[i]) {
        corto_buffer_append(&buff, "%s%s%s", 
            CORTO_MAGENTA, components[i], CORTO_NORMAL);
        i ++;
        if (components[i]) {
            corto_buffer_appendstr(&buff, ": ");
        }
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
        if (isStr && (isStr == ch) && !isalpha(ptr[1]) && (prev != '\\')) {
            isStr = '\0';
        } else if (((ch == '\'') || (ch == '"')) && !isStr && !isalpha(prev) && (prev != '\\')) {
            corto_buffer_appendstr(&buff, CORTO_CYAN);
            isStr = ch;
        }

        if ((isdigit(ch) || (ch == '-' && isdigit(ptr[1]))) && !isNum && !isStr && !isalpha(prev) && !isdigit(prev) && (prev != '_') && (prev != '.')) {
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

static void corto_logprint_kind(corto_buffer *buf, corto_err kind) {
    char *color, *levelstr;
    int levelspace;

    switch(kind) {
    case CORTO_THROW: color = CORTO_RED; levelstr = "throw"; break;
    case CORTO_ERROR: color = CORTO_RED; levelstr = "error"; break;
    case CORTO_WARNING: color = CORTO_YELLOW; levelstr = "warn"; break;
    case CORTO_INFO: color = CORTO_BLUE; levelstr = "info"; break;
    case CORTO_OK: color = CORTO_GREEN; levelstr = "ok"; break;
    case CORTO_TRACE: color = CORTO_GREY; levelstr = "trace"; break;
    case CORTO_DEBUG: color = CORTO_GREY; levelstr = "debug"; break;
    default: color = CORTO_RED; levelstr = "critical"; break;
    }

    if (corto_verbosityGet() <= CORTO_TRACE) {
        levelspace = 5;
    } else {
        levelspace = 4;
    }

    corto_buffer_append(
        buf, "%s%*s%s", color, levelspace, levelstr, CORTO_NORMAL);
}

static void corto_logprint_time(corto_buffer *buf, corto_time t) {
    corto_buffer_append(buf, "%.9d.%.4d", t.sec, t.nanosec / 100000);
}

static void corto_logprint_friendlyTime(corto_buffer *buf, corto_time t) {
    corto_id tbuff;
    time_t sec = t.sec;
    struct tm * timeinfo = localtime(&sec);
    strftime(tbuff, sizeof(tbuff), "%F %T", timeinfo);
    corto_buffer_append(buf, "%s.%.4d", tbuff, t.nanosec / 100000);
}

static int corto_logprint_components(corto_buffer *buf, char *components[]) {
    char *componentStr = components ? corto_log_componentString(components) : NULL;
    if (componentStr) {
        corto_buffer_appendstr(buf, componentStr);
        corto_dealloc(componentStr);
        return 1;
    } else {
        return 0;
    }
}

static int corto_logprint_msg(corto_buffer *buf, corto_string msg) {
    char *tokenized = msg;
    if (!msg) {
        return 0;
    }

    if (!strchr(msg, '\033')) {
        tokenized = corto_log_tokenize(msg);
    }
    corto_buffer_appendstr(buf, tokenized);
    if (tokenized != msg) corto_dealloc(tokenized);

    return 1;
}

static int corto_logprint_file(corto_buffer *buf, char const *file) {
    if (file) {
        corto_buffer_appendstr(buf, (char*)file);
        return 1;
    } else {
        return 0;
    }
}

static int corto_logprint_line(corto_buffer *buf, corto_uint64 line) {
    if (line) {
        corto_buffer_append(buf, "%s%u%s", CORTO_GREEN, line, CORTO_NORMAL);
        return 1;
    } else {
        return 0;
    }
}

static void corto_logprint(FILE *f, corto_err kind, char *components[], char const *file, corto_uint64 line, char *msg) {
    size_t n = 0;
    corto_buffer buf = CORTO_BUFFER_INIT;
    char *fmtptr, ch;
    corto_bool prevSeparatedBySpace = FALSE, separatedBySpace = FALSE;
    corto_time now;
    corto_timeGet(&now);

    for (fmtptr = corto_errfmt_current; (ch = *fmtptr); fmtptr++) {
        if (ch == '%') {
            int ret = 1;
            switch(fmtptr[1]) {
            case 'T': corto_logprint_friendlyTime(&buf, now); break;
            case 't': corto_logprint_time(&buf, now); break;
            case 'k': corto_logprint_kind(&buf, kind); break;
            case 'c': ret = corto_logprint_components(&buf, components); break;
            case 'f': ret = corto_logprint_file(&buf, file); break;
            case 'l': ret = corto_logprint_line(&buf, line); break;
            case 'm': ret = corto_logprint_msg(&buf, msg); break;
            case 'a': corto_buffer_append(&buf, "%s%s%s", CORTO_CYAN, corto_appName, CORTO_NORMAL); break;
            default:
                corto_buffer_appendstr(&buf, "%");
                corto_buffer_appendstrn(&buf, &fmtptr[1], 1);
                break;
            }

            if (fmtptr[2] == ' ') {
                separatedBySpace = TRUE;
            } else if ((fmtptr[2] != '%') && (fmtptr[3] == ' ')) {
                separatedBySpace = TRUE;
            } else {
                separatedBySpace = FALSE;
            }

            if (!ret) {
                if (fmtptr[2] && (fmtptr[2] != '%')) {
                    if ((fmtptr[2] != ' ') && (fmtptr[3] == ' ') && prevSeparatedBySpace) {
                        fmtptr += 2;
                    } else {
                        fmtptr += 1;
                    }
                }
            }

            prevSeparatedBySpace = separatedBySpace;

            fmtptr += 1;
        } else {
            corto_buffer_appendstrn(&buf, &ch, 1);
        }
    }

    char *str = corto_buffer_str(&buf);

    n = strlen(str) + 1;
    if (n < 80) {
        n = 80 - n;
    } else {
        n = 0;
    }

    fprintf(f, "%s\n", str);

    corto_dealloc(str);
}

static char* corto_log_parseComponents(char *components[], char *msg) {
    char *ptr, *prev = msg, ch;
    int count = 0;

    for (ptr = msg; (ch = *ptr) && (isalpha(ch) || isdigit(ch) || (ch == ':') || (ch == '/') || (ch == '_')); ptr++) {
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

void corto_errfmt(char *fmt) {
    if (corto_errfmt_application) {
        free(corto_errfmt_application);
    }

    corto_errfmt_current = strdup(fmt);
    corto_errfmt_application = corto_errfmt_current;

    corto_setenv("CORTO_ERRFMT", "%s", corto_errfmt_current);
}

corto_err corto_logv(char const *file, unsigned int line, corto_err kind, unsigned int level, char* fmt, va_list arg, FILE* f) {
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
            corto_logprint(f, kind, components, file, line, msgBody);
        }

        if (corto_err_callbacks) {
            corto_mutexLock(&corto_adminLock);
            if (corto_err_callbacks) {
                corto_iter it = corto_ll_iter(corto_err_callbacks);
                while (corto_iter_hasNext(&it)) {
                    corto_err_callback callback = corto_iter_next(&it);
                    corto_err_notifyCallkback(
                        callback,
                        components,
                        kind,
                        msgBody);
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

void _corto_assertv(char const *file, unsigned int line, unsigned int condition, char* fmt, va_list args) {
    if (!condition) {
        corto_logv(file, line, CORTO_ASSERT, 0, fmt, args, stderr);
        corto_backtrace(stderr);
        abort();
    }
}

void corto_criticalv(char const *file, unsigned int line, char* fmt, va_list args) {
    corto_logv(file, line, CORTO_CRITICAL, 0, fmt, args, stderr);
    corto_backtrace(stderr);
    fflush(stderr);
    abort();
}

corto_err corto_debugv(char const *file, unsigned int line, char* fmt, va_list args) {
    return corto_logv(file, line, CORTO_DEBUG, 0, fmt, args, stderr);
}

corto_err corto_tracev(char const *file, unsigned int line, char* fmt, va_list args) {
    return corto_logv(file, line, CORTO_TRACE, 0, fmt, args, stderr);
}

corto_err corto_warningv(char const *file, unsigned int line, char* fmt, va_list args) {
    return corto_logv(file, line, CORTO_WARNING, 0, fmt, args, stderr);
}

corto_err corto_errorv(char const *file, unsigned int line, char* fmt, va_list args) {
    corto_err result = corto_logv(file, line, CORTO_ERROR, 0, fmt, args, stderr);
    if (CORTO_BACKTRACE_ENABLED || CORTO_DEBUG_ENABLED) {
        corto_backtrace(stderr);
    }
    return result;
}

corto_err corto_okv(char const *file, unsigned int line, char* fmt, va_list args) {
    return corto_logv(file, line, CORTO_OK, 0, fmt, args, stderr);
}

corto_err corto_infov(char const *file, unsigned int line, char* fmt, va_list args) {
    return corto_logv(file, line, CORTO_INFO, 0, fmt, args, stderr);
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
            corto_logprint(stderr, CORTO_THROW, NULL, NULL, 0, err);
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

corto_err _corto_debug(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_debugv(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_trace(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_tracev(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_info(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_infov(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_ok(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_okv(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_warning(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_warningv(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

corto_err _corto_error(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;
    corto_err result;

    va_start(arglist, fmt);
    result = corto_errorv(file, line, fmt, arglist);
    va_end(arglist);

    return result;
}

void _corto_critical(char const *file, unsigned int line, char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    corto_criticalv(file, line, fmt, arglist);
    va_end(arglist);
}

void _corto_assert(char const *file, unsigned int line, unsigned int condition, char* fmt, ...) {
    va_list arglist;

    va_start(arglist, fmt);
    _corto_assertv(file, line, condition, fmt, arglist);
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
