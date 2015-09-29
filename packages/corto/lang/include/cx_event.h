/* cx_event.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_EVENT_H
#define CORTO_LANG_EVENT_H

#include "corto.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::event::handle() */
CORTO_LANG_EXPORT void _cx_event_handle(cx_event _this);
#define cx_event_handle(_this) _cx_event_handle(cx_event(_this))

/* ::corto::lang::event::handle() */
CORTO_LANG_EXPORT cx_void _cx_event_handle_v(cx_event _this);
#define cx_event_handle_v(_this) _cx_event_handle_v(cx_event(_this))

/* ::corto::lang::event::uniqueKind() */
CORTO_LANG_EXPORT cx_int16 _cx_event_uniqueKind(void);
#define cx_event_uniqueKind() _cx_event_uniqueKind()

#ifdef __cplusplus
}
#endif
#endif

