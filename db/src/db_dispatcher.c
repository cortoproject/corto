/*
 * db_dispatcher.c
 *
 *  Created on: Feb 9, 2013
 *      Author: sander
 */

#include "db_dispatcher.h"
#include "db_util.h"
#include "db_err.h"
#include "db_async.h"
#include "db_class.h"
#include "db_object.h"
#include "db_call.h"
#include "db__meta.h"

static int db_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */

void db_dispatcher_post(db_dispatcher _this, db_event event) {
	static db_uint32 db_dispatcher_postId;
	db_method m;

	/* Resolve method post */
	if (!db_dispatcher_postId) {
		db_dispatcher_postId = db_interface_resolveMethodId(db_dispatcher_o, "post");
		db_assert(db_dispatcher_postId, "abstract dispatcher has no method 'post'");
	}

	/* Obtain implementation method */
	m = db_class_resolveInterfaceMethod(db_class(db_typeof(_this)), db_dispatcher_o, db_dispatcher_postId);
	if (!m) {
		db_id id;
		db_critical("class '%s' does not implement method dispatcher::post.", db_fullname(db_typeof(_this), id));
	}

    db_call(db_function(m), NULL, _this, event);
}

db_event db_dispatcher_getEvent(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object source) {
    static db_uint32 db_dispatcher_getEventId;
    db_method m;
    db_event result;

    /* Resolve method post */
    if (!db_dispatcher_getEventId) {
        db_dispatcher_getEventId = db_interface_resolveMethodId(db_dispatcher_o, "getEvent");
        db_assert(db_dispatcher_getEventId, "abstract dispatcher has no method 'post'");
    }

    /* Obtain implementation method */
    m = db_class_resolveInterfaceMethod(db_class(db_typeof(_this)), db_dispatcher_o, db_dispatcher_getEventId);
    if (!m) {
        db_id id;
        db_critical("class '%s' does not implement method dispatcher::getEvent.", db_fullname(db_typeof(_this), id));
    }

    db_call(db_function(m), &result, _this, observer, me, observable, source);

    return result;
}

db_int16 db_event_uniqueKind(void) {
	int result = db_ainc(&db_maxEventId)-1;
	if (result == 65535) {
		db_critical("event-kinds exhausted (>=65536)!");
	}
	return result;
}

void db_event_processed(db_event event) {
    event->handled = TRUE;
}
