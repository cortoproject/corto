/*
 * cx_async.h
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#ifndef CX_ASYNC_H_
#define CX_ASYNC_H_

#include "cx__type.h"
#include "cx_async_posix.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CX_LOCK_BUSY (1)

/* Thread */
typedef unsigned long int cx_thread;
typedef void* (*cx_threadFunc)(void*);

cx_thread cx_threadNew(cx_threadFunc f, void* arg);
int cx_threadJoin(cx_thread thread, void**);
int cx_threadDetach(cx_thread thread);
int cx_threadFree(cx_thread thread);
int cx_threadSetPriority(cx_thread thread, int priority);
int cx_threadGetPriority(cx_thread thread);
int cx_threadKill(cx_thread, int signal);
int cx_threadCancel(cx_thread);
cx_thread cx_threadSelf(void);
int cx_threadTlsKey(cx_threadKey* key, void(*destructor)(void*));
int cx_threadTlsSet(cx_threadKey key, void* value);
void* cx_threadTlsGet(cx_threadKey key);

/* Mutex */
typedef struct cx_mutex_s* cx_mutex;

void cx_mutexNew(struct cx_mutex_s *m);
int cx_mutexLock(cx_mutex mutex);
int cx_mutexUnlock(cx_mutex mutex);
int cx_mutexFree(cx_mutex mutex);
int cx_mutexTry(cx_mutex mutex);

/* Read-write mutex */
typedef struct cx_rwmutex_s* cx_rwmutex;

void cx_rwmutexNew(struct cx_rwmutex_s *m);
int cx_rwmutexRead(cx_rwmutex mutex);
int cx_rwmutexWrite(cx_rwmutex mutex);
int cx_rwmutexTryRead(cx_rwmutex mutex);
int cx_rwmutexTryWrite(cx_rwmutex mutex);
int cx_rwmutexUnlock(cx_rwmutex mutex);
int cx_rwmutexFree(cx_rwmutex mutex);

/* Semaphore */
typedef struct cx_sem_s cx_sem_s;
typedef cx_sem_s* cx_sem;

cx_sem cx_semNew(unsigned int initValue);
int cx_semPost(cx_sem);
int cx_semWait(cx_sem);
int cx_semTryWait(cx_sem);
int cx_semValue(cx_sem);
int cx_semFree(cx_sem);

/* Atomic increment and decrement */
int cx_ainc(int* count);
int cx_adec(int* count);

/* use GNU atomic compare and swap */
#define cx_cas(ptr,old,new) __sync_bool_compare_and_swap(ptr,old,new)

#ifdef __cplusplus
}
#endif

#endif /* CX_ASYNC_H */
