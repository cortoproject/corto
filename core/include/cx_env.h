
#ifndef cx_env_H
#define cx_env_H

#ifdef __cplusplus
extern "C" {
#endif

void cx_setenv(const char *varname, const char *value);
char* cx_getenv(const char *varname);

#ifdef __cplusplus
}
#endif

#endif
