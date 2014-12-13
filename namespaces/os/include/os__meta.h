/* os__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef os_META_H
#define os_META_H

#include "hyve.h"

#include "os__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve */
extern db_object _o;

/* ::hyve::os */
extern db_void (*os_o);

/* ::hyve::os::exit(::hyve::lang::bool success) */
extern db_function os_exit_o;

/* ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) */
extern db_function os_loadavg_o;

/* ::hyve::os::loadAvgKind */
extern db_enum os_loadAvgKind_o;

/* ::hyve::os::loadAvgKind::MIN_1 */
extern db_constant (*os_loadAvgKind_MIN_1_o);

/* ::hyve::os::loadAvgKind::MIN_15 */
extern db_constant (*os_loadAvgKind_MIN_15_o);

/* ::hyve::os::loadAvgKind::MIN_5 */
extern db_constant (*os_loadAvgKind_MIN_5_o);

/* ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) */
extern db_function os_sleep_o;

/* ::hyve::os::system(::hyve::lang::string cmd) */
extern db_function os_system_o;

/* ::hyve::os::thread */
extern db_class os_thread_o;

/* ::hyve::os::thread::construct(::hyve::os::thread object) */
extern db_callback os_thread_construct_o;

/* ::hyve::os::thread::destruct(::hyve::os::thread object) */
extern db_callback os_thread_destruct_o;

/* ::hyve::os::thread::handle */
extern db_member os_thread_handle_o;

/* ::hyve::os::thread::join() */
extern db_method os_thread_join_o;

/* ::hyve::os::thread::run() */
extern db_virtual os_thread_run_o;

/* ::hyve::os::thread::start() */
extern db_method os_thread_start_o;

/* ::hyve::os::thread::stop() */
extern db_method os_thread_stop_o;

/* ::hyve::os::thread::stopping */
extern db_member os_thread_stopping_o;

/* ::hyve::os::time */
extern db_class os_time_o;

/* ::hyve::os::time::add(::hyve::os::time t) */
extern db_method os_time_add_o;

/* ::hyve::os::time::get() */
extern db_method os_time_get_o;

/* ::hyve::os::time::nanoseconds */
extern db_member os_time_nanoseconds_o;

/* ::hyve::os::time::seconds */
extern db_member os_time_seconds_o;

/* ::hyve::os::time::sub(::hyve::os::time t) */
extern db_method os_time_sub_o;

/* ::hyve::os::time::toFloat() */
extern db_method os_time_toFloat_o;

/* ::hyve::os::timer */
extern db_class os_timer_o;

/* ::hyve::os::timer::nanosec */
extern db_member os_timer_nanosec_o;

/* ::hyve::os::timer::run() */
extern db_method os_timer_run_o;

/* ::hyve::os::timer::sec */
extern db_member os_timer_sec_o;

/* ::hyve::os::timer::stop() */
extern db_method os_timer_stop_o;

int os_load(void);
#ifdef __cplusplus
}
#endif
#endif

