/* db_observer.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__class.h"
/* $end */

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::observer::bind(lang::observer object) */
db_int16 db_observer_bind(db_observer object) {
/* $begin(::cortex::lang::observer::bind) */
    db_parameter *p;

	/* If this is a scoped observer, automatically bind with parent if it's a class. */
	if (db_checkAttr(object, DB_ATTR_SCOPED)) {
		if (db_class_instanceof(db_class_o, db_parentof(object))) {
			db_class_bindObserver(db_parentof(object), object);
		}
	}

	db_function(object)->size = sizeof(db_object) * 2;
	if (object->me || object->template) {
	    db_function(object)->size += sizeof(db_object); /* Add space for this-object */
	}

	/* Set parameters of observer: (observable, source) */
	db_function(object)->parameters.buffer = db_malloc(sizeof(db_parameter) * 2);
	db_function(object)->parameters.length = 2;

	/* Parameter observable */
	p = &db_function(object)->parameters.buffer[0];
	p->name = db_strdup("observable");
	p->passByReference = TRUE;
	if (object->observable && (!(object->mask & DB_ON_SCOPE) && !(object->mask & DB_ON_DECLARE))) {
		p->type = db_typeof(object->observable);
		db_keep_ext(object, db_typeof(object->observable), "Keep parameter type");
	} else {
		p->type = db_typedef(db_object_o);
		db_keep_ext(object, db_object_o, "Keep type of observable parameter for observer");
	}

	/* Parameter source */
	p = &db_function(object)->parameters.buffer[1];
	p->name = db_strdup("source");
	p->passByReference = TRUE;
	p->type = db_typedef(db_object_o);
	db_keep_ext(object, db_object_o, "Keep type of source parameter for observer");

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
        if (db_observer_listen(object, object->observable, object->me)) {
            goto error;
        }
    }

	return 0;
error:
	return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::observer::init(lang::observer object) */
db_int16 db_observer_init(db_observer object) {
/* $begin(::cortex::lang::observer::init) */
	db_function(object)->returnType = db_typedef(db_void_o); db_keep_ext(object, db_void_o, "Keep void-type of observer object.");
	db_function(object)->size = sizeof(db_object) * 2;

	return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
/* $end */
}

/* ::cortex::lang::observer::listen(lang::object observable,lang::object me) */
db_int16 db_observer_listen(db_observer _this, db_object observable, db_object me) {
/* $begin(::cortex::lang::observer::listen) */
    db_object oldObservable = NULL;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            db_set_ext(_this, &_this->observing, NULL, "unset observing member");
        } else {
            oldObservable = _this->observable;
        }
        db_set_ext(_this, &_this->observable, observable, "unset observing member");
    } else {
        oldObservable = db_class_getObservable(db_class(db_typeof(me)), _this, me);
        db_class_setObservable(db_class(db_typeof(me)), _this, me, observable);
    }

	if (oldObservable) {
		db_silence(oldObservable, _this, me);
	}

	if (observable) {
		if (!me || db_checkState(me, DB_DEFINED)) {
			if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
				db_listen(observable, _this, me);
			} else {
				if (!_this->template) {
					db_id id;
					db_error("cannot observe non-observable object '%s'", db_fullname(observable, id));
					goto error;
				}
			}
		} else if (db_instanceof((db_typedef)db_class_o, db_typeof(me))) {
			db_class_setObservable(db_class(db_typeof(me)), _this, me, observable);
		}
	}

    return 0;
error:
	return -1;
/* $end */
}

/* ::cortex::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
db_void db_observer_setDispatcher(db_observer _this, db_dispatcher dispatcher) {
/* $begin(::cortex::lang::observer::setDispatcher) */
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
	db_set_ext(_this, &_this->dispatcher, dispatcher, "Set dispatcher member.");
/* $end */
}

/* ::cortex::lang::observer::silence(lang::object me) */
db_int16 db_observer_silence(db_observer _this, db_object me) {
/* $begin(::cortex::lang::observer::silence) */
	db_object oldObservable;

    /* Silence old observable */
    if (!_this->template) {
        if (_this->observing) {
            oldObservable = _this->observing;
            db_set_ext(_this, &_this->observing, NULL, "unset observing member");
        } else {
            oldObservable = _this->observable;
        }
        db_set_ext(_this, &_this->observable, NULL, "unset observing member");
    } else {
        oldObservable = db_class_getObservable(db_class(db_typeof(me)), me, _this);
        db_class_setObservable(db_class(db_typeof(me)), me, _this, NULL);
    }

    if (oldObservable) {
        db_silence(oldObservable, _this, me);
    }

    return 0;
/* $end */
}

/* ::cortex::lang::observer::unbind(lang::observer object) */
db_void db_observer_unbind(db_observer object) {
/* $begin(::cortex::lang::observer::unbind) */
    if (!object->template) {
		if (object->observable) {
			if (object->observing) {
				/* When the observer uses an expression, silence observing rather than observable */
				db_silence(object->observing, object, object->me);
			} else {
				db_silence(object->observable, object, object->me);
			}
		}
    }

    db_function_unbind(db_function(object));
/* $end */
}
