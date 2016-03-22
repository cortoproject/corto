/* packages.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_PACKAGES_H
#define CORTO_CORE_PACKAGES_H

#include "corto/corto.h"
#include "corto/core/_type.h"
#include "corto/core/_api.h"
#include "corto/core/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_packages_construct(
    corto_packages _this);
#define corto_packages_construct(_this) _corto_packages_construct(corto_packages(_this))

CORTO_EXPORT corto_void _corto_packages_destruct(
    corto_packages _this);
#define corto_packages_destruct(_this) _corto_packages_destruct(corto_packages(_this))

CORTO_EXPORT corto_resultIter _corto_packages_onRequest(
    corto_packages _this,
    corto_request *request);
#define corto_packages_onRequest(_this, request) _corto_packages_onRequest(corto_packages(_this), request)

CORTO_EXPORT corto_resultIter _corto_packages_onRequest_v(
    corto_packages _this,
    corto_request *request);
#define corto_packages_onRequest_v(_this, request) _corto_packages_onRequest_v(corto_packages(_this), request)

CORTO_EXPORT corto_object _corto_packages_onResume(
    corto_packages _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_packages_onResume(_this, parent, name, o) _corto_packages_onResume(corto_packages(_this), parent, name, o)

CORTO_EXPORT corto_object _corto_packages_onResume_v(
    corto_packages _this,
    corto_string parent,
    corto_string name,
    corto_object o);
#define corto_packages_onResume_v(_this, parent, name, o) _corto_packages_onResume_v(corto_packages(_this), parent, name, o)

#ifdef __cplusplus
}
#endif
#endif

