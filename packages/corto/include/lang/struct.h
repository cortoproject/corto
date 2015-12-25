/* struct.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_STRUCT_H
#define CORTO_LANG_STRUCT_H

#include "corto/corto__interface.h"
#include "corto/lang/lang__type.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_bool _corto_struct_castable(corto_struct _this, corto_type type);
#define corto_struct_castable(_this, type) _corto_struct_castable(corto_struct(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_struct_castable_v(corto_struct _this, corto_type type);
#define corto_struct_castable_v(_this, type) _corto_struct_castable_v(corto_struct(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_struct_compatible(corto_struct _this, corto_type type);
#define corto_struct_compatible(_this, type) _corto_struct_compatible(corto_struct(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_struct_compatible_v(corto_struct _this, corto_type type);
#define corto_struct_compatible_v(_this, type) _corto_struct_compatible_v(corto_struct(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_struct_construct(corto_struct _this);
#define corto_struct_construct(_this) _corto_struct_construct(corto_struct(_this))

CORTO_EXPORT corto_int16 _corto_struct_init(corto_struct _this);
#define corto_struct_init(_this) _corto_struct_init(corto_struct(_this))

CORTO_EXPORT corto_member _corto_struct_resolveMember(corto_struct _this, corto_string name);
#define corto_struct_resolveMember(_this, name) _corto_struct_resolveMember(corto_struct(_this), name)

CORTO_EXPORT corto_member _corto_struct_resolveMember_v(corto_struct _this, corto_string name);
#define corto_struct_resolveMember_v(_this, name) _corto_struct_resolveMember_v(corto_struct(_this), name)

#ifdef __cplusplus
}
#endif
#endif
