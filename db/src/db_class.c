/* db_class.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__interface.h"

/* An object of a class-type has extra information appended to it's value. This is the information
* required to store callbacks and observers. The memory layout
* of a class-instantiation is (exclusive hyve object-header):
*
* +-----------------+
* |  object-value   |
* +-----------------+
* | callback-table  |
* +-----------------+
* | observer-table  |
* +-----------------+
*
*/

static db_uint32 db__class_observerCount(db_class _this);

db_uint32 db__class_delegateCount(db_class _this) {
    db_uint32 delegateCount;
    db_interface o;

    delegateCount = db_struct(_this)->delegateCount;
    o = db_interface(_this);
    while(o->base) {
        o = o->base;
        delegateCount += db_struct(o)->delegateCount;
    }

    return delegateCount;
}

static db_uint32 db__class_observerCount(db_class _this) {
    db_uint32 count;
    db_interface o;

    count = _this->observers.length;
    o = db_interface(_this);
    while(o->base) {
        o = o->base;
        count += db_class(o)->observers.length;
    }

    return count;
}

static db_uint32 db__class_nextDelegateId(db_class _this) {
    db_uint32 nextId;
    db_class base;

    nextId = db_struct(_this)->delegateCount;
    base = db_class(db_interface(_this)->base);
    while(base) {
        db_assert(db_class_instanceof(db_class_o, base), "class::nextDelegateId: class can only inherit from classes.");
        nextId += db_struct(base)->delegateCount;
        base = db_class(db_interface(base)->base);
    }

    db_struct(_this)->delegateCount++;

    return nextId;
}

/* Set method in vtable on specific index (must only be used for delegate-callbacks). */
static db_bool db_vtableSet(db_vtable* vtable, db_uint32 i, db_function method) {
    db_bool result;

    result = FALSE;

    if (vtable->length <= i) {
        vtable->buffer = db_realloc(vtable->buffer, sizeof(db_member) * (i + 1));
        memset(DB_OFFSET(vtable->buffer, sizeof(db_member) * vtable->length), 0, sizeof(db_member) * (i - vtable->length + 1));
    }

    /* If the length != 0 but the vtable buffer is NULL, than this is the first time the vtable is used.
     * Initialize the buffer to point to the address right after the vtable, which is where the buffer
     * is located. This only occurs for SSO objects. */
    if (!vtable->buffer) {
        vtable->buffer = DB_OFFSET(vtable, sizeof(db_vtable));
    }

    db_assert(!vtable->buffer[i] || vtable->buffer[i] == method, "slot %d in vtable is already occupied by method that doesn't match", i);

    if (!vtable->buffer[i]) {
        vtable->buffer[i] = method;
        result = TRUE;
    }

    if (i>=vtable->length) {
        vtable->length = i+1;
    }

    return result;
}

/* Check interfaces */
static db_bool db_class_checkInterfaceCompatibility(db_class _this, db_interface interface, db_vtable* vtable) {
    db_uint32 i;
    db_method m_interface; /* Interface method */
    db_method m_class, *m_classPtr; /* Class method */
    db_bool compatible;
    db_int32 distance;

    /* Walk vtable of interface */
    compatible = TRUE;
    for(i=0; (i<interface->methods.length); i++) {
        m_interface = (db_method)interface->methods.buffer[i];

        m_class = NULL;
        m_classPtr = (db_method*)db_vtableLookup(&db_interface(_this)->methods, db_nameof(m_interface), NULL, &distance);
        if (m_classPtr) {
            m_class = *m_classPtr;
        }

        /* Check if procedures are compatible */
        if (m_class && !distance) {
            if ((compatible = db_interface_checkProcedureCompatibility(db_function(m_interface), db_function(m_class)))) {
                db_set_ext(_this, &vtable->buffer[i], m_class, "Set method in interface lookup table.");
            }
        } else {
            db_id id, id2;
            db_error("class '%s' is missing implementation for function '%s'", db_fullname(_this, id), db_fullname(m_interface, id2));
            compatible = FALSE;
        }
    }

    if (interface->base) {
        compatible = compatible & db_class_checkInterfaceCompatibility(_this, interface->base, vtable);
    }

    return compatible;
}

/* Get table that stores callbacks */
db_vtable* db_class_getCallbackVtable(db_object o) {
    db_vtable* result;
    db_type type;

    type = db_typeof(o)->real;
    result = NULL;

    /* Obtain vtable. */
    if (db_class_instanceof(db_class_o, type)) {
        if (db__class_delegateCount(db_class(type))) {
            result = (db_vtable*)DB_OFFSET(o, type->size);
        }
    }

    return result;
}

/* Get table that stores observers */
db_vtable* db_class_getObserverVtable(db_object o) {
    db_vtable* result;
    db_type type;
    db_uint32 observerCount, delegateCount;

    type = db_typeof(o)->real;
    result = NULL;

    /* Obtain vtable. */
    if (db_class_instanceof(db_class_o, type)) {
        if ((observerCount = db__class_observerCount(db_class(type)))) {
            result = (db_vtable*)DB_OFFSET(o, type->size);
            if ((delegateCount = db__class_delegateCount(db_class(type)))) {
                result = DB_OFFSET(result, sizeof(db_vtable) + delegateCount * sizeof(db_callback));
            }
        }
    }

    return result;
}

db_object db_class_getObservable(db_class _this, db_observer observer, db_object me) {
    db_vtable* observers;
    db_object result = NULL;
    DB_UNUSED(_this);
    observers = db_class_getObserverVtable(me);
    if (observers) {
        result = observers->buffer[observer->template-1];
    } else {
        db_id id, id2;
        db_error("failed to get observer for object '%s' of type '%s'", db_fullname(me, id), db_fullname(db_typeof(me), id2));
    }
    return result;
}

void db_class_setObservable(db_class _this, db_observer observer, db_object me, db_object observable) {
    db_vtable* observers;
    DB_UNUSED(_this);

    observers = db_class_getObserverVtable(me);
    if (observers) {
        observers->buffer[observer->template-1] = observable;
    } else {
        db_id id, id2;
        db_error("failed to set observer for object '%s' of type '%s'", db_fullname(me, id), db_fullname(db_typeof(me), id2));
    }
}

void db_class_attachObservers(db_class _this, db_object object) {
    db_uint32 i, id;
    db_vtable* observers;
    db_class base;
    db_object observable;

    /* Get table for instantiated observer-templates */
    observers = db_class_getObserverVtable(object);
    if (observers) {
        id = db__class_observerCount(_this);
        observers->buffer = DB_OFFSET(observers, sizeof(db_vtable));
        observers->length = id;
        base = _this;

        do {
            for(i=0; i<base->observers.length; i++) {
                observable = base->observers.buffer[i]->observable;
                db_class_setObservable(_this, base->observers.buffer[i], object, observable);
            }
        }while((base = db_class(db_interface(base)->base)));
    }
}

void db_class_listenObservers(db_class _this, db_object object) {
    db_uint32 i;
    db_vtable* observers;
    db_class base;
    db_object observable;

    /* Get table for instantiated observer-templates */
    observers = db_class_getObserverVtable(object);
    if (observers) {
        base = _this;

        do {
            for(i=0; i<base->observers.length; i++) {
                observable = observers->buffer[i];
                if (!observable) {
                    observable = object;
                }
                if (!db_listening(observable, base->observers.buffer[i], object)) {
                    /* Do not activate observers that listen for non-observables and childs on non-scoped objects */
                    if (db_checkAttr(observable, DB_ATTR_OBSERVABLE) &&
                            (!(base->observers.buffer[i]->mask & DB_ON_SCOPE) || db_checkAttr(object, DB_ATTR_SCOPED))) {
                        db_listen(observable, base->observers.buffer[i], object);
                    }
                }
            }
        }while((base = db_class(db_interface(base)->base)));
    }
}

void db_class_detachObservers(db_class _this, db_object object) {
    db_uint32 i, id;
    db_vtable* observers;
    db_class base;
    db_object observable;

    /* Get table for instantiated observer-templates */
    observers = db_class_getObserverVtable(object);
    if (observers) {
        id = db__class_observerCount(_this);
        observers->buffer = DB_OFFSET(observers, sizeof(db_vtable));
        observers->length = id;
        base = _this;
        do {
            for(i=0; i<base->observers.length; i++) {
                observable = db_class_getObservable(base, base->observers.buffer[i], object);
                if (observable) {
                    /* Do not silence observers that listen for childs on non-scoped objects */
                    if (db_checkAttr(observable, DB_ATTR_OBSERVABLE) &&
                            (!(base->observers.buffer[i]->mask & DB_ON_SCOPE) || db_checkAttr(object, DB_ATTR_SCOPED))) {
                        db_silence(observable, base->observers.buffer[i], object);
                    }
                }
            }
        }while((base = db_class(db_interface(base)->base)));
    }
}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::class::_construct(lang::class object) */
db_int16 db_class__construct(db_class object) {
/* $begin(::hyve::lang::class::_construct) */
	db_int16 result;
    db_uint32 i;

    /* This will bind methods of potential base-class which is necessary before validating
     * whether this class correctly (fully) implements its interface. */
    result = db_struct_construct(db_struct(object));

	/* Create interface vector */
    if (!result) {
        if (object->implements.length) {
            object->interfaceVector.length = object->implements.length;
            object->interfaceVector.buffer = db_calloc(object->implements.length * sizeof(db_interfaceVector));
        }

        /* Validate that all interface interfaces are correctly implemented and generate interface tables. */
        for(i=0; (i<object->implements.length) && !result; i++) {
            db_interface interface = object->implements.buffer[i];
            object->interfaceVector.buffer[i].interface = interface;
            object->interfaceVector.buffer[i].vector.length  = interface->methods.length;
            if (interface->methods.length) {
                object->interfaceVector.buffer[i].vector.buffer = db_calloc(interface->methods.length * sizeof(db_function));
            } else {
                object->interfaceVector.buffer[i].vector.buffer = NULL;
            }
            result = !db_class_checkInterfaceCompatibility(object, interface, &object->interfaceVector.buffer[i].vector);
        }
    }

	return result;
/* $end */
}

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::class::_destruct(lang::class object) */
db_void db_class__destruct(db_class object) {
/* $begin(::hyve::lang::class::_destruct) */
    db_uint32 i,j;
    db_interfaceVector *v;

    /* Free attached observers */
    for(i=0; i<object->observers.length; i++) {
    	db_free_ext(object, object->observers.buffer[i], "Unbind observer from class");
    }
    db_dealloc(object->observers.buffer);
    object->observers.buffer = NULL;
    object->observers.length = 0;

    /* Free interfaceVector */
    for(i=0; i<object->interfaceVector.length; i++) {
    	v = &object->interfaceVector.buffer[i];
    	v->interface = NULL;
    	for(j=0; j<v->vector.length; j++) {
    		if (v->vector.buffer[j]) {
				db_free_ext(object, v->vector.buffer[j], "Unbind interface vector");
				v->vector.buffer[j] = NULL;
    		}
    	}
    }

    /* Call type::destruct */
    db_interface_destruct(db_interface(object));
/* $end */
}

/* ::hyve::lang::class::allocSize() */
db_uint32 db_class_allocSize_v(db_class _this) {
/* $begin(::hyve::lang::class::allocSize) */
    db_uint32 delegateCount, observerCount;
    db_uint16 size;

    size = db_type(_this)->size;
    if ((delegateCount = db__class_delegateCount(_this))) {
        size += sizeof(db_vtable) + delegateCount * sizeof(db_callback);
    }

    if ((observerCount = db__class_observerCount(_this))) {
    	size += sizeof(db_vtable) + observerCount * sizeof(db_observer);
    }

    return size;/* $end */
}

/* ::hyve::lang::class::bindCallback(lang::delegate delegate,lang::object object,lang::callback method) */
db_int16 db_class_bindCallback(db_class _this, db_delegate delegate, db_object object, db_callback method) {
/* $begin(::hyve::lang::class::bindCallback) */
    db_vtable* vtable;
    db_type targetType;

    DB_UNUSED(_this);

    /* Check if callback is compatible with delegate */
    db_interface_checkProcedureCompatibility(db_function(delegate), db_function(method));

    targetType = db_typeof(object)->real;
    if (targetType->size) {
        vtable = (db_vtable*)DB_OFFSET(object, targetType->size);
        if (db_vtableSet(vtable, delegate->id-1, db_function(method))) {
            db_keep_ext(object, method, "Keep callback");
        }
    } else {
        db_id id1, id2, id3;
        db_error("class::bindDelegate: cannot bind callback '%s' to '%s', type '%s' is not defined.", db_fullname(method, id1), db_fullname(object, id2), db_fullname(targetType, id3));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::lang::class::bindDelegate(lang::delegate delegate) */
db_int16 db_class_bindDelegate(db_class _this, db_delegate delegate) {
/* $begin(::hyve::lang::class::bindDelegate) */
    db_delegate* found;

    /* Check if a method with the same name is already in the vtable */
    found = (db_delegate*)db_vtableLookup(&db_interface(_this)->methods, db_nameof(delegate), NULL, NULL);

    if (found) {
        /* Function is reentrant */
        if (*found != delegate) {
            db_id id;
            db_critical("class::bindDelegate: cannot override method '%s': delegates can't be overridden", db_fullname(delegate, id));
            goto error;
        }
    } else {
        /* Insert delegate */
        if (db_vtableInsert(&db_interface(_this)->methods, db_function(delegate))) {
            db_keep_ext(_this, delegate, "Bind delegate.");
        }

        /* Assign delegateId */
        delegate->id = db__class_nextDelegateId(_this) + 1;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::lang::class::bindMethod(lang::method method) */
db_int16 db_class_bindMethod(db_class _this, db_method method) {
/* $begin(::hyve::lang::class::bindMethod) */
	return db_interface_bindMethod_v(db_interface(_this), method);
/* $end */
}

/* ::hyve::lang::class::bindObserver(lang::observer observer) */
db_void db_class_bindObserver(db_class _this, db_observer observer) {
/* $begin(::hyve::lang::class::bindObserver) */
    _this->observers.buffer = db_realloc(_this->observers.buffer, (_this->observers.length + 1) * sizeof(db_observer));
    _this->observers.buffer[_this->observers.length] = observer;
    _this->observers.length++;
    observer->template = _this->observers.length;
    db_keep_ext(_this, observer, "Bind observer to class");
/* $end */
}

/* ::hyve::lang::class::findObserver(lang::object observable,string expr) */
db_observer db_class_findObserver(db_class _this, db_object observable, db_string expr) {
/* $begin(::hyve::lang::class::findObserver) */
    db_uint32 i;
    db_observer result = NULL;

    for(i=0; i<_this->observers.length; i++) {
        if (_this->observers.buffer[i]->observable == observable) {
            if (_this->observers.buffer[i]->expression && expr) {
                if (!strcmp(_this->observers.buffer[i]->expression, expr)) {
                    result = _this->observers.buffer[i];
                    break;
                }
            } else {
                result = _this->observers.buffer[i];
                break;
            }
        }
    }

    return result;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::class::init(lang::class object) */
db_int16 db_class_init(db_class object) {
/* $begin(::hyve::lang::class::init) */
    if (db_struct_init(db_struct(object))) {
    	goto error;
    }

    db_type(object)->reference = TRUE;
    db_interface(object)->kind = DB_CLASS;

    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::lang::class::instanceof(lang::object object) */
db_bool db_class_instanceof(db_class _this, db_object object) {
/* $begin(::hyve::lang::class::instanceof) */
    db_type t;
    db_bool result;

    result = FALSE;
    t = db_typeof(object)->real;

    if (t->kind == DB_COMPOSITE) {
        if (db_interface(t)->kind == DB_CLASS) {
        	db_interface p;
            p = (db_interface)t;

            while(p && !result) {
                result = (p == (db_interface)_this);
                p = p->base;
            }
        }
    }

    return result;
/* $end */
}

/* ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
db_observer db_class_privateObserver(db_class _this, db_object object, db_observer observer) {
/* $begin(::hyve::lang::class::privateObserver) */
    DB_UNUSED(_this);
    DB_UNUSED(object);
    return observer; /* Workaround - this function can be removed */
/* $end */
}

/* ::hyve::lang::class::resolveCallback(lang::delegate delegate,lang::object target) */
db_callback db_class_resolveCallback(db_class _this, db_delegate delegate, db_object target) {
/* $begin(::hyve::lang::class::resolveCallback) */
    db_type targetType;
    db_vtable *vtable;
    db_callback result;

    DB_UNUSED(_this);

    targetType = db_typeof(target)->real;

    result = NULL;
    vtable = NULL;

    if ((vtable = DB_OFFSET(target, targetType->size)) && vtable->buffer) {
        result = (db_callback)vtable->buffer[delegate->id-1];
    }

    /* If no callback is found, and object is a type, and type is extendable, lookup callback in base */
    if (!result && (db_class_instanceof(db_struct_o, target))) {
        while(db_interface(target)->base) {
            target = db_interface(target)->base;

            vtable = DB_OFFSET(target, targetType->size);
            if (vtable->buffer && (vtable->length >= delegate->id)) {
                result = (db_callback)vtable->buffer[delegate->id-1];
            }

            if (result) {
                break;
            }
        }
    }

    return result;
/* $end */
}

/* ::hyve::lang::class::resolveDelegate(lang::string name) */
db_delegate db_class_resolveDelegate(db_class _this, db_string name) {
/* $begin(::hyve::lang::class::resolveDelegate) */
    db_delegate result;
    db_function* found;

    result = NULL;

    /* Lookup method */
    if ((found = db_vtableLookup(&db_interface(_this)->methods, name, NULL, NULL))) {
        if (db_typeof(*found) == db_typedef(db_delegate_o)) {
            result = db_delegate(*found);
        } else {
            db_error("class::resolveDelegate: resolved function '%s' is not a delegate.", name);
        }
    }

    return result;
/* $end */
}

/* ::hyve::lang::class::resolveInterfaceMethod(lang::interface interface,lang::uint32 method) */
db_method db_class_resolveInterfaceMethod(db_class _this, db_interface interface, db_uint32 method) {
/* $begin(::hyve::lang::class::resolveInterfaceMethod) */
    db_uint32 i;
    db_interfaceVector *v;

    /* Lookup interface class */
    for(i=0; i<_this->interfaceVector.length; i++) {
        v = &_this->interfaceVector.buffer[i];
        if (v->interface == interface) {
            break;
        } else {
            v = NULL;
        }
    }

    if (!v) {
        db_id id, id2;
        db_error("class::resolveInterfaceMethod: class '%s' does not implement interface '%s'", db_fullname(_this, id), db_fullname(interface, id2));
        goto error;
    }

    return db_method(v->vector.buffer[method-1]);
error:
    return NULL;
/* $end */
}
