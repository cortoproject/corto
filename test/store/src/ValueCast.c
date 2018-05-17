/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_ValueCast_tc_castBinaryBool(
    test_ValueCast this)
{
    corto_word w = 10;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    w = 0;

    ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

}

void test_ValueCast_tc_castBinaryChar(
    test_ValueCast this)
{
    corto_word w = 65;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_char_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_char_o));

    corto_char *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 'A');

}

void test_ValueCast_tc_castBinaryFloat(
    test_ValueCast this)
{
    corto_word w = 10;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

}

void test_ValueCast_tc_castBinaryInt(
    test_ValueCast this)
{
    corto_word w = 10;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

}

void test_ValueCast_tc_castBinaryString(
    test_ValueCast this)
{
    corto_word w = 10;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "0xa");

}

void test_ValueCast_tc_castBinaryUint(
    test_ValueCast this)
{
    corto_word w = 10;
    corto_value left = corto_value_ptr(&w, corto_word_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

}

void test_ValueCast_tc_castBitmaskInt(
    test_ValueCast this)
{
    corto_attr v = CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_ptr(&v, corto_attr_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE);

}

void test_ValueCast_tc_castBitmaskString(
    test_ValueCast this)
{
    corto_attr v = CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_ptr(&v, corto_attr_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "ATTR_NAMED|ATTR_WRITABLE");

}

void test_ValueCast_tc_castBitmaskUint(
    test_ValueCast this)
{
    corto_attr v = CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_ptr(&v, corto_attr_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE);

}

void test_ValueCast_tc_castBoolBinary(
    test_ValueCast this)
{
    corto_bool v = TRUE;
    corto_value left = corto_value_ptr(&v, corto_bool_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_word_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

}

void test_ValueCast_tc_castBoolInt(
    test_ValueCast this)
{
    corto_bool v = TRUE;
    corto_value left = corto_value_ptr(&v, corto_bool_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

}

void test_ValueCast_tc_castBoolString(
    test_ValueCast this)
{
    corto_bool v = TRUE;
    corto_value left = corto_value_ptr(&v, corto_bool_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "true");

    v = FALSE;

    ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "false");

}

void test_ValueCast_tc_castBoolUint(
    test_ValueCast this)
{
    corto_bool v = TRUE;
    corto_value left = corto_value_ptr(&v, corto_bool_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

}

void test_ValueCast_tc_castEnumInt(
    test_ValueCast this)
{
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_ptr(&v, corto_width_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

}

void test_ValueCast_tc_castEnumString(
    test_ValueCast this)
{
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_ptr(&v, corto_width_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "WIDTH_WORD");

}

void test_ValueCast_tc_castEnumUint(
    test_ValueCast this)
{
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_ptr(&v, corto_width_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

}

void test_ValueCast_tc_castFloatBool(
    test_ValueCast this)
{
    corto_float64 v = 10.5;
    corto_value left = corto_value_ptr(&v, corto_float64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = 0;
    ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

}

void test_ValueCast_tc_castFloatInt(
    test_ValueCast this)
{
    corto_float64 v = 10.5;
    corto_value left = corto_value_ptr(&v, corto_float64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

}

void test_ValueCast_tc_castFloatString(
    test_ValueCast this)
{
    corto_float64 v = 10.5;
    corto_value left = corto_value_ptr(&v, corto_float64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10.500000");

    corto_value_free(&out);

}

void test_ValueCast_tc_castFloatUint(
    test_ValueCast this)
{
    corto_float64 v = 10.5;
    corto_value left = corto_value_ptr(&v, corto_float64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castIntBinary(
    test_ValueCast this)
{
    corto_int64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castIntBool(
    test_ValueCast this)
{
    corto_int64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = 0;
    ret = corto_value_cast(&left, corto_bool_o, false, &out);
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

void test_ValueCast_tc_castIntChar(
    test_ValueCast this)
{
    corto_int64 v = 65;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_char_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_char_o));

    corto_char *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 'A');

    corto_value_free(&out);

}

void test_ValueCast_tc_castIntFloat(
    test_ValueCast this)
{
    corto_int64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castIntString(
    test_ValueCast this)
{
    corto_int64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");

    corto_value_free(&out);

}

void test_ValueCast_tc_castIntUint(
    test_ValueCast this)
{
    corto_int64 v = 10;
    corto_value left = corto_value_ptr(&v, corto_int64_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castStringBinary(
    test_ValueCast this)
{
    corto_string v = "0xa";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castStringBool(
    test_ValueCast this)
{
    corto_string v = "true";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = "false";

    ret = corto_value_cast(&left, corto_bool_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = NULL;

    ret = corto_value_cast(&left, corto_bool_o, false, &out);
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

void test_ValueCast_tc_castStringEnum(
    test_ValueCast this)
{
    corto_string v = "WIDTH_WORD";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_width_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_width_o));

    corto_width *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

    corto_value_free(&out);

}

void test_ValueCast_tc_castStringFloat(
    test_ValueCast this)
{
    corto_string v = "10.5";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10.5);

    corto_value_free(&out);

}

void test_ValueCast_tc_castStringInt(
    test_ValueCast this)
{
    corto_string v = "10";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}

void test_ValueCast_tc_castStringUint(
    test_ValueCast this)
{
    corto_string v = "10";
    corto_value left = corto_value_ptr(&v, corto_string_o);
    corto_value out = corto_value_ptr(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, false, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_POINTER);

    corto_type type = corto_value_typeof(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_ptrof(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

}
