/* Fast_Integer.c
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

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::Integer::init(Integer object) */
db_int16 Fast_Integer_init(Fast_Integer object) {
/* $begin(::hyve::Fast::Integer::init) */
    Fast_Literal(object)->kind = FAST_Integer;
    return Fast_Literal_init((Fast_Literal)object);
/* $end */
}

/* ::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Integer_serialize(Fast_Integer _this, db_type dstType, db_word dst) {
/* $begin(::hyve::Fast::Integer::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);
	memset((void*)dst, 0, db_type_sizeof(dstType));

	switch(kind) {
	case FAST_Boolean:
		*(db_bool*)dst = _this->value ? TRUE : FALSE;
		break;
	case FAST_Integer:
	case FAST_SignedInteger:
    case FAST_FloatingPoint:
	case FAST_Enumerated:
	case FAST_String:
		db_convert(db_primitive(db_uint64_o), &_this->value, db_primitive(dstType), (void*)dst);
		break;
	default: {
        db_id id;
        Fast_Parser_error(yparser(), "cannot serialize integer value to storage of type '%s'", db_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Integer_toIc_v(Fast_Integer _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Integer::toIc) */
	db_ic result;
	db_value v;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	db_valueLiteralInit(&v, DB_LITERAL_UNSIGNED_INTEGER, &_this->value);
	result = (db_ic)db_icLiteral__create(
			program, Fast_Node(_this)->line, v, Fast_Expression_getType(Fast_Expression(_this)));

	return result;
/* $end */
}
