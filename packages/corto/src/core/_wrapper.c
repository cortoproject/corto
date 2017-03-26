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
        _methodId = corto_interface_resolveMethodId(_abstract, "onRequest(/corto/core/request request)");
    }
    corto_assert(_methodId, "virtual 'onRequest(/corto/core/request request)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onRequest(/corto/core/request request)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_request*))((corto_function)_method)->fptr)(this, request);
    } else {
        corto_call(corto_function(_method), &_result, this, request);
    }
    
    return _result;
}

corto_string _corto_mount_onId(
    corto_mount this)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_string _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onId()");
    }
    corto_assert(_methodId, "virtual 'onId()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onId()@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_string ___ (*)(corto_object))((corto_function)_method)->fptr)(this);
    } else {
        corto_call(corto_function(_method), &_result, this);
    }
    
    return _result;
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
        _methodId = corto_interface_resolveMethodId(_abstract, "onRequest(/corto/core/request request)");
    }
    corto_assert(_methodId, "virtual 'onRequest(/corto/core/request request)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onRequest(/corto/core/request request)@%d'", corto_idof(this), _methodId);

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
    corto_string expr,
    corto_word ctx)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_word _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onSubscribe(string parent,string expr,lang/word ctx)");
    }
    corto_assert(_methodId, "virtual 'onSubscribe(string parent,string expr,lang/word ctx)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onSubscribe(string parent,string expr,lang/word ctx)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_word ___ (*)(corto_object, corto_string, corto_string, corto_word))((corto_function)_method)->fptr)(this, parent, expr, ctx);
    } else {
        corto_call(corto_function(_method), &_result, this, parent, expr, ctx);
    }
    
    return _result;
}

corto_void _corto_mount_onUnsubscribe(
    corto_mount this,
    corto_string parent,
    corto_string expr,
    corto_word ctx)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onUnsubscribe(string parent,string expr,lang/word ctx)");
    }
    corto_assert(_methodId, "virtual 'onUnsubscribe(string parent,string expr,lang/word ctx)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onUnsubscribe(string parent,string expr,lang/word ctx)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_string, corto_string, corto_word))((corto_function)_method)->fptr)(this, parent, expr, ctx);
    } else {
        corto_call(corto_function(_method), NULL, this, parent, expr, ctx);
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

corto_route _corto_routerimpl_findRoute(
    corto_routerimpl this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_route _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "findRoute(object instance,stringseq pattern,any param,out:any routerData)");
    }
    corto_assert(_methodId, "virtual 'findRoute(object instance,stringseq pattern,any param,out:any routerData)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::findRoute(object instance,stringseq pattern,any param,out:any routerData)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_route ___ (*)(corto_object, corto_object, corto_stringseq, corto_any, corto_any*))((corto_function)_method)->fptr)(this, instance, pattern, param, routerData);
    } else {
        corto_call(corto_function(_method), &_result, this, instance, pattern, param, routerData);
    }
    
    return _result;
}

corto_int32 _corto_routerimpl_matchRoute(
    corto_routerimpl this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_int32 _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "matchRoute(core/route route,stringseq pattern,any param,out:any routerData)");
    }
    corto_assert(_methodId, "virtual 'matchRoute(core/route route,stringseq pattern,any param,out:any routerData)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::matchRoute(core/route route,stringseq pattern,any param,out:any routerData)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_int32 ___ (*)(corto_object, corto_route, corto_stringseq, corto_any, corto_any*))((corto_function)_method)->fptr)(this, route, pattern, param, routerData);
    } else {
        corto_call(corto_function(_method), &_result, this, route, pattern, param, routerData);
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
