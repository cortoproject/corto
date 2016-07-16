/* $CORTO_GENERATED
 *
 * SelectSinkWithType.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_SelectSinkWithType_setup(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/setup) */

    /* Register sink mount */
    corto_int32CreateChild_auto(root_o, mount, 0);
    test_SinkReplicatorCreateChild_auto(root_o, sinkMount, mount, "int32", NULL);

    /* Ensure all objects are created with persistency enabled */
    corto_setAttr(CORTO_ATTR_PERSISTENT);

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectMixedScope(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMixedScope) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create int32 object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(mount, i, 0);

    /* Create float object that is not in mount (should show up) */
    corto_float32CreateChild_auto(mount, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "*").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "j"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "float32"));

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

corto_void _test_SelectSinkWithType_tc_selectMixedScopeNested1(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMixedScopeNested1) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create int32 object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(x, i, 0);

    /* Create float object that is not in mount (should show up) */
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

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "j"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "float32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectMixedScopeNested2(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMixedScopeNested2) */
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

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "j"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "float32"));

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectMount(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMount) */
    corto_iter iter;
    corto_result *result;

    corto_int16 ret = corto_select("/", "mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "mount"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectMountFromParent(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMountFromParent) */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_release(mount);

    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount/x", "..").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "mount"));
    test_assert(!strcmp(result->parent, "../.."));
    test_assert(!strcmp(result->type, "int32"));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectMountFromVirtualParent(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectMountFromVirtualParent) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("/mount/x", "..").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "mount"));
    test_assert(!strcmp(result->parent, "../.."));
    test_assert(!strcmp(result->type, "int32"));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectSingleMatch(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectSingleMatch) */
    corto_iter iter;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, test, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "test").iter( &iter );

    test_assert(ret == 0);
    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSinkWithType_tc_selectSingleNoMatch(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/tc_selectSingleNoMatch) */
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_float32CreateChild_auto(mount, test, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("/mount", "test").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iterHasNext(&iter));
    result = corto_iterNext(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "test"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "float32"));

/* $end */
}

corto_void _test_SelectSinkWithType_teardown(
    test_SelectSinkWithType this)
{
/* $begin(test/SelectSinkWithType/teardown) */

    /* << Insert implementation >> */

/* $end */
}
