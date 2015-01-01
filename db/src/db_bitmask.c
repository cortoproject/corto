/* cx_bitmask.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* $header() */
#include "cx__bitmask.h"
cx_int16 cx__bitmask_bindConstant(cx_bitmask _this, cx_constant* c) {
    cx_rbtree scope;

    if (cx_checkState(cx_type_o, DB_DEFINED)) {
        scope = cx_scopeof(_this);
        *c = 0x1 << (cx_rbtreeSize(scope)-1);
    }
    cx_enum(_this)->constants.buffer = cx_realloc(cx_enum(_this)->constants.buffer, (cx_enum(_this)->constants.length+1) * sizeof(cx_constant*));
    cx_enum(_this)->constants.buffer[cx_enum(_this)->constants.length] = c;
    cx_enum(_this)->constants.length++;
    
    cx_keep(c);

    return 0;
}
/* $end */

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::bitmask::init(lang::bitmask object) */
cx_int16 cx_bitmask_init(cx_bitmask object) {
/* $begin(::cortex::lang::bitmask::init) */
    cx_primitive(object)->kind = DB_BITMASK;
    cx_primitive(object)->width = DB_WIDTH_32;
    cx_set(&cx_type(object)->defaultType, cx_constant_o);
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
