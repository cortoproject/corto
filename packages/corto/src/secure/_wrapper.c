/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/secure.
 */

#include <corto/secure/secure.h>
#include <corto/secure/_meta.h>

corto_string _corto_secure_key_authenticate(
    corto_secure_key this,
    corto_string user,
    corto_string password)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_string _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "authenticate(string user,string password)");
    }
    corto_assert(_methodId, "virtual 'authenticate(string user,string password)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::authenticate(string user,string password)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_string ___ (*)(corto_object, corto_string, corto_string))((corto_function)_method)->fptr)(this, user, password);
    } else {
        corto_call(corto_function(_method), &_result, this, user, password);
    }
    
    return _result;
}

corto_secure_accessKind _corto_secure_lock_authorize(
    corto_secure_lock this,
    corto_object object,
    corto_secure_actionKind action)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_secure_accessKind _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "authorize(object object,secure/actionKind action)");
    }
    corto_assert(_methodId, "virtual 'authorize(object object,secure/actionKind action)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::authorize(object object,secure/actionKind action)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_secure_accessKind ___ (*)(corto_object, corto_object, corto_secure_actionKind))((corto_function)_method)->fptr)(this, object, action);
    } else {
        corto_call(corto_function(_method), &_result, this, object, action);
    }
    
    return _result;
}
