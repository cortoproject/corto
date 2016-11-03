/* $CORTO_GENERATED
 *
 * observableEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

corto_void _corto_observableEvent_handle_v(
    corto_observableEvent this)
{
/* $begin(corto/core/observableEvent/handle) */
    corto_bool lockRequired =
      (this->thread != corto_threadSelf()) &&
      !(this->mask & CORTO_ON_DELETE);

    /* Don't readlock event for DELETE events */
    if (!lockRequired || !corto_readBegin(this->observable)) {
        corto_function f = corto_function(this->observer);

        if (f->kind == CORTO_PROCEDURE_CDECL) {
            ((void(*)(
              corto_object,
              corto_eventMask,
              corto_object,
              corto_observer))f->fptr
            )(this->me, this->mask, this->observable, corto_observer(this->observer));
        } else {
            corto_call(f, NULL, this->me, this->mask, this->observable, this->observer);
        }

        if (lockRequired) {
            corto_readEnd(this->observable);
        }
        corto_event_handle_v(corto_event(this));
    } else {
        /* Error */
        corto_error("%s", corto_lasterr());
        corto_backtrace(stderr);
    }
/* $end */
}
