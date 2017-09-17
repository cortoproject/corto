/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CORTO_OS_H
#define CORTO_OS_H

/* UNSTABLE API */

#include "corto/posix_thread.h"

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
CORTO_EXPORT int corto_proccmd(char *cmd, int8_t *rc);

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

#define CORTO_LOCK_BUSY (1)

/* Thread */
typedef unsigned long int corto_thread;
typedef void* (*corto_threadFunc)(void*);

CORTO_EXPORT corto_thread corto_threadNew(corto_threadFunc f, void* arg);
CORTO_EXPORT int corto_threadJoin(corto_thread thread, void**);
CORTO_EXPORT int corto_threadDetach(corto_thread thread);
CORTO_EXPORT int corto_threadFree(corto_thread thread);
CORTO_EXPORT int corto_threadSetPriority(corto_thread thread, int priority);
CORTO_EXPORT int corto_threadGetPriority(corto_thread thread);
CORTO_EXPORT int corto_threadKill(corto_thread, int signal);
CORTO_EXPORT int corto_threadCancel(corto_thread);
CORTO_EXPORT corto_thread corto_threadSelf(void);
CORTO_EXPORT int corto_threadTlsKey(corto_threadKey* key, void(*destructor)(void*));
CORTO_EXPORT int corto_threadTlsSet(corto_threadKey key, void* value);
CORTO_EXPORT void* corto_threadTlsGet(corto_threadKey key);
CORTO_EXPORT void corto_threadTlsKeysDestruct(void);

/* Mutex */
typedef struct corto_mutex_s* corto_mutex;

CORTO_EXPORT int corto_mutexNew(struct corto_mutex_s *m);
CORTO_EXPORT int corto_mutexLock(corto_mutex mutex);
CORTO_EXPORT int corto_mutexUnlock(corto_mutex mutex);
CORTO_EXPORT int corto_mutexFree(corto_mutex mutex);
CORTO_EXPORT int corto_mutexTry(corto_mutex mutex);
CORTO_EXPORT int corto_mutexLockTimed(corto_mutex mutex, struct timespec timeout);

/* Read-write mutex */
typedef struct corto_rwmutex_s* corto_rwmutex;

CORTO_EXPORT int corto_rwmutexNew(struct corto_rwmutex_s *m);
CORTO_EXPORT int corto_rwmutexRead(corto_rwmutex mutex);
CORTO_EXPORT int corto_rwmutexWrite(corto_rwmutex mutex);
CORTO_EXPORT int corto_rwmutexTryRead(corto_rwmutex mutex);
CORTO_EXPORT int corto_rwmutexTryWrite(corto_rwmutex mutex);
CORTO_EXPORT int corto_rwmutexUnlock(corto_rwmutex mutex);
CORTO_EXPORT int corto_rwmutexFree(corto_rwmutex mutex);

/* Semaphore */
typedef struct corto_sem_s* corto_sem;

CORTO_EXPORT corto_sem corto_semNew(unsigned int initValue);
CORTO_EXPORT int corto_semPost(corto_sem);
CORTO_EXPORT int corto_semWait(corto_sem);
CORTO_EXPORT int corto_semTryWait(corto_sem);
CORTO_EXPORT int corto_semValue(corto_sem);
CORTO_EXPORT int corto_semFree(corto_sem);

/* Atomic increment and decrement */
CORTO_EXPORT int corto_ainc(int* count);
CORTO_EXPORT int corto_adec(int* count);

/* use GNU atomic compare and swap */
#define corto_cas(ptr, old, new) __sync_bool_compare_and_swap(ptr, old, new)

typedef struct corto_file_s* corto_file;

/* File functions */
CORTO_EXPORT char* corto_fileLoad(const char* file);
CORTO_EXPORT corto_file corto_fileOpen(const char* file);
CORTO_EXPORT corto_file corto_fileAppend(const char* file);
CORTO_EXPORT corto_file corto_fileRead(const char* file);

CORTO_EXPORT FILE* corto_fileGet(corto_file file);
CORTO_EXPORT void corto_fileClose(corto_file);
CORTO_EXPORT char* corto_fileSearch(const char* file, corto_ll locations);
CORTO_EXPORT int corto_fileTest(const char* filefmt, ...);

CORTO_EXPORT unsigned int corto_fileSize(corto_file);
CORTO_EXPORT unsigned int corto_fileTell(corto_file);
CORTO_EXPORT bool corto_fileEof(corto_file);

CORTO_EXPORT char* corto_fileReadLine(corto_file file, char* buf, unsigned int length);

CORTO_EXPORT char* corto_fileExtension(char* file, char* buffer);
CORTO_EXPORT char* corto_filePath(char* file, char* buffer);
CORTO_EXPORT char* corto_fileBase(char* file, char* buffer);

/* Time functions */
CORTO_EXPORT void corto_sleep(unsigned int sec, unsigned int nanosec);
CORTO_EXPORT void timespec_gettime(struct timespec* time);
CORTO_EXPORT struct timespec timespec_add(struct timespec t1, struct timespec t2);
CORTO_EXPORT struct timespec timespec_sub(struct timespec t1, struct timespec t2);
CORTO_EXPORT int timespec_compare(struct timespec t1, struct timespec t2);
CORTO_EXPORT double timespec_toDouble(struct timespec t);

/* Do not belong here */
CORTO_EXPORT char* corto_itoa (int num, char* buff);
CORTO_EXPORT char* corto_utoa (unsigned int num, char* buff);
CORTO_EXPORT char* corto_ftoa (float num, char* buff);


#ifdef __cplusplus
}
#endif

#endif
