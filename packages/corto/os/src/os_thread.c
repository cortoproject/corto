/* os_thread.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* ::corto::os::thread::construct() */
corto_int16 _os_thread_construct(os_thread this) {
/* $begin(::corto::os::thread::construct) */
    CORTO_UNUSED(this);

    return 0;
/* $end */
}

/* ::corto::os::thread::destruct() */
corto_void _os_thread_destruct(os_thread this) {
/* $begin(::corto::os::thread::destruct) */

    if (this->handle) {
        corto_threadJoin(this->handle, NULL);
        corto_threadDetach(this->handle);
    }
/* $end */
}

/* ::corto::os::thread::join() */
corto_void _os_thread_join(os_thread this) {
/* $begin(::corto::os::thread::join) */

    corto_threadJoin(this->handle, NULL);
    corto_threadDetach(this->handle);
    this->handle = 0;

/* $end */
}

/* ::corto::os::thread::run() */
corto_void _os_thread_run_v(os_thread this) {
/* $begin(::corto::os::thread::run) */
    corto_call(corto_function(os_thread_run_o),NULL,this);
/* $end */
}

/* ::corto::os::thread::start() */
corto_void _os_thread_start(os_thread this) {
/* $begin(::corto::os::thread::start) */
    corto_context context;

    /* Signal contextswitch to bindings */
    context = corto_contextSwitch(this);

    this->handle = corto_threadNew((corto_threadFunc)_os_thread_run_v, context);
/* $end */
}

/* ::corto::os::thread::stop() */
corto_void _os_thread_stop(os_thread this) {
/* $begin(::corto::os::thread::stop) */

    this->stopping = TRUE;

/* $end */
}
