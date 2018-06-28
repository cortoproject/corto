/* _interface.c
 *
 * This file contains interface methods for /corto/vstore.
 */

#include <corto/corto.h>
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
        _methodId = corto_interface_resolve_method_id(corto_dispatcher_o, "post(event e)");
    }
    corto_assert(_methodId, "method 'post(event e)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr() ? ": " : "", corto_lasterr() ? corto_lasterr() : "");

    /* Lookup method-object. */
    _method = corto_class_resolveInterfaceMethod((corto_class)_abstract, corto_dispatcher_o, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::post(event e)@%d'", corto_idof(_this), _methodId);

    if (corto_function(_method)->kind == CORTO_PROCEDURE_CDECL) {
        ((void ___ (*)(corto_object, corto_event *))((corto_function)_method)->fptr)(_this, e);
    } else {
        corto_invoke(corto_function(_method), NULL, _this, e);
    }
}
