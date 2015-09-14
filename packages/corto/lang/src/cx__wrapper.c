/* cx__wrapper.c
 *
 * This file contains wrapper functions for ::corto::lang.
 */

#define corto_lang_LIB
#include "cx.h"
#include "cx__meta.h"

void __cx_alias_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_alias_construct(
        cx_alias(*(void**)args));
}

void __cx_alias_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_alias_init(
        cx_alias(*(void**)args));
}

void __cx_array_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_array_construct(
        cx_array(*(void**)args));
}

void __cx_array_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_array_destruct(
        cx_array(*(void**)args));
}

void __cx_array_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_array_init(
        cx_array(*(void**)args));
}

void __cx_binary_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_binary_init(
        cx_binary(*(void**)args));
}

void __cx_bitmask_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_bitmask_init(
        cx_bitmask(*(void**)args));
}

void __cx_boolean_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_boolean_init(
        cx_boolean(*(void**)args));
}

void __cx_character_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_character_init(
        cx_character(*(void**)args));
}

/* virtual ::corto::lang::class::allocSize() */
cx_uint32 cx_class_allocSize(cx_class this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_uint32 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "allocSize()");
    }
    cx_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this);
    
    return _result;
}

void __cx_class_allocSize_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = _cx_class_allocSize_v(
        cx_class(*(void**)args));
}

void __cx_class_bindObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_class_bindObserver(
        cx_class(*(void**)args),
        cx_observer(*(cx_observer*)((intptr_t)args + sizeof(void*))));
}

void __cx_class_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_class_construct(
        cx_class(*(void**)args));
}

void __cx_class_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_class_destruct(
        cx_class(*(void**)args));
}

void __cx_class_findObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = _cx_class_findObserver(
        cx_class(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_class_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_class_init(
        cx_class(*(void**)args));
}

void __cx_class_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_class_instanceof(
        cx_class(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_class_privateObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = _cx_class_privateObserver(
        cx_class(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)),
        cx_observer(*(cx_observer*)((intptr_t)args + sizeof(void*) + sizeof(cx_object))));
}

void __cx_class_resolveInterfaceMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = _cx_class_resolveInterfaceMethod(
        cx_class(*(void**)args),
        cx_interface(*(cx_interface*)((intptr_t)args + sizeof(void*))),
        *(cx_uint32*)((intptr_t)args + sizeof(void*) + sizeof(cx_interface)));
}

/* virtual ::corto::lang::collection::castable(type type) */
cx_bool cx_collection_castable(cx_collection this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_collection_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_collection_castable_v(
        cx_collection(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::collection::compatible(type type) */
cx_bool cx_collection_compatible(cx_collection this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_collection_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_collection_compatible_v(
        cx_collection(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_collection_elementRequiresAlloc(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = _cx_collection_elementRequiresAlloc(
        cx_collection(*(void**)args));
}

void __cx_collection_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_collection_init(
        cx_collection(*(void**)args));
}

void __cx_collection_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = _cx_collection_size(
        *(cx_any*)args);
}

void __cx_constant_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_constant_init(
        cx_constant(*(void**)args));
}

void __cx_delegate_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_delegate_bind(
        cx_function(*(cx_function*)args));
}

/* virtual ::corto::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable(cx_delegate this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_delegate_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_delegate_castable_v(
        cx_delegate(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible(cx_delegate this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_delegate_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_delegate_compatible_v(
        cx_delegate(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_delegate_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_delegate_init(
        cx_delegate(*(void**)args));
}

void __cx_delegate_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_delegate_instanceof(
        cx_delegate(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::corto::lang::dispatcher::post(event e) */
void cx_dispatcher_post(cx_dispatcher this, cx_event e) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "post(event e)");
    }
    cx_assert(_methodId, "virtual method 'post(event e)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::post(event e)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), NULL, this, e);
}

void __cx_dispatcher_post_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_dispatcher_post_v(
        cx_dispatcher(*(void**)args),
        cx_event(*(cx_event*)((intptr_t)args + sizeof(void*))));
}

void __cx_enum_constant(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = _cx_enum_constant(
        cx_enum(*(void**)args),
        *(cx_int32*)((intptr_t)args + sizeof(void*)));
}

void __cx_enum_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_enum_construct(
        cx_enum(*(void**)args));
}

void __cx_enum_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_enum_destruct(
        cx_enum(*(void**)args));
}

void __cx_enum_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_enum_init(
        cx_enum(*(void**)args));
}

/* virtual ::corto::lang::event::handle() */
void cx_event_handle(cx_event this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "handle()");
    }
    cx_assert(_methodId, "virtual method 'handle()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::handle()@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), NULL, this);
}

void __cx_event_handle_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_event_handle_v(
        cx_event(*(void**)args));
}

void __cx_event_uniqueKind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_event_uniqueKind(
        );
}

void __cx_float_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_float_init(
        cx_float(*(void**)args));
}

void __cx_function_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_function_bind(
        cx_function(*(void**)args));
}

void __cx_function_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_function_init(
        cx_function(*(void**)args));
}

void __cx_function_stringToParameterSeq(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_parameterseq*)result = _cx_function_stringToParameterSeq(
        *(cx_string*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_string)));
}

void __cx_function_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_function_unbind(
        cx_function(*(cx_function*)args));
}

void __cx_int_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_int_init(
        cx_int(*(void**)args));
}

void __cx_interface_baseof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_interface_baseof(
        cx_interface(*(void**)args),
        cx_interface(*(cx_interface*)((intptr_t)args + sizeof(void*))));
}

void __cx_interface_bindMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_interface_bindMethod(
        cx_interface(*(void**)args),
        cx_method(*(cx_method*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::interface::compatible(type type) */
cx_bool cx_interface_compatible(cx_interface this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_interface_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_interface_compatible_v(
        cx_interface(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_interface_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_interface_construct(
        cx_interface(*(void**)args));
}

void __cx_interface_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_interface_destruct(
        cx_interface(*(void**)args));
}

void __cx_interface_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_interface_init(
        cx_interface(*(void**)args));
}

/* virtual ::corto::lang::interface::resolveMember(string name) */
cx_member cx_interface_resolveMember(cx_interface this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, name);
    
    return _result;
}

void __cx_interface_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = _cx_interface_resolveMember_v(
        cx_interface(*(void**)args),
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = _cx_interface_resolveMethod(
        cx_interface(*(void**)args),
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethodById(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = _cx_interface_resolveMethodById(
        cx_interface(*(void**)args),
        *(cx_uint32*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethodId(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint32*)result = _cx_interface_resolveMethodId(
        cx_interface(*(void**)args),
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::corto::lang::iterator::castable(type type) */
cx_bool cx_iterator_castable(cx_iterator this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_iterator_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_iterator_castable_v(
        cx_iterator(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::iterator::compatible(type type) */
cx_bool cx_iterator_compatible(cx_iterator this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_iterator_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_iterator_compatible_v(
        cx_iterator(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_iterator_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_iterator_init(
        cx_iterator(*(void**)args));
}

void __cx_list_append_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = _cx_list_append_(
        *(cx_any*)args);
}

void __cx_list_append_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_list_append_any(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_list_clear(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_list_clear(
        *(cx_any*)args);
}

void __cx_list_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_list_construct(
        cx_list(*(void**)args));
}

void __cx_list_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_list_init(
        cx_list(*(void**)args));
}

void __cx_list_insert_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = _cx_list_insert_(
        *(cx_any*)args);
}

void __cx_list_insert_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_list_insert_any(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_list_reverse(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_list_reverse(
        *(cx_any*)args);
}

void __cx_map_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_map_construct(
        cx_map(*(void**)args));
}

void __cx_map_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_map_init(
        cx_map(*(void**)args));
}

void __cx_member_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_member_construct(
        cx_member(*(void**)args));
}

void __cx_member_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_member_init(
        cx_member(*(void**)args));
}

void __cx_metaprocedure_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_metaprocedure_bind(
        cx_metaprocedure(*(void**)args));
}

void __cx_method_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_method_bind(
        cx_method(*(void**)args));
}

void __cx_method_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_method_init(
        cx_method(*(void**)args));
}

/* virtual ::corto::lang::observableEvent::handle() */
void cx_observableEvent_handle(cx_observableEvent this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "handle()");
    }
    cx_assert(_methodId, "virtual method 'handle()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::handle()@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), NULL, this);
}

void __cx_observableEvent_handle_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_observableEvent_handle_v(
        cx_observableEvent(*(void**)args));
}

void __cx_observer_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_observer_bind(
        cx_observer(*(void**)args));
}

void __cx_observer_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_observer_init(
        cx_observer(*(void**)args));
}

void __cx_observer_listen(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_observer_listen(
        cx_observer(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_object)));
}

void __cx_observer_setDispatcher(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_observer_setDispatcher(
        cx_observer(*(void**)args),
        cx_dispatcher(*(cx_dispatcher*)((intptr_t)args + sizeof(void*))));
}

void __cx_observer_silence(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_observer_silence(
        cx_observer(*(void**)args),
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_observer_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_observer_unbind(
        cx_observer(*(cx_observer*)args));
}

/* virtual ::corto::lang::primitive::castable(type type) */
cx_bool cx_primitive_castable(cx_primitive this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_primitive_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_primitive_castable_v(
        cx_primitive(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::primitive::compatible(type type) */
cx_bool cx_primitive_compatible(cx_primitive this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_primitive_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_primitive_compatible_v(
        cx_primitive(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_primitive_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_primitive_construct(
        cx_primitive(*(void**)args));
}

void __cx_primitive_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_primitive_init(
        cx_primitive(*(void**)args));
}

void __cx_procedure_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_procedure_init(
        cx_procedure(*(void**)args));
}

void __cx_procedure_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_procedure_unbind(
        cx_procedure(*(void**)args),
        cx_function(*(cx_function*)((intptr_t)args + sizeof(void*))));
}

void __cx_sequence_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_sequence_construct(
        cx_sequence(*(void**)args));
}

void __cx_sequence_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_sequence_init(
        cx_sequence(*(void**)args));
}

void __cx_sequence_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    _cx_sequence_size(
        *(cx_any*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_any)));
}

/* virtual ::corto::lang::struct::castable(type type) */
cx_bool cx_struct_castable(cx_struct this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_struct_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_struct_castable_v(
        cx_struct(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

/* virtual ::corto::lang::struct::compatible(type type) */
cx_bool cx_struct_compatible(cx_struct this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_struct_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_struct_compatible_v(
        cx_struct(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_struct_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_struct_construct(
        cx_struct(*(void**)args));
}

void __cx_struct_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_struct_init(
        cx_struct(*(void**)args));
}

/* virtual ::corto::lang::struct::resolveMember(string name) */
cx_member cx_struct_resolveMember(cx_struct this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, name);
    
    return _result;
}

void __cx_struct_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = _cx_struct_resolveMember_v(
        cx_struct(*(void**)args),
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_text_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_text_init(
        cx_text(*(void**)args));
}

void __cx_type_alignmentof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint16*)result = _cx_type_alignmentof(
        cx_type(*(void**)args));
}

/* virtual ::corto::lang::type::allocSize() */
cx_uint32 cx_type_allocSize(cx_type this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_uint32 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "allocSize()");
    }
    cx_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this);
    
    return _result;
}

void __cx_type_allocSize_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = _cx_type_allocSize_v(
        cx_type(*(void**)args));
}

/* virtual ::corto::lang::type::castable(type type) */
cx_bool cx_type_castable(cx_type this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_type_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_type_castable_v(
        cx_type(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_type_checkAttr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_type_checkAttr(
        *(cx_any*)args,
        *(cx_attr*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_checkState(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_type_checkState(
        *(cx_any*)args,
        *(cx_state*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_compare(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_equalityKind*)result = _cx_type_compare(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

/* virtual ::corto::lang::type::compatible(type type) */
cx_bool cx_type_compatible(cx_type this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(this), _methodId);

    cx_call(cx_function(_method), &_result, this, type);
    
    return _result;
}

void __cx_type_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_type_compatible_v(
        cx_type(*(void**)args),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(void*))));
}

void __cx_type_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_type_construct(
        cx_type(*(void**)args));
}

void __cx_type_copy(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = _cx_type_copy(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_declare(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = _cx_type_declare(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)),
        cx_type(*(cx_type*)((intptr_t)args + sizeof(cx_any) + sizeof(cx_string))));
}

void __cx_type_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_type_define(
        *(cx_any*)args);
}

void __cx_type_delete(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_type_delete(
        *(cx_any*)args);
}

void __cx_type_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_type_destruct(
        cx_type(*(void**)args));
}

void __cx_type_fullname(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = _cx_type_fullname(
        *(cx_any*)args);
}

void __cx_type_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_type_init(
        cx_type(*(void**)args));
}

void __cx_type_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = _cx_type_instanceof(
        *(cx_any*)args,
        cx_type(*(cx_type*)((intptr_t)args + sizeof(cx_any))));
}

void __cx_type_invalidate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    _cx_type_invalidate(
        *(cx_any*)args);
}

void __cx_type_lookup(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = _cx_type_lookup(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_nameof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = _cx_type_nameof(
        *(cx_any*)args);
}

void __cx_type_parentof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_object*)result = _cx_type_parentof(
        *(cx_any*)args);
}

void __cx_type_relname(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_string*)result = _cx_type_relname(
        *(cx_any*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_resolve(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = _cx_type_resolve(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_resolveProcedure(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_function*)result = _cx_type_resolveProcedure(
        cx_type(*(void**)args),
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_type_sizeof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = _cx_type_sizeof(
        cx_type(*(void**)args));
}

void __cx_type_toString(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = _cx_type_toString(
        *(cx_any*)args);
}

void __cx_type_typeof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = _cx_type_typeof(
        *(cx_any*)args);
}

void __cx_uint_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_uint_init(
        cx_uint(*(void**)args));
}

void __cx_virtual_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = _cx_virtual_init(
        cx_virtual(*(void**)args));
}
