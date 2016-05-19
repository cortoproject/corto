/* mount.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_MOUNT_H
#define CORTO_CORE_MOUNT_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_mount_construct(
    corto_mount this);
#define corto_mount_construct(_this) _corto_mount_construct(corto_mount(_this))

CORTO_EXPORT corto_void _corto_mount_destruct(
    corto_mount this);
#define corto_mount_destruct(_this) _corto_mount_destruct(corto_mount(_this))

CORTO_EXPORT corto_int16 _corto_mount_init(
    corto_mount this);
#define corto_mount_init(_this) _corto_mount_init(corto_mount(_this))

CORTO_EXPORT corto_void _corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_mount_invoke(_this, instance, proc, args) _corto_mount_invoke(corto_mount(_this), instance, corto_function(proc), args)

CORTO_EXPORT corto_void _corto_mount_on_declare(
    corto_mount this,
    corto_object observable);
#define corto_mount_on_declare(_this, observable) _corto_mount_on_declare(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_on_delete(
    corto_mount this,
    corto_object observable);
#define corto_mount_on_delete(_this, observable) _corto_mount_on_delete(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_on_update(
    corto_mount this,
    corto_object observable);
#define corto_mount_on_update(_this, observable) _corto_mount_on_update(corto_mount(_this), observable)
CORTO_EXPORT corto_void _corto_mount_onDeclare(
    corto_mount this,
    corto_object observable);
#define corto_mount_onDeclare(_this, observable) _corto_mount_onDeclare(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onDeclare_v(
    corto_mount this,
    corto_object observable);
#define corto_mount_onDeclare_v(_this, observable) _corto_mount_onDeclare_v(corto_mount(_this), observable)
CORTO_EXPORT corto_void _corto_mount_onDelete(
    corto_mount this,
    corto_object observable);
#define corto_mount_onDelete(_this, observable) _corto_mount_onDelete(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onDelete_v(
    corto_mount this,
    corto_object observable);
#define corto_mount_onDelete_v(_this, observable) _corto_mount_onDelete_v(corto_mount(_this), observable)
CORTO_EXPORT corto_void _corto_mount_onInvoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_mount_onInvoke(_this, instance, proc, args) _corto_mount_onInvoke(corto_mount(_this), instance, corto_function(proc), args)

CORTO_EXPORT corto_void _corto_mount_onInvoke_v(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_mount_onInvoke_v(_this, instance, proc, args) _corto_mount_onInvoke_v(corto_mount(_this), instance, corto_function(proc), args)
CORTO_EXPORT corto_resultIter _corto_mount_onRequest(
    corto_mount this,
    corto_request *request);
#define corto_mount_onRequest(_this, request) _corto_mount_onRequest(corto_mount(_this), request)

CORTO_EXPORT corto_resultIter _corto_mount_onRequest_v(
    corto_mount this,
    corto_request *request);
#define corto_mount_onRequest_v(_this, request) _corto_mount_onRequest_v(corto_mount(_this), request)
CORTO_EXPORT corto_object _corto_mount_onResume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_onResume(_this, parent, name, o) _corto_mount_onResume(corto_mount(_this), parent, name, o)

CORTO_EXPORT corto_object _corto_mount_onResume_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_onResume_v(_this, parent, name, o) _corto_mount_onResume_v(corto_mount(_this), parent, name, o)
CORTO_EXPORT corto_void _corto_mount_onUpdate(
    corto_mount this,
    corto_object observable);
#define corto_mount_onUpdate(_this, observable) _corto_mount_onUpdate(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_onUpdate_v(
    corto_mount this,
    corto_object observable);
#define corto_mount_onUpdate_v(_this, observable) _corto_mount_onUpdate_v(corto_mount(_this), observable)

CORTO_EXPORT corto_void _corto_mount_post(
    corto_mount this,
    corto_event e);
#define corto_mount_post(_this, e) _corto_mount_post(corto_mount(_this), corto_event(e))

CORTO_EXPORT corto_resultIter _corto_mount_request(
    corto_mount this,
    corto_request *request);
#define corto_mount_request(_this, request) _corto_mount_request(corto_mount(_this), request)

CORTO_EXPORT corto_object _corto_mount_resume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_mount_resume(_this, parent, name, o) _corto_mount_resume(corto_mount(_this), parent, name, o)

CORTO_EXPORT corto_int16 _corto_mount_setContentType(
    corto_mount this,
    corto_string type);
#define corto_mount_setContentType(_this, type) _corto_mount_setContentType(corto_mount(_this), type)

#ifdef __cplusplus
}
#endif
#endif

