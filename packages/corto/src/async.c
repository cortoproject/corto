/*
 * corto_thread.c
 *
 *  Created on: 20 aug. 2010
 *      Author: Sander
 */

#include "corto/corto.h"

corto_thread corto_threadNew(corto_threadFunc f, void* arg) {
    pthread_t thread;
    int r;

    if ((r = pthread_create (&thread, NULL, f, arg))) {
        corto_critical("pthread_create failed: %d", r);
    }

    return (corto_thread)thread;
}

int corto_threadJoin(corto_thread thread, void** result) {
    return pthread_join((pthread_t)thread, result);
}

int corto_threadDetach(corto_thread thread) {
    pthread_detach((pthread_t)thread);
    return 0;
}

int corto_threadSetPriority(corto_thread thread, int priority) {
    pthread_t tid;
    struct sched_param param;

    tid = (pthread_t)thread;

    param.sched_priority = priority;

    return pthread_setschedparam(tid, SCHED_OTHER, &param);
}

int corto_threadGetPriority(corto_thread thread) {
    pthread_t tid;
    int policy;
    struct sched_param param;

    tid = (pthread_t)thread;

    if (pthread_getschedparam(tid, &policy, &param)) {
        return -1;
    }

    return param.sched_priority;
}

int corto_threadKill(corto_thread thr, int signal) {
    return pthread_kill((pthread_t)thr, signal);
}

corto_thread corto_threadSelf() {
    return (corto_thread)pthread_self();
}

int corto_threadCancel(corto_thread thread) {
    return pthread_cancel((pthread_t)thread);
}

int corto_threadTlsKey(corto_threadKey* key, void(*destructor)(void*)){
    if (pthread_key_create(key, destructor)) {
        corto_error("corto_threadTlsKey failed.");
        goto error;
    }
    return 0;
error:
    return -1;
}

int corto_threadTlsSet(corto_threadKey key, void* value) {
    return pthread_setspecific(key, value);
}

void* corto_threadTlsGet(corto_threadKey key) {
    return pthread_getspecific(key);
}

void corto_mutexNew(struct corto_mutex_s *m) {
    pthread_mutex_init (&m->mutex, NULL);

#if DETECT_CONTENTION
    void* buff[DEPTH];
    m->contention = 0;
    m->c_entries = backtrace(buff, DEPTH);
    m->c_symbols = backtrace_symbols(buff, DEPTH);
#endif
}

int corto_mutexLock(corto_mutex mutex) {
    int result;

    result = 0;
    if (pthread_mutex_trylock(&mutex->mutex)) {
#if DETECT_CONTENTION
        mutex->contention++;
        corto_trace("!! Contention(%d) @ ", mutex->contention);
        corto_backtrace(stdout);

        corto_trace("   Mutex creation @ :");
        corto_printBacktrace(stdout, mutex->c_entries, mutex->c_symbols);
#endif
        result = pthread_mutex_lock (&mutex->mutex);

    }

    return result;
}

int corto_mutexUnlock(corto_mutex mutex) {
    return pthread_mutex_unlock(&mutex->mutex);
}

int corto_mutexFree(corto_mutex mutex) {
    int result;

    result = pthread_mutex_destroy(&mutex->mutex);

    return result;
}

int corto_mutexTry(corto_mutex mutex) {
    int result;

    result = pthread_mutex_trylock(&mutex->mutex);

    return result;
}

/* Create read-write mutex */
void corto_rwmutexNew(struct corto_rwmutex_s *m) {
    if (pthread_rwlock_init(&m->mutex, NULL)) {
        corto_critical("pthread_rwlock_init failed.");
    }
}

/* Free read-write mutex */
int corto_rwmutexFree(corto_rwmutex m) {
    int result = 0;
    if ((result = pthread_rwlock_destroy(&m->mutex))) {
        corto_critical("pthread_rwlock_destroy failed (%s)", strerror(result));
    }
    return 0;
}

/* Read lock */
int corto_rwmutexRead(corto_rwmutex mutex) {
    return pthread_rwlock_rdlock(&mutex->mutex);
}

/* Write lock */
int corto_rwmutexWrite(corto_rwmutex mutex) {
    return pthread_rwlock_wrlock(&mutex->mutex);
}

/* Try read */
int corto_rwmutexTryRead(corto_rwmutex mutex) {
    return pthread_rwlock_tryrdlock(&mutex->mutex);
}

/* Try write */
int corto_rwmutexTryWrite(corto_rwmutex mutex) {
    return pthread_rwlock_trywrlock(&mutex->mutex);
}

/* Write unlock */
int corto_rwmutexUnlock(corto_rwmutex mutex) {
    return pthread_rwlock_unlock(&mutex->mutex);
}

corto_sem corto_semNew(unsigned int initValue) {
    corto_sem semaphore;

    semaphore = malloc (sizeof(corto_sem_s));
    memset(semaphore, 0, sizeof(corto_sem_s));
    if (semaphore) {
        pthread_mutex_init(&semaphore->mutex, NULL);
        pthread_cond_init(&semaphore->cond, NULL);
        semaphore->value = initValue;
    }

    return (corto_sem)semaphore;
}

/* Post to semaphore */
int corto_semPost(corto_sem semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    semaphore->value++;
    if(semaphore->value > 0) {
        pthread_cond_signal(&semaphore->cond);
    }
    pthread_mutex_unlock(&semaphore->mutex);
    return 0;
}

/* Wait for semaphore */
int corto_semWait(corto_sem semaphore) {
    pthread_mutex_lock(&semaphore->mutex);
    while(semaphore->value <= 0) {
        pthread_cond_wait(&semaphore->cond, &semaphore->mutex);
    }
    semaphore->value--;
    pthread_mutex_unlock(&semaphore->mutex);
    return 0;
}

/* Trywait for semaphore */
int corto_semTryWait(corto_sem semaphore) {
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
int corto_semValue(corto_sem semaphore) {
    return semaphore->value;
}

/* Free semaphore */
int corto_semFree(corto_sem semaphore) {
    pthread_cond_destroy(&semaphore->cond);
    pthread_mutex_destroy(&semaphore->mutex);
    free(semaphore);
    return 0;
}


int corto_ainc(int* count) {
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

int corto_adec(int* count) {
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
