/* corto_dispatcher.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_DISPATCHER_H
#define CORTO_LANG_DISPATCHER_H

#include "corto.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual /corto/lang/dispatcher/post(event e) */
CORTO_LANG_EXPORT void _corto_dispatcher_post(corto_dispatcher _this, corto_event e);
#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), corto_event(e))

CORTO_LANG_EXPORT corto_void _corto_dispatcher_post_v(corto_dispatcher _this, corto_event e);
#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), corto_event(e))

#ifdef __cplusplus
}
#endif
#endif

