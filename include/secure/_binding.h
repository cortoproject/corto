/* _binding.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_SECURE_BINDING_H
#define CORTO_SECURE_BINDING_H

/* -- Type casting -- */
#define corto_secure_accessKind(o) ((corto_secure_accessKind*)corto_assert_type((corto_type)corto_secure_accessKind_o, o))
#define corto_secure_actionKind(o) ((corto_secure_actionKind*)corto_assert_type((corto_type)corto_secure_actionKind_o, o))
#define corto_secure_key(o) ((corto_secure_key)corto_assert_type((corto_type)corto_secure_key_o, o))
#define corto_secure_lock(o) ((corto_secure_lock)corto_assert_type((corto_type)corto_secure_lock_o, o))

/* -- Non-expanding typedefs -- */
typedef corto_secure_accessKind _type_corto_secure_accessKind;
typedef corto_secure_actionKind _type_corto_secure_actionKind;
typedef corto_secure_key _type_corto_secure_key;
typedef corto_secure_lock _type_corto_secure_lock;

/* -- Argument type casting -- */
#ifndef CORTO_IMPL
#define corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
#define corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
#define corto_secure_key_login_v(_this, user, password) _corto_secure_key_login_v(corto_secure_key(_this), user, password)
#define corto_secure_key_logout_v(_this, key) _corto_secure_key_logout_v(corto_secure_key(_this), key)
#define corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
#define corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
#define corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))
#else
/* Can't use argument type casting macro's within project, as they would
 * substitute headers in implementation files. */
#define corto_secure_key_construct _corto_secure_key_construct
#define corto_secure_key_destruct _corto_secure_key_destruct
#define corto_secure_key_login_v _corto_secure_key_login_v
#define corto_secure_key_logout_v _corto_secure_key_logout_v
#define corto_secure_lock_authorize_v _corto_secure_lock_authorize_v
#define corto_secure_lock_construct _corto_secure_lock_construct
#define corto_secure_lock_destruct _corto_secure_lock_destruct
/* Macro for doing argument type casting within project. */
#define safe_corto_secure_key_construct(_this) _corto_secure_key_construct(corto_secure_key(_this))
#define safe_corto_secure_key_destruct(_this) _corto_secure_key_destruct(corto_secure_key(_this))
#define safe_corto_secure_key_login_v(_this, user, password) _corto_secure_key_login_v(corto_secure_key(_this), user, password)
#define safe_corto_secure_key_logout_v(_this, key) _corto_secure_key_logout_v(corto_secure_key(_this), key)
#define safe_corto_secure_lock_authorize_v(_this, token, action) _corto_secure_lock_authorize_v(corto_secure_lock(_this), token, action)
#define safe_corto_secure_lock_construct(_this) _corto_secure_lock_construct(corto_secure_lock(_this))
#define safe_corto_secure_lock_destruct(_this) _corto_secure_lock_destruct(corto_secure_lock(_this))
#endif

/* -- Overridable methods -- */
#define corto_secure_key_login(_this, user, password) ( \
    ((corto_function)corto_secure_key_login_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_string (*)(corto_object, const char *, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_login_o)->index - 1])->fptr)(corto_secure_key(_this), user, password) \
    : *(corto_string*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_login_o)->index - 1], alloca(sizeof(corto_string)), corto_secure_key(_this), user, password) \
    )
#define corto_secure_key_logout(_this, key) ( \
    ((corto_function)corto_secure_key_logout_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_void (*)(corto_object, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_logout_o)->index - 1])->fptr)(corto_secure_key(_this), key) \
    : (void)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_key_logout_o)->index - 1], NULL, corto_secure_key(_this), key) \
    )
#define corto_secure_lock_authorize(_this, token, action) ( \
    ((corto_function)corto_secure_lock_authorize_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_secure_accessKind (*)(corto_object, const char *, corto_secure_actionKind))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_lock_authorize_o)->index - 1])->fptr)(corto_secure_lock(_this), token, action) \
    : *(corto_secure_accessKind*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_secure_lock_authorize_o)->index - 1], alloca(sizeof(corto_secure_accessKind)), corto_secure_lock(_this), token, action) \
    )

/* -- Short identifier translation -- */

/* -- Short object variable translation -- */

#endif

