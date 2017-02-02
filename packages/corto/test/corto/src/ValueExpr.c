/* $CORTO_GENERATED
 *
 * ValueExpr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_ValueExpr_tc_add(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_add) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 30);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_and(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_and) */
    corto_value left = corto_value_literalInteger(12);
    corto_value right = corto_value_literalInteger(9);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 8);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_condAnd(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_condAnd) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set right to 0 so that expression evaluates to FALSE
    right = corto_value_literalInteger(0);
    ret = corto_value_binaryOperator(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

    // Set left to 0 to validate that expression still evaluates to FALSE
    left = corto_value_literalInteger(0);
    ret = corto_value_binaryOperator(CORTO_COND_AND, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_condNot(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_condNot) */
    corto_value left = corto_value_literalBoolean(FALSE);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_unaryOperator(CORTO_COND_NOT, &left, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_condOr(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_condOr) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set right to 0 so that expression evaluates to FALSE
    right = corto_value_literalInteger(0);
    ret = corto_value_binaryOperator(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    // Set left to 0 to validate that expression still evaluates to FALSE
    left = corto_value_literalInteger(0);
    ret = corto_value_binaryOperator(CORTO_COND_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);
    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_div(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_div) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_DIV, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 0.5);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAddFltInt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAddFltInt) */
    corto_value left = corto_value_literalFloatingPoint(10.5);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 30.5);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAddIntFlt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAddIntFlt) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalFloatingPoint(20.5);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 30.5);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAddIntStr(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAddIntStr) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalString("Hello");
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10Hello");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAddStrInt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAddStrInt) */
    corto_value left = corto_value_literalString("Hello");
    corto_value right = corto_value_literalInteger(10);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello10");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAddStrStr(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAddStrStr) */
    corto_value left = corto_value_literalString("Hello");
    corto_value right = corto_value_literalString("World");
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ADD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "HelloWorld");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignBoolRef(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignBoolRef) */
    corto_bool leftValue = FALSE;
    corto_value left = corto_value_value(corto_bool_o, &leftValue);
    corto_value right = corto_value_value(corto_object_o, corto_typeKind_o);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);
    test_assertint(leftValue, TRUE);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignFltInt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignFltInt) */
    corto_float64 leftValue = 0;
    corto_value left = corto_value_value(corto_float64_o, &leftValue);
    corto_value right = corto_value_literalInteger(10);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);
    test_assertflt(leftValue, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignIntFlt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignIntFlt) */
    corto_int64 leftValue = 0;
    corto_value left = corto_value_value(corto_int64_o, &leftValue);
    corto_value right = corto_value_literalFloatingPoint(10.5);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignIntInt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignIntInt) */
    corto_int64 leftValue = 0;
    corto_value left = corto_value_value(corto_int64_o, &leftValue);
    corto_value right = corto_value_literalInteger(10);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignIntStr(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignIntStr) */
    corto_int64 leftValue = 0;
    corto_value left = corto_value_value(corto_int64_o, &leftValue);
    corto_value right = corto_value_literalString("10");
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);
    test_assertint(leftValue, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignStrInt(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignStrInt) */
    corto_string leftValue = NULL;
    corto_value left = corto_value_value(corto_string_o, &leftValue);
    corto_value right = corto_value_literalInteger(10);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");
    test_assertstr(leftValue, "10");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_exprAssignStrStr(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_exprAssignStrStr) */
    corto_string leftValue = NULL;
    corto_value left = corto_value_value(corto_string_o, &leftValue);
    corto_value right = corto_value_literalString("Hello");
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_ASSIGN, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello");

    ptr = corto_value_getPtr(&left);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "Hello");
    test_assertstr(leftValue, "Hello");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_member(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_member) */
    test_Point *p = corto_create(test_Point_o);
    test_assert(p != NULL);

    p->x = 10;
    p->y = 20;

    corto_value v = corto_value_object(p, NULL);
    corto_value out;

    corto_int16 ret = corto_value_getMember(&v, "x", &out);
    test_assert(ret == 0);
    corto_type type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    void *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 10);

    ret = corto_value_getMember(&v, "y", &out);
    test_assert(ret == 0);
    type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 20);

/* $end */
}

corto_void _test_ValueExpr_tc_memberNested(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_memberNested) */

    test_Line *l = corto_create(test_Line_o);
    test_assert(l != NULL);

    l->start.x = 10;
    l->start.y = 20;
    l->stop.x = 30;
    l->stop.y = 40;

    corto_value v = corto_value_object(l, NULL);
    corto_value out;

    corto_int16 ret = corto_value_getMember(&v, "start.x", &out);
    test_assert(ret == 0);
    corto_type type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    void *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 10);

    ret = corto_value_getMember(&v, "start.y", &out);
    test_assert(ret == 0);
    type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 20);

    ret = corto_value_getMember(&v, "stop.x", &out);
    test_assert(ret == 0);
    type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 30);

    ret = corto_value_getMember(&v, "stop.y", &out);
    test_assert(ret == 0);
    type = corto_value_getType(&out);
    test_assert(type == corto_type(corto_int32_o));
    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*(corto_int32*)ptr, 40);

/* $end */
}

corto_void _test_ValueExpr_tc_mod(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_mod) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(3);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_MOD, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 1);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_mul(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_mul) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_MUL, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 200);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_or(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_or) */
    corto_value left = corto_value_literalInteger(12);
    corto_value right = corto_value_literalInteger(9);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_OR, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 13);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueExpr_tc_sub(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_sub) */
    corto_value left = corto_value_literalInteger(10);
    corto_value right = corto_value_literalInteger(20);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_binaryOperator(CORTO_SUB, &left, &right, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, -10);

    corto_value_free(&out);

/* $end */
}
