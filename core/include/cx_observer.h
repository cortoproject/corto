/* cx_observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_observer_H
#define cx_observer_H

#include "corto.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::observer::bind() */
cx_int16 _cx_observer_bind(cx_observer _this);
#define cx_observer_bind(_this) _cx_observer_bind(cx_observer(_this))

/* ::corto::lang::observer::init() */
cx_int16 _cx_observer_init(cx_observer _this);
#define cx_observer_init(_this) _cx_observer_init(cx_observer(_this))

/* ::corto::lang::observer::listen(object observable,object me) */
cx_int16 _cx_observer_listen(cx_observer _this, cx_object observable, cx_object me);
#define cx_observer_listen(_this, observable, me) _cx_observer_listen(cx_observer(_this), observable, me)

/* ::corto::lang::observer::setDispatcher(dispatcher dispatcher) */
cx_void _cx_observer_setDispatcher(cx_observer _this, cx_dispatcher dispatcher);
#define cx_observer_setDispatcher(_this, dispatcher) _cx_observer_setDispatcher(cx_observer(_this), cx_dispatcher(dispatcher))

/* ::corto::lang::observer::silence(object me) */
cx_int16 _cx_observer_silence(cx_observer _this, cx_object me);
#define cx_observer_silence(_this, me) _cx_observer_silence(cx_observer(_this), me)

/* ::corto::lang::observer::unbind(observer object) */
cx_void _cx_observer_unbind(cx_observer object);
#define cx_observer_unbind(object) _cx_observer_unbind(cx_observer(object))

#ifdef __cplusplus
}
#endif
#endif

