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

#ifndef CORTO_THREAD_H
#define CORTO_THREAD_H

#include "corto/posix_thread.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_LOCK_BUSY (1)



/* -- Thread management -- */

typedef unsigned long int corto_thread;
typedef void* (*corto_thread_cb)(void*);

/** Create new thread.
 *
 * @param func Pointer to function to run in thread.
 * @param arg Argument to pass to thread function.
 * @return Handle to thread, 0 if failed.
 */
CORTO_EXPORT 
corto_thread corto_thread_new(
    corto_thread_cb func, 
    void* arg);

/** Join a thread.
 * Blocks until the specified thread exits.
 *
 * @param thread Handle to thread to join.
 * @param arg Pointer that will be set to return value of thread.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_thread_join(
    corto_thread thread, 
    void **arg);

/** Detach a thread.
 * Enables automatic cleanup of resources once a thread exits and removes the
 * need to call corto_thread_join.
 *
 * @param thread Handle to thread to detach.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_thread_detach(
    corto_thread thread);

/** Set priority of a thread.
 *
 * @param thread Handle to thread to detach.
 * @param priority Priority to set.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_thread_setPriority(
    corto_thread thread, 
    int priority);

/** Get priority of a thread.
 *
 * @param thread Handle to thread to detach.
 * @return Priority of thread.
 */
CORTO_EXPORT 
int corto_thread_getPriority(
    corto_thread thread);

/** Return handle of current thread.
 *
 * @return handle to thread.
 */
CORTO_EXPORT 
corto_thread corto_thread_self(void);



/* -- Thread local storage -- */

/** Generate a new tls key.
 *
 * @param key_out Pointer to variable that will hold new tls key.
 * @param destructor Function that will be invoked when tls data is cleaned up.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_tls_new(
    corto_tls* key_out, 
    void(*destructor)(void*));

/** Set thread specific data for tls key.
 *
 * @param key Key for which to set the tls data.
 * @param value Value to assign to tls storage.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_tls_set(
    corto_tls key, 
    void* value);

/** Get thread specific data for tls key.
 *
 * @param key Key for which to get the tls data.
 * @return tls storage corresponding to key. NULL if not set.
 */
CORTO_EXPORT 
void* corto_tls_get(
    corto_tls key);

/** Free tls data in main thread.
 * Sometimes thread libraries do not cleanup tls data automatically in the
 * mainthread. To ensure that there are no memory leaks, call this function
 * before exitting the application to ensure memory logs are clean.
 *
 * The corto_stop function calls this function.
 */
CORTO_EXPORT 
void corto_tls_free(void);



/* -- Mutex operations -- */

typedef struct corto_mutex_s* corto_mutex;

/** Create new mutex.
 *
 * @param mutex Pointer to uninitialized corto_mutex_s structure.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_mutex_new(
    struct corto_mutex_s *mutex);

/** Lock mutex
 *
 * @param mutex Mutex to lock.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_mutex_lock(
    corto_mutex mutex);

/** Unlock mutex
 *
 * @param mutex Mutex to unlock.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_mutex_unlock(
    corto_mutex mutex);

/** Free mutex resources.
 *
 * @param mutex Mutex to free.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_mutex_free(
    corto_mutex mutex);

/** Try to lock mutex.
 * If another thread already holds the mutex, the function will fail.
 *
 * @param mutex Mutex to free.
 * @return 0 if mutex is free, CORTO_LOCK_BUSY if occupied, other value if failed.
 */
CORTO_EXPORT 
int corto_mutex_try(
    corto_mutex mutex);

/** Try to lock mutex for specified amount of time.
 * If a lock cannot be obtained within the specified timeout period, acquiring
 * the mutex will fail.
 *
 * @param mutex Mutex to lock.
 * @param timeout The maximum amount of time to try to lock the mutex.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_mutex_lockTimed(
    corto_mutex mutex, 
    struct timespec timeout);



/* -- Read-write mutex -- */
typedef struct corto_rwmutex_s* corto_rwmutex;


/** Create new read-write mutex.
 *
 * @param mutex Pointer to uninitialized corto_rwmutex_s structure.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_new(
    struct corto_rwmutex_s *mutex);

/** Read read-write mutex.
 * Multiple threads may simultaneously read a resource protected by a read-write
 * mutex.
 *
 * @param mutex Mutex to read.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_read(
    corto_rwmutex mutex);

/** Write read-write mutex.
 * Only one thread may simultaneously write a resource protected by a read-write
 * mutex.
 *
 * @param mutex Mutex to read.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_write(
    corto_rwmutex mutex);

/** Try reading read-write mutex.
 * If another thread is already writing the mutex, this function will fail.
 *
 * @param mutex Mutex to read.
 * @return 0 if success, CORTO_LOCK_BUSY if busy, other value if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_tryRead(
    corto_rwmutex mutex);

/** Try writing read-write mutex.
 * If another thread is already reading or writing the mutex, this function will
 * fail.
 *
 * @param mutex Mutex to write.
 * @return 0 if success, CORTO_LOCK_BUSY if busy, other value if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_tryWrite(
    corto_rwmutex mutex);

/** Unlock read-write mutex.
 * Needs to be called after successfully obtaining a read or write lock.
 *
 * @param mutex Mutex to unlock.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_unlock(
    corto_rwmutex mutex);

/** Free read-write mutex resources.
 *
 * @param mutex Mutex to free.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rwmutex_free(
    corto_rwmutex mutex);



/* -- Semaphores -- */

typedef struct corto_sem_s* corto_sem;

/** Create new semaphore.
 *
 * @param initValue Initial value of semaphore.
 * @return Handle to new semaphore. NULL if failed.
 */
CORTO_EXPORT 
corto_sem corto_sem_new(
    unsigned int initValue);

/** Increase value of semaphore.
 *
 * @param sem Handle to semaphore.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_sem_post(
    corto_sem sem);

/** Decrease value of semaphore, block if zero.
 *
 * @param sem Handle to semaphore.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_sem_wait(
    corto_sem sem);

/** Try decreasing value of semaphore, do not block if zero.
 *
 * @param sem Handle to semaphore.
 * @return 0 if success, CORTO_LOCK_BUSY if empty, non-zero if failed.
 */
CORTO_EXPORT 
int corto_sem_tryWait(
    corto_sem sem);

/** Get current value of semaphore.
 *
 * @param sem Handle to semaphore.
 * @return Value of current semaphore.
 */
CORTO_EXPORT 
int corto_sem_value(
    corto_sem sem);

/** Free semaphore resources.
 *
 * @param sem Handle to semaphore.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_sem_free(
    corto_sem sem);



/* -- Atomic increments and decrements -- */

/** Atomically increment integer value.
 * Even if multiple threads simultaneously are calling corto_ainc, it is
 * guaranteed that count will be increased by the number of times corto_ainc
 * is invoked.
 *
 * @param count Value to increment.
 * @return Value after incrementing.
 */
CORTO_EXPORT 
int corto_ainc(
    int* count);

/** Atomically decrement integer value.
 * Even if multiple threads simultaneously are calling corto_adec, it is
 * guaranteed that count will be increased by the number of times corto_ainc
 * is invoked.
 * 
 * @param count Value to decrement.
 * @return Value after decrementing.
 */
CORTO_EXPORT 
int corto_adec(
    int* count);

/** Atomic compare and swap.
 * Only set ptr to new value if the value of ptr equals old value.
 */
#define corto_cas(ptr, old, new) __sync_bool_compare_and_swap(ptr, old, new)


/* Platform-specific public definitions for increased efficiency. */
#include "corto/posix_thread.h"

#ifdef __cplusplus
}
#endif

#endif
