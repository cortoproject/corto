/* $CORTO_GENERATED
 *
 * observer.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/core/core.h"

/* $header() */
#include "../lang/_class.h"
/* $end */

corto_int16 _corto_observer_bind(
    corto_observer this)
{
/* $begin(corto/core/observer/bind) */

    /* If this is a scoped observer, automatically bind with parent if it's a class. */
    if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        this->_template = 1;
    }

    /* Listen to observable */
    if (!this->_template) {
        if (corto_observer_listen(this, this->observable, this->me)) {
            goto error;
        }
    }

    return corto_function_bind(this);
error:
    return -1;
/* $end */
}

corto_int16 _corto_observer_init(
    corto_observer this)
{
/* $begin(corto/core/observer/init) */
    corto_parameter *p;

    corto_setref(&corto_function(this)->returnType, corto_void_o);

    /* Set parameters of observer: (this, observable, source) */
    corto_function(this)->parameters.buffer = corto_calloc(sizeof(corto_parameter) * 1);
    corto_function(this)->parameters.length = 1;

    /* Parameter observable */
    p = &corto_function(this)->parameters.buffer[0];
    p->name = corto_strdup("observable");
    p->passByReference = TRUE;
    if (this->observable && (!(this->mask & CORTO_ON_SCOPE) && !(this->mask & CORTO_ON_DECLARE))) {
        corto_setref(&p->type, corto_typeof(this->observable));
    } else {
        corto_setref(&p->type, corto_type(corto_object_o));
    }

    return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
/* $end */
}

corto_int16 _corto_observer_listen(
    corto_observer this,
    corto_object observable,
    corto_object me)
{
/* $begin(corto/core/observer/listen) */
    corto_object oldObservable = NULL;

    /* Silence old observable */
    if (!this->_template) {
        oldObservable = this->observable;
        corto_setref(&this->observable, observable);
    } else {
        corto_critical("don't use observer::listen for instance observers (use class::listen)");
    }

    if (oldObservable) {
        corto_silence(me, this, this->mask, oldObservable);
    }

    if (observable) {
        if (!me || corto_checkState(me, CORTO_DEFINED)) {
            if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
                corto_listen(me, this, this->mask, observable, this->dispatcher);
            } else {
                if (!this->_template) {
                    corto_seterr("cannot observe non-observable object '%s'",
                        corto_fullpath(NULL, observable));
                    goto error;
                }
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_observer_setDispatcher(
    corto_observer this,
    corto_dispatcher dispatcher)
{
/* $begin(corto/core/observer/setDispatcher) */
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
    corto_setref(&this->dispatcher, dispatcher);
/* $end */
}

corto_int16 _corto_observer_silence(
    corto_observer this,
    corto_object me)
{
/* $begin(corto/core/observer/silence) */
    corto_object oldObservable = NULL;

    /* Silence old observable */
    if (!this->_template) {
        oldObservable = this->observable;
        corto_setref(&this->observable, NULL);
    } else {
        corto_critical("don't use observer::silence for instance observers (use class::silence)");
    }

    if (oldObservable) {
        corto_silence(me, this, this->mask, oldObservable);
    }

    return 0;
/* $end */
}

corto_void _corto_observer_unbind(
    corto_observer object)
{
/* $begin(corto/core/observer/unbind) */
    if (!object->_template) {
        if (object->observable) {
            corto_silence(object->me, object, object->mask, object->observable);
        }
    }

    corto_function_unbind(corto_function(object));
/* $end */
}
