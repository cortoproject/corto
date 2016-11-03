
#ifndef corto_env_H
#define corto_env_H

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 corto_setenv(const char *varname, const char *value, ...);
char* corto_getenv(const char *varname);
char* corto_envparse(const char* str, ...);
char* corto_venvparse(const char* str, va_list args);

#ifdef __cplusplus
}
#endif

#endif
