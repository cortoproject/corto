/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_SelectMount_setup(
    test_SelectMount this)
{

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create mount */
    this->mount = test_ListMountCreate(a_o, CORTO_ON_SCOPE, CORTO_REMOTE_OWNER);

    corto_enableload(FALSE);

}

void test_SelectMount_tc_selectGrandparentFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("../..").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "/corto/vstore/package");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectInvertCase(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("XYZ").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectInvertCaseFilter(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("XY?").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectInvertCaseScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz").from("/A").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectIteratorPartialRelease(
    test_SelectMount this)
{
    test_MountIterCount mount = test_MountIterCountCreateChild(root_o, "mount", NULL);
    test_assert(mount != NULL);

    corto_iter it;
    corto_int32 i = 0;
    
    corto_int16 ret = corto_select("*").from("/mount").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 5; i++) {
        test_assert(corto_iter_hasNext(&it));
        test_assert(corto_iter_next(&it) != NULL);
    }

    corto_iter_release(&it);
    test_assertint(mount->hasNextCount, 5);
    test_assertint(mount->nextCount, 5);
    test_assertint(mount->releaseCount, 1);
    test_assert(corto_delete(mount) == 0);
}

void test_SelectMount_tc_selectIteratorPartialReleaseTwoMounts(
    test_SelectMount this)
{
    corto_iter it;
    corto_int32 i = 0;

    corto_object mount = corto_createChild(root_o, "mount", corto_void_o);

    test_MountIterCount mountA = test_MountIterCountCreate(mount);
    test_assert(mountA != NULL);

    test_MountIterCount mountB = test_MountIterCountCreate(mount);
    test_assert(mountB != NULL);
    
    corto_int16 ret = corto_select("*").from("/mount").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 15; i++) {
        test_assert(corto_iter_hasNext(&it));
        test_assert(corto_iter_next(&it) != NULL);
    }

    corto_iter_release(&it);
    test_assertint(mountA->hasNextCount + mountB->hasNextCount, 16);
    test_assertint(mountA->nextCount + mountB->nextCount, 15);
    test_assertint(mountA->releaseCount, 1);
    test_assertint(mountB->releaseCount, 1);
    test_assert(corto_delete(mountA) == 0);
    test_assert(corto_delete(mountB) == 0);
    test_assert(corto_delete(mount) == 0);
}

void test_SelectMount_tc_selectIteratorPartialReleaseTwoMountsNested(
    test_SelectMount this)
{
    test_MountIterCount mountA = test_MountIterCountCreateChild(root_o, "mount", NULL);
    test_assert(mountA != NULL);

    test_MountIterCount mountB = test_MountIterCountCreateChild(mountA, "mount", NULL);
    test_assert(mountB != NULL);

    corto_iter it;
    corto_int32 i = 0;
    
    corto_int16 ret = corto_select("//").from("/mount").iter( &it );
    test_assert(ret == 0);

    for (i = 0; i < 15; i++) {
        test_assert(corto_iter_hasNext(&it));
        test_assert(corto_iter_next(&it) != NULL);
    }

    corto_iter_release(&it);
    test_assertint(mountA->releaseCount, 1);
    test_assertint(mountB->releaseCount, 1);
    test_assertint(mountA->hasNextCount + mountB->hasNextCount, 15);
    test_assertint(mountA->nextCount + mountB->nextCount, 14);
    /* hasNext and next are called in total 15 and 14 times, because select also
     * finds the nested 'mount' object */
    test_assert(corto_delete(mountA) == 0);
    test_assert(corto_delete(mountB) == 0);
}

void test_SelectMount_tc_selectIteratorRelease(
    test_SelectMount this)
{
    test_MountIterCount mount = test_MountIterCountCreateChild(root_o, "mount", NULL);
    corto_iter it;
    corto_int32 count = 0;
    
    corto_int16 ret = corto_select("*").from("/mount").iter( &it );
    test_assert(ret == 0);

    while (corto_iter_hasNext(&it)) {
        corto_iter_next(&it);
        count ++;
    }

    test_assertint(count, 10);
    test_assertint(mount->hasNextCount, 11);
    test_assertint(mount->nextCount, 10);
    test_assertint(mount->releaseCount, 1);
    test_assert(corto_delete(mount) == 0);
}

void test_SelectMount_tc_selectParentFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("..").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "");
    test_assertstr(result->parent, "..");
    test_assertstr(result->type, "/corto/vstore/package");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectParentFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("..").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "void");

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectMount_tc_selectScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/*").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeFilter(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/*z").from("/").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeFilterFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("*z").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeFilterFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("*c").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("*")
        .from("/A")
        .iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeFromVirtualMount(
    test_SelectMount this)
{

    corto_object m = test_VirtualMountCreate("/data");
    test_assert(m != NULL);

    corto_iter it;
    test_assert(!corto_select("data/*").contentType("text/corto").iter(&it));

    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, "/data");
    test_assertstr(r->type, "int32");
    test_assertstr(corto_result_getText(r), "10");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, "/data");
    test_assertstr(r->type, "string");
    test_assertstr(corto_result_getText(r), "Hello World");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, "/data");
    test_assertstr(r->type, "float64");
    test_assertstr(corto_result_getText(r), "10.5");

    test_assert(!corto_iter_hasNext(&it));

}

void test_SelectMount_tc_selectScopeFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("*").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectMount_tc_selectScopeMixed(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    /* Create additional three objects in scope of a */
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    corto_voidCreateChild(a, "b");
    corto_voidCreateChild(a, "bc");
    corto_voidCreateChild(a, "abc");
    corto_release(a);

    corto_int16 ret = corto_select("a/*").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "b");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "void");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNested(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/xyz/*").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNestedDirty(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/../a/./xyz/./*").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNestedDirtyFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("../a/./xyz/./*").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNestedDirtyFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("../../a/../a/./xyz/./abc/*").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNestedFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz/*").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectScopeNestedFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("abc/*").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingle(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/xyz").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "a");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleFromScopeTree(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//foo").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleFromVirtualMount(
    test_SelectMount this)
{

    /* << Insert implementation >> */

}

void test_SelectMount_tc_selectSingleFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("bc").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleNested(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("a/xyz/abc").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "a/xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleNestedFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz/bc").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleNestedFromScopeTree(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz//foo").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleNestedFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("abc/foo").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleTree(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//a").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleTree2(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//foo").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectSingleTree3(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//hello").from("/").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "a/xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectTree(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "b");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "c");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "yz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "string");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "float64");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectTreeEmptyNestedScope(
    test_SelectMount this)
{
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
    corto_int16 ret = corto_select("//").from("/b").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount");
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount2");
    test_assert(!corto_iter_hasNext(&it));

    ret = corto_delete(m);
    test_assert(ret == 0);

    ret = corto_delete(b_o);
    test_assert(ret == 0);

}

void test_SelectMount_tc_selectTreeEmptyScope(
    test_SelectMount this)
{
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
    corto_int16 ret = corto_select("//").from("/b").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "mount");
    test_assert(!corto_iter_hasNext(&it));

    ret = corto_delete(m);
    test_assert(ret == 0);

    ret = corto_delete(b_o);
    test_assert(ret == 0);

}

void test_SelectMount_tc_selectTreeFromNestedScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//").from("/a/xyz/abc").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectTreeFromScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("//").from("/a/xyz").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectTreeFromVirtualMount(
    test_SelectMount this)
{

    /* << Insert implementation >> */

}

void test_SelectMount_tc_selectTreeFromVirtualNestedScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz/abc//").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectTreeFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("xyz//").from("/a").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "foo");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "hello");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "world");
    test_assertstr(result->parent, "xyz/abc/foo");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bar");
    test_assertstr(result->parent, "xyz/abc");
    test_assertstr(result->type, "uint32");

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "bc");
    test_assertstr(result->parent, "xyz");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectVirtualGrandparentFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("../..").from("/a/xyz/abc/foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "xyz");
    test_assertstr(result->parent, "../../..");
    test_assertstr(result->type, "float64");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_tc_selectVirtualParentFromVirtualScope(
    test_SelectMount this)
{
    corto_result *result;
    corto_iter iter;

    corto_int16 ret = corto_select("..").from("/a/xyz/abc/foo").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "abc");
    test_assertstr(result->parent, "../..");
    test_assertstr(result->type, "uint32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectMount_teardown(
    test_SelectMount this)
{

    corto_delete(this->mount);
    this->mount = NULL;

}

void test_SelectMount_tc_selectFromMountWithPartialFrom(
    test_SelectMount this)
{
    corto_object p = corto_createChild(root_o, "parent", corto_void_o);
    test_assert(p != NULL);

    test_VirtualSinkMount m = test_VirtualSinkMountCreate("parent");
    test_assert(m != NULL);

    corto_object o = corto_lookup(p, "x");
    test_assert(o != NULL);

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(p) == 0);
}

void test_SelectMount_tc_selectFromPartialMatchedElement(
    test_SelectMount this)
{
    corto_iter it;
    test_assert(corto_select("*").from("/a/x").iter(&it) == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "uint32");

    test_assert(corto_iter_hasNext(&it));    
    r = corto_iter_next(&it);
    test_assertstr(r->id, "b");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "uint32");

    test_assert(corto_iter_hasNext(&it));    
    r = corto_iter_next(&it);
    test_assertstr(r->id, "c");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "uint32"); 

    test_assert(!corto_iter_hasNext(&it));
}
