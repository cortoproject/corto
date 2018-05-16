/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_assign_reftype_ptr_tc_byref_frommbr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == val);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byref_frommbr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == val);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byref_frommbr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign value to reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != val);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromnull(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_null();
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == NULL);
    test_assertint(corto_countof(foo), 1);

    corto_delete(foo);
}


void test_assign_reftype_ptr_tc_byref_fromobj_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromobj_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromobj_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromptr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromptr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byref_fromptr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_frommbr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == val);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_bytype_frommbr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == val);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_bytype_frommbr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign value to reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != val);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromnull(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_null();
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == NULL);
    test_assertint(corto_countof(foo), 1);

    corto_delete(foo);
}


void test_assign_reftype_ptr_tc_bytype_fromobj_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromobj_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromobj_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromptr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromptr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == bar);
    test_assertint(corto_countof(foo), 1);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_bytype_fromptr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_frommbr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byval_frommbr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* BY_TYPE is changed to BY_VALUE, since types of left and right match */
    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byval_frommbr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype val = corto_create(NULL, NULL, test_reftype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_refmbr bar = corto_create(NULL, NULL, test_refmbr_o);
    test_assert(bar != NULL);

    corto_set_ref(&bar->m, val);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_member(bar, test_refmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
    test_assert(corto_delete(val) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromnull(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_null();
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() == 1);

    test_assert(var == foo);
    test_assertint(corto_countof(foo), 2);

    corto_delete(foo);
}


void test_assign_reftype_ptr_tc_byval_fromobj_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromobj_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromobj_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromptr_byref(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(var != bar);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromptr_bytype(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_reftype_ptr_tc_byval_fromptr_byval(
    test_assign_reftype_ptr this)
{
    test_reftype foo = corto_create(NULL, NULL, test_reftype_o);
    test_assert(foo != NULL);

    test_reftype bar = corto_create(NULL, NULL, test_reftype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_object var = foo; corto_claim(foo);

    corto_value left = corto_value_pointer(&var, test_reftype_o);
    corto_value right = corto_value_pointer(&bar, test_reftype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assert(var == foo);
    test_assert(foo->x == 10);
    test_assert(foo->y == 20);
    test_assertint(corto_countof(foo), 2);

    corto_release(foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}
