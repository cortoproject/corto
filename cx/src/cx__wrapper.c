/* cx__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::lang.
 */

#include "cx.h"
#include "cx__meta.h"

void __cx_alias_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_alias_init(
        *(void**)args);
}

void __cx_array_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_array_construct(
        *(void**)args);
}

void __cx_array_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_array_destruct(
        *(void**)args);
}

void __cx_array_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_array_init(
        *(void**)args);
}

void __cx_binary_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_binary_init(
        *(void**)args);
}

void __cx_bitmask_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_bitmask_init(
        *(void**)args);
}

void __cx_boolean_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_boolean_init(
        *(void**)args);
}

void __cx_character_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_character_init(
        *(void**)args);
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
        *(void**)args);
}

void __cx_class_bindObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_class_bindObserver(
        *(void**)args,
        *(cx_observer*)((intptr_t)args + sizeof(void*)));
}

void __cx_class_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_class_construct(
        *(void**)args);
}

void __cx_class_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_class_destruct(
        *(void**)args);
}

void __cx_class_findObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = cx_class_findObserver(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(cx_object)));
}

void __cx_class_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_class_init(
        *(void**)args);
}

void __cx_class_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_class_instanceof(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_class_privateObserver(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observer*)result = cx_class_privateObserver(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)),
        *(cx_observer*)((intptr_t)args + sizeof(void*) + sizeof(cx_object)));
}

void __cx_class_resolveInterfaceMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_class_resolveInterfaceMethod(
        *(void**)args,
        *(cx_interface*)((intptr_t)args + sizeof(void*)),
        *(cx_uint32*)((intptr_t)args + sizeof(void*) + sizeof(cx_interface)));
}

/* virtual ::cortex::lang::collection::castable(type type) */
cx_bool cx_collection_castable(cx_collection _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_collection_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_collection_castable_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::lang::collection::compatible(type type) */
cx_bool cx_collection_compatible(cx_collection _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_collection_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_collection_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_collection_elementRequiresAlloc(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = cx_collection_elementRequiresAlloc(
        *(void**)args);
}

void __cx_collection_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_collection_init(
        *(void**)args);
}

void __cx_collection_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_collection_size(
        *(cx_any*)args);
}

void __cx_constant_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_constant_init(
        *(void**)args);
}

/* virtual ::cortex::lang::dispatcher::getEvent(observer observer,object me,object observable,object src) */
cx_observableEvent cx_dispatcher_getEvent(cx_dispatcher _this, cx_observer observer, cx_object me, cx_object observable, cx_object src) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_observableEvent _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "getEvent(observer observer,object me,object observable,object src)");
    }
    cx_assert(_methodId, "virtual method 'getEvent(observer observer,object me,object observable,object src)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::getEvent(observer observer,object me,object observable,object src)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, observer, me, observable, src);
    
    return _result;
}

void __cx_dispatcher_getEvent_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_observableEvent*)result = cx_dispatcher_getEvent_v(
        *(void**)args,
        *(cx_observer*)((intptr_t)args + sizeof(void*)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_observer)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_observer) + sizeof(cx_object)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_observer) + sizeof(cx_object) + sizeof(cx_object)));
}

/* virtual ::cortex::lang::dispatcher::post(event event) */
void cx_dispatcher_post(cx_dispatcher _this, cx_event event) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "post(event event)");
    }
    cx_assert(_methodId, "virtual method 'post(event event)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::post(event event)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), NULL, _this, event);
}

void __cx_dispatcher_post_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_dispatcher_post_v(
        *(void**)args,
        *(cx_event*)((intptr_t)args + sizeof(void*)));
}

void __cx_enum_constant(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_object*)result = cx_enum_constant(
        *(void**)args,
        *(cx_int32*)((intptr_t)args + sizeof(void*)));
}

void __cx_enum_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_enum_construct(
        *(void**)args);
}

void __cx_enum_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_enum_destruct(
        *(void**)args);
}

void __cx_enum_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_enum_init(
        *(void**)args);
}

void __cx_event_processed(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_event_processed(
        *(void**)args);
}

void __cx_event_uniqueKind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_event_uniqueKind(
        );
}

void __cx_float_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_float_init(
        *(void**)args);
}

void __cx_function_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_function_bind(
        *(void**)args);
}

void __cx_function_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_function_init(
        *(void**)args);
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
    CX_UNUSED(args);
    *(cx_int16*)result = cx_int_init(
        *(void**)args);
}

void __cx_interface_baseof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_baseof(
        *(void**)args,
        *(cx_interface*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_bindMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_interface_bindMethod(
        *(void**)args,
        *(cx_method*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::lang::interface::compatible(type type) */
cx_bool cx_interface_compatible(cx_interface _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_interface_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_interface_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_interface_construct(
        *(void**)args);
}

void __cx_interface_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_interface_destruct(
        *(void**)args);
}

void __cx_interface_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_interface_init(
        *(void**)args);
}

/* virtual ::cortex::lang::interface::resolveMember(string name) */
cx_member cx_interface_resolveMember(cx_interface _this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, name);
    
    return _result;
}

void __cx_interface_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = cx_interface_resolveMember_v(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethod(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_interface_resolveMethod(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethodById(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_method*)result = cx_interface_resolveMethodById(
        *(void**)args,
        *(cx_uint32*)((intptr_t)args + sizeof(void*)));
}

void __cx_interface_resolveMethodId(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint32*)result = cx_interface_resolveMethodId(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_iterator_hasNext(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = cx_iterator_hasNext(
        *(cx_any*)args);
}

void __cx_iterator_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_iterator_init(
        *(cx_iterator*)args);
}

void __cx_iterator_next(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = cx_iterator_next(
        *(cx_any*)args);
}

void __cx_list_append_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = cx_list_append_(
        *(cx_any*)args);
}

void __cx_list_append_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_list_append_any(
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
    CX_UNUSED(args);
    *(cx_int16*)result = cx_list_construct(
        *(void**)args);
}

void __cx_list_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_list_init(
        *(void**)args);
}

void __cx_list_insert_(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_any*)result = cx_list_insert_(
        *(cx_any*)args);
}

void __cx_list_insert_any(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_list_insert_any(
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
    CX_UNUSED(args);
    *(cx_int16*)result = cx_map_construct(
        *(void**)args);
}

void __cx_map_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_map_init(
        *(void**)args);
}

void __cx_member_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_member_construct(
        *(void**)args);
}

void __cx_member_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_member_init(
        *(void**)args);
}

void __cx_metaprocedure_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_metaprocedure_bind(
        *(void**)args);
}

void __cx_method_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_method_bind(
        *(void**)args);
}

void __cx_method_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_method_init(
        *(void**)args);
}

void __cx_observer_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_observer_bind(
        *(void**)args);
}

void __cx_observer_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_observer_init(
        *(void**)args);
}

void __cx_observer_listen(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_listen(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)),
        *(cx_object*)((intptr_t)args + sizeof(void*) + sizeof(cx_object)));
}

void __cx_observer_setDispatcher(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_observer_setDispatcher(
        *(void**)args,
        *(cx_dispatcher*)((intptr_t)args + sizeof(void*)));
}

void __cx_observer_silence(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_observer_silence(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_observer_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_observer_unbind(
        *(cx_observer*)args);
}

/* virtual ::cortex::lang::primitive::castable(type type) */
cx_bool cx_primitive_castable(cx_primitive _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_primitive_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_primitive_castable_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::lang::primitive::compatible(type type) */
cx_bool cx_primitive_compatible(cx_primitive _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_primitive_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_primitive_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_primitive_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_primitive_construct(
        *(void**)args);
}

void __cx_primitive_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_primitive_init(
        *(void**)args);
}

void __cx_procedure_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_procedure_init(
        *(void**)args);
}

void __cx_procedure_unbind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_procedure_unbind(
        *(void**)args,
        *(cx_function*)((intptr_t)args + sizeof(void*)));
}

void __cx_delegate_bind(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = cx_delegate_bind(
        *(cx_function*)args);
}

/* virtual ::cortex::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable(cx_delegate _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_delegate_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_delegate_castable_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible(cx_delegate _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_delegate_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_delegate_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_delegate_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_delegate_init(
        *(void**)args);
}

void __cx_delegate_instanceof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_delegate_instanceof(
        *(void**)args,
        *(cx_object*)((intptr_t)args + sizeof(void*)));
}

void __cx_sequence_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_sequence_construct(
        *(void**)args);
}

void __cx_sequence_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_sequence_init(
        *(void**)args);
}

void __cx_sequence_size(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    cx_sequence_size(
        *(cx_any*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_any)));
}

/* virtual ::cortex::lang::struct::castable(type type) */
cx_bool cx_struct_castable(cx_struct _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_struct_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_struct_castable_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

/* virtual ::cortex::lang::struct::compatible(type type) */
cx_bool cx_struct_compatible(cx_struct _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_struct_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_struct_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_struct_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_struct_construct(
        *(void**)args);
}

void __cx_struct_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_struct_init(
        *(void**)args);
}

/* virtual ::cortex::lang::struct::resolveMember(string name) */
cx_member cx_struct_resolveMember(cx_struct _this, cx_string name) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_member _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    cx_assert(_methodId, "virtual method 'resolveMember(string name)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, name);
    
    return _result;
}

void __cx_struct_resolveMember_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_member*)result = cx_struct_resolveMember_v(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_text_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_text_init(
        *(void**)args);
}

void __cx_type_alignmentof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint16*)result = cx_type_alignmentof(
        *(void**)args);
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
        *(void**)args);
}

/* virtual ::cortex::lang::type::castable(type type) */
cx_bool cx_type_castable(cx_type _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    cx_assert(_methodId, "virtual method 'castable(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_type_castable_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_castable_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
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

/* virtual ::cortex::lang::type::compatible(type type) */
cx_bool cx_type_compatible(cx_type _this, cx_type type) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_bool _result;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    cx_assert(_methodId, "virtual method 'compatible(type type)' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), &_result, _this, type);
    
    return _result;
}

void __cx_type_compatible_v(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_bool*)result = cx_type_compatible_v(
        *(void**)args,
        *(cx_type*)((intptr_t)args + sizeof(void*)));
}

void __cx_type_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_type_construct(
        *(void**)args);
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
        *(void**)args);
}

void __cx_type_fullname(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_string*)result = cx_type_fullname(
        *(cx_any*)args);
}

void __cx_type_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_type_init(
        *(void**)args);
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
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __cx_type_sizeof(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_uint32*)result = cx_type_sizeof(
        *(void**)args);
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
    CX_UNUSED(args);
    *(cx_int16*)result = cx_typedef_construct(
        *(void**)args);
}

void __cx_typedef_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    cx_typedef_destruct(
        *(void**)args);
}

void __cx_typedef_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_typedef_init(
        *(void**)args);
}

void __cx_typedef_realType(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_type*)result = cx_typedef_realType(
        *(void**)args);
}

void __cx_uint_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_uint_init(
        *(void**)args);
}

void __cx_virtual_init(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = cx_virtual_init(
        *(void**)args);
}
