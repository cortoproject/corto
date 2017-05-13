/* _interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE_INTERFACE_H
#define CORTO_SECURE_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif

#define corto_secure_key_authenticate_v(_this, user, password) _corto_secure_key_authenticate_v(corto_secure_key(_this), user, password)
CORTO_EXPORT
corto_string _corto_secure_key_authenticate_v(
    corto_secure_key _this,
    corto_string user,
    corto_string password);

#define corto_secure_key_authenticate(_this, user, password) _corto_secure_key_authenticate(corto_secure_key(_this), user, password)
CORTO_EXPORT
corto_string _corto_secure_key_authenticate(
    corto_secure_key _this,
    corto_string user,
    corto_string password);

#define corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
CORTO_EXPORT
int16_t _corto_secure_key_construct(
    corto_secure_key _this);

#define corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
CORTO_EXPORT
void _corto_secure_key_destruct(
    corto_secure_key _this);

#define corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock _this,
    corto_string token,
    corto_secure_actionKind action);

#define corto_secure_lock_authorize(_this, token, action) _corto_secure_lock_authorize(corto_secure_lock(_this), token, action)
CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize(
    corto_secure_lock _this,
    corto_string token,
    corto_secure_actionKind action);

#define corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
CORTO_EXPORT
int16_t _corto_secure_lock_construct(
    corto_secure_lock _this);

#define corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))
CORTO_EXPORT
void _corto_secure_lock_destruct(
    corto_secure_lock _this);

#ifdef __cplusplus
}
#endif

#endif

