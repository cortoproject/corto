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

void test_Lookup_tc_lookupIdEndsWithDot(
    test_Lookup this)
{

    corto_object o = corto_create(root_o, "dot.", corto_void_o);
    test_assert(o != NULL);

    corto_object l = corto_lookup(root_o, "dot.");
    test_assert(l != NULL);
    test_assert(l == o);

    corto_release(o);
    corto_release(l);

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

void test_Lookup_tc_lookupIdStartsWithDot(
    test_Lookup this)
{

    corto_object o = corto_create(root_o, ".dot", corto_void_o);
    test_assert(o != NULL);

    corto_object l = corto_lookup(root_o, ".dot");
    test_assert(l != NULL);
    test_assert(l == o);

    corto_release(o);
    corto_release(l);

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
