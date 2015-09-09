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

/* ::test::StringDeserializer::tc_deserBoolFalse() */
cx_void _test_StringDeserializer_tc_deserBoolFalse(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolFalse) */

    cx_object o = NULL;
    cx_int16 ret = cx_fromStr(&o, "bool{false}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == FALSE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolInvalid() */
cx_void _test_StringDeserializer_tc_deserBoolInvalid(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolInvalid) */

    cx_string err;
    cx_object o = cx_boolCreate(TRUE); 
    cx_int16 ret = cx_fromStr(&o, "bool{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = cx_lasterr()) != NULL);
    test_assert(!strcmp(err, "'bar' is not a valid boolean value"));
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

    cx_object p = NULL; cx_fromStr(&p, "char{a}");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == 'a');
    cx_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharEscape() */
cx_void _test_StringDeserializer_tc_deserCharEscape(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharEscape) */

    cx_object p = NULL; cx_fromStr(&p, "char{\\}");
    test_assert(p != NULL);
    test_assert(cx_typeof(p) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)p == '\\');
    cx_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharEscapeQuoted() */
cx_void _test_StringDeserializer_tc_deserCharEscapeQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharEscapeQuoted) */

    cx_object o = NULL; cx_fromStr(&o, "char{'\\\\'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == '\\');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharNull() */
cx_void _test_StringDeserializer_tc_deserCharNull(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharNull) */

    cx_object o = NULL; cx_fromStr(&o, "char{\0}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == '\0');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharNullQuoted() */
cx_void _test_StringDeserializer_tc_deserCharNullQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharNullQuoted) */

    cx_object o = NULL; cx_fromStr(&o, "char{'\0'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == '\0');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharQuoted() */
cx_void _test_StringDeserializer_tc_deserCharQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharQuoted) */

    cx_object o = NULL; cx_fromStr(&o, "char{'a'}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_char_o);
    test_assert(*(cx_char*)o == 'a');
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserExisting() */
cx_void _test_StringDeserializer_tc_deserExisting(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserExisting) */

    cx_object o = cx_boolCreate(FALSE); 
    cx_int16 ret = cx_fromStr(&o, "true");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserExisting_w_type() */
cx_void _test_StringDeserializer_tc_deserExisting_w_type(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserExisting_w_type) */

    cx_object o = cx_boolCreate(FALSE); 
    cx_int16 ret = cx_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(cx_typeof(o) == (cx_type)cx_bool_o);
    test_assert(*(cx_bool*)o == TRUE);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16() */
cx_void _test_StringDeserializer_tc_deserInt16(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16) */

    cx_object o = NULL; cx_fromStr(&o, "int16{32767}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int16_o);
    test_assert(*(cx_int16*)o == 32767);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16Minus() */
cx_void _test_StringDeserializer_tc_deserInt16Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16Minus) */

    cx_object o = NULL; cx_fromStr(&o, "int16{-32768}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int16_o);
    test_assert(*(cx_int16*)o == -32768);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16Overflow() */
cx_void _test_StringDeserializer_tc_deserInt16Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "int16{32768}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int16_o);
    test_assert(*(cx_int16*)o == -32768);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32() */
cx_void _test_StringDeserializer_tc_deserInt32(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32) */

    cx_object o = NULL; cx_fromStr(&o, "int32{2147483647}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(*(cx_int32*)o == 2147483647);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32Minus() */
cx_void _test_StringDeserializer_tc_deserInt32Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32Minus) */

    cx_object o = NULL; cx_fromStr(&o, "int32{-2147483648}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(*(cx_int32*)o == -2147483648);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32Overflow() */
cx_void _test_StringDeserializer_tc_deserInt32Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "int32{2147483648}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(*(cx_int32*)o == -2147483648);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt64() */
cx_void _test_StringDeserializer_tc_deserInt64(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt64) */
    
    cx_object o = NULL; cx_fromStr(&o, "int64{9223372036854775807}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int64_o);
    test_assert(*(cx_int64*)o == 9223372036854775807);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt64Minus() */
cx_void _test_StringDeserializer_tc_deserInt64Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt64Minus) */

    cx_object o = NULL; cx_fromStr(&o, "int64{-9223372036854775808");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int64_o);
    test_assert(*(cx_int64*)o == (-9223372036854775807 - 1)); /* C doesn't allow -9223372036854775808 */
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

/* ::test::StringDeserializer::tc_deserUint16() */
cx_void _test_StringDeserializer_tc_deserUint16(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint16) */

    cx_object o = NULL; cx_fromStr(&o, "uint16{65535}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint16_o);
    test_assert(*(cx_uint16*)o == 65535);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint16Overflow() */
cx_void _test_StringDeserializer_tc_deserUint16Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint16Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "uint16{65536}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint16_o);
    test_assert(*(cx_uint16*)o == 0);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint32() */
cx_void _test_StringDeserializer_tc_deserUint32(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint32) */

    cx_object o = NULL; cx_fromStr(&o, "uint32{4294967295}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint32_o);
    test_assert(*(cx_uint32*)o == 4294967295);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint32Overflow() */
cx_void _test_StringDeserializer_tc_deserUint32Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint32Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "uint32{4294967296}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint32_o);
    test_assert(*(cx_uint32*)o == 0);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint64() */
cx_void _test_StringDeserializer_tc_deserUint64(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint64) */

    cx_object o = NULL; cx_fromStr(&o, "uint64{18446744073709551615}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint64_o);
    test_assert(*(cx_uint64*)o == 18446744073709551615u);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint8() */
cx_void _test_StringDeserializer_tc_deserUint8(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint8) */

    cx_object o = NULL; cx_fromStr(&o, "uint8{255}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint8_o);
    test_assert(*(cx_uint8*)o == 255);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint8Overflow() */
cx_void _test_StringDeserializer_tc_deserUint8Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint8Overflow) */

    cx_object o = NULL; cx_fromStr(&o, "uint8{256}");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_uint8_o);
    test_assert(*(cx_uint8*)o == 0);
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_errExcessElements() */
cx_void _test_StringDeserializer_tc_errExcessElements(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errExcessElements) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::StringDeserializer::tc_errMissingType() */
cx_void _test_StringDeserializer_tc_errMissingType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errMissingType) */

    cx_string err;
    cx_object o = NULL; cx_fromStr(&o, "{foo}");
    test_assert(o == NULL);
    test_assert((err = cx_lasterr()) != NULL);
    test_assert(!strcmp(err, "no type provided for '{foo}'"));

/* $end */
}

/* ::test::StringDeserializer::tc_errNotAType() */
cx_void _test_StringDeserializer_tc_errNotAType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errNotAType) */

    cx_string err;
    cx_object o = NULL; cx_fromStr(&o, "lang{foo}");
    test_assert(o == NULL);
    test_assert((err = cx_lasterr()) != NULL);
    test_assert(!strcmp(err, "'lang' is not a type"));

/* $end */
}

/* ::test::StringDeserializer::tc_errTypeMismatch() */
cx_void _test_StringDeserializer_tc_errTypeMismatch(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errTypeMismatch) */

    cx_string err;
    cx_object o = cx_boolCreate(TRUE); 
    cx_int16 ret = cx_fromStr(&o, "string{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = cx_lasterr()) != NULL);
    test_assert(!strcmp(err, "type of object ('::corto::lang::bool') does not match string ('::corto::lang::string')"));
    cx_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_errUnresolvedMember() */
cx_void _test_StringDeserializer_tc_errUnresolvedMember(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errUnresolvedMember) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::StringDeserializer::tc_errUnresolvedType() */
cx_void _test_StringDeserializer_tc_errUnresolvedType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errUnresolvedType) */

    cx_string err;
    cx_object o = NULL;
    cx_int16 ret = cx_fromStr(&o, "foo{bar}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = cx_lasterr()) != NULL);
    test_assert(!strcmp(err, "unknown type 'foo'"));

/* $end */
}

/* ::test::StringDeserializer::teardown() */
cx_void _test_StringDeserializer_teardown(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::teardown) */

    /* << Insert implementation >> */

/* $end */
}
