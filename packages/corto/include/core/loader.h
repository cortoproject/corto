/* loader.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_LOADER_H
#define CORTO_CORE_LOADER_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>

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

#ifdef __cplusplus
}
#endif
#endif

