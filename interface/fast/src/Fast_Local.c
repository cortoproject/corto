/* Fast_Local.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Local.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Local::construct(Local object) */
db_int16 Fast_Local_construct(Fast_Local object) {
/* $begin(::hyve::Fast::Local::construct) */

    Fast_Node(object)->kind = FAST_Variable;
    Fast_Variable(object)->kind = FAST_Local;
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_typedef(Fast_ObjectBase(object->type)->value)->real));
    object->isReference |= Fast_Expression_getType(Fast_Expression(object))->reference;
    Fast_Expression(object)->isReference = object->isReference;

    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
    	Fast_Expression(object)->forceReference = TRUE;
    }

    return 0;
/* $end */
}

/* virtual ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Local_toIc(Fast_Local _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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
        _result = ((db_ic(*)(Fast_Local, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Local_toIc_v(Fast_Local _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Local::toIc) */
	db_ic result;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	result = (db_ic)db_icLocal__create(
                program,
                Fast_Node(_this)->line,
                _this->name,
                Fast_Expression_getType(Fast_Expression(_this)),
               _this->kind == FAST_LocalParameter,
               _this->kind == FAST_LocalReturn,
               FALSE);

	if (_this->isReference) {
		((db_icStorage)result)->isReference = TRUE;
	}

	return result;
/* $end */
}
