/* cx_observableEvent.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::observableEvent::handle() */
cx_void _cx_observableEvent_handle_v(cx_observableEvent this) {
/* $begin(::corto::lang::observableEvent::handle) */
    cx_call(cx_function(this->observer), NULL, this->me, this->observable, this->source);
    cx_event_handle_v(cx_event(this));
/* $end */
}
