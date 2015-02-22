/*
 * cx_thread.c
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

#include "cx_async.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx_time.h"

static int cx_posixError(char* func, int error) {
    if (error) {
        cx_warning("%s failed: %s.", func, strerror(errno));
    }
    return error;
}

cx_thread cx_threadNew(cx_threadFunc f, void* arg) {
    pthread_t thread;
    int r;

    if ((r = pthread_create (&thread, NULL, f, arg))) {
        cx_critical("pthread_create failed: %d", r);
    }

    return (cx_thread)thread;
}

int cx_threadJoin(cx_thread thread, void** result) {
    return pthread_join((pthread_t)thread, result);
}

int cx_threadDetach(cx_thread thread) {
    pthread_detach((pthread_t)thread);
    return 0;
}

int cx_threadSetPriority(cx_thread thread, int priority) {
    pthread_t tid;
    struct sched_param param;

    tid = (pthread_t)thread;

    param.sched_priority = priority;

    return pthread_setschedparam(tid, SCHED_OTHER, &param);
}

int cx_threadGetPriority(cx_thread thread) {
    pthread_t tid;
    int policy;
    struct sched_param param;

    tid = (pthread_t)thread;

    if (pthread_getschedparam(tid, &policy, &param)) {
        return -1;
    }

    return param.sched_priority;
}

int cx_threadKill(cx_thread thr, int signal) {
    return pthread_kill((pthread_t)thr, signal);
}

cx_thread cx_threadSelf() {
    return (cx_thread)pthread_self();
}

int cx_threadCancel(cx_thread thread) {
    return pthread_cancel((pthread_t)thread);
}

int cx_threadTlsKey(cx_threadKey* key, void(*destructor)(void*)){
    if (pthread_key_create(key, destructor)) {
        cx_error("cx_threadTlsKey failed.");
        goto error;
    }
    return 0;
error:
    return -1;
}

int cx_threadTlsSet(cx_threadKey key, void* value) {
    return pthread_setspecific(key, value);
}

void* cx_threadTlsGet(cx_threadKey key) {
    return pthread_getspecific(key);
}

void cx_mutexNew(struct cx_mutex_s *m) {
    pthread_mutex_init (&m->mutex, NULL);

#if DETECT_CONTENTION
    void* buff[DEPTH];
    m->contention = 0;
    m->c_entries = backtrace(buff, DEPTH);
    m->c_symbols = backtrace_symbols(buff, DEPTH);
#endif
}

int cx_mutexLock(cx_mutex mutex) {
    int result;

    result = 0;
    if (pthread_mutex_trylock(&mutex->mutex)) {
#if DETECT_CONTENTION
        mutex->contention++;
        cx_trace("!! Contention(%d) @ ", mutex->contention);
        cx_backtrace(stdout);

        cx_trace("   Mutex creation @ :");
        cx_printBacktrace(stdout, mutex->c_entries, mutex->c_symbols);
#endif
        result = pthread_mutex_lock (&mutex->mutex);

    }

    return result;
}

int cx_mutexUnlock(cx_mutex mutex) {
    return pthread_mutex_unlock(&mutex->mutex);
}

int cx_mutexFree(cx_mutex mutex) {
    int result;

    result = pthread_mutex_destroy(&mutex->mutex);

    return result;
}

int cx_mutexTry(cx_mutex mutex) {
    int result;

    result = pthread_mutex_trylock(&mutex->mutex);

    return result;
}

cx_sem cx_semNew(unsigned int initValue) {
    sem_t* semaphore;

    semaphore = malloc (sizeof(sem_t));
    memset(semaphore, 0, sizeof(sem_t));
    if (semaphore) {
        cx_posixError("sem_init", sem_init (semaphore, FALSE, initValue));
    }

    return (cx_sem)semaphore;
}

/* Create read-write mutex */
void cx_rwmutexNew(struct cx_rwmutex_s *m) {
    if (pthread_rwlock_init(&m->mutex, NULL)) {
        cx_critical("pthread_rwlock_init failed.");
    }
}

/* Free read-write mutex */
int cx_rwmutexFree(cx_rwmutex m) {
    int result = 0;
    if ((result = pthread_rwlock_destroy(&m->mutex))) {
        cx_critical("pthread_rwlock_destroy failed (%s)", strerror(result));
    }
    return 0;
}

/* Read lock */
int cx_rwmutexRead(cx_rwmutex mutex) {
    return pthread_rwlock_rdlock(&mutex->mutex);
}

/* Write lock */
int cx_rwmutexWrite(cx_rwmutex mutex) {
    return pthread_rwlock_wrlock(&mutex->mutex);
}

/* Try read */
int cx_rwmutexTryRead(cx_rwmutex mutex) {
    return pthread_rwlock_tryrdlock(&mutex->mutex);
}

/* Try write */
int cx_rwmutexTryWrite(cx_rwmutex mutex) {
    return pthread_rwlock_trywrlock(&mutex->mutex);
}

/* Write unlock */
int cx_rwmutexUnlock(cx_rwmutex mutex) {
    return pthread_rwlock_unlock(&mutex->mutex);
}

/* Post to semaphore */
int cx_semPost(cx_sem semaphore) {
    return cx_posixError("sem_post", sem_post((sem_t*)semaphore));
}

/* Wait for semaphore */
int cx_semWait(cx_sem semaphore) {
    return cx_posixError("sem_wait", sem_wait ((sem_t*)semaphore));
}

/* Trywait for semaphore */
int cx_semTryWait(cx_sem semaphore) {
    int result;
    result = sem_trywait((sem_t*)semaphore);
    if (result && (errno != EAGAIN)) {
        cx_posixError("sem_trywait", result);
    }
    return result;
}

/* Get value of semaphore */
int cx_semValue(cx_sem semaphore) {
    int value;
    cx_posixError("sem_getvalue", sem_getvalue((sem_t*)semaphore, &value));
    return value;
}

/* Free semaphore */
int cx_semFree(cx_sem semaphore) {
    sem_destroy ((sem_t*)semaphore);
    free(semaphore);
    return 0;
}


int cx_ainc(int* count) {
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

int cx_adec(int* count) {
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


