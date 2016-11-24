/* $CORTO_GENERATED
 *
 * SelectSink.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_SelectSink_setup(
    test_SelectSink this)
{
/* $begin(test/SelectSink/setup) */

    /* Register sink mount */
    corto_voidCreateChild_auto(root_o, mount);
    test_SinkReplicatorCreateChild_auto(root_o, sinkMount, mount, NULL, NULL);

    /* Ensure all objects are created with persistency enabled */
    corto_setAttr(CORTO_ATTR_PERSISTENT);

/* $end */
}

corto_void _test_SelectSink_tc_selectMixedScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScope) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(mount, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(mount, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "y"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "z"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectMixedScopeNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScopeNested1) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(x, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(x, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectMixedScopeNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScopeNested2) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(a, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(a, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/a/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectMountInResult(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMountInResult) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x").iter( &iter );
    test_assert(ret == 0);

    corto_object mount = corto_lookup(NULL, "sinkMount");
    test_assert(mount != NULL);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "int32");
    test_assert(result->owner == mount);

    test_assert(!corto_iterHasNext(&iter));
    corto_release(mount);

/* $end */
}

corto_void _test_SelectSink_tc_selectScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectScope) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "y"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "z"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectSingle(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingle) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectSingleTypeFilter(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleTypeFilter) */
    corto_iter iter;
    corto_result *result;

    // Create SINK mount that is responsible for all package objects in scope
    corto_loader l = corto_loaderCreate();
    test_assert(l != NULL);

    // Select single object of the package type
    corto_int16 ret = corto_select(NULL, "//lang*").iter( &iter );
    test_assert(ret == 0);
    test_assertstr(corto_lasterr(), NULL);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "lang"));
    test_assert(!strcmp(result->parent, "/corto"));
    test_assert(!strcmp(result->type, "/corto/core/package"));

/* $end */
}

corto_void _test_SelectSink_tc_selectSingleVirtualNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleVirtualNested1) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x/a").iter( &iter );

    test_assert(ret == 0);

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);
    corto_release(mount);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectSingleVirtualNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleVirtualNested2) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x/a/k").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualScopeNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeNested1) */
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild(mount, "x", 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/a/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualScopeNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeNested2) */
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/a/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualScopeVirtualNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeVirtualNested1) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x/a/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualScopeVirtualNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeVirtualNested2) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount", "x/a/k/*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "n"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "o"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "p"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualSingleNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualSingleNested1) */
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/a").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_tc_selectVirtualSingleNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualSingleNested2) */
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "x/a/k").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSink_teardown(
    test_SelectSink this)
{
/* $begin(test/SelectSink/teardown) */

    /* << Insert implementation >> */

/* $end */
}
