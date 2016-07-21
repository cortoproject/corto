/* subscriber.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE_SUBSCRIBER_H
#define CORTO_CORE_SUBSCRIBER_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/core/_type.h>
#include <corto/core/_api.h>
#include <corto/core/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_subscriber_construct(
    corto_subscriber _this);
#define corto_subscriber_construct(_this) _corto_subscriber_construct(corto_subscriber(_this))

CORTO_EXPORT corto_void _corto_subscriber_destruct(
    corto_subscriber _this);
#define corto_subscriber_destruct(_this) _corto_subscriber_destruct(corto_subscriber(_this))

#ifdef __cplusplus
}
#endif
#endif

