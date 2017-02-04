/* $CORTO_GENERATED
 *
 * ValueCast.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_ValueCast_tc_castBinaryBool(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryBool) */
    corto_word w = 10;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    w = 0;

    ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

/* $end */
}

corto_void _test_ValueCast_tc_castBinaryChar(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryChar) */
    corto_word w = 65;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_char_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_char_o));

    corto_char *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 'A');

/* $end */
}

corto_void _test_ValueCast_tc_castBinaryFloat(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryFloat) */
    corto_word w = 10;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

/* $end */
}

corto_void _test_ValueCast_tc_castBinaryInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryInt) */
    corto_word w = 10;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

/* $end */
}

corto_void _test_ValueCast_tc_castBinaryString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryString) */
    corto_word w = 10;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "0xa");

/* $end */
}

corto_void _test_ValueCast_tc_castBinaryUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBinaryUint) */
    corto_word w = 10;
    corto_value left = corto_value_value(corto_word_o, &w);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

/* $end */
}

corto_void _test_ValueCast_tc_castBitmaskInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBitmaskInt) */
    corto_attr v = CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_value(corto_attr_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE);

/* $end */
}

corto_void _test_ValueCast_tc_castBitmaskString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBitmaskString) */
    corto_attr v = CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_value(corto_attr_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "ATTR_SCOPED|ATTR_WRITABLE");

/* $end */
}

corto_void _test_ValueCast_tc_castBitmaskUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBitmaskUint) */
    corto_attr v = CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE;
    corto_value left = corto_value_value(corto_attr_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE);

/* $end */
}

corto_void _test_ValueCast_tc_castBoolBinary(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBoolBinary) */
    corto_bool v = TRUE;
    corto_value left = corto_value_value(corto_bool_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_word_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

/* $end */
}

corto_void _test_ValueCast_tc_castBoolInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBoolInt) */
    corto_bool v = TRUE;
    corto_value left = corto_value_value(corto_bool_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

/* $end */
}

corto_void _test_ValueCast_tc_castBoolString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBoolString) */
    corto_bool v = TRUE;
    corto_value left = corto_value_value(corto_bool_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "true");

    v = FALSE;

    ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "false");

/* $end */
}

corto_void _test_ValueCast_tc_castBoolUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castBoolUint) */
    corto_bool v = TRUE;
    corto_value left = corto_value_value(corto_bool_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = FALSE;

    ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

/* $end */
}

corto_void _test_ValueCast_tc_castEnumInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castEnumInt) */
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_value(corto_width_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

/* $end */
}

corto_void _test_ValueCast_tc_castEnumString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castEnumString) */
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_value(corto_width_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "WIDTH_WORD");

/* $end */
}

corto_void _test_ValueCast_tc_castEnumUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castEnumUint) */
    corto_width v = CORTO_WIDTH_WORD;
    corto_value left = corto_value_value(corto_width_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

/* $end */
}

corto_void _test_ValueCast_tc_castFloatBool(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castFloatBool) */
    corto_float64 v = 10.5;
    corto_value left = corto_value_value(corto_float64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = 0;
    ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, FALSE);

/* $end */
}

corto_void _test_ValueCast_tc_castFloatInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castFloatInt) */
    corto_float64 v = 10.5;
    corto_value left = corto_value_value(corto_float64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

/* $end */
}

corto_void _test_ValueCast_tc_castFloatString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castFloatString) */
    corto_float64 v = 10.5;
    corto_value left = corto_value_value(corto_float64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10.500000");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castFloatUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castFloatUint) */
    corto_float64 v = 10.5;
    corto_value left = corto_value_value(corto_float64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castIntBinary(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntBinary) */
    corto_int64 v = 10;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castIntBool(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntBool) */
    corto_int64 v = 10;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = 0;
    ret = corto_value_cast(&left, corto_bool_o, &out);
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

corto_void _test_ValueCast_tc_castIntChar(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntChar) */
    corto_int64 v = 65;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_char_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_char_o));

    corto_char *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 'A');

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castIntFloat(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntFloat) */
    corto_int64 v = 10;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castIntString(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntString) */
    corto_int64 v = 10;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_string_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_string_o));

    corto_string *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertstr(*ptr, "10");

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castIntUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castIntUint) */
    corto_int64 v = 10;
    corto_value left = corto_value_value(corto_int64_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castStringBinary(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringBinary) */
    corto_string v = "0xa";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_word_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_word_o));

    corto_word *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castStringBool(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringBool) */
    corto_string v = "true";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_bool_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_bool_o));

    corto_bool *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, TRUE);

    v = "false";

    ret = corto_value_cast(&left, corto_bool_o, &out);
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

corto_void _test_ValueCast_tc_castStringEnum(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringEnum) */
    corto_string v = "WIDTH_WORD";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_width_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_width_o));

    corto_width *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, CORTO_WIDTH_WORD);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castStringFloat(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringFloat) */
    corto_string v = "10.5";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_float64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_float64_o));

    corto_float64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertflt(*ptr, 10.5);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castStringInt(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringInt) */
    corto_string v = "10";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_int64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_int64_o));

    corto_int64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}

corto_void _test_ValueCast_tc_castStringUint(
    test_ValueCast this)
{
/* $begin(test/ValueCast/tc_castStringUint) */
    corto_string v = "10";
    corto_value left = corto_value_value(corto_string_o, &v);
    corto_value out = corto_value_value(NULL, NULL);

    corto_int16 ret = corto_value_cast(&left, corto_uint64_o, &out);
    test_assert(ret == 0);
    test_assert(out.kind == CORTO_VALUE);

    corto_type type = corto_value_getType(&out);
    test_assert(type != NULL);
    test_assert(type == corto_type(corto_uint64_o));

    corto_uint64 *ptr = corto_value_getPtr(&out);
    test_assert(ptr != NULL);
    test_assertint(*ptr, 10);

    corto_value_free(&out);

/* $end */
}
