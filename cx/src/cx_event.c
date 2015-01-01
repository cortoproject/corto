/* cx_event.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
static int cx_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */
/* $end */

/* ::cortex::lang::event::processed() */
cx_void cx_event_processed(cx_event _this) {
/* $begin(::cortex::lang::event::processed) */
	_this->handled = TRUE;
/* $end */
}

/* ::cortex::lang::event::uniqueKind() */
cx_int16 cx_event_uniqueKind(void) {
/* $begin(::cortex::lang::event::uniqueKind) */
	int result = cx_ainc(&cx_maxEventId)-1;
	if (result == 65535) {
		cx_critical("event-kinds exhausted (>=65536)!");
	}
	return result;
/* $end */
}
