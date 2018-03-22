/* _interface.h
 * This file is generated. Do not modify the contents of this file.
 */

#ifndef CORTO_SECURE_INTERFACE_H
#define CORTO_SECURE_INTERFACE_H

#include <corto/_project.h>


#ifdef __cplusplus
extern "C" {
#endif


/* class corto/secure/key */

CORTO_EXPORT
int16_t _corto_secure_key_construct(
    corto_secure_key _this);

CORTO_EXPORT
void _corto_secure_key_destruct(
    corto_secure_key _this);

CORTO_EXPORT
corto_string _corto_secure_key_login_v(
    corto_secure_key _this,
    const char *user,
    const char *password);

CORTO_EXPORT
void _corto_secure_key_logout_v(
    corto_secure_key _this,
    const char *key);


/* class corto/secure/lock */

CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock _this,
    const char *token,
    corto_secure_actionKind action);

CORTO_EXPORT
int16_t _corto_secure_lock_construct(
    corto_secure_lock _this);

CORTO_EXPORT
void _corto_secure_lock_destruct(
    corto_secure_lock _this);

#ifdef __cplusplus
}
#endif

#endif

