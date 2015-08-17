/* Fast_Integer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Integer::init() */
cx_int16 _Fast_Integer_init(Fast_Integer _this) {
/* $begin(::cortex::Fast::Integer::init) */
    Fast_Literal(_this)->kind = Fast_Int;
    return Fast_Literal_init((Fast_Literal)_this);
/* $end */
}

/* ::cortex::Fast::Integer::serialize(type dstType,word dst) */
cx_int16 _Fast_Integer_serialize(Fast_Integer _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Integer::serialize) */
    Fast_valueKind kind;

    kind = Fast_valueKindFromType(dstType);
    memset((void*)dst, 0, cx_type_sizeof(dstType));

    switch(kind) {
    case Fast_Bool:
        *(cx_bool*)dst = _this->value ? TRUE : FALSE;
        break;
    case Fast_Int:
    case Fast_SignedInt:
    case Fast_Float:
    case Fast_Enum:
    case Fast_Text:
        cx_convert(cx_primitive(cx_uint64_o), &_this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize integer value to storage of type '%s'", Fast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Integer::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Integer_toIc_v(Fast_Integer _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Integer::toIc) */
    ic_node result;
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (ic_node)ic_literal__create((cx_any){Fast_Expression_getType(Fast_Expression(_this)), &_this->value, FALSE});

    return result;
/* $end */
}
