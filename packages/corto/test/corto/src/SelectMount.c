/* $CORTO_GENERATED
 *
 * SelectMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_SelectMount_setup(
    test_SelectMount this)
{
/* $begin(test/SelectMount/setup) */

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create mount */
    this->mount = test_ListMountCreate(a_o, CORTO_ON_SCOPE, CORTO_SOURCE);

    corto_enableload(FALSE);

/* $end */
}

corto_void _test_SelectMount_tc_selectGrandparentFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectGrandparentFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectInvertCase(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectInvertCase) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "XYZ").iter( &iter );
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

corto_void _test_SelectMount_tc_selectInvertCaseFilter(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectInvertCaseFilter) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/a", "XY?").iter( &iter );
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

corto_void _test_SelectMount_tc_selectInvertCaseScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectInvertCaseScope) */
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("/A", "xyz").iter( &iter );
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

corto_void _test_SelectMount_tc_selectIteratorPartialRelease(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectIteratorPartialRelease) */
    test_MountIterCount mount = test_MountIterCountCreateChild(root_o, "mount", NULL);
    test_assert(mount != NULL);

    corto_iter it;
    corto_int32 i = 0;
    
    corto_int16 ret = corto_select("/mount", "*").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 5; i++) {
        test_assert(corto_iterHasNext(&it));
        test_assert(corto_iterNext(&it) != NULL);
    }
    corto_iterRelease(&it);

    test_assertint(mount->hasNextCount, 5);
    test_assertint(mount->nextCount, 5);
    test_assertint(mount->releaseCount, 1);

    test_assert(corto_delete(mount) == 0);

/* $end */
}

corto_void _test_SelectMount_tc_selectIteratorPartialReleaseTwoMounts(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectIteratorPartialReleaseTwoMounts) */
    corto_iter it;
    corto_int32 i = 0;

    corto_object mount = corto_createChild(root_o, "mount", corto_void_o);

    test_MountIterCount mountA = test_MountIterCountCreate(mount);
    test_assert(mountA != NULL);

    test_MountIterCount mountB = test_MountIterCountCreate(mount);
    test_assert(mountB != NULL);
    
    corto_int16 ret = corto_select("/mount", "*").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 15; i++) {
        test_assert(corto_iterHasNext(&it));
        test_assert(corto_iterNext(&it) != NULL);
    }
    corto_iterRelease(&it);

    test_assertint(mountA->hasNextCount + mountB->hasNextCount, 16);
    test_assertint(mountA->nextCount + mountB->nextCount, 15);
    test_assertint(mountA->releaseCount, 1);
    test_assertint(mountB->releaseCount, 1);

    test_assert(corto_delete(mountA) == 0);
    test_assert(corto_delete(mountB) == 0);
    test_assert(corto_delete(mount) == 0);

/* $end */
}

corto_void _test_SelectMount_tc_selectIteratorPartialReleaseTwoMountsNested(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectIteratorPartialReleaseTwoMountsNested) */
    test_MountIterCount mountA = test_MountIterCountCreateChild(root_o, "mount", NULL);
    test_assert(mountA != NULL);

    test_MountIterCount mountB = test_MountIterCountCreateChild(mountA, "mount", NULL);
    test_assert(mountB != NULL);

    corto_iter it;
    corto_int32 i = 0;
    
    corto_int16 ret = corto_select("/mount", "//").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 15; i++) {
        test_assert(corto_iterHasNext(&it));
        test_assert(corto_iterNext(&it) != NULL);
    }
    corto_iterRelease(&it);

    test_assertint(mountA->releaseCount, 1);
    test_assertint(mountB->releaseCount, 1);
    test_assertint(mountA->hasNextCount + mountB->hasNextCount, 15);
    test_assertint(mountA->nextCount + mountB->nextCount, 14);

    /* hasNext and next are called in total 15 and 14 times, because select also
     * finds the nested 'mount' object */

    test_assert(corto_delete(mountA) == 0);
    test_assert(corto_delete(mountB) == 0);

/* $end */
}

corto_void _test_SelectMount_tc_selectIteratorRelease(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectIteratorRelease) */
    test_MountIterCount mount = test_MountIterCountCreateChild(root_o, "mount", NULL);
    corto_iter it;
    corto_int32 count = 0;
    
    corto_int16 ret = corto_select("/mount", "*").iter( &it );
    test_assert(ret == 0);

    while (corto_iterHasNext(&it)) {
        corto_iterNext(&it);
        count ++;
    }

    test_assertint(count, 10);
    test_assertint(mount->hasNextCount, 11);
    test_assertint(mount->nextCount, 10);
    test_assertint(mount->releaseCount, 1);

    test_assert(corto_delete(mount) == 0);

/* $end */
}

corto_void _test_SelectMount_tc_selectParentFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectParentFromScope) */
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

corto_void _test_SelectMount_tc_selectParentFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectParentFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScope) */
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

corto_void _test_SelectMount_tc_selectScopeFilter(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeFilter) */
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

corto_void _test_SelectMount_tc_selectScopeFilterFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeFilterFromScope) */
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

corto_void _test_SelectMount_tc_selectScopeFilterFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeFilterFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectScopeFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeFromScope) */
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

corto_void _test_SelectMount_tc_selectScopeFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectScopeMixed(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeMixed) */
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

corto_void _test_SelectMount_tc_selectScopeNested(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNested) */
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

corto_void _test_SelectMount_tc_selectScopeNestedDirty(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNestedDirty) */
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

corto_void _test_SelectMount_tc_selectScopeNestedDirtyFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNestedDirtyFromScope) */
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

corto_void _test_SelectMount_tc_selectScopeNestedDirtyFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNestedDirtyFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectScopeNestedFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNestedFromScope) */
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

corto_void _test_SelectMount_tc_selectScopeNestedFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectScopeNestedFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectSingle(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingle) */
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

corto_void _test_SelectMount_tc_selectSingleFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleFromScope) */
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

corto_void _test_SelectMount_tc_selectSingleFromScopeTree(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleFromScopeTree) */
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

corto_void _test_SelectMount_tc_selectSingleFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectSingleNested(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleNested) */
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

corto_void _test_SelectMount_tc_selectSingleNestedFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleNestedFromScope) */
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

corto_void _test_SelectMount_tc_selectSingleNestedFromScopeTree(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleNestedFromScopeTree) */
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

corto_void _test_SelectMount_tc_selectSingleNestedFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleNestedFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectSingleTree(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleTree) */
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

corto_void _test_SelectMount_tc_selectSingleTree2(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleTree2) */
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

corto_void _test_SelectMount_tc_selectSingleTree3(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectSingleTree3) */
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

corto_void _test_SelectMount_tc_selectTree(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTree) */
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

corto_void _test_SelectMount_tc_selectTreeEmptyNestedScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeEmptyNestedScope) */
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

corto_void _test_SelectMount_tc_selectTreeEmptyScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeEmptyScope) */
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

corto_void _test_SelectMount_tc_selectTreeFromNestedScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeFromNestedScope) */
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

corto_void _test_SelectMount_tc_selectTreeFromScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeFromScope) */
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

corto_void _test_SelectMount_tc_selectTreeFromVirtualNestedScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeFromVirtualNestedScope) */
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

corto_void _test_SelectMount_tc_selectTreeFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectTreeFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectVirtualGrandparentFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectVirtualGrandparentFromVirtualScope) */
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

corto_void _test_SelectMount_tc_selectVirtualParentFromVirtualScope(
    test_SelectMount this)
{
/* $begin(test/SelectMount/tc_selectVirtualParentFromVirtualScope) */
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

corto_void _test_SelectMount_teardown(
    test_SelectMount this)
{
/* $begin(test/SelectMount/teardown) */

    corto_delete(this->mount);
    this->mount = NULL;

/* $end */
}
