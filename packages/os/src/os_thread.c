/* os_thread.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"
#include "os__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::os::thread::construct(::cortex::os::thread object) */
cx_int16 os_thread_construct(os_thread object) {
/* $begin(::cortex::os::thread::construct) */
    CX_UNUSED(object);

    return 0;
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::os::thread::destruct(::cortex::os::thread object) */
cx_void os_thread_destruct(os_thread object) {
/* $begin(::cortex::os::thread::destruct) */

    if (object->handle) {
        cx_threadJoin(object->handle, NULL);
        cx_threadDetach(object->handle);
    }
/* $end */
}

/* ::cortex::os::thread::join() */
cx_void os_thread_join(os_thread _this) {
/* $begin(::cortex::os::thread::join) */

    cx_threadJoin(_this->handle, NULL);
    cx_threadDetach(_this->handle);
    _this->handle = 0;

/* $end */
}

/* ::cortex::os::thread::run() */
cx_void os_thread_run_v(os_thread _this) {
/* $begin(::cortex::os::thread::run) */
    cx_call(cx_function(os_thread_run_o),NULL,_this);
/* $end */
}

/* ::cortex::os::thread::start() */
cx_void os_thread_start(os_thread _this) {
/* $begin(::cortex::os::thread::start) */
    cx_context context;

    /* Signal contextswitch to bindings */
    context = cx_contextSwitch(_this);

    _this->handle = cx_threadNew((cx_threadFunc)os_thread_run_v, context);
/* $end */
}

/* ::cortex::os::thread::stop() */
cx_void os_thread_stop(os_thread _this) {
/* $begin(::cortex::os::thread::stop) */

    _this->stopping = TRUE;

/* $end */
}
