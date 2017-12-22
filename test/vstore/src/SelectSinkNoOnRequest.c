/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_SelectSinkNoOnRequest_setup(
    test_SelectSinkNoOnRequest this)
{
    /* Register sink mount */
    corto_int32CreateChild_auto(root_o, mount, 0);
    corto_int32CreateChild_auto(mount, x, 10);
    corto_int32CreateChild_auto(mount, y, 10);

    test_EmptySinkMountCreateChild_auto(root_o, sinkMount, mount);

    /* Ensure all objects are created with persistency enabled */
    corto_set_attr(CORTO_ATTR_PERSISTENT);
}

void test_SelectSinkNoOnRequest_tc_selectScope(
    test_SelectSinkNoOnRequest this)
{
    corto_result *result;
    corto_iter iter;
    corto_int16 ret = corto_select("*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "y"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSinkNoOnRequest_tc_selectSingle(
    test_SelectSinkNoOnRequest this)
{
    corto_result *result;
    corto_iter iter;
    corto_int16 ret = corto_select("x").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSinkNoOnRequest_teardown(
    test_SelectSinkNoOnRequest this)
{

    /* << Insert implementation >> */

}

