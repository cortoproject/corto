/* secure.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE__API_H
#define CORTO_SECURE__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/secure/accessKind */
CORTO_EXPORT corto_secure_accessKind* _corto_secure_accessKindCreate(corto_secure_accessKind value);
#define corto_secure_accessKindCreate(value) _corto_secure_accessKindCreate(value)
#define corto_secure_accessKindCreate_auto(_id, value) corto_secure_accessKind* _id = corto_secure_accessKindCreate(value); (void)_id
CORTO_EXPORT corto_secure_accessKind* _corto_secure_accessKindCreateChild(corto_object _parent, corto_string _id, corto_secure_accessKind value);
#define corto_secure_accessKindCreateChild(_parent, _id, value) _corto_secure_accessKindCreateChild(_parent, _id, value)
#define corto_secure_accessKindCreateChild_auto(_parent, _id, value) corto_secure_accessKind* _id = corto_secure_accessKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_accessKindUpdate(corto_secure_accessKind* _this, corto_secure_accessKind value);
#define corto_secure_accessKindUpdate(_this, value) _corto_secure_accessKindUpdate(corto_secure_accessKind(_this), value)

CORTO_EXPORT corto_secure_accessKind* _corto_secure_accessKindDeclare(void);
#define corto_secure_accessKindDeclare() _corto_secure_accessKindDeclare()
#define corto_secure_accessKindDeclare_auto(_id) corto_secure_accessKind* _id = corto_secure_accessKindDeclare(); (void)_id
CORTO_EXPORT corto_secure_accessKind* _corto_secure_accessKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_secure_accessKindDeclareChild(_parent, _id) _corto_secure_accessKindDeclareChild(_parent, _id)
#define corto_secure_accessKindDeclareChild_auto(_parent, _id) corto_secure_accessKind* _id = corto_secure_accessKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_accessKindDefine(corto_secure_accessKind* _this, corto_secure_accessKind value);
#define corto_secure_accessKindDefine(_this, value) _corto_secure_accessKindDefine(corto_secure_accessKind(_this), value)
CORTO_EXPORT corto_secure_accessKind* _corto_secure_accessKindAssign(corto_secure_accessKind* _this, corto_secure_accessKind value);
#define corto_secure_accessKind__optional_NotSet NULL
#define corto_secure_accessKind__optional_Set(value) corto_secure_accessKindAssign((corto_secure_accessKind*)corto_calloc(sizeof(corto_secure_accessKind)), value)
#define corto_secure_accessKind__optional_SetCond(cond, value) cond ? corto_secure_accessKindAssign((corto_secure_accessKind*)corto_calloc(sizeof(corto_secure_accessKind)), value) : NULL
#define corto_secure_accessKindUnset(_this) _this ? corto_deinitp(_this, corto_secure_accessKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_secure_accessKindAssign(_this, value) _corto_secure_accessKindAssign(_this, value)
#define corto_secure_accessKindSet(_this, value) _this = _this ? _this : (corto_secure_accessKind*)corto_calloc(sizeof(corto_secure_accessKind)); _corto_secure_accessKindAssign(_this, value)
CORTO_EXPORT corto_string _corto_secure_accessKindStr(corto_secure_accessKind value);
#define corto_secure_accessKindStr(value) _corto_secure_accessKindStr(value)
CORTO_EXPORT corto_secure_accessKind* corto_secure_accessKindFromStr(corto_secure_accessKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_secure_accessKindCompare(corto_secure_accessKind dst, corto_secure_accessKind src);

CORTO_EXPORT corto_int16 _corto_secure_accessKindInit(corto_secure_accessKind* value);
#define corto_secure_accessKindInit(value) _corto_secure_accessKindInit(value)
CORTO_EXPORT corto_int16 _corto_secure_accessKindDeinit(corto_secure_accessKind* value);
#define corto_secure_accessKindDeinit(value) _corto_secure_accessKindDeinit(value)

/* /corto/secure/actionKind */
CORTO_EXPORT corto_secure_actionKind* _corto_secure_actionKindCreate(corto_secure_actionKind value);
#define corto_secure_actionKindCreate(value) _corto_secure_actionKindCreate(value)
#define corto_secure_actionKindCreate_auto(_id, value) corto_secure_actionKind* _id = corto_secure_actionKindCreate(value); (void)_id
CORTO_EXPORT corto_secure_actionKind* _corto_secure_actionKindCreateChild(corto_object _parent, corto_string _id, corto_secure_actionKind value);
#define corto_secure_actionKindCreateChild(_parent, _id, value) _corto_secure_actionKindCreateChild(_parent, _id, value)
#define corto_secure_actionKindCreateChild_auto(_parent, _id, value) corto_secure_actionKind* _id = corto_secure_actionKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_actionKindUpdate(corto_secure_actionKind* _this, corto_secure_actionKind value);
#define corto_secure_actionKindUpdate(_this, value) _corto_secure_actionKindUpdate(corto_secure_actionKind(_this), value)

CORTO_EXPORT corto_secure_actionKind* _corto_secure_actionKindDeclare(void);
#define corto_secure_actionKindDeclare() _corto_secure_actionKindDeclare()
#define corto_secure_actionKindDeclare_auto(_id) corto_secure_actionKind* _id = corto_secure_actionKindDeclare(); (void)_id
CORTO_EXPORT corto_secure_actionKind* _corto_secure_actionKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_secure_actionKindDeclareChild(_parent, _id) _corto_secure_actionKindDeclareChild(_parent, _id)
#define corto_secure_actionKindDeclareChild_auto(_parent, _id) corto_secure_actionKind* _id = corto_secure_actionKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_actionKindDefine(corto_secure_actionKind* _this, corto_secure_actionKind value);
#define corto_secure_actionKindDefine(_this, value) _corto_secure_actionKindDefine(corto_secure_actionKind(_this), value)
CORTO_EXPORT corto_secure_actionKind* _corto_secure_actionKindAssign(corto_secure_actionKind* _this, corto_secure_actionKind value);
#define corto_secure_actionKind__optional_NotSet NULL
#define corto_secure_actionKind__optional_Set(value) corto_secure_actionKindAssign((corto_secure_actionKind*)corto_calloc(sizeof(corto_secure_actionKind)), value)
#define corto_secure_actionKind__optional_SetCond(cond, value) cond ? corto_secure_actionKindAssign((corto_secure_actionKind*)corto_calloc(sizeof(corto_secure_actionKind)), value) : NULL
#define corto_secure_actionKindUnset(_this) _this ? corto_deinitp(_this, corto_secure_actionKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_secure_actionKindAssign(_this, value) _corto_secure_actionKindAssign(_this, value)
#define corto_secure_actionKindSet(_this, value) _this = _this ? _this : (corto_secure_actionKind*)corto_calloc(sizeof(corto_secure_actionKind)); _corto_secure_actionKindAssign(_this, value)
CORTO_EXPORT corto_string _corto_secure_actionKindStr(corto_secure_actionKind value);
#define corto_secure_actionKindStr(value) _corto_secure_actionKindStr(value)
CORTO_EXPORT corto_secure_actionKind* corto_secure_actionKindFromStr(corto_secure_actionKind* value, corto_string str);
CORTO_EXPORT corto_equalityKind corto_secure_actionKindCompare(corto_secure_actionKind dst, corto_secure_actionKind src);

CORTO_EXPORT corto_int16 _corto_secure_actionKindInit(corto_secure_actionKind* value);
#define corto_secure_actionKindInit(value) _corto_secure_actionKindInit(value)
CORTO_EXPORT corto_int16 _corto_secure_actionKindDeinit(corto_secure_actionKind* value);
#define corto_secure_actionKindDeinit(value) _corto_secure_actionKindDeinit(value)

/* /corto/secure/key */
CORTO_EXPORT corto_secure_key _corto_secure_keyCreate(void);
#define corto_secure_keyCreate() _corto_secure_keyCreate()
#define corto_secure_keyCreate_auto(_id) corto_secure_key _id = corto_secure_keyCreate(); (void)_id
CORTO_EXPORT corto_secure_key _corto_secure_keyCreateChild(corto_object _parent, corto_string _id);
#define corto_secure_keyCreateChild(_parent, _id) _corto_secure_keyCreateChild(_parent, _id)
#define corto_secure_keyCreateChild_auto(_parent, _id) corto_secure_key _id = corto_secure_keyCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_keyUpdate(corto_secure_key _this);
#define corto_secure_keyUpdate(_this) _corto_secure_keyUpdate(corto_secure_key(_this))

CORTO_EXPORT corto_secure_key _corto_secure_keyDeclare(void);
#define corto_secure_keyDeclare() _corto_secure_keyDeclare()
#define corto_secure_keyDeclare_auto(_id) corto_secure_key _id = corto_secure_keyDeclare(); (void)_id
CORTO_EXPORT corto_secure_key _corto_secure_keyDeclareChild(corto_object _parent, corto_string _id);
#define corto_secure_keyDeclareChild(_parent, _id) _corto_secure_keyDeclareChild(_parent, _id)
#define corto_secure_keyDeclareChild_auto(_parent, _id) corto_secure_key _id = corto_secure_keyDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_keyDefine(corto_secure_key _this);
#define corto_secure_keyDefine(_this) _corto_secure_keyDefine(corto_secure_key(_this))
CORTO_EXPORT corto_secure_key _corto_secure_keyAssign(corto_secure_key _this);
#define corto_secure_key__optional_NotSet NULL
#define corto_secure_key__optional_Set() corto_secure_keyAssign((corto_secure_key*)corto_calloc(sizeof(corto_secure_key)))
#define corto_secure_key__optional_SetCond(cond) cond ? corto_secure_keyAssign((corto_secure_key*)corto_calloc(sizeof(corto_secure_key))) : NULL
#define corto_secure_keyUnset(_this) _this ? corto_deinitp(_this, corto_secure_key_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_secure_keyAssign(_this) _corto_secure_keyAssign(_this)
#define corto_secure_keySet(_this) _this = _this ? _this : (corto_secure_key*)corto_calloc(sizeof(corto_secure_key)); _corto_secure_keyAssign(_this)
CORTO_EXPORT corto_string _corto_secure_keyStr(corto_secure_key value);
#define corto_secure_keyStr(value) _corto_secure_keyStr(corto_secure_key(value))
CORTO_EXPORT corto_secure_key corto_secure_keyFromStr(corto_secure_key value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_secure_keyCompare(corto_secure_key dst, corto_secure_key src);
#define corto_secure_keyCompare(dst, src) _corto_secure_keyCompare(corto_secure_key(dst), corto_secure_key(src))

/* /corto/secure/lock */
CORTO_EXPORT corto_secure_lock _corto_secure_lockCreate(corto_string mount, corto_string expr, corto_int16 priority);
#define corto_secure_lockCreate(mount, expr, priority) _corto_secure_lockCreate(mount, expr, priority)
#define corto_secure_lockCreate_auto(_id, mount, expr, priority) corto_secure_lock _id = corto_secure_lockCreate(mount, expr, priority); (void)_id
CORTO_EXPORT corto_secure_lock _corto_secure_lockCreateChild(corto_object _parent, corto_string _id, corto_string mount, corto_string expr, corto_int16 priority);
#define corto_secure_lockCreateChild(_parent, _id, mount, expr, priority) _corto_secure_lockCreateChild(_parent, _id, mount, expr, priority)
#define corto_secure_lockCreateChild_auto(_parent, _id, mount, expr, priority) corto_secure_lock _id = corto_secure_lockCreateChild(_parent, #_id, mount, expr, priority); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_lockUpdate(corto_secure_lock _this, corto_string mount, corto_string expr, corto_int16 priority);
#define corto_secure_lockUpdate(_this, mount, expr, priority) _corto_secure_lockUpdate(corto_secure_lock(_this), mount, expr, priority)

CORTO_EXPORT corto_secure_lock _corto_secure_lockDeclare(void);
#define corto_secure_lockDeclare() _corto_secure_lockDeclare()
#define corto_secure_lockDeclare_auto(_id) corto_secure_lock _id = corto_secure_lockDeclare(); (void)_id
CORTO_EXPORT corto_secure_lock _corto_secure_lockDeclareChild(corto_object _parent, corto_string _id);
#define corto_secure_lockDeclareChild(_parent, _id) _corto_secure_lockDeclareChild(_parent, _id)
#define corto_secure_lockDeclareChild_auto(_parent, _id) corto_secure_lock _id = corto_secure_lockDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_secure_lockDefine(corto_secure_lock _this, corto_string mount, corto_string expr, corto_int16 priority);
#define corto_secure_lockDefine(_this, mount, expr, priority) _corto_secure_lockDefine(corto_secure_lock(_this), mount, expr, priority)
CORTO_EXPORT corto_secure_lock _corto_secure_lockAssign(corto_secure_lock _this, corto_string mount, corto_string expr, corto_int16 priority);
#define corto_secure_lock__optional_NotSet NULL
#define corto_secure_lock__optional_Set(mount, expr, priority) corto_secure_lockAssign((corto_secure_lock*)corto_calloc(sizeof(corto_secure_lock)), mount, expr, priority)
#define corto_secure_lock__optional_SetCond(cond, mount, expr, priority) cond ? corto_secure_lockAssign((corto_secure_lock*)corto_calloc(sizeof(corto_secure_lock)), mount, expr, priority) : NULL
#define corto_secure_lockUnset(_this) _this ? corto_deinitp(_this, corto_secure_lock_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_secure_lockAssign(_this, mount, expr, priority) _corto_secure_lockAssign(_this, mount, expr, priority)
#define corto_secure_lockSet(_this, mount, expr, priority) _this = _this ? _this : (corto_secure_lock*)corto_calloc(sizeof(corto_secure_lock)); _corto_secure_lockAssign(_this, mount, expr, priority)
CORTO_EXPORT corto_string _corto_secure_lockStr(corto_secure_lock value);
#define corto_secure_lockStr(value) _corto_secure_lockStr(corto_secure_lock(value))
CORTO_EXPORT corto_secure_lock corto_secure_lockFromStr(corto_secure_lock value, corto_string str);
CORTO_EXPORT corto_equalityKind _corto_secure_lockCompare(corto_secure_lock dst, corto_secure_lock src);
#define corto_secure_lockCompare(dst, src) _corto_secure_lockCompare(corto_secure_lock(dst), corto_secure_lock(src))


#ifdef __cplusplus
}
#endif
#endif

