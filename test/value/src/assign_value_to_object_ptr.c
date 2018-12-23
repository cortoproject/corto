/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void test_assign_value_to_object_ptr_tc_byref_fromobj_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assert(corto_countof(foo) == 1);
    test_assert(corto_release(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byref_fromobj_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assert(corto_countof(foo) == 1);
    test_assert(corto_release(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byref_fromobj_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byref_fromptr_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byref_fromptr_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byref_fromptr_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromobj_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assert(corto_countof(foo) == 1);
    test_assert(corto_release(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromobj_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assert(corto_countof(foo) == 1);
    test_assert(corto_release(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromobj_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromptr_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromptr_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_bytype_fromptr_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromobj_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromobj_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromobj_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromptr_byref(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromptr_bytype(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_value_to_object_ptr_tc_byval_fromptr_byval(
    test_assign_value_to_object_ptr this)
{
    corto_object foo = corto_create(NULL, NULL, corto_object_o);
    test_assert(foo != NULL);

    int32_t *bar = corto_create(NULL, NULL, corto_int32_o);
    test_assert(bar != NULL);

    *bar = 10;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, corto_object_o);
    corto_value right = corto_value_pointer(&bar, corto_int32_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take value from object pointer, don't know type of ref */
    test_assert(ret != 0);
    test_assert(ut_catch() != 0);

    test_assert(var == foo);
    test_assert(corto_release(foo) == 1);
    test_assert(corto_countof(bar) == 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}
