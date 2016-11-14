/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/core.
 */

#include <corto/core/core.h>
#include <corto/core/_load.h>

corto_void _corto_dispatcher_post(
    corto_dispatcher this,
    corto_event e)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "post(event e)");
    }
    corto_assert(_methodId, "virtual 'post(event e)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::post(event e)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_event))((corto_function)_method)->fptr)(this, e);
    } else {
        corto_call(corto_function(_method), NULL, this, e);
    }
}

corto_void _corto_event_handle(
    corto_event this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual 'handle()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), NULL, this);
    }
}

corto_void _corto_invokeEvent_handle(
    corto_invokeEvent this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual 'handle()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), NULL, this);
    }
}

corto_void _corto_loader_onDeclare(
    corto_loader this,
    corto_object observable)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onDeclare(object observable)");
    }
    corto_assert(_methodId, "virtual 'onDeclare(object observable)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onDeclare(object observable)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object))((corto_function)_method)->fptr)(this, observable);
    } else {
        corto_call(corto_function(_method), NULL, this, observable);
    }
}

corto_resultIter _corto_loader_onRequest(
    corto_loader this,
    corto_request *request)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onRequest(core/request request)");
    }
    corto_assert(_methodId, "virtual 'onRequest(core/request request)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onRequest(core/request request)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_request*))((corto_function)_method)->fptr)(this, request);
    } else {
        corto_call(corto_function(_method), &_result, this, request);
    }
    
    return _result;
}

corto_object _corto_loader_onResume(
    corto_loader this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onResume(string parent,string name,object o)");
    }
    corto_assert(_methodId, "virtual 'onResume(string parent,string name,object o)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onResume(string parent,string name,object o)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_object ___ (*)(corto_object, corto_string, corto_string, corto_object))((corto_function)_method)->fptr)(this, parent, name, o);
    } else {
        corto_call(corto_function(_method), &_result, this, parent, name, o);
    }
    
    return _result;
}

corto_void _corto_mount_onDeclare(
    corto_mount this,
    corto_object observable)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onDeclare(object observable)");
    }
    corto_assert(_methodId, "virtual 'onDeclare(object observable)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onDeclare(object observable)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object))((corto_function)_method)->fptr)(this, observable);
    } else {
        corto_call(corto_function(_method), NULL, this, observable);
    }
}

corto_void _corto_mount_onDelete(
    corto_mount this,
    corto_object observable)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onDelete(object observable)");
    }
    corto_assert(_methodId, "virtual 'onDelete(object observable)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onDelete(object observable)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object))((corto_function)_method)->fptr)(this, observable);
    } else {
        corto_call(corto_function(_method), NULL, this, observable);
    }
}

corto_void _corto_mount_onInvoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onInvoke(object instance,function proc,word argptrs)");
    }
    corto_assert(_methodId, "virtual 'onInvoke(object instance,function proc,word argptrs)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onInvoke(object instance,function proc,word argptrs)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object, corto_function, corto_word))((corto_function)_method)->fptr)(this, instance, proc, argptrs);
    } else {
        corto_call(corto_function(_method), NULL, this, instance, proc, argptrs);
    }
}

corto_void _corto_mount_onNotify(
    corto_mount this,
    corto_eventMask event,
    corto_result *object)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onNotify(core/eventMask event,core/result object)");
    }
    corto_assert(_methodId, "virtual 'onNotify(core/eventMask event,core/result object)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onNotify(core/eventMask event,core/result object)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_eventMask, corto_result*))((corto_function)_method)->fptr)(this, event, object);
    } else {
        corto_call(corto_function(_method), NULL, this, event, object);
    }
}

corto_void _corto_mount_onPoll(
    corto_mount this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onPoll()");
    }
    corto_assert(_methodId, "virtual 'onPoll()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onPoll()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), NULL, this);
    }
}

corto_resultIter _corto_mount_onRequest(
    corto_mount this,
    corto_request *request)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onRequest(core/request request)");
    }
    corto_assert(_methodId, "virtual 'onRequest(core/request request)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onRequest(core/request request)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_request*))((corto_function)_method)->fptr)(this, request);
    } else {
        corto_call(corto_function(_method), &_result, this, request);
    }
    
    return _result;
}

corto_object _corto_mount_onResume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onResume(string parent,string name,object o)");
    }
    corto_assert(_methodId, "virtual 'onResume(string parent,string name,object o)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onResume(string parent,string name,object o)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_object ___ (*)(corto_object, corto_string, corto_string, corto_object))((corto_function)_method)->fptr)(this, parent, name, o);
    } else {
        corto_call(corto_function(_method), &_result, this, parent, name, o);
    }
    
    return _result;
}

corto_word _corto_mount_onSubscribe(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_word _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onSubscribe(string parent,string name,core/eventMask mask)");
    }
    corto_assert(_methodId, "virtual 'onSubscribe(string parent,string name,core/eventMask mask)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onSubscribe(string parent,string name,core/eventMask mask)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_word ___ (*)(corto_object, corto_string, corto_string, corto_eventMask))((corto_function)_method)->fptr)(this, parent, name, mask);
    } else {
        corto_call(corto_function(_method), &_result, this, parent, name, mask);
    }
    
    return _result;
}

corto_void _corto_mount_onUnsubscribe(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask,
    corto_word userData)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onUnsubscribe(string parent,string name,core/eventMask mask,lang/word userData)");
    }
    corto_assert(_methodId, "virtual 'onUnsubscribe(string parent,string name,core/eventMask mask,lang/word userData)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onUnsubscribe(string parent,string name,core/eventMask mask,lang/word userData)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_string, corto_string, corto_eventMask, corto_word))((corto_function)_method)->fptr)(this, parent, name, mask, userData);
    } else {
        corto_call(corto_function(_method), NULL, this, parent, name, mask, userData);
    }
}

corto_void _corto_mount_onUpdate(
    corto_mount this,
    corto_object observable)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onUpdate(object observable)");
    }
    corto_assert(_methodId, "virtual 'onUpdate(object observable)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onUpdate(object observable)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object))((corto_function)_method)->fptr)(this, observable);
    } else {
        corto_call(corto_function(_method), NULL, this, observable);
    }
}

corto_void _corto_observableEvent_handle(
    corto_observableEvent this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual 'handle()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), NULL, this);
    }
}

corto_int32 _corto_routerimpl_matchRoute(
    corto_routerimpl this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_int32 _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "matchRoute(core/route route,stringseq pattern,any param)");
    }
    corto_assert(_methodId, "virtual 'matchRoute(core/route route,stringseq pattern,any param)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::matchRoute(core/route route,stringseq pattern,any param)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_int32 ___ (*)(corto_object, corto_route, corto_stringseq, corto_any))((corto_function)_method)->fptr)(this, route, pattern, param);
    } else {
        corto_call(corto_function(_method), &_result, this, route, pattern, param);
    }
    
    return _result;
}

corto_void _corto_subscriberEvent_handle(
    corto_subscriberEvent this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual 'handle()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), NULL, this);
    }
}
