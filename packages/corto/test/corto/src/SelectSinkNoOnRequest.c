/* $CORTO_GENERATED
 *
 * SelectSinkNoOnRequest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_SelectSinkNoOnRequest_setup(
    test_SelectSinkNoOnRequest this)
{
/* $begin(test/SelectSinkNoOnRequest/setup) */
    /* Register sink mount */
    corto_int32CreateChild_auto(root_o, mount, 0);
    corto_int32CreateChild_auto(mount, x, 10);
    corto_int32CreateChild_auto(mount, y, 10);

    test_EmptySinkReplicatorCreateChild_auto(root_o, sinkMount, mount);

    /* Ensure all objects are created with persistency enabled */
    corto_setAttr(CORTO_ATTR_PERSISTENT);


/* $end */
}

corto_void _test_SelectSinkNoOnRequest_tc_selectScope(
    test_SelectSinkNoOnRequest this)
{
/* $begin(test/SelectSinkNoOnRequest/tc_selectScope) */
    corto_result *result;
    corto_iter iter;
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

    test_assert(!corto_iterHasNext(&iter));

/* $end */
}

corto_void _test_SelectSinkNoOnRequest_tc_selectSingle(
    test_SelectSinkNoOnRequest this)
{
/* $begin(test/SelectSinkNoOnRequest/tc_selectSingle) */
    corto_result *result;
    corto_iter iter;
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

corto_void _test_SelectSinkNoOnRequest_teardown(
    test_SelectSinkNoOnRequest this)
{
/* $begin(test/SelectSinkNoOnRequest/teardown) */

    /* << Insert implementation >> */

/* $end */
}
