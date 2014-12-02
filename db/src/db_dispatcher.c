/* db_dispatcher.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
db_observableEvent db_dispatcher_getEvent_v(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src) {
/* $begin(::hyve::lang::dispatcher::getEvent) */

    DB_UNUSED(_this);
    DB_UNUSED(observer);
    DB_UNUSED(me);
    DB_UNUSED(observable);
    DB_UNUSED(src);
    return NULL;

/* $end */
}

/* ::hyve::lang::dispatcher::post(lang::event event) */
db_void db_dispatcher_post_v(db_dispatcher _this, db_event event) {
/* $begin(::hyve::lang::dispatcher::post) */

    DB_UNUSED(_this);
    DB_UNUSED(event);

/* $end */
}
