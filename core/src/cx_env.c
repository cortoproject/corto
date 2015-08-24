
#include "cx_env.h"
#include "stdlib.h"

void cx_setenv(const char *varname, const char *value) {
	if (value) {
		setenv(varname, value, 1);
	} else {
		unsetenv(varname);
	}
}

char* cx_getenv(const char *varname) {
	return getenv(varname);
}

