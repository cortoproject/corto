/* $CORTO_GENERATED
 *
 * union.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
#include "_interface.h"
#include "_class.h"
/* $end */

corto_int16 _corto_union_construct(
    corto_union this)
{
/* $begin(corto/lang/union/construct) */
    corto_uint32 size = 0;
    corto_uint8 alignment = 0;

    /* Don't allow empty unions */
    if (!corto_interface(this)->nextMemberId) {
        corto_seterr("invalid empty union");
        goto error;
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

    /* Calculate size & set offsets */
    corto_int32 i; for(i = 0; i < corto_interface(this)->members.length; i ++) {
        corto_member m = corto_interface(this)->members.buffer[i];
        corto_uint32 memberSize = corto_type_sizeof(m->type);
        if (memberSize > size) {
            size = memberSize;
        }
        /* All members start at the same offset */
        m->offset = CORTO_ALIGN(sizeof(corto_uint32), alignment);
    }

    /* Add size of discriminator */
    size += sizeof(corto_uint32);
    size = alignment ? CORTO_ALIGN(size, alignment) : size;

    corto_type(this)->size = size;
    corto_type(this)->alignment = alignment;

    return corto_type_construct(this);
error:
    return -1;
/* $end */
}

corto_member _corto_union_findCase(
    corto_union this,
    corto_int32 discriminator)
{
/* $begin(corto/lang/union/findCase) */
    corto_member member = NULL;
    corto_bool found = FALSE;
    corto_uint32 i = 0;

    for(i = 0; i < corto_interface(this)->members.length; i  ++) {
        corto_case c = corto_case(corto_interface(this)->members.buffer[i]);

        /* If discriminator list is empty, this is a default */
        if (!c->discriminator.length) {
            member = corto_member(c);

        /* Otherwise loop discriminators to see if there's a match */
        } else {
            corto_int32 j = 0;
            for (j = 0; j < c->discriminator.length; j ++) {
                corto_int32 caseDiscriminator = c->discriminator.buffer[j];
                if (discriminator == caseDiscriminator) {
                    member = corto_member(c);
                    found = TRUE;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }

    return member;
/* $end */
}

corto_int16 _corto_union_init(
    corto_union this)
{
/* $begin(corto/lang/union/init) */

    if (corto_interface_init(this)) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_UNION;
    corto_type(this)->reference = FALSE;

    return 0;
error:
    return -1;
/* $end */
}
