/* $CORTO_GENERATED
 *
 * corto_observableEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

corto_void _corto_observableEvent_handle_v(corto_observableEvent this) {
/* $begin(corto/lang/observableEvent/handle) */
    corto_call(corto_function(this->observer), NULL, this->me, this->observable, this->source);
    corto_event_handle_v(corto_event(this));
/* $end */
}
