/* $CORTO_GENERATED
 *
 * Lookup.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

/* $header(test/Lookup/tc_lookupAll) */
int tc_lookupAllWalk(corto_object o, void *udata) {
    CORTO_UNUSED(udata);
    corto_id id;
    corto_object r;

    corto_path(id, NULL, o, "/");
    r = corto_lookup(NULL, id);

    /* Set errormessage to ease debugging */
    if (!r) corto_seterr("failed to lookup %s", id);
    test_assert(r != NULL);
    test_assert(r == o);
    corto_release(r);

    corto_objectseq scope = corto_scopeClaim(o);
    corto_objectseqForeach(scope, child) {
        tc_lookupAllWalk(child, NULL);
    }
    corto_scopeRelease(scope);

    return 1;
}
/* $end */
corto_void _test_Lookup_tc_lookupAll(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupAll) */
    corto_objectseq scope = corto_scopeClaim(root_o);
    corto_objectseqForeach(scope, o) {
        tc_lookupAllWalk(o, NULL);
    }
    corto_scopeRelease(scope);
/* $end */
}

corto_void _test_Lookup_tc_lookupCaseInsensitive(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupCaseInsensitive) */

    corto_object o = corto_lookup(NULL, "COrTO");
    test_assert(o != NULL);
    test_assert(o == corto_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupEmptyString(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupEmptyString) */

    corto_object o = corto_lookup(NULL, "");
    test_assert (o == NULL);
    test_assertstr(corto_lasterr(), "invalid identifier");

/* $end */
}

corto_void _test_Lookup_tc_lookupFunctionArgs(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupFunctionArgs) */

    corto_object o = corto_lookup(NULL, "test/functionToResolve(int32,int32)");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupFunctionNoArgs(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupFunctionNoArgs) */

    corto_object o = corto_lookup(NULL, "test/functionToResolve");
    test_assert(o != NULL);
    test_assert(o == test_functionToResolve_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupIdFromNull(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupIdFromNull) */

    corto_object o = corto_lookup(NULL, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupIdFromRoot(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupIdFromRoot) */

    corto_object o = corto_lookup(root_o, "corto");
    test_assert(o != NULL);
    test_assert(o == corto_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupIdFromScope(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupIdFromScope) */

    corto_object o = corto_lookup(corto_core_o, "mount");
    test_assert(o != NULL);
    test_assert(o != corto_word_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNested2FromNull(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNested2FromNull) */

    corto_object o = corto_lookup(NULL, "corto/core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNested2FromRoot(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNested2FromRoot) */

    corto_object o = corto_lookup(root_o, "corto/core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNested2FromScope(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNested2FromScope) */

    corto_object parent = corto_createChild(corto_o, "parent", corto_void_o);
    corto_object child = corto_createChild(parent, "child", corto_void_o);
    corto_object grandchild = corto_createChild(child, "grandchild", corto_void_o);

    corto_object o = corto_lookup(corto_o, "parent/child/grandchild");
    test_assert(o != NULL);
    test_assert(o == grandchild);

    corto_release(o);
    corto_delete(parent);

/* $end */
}

corto_void _test_Lookup_tc_lookupNestedFromNull(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNestedFromNull) */

    corto_object o = corto_lookup(NULL, "corto/core");
    test_assert(o != NULL);
    test_assert(o == corto_core_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNestedFromRoot(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNestedFromRoot) */

    corto_object o = corto_lookup(root_o, "corto/core");
    test_assert(o != NULL);
    test_assert(o == corto_core_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNestedFromScope(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNestedFromScope) */

    corto_object o = corto_lookup(corto_o, "core/mount");
    test_assert(o != NULL);
    test_assert(o == corto_mount_o);

/* $end */
}

corto_void _test_Lookup_tc_lookupNull(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupNull) */

    corto_object o = corto_lookup(NULL, NULL);
    test_assert(o == NULL);
    test_assertstr(corto_lasterr(), "invalid identifier");

/* $end */
}

corto_void _test_Lookup_tc_lookupParent(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParent) */

    corto_object o = corto_lookup(corto_lang_o, "..");
    test_assert(o == corto_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupParentAfterExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParentAfterExpr) */

    corto_object o = corto_lookup(corto_o, "lang/class/..");
    test_assert(o == corto_lang_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupParentBeforeExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParentBeforeExpr) */

    corto_object o = corto_lookup(corto_class_o, "../method");
    test_assert(o == corto_method_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunction(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunction) */

    corto_object o = corto_voidCreateChild(NULL, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));

    corto_object p = corto_lookup(NULL, "o()");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunctionArgs(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunctionArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_release(p);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunctionArgsScoped(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunctionArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "/parent/o(uint32 a)");
    test_assert(p != NULL);
    test_assert(o == p);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunctionMatchingArgs(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunctionMatchingArgs) */

    corto_object o = corto_voidCreateChild(NULL, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunctionMatchingArgsScoped(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunctionMatchingArgsScoped) */
    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o(uint32 a)");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o(uint32 a)"));
    test_assert(!strcmp(corto_fullpath(NULL, o), "/parent/o(uint32 a)"));

    corto_object p = corto_lookup(NULL, "/parent/o(uint16 a)");
    test_assert(p == NULL);

    corto_delete(o);
    corto_delete(parent);

/* $end */
}

corto_void _test_Lookup_tc_lookupParenthesesNoFunctionScoped(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParenthesesNoFunctionScoped) */
    corto_id id;

    corto_object parent = corto_voidCreateChild(NULL, "parent");
    test_assert(parent != NULL);

    corto_object o = corto_voidCreateChild(parent, "o()");
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o()"));
    test_assert(!strcmp(corto_fullpath(id, o), "/parent/o()"));

    corto_object p = corto_lookup(NULL, "/parent/o()");
    test_assert(p != NULL);
    test_assert(p == o);

    corto_delete(o);
    corto_delete(parent);
    corto_release(p);

/* $end */
}

corto_void _test_Lookup_tc_lookupParentInExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupParentInExpr) */

    corto_object o = corto_lookup(corto_lang_o, "class/../method");
    test_assert(o == corto_method_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupRoot(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupRoot) */

    corto_object o = corto_lookup(NULL, "/");
    test_assert (o == root_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupThis(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupThis) */

    corto_object o = corto_lookup(corto_lang_o, ".");
    test_assert(o == corto_lang_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupThisAfterExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupThisAfterExpr) */

    corto_object o = corto_lookup(NULL, "corto/core/.");
    test_assert(o == corto_core_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupThisBeforeExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupThisBeforeExpr) */

    corto_object o = corto_lookup(corto_core_o, "./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

/* $end */
}

corto_void _test_Lookup_tc_lookupThisInExpr(
    test_Lookup this)
{
/* $begin(test/Lookup/tc_lookupThisInExpr) */

    corto_object o = corto_lookup(corto_o, "core/./mount");
    test_assert(o == corto_mount_o);
    corto_release(o);

/* $end */
}
