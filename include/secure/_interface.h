/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_SECURE_INTERFACE_H
#define CORTO_SECURE_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_string _corto_secure_key_authenticate_v(
    corto_secure_key _this,
    const char *user,
    const char *password);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_key_authenticate_v(_this, user, password) _corto_secure_key_authenticate_v(corto_secure_key(_this), user, password)
#else
#define corto_secure_key_authenticate_v _corto_secure_key_authenticate_v
#endif

/* explicit type-safe macro */
#define safe_corto_secure_key_authenticate_v(_this, user, password) _corto_secure_key_authenticate_v(corto_secure_key(_this), user, password)

#define corto_secure_key_authenticate(_this, user, password) _corto_secure_key_authenticate(corto_secure_key(_this), user, password)
CORTO_EXPORT
corto_string _corto_secure_key_authenticate(
    corto_secure_key _this,
    const char *user,
    const char *password);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_secure_key_construct(
    corto_secure_key _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
#else
#define corto_secure_key_construct _corto_secure_key_construct
#endif

/* explicit type-safe macro */
#define safe_corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_secure_key_destruct(
    corto_secure_key _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
#else
#define corto_secure_key_destruct _corto_secure_key_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock _this,
    const char *token,
    corto_secure_actionKind action);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
#else
#define corto_secure_lock_authorize_v _corto_secure_lock_authorize_v
#endif

/* explicit type-safe macro */
#define safe_corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)

#define corto_secure_lock_authorize(_this, token, action) _corto_secure_lock_authorize(corto_secure_lock(_this), token, action)
CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize(
    corto_secure_lock _this,
    const char *token,
    corto_secure_actionKind action);

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
int16_t _corto_secure_lock_construct(
    corto_secure_lock _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
#else
#define corto_secure_lock_construct _corto_secure_lock_construct
#endif

/* explicit type-safe macro */
#define safe_corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))

/* forward declaration of the function. the '_' in front of the name allows
 * insertion of type-safe casts */
CORTO_EXPORT
void _corto_secure_lock_destruct(
    corto_secure_lock _this);

/* implicit type-safe macro (not available for project implementation) */
#ifndef BUILDING_CORTO
#define corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))
#else
#define corto_secure_lock_destruct _corto_secure_lock_destruct
#endif

/* explicit type-safe macro */
#define safe_corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))

#ifdef __cplusplus
}
#endif

#endif

