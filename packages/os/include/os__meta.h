/* os__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef os_META_H
#define os_META_H

#include "cortex.h"

#include "os__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::os */
extern cx_package os_o;

/* ::cortex::os::exit(bool success) */
extern cx_function os_exit_o;

/* ::cortex::os::sleep(uint32 sec,uint32 nsec) */
extern cx_function os_sleep_o;

/* ::cortex::os::system(string cmd) */
extern cx_function os_system_o;

/* ::cortex::os::thread */
extern cx_class os_thread_o;

/* ::cortex::os::thread::construct() */
extern cx_method os_thread_construct_o;

/* ::cortex::os::thread::destruct() */
extern cx_method os_thread_destruct_o;

/* ::cortex::os::thread::handle */
extern cx_member os_thread_handle_o;

/* ::cortex::os::thread::join() */
extern cx_method os_thread_join_o;

/* ::cortex::os::thread::run() */
extern cx_virtual os_thread_run_o;

/* ::cortex::os::thread::start() */
extern cx_method os_thread_start_o;

/* ::cortex::os::thread::stop() */
extern cx_method os_thread_stop_o;

/* ::cortex::os::thread::stopping */
extern cx_member os_thread_stopping_o;

/* ::cortex::os::time */
extern cx_class os_time_o;

/* ::cortex::os::time::add(time t) */
extern cx_method os_time_add_o;

/* ::cortex::os::time::get() */
extern cx_method os_time_get_o;

/* ::cortex::os::time::nanoseconds */
extern cx_member os_time_nanoseconds_o;

/* ::cortex::os::time::seconds */
extern cx_member os_time_seconds_o;

/* ::cortex::os::time::sub(time t) */
extern cx_method os_time_sub_o;

/* ::cortex::os::time::toFloat() */
extern cx_method os_time_toFloat_o;

/* ::cortex::os::timer */
extern cx_class os_timer_o;

/* ::cortex::os::timer::nanosec */
extern cx_member os_timer_nanosec_o;

/* ::cortex::os::timer::run() */
extern cx_method os_timer_run_o;

/* ::cortex::os::timer::sec */
extern cx_member os_timer_sec_o;

/* ::cortex::os::timer::stop() */
extern cx_method os_timer_stop_o;

int os_load(void);
#ifdef __cplusplus
}
#endif
#endif

