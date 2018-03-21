/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_Security_setup(
    test_Security this)
{
    corto_void__create_auto(root_o, a);
    corto_void__create_auto(a, b);
    corto_void__create_auto(b, c);
    corto_int32__create_auto(a, d, 10);
    test_TestKey__create(NULL, NULL);
    corto_enable_security(true);
    test_assert(corto_secured() == true);
}

void test_Security_tc_login(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");

    token = corto_login("Marvin", "android");
    test_assert(token != NULL);
    test_assertstr(token, "token_user02");

}

void test_Security_tc_loginFail(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "41");
    test_assert(token == NULL);

}

void test_Security_tc_authorizeCreate(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    test_assertstr(token, "token_user01");
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_CREATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_void__create(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);
    corto_int16 ret = corto_delete(foo);
    test_assert(ret == 0);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDelete(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_DELETE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_void__create(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);
    corto_int16 ret = corto_delete(foo);
    test_assert(ret == 0);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedCreate(
    test_Security this)
{
    test_assert(corto_secured() == 1);

    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_CREATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_void__create(b, "foo");
    corto_release(b);
    test_assert(foo == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedDelete(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/foo", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_DELETE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_object foo = corto_void__create(b, "foo");
    corto_release(b);
    test_assert(foo != NULL);
    corto_int16 ret = corto_delete(foo);
    test_assert(ret != 0);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedLookup(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedResolve(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeResolveParentDenied(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedScopeClaim(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/c", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_objectseq seq = corto_scope_claim(b);
    int i;
    for (i = 0; i < seq.length; i ++) {
        test_assert(strcmp(corto_idof(seq.buffer[i]), "c"));
    }

    corto_scope_release(seq);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

int test_Security_tc_authorizeDeniedScopeWalk_walk(
    corto_object o,
    void *userData)
{
    test_assert(strcmp(corto_idof(o), "c"));
    return 1;
}

void test_Security_tc_authorizeDeniedScopeWalk(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b/c", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_int16 ret = corto_scope_walk(
        b, test_Security_tc_authorizeDeniedScopeWalk_walk, NULL);
    test_assert(ret == 1);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedSelect(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_iter iter;
    corto_int16 ret = corto_select(".").from("/a/b").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));
    ret = corto_select("b").from("/a").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));
    ret = corto_select("*")
        .from("/A").iter(&iter);
    test_assert(ret == 0);
    corto_resultIter__foreach(iter, result) {
        test_assert(strcmp(result.id, "b"));
    }

    ret = corto_select("..").from("/a/b/c").iter(&iter);
    test_assert(ret == 0);
    test_assert(!corto_iter_hasNext(&iter));
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedUpdate(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/d", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_int32 *d = corto_resolve(root_o, "/a/d");
    test_assert(d != NULL);
    corto_int16 ret = corto_int32__update(d, 20);
    test_assert(ret != 0);
    corto_release(d);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeDeniedUpdateVoid(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_int16 ret = corto_void__update(b);
    test_assert(ret != 0);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeLookup(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeResolve(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_object b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeSelect(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_iter iter;
    corto_int16 ret = corto_select(".").from("/a/b").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));
    corto_iter_release(&iter);
    ret = corto_select("b").from("/a").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));
    corto_iter_release(&iter);
    ret = corto_select("*")
        .from("/A").iter(&iter);
    test_assert(ret == 0);
    corto_int32 count = 0;
    corto_resultIter__foreach(iter, result) {
        if (!strcmp(result.id, "b")) {
            count ++;
        }

    }

    test_assertint(count, 1);
    ret = corto_select("..").from("/a/b/c").iter(&iter);
    test_assert(ret == 0);
    test_assert(corto_iter_hasNext(&iter));
    corto_iter_release(&iter);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeUpdate(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/d", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_int32 *d = corto_resolve(root_o, "/a/d");
    test_assert(d != NULL);
    corto_int16 ret = corto_int32__update(d, 20);
    test_assert(ret == 0);
    corto_release(d);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_authorizeUpdateVoid(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r = {"token_user01", CORTO_SECURE_ACTION_UPDATE, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r);
    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_int16 ret = corto_void__update(b);
    test_assert(ret == 0);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantLowerDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantLowerDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantLowerDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantSameDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantSameDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyGrantSameDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedLowerDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedLowerDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedLowerDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedSameDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedSameDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyUndefinedSameDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenyLowerDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenyLowerDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenyLowerDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenySameDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenySameDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockGrantDenySameDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockSwitchUser(
    test_Security this)
{
    test_TestLock l = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule r1 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(l->rules, &r1);
    test_AccessRule r2 = {"token_user02", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(l->rules, &r2);
    const char *token1 = corto_login("Ford Prefect", "42");
    test_assert(token1 != NULL);
    const char *prev = corto_set_session(token1);
    test_assert(prev == NULL);
    corto_int32 *b = corto_resolve(root_o, "/a/b");
    test_assert(b != NULL);
    corto_release(b);
    const char *token2 = corto_login("Marvin", "android");
    test_assert(token2 != NULL);
    prev = corto_set_session(token2);
    test_assert(prev == token1);
    b = corto_resolve(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token2);
}

void test_Security_tc_lockUndefinedDenyLowerDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockUndefinedDenyLowerDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockUndefinedDenyLowerDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a", "b", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockUndefinedDenySameDepthHigherPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockUndefinedDenySameDepthLowerPrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 1, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockUndefinedDenySameDepthSamePrio(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock upper = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule uR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(upper->rules, &uR);
    test_TestLock lower = test_TestLock__create(NULL, NULL, "/a/b", ".", 0, NULL);
    test_AccessRule lR = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_UNDEFINED};
    test_AccessRuleList__insert(lower->rules, &lR);
    corto_int32 *b = corto_lookup(root_o, "/a/b");
    test_assert(b == NULL);
    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyTreeGrantSelectScope(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock lock1 = test_TestLock__create(NULL, NULL, "/a", "//", 0, NULL);
    test_AccessRule rule1 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lock1->rules, &rule1);

    test_TestLock lock2 = test_TestLock__create(NULL, NULL, "/a/b", "/", 0, NULL);
    test_AccessRule rule2 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lock2->rules, &rule2);

    corto_iter it;
    test_assert(corto_select("*").from("/a/b").iter(&it) == 0);

    test_assert(corto_iter_hasNext(&it) != 0);
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "c");
    test_assertstr(r->type, "void");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it) == 0);

    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyTreeGrantScopeSelectThis(
    test_Security this)
{
    const char *token = corto_login("Ford Prefect", "42");
    test_assert(token != NULL);
    const char *prev = corto_set_session(token);
    test_assert(prev == NULL);

    test_TestLock lock1 = test_TestLock__create(NULL, NULL, "/a", "//", 0, NULL);
    test_AccessRule rule1 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_DENIED};
    test_AccessRuleList__insert(lock1->rules, &rule1);

    test_TestLock lock2 = test_TestLock__create(NULL, NULL, "/a/b", "/", 0, NULL);
    test_AccessRule rule2 = {"token_user01", CORTO_SECURE_ACTION_READ, CORTO_SECURE_ACCESS_GRANTED};
    test_AccessRuleList__insert(lock2->rules, &rule2);

    corto_iter it;
    test_assert(corto_select(".").from("/a/b").iter(&it) == 0);
    test_assert(corto_iter_hasNext(&it) == 0);

    prev = corto_set_session(prev);
    test_assert(prev == token);
}

void test_Security_tc_lockDenyTreeSelectMount(
    test_Security this)
{
    corto_enable_security(false);
}

void test_Security_teardown(
    test_Security this)
{
    corto_enable_security(false);
}
