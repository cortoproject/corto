/*
 * db_thread.c
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "time.h"
#include "stdarg.h"
#include "execinfo.h"

#include "db_async.h"
#include "db_err.h"
#include "db_util.h"
#include "db_time.h"

static int db_posixError(char* func, int error) {
	if (error) {
		db_warning("%s failed: %s.", func, strerror(errno));
	}
	return error;
}

db_thread db_threadNew(db_threadFunc f, void* arg) {
	pthread_t thread;
	int r;

	if ((r = pthread_create (&thread, NULL, f, arg))) {
	    db_critical("pthread_create failed: %d", r);
	}

	return (db_thread)thread;
}

int db_threadJoin(db_thread thread, void** result) {
	return pthread_join((pthread_t)thread, result);
}

int db_threadDetach(db_thread thread) {
	pthread_detach((pthread_t)thread);
	return 0;
}

int db_threadSetPriority(db_thread thread, int priority) {
	pthread_t tid;
	struct sched_param param;

	tid = (pthread_t)thread;

	param.sched_priority = priority;

	return pthread_setschedparam(tid, SCHED_OTHER, &param);
}

int db_threadGetPriority(db_thread thread) {
	pthread_t tid;
	int policy;
	struct sched_param param;

	tid = (pthread_t)thread;

	if (pthread_getschedparam(tid, &policy, &param)) {
		return -1;
	}

	return param.sched_priority;
}

int db_threadKill(db_thread thr, int signal) {
	return pthread_kill((pthread_t)thr, signal);
}

db_thread db_threadSelf() {
	return (db_thread)pthread_self();
}

int db_threadCancel(db_thread thread) {
	return pthread_cancel((pthread_t)thread);
}

int db_threadTlsKey(db_threadKey* key, void(*destructor)(void*)){
    if (pthread_key_create(key, destructor)) {
        db_error("db_threadTlsKey failed.");
        goto error;
    }
    return 0;
error:
    return -1;
}

int db_threadTlsSet(db_threadKey key, void* value) {
    return pthread_setspecific(key, value);
}

void* db_threadTlsGet(db_threadKey key) {
    return pthread_getspecific(key);
}

struct db_mutex_s db_mutexNew() {
	struct db_mutex_s mutex;

#if DETECT_CONTENTION
	void* buff[DEPTH];
#endif

	pthread_mutex_init (&mutex.mutex, NULL);

#if DETECT_CONTENTION
	mutex->contention = 0;
	mutex->c_entries = backtrace(buff, DEPTH);
	mutex->c_symbols = backtrace_symbols(buff, DEPTH);
#endif

	return mutex;
}

int db_mutexLock(db_mutex mutex) {
	int result;

	result = 0;
	if (pthread_mutex_trylock(&mutex->mutex)) {
#if DETECT_CONTENTION
		mutex->contention++;
		db_trace("!! Contention(%d) @ ", mutex->contention);
		db_backtrace(stdout);

		db_trace("   Mutex creation @ :");
		db_printBacktrace(stdout, mutex->c_entries, mutex->c_symbols);
#endif
		result = pthread_mutex_lock (&mutex->mutex);

	}

	return result;
}

int db_mutexUnlock(db_mutex mutex) {
	return pthread_mutex_unlock(&mutex->mutex);
}

int db_mutexFree(db_mutex mutex) {
	int result;

	result = pthread_mutex_destroy(&mutex->mutex);

	return result;
}

int db_mutexTry(db_mutex mutex) {
	int result;

	result = pthread_mutex_trylock(&mutex->mutex);

	return result;
}

db_sem db_semNew(unsigned int initValue) {
	sem_t* semaphore;

	semaphore = malloc (sizeof(sem_t));
	memset(semaphore, 0, sizeof(sem_t));
	if (semaphore) {
		db_posixError("sem_init", sem_init (semaphore, FALSE, initValue));
	}

	return (db_sem)semaphore;
}

/* Create read-write mutex */
struct db_rwmutex_s db_rwmutexNew() {
    struct db_rwmutex_s result;

	if (pthread_rwlock_init(&result.mutex, NULL)) {
		db_critical("pthread_rwlock_init failed.");
	}

	return result;
}

/* Free read-write mutex */
int db_rwmutexFree(db_rwmutex mutex) {
	if (pthread_rwlock_destroy(&mutex->mutex)) {
		db_error("pthread_rwlock_destroy failed.");
	}
	return 0;
}

/* Read lock */
int db_rwmutexRead(db_rwmutex mutex) {
	return pthread_rwlock_rdlock(&mutex->mutex);
}

/* Write lock */
int db_rwmutexWrite(db_rwmutex mutex) {
	return pthread_rwlock_wrlock(&mutex->mutex);
}

/* Try read */
int db_rwmutexTryRead(db_rwmutex mutex) {
    return pthread_rwlock_tryrdlock(&mutex->mutex);
}

/* Try write */
int db_rwmutexTryWrite(db_rwmutex mutex) {
    return pthread_rwlock_trywrlock(&mutex->mutex);
}

/* Write unlock */
int db_rwmutexUnlock(db_rwmutex mutex) {
	return pthread_rwlock_unlock(&mutex->mutex);
}

/* Post to semaphore */
int db_semPost(db_sem semaphore) {
	return db_posixError("sem_post", sem_post((sem_t*)semaphore));
}

/* Wait for semaphore */
int db_semWait(db_sem semaphore) {
	return db_posixError("sem_wait", sem_wait ((sem_t*)semaphore));
}

/* Trywait for semaphore */
int db_semTryWait(db_sem semaphore) {
	int result;
	result = sem_trywait((sem_t*)semaphore);
	if (result && (errno != EAGAIN)) {
		db_posixError("sem_trywait", result);
	}
	return result;
}

/* Get value of semaphore */
int db_semValue(db_sem semaphore) {
	int value;
	db_posixError("sem_getvalue", sem_getvalue((sem_t*)semaphore, &value));
	return value;
}

/* Free semaphore */
int db_semFree(db_sem semaphore) {
	sem_destroy ((sem_t*)semaphore);
	free(semaphore);
	return 0;
}


int db_ainc(int* count) {
    int value;
#ifdef __GNUC__
    __asm__ __volatile__ (
            "movl $1, %0\n\t"
            "lock\n\t"
            "xaddl %0, %2\n\t"
            "incl %0"
    :       "=&r" (value), "=m" (*count)
    :       "m" (*count)
    :       "memory");

    return value;
#else
    AtomicModify( count, &value, 0, 1 );
    return( value + 1 );
#endif
}

int db_adec(int* count) {
    int value;
#ifdef __GNUC__
    __asm__ __volatile__ (
            "movl $-1, %0\n\t"
            "lock\n\t"
            "xaddl %0, %2\n\t"
            "decl %0"
    :       "=&r" (value), "=m" (*count)
    :       "m" (*count)
    :       "memory");

    return value;
#else
    AtomicModify( count, &value, 0, -1 );
    return( value - 1 );
#endif
}


