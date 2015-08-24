
#ifndef cx_env_H
#define cx_env_H

#ifdef __cplusplus
extern "C" {
#endif

void cx_setenv(const char *varname, const char *value, ...);
char* cx_getenv(const char *varname);
char* cx_envparse(const char* str, ...);
char* cx_venvparse(const char* str, va_list args);

#ifdef __cplusplus
}
#endif

#endif
