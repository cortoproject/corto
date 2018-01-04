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

/* -- Procudure declarations -- */


/* class corto/secure/key */

CORTO_EXPORT
corto_string _corto_secure_key_authenticate_v(
    corto_secure_key _this,
    const char *user,
    const char *password);

/* corto_string corto_secure_key_authenticate(corto_secure_key, const char *, const char *) */
#define corto_secure_key_authenticate(_this, user, password) ( \
    ((corto_function)corto_secure_key_authenticate_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_string (*)(corto_object, const char *, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_authenticate_o)->index - 1])->fptr)(corto_secure_key(_this), user, password) \
    : *(corto_string*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_authenticate_o)->index - 1], alloca(sizeof(corto_string)), corto_secure_key(_this), user, password) \
    )

CORTO_EXPORT
int16_t _corto_secure_key_construct(
    corto_secure_key _this);

CORTO_EXPORT
void _corto_secure_key_destruct(
    corto_secure_key _this);


/* class corto/secure/lock */

CORTO_EXPORT
corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock _this,
    const char *token,
    corto_secure_actionKind action);

/* corto_secure_accessKind corto_secure_lock_authorize(corto_secure_lock, const char *, corto_secure_actionKind) */
#define corto_secure_lock_authorize(_this, token, action) ( \
    ((corto_function)corto_secure_lock_authorize_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_secure_accessKind (*)(corto_object, const char *, corto_secure_actionKind))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_lock_authorize_o)->index - 1])->fptr)(corto_secure_lock(_this), token, action) \
    : *(corto_secure_accessKind*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_lock_authorize_o)->index - 1], alloca(sizeof(corto_secure_accessKind)), corto_secure_lock(_this), token, action) \
    )

CORTO_EXPORT
int16_t _corto_secure_lock_construct(
    corto_secure_lock _this);

CORTO_EXPORT
void _corto_secure_lock_destruct(
    corto_secure_lock _this);

/* -- Support macro's -- */
#ifndef BUILDING_CORTO
#define corto_secure_key_authenticate_v(_this, user, password) _corto_secure_key_authenticate_v(corto_secure_key(_this), user, password)
#define corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
#define corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
#define corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
#define corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
#define corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))
#else
#define corto_secure_key_authenticate_v _corto_secure_key_authenticate_v
#define corto_secure_key_construct _corto_secure_key_construct
#define corto_secure_key_destruct _corto_secure_key_destruct
#define corto_secure_lock_authorize_v _corto_secure_lock_authorize_v
#define corto_secure_lock_construct _corto_secure_lock_construct
#define corto_secure_lock_destruct _corto_secure_lock_destruct
#ifndef __cplusplus
#endif
#endif
#define safe_corto_secure_key_authenticate_v(_this, user, password) _corto_secure_key_authenticate_v(corto_secure_key(_this), user, password)
#define safe_corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
#define safe_corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
#define safe_corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
#define safe_corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
#define safe_corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))

#ifdef __cplusplus
}
#endif

#endif

