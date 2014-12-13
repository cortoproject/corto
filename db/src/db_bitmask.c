/* db_bitmask.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__bitmask.h"
db_int16 db__bitmask_bindConstant(db_bitmask _this, db_constant* c) {
    db_rbtree scope;

    if (db_checkState(db_type_o, DB_DEFINED)) {
        scope = db_scopeof(_this);
        *c = 0x1 << (db_rbtreeSize(scope)-1);
    }
    db_enum(_this)->constants.buffer = db_realloc(db_enum(_this)->constants.buffer, (db_enum(_this)->constants.length+1) * sizeof(db_constant*));
    db_enum(_this)->constants.buffer[db_enum(_this)->constants.length] = c;
    db_enum(_this)->constants.length++;
    
    db_keep(c);

    return 0;
}
/* $end */

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::bitmask::init(lang::bitmask object) */
db_int16 db_bitmask_init(db_bitmask object) {
/* $begin(::hyve::lang::bitmask::init) */
    db_primitive(object)->kind = DB_BITMASK;
    db_primitive(object)->width = DB_WIDTH_32;
    db_set(&db_type(object)->defaultType, db_constant_o);
    return db_primitive_init((db_primitive)object);
/* $end */
}
