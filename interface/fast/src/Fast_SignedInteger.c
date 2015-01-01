/* Fast_SignedInteger.c
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

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::SignedInteger::init(SignedInteger object) */
cx_int16 Fast_SignedInteger_init(Fast_SignedInteger object) {
/* $begin(::cortex::Fast::SignedInteger::init) */
    Fast_Literal(object)->kind = FAST_SignedInteger;
    return Fast_Literal_init(Fast_Literal(object));
/* $end */
}

/* ::cortex::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_SignedInteger_serialize(Fast_SignedInteger _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::SignedInteger::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);
    
	memset((void*)dst, 0, cx_type_sizeof(dstType));

	switch(kind) {
	case FAST_Boolean:
		*(cx_bool*)dst = _this->value ? TRUE : FALSE;
		break;
	case FAST_Integer:
	case FAST_SignedInteger:
	case FAST_Enumerated:
	case FAST_String:
		cx_convert(cx_primitive(cx_int64_o), &_this->value, cx_primitive(dstType), (void*)dst);
		break;
	default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize signed integer value to storage of type '%s'", cx_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::SignedInteger::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::SignedInteger::toIc) */
	cx_ic result;
	cx_value v;
	CX_UNUSED(storage);
	CX_UNUSED(stored);

	cx_valueLiteralInit(&v, CX_LITERAL_INTEGER, &_this->value);
	result = (cx_ic)cx_icLiteral__create(
			program, Fast_Node(_this)->line, v, Fast_Expression_getType(Fast_Expression(_this)));

	return result;
/* $end */
}
