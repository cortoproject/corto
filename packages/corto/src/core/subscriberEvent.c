/* $CORTO_GENERATED
 *
 * subscriberEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

/* $header() */
#include "_object.h"
/* $end */

void _corto_subscriberEvent_deinit(
    corto_subscriberEvent* this)
{
/* $begin(corto/core/subscriberEvent/deinit) */

    if (this->contentTypeHandle && this->data.value) {
        ((corto_contentType)this->contentTypeHandle)->release(this->data.value);
    }

/* $end */
}

void _corto_subscriberEvent_handle(
    corto_event *e)
{
/* $begin(corto/core/subscriberEvent/handle) */
    corto_function f = corto_function(((corto_subscriberEvent*)e)->subscriber);

    if (f->kind == CORTO_PROCEDURE_CDECL) {
        ((void(*)(corto_event*))f->fptr)(e);
    } else {
        corto_call(f, NULL, e);
    }

/* $end */
}

int16_t _corto_subscriberEvent_init(
    corto_subscriberEvent* this)
{
/* $begin(corto/core/subscriberEvent/init) */
    ((corto_event*)this)->handleAction.super.procedure = corto_subscriberEvent_handle_o;
    return 0;
/* $end */
}
