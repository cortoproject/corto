/* corto_event.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
static int corto_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */
/* $end */

/* ::corto::lang::event::handle() */
corto_void _corto_event_handle_v(corto_event this) {
/* $begin(::corto::lang::event::handle) */
    this->handled = TRUE;
/* $end */
}

/* ::corto::lang::event::uniqueKind() */
corto_int16 _corto_event_uniqueKind(void) {
/* $begin(::corto::lang::event::uniqueKind) */
    int result = corto_ainc(&corto_maxEventId)-1;
    if (result == 65535) {
        corto_critical("event-kinds exhausted (>=65536)!");
    }
    return result;
/* $end */
}
