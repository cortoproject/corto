/* cx_dispatcher.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_DISPATCHER_H
#define CORTO_LANG_DISPATCHER_H

#include "corto.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::dispatcher::post(event e) */
CORTO_LANG_EXPORT void _cx_dispatcher_post(cx_dispatcher _this, cx_event e);
#define cx_dispatcher_post(_this, e) _cx_dispatcher_post(cx_dispatcher(_this), cx_event(e))

/* ::corto::lang::dispatcher::post(event e) */
CORTO_LANG_EXPORT cx_void _cx_dispatcher_post_v(cx_dispatcher _this, cx_event e);
#define cx_dispatcher_post_v(_this, e) _cx_dispatcher_post_v(cx_dispatcher(_this), cx_event(e))

#ifdef __cplusplus
}
#endif
#endif

