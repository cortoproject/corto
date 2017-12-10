/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


corto_int16 corto_secure_registerLock(corto_secure_lock lock);

corto_secure_accessKind corto_secure_lock_authorize_v(
    corto_secure_lock this,
    corto_string token,
    corto_secure_actionKind action)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(token);
    CORTO_UNUSED(action);

    return CORTO_SECURE_ACCESS_UNDEFINED;
}

int16_t corto_secure_lock_construct(
    corto_secure_lock this)
{

    if (corto_secure_registerLock(this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

void corto_secure_lock_destruct(
    corto_secure_lock this)
{

    CORTO_UNUSED(this);

}

