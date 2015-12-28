/* observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_OBSERVER_H
#define CORTO_CORE_OBSERVER_H

#include "corto/corto.h"
#include "corto/core/_type.h"
#include "corto/core/_api.h"
#include "corto/core/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_observer_bind(corto_observer _this);
#define corto_observer_bind(_this) _corto_observer_bind(corto_observer(_this))

CORTO_EXPORT corto_int16 _corto_observer_init(corto_observer _this);
#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))

CORTO_EXPORT corto_int16 _corto_observer_listen(corto_observer _this, corto_object observable, corto_object me);
#define corto_observer_listen(_this, observable, me) _corto_observer_listen(corto_observer(_this), observable, me)

CORTO_EXPORT corto_void _corto_observer_setDispatcher(corto_observer _this, corto_dispatcher dispatcher);
#define corto_observer_setDispatcher(_this, dispatcher) _corto_observer_setDispatcher(corto_observer(_this), corto_dispatcher(dispatcher))

CORTO_EXPORT corto_int16 _corto_observer_silence(corto_observer _this, corto_object me);
#define corto_observer_silence(_this, me) _corto_observer_silence(corto_observer(_this), me)

CORTO_EXPORT corto_void _corto_observer_unbind(corto_observer object);
#define corto_observer_unbind(object) _corto_observer_unbind(corto_observer(object))

#ifdef __cplusplus
}
#endif
#endif

