/* corto_interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_INTERFACE_H
#define CORTO_LANG_INTERFACE_H

#include "corto.h"
#include "corto_type.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_LANG_EXPORT corto_int16 _corto_interface_baseof(corto_interface _this, corto_interface type);
#define corto_interface_baseof(_this, type) _corto_interface_baseof(corto_interface(_this), corto_interface(type))

CORTO_LANG_EXPORT corto_int16 _corto_interface_bindMethod(corto_interface _this, corto_method method);
#define corto_interface_bindMethod(_this, method) _corto_interface_bindMethod(corto_interface(_this), corto_method(method))

/* virtual /corto/lang/interface/compatible(type type) */
CORTO_LANG_EXPORT corto_bool _corto_interface_compatible(corto_interface _this, corto_type type);
#define corto_interface_compatible(_this, type) _corto_interface_compatible(corto_interface(_this), corto_type(type))

CORTO_LANG_EXPORT corto_bool _corto_interface_compatible_v(corto_interface _this, corto_type type);
#define corto_interface_compatible_v(_this, type) _corto_interface_compatible_v(corto_interface(_this), corto_type(type))

CORTO_LANG_EXPORT corto_int16 _corto_interface_construct(corto_interface _this);
#define corto_interface_construct(_this) _corto_interface_construct(corto_interface(_this))

CORTO_LANG_EXPORT corto_void _corto_interface_destruct(corto_interface _this);
#define corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))

CORTO_LANG_EXPORT corto_int16 _corto_interface_init(corto_interface _this);
#define corto_interface_init(_this) _corto_interface_init(corto_interface(_this))

/* virtual /corto/lang/interface/resolveMember(string name) */
CORTO_LANG_EXPORT corto_member _corto_interface_resolveMember(corto_interface _this, corto_string name);
#define corto_interface_resolveMember(_this, name) _corto_interface_resolveMember(corto_interface(_this), name)

CORTO_LANG_EXPORT corto_member _corto_interface_resolveMember_v(corto_interface _this, corto_string name);
#define corto_interface_resolveMember_v(_this, name) _corto_interface_resolveMember_v(corto_interface(_this), name)

CORTO_LANG_EXPORT corto_method _corto_interface_resolveMethod(corto_interface _this, corto_string name);
#define corto_interface_resolveMethod(_this, name) _corto_interface_resolveMethod(corto_interface(_this), name)

CORTO_LANG_EXPORT corto_method _corto_interface_resolveMethodById(corto_interface _this, corto_uint32 id);
#define corto_interface_resolveMethodById(_this, id) _corto_interface_resolveMethodById(corto_interface(_this), id)

CORTO_LANG_EXPORT corto_uint32 _corto_interface_resolveMethodId(corto_interface _this, corto_string name);
#define corto_interface_resolveMethodId(_this, name) _corto_interface_resolveMethodId(corto_interface(_this), name)

#ifdef __cplusplus
}
#endif
#endif

