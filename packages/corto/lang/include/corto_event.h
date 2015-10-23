/* corto_event.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_EVENT_H
#define CORTO_LANG_EVENT_H

#include "corto.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::event::handle() */
CORTO_LANG_EXPORT void _corto_event_handle(corto_event _this);
#define corto_event_handle(_this) _corto_event_handle(corto_event(_this))

/* ::corto::lang::event::handle() */
CORTO_LANG_EXPORT corto_void _corto_event_handle_v(corto_event _this);
#define corto_event_handle_v(_this) _corto_event_handle_v(corto_event(_this))

/* ::corto::lang::event::uniqueKind() */
CORTO_LANG_EXPORT corto_int16 _corto_event_uniqueKind(void);
#define corto_event_uniqueKind() _corto_event_uniqueKind()

#ifdef __cplusplus
}
#endif
#endif

