#include "corto.h"
#include "stdlib.h"
#include "ctype.h"

void corto_setenv(const char *varname, const char *value, ...) {

    if (value) {
        va_list arglist;
        char *buff;
        va_start(arglist, value);
        buff = corto_venvparse(value, arglist);
        va_end(arglist);
        setenv(varname, buff, 1);
        corto_dealloc(buff);
    } else {
        unsetenv(varname);
    }
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

char* corto_venvparse(const char* input, va_list arglist) {
    int size = 256;
    char *result = corto_alloc(size);
    const char *ptr;
    char *bptr, *varptr, *str, ch;
    char var[256];

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
			if (varptr != var) {
				if (isalpha(ch) || (ch == '_')) {
					*varptr = ch;
					varptr++;
				} else {
					char *val;
					int len;
					*varptr = '\0';
					val = corto_getenv(var);
					if (!val) {
						corto_seterr("environment variable '%s' doesn't exist", var);
						goto error;
					}
					len = strlen(val);
					bptr = corto_growBuffer(&result, bptr, &size, len + 1);
					memcpy(bptr, val, len);
					bptr += len;
					varptr = var;
					*bptr = ch;
					bptr++;
				}
			} else {
				bptr = corto_growBuffer(&result, bptr, &size, 1);
				*bptr = ch;
				bptr++;
			}
		}
		ptr++;
	}

    bptr = corto_growBuffer(&result, bptr, &size, 1);
    *bptr = '\0';

    return result;
error:
    return NULL;
}

char* corto_envparse(const char* str, ...) {
    va_list arglist;
    char *result;

    va_start(arglist, str);
    result = corto_venvparse (str, arglist);
    va_end(arglist);

    return result;
}
