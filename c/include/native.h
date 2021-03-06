/* native.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_NATIVE__API_H
#define CORTO_NATIVE__API_H

#ifdef __cplusplus
extern "C" {
#endif

/* /corto/native/type */
CORTO_C_EXPORT corto_native_type _corto_native_type__create(corto_object _parent, const char *_id, const char * name, bool is_ptr);
#define corto_native_type__create(_parent, _id, name, is_ptr) _corto_native_type__create(_parent, _id, name, is_ptr)
#define corto_native_type__create_auto(_parent, _id, name, is_ptr) corto_native_type _id = corto_native_type__create(_parent, #_id, name, is_ptr); (void)_id
#define corto_native_type__declare(parent, id) (corto_native_type)corto_declare(parent, id, corto_native_type_o)
CORTO_C_EXPORT corto_int16 _corto_native_type__update(corto_native_type _this, const char * name, bool is_ptr);
#define corto_native_type__update(_this, name, is_ptr) _corto_native_type__update(corto_native_type(_this), name, is_ptr)
CORTO_C_EXPORT corto_native_type _corto_native_type__assign(corto_native_type _this, const char * name, bool is_ptr);
#define corto_native_type__optional_not_set NULL
#define corto_native_type__optional_set(name, is_ptr) (corto_native_type*)corto_native_type__assign((corto_native_type*)corto_ptr_new(corto_native_type_o), name, is_ptr)
#define corto_native_type__optional_set_cond(__cond, name, is_ptr) __cond ? (corto_native_type*)corto_native_type__assign((corto_native_type*)corto_ptr_new(corto_native_type_o), name, is_ptr) : NULL
#define corto_native_type__unset(_this) _this ? corto_ptr_free(_this, corto_native_type_o), 0 : 0; _this = NULL;
#define corto_native_type__assign(_this, name, is_ptr) _corto_native_type__assign(_this, name, is_ptr)
#define corto_native_type__set(_this, name, is_ptr) _this = _this ? _this : (corto_native_type*)corto_ptr_new(corto_native_type_o); _corto_native_type__assign(_this, name, is_ptr)


#ifdef __cplusplus
}
#endif
#endif
