/* Fast_NewExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_NewExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::NewExpr::construct(Fast::NewExpr object) */
db_int16 Fast_NewExpr_construct(Fast_NewExpr object) {
/* $begin(::hyve::Fast::NewExpr::construct) */

    Fast_Node(object)->kind = FAST_New;
    Fast_Expression(object)->type = Fast_Variable(object->type);
    db_keep_ext(object, object->type, "Set type of Fast::NewExpr");

    return 0;
/* $end */
}

/* virtual ::hyve::Fast::NewExpr::hasSideEffects() */
db_bool Fast_NewExpr_hasSideEffects(Fast_NewExpr _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    db_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::hasSideEffects()'.", db_nameof(_this));
        _result = ((db_bool(*)(Fast_NewExpr))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::NewExpr::hasSideEffects() */
db_bool Fast_NewExpr_hasSideEffects_v(Fast_NewExpr _this) {
/* $begin(::hyve::Fast::NewExpr::hasSideEffects) */
    DB_UNUSED(_this);
    return TRUE;
/* $end */
}

/* virtual ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_NewExpr_toIc(Fast_NewExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_NewExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_NewExpr_toIc_v(Fast_NewExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::NewExpr::toIc) */
	db_ic type, attrs, result;
	db_icOp op;
	DB_UNUSED(stored);

	if (storage) {
		result = (db_ic)storage;
	} else {
		result = (db_ic)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), TRUE);
	}

	type = Fast_Node_toIc(Fast_Node(_this->type), program, NULL, TRUE);
	if (_this->attributes) {
		attrs = Fast_Node_toIc(Fast_Node(_this->attributes), program, NULL, TRUE);
	} else {
		attrs = NULL;
	}

	op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_NEW, (db_icValue)result, (db_icValue)type, (db_icValue)attrs);
	op->s1Deref = DB_IC_DEREF_ADDRESS;
	db_icProgram_addIc(program, (db_ic)op);

	return result;
/* $end */
}
