/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Init_tc_default_composite(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assertint(o->m_default_composite.x, 10);
    test_assertint(o->m_default_composite.y, 20);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_default_list(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_default_list != NULL);
    test_assertint(corto_ll_count(o->m_default_list), 3);
    test_assertint((intptr_t)corto_ll_get(o->m_default_list, 0), 10);
    test_assertint((intptr_t)corto_ll_get(o->m_default_list, 1), 20);
    test_assertint((intptr_t)corto_ll_get(o->m_default_list, 2), 30);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_default_nested(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assertint(o->m_default_nested.start.x, 10);
    test_assertint(o->m_default_nested.start.y, 20);
    test_assertint(o->m_default_nested.stop.x, 30);
    test_assertint(o->m_default_nested.stop.y, 40);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_default_num(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assertint(o->m_default_num, 10);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_default_string(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assertstr(o->m_default_string, "Hello World");
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_list(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_list == NULL);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_list_not_null(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_list_not_null != NULL);
    test_assert(corto_ll_count(o->m_list_not_null) == 0);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_map(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_map == NULL);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_map_not_null(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_map_not_null != NULL);
    test_assert(corto_rb_count(o->m_map) == 0);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_nestedInit(
    test_Init this)
{
    test_NestedInitTest *o = corto_declare(NULL, NULL, test_NestedInitTest_o);
    test_assertint(o->m_nested.m_default_composite.x, 10);
    test_assertint(o->m_nested.m_default_composite.y, 20);
    test_assert(o->m_nested.m_default_list != NULL);
    test_assertint(corto_ll_count(o->m_nested.m_default_list), 3);
    test_assertint((intptr_t)corto_ll_get(o->m_nested.m_default_list, 0), 10);
    test_assertint((intptr_t)corto_ll_get(o->m_nested.m_default_list, 1), 20);
    test_assertint((intptr_t)corto_ll_get(o->m_nested.m_default_list, 2), 30);
    test_assertint(o->m_nested.m_default_nested.start.x, 10);
    test_assertint(o->m_nested.m_default_nested.start.y, 20);
    test_assertint(o->m_nested.m_default_nested.stop.x, 30);
    test_assertint(o->m_nested.m_default_nested.stop.y, 40);
    test_assertint(o->m_nested.m_default_num, 10);
    test_assertstr(o->m_nested.m_default_string, "Hello World");
    test_assert(o->m_nested.m_list == NULL);
    test_assert(o->m_nested.m_list_not_null != NULL);
    test_assert(corto_ll_count(o->m_nested.m_list_not_null) == 0);
    test_assert(o->m_nested.m_map == NULL);
    test_assert(o->m_nested.m_map_not_null != NULL);
    test_assert(corto_rb_count(o->m_nested.m_map) == 0);
    test_assert(o->m_nested.m_observable != NULL);
    test_assert(*o->m_nested.m_observable == 0);
    test_assert(o->m_nested.m_observable_default != NULL);
    test_assert(*o->m_nested.m_observable_default == 10);
    test_assert(o->m_nested.m_observable_list != NULL);
    test_assert(*o->m_nested.m_observable_list != NULL);
    test_assert(corto_ll_count(*o->m_nested.m_observable_list) == 0);
    test_assert(o->m_nested.m_observable_list_not_null != NULL);
    test_assert(*o->m_nested.m_observable_list_not_null != NULL);
    test_assert(corto_ll_count(*o->m_nested.m_observable_list_not_null) == 0);
    test_assert(o->m_nested.m_target != NULL);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_observable(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_observable != NULL);
    test_assert(*o->m_observable == 0);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_observable_default(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_observable_default != NULL);
    test_assert(*o->m_observable_default == 10);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_observable_list(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_observable_list != NULL);

    /* Observable values are their own (orphaned) object, and thus initialize by
     * default, since the NOT_NULL modifier does not apply to the object. */
    test_assert(*o->m_observable_list != NULL);
    test_assert(corto_ll_count(*o->m_observable_list) == 0);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_observable_list_not_null(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_observable_list_not_null != NULL);
    test_assert(*o->m_observable_list_not_null != NULL);
    test_assert(corto_ll_count(*o->m_observable_list_not_null) == 0);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_target(
    test_Init this)
{
    test_InitTest *o = corto_declare(NULL, NULL, test_InitTest_o);
    test_assert(o->m_target != NULL);
    test_assert(corto_delete(o) == 0);
}

void test_Init_tc_singleton(
    test_Init this)
{
    test_struct_singleton *foo = corto_create(root_o, "foo", test_struct_singleton_o);
    test_struct_singleton *bar = corto_create(root_o, "bar", test_struct_singleton_o);
    test_assert(foo != NULL);
    test_assert(bar != NULL);

    test_assert(foo->m == bar->m);
    test_assertref(corto_typeof(foo->m), corto_int32_o);
    test_assertint(corto_countof(foo->m), 2);

    test_assert(corto_delete(bar) == 0);
    test_assertint(corto_countof(foo->m), 1);
    test_assert(corto_delete(foo) == 0);
}
