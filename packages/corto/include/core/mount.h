/* mount.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_MOUNT_H
#define CORTO_CORE_MOUNT_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_mount_construct(
    corto_mount _this);
#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))

CORTO_EXPORT corto_void _corto_mount_destruct(
    corto_mount _this);
#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))

CORTO_EXPORT corto_int16 _corto_mount_init(
    corto_mount _this);
#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))

CORTO_EXPORT corto_void _corto_mount_invoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs);
#define corto_mount_invoke(_this, instance, proc, argptrs) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT corto_void _corto_mount_onDeclare(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onDeclare(_this, observable) _corto_mount_onDeclare(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onDeclare_v(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onDeclare_v(_this, observable) _corto_mount_onDeclare_v(corto_mount(_this), observable)
CORTO_EXPORT corto_void _corto_mount_onDelete(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onDelete(_this, observable) _corto_mount_onDelete(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onDelete_v(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onDelete_v(_this, observable) _corto_mount_onDelete_v(corto_mount(_this), observable)
CORTO_EXPORT corto_void _corto_mount_onInvoke(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs);
#define corto_mount_onInvoke(_this, instance, proc, argptrs) _corto_mount_onInvoke(corto_mount(_this), instance, corto_function(proc), argptrs)

CORTO_EXPORT corto_void _corto_mount_onInvoke_v(
    corto_mount _this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs);
#define corto_mount_onInvoke_v(_this, instance, proc, argptrs) _corto_mount_onInvoke_v(corto_mount(_this), instance, corto_function(proc), argptrs)
CORTO_EXPORT corto_void _corto_mount_onNotify(
    corto_mount _this,
    corto_eventMask event,
    corto_result *object);
#define corto_mount_onNotify(_this, event, object) _corto_mount_onNotify(corto_mount(_this), event, object)

CORTO_EXPORT corto_void _corto_mount_onNotify_v(
    corto_mount _this,
    corto_eventMask event,
    corto_result *object);
#define corto_mount_onNotify_v(_this, event, object) _corto_mount_onNotify_v(corto_mount(_this), event, object)
CORTO_EXPORT corto_void _corto_mount_onPoll(
    corto_mount _this);
#define corto_mount_onPoll(_this) _corto_mount_onPoll(corto_mount(_this))

CORTO_EXPORT corto_void _corto_mount_onPoll_v(
    corto_mount _this);
#define corto_mount_onPoll_v(_this) _corto_mount_onPoll_v(corto_mount(_this))
CORTO_EXPORT corto_resultIter _corto_mount_onRequest(
    corto_mount _this,
    corto_request *request);
#define corto_mount_onRequest(_this, request) _corto_mount_onRequest(corto_mount(_this), request)

CORTO_EXPORT corto_resultIter _corto_mount_onRequest_v(
    corto_mount _this,
    corto_request *request);
#define corto_mount_onRequest_v(_this, request) _corto_mount_onRequest_v(corto_mount(_this), request)
CORTO_EXPORT corto_object _corto_mount_onResume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_onResume(_this, parent, name, o) _corto_mount_onResume(corto_mount(_this), parent, name, o)

CORTO_EXPORT corto_object _corto_mount_onResume_v(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_onResume_v(_this, parent, name, o) _corto_mount_onResume_v(corto_mount(_this), parent, name, o)
CORTO_EXPORT corto_word _corto_mount_onSubscribe(
    corto_mount _this,
    corto_string parent,
    corto_string name);
#define corto_mount_onSubscribe(_this, parent, name) _corto_mount_onSubscribe(corto_mount(_this), parent, name)

CORTO_EXPORT corto_word _corto_mount_onSubscribe_v(
    corto_mount _this,
    corto_string parent,
    corto_string name);
#define corto_mount_onSubscribe_v(_this, parent, name) _corto_mount_onSubscribe_v(corto_mount(_this), parent, name)
CORTO_EXPORT corto_void _corto_mount_onUnsubscribe(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_word userData);
#define corto_mount_onUnsubscribe(_this, parent, name, userData) _corto_mount_onUnsubscribe(corto_mount(_this), parent, name, userData)

CORTO_EXPORT corto_void _corto_mount_onUnsubscribe_v(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_word userData);
#define corto_mount_onUnsubscribe_v(_this, parent, name, userData) _corto_mount_onUnsubscribe_v(corto_mount(_this), parent, name, userData)
CORTO_EXPORT corto_void _corto_mount_onUpdate(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onUpdate(_this, observable) _corto_mount_onUpdate(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onUpdate_v(
    corto_mount _this,
    corto_object observable);
#define corto_mount_onUpdate_v(_this, observable) _corto_mount_onUpdate_v(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_post(
    corto_mount _this,
    corto_event e);
#define corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), corto_event(e))

CORTO_EXPORT corto_resultIter _corto_mount_request(
    corto_mount _this,
    corto_request *request);
#define corto_mount_request(_this, request) _corto_mount_request(corto_mount(_this), request)

CORTO_EXPORT corto_object _corto_mount_resume(
    corto_mount _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)

CORTO_EXPORT corto_void _corto_mount_return(
    corto_mount _this,
    corto_result *r);
#define corto_mount_return(_this, r) _corto_mount_return(corto_mount(_this), r)

CORTO_EXPORT corto_int16 _corto_mount_setContentType(
    corto_mount _this,
    corto_string type);
#define corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)

CORTO_EXPORT corto_int16 _corto_mount_setContentTypeIn(
    corto_mount _this,
    corto_string type);
#define corto_mount_setContentTypeIn(_this, type) _corto_mount_setContentTypeIn(corto_mount(_this), type)

CORTO_EXPORT corto_int16 _corto_mount_setContentTypeOut(
    corto_mount _this,
    corto_string type);
#define corto_mount_setContentTypeOut(_this, type) _corto_mount_setContentTypeOut(corto_mount(_this), type)

CORTO_EXPORT corto_void _corto_mount_subscribe(
    corto_mount _this,
    corto_request *request);
#define corto_mount_subscribe(_this, request) _corto_mount_subscribe(corto_mount(_this), request)

CORTO_EXPORT corto_void _corto_mount_unsubscribe(
    corto_mount _this,
    corto_request *request);
#define corto_mount_unsubscribe(_this, request) _corto_mount_unsubscribe(corto_mount(_this), request)

#ifdef __cplusplus
}
#endif
#endif

