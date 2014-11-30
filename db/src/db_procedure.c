/*
 * db_procedure.c
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#include "db__interface.h"
#include "db__procedure.h"
#include "db_struct.h"
#include "db__class.h"
#include "db_object.h"
#include "db__meta.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_type.h"
#include "db_call.h"

#include "string.h"

static db_delegate db_procedure_bind_d = NULL;

/* procedure::init */
db_int16 db_procedure_init(db_procedure object) {

    if (db_interface_init(db_interface(object))) {
    	goto error;
    }

    db_interface(object)->kind = DB_PROCEDURE;
    db_type(object)->reference = TRUE;

    return 0;
error:
	return -1;
}

/* procedure::bind */
db_int16 db_procedure_bind(db_procedure _this, db_object object) {
    db_callback bind;
    db_int16 result;
    DB_UNUSED(_this);

    result = 0;

    /* Resolve class::construct once. */
    if (!db_procedure_bind_d) {
        db_procedure_bind_d = db_class_resolveDelegate(db_procedure_o, "bind");
    }

    /* procedure::bind must exist */
    db_assert(db_procedure_bind_d != NULL, "unresolved delegate 'procedure::bind'");

    bind = db_class_resolveCallback(db_class_o, db_procedure_bind_d, db_typeof(object)->real);
    if (bind) {
        db_call(db_function(bind), &result, object);
    }

    return result;
}

/* procedure::unbind */
void db_procedure_unbind(db_procedure _this, db_object object) {
    if (_this->kind == DB_OBSERVER){
        db_observer_unbind(object);
    } else {
        db_function_unbind(object);
    }
}

static db_int16 db_function_parseArguments(db_function object) {
    db_char* ptr;

    ptr = strchr(db_nameof(object), '(');
    if (!ptr) {
        db_error("missing argumentlist in name for function '%s'", db_nameof(object));
        goto error;
    }
    ptr++;

    /* Check if function has arguments */
    if (*ptr != ')') {
        db_uint32 count, i;
        db_id id;
        db_bool reference;

        /* Count number of parameters for function */
        count = db_signatureParamCount(db_nameof(object));
        i = 0;
        reference = FALSE;

        /* Allocate size for parameters */
        object->parameters.length = count;
        object->parameters.buffer = db_malloc(sizeof(db_parameter) * count);
        memset(object->parameters.buffer, 0, sizeof(db_parameter) * count);

        /* Parse arguments */
        for(i=0; i<count; i++) {
            if (db_signatureParamType(db_nameof(object), i, id, &reference)) {
                db_error("error occurred while parsing type of argument '%s' for function '%s'", db_nameof(object));
                goto error;
            }

            /* Set reference */
            object->parameters.buffer[i].passByReference = reference;

            /* Assign type */
            object->parameters.buffer[i].type = db_resolve_ext(object, db_parentof(object), id, FALSE, "Resolve parameter-type for function");
            if (!object->parameters.buffer[i].type) {
                db_id func;
                db_error("type '%s' of argument %d in function %s not found", id, i, db_fullname(object, func));
                goto error;
            }

            /* Parse name */
            if (db_signatureParamName(db_nameof(object), i, id)) {
                db_error("error occurred while parsing name of argument '%s' for function '%s'", db_nameof(object));
                goto error;
            }
            object->parameters.buffer[i].name = db_strdup(id);
        }
    }

    return 0;
error:
	object->parameters.length = 0;
	db_dealloc(object->parameters.buffer);
	object->parameters.buffer = NULL;
    return -1;
}


typedef struct db_functionLookup_t {
	db_function f;
	db_bool error;
	db_id name;
}db_functionLookup_t;

int db_functionLookupWalk(db_object o, void* userData) {
	db_functionLookup_t* data;
	db_int32 d;

	data = userData;

	if (o != data->f) {
		if ((db_class_instanceof(db_procedure_o, db_typeof(o)))) {
			if (db_overload(o, db_nameof(data->f), &d, FALSE)) {
				data->error = TRUE;
				goto finish;
			}

			/* Check if function matches */
			if (!d) {
				db_id id, id2;
				db_error("function '%s' conflicts with existing declaration '%s'", db_fullname(data->f, id), db_fullname(o, id2));
				data->error = TRUE;
				goto finish;
			} else {
				db_id id;

				/* Get name of function */
				db_signatureName(db_nameof(o), id);

				/* Set overloading flags if a function with same name is found. */
				if (!strcmp(data->name, id)) {
					db_function(o)->overloaded = TRUE;
					data->f->overloaded = TRUE;
				}
			}
		}
	}

	return 1;
finish:
	return 0;
}

/* type::init -> function::init */
db_int16 db_function_init(db_function object) {
	db_functionLookup_t walkData;
    db_ll scope;
	DB_UNUSED(object);

	scope = db_scopeClaim(db_parentof(object));

    walkData.f = object;
    walkData.error = FALSE;
    db_signatureName(db_nameof(object), walkData.name);
    db_llWalk(scope, db_functionLookupWalk, &walkData);
    if (walkData.error) {
    	goto error;
    }

    db_scopeRelease(scope);

    /* Parse arguments */
    if (db_function_parseArguments(object)) {
    	goto error;
    }

    return 0;
error:
	return -1;
}

/* procedure::bind -> function::bind */
db_int16 db_function_bind(db_function object) {

	/* Count the size based on the parameters and store parameters in slots */
	if (!object->size) {
	    db_uint32 i;
	    for(i=0; i<object->parameters.length; i++) {
	    	db_type paramType = object->parameters.buffer[i].type->real;
	    	switch(paramType->kind) {
	    	case DB_ANY:
	    		object->size += sizeof(db_any);
	    		break;
	    	case DB_PRIMITIVE:
		    	object->size += db_type_sizeof(paramType);
	    		break;
	    	default:
	    		object->size += sizeof(void*);
	    		break;
	    	}
	    }

	    /* Add size of this-pointer - this must be moved to impl of methods, delegates and callbacks. */
		if (!(db_typeof(object) == db_typedef(db_function_o))) {
			if (db_typeof(object) == db_typedef(db_metaprocedure_o)) {
				object->size += sizeof(db_any);
			} else {
				object->size += sizeof(db_object);
			}
		}
	}

	return 0;
}

/* procedure::unbind -> function::unbind */
void db_function_unbind(db_function object) {
    db_uint32 i;

    db_callDestroy(object);

    /* Deinitialize parameters */
    for(i=0; i<object->parameters.length; i++) {
        db_dealloc(object->parameters.buffer[i].name);
        object->parameters.buffer[i].name = NULL;
        db_free_ext(object, object->parameters.buffer[i].type, "Free function parameter-type.");
        object->parameters.buffer[i].type = NULL;
    }

    db_dealloc(object->parameters.buffer);
    object->parameters.buffer = NULL;
}

/* type::init -> method::init */
db_int16 db_method_init(db_method object) {
    db_object parent;

    /* Locate parent class object */
    parent = db_parentof(object);
    if (parent) {
        /* Parent of method must be an abstract type */
        if (db_class_instanceof(db_interface_o, parent)) {
            /* Can't use the db_interface_bindMethod here, since that would introduce a bootstrap issue. */
            if (db_typeof(parent) == db_typedef(db_interface_o)) {
                if (db_interface_bindMethod_v(db_interface(parent), object)) {
                    goto error;
                }
            } else if (db_typeof(parent) == db_typedef(db_struct_o)) {
                if (db_interface_bindMethod_v(db_interface(parent), object)) {
                    goto error;
                }
            } else if (db_typeof(parent) == db_typedef(db_class_o)) {
                if (db_class_bindMethod(db_class(parent), object)) {
                    goto error;
                }
            }
        } else {
            db_id id1, id2;
            db_error("method::init: parent '%s' of method '%s' is not an abstract object.", db_fullname(parent, id1), db_fullname(object, id2));
            goto error;
        }
    } else {
        db_id id;
        db_error("method::init: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }


    return db_function_init(db_function(object));
error:
	return -1;
}

/* type::init -> virtual::init */
db_int16 db_virtual_init(db_virtual object ) {
    db_method(object)->virtual = TRUE;
    return db_method_init(db_method(object));
}

/* procedure::bind -> method::bind */
db_int16 db_method_bind(db_method object) {
    db_object parent;

    /* Locate parent class object */
    parent = db_parentof(object);
    if (parent) {
    	/* Bind function */
    	if (db_function_bind(db_function(object))) {
    		goto error;
    	}
    } else {
        db_id id;
        db_error("method::init: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* type::init -> delegate::init */
db_int16 db_delegate_init(db_delegate object) {
    db_object parent;

    /* Initialize function */
    if (db_function_init(db_function(object))) {
        goto error;
    }

    parent = db_parentof(object);
    if (parent) {
        /* Parent of delegate must be an abstract */
        if (db_class_instanceof(db_interface_o, parent)) {
            /* Bind delegate to class */
            if (db_interface(parent)->kind == DB_CLASS) {
                if (db_class_bindDelegate(db_class(parent), object)) {
                    goto error;
                }
            } else {
                db_id id1, id2;
                db_error("delegate::init: parent '%s' of method '%s' is not a class object.", db_fullname(parent, id1), db_fullname(object, id2));
            }
        }
    } else {
        db_id id;
        db_error("delegate::init: '%s' is an orphan", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* type::init -> callback::init */
db_int16 db_callback_init(db_callback object) {

    /* Call function initializer */
    if (db_function_init(db_function(object))) {
        goto error;
    }

    /* This greatly facilitates the bootstrap. */
    if (object->delegate) {
        return db_callback_bind(object);
    }

    return 0;
error:
    return -1;
}

/* procedure::bind -> callback::bind */
db_int16 db_callback_bind(db_callback object) {
    db_class delegateClass;
    db_object parent;

    db_assert(object->delegate != NULL, "callback '%s' has <null> for member delegate.", db_nameof(object));

    if (db_function_bind(db_function(object))) {
    	goto error;
    }

    delegateClass = db_class(db_parentof(object->delegate));
    parent = db_parentof(object);
    if (parent) {
        if (db_class_bindCallback(delegateClass, object->delegate, db_type(parent), object)) {
            goto error;
        }
    } else {
        db_id id;
        db_error("callback::bind: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

db_int16 db_observer_init(db_observer object) {
	db_function(object)->returnType = db_typedef(db_void_o); db_keep_ext(object, db_void_o, "Keep void-type of observer object.");
	db_function(object)->size = sizeof(db_object) * 2;

	return 0; /* Don't call function::init, observers do not have parseable parameters, which is currently the only thing a function initializer does. */
}

/* Listen to observable or delay listening until observable is defined, in case of an observer-expression. */
db_int16 db_observer_listen(db_observer _this, db_object observable, db_object me) {
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
}

/* Stop listening to observable. */
db_int16 db_observer_silence(db_observer _this, db_object me) {
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
}

db_int16 db_observer_bind(db_observer object) {
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
}

/* Unbind observer, stop listening to observable. */
void db_observer_unbind(db_observer object) {
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
}

/* Set a dispatcher for an observer */
void db_observer_setDispatcher(db_observer _this, db_dispatcher dispatcher) {
    /* TODO: when observer is a template observer only set the dispatcher in observerData. */
	db_set_ext(_this, &_this->dispatcher, dispatcher, "Set dispatcher member.");
}

/* Bind metaprocedure */
db_int16 db_metaprocedure_bind(db_metaprocedure object) {
	db_object parent;

	parent = db_parentof(object);
	if (db_instanceof(db_typedef(db_type_o), parent)) {
		if (db_type_bindMetaprocedure(db_type(parent), object)) {
			goto error;
		}
	} else {
		db_id id, id2;
		db_error("metaoperation '%s' not defined in scope of '%s' which is not a type", db_fullname(object, id), db_fullname(parent, id2));
		goto error;
	}

    return db_function_bind(db_function(object));
error:
	return -1;
}


