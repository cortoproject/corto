/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

void corto_observer_event_deinit(
    corto_observer_event* this)
{

    CORTO_UNUSED(this);

}

void corto_observer_event_handle(
    corto_event *e)
{
    corto_observer_event *this = (corto_observer_event*)e;
    corto_bool lockRequired =
      (this->thread != corto_thread_self()) &&
      !(this->event & CORTO_DELETE);

    /* Don't readlock event for DELETE events */
    if (!lockRequired || !corto_read_begin(this->data)) {
        corto_function f = corto_function(this->observer);

        if (f->kind == CORTO_PROCEDURE_CDECL) {
            ((void(*)(corto_observer_event*))f->fptr)(this);
        } else {
            corto_invoke(f, NULL, this);
        }

        if (lockRequired) {
            corto_read_end(this->data);
        }
    } else {
        /* Error */
        corto_raise();
    }

}

int16_t corto_observer_event_init(
    corto_observer_event* this)
{
    ((corto_event*)this)->handleAction.super.procedure = corto_observer_event_handle_o;
    return 0;
}
