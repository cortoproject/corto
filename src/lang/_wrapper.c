/* _wrapper.c
 *
 * This file contains wrapper functions for /corto/lang.
 */

#include <corto/lang/lang.h>
#include <corto/lang/_load.h>
bool _corto_collection_castable(
    corto_collection _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_collection_compatible(
    corto_collection _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_delegate_castable(
    corto_delegate _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_delegate_compatible(
    corto_delegate _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_interface_compatible(
    corto_interface _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
corto_member _corto_interface_resolveMember(
    corto_interface _this,
    const char *name)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "method 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_member ___ (*)(corto_object, const char *))((corto_function)_method)->fptr)(_this, name);
    } else {
        corto_call(corto_function(_method), &_result, _this, name);
    }
    
    return _result;
}
bool _corto_iterator_castable(
    corto_iterator _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_iterator_compatible(
    corto_iterator _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_primitive_castable(
    corto_primitive _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_primitive_compatible(
    corto_primitive _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_struct_castable(
    corto_struct _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_struct_compatible(
    corto_struct _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
corto_member _corto_struct_resolveMember(
    corto_struct _this,
    const char *name)

{
    static corto_uint32 _methodId;
    corto_method _method;
    corto_member _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "resolveMember(string name)");
    }
    corto_assert(_methodId, "method 'resolveMember(string name)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::resolveMember(string name)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((corto_member ___ (*)(corto_object, const char *))((corto_function)_method)->fptr)(_this, name);
    } else {
        corto_call(corto_function(_method), &_result, _this, name);
    }
    
    return _result;
}
bool _corto_type_castable(
    corto_type _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "castable(type type)");
    }
    corto_assert(_methodId, "method 'castable(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::castable(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
bool _corto_type_compatible(
    corto_type _this,
    corto_type type)

{
    static corto_uint32 _methodId;
    corto_method _method;
    bool _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "compatible(type type)");
    }
    corto_assert(_methodId, "method 'compatible(type type)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::compatible(type type)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        _result = ((bool ___ (*)(corto_object, corto_type))((corto_function)_method)->fptr)(_this, type);
    } else {
        corto_call(corto_function(_method), &_result, _this, type);
    }
    
    return _result;
}
