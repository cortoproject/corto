/* Fast_SignedInteger.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::SignedInteger::init() */
cx_int16 _Fast_SignedInteger_init(Fast_SignedInteger _this) {
/* $begin(::corto::Fast::SignedInteger::init) */
    Fast_Literal(_this)->kind = Fast_SignedInt;
    return Fast_Literal_init(Fast_Literal(_this));
/* $end */
}

/* ::corto::Fast::SignedInteger::serialize(type dstType,word dst) */
cx_int16 _Fast_SignedInteger_serialize(Fast_SignedInteger _this, cx_type dstType, cx_word dst) {
/* $begin(::corto::Fast::SignedInteger::serialize) */
    Fast_valueKind kind;

    kind = Fast_valueKindFromType(dstType);
    
    memset((void*)dst, 0, cx_type_sizeof(dstType));

    switch(kind) {
    case Fast_Bool:
        *(cx_bool*)dst = _this->value ? TRUE : FALSE;
        break;
    case Fast_Int:
    case Fast_SignedInt:
    case Fast_Enum:
    case Fast_Text:
        cx_convert(cx_primitive(cx_int64_o), &_this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize signed integer value to storage of type '%s'", Fast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::SignedInteger::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::SignedInteger::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_literalCreate((cx_any){Fast_Expression_getType(Fast_Expression(_this)), &_this->value, FALSE});

    return result;
/* $end */
}
