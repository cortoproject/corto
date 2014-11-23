/* Fast_SignedInteger.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_SignedInteger.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::SignedInteger::init(SignedInteger object) */
db_int16 Fast_SignedInteger_init(Fast_SignedInteger object) {
/* $begin(::hyve::Fast::SignedInteger::init) */
    Fast_Literal(object)->kind = FAST_SignedInteger;
    return Fast_Literal_init(Fast_Literal(object));
/* $end */
}

/* ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_SignedInteger_serialize(Fast_SignedInteger _this, db_type dstType, db_word dst) {
/* $begin(::hyve::Fast::SignedInteger::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);
    
	memset((void*)dst, 0, db_type_sizeof(dstType));

	switch(kind) {
	case FAST_Boolean:
		*(db_bool*)dst = _this->value ? TRUE : FALSE;
		break;
	case FAST_Integer:
	case FAST_SignedInteger:
	case FAST_Enumerated:
	case FAST_String:
		db_convert(db_primitive(db_int64_o), &_this->value, db_primitive(dstType), (void*)dst);
		break;
	default: {
        db_id id;
        Fast_Parser_error(yparser(), "cannot serialize signed integer value to storage of type '%s'", db_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* virtual ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_SignedInteger_toIc(Fast_SignedInteger _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_SignedInteger, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::SignedInteger::toIc) */
	db_ic result;
	db_value v;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	db_valueLiteralInit(&v, DB_LITERAL_INTEGER, &_this->value);
	result = (db_ic)db_icLiteral__create(
			program, Fast_Node(_this)->line, v, Fast_Expression_getType(Fast_Expression(_this)));

	return result;
/* $end */
}
