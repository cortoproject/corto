/* cx_procptr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* ::cortex::lang::procptr::compatible(lang::type type) */
cx_bool cx_procptr_compatible_v(cx_procptr _this, cx_type type) {
/* $begin(::cortex::lang::procptr::compatible) */
    cx_bool result = FALSE;
    DB_UNUSED(_this);

    if((type->kind == DB_COMPOSITE) && (cx_interface(type)->kind == DB_PROCPTR)) {
        cx_uint32 i;
        result = TRUE;

        /* Validate returntype */
        if((_this->returnType != cx_procptr(type)->returnType) || (_this->returnsReference != cx_procptr(type)->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if(_this->parameters.length != cx_procptr(type)->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for(i = 0; !result && (i < _this->parameters.length); i++) {
            if(_this->parameters.buffer[i].type != cx_procptr(type)->parameters.buffer[i].type) {
                result = FALSE;
            }
            if(_this->parameters.buffer[i].passByReference != cx_procptr(type)->parameters.buffer[i].passByReference) {
                result = FALSE;
            }
        }   
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::procptr::init(lang::procptr object) */
cx_int16 cx_procptr_init(cx_procptr object) {
/* $begin(::cortex::lang::procptr::init) */
    cx_int16 result;

    cx_interface(object)->base = cx_interface(cx_procptrdata_o);

    result = cx_struct_init(cx_struct(object));
    if(result) {
        goto error;
    }

    cx_interface(object)->kind = DB_PROCPTR;

    return 0;
error:
    return -1;
/* $end */
}
