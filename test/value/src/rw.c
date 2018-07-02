/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

#define test_array_elem(array_ptr, index, type, type_code, value) {\
    test_assertint(corto_rw_get_index(&init), index);\
    corto_type type = corto_rw_get_type(&init);\
    test_assert(type != NULL);\
    test_assert(type == (corto_type)type);\
    corto_member member = corto_rw_get_member(&init);\
    test_assert(member == NULL);\
    test_assert(corto_catch() != 0);\
    void *ptr = corto_rw_get_ptr(&init);\
    test_assert(ptr != NULL);\
    test_assert(ptr == &array_ptr[index]);\
    test_assert(corto_rw_set_##type_code(&init, value) == 0);\
    test_assert##type_code(array_ptr[index], value);\
}

#define test_list_elem(list_ptr, index, type, type_code, value, count_before, count_after) {\
    test_assertint(corto_ll_count(list_ptr), count_before);\
    test_assertint(corto_rw_get_index(&init), index);\
    corto_type type = corto_rw_get_type(&init);\
    test_assert(type != NULL);\
    test_assert(type == (corto_type)type);\
    corto_member member = corto_rw_get_member(&init);\
    test_assert(member == NULL);\
    test_assert(corto_catch() != 0);\
    type_code *ptr = corto_rw_get_ptr(&init);\
    test_assert(ptr != NULL);\
    test_assertint(*ptr, 0);\
    test_assert(corto_rw_set_##type_code(&init, value) == 0);\
    test_assert##type_code(test_##type_code##_list__get(list_ptr, index), value);\
    test_assert##type_code(*ptr, value);\
    test_assertint(corto_ll_count(list_ptr), count_after);\
}

void test_rw_tc_collection_array(
    test_rw this)
{
    corto_type type;
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

    test_array_elem(obj, 0, corto_int32_o, int, 10);
    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_array_elem(obj, 1, corto_int32_o, int, 20);
    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_array_elem(obj, 2, corto_int32_o, int, 30);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}


void test_rw_tc_collection_list(
    test_rw this)
{
    corto_type type;

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

    test_list_elem(*obj, 0, corto_int32_o, int, 10, 0, 1);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_list_elem(*obj, 1, corto_int32_o, int, 20, 2, 2);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_list_elem(*obj, 2, corto_int32_o, int, 30, 3, 3);
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

    test_array_elem(obj->buffer, 0, corto_int32_o, int, 10);
    test_assertint(obj->length, 1);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_array_elem(obj->buffer, 1, corto_int32_o, int, 20);
    test_assertint(obj->length, 2);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_array_elem(obj->buffer, 2, corto_int32_o, int, 30);
    test_assertint(obj->length, 3);

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
    corto_type type;
    corto_member member;
    void *ptr;

    test_refsub obj = corto_declare(root_o, "obj", test_refsub_o);
    corto_rw init = corto_rw_init(test_refsub_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refsub_o);
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
    test_assert(member == test_refbase_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super.x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refbase_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super.y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refsub_z_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->z);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_inheritance_ref_nested(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    corto_object ref_base_obj = corto_create(NULL, NULL, test_refbase_o);
    test_assert(ref_base_obj != NULL);

    corto_object ref_sub_obj = corto_create(NULL, NULL, test_refsub_o);
    test_assert(ref_sub_obj != NULL);

    test_refsub_nested obj = corto_declare(root_o, "obj", test_refsub_nested_o);
    corto_rw init = corto_rw_init(test_refsub_nested_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refsub_nested_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refbase_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refsub_nested_m_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m);
    test_assert(corto_rw_set_ref(&init, ref_base_obj) == 0);
    test_assert(obj->m == ref_base_obj);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_refbase_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_refsub_nested_n_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->n);
    test_assert(corto_rw_set_ref(&init, ref_sub_obj) == 0);
    test_assert(obj->n == ref_sub_obj);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_rw_tc_inheritance_value(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valsub *obj = corto_declare(root_o, "obj", test_valsub_o);
    corto_rw init = corto_rw_init(test_valsub_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valsub_o);
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
    test_assert(member == test_valbase_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super.x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valbase_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super.y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valsub_z_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->z);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_inheritance_value_nested(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_valsub_nested *obj = corto_declare(root_o, "obj", test_valsub_nested_o);
    corto_rw init = corto_rw_init(test_valsub_nested_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_valsub_nested_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* root (valsub_nested) */
    test_assert(corto_rw_push(&init, false) == 0);

    /* m (valsub) */
    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valbase_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.super.x);
    test_assert(corto_rw_set_int(&init, 10) == 0);
    test_assertint(obj->m.super.x, 10);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valbase_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.super.y);
    test_assert(corto_rw_set_int(&init, 20) == 0);
    test_assertint(obj->m.super.y, 20);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valsub_z_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->m.z);
    test_assert(corto_rw_set_int(&init, 30) == 0);
    test_assertint(obj->m.z, 30);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);

    /* n -> m */
    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    /* n (valsub) */
    test_assert(corto_rw_push(&init, false) == 0);

    test_assertint(corto_rw_get_index(&init), 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valbase_x_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->n.super.x);
    test_assert(corto_rw_set_int(&init, 40) == 0);
    test_assertint(obj->n.super.x, 40);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 1);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valbase_y_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->n.super.y);
    test_assert(corto_rw_set_int(&init, 50) == 0);
    test_assertint(obj->n.super.y, 50);

    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_assertint(corto_rw_get_index(&init), 2);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_valsub_z_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->n.z);
    test_assert(corto_rw_set_int(&init, 60) == 0);
    test_assertint(obj->n.z, 60);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_nested_collection_array(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_s_nested_array *obj = corto_declare(root_o, "obj", test_s_nested_array_o);
    corto_rw init = corto_rw_init(test_s_nested_array_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_s_nested_array_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, false) == 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_array_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_s_nested_array_m_o);

    test_assert(corto_rw_push(&init, true) == 0);

    test_array_elem(obj->m, 0, corto_int32_o, int, 10);
    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_array_elem(obj->m, 1, corto_int32_o, int, 20);
    test_assert(corto_rw_has_next(&init) == true);
    test_assert(corto_rw_next(&init) == 0);

    test_array_elem(obj->m, 2, corto_int32_o, int, 30);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);

    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_nested_collection_list(
    test_rw this)
{
    corto_type type;
    corto_member member;

    test_s_nested_list *obj = corto_declare(root_o, "obj", test_s_nested_list_o);
    corto_rw init = corto_rw_init(test_s_nested_list_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_s_nested_list_o);
    test_assert(corto_rw_get_ptr(&init) == obj);

    /* Push s_nested_list (composite) scope */
    test_assert(corto_rw_push(&init, false) == 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_list_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_s_nested_list_m_o);

    /* Push list scope */
    test_assert(obj->m == NULL);
    test_assert(corto_rw_push(&init, true) == 0);
    test_assert(obj->m != NULL);
    test_assertint(corto_ll_count(obj->m), 0);

    test_list_elem(obj->m, 0, corto_int32_o, int, 10, 0, 1);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_list_elem(obj->m, 1, corto_int32_o, int, 20, 2, 2);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_list_elem(obj->m, 2, corto_int32_o, int, 30, 3, 3);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    /* s_nested_list */

    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_rw_tc_nested_collection_sequence(
    test_rw this)
{
    corto_type type;
    corto_member member;
    void *ptr;

    test_s_nested_sequence *obj = corto_declare(root_o, "obj", test_s_nested_sequence_o);
    corto_rw init = corto_rw_init(test_s_nested_sequence_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_s_nested_sequence_o);
    ptr = corto_rw_get_ptr(&init);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&init, false) == 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_seq_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_s_nested_sequence_m_o);

    test_assert(corto_rw_push(&init, true) == 0);
    test_assert(obj->m.buffer == NULL);
    test_assertint(obj->m.length, 0);

    test_array_elem(obj->m.buffer, 0, corto_int32_o, int, 10);
    test_assertint(obj->m.length, 1);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_array_elem(obj->m.buffer, 1, corto_int32_o, int, 20);
    test_assertint(obj->m.length, 2);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_next(&init) == 0); /* appends new element */

    test_array_elem(obj->m.buffer, 2, corto_int32_o, int, 30);
    test_assertint(obj->m.length, 3);

    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_rw_tc_nested_collection_list_empty(
    test_rw this)
{
    corto_type type;
    corto_member member;

    test_s_nested_list *obj = corto_declare(root_o, "obj", test_s_nested_list_o);
    corto_rw init = corto_rw_init(test_s_nested_list_o, obj);
    test_assert(corto_rw_has_next(&init) == false);

    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_s_nested_list_o);
    test_assert(corto_rw_get_ptr(&init) == obj);

    /* Push s_nested_list (composite) scope */
    test_assert(corto_rw_push(&init, false) == 0);
    type = corto_rw_get_type(&init);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_int_list_o);
    member = corto_rw_get_member(&init);
    test_assert(member != NULL);
    test_assert(member == test_s_nested_list_m_o);

    /* Push list scope */
    test_assert(obj->m == NULL);
    test_assert(corto_rw_push(&init, true) == 0);
    test_assert(obj->m != NULL);
    test_assertint(corto_ll_count(obj->m), 0);
    test_assert(corto_rw_has_next(&init) == false);
    test_assert(corto_rw_pop(&init) == 0);
    test_assertint(corto_ll_count(obj->m), 0);
    /* s_nested_list */

    test_assert(corto_rw_pop(&init) == 0);
    corto_rw_deinit(&init);

    test_assert(corto_define(obj) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_rw_tc_composite_out_of_bounds_by_one(
    test_rw this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(test_point_o, obj);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);

    /* Invalid index */
    test_assert(corto_rw_index(&rw, 2) != 0);
    test_assert(corto_catch() != 0);

    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_tc_composite_out_of_bounds(
    test_rw this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(test_point_o, obj);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);

    /* Invalid index */
    test_assert(corto_rw_index(&rw, 3) != 0);
    test_assert(corto_catch() != 0);

    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}
