
#ifndef corto_files_H
#define corto_files_H

#include "corto/ll.h"

#ifdef __cplusplus
extern "C" {
#endif

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
CORTO_EXPORT int corto_mkdir(const char *name);

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
CORTO_EXPORT int corto_isDirectory(const char *name);

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

#ifdef __cplusplus
}
#endif

#endif
