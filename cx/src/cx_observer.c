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

/* ::cortex::lang::observer::bind() */
cx_int16 cx_observer_bind(cx_observer _this) {
/* $begin(::cortex::lang::observer::bind) */

    /* If this is a scoped observer, automatically bind with parent if it's a class. */
    if (cx_checkAttr(_this, CX_ATTR_SCOPED)) {
        if (cx_class_instanceof(cx_class_o, cx_parentof(_this))) {
            cx_class_bindObserver(cx_parentof(_this), _this);
        }
    }

    cx_function(_this)->size = sizeof(cx_object) * 3;

    /* Check if mask specifies either SELF or CHILDS, if not enable SELF */
    if (!(_this->mask & (CX_ON_SELF|CX_ON_SCOPE|CX_ON_TREE))) {
        _this->mask |= CX_ON_SELF;
    }

    /* Check if mask specifies either VALUE or METAVALUE, if not enable VALUE */
    if (!((_this->mask & CX_ON_VALUE) || (_this->mask & CX_ON_METAVALUE))) {
        _this->mask |= CX_ON_VALUE;
    }

    /* Listen to observable */
    if (!_this->template) {
        if (cx_observer_listen(_this, _this->observable, _this->me)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::observer::init() */
cx_int16 cx_observer_init(cx_observer _this) {
/* $begin(::cortex::lang::observer::init) */
    cx_parameter *p;
    
    cx_setref( &cx_function(_this)->returnType, cx_void_o);

    /* Set parameters of observer: (this, observable, source) */
    cx_function(_this)->parameters.buffer = cx_calloc(sizeof(cx_parameter) * 2);
    cx_function(_this)->parameters.length = 2;
 

    /* Parameter observable */
    p = &cx_function(_this)->parameters.buffer[0];
    p->name = cx_strdup("observable");
    p->passByReference = TRUE;
    if (_this->observable && (!(_this->mask & CX_ON_SCOPE) && !(_this->mask & CX_ON_DECLARE))) {
        cx_setref(&p->type, cx_typeof(_this->observable));
    } else {
        cx_setref(&p->type, cx_type(cx_object_o));
    }

    /* Parameter source */
    p = &cx_function(_this)->parameters.buffer[1];
    p->name = cx_strdup("source");
    p->passByReference = TRUE;
    cx_setref(&p->type, cx_type(cx_object_o));

    return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
/* $end */
}

/* ::cortex::lang::observer::listen(object observable,object me) */
cx_int16 cx_observer_listen(cx_observer _this, cx_object observable, cx_object me) {
/* $begin(::cortex::lang::observer::listen) */
    cx_object oldObservable = NULL;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            cx_setref(&_this->observing, NULL);
        } else {
            oldObservable = _this->observable;
        }
        cx_setref(&_this->observable, observable);
    } else {
        oldObservable = cx_class_getObservable(cx_class(cx_typeof(me)), _this, me);
        cx_class_setObservable(cx_class(cx_typeof(me)), _this, me, observable);
    }

    if (oldObservable) {
        cx_silence(oldObservable, _this, me);
    }

    if (observable) {
        if (!me || cx_checkState(me, CX_DEFINED)) {
            if (cx_checkAttr(observable, CX_ATTR_OBSERVABLE)) {
                cx_listen(observable, _this, me);
            } else {
                if (!_this->template) {
                    cx_id id;
                    cx_error("cannot observe non-observable object '%s'", cx_fullname(observable, id));
                    goto error;
                }
            }
        } else if (cx_instanceof((cx_type)cx_class_o, cx_typeof(me))) {
            cx_class_setObservable(cx_class(cx_typeof(me)), _this, me, observable);
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::observer::setDispatcher(dispatcher dispatcher) */
cx_void cx_observer_setDispatcher(cx_observer _this, cx_dispatcher dispatcher) {
/* $begin(::cortex::lang::observer::setDispatcher) */
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
    cx_setref(&_this->dispatcher, dispatcher);
/* $end */
}

/* ::cortex::lang::observer::silence(object me) */
cx_int16 cx_observer_silence(cx_observer _this, cx_object me) {
/* $begin(::cortex::lang::observer::silence) */
    cx_object oldObservable;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            cx_setref(&_this->observing, NULL);
        } else {
            oldObservable = _this->observable;
        }
        cx_setref(&_this->observable, NULL);
    } else {
        oldObservable = cx_class_getObservable(cx_class(cx_typeof(me)), me, _this);
        cx_class_setObservable(cx_class(cx_typeof(me)), me, _this, NULL);
    }

    if (oldObservable) {
        cx_silence(oldObservable, _this, me);
    }

    return 0;
/* $end */
}

/* ::cortex::lang::observer::unbind(observer object) */
cx_void cx_observer_unbind(cx_observer object) {
/* $begin(::cortex::lang::observer::unbind) */
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
