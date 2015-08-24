
#include "cortex.h"
#include "stdlib.h"
#include "ctype.h"

void cx_setenv(const char *varname, const char *value, ...) {

	if (value) {
	    va_list arglist;
	    char *buff;
	    va_start(arglist, value);
		buff = cx_venvparse(value, arglist);
	    va_end(arglist);
		setenv(varname, buff, 1);
		cx_dealloc(buff);
	} else {
		unsetenv(varname);
	}
}

char* cx_getenv(const char *varname) {
	return getenv(varname);
}

static char* cx_growBuffer(char **buffer, char *ptr, int *size, int length) {
	int pos = ptr - *buffer;

	if ((pos + length) < *size) {
		*size = (length < 256) ? 256 : length;
		*buffer = cx_realloc(*buffer, *size);
		ptr = &(*buffer)[pos];
	}

	return ptr;
}

char* cx_venvparse(const char* input, va_list arglist) {
	int size = 256;
	char *result = cx_alloc(size);
	const char *ptr;
	char *bptr, *varptr, *str, ch;
	char var[256];

	cx_vasprintf(&str, input, arglist);

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
			char *val = cx_getenv("HOME");
			int len = strlen(val);
			bptr = cx_growBuffer(&result, bptr, &size, len);
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
					val = cx_getenv(var);
					if (!val) {
						cx_error("environment variable '%s' doesn't exist", var);
						goto error;
					}
					len = strlen(val);
					bptr = cx_growBuffer(&result, bptr, &size, len + 1);
					memcpy(bptr, val, len);
					bptr += len;
					varptr = var;
					*bptr = ch;
					bptr++;
				}
			} else {
				bptr = cx_growBuffer(&result, bptr, &size, 1);
				*bptr = ch;
				bptr++;
			}
		}
		ptr++;
	}

	bptr = cx_growBuffer(&result, bptr, &size, 1);
	*bptr = '\0';

	return result;
error:
	return NULL;
}

char* cx_envparse(const char* str, ...) {
    va_list arglist;
    char *result;

    va_start(arglist, str);
	result = cx_venvparse (str, arglist);
    va_end(arglist);

    return result;
}
