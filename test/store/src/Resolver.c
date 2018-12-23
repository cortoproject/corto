/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Resolver_setup(
    test_Resolver this)
{

}

void test_Resolver_tc_caseInsensitive(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "COrTO");
    test_assert(o != NULL);
    test_assert(o == corto_o);
    corto_release(o);

}


int tc_resolveAllWalk(corto_object o, void *ctx) {
    CORTO_UNUSED(ctx);
    corto_id id;
    corto_object r;

    if (corto_typeof(o) != corto_unknown_o) {
        corto_fullpath(id, o);
        r = corto_resolve(NULL, id);

        /* Set errormessage to ease debugging */
        if (!r) ut_error("failed to resolve %s", id);
        test_assert(r != NULL);
        if (r != o) {
            ut_throw("got %s, expected %s",
              corto_fullpath(NULL, r),
              corto_fullpath(NULL, o));
        }
        test_assert(r == o);
        corto_release(r);
    }

    corto_objectseq scope = corto_scope_claim(o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_resolveAllWalk(scope.buffer[i], NULL);
    }
    corto_scope_release(scope);

    return 1;
}

void test_Resolver_tc_resolveAll(
    test_Resolver this)
{
    corto_objectseq scope = corto_scope_claim(root_o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_resolveAllWalk(scope.buffer[i], NULL);
    }
    corto_scope_release(scope);
}

void test_Resolver_tc_resolveAnonymous(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "string{\"Hello World\"}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)corto_string_o);

    corto_string s = *(corto_string*)o;
    test_assertstr(s, "Hello World");

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNested(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "/test/Point{10,20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_Point_o);

    test_Point *p = o;
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithKeys(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "test/Point{y=10, x=20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_Point_o);

    test_Point *p = o;
    test_assertint(p->x, 20);
    test_assertint(p->y, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithRefCorto(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "test/ReferenceMember{lang, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == corto_lang_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithRefNested(
    test_Resolver this)
{
    corto_object nested = corto_create(root_o, "data/nested", corto_void_o);
    corto_object o = corto_resolve(NULL, "test/ReferenceMember{/data/nested, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == nested);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithRefRoot(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "test/ReferenceMember{/, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == root_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithRefLang(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "test/ReferenceMember{int32, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == corto_int32_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousNestedWithRefRelativeToParent(
    test_Resolver this)
{
    corto_object data = corto_lookup(NULL, "data");
    test_assert(data != NULL);

    corto_object nested = corto_create(root_o, "data/nested", corto_void_o);
    corto_object o = corto_resolve(data, "test/ReferenceMember{nested, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == nested);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousAnonymousType(
    test_Resolver this)
{
    corto_object o = corto_resolve(NULL, "list{int32}{1, 2, 3}");
    test_assert(o != NULL);

    corto_type t = corto_typeof(o);
    test_assert(t->kind == CORTO_COLLECTION);
    test_assert(corto_collection(t)->kind == CORTO_LIST);
    test_assert(corto_collection(t)->element_type == corto_type(corto_int32_o));

    ut_ll l = *(ut_ll*)o;
    test_assert(ut_ll_count(l) == 3);
    test_assertint((corto_int32)(corto_word)ut_ll_get(l, 0), 1);
    test_assertint((corto_int32)(corto_word)ut_ll_get(l, 1), 2);
    test_assertint((corto_int32)(corto_word)ut_ll_get(l, 2), 3);

    corto_release(o);
}

void test_Resolver_tc_resolveAnonymousWithPartialMatch(
    test_Resolver this)
{
    /* Create isolated scope with partial match */
    corto_object partial = corto_create(
        root_o, "data/PointPartial", corto_void_o);
    test_assert(partial != NULL);

    /* Create type with same layout as test/Point */
    corto_struct s = corto_declare(root_o, "data/Point", corto_struct_o);
    test_assert(s != NULL);
    corto_member x = corto_declare(s, "x", corto_member_o);
    x->type = (corto_type)corto_int32_o;
    test_assert(corto_define(x) == 0);
    corto_member y = corto_declare(s, "y", corto_member_o);
    y->type = (corto_type)corto_int32_o;
    test_assert(corto_define(y) == 0);
    test_assert(corto_define(s) == 0);

    corto_object o = corto_resolve(root_o, "data/Point{10,20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)s);

    test_Point *p = o;
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    corto_release(o);
}

void test_Resolver_tc_resolveCorto(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "corto");
    test_assert (o == corto_o);
    corto_release(o);

}

void test_Resolver_tc_resolveEmptyString(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "");
    test_assert (o == NULL);
    if (o) corto_release(o);

}

void test_Resolver_tc_resolveFunctionArgs(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "test/functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

}

void test_Resolver_tc_resolveFunctionNoArgs(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "test/functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

}

void test_Resolver_tc_resolveG(
    test_Resolver this)
{

    /* Start loader mount */
    corto_object o = corto_resolve(NULL, "g");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_idof(o), "g"));
    test_assert (corto_parentof(o) == corto_o);
    corto_release(o);

}

void test_Resolver_tc_resolveIdFromNull(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

}

void test_Resolver_tc_resolveIdFromRoot(
    test_Resolver this)
{

    corto_object o = corto_resolve(root_o, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

}

void test_Resolver_tc_resolveIdFromScope(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_vstore_o, "mount");
    test_assert(o != NULL);
    test_assert(o != corto_word_o);

}

void test_Resolver_tc_resolveLang(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "lang");
    test_assert(o != NULL);
    test_assert (!strcmp(corto_idof(o), "lang"));
    test_assert (o == corto_lang_o);
    corto_release(o);

}

void test_Resolver_tc_resolveNested2FromNull(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "corto/vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Resolver_tc_resolveNested2FromRoot(
    test_Resolver this)
{

    corto_object o = corto_resolve(root_o, "corto/vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Resolver_tc_resolveNested2FromScope(
    test_Resolver this)
{

    corto_object parent = corto_create(corto_o, "parent", corto_void_o);
    corto_object child = corto_create(parent, "child", corto_void_o);
    corto_object grandchild = corto_create(child, "grandchild", corto_void_o);

    corto_object o = corto_resolve(corto_o, "parent/child/grandchild");
    test_assert(o != NULL);
    test_assert(o == grandchild);

    corto_release(o);
    corto_delete(parent);

}

void test_Resolver_tc_resolveNestedFromNull(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "corto/vstore");
    test_assert(o != NULL);
    test_assert(o == corto_vstore_o);

}

void test_Resolver_tc_resolveNestedFromRoot(
    test_Resolver this)
{

    corto_object o = corto_resolve(root_o, "corto/vstore");
    test_assert(o != NULL);
    test_assert(o == corto_vstore_o);

}

void test_Resolver_tc_resolveNestedFromScope(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_o, "vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Resolver_tc_resolveNull(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, NULL);
    test_assert (o == NULL);

}

void test_Resolver_tc_resolveObjectAFromScopeWithFunctionA(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_o, "/corto/lang/class/construct");
    test_assert(o != NULL);
    test_assertstr("/corto/lang/class/construct", corto_fullpath(NULL, o));

}

void test_Resolver_tc_resolveParent(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_lang_o, "..");
    test_assert(o == corto_o);
    corto_release(o);

}

void test_Resolver_tc_resolveParentAfterExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_o, "lang/class/..");
    test_assert(o == corto_lang_o);
    corto_release(o);

}

void test_Resolver_tc_resolveParentBeforeExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_class_o, "../method");
    test_assert(o == corto_method_o);
    corto_release(o);

}

void test_Resolver_tc_resolveParenthesesNoFunction(
    test_Resolver this)
{

    corto_object o = corto_void__create(root_o, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));

    corto_object p = corto_resolve(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

}

void test_Resolver_tc_resolveParenthesesNoFunctionArgs(
    test_Resolver this)
{

    corto_object o = corto_void__create(root_o, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

}

void test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(
    test_Resolver this)
{
    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

}

void test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(
    test_Resolver this)
{

    corto_object o = corto_void__create(root_o, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);

}

void test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(
    test_Resolver this)
{
    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_resolve(NULL, "/parent/o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);
    corto_delete(parent);

}

void test_Resolver_tc_resolveParenthesesNoFunctionScoped(
    test_Resolver this)
{
    corto_id id;

    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));
    test_assert(!strcmp(corto_fullpath(id, o), "/parent/o()"));

    corto_object p = corto_resolve(NULL, "/parent/o()");
    test_assert(p != NULL);
    test_assert(p == o);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

}

void test_Resolver_tc_resolveParentInExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_lang_o, "class/../method");
    test_assert(o == corto_method_o);
    corto_release(o);

}

void test_Resolver_tc_resolveRoot(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "/");
    test_assert (o == root_o);
    corto_release(o);

}

void test_Resolver_tc_resolveString(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "string");
    test_assert (o == corto_string_o);
    corto_release(o);

}

void test_Resolver_tc_resolveThis(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    corto_release(o);

}

void test_Resolver_tc_resolveThisAfterExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(NULL, "corto/vstore/.");
    test_assert(o == corto_vstore_o);
    corto_release(o);

}

void test_Resolver_tc_resolveThisBeforeExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_vstore_o, "./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

}

void test_Resolver_tc_resolveThisInExpr(
    test_Resolver this)
{

    corto_object o = corto_resolve(corto_o, "vstore/./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

}

void test_Resolver_teardown(
    test_Resolver this)
{

}
