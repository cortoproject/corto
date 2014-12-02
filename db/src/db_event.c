/* db_event.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
static int db_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */
/* $end */

/* ::hyve::lang::event::processed() */
db_void db_event_processed(db_event _this) {
/* $begin(::hyve::lang::event::processed) */
	_this->handled = TRUE;
/* $end */
}

/* ::hyve::lang::event::uniqueKind() */
db_int16 db_event_uniqueKind(void) {
/* $begin(::hyve::lang::event::uniqueKind) */
	int result = db_ainc(&db_maxEventId)-1;
	if (result == 65535) {
		db_critical("event-kinds exhausted (>=65536)!");
	}
	return result;
/* $end */
}
