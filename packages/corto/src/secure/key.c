/* $CORTO_GENERATED
 *
 * key.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/secure/secure.h>

/* $header() */
static corto_secure_key corto_currentKey;
static corto_int8 CORTO_OLS_SECURE_LOCK;
static corto_string corto_keyToken;
extern corto_thread corto_mainThread;
extern corto_mutex_s corto_adminLock;

corto_string corto_login(corto_string username, corto_string password) {
    if (corto_currentKey) {
        return corto_secure_key_authenticate(corto_currentKey, username, password);
    } else {
        return NULL;
    }
}

corto_string corto_authenticate(corto_string key) {
    if (corto_mutexLock(&corto_adminLock)) {
        goto error;
    }

    corto_string prev = corto_keyToken;
    corto_keyToken = key;

    if (corto_mutexUnlock(&corto_adminLock)) {
        goto error;
    }

    return prev;
error:
    return key;
}

corto_bool corto_authorized(corto_object object, corto_secure_actionKind access)
{
    /*corto_object p = object;
    while (p) {
        corto_ll locks =
    }*/
    return FALSE;
}


corto_bool corto_authorizedId(corto_string id, corto_secure_actionKind access);

/* $end */

corto_string _corto_secure_key_authenticate_v(
    corto_secure_key this,
    corto_string user,
    corto_string password)
{
/* $begin(corto/secure/key/authenticate) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(user);
    CORTO_UNUSED(password);

    return NULL;
/* $end */
}

corto_int16 _corto_secure_key_construct(
    corto_secure_key this)
{
/* $begin(corto/secure/key/construct) */
    if (corto_currentKey != NULL) {
        corto_seterr("secure: a secure/key instance is already active");
        goto error;
    }

    /* Only allow setting key in the mainthread */
    if (corto_mainThread != corto_threadSelf()) {
        corto_seterr("secure: may only create a secure/key instance in the mainthread");
        goto error;
    }

    corto_currentKey = this;
    CORTO_OLS_SECURE_LOCK = corto_olsKey((void(*)(void*))corto_release);

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_secure_key_destruct(
    corto_secure_key this)
{
/* $begin(corto/secure/key/destruct) */

    corto_trace("secure: delete key");
    corto_currentKey = NULL;

/* $end */
}
