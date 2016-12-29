/* lock.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE_LOCK_H
#define CORTO_SECURE_LOCK_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/secure/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_secure_accessKind _corto_secure_lock_authorize(
    corto_secure_lock _this,
    corto_string token,
    corto_secure_actionKind action);
#define corto_secure_lock_authorize(_this, token, action) _corto_secure_lock_authorize(corto_secure_lock(_this), token, action)

CORTO_EXPORT corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock _this,
    corto_string token,
    corto_secure_actionKind action);
#define corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)

CORTO_EXPORT corto_int16 _corto_secure_lock_construct(
    corto_secure_lock _this);
#define corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))

CORTO_EXPORT corto_void _corto_secure_lock_destruct(
    corto_secure_lock _this);
#define corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))

#ifdef __cplusplus
}
#endif
#endif

