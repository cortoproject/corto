/* $CORTO_GENERATED
 *
 * corto_invokeEvent.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "corto.h"

corto_void _corto_invokeEvent_handle_v(corto_invokeEvent this) {
/* $begin(::corto::lang::invokeEvent::handle) */

	corto_invokeActionCall(&this->replicator->onInvoke, this->instance, this->function, this->args);

/* $end */
}
