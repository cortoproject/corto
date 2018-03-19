/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_secure_accessKind test_TestLock_authorize(
    test_TestLock this,
    const char *token,
    corto_secure_actionKind action)
{
    if (token) {
        corto_iter it = corto_ll_iter(this->rules);
        while (corto_iter_hasNext(&it)) {
            test_AccessRule *r = corto_iter_next(&it);
            if (!strcmp(r->user, token) && (r->action == action)) {
                return r->access;
            }
        }
    }

    return CORTO_SECURE_ACCESS_UNDEFINED;
}

int16_t test_TestLock_construct(
    test_TestLock this)
{
    corto_set_str(&this->super.query.select, this->expr);
    corto_set_str(&this->super.query.from, this->mount);
    this->super.priority = this->priority;
    return corto_secure_lock_construct(this);
}
