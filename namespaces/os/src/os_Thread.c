/* os_thread.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os_thread.h"
#include "os__meta.h"


/* $begin($header) */
#include "db_async.h"
#include "db_call.h"

/* Threadfunction */
void* os_Thread__run(void* context) {
    os_thread thr;

    /* Restore context for bindings */
    thr = db_contextRestore(context);

    /* Call virtual run-method */
	os_thread_run(thr);

	return NULL;
}

/* $end */

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

/* virtual ::hyve::os::thread::run() */
void os_thread_run(os_thread _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "run()");
    }
    db_assert(_methodId, "virtual method 'run()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::run()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::run()'.", db_nameof(_this));
        ((void(*)(os_thread))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), NULL, _this);
    }
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

    _this->handle = db_threadNew(os_Thread__run, context);
/* $end */
}

/* ::hyve::os::thread::stop() */
db_void os_thread_stop(os_thread _this) {
/* $begin(::hyve::os::thread::stop) */

    _this->stopping = TRUE;

/* $end */
}
