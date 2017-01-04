/* $CORTO_GENERATED
 *
 * ReplicatorRequest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_ReplicatorRequest_setup(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/setup) */

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create mount */
    this->mount = test_ListReplicatorCreate(a_o, CORTO_ON_SCOPE, CORTO_SOURCE);

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectGrandparentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectGrandparentFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "../..").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "/corto/core/package");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectParentFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectParentFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "..").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "");
    test_assertstr(result->parent, "..");
    test_assertstr(result->type, "/corto/core/package");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectParentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectParentFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "..").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "void");

    test_assert(!corto_iterHasNext(&iter));
/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilter(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilter) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/*z").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilterFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilterFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "*z").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilterFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilterFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "*c").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));
/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeMixed(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeMixed) */
    corto_result *result;
    corto_iter iter;

    /* Create additional three objects in scope of a */
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    corto_voidCreateChild(a, "b");
    corto_voidCreateChild(a, "bc");
    corto_voidCreateChild(a, "abc");
    corto_release(a);

    corto_int16 ret = corto_select("/", "a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "b");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNested(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNested) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/xyz/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirty(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirty) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/../a/./xyz/./*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirtyFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirtyFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "../a/./xyz/./*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirtyFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirtyFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "../../a/../a/./xyz/./abc/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "abc/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingle(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingle) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleFromScopeTree(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleFromScopeTree) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "//foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "bc").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNested(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNested) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "a/xyz/abc").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNestedFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNestedFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz/bc").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNestedFromScopeTree(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNestedFromScopeTree) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz//foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNestedFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNestedFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "abc/foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleTree(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleTree) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "//a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleTree2(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleTree2) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "//foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleTree3(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleTree3) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/", "//hello").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "a/xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTree(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTree) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "//").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "b");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "c");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeEmptyNestedScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeEmptyNestedScope) */
    corto_object b_o = corto_createChild(root_o, "b", corto_void_o);
    test_assert(b_o != NULL);

    corto_object mount_o = corto_createChild(b_o, "mount", corto_void_o);
    test_assert(mount_o != NULL);

    corto_object child_o = corto_createChild(b_o, "mount2", corto_void_o);
    test_assert(child_o != NULL);

    /* Empty mount that sets userdata of iterator - this touches a sensitive
     * part of corto_select that could accidentally interpret iterator userdata
     * the wrong way, which would result in a crash. */
    test_MountWIterData m = test_MountWIterDataCreate(mount_o);
    test_assert(m != NULL);

    corto_iter it;
    corto_int16 ret = corto_select("/b", "//").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    corto_result *r = corto_iterNext(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount");
    test_assert(corto_iterHasNext(&it));
    r = corto_iterNext(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount2");
    test_assert(!corto_iterHasNext(&it));

    ret = corto_delete(m);
    test_assert(ret == 0);

    ret = corto_delete(b_o);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeEmptyScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeEmptyScope) */
    corto_object b_o = corto_createChild(root_o, "b", corto_void_o);
    test_assert(b_o != NULL);

    corto_object mount_o = corto_createChild(b_o, "mount", corto_void_o);
    test_assert(mount_o != NULL);

    /* Empty mount that sets userdata of iterator - this touches a sensitive
     * part of corto_select that could accidentally interpret iterator userdata
     * the wrong way, which would result in a crash. */
    test_MountWIterData m = test_MountWIterDataCreate(mount_o);
    test_assert(m != NULL);

    corto_iter it;
    corto_int16 ret = corto_select("/b", "//").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&it));
    corto_result *r = corto_iterNext(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount");
    test_assert(!corto_iterHasNext(&it));

    ret = corto_delete(m);
    test_assert(ret == 0);

    ret = corto_delete(b_o);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeFromNestedScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeFromNestedScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz/abc", "//").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeFromScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz", "//").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeFromVirtualNestedScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeFromVirtualNestedScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz/abc//").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectTreeFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectTreeFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "xyz//").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectVirtualGrandparentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectVirtualGrandparentFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz/abc/foo", "../..").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "../../..");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectVirtualParentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectVirtualParentFromVirtualScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a/xyz/abc/foo", "..").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_teardown(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/teardown) */

    corto_delete(this->mount);
    this->mount = NULL;

/* $end */
}
