/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_rw_tc_collection_array(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    int32_t *obj = corto_declare(root_o, "obj", test_int_array_o);
    corto_rw init = corto_rw_init(test_int_array_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_array_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, true) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj[0]);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj[0], 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj[1]);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj[1], 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj[2]);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(obj[2], 30);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_collection_list(
    test_rw this)
{
    corto_type type;
    corto_member member;
    int32_t *ptr;

    test_int_list *obj = corto_declare(root_o, "obj", test_int_list_o);
    corto_rw init = corto_rw_init(test_int_list_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_list_o);
    test_assert(corto_rw_get_ptr(&init) == obj);

    test_assert(corto_rw_push(&init, true) == 0);
    test_assert(*obj != NULL);
    test_assertint(corto_ll_count(*obj), 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init); /* appends new element */
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(test_int_list__get(*obj, 0), 10);
    test_assertint(*ptr, 10);
    test_assertint(corto_ll_count(*obj), 1);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(test_int_list__get(*obj, 1), 20);
    test_assertint(*ptr, 20);
    test_assertint(corto_ll_count(*obj), 2);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(test_int_list__get(*obj, 2), 30);
    test_assertint(*ptr, 30);
    test_assertint(corto_ll_count(*obj), 3);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_rw_tc_collection_sequence(
    test_rw this)
{
    corto_type type;
    corto_member member;
    int32_t *ptr;

    test_int_seq *obj = corto_declare(root_o, "obj", test_int_seq_o);
    corto_rw init = corto_rw_init(test_int_seq_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_seq_o);
    test_assert(corto_rw_get_ptr(&init) == obj);

    test_assert(corto_rw_push(&init, true) == 0);
    test_assert(obj->buffer == NULL);
    test_assertint(obj->length, 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init); /* appends new element */
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(*ptr, 10);
    test_assert(obj->buffer != NULL);
    test_assertint(obj->length, 1);
    test_assertint(obj->buffer[0], 10);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(*ptr, 20);
    test_assert(obj->buffer != NULL);
    test_assertint(obj->length, 2);
    test_assertint(obj->buffer[1], 20);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member == NULL);
    test_assert(corto_catch() != 0);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 0);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(*ptr, 30);
    test_assert(obj->buffer != NULL);
    test_assertint(obj->length, 3);
    test_assertint(obj->buffer[2], 30);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}


void test_rw_tc_composite_ref(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_reftype obj = corto_declare(root_o, "obj", test_reftype_o);
    corto_rw init = corto_rw_init(test_reftype_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_reftype_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_reftype_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_reftype_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_composite_ref_nested(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_reftype ref_obj = corto_create(NULL, NULL, test_reftype_o);
    test_assert(ref_obj != NULL);

    test_refmbr obj = corto_declare(root_o, "obj", test_refmbr_o);
    corto_rw init = corto_rw_init(test_refmbr_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refmbr_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* valmbr */
    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_reftype_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refmbr_m_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m);
    test_assert(corto_rw_set_ref(&init, ref_obj) == 0);
    test_assert(obj->m == ref_obj);

    /* valmbr */
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_composite_value(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valtype *obj = corto_declare(root_o, "obj", test_valtype_o);
    corto_rw init = corto_rw_init(test_valtype_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_composite_value_nested(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valmbr *obj = corto_declare(root_o, "obj", test_valmbr_o);
    corto_rw init = corto_rw_init(test_valmbr_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valmbr_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* valmbr */
    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valtype_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valmbr_m_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m);

    /* valtype */
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.x);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(obj->m.x, 30);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valtype_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.y);
    test_assert(corto_rw_set_int(&init, 40) == 0);
    test_assertint(obj->m.y, 40);

    /* valtype */
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);

    /* valmbr */
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_bool(
    test_rw this)
{
    corto_type type;
    void *ptr;

    bool *obj = corto_declare(root_o, "obj", corto_bool_o);
    corto_rw init = corto_rw_init(corto_bool_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_bool(&init, true);
    test_assert(*obj == true);
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_char(
    test_rw this)
{
    corto_type type;
    void *ptr;

    char *obj = corto_declare(root_o, "obj", corto_char_o);
    corto_rw init = corto_rw_init(corto_char_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_char_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_char(&init, 'a');
    test_assertint(*obj, 'a');
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_constant(
    test_rw this)
{
    corto_type type;
    void *ptr;

    int32_t *obj = corto_declare(root_o, "obj", test_Color_o);
    corto_rw init = corto_rw_init(test_Color_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_Color_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_int(&init, Test_Blue);
    test_assertint(*obj, Test_Blue);
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_float(
    test_rw this)
{
    corto_type type;
    void *ptr;

    float *obj = corto_declare(root_o, "obj", corto_float32_o);
    corto_rw init = corto_rw_init(corto_float32_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float32_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_float(&init, 10.5);
    test_assertint(*obj, 10.5);
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_int(
    test_rw this)
{
    corto_type type;
    void *ptr;

    int32_t *obj = corto_declare(root_o, "obj", corto_int32_o);
    corto_rw init = corto_rw_init(corto_int32_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_int(&init, -10);
    test_assertint(*obj, -10);
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_string(
    test_rw this)
{
    corto_type type;
    void *ptr;

    char **obj = corto_declare(root_o, "obj", corto_string_o);
    corto_rw init = corto_rw_init(corto_string_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_string(&init, "Hello World");
    test_assertstr(*obj, "Hello World");
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_primitive_uint(
    test_rw this)
{
    corto_type type;
    void *ptr;

    uint32_t *obj = corto_declare(root_o, "obj", corto_int32_o);
    corto_rw init = corto_rw_init(corto_int32_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_int(&init, 10);
    test_assertint(*obj, 10);
    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_reference(
    test_rw this)
{
    corto_type type;
    void *ptr;

    corto_object *obj = corto_declare(root_o, "obj", corto_object_o);
    corto_rw init = corto_rw_init(corto_object_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_object_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    corto_rw_set_ref(&init, corto_lang_o);
    test_assert(*obj == corto_lang_o);
    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_inheritance_ref(
    test_rw this)
{
    /* Insert implementation */
}

void test_rw_tc_inheritance_ref_nested(
    test_rw this)
{
    /* Insert implementation */
}

void test_rw_tc_inheritance_value(
    test_rw this)
{
    /* Insert implementation */
}

void test_rw_tc_inheritance_value_nested(
    test_rw this)
{
    /* Insert implementation */
}
