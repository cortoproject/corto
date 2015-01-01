/* cx_observer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__class.h"
/* $end */

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::observer::bind(lang::observer object) */
cx_int16 cx_observer_bind(cx_observer object) {
/* $begin(::cortex::lang::observer::bind) */
    cx_parameter *p;

	/* If this is a scoped observer, automatically bind with parent if it's a class. */
	if (cx_checkAttr(object, DB_ATTR_SCOPED)) {
		if (cx_class_instanceof(cx_class_o, cx_parentof(object))) {
			cx_class_bindObserver(cx_parentof(object), object);
		}
	}

	cx_function(object)->size = sizeof(cx_object) * 2;
	if (object->me || object->template) {
	    cx_function(object)->size += sizeof(cx_object); /* Add space for this-object */
	}

	/* Set parameters of observer: (observable, source) */
	cx_function(object)->parameters.buffer = cx_malloc(sizeof(cx_parameter) * 2);
	cx_function(object)->parameters.length = 2;

	/* Parameter observable */
	p = &cx_function(object)->parameters.buffer[0];
	p->name = cx_strdup("observable");
	p->passByReference = TRUE;
	if (object->observable && (!(object->mask & DB_ON_SCOPE) && !(object->mask & DB_ON_DECLARE))) {
		p->type = cx_typeof(object->observable);
		cx_keep_ext(object, cx_typeof(object->observable), "Keep parameter type");
	} else {
		p->type = cx_typedef(cx_object_o);
		cx_keep_ext(object, cx_object_o, "Keep type of observable parameter for observer");
	}

	/* Parameter source */
	p = &cx_function(object)->parameters.buffer[1];
	p->name = cx_strdup("source");
	p->passByReference = TRUE;
	p->type = cx_typedef(cx_object_o);
	cx_keep_ext(object, cx_object_o, "Keep type of source parameter for observer");

    /* Check if mask specifies either SELF or CHILDS, if not enable SELF */
    if (!((object->mask & DB_ON_SELF) || (object->mask & DB_ON_SCOPE))) {
        object->mask |= DB_ON_SELF;
    }

	/* Check if mask specifies either VALUE or METAVALUE, if not enable VALUE */
	if (!((object->mask & DB_ON_VALUE) || (object->mask & DB_ON_METAVALUE))) {
	    object->mask |= DB_ON_VALUE;
	}

    /* Listen to observable */
    if (!object->template) {
        if (cx_observer_listen(object, object->observable, object->me)) {
            goto error;
        }
    }

	return 0;
error:
	return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::observer::init(lang::observer object) */
cx_int16 cx_observer_init(cx_observer object) {
/* $begin(::cortex::lang::observer::init) */
	cx_function(object)->returnType = cx_typedef(cx_void_o); cx_keep_ext(object, cx_void_o, "Keep void-type of observer object.");
	cx_function(object)->size = sizeof(cx_object) * 2;

	return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
/* $end */
}

/* ::cortex::lang::observer::listen(lang::object observable,lang::object me) */
cx_int16 cx_observer_listen(cx_observer _this, cx_object observable, cx_object me) {
/* $begin(::cortex::lang::observer::listen) */
    cx_object oldObservable = NULL;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            cx_set_ext(_this, &_this->observing, NULL, "unset observing member");
        } else {
            oldObservable = _this->observable;
        }
        cx_set_ext(_this, &_this->observable, observable, "unset observing member");
    } else {
        oldObservable = cx_class_getObservable(cx_class(cx_typeof(me)), _this, me);
        cx_class_setObservable(cx_class(cx_typeof(me)), _this, me, observable);
    }

	if (oldObservable) {
		cx_silence(oldObservable, _this, me);
	}

	if (observable) {
		if (!me || cx_checkState(me, DB_DEFINED)) {
			if (cx_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
				cx_listen(observable, _this, me);
			} else {
				if (!_this->template) {
					cx_id id;
					cx_error("cannot observe non-observable object '%s'", cx_fullname(observable, id));
					goto error;
				}
			}
		} else if (cx_instanceof((cx_typedef)cx_class_o, cx_typeof(me))) {
			cx_class_setObservable(cx_class(cx_typeof(me)), _this, me, observable);
		}
	}

    return 0;
error:
	return -1;
/* $end */
}

/* ::cortex::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
cx_void cx_observer_setDispatcher(cx_observer _this, cx_dispatcher dispatcher) {
/* $begin(::cortex::lang::observer::setDispatcher) */
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
	cx_set_ext(_this, &_this->dispatcher, dispatcher, "Set dispatcher member.");
/* $end */
}

/* ::cortex::lang::observer::silence(lang::object me) */
cx_int16 cx_observer_silence(cx_observer _this, cx_object me) {
/* $begin(::cortex::lang::observer::silence) */
	cx_object oldObservable;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            cx_set_ext(_this, &_this->observing, NULL, "unset observing member");
        } else {
            oldObservable = _this->observable;
        }
        cx_set_ext(_this, &_this->observable, NULL, "unset observing member");
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

/* ::cortex::lang::observer::unbind(lang::observer object) */
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
