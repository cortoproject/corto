/*
 * db_async_posix.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef DB_ASYNC_POSIX_H_
#define DB_ASYNC_POSIX_H_

#include "pthread.h"
#include "signal.h"
#include "semaphore.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef pthread_key_t db_threadKey;

typedef struct db_rwmutex_s {
    pthread_rwlock_t mutex;
}db_rwmutex_s;

#define DETECT_CONTENTION (0)

typedef struct db_mutex_s {
    pthread_mutex_t mutex;

#if DETECT_CONTENTION
    db_uint32 contention;
    db_time hotness;

    /* creation */
    db_uint32 c_entries;
    char** c_symbols;

    /* locked by */
    db_uint32 l_entries;
    char** l_symbols;
#endif
}db_mutex_s;

#define DB_MUTEX_INITIALIZER {PTHREAD_MUTEX_INITIALIZER}
#define DB_RWMUTEX_INITIALIZER {PTHREAD_RWLOCK_INITIALIZER}

#ifdef __cplusplus
}
#endif

#endif /* DB_ASYNC_POSIX_H_ */
