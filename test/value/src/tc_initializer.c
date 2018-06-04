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
    corto_type type;
    corto_member member;
    void *ptr;

    test_reftype obj = corto_declare(root_o, "obj", test_reftype_o);
    corto_initializer init = corto_initializer_init(test_reftype_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_reftype_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_reftype_x_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_initializer_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_reftype_y_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_initializer_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_pop(&init) == 0);
    corto_initializer_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_composite_ref_nested(
    test_tc_initializer this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_reftype ref_obj = corto_create(NULL, NULL, test_reftype_o);
    test_assert(ref_obj != NULL);

    test_refmbr obj = corto_declare(root_o, "obj", test_refmbr_o);
    corto_initializer init = corto_initializer_init(test_refmbr_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refmbr_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* valmbr */
    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_x_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_initializer_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_y_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_initializer_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 2);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_reftype_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_m_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m);
    test_assert(corto_initializer_set_ref(&init, ref_obj) == 0);
    test_assert(obj->m == ref_obj);

    /* valmbr */
    test_assert(corto_initializer_pop(&init) == 0);
    corto_initializer_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_composite_value(
    test_tc_initializer this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valtype *obj = corto_declare(root_o, "obj", test_valtype_o);
    corto_initializer init = corto_initializer_init(test_valtype_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_x_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_initializer_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_initializer_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_pop(&init) == 0);
    corto_initializer_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_composite_value_nested(
    test_tc_initializer this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valmbr *obj = corto_declare(root_o, "obj", test_valmbr_o);
    corto_initializer init = corto_initializer_init(test_valmbr_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valmbr_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* valmbr */
    test_assert(corto_initializer_push(&init, false) == 0);

    test_assertint(corto_initializer_get_index(&init), 0);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_x_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_initializer_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_y_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_initializer_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 2);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_m_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m);

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
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.x);
    test_assert(corto_initializer_set_int(&init, 30) == 0);
    test_assertint(obj->m.x, 30);

    test_assert(corto_initializer_has_next(&init) == true);
    test_assert(corto_initializer_next(&init) == 0);

    test_assertint(corto_initializer_get_index(&init), 1);
    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_initializer_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.y);
    test_assert(corto_initializer_set_int(&init, 40) == 0);
    test_assertint(obj->m.y, 40);

    /* valtype */
    test_assert(corto_initializer_has_next(&init) == false);
    test_assert(corto_initializer_pop(&init) == 0);

    /* valmbr */
    test_assert(corto_initializer_pop(&init) == 0);
    corto_initializer_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_bool(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    bool *obj = corto_declare(root_o, "obj", corto_bool_o);
    corto_initializer init = corto_initializer_init(corto_bool_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_bool(&init, true);
    test_assert(*obj == true);
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_char(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    char *obj = corto_declare(root_o, "obj", corto_char_o);
    corto_initializer init = corto_initializer_init(corto_char_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_char_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_char(&init, 'a');
    test_assertint(*obj, 'a');
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_constant(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    int32_t *obj = corto_declare(root_o, "obj", test_Color_o);
    corto_initializer init = corto_initializer_init(test_Color_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_Color_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_int(&init, Test_Blue);
    test_assertint(*obj, Test_Blue);
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_float(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    float *obj = corto_declare(root_o, "obj", corto_float32_o);
    corto_initializer init = corto_initializer_init(corto_float32_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float32_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_float(&init, 10.5);
    test_assertint(*obj, 10.5);
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_int(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    int32_t *obj = corto_declare(root_o, "obj", corto_int32_o);
    corto_initializer init = corto_initializer_init(corto_int32_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_int(&init, -10);
    test_assertint(*obj, -10);
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_string(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    char **obj = corto_declare(root_o, "obj", corto_string_o);
    corto_initializer init = corto_initializer_init(corto_string_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_string(&init, "Hello World");
    test_assertstr(*obj, "Hello World");
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_primitive_uint(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    uint32_t *obj = corto_declare(root_o, "obj", corto_int32_o);
    corto_initializer init = corto_initializer_init(corto_int32_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_int(&init, 10);
    test_assertint(*obj, 10);
    test_assert(corto_define(obj) == 0);
}


void test_tc_initializer_tc_reference(
    test_tc_initializer this)
{
    corto_type type;
    void *ptr;

    corto_object *obj = corto_declare(root_o, "obj", corto_object_o);
    corto_initializer init = corto_initializer_init(corto_object_o, obj);
    test_assert(corto_initializer_has_next(&init) == false);

    type = corto_initializer_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_object_o);
    ptr = corto_initializer_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_initializer_set_ref(&init, corto_lang_o);
    test_assert(*obj == corto_lang_o);
    test_assert(corto_define(obj) == 0);
}
