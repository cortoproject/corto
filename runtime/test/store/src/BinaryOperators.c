/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_BinaryOperators_tc_compareStringEqual(
    test_BinaryOperators this)
{
    corto_string target = "ABC";
    corto_string targetNull = NULL;

    corto_string *str = corto_stringCreate("ABC");
    corto_string *strNull = (corto_string *)corto_create(corto_string_o);

    corto_type type = corto_typeof(str);

    bool equal = false;
    test_assert(corto_ptr_binaryOp(type, CORTO_COND_EQ, &target, &*str, &equal) == 0);
    test_assert(equal == true);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_EQ, &target, &targetNull, &equal) == 0);
    test_assert(equal == false);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_EQ, &target, &strNull, &equal) == 0);
    test_assert(equal == false);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_EQ, &targetNull, &*strNull, &equal) == 0);
    test_assert(equal == true);
}

void test_BinaryOperators_tc_compareStringNotEqual(
    test_BinaryOperators this)
{
    corto_string target = "ABC";
    corto_string targetNull = NULL;

    corto_string *str = corto_stringCreate("ABC");
    corto_string *strNull = (corto_string *)corto_create(corto_string_o);

    corto_type type = corto_typeof(str);

    bool notEqual = true;
    test_assert(corto_ptr_binaryOp(type, CORTO_COND_NEQ, &target, &*str, &notEqual) == 0);
    test_assert(notEqual == false);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_NEQ, &target, &targetNull, &notEqual) == 0);
    test_assert(notEqual == true);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_NEQ, &target, &strNull, &notEqual) == 0);
    test_assert(notEqual == true);

    test_assert(corto_ptr_binaryOp(type, CORTO_COND_NEQ, &targetNull, &*strNull, &notEqual) == 0);
    test_assert(notEqual == false);
}
