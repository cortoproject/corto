/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/lang.
 */

#include <corto/lang/lang.h>
#include <corto/lang/_load.h>

bool _corto_collection_castable(
    corto_collection this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_collection_compatible(
    corto_collection this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_delegate_castable(
    corto_delegate this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_delegate_compatible(
    corto_delegate this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_interface_compatible(
    corto_interface this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

corto_member _corto_interface_resolveMember(
    corto_interface this,
    corto_string name)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "virtual 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_member ___ (*)(corto_object, corto_string))((corto_function)_method)->fptr)(this, name);
    } else {
        corto_call(corto_function(_method), &_result, this, name);
    }
    
    return _result;
}

bool _corto_iterator_castable(
    corto_iterator this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_iterator_compatible(
    corto_iterator this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_primitive_castable(
    corto_primitive this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_primitive_compatible(
    corto_primitive this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_struct_castable(
    corto_struct this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_struct_compatible(
    corto_struct this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

corto_member _corto_struct_resolveMember(
    corto_struct this,
    corto_string name)
{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "virtual 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_member ___ (*)(corto_object, corto_string))((corto_function)_method)->fptr)(this, name);
    } else {
        corto_call(corto_function(_method), &_result, this, name);
    }
    
    return _result;
}

bool _corto_type_castable(
    corto_type this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "virtual 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}

bool _corto_type_compatible(
    corto_type this,
    corto_type type)
{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "virtual 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(this, type);
    } else {
        corto_call(corto_function(_method), &_result, this, type);
    }
    
    return _result;
}
