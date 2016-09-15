/* $CORTO_GENERATED
 *
 * lock.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/secure/secure.h>

/* $header() */
corto_int16 corto_secure_registerLock(corto_secure_lock lock);
/* $end */

corto_secure_accessKind _corto_secure_lock_authorize_v(
    corto_secure_lock this,
    corto_object object,
    corto_secure_actionKind action)
{
/* $begin(corto/secure/lock/authorize) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(object);
    CORTO_UNUSED(action);

    return CORTO_SECURE_ACCESS_DENIED;
/* $end */
}

corto_int16 _corto_secure_lock_construct(
    corto_secure_lock this)
{
/* $begin(corto/secure/lock/construct) */

    if (corto_secure_registerLock(this)) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_secure_lock_destruct(
    corto_secure_lock this)
{
/* $begin(corto/secure/lock/destruct) */

    CORTO_UNUSED(this);

/* $end */
}
