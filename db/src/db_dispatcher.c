/* cx_dispatcher.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* ::cortex::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
cx_observableEvent cx_dispatcher_getEvent_v(cx_dispatcher _this, cx_observer observer, cx_object me, cx_object observable, cx_object src) {
/* $begin(::cortex::lang::dispatcher::getEvent) */

    DB_UNUSED(_this);
    DB_UNUSED(observer);
    DB_UNUSED(me);
    DB_UNUSED(observable);
    DB_UNUSED(src);
    return NULL;

/* $end */
}

/* ::cortex::lang::dispatcher::post(lang::event event) */
cx_void cx_dispatcher_post_v(cx_dispatcher _this, cx_event event) {
/* $begin(::cortex::lang::dispatcher::post) */

    DB_UNUSED(_this);
    DB_UNUSED(event);

/* $end */
}
