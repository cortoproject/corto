/* Fast__wrapper.c
 *
 * This file contains wrapper functions for ::hyve::Fast.
 */

#include "Fast.h"
#include "Fast__meta.h"

void __Fast_valueKindFromType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_valueKind*)result = Fast_valueKindFromType(
        *(db_type*)args);
}

void __Fast_BinaryExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_BinaryExpr_construct(
        *(Fast_BinaryExpr*)args);
}

void __Fast_BinaryExpr_fold(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Expression*)result = Fast_BinaryExpr_fold(
        *(Fast_BinaryExpr*)args);
}

/* virtual ::hyve::Fast::BinaryExpr::hasSideEffects() */
db_bool Fast_BinaryExpr_hasSideEffects(Fast_BinaryExpr _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_BinaryExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_BinaryExpr_hasSideEffects_v(
        *(Fast_BinaryExpr*)args);
}

void __Fast_BinaryExpr_setOperator(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_BinaryExpr_setOperator(
        *(Fast_BinaryExpr*)args,
        *(db_operatorKind*)((intptr_t)args + sizeof(Fast_BinaryExpr)));
}

/* virtual ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_BinaryExpr_toIc(Fast_BinaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_BinaryExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_BinaryExpr_toIc_v(
        *(Fast_BinaryExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_BinaryExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_BinaryExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_BinaryExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Block_addStatement(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Block_addStatement(
        *(Fast_Block*)args,
        *(Fast_Node*)((intptr_t)args + sizeof(Fast_Block)));
}

void __Fast_Block_declare(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_declare(
        *(Fast_Block*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Block)),
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string) + sizeof(Fast_Variable)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string) + sizeof(Fast_Variable) + sizeof(db_bool)));
}

void __Fast_Block_declareReturnVariable(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_declareReturnVariable(
        *(Fast_Block*)args,
        *(db_function*)((intptr_t)args + sizeof(Fast_Block)));
}

void __Fast_Block_declareTemplate(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Template*)result = Fast_Block_declareTemplate(
        *(Fast_Block*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Block)),
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string) + sizeof(Fast_Variable)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_string) + sizeof(Fast_Variable) + sizeof(db_bool)));
}

void __Fast_Block_lookup(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Block_lookup(
        *(Fast_Block*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Block)));
}

void __Fast_Block_lookupLocal(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Block_lookupLocal(
        *(Fast_Block*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Block)));
}

void __Fast_Block_resolve(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Block_resolve(
        *(Fast_Block*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Block)));
}

void __Fast_Block_setFunction(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Block_setFunction(
        *(Fast_Block*)args,
        *(db_function*)((intptr_t)args + sizeof(Fast_Block)));
}

/* virtual ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIc(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Block_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Block_toIc_v(
        *(Fast_Block*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Block)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

/* virtual ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Block_toIcBody(Fast_Block _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Block_toIcBody_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Block_toIcBody_v(
        *(Fast_Block*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Block)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Block) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Boolean_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Boolean_init(
        *(Fast_Boolean*)args);
}

void __Fast_Boolean_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Boolean_serialize(
        *(Fast_Boolean*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Boolean)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Boolean) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Boolean_toIc(Fast_Boolean _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Boolean_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Boolean_toIc_v(
        *(Fast_Boolean*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Boolean)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Boolean) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Boolean) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Call_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Call_construct(
        *(Fast_Call*)args);
}

/* virtual ::hyve::Fast::Call::hasSideEffects() */
db_bool Fast_Call_hasSideEffects(Fast_Call _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Call_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_Call_hasSideEffects_v(
        *(Fast_Call*)args);
}

/* virtual ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Call_toIc(Fast_Call _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Call_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Call_toIc_v(
        *(Fast_Call*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Call)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Call) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Call) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_CastExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_CastExpr_construct(
        *(Fast_CastExpr*)args);
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_CastExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_CastExpr_toIc_v(
        *(Fast_CastExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_CastExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_CastExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_CastExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Character_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Character_init(
        *(Fast_Character*)args);
}

void __Fast_Character_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Character_serialize(
        *(Fast_Character*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Character)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Character) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Character_toIc(Fast_Character _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Character_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Character_toIc_v(
        *(Fast_Character*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Character)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Character) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Character) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_CommaExpr_addExpression(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_CommaExpr_addExpression(
        *(Fast_CommaExpr*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_CommaExpr)));
}

void __Fast_CommaExpr_addOrCreate(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_CommaExpr_addOrCreate(
        *(Fast_Expression*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Expression)));
}

void __Fast_CommaExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_CommaExpr_construct(
        *(Fast_CommaExpr*)args);
}

/* virtual ::hyve::Fast::CommaExpr::hasSideEffects() */
db_bool Fast_CommaExpr_hasSideEffects(Fast_CommaExpr _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_CommaExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_CommaExpr_hasSideEffects_v(
        *(Fast_CommaExpr*)args);
}

void __Fast_CommaExpr_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_CommaExpr_init(
        *(Fast_CommaExpr*)args);
}

/* virtual ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CommaExpr_toIc(Fast_CommaExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_CommaExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_CommaExpr_toIc_v(
        *(Fast_CommaExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_CommaExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_CommaExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_CommaExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_CommaExpr_toList(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Node_list*)result = Fast_CommaExpr_toList(
        *(Fast_CommaExpr*)args);
}

void __Fast_Define_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Define_construct(
        *(Fast_Define*)args);
}

/* virtual ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Define_toIc(Fast_Define _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Define_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Define_toIc_v(
        *(Fast_Define*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Define)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Define) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Define) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_DynamicInitializer_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_DynamicInitializer_construct(
        *(Fast_DynamicInitializer*)args);
}

void __Fast_DynamicInitializer_define(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_DynamicInitializer_define(
        *(Fast_DynamicInitializer*)args);
}

void __Fast_DynamicInitializer_pop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_DynamicInitializer_pop(
        *(Fast_DynamicInitializer*)args);
}

void __Fast_DynamicInitializer_push(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_DynamicInitializer_push(
        *(Fast_DynamicInitializer*)args);
}

void __Fast_DynamicInitializer_value(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_DynamicInitializer_value(
        *(Fast_DynamicInitializer*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_DynamicInitializer)));
}

void __Fast_ElementExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_ElementExpr_construct(
        *(Fast_MemberExpr*)args);
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_ElementExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_ElementExpr_toIc_v(
        *(Fast_ElementExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_ElementExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_ElementExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_ElementExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Expression_cast(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Expression_cast(
        *(Fast_Expression*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Expression)));
}

void __Fast_Expression_cleanList(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Expression_cleanList(
        *(Fast_Expression_list*)args);
}

/* virtual ::hyve::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold(Fast_Expression _this) {
    static db_uint32 _methodId;
    db_method _method;
    Fast_Expression _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "fold()");
    }
    db_assert(_methodId, "virtual method 'fold()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::fold()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_fold_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Expression*)result = Fast_Expression_fold_v(
        *(Fast_Expression*)args);
}

void __Fast_Expression_fromList(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Expression_fromList(
        *(Fast_Expression_list*)args);
}

void __Fast_Expression_getType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = Fast_Expression_getType(
        *(Fast_Expression*)args);
}

void __Fast_Expression_getType_expr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_type*)result = Fast_Expression_getType_expr(
        *(Fast_Expression*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Expression)));
}

void __Fast_Expression_getType_type(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_type*)result = Fast_Expression_getType_type(
        *(Fast_Expression*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Expression)));
}

/* virtual ::hyve::Fast::Expression::getValue() */
db_word Fast_Expression_getValue(Fast_Expression _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_getValue_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_word*)result = Fast_Expression_getValue_v(
        *(Fast_Expression*)args);
}

/* virtual ::hyve::Fast::Expression::hasSideEffects() */
db_bool Fast_Expression_hasSideEffects(Fast_Expression _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_Expression_hasSideEffects_v(
        *(Fast_Expression*)args);
}

void __Fast_Expression_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Expression_init(
        *(Fast_Expression*)args);
}

/* virtual ::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Expression_serialize(Fast_Expression _this, db_type dstType, db_word dst) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "serialize(lang::type dstType,lang::word dst)");
    }
    db_assert(_methodId, "virtual method 'serialize(lang::type dstType,lang::word dst)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::serialize(lang::type dstType,lang::word dst)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, dstType, dst);
    
    return _result;
}

void __Fast_Expression_serialize_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Expression_serialize_v(
        *(Fast_Expression*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Expression)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Expression) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList(Fast_Expression _this) {
    static db_uint32 _methodId;
    db_method _method;
    Fast_Expression_list _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toList()");
    }
    db_assert(_methodId, "virtual method 'toList()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toList()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_toList_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Expression_list*)result = Fast_Expression_toList_v(
        *(Fast_Expression*)args);
}

void __Fast_FloatingPoint_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_FloatingPoint_init(
        *(Fast_FloatingPoint*)args);
}

void __Fast_FloatingPoint_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_FloatingPoint_serialize(
        *(Fast_FloatingPoint*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_FloatingPoint)),
        *(db_word*)((intptr_t)args + sizeof(Fast_FloatingPoint) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_FloatingPoint_toIc(Fast_FloatingPoint _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_FloatingPoint_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_FloatingPoint_toIc_v(
        *(Fast_FloatingPoint*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_FloatingPoint)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_FloatingPoint) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_FloatingPoint) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_If_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_If_construct(
        *(Fast_If*)args);
}

void __Fast_If_noWarnUnreachable(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_If_noWarnUnreachable(
        *(Fast_If*)args);
}

/* virtual ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_If_toIc(Fast_If _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_If_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_If_toIc_v(
        *(Fast_If*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_If)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_If) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_If) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Initializer_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Initializer_construct(
        *(Fast_Initializer*)args);
}

void __Fast_Initializer_currentType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = Fast_Initializer_currentType(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::define() */
db_int16 Fast_Initializer_define(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "define()");
    }
    db_assert(_methodId, "virtual method 'define()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::define()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_define_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Initializer_define_v(
        *(Fast_Initializer*)args);
}

void __Fast_Initializer_initFrame(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint16*)result = Fast_Initializer_initFrame(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::member(lang::string name) */
db_int32 Fast_Initializer_member(Fast_Initializer _this, db_string name) {
    static db_uint32 _methodId;
    db_method _method;
    db_int32 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "member(lang::string name)");
    }
    db_assert(_methodId, "virtual method 'member(lang::string name)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::member(lang::string name)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, name);
    
    return _result;
}

void __Fast_Initializer_member_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int32*)result = Fast_Initializer_member_v(
        *(Fast_Initializer*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Initializer)));
}

/* virtual ::hyve::Fast::Initializer::next() */
db_int16 Fast_Initializer_next(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "next()");
    }
    db_assert(_methodId, "virtual method 'next()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::next()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_next_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Initializer_next_v(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::pop() */
db_int8 Fast_Initializer_pop(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int8 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "pop()");
    }
    db_assert(_methodId, "virtual method 'pop()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::pop()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_pop_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int8*)result = Fast_Initializer_pop_v(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::popKey() */
db_int16 Fast_Initializer_popKey(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "popKey()");
    }
    db_assert(_methodId, "virtual method 'popKey()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::popKey()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_popKey_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Initializer_popKey_v(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::push() */
db_int16 Fast_Initializer_push(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "push()");
    }
    db_assert(_methodId, "virtual method 'push()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::push()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_push_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Initializer_push_v(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::pushKey() */
db_int16 Fast_Initializer_pushKey(Fast_Initializer _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "pushKey()");
    }
    db_assert(_methodId, "virtual method 'pushKey()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::pushKey()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_pushKey_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Initializer_pushKey_v(
        *(Fast_Initializer*)args);
}

void __Fast_Initializer_type(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = Fast_Initializer_type(
        *(Fast_Initializer*)args);
}

/* virtual ::hyve::Fast::Initializer::value(Expression v) */
db_int16 Fast_Initializer_value(Fast_Initializer _this, Fast_Expression v) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "value(Expression v)");
    }
    db_assert(_methodId, "virtual method 'value(Expression v)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::value(Expression v)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, v);
    
    return _result;
}

void __Fast_Initializer_value_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Initializer_value_v(
        *(Fast_Initializer*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Initializer)));
}

/* virtual ::hyve::Fast::Initializer::valueKey(Expression key) */
db_int16 Fast_Initializer_valueKey(Fast_Initializer _this, Fast_Expression key) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "valueKey(Expression key)");
    }
    db_assert(_methodId, "virtual method 'valueKey(Expression key)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::valueKey(Expression key)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, key);
    
    return _result;
}

void __Fast_Initializer_valueKey_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Initializer_valueKey_v(
        *(Fast_Initializer*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Initializer)));
}

void __Fast_InitializerExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_InitializerExpr_construct(
        *(Fast_InitializerExpr*)args);
}

void __Fast_InitializerExpr_define(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_InitializerExpr_define(
        *(Fast_InitializerExpr*)args);
}

void __Fast_InitializerExpr_insert(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_InitializerExpr_insert(
        *(Fast_InitializerExpr*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_InitializerExpr)));
}

void __Fast_InitializerExpr_member(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int32*)result = Fast_InitializerExpr_member(
        *(Fast_InitializerExpr*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_InitializerExpr)));
}

void __Fast_InitializerExpr_pop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_InitializerExpr_pop(
        *(Fast_InitializerExpr*)args);
}

void __Fast_InitializerExpr_push(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_InitializerExpr_push(
        *(Fast_InitializerExpr*)args);
}

void __Fast_InitializerExpr_value(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_InitializerExpr_value(
        *(Fast_InitializerExpr*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_InitializerExpr)));
}

void __Fast_Integer_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Integer_init(
        *(Fast_Integer*)args);
}

void __Fast_Integer_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Integer_serialize(
        *(Fast_Integer*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Integer)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Integer) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Integer_toIc(Fast_Integer _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Integer_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Integer_toIc_v(
        *(Fast_Integer*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Integer)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Integer) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Integer) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Literal_getValue_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_word*)result = Fast_Literal_getValue_v(
        *(Fast_Literal*)args);
}

void __Fast_Literal_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Literal_init(
        *(Fast_Literal*)args);
}

void __Fast_Local_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Local_construct(
        *(Fast_Local*)args);
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Local_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Local_toIc_v(
        *(Fast_Local*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Local)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Local) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Local) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_MemberExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_MemberExpr_construct(
        *(Fast_MemberExpr*)args);
}

/* virtual ::hyve::Fast::MemberExpr::hasSideEffects() */
db_bool Fast_MemberExpr_hasSideEffects(Fast_MemberExpr _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_MemberExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_MemberExpr_hasSideEffects_v(
        *(Fast_MemberExpr*)args);
}

/* virtual ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_MemberExpr_toIc(Fast_MemberExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_MemberExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_MemberExpr_toIc_v(
        *(Fast_MemberExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_MemberExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_MemberExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_MemberExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_NewExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_NewExpr_construct(
        *(Fast_NewExpr*)args);
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_NewExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_NewExpr_hasSideEffects_v(
        *(Fast_NewExpr*)args);
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_NewExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_NewExpr_toIc_v(
        *(Fast_NewExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_NewExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_NewExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_NewExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Node_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Node_init(
        *(Fast_Node*)args);
}

/* virtual ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Node_toIc(Fast_Node _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Node_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Node_toIc_v(
        *(Fast_Node*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Node)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Node) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Node) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Null_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Null_init(
        *(Fast_Null*)args);
}

void __Fast_Null_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Null_serialize(
        *(Fast_Null*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Null)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Null) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Null_toIc(Fast_Null _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Null_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Null_toIc_v(
        *(Fast_Null*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Null)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Null) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Null) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Object_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Object_construct(
        *(Fast_Object*)args);
}

void __Fast_Object_getValue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_word*)result = Fast_Object_getValue(
        *(Fast_Object*)args);
}

void __Fast_Object_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Object_serialize(
        *(Fast_Object*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_Object)),
        *(db_word*)((intptr_t)args + sizeof(Fast_Object) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Object_toIc(Fast_Object _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Object_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Object_toIc_v(
        *(Fast_Object*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Object)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Object) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Object) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_ObjectBase_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_ObjectBase_construct(
        *(Fast_ObjectBase*)args);
}

void __Fast_Parser_addStatement(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_addStatement(
        *(Fast_Parser*)args,
        *(Fast_Node*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_argumentToString(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_string*)result = Fast_Parser_argumentToString(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable) + sizeof(db_string)));
}

void __Fast_Parser_binaryExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_binaryExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)),
        *(db_operatorKind*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression) + sizeof(Fast_Expression)));
}

void __Fast_Parser_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_bind(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable)));
}

void __Fast_Parser_bindOneliner(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_bindOneliner(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable) + sizeof(Fast_Block)));
}

void __Fast_Parser_blockPop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_blockPop(
        *(Fast_Parser*)args);
}

void __Fast_Parser_blockPush(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Block*)result = Fast_Parser_blockPush(
        *(Fast_Parser*)args,
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_callExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_callExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_castExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_castExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_collect(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_collect(
        *(Fast_Parser*)args,
        *(db_object*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_collectHeap(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_collectHeap(
        *(Fast_Parser*)args,
        *(db_word*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_construct(
        *(Fast_Parser*)args);
}

void __Fast_Parser_declaration(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_declaration(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable) + sizeof(db_string)));
}

void __Fast_Parser_declareFunction(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_declareFunction(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable)),
        *(db_type*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable) + sizeof(db_string)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Variable) + sizeof(db_string) + sizeof(db_type)));
}

void __Fast_Parser_declareFunctionParams(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Block*)result = Fast_Parser_declareFunctionParams(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_define(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_define(
        *(Fast_Parser*)args);
}

void __Fast_Parser_defineScope(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_defineScope(
        *(Fast_Parser*)args);
}

void __Fast_Parser_defineVariable(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_defineVariable(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_destruct(
        *(Fast_Parser*)args);
}

void __Fast_Parser_elementExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_elementExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_foreach(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_foreach(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string)));
}

void __Fast_Parser_getComplexType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = Fast_Parser_getComplexType(
        *(Fast_Parser*)args);
}

void __Fast_Parser_getLvalue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_getLvalue(
        *(Fast_Parser*)args,
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_getLvalueType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_type*)result = Fast_Parser_getLvalueType(
        *(Fast_Parser*)args,
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_ifStatement(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_ifStatement(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)),
        *(Fast_If*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression) + sizeof(Fast_Block)));
}

void __Fast_Parser_initDeclareStaged(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_initDeclareStaged(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_initKeyValuePop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_initKeyValuePop(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initKeyValuePush(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_initKeyValuePush(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initKeyValueSet(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_initKeyValueSet(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_initMember(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_initMember(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_initPop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_initPop(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initPush(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_initPush(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initPushExpression(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Expression*)result = Fast_Parser_initPushExpression(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initPushIdentifier(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_initPushIdentifier(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_initPushStatic(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_Parser_initPushStatic(
        *(Fast_Parser*)args);
}

void __Fast_Parser_initStage(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_initStage(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string)));
}

void __Fast_Parser_initValue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Parser_initValue(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_isAbortSet(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_Parser_isAbortSet(
        *(Fast_Parser*)args);
}

void __Fast_Parser_isErrSet(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_Parser_isErrSet(
        *(Fast_Parser*)args);
}

void __Fast_Parser_lookup(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_lookup(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_object*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string)));
}

void __Fast_Parser_memberExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_memberExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_observerDeclaration(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_observerDeclaration(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string)),
        *(db_eventMask*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string) + sizeof(Fast_Expression)),
        *(Fast_Object*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string) + sizeof(Fast_Expression) + sizeof(db_eventMask)));
}

void __Fast_Parser_observerPop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_observerPop(
        *(Fast_Parser*)args);
}

void __Fast_Parser_observerPush(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_observerPush(
        *(Fast_Parser*)args);
}

void __Fast_Parser_parse(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint32*)result = Fast_Parser_parse(
        *(Fast_Parser*)args);
}

void __Fast_Parser_parseExpression(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_parseExpression(
        *(Fast_Parser*)args,
        *(db_string*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string)),
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string) + sizeof(Fast_Block)),
        *(db_uint32*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string) + sizeof(Fast_Block) + sizeof(Fast_Variable)),
        *(db_uint32*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(db_string) + sizeof(Fast_Block) + sizeof(Fast_Variable) + sizeof(db_uint32)));
}

void __Fast_Parser_popComplexType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_popComplexType(
        *(Fast_Parser*)args);
}

void __Fast_Parser_popLvalue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_popLvalue(
        *(Fast_Parser*)args);
}

void __Fast_Parser_popScope(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_popScope(
        *(Fast_Parser*)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_postfixExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_postfixExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_operatorKind*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_pushComplexType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_pushComplexType(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_pushLvalue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_pushLvalue(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_pushReturnAsLvalue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_Parser_pushReturnAsLvalue(
        *(Fast_Parser*)args,
        *(db_function*)((intptr_t)args + sizeof(Fast_Parser)));
}

void __Fast_Parser_pushScope(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(Fast_Variable*)result = Fast_Parser_pushScope(
        *(Fast_Parser*)args);
}

void __Fast_Parser_reset(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    Fast_Parser_reset(
        *(Fast_Parser*)args);
}

void __Fast_Parser_ternaryExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_ternaryExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression) + sizeof(Fast_Expression)));
}

void __Fast_Parser_unaryExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_unaryExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(db_operatorKind*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_updateStatement(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_updateStatement(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)));
}

void __Fast_Parser_waitExpr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_waitExpr(
        *(Fast_Parser*)args,
        *(Fast_Expression_list*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression_list)));
}

void __Fast_Parser_whileStatement(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_whileStatement(
        *(Fast_Parser*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Parser)),
        *(Fast_Block*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Parser) + sizeof(Fast_Expression) + sizeof(Fast_Block)));
}

void __Fast_PostfixExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_PostfixExpr_construct(
        *(Fast_PostfixExpr*)args);
}

/* virtual ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_PostfixExpr_toIc(Fast_PostfixExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_PostfixExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_PostfixExpr_toIc_v(
        *(Fast_PostfixExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_PostfixExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_PostfixExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_PostfixExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_SignedInteger_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_SignedInteger_init(
        *(Fast_SignedInteger*)args);
}

void __Fast_SignedInteger_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_SignedInteger_serialize(
        *(Fast_SignedInteger*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_SignedInteger)),
        *(db_word*)((intptr_t)args + sizeof(Fast_SignedInteger) + sizeof(db_type)));
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_SignedInteger_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_SignedInteger_toIc_v(
        *(Fast_SignedInteger*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_SignedInteger)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_SignedInteger) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_SignedInteger) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_StaticInitializer_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_StaticInitializer_construct(
        *(Fast_StaticInitializer*)args);
}

void __Fast_StaticInitializer_define(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_StaticInitializer_define(
        *(Fast_StaticInitializer*)args);
}

void __Fast_StaticInitializer_push(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = Fast_StaticInitializer_push(
        *(Fast_StaticInitializer*)args);
}

void __Fast_StaticInitializer_value(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_StaticInitializer_value(
        *(Fast_StaticInitializer*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_StaticInitializer)));
}

void __Fast_String_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_String_construct(
        *(Fast_String*)args);
}

void __Fast_String_getValue(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_word*)result = Fast_String_getValue(
        *(Fast_String*)args);
}

void __Fast_String_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_String_init(
        *(Fast_String*)args);
}

void __Fast_String_serialize(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_String_serialize(
        *(Fast_String*)args,
        *(db_type*)((intptr_t)args + sizeof(Fast_String)),
        *(db_word*)((intptr_t)args + sizeof(Fast_String) + sizeof(db_type)));
}

/* virtual ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_String_toIc(Fast_String _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_String_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_String_toIc_v(
        *(Fast_String*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_String)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_String) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_String) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Template_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Template_construct(
        *(Fast_Template*)args);
}

void __Fast_TernaryExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_TernaryExpr_construct(
        *(Fast_TernaryExpr*)args);
}

/* virtual ::hyve::Fast::TernaryExpr::hasSideEffects() */
db_bool Fast_TernaryExpr_hasSideEffects(Fast_TernaryExpr _this) {
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_TernaryExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_TernaryExpr_hasSideEffects_v(
        *(Fast_TernaryExpr*)args);
}

void __Fast_TernaryExpr_setOperator(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    Fast_TernaryExpr_setOperator(
        *(Fast_TernaryExpr*)args,
        *(db_operatorKind*)((intptr_t)args + sizeof(Fast_TernaryExpr)));
}

/* virtual ::hyve::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_TernaryExpr_toIc(Fast_TernaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_TernaryExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_TernaryExpr_toIc_v(
        *(Fast_TernaryExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_TernaryExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_TernaryExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_TernaryExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_UnaryExpr_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_UnaryExpr_construct(
        *(Fast_UnaryExpr*)args);
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

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_UnaryExpr_hasSideEffects_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = Fast_UnaryExpr_hasSideEffects_v(
        *(Fast_UnaryExpr*)args);
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_UnaryExpr_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_UnaryExpr_toIc_v(
        *(Fast_UnaryExpr*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_UnaryExpr)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_UnaryExpr) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_UnaryExpr) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Update_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Update_construct(
        *(Fast_Update*)args);
}

/* virtual ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Update_toIc(Fast_Update _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Update_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Update_toIc_v(
        *(Fast_Update*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Update)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Update) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Update) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_Variable_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Variable_construct(
        *(Fast_Variable*)args);
}

void __Fast_Wait_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_Wait_construct(
        *(Fast_Wait*)args);
}

/* virtual ::hyve::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Wait_toIc(Fast_Wait _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Wait_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_Wait_toIc_v(
        *(Fast_Wait*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_Wait)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_Wait) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_Wait) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}

void __Fast_While_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = Fast_While_construct(
        *(Fast_While*)args);
}

/* virtual ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_While_toIc(Fast_While _this, db_icProgram program, db_icStorage storage, db_bool stored) {
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

    db_call(db_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_While_toIc_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_ic*)result = Fast_While_toIc_v(
        *(Fast_While*)args,
        *(db_icProgram*)((intptr_t)args + sizeof(Fast_While)),
        *(db_icStorage*)((intptr_t)args + sizeof(Fast_While) + sizeof(db_icProgram)),
        *(db_bool*)((intptr_t)args + sizeof(Fast_While) + sizeof(db_icProgram) + sizeof(db_icStorage)));
}
