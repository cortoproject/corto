/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_NATIVE__API_H
#define CORTO_NATIVE__API_H

#include <corto/corto.h>
#include <corto/_interface.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/native/type */
CORTO_EXPORT corto_native_type _corto_native_typeCreate(corto_string name);
#define corto_native_typeCreate(name) _corto_native_typeCreate(name)
#define corto_native_typeCreate_auto(_name, name) corto_native_type _name = corto_native_typeCreate(name); (void)_name
CORTO_EXPORT corto_native_type _corto_native_typeCreateChild(corto_object _parent, corto_string _name, corto_string name);
#define corto_native_typeCreateChild(_parent, _name, name) _corto_native_typeCreateChild(_parent, _name, name)
#define corto_native_typeCreateChild_auto(_parent, _name, name) corto_native_type _name = corto_native_typeCreateChild(_parent, #_name, name); (void)_name
CORTO_EXPORT corto_int16 _corto_native_typeUpdate(corto_native_type _this, corto_string name);
#define corto_native_typeUpdate(_this, name) _corto_native_typeUpdate(corto_native_type(_this), name)

CORTO_EXPORT corto_native_type _corto_native_typeDeclare(void);
#define corto_native_typeDeclare() _corto_native_typeDeclare()
#define corto_native_typeDeclare_auto(_name) corto_native_type _name = corto_native_typeDeclare(); (void)_name
CORTO_EXPORT corto_native_type _corto_native_typeDeclareChild(corto_object _parent, corto_string _name);
#define corto_native_typeDeclareChild(_parent, _name) _corto_native_typeDeclareChild(_parent, _name)
#define corto_native_typeDeclareChild_auto(_parent, _name) corto_native_type _name = corto_native_typeDeclareChild(_parent, #_name); (void)_name
CORTO_EXPORT corto_int16 _corto_native_typeDefine(corto_native_type _this, corto_string name);
#define corto_native_typeDefine(_this, name) _corto_native_typeDefine(corto_native_type(_this), name)
CORTO_EXPORT corto_native_type _corto_native_typeAssign(corto_native_type _this, corto_string name);
#define corto_native_type__optional_NotSet NULL
#define corto_native_type__optional_Set(name) corto_native_typeAssign(corto_alloc(sizeof(corto_native_type)), name)
#define corto_native_typeUnset(_this) _this ? corto_deinitp(_this, corto_native_type_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_native_typeAssign(_this, name) _corto_native_typeAssign(corto_native_type(_this), name)
#define corto_native_typeSet(_this, name) _this = _this ? _this : corto_alloc(sizeof(corto_native_type_o)); _corto_native_typeAssign(corto_native_type(_this), name)
CORTO_EXPORT corto_string _corto_native_typeStr(corto_native_type value);
#define corto_native_typeStr(value) _corto_native_typeStr(corto_native_type(value))
CORTO_EXPORT corto_native_type corto_native_typeFromStr(corto_native_type value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_native_typeCompare(corto_native_type dst, corto_native_type src);
#define corto_native_typeCompare(dst, src) _corto_native_typeCompare(corto_native_type(dst), corto_native_type(src))


#ifdef __cplusplus
}
#endif
#endif

