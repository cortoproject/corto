/* cx_event.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
static int cx_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */
/* $end */

/* ::corto::lang::event::handle() */
cx_void _cx_event_handle_v(cx_event _this) {
/* $begin(::corto::lang::event::handle) */
    _this->handled = TRUE;
/* $end */
}

/* ::corto::lang::event::uniqueKind() */
cx_int16 _cx_event_uniqueKind(void) {
/* $begin(::corto::lang::event::uniqueKind) */
    int result = cx_ainc(&cx_maxEventId)-1;
    if (result == 65535) {
        cx_critical("event-kinds exhausted (>=65536)!");
    }
    return result;
/* $end */
}
