/*
 * cx_object.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CX_OBJECT_H_
#define CX_OBJECT_H_

#include "cx__type.h"
#include "cx_ll.h"
#include "cx_value.h"
#include "cx_async.h"
#include "cx_time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef char cx_id[512];

typedef int (*cx_scopeWalkAction)(cx_object o, void* userData);
typedef cx_equalityKind ___ (*cx_equalsAction)(cx_type _this, const void* o1, const void* o2);

/* Event-kinds */
#define CX_EVENT_NONE       (0)
#define CX_EVENT_OBSERVABLE (1)

/* Object lifecycle */
cx_attr cx_setAttr(cx_attr attr);
cx_attr cx_getAttr(void);
cx_object _cx_create(cx_type type);
cx_object _cx_createChild(cx_object parent, cx_string name, cx_type type);
cx_object _cx_declare(cx_type type);
cx_object _cx_declareChild(cx_object parent, cx_string name, cx_type type);
cx_int16 cx_define(cx_object o);
void cx_delete(cx_object o);
void cx_drop(cx_object o);
cx_int32 cx_claim(cx_object o);
cx_int32 cx_release(cx_object o);
void cx_invalidate(cx_object o);
void cx_attach(cx_object parent, cx_object child);
void cx_detach(cx_object parent, cx_object child);

/* Generic object data */
cx_type cx_typeof(cx_object o);
cx_int32 cx_countof(cx_object o);
cx_int8 cx_stateof(cx_object o);
cx_bool cx_checkState(cx_object o, cx_int8 state);
cx_bool cx_checkAttr(cx_object o, cx_int8 attr);
cx_object cx_assertType(cx_type type, cx_object o);
cx_bool _cx_instanceof(cx_type type, cx_object o);

/* Scoped data */
cx_string cx_nameof(cx_object o);
cx_object cx_parentof(cx_object o);
cx_uint32 cx_scopeSize(cx_object o); /* Returns number of objects (non-recursive) in scope */
cx_ll cx_scopeClaim(cx_object o); /* Safe way to access scope contents */
void cx_scopeRelease(cx_ll scope);
cx_int32 cx_scopeWalk(cx_object o, cx_scopeWalkAction action, void* userData); /* Safe object-walk */
cx_string cx_fullname(cx_object o, cx_id buffer);
cx_string cx_relname(cx_object from, cx_object o, cx_id buffer);

/* Persistent data */
cx_time cx_timestampof(cx_object o);

/* Find objects by name */
cx_object cx_lookup(cx_object scope, cx_string name);
cx_object cx_resolve(cx_object scope, cx_string expr);

/* Notifications */
cx_object cx_setSource(cx_object source);
cx_int32 cx_listen(cx_object observable, cx_observer observer, cx_object _this);
cx_int32 cx_silence(cx_object observable, cx_observer observer, cx_object _this);
cx_bool cx_listening(cx_object observable, cx_observer, cx_object _this);
cx_int32 cx_update(cx_object observable);
cx_int32 cx_updateBegin(cx_object observable);
cx_int32 cx_updateTry(cx_object observable);
cx_int32 cx_updateEnd(cx_object observable);
cx_int32 cx_updateCancel(cx_object observable);

/* Read locking */
cx_int32 cx_readBegin(cx_object object);
cx_int32 cx_readEnd(cx_object object);

/* Write locking */
cx_int32 cx_lock(cx_object object);
cx_int32 cx_unlock(cx_object object);

/* Waiting */
cx_int32 cx_waitfor(cx_object observable);
cx_object cx_wait(cx_int32 timeout_sec, cx_int32 timeout_nanosec);

/* REPL functionality */
cx_int16 cx_expr(cx_object scope, cx_string expr, cx_value *value);

/* Set reference field */
void cx_setref(void* ptr, cx_object value);

/* Set string field */
void cx_setstr(cx_string* ptr, cx_string value);

/* Serialize to string */
cx_string cx_str(cx_object object, cx_uint32 maxLength);
cx_string cx_strv(cx_value* v, cx_uint32 maxLength);
cx_string _cx_strp(void *p, cx_type type, cx_uint32 maxLength);
cx_string cx_stra(cx_any a, cx_uint32 maxLength);

/* Deserialize from string */
cx_int16 cx_fromStr(void *o, cx_string string);
cx_int16 cx_fromStrv(cx_value *v, cx_string string);
cx_int16 _cx_fromStrp(void *p, cx_type type, cx_string string);
cx_int16 cx_fromStra(cx_any *a, cx_string string);

/* Copy */
cx_int16 cx_copy(cx_object *dst, cx_object src);
cx_int16 cx_copyv(cx_value *dst, cx_value *src);
cx_int16 _cx_copyp(void *dst, cx_type type, void *src);
cx_int16 cx_copya(cx_any *dst, cx_any src);

/* Compare */
cx_equalityKind cx_compare(cx_object o1, cx_object o2);
cx_equalityKind cx_comparev(cx_value *v1, cx_value *value2);
cx_equalityKind _cx_comparep(void *p1, cx_type type, void *p2);
cx_equalityKind cx_comparea(cx_any a1, cx_any a2);

/* Init */
cx_int16 cx_init(cx_object o);
cx_int16 cx_initv(cx_value *v);
cx_int16 _cx_initp(void *v, cx_type type);
cx_int16 cx_inita(cx_any a);

/* Deinit */
cx_int16 cx_deinit(cx_object o);
cx_int16 cx_deinitv(cx_value *v);
cx_int16 _cx_deinitp(void *v, cx_type type);
cx_int16 cx_deinita(cx_any a);

/* Macro's that automate casting of parameters */
#define cx_create(type) _cx_create(cx_type(type))
#define cx_createChild(parent, name, type) _cx_createChild(parent, name, cx_type(type))
#define cx_declare(type) _cx_declare(cx_type(type))
#define cx_declareChild(parent, name, type) _cx_declareChild(parent, name, cx_type(type))
#define cx_strp(p, type, maxLength) _cx_strp(p, cx_type(type), maxLength)
#define cx_fromStrp(out, type, string) _cx_fromStrp(out, cx_type(type), string)
#define cx_copyp(p, type, src) _cx_copyp(p, cx_type(type), src)
#define cx_comparep(p1, type, p2) _cx_comparep(p1, cx_type(type), p2)
#define cx_initp(p, type) _cx_initp(p, cx_type(type))
#define cx_deinitp(p, type) _cx_deinitp(p, cx_type(type))
#define cx_instanceof(type, o) _cx_instanceof((cx_type)type, o)

#ifdef __cplusplus
}
#endif

#endif /* CX_OBJECT_H_ */
