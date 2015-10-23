/* ic_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::member::construct() */
corto_int16 _ic_member_construct(ic_member this) {
/* $begin(::corto::ic::member::construct) */
    corto_id name;

    ic_storage(this)->kind = IC_MEMBER;
    corto_setref(&ic_storage(this)->type, this->member->type);
    corto_setref(&ic_storage(this)->base, this->base);
    ic_storage(this)->isReference = this->member->type->reference;
    sprintf(name, "%s.%s", this->base->name, corto_nameof(this->member));
    ic_storage(this)->name = corto_strdup(name);

    return ic_storage_construct(ic_storage(this));
/* $end */
}
