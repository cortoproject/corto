/* db_procptr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* ::cortex::lang::procptr::compatible(lang::type type) */
db_bool db_procptr_compatible_v(db_procptr _this, db_type type) {
/* $begin(::cortex::lang::procptr::compatible) */
    db_bool result = FALSE;
    DB_UNUSED(_this);

    if((type->kind == DB_COMPOSITE) && (db_interface(type)->kind == DB_PROCPTR)) {
        db_uint32 i;
        result = TRUE;

        /* Validate returntype */
        if((_this->returnType != db_procptr(type)->returnType) || (_this->returnsReference != db_procptr(type)->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if(_this->parameters.length != db_procptr(type)->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for(i = 0; !result && (i < _this->parameters.length); i++) {
            if(_this->parameters.buffer[i].type != db_procptr(type)->parameters.buffer[i].type) {
                result = FALSE;
            }
            if(_this->parameters.buffer[i].passByReference != db_procptr(type)->parameters.buffer[i].passByReference) {
                result = FALSE;
            }
        }   
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::procptr::init(lang::procptr object) */
db_int16 db_procptr_init(db_procptr object) {
/* $begin(::cortex::lang::procptr::init) */
    db_int16 result;

    db_interface(object)->base = db_interface(db_procptrdata_o);

    result = db_struct_init(db_struct(object));
    if(result) {
        goto error;
    }

    db_interface(object)->kind = DB_PROCPTR;

    return 0;
error:
    return -1;
/* $end */
}
