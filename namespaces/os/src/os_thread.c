/* os_thread.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"
#include "os__meta.h"

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::os::thread::construct(::hyve::os::thread object) */
db_int16 os_thread_construct(os_thread object) {
/* $begin(::hyve::os::thread::construct) */
	DB_UNUSED(object);

    return 0;
/* $end */
}

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::os::thread::destruct(::hyve::os::thread object) */
db_void os_thread_destruct(os_thread object) {
/* $begin(::hyve::os::thread::destruct) */

    if (object->handle) {
        db_threadJoin(object->handle, NULL);
        db_threadDetach(object->handle);
    }
/* $end */
}

/* ::hyve::os::thread::join() */
db_void os_thread_join(os_thread _this) {
/* $begin(::hyve::os::thread::join) */

    db_threadJoin(_this->handle, NULL);
    db_threadDetach(_this->handle);
    _this->handle = 0;

/* $end */
}

/* ::hyve::os::thread::run() */
db_void os_thread_run_v(os_thread _this) {
/* $begin(::hyve::os::thread::run) */
    db_call(db_function(os_thread_run_o),NULL,_this);
/* $end */
}

/* ::hyve::os::thread::start() */
db_void os_thread_start(os_thread _this) {
/* $begin(::hyve::os::thread::start) */
    db_context context;

    /* Signal contextswitch to bindings */
    context = db_contextSwitch(_this);

    _this->handle = db_threadNew((db_threadFunc)os_thread_run_v, context);
/* $end */
}

/* ::hyve::os::thread::stop() */
db_void os_thread_stop(os_thread _this) {
/* $begin(::hyve::os::thread::stop) */

    _this->stopping = TRUE;

/* $end */
}
