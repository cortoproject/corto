/* $CORTO_GENERATED
 *
 * subscriberEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"
/* $end */

corto_int16 _corto_subscriberEvent_construct(
    corto_subscriberEvent this)
{
/* $begin(corto/core/subscriberEvent/construct) */
    CORTO_UNUSED(this);
    return 0;
/* $end */
}

corto_void _corto_subscriberEvent_destruct(
    corto_subscriberEvent this)
{
/* $begin(corto/core/subscriberEvent/destruct) */
    if (this->contentTypeHandle && this->result.value) {
        ((corto_contentType)this->contentTypeHandle)->release(this->result.value);
    }

/* $end */
}

corto_void _corto_subscriberEvent_handle_v(
    corto_subscriberEvent this)
{
/* $begin(corto/core/subscriberEvent/handle) */
    corto_observableEvent e = corto_observableEvent(this);
    corto_function f = corto_function(e->observer);

    if (f->kind == CORTO_PROCEDURE_CDECL) {
        ((void(*)(
          corto_object,
          corto_eventMask,
          corto_result*,
          corto_subscriber))f->fptr
        )(e->me, e->mask, &this->result, corto_subscriber(e->observer));
    } else {
        corto_call(f, NULL, e->me, e->mask, &this->result, e->observer);
    }

    corto_event_handle_v(corto_event(this));

/* $end */
}
