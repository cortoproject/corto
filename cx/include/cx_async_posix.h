/*
 * cx_async_posix.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef CX_ASYNC_POSIX_H_
#define CX_ASYNC_POSIX_H_

#include "pthread.h"
#include "signal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef pthread_key_t cx_threadKey;

typedef struct cx_rwmutex_s {
    pthread_rwlock_t mutex;
}cx_rwmutex_s;

#define DETECT_CONTENTION (0)

typedef struct cx_mutex_s {
    pthread_mutex_t mutex;

#if DETECT_CONTENTION
    cx_uint32 contention;
    cx_time hotness;

    /* creation */
    cx_uint32 c_entries;
    char** c_symbols;

    /* locked by */
    cx_uint32 l_entries;
    char** l_symbols;
#endif
}cx_mutex_s;
    
typedef struct cx_sem_s {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
}cx_sem_s;

#define CX_MUTEX_INITIALIZER {PTHREAD_MUTEX_INITIALIZER}
#define CX_RWMUTEX_INITIALIZER {PTHREAD_RWLOCK_INITIALIZER}

#ifdef __cplusplus
}
#endif

#endif /* CX_ASYNC_POSIX_H_ */
