/* os_timer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_os_LIB
#include "os.h"

/* $header() */
#include "cx_time.h"
/* $end */

/* ::corto::os::timer::run() */
cx_void _os_timer_run(os_timer this) {
/* $begin(::corto::os::timer::run) */

    while(!this->_base.stopping) {
        cx_sleep(this->sec, this->nanosec);
        cx_update(this);
    }

/* $end */
}

/* ::corto::os::timer::stop() */
cx_void _os_timer_stop(os_timer this) {
/* $begin(::corto::os::timer::stop) */

    /*os_thread_stop_v(os_thread(this));*/
    os_thread_join(os_thread(this));

/* $end */
}
