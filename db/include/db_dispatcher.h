/* cx_dispatcher.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_dispatcher_H
#define cx_dispatcher_H

#include "cortex.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
cx_observableEvent cx_dispatcher_getEvent(cx_dispatcher _this, cx_observer observer, cx_object me, cx_object observable, cx_object src);

/* ::cortex::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
cx_observableEvent cx_dispatcher_getEvent_v(cx_dispatcher _this, cx_observer observer, cx_object me, cx_object observable, cx_object src);

/* virtual ::cortex::lang::dispatcher::post(lang::event event) */
void cx_dispatcher_post(cx_dispatcher _this, cx_event event);

/* ::cortex::lang::dispatcher::post(lang::event event) */
cx_void cx_dispatcher_post_v(cx_dispatcher _this, cx_event event);

#ifdef __cplusplus
}
#endif
#endif

