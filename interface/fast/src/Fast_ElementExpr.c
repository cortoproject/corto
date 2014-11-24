/* Fast_ElementExpr.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_ElementExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "db_type.h"
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object) */
db_int16 Fast_ElementExpr_construct(Fast_MemberExpr object) {
/* $begin(::hyve::Fast::ElementExpr::construct) */
	db_type lvalueType, rvalueType;

	Fast_Node(object)->kind = FAST_Element;

	lvalueType = Fast_Expression_getType(object->lvalue);

	if (lvalueType) {
    	if (lvalueType->kind == DB_COLLECTION) {
    		rvalueType = Fast_Expression_getType(object->rvalue);
    		if (rvalueType) {
    			if (db_collection(lvalueType)->kind != DB_MAP) {
					if (!db_type_castable(db_type(db_uint32_o), rvalueType)) {
						db_id id;
						Fast_Parser_error(yparser(), "expected integer expression for index, got '%s'", db_fullname(rvalueType, id));
						goto error;
					}
    			} else {
					if (!db_type_castable(db_map(lvalueType)->keyType->real, rvalueType)) {
						db_id id, id2;
						Fast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
								db_fullname(db_map(lvalueType)->keyType->real, id), db_fullname(rvalueType, id2));
						goto error;
					}
    			}
    		}
    	    /* Set type of expression */
    		Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_collection(lvalueType)->elementType->real));
    	} else {
    		db_id id;
    		Fast_Parser_error(yparser(), "cannot obtain element from object of non-collection type '%s'", db_fullname(lvalueType, id));
    		goto error;
    	}
    } else {
    	Fast_Parser_error(yparser(), "dynamic expressions are not yet supported");
    	goto error;
    }
    
    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
    	Fast_Expression(object)->forceReference = TRUE;
        Fast_Expression(object)->isReference = TRUE;
    }

    return 0;
error:
	return -1;
/* $end */
}

/* virtual ::hyve::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_ElementExpr_toIc(Fast_ElementExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_ElementExpr, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_ElementExpr_toIc_v(Fast_ElementExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::ElementExpr::toIc) */
	db_icElement result;
	db_ic lvalue, rvalue;
	DB_UNUSED(stored);
	DB_UNUSED(storage);

	/* Get lvalue & rvalue */
	lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
	rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, NULL, TRUE);

	result = db_icElement__create(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), (db_icStorage)lvalue, (db_icValue)rvalue);

	return (db_ic)result;
/* $end */
}
