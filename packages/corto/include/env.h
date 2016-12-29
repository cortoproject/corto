
#ifndef corto_env_H
#define corto_env_H

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_int16 corto_setenv(const char *varname, const char *value, ...);
CORTO_EXPORT char* corto_getenv(const char *varname);
CORTO_EXPORT char* corto_envparse(const char* str, ...);
CORTO_EXPORT char* corto_venvparse(const char* str, va_list args);

#ifdef __cplusplus
}
#endif

#endif
