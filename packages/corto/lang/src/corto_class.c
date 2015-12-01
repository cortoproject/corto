/* $CORTO_GENERATED
 *
 * corto_class.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto__interface.h"

/* An object of a class-type has extra information appended to it's value. This is the information
* required to store observers. The memory layout
* of a class-instantiation is (exclusive corto object-header):
*
* +-----------------+
* |  object-value   |
* +-----------------+
* | observer-table  |
* +-----------------+
*/

typedef struct corto_observerEntry {
    corto_object observable;
    corto_eventMask mask;
    corto_object dispatcher;
} corto_observerEntry;

CORTO_SEQUENCE(corto_observerTable, corto_observerEntry,);

static corto_uint32 corto__class_observerCount(corto_class this);

static corto_uint32 corto__class_observerCount(corto_class this) {
    corto_uint32 count;
    corto_interface o;

    count = this->observers.length;
    o = corto_interface(this);
    while (o->base) {
        o = o->base;
        count += corto_class(o)->observers.length;
    }

    return count;
}

/* Check interfaces */
static corto_bool corto_class_checkInterfaceCompatibility(corto_class this, corto_interface interface, corto_vtable* vtable) {
    corto_uint32 i;
    corto_method m_interface; /* Interface method */
    corto_method m_class, *m_classPtr; /* Class method */
    corto_bool compatible;
    corto_int32 distance;

    /* Walk vtable of interface */
    compatible = TRUE;
    for (i=0; (i<interface->methods.length); i++) {
        m_interface = (corto_method)interface->methods.buffer[i];

        m_class = NULL;
        m_classPtr = (corto_method*)corto_vtableLookup(&corto_interface(this)->methods, corto_nameof(m_interface), &distance);
        if (m_classPtr) {
            m_class = *m_classPtr;
        }

        /* Check if procedures are compatible */
        if (m_class && !distance) {
            if ((compatible = corto_interface_checkProcedureCompatibility(corto_function(m_interface), corto_function(m_class)))) {
                corto_setref(&vtable->buffer[i], m_class);
            }
        } else {
            corto_id id, id2;
            corto_seterr("class '%s' is missing implementation for function '%s'", corto_fullname(this, id), corto_fullname(m_interface, id2));
            compatible = FALSE;
        }
    }

    if (interface->base) {
        compatible = compatible & corto_class_checkInterfaceCompatibility(this, interface->base, vtable);
    }

    return compatible;
}

/* Get table that stores observers */
corto_observerTable* corto_class_getObserverVtable(corto_object o) {
    corto_observerTable* result;
    corto_type type;
    corto_uint32 observerCount;

    type = corto_typeof(o);
    result = NULL;

    /* Obtain vtable. */
    if (corto_class_instanceof(corto_class_o, type)) {
        if ((observerCount = corto__class_observerCount(corto_class(type)))) {
            result = (corto_observerTable*)CORTO_OFFSET(o, type->size);
        }
    }

    return result;
}

void corto_class_attachObservers(corto_class this, corto_object object) {
    corto_uint32 i, id;
    corto_observerTable* observers;
    corto_class base;

    /* Get table for instantiated observer-templates */
    observers = corto_class_getObserverVtable(object);
    if (observers) {
        id = corto__class_observerCount(this);
        observers->buffer = CORTO_OFFSET(observers, sizeof(corto_observerTable));
        observers->length = id;
        base = this;

        do {
            corto_any this = {corto_typeof(object), object, FALSE};
            for (i=0; i<base->observers.length; i++) {
                corto_class_listen(this, 
                    base->observers.buffer[i],
                    base->observers.buffer[i]->mask,  
                    base->observers.buffer[i]->observable,
                    base->observers.buffer[i]->dispatcher);
            }
        } while ((base = corto_class(corto_interface(base)->base)));
    }
}

void corto_class_listenObservers(corto_class this, corto_object object) {
    corto_uint32 i;
    corto_observerTable* observers;
    corto_class base;

    /* Get table for instantiated observer-templates */
    observers = corto_class_getObserverVtable(object);
    if (observers) {
        base = this;

        do {
            for (i=0; i<base->observers.length; i++) {
                if (observers->buffer[i].observable) {
                    corto_listen(
                        object,
                        base->observers.buffer[i],
                        observers->buffer[i].mask,
                        observers->buffer[i].observable,
                        NULL);
                }
            }
        } while ((base = corto_class(corto_interface(base)->base)));
    }
}

void corto_class_detachObservers(corto_class this, corto_object object) {
    corto_uint32 i;
    corto_observerTable* observers;
    corto_class base;
    corto_object observable;
    corto_eventMask mask;

    /* Get table for instantiated observer-templates */
    observers = corto_class_getObserverVtable(object);
    if (observers) {
        base = this;
        do {
            for (i=0; i<base->observers.length; i++) {
                corto_any thisAny = {corto_type(this), object, FALSE};
                observable = corto_class_observableOf(thisAny, base->observers.buffer[i]);
                mask = corto_class_eventMaskOf(thisAny, base->observers.buffer[i]);
                if (observable) {
                    /* Do not silence observers that listen for childs on non-scoped objects */
                    if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE) &&
                            (!(base->observers.buffer[i]->mask & CORTO_ON_SCOPE) || corto_checkAttr(object, CORTO_ATTR_SCOPED))) {
                        corto_silence(
                            object,
                            base->observers.buffer[i],
                            mask,
                            observable);
                    }
                }
            }
        } while ((base = corto_class(corto_interface(base)->base)));
    }
}

/* $end */

corto_uint32 _corto_class_allocSize_v(corto_class this) {
/* $begin(corto/lang/class/allocSize) */
    corto_uint32 observerCount;
    corto_uint32 size;

    size = corto_type(this)->size;

    if ((observerCount = corto__class_observerCount(this))) {
        size += sizeof(corto_observerTable) + observerCount * sizeof(corto_observerEntry);
    }

    return size;
/* $end */
}

corto_void _corto_class_bindObserver(corto_class this, corto_observer observer) {
/* $begin(corto/lang/class/bindObserver) */
    this->observers.buffer = corto_realloc(this->observers.buffer, (this->observers.length + 1) * sizeof(corto_observer));
    this->observers.buffer[this->observers.length] = observer;
    this->observers.length++;
    observer->_template = this->observers.length;
    corto_claim(observer);
/* $end */
}

corto_int16 _corto_class_construct(corto_class this) {
/* $begin(corto/lang/class/construct) */
    corto_int16 result;
    corto_uint32 i;

    /* This will bind methods of potential base-class which is necessary before validating
     * whether this class correctly (fully) implements its interface. */
    result = corto_struct_construct(this);

    /* Create interface vector */
    if (!result) {
        if (this->implements.length) {
            this->interfaceVector.length = this->implements.length;
            this->interfaceVector.buffer = corto_calloc(this->implements.length * sizeof(corto_interfaceVector));
        }

        /* Validate that all interface interfaces are correctly implemented and generate interface tables. */
        for (i=0; (i<this->implements.length) && !result; i++) {
            corto_interface interface = this->implements.buffer[i];
            this->interfaceVector.buffer[i].interface = interface;
            this->interfaceVector.buffer[i].vector.length  = interface->methods.length;
            if (interface->methods.length) {
                this->interfaceVector.buffer[i].vector.buffer = corto_calloc(interface->methods.length * sizeof(corto_function));
            } else {
                this->interfaceVector.buffer[i].vector.buffer = NULL;
            }
            result = !corto_class_checkInterfaceCompatibility(this, interface, &this->interfaceVector.buffer[i].vector);
        }
    }

    return result;
/* $end */
}

corto_void _corto_class_destruct(corto_class this) {
/* $begin(corto/lang/class/destruct) */
    corto_uint32 i,j;
    corto_interfaceVector *v;

    /* Free attached observers */
    for (i=0; i<this->observers.length; i++) {
        corto_release(this->observers.buffer[i]);
    }
    corto_dealloc(this->observers.buffer);
    this->observers.buffer = NULL;
    this->observers.length = 0;

    /* Free interfaceVector */
    for (i=0; i<this->interfaceVector.length; i++) {
        v = &this->interfaceVector.buffer[i];
        v->interface = NULL;
        for (j=0; j<v->vector.length; j++) {
            if (v->vector.buffer[j]) {
                corto_release(v->vector.buffer[j]);
                v->vector.buffer[j] = NULL;
            }
        }
    }

    /* Call type::destruct */
    corto_interface_destruct(corto_interface(this));
/* $end */
}

corto_eventMask _corto_class_eventMaskOf(corto_any this, corto_observer observer) {
/* $begin(corto/lang/class/eventMaskOf) */

    corto_observerTable* observers;
    corto_eventMask result = 0;
    corto_object me = this.value;

    observers = corto_class_getObserverVtable(me);
    if (observers) {
        result = observers->buffer[observer->_template-1].mask;
    } else {
        corto_id id, id2;
        corto_error("failed to get observer for object '%s' of type '%s'", corto_fullname(me, id), corto_fullname(corto_typeof(me), id2));
    }

    return result;

/* $end */
}

corto_observer _corto_class_findObserver(corto_class this, corto_object observable) {
/* $begin(corto/lang/class/findObserver) */
    corto_uint32 i;
    corto_observer result = NULL;

    for (i=0; i<this->observers.length; i++) {
        if (this->observers.buffer[i]->observable == observable) {
            result = this->observers.buffer[i];
            break;
        }
    }

    return result;
/* $end */
}

corto_int16 _corto_class_init(corto_class this) {
/* $begin(corto/lang/class/init) */
    if (corto_struct_init(this)) {
        goto error;
    }

    corto_type(this)->reference = TRUE;
    corto_interface(this)->kind = CORTO_CLASS;

    return 0;
error:
    return -1;
/* $end */
}

corto_bool _corto_class_instanceof(corto_class this, corto_object object) {
/* $begin(corto/lang/class/instanceof) */
    corto_type t;
    corto_bool result;

    result = FALSE;
    t = corto_typeof(object);

    if (t->kind == CORTO_COMPOSITE) {
        if (corto_interface(t)->kind == CORTO_CLASS) {
            corto_interface p;
            p = (corto_interface)t;

            while (p && !result) {
                result = (p == (corto_interface)this);
                p = p->base;
            }
        }
    }

    return result;
/* $end */
}

corto_void _corto_class_listen(corto_any this, corto_observer observer, corto_eventMask mask, corto_object observable, corto_dispatcher dispatcher) {
/* $begin(corto/lang/class/listen) */
    corto_observerTable* observers;

    observers = corto_class_getObserverVtable(this.value);
    if (observers) {
        observers->buffer[observer->_template-1].observable = observable;
        observers->buffer[observer->_template-1].mask = mask;
        observers->buffer[observer->_template-1].dispatcher = dispatcher;
    } else {
        corto_id id, id2;
        corto_error("failed to set observable for observer '%s' of '%s' of type '%s' (%d)", 
            corto_nameof(observer),
            corto_fullname(this.value, id),
            corto_fullname(corto_typeof(this.value), id2),
            corto_countof(this.value));
    }

/* $end */
}

corto_object _corto_class_observableOf(corto_any this, corto_observer observer) {
/* $begin(corto/lang/class/observableOf) */
    corto_observerTable* observers;
    corto_object result = NULL;
    corto_object me = this.value;

    observers = corto_class_getObserverVtable(me);
    if (observers) {
        result = observers->buffer[observer->_template-1].observable;
    } else {
        corto_id id, id2;
        corto_error("failed to get observer for object '%s' of type '%s'", corto_fullname(me, id), corto_fullname(corto_typeof(me), id2));
    }

    return result;
/* $end */
}

corto_method _corto_class_resolveInterfaceMethod(corto_class this, corto_interface interface, corto_uint32 method) {
/* $begin(corto/lang/class/resolveInterfaceMethod) */
    corto_uint32 i;
    corto_interfaceVector *v;

    /* Lookup interface class */
    for (i=0; i<this->interfaceVector.length; i++) {
        v = &this->interfaceVector.buffer[i];
        if (v->interface == interface) {
            break;
        } else {
            v = NULL;
        }
    }

    if (!v) {
        corto_id id, id2;
        corto_error("class::resolveInterfaceMethod: class '%s' does not implement interface '%s'", corto_fullname(this, id), corto_fullname(interface, id2));
        goto error;
    }

    return corto_method(v->vector.buffer[method-1]);
error:
    return NULL;
/* $end */
}

corto_void _corto_class_setDispatcher(corto_any this, corto_observer observer, corto_dispatcher dispatcher) {
/* $begin(corto/lang/class/setDispatcher) */

    corto_observerTable* observers;

    observers = corto_class_getObserverVtable(this.value);
    if (observers) {
        observers->buffer[observer->_template-1].dispatcher = dispatcher;
    } else {
        corto_id id, id2;
        corto_error("failed to set dispatcher for '%s' of type '%s'", 
            corto_fullname(this.value, id), 
            corto_fullname(corto_typeof(this.value), id2));
    }

/* $end */
}

corto_void _corto_class_setMask(corto_any this, corto_observer observer, corto_eventMask mask) {
/* $begin(corto/lang/class/setMask) */

    corto_observerTable* observers;

    observers = corto_class_getObserverVtable(this.value);
    if (observers) {
        observers->buffer[observer->_template-1].mask = mask;
    } else {
        corto_id id, id2;
        corto_error("failed to set mask for '%s' of type '%s'", 
            corto_fullname(this.value, id), 
            corto_fullname(corto_typeof(this.value), id2));
    }

/* $end */
}

corto_void _corto_class_setObservable(corto_any this, corto_observer observer, corto_object observable) {
/* $begin(corto/lang/class/setObservable) */

    corto_observerTable* observers;

    observers = corto_class_getObserverVtable(this.value);
    if (observers) {
        observers->buffer[observer->_template-1].observable = observable;
    } else {
        corto_id id, id2;
        corto_error("failed to set observable for '%s' of type '%s'", 
            corto_fullname(this.value, id), 
            corto_fullname(corto_typeof(this.value), id2));
    }

/* $end */
}
