/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_ValueExpr_tc_add(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);

    corto_value_free(&out);

}

void test_ValueExpr_tc_and(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(12);
    corto_value right = corto_value_int(9);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 8);

    corto_value_free(&out);

}

void test_ValueExpr_tc_condAnd(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set right to 0 so that expression evaluates to FALSE
    right = corto_value_int(0);
    ret = corto_value_binaryOp(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

    // Set left to 0 to validate that expression still evaluates to FALSE
    left = corto_value_int(0);
    ret = corto_value_binaryOp(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

    corto_value_free(&out);

}

void test_ValueExpr_tc_condNot(
    test_ValueExpr this)
{
    corto_value left = corto_value_bool(FALSE);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_unaryOp(CORTO_COND_NOT, &left, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    corto_value_free(&out);

}

void test_ValueExpr_tc_condOr(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set right to 0 so that expression evaluates to FALSE
    right = corto_value_int(0);
    ret = corto_value_binaryOp(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set left to 0 to validate that expression still evaluates to FALSE
    left = corto_value_int(0);
    ret = corto_value_binaryOp(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);
    corto_value_free(&out);

}

void test_ValueExpr_tc_div(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_DIV, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 0.5);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAddFltInt(
    test_ValueExpr this)
{
    corto_value left = corto_value_float(10.5);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 30.5);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAddIntFlt(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_float(20.5);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 30.5);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAddIntStr(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_string("Hello");
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10Hello");

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAddStrInt(
    test_ValueExpr this)
{
    corto_value left = corto_value_string("Hello");
    corto_value right = corto_value_int(10);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello10");

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAddStrStr(
    test_ValueExpr this)
{
    corto_value left = corto_value_string("Hello");
    corto_value right = corto_value_string("World");
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "HelloWorld");

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignBoolRef(
    test_ValueExpr this)
{
    corto_bool leftValue = FALSE;
    corto_value left = corto_value_ptr(&leftValue, corto_bool_o);
    corto_value right = corto_value_ptr(corto_typeKind_o, corto_object_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);
    test_assertint(leftValue, TRUE);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignFltInt(
    test_ValueExpr this)
{
    corto_float64 leftValue = 0;
    corto_value left = corto_value_ptr(&leftValue, corto_float64_o);
    corto_value right = corto_value_int(10);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);
    test_assertflt(leftValue, 10);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignIntFlt(
    test_ValueExpr this)
{
    corto_int64 leftValue = 0;
    corto_value left = corto_value_ptr(&leftValue, corto_int64_o);
    corto_value right = corto_value_float(10.5);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignIntInt(
    test_ValueExpr this)
{
    corto_int64 leftValue = 0;
    corto_value left = corto_value_ptr(&leftValue, corto_int64_o);
    corto_value right = corto_value_int(10);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignIntStr(
    test_ValueExpr this)
{
    corto_int64 leftValue = 0;
    corto_value left = corto_value_ptr(&leftValue, corto_int64_o);
    corto_value right = corto_value_string("10");
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignStrInt(
    test_ValueExpr this)
{
    corto_string leftValue = NULL;
    corto_value left = corto_value_ptr(&leftValue, corto_string_o);
    corto_value right = corto_value_int(10);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");
    test_assertstr(leftValue, "10");

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprAssignStrStr(
    test_ValueExpr this)
{
    corto_string leftValue = NULL;
    corto_value left = corto_value_ptr(&leftValue, corto_string_o);
    corto_value right = corto_value_string("Hello");
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello");

    ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello");
    test_assertstr(leftValue, "Hello");

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprMemLiteralOut(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_int(0);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprMemMemberInOut(
    test_ValueExpr this)
{
    test_Point p = {10, 20};
    corto_value pY, pValue = corto_value_ptr(&p, test_Point_o);
    test_assert(corto_value_memberExpr(&pValue, "y", &pY) == 0);
    corto_value v = corto_value_int(30);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &pY, &v, &pY);
    test_assert(ret == 0);
    test_assert(pY.kind == CORTO_MEMBER);

    corto_type type = corto_value_typeof(&pY);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int32_o));

    corto_int32 *ptr = corto_value_ptrof(&pY);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 50);
    test_assertint(p.x, 10);
    test_assertint(p.y, 50);

    corto_value_free(&pY);

}

void test_ValueExpr_tc_exprMemMemberOut(
    test_ValueExpr this)
{
    test_Point p = {10, 20};
    corto_value pX, pValue = corto_value_ptr(&p, test_Point_o);
    test_assert(corto_value_memberExpr(&pValue, "x", &pX) == 0);
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &pX);
    test_assert(ret == 0);
    test_assert(pX.kind == CORTO_MEMBER);

    corto_type type = corto_value_typeof(&pX);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int32_o));

    corto_int32 *ptr = corto_value_ptrof(&pX);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);
    test_assertint(p.x, 30);
    test_assertint(p.y, 20);

    corto_value_free(&pX);

}

void test_ValueExpr_tc_exprMemNullOut(
    test_ValueExpr this)
{
    corto_uint64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value right = corto_value_int(20);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &left, &right, NULL);
    test_assert(ret == 0);
    test_assert(left.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&left);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 20);
    test_assertint(v, 20);

    corto_value_free(&right);

}

void test_ValueExpr_tc_exprMemNullOutAssignMember(
    test_ValueExpr this)
{
    test_Point p = {10, 20};
    corto_value pX, pValue = corto_value_ptr(&p, test_Point_o);
    test_assert(corto_value_memberExpr(&pValue, "x", &pX) == 0);
    corto_value v = corto_value_int(30);

    corto_int16 ret = corto_value_binaryOp(CORTO_ASSIGN, &pX, &v, NULL);
    test_assert(ret == 0);
    test_assert(pX.kind == CORTO_MEMBER);

    corto_type type = corto_value_typeof(&pX);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int32_o));

    corto_int32 *ptr = corto_value_ptrof(&pX);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);
    test_assertint(p.x, 30);
    test_assertint(p.y, 20);

    corto_value_free(&pX);

}

void test_ValueExpr_tc_exprMemPtrOut(
    test_ValueExpr this)
{
    corto_uint64 v = 10;
    corto_value out = corto_value_ptr(&v, corto_int64_o);
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);
    test_assertint(v, 30);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprMemSameInOut(
    test_ValueExpr this)
{
    corto_uint64 val = 10;
    corto_value out = corto_value_ptr(&val, corto_int64_o);
    corto_value v = corto_value_int(20);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &out, &v, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);
    test_assertint(val, 30);

    corto_value_free(&out);

}

void test_ValueExpr_tc_exprMemValueOut(
    test_ValueExpr this)
{
    corto_value out = corto_value_init();
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);

    corto_int16 ret = corto_value_binaryOp(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);

    corto_value_free(&out);

}

void test_ValueExpr_tc_member(
    test_ValueExpr this)
{
    test_Point *p = corto_create(NULL, NULL, test_Point_o);
    test_assert(p != NULL);

    p->x = 10;
    p->y = 20;

    corto_value v = corto_value_object(p, NULL);
    corto_value out;

    corto_int16 ret = corto_value_memberExpr(&v, "x", &out);
    test_assert(ret == 0);
    corto_type type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    void *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 10);

    ret = corto_value_memberExpr(&v, "y", &out);
    test_assert(ret == 0);
    type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 20);

}

void test_ValueExpr_tc_memberNested(
    test_ValueExpr this)
{

    test_Line *l = corto_create(NULL, NULL, test_Line_o);
    test_assert(l != NULL);

    l->start.x = 10;
    l->start.y = 20;
    l->stop.x = 30;
    l->stop.y = 40;

    corto_value v = corto_value_object(l, NULL);
    corto_value out;

    corto_int16 ret = corto_value_memberExpr(&v, "start.x", &out);
    test_assert(ret == 0);
    corto_type type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    void *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 10);

    ret = corto_value_memberExpr(&v, "start.y", &out);
    test_assert(ret == 0);
    type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 20);

    ret = corto_value_memberExpr(&v, "stop.x", &out);
    test_assert(ret == 0);
    type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 30);

    ret = corto_value_memberExpr(&v, "stop.y", &out);
    test_assert(ret == 0);
    type = corto_value_typeof(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 40);

}

void test_ValueExpr_tc_mod(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(3);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_MOD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 1);

    corto_value_free(&out);

}

void test_ValueExpr_tc_mul(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_MUL, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 200);

    corto_value_free(&out);

}

void test_ValueExpr_tc_or(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(12);
    corto_value right = corto_value_int(9);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 13);

    corto_value_free(&out);

}

void test_ValueExpr_tc_sub(
    test_ValueExpr this)
{
    corto_value left = corto_value_int(10);
    corto_value right = corto_value_int(20);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_binaryOp(CORTO_SUB, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, -10);

    corto_value_free(&out);

}

