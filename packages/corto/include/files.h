
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
int corto_mkdir(const char *name);

/* Read the contents of a directory */
corto_ll corto_opendir(const char *name);

/* Release directory contents */
void corto_closedir(corto_ll dir);

/* Creates a file. Returns zero if OK, -1 if failed */
int corto_touch(const char *name);

/* Get working directory. Returns NULL of failed, an internal buffer otherwise */
char* corto_cwd(void);

/* Change working directory. Returns zero if OK, -1 if failed */
int corto_chdir(const char *name);

/* Copy a file. Returns zero if OK, -1 if failed */
int corto_cp(const char *source, const char *destination);

/* Remove a file or directory. Returns 0 if OK, -1 if failed */
int corto_rm(const char *name);

/* Recursively remove a directory */
int corto_rmtree(const char *name);

/* Test whether a file exists */
int corto_fileTest(const char* filefmt, ...);

/* Run a process, return PID (-1 if failed) */
corto_pid corto_procrun(const char* exec, char *argv[]);

/* Same as corto_procrun, but override stdin, stdout and stderr of child */
corto_pid corto_procrunRedirect(
    const char* exec, char *argv[], FILE *inc, FILE *out, FILE *err);

/* Send signal to process */
int corto_prockill(corto_pid pid, corto_procsignal sig);

/* Wait for process */
int corto_procwait(corto_pid pid, int8_t *rc);

/* Check state of process */
int corto_proccheck(corto_pid pid, int8_t *rc);

#ifdef __cplusplus
}
#endif

#endif
