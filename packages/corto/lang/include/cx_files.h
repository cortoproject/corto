
#ifndef cx_files_H
#define cx_files_H

#include "cx_ll.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int cx_pid;

typedef enum cx_procsignal {
	CX_SIGINT = 2,
	CX_SIGQUIT = 3,
	CX_SIGILL = 4,
	CX_SIGABRT = 6,
	CX_SIGFPE = 8,
	CX_SIGKILL = 9,
	CX_SIGSEGV = 11,
	CX_SIGTERM = 15
} cx_procsignal;

/* Create a directory. Returns zero if OK, -1 if failed */
int cx_mkdir(const char *name);

/* Read the contents of a directory */
cx_ll cx_opendir(const char *name);

/* Release directory contents */
void cx_closedir(cx_ll dir);

/* Creates a file. Returns zero if OK, -1 if failed */
int cx_touch(const char *name);

/* Change working directory. Returns zero if OK, -1 if failed */
int cx_chdir(const char *name);

/* Copy a file. Returns zero if OK, -1 if failed */
int cx_cp(const char *source, const char *destination);

/* Remove a file. Returns 0 if OK, -1 if failed */
int cx_rm(const char *name);

/* Test whether a file exists */
int cx_fileTest(const char* file);

/* Run a process, return PID (-1 if failed) */
cx_pid cx_procrun(const char* exec, char *argv[]);

/* Send signal to process */
int cx_prockill(cx_pid pid, cx_procsignal sig);

/* Wait for process */
int cx_procwait(cx_pid pid, int8_t *rc);

/* Check state of process */
int cx_proccheck(cx_pid pid, int8_t *rc);

#ifdef __cplusplus
}
#endif

#endif
