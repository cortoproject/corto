/*
 * corto_async.h
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#ifndef CORTO_ASYNC_H_
#define CORTO_ASYNC_H_

#include "corto_async_posix.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_LOCK_BUSY (1)

/* Thread */
typedef unsigned long int corto_thread;
typedef void* (*corto_threadFunc)(void*);

corto_thread corto_threadNew(corto_threadFunc f, void* arg);
int corto_threadJoin(corto_thread thread, void**);
int corto_threadDetach(corto_thread thread);
int corto_threadFree(corto_thread thread);
int corto_threadSetPriority(corto_thread thread, int priority);
int corto_threadGetPriority(corto_thread thread);
int corto_threadKill(corto_thread, int signal);
int corto_threadCancel(corto_thread);
corto_thread corto_threadSelf(void);
int corto_threadTlsKey(corto_threadKey* key, void(*destructor)(void*));
int corto_threadTlsSet(corto_threadKey key, void* value);
void* corto_threadTlsGet(corto_threadKey key);

/* Mutex */
typedef struct corto_mutex_s* corto_mutex;

void corto_mutexNew(struct corto_mutex_s *m);
int corto_mutexLock(corto_mutex mutex);
int corto_mutexUnlock(corto_mutex mutex);
int corto_mutexFree(corto_mutex mutex);
int corto_mutexTry(corto_mutex mutex);

/* Read-write mutex */
typedef struct corto_rwmutex_s* corto_rwmutex;

void corto_rwmutexNew(struct corto_rwmutex_s *m);
int corto_rwmutexRead(corto_rwmutex mutex);
int corto_rwmutexWrite(corto_rwmutex mutex);
int corto_rwmutexTryRead(corto_rwmutex mutex);
int corto_rwmutexTryWrite(corto_rwmutex mutex);
int corto_rwmutexUnlock(corto_rwmutex mutex);
int corto_rwmutexFree(corto_rwmutex mutex);

/* Semaphore */
typedef struct corto_sem_s* corto_sem;

corto_sem corto_semNew(unsigned int initValue);
int corto_semPost(corto_sem);
int corto_semWait(corto_sem);
int corto_semTryWait(corto_sem);
int corto_semValue(corto_sem);
int corto_semFree(corto_sem);

/* Atomic increment and decrement */
int corto_ainc(int* count);
int corto_adec(int* count);

/* use GNU atomic compare and swap */
#define corto_cas(ptr, old, new) __sync_bool_compare_and_swap(ptr, old, new)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_ASYNC_H */
