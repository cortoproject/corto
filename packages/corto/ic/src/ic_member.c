/* $CORTO_GENERATED
 *
 * ic_member.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ic.h"

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
