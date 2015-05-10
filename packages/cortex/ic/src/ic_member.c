/* ic_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::member::construct() */
cx_int16 ic_member_construct(ic_member _this) {
/* $begin(::cortex::ic::member::construct) */
    cx_id name;

    ic_storage(_this)->kind = IC_MEMBER;
    cx_set(&ic_storage(_this)->type, _this->member->type);
    cx_set(&ic_storage(_this)->base, _this->base);
    ic_storage(_this)->isReference = _this->member->type->reference;
    sprintf(name, "%s.%s", _this->base->name, cx_nameof(_this->member));
    ic_storage(_this)->name = cx_strdup(name);

    return ic_storage_construct(ic_storage(_this));
/* $end */
}
