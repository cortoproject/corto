/* ic_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::member::construct() */
cx_int16 _ic_member_construct(ic_member this) {
/* $begin(::corto::ic::member::construct) */
    cx_id name;

    ic_storage(this)->kind = IC_MEMBER;
    cx_setref(&ic_storage(this)->type, this->member->type);
    cx_setref(&ic_storage(this)->base, this->base);
    ic_storage(this)->isReference = this->member->type->reference;
    sprintf(name, "%s.%s", this->base->name, cx_nameof(this->member));
    ic_storage(this)->name = cx_strdup(name);

    return ic_storage_construct(ic_storage(this));
/* $end */
}
