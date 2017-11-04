/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

void corto_observerEvent_deinit(
    corto_observerEvent* this)
{

    CORTO_UNUSED(this);

}

void corto_observerEvent_handle(
    corto_event *e)
{
    corto_observerEvent *this = (corto_observerEvent*)e;
    corto_bool lockRequired =
      (this->thread != corto_thread_self()) &&
      !(this->event & CORTO_DELETE);

    /* Don't readlock event for DELETE events */
    if (!lockRequired || !corto_readBegin(this->data)) {
        corto_function f = corto_function(this->observer);

        if (f->kind == CORTO_PROCEDURE_CDECL) {
            ((void(*)(corto_observerEvent*))f->fptr)(this);
        } else {
            corto_call(f, NULL, this);
        }

        if (lockRequired) {
            corto_readEnd(this->data);
        }
    } else {
        /* Error */
        corto_raise();
    }

}

int16_t corto_observerEvent_init(
    corto_observerEvent* this)
{
    ((corto_event*)this)->handleAction.super.procedure = corto_observerEvent_handle_o;
    return 0;
}

