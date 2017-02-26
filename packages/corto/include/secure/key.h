/* key.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_SECURE_KEY_H
#define CORTO_SECURE_KEY_H

#include <corto/corto.h>
#include <corto/_project.h>

#include <corto/secure/_type.h>
#include <corto/secure/_load.h>

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
corto_int16 _corto_secure_key_construct(
    corto_secure_key _this);

#define corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
CORTO_EXPORT
corto_void _corto_secure_key_destruct(
    corto_secure_key _this);

#ifdef __cplusplus
}
#endif

#endif

