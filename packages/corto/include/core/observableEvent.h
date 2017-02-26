/* observableEvent.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_OBSERVABLEEVENT_H
#define CORTO_CORE_OBSERVABLEEVENT_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/core/_type.h>
#include <corto/core/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_observableEvent_handle_v(_this) _corto_observableEvent_handle_v(corto_observableEvent(_this))
CORTO_EXPORT
corto_void _corto_observableEvent_handle_v(
    corto_observableEvent _this);

#define corto_observableEvent_handle(_this) _corto_observableEvent_handle(corto_observableEvent(_this))
CORTO_EXPORT
corto_void _corto_observableEvent_handle(
    corto_observableEvent _this);

#ifdef __cplusplus
}
#endif

#endif

