/* os_thread.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* ::corto::os::thread::construct() */
cx_int16 _os_thread_construct(os_thread _this) {
/* $begin(::corto::os::thread::construct) */
    CX_UNUSED(_this);

    return 0;
/* $end */
}

/* ::corto::os::thread::destruct() */
cx_void _os_thread_destruct(os_thread _this) {
/* $begin(::corto::os::thread::destruct) */

    if (_this->handle) {
        cx_threadJoin(_this->handle, NULL);
        cx_threadDetach(_this->handle);
    }
/* $end */
}

/* ::corto::os::thread::join() */
cx_void _os_thread_join(os_thread _this) {
/* $begin(::corto::os::thread::join) */

    cx_threadJoin(_this->handle, NULL);
    cx_threadDetach(_this->handle);
    _this->handle = 0;

/* $end */
}

/* ::corto::os::thread::run() */
cx_void _os_thread_run_v(os_thread _this) {
/* $begin(::corto::os::thread::run) */
    cx_call(cx_function(os_thread_run_o),NULL,_this);
/* $end */
}

/* ::corto::os::thread::start() */
cx_void _os_thread_start(os_thread _this) {
/* $begin(::corto::os::thread::start) */
    cx_context context;

    /* Signal contextswitch to bindings */
    context = cx_contextSwitch(_this);

    _this->handle = cx_threadNew((cx_threadFunc)_os_thread_run_v, context);
/* $end */
}

/* ::corto::os::thread::stop() */
cx_void _os_thread_stop(os_thread _this) {
/* $begin(::corto::os::thread::stop) */

    _this->stopping = TRUE;

/* $end */
}
