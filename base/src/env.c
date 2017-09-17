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

#include <include/base.h>

int16_t corto_setenv(const char *varname, const char *value, ...) {
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

/* TODO: replace with corto_buffer */
static char* corto_growBuffer(char **buffer, char *ptr, int *size, int length) {
    int pos = ptr - *buffer;

    if ((pos + length) >= *size) {
        *size = ((pos + length) < 256) ? 256 : pos + length + 1;
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

    str = corto_vasprintf(input, arglist);

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
            if (!val) {
                corto_seterr("$HOME environment variable (~) not found in string '%s'", str);
                goto error;
            }
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
