/* cx_observableEvent.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* ::cortex::lang::observableEvent::handle() */
cx_void cx_observableEvent_handle_v(cx_observableEvent _this) {
/* $begin(::cortex::lang::observableEvent::handle) */
    cx_call(cx_function(_this->observer), NULL, _this->me, _this->observable, _this->source);
    cx_event_handle_v(cx_event(_this));
/* $end */
}
