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
static corto_ll corto_secure_locks[CORTO_MAX_SCOPE_DEPTH];
static corto_thread corto_secure_mainThread;

extern corto_mutex_s corto_adminLock;

void corto_secure_init(void) {
    corto_secure_mainThread = corto_threadSelf();
}

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

static corto_int16 corto_secure_getObjectDepth(corto_object o) {
    corto_int16 result = 0;
    corto_object p = o;
    while ((p = corto_parentof(o))) {
        result ++;
    }
    return result;
}

static corto_bool corto_secure_matchLock(char *lockId, char *id) {
    char *lPtr = lockId, *idPtr = id;

    while (*lPtr == *idPtr) {
        lPtr++;
        idPtr++;
    }

    return *lPtr == '\0';
}

corto_int16 corto_secure_registerLock(corto_secure_lock lock) {
    if (corto_secure_mainThread == corto_threadSelf()) {
        char *ptr = lock->mount;
        corto_int16 depth = 0;
        while ((ptr = strchr(ptr + 1, '/'))) {
            depth ++;
        }
        if (depth >= CORTO_MAX_SCOPE_DEPTH) {
            corto_seterr("invalid identifier for mount-member of lock");
            goto error;
        }
        if (!corto_secure_locks[depth]) {
            corto_secure_locks[depth] = corto_llNew();
        }
        corto_llAppend(corto_secure_locks[depth], lock);
    } else {
        corto_seterr("locks can only be created in mainthread");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_bool corto_authorized(corto_object object, corto_secure_actionKind access)
{
    corto_secure_accessKind allowed = CORTO_SECURE_ACCESS_UNDEFINED;

    if (corto_currentKey) {
        corto_int32 depth = corto_secure_getObjectDepth(object);
        corto_object p = object;
        corto_uint16 currentDepth = 0;
        corto_int16 priority = 0;
        corto_id objectId;
        corto_fullpath(objectId, object);

        do {
            corto_ll locks = corto_secure_locks[depth];
            if (locks) {
                corto_iter it = corto_llIter(locks);
                while (corto_iterHasNext(&it)) {
                    corto_secure_lock lock = corto_iterNext(&it);
                    if (!corto_secure_matchLock(lock->mount, objectId)) {
                        continue;
                    }

                    /* Priority of lock must be at least of the same priority or
                     * higher than set value. */
                    if (lock->priority >= priority) {

                        /* More specific locks take precedence over less specific
                         * locks, unless priority is higher */
                        if ((currentDepth == depth) || (lock->priority > priority)) {
                            corto_secure_accessKind result =
                              corto_secure_lock_authorize(lock, object, access);

                            /* Only overwrite value if access is undefined, result
                             * is not undefined or access is denied and lock has
                             * a higher priority than what was set */
                            if ((allowed == CORTO_SECURE_ACCESS_UNDEFINED) ||
                               ((allowed == CORTO_SECURE_ACCESS_GRANTED) &&
                                (result != CORTO_SECURE_ACCESS_UNDEFINED)) ||
                               ((allowed == CORTO_SECURE_ACCESS_DENIED) &&
                                (lock->priority > priority)))
                            {
                                  allowed = result;
                                  priority = lock->priority;
                                  currentDepth = depth;
                            }
                        }
                    }
                }
            }

            p = corto_parentof(p);
        } while (--depth);
    }

    return allowed != CORTO_SECURE_ACCESS_DENIED;
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
    if (corto_secure_mainThread != corto_threadSelf()) {
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
    CORTO_UNUSED(this);

    corto_trace("secure: delete key");
    corto_currentKey = NULL;

/* $end */
}
