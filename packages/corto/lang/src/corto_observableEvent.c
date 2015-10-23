/* corto_observableEvent.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::observableEvent::handle() */
corto_void _corto_observableEvent_handle_v(corto_observableEvent this) {
/* $begin(::corto::lang::observableEvent::handle) */
    corto_call(corto_function(this->observer), NULL, this->me, this->observable, this->source);
    corto_event_handle_v(corto_event(this));
/* $end */
}
