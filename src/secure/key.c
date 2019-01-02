/* This is a managed file. Do not delete this comment. */

#include <corto>

static corto_secure_key corto_secure_keyInstance;
static ut_thread corto_secure_mainThread;
static ut_tls CORTO_KEY_SESSION_TOKEN;

static
corto_entityAdmin corto_lock_admin = {0, 0, UT_RWMUTEX_INIT, 0, 0, UT_MUTEX_INIT, UT_COND_INIT};

void corto_secure_init(void) {
    corto_secure_mainThread = ut_thread_self();
    ut_tls_new(&corto_lock_admin.key, corto_entityAdmin_free);
    ut_tls_new(&CORTO_KEY_SESSION_TOKEN, NULL);
}

bool corto_secured(void) {
     if (corto_secure_keyInstance) {
         return corto_secure_keyInstance->enabled;
     } else {
         return false;
     }
}

bool corto_enable_security(
    bool enabled)
{
    if (corto_secure_keyInstance) {
        corto_secure_keyInstance->enabled = enabled;
        return enabled;
    } else {
        return false;
    }
}

const char* corto_login(
    const char *username,
    const char *password)
{
    if (corto_secure_keyInstance) {
        return corto_secure_key_login(
            corto_secure_keyInstance,
            username,
            password);
    } else {
        return NULL;
    }
}

void ut_logout(
    const char *key)
{
    if (corto_secure_keyInstance) {
        corto_secure_key_logout(
            corto_secure_keyInstance,
            key);
    }
}

const char* corto_set_session(
    const char *session_token)
{
    if (ut_rwmutex_write(&corto_lock_admin.lock)) {
        ut_throw(NULL);
        goto error;
    }

    const char *prev = ut_tls_get(CORTO_KEY_SESSION_TOKEN);
    ut_tls_set(CORTO_KEY_SESSION_TOKEN, (void*)session_token);

    if (ut_rwmutex_unlock(&corto_lock_admin.lock)) {
        ut_throw(NULL);
        goto error;
    }

    return prev;
error:
    return session_token;
}

const char *corto_get_session(void)
{
    return ut_tls_get(CORTO_KEY_SESSION_TOKEN);
}

int16_t corto_secure_registerLock(
    corto_secure_lock lock)
{
    if (corto_secure_mainThread == ut_thread_self()) {
        corto_entityAdmin_add(&corto_lock_admin, lock->query.from, lock, NULL);
    } else {
        ut_throw("locks can only be created in mainthread");
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_secure_unregisterLock(
    corto_secure_lock lock)
{
    if (corto_secure_mainThread == ut_thread_self()) {
        corto_entityAdmin_remove(&corto_lock_admin, lock->query.from, lock, NULL, FALSE);
    } else {
        ut_throw("locks can only be removed from mainthread");
        goto error;
    }

    return 0;
error:
    return -1;
}

bool corto_authorize(
    corto_object object,
    corto_secure_actionKind access)
{
    if (corto_check_attr(object, CORTO_ATTR_NAMED)) {
        corto_id objectId;
        corto_fullpath(objectId, object);
        return corto_authorize_id(objectId, access);
    } else {
        return TRUE;
    }
}

static
const char* corto_access_kind_to_str(
    corto_secure_accessKind access)
{
    return access == CORTO_SECURE_ACCESS_UNDEFINED
        ? "undefined"
        : access == CORTO_SECURE_ACCESS_DENIED
            ? "denied"
            : "granted"
            ;
}

static
const char* corto_action_kind_to_str(
    corto_secure_actionKind action)
{
    return action == CORTO_SECURE_ACTION_CREATE
        ? "create"
        : action == CORTO_SECURE_ACTION_READ
            ? "read"
            : action == CORTO_SECURE_ACTION_UPDATE
                ? "update"
                : action == CORTO_SECURE_ACTION_DELETE
                    ? "delete"
                    : "?"
                    ;
}

bool corto_authorize_id(
    const char *objectId,
    corto_secure_actionKind access)
{
    corto_secure_accessKind allowed = CORTO_SECURE_ACCESS_UNDEFINED;
    const char *session_token =
        ut_tls_get(CORTO_KEY_SESSION_TOKEN);

    corto_secure_lock active_lock = NULL;

    if (corto_secure_keyInstance && corto_secure_keyInstance->enabled) {
        int32_t depth = corto_entityAdmin_claimDepthFromId(objectId);
        uint16_t currentDepth = 0;
        int16_t priority = 0;

        /* If no session is set and security is enabled, deny access */
        if (!session_token) {
            return false;
        }

        /* '#' is the builtin token that is used internally by the API, and always
         * grants access. */
        if (session_token[0] == '#' &&
            session_token[1] == '\0')
        {
            return true;
        }

        ut_log_push_dbg(
            strarg("authorize:%s, %s",
                corto_action_kind_to_str(access),
                objectId));

        /* Walk over locks in the lock admin */
        corto_entityAdmin *admin = corto_entityAdmin_claim(&corto_lock_admin);
        do {
            int ep, e;
            for (ep = 0; ep < admin->entities[depth].length; ep ++) {
                corto_entityPerParent *perParent = &admin->entities[depth].buffer[ep];
                const char *expr;
                if (!(expr = ut_matchParent(perParent->parent, objectId))) {
                    continue;
                }

                for (e = 0; e < perParent->entities.length; e ++) {
                    corto_entity *entity = &perParent->entities.buffer[e];
                    corto_secure_lock lock = entity->e;
                    if (lock->query.select &&
                        *expr &&
                        !ut_expr(lock->query.select, expr))
                    {
                        ut_debug(
                            "skip lock '%s' for '%s' ('%s' does not match '%s')",
                            corto_fullpath(NULL, lock),
                            objectId,
                            lock->query.select,
                            expr);
                        continue;
                    }

                    /* Priority of lock must be at least of the same priority or
                     * higher than set value. */
                    if (lock->priority >= priority) {
                        /* More specific locks take precedence over less specific
                         * locks, unless priority is higher or a more specific
                         * lock returned UNDEFINED */
                        if ((allowed == CORTO_SECURE_ACCESS_UNDEFINED) ||
                            (currentDepth == depth) ||
                            (lock->priority > priority))
                        {
                            corto_secure_accessKind result;

                            result = corto_secure_lock_authorize(
                                lock, session_token, access);

                            ut_debug("eval '%s' result = '%s', priority = %d",
                                corto_fullpath(NULL, lock),
                                corto_access_kind_to_str(result),
                                lock->priority);

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
                                      active_lock = lock;
                                      ut_debug(
                                          "set active '%s' result = '%s', priority = %d",
                                          corto_fullpath(NULL, lock),
                                          corto_access_kind_to_str(allowed),
                                          lock->priority);
                                }
                            }
                        }
                    }
                }
            }
        } while (--depth >= 0);

        corto_entityAdmin_release(&corto_lock_admin);

        if (allowed == CORTO_SECURE_ACCESS_DENIED) {
            ut_ok(
                "#[red]deny#[normal] access to '%s' for session '%s' by '%s'",
                objectId,
                session_token,
                corto_fullpath(NULL, active_lock));
        } else {
            ut_trace(
                "#[green]allow#[normal] access to '%s' for session '%s' by '%s'",
                objectId,
                session_token,
                corto_fullpath(NULL, active_lock));
        }

        ut_log_pop_dbg();
    }

    return allowed != CORTO_SECURE_ACCESS_DENIED;
}

corto_string corto_secure_key_login_v(
    corto_secure_key this,
    const char *user,
    const char *password)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(user);
    CORTO_UNUSED(password);

    return NULL;
}

void corto_secure_key_logout_v(
    corto_secure_key this,
    const char *key)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(key);
}

int16_t corto_secure_key_construct(
    corto_secure_key this)
{
    if (corto_secure_keyInstance != NULL) {
        ut_throw("secure: a secure/key instance is already active");
        goto error;
    }

    /* Only allow setting key in the mainthread */
    if (corto_secure_mainThread != ut_thread_self()) {
        ut_throw("secure: may only create a secure/key instance in the mainthread");
        goto error;
    }

    corto_secure_keyInstance = this;
    return 0;
error:
    return -1;
}

void corto_secure_key_destruct(
    corto_secure_key this)
{
    CORTO_UNUSED(this);

    ut_trace("secure: delete key");
    corto_secure_keyInstance = NULL;

}
