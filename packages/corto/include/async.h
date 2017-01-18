/*
 * corto_async.h
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#ifndef CORTO_ASYNC_H_
#define CORTO_ASYNC_H_

#include "corto/async_posix.h"

#ifdef __cplusplus
extern "C" {
#endif

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
CORTO_EXPORT int corto_mutexLockTimed(corto_mutex mutex, corto_time timeout);

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

#ifdef __cplusplus
}
#endif

#endif /* CORTO_ASYNC_H */
