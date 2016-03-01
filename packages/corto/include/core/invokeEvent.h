/* invokeEvent.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_INVOKEEVENT_H
#define CORTO_CORE_INVOKEEVENT_H

#include "corto/corto.h"
#include "corto/core/_type.h"
#include "corto/core/_api.h"
#include "corto/core/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT void _corto_invokeEvent_handle(
    corto_invokeEvent _this);
#define corto_invokeEvent_handle(_this) _corto_invokeEvent_handle(corto_invokeEvent(_this))

CORTO_EXPORT corto_void _corto_invokeEvent_handle_v(
    corto_invokeEvent _this);
#define corto_invokeEvent_handle_v(_this) _corto_invokeEvent_handle_v(corto_invokeEvent(_this))

#ifdef __cplusplus
}
#endif
#endif

