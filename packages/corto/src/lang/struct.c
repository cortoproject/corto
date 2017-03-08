/* $CORTO_GENERATED
 *
 * struct.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
#include "_interface.h"
#include "_class.h"
/* $end */

corto_bool _corto_struct_castable_v(
    corto_struct this,
    corto_type type)
{
/* $begin(corto/lang/struct/castable) */
    return corto_struct_compatible(this, type);
/* $end */
}

corto_bool _corto_struct_compatible_v(
    corto_struct this,
    corto_type type)
{
/* $begin(corto/lang/struct/compatible) */
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
/* $end */
}

corto_int16 _corto_struct_construct(
    corto_struct this)
{
/* $begin(corto/lang/struct/construct) */
    corto_struct base;
    corto_uint16 alignment;
    corto_uint32 size;

    size = 0;
    alignment = 0;

    /* Don't allow empty structs */
    if (!corto_interface(this)->nextMemberId && !corto_interface(this)->base) {
        corto_member m = corto_declareChild(this, "__dummy", corto_member_o);
        if (!m) {
            corto_critical("failed to declare dummy member (%s)", corto_lasterr());
        }
        corto_setref(&m->type, corto_int8_o);
        m->modifiers = CORTO_PRIVATE|CORTO_LOCAL;
        corto_define(m);
    }

    /* Insert members */
    if (corto__interface_insertMembers(corto_interface(this))) {
        goto error;
    }

    /* Calculate alignment of self */
    if (corto_interface(this)->members.length) {
        alignment = corto__interface_calculateAlignment(corto_interface(this));
        if (!alignment) {
            corto_seterr("can't compute alignment of %s: %s",
                corto_fullpath(NULL, this),
                corto_lasterr());
            goto error;
        }
    }

    /* Check if struct inherits from another struct */
    base = (corto_struct)corto_interface(this)->base;

    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        if (!corto_instanceof(corto_type(corto_struct_o), base)) {
            corto_seterr("struct '%s' inherits from non-struct type '%s'",
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

        if (corto_type(base)->hasResources) {
            corto_type(this)->hasResources = TRUE;
        }
    }

    /* Calculate size of self */
    if (corto_interface(this)->members.length) {
        size = corto__interface_calculateSize(corto_interface(this), size);
        if (!size) {
            corto_seterr("can't compute size of %s: %s",
                corto_fullpath(NULL, this),
                corto_lasterr());
            goto error;
        }
    }

    /* Set size of self */
    corto_type(this)->size = size;

    return corto_interface_construct(this);
error:
    return -1;
/* $end */
}

corto_int16 _corto_struct_init(
    corto_struct this)
{
/* $begin(corto/lang/struct/init) */
    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (corto_checkState(corto_type_o, CORTO_DEFINED)) {
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
/* $end */
}

corto_member _corto_struct_resolveMember_v(
    corto_struct this,
    corto_string name)
{
/* $begin(corto/lang/struct/resolveMember) */
    corto_interface base;
    corto_member m;

    m = NULL;
    base = corto_interface(this);
    do {
        m = corto_interface_resolveMember_v(corto_interface(base), name);
    }while(!m && (base=corto_interface(base)->base));

    return m;
/* $end */
}
