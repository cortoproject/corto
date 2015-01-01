/* db__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::lang.
 */

#include "db.h"
#include "db__meta.h"

void __db_alias_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_alias_init(
        *(db_alias*)args);
}

void __db_array_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_array_construct(
        *(db_array*)args);
}

void __db_array_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_array_destruct(
        *(db_array*)args);
}

void __db_array_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_array_init(
        *(db_array*)args);
}

void __db_binary_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_binary_init(
        *(db_binary*)args);
}

void __db_bitmask_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_bitmask_init(
        *(db_bitmask*)args);
}

void __db_boolean_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_boolean_init(
        *(db_boolean*)args);
}

void __db_callback_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_callback_bind(
        *(db_callback*)args);
}

void __db_callback_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_callback_init(
        *(db_callback*)args);
}

void __db_character_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_character_init(
        *(db_character*)args);
}

void __db_class__construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class__construct(
        *(db_class*)args);
}

void __db_class__destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_class__destruct(
        *(db_class*)args);
}

/* virtual ::cortex::lang::class::allocSize() */
db_uint32 db_class_allocSize(db_class _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_uint32 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "allocSize()");
    }
    db_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __db_class_allocSize_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint32*)result = db_class_allocSize_v(
        *(db_class*)args);
}

void __db_class_bindCallback(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class_bindCallback(
        *(db_class*)args,
        *(db_delegate*)((intptr_t)args + sizeof(db_class)),
        *(db_object*)((intptr_t)args + sizeof(db_class) + sizeof(db_delegate)),
        *(db_callback*)((intptr_t)args + sizeof(db_class) + sizeof(db_delegate) + sizeof(db_object)));
}

void __db_class_bindDelegate(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class_bindDelegate(
        *(db_class*)args,
        *(db_delegate*)((intptr_t)args + sizeof(db_class)));
}

void __db_class_bindMethod(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class_bindMethod(
        *(db_class*)args,
        *(db_method*)((intptr_t)args + sizeof(db_class)));
}

void __db_class_bindObserver(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_class_bindObserver(
        *(db_class*)args,
        *(db_observer*)((intptr_t)args + sizeof(db_class)));
}

/* delegate ::cortex::lang::class::construct(lang::object object) */
db_int16 db_class_construct(db_class _this, db_object object) {
    db_callback _callback;
    db_int16 _result;
    /* Lookup callback-object. */
    _callback = db_class_resolveCallback(db_class(db_typeof(_this)), db_class_construct_o, _this);

    db_assert(_callback != NULL, "no callback 'construct(lang::object object)' for object of type 'db_class' (call 'db_class_construct_checkCallback' first)");

    db_call(db_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::class::construct(lang::object object), obtain callback */
db_bool db_class_construct_hasCallback(db_class _this) {
    /* Lookup callback-object. */
    return db_class_resolveCallback(db_class(db_typeof(_this)), db_class_construct_o, _this) != NULL;
}

void __db_class_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class_construct(
        *(db_class*)args,
        *(db_object*)((intptr_t)args + sizeof(db_class)));
}

/* delegate ::cortex::lang::class::destruct(lang::object object) */
void db_class_destruct(db_class _this, db_object object) {
    db_callback _callback;
    /* Lookup callback-object. */
    _callback = db_class_resolveCallback(db_class(db_typeof(_this)), db_class_destruct_o, _this);

    db_assert(_callback != NULL, "no callback 'destruct(lang::object object)' for object of type 'db_class' (call 'db_class_destruct_checkCallback' first)");

    db_call(db_function(_callback), NULL, object);
}

/* delegate ::cortex::lang::class::destruct(lang::object object), obtain callback */
db_bool db_class_destruct_hasCallback(db_class _this) {
    /* Lookup callback-object. */
    return db_class_resolveCallback(db_class(db_typeof(_this)), db_class_destruct_o, _this) != NULL;
}

void __db_class_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_class_destruct(
        *(db_class*)args,
        *(db_object*)((intptr_t)args + sizeof(db_class)));
}

void __db_class_findObserver(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_observer*)result = db_class_findObserver(
        *(db_class*)args,
        *(db_object*)((intptr_t)args + sizeof(db_class)),
        *(db_string*)((intptr_t)args + sizeof(db_class) + sizeof(db_object)));
}

void __db_class_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_class_init(
        *(db_class*)args);
}

void __db_class_instanceof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_class_instanceof(
        *(db_class*)args,
        *(db_object*)((intptr_t)args + sizeof(db_class)));
}

void __db_class_privateObserver(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_observer*)result = db_class_privateObserver(
        *(db_class*)args,
        *(db_object*)((intptr_t)args + sizeof(db_class)),
        *(db_observer*)((intptr_t)args + sizeof(db_class) + sizeof(db_object)));
}

void __db_class_resolveCallback(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_callback*)result = db_class_resolveCallback(
        *(db_class*)args,
        *(db_delegate*)((intptr_t)args + sizeof(db_class)),
        *(db_object*)((intptr_t)args + sizeof(db_class) + sizeof(db_delegate)));
}

void __db_class_resolveDelegate(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_delegate*)result = db_class_resolveDelegate(
        *(db_class*)args,
        *(db_string*)((intptr_t)args + sizeof(db_class)));
}

void __db_class_resolveInterfaceMethod(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_method*)result = db_class_resolveInterfaceMethod(
        *(db_class*)args,
        *(db_interface*)((intptr_t)args + sizeof(db_class)),
        *(db_uint32*)((intptr_t)args + sizeof(db_class) + sizeof(db_interface)));
}

/* virtual ::cortex::lang::collection::castable(lang::type type) */
db_bool db_collection_castable(db_collection _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_collection_castable_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_collection_castable_v(
        *(db_collection*)args,
        *(db_type*)((intptr_t)args + sizeof(db_collection)));
}

void __db_collection_elementRequiresAlloc(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_bool*)result = db_collection_elementRequiresAlloc(
        *(db_collection*)args);
}

void __db_collection_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_collection_init(
        *(db_collection*)args);
}

void __db_collection_size(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint32*)result = db_collection_size(
        *(db_any*)args);
}

void __db_constant_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_constant_init(
        *(void**)args);
}

void __db_delegate_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_delegate_init(
        *(db_delegate*)args);
}

/* virtual ::cortex::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
db_observableEvent db_dispatcher_getEvent(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src) {
    static db_uint32 _methodId;
    db_method _method;
    db_observableEvent _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)");
    }
    db_assert(_methodId, "virtual method 'getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, observer, me, observable, src);
    
    return _result;
}

void __db_dispatcher_getEvent_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_observableEvent*)result = db_dispatcher_getEvent_v(
        *(db_dispatcher*)args,
        *(db_observer*)((intptr_t)args + sizeof(db_dispatcher)),
        *(db_object*)((intptr_t)args + sizeof(db_dispatcher) + sizeof(db_observer)),
        *(db_object*)((intptr_t)args + sizeof(db_dispatcher) + sizeof(db_observer) + sizeof(db_object)),
        *(db_object*)((intptr_t)args + sizeof(db_dispatcher) + sizeof(db_observer) + sizeof(db_object) + sizeof(db_object)));
}

/* virtual ::cortex::lang::dispatcher::post(lang::event event) */
void db_dispatcher_post(db_dispatcher _this, db_event event) {
    static db_uint32 _methodId;
    db_method _method;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "post(lang::event event)");
    }
    db_assert(_methodId, "virtual method 'post(lang::event event)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::post(lang::event event)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), NULL, _this, event);
}

void __db_dispatcher_post_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_dispatcher_post_v(
        *(db_dispatcher*)args,
        *(db_event*)((intptr_t)args + sizeof(db_dispatcher)));
}

void __db_enum_constant(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_enum_constant(
        *(db_enum*)args,
        *(db_int32*)((intptr_t)args + sizeof(db_enum)));
}

void __db_enum_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_enum_construct(
        *(db_enum*)args);
}

void __db_enum_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_enum_destruct(
        *(db_enum*)args);
}

void __db_enum_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_enum_init(
        *(db_enum*)args);
}

void __db_event_processed(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    db_event_processed(
        *(db_event*)args);
}

void __db_event_uniqueKind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = db_event_uniqueKind(
        );
}

void __db_float_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_float_init(
        *(db_float*)args);
}

void __db_function_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_function_bind(
        *(db_function*)args);
}

void __db_function_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_function_init(
        *(db_function*)args);
}

void __db_function_stringToParameterSeq(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_parameterSeq*)result = db_function_stringToParameterSeq(
        *(db_string*)args,
        *(db_object*)((intptr_t)args + sizeof(db_string)));
}

void __db_function_unbind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_function_unbind(
        *(db_function*)args);
}

void __db_int_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_int_init(
        *(db_int*)args);
}

void __db_interface_baseof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_interface_baseof(
        *(db_interface*)args,
        *(db_interface*)((intptr_t)args + sizeof(db_interface)));
}

/* virtual ::cortex::lang::interface::bindMethod(lang::method method) */
db_int16 db_interface_bindMethod(db_interface _this, db_method method) {
    static db_uint32 _methodId;
    db_method _method;
    db_int16 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "bindMethod(lang::method method)");
    }
    db_assert(_methodId, "virtual method 'bindMethod(lang::method method)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::bindMethod(lang::method method)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, method);
    
    return _result;
}

void __db_interface_bindMethod_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_interface_bindMethod_v(
        *(db_interface*)args,
        *(db_method*)((intptr_t)args + sizeof(db_interface)));
}

/* virtual ::cortex::lang::interface::compatible(lang::type type) */
db_bool db_interface_compatible(db_interface _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_interface_compatible_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_interface_compatible_v(
        *(db_interface*)args,
        *(db_type*)((intptr_t)args + sizeof(db_interface)));
}

void __db_interface_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_interface_construct(
        *(db_interface*)args);
}

void __db_interface_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_interface_destruct(
        *(db_interface*)args);
}

void __db_interface_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_interface_init(
        *(db_interface*)args);
}

/* virtual ::cortex::lang::interface::resolveMember(lang::string name) */
db_member db_interface_resolveMember(db_interface _this, db_string name) {
    static db_uint32 _methodId;
    db_method _method;
    db_member _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "resolveMember(lang::string name)");
    }
    db_assert(_methodId, "virtual method 'resolveMember(lang::string name)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::resolveMember(lang::string name)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, name);
    
    return _result;
}

void __db_interface_resolveMember_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_member*)result = db_interface_resolveMember_v(
        *(db_interface*)args,
        *(db_string*)((intptr_t)args + sizeof(db_interface)));
}

void __db_interface_resolveMethod(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_method*)result = db_interface_resolveMethod(
        *(db_interface*)args,
        *(db_string*)((intptr_t)args + sizeof(db_interface)));
}

void __db_interface_resolveMethodById(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_method*)result = db_interface_resolveMethodById(
        *(db_interface*)args,
        *(db_uint32*)((intptr_t)args + sizeof(db_interface)));
}

void __db_interface_resolveMethodId(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_uint32*)result = db_interface_resolveMethodId(
        *(db_interface*)args,
        *(db_string*)((intptr_t)args + sizeof(db_interface)));
}

void __db_list_append_(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_any*)result = db_list_append_(
        *(db_any*)args);
}

void __db_list_append_lang_any(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_list_append_lang_any(
        *(db_any*)args,
        *(db_any*)((intptr_t)args + sizeof(db_any)));
}

void __db_list_clear(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    db_list_clear(
        *(db_any*)args);
}

void __db_list_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_list_construct(
        *(db_list*)args);
}

void __db_list_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_list_init(
        *(db_list*)args);
}

void __db_list_insert_(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_any*)result = db_list_insert_(
        *(db_any*)args);
}

void __db_list_insert_lang_any(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_list_insert_lang_any(
        *(db_any*)args,
        *(db_any*)((intptr_t)args + sizeof(db_any)));
}

void __db_list_reverse(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    db_list_reverse(
        *(db_any*)args);
}

void __db_map_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_map_construct(
        *(db_map*)args);
}

void __db_map_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_map_init(
        *(db_map*)args);
}

void __db_member_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_member_construct(
        *(db_member*)args);
}

void __db_member_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_member_init(
        *(db_member*)args);
}

void __db_metaprocedure_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_metaprocedure_bind(
        *(db_metaprocedure*)args);
}

void __db_method_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_method_bind(
        *(db_method*)args);
}

void __db_method_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_method_init(
        *(db_method*)args);
}

void __db_observer_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_observer_bind(
        *(db_observer*)args);
}

void __db_observer_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_observer_init(
        *(db_observer*)args);
}

void __db_observer_listen(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_observer_listen(
        *(db_observer*)args,
        *(db_object*)((intptr_t)args + sizeof(db_observer)),
        *(db_object*)((intptr_t)args + sizeof(db_observer) + sizeof(db_object)));
}

void __db_observer_setDispatcher(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_observer_setDispatcher(
        *(db_observer*)args,
        *(db_dispatcher*)((intptr_t)args + sizeof(db_observer)));
}

void __db_observer_silence(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_observer_silence(
        *(db_observer*)args,
        *(db_object*)((intptr_t)args + sizeof(db_observer)));
}

void __db_observer_unbind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_observer_unbind(
        *(db_observer*)args);
}

/* virtual ::cortex::lang::primitive::castable(lang::type type) */
db_bool db_primitive_castable(db_primitive _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_primitive_castable_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_primitive_castable_v(
        *(db_primitive*)args,
        *(db_type*)((intptr_t)args + sizeof(db_primitive)));
}

/* virtual ::cortex::lang::primitive::compatible(lang::type type) */
db_bool db_primitive_compatible(db_primitive _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_primitive_compatible_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_primitive_compatible_v(
        *(db_primitive*)args,
        *(db_type*)((intptr_t)args + sizeof(db_primitive)));
}

void __db_primitive_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_primitive_construct(
        *(db_primitive*)args);
}

void __db_primitive_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_primitive_init(
        *(db_primitive*)args);
}

/* delegate ::cortex::lang::procedure::bind(lang::object object) */
db_int16 db_procedure_bind(db_procedure _this, db_object object) {
    db_callback _callback;
    db_int16 _result;
    /* Lookup callback-object. */
    _callback = db_class_resolveCallback(db_class(db_typeof(_this)), db_procedure_bind_o, _this);

    db_assert(_callback != NULL, "no callback 'bind(lang::object object)' for object of type 'db_procedure' (call 'db_procedure_bind_checkCallback' first)");

    db_call(db_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::procedure::bind(lang::object object), obtain callback */
db_bool db_procedure_bind_hasCallback(db_procedure _this) {
    /* Lookup callback-object. */
    return db_class_resolveCallback(db_class(db_typeof(_this)), db_procedure_bind_o, _this) != NULL;
}

void __db_procedure_bind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_procedure_bind(
        *(db_procedure*)args,
        *(db_object*)((intptr_t)args + sizeof(db_procedure)));
}

void __db_procedure_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_procedure_init(
        *(db_procedure*)args);
}

void __db_procedure_unbind(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_procedure_unbind(
        *(db_procedure*)args,
        *(db_object*)((intptr_t)args + sizeof(db_procedure)));
}

/* virtual ::cortex::lang::procptr::compatible(lang::type type) */
db_bool db_procptr_compatible(db_procptr _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_procptr_compatible_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_procptr_compatible_v(
        *(db_procptr*)args,
        *(db_type*)((intptr_t)args + sizeof(db_procptr)));
}

void __db_procptr_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_procptr_init(
        *(db_procptr*)args);
}

void __db_sequence_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_sequence_construct(
        *(db_sequence*)args);
}

void __db_sequence_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_sequence_init(
        *(db_sequence*)args);
}

void __db_sequence_size(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_sequence_size(
        *(db_any*)args,
        *(db_uint32*)((intptr_t)args + sizeof(db_any)));
}

/* virtual ::cortex::lang::struct::castable(lang::type type) */
db_bool db_struct_castable(db_struct _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_struct_castable_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_struct_castable_v(
        *(db_struct*)args,
        *(db_type*)((intptr_t)args + sizeof(db_struct)));
}

/* virtual ::cortex::lang::struct::compatible(lang::type type) */
db_bool db_struct_compatible(db_struct _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_struct_compatible_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_struct_compatible_v(
        *(db_struct*)args,
        *(db_type*)((intptr_t)args + sizeof(db_struct)));
}

void __db_struct_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_struct_construct(
        *(db_struct*)args);
}

void __db_struct_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_struct_init(
        *(db_struct*)args);
}

/* virtual ::cortex::lang::struct::resolveMember(lang::string name) */
db_member db_struct_resolveMember(db_struct _this, db_string name) {
    static db_uint32 _methodId;
    db_method _method;
    db_member _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "resolveMember(lang::string name)");
    }
    db_assert(_methodId, "virtual method 'resolveMember(lang::string name)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::resolveMember(lang::string name)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, name);
    
    return _result;
}

void __db_struct_resolveMember_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_member*)result = db_struct_resolveMember_v(
        *(db_struct*)args,
        *(db_string*)((intptr_t)args + sizeof(db_struct)));
}

void __db_text_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_text_init(
        *(db_text*)args);
}

void __db_type__destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_type__destruct(
        *(db_type*)args);
}

void __db_type__init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_type__init(
        *(db_type*)args);
}

void __db_type_alignmentof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint16*)result = db_type_alignmentof(
        *(db_type*)args);
}

/* virtual ::cortex::lang::type::allocSize() */
db_uint32 db_type_allocSize(db_type _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_uint32 _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "allocSize()");
    }
    db_assert(_methodId, "virtual method 'allocSize()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::allocSize()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this);
    
    return _result;
}

void __db_type_allocSize_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint32*)result = db_type_allocSize_v(
        *(db_type*)args);
}

/* virtual ::cortex::lang::type::castable(lang::type type) */
db_bool db_type_castable(db_type _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "castable(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'castable(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::castable(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_type_castable_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_type_castable_v(
        *(db_type*)args,
        *(db_type*)((intptr_t)args + sizeof(db_type)));
}

void __db_type_checkAttr(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_type_checkAttr(
        *(db_any*)args,
        *(db_attr*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_checkState(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_type_checkState(
        *(db_any*)args,
        *(db_state*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_compare(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_equalityKind*)result = db_type_compare(
        *(db_any*)args,
        *(db_any*)((intptr_t)args + sizeof(db_any)));
}

/* virtual ::cortex::lang::type::compatible(lang::type type) */
db_bool db_type_compatible(db_type _this, db_type type) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "compatible(lang::type type)");
    }
    db_assert(_methodId, "virtual method 'compatible(lang::type type)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::compatible(lang::type type)@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), &_result, _this, type);
    
    return _result;
}

void __db_type_compatible_v(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_type_compatible_v(
        *(db_type*)args,
        *(db_type*)((intptr_t)args + sizeof(db_type)));
}

void __db_type_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_type_construct(
        *(db_type*)args);
}

void __db_type_copy(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_type_copy(
        *(db_any*)args,
        *(db_any*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_declare(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_type_declare(
        *(db_any*)args,
        *(db_string*)((intptr_t)args + sizeof(db_any)),
        *(db_typedef*)((intptr_t)args + sizeof(db_any) + sizeof(db_string)));
}

void __db_type_define(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_int16*)result = db_type_define(
        *(db_any*)args);
}

void __db_type_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    db_type_destruct(
        *(db_any*)args);
}

void __db_type_fullname(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = db_type_fullname(
        *(db_any*)args);
}

/* delegate ::cortex::lang::type::init(lang::object object) */
db_int16 db_type_init(db_type _this, db_object object) {
    db_callback _callback;
    db_int16 _result;
    /* Lookup callback-object. */
    _callback = db_class_resolveCallback(db_class(db_typeof(_this)), db_type_init_o, _this);

    db_assert(_callback != NULL, "no callback 'init(lang::object object)' for object of type 'db_type' (call 'db_type_init_checkCallback' first)");

    db_call(db_function(_callback), &_result, object);
    
    return _result;
}

/* delegate ::cortex::lang::type::init(lang::object object), obtain callback */
db_bool db_type_init_hasCallback(db_type _this) {
    /* Lookup callback-object. */
    return db_class_resolveCallback(db_class(db_typeof(_this)), db_type_init_o, _this) != NULL;
}

void __db_type_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_type_init(
        *(db_type*)args,
        *(db_object*)((intptr_t)args + sizeof(db_type)));
}

void __db_type_instanceof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_bool*)result = db_type_instanceof(
        *(db_any*)args,
        *(db_typedef*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_invalidate(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    db_type_invalidate(
        *(db_any*)args);
}

void __db_type_lookup(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_type_lookup(
        *(db_any*)args,
        *(db_string*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_nameof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = db_type_nameof(
        *(db_any*)args);
}

void __db_type_parentof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_object*)result = db_type_parentof(
        *(db_any*)args);
}

void __db_type_relname(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_string*)result = db_type_relname(
        *(db_any*)args,
        *(db_object*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_resolve(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_type_resolve(
        *(db_any*)args,
        *(db_string*)((intptr_t)args + sizeof(db_any)));
}

void __db_type_resolveProcedure(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_function*)result = db_type_resolveProcedure(
        *(db_type*)args,
        *(db_string*)((intptr_t)args + sizeof(db_type)));
}

void __db_type_sizeof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_uint32*)result = db_type_sizeof(
        *(db_type*)args);
}

void __db_type_toString(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_string*)result = db_type_toString(
        *(db_any*)args);
}

void __db_type_typeof(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = db_type_typeof(
        *(db_any*)args);
}

void __db_typedef_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_typedef_construct(
        *(db_typedef*)args);
}

void __db_typedef_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_typedef_destruct(
        *(db_typedef*)args);
}

void __db_typedef_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_typedef_init(
        *(db_typedef*)args);
}

void __db_typedef_realType(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_type*)result = db_typedef_realType(
        *(db_typedef*)args);
}

void __db_uint_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_uint_init(
        *(db_uint*)args);
}

void __db_virtual_init(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = db_virtual_init(
        *(db_virtual*)args);
}
