/* event.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_EVENT_H
#define CORTO_CORE_EVENT_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_void _corto_event_handle(
    corto_event _this);
#define corto_event_handle(_this) _corto_event_handle(corto_event(_this))

CORTO_EXPORT corto_void _corto_event_handle_v(
    corto_event _this);
#define corto_event_handle_v(_this) _corto_event_handle_v(corto_event(_this))

CORTO_EXPORT corto_int16 _corto_event_uniqueKind(void);
#define corto_event_uniqueKind() _corto_event_uniqueKind()

#ifdef __cplusplus
}
#endif
#endif

