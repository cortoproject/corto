/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CORTO_THREAD_POSIX_H_
#define CORTO_THREAD_POSIX_H_

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
    uint32_t contention;
    corto_time hotness;

    /* creation */
    uint32_t c_entries;
    char** c_symbols;

    /* locked by */
    uint32_t l_entries;
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

#endif /* CORTO_THREAD_POSIX_H_ */
