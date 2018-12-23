/* This is a managed file. Do not delete this comment. */

#include <corto>

void corto_event_handle(
    corto_event* this)
{
    void *args[] = {&this};
    corto_invokeb(this->handleAction.super.procedure, NULL, args);
}
