/* os__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef os_META_H
#define os_META_H

#include "corto.h"

#include "os__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::os */
extern cx_package os_o;

/* ::corto::os::exit(bool success) */
extern cx_function os_exit_o;

/* ::corto::os::sleep(uint32 sec,uint32 nsec) */
extern cx_function os_sleep_o;

/* ::corto::os::system(string cmd) */
extern cx_function os_system_o;

/* ::corto::os::thread */
extern cx_class os_thread_o;

/* ::corto::os::thread::construct() */
extern cx_method os_thread_construct_o;

/* ::corto::os::thread::destruct() */
extern cx_method os_thread_destruct_o;

/* ::corto::os::thread::handle */
extern cx_member os_thread_handle_o;

/* ::corto::os::thread::join() */
extern cx_method os_thread_join_o;

/* ::corto::os::thread::run() */
extern cx_virtual os_thread_run_o;

/* ::corto::os::thread::start() */
extern cx_method os_thread_start_o;

/* ::corto::os::thread::stop() */
extern cx_method os_thread_stop_o;

/* ::corto::os::thread::stopping */
extern cx_member os_thread_stopping_o;

/* ::corto::os::time */
extern cx_class os_time_o;

/* ::corto::os::time::add(::corto::os::time t) */
extern cx_method os_time_add_o;

/* ::corto::os::time::get() */
extern cx_method os_time_get_o;

/* ::corto::os::time::nanoseconds */
extern cx_member os_time_nanoseconds_o;

/* ::corto::os::time::seconds */
extern cx_member os_time_seconds_o;

/* ::corto::os::time::sub(::corto::os::time t) */
extern cx_method os_time_sub_o;

/* ::corto::os::time::toFloat() */
extern cx_method os_time_toFloat_o;

/* ::corto::os::timer */
extern cx_class os_timer_o;

/* ::corto::os::timer::nanosec */
extern cx_member os_timer_nanosec_o;

/* ::corto::os::timer::run() */
extern cx_method os_timer_run_o;

/* ::corto::os::timer::sec */
extern cx_member os_timer_sec_o;

/* ::corto::os::timer::stop() */
extern cx_method os_timer_stop_o;

int os_load(void);
#ifdef __cplusplus
}
#endif
#endif

