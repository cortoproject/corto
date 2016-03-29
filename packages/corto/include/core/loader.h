/* loader.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_LOADER_H
#define CORTO_CORE_LOADER_H

#include "corto/corto.h"
#include "corto/core/_type.h"
#include "corto/core/_api.h"
#include "corto/core/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_loader_construct(
    corto_loader _this);
#define corto_loader_construct(_this) _corto_loader_construct(corto_loader(_this))

CORTO_EXPORT corto_void _corto_loader_destruct(
    corto_loader _this);
#define corto_loader_destruct(_this) _corto_loader_destruct(corto_loader(_this))

CORTO_EXPORT corto_resultIter _corto_loader_onRequest(
    corto_loader _this,
    corto_request *request);
#define corto_loader_onRequest(_this, request) _corto_loader_onRequest(corto_loader(_this), request)

CORTO_EXPORT corto_resultIter _corto_loader_onRequest_v(
    corto_loader _this,
    corto_request *request);
#define corto_loader_onRequest_v(_this, request) _corto_loader_onRequest_v(corto_loader(_this), request)

CORTO_EXPORT corto_object _corto_loader_onResume(
    corto_loader _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_loader_onResume(_this, parent, name, o) _corto_loader_onResume(corto_loader(_this), parent, name, o)

CORTO_EXPORT corto_object _corto_loader_onResume_v(
    corto_loader _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_loader_onResume_v(_this, parent, name, o) _corto_loader_onResume_v(corto_loader(_this), parent, name, o)

#ifdef __cplusplus
}
#endif
#endif

