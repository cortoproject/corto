/* Fast_Null.c
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

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Null::init(Null object) */
cx_int16 Fast_Null_init(Fast_Null object) {
/* $begin(::cortex::Fast::Null::init) */
    Fast_Literal(object)->kind = FAST_Null;
    Fast_Expression(object)->type = NULL;
    return Fast_Literal_init(Fast_Literal(object));
/* $end */
}

/* ::cortex::Fast::Null::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_Null_serialize(Fast_Null _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Null::serialize) */
	Fast_valueKind kind;
	DB_UNUSED(_this);

	kind = Fast_valueKindFromType(dstType);
	
    switch(kind) {
	case FAST_Boolean:
		*(cx_bool*)dst = FALSE;
		break;
	case FAST_String:
		if (*(cx_string*)dst) {
			cx_dealloc(*(cx_string*)dst);
		}
		*(cx_string*)dst = NULL;
		break;
	case FAST_Reference:
		if (*(cx_object*)dst) {
			cx_free(*(cx_object*)dst);
		}
		*(cx_object*)dst = NULL;
		break;
	default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize null value to storage of type '%s'", cx_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Null::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Null_toIc_v(Fast_Null _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Null::toIc) */
    cx_ic result;
    DB_UNUSED(storage);
    DB_UNUSED(stored);
    DB_UNUSED(_this);
    cx_value value;

    value.kind = DB_LITERAL;
    value.is.literal.kind = DB_LITERAL_NULL;
    result = (cx_ic)cx_icLiteral__create(program, Fast_Node(_this)->line, value, cx_type(cx_void_o));

    return result;
/* $end */
}
