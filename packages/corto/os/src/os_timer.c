/* os_timer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* $header() */
#include "cx_time.h"
/* $end */

/* ::corto::os::timer::run() */
cx_void _os_timer_run(os_timer _this) {
/* $begin(::corto::os::timer::run) */

    while(!_this->_parent.stopping) {
        cx_sleep(_this->sec, _this->nanosec);
        cx_update(_this);
    }

/* $end */
}

/* ::corto::os::timer::stop() */
cx_void _os_timer_stop(os_timer _this) {
/* $begin(::corto::os::timer::stop) */

    /*os_thread_stop_v(os_thread(_this));*/
    os_thread_join(os_thread(_this));

/* $end */
}
