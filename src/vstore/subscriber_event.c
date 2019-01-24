/* This is a managed file. Do not delete this comment. */

#include <corto>

#include "src/store/object.h"

void corto_subscriber_event_deinit(
    corto_subscriber_event* this)
{
    if (this->fmt.handle && this->data.value) {
        corto_fmt_data_deinit(&this->fmt);
    }
}

void corto_subscriber_event_handle(
    corto_event *e)
{
    corto_function f = corto_function(((corto_subscriber_event*)e)->subscriber);

    if (f->kind == CORTO_PROCEDURE_CDECL) {
        ((void(*)(corto_event*))f->fptr)(e);
    } else {
        corto_invoke(f, NULL, e);
    }
}

int16_t corto_subscriber_event_init(
    corto_subscriber_event* this)
{
    ((corto_event*)this)->handleAction.super.procedure = corto_subscriber_event_handle_o;
    return 0;
}
