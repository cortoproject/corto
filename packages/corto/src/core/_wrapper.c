/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/core.
 */

#include "corto/core/core.h"
#include "corto/core/_meta.h"

void _corto_dispatcher_post(corto_dispatcher this, corto_event e) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "post(event e)");
    }
    corto_assert(_methodId, "virtual method 'post(event e)' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::post(event e)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this, e);
}

void __corto_dispatcher_post_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_dispatcher_post_v(
        corto_dispatcher(*(void**)args),
        corto_event(*(corto_event*)((intptr_t)args + sizeof(void*))));
}

void _corto_event_handle(corto_event this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual method 'handle()' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this);
}

void __corto_event_handle_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_event_handle_v(
        corto_event(*(void**)args));
}

void __corto_event_uniqueKind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_event_uniqueKind(
        );
}

void _corto_invokeEvent_handle(corto_invokeEvent this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual method 'handle()' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this);
}

void __corto_invokeEvent_handle_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_invokeEvent_handle_v(
        corto_invokeEvent(*(void**)args));
}

void _corto_observableEvent_handle(corto_observableEvent this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual method 'handle()' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this);
}

void __corto_observableEvent_handle_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_observableEvent_handle_v(
        corto_observableEvent(*(void**)args));
}

void __corto_observer_bind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_observer_bind(
        corto_observer(*(void**)args));
}

void __corto_observer_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_observer_init(
        corto_observer(*(void**)args));
}

void __corto_observer_listen(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_observer_listen(
        corto_observer(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)),
        *(corto_object*)((intptr_t)args + sizeof(void*) + sizeof(corto_object)));
}

void __corto_observer_setDispatcher(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_observer_setDispatcher(
        corto_observer(*(void**)args),
        corto_dispatcher(*(corto_dispatcher*)((intptr_t)args + sizeof(void*))));
}

void __corto_observer_silence(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_observer_silence(
        corto_observer(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void __corto_observer_unbind(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_observer_unbind(
        corto_observer(*(corto_observer*)args));
}

void __corto_replicator_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _corto_replicator_construct(
        corto_replicator(*(void**)args));
}

void __corto_replicator_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _corto_replicator_destruct(
        corto_replicator(*(void**)args));
}

void __corto_replicator_invoke(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_invoke(
        corto_replicator(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)),
        corto_function(*(corto_function*)((intptr_t)args + sizeof(void*) + sizeof(corto_object))),
        *(corto_octetseq*)((intptr_t)args + sizeof(void*) + sizeof(corto_object) + sizeof(corto_function)));
}

void __corto_replicator_on_declare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_on_declare(
        corto_replicator(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __corto_replicator_on_delete(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_on_delete(
        corto_replicator(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __corto_replicator_on_update(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_on_update(
        corto_replicator(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void _corto_replicator_onDeclare(corto_replicator this, corto_object observable) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onDeclare(object observable)");
    }
    corto_assert(_methodId, "virtual method 'onDeclare(object observable)' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onDeclare(object observable)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this, observable);
}

void __corto_replicator_onDeclare_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_onDeclare_v(
        corto_replicator(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void _corto_replicator_onDelete(corto_replicator this, corto_object observable) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onDelete(object observable)");
    }
    corto_assert(_methodId, "virtual method 'onDelete(object observable)' not found in interface '%s' (%s)", corto_nameof(_abstract), corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onDelete(object observable)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this, observable);
}

void __corto_replicator_onDelete_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_onDelete_v(
        corto_replicator(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void _corto_replicator_onInvoke(corto_replicator this, corto_object instance, corto_function proc, corto_octetseq args) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onInvoke(object instance,function proc,octetseq args)");
    }
    corto_assert(_methodId, "virtual method 'onInvoke(object instance,function proc,octetseq args)' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onInvoke(object instance,function proc,octetseq args)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this, instance, proc, args);
}

void __corto_replicator_onInvoke_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_onInvoke_v(
        corto_replicator(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)),
        corto_function(*(corto_function*)((intptr_t)args + sizeof(void*) + sizeof(corto_object))),
        *(corto_octetseq*)((intptr_t)args + sizeof(void*) + sizeof(corto_object) + sizeof(corto_function)));
}

corto_resultIter _corto_replicator_onRequest(corto_replicator this, corto_string parent, corto_string expr, corto_bool setContent) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onRequest(string parent,string expr,bool setContent)");
    }
    corto_assert(_methodId, "virtual method 'onRequest(string parent,string expr,bool setContent)' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onRequest(string parent,string expr,bool setContent)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), &_result, this, parent, expr, setContent);

    return _result;
}

void __corto_replicator_onRequest_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_resultIter*)result = _corto_replicator_onRequest_v(
        corto_replicator(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)),
        *(corto_string*)((intptr_t)args + sizeof(void*) + sizeof(corto_string)),
        *(corto_bool*)((intptr_t)args + sizeof(void*) + sizeof(corto_string) + sizeof(corto_string)));
}

void _corto_replicator_onUpdate(corto_replicator this, corto_object observable) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onUpdate(object observable)");
    }
    corto_assert(_methodId, "virtual method 'onUpdate(object observable)' not found in interface '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onUpdate(object observable)@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this, observable);
}

void __corto_replicator_onUpdate_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_onUpdate_v(
        corto_replicator(*(void**)args),
        *(corto_object*)((intptr_t)args + sizeof(void*)));
}

void __corto_replicator_post(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _corto_replicator_post(
        corto_replicator(*(void**)args),
        corto_event(*(corto_event*)((intptr_t)args + sizeof(void*))));
}

void __corto_replicator_request(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_resultIter*)result = _corto_replicator_request(
        corto_replicator(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)),
        *(corto_string*)((intptr_t)args + sizeof(void*) + sizeof(corto_string)),
        *(corto_bool*)((intptr_t)args + sizeof(void*) + sizeof(corto_string) + sizeof(corto_string)));
}

void __corto_replicator_setContentType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _corto_replicator_setContentType(
        corto_replicator(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __corto_result_getText(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_string*)result = _corto_result_getText(
        corto_result(*(void**)args));
}
