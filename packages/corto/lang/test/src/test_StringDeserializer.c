/* test_StringDeserializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::StringDeserializer::setup() */
cx_void _test_StringDeserializer_setup(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::setup) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolExisting() */
cx_void _test_StringDeserializer_tc_deserBoolExisting(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolExisting) */

    cx_object o = cx_boolCreate(FALSE); cx_fromStr(&o, "true");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolExisting_w_type() */
cx_void _test_StringDeserializer_tc_deserBoolExisting_w_type(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolExisting_w_type) */

    cx_object o = cx_boolCreate(FALSE); cx_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolFalse() */
cx_void _test_StringDeserializer_tc_deserBoolFalse(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolFalse) */

    cx_object o = NULL; cx_fromStr(&o, "bool{false}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == FALSE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolTrue() */
cx_void _test_StringDeserializer_tc_deserBoolTrue(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolTrue) */

    cx_object o = NULL; cx_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserChar() */
cx_void _test_StringDeserializer_tc_deserChar(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserChar) */

    cx_object o = NULL; cx_fromStr(&o, "char{'a'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == 'a');
    cx_delete(o);

    cx_object p = NULL; cx_fromStr(&p, "char{'a'}");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == 'a');
    cx_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharEscape() */
cx_void _test_StringDeserializer_tc_deserCharEscape(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharEscape) */

    cx_object o = NULL; cx_fromStr(&o, "char{'\\\\'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == '\\');
    cx_delete(o);

    cx_object p = NULL; cx_fromStr(&p, "char{\\}");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == '\\');
    cx_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharExisting() */
cx_void _test_StringDeserializer_tc_deserCharExisting(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharExisting) */

    cx_object o = cx_charCreate('a'); cx_fromStr(&o, "b");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == 'b');
    cx_delete(o);

    cx_object p = cx_charCreate('a'); cx_fromStr(&p, "'b'");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == 'b');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharExisting_w_type() */
cx_void _test_StringDeserializer_tc_deserCharExisting_w_type(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharExisting_w_type) */

    cx_object o = cx_charCreate('a'); cx_fromStr(&o, "char{b}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == 'b');
    cx_delete(o);

    cx_object p = cx_charCreate('a'); cx_fromStr(&p, "char{'b'}");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == 'b');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharNull() */
cx_void _test_StringDeserializer_tc_deserCharNull(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharNull) */

    cx_object o = NULL; cx_fromStr(&o, "char{'\0'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == '\0');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8() */
cx_void _test_StringDeserializer_tc_deserInt8(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8) */

    cx_object o = NULL; cx_fromStr(&o, "int8{127}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int8_o);
    test_assert(*(cx_int8*)o == 127);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Existing() */
cx_void _test_StringDeserializer_tc_deserInt8Existing(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Existing) */

    cx_object o = cx_int8Create(0); cx_fromStr(&o, "50");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int8_o);
    test_assert(*(cx_int8*)o == 50);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Existing_w_type() */
cx_void _test_StringDeserializer_tc_deserInt8Existing_w_type(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Existing_w_type) */

    cx_object o = cx_int8Create(0); cx_fromStr(&o, "int8{50}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int8_o);
    test_assert(*(cx_int8*)o == 50);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Minus() */
cx_void _test_StringDeserializer_tc_deserInt8Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Minus) */

    cx_object o = NULL; cx_fromStr(&o, "int8{-128}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int8_o);
    test_assert(*(cx_int8*)o == -128);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Overflow() */
cx_void _test_StringDeserializer_tc_deserInt8Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "int8{128}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int8_o);
    test_assert(*(cx_int8*)o == -128);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::teardown() */
cx_void _test_StringDeserializer_teardown(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::teardown) */

    /* << Insert implementation >> */

/* $end */
}
