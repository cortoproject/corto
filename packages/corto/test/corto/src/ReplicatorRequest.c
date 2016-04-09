/* $CORTO_GENERATED
 *
 * ReplicatorRequest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_ReplicatorRequest_setup(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/setup) */

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create mount */
    this->mount = test_ListReplicatorCreate(a_o, 0, CORTO_SOURCE);

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectGrandparentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectGrandparentFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "../..").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, ""));
    test_assert(!strcmp(result->parent, "../.."));
    test_assert(!strcmp(result->type, "/corto/core/package"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectParentFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectParentFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "..").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, ""));
    test_assert(!strcmp(result->parent, ".."));
    test_assert(!strcmp(result->type, "/corto/core/package"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectParentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectParentFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "..").iter(&ret);
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "../.."));
    test_assert(!strcmp(result->type, "void"));

    test_assert(!corto_iterHasNext(&iter));
/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "string"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilter(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilter) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/*z").iter( &ret );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "string"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilterFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilterFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "*z").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "yz"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "string"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFilterFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFilterFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "*c").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "yz"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "string"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));
/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeMixed(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeMixed) */
    corto_result *result;
    corto_int16 ret = 0;

    /* Create additional three objects in scope of a */
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    corto_voidCreateChild(a, "b");
    corto_voidCreateChild(a, "bc");
    corto_voidCreateChild(a, "abc");
    corto_release(a);

    corto_iter iter = corto_select("/", "a/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "void"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "yz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "string"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNested(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNested) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/xyz/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirty(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirty) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/../a/./xyz/./*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirtyFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirtyFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "../a/./xyz/./*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedDirtyFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedDirtyFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "../../a/../a/./xyz/./abc/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "foo"));
    test_assert(!strcmp(result->parent, "abc"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bar"));
    test_assert(!strcmp(result->parent, "abc"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "xyz/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectScopeNestedFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectScopeNestedFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "abc/*").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "foo"));
    test_assert(!strcmp(result->parent, "abc"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bar"));
    test_assert(!strcmp(result->parent, "abc"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingle(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingle) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/xyz").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "a"));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "xyz").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "bc").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNested(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNested) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/", "a/xyz/abc").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "a/xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNestedFromScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNestedFromScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a", "xyz/bc").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "bc"));
    test_assert(!strcmp(result->parent, "xyz"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectSingleNestedFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectSingleNestedFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz", "abc/foo").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "foo"));
    test_assert(!strcmp(result->parent, "abc"));
    test_assert(!strcmp(result->type, "uint32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectVirtualGrandparentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectVirtualGrandparentFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz/abc/foo", "../..").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "xyz"));
    test_assert(!strcmp(result->parent, "../../.."));
    test_assert(!strcmp(result->type, "float64"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_ReplicatorRequest_tc_selectVirtualParentFromVirtualScope(
    test_ReplicatorRequest this)
{
/* $begin(test/ReplicatorRequest/tc_selectVirtualParentFromVirtualScope) */
    corto_result *result;
    corto_int16 ret = 0;

    corto_iter iter = corto_select("/a/xyz/abc/foo", "..").iter( &ret );
    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "abc"));
    test_assert(!strcmp(result->parent, "../.."));
    test_assert(!strcmp(result->type, "uint32"));

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
