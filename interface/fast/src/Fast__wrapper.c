/* Fast__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::Fast.
 */

#include "Fast.h"
#include "Fast__meta.h"

void __Fast_report(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_report(
        *(cx_string*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_string)),
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_string)),
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_string) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32) + sizeof(cx_string)));
}

void __Fast_reportError(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_reportError(
        *(cx_string*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string)),
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32) + sizeof(cx_string)));
}

void __Fast_reportWarning(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_reportWarning(
        *(cx_string*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string)),
        *(cx_uint32*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32)),
        *(cx_string*)((intptr_t)args + sizeof(cx_string) + sizeof(cx_uint32) + sizeof(cx_uint32) + sizeof(cx_string)));
}

void __Fast_valueKindFromType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_valueKind*)result = Fast_valueKindFromType(
        *(cx_type*)args);
}

void __Fast_BinaryExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_BinaryExpr_construct(
        *(void**)args);
}

void __Fast_BinaryExpr_fold(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Expression*)result = Fast_BinaryExpr_fold(
        *(void**)args);
}

/* virtual ::cortex::Fast::BinaryExpr::hasSideEffects() */
cx_bool Fast_BinaryExpr_hasSideEffects(Fast_BinaryExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_BinaryExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_BinaryExpr_hasSideEffects_v(
        *(void**)args);
}

void __Fast_BinaryExpr_setOperator(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_BinaryExpr_setOperator(
        *(void**)args,
        *(cx_operatorKind*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::BinaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_BinaryExpr_toIc(Fast_BinaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_BinaryExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_BinaryExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Block_addStatement(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Block_addStatement(
        *(void**)args,
        *(Fast_Node*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_declare(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_declare(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(Fast_Variable*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Variable)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Variable) + sizeof(cx_bool)));
}

void __Fast_Block_declareReturnVariable(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_declareReturnVariable(
        *(void**)args,
        *(cx_function*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_declareTemplate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Template*)result = Fast_Block_declareTemplate(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(Fast_Variable*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Variable)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Variable) + sizeof(cx_bool)));
}

void __Fast_Block_lookup(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Block_lookup(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_lookupLocal(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_lookupLocal(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_resolve(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Block_resolve(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_resolveLocal(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Local*)result = Fast_Block_resolveLocal(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Block_setFunction(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Block_setFunction(
        *(void**)args,
        *(cx_function*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIc(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Block_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Block_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

/* virtual ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Block_toIcBody(Fast_Block _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Block_toIcBody_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Block_toIcBody_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Boolean_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Boolean_init(
        *(void**)args);
}

void __Fast_Boolean_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Boolean_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Boolean::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Boolean_toIc(Fast_Boolean _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Boolean_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Boolean_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Call_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Call_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects(Fast_Call _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Call_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_Call_hasSideEffects_v(
        *(void**)args);
}

void __Fast_Call_setParameters(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Call_setParameters(
        *(void**)args,
        *(cx_function*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Call_toIc(Fast_Call _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Call_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Call_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_CallBuilder_build(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Call*)result = Fast_CallBuilder_build(
        *(void**)args);
}

void __Fast_CallBuilder_buildSignature(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_CallBuilder_buildSignature(
        *(void**)args);
}

void __Fast_CastExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_CastExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::CastExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CastExpr_toIc(Fast_CastExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_CastExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_CastExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Character_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Character_init(
        *(void**)args);
}

void __Fast_Character_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Character_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Character_toIc(Fast_Character _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Character_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Character_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_CommaExpr_addExpression(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_CommaExpr_addExpression(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_CommaExpr_addOrCreate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_CommaExpr_addOrCreate(
        *(Fast_Expression*)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(Fast_Expression)));
}

void __Fast_CommaExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_CommaExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::CommaExpr::hasSideEffects() */
cx_bool Fast_CommaExpr_hasSideEffects(Fast_CommaExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_CommaExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_CommaExpr_hasSideEffects_v(
        *(void**)args);
}

void __Fast_CommaExpr_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_CommaExpr_init(
        *(void**)args);
}

/* virtual ::cortex::Fast::CommaExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CommaExpr_toIc(Fast_CommaExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_CommaExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_CommaExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_CommaExpr_toList(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Node_list*)result = Fast_CommaExpr_toList(
        *(void**)args);
}

void __Fast_Define_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Define_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::Define::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Define_toIc(Fast_Define _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Define_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Define_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_DelegateCall_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_DelegateCall_construct(
        *(void**)args);
}

void __Fast_DynamicInitializer_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_DynamicInitializer_construct(
        *(void**)args);
}

void __Fast_DynamicInitializer_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_DynamicInitializer_define(
        *(void**)args);
}

void __Fast_DynamicInitializer_pop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_DynamicInitializer_pop(
        *(void**)args);
}

void __Fast_DynamicInitializer_push(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_DynamicInitializer_push(
        *(void**)args);
}

void __Fast_DynamicInitializer_value(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_DynamicInitializer_value(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_ElementExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_ElementExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::ElementExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_ElementExpr_toIc(Fast_ElementExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_ElementExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_ElementExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Expression_cast(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Expression_cast(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

void __Fast_Expression_cleanList(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Expression_cleanList(
        *(Fast_Expression_list*)args);
}

/* virtual ::cortex::Fast::Expression::fold() */
Fast_Expression Fast_Expression_fold(Fast_Expression _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    Fast_Expression _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "fold()");
    }
    cx_assert(_methodId, "virtual method 'fold()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::fold()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_fold_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Expression*)result = Fast_Expression_fold_v(
        *(void**)args);
}

void __Fast_Expression_fromList(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Expression_fromList(
        *(Fast_Expression_list*)args);
}

void __Fast_Expression_getType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = Fast_Expression_getType(
        *(void**)args);
}

void __Fast_Expression_getType_expr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_type*)result = Fast_Expression_getType_expr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Expression_getType_type(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_type*)result = Fast_Expression_getType_type(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::Expression::getValue() */
cx_word Fast_Expression_getValue(Fast_Expression _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_word _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "getValue()");
    }
    cx_assert(_methodId, "virtual method 'getValue()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::getValue()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_getValue_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_word*)result = Fast_Expression_getValue_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::Expression::hasSideEffects() */
cx_bool Fast_Expression_hasSideEffects(Fast_Expression _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_Expression_hasSideEffects_v(
        *(void**)args);
}

void __Fast_Expression_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Expression_init(
        *(void**)args);
}

/* virtual ::cortex::Fast::Expression::serialize(type dstType,word dst) */
cx_int16 Fast_Expression_serialize(Fast_Expression _this, cx_type dstType, cx_word dst) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "serialize(type dstType,word dst)");
    }
    cx_assert(_methodId, "virtual method 'serialize(type dstType,word dst)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::serialize(type dstType,word dst)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, dstType, dst);
    
    return _result;
}

void __Fast_Expression_serialize_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Expression_serialize_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Expression::toList() */
Fast_Expression_list Fast_Expression_toList(Fast_Expression _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    Fast_Expression_list _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toList()");
    }
    cx_assert(_methodId, "virtual method 'toList()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toList()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Expression_toList_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Expression_list*)result = Fast_Expression_toList_v(
        *(void**)args);
}

void __Fast_FloatingPoint_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_FloatingPoint_init(
        *(void**)args);
}

void __Fast_FloatingPoint_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_FloatingPoint_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_FloatingPoint_toIc(Fast_FloatingPoint _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_FloatingPoint_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_FloatingPoint_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_If_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_If_construct(
        *(void**)args);
}

void __Fast_If_noWarnUnreachable(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_If_noWarnUnreachable(
        *(void**)args);
}

/* virtual ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_If_toIc(Fast_If _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_If_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_If_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Initializer_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_construct(
        *(void**)args);
}

void __Fast_Initializer_currentType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = Fast_Initializer_currentType(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::define() */
cx_int16 Fast_Initializer_define(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "define()");
    }
    cx_assert(_methodId, "virtual method 'define()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::define()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_define_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_define_v(
        *(void**)args);
}

void __Fast_Initializer_initFrame(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint16*)result = Fast_Initializer_initFrame(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::member(string name) */
cx_int32 Fast_Initializer_member(Fast_Initializer _this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int32 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "member(string name)");
    }
    cx_assert(_methodId, "virtual method 'member(string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::member(string name)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, name);
    
    return _result;
}

void __Fast_Initializer_member_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int32*)result = Fast_Initializer_member_v(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::Initializer::next() */
cx_int16 Fast_Initializer_next(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "next()");
    }
    cx_assert(_methodId, "virtual method 'next()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::next()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_next_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_next_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::pop() */
cx_int8 Fast_Initializer_pop(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int8 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "pop()");
    }
    cx_assert(_methodId, "virtual method 'pop()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::pop()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_pop_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int8*)result = Fast_Initializer_pop_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::popKey() */
cx_int16 Fast_Initializer_popKey(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "popKey()");
    }
    cx_assert(_methodId, "virtual method 'popKey()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::popKey()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_popKey_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_popKey_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::push() */
cx_int16 Fast_Initializer_push(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "push()");
    }
    cx_assert(_methodId, "virtual method 'push()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::push()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_push_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_push_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::pushKey() */
cx_int16 Fast_Initializer_pushKey(Fast_Initializer _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "pushKey()");
    }
    cx_assert(_methodId, "virtual method 'pushKey()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::pushKey()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Initializer_pushKey_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Initializer_pushKey_v(
        *(void**)args);
}

void __Fast_Initializer_type(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = Fast_Initializer_type(
        *(void**)args);
}

/* virtual ::cortex::Fast::Initializer::value(Expression v) */
cx_int16 Fast_Initializer_value(Fast_Initializer _this, Fast_Expression v) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "value(Expression v)");
    }
    cx_assert(_methodId, "virtual method 'value(Expression v)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::value(Expression v)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, v);
    
    return _result;
}

void __Fast_Initializer_value_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Initializer_value_v(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::Initializer::valueKey(Expression key) */
cx_int16 Fast_Initializer_valueKey(Fast_Initializer _this, Fast_Expression key) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "valueKey(Expression key)");
    }
    cx_assert(_methodId, "virtual method 'valueKey(Expression key)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::valueKey(Expression key)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, key);
    
    return _result;
}

void __Fast_Initializer_valueKey_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Initializer_valueKey_v(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_InitializerExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_InitializerExpr_construct(
        *(void**)args);
}

void __Fast_InitializerExpr_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_InitializerExpr_define(
        *(void**)args);
}

void __Fast_InitializerExpr_insert(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_InitializerExpr_insert(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_InitializerExpr_member(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int32*)result = Fast_InitializerExpr_member(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_InitializerExpr_pop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_InitializerExpr_pop(
        *(void**)args);
}

void __Fast_InitializerExpr_push(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_InitializerExpr_push(
        *(void**)args);
}

void __Fast_InitializerExpr_value(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_InitializerExpr_value(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Integer_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Integer_init(
        *(void**)args);
}

void __Fast_Integer_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Integer_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Integer_toIc(Fast_Integer _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Integer_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Integer_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

/* virtual ::cortex::Fast::Literal::getValue() */
cx_word Fast_Literal_getValue(Fast_Literal _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_word _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "getValue()");
    }
    cx_assert(_methodId, "virtual method 'getValue()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::getValue()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_Literal_getValue_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_word*)result = Fast_Literal_getValue_v(
        *(void**)args);
}

void __Fast_Literal_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Literal_init(
        *(void**)args);
}

void __Fast_Local_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Local_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Local_toIc(Fast_Local _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Local_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Local_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_MemberExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_MemberExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::MemberExpr::hasSideEffects() */
cx_bool Fast_MemberExpr_hasSideEffects(Fast_MemberExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_MemberExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_MemberExpr_hasSideEffects_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::MemberExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_MemberExpr_toIc(Fast_MemberExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_MemberExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_MemberExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_NewExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_NewExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::NewExpr::hasSideEffects() */
cx_bool Fast_NewExpr_hasSideEffects(Fast_NewExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_NewExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_NewExpr_hasSideEffects_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::NewExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_NewExpr_toIc(Fast_NewExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_NewExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_NewExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Node_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Node_init(
        *(void**)args);
}

/* virtual ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Node_toIc(Fast_Node _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Node_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Node_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Null_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Null_init(
        *(void**)args);
}

void __Fast_Null_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Null_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Null::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Null_toIc(Fast_Null _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Null_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Null_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Object_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Object_construct(
        *(void**)args);
}

void __Fast_Object_getValue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_word*)result = Fast_Object_getValue(
        *(void**)args);
}

void __Fast_Object_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Object_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Object_toIc(Fast_Object _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Object_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Object_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_ObjectBase_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_ObjectBase_construct(
        *(void**)args);
}

void __Fast_Parser_addStatement(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_addStatement(
        *(void**)args,
        *(Fast_Node*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_argumentToString(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_string*)result = Fast_Parser_argumentToString(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable) + sizeof(cx_string)));
}

void __Fast_Parser_binaryExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_binaryExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)),
        *(cx_operatorKind*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression) + sizeof(Fast_Expression)));
}

void __Fast_Parser_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_bind(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable)));
}

void __Fast_Parser_bindOneliner(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_bindOneliner(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable) + sizeof(Fast_Block)));
}

void __Fast_Parser_blockPop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_blockPop(
        *(void**)args);
}

void __Fast_Parser_blockPush(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Block*)result = Fast_Parser_blockPush(
        *(void**)args,
        *(cx_bool*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_callExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_callExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_castExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_castExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_collect(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_collect(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_collectHeap(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_collectHeap(
        *(void**)args,
        *(cx_word*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_construct(
        *(void**)args);
}

void __Fast_Parser_declaration(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_declaration(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable) + sizeof(cx_string)));
}

void __Fast_Parser_declareFunction(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_declareFunction(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable)),
        *(cx_type*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable) + sizeof(cx_string)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Variable) + sizeof(cx_string) + sizeof(cx_type)));
}

void __Fast_Parser_declareFunctionParams(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Block*)result = Fast_Parser_declareFunctionParams(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_define(
        *(void**)args);
}

void __Fast_Parser_defineScope(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_defineScope(
        *(void**)args);
}

void __Fast_Parser_defineVariable(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_defineVariable(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_destruct(
        *(void**)args);
}

void __Fast_Parser_elementExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_elementExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_foreach(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_foreach(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)));
}

void __Fast_Parser_getComplexType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = Fast_Parser_getComplexType(
        *(void**)args);
}

void __Fast_Parser_getLvalue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_getLvalue(
        *(void**)args,
        *(cx_bool*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_getLvalueType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_type*)result = Fast_Parser_getLvalueType(
        *(void**)args,
        *(cx_bool*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_ifStatement(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_ifStatement(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)),
        *(Fast_If*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression) + sizeof(Fast_Block)));
}

void __Fast_Parser_initDeclareStaged(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_initDeclareStaged(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_initKeyValuePop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_initKeyValuePop(
        *(void**)args);
}

void __Fast_Parser_initKeyValuePush(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_initKeyValuePush(
        *(void**)args);
}

void __Fast_Parser_initKeyValueSet(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_initKeyValueSet(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_initMember(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_initMember(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_initPop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_initPop(
        *(void**)args);
}

void __Fast_Parser_initPush(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_initPush(
        *(void**)args);
}

void __Fast_Parser_initPushExpression(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Expression*)result = Fast_Parser_initPushExpression(
        *(void**)args);
}

void __Fast_Parser_initPushIdentifier(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_initPushIdentifier(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_initPushStatic(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Parser_initPushStatic(
        *(void**)args);
}

void __Fast_Parser_initStage(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_initStage(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)));
}

void __Fast_Parser_initValue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_initValue(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_isAbortSet(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_Parser_isAbortSet(
        *(void**)args);
}

void __Fast_Parser_isErrSet(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_Parser_isErrSet(
        *(void**)args);
}

void __Fast_Parser_lookup(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_lookup(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)));
}

void __Fast_Parser_memberExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_memberExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_observerDeclaration(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Variable*)result = Fast_Parser_observerDeclaration(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)),
        *(cx_eventMask*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Expression)),
        *(Fast_Object*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Expression) + sizeof(cx_eventMask)));
}

void __Fast_Parser_observerPop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_observerPop(
        *(void**)args);
}

void __Fast_Parser_observerPush(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_observerPush(
        *(void**)args);
}

void __Fast_Parser_parse(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = Fast_Parser_parse(
        *(void**)args);
}

void __Fast_Parser_parseExpression(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_parseExpression(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(cx_string)),
        *(Fast_Variable*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Block)),
        *(cx_uint32*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Block) + sizeof(Fast_Variable)),
        *(cx_uint32*)((intptr_t)args + sizeof(void*) + sizeof(cx_string) + sizeof(Fast_Block) + sizeof(Fast_Variable) + sizeof(cx_uint32)));
}

void __Fast_Parser_parseLine(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_Parser_parseLine(
        *(cx_string*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_string)),
        *(cx_value**)((intptr_t)args + sizeof(cx_string) + sizeof(cx_object)));
}

void __Fast_Parser_popComplexType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_popComplexType(
        *(void**)args);
}

void __Fast_Parser_popLvalue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_popLvalue(
        *(void**)args);
}

void __Fast_Parser_popScope(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_popScope(
        *(void**)args,
        *(Fast_Variable*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_postfixExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_postfixExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(cx_operatorKind*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_pushComplexType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_pushComplexType(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_pushLvalue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_pushLvalue(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_pushReturnAsLvalue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_Parser_pushReturnAsLvalue(
        *(void**)args,
        *(cx_function*)((intptr_t)args + sizeof(void*)));
}

void __Fast_Parser_pushScope(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(Fast_Variable*)result = Fast_Parser_pushScope(
        *(void**)args);
}

void __Fast_Parser_reset(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    Fast_Parser_reset(
        *(void**)args);
}

void __Fast_Parser_ternaryExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_ternaryExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression) + sizeof(Fast_Expression)));
}

void __Fast_Parser_unaryExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_unaryExpr(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(cx_operatorKind*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_updateStatement(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_updateStatement(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)));
}

void __Fast_Parser_waitExpr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Expression*)result = Fast_Parser_waitExpr(
        *(void**)args,
        *(Fast_Expression_list*)((intptr_t)args + sizeof(void*)),
        *(Fast_Expression*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression_list)));
}

void __Fast_Parser_whileStatement(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(Fast_Node*)result = Fast_Parser_whileStatement(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)),
        *(Fast_Block*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(Fast_Expression) + sizeof(Fast_Block)));
}

void __Fast_PostfixExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_PostfixExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::PostfixExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostfixExpr_toIc(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_PostfixExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_PostfixExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_SignedInteger_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_SignedInteger_init(
        *(void**)args);
}

void __Fast_SignedInteger_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_SignedInteger_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_SignedInteger_toIc(Fast_SignedInteger _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_SignedInteger_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_SignedInteger_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_StaticCall_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_StaticCall_construct(
        *(void**)args);
}

void __Fast_StaticInitializer_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_StaticInitializer_construct(
        *(void**)args);
}

void __Fast_StaticInitializer_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_StaticInitializer_define(
        *(void**)args);
}

void __Fast_StaticInitializer_push(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_StaticInitializer_push(
        *(void**)args);
}

void __Fast_StaticInitializer_value(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_StaticInitializer_value(
        *(void**)args,
        *(Fast_Expression*)((intptr_t)args + sizeof(void*)));
}

void __Fast_String_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_String_construct(
        *(void**)args);
}

void __Fast_String_getValue(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_word*)result = Fast_String_getValue(
        *(void**)args);
}

void __Fast_String_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_String_init(
        *(void**)args);
}

void __Fast_String_serialize(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = Fast_String_serialize(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)),
        *(cx_word*)((intptr_t)args + sizeof(void*) + sizeof(cx_type)));
}

/* virtual ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_String_toIc(Fast_String _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_String_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_String_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Template_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Template_construct(
        *(void**)args);
}

void __Fast_TernaryExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_TernaryExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::TernaryExpr::hasSideEffects() */
cx_bool Fast_TernaryExpr_hasSideEffects(Fast_TernaryExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_TernaryExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_TernaryExpr_hasSideEffects_v(
        *(void**)args);
}

void __Fast_TernaryExpr_setOperator(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    Fast_TernaryExpr_setOperator(
        *(void**)args,
        *(cx_operatorKind*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::Fast::TernaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_TernaryExpr_toIc(Fast_TernaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_TernaryExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_TernaryExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_UnaryExpr_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_UnaryExpr_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::UnaryExpr::hasSideEffects() */
cx_bool Fast_UnaryExpr_hasSideEffects(Fast_UnaryExpr _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    cx_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __Fast_UnaryExpr_hasSideEffects_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = Fast_UnaryExpr_hasSideEffects_v(
        *(void**)args);
}

/* virtual ::cortex::Fast::UnaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_UnaryExpr_toIc(Fast_UnaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_UnaryExpr_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_UnaryExpr_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Update_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Update_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Update_toIc(Fast_Update _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Update_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Update_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_Variable_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Variable_construct(
        *(void**)args);
}

void __Fast_Wait_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_Wait_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::Wait::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Wait_toIc(Fast_Wait _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_Wait_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_Wait_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}

void __Fast_While_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = Fast_While_construct(
        *(void**)args);
}

/* virtual ::cortex::Fast::While::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_While_toIc(Fast_While _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_ic _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)");
    }
    cx_assert(_methodId, "virtual method 'toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, program, storage, stored);
    
    return _result;
}

void __Fast_While_toIc_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_ic*)result = Fast_While_toIc_v(
        *(void**)args,
        *(cx_icProgram*)((intptr_t)args + sizeof(void*)),
        *(cx_icStorage*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram)),
        *(cx_bool*)((intptr_t)args + sizeof(void*) + sizeof(cx_icProgram) + sizeof(cx_icStorage)));
}
