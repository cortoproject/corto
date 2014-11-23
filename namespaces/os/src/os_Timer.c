/* os_timer.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os_timer.h"
#include "os__meta.h"


/* $begin($header) */
#include "db_time.h"
/* $end */

/* ::hyve::os::timer::run() */
db_void os_timer_run(os_timer _this) {
/* $begin(::hyve::os::timer::run) */

    while(!_this->_parent.stopping) {
        db_sleep(_this->sec, _this->nanosec);
        db_update(_this);
    }

/* $end */
}

/* ::hyve::os::timer::stop() */
db_void os_timer_stop(os_timer _this) {
/* $begin(::hyve::os::timer::stop) */

    /*os_thread_stop_v(os_thread(_this));*/
    os_thread_join(os_thread(_this));

/* $end */
}
