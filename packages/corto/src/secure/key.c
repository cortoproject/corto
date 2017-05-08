/* $CORTO_GENERATED
 *
 * key.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

/* $header() */
static corto_secure_key corto_secure_keyInstance;
static corto_string corto_secure_token;
static corto_ll corto_secure_locks[CORTO_MAX_SCOPE_DEPTH];
static corto_thread corto_secure_mainThread;

extern corto_mutex_s corto_adminLock;

void corto_secure_init(void) {
    corto_secure_mainThread = corto_threadSelf();
}

corto_bool corto_secured(void) {
    return corto_secure_keyInstance != NULL;
}

corto_string corto_login(corto_string username, corto_string password) {
    if (corto_secure_keyInstance) {
        return corto_secure_key_authenticate(corto_secure_keyInstance, username, password);
    } else {
        return NULL;
    }
}

corto_string corto_authenticate(corto_string key) {
    if (corto_mutexLock(&corto_adminLock)) {
        goto error;
    }

    corto_string prev = corto_secure_token;
    corto_secure_token = key;

    if (corto_mutexUnlock(&corto_adminLock)) {
        goto error;
    }

    return prev;
error:
    return key;
}

static corto_int16 corto_secure_getObjectDepth(corto_id id) {
    corto_int16 result = 0;
    char *ptr = id;
    while ((ptr = strchr(ptr + 1, '/'))) {
        result ++;
    }
    return result;
}

corto_int16 corto_secure_registerLock(corto_secure_lock lock) {
    if (corto_secure_mainThread == corto_threadSelf()) {
        corto_int16 depth = corto_secure_getObjectDepth(lock->mount);
        if (depth >= CORTO_MAX_SCOPE_DEPTH) {
            corto_seterr("invalid identifier for mount-member of lock");
            goto error;
        }
        if (!corto_secure_locks[depth]) {
            corto_secure_locks[depth] = corto_ll_new();
        }
        corto_ll_append(corto_secure_locks[depth], lock);
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
    if (corto_checkAttr(object, CORTO_ATTR_SCOPED)) {
        corto_id objectId;
        corto_fullpath(objectId, object);
        return corto_authorizedId(objectId, access);
    } else {
        return TRUE;
    }
}

corto_bool corto_authorizedId(corto_string objectId, corto_secure_actionKind access) {
    corto_secure_accessKind allowed = CORTO_SECURE_ACCESS_UNDEFINED;

    if (corto_secure_keyInstance) {
        corto_int32 depth = corto_secure_getObjectDepth(objectId);
        corto_uint16 currentDepth = 0;
        corto_int16 priority = 0;
        do {
            corto_ll locks = corto_secure_locks[depth];
            if (locks) {
                corto_iter it = corto_ll_iter(locks);
                while (corto_iter_hasNext(&it)) {
                    corto_secure_lock lock = corto_iter_next(&it);
                    char *expr;
                    if (!(expr = corto_matchParent(lock->mount, objectId))) {
                        continue;
                    }

                    if (lock->expr && *expr && !corto_match(lock->expr, expr)) {
                        continue;
                    }

                    /* Priority of lock must be at least of the same priority or
                     * higher than set value. */
                    if (lock->priority >= priority) {

                        /* More specific locks take precedence over less specific
                         * locks, unless priority is higher */
                        if ((allowed == CORTO_SECURE_ACCESS_UNDEFINED) ||
                            (currentDepth == depth) ||
                            (lock->priority > priority))
                        {
                            corto_secure_accessKind result;

                            result = corto_secure_lock_authorize(lock, corto_secure_token, access);

                            /* Only overwrite value if access is undefined, result
                             * is not undefined or access is denied and lock has
                             * a higher priority than what was set */
                            if (result != CORTO_SECURE_ACCESS_UNDEFINED) {
                                if ((allowed != CORTO_SECURE_ACCESS_DENIED) ||
                                    (lock->priority > priority))
                                {
                                      allowed = result;
                                      priority = lock->priority;
                                      currentDepth = depth;
                                }
                            }
                        }
                    }
                }
            }
        } while (--depth >= 0);
    }
    return allowed != CORTO_SECURE_ACCESS_DENIED;
}
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

int16_t _corto_secure_key_construct(
    corto_secure_key this)
{
/* $begin(corto/secure/key/construct) */
    if (corto_secure_keyInstance != NULL) {
        corto_seterr("secure: a secure/key instance is already active");
        goto error;
    }

    /* Only allow setting key in the mainthread */
    if (corto_secure_mainThread != corto_threadSelf()) {
        corto_seterr("secure: may only create a secure/key instance in the mainthread");
        goto error;
    }

    corto_secure_keyInstance = this;

    return 0;
error:
    return -1;
/* $end */
}

void _corto_secure_key_destruct(
    corto_secure_key this)
{
/* $begin(corto/secure/key/destruct) */
    CORTO_UNUSED(this);

    corto_trace("secure: delete key");
    corto_secure_keyInstance = NULL;

/* $end */
}
