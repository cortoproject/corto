
#define corto_lang_LIB
#include "corto.h"
#include "stdlib.h"
#include "ctype.h"

corto_int16 corto_setenv(const char *varname, const char *value, ...) {
    if (value) {
        va_list arglist;
        char *buff;
        va_start(arglist, value);
        buff = corto_venvparse(value, arglist);
        if (!buff) {
            va_end(arglist);
            goto error;
        }
        va_end(arglist);
        setenv(varname, buff, 1);
        corto_dealloc(buff);
    } else {
        unsetenv(varname);
    }
    return 0;
error:
    return -1;
}

char* corto_getenv(const char *varname) {
    return getenv(varname);
}

static char* corto_growBuffer(char **buffer, char *ptr, int *size, int length) {
    int pos = ptr - *buffer;

    if ((pos + length) < *size) {
        *size = (length < 256) ? 256 : length;
        *buffer = corto_realloc(*buffer, *size);
        ptr = &(*buffer)[pos];
    }

    return ptr;
}

static int corto_venvparseFlush(char* var, char** varptrptr, char** bptrptr, char** resultptr, int size, char ch) {
    char *val;
    int len;
    **varptrptr = '\0';
    val = corto_getenv(var);
    if (!val) {
        corto_seterr("environment variable '%s' doesn't exist", var);
        goto error;
    }
    len = strlen(val);
    *bptrptr = corto_growBuffer(resultptr, *bptrptr, &size, len + 1);
    memcpy(*bptrptr, val, len);
    *bptrptr += len;
    *varptrptr = var;
    **bptrptr = ch;
    (*bptrptr)++;
    return 0;
error:
    return -1;
}

char* corto_venvparse(const char* input, va_list arglist) {
    int size = 256;
    char *result = corto_alloc(size);
    const char *ptr;
    char *bptr, *str = NULL;
    char var[256], *varptr; /* buffer for name of environment variable */
    char ch;

    corto_vasprintf(&str, input, arglist);

    ptr = str;
    bptr = result;
    varptr = var;

    while ((ch = *ptr)) {
        if (ch == '$') {
            ptr++;
            varptr = var;
            *varptr = *ptr;
            varptr++;
        } else if (ch == '~') {
            char *val = corto_getenv("HOME");
            int len = strlen(val);
            bptr = corto_growBuffer(&result, bptr, &size, len);
            memcpy(bptr, val, len);
            bptr += len;
        } else {
            /* decide if we buffer a variable name or copy chars directly */
            if (varptr != var) {
                if (isalpha(ch) || (ch == '_')) {
                    /* copy variable name into var */
                    *varptr = ch;
                    varptr++;
                } else {
                    /* copy the value of the variable */
                    if (corto_venvparseFlush(var, &varptr, &bptr, &result, size, ch)) {
                        goto error;
                    }
                }
            } else {
                bptr = corto_growBuffer(&result, bptr, &size, 1);
                *bptr = ch;
                bptr++;
            }
        }
        ptr++;
    }
    if (varptr != var) {
        if (corto_venvparseFlush(var, &varptr, &bptr, &result, size, ch)) {
            goto error;
        }
    }

    bptr = corto_growBuffer(&result, bptr, &size, 1);
    *bptr = '\0';

    corto_dealloc(str);

    return result;
error:
    if (str) corto_dealloc(str);
    return NULL;
}

char* corto_envparse(const char* str, ...) {
    va_list arglist;
    char *result;

    va_start(arglist, str);
    result = corto_venvparse(str, arglist);
    va_end(arglist);
    return result;
}
