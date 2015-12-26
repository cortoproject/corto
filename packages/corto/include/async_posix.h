/*
 * corto_async_posix.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef CORTO_ASYNC_POSIX_H_
#define CORTO_ASYNC_POSIX_H_

#include "pthread.h"
#include "signal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef pthread_key_t corto_threadKey;

typedef struct corto_rwmutex_s {
    pthread_rwlock_t mutex;
}corto_rwmutex_s;

#define DETECT_CONTENTION (0)

typedef struct corto_mutex_s {
    pthread_mutex_t mutex;

#if DETECT_CONTENTION
    corto_uint32 contention;
    corto_time hotness;

    /* creation */
    corto_uint32 c_entries;
    char** c_symbols;

    /* locked by */
    corto_uint32 l_entries;
    char** l_symbols;
#endif
}corto_mutex_s;
    
typedef struct corto_sem_s {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
}corto_sem_s;

#define CORTO_MUTEX_INITIALIZER {PTHREAD_MUTEX_INITIALIZER}
#define CORTO_RWMUTEX_INITIALIZER {PTHREAD_RWLOCK_INITIALIZER}

#ifdef __cplusplus
}
#endif

#endif /* CORTO_ASYNC_POSIX_H_ */
