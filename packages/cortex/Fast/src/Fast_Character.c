/* Fast_Character.c
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

/* ::cortex::Fast::Character::init() */
cx_int16 Fast_Character_init(Fast_Character _this) {
/* $begin(::cortex::Fast::Character::init) */
    Fast_Literal(_this)->kind = Fast_Char;
    return Fast_Literal_init(Fast_Literal(_this));
/* $end */
}

/* ::cortex::Fast::Character::serialize(type dstType,word dst) */
cx_int16 Fast_Character_serialize(Fast_Character _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Character::serialize) */
    Fast_valueKind kind;

    kind = Fast_valueKindFromType(dstType);

    switch(kind) {
    case Fast_Bool:
        *(cx_bool*)dst = _this->value ? TRUE : FALSE;
        break;
    case Fast_Char:
    case Fast_Int:
    case Fast_SignedInt:
    case Fast_Text:
        cx_convert(cx_primitive(cx_char_o), &_this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize character value to storage of type '%s'", Fast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Character::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Character_toIc_v(Fast_Character _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Character::toIc) */
    ic_literal result;
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = ic_literal__create((cx_any){cx_type(cx_char_o), &_this->value, FALSE});

    return ic_node(result);
/* $end */
}
