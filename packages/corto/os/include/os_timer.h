/* os_timer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_timer_H
#define os_timer_H

#include "corto.h"
#include "os_thread.h"
#include "os__type.h"
#include "os__api.h"
#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::os::timer::run() */
cx_void _os_timer_run(os_timer _this);
#define os_timer_run(_this) _os_timer_run(os_timer(_this))

/* ::corto::os::timer::stop() */
cx_void _os_timer_stop(os_timer _this);
#define os_timer_stop(_this) _os_timer_stop(os_timer(_this))

#ifdef __cplusplus
}
#endif
#endif

