
#ifndef corto_files_H
#define corto_files_H

#include "corto/ll.h"

#ifdef __cplusplus
extern "C" {
#endif

#if INTPTR_MAX == INT32_MAX
#define CORTO_CPU_32BIT
#elif INTPTR_MAX == INT64_MAX
#define CORTO_CPU_64BIT
#else
#warning "corto is not supported on platforms which are neither 32- nor 64-bit."
#endif

#if defined(WIN32) || defined(WIN64)
#define CORTO_OS_WINDOWS
#elif defined(__linux__)
#define CORTO_OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#define CORTO_OS_OSX
#else
#warning "corto is not supported on non-unix or windows operating systems."
#endif

#ifdef __i386__
#define CORTO_CPU_STRING "x86"
#elif __x86_64__
#define CORTO_CPU_STRING "x64"
#elif defined(__arm__) && defined(CORTO_CPU_32BIT)
#define CORTO_CPU_STRING "Arm"
#elif defined(__arm__) && defined(CORTO_CPU_64BIT)
#define CORTO_CPU_STRING "Arm64"
#endif

#ifdef CORTO_OS_WINDOWS
#define CORTO_OS_STRING "windows"
#elif defined(CORTO_OS_LINUX)
#define CORTO_OS_STRING "linux"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#elif defined(CORTO_OS_OSX)
#define CORTO_OS_STRING "darwin"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#endif

#define CORTO_PLATFORM_STRING CORTO_CPU_STRING "-" CORTO_OS_STRING

typedef int corto_pid;

typedef enum corto_procsignal {
    CORTO_SIGINT = 2,
    CORTO_SIGQUIT = 3,
    CORTO_SIGILL = 4,
    CORTO_SIGABRT = 6,
    CORTO_SIGFPE = 8,
    CORTO_SIGKILL = 9,
    CORTO_SIGSEGV = 11,
    CORTO_SIGTERM = 15
} corto_procsignal;

/* Create a directory. Returns zero if OK, -1 if failed */
CORTO_EXPORT int corto_mkdir(const char *name, ...);

/* Read the contents of a directory */
CORTO_EXPORT corto_ll corto_opendir(const char *name);

/* Release directory contents */
CORTO_EXPORT void corto_closedir(corto_ll dir);

/* Creates a file. Returns zero if OK, -1 if failed */
CORTO_EXPORT int corto_touch(const char *name);

/* Get working directory. Returns NULL of failed, an internal buffer otherwise */
CORTO_EXPORT char* corto_cwd(void);

/* Change working directory. Returns zero if OK, -1 if failed */
CORTO_EXPORT int corto_chdir(const char *name);

/* Copy a file. Returns zero if OK, -1 if failed */
CORTO_EXPORT int corto_cp(const char *source, const char *destination);

/* Test if name is a directory */
CORTO_EXPORT int corto_isdir(const char *name);

/* Rename a file or directory. Returns 0 if OK, -1 if failed */
CORTO_EXPORT int corto_rename(const char *oldName, const char *newName);

/* Remove a file or directory. Returns 0 if OK, -1 if failed */
CORTO_EXPORT int corto_rm(const char *name);

/* Recursively remove a directory */
CORTO_EXPORT int corto_rmtree(const char *name);

/* Run a process, return PID (-1 if failed) */
CORTO_EXPORT corto_pid corto_procrun(const char* exec, char *argv[]);

/* Same as corto_procrun, but override stdin, stdout and stderr of child */
CORTO_EXPORT corto_pid corto_procrunRedirect(
    const char* exec, char *argv[], FILE *in, FILE *out, FILE *err);

/* Send signal to process */
CORTO_EXPORT int corto_prockill(corto_pid pid, corto_procsignal sig);

/* Wait for process */
CORTO_EXPORT int corto_procwait(corto_pid pid, int8_t *rc);

/* Check state of process */
CORTO_EXPORT int corto_proccheck(corto_pid pid, int8_t *rc);

/* Simple blocking function to create and wait for a process */
CORTO_EXPORT int corto_proccmd(corto_string cmd, int8_t *rc);

/* Check whether process is being debugged */
CORTO_EXPORT int corto_beingTraced(void);

/* Get hostname of current machine */
CORTO_EXPORT char* corto_hostname(void);

/* Get PID of current process */
#define corto_pid() _corto_pid()
CORTO_EXPORT corto_pid _corto_pid(void);

typedef struct corto_dl_s* corto_dl;

/* Link dynamic library */
CORTO_EXPORT corto_dl corto_dlOpen(const char* file);

/* Close dynamic library */
CORTO_EXPORT void corto_dlClose(corto_dl dl);

/* Lookup symbol in dynamic library */
CORTO_EXPORT void* corto_dlSym(corto_dl dl, const char* sym);

/* Lookup procedure in dynamic library */
CORTO_EXPORT void*(*corto_dlProc(corto_dl dl, const char* proc))(void);

/* Return error code */
CORTO_EXPORT const char* corto_dlError(void);

/* Set environment variable */
CORTO_EXPORT int16_t corto_setenv(const char *varname, const char *value, ...);

/* Get environment variable */
CORTO_EXPORT char* corto_getenv(const char *varname);

/* Parse string with environment variable references */
CORTO_EXPORT char* corto_envparse(const char* str, ...);

/* Same as envparse with va_list */
CORTO_EXPORT char* corto_venvparse(const char* str, va_list args);


#ifdef __cplusplus
}
#endif

#endif
