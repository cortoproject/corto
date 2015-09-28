/* cx_observer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx__class.h"
/* $end */

/* ::corto::lang::observer::bind() */
cx_int16 _cx_observer_bind(cx_observer this) {
/* $begin(::corto::lang::observer::bind) */

    /* If this is a scoped observer, automatically bind with parent if it's a class. */
    if (cx_checkAttr(this, CX_ATTR_SCOPED)) {
        if (cx_class_instanceof(cx_class_o, cx_parentof(this))) {
            cx_class_bindObserver(cx_parentof(this), this);
        }
    }

    cx_function(this)->size = sizeof(cx_object) * 3;

    /* Check if mask specifies either SELF or CHILDS, if not enable SELF */
    if (!(this->mask & (CX_ON_SELF|CX_ON_SCOPE|CX_ON_TREE))) {
        this->mask |= CX_ON_SELF;
    }

    /* Check if mask specifies either VALUE or METAVALUE, if not enable VALUE */
    if (!((this->mask & CX_ON_VALUE) || (this->mask & CX_ON_METAVALUE))) {
        this->mask |= CX_ON_VALUE;
    }

    /* Listen to observable */
    if (!this->template) {
        if (cx_observer_listen(this, this->observable, this->me)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::observer::init() */
cx_int16 _cx_observer_init(cx_observer this) {
/* $begin(::corto::lang::observer::init) */
    cx_parameter *p;
    
    cx_setref( &cx_function(this)->returnType, cx_void_o);

    /* Set parameters of observer: (this, observable, source) */
    cx_function(this)->parameters.buffer = cx_calloc(sizeof(cx_parameter) * 2);
    cx_function(this)->parameters.length = 2;
 

    /* Parameter observable */
    p = &cx_function(this)->parameters.buffer[0];
    p->name = cx_strdup("observable");
    p->passByReference = TRUE;
    if (this->observable && (!(this->mask & CX_ON_SCOPE) && !(this->mask & CX_ON_DECLARE))) {
        cx_setref(&p->type, cx_typeof(this->observable));
    } else {
        cx_setref(&p->type, cx_type(cx_object_o));
    }

    /* Parameter source */
    p = &cx_function(this)->parameters.buffer[1];
    p->name = cx_strdup("source");
    p->passByReference = TRUE;
    cx_setref(&p->type, cx_type(cx_object_o));

    return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
/* $end */
}

/* ::corto::lang::observer::listen(object observable,object me) */
cx_int16 _cx_observer_listen(cx_observer this, cx_object observable, cx_object me) {
/* $begin(::corto::lang::observer::listen) */
    cx_object oldObservable = NULL;

    /* Silence old observable */
    if (!this->template) {
        if (this->observing) {
            oldObservable = this->observing;
            cx_setref(&this->observing, NULL);
        } else {
            oldObservable = this->observable;
        }
        cx_setref(&this->observable, observable);
    } else {
        oldObservable = cx_class_getObservable(cx_class(cx_typeof(me)), this, me);
        cx_class_setObservable(cx_class(cx_typeof(me)), this, me, observable);
    }

    if (oldObservable) {
        cx_silence(oldObservable, this, me);
    }

    if (observable) {
        if (!me || cx_checkState(me, CX_DEFINED)) {
            if (cx_checkAttr(observable, CX_ATTR_OBSERVABLE)) {
                cx_listen(observable, this, me);
            } else {
                if (!this->template) {
                    cx_id id;
                    cx_error("cannot observe non-observable object '%s'", cx_fullname(observable, id));
                    goto error;
                }
            }
        } else if (cx_instanceof((cx_type)cx_class_o, cx_typeof(me))) {
            cx_class_setObservable(cx_class(cx_typeof(me)), this, me, observable);
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::observer::setDispatcher(dispatcher dispatcher) */
cx_void _cx_observer_setDispatcher(cx_observer this, cx_dispatcher dispatcher) {
/* $begin(::corto::lang::observer::setDispatcher) */
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
    cx_setref(&this->dispatcher, dispatcher);
/* $end */
}

/* ::corto::lang::observer::silence(object me) */
cx_int16 _cx_observer_silence(cx_observer this, cx_object me) {
/* $begin(::corto::lang::observer::silence) */
    cx_object oldObservable;

    /* Silence old observable */
    if (!this->template) {
        if (this->observing) {
            oldObservable = this->observing;
            cx_setref(&this->observing, NULL);
        } else {
            oldObservable = this->observable;
        }
        cx_setref(&this->observable, NULL);
    } else {
        oldObservable = cx_class_getObservable(cx_class(cx_typeof(me)), me, this);
        cx_class_setObservable(cx_class(cx_typeof(me)), me, this, NULL);
    }

    if (oldObservable) {
        cx_silence(oldObservable, this, me);
    }

    return 0;
/* $end */
}

/* ::corto::lang::observer::unbind(observer object) */
cx_void _cx_observer_unbind(cx_observer object) {
/* $begin(::corto::lang::observer::unbind) */
    if (!object->template) {
        if (object->observable) {
            if (object->observing) {
                /* When the observer uses an expression, silence observing rather than observable */
                cx_silence(object->observing, object, object->me);
            } else {
                cx_silence(object->observable, object, object->me);
            }
        }
    }

    cx_function_unbind(cx_function(object));
/* $end */
}
