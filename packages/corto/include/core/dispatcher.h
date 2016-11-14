/* dispatcher.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_DISPATCHER_H
#define CORTO_CORE_DISPATCHER_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_load.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_void _corto_dispatcher_post(
    corto_dispatcher _this,
    corto_event e);
#define corto_dispatcher_post(_this, e) _corto_dispatcher_post(corto_dispatcher(_this), corto_event(e))

CORTO_EXPORT corto_void _corto_dispatcher_post_v(
    corto_dispatcher _this,
    corto_event e);
#define corto_dispatcher_post_v(_this, e) _corto_dispatcher_post_v(corto_dispatcher(_this), corto_event(e))

#ifdef __cplusplus
}
#endif
#endif

