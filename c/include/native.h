/* native.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_NATIVE__API_H
#define CORTO_NATIVE__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/native/type */
CORTO_EXPORT corto_native_type _corto_native_typeCreate(corto_string name);
#define corto_native_typeCreate(name) _corto_native_typeCreate(name)
#define corto_native_typeCreate_auto(_id, name) corto_native_type _id = corto_native_typeCreate(name); (void)_id
CORTO_EXPORT corto_native_type _corto_native_typeCreateChild(corto_object _parent, corto_string _id, corto_string name);
#define corto_native_typeCreateChild(_parent, _id, name) _corto_native_typeCreateChild(_parent, _id, name)
#define corto_native_typeCreateChild_auto(_parent, _id, name) corto_native_type _id = corto_native_typeCreateChild(_parent, #_id, name); (void)_id
CORTO_EXPORT corto_int16 _corto_native_typeUpdate(corto_native_type _this, corto_string name);
#define corto_native_typeUpdate(_this, name) _corto_native_typeUpdate(corto_native_type(_this), name)

CORTO_EXPORT corto_native_type _corto_native_typeDeclare(void);
#define corto_native_typeDeclare() _corto_native_typeDeclare()
#define corto_native_typeDeclare_auto(_id) corto_native_type _id = corto_native_typeDeclare(); (void)_id
CORTO_EXPORT corto_native_type _corto_native_typeDeclareChild(corto_object _parent, corto_string _id);
#define corto_native_typeDeclareChild(_parent, _id) _corto_native_typeDeclareChild(_parent, _id)
#define corto_native_typeDeclareChild_auto(_parent, _id) corto_native_type _id = corto_native_typeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_native_typeDefine(corto_native_type _this, corto_string name);
#define corto_native_typeDefine(_this, name) _corto_native_typeDefine(corto_native_type(_this), name)
CORTO_EXPORT corto_native_type _corto_native_typeAssign(corto_native_type _this, corto_string name);
#define corto_native_type__optional_NotSet NULL
#define corto_native_type__optional_Set(name) corto_native_typeAssign((corto_native_type*)corto_ptr_new(corto_native_type_o)), name)
#define corto_native_type__optional_SetCond(cond, name) cond ? corto_native_typeAssign((corto_native_type*)corto_ptr_new(corto_native_type_o), name) : NULL
#define corto_native_typeUnset(_this) _this ? corto_ptr_free(_this, corto_native_type_o), 0 : 0; _this = NULL;
#define corto_native_typeAssign(_this, name) _corto_native_typeAssign(_this, name)
#define corto_native_typeSet(_this, name) _this = _this ? _this : (corto_native_type*)corto_ptr_new(corto_native_type_o); _corto_native_typeAssign(_this, name)


#ifdef __cplusplus
}
#endif
#endif

