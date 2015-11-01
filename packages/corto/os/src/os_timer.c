/* $CORTO_GENERATED
 *
 * os_timer.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "os.h"

/* $header() */
#include "corto_time.h"
/* $end */

corto_void _os_timer_run(os_timer this) {
/* $begin(::corto::os::timer::run) */

    while(!this->_base.stopping) {
        corto_sleep(this->sec, this->nanosec);
        corto_update(this);
    }

/* $end */
}

corto_void _os_timer_stop(os_timer this) {
/* $begin(::corto::os::timer::stop) */

    /*os_thread_stop_v(os_thread(this));*/
    os_thread_join(os_thread(this));

/* $end */
}
