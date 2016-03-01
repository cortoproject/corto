/* $CORTO_GENERATED
 *
 * invokeEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/core/core.h"

corto_void _corto_invokeEvent_handle_v(
    corto_invokeEvent this)
{
/* $begin(corto/core/invokeEvent/handle) */

    corto_replicator_onInvoke(this->replicator, this->instance, this->function, this->args);

/* $end */
}
