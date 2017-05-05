/* $CORTO_GENERATED
 *
 * observerEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

void _corto_observerEvent_deinit(
    corto_observerEvent* this)
{
/* $begin(corto/core/observerEvent/deinit) */

    CORTO_UNUSED(this);

/* $end */
}

void _corto_observerEvent_handle(
    corto_event *e)
{
/* $begin(corto/core/observerEvent/handle) */
    corto_observerEvent *this = (corto_observerEvent*)e;
    corto_bool lockRequired =
      (this->thread != corto_threadSelf()) &&
      !(this->event & CORTO_ON_DELETE);

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
        corto_error("%s", corto_lasterr());
        corto_backtrace(stderr);
    }

/* $end */
}

int16_t _corto_observerEvent_init(
    corto_observerEvent* this)
{
/* $begin(corto/core/observerEvent/init) */
    ((corto_event*)this)->handleAction.super.procedure = corto_observerEvent_handle_o;
    return 0;
/* $end */
}
