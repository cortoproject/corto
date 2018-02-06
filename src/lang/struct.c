/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "src/store/object.h"
#include "interface.h"
#include "class.h"
bool corto_struct_castable_v(
    corto_struct this,
    corto_type type)
{
    return corto_struct_compatible(this, type);
}

bool corto_struct_compatible_v(
    corto_struct this,
    corto_type type)
{
    corto_bool result;

    corto_assert(corto_class_instanceof(corto_struct_o, this), "struct::compatible called on non-struct object.");
    result = FALSE;

    /* Call overloaded type::compatible function first to check for generic compatibility. */
    if (!corto_type_compatible_v(corto_type(this), type)) {
        /* Type must be at least struct for it to be compatible. */
        if (corto_class_instanceof(corto_struct_o, type)) {
            corto_interface e;

            /* Check if 'this' is superclass of 'type' */
            e = corto_interface(type);
            do {
                e = corto_interface(e)->base;
            }while(e && (e != corto_interface(this)));
            result = (e == (corto_interface)this);
        }

    } else {
        result = TRUE;
    }

    return result;
}

int16_t corto_struct_construct(
    corto_struct this)
{
    corto_struct base;
    corto_uint16 alignment;
    corto_uint32 size;

    size = 0;
    alignment = 0;

    /* Don't allow empty structs */
    if (!corto_interface(this)->nextMemberId && !corto_interface(this)->base) {
        corto_member m = corto(CORTO_DECLARE|CORTO_FORCE_TYPE, {
            .parent = this,
            .id = "__dummy",
            .type = corto_member_o,
            .attrs = CORTO_ATTR_NAMED
        });

        if (!m) {
            corto_critical("failed to declare dummy member");
        }

        corto_set_ref(&m->type, corto_int8_o);
        m->modifiers = CORTO_PRIVATE|CORTO_LOCAL;
        corto(CORTO_DEFINE, {.object = m});
    }

    /* Insert members */
    if (corto__interface_insertMembers(corto_interface(this))) {
        goto error;
    }

    /* Calculate alignment of self */
    if (corto_interface(this)->members.length) {
        alignment = corto__interface_calculateAlignment(corto_interface(this));
        if (!alignment) {
            corto_throw("can't compute alignment of %s",
                corto_fullpath(NULL, this));
            goto error;
        }

    }

    /* Check if struct inherits from another struct */
    base = (corto_struct)corto_interface(this)->base;
    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        /* Test if there are no circular references in the base */
        do {
            if (base == this) {
                corto_throw("interface '%s' inherits from itself",
                    corto_fullpath(NULL, this));
                goto error;
            }

        } while ((base = (corto_struct)((corto_interface)base)->base));
        base = (corto_struct)corto_interface(this)->base;
        if (!corto_instanceof(corto_type(corto_struct_o), base)) {
            corto_throw("struct '%s' inherits from non-struct type '%s'",
                corto_fullpath(NULL, this), corto_fullpath(NULL, base));
            goto error;
        }

        if (corto_type(base)->alignment) {
            if (alignment < corto_type(base)->alignment) {
                alignment = corto_type(base)->alignment;
            }

        }

    }

    /* Set alignment of self */
    corto_type(this)->alignment = alignment;

    /* Get size of base-class */
    if (base) {
        size = corto_type(base)->size;
        if (corto_type(base)->flags & CORTO_TYPE_HAS_RESOURCES) {
            corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
        }

        if (corto_type(base)->flags & CORTO_TYPE_NEEDS_INIT) {
            corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
        }
    }

    /* Calculate size of self */
    if (corto_interface(this)->members.length) {
        size = corto__interface_calculateSize(corto_interface(this), size);
        if (!size) {
            corto_throw("can't compute size of %s",
                corto_fullpath(NULL, this));
            goto error;
        }

    }

    /* Set size of self */
    corto_type(this)->size = size;

    if (this->keys.length != 0) {
        /* If a keylist was provided, test if members have been added and ensure
         * the KEY modifier is enabled */
        corto_int32 i;
        for (i = 0; i < this->keys.length; i++) {
            corto_object o = corto_interface_resolveMember(this, this->keys.buffer[i]);
            if (!o) {
                corto_throw("no member with name '%s' found for table '%s'",
                    this->keys.buffer[i],
                    corto_fullpath(NULL, this));
                goto error;
            }

            if (!corto_instanceof(corto_member_o, o)) {
                corto_throw("object '%s' in table '%s' is not a member",
                    corto_fullpath(NULL, o),
                    corto_fullpath(NULL, this));
                goto error;
            }

            corto_member m = corto_member(o);
            if (corto_parentof(m) == this) {
                m->modifiers |= CORTO_KEY;
            }

            this->keycache.buffer =
                corto_realloc(this->keycache.buffer,
                    sizeof(corto_object) * (this->keycache.length + 1));
            this->keycache.buffer[this->keycache.length] = m;
            corto_claim(m);
            this->keycache.length ++;
            corto_release(o);
        }

    } else {
        /* If no keylist was provided, walk over members and add keys to the
         * list automatically based on order of occurrence. */
        corto_int32 i;
        corto_interface interface = corto_interface(this);
        for (i = 0; i < interface->members.length; i ++) {
            corto_member m = interface->members.buffer[i];
            if ((m->modifiers & CORTO_KEY) == CORTO_KEY) {
                this->keys.buffer =
                    corto_realloc(this->keys.buffer,
                        sizeof(char*) * (this->keys.length + 1));
                this->keys.buffer[this->keys.length] =
                    corto_strdup(corto_idof(m));
                this->keys.length ++;
                this->keycache.buffer =
                    corto_realloc(this->keycache.buffer,
                        sizeof(corto_object) * (this->keycache.length + 1));
                this->keycache.buffer[this->keycache.length] = m;
                corto_claim(m);
                this->keycache.length ++;
            }
        }
    }

    freeops_create(NULL, (corto_type)this);

    return safe_corto_interface_construct(this);
error:
    return -1;
}

int16_t corto_struct_init(
    corto_struct this)
{
    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (corto_check_state(corto_type_o, CORTO_VALID)) {
        this->baseAccess = CORTO_GLOBAL;
    }

    if (_corto_interface_init((corto_interface)this)) {
        goto error;
    }

    ((corto_interface)this)->kind = CORTO_STRUCT;
    ((corto_type)this)->reference = FALSE;
    return 0;
error:
    return -1;
}

corto_member corto_struct_resolveMember_v(
    corto_struct this,
    const char *name)
{
    corto_interface base;
    corto_member m;

    m = NULL;
    base = corto_interface(this);
    do {
        m = corto_interface_resolveMember_v(corto_interface(base), name);
    } while(!m && (base = corto_interface(base)->base));
    return m;
}

void corto_struct_destruct(
    corto_struct this)
{
    freeops_delete(this);
}
