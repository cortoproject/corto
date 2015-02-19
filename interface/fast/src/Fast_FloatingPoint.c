/* Fast_FloatingPoint.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::FloatingPoint::init() */
cx_int16 Fast_FloatingPoint_init(Fast_FloatingPoint _this) {
/* $begin(::cortex::Fast::FloatingPoint::init) */
    Fast_Literal(_this)->kind = Fast_Float;
    return Fast_Literal_init(Fast_Literal(_this));
/* $end */
}

/* ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) */
cx_int16 Fast_FloatingPoint_serialize(Fast_FloatingPoint _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::FloatingPoint::serialize) */
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
    case Fast_Text:
        cx_convert(cx_primitive(cx_float64_o), &_this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize floating point value to storage of type '%s'", cx_fullname(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_FloatingPoint_toIc_v(Fast_FloatingPoint _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::FloatingPoint::toIc) */
    cx_ic result;
    cx_value v;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    cx_valueLiteralInit(&v, CX_LITERAL_FLOATING_POINT, &_this->value);
    result = (cx_ic)cx_icLiteral__create(
            program, Fast_Node(_this)->line, v, Fast_Expression_getType(Fast_Expression(_this)));

    return result;
/* $end */
}
