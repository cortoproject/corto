/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

#define test_field(rw, index, m, t, obj_ptr)\
{\
    test_assertint(corto_rw_get_index(rw), index);\
    corto_type type = corto_rw_get_type(rw);\
    test_assert(type != NULL);\
    test_assert(type == t);\
    corto_member member = corto_rw_get_member(rw);\
    test_assert(member == m);\
    void *ptr = corto_rw_get_ptr(rw);\
    test_assert(ptr != NULL);\
    test_assert(ptr == obj_ptr);\
}

void test_rw_field_expr_tc_composite_full(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(obj, test_point_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}


void test_rw_field_expr_tc_composite_full_reverse(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(obj, test_point_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}


void test_rw_field_expr_tc_composite_mixed(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(obj, test_point_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_next(&rw) == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}


void test_rw_field_expr_tc_composite_partial(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point *obj = corto_declare(root_o, "obj", test_point_o);
    corto_rw rw = corto_rw_init(obj, test_point_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_expr_full(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    test_assert(corto_rw_field(&rw, "start.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.x, 10);

    test_assert(corto_rw_field(&rw, "start.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_field(&rw, "stop.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_field(&rw, "stop.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_pop(&rw) == 0);

    /* Verify we're back at the root */
    test_field(&rw, -1, NULL, (corto_type)test_line_o, obj);

    corto_rw_deinit(&rw);
    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_expr_full_reverse(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    test_assert(corto_rw_field(&rw, "stop.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_field(&rw, "stop.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_field(&rw, "start.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_field(&rw, "start.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.x, 10);

    test_assert(corto_rw_pop(&rw) == 0);

    /* Verify we're back at the root */
    test_field(&rw, -1, NULL, (corto_type)test_line_o, obj);

    corto_rw_deinit(&rw);
    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_expr_mixed(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    test_assert(corto_rw_field(&rw, "start.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.x, 10);

    test_assert(corto_rw_field(&rw, "start.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_field(&rw, "stop") == 0);
    test_field(&rw, 1, test_line_stop_o, (corto_type)test_point_o, &obj->stop);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);
    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_expr_partial(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    test_assert(corto_rw_field(&rw, "stop.x") == 0);
    test_field(&rw, -1, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_field(&rw, "start.y") == 0);
    test_field(&rw, -1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.y, 10);

    test_assert(corto_rw_pop(&rw) == 0);

    /* Verify we're back at the root */
    test_field(&rw, -1, NULL, (corto_type)test_line_o, obj);

    corto_rw_deinit(&rw);
    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_push_full(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_assert(corto_rw_field(&rw, "start") == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    /* point (start) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_field(&rw, "stop") == 0);
    test_field(&rw, 1, test_line_stop_o, (corto_type)test_point_o, &obj->stop);

    /* point (stop) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_push_full_reverse(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    /* point (start) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.y, 10);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.x, 20);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_pop(&rw) == 0);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_next(&rw) == 0);

    test_field(&rw, 1, test_line_stop_o, (corto_type)test_point_o, &obj->stop);

    /* point (stop) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.y, 30);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.x, 40);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_push_mixed(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    /* point (start) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->start.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->start.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_next(&rw) == 0);

    test_field(&rw, 1, test_line_stop_o, (corto_type)test_point_o, &obj->stop);

    /* point (stop) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->stop.x);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->stop.x, 30);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_nested_push_partial(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_line *obj = corto_declare(root_o, "obj", test_line_o);
    corto_rw rw = corto_rw_init(obj, test_line_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_line_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* line */
    test_assert(corto_rw_push(&rw, false) == 0);
    test_field(&rw, 0, test_line_start_o, (corto_type)test_point_o, &obj->start);

    /* point (start) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->start.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->start.y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_next(&rw) == 0);

    test_field(&rw, 1, test_line_stop_o, (corto_type)test_point_o, &obj->stop);

    /* point (stop) */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->stop.y);
    test_assert(corto_rw_set_int(&rw, 40) == 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_push_full(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* point3d */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super") == 0);
    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super);

    /* point */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    /* point3d */

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_push_full_reverse(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* point3d */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "super") == 0);
    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super);

    /* point */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.y, 10);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.x, 20);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_pop(&rw) == 0);
    /* point3d */

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_push_mixed(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* point3d */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super") == 0);
    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super);

    /* point */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);
    test_assert(corto_rw_next(&rw) == 0);

    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    /* point3d */

    test_assert(corto_rw_next(&rw) == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_push_partial(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* point3d */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super") == 0);
    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super);

    /* point */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_pop(&rw) == 0);
    /* point3d */

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_push_mixed_three_values(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_three_values_sub *obj = corto_declare(root_o, "obj", test_three_values_sub_o);
    corto_rw rw = corto_rw_init(obj, test_three_values_sub_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_three_values_sub_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    /* three_values_sub */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super") == 0);
    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_three_values_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == &obj->super);

    /* three_values */
    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "b") == 0);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.b, 10);

    /* This tests whether the index is initialized to 1 instead of 0 */
    test_assert(corto_rw_next(&rw) == 0);

    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.b, 10);
    test_assertint(obj->super.c, 20);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    /* point3d */

    test_assert(corto_rw_next(&rw) == 0);
    test_field(&rw, 3, test_three_values_sub_a_o, (corto_type)corto_int32_o, &obj->a);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->a, 30);

    test_assert(corto_rw_next(&rw) == 0);
    test_field(&rw, 4, test_three_values_sub_b_o, (corto_type)corto_int32_o, &obj->b);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->b, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_expr_full(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super.x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "super.y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_expr_full_reverse(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);

    test_assert(corto_rw_field(&rw, "super.y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "super.x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_expr_mixed(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super.x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "super.y") == 0);
    test_field(&rw, 1, test_point_y_o, (corto_type)corto_int32_o, &obj->super.y);
    test_assert(corto_rw_set_int(&rw, 20) == 0);
    test_assertint(obj->super.y, 20);

    test_assert(corto_rw_next(&rw) == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}

void test_rw_field_expr_tc_inheritance_expr_partial(
    test_rw_field_expr this)
{
    corto_type type;
    void *ptr;

    test_point3d *obj = corto_declare(root_o, "obj", test_point3d_o);
    corto_rw rw = corto_rw_init(obj, test_point3d_o);
    test_assert(corto_rw_has_next(&rw) == false);

    type = corto_rw_get_type(&rw);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_point3d_o);
    ptr = corto_rw_get_ptr(&rw);
    test_assert(ptr != NULL);
    test_assert(ptr == obj);

    test_assert(corto_rw_push(&rw, false) == 0);

    test_assert(corto_rw_field(&rw, "super.x") == 0);
    test_field(&rw, 0, test_point_x_o, (corto_type)corto_int32_o, &obj->super.x);
    test_assert(corto_rw_set_int(&rw, 10) == 0);
    test_assertint(obj->super.x, 10);

    test_assert(corto_rw_has_next(&rw) == true);

    test_assert(corto_rw_field(&rw, "z") == 0);
    test_field(&rw, 2, test_point3d_z_o, (corto_type)corto_int32_o, &obj->z);
    test_assert(corto_rw_set_int(&rw, 30) == 0);
    test_assertint(obj->z, 30);

    test_assert(corto_rw_has_next(&rw) == false);
    test_assert(corto_rw_pop(&rw) == 0);
    corto_rw_deinit(&rw);

    test_assert(corto_define(obj) == 0);
}
