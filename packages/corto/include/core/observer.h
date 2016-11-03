/* observer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_OBSERVER_H
#define CORTO_CORE_OBSERVER_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_observer_construct(
    corto_observer _this);
#define corto_observer_construct(_this) _corto_observer_construct(corto_observer(_this))

CORTO_EXPORT corto_void _corto_observer_destruct(
    corto_observer _this);
#define corto_observer_destruct(_this) _corto_observer_destruct(corto_observer(_this))

CORTO_EXPORT corto_int16 _corto_observer_init(
    corto_observer _this);
#define corto_observer_init(_this) _corto_observer_init(corto_observer(_this))

CORTO_EXPORT corto_int16 _corto_observer_observe(
    corto_observer _this,
    corto_object instance,
    corto_object observable);
#define corto_observer_observe(_this, instance, observable) _corto_observer_observe(corto_observer(_this), instance, observable)

CORTO_EXPORT corto_bool _corto_observer_observing(
    corto_observer _this,
    corto_object instance,
    corto_object observable);
#define corto_observer_observing(_this, instance, observable) _corto_observer_observing(corto_observer(_this), instance, observable)

CORTO_EXPORT corto_int16 _corto_observer_unobserve(
    corto_observer _this,
    corto_object instance,
    corto_object observable);
#define corto_observer_unobserve(_this, instance, observable) _corto_observer_unobserve(corto_observer(_this), instance, observable)

#ifdef __cplusplus
}
#endif
#endif

