/* cx_observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_OBSERVER_H
#define CORTO_LANG_OBSERVER_H

#include "corto.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::observer::bind() */
CORTO_LANG_EXPORT cx_int16 _cx_observer_bind(cx_observer _this);
#define cx_observer_bind(_this) _cx_observer_bind(cx_observer(_this))

/* ::corto::lang::observer::init() */
CORTO_LANG_EXPORT cx_int16 _cx_observer_init(cx_observer _this);
#define cx_observer_init(_this) _cx_observer_init(cx_observer(_this))

/* ::corto::lang::observer::listen(object observable,object me) */
CORTO_LANG_EXPORT cx_int16 _cx_observer_listen(cx_observer _this, cx_object observable, cx_object me);
#define cx_observer_listen(_this, observable, me) _cx_observer_listen(cx_observer(_this), observable, me)

/* ::corto::lang::observer::setDispatcher(dispatcher dispatcher) */
CORTO_LANG_EXPORT cx_void _cx_observer_setDispatcher(cx_observer _this, cx_dispatcher dispatcher);
#define cx_observer_setDispatcher(_this, dispatcher) _cx_observer_setDispatcher(cx_observer(_this), cx_dispatcher(dispatcher))

/* ::corto::lang::observer::silence(object me) */
CORTO_LANG_EXPORT cx_int16 _cx_observer_silence(cx_observer _this, cx_object me);
#define cx_observer_silence(_this, me) _cx_observer_silence(cx_observer(_this), me)

/* ::corto::lang::observer::unbind(observer object) */
CORTO_LANG_EXPORT cx_void _cx_observer_unbind(cx_observer object);
#define cx_observer_unbind(object) _cx_observer_unbind(cx_observer(object))

#ifdef __cplusplus
}
#endif
#endif

