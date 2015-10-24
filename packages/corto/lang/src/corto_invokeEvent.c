/* corto_invokeEvent.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::invokeEvent::handle() */
corto_void _corto_invokeEvent_handle_v(corto_invokeEvent this) {
/* $begin(::corto::lang::invokeEvent::handle) */

	corto_invokeActionCall(&this->replicator->onInvoke, this->instance, this->function, this->args);

/* $end */
}