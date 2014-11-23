/*
 * db_async.h
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#ifndef DB_ASYNC_H_
#define DB_ASYNC_H_

#include "db__type.h"
#include "db_async_posix.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_LOCK_BUSY (1)

/* Thread */
typedef unsigned long int db_thread;
typedef void* (*db_threadFunc)(void*);

db_thread db_threadNew(db_threadFunc f, void* arg);
int db_threadJoin(db_thread thread, void**);
int db_threadDetach(db_thread thread);
int db_threadFree(db_thread thread);
int db_threadSetPriority(db_thread thread, int priority);
int db_threadGetPriority(db_thread thread);
int db_threadKill(db_thread, int signal);
int db_threadCancel(db_thread);
db_thread db_threadSelf(void);
int db_threadTlsKey(db_threadKey* key, void(*destructor)(void*));
int db_threadTlsSet(db_threadKey key, void* value);
void* db_threadTlsGet(db_threadKey key);

/* Mutex */
typedef struct db_mutex_s* db_mutex;

struct db_mutex_s db_mutexNew(void);
int db_mutexLock(db_mutex mutex);
int db_mutexUnlock(db_mutex mutex);
int db_mutexFree(db_mutex mutex);
int db_mutexTry(db_mutex mutex);

/* Read-write mutex */
typedef struct db_rwmutex_s* db_rwmutex;

struct db_rwmutex_s db_rwmutexNew(void);
int db_rwmutexRead(db_rwmutex mutex);
int db_rwmutexWrite(db_rwmutex mutex);
int db_rwmutexTryRead(db_rwmutex mutex);
int db_rwmutexTryWrite(db_rwmutex mutex);
int db_rwmutexUnlock(db_rwmutex mutex);
int db_rwmutexFree(db_rwmutex mutex);

/* Semaphore */
typedef struct db_sem_s db_sem_s;
typedef db_sem_s* db_sem;

db_sem db_semNew(unsigned int initValue);
int db_semPost(db_sem);
int db_semWait(db_sem);
int db_semTryWait(db_sem);
int db_semValue(db_sem);
int db_semFree(db_sem);

/* Atomic increment and decrement */
int db_ainc(int* count);
int db_adec(int* count);

/* use GNU atomic compare and swap */
#define db_cas(ptr,old,new) __sync_bool_compare_and_swap(ptr,old,new)

#ifdef __cplusplus
}
#endif

#endif /* DB_ASYNC_H */
