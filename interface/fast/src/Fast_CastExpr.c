/* Fast_CastExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_CastExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "db_type.h"
#include "Fast__api.h"
#include "Fast.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::CastExpr::construct(Fast::CastExpr object) */
db_int16 Fast_CastExpr_construct(Fast_CastExpr object) {
/* $begin(::hyve::Fast::CastExpr::construct) */

	Fast_Node(object)->kind = FAST_Call;

	if (Fast_Node(object->lvalue)->kind == FAST_Variable) {
		if (Fast_Variable(object->lvalue)->kind == FAST_Object) {
			db_object lvalue = Fast_ObjectBase(object->lvalue)->value;
			if (db_class_instanceof(db_type_o, lvalue)) {
				db_type rvalueType;
				rvalueType = Fast_Expression_getType(object->rvalue);
				if (rvalueType) {
					if (db_type_castable(rvalueType, db_type(lvalue))) {
                        /* TODO: db_assert(!db_type_compatible(rvalueType, db_type(lvalue)), "%d: redundant cast inserted", yparser()->line); */
						Fast_Expression(object)->type = (Fast_Variable)object->lvalue;
					} else {
                        db_id id1, id2;
                        Fast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                                db_fullname(rvalueType, id1), db_fullname(lvalue, id2));
                        goto error;
					}
				} else {
					/* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
					 * type barrier for code using this expression. */
					Fast_Expression(object)->type = (Fast_Variable)object->lvalue;
				}
			} else {
				Fast_Parser_error(yparser(), "left-side of cast-expression is not a type");
				goto error;
			}
		} else {
			Fast_Parser_error(yparser(), "dynamic expressions in cast-expression not supported");
			goto error;
		}
	} else {
		Fast_Parser_error(yparser(), "dynamic expressions in cast-expression not supported");
		goto error;
	}

	/* Keep type */
	db_keep_ext(object, object->lvalue, "type");

	return 0;
error:
	return -1;
/* $end */
}

/* virtual ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CastExpr_toIc(Fast_CastExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_CastExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CastExpr_toIc_v(Fast_CastExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::CastExpr::toIc) */
	db_ic lvalue, rvalue, result;
	db_icOp op;
	db_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
	DB_UNUSED(stored);

    if (storage && (storage->type == _thisType)) {
        result = (db_ic)storage;
    } else {
        result = (db_ic)db_icProgram_accumulatorPush(
        	program, 
        	Fast_Node(_this)->line, 
        	Fast_Expression_getType(Fast_Expression(_this)),
        	Fast_Expression(_this)->isReference);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (db_icStorage)NULL, TRUE);

    op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_CAST, (db_icValue)result, (db_icValue)rvalue, (db_icValue)lvalue);
    db_icProgram_addIc(program, (db_ic)op);

    return result;
/* $end */
}
