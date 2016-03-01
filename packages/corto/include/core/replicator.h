/* replicator.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_REPLICATOR_H
#define CORTO_CORE_REPLICATOR_H

#include "corto/corto.h"
#include "corto/core/_type.h"
#include "corto/core/_api.h"
#include "corto/core/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_replicator_construct(
    corto_replicator _this);
#define corto_replicator_construct(_this) _corto_replicator_construct(corto_replicator(_this))

CORTO_EXPORT corto_void _corto_replicator_destruct(
    corto_replicator _this);
#define corto_replicator_destruct(_this) _corto_replicator_destruct(corto_replicator(_this))

CORTO_EXPORT corto_void _corto_replicator_invoke(
    corto_replicator _this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_replicator_invoke(_this, instance, proc, args) _corto_replicator_invoke(corto_replicator(_this), instance, corto_function(proc), args)

CORTO_EXPORT corto_void _corto_replicator_on_declare(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_on_declare(_this, observable) _corto_replicator_on_declare(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_on_delete(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_on_delete(_this, observable) _corto_replicator_on_delete(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_on_update(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_on_update(_this, observable) _corto_replicator_on_update(corto_replicator(_this), observable)

CORTO_EXPORT void _corto_replicator_onDeclare(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onDeclare(_this, observable) _corto_replicator_onDeclare(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_onDeclare_v(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onDeclare_v(_this, observable) _corto_replicator_onDeclare_v(corto_replicator(_this), observable)

CORTO_EXPORT void _corto_replicator_onDelete(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onDelete(_this, observable) _corto_replicator_onDelete(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_onDelete_v(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onDelete_v(_this, observable) _corto_replicator_onDelete_v(corto_replicator(_this), observable)

CORTO_EXPORT void _corto_replicator_onInvoke(
    corto_replicator _this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_replicator_onInvoke(_this, instance, proc, args) _corto_replicator_onInvoke(corto_replicator(_this), instance, corto_function(proc), args)

CORTO_EXPORT corto_void _corto_replicator_onInvoke_v(
    corto_replicator _this,
    corto_object instance,
    corto_function proc,
    corto_octetseq args);
#define corto_replicator_onInvoke_v(_this, instance, proc, args) _corto_replicator_onInvoke_v(corto_replicator(_this), instance, corto_function(proc), args)

CORTO_EXPORT corto_resultIter _corto_replicator_onRequest(
    corto_replicator _this,
    corto_string parent,
    corto_string expr,
    corto_string param,
    corto_bool setContent);
#define corto_replicator_onRequest(_this, parent, expr, param, setContent) _corto_replicator_onRequest(corto_replicator(_this), parent, expr, param, setContent)

CORTO_EXPORT corto_resultIter _corto_replicator_onRequest_v(
    corto_replicator _this,
    corto_string parent,
    corto_string expr,
    corto_string param,
    corto_bool setContent);
#define corto_replicator_onRequest_v(_this, parent, expr, param, setContent) _corto_replicator_onRequest_v(corto_replicator(_this), parent, expr, param, setContent)

CORTO_EXPORT void _corto_replicator_onUpdate(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onUpdate(_this, observable) _corto_replicator_onUpdate(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_onUpdate_v(
    corto_replicator _this,
    corto_object observable);
#define corto_replicator_onUpdate_v(_this, observable) _corto_replicator_onUpdate_v(corto_replicator(_this), observable)

CORTO_EXPORT corto_void _corto_replicator_post(
    corto_replicator _this,
    corto_event e);
#define corto_replicator_post(_this, e) _corto_replicator_post(corto_replicator(_this), corto_event(e))

CORTO_EXPORT corto_resultIter _corto_replicator_request(
    corto_replicator _this,
    corto_string parent,
    corto_string expr,
    corto_string param,
    corto_bool setContent);
#define corto_replicator_request(_this, parent, expr, param, setContent) _corto_replicator_request(corto_replicator(_this), parent, expr, param, setContent)

CORTO_EXPORT corto_int16 _corto_replicator_setContentType(
    corto_replicator _this,
    corto_string type);
#define corto_replicator_setContentType(_this, type) _corto_replicator_setContentType(corto_replicator(_this), type)

#ifdef __cplusplus
}
#endif
#endif

