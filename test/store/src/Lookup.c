/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


int tc_lookupAllWalk(corto_object o, void *ctx) {
    CORTO_UNUSED(ctx);
    corto_id id;
    corto_object r;

    if (corto_typeof(o) != corto_unknown_o) {
        corto_path(id, NULL, o, "/");
        r = corto_lookup(NULL, id);

        /* Set errormessage to ease debugging */
        if (!r) {
            corto_error("failed to lookup %s (%s, %p, root = %p)", id);
        }
        test_assert(r != NULL);
        test_assert(r == o);
        corto_release(r);
    }

    corto_objectseq scope = corto_scope_claim(o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_lookupAllWalk(scope.buffer[i], NULL);
    }
    corto_scope_release(scope);

    return 1;
}

void test_Lookup_tc_lookupAll(
    test_Lookup this)
{
    corto_objectseq scope = corto_scope_claim(root_o);
    int i;
    for (i = 0; i < scope.length; i ++) {
        tc_lookupAllWalk(scope.buffer[i], NULL);
    }
    corto_scope_release(scope);
}

void test_Lookup_tc_lookupCaseInsensitive(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "COrTO");
    test_assert(o != NULL);
    test_assert(o == corto_o);
    corto_release(o);

}

void test_Lookup_tc_lookupEmptyString(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "");
    test_assert (o == NULL);
    test_assert(corto_catch());
}

void test_Lookup_tc_lookupFunctionArgs(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "test/functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

}

void test_Lookup_tc_lookupFunctionNoArgs(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "test/functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

}

void test_Lookup_tc_lookupIdFromNull(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

}

void test_Lookup_tc_lookupIdFromRoot(
    test_Lookup this)
{

    corto_object o = corto_lookup(root_o, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

}

void test_Lookup_tc_lookupIdFromScope(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_vstore_o, "mount");
    test_assert(o != NULL);
    test_assert(o != corto_word_o);

}

void test_Lookup_tc_lookupNested2FromNull(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "corto/vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Lookup_tc_lookupNested2FromRoot(
    test_Lookup this)
{

    corto_object o = corto_lookup(root_o, "corto/vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Lookup_tc_lookupNested2FromScope(
    test_Lookup this)
{

    corto_object parent = corto_create(corto_o, "parent", corto_void_o);
    corto_object child = corto_create(parent, "child", corto_void_o);
    corto_object grandchild = corto_create(child, "grandchild", corto_void_o);

    corto_object o = corto_lookup(corto_o, "parent/child/grandchild");
    test_assert(o != NULL);
    test_assert(o == grandchild);

    corto_release(o);
    corto_delete(parent);

}

void test_Lookup_tc_lookupNestedFromNull(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "corto/vstore");
    test_assert(o != NULL);
    test_assert(o == corto_vstore_o);

}

void test_Lookup_tc_lookupNestedFromRoot(
    test_Lookup this)
{

    corto_object o = corto_lookup(root_o, "corto/vstore");
    test_assert(o != NULL);
    test_assert(o == corto_vstore_o);

}

void test_Lookup_tc_lookupNestedFromScope(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_o, "vstore/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

}

void test_Lookup_tc_lookupNull(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, NULL);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_Lookup_tc_lookupParent(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_lang_o, "..");
    test_assert(o == corto_o);
    corto_release(o);

}

void test_Lookup_tc_lookupParentAfterExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_o, "lang/class/..");
    test_assert(o == corto_lang_o);
    corto_release(o);

}

void test_Lookup_tc_lookupParentBeforeExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_class_o, "../method");
    test_assert(o == corto_method_o);
    corto_release(o);

}

void test_Lookup_tc_lookupParenthesesNoFunction(
    test_Lookup this)
{

    corto_object o = corto_void__create(root_o, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));

    corto_object p = corto_lookup(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

}

void test_Lookup_tc_lookupParenthesesNoFunctionArgs(
    test_Lookup this)
{

    corto_object o = corto_void__create(root_o, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

}

void test_Lookup_tc_lookupParenthesesNoFunctionArgsScoped(
    test_Lookup this)
{
    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "/parent/o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

}

void test_Lookup_tc_lookupParenthesesNoFunctionMatchingArgs(
    test_Lookup this)
{

    corto_object o = corto_void__create(root_o, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);

}

void test_Lookup_tc_lookupParenthesesNoFunctionMatchingArgsScoped(
    test_Lookup this)
{
    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "/parent/o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);
    corto_delete(parent);

}

void test_Lookup_tc_lookupParenthesesNoFunctionScoped(
    test_Lookup this)
{
    corto_id id;

    corto_object parent = corto_void__create(root_o, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_void__create(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));
    test_assert(!strcmp(corto_fullpath(id, o), "/parent/o()"));

    corto_object p = corto_lookup(NULL, "/parent/o()");
    test_assert(p != NULL);
    test_assert(p == o);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

}

void test_Lookup_tc_lookupParentInExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_lang_o, "class/../method");
    test_assert(o == corto_method_o);
    corto_release(o);

}

void test_Lookup_tc_lookupRoot(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "/");
    test_assert (o == root_o);
    corto_release(o);

}

void test_Lookup_tc_lookupThis(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    corto_release(o);

}

void test_Lookup_tc_lookupThisAfterExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(NULL, "corto/vstore/.");
    test_assert(o == corto_vstore_o);
    corto_release(o);

}

void test_Lookup_tc_lookupThisBeforeExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_vstore_o, "./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

}

void test_Lookup_tc_lookupThisInExpr(
    test_Lookup this)
{

    corto_object o = corto_lookup(corto_o, "vstore/./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

}

void test_Lookup_tc_lookupNoResume(
    test_Lookup this)
{
    corto_object world = corto_create(root_o, "hello/world", corto_int32_o);
    test_assert(world != NULL);
    test_assert(corto_typeof(world) == (corto_type)corto_int32_o);
    test_assert(corto_countof(world) == 1);

    corto_object hello = corto_parentof(world);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_unknown_o);
    test_assert(corto_countof(hello) == 1);

    /* Should not be able to lookup unknown object */
    corto_object o = corto(CORTO_LOOKUP, {.parent = root_o, .id = "hello"});
    test_assert(o != NULL);
    test_assert(o == hello);
    test_assert(corto_countof(o) == 2);
    corto_release(o);

    test_assert(corto_delete(world) == 0);
}

void test_Lookup_tc_lookupUnknown(
    test_Lookup this)
{
    corto_object world = corto_create(root_o, "hello/world", corto_int32_o);
    test_assert(world != NULL);
    test_assert(corto_typeof(world) == (corto_type)corto_int32_o);
    test_assert(corto_countof(world) == 1);

    corto_object hello = corto_parentof(world);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_unknown_o);
    test_assert(corto_countof(hello) == 1);

    /* Should not be able to lookup unknown object */
    corto_object o = corto_lookup(root_o, "hello");
    test_assert(o == NULL);
    test_assert(corto_countof(hello) == 1);

    test_assert(corto_delete(world) == 0);
}

void test_Lookup_tc_lookupAnonymous(
    test_Lookup this)
{
    corto_object o = corto_resolve(NULL, "corto/lang/string{\"Hello World\"}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)corto_string_o);

    corto_string s = *(corto_string*)o;
    test_assertstr(s, "Hello World");

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousAnonymousType(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "corto/lang/list{int32}{1, 2, 3}");
    test_assert(o != NULL);

    corto_type t = corto_typeof(o);
    test_assert(t->kind == CORTO_COLLECTION);
    test_assert(corto_collection(t)->kind == CORTO_LIST);
    test_assert(corto_collection(t)->elementType == corto_type(corto_int32_o));

    corto_ll l = *(corto_ll*)o;
    test_assert(corto_ll_count(l) == 3);
    test_assertint((corto_int32)(corto_word)corto_ll_get(l, 0), 1);
    test_assertint((corto_int32)(corto_word)corto_ll_get(l, 1), 2);
    test_assertint((corto_int32)(corto_word)corto_ll_get(l, 2), 3);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNested(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "test/Point{10, 20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_Point_o);

    test_Point *p = o;
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithKeys(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "test/Point{y=10, x=20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_Point_o);

    test_Point *p = o;
    test_assertint(p->x, 20);
    test_assertint(p->y, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithRefRelativeToParent(
    test_Lookup this)
{
    corto_object data = corto_lookup(NULL, "data");
    test_assert(data != NULL);

    corto_object nested = corto_create(root_o, "data/nested", corto_void_o);
    test_assert(nested != NULL);
    test_assert(corto_parentof(nested) == data);
    test_assertstr(corto_idof(nested), "nested");

    corto_object o = corto_lookup(data, "/test/ReferenceMember{nested, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == nested);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithRefCorto(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "test/ReferenceMember{lang, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == corto_lang_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithRefLang(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "test/ReferenceMember{int32, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == corto_int32_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithRefNested(
    test_Lookup this)
{
    corto_object nested = corto_create(root_o, "/data/nested", corto_void_o);
    test_assert(nested != NULL);
    test_assertstr(corto_idof(nested), "nested");

    corto_object o = corto_lookup(NULL, "test/ReferenceMember{/data/nested, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == nested);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousNestedWithRefRoot(
    test_Lookup this)
{
    corto_object o = corto_lookup(NULL, "test/ReferenceMember{/, 10}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);

    test_ReferenceMember *p = o;
    test_assert(p->m == root_o);
    test_assertint(p->n, 10);

    corto_release(o);
}

void test_Lookup_tc_lookupAnonymousWithPartialMatch(
    test_Lookup this)
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

    corto_object o = corto_lookup(root_o, "data/Point{10,20}");
    test_assert(o != NULL);

    test_assert(corto_typeof(o) == (corto_type)s);

    test_Point *p = o;
    test_assertint(p->x, 10);
    test_assertint(p->y, 20);

    corto_release(o);
}

void test_Lookup_tc_lookupDot(
    test_Lookup this)
{
    corto_create(data_o, "foo", corto_void_o);
    corto_object obj = corto_lookup(NULL, "data.foo");
    test_assert(obj != NULL);

    test_assertstr(corto_idof(obj), "foo");
    test_assertstr(corto_fullpath(NULL, obj), "/data/foo");

    test_assert(corto_release(obj) == 1);
}

void test_Lookup_tc_lookupDotNested(
    test_Lookup this)
{
    corto_create(data_o, "foo/bar", corto_void_o);
    corto_object obj = corto_lookup(NULL, "data.foo.bar");
    test_assert(obj != NULL);

    test_assertstr(corto_idof(obj), "bar");
    test_assertstr(corto_fullpath(NULL, obj), "/data/foo/bar");

    test_assert(corto_release(obj) == 1);
}
