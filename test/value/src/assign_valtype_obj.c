/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void test_assign_valtype_obj_tc_byref_frommbr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot obtain reference from non-reference member value */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_frommbr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_frommbr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromobj_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromobj_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromobj_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromptr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromptr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byref_fromptr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_REFERENCE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign object by reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_frommbr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot obtain reference from non-reference member */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_frommbr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_frommbr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromobj_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign reference to non-reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromobj_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromobj_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromptr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign reference to non-reference */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromptr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_bytype_fromptr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_TYPE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_frommbr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot obtain reference from non-reference member */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_frommbr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_frommbr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *val = corto_create(NULL, NULL, test_valtype_o);
    test_assert(val != NULL);

    val->x = 10;
    val->y = 20;

    test_valmbr *bar = corto_create(NULL, NULL, test_valmbr_o);
    test_assert(bar != NULL);

    bar->m = *val;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_member(bar, test_valmbr_m_o, &bar->m);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromobj_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot assign reference to non-reference value */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromobj_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromobj_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_object(bar, NULL);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromptr_byref(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_REFERENCE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    /* Cannot take reference from non-reference value */
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assertint(foo->x, 0);
    test_assertint(foo->y, 0);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromptr_bytype(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_TYPE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}


void test_assign_valtype_obj_tc_byval_fromptr_byval(
    test_assign_valtype_obj this)
{
    test_valtype *foo = corto_create(NULL, NULL, test_valtype_o);
    test_assert(foo != NULL);

    test_valtype *bar = corto_create(NULL, NULL, test_valtype_o);
    test_assert(bar != NULL);

    bar->x = 10;
    bar->y = 20;

    corto_value left = corto_value_object(foo, NULL);
    corto_value right = corto_value_pointer(bar, test_valtype_o);
    corto_value result = corto_value_init();

    left.ref_kind = CORTO_BY_VALUE;
    right.ref_kind = CORTO_BY_VALUE;

    int16_t ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &result);

    test_assert(ret == 0);

    test_assertint(foo->x, 10);
    test_assertint(foo->y, 20);

    test_assert(result.kind == CORTO_POINTER);
    void *ptr = corto_value_ptrof(&result);
    test_assert(ptr != NULL);
    test_assert(ptr == foo);

    test_assert(corto_delete(foo) == 0);
    test_assert(corto_delete(bar) == 0);
}
