/* Fast_Boolean.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Boolean::init() */
cx_int16 Fast_Boolean_init(Fast_Boolean _this) {
/* $begin(::cortex::Fast::Boolean::init) */
    Fast_Literal(_this)->kind = Fast_Bool;
    return Fast_Literal_init(Fast_Literal(_this));
/* $end */
}

/* ::cortex::Fast::Boolean::serialize(type dstType,word dst) */
cx_int16 Fast_Boolean_serialize(Fast_Boolean _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Boolean::serialize) */
    Fast_valueKind kind;

    kind = Fast_valueKindFromType(dstType);

    switch(kind) {
    case Fast_Bool:
    case Fast_Int:
        memset((void*)dst, 0, cx_type_sizeof(dstType));
        *(cx_bool*)dst = _this->value;
        break;
    case Fast_Text:
        if (*(cx_string*)dst) {
            cx_dealloc(*(cx_string*)dst);
        }
        if (_this->value) {
            *(cx_string*)dst = cx_strdup("true");
        } else {
            *(cx_string*)dst = cx_strdup("false");
        }
        break;
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize boolean value to storage of type '%s'", Fast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Boolean::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Boolean_toIc_v(Fast_Boolean _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Boolean::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_literal__create((cx_any){cx_type(cx_bool_o), &_this->value, FALSE});

    return result;
/* $end */
}
