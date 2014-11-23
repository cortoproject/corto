/* Fast_UnaryExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_UnaryExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
db_int16 Fast_UnaryExpr_construct(Fast_UnaryExpr object) {
/* $begin(::hyve::Fast::UnaryExpr::construct) */
	db_type lvalueType;

	lvalueType = Fast_Expression_getType(object->lvalue);
    Fast_Node(object)->kind = FAST_Unary;

    if (object->operator == DB_COND_NOT) {
    	Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_bool_o));
    } else {
    	Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(lvalueType));
    }

    return 0;
/* $end */
}

/* virtual ::hyve::Fast::UnaryExpr::hasSideEffects() */
db_bool Fast_UnaryExpr_hasSideEffects(Fast_UnaryExpr _this) {
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
        _result = ((db_bool(*)(Fast_UnaryExpr))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::UnaryExpr::hasSideEffects() */
db_bool Fast_UnaryExpr_hasSideEffects_v(Fast_UnaryExpr _this) {
/* $begin(::hyve::Fast::UnaryExpr::hasSideEffects) */

    return Fast_Expression_hasSideEffects(_this->lvalue);

/* $end */
}

/* virtual ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_UnaryExpr_toIc(Fast_UnaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_UnaryExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_UnaryExpr_toIc_v(Fast_UnaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::UnaryExpr::toIc) */
	db_icStorage result;
	db_ic lvalue;
	db_icOp op;
	DB_UNUSED(stored);

    if (storage) {
    	result = storage;
    } else {
    	result = (db_icStorage)db_icProgram_accumulatorPush(
            program, 
            Fast_Node(_this)->line, 
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);

    switch(_this->operator) {
    case DB_INC:
    case DB_DEC:
        op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)lvalue, NULL, NULL);
        db_icProgram_addIc(program, (db_ic)op);
        result = (db_icStorage)lvalue;
    	break;
    default:
        op = db_icOp__create(program, Fast_Node(_this)->line, db_icOpKindFromOperator(_this->operator), (db_icValue)result, (db_icValue)lvalue, NULL);
        db_icProgram_addIc(program, (db_ic)op);
    	break;
    }

    if (!storage) {
    	db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (db_ic)result;
/* $end */
}
