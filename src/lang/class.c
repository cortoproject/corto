/* This is a managed file. Do not delete this comment. */

#include <corto>

#include "interface.h"

/* Check interfaces */
static corto_bool corto_class_checkInterfaceCompatibility(
    corto_class this,
    corto_interface interface,
    corto_objectseq* vtable)
{
    corto_uint32 i;
    corto_method m_interface; /* Interface method */
    corto_method m_class, *m_classPtr; /* Class method */
    corto_bool compatible;
    corto_int32 distance;

    /* Walk vtable of interface */
    compatible = TRUE;
    for (i = 0; i < interface->methods.length; i++) {
        m_interface = (corto_method)interface->methods.buffer[i];

        m_class = NULL;
        m_classPtr = (corto_method*)corto_vtableLookup(&corto_interface(this)->methods, corto_idof(m_interface), &distance);
        if (m_classPtr) {
            m_class = *m_classPtr;
        }

        /* Check if procedures are compatible */
        if (m_class && !distance) {
            if ((compatible = corto_interface_checkProcedureCompatibility(corto_function(m_interface), corto_function(m_class)))) {
                corto_set_ref(&vtable->buffer[i], m_class);
            }
        } else {
            ut_throw(
                "class '%s' is missing implementation for function '%s'",
                corto_fullpath(NULL, this),
                corto_fullpath(NULL, m_interface));
            compatible = FALSE;
        }
    }

    if (interface->base) {
        compatible = compatible & corto_class_checkInterfaceCompatibility(this, interface->base, vtable);
    }

    return compatible;
}

int16_t corto_class_construct(
    corto_class this)
{
    corto_int16 result;
    corto_uint32 i;

    /* This will construct methods of potential base-class which is necessary before validating
     * whether this class correctly (fully) implements its interface. */
    result = safe_corto_struct_construct(this);

    /* Create interface vector */
    if (!result) {
        if (this->implements.length) {
            this->interfaceVector.length = this->implements.length;
            this->interfaceVector.buffer = corto_calloc(this->implements.length * sizeof(corto_interfaceVector));
        }

        /* Validate that all interface interfaces are correctly implemented and generate interface tables. */
        for (i=0; (i<this->implements.length) && !result; i++) {

            corto_interface interface = this->implements.buffer[i];
            corto_set_ref(&this->interfaceVector.buffer[i].interface, interface);
            this->interfaceVector.buffer[i].vector.length = interface->methods.length;

            if (interface->methods.length) {
                this->interfaceVector.buffer[i].vector.buffer = corto_calloc(interface->methods.length * sizeof(corto_function));
            } else {
                this->interfaceVector.buffer[i].vector.buffer = NULL;
            }
            result = !corto_class_checkInterfaceCompatibility(this, interface, &this->interfaceVector.buffer[i].vector);
        }
    }

    if (!result) {
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_construct_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_CONSTRUCT;
        }
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_define_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_DEFINE;
        }
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_destruct_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_DESTRUCT;
        }
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_delete_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_DELETE;
        }
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_validate_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_VALIDATE;
        }
        if (corto_interface_pullDelegate(corto_interface(this), corto_class_update_o)) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_UPDATE;
        }
    }

    return result;
}

void corto_class_destruct(
    corto_class this)
{
    corto_uint32 i,j;
    corto_interfaceVector *v;

    /* Free interfaceVector */
    if (corto_isbuiltin(this)) {
        for (i=0; i<this->interfaceVector.length; i++) {
            v = &this->interfaceVector.buffer[i];
            v->interface = NULL;
            for (j=0; j<v->vector.length; j++) {
                if (v->vector.buffer[j]) {
                    corto_release(v->vector.buffer[j]);
                    v->vector.buffer[j] = NULL;
                }
            }
            if (v->vector.buffer) {
                free(v->vector.buffer);
            }
        }
        if (this->interfaceVector.buffer) {
            free(this->interfaceVector.buffer);
        }
    }

    /* Call type::destruct */
    corto_interface_destruct(corto_interface(this));
}

int16_t corto_class_init(
    corto_class this)
{
    if (_corto_struct_init((corto_struct)this)) {
        goto error;
    }

    corto_type(this)->reference = TRUE;
    corto_interface(this)->kind = CORTO_CLASS;

    return 0;
error:
    return -1;
}

bool corto_class_instanceof(
    corto_class this,
    corto_object object)
{
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
}

corto_method corto_class_resolve_interface_method(
    corto_class this,
    corto_interface interface,
    uint32_t method)
{
    uint32_t i;
    corto_interfaceVector *v = NULL;

    /* Lookup interface class */
    corto_interface base = (corto_interface)this;
    do {
        for (i = 0; i < ((corto_class)base)->interfaceVector.length; i++) {
            v = &((corto_class)base)->interfaceVector.buffer[i];
            if (v->interface == interface) {
                break;
            } else {
                v = NULL;
            }
        }
    } while (!v && (base = base->base));

    if (!v) {
        ut_error(
            "class::resolve_interface_method: class '%s' does not implement interface '%s'",
            corto_fullpath(NULL, this),
            corto_fullpath(NULL, interface));
        goto error;
    }

    return corto_method(v->vector.buffer[method - 1]);
error:
    return NULL;
}
