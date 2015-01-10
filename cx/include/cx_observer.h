/* cx_observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_observer_H
#define cx_observer_H

#include "cortex.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::procedure::bind(object object) -> ::cortex::lang::observer::bind(observer object) */
cx_int16 cx_observer_bind(cx_observer object);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::observer::init(observer object) */
cx_int16 cx_observer_init(cx_observer object);

/* ::cortex::lang::observer::listen(object observable,object me) */
cx_int16 cx_observer_listen(cx_observer _this, cx_object observable, cx_object me);

/* ::cortex::lang::observer::setDispatcher(dispatcher dispatcher) */
cx_void cx_observer_setDispatcher(cx_observer _this, cx_dispatcher dispatcher);

/* ::cortex::lang::observer::silence(object me) */
cx_int16 cx_observer_silence(cx_observer _this, cx_object me);

/* ::cortex::lang::observer::unbind(observer object) */
cx_void cx_observer_unbind(cx_observer object);

#ifdef __cplusplus
}
#endif
#endif

