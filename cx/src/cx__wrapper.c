/* cx__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::lang.
 */

#include "cx.h"
#include "cx__meta.h"

void __cx_alias_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_alias_init(
        *(cx_alias*)args);
}

void __cx_array_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_array_construct(
        *(cx_array*)args);
}

void __cx_array_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_array_destruct(
        *(cx_array*)args);
}

void __cx_array_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_array_init(
        *(cx_array*)args);
}

void __cx_binary_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_binary_init(
        *(cx_binary*)args);
}

void __cx_bitmask_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_bitmask_init(
        *(cx_bitmask*)args);
}

void __cx_boolean_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_boolean_init(
        *(cx_boolean*)args);
}

void __cx_callback_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_callback_bind(
        *(cx_callback*)args);
}

void __cx_callback_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_callback_init(
        *(cx_callback*)args);
}

void __cx_character_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_character_init(
        *(cx_character*)args);
}

void __cx_class__construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class__construct(
        *(cx_class*)args);
}

void __cx_class__destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_class__destruct(
        *(cx_class*)args);
}

/* virtual ::cortex::lang::class::allocSize() */
cx_uint32 cx_class_allocSize(cx_class _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_uint32 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "allocSize()");
    }
    cx_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __cx_class_allocSize_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_class_allocSize_v(
        *(cx_class*)args);
}

void __cx_class_bindCallback(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class_bindCallback(
        *(cx_class*)args,
        *(cx_delegate*)((intptr_t)args + sizeof(cx_class)),
        *(cx_object*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_delegate)),
        *(cx_callback*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_delegate) + sizeof(cx_object)));
}

void __cx_class_bindDelegate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class_bindDelegate(
        *(cx_class*)args,
        *(cx_delegate*)((intptr_t)args + sizeof(cx_class)));
}

void __cx_class_bindMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class_bindMethod(
        *(cx_class*)args,
        *(cx_method*)((intptr_t)args + sizeof(cx_class)));
}

void __cx_class_bindObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_class_bindObserver(
        *(cx_class*)args,
        *(cx_observer*)((intptr_t)args + sizeof(cx_class)));
}

/* delegate ::cortex::lang::class::construct(lang::object object) */
cx_int16 cx_class_construct(cx_class _this, cx_object object) {
    cx_callback _callback;
    cx_int16 _result;
    /* Lookup callback-object. */
    _callback = cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_class_construct_o, _this);

    cx_assert(_callback != NULL, "no callback 'construct(lang::object object)' for object of type 'cx_class' (call 'cx_class_construct_checkCallback' first)");

    cx_call(cx_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::class::construct(lang::object object), obtain callback */
cx_bool cx_class_construct_hasCallback(cx_class _this) {
    /* Lookup callback-object. */
    return cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_class_construct_o, _this) != NULL;
}

void __cx_class_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class_construct(
        *(cx_class*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_class)));
}

/* delegate ::cortex::lang::class::destruct(lang::object object) */
void cx_class_destruct(cx_class _this, cx_object object) {
    cx_callback _callback;
    /* Lookup callback-object. */
    _callback = cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_class_destruct_o, _this);

    cx_assert(_callback != NULL, "no callback 'destruct(lang::object object)' for object of type 'cx_class' (call 'cx_class_destruct_checkCallback' first)");

    cx_call(cx_function(_callback), NULL, object);
}

/* delegate ::cortex::lang::class::destruct(lang::object object), obtain callback */
cx_bool cx_class_destruct_hasCallback(cx_class _this) {
    /* Lookup callback-object. */
    return cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_class_destruct_o, _this) != NULL;
}

void __cx_class_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_class_destruct(
        *(cx_class*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_class)));
}

void __cx_class_findObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = cx_class_findObserver(
        *(cx_class*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_class)),
        *(cx_string*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_object)));
}

void __cx_class_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_class_init(
        *(cx_class*)args);
}

void __cx_class_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_class_instanceof(
        *(cx_class*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_class)));
}

void __cx_class_privateObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = cx_class_privateObserver(
        *(cx_class*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_class)),
        *(cx_observer*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_object)));
}

void __cx_class_resolveCallback(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_callback*)result = cx_class_resolveCallback(
        *(cx_class*)args,
        *(cx_delegate*)((intptr_t)args + sizeof(cx_class)),
        *(cx_object*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_delegate)));
}

void __cx_class_resolveDelegate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_delegate*)result = cx_class_resolveDelegate(
        *(cx_class*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_class)));
}

void __cx_class_resolveInterfaceMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_class_resolveInterfaceMethod(
        *(cx_class*)args,
        *(cx_interface*)((intptr_t)args + sizeof(cx_class)),
        *(cx_uint32*)((intptr_t)args + sizeof(cx_class) + sizeof(cx_interface)));
}

/* virtual ::cortex::lang::collection::castable(lang::type type) */
cx_bool cx_collection_castable(cx_collection _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_collection_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_collection_castable_v(
        *(cx_collection*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_collection)));
}

void __cx_collection_elementRequiresAlloc(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = cx_collection_elementRequiresAlloc(
        *(cx_collection*)args);
}

void __cx_collection_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_collection_init(
        *(cx_collection*)args);
}

void __cx_collection_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_collection_size(
        *(cx_any*)args);
}

void __cx_constant_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_constant_init(
        *(void**)args);
}

void __cx_delegate_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_delegate_init(
        *(cx_delegate*)args);
}

/* virtual ::cortex::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
cx_observableEvent cx_dispatcher_getEvent(cx_dispatcher _this, cx_observer observer, cx_object me, cx_object observable, cx_object src) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_observableEvent _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)");
    }
    cx_assert(_methodId, "virtual method 'getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, observer, me, observable, src);
    
    return _result;
}

void __cx_dispatcher_getEvent_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observableEvent*)result = cx_dispatcher_getEvent_v(
        *(cx_dispatcher*)args,
        *(cx_observer*)((intptr_t)args + sizeof(cx_dispatcher)),
        *(cx_object*)((intptr_t)args + sizeof(cx_dispatcher) + sizeof(cx_observer)),
        *(cx_object*)((intptr_t)args + sizeof(cx_dispatcher) + sizeof(cx_observer) + sizeof(cx_object)),
        *(cx_object*)((intptr_t)args + sizeof(cx_dispatcher) + sizeof(cx_observer) + sizeof(cx_object) + sizeof(cx_object)));
}

/* virtual ::cortex::lang::dispatcher::post(lang::event event) */
void cx_dispatcher_post(cx_dispatcher _this, cx_event event) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "post(lang::event event)");
    }
    cx_assert(_methodId, "virtual method 'post(lang::event event)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::post(lang::event event)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), NULL, _this, event);
}

void __cx_dispatcher_post_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_dispatcher_post_v(
        *(cx_dispatcher*)args,
        *(cx_event*)((intptr_t)args + sizeof(cx_dispatcher)));
}

void __cx_enum_constant(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = cx_enum_constant(
        *(cx_enum*)args,
        *(cx_int32*)((intptr_t)args + sizeof(cx_enum)));
}

void __cx_enum_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_enum_construct(
        *(cx_enum*)args);
}

void __cx_enum_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_enum_destruct(
        *(cx_enum*)args);
}

void __cx_enum_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_enum_init(
        *(cx_enum*)args);
}

void __cx_event_processed(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_event_processed(
        *(cx_event*)args);
}

void __cx_event_uniqueKind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_event_uniqueKind(
        );
}

void __cx_float_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_float_init(
        *(cx_float*)args);
}

void __cx_function_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_function_bind(
        *(cx_function*)args);
}

void __cx_function_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_function_init(
        *(cx_function*)args);
}

void __cx_function_stringToParameterSeq(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_parameterSeq*)result = cx_function_stringToParameterSeq(
        *(cx_string*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_string)));
}

void __cx_function_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_function_unbind(
        *(cx_function*)args);
}

void __cx_int_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_int_init(
        *(cx_int*)args);
}

void __cx_interface_baseof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_baseof(
        *(cx_interface*)args,
        *(cx_interface*)((intptr_t)args + sizeof(cx_interface)));
}

/* virtual ::cortex::lang::interface::bindMethod(lang::method method) */
cx_int16 cx_interface_bindMethod(cx_interface _this, cx_method method) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_int16 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "bindMethod(lang::method method)");
    }
    cx_assert(_methodId, "virtual method 'bindMethod(lang::method method)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::bindMethod(lang::method method)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, method);
    
    return _result;
}

void __cx_interface_bindMethod_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_bindMethod_v(
        *(cx_interface*)args,
        *(cx_method*)((intptr_t)args + sizeof(cx_interface)));
}

/* virtual ::cortex::lang::interface::compatible(lang::type type) */
cx_bool cx_interface_compatible(cx_interface _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_interface_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_interface_compatible_v(
        *(cx_interface*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_interface)));
}

void __cx_interface_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_construct(
        *(cx_interface*)args);
}

void __cx_interface_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_interface_destruct(
        *(cx_interface*)args);
}

void __cx_interface_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_init(
        *(cx_interface*)args);
}

/* virtual ::cortex::lang::interface::resolveMember(lang::string name) */
cx_member cx_interface_resolveMember(cx_interface _this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(lang::string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(lang::string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(lang::string name)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, name);
    
    return _result;
}

void __cx_interface_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = cx_interface_resolveMember_v(
        *(cx_interface*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_interface)));
}

void __cx_interface_resolveMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_interface_resolveMethod(
        *(cx_interface*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_interface)));
}

void __cx_interface_resolveMethodById(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_interface_resolveMethodById(
        *(cx_interface*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_interface)));
}

void __cx_interface_resolveMethodId(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint32*)result = cx_interface_resolveMethodId(
        *(cx_interface*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_interface)));
}

void __cx_list_append_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = cx_list_append_(
        *(cx_any*)args);
}

void __cx_list_append_lang_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_list_append_lang_any(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_list_clear(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_list_clear(
        *(cx_any*)args);
}

void __cx_list_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_list_construct(
        *(cx_list*)args);
}

void __cx_list_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_list_init(
        *(cx_list*)args);
}

void __cx_list_insert_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = cx_list_insert_(
        *(cx_any*)args);
}

void __cx_list_insert_lang_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_list_insert_lang_any(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_list_reverse(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_list_reverse(
        *(cx_any*)args);
}

void __cx_map_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_map_construct(
        *(cx_map*)args);
}

void __cx_map_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_map_init(
        *(cx_map*)args);
}

void __cx_member_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_member_construct(
        *(cx_member*)args);
}

void __cx_member_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_member_init(
        *(cx_member*)args);
}

void __cx_metaprocedure_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_metaprocedure_bind(
        *(cx_metaprocedure*)args);
}

void __cx_method_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_method_bind(
        *(cx_method*)args);
}

void __cx_method_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_method_init(
        *(cx_method*)args);
}

void __cx_observer_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_bind(
        *(cx_observer*)args);
}

void __cx_observer_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_init(
        *(cx_observer*)args);
}

void __cx_observer_listen(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_listen(
        *(cx_observer*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_observer)),
        *(cx_object*)((intptr_t)args + sizeof(cx_observer) + sizeof(cx_object)));
}

void __cx_observer_setDispatcher(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_observer_setDispatcher(
        *(cx_observer*)args,
        *(cx_dispatcher*)((intptr_t)args + sizeof(cx_observer)));
}

void __cx_observer_silence(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_silence(
        *(cx_observer*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_observer)));
}

void __cx_observer_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_observer_unbind(
        *(cx_observer*)args);
}

/* virtual ::cortex::lang::primitive::castable(lang::type type) */
cx_bool cx_primitive_castable(cx_primitive _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_primitive_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_primitive_castable_v(
        *(cx_primitive*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_primitive)));
}

/* virtual ::cortex::lang::primitive::compatible(lang::type type) */
cx_bool cx_primitive_compatible(cx_primitive _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_primitive_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_primitive_compatible_v(
        *(cx_primitive*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_primitive)));
}

void __cx_primitive_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_primitive_construct(
        *(cx_primitive*)args);
}

void __cx_primitive_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_primitive_init(
        *(cx_primitive*)args);
}

/* delegate ::cortex::lang::procedure::bind(lang::object object) */
cx_int16 cx_procedure_bind(cx_procedure _this, cx_object object) {
    cx_callback _callback;
    cx_int16 _result;
    /* Lookup callback-object. */
    _callback = cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_procedure_bind_o, _this);

    cx_assert(_callback != NULL, "no callback 'bind(lang::object object)' for object of type 'cx_procedure' (call 'cx_procedure_bind_checkCallback' first)");

    cx_call(cx_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::procedure::bind(lang::object object), obtain callback */
cx_bool cx_procedure_bind_hasCallback(cx_procedure _this) {
    /* Lookup callback-object. */
    return cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_procedure_bind_o, _this) != NULL;
}

void __cx_procedure_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_procedure_bind(
        *(cx_procedure*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_procedure)));
}

void __cx_procedure_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_procedure_init(
        *(cx_procedure*)args);
}

void __cx_procedure_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_procedure_unbind(
        *(cx_procedure*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_procedure)));
}

/* virtual ::cortex::lang::procptr::compatible(lang::type type) */
cx_bool cx_procptr_compatible(cx_procptr _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_procptr_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_procptr_compatible_v(
        *(cx_procptr*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_procptr)));
}

void __cx_procptr_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_procptr_init(
        *(cx_procptr*)args);
}

void __cx_sequence_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_sequence_construct(
        *(cx_sequence*)args);
}

void __cx_sequence_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_sequence_init(
        *(cx_sequence*)args);
}

void __cx_sequence_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_sequence_size(
        *(cx_any*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_any)));
}

/* virtual ::cortex::lang::struct::castable(lang::type type) */
cx_bool cx_struct_castable(cx_struct _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_struct_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_struct_castable_v(
        *(cx_struct*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_struct)));
}

/* virtual ::cortex::lang::struct::compatible(lang::type type) */
cx_bool cx_struct_compatible(cx_struct _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_struct_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_struct_compatible_v(
        *(cx_struct*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_struct)));
}

void __cx_struct_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_struct_construct(
        *(cx_struct*)args);
}

void __cx_struct_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_struct_init(
        *(cx_struct*)args);
}

/* virtual ::cortex::lang::struct::resolveMember(lang::string name) */
cx_member cx_struct_resolveMember(cx_struct _this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(lang::string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(lang::string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(lang::string name)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, name);
    
    return _result;
}

void __cx_struct_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = cx_struct_resolveMember_v(
        *(cx_struct*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_struct)));
}

void __cx_text_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_text_init(
        *(cx_text*)args);
}

void __cx_type__destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_type__destruct(
        *(cx_type*)args);
}

void __cx_type__init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_type__init(
        *(cx_type*)args);
}

void __cx_type_alignmentof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint16*)result = cx_type_alignmentof(
        *(cx_type*)args);
}

/* virtual ::cortex::lang::type::allocSize() */
cx_uint32 cx_type_allocSize(cx_type _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_uint32 _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "allocSize()");
    }
    cx_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this);
    
    return _result;
}

void __cx_type_allocSize_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_type_allocSize_v(
        *(cx_type*)args);
}

/* virtual ::cortex::lang::type::castable(lang::type type) */
cx_bool cx_type_castable(cx_type _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_type_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_castable_v(
        *(cx_type*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_type)));
}

void __cx_type_checkAttr(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_checkAttr(
        *(cx_any*)args,
        *(cx_attr*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_checkState(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_checkState(
        *(cx_any*)args,
        *(cx_state*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_compare(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_equalityKind*)result = cx_type_compare(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

/* virtual ::cortex::lang::type::compatible(lang::type type) */
cx_bool cx_type_compatible(cx_type _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_type_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_compatible_v(
        *(cx_type*)args,
        *(cx_type*)((intptr_t)args + sizeof(cx_type)));
}

void __cx_type_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_type_construct(
        *(cx_type*)args);
}

void __cx_type_copy(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_type_copy(
        *(cx_any*)args,
        *(cx_any*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_declare(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = cx_type_declare(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)),
        *(cx_typedef*)((intptr_t)args + sizeof(cx_any) + sizeof(cx_string)));
}

void __cx_type_define(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_type_define(
        *(cx_any*)args);
}

void __cx_type_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_type_destruct(
        *(cx_any*)args);
}

void __cx_type_fullname(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = cx_type_fullname(
        *(cx_any*)args);
}

/* delegate ::cortex::lang::type::init(lang::object object) */
cx_int16 cx_type_init(cx_type _this, cx_object object) {
    cx_callback _callback;
    cx_int16 _result;
    /* Lookup callback-object. */
    _callback = cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_type_init_o, _this);

    cx_assert(_callback != NULL, "no callback 'init(lang::object object)' for object of type 'cx_type' (call 'cx_type_init_checkCallback' first)");

    cx_call(cx_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::type::init(lang::object object), obtain callback */
cx_bool cx_type_init_hasCallback(cx_type _this) {
    /* Lookup callback-object. */
    return cx_class_resolveCallback(cx_class(cx_typeof(_this)), cx_type_init_o, _this) != NULL;
}

void __cx_type_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_type_init(
        *(cx_type*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_type)));
}

void __cx_type_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_instanceof(
        *(cx_any*)args,
        *(cx_typedef*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_invalidate(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_type_invalidate(
        *(cx_any*)args);
}

void __cx_type_lookup(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = cx_type_lookup(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_nameof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = cx_type_nameof(
        *(cx_any*)args);
}

void __cx_type_parentof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_object*)result = cx_type_parentof(
        *(cx_any*)args);
}

void __cx_type_relname(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_string*)result = cx_type_relname(
        *(cx_any*)args,
        *(cx_object*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_resolve(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = cx_type_resolve(
        *(cx_any*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_any)));
}

void __cx_type_resolveProcedure(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_function*)result = cx_type_resolveProcedure(
        *(cx_type*)args,
        *(cx_string*)((intptr_t)args + sizeof(cx_type)));
}

void __cx_type_sizeof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_type_sizeof(
        *(cx_type*)args);
}

void __cx_type_toString(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = cx_type_toString(
        *(cx_any*)args);
}

void __cx_type_typeof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = cx_type_typeof(
        *(cx_any*)args);
}

void __cx_typedef_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_typedef_construct(
        *(cx_typedef*)args);
}

void __cx_typedef_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_typedef_destruct(
        *(cx_typedef*)args);
}

void __cx_typedef_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_typedef_init(
        *(cx_typedef*)args);
}

void __cx_typedef_realType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = cx_typedef_realType(
        *(cx_typedef*)args);
}

void __cx_uint_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_uint_init(
        *(cx_uint*)args);
}

void __cx_virtual_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_virtual_init(
        *(cx_virtual*)args);
}
