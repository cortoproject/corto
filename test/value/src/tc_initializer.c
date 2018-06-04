/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_tc_initializer_tc_collection_array(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_collection_list(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_collection_sequence(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_composite_ref(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_composite_ref_nested(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_composite_value(
    test_tc_initializer this)
{
    corto_type type;
    corto_member member;

    test_valtype *obj = corto_declare(root_o, "obj", test_valtype_o);
    corto_initializer init = corto_initializer_init(test_valtype_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);

    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_x_o);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);

    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_pop(&init) == 0);

    corto_initializer_deinit(&init);
}


void test_tc_initializer_tc_composite_value_nested(
    test_tc_initializer this)
{
    corto_type type;
    corto_member member;

    test_valtype *obj = corto_declare(root_o, "obj", test_valmbr_o);
    corto_initializer init = corto_initializer_init(test_valmbr_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valmbr_o);

    /* valmbr */
    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_x_o);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_y_o);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 2);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_m_o);

    /* valtype */
    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_x_o);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);

    /* valtype */
    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_pop(&init) == 0);

    /* valmbr */
    test_assert(corto_initializer_pop(&init) == 0);

    corto_initializer_deinit(&init);
}


void test_tc_initializer_tc_primitive_bool(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_char(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_constant(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_float(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_int(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_string(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_primitive_uint(
    test_tc_initializer this)
{
    /* Insert implementation */
}


void test_tc_initializer_tc_reference(
    test_tc_initializer this)
{
    /* Insert implementation */
}
