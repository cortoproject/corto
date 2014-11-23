/* Fast_Literal.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Literal.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
/* $end */

/* virtual ::hyve::Fast::Literal::getValue() */
db_word Fast_Literal_getValue(Fast_Literal _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_word _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "getValue()");
    }
    db_assert(_methodId, "virtual method 'getValue()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::getValue()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::getValue()'.", db_nameof(_this));
        _result = ((db_word(*)(Fast_Literal))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::Literal::getValue() */
db_word Fast_Literal_getValue_v(Fast_Literal _this) {
/* $begin(::hyve::Fast::Literal::getValue) */
	db_word result = 0;

    switch(_this->kind) {
    case FAST_Boolean: result = (db_word)&Fast_Boolean(_this)->value; break;
    case FAST_Character: result = (db_word)&Fast_Character(_this)->value; break;
    case FAST_Integer: result = (db_word)&Fast_Integer(_this)->value; break;
    case FAST_SignedInteger: result = (db_word)&Fast_SignedInteger(_this)->value; break;
    case FAST_FloatingPoint: result = (db_word)&Fast_FloatingPoint(_this)->value; break;
    default: break; /* Enumerated, Reference & Null have no value. String handles it's own value. */
    }

    return result;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::Literal::init(Literal object) */
db_int16 Fast_Literal_init(Fast_Literal object) {
/* $begin(::hyve::Fast::Literal::init) */
    if (!Fast_Expression(object)->type) {
        switch(object->kind) {
        case FAST_Boolean:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_bool_o);
            break;
        case FAST_Character:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_char_o);
            break;
        case FAST_Integer:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_uint64_o);
            break;
        case FAST_SignedInteger:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_int64_o);
            break;
        case FAST_FloatingPoint:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_float64_o);
            break;
        case FAST_String:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_string_o);
            break;
        case FAST_Enumerated:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_uint32_o);
            break;
        case FAST_Reference:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_object_o);
            break;
        case FAST_Null:
            /* No type. */
            break;
        }
    }

    Fast_Node(object)->kind = FAST_Literal;

    return Fast_Expression_init(Fast_Expression(object));
/* $end */
}
