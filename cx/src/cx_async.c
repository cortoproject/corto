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

cx_sem cx_semNew(unsigned int initValue) {
    cx_sem semaphore;
    
    semaphore = malloc (sizeof(cx_sem_s));
    memset(semaphore, 0, sizeof(cx_sem_s));
    if (semaphore) {
        pthread_mutex_init(&semaphore->mutex, NULL);
        pthread_cond_init(&semaphore->cond, NULL);
        semaphore->value = initValue;
    }
    
    return (cx_sem)semaphore;
}

/* Post to semaphore */
int cx_semPost(cx_sem semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    semaphore->value++;
    if(semaphore->value > 0) {
        pthread_cond_signal(&semaphore->cond);
    }
    pthread_mutex_unlock(&semaphore->mutex);
    return 0;
}

/* Wait for semaphore */
int cx_semWait(cx_sem semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    while(semaphore->value <= 0) {
        pthread_cond_wait(&semaphore->cond, &semaphore->mutex);
    }
    semaphore->value--;
    pthread_mutex_unlock(&semaphore->mutex);    
    return 0;
}

/* Trywait for semaphore */
int cx_semTryWait(cx_sem semaphore) {
    int result;

    pthread_mutex_lock(&semaphore->mutex);
    if(semaphore->value > 0) {
        semaphore->value--;
        result = 0;
    } else {
        errno = EAGAIN;
        result = -1;
    }
    pthread_mutex_unlock(&semaphore->mutex);    
    return result;
}

/* Get value of semaphore */
int cx_semValue(cx_sem semaphore) {
    return semaphore->value;
}

/* Free semaphore */
int cx_semFree(cx_sem semaphore) {
    pthread_cond_destroy(&semaphore->cond);
    pthread_mutex_destroy(&semaphore->mutex);
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


