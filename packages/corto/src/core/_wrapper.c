/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/core.
 */

#include <corto/core/core.h>
#include <corto/core/_load.h>
void _corto_dispatcher_post(
    corto_dispatcher _this,
    corto_event *e)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "post(event e)");
    }
    corto_assert(_methodId, "virtual 'post(event e)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::post(event e)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_event*))((corto_function)_method)->fptr)(_this, e);
    } else {
        corto_call(corto_function(_method), NULL, _this, e);
    }
}
void _corto_invokeEvent_handle(
    corto_invokeEvent _this)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "handle()");
    }
    corto_assert(_methodId, "virtual 'handle()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::handle()@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(_this);
    } else {
        corto_call(corto_function(_method), NULL, _this);
    }
}
corto_resultIter _corto_loader_onQuery(
    corto_loader _this,
    corto_query *query)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onQuery(/corto/core/query query)");
    }
    corto_assert(_methodId, "virtual 'onQuery(/corto/core/query query)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onQuery(/corto/core/query query)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_query*))((corto_function)_method)->fptr)(_this, query);
    } else {
        corto_call(corto_function(_method), &_result, _this, query);
    }
    
    return _result;
}
corto_string _corto_mount_onId(
    corto_mount _this)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_string _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onId()");
    }
    corto_assert(_methodId, "virtual 'onId()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onId()@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_string ___ (*)(corto_object))((corto_function)_method)->fptr)(_this);
    } else {
        corto_call(corto_function(_method), &_result, _this);
    }
    
    return _result;
}
void _corto_mount_onInvoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onInvoke(object instance,function proc,word argptrs)");
    }
    corto_assert(_methodId, "virtual 'onInvoke(object instance,function proc,word argptrs)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onInvoke(object instance,function proc,word argptrs)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_object, corto_function, corto_word))((corto_function)_method)->fptr)(_this, instance, proc, argptrs);
    } else {
        corto_call(corto_function(_method), NULL, _this, instance, proc, argptrs);
    }
}
void _corto_mount_onNotify(
    corto_mount _this,
    corto_subscriberEvent *event)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onNotify(core/subscriberEvent event)");
    }
    corto_assert(_methodId, "virtual 'onNotify(core/subscriberEvent event)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onNotify(core/subscriberEvent event)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_subscriberEvent*))((corto_function)_method)->fptr)(_this, event);
    } else {
        corto_call(corto_function(_method), NULL, _this, event);
    }
}
void _corto_mount_onNotifyBatch(
    corto_mount _this,
    corto_subscriberEventIter data)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onNotifyBatch(core/subscriberEventIter data)");
    }
    corto_assert(_methodId, "virtual 'onNotifyBatch(core/subscriberEventIter data)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onNotifyBatch(core/subscriberEventIter data)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_subscriberEventIter))((corto_function)_method)->fptr)(_this, data);
    } else {
        corto_call(corto_function(_method), NULL, _this, data);
    }
}
void _corto_mount_onPoll(
    corto_mount _this)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onPoll()");
    }
    corto_assert(_methodId, "virtual 'onPoll()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onPoll()@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object))((corto_function)_method)->fptr)(_this);
    } else {
        corto_call(corto_function(_method), NULL, _this);
    }
}
corto_resultIter _corto_mount_onQuery(
    corto_mount _this,
    corto_query *query)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onQuery(/corto/core/query query)");
    }
    corto_assert(_methodId, "virtual 'onQuery(/corto/core/query query)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onQuery(/corto/core/query query)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_query*))((corto_function)_method)->fptr)(_this, query);
    } else {
        corto_call(corto_function(_method), &_result, _this, query);
    }
    
    return _result;
}
corto_resultIter _corto_mount_onQueryHistorical(
    corto_mount _this,
    corto_query *query)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_resultIter _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onQueryHistorical(/corto/core/query query)");
    }
    corto_assert(_methodId, "virtual 'onQueryHistorical(/corto/core/query query)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onQueryHistorical(/corto/core/query query)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_resultIter ___ (*)(corto_object, corto_query*))((corto_function)_method)->fptr)(_this, query);
    } else {
        corto_call(corto_function(_method), &_result, _this, query);
    }
    
    return _result;
}
corto_object _corto_mount_onResume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object object)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onResume(string parent,string name,object object)");
    }
    corto_assert(_methodId, "virtual 'onResume(string parent,string name,object object)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onResume(string parent,string name,object object)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_object ___ (*)(corto_object, corto_string, corto_string, corto_object))((corto_function)_method)->fptr)(_this, parent, name, object);
    } else {
        corto_call(corto_function(_method), &_result, _this, parent, name, object);
    }
    
    return _result;
}
uintptr_t _corto_mount_onSubscribe(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx)

{
    static corto_uint32 _methodId;
    corto_method _method;
    uintptr_t _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onSubscribe(core/query query,lang/word ctx)");
    }
    corto_assert(_methodId, "virtual 'onSubscribe(core/query query,lang/word ctx)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onSubscribe(core/query query,lang/word ctx)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((uintptr_t ___ (*)(corto_object, corto_query*, corto_word))((corto_function)_method)->fptr)(_this, query, ctx);
    } else {
        corto_call(corto_function(_method), &_result, _this, query, ctx);
    }
    
    return _result;
}
uintptr_t _corto_mount_onTransactionBegin(
    corto_mount _this)

{
    static corto_uint32 _methodId;
    corto_method _method;
    uintptr_t _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onTransactionBegin()");
    }
    corto_assert(_methodId, "virtual 'onTransactionBegin()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onTransactionBegin()@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((uintptr_t ___ (*)(corto_object))((corto_function)_method)->fptr)(_this);
    } else {
        corto_call(corto_function(_method), &_result, _this);
    }
    
    return _result;
}
void _corto_mount_onTransactionEnd(
    corto_mount _this,
    corto_subscriberEventIter events,
    uintptr_t ctx)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onTransactionEnd(core/subscriberEventIter events,word ctx)");
    }
    corto_assert(_methodId, "virtual 'onTransactionEnd(core/subscriberEventIter events,word ctx)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onTransactionEnd(core/subscriberEventIter events,word ctx)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_subscriberEventIter, corto_word))((corto_function)_method)->fptr)(_this, events, ctx);
    } else {
        corto_call(corto_function(_method), NULL, _this, events, ctx);
    }
}
void _corto_mount_onUnsubscribe(
    corto_mount _this,
    corto_query *query,
    uintptr_t ctx)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "onUnsubscribe(core/query query,lang/word ctx)");
    }
    corto_assert(_methodId, "virtual 'onUnsubscribe(core/query query,lang/word ctx)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::onUnsubscribe(core/query query,lang/word ctx)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_query*, corto_word))((corto_function)_method)->fptr)(_this, query, ctx);
    } else {
        corto_call(corto_function(_method), NULL, _this, query, ctx);
    }
}
corto_route _corto_routerimpl_findRoute(
    corto_routerimpl _this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_route _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "findRoute(object instance,stringseq pattern,any param,out:any routerData)");
    }
    corto_assert(_methodId, "virtual 'findRoute(object instance,stringseq pattern,any param,out:any routerData)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::findRoute(object instance,stringseq pattern,any param,out:any routerData)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_route ___ (*)(corto_object, corto_object, corto_stringseq, corto_any, corto_any*))((corto_function)_method)->fptr)(_this, instance, pattern, param, routerData);
    } else {
        corto_call(corto_function(_method), &_result, _this, instance, pattern, param, routerData);
    }
    
    return _result;
}
int32_t _corto_routerimpl_matchRoute(
    corto_routerimpl _this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)

{
    static corto_uint32 _methodId;
    corto_method _method;
    int32_t _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "matchRoute(core/route route,stringseq pattern,any param,out:any routerData)");
    }
    corto_assert(_methodId, "virtual 'matchRoute(core/route route,stringseq pattern,any param,out:any routerData)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::matchRoute(core/route route,stringseq pattern,any param,out:any routerData)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((int32_t ___ (*)(corto_object, corto_route, corto_stringseq, corto_any, corto_any*))((corto_function)_method)->fptr)(_this, route, pattern, param, routerData);
    } else {
        corto_call(corto_function(_method), &_result, _this, route, pattern, param, routerData);
    }
    
    return _result;
}
