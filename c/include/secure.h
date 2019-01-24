/* secure.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE__API_H
#define CORTO_SECURE__API_H

#ifdef __cplusplus
extern "C" {
#endif

/* /corto/secure/accessKind */
CORTO_C_EXPORT corto_secure_accessKind* _corto_secure_accessKind__create(corto_object _parent, const char *_id, corto_secure_accessKind value);
#define corto_secure_accessKind__create(_parent, _id, value) _corto_secure_accessKind__create(_parent, _id, value)
#define corto_secure_accessKind__create_auto(_parent, _id, value) corto_secure_accessKind* _id = corto_secure_accessKind__create(_parent, #_id, value); (void)_id
#define corto_secure_accessKind__declare(parent, id) (corto_secure_accessKind*)corto_declare(parent, id, corto_secure_accessKind_o)
CORTO_C_EXPORT corto_int16 _corto_secure_accessKind__update(corto_secure_accessKind* _this, corto_secure_accessKind value);
#define corto_secure_accessKind__update(_this, value) _corto_secure_accessKind__update(corto_secure_accessKind(_this), value)
CORTO_C_EXPORT corto_secure_accessKind* _corto_secure_accessKind__assign(corto_secure_accessKind* _this, corto_secure_accessKind value);
#define corto_secure_accessKind__optional_not_set NULL
#define corto_secure_accessKind__optional_set(value) (corto_secure_accessKind*)corto_secure_accessKind__assign((corto_secure_accessKind*)corto_ptr_new(corto_secure_accessKind_o), value)
#define corto_secure_accessKind__optional_set_cond(__cond, value) __cond ? (corto_secure_accessKind*)corto_secure_accessKind__assign((corto_secure_accessKind*)corto_ptr_new(corto_secure_accessKind_o), value) : NULL
#define corto_secure_accessKind__unset(_this) _this ? corto_ptr_free(_this, corto_secure_accessKind_o), 0 : 0; _this = NULL;
#define corto_secure_accessKind__assign(_this, value) _corto_secure_accessKind__assign(_this, value)
#define corto_secure_accessKind__set(_this, value) _this = _this ? _this : (corto_secure_accessKind*)corto_ptr_new(corto_secure_accessKind_o); _corto_secure_accessKind__assign(_this, value)

/* /corto/secure/actionKind */
CORTO_C_EXPORT corto_secure_actionKind* _corto_secure_actionKind__create(corto_object _parent, const char *_id, corto_secure_actionKind value);
#define corto_secure_actionKind__create(_parent, _id, value) _corto_secure_actionKind__create(_parent, _id, value)
#define corto_secure_actionKind__create_auto(_parent, _id, value) corto_secure_actionKind* _id = corto_secure_actionKind__create(_parent, #_id, value); (void)_id
#define corto_secure_actionKind__declare(parent, id) (corto_secure_actionKind*)corto_declare(parent, id, corto_secure_actionKind_o)
CORTO_C_EXPORT corto_int16 _corto_secure_actionKind__update(corto_secure_actionKind* _this, corto_secure_actionKind value);
#define corto_secure_actionKind__update(_this, value) _corto_secure_actionKind__update(corto_secure_actionKind(_this), value)
CORTO_C_EXPORT corto_secure_actionKind* _corto_secure_actionKind__assign(corto_secure_actionKind* _this, corto_secure_actionKind value);
#define corto_secure_actionKind__optional_not_set NULL
#define corto_secure_actionKind__optional_set(value) (corto_secure_actionKind*)corto_secure_actionKind__assign((corto_secure_actionKind*)corto_ptr_new(corto_secure_actionKind_o), value)
#define corto_secure_actionKind__optional_set_cond(__cond, value) __cond ? (corto_secure_actionKind*)corto_secure_actionKind__assign((corto_secure_actionKind*)corto_ptr_new(corto_secure_actionKind_o), value) : NULL
#define corto_secure_actionKind__unset(_this) _this ? corto_ptr_free(_this, corto_secure_actionKind_o), 0 : 0; _this = NULL;
#define corto_secure_actionKind__assign(_this, value) _corto_secure_actionKind__assign(_this, value)
#define corto_secure_actionKind__set(_this, value) _this = _this ? _this : (corto_secure_actionKind*)corto_ptr_new(corto_secure_actionKind_o); _corto_secure_actionKind__assign(_this, value)

/* /corto/secure/key */
CORTO_C_EXPORT corto_secure_key _corto_secure_key__create(corto_object _parent, const char *_id);
#define corto_secure_key__create(_parent, _id) _corto_secure_key__create(_parent, _id)
#define corto_secure_key__create_auto(_parent, _id) corto_secure_key _id = corto_secure_key__create(_parent, #_id); (void)_id
#define corto_secure_key__declare(parent, id) (corto_secure_key)corto_declare(parent, id, corto_secure_key_o)
CORTO_C_EXPORT corto_int16 _corto_secure_key__update(corto_secure_key _this);
#define corto_secure_key__update(_this) _corto_secure_key__update(corto_secure_key(_this))
CORTO_C_EXPORT corto_secure_key _corto_secure_key__assign(corto_secure_key _this);
#define corto_secure_key__optional_not_set NULL
#define corto_secure_key__optional_set() (corto_secure_key*)corto_secure_key__assign((corto_secure_key*)corto_ptr_new(corto_secure_key_o))
#define corto_secure_key__optional_set_cond(__cond) __cond ? (corto_secure_key*)corto_secure_key__assign((corto_secure_key*)corto_ptr_new(corto_secure_key_o)) : NULL
#define corto_secure_key__unset(_this) _this ? corto_ptr_free(_this, corto_secure_key_o), 0 : 0; _this = NULL;
#define corto_secure_key__assign(_this) _corto_secure_key__assign(_this)
#define corto_secure_key__set(_this) _this = _this ? _this : (corto_secure_key*)corto_ptr_new(corto_secure_key_o); _corto_secure_key__assign(_this)

/* /corto/secure/lock */
CORTO_C_EXPORT corto_secure_lock _corto_secure_lock__create(corto_object _parent, const char *_id, corto_query* query, int16_t priority);
#define corto_secure_lock__create(_parent, _id, query, priority) _corto_secure_lock__create(_parent, _id, query, priority)
#define corto_secure_lock__create_auto(_parent, _id, query, priority) corto_secure_lock _id = corto_secure_lock__create(_parent, #_id, query, priority); (void)_id
#define corto_secure_lock__declare(parent, id) (corto_secure_lock)corto_declare(parent, id, corto_secure_lock_o)
CORTO_C_EXPORT corto_int16 _corto_secure_lock__update(corto_secure_lock _this, corto_query* query, int16_t priority);
#define corto_secure_lock__update(_this, query, priority) _corto_secure_lock__update(corto_secure_lock(_this), query, priority)
CORTO_C_EXPORT corto_secure_lock _corto_secure_lock__assign(corto_secure_lock _this, corto_query* query, int16_t priority);
#define corto_secure_lock__optional_not_set NULL
#define corto_secure_lock__optional_set(query, priority) (corto_secure_lock*)corto_secure_lock__assign((corto_secure_lock*)corto_ptr_new(corto_secure_lock_o), query, priority)
#define corto_secure_lock__optional_set_cond(__cond, query, priority) __cond ? (corto_secure_lock*)corto_secure_lock__assign((corto_secure_lock*)corto_ptr_new(corto_secure_lock_o), query, priority) : NULL
#define corto_secure_lock__unset(_this) _this ? corto_ptr_free(_this, corto_secure_lock_o), 0 : 0; _this = NULL;
#define corto_secure_lock__assign(_this, query, priority) _corto_secure_lock__assign(_this, query, priority)
#define corto_secure_lock__set(_this, query, priority) _this = _this ? _this : (corto_secure_lock*)corto_ptr_new(corto_secure_lock_o); _corto_secure_lock__assign(_this, query, priority)


#ifdef __cplusplus
}
#endif
#endif
