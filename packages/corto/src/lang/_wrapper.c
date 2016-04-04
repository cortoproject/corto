/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/lang.
 */

#include "corto/lang/lang.h"
#include "corto/lang/_meta.h"

void __corto_destructAction(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    corto_void ___ (*_fptr)(corto_object) = (corto_void ___ (*)(corto_object))f->implData;
    CORTO_UNUSED(result);
    _fptr(
        *(void**)args);
}

void __corto_initAction(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    corto_int16 ___ (*_fptr)(corto_object) = (corto_int16 ___ (*)(corto_object))f->implData;
    *(corto_int16*)result = _fptr(
        *(void**)args);
}

void __corto_nameAction(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    corto_string ___ (*_fptr)(corto_object) = (corto_string ___ (*)(corto_object))f->implData;
    *(corto_string*)result = _fptr(
        *(void**)args);
}

void __corto_alias_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_alias_construct(
        corto_alias(*(void**)args));
}

void __corto_alias_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_alias_init(
        corto_alias(*(void**)args));
}

void __corto_array_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_array_construct(
        corto_array(*(void**)args));
}

void __corto_array_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_array_destruct(
        corto_array(*(void**)args));
}

void __corto_array_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_array_init(
        corto_array(*(void**)args));
}

void __corto_binary_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_binary_init(
        corto_binary(*(void**)args));
}

void __corto_bitmask_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_bitmask_init(
        corto_bitmask(*(void**)args));
}

void __corto_boolean_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_boolean_init(
        corto_boolean(*(void**)args));
}

void __corto_character_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_character_init(
        corto_character(*(void**)args));
}

void __corto_class_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_class_construct(
        corto_class(*(void**)args));
}

void __corto_class_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_class_destruct(
        corto_class(*(void**)args));
}

void __corto_class_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_class_init(
        corto_class(*(void**)args));
}

void __corto_class_instanceof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_class_instanceof(
        corto_class(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void __corto_class_resolveInterfaceMethod(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_method*)result = _corto_class_resolveInterfaceMethod(
        corto_class(*(void**)args),
        corto_interface(*(corto_interface*)((intptr_t)args + sizeof(void*))),
        *(corto_uint32*)((intptr_t)args + sizeof(void*) + sizeof(corto_interface)));
}

corto_bool _corto_collection_castable(
    corto_collection this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_collection_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_collection_castable_v(
        corto_collection(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_collection_compatible(
    corto_collection this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_collection_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_collection_compatible_v(
        corto_collection(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_collection_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_collection_init(
        corto_collection(*(void**)args));
}

void __corto_collection_requiresAlloc(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_collection_requiresAlloc(
        corto_type(*(corto_type*)args));
}

void __corto_collection_size(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_uint32*)result = _corto_collection_size(
        *(corto_any*)args);
}

void __corto_constant_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_constant_init(
        corto_constant(*(void**)args));
}

void __corto_delegate_bind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_delegate_bind(
        corto_function(*(corto_function*)args));
}

corto_bool _corto_delegate_castable(
    corto_delegate this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_delegate_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_delegate_castable_v(
        corto_delegate(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_delegate_compatible(
    corto_delegate this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_delegate_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_delegate_compatible_v(
        corto_delegate(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_delegate_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_delegate_init(
        corto_delegate(*(void**)args));
}

void __corto_delegate_instanceof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_delegate_instanceof(
        corto_delegate(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void __corto_enum_constant(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _corto_enum_constant(
        corto_enum(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)));
}

void __corto_enum_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_enum_construct(
        corto_enum(*(void**)args));
}

void __corto_enum_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_enum_destruct(
        corto_enum(*(void**)args));
}

void __corto_enum_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_enum_init(
        corto_enum(*(void**)args));
}

void __corto_float_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_float_init(
        corto_float(*(void**)args));
}

void __corto_function_bind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_function_bind(
        corto_function(*(void**)args));
}

void __corto_function_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_function_init(
        corto_function(*(void**)args));
}

void __corto_function_parseParamString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_function_parseParamString(
        corto_function(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_function_stringToParameterSeq(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_parameterseq*)result = _corto_function_stringToParameterSeq(
        *(corto_string*)args,
        *(corto_object*)((intptr_t)args + sizeof(corto_string)));
}

void __corto_function_unbind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_function_unbind(
        corto_function(*(corto_function*)args));
}

void __corto_int_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_int_init(
        corto_int(*(void**)args));
}

void __corto_interface_baseof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_interface_baseof(
        corto_interface(*(void**)args),
        corto_interface(*(corto_interface*)((intptr_t)args + sizeof(void*))));
}

void __corto_interface_bindMethod(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_interface_bindMethod(
        corto_interface(*(void**)args),
        corto_method(*(corto_method*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_interface_compatible(
    corto_interface this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_interface_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_interface_compatible_v(
        corto_interface(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_interface_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_interface_construct(
        corto_interface(*(void**)args));
}

void __corto_interface_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_interface_destruct(
        corto_interface(*(void**)args));
}

void __corto_interface_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_interface_init(
        corto_interface(*(void**)args));
}

corto_member _corto_interface_resolveMember(
    corto_interface this,
    corto_string name) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "virtual 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, name);
    
    return _result;
}

void __corto_interface_resolveMember_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_member*)result = _corto_interface_resolveMember_v(
        corto_interface(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_interface_resolveMethod(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_method*)result = _corto_interface_resolveMethod(
        corto_interface(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_interface_resolveMethodById(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_method*)result = _corto_interface_resolveMethodById(
        corto_interface(*(void**)args),
        *(corto_uint32*)((intptr_t)args + sizeof(void*)));
}

void __corto_interface_resolveMethodId(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_uint32*)result = _corto_interface_resolveMethodId(
        corto_interface(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

corto_bool _corto_iterator_castable(
    corto_iterator this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_iterator_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_iterator_castable_v(
        corto_iterator(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_iterator_compatible(
    corto_iterator this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_iterator_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_iterator_compatible_v(
        corto_iterator(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_iterator_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_iterator_init(
        corto_iterator(*(void**)args));
}

void __corto_list_append_(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_any*)result = _corto_list_append_(
        *(corto_any*)args);
}

void __corto_list_append_any(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_list_append_any(
        *(corto_any*)args,
        *(corto_any*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_list_clear(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_list_clear(
        *(corto_any*)args);
}

void __corto_list_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_list_construct(
        corto_list(*(void**)args));
}

void __corto_list_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_list_init(
        corto_list(*(void**)args));
}

void __corto_list_insert_(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_any*)result = _corto_list_insert_(
        *(corto_any*)args);
}

void __corto_list_insert_any(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_list_insert_any(
        *(corto_any*)args,
        *(corto_any*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_list_reverse(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_list_reverse(
        *(corto_any*)args);
}

void __corto_map_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_map_construct(
        corto_map(*(void**)args));
}

void __corto_map_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_map_init(
        corto_map(*(void**)args));
}

void __corto_member_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_member_construct(
        corto_member(*(void**)args));
}

void __corto_member_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_member_init(
        corto_member(*(void**)args));
}

void __corto_metaprocedure_bind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_metaprocedure_bind(
        corto_metaprocedure(*(void**)args));
}

void __corto_method_bind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_method_bind(
        corto_method(*(void**)args));
}

void __corto_method_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_method_init(
        corto_method(*(void**)args));
}

corto_bool _corto_primitive_castable(
    corto_primitive this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_primitive_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_primitive_castable_v(
        corto_primitive(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_primitive_compatible(
    corto_primitive this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_primitive_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_primitive_compatible_v(
        corto_primitive(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_primitive_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_primitive_construct(
        corto_primitive(*(void**)args));
}

void __corto_primitive_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_primitive_init(
        corto_primitive(*(void**)args));
}

void __corto_primitive_isInteger(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_bool*)result = _corto_primitive_isInteger(
        corto_primitive(*(void**)args));
}

void __corto_primitive_isNumber(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_bool*)result = _corto_primitive_isNumber(
        corto_primitive(*(void**)args));
}

void __corto_procedure_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_procedure_init(
        corto_procedure(*(void**)args));
}

void __corto_procedure_unbind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_procedure_unbind(
        corto_procedure(*(void**)args),
        corto_function(*(corto_function*)((intptr_t)args + sizeof(void*))));
}

void __corto_sequence_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_sequence_construct(
        corto_sequence(*(void**)args));
}

void __corto_sequence_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_sequence_init(
        corto_sequence(*(void**)args));
}

void __corto_sequence_size(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_sequence_size(
        *(corto_any*)args,
        *(corto_uint32*)((intptr_t)args + sizeof(corto_any)));
}

corto_bool _corto_struct_castable(
    corto_struct this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_struct_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_struct_castable_v(
        corto_struct(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

corto_bool _corto_struct_compatible(
    corto_struct this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_struct_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_struct_compatible_v(
        corto_struct(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_struct_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_struct_construct(
        corto_struct(*(void**)args));
}

void __corto_struct_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_struct_init(
        corto_struct(*(void**)args));
}

corto_member _corto_struct_resolveMember(
    corto_struct this,
    corto_string name) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "virtual 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, name);
    
    return _result;
}

void __corto_struct_resolveMember_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_member*)result = _corto_struct_resolveMember_v(
        corto_struct(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_text_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_text_init(
        corto_text(*(void**)args));
}

void __corto_type_alignmentof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_uint16*)result = _corto_type_alignmentof(
        corto_type(*(void**)args));
}

corto_bool _corto_type_castable(
    corto_type this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_type_castable_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_type_castable_v(
        corto_type(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_type_checkAttr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_type_checkAttr(
        *(corto_any*)args,
        *(corto_attr*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_checkState(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_type_checkState(
        *(corto_any*)args,
        *(corto_state*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_compare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_equalityKind*)result = _corto_type_compare(
        *(corto_any*)args,
        *(corto_any*)((intptr_t)args + sizeof(corto_any)));
}

corto_bool _corto_type_compatible(
    corto_type this,
    corto_type type) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, type);
    
    return _result;
}

void __corto_type_compatible_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_type_compatible_v(
        corto_type(*(void**)args),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(void*))));
}

void __corto_type_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_type_construct(
        corto_type(*(void**)args));
}

void __corto_type_copy(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_type_copy(
        *(corto_any*)args,
        *(corto_any*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_declare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _corto_type_declare(
        *(corto_any*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_any)),
        corto_type(*(corto_type*)((intptr_t)args + sizeof(corto_any) + sizeof(corto_string))));
}

void __corto_type_define(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_type_define(
        *(corto_any*)args);
}

void __corto_type_delete(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_type_delete(
        *(corto_any*)args);
}

void __corto_type_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_type_destruct(
        corto_type(*(void**)args));
}

void __corto_type_fullpath(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_string*)result = _corto_type_fullpath(
        *(corto_any*)args);
}

void __corto_type_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_type_init(
        corto_type(*(void**)args));
}

void __corto_type_instanceof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _corto_type_instanceof(
        *(corto_any*)args,
        corto_type(*(corto_type*)((intptr_t)args + sizeof(corto_any))));
}

void __corto_type_invalidate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_type_invalidate(
        *(corto_any*)args);
}

void __corto_type_lookup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _corto_type_lookup(
        *(corto_any*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_name(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_string*)result = _corto_type_name(
        *(corto_any*)args);
}

void __corto_type_parent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_object*)result = _corto_type_parent(
        *(corto_any*)args);
}

void __corto_type_path(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_string*)result = _corto_type_path(
        *(corto_any*)args,
        *(corto_object*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_resolve(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _corto_type_resolve(
        *(corto_any*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_any)));
}

void __corto_type_resolveProcedure(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_function*)result = _corto_type_resolveProcedure(
        corto_type(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_type_sizeof(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_uint32*)result = _corto_type_sizeof(
        corto_type(*(void**)args));
}

void __corto_type_str(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_string*)result = _corto_type_str(
        *(corto_any*)args);
}

void __corto_type_type(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_type*)result = _corto_type_type(
        *(corto_any*)args);
}

void __corto_uint_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_uint_init(
        corto_uint(*(void**)args));
}

void __corto_virtual_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_virtual_init(
        corto_virtual(*(void**)args));
}
