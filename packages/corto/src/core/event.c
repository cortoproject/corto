/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


static int corto_maxEventId = 16; /* kind 0 - 15 are reserved for internal usage */

void corto_event_handle(
    corto_event* this)
{
    void *args[] = {&this};
    corto_callb(this->handleAction.super.procedure, NULL, args);
    this->handled = TRUE;
}

int16_t corto_event_uniqueKind(void)
{
    int result = corto_ainc(&corto_maxEventId)-1;
    if (result == 65535) {
        corto_critical("event-kinds exhausted (>=65536)!");
    }
    return result;
}

