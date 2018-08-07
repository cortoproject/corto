/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_assign_ref_to_bool_obj_tc_byref_fromobj_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byref_fromobj_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byref_fromobj_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byref_fromptr_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byref_fromptr_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byref_fromptr_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromobj_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromobj_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromobj_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromptr_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromptr_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_bytype_fromptr_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromobj_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromobj_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromobj_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromptr_byref(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromptr_bytype(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(*foo == true);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_ref_to_bool_obj_tc_byval_fromptr_byval(
    test_assign_ref_to_bool_obj this)
{
    bool *foo = corto_create(NULL, NULL, corto_bool_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(*foo == false);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}
