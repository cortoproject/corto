/* $CORTO_GENERATED
 *
 * os_thread.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "os.h"

corto_int16 _os_thread_construct(os_thread this) {
/* $begin(::corto::os::thread::construct) */
    CORTO_UNUSED(this);

    return 0;
/* $end */
}

corto_void _os_thread_destruct(os_thread this) {
/* $begin(::corto::os::thread::destruct) */

    if (this->handle) {
        corto_threadJoin(this->handle, NULL);
        corto_threadDetach(this->handle);
    }
/* $end */
}

corto_void _os_thread_join(os_thread this) {
/* $begin(::corto::os::thread::join) */

    corto_threadJoin(this->handle, NULL);
    corto_threadDetach(this->handle);
    this->handle = 0;

/* $end */
}

corto_void _os_thread_run_v(os_thread this) {
/* $begin(::corto::os::thread::run) */
    corto_call(corto_function(os_thread_run_o),NULL,this);
/* $end */
}

corto_void _os_thread_start(os_thread this) {
/* $begin(::corto::os::thread::start) */
    corto_context context;

    /* Signal contextswitch to bindings */
    context = corto_contextSwitch(this);

    this->handle = corto_threadNew((corto_threadFunc)_os_thread_run_v, context);
/* $end */
}

corto_void _os_thread_stop(os_thread this) {
/* $begin(::corto::os::thread::stop) */

    this->stopping = TRUE;

/* $end */
}
