/* Fast_Boolean.c
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

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::Boolean::init(Boolean object) */
db_int16 Fast_Boolean_init(Fast_Boolean object) {
/* $begin(::hyve::Fast::Boolean::init) */
    Fast_Literal(object)->kind = FAST_Boolean;
    return Fast_Literal_init(Fast_Literal(object));
/* $end */
}

/* ::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Boolean_serialize(Fast_Boolean _this, db_type dstType, db_word dst) {
/* $begin(::hyve::Fast::Boolean::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);

	switch(kind) {
	case FAST_Boolean:
	case FAST_Integer:
		memset((void*)dst, 0, db_type_sizeof(dstType));
		*(db_bool*)dst = _this->value;
		break;
	case FAST_String:
		if (*(db_string*)dst) {
			db_dealloc(*(db_string*)dst);
		}
		if (_this->value) {
			*(db_string*)dst = db_strdup("true");
		} else {
			*(db_string*)dst = db_strdup("false");
		}
		break;
	default: {
        db_id id;
        Fast_Parser_error(yparser(), "cannot serialize boolean value to storage of type '%s'", db_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Boolean_toIc_v(Fast_Boolean _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Boolean::toIc) */
	db_ic result;
	db_value v;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	db_valueLiteralInit(&v, DB_LITERAL_BOOLEAN, &_this->value);
	result = (db_ic)db_icLiteral__create(program, Fast_Node(_this)->line, v, db_type(db_bool_o));

	return result;
/* $end */
}
