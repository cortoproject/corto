/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include "src/store/object.h"

void corto_subscriberEvent_deinit(
    corto_subscriberEvent* this)
{
    if (this->contentTypeHandle && this->data.value) {
        ((corto_fmt)this->contentTypeHandle)->release(this->data.value);
    }
}

void corto_subscriberEvent_handle(
    corto_event *e)
{
    corto_function f = corto_function(((corto_subscriberEvent*)e)->subscriber);

    if (f->kind == CORTO_PROCEDURE_CDECL) {
        ((void(*)(corto_event*))f->fptr)(e);
    } else {
        corto_invoke(f, NULL, e);
    }
}

int16_t corto_subscriberEvent_init(
    corto_subscriberEvent* this)
{
    ((corto_event*)this)->handleAction.super.procedure = corto_subscriberEvent_handle_o;
    return 0;
}

