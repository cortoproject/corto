/* subscriberEvent.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_SUBSCRIBEREVENT_H
#define CORTO_CORE_SUBSCRIBEREVENT_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/core/_type.h>
#include <corto/core/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_subscriberEvent_construct(_this) _corto_subscriberEvent_construct(corto_subscriberEvent(_this))
CORTO_EXPORT
corto_int16 _corto_subscriberEvent_construct(
    corto_subscriberEvent _this);

#define corto_subscriberEvent_destruct(_this) _corto_subscriberEvent_destruct(corto_subscriberEvent(_this))
CORTO_EXPORT
corto_void _corto_subscriberEvent_destruct(
    corto_subscriberEvent _this);

#define corto_subscriberEvent_handle_v(_this) _corto_subscriberEvent_handle_v(corto_subscriberEvent(_this))
CORTO_EXPORT
corto_void _corto_subscriberEvent_handle_v(
    corto_subscriberEvent _this);

#define corto_subscriberEvent_handle(_this) _corto_subscriberEvent_handle(corto_subscriberEvent(_this))
CORTO_EXPORT
corto_void _corto_subscriberEvent_handle(
    corto_subscriberEvent _this);

#ifdef __cplusplus
}
#endif

#endif

