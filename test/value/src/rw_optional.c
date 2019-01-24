/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_rw_optional_tc_primitive(
    test_rw_optional this)
{
    test_s_optional_primitive *o = corto_create(root_o, "o", test_s_optional_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_primitive_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertint(*o->m, 10);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_primitive_notset(
    test_rw_optional this)
{
    test_s_optional_primitive *o = corto_create(root_o, "o", test_s_optional_primitive_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(corto_int32_o);
    test_assert(o->m != NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_primitive_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_unset(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m == NULL);

    test_assert(corto_delete(o) == 0);
}

void test_rw_optional_tc_collection(
    test_rw_optional this)
{
    test_s_optional_collection *o = corto_create(root_o, "o", test_s_optional_collection_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_collection_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, true) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assert(*o->m != NULL);
    test_assertint(ut_ll_count(*o->m), 2);
    test_assertint((uintptr_t)ut_ll_get(*o->m, 0), 10);
    test_assertint((uintptr_t)ut_ll_get(*o->m, 1), 20);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_collection_notset(
    test_rw_optional this)
{
    test_s_optional_collection *o = corto_create(root_o, "o", test_s_optional_collection_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(corto_int32List_o);
    test_assert(o->m != NULL);
    test_assert(*o->m != NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_collection_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_unset(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m == NULL);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_composite(
    test_rw_optional this)
{
    test_s_optional_composite *o = corto_create(root_o, "o", test_s_optional_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_composite_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertint(o->m->x, 10);
    test_assertint(o->m->y, 20);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_composite_notset(
    test_rw_optional this)
{
    test_s_optional_composite *o = corto_create(root_o, "o", test_s_optional_composite_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(test_point_o);
    test_assert(o->m != NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_composite_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_unset(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m == NULL);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_reference(
    test_rw_optional this)
{
    test_s_optional_reference *o = corto_create(root_o, "o", test_s_optional_reference_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_object dummy = corto_create(NULL, NULL, corto_void_o);
    test_assert(dummy != NULL);
    test_assertint(corto_countof(dummy), 1);

    o->m = corto_ptr_new(corto_object_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_reference_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_ref(&rw, dummy) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertref(*o->m, dummy);
    test_assertint(corto_countof(dummy), 2);

    test_assert(corto_delete(o) == 0);
    test_assertint(corto_countof(dummy), 1);
    test_assert(corto_delete(dummy) == 0);
}


void test_rw_optional_tc_reference_notset(
    test_rw_optional this)
{
    test_s_optional_reference *o = corto_create(root_o, "o", test_s_optional_reference_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_object dummy = corto_create(NULL, NULL, corto_void_o);
    test_assert(dummy != NULL);
    test_assertint(corto_countof(dummy), 1);

    o->m = corto_ptr_new(corto_object_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);
    corto_set_ref(o->m, dummy);
    test_assertint(corto_countof(dummy), 2);

    corto_rw rw = corto_rw_init(o, test_s_optional_reference_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_unset(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m == NULL);
    test_assertint(corto_countof(dummy), 1);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(dummy) == 0);
}


void test_rw_optional_tc_reference_null(
    test_rw_optional this)
{
    test_s_optional_reference *o = corto_create(root_o, "o", test_s_optional_reference_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    corto_object dummy = corto_create(NULL, NULL, corto_void_o);
    test_assert(dummy != NULL);
    test_assertint(corto_countof(dummy), 1);

    o->m = corto_ptr_new(corto_object_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);
    corto_set_ref(o->m, dummy);
    test_assertint(corto_countof(dummy), 2);

    corto_rw rw = corto_rw_init(o, test_s_optional_reference_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_null(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertref(*o->m, NULL);
    test_assertint(corto_countof(dummy), 1);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(dummy) == 0);
}


void test_rw_optional_tc_string(
    test_rw_optional this)
{
    test_s_optional_string *o = corto_create(root_o, "o", test_s_optional_string_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(corto_string_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);

    corto_rw rw = corto_rw_init(o, test_s_optional_string_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_string(&rw, "Hello World") == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertstr(*o->m, "Hello World");

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_string_notset(
    test_rw_optional this)
{
    test_s_optional_string *o = corto_create(root_o, "o", test_s_optional_string_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(corto_string_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);
    corto_set_str(o->m, "Hello World");

    corto_rw rw = corto_rw_init(o, test_s_optional_string_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_unset(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m == NULL);

    test_assert(corto_delete(o) == 0);
}


void test_rw_optional_tc_string_null(
    test_rw_optional this)
{
    test_s_optional_string *o = corto_create(root_o, "o", test_s_optional_string_o);
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(o->m == NULL);

    o->m = corto_ptr_new(corto_string_o);
    test_assert(o->m != NULL);
    test_assert(*o->m == NULL);
    corto_set_str(o->m, "Hello World");

    corto_rw rw = corto_rw_init(o, test_s_optional_string_o);
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_next(&rw) == 0);
    test_assert(corto_rw_set_null(&rw) == 0);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(o->m != NULL);
    test_assertstr(*o->m, NULL);

    test_assert(corto_delete(o) == 0);
}
