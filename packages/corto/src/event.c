/* $CORTO_GENERATED
 *
 * corto_event.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/corto.h"

/* $header() */
static int corto_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */
/* $end */

corto_void _corto_event_handle_v(corto_event this) {
/* $begin(corto/lang/event/handle) */
    this->handled = TRUE;
/* $end */
}

corto_int16 _corto_event_uniqueKind(void) {
/* $begin(corto/lang/event/uniqueKind) */
    int result = corto_ainc(&corto_maxEventId)-1;
    if (result == 65535) {
        corto_critical("event-kinds exhausted (>=65536)!");
    }
    return result;
/* $end */
}
