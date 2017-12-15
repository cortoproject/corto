/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

void corto_event_handle(
    corto_event* this)
{
    void *args[] = {&this};
    corto_callb(this->handleAction.super.procedure, NULL, args);
}
