/* tc_Animal.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "tc_Animal.h"
#include "tc_call__meta.h"


/* ::tc_call::Animal::getKind() */
tc_AnimalKind tc_Animal_getKind(tc_Animal _this) {
/* $begin(::tc_call::Animal::getKind) */
    return _this->kind;
/* $end */
}

/* virtual ::tc_call::Animal::matesWith(::tc_call::Animal m) */
db_bool tc_Animal_matesWith(tc_Animal _this, tc_Animal m) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "matesWith(::tc_call::Animal m)");
    }
    db_assert(_methodId, "virtual method 'matesWith(::tc_call::Animal m)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::matesWith(::tc_call::Animal m)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::matesWith(::tc_call::Animal m)'.", db_nameof(_this));
        _result = ((db_bool(*)(tc_Animal, tc_Animal ))_method->_parent.impl)(_this, m);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, m);
    }
    
    return _result;
}

/* ::tc_call::Animal::matesWith(::tc_call::Animal m) */
db_bool tc_Animal_matesWith_v(tc_Animal _this, tc_Animal m) {
/* $begin(::tc_call::Animal::matesWith) */
    return _this->kind == m->kind;
/* $end */
}
