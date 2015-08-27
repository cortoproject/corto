/* Fast_Storage.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* ::corto::Fast::Storage::construct() */
cx_int16 _Fast_Storage_construct(Fast_Storage _this) {
/* $begin(::corto::Fast::Storage::construct) */

    Fast_Node(_this)->kind = Fast_StorageExpr;
    Fast_Expression(_this)->deref = Fast_Expression(_this)->type->reference ? Fast_ByReference : Fast_ByValue;

    return 0;
/* $end */
}
