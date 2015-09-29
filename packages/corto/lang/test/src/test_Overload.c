/* test_Overload.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::Overload::tc_ambiguous() */
cx_void _test_Overload_tc_ambiguous(test_Overload this) {
/* $begin(::test::Overload::tc_ambiguous) */

    cx_object o = cx_resolve(test_o, "ol_null");
    test_assert(o == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference to 'ol_null'"));

/* $end */
}

/* ::test::Overload::tc_ambiguousNull() */
cx_void _test_Overload_tc_ambiguousNull(test_Overload this) {
/* $begin(::test::Overload::tc_ambiguousNull) */

    cx_object o = cx_resolve(test_o, "ol_null(null)");
    test_assert(o == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'ol_null(null)'"));

/* $end */
}

/* ::test::Overload::tc_ambiguousWildcard() */
cx_void _test_Overload_tc_ambiguousWildcard(test_Overload this) {
/* $begin(::test::Overload::tc_ambiguousWildcard) */

    cx_object o = cx_resolve(test_o, "ol_null(?)");
    test_assert(o == NULL);
    test_assert(cx_lasterr() != NULL);
    test_assert(!strcmp(cx_lasterr(), "ambiguous reference 'ol_null(?)'"));

/* $end */
}

/* ::test::Overload::tc_anyChar() */
cx_void _test_Overload_tc_anyChar(test_Overload this) {
/* $begin(::test::Overload::tc_anyChar) */

    cx_object o = cx_resolve(test_o, "ol_any(char)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_char_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(char a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyColor() */
cx_void _test_Overload_tc_anyColor(test_Overload this) {
/* $begin(::test::Overload::tc_anyColor) */

    cx_object o = cx_resolve(test_o, "ol_any(Color)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any__test_Color_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(::test::Color a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyFloat32() */
cx_void _test_Overload_tc_anyFloat32(test_Overload this) {
/* $begin(::test::Overload::tc_anyFloat32) */

    cx_object o = cx_resolve(test_o, "ol_any(float32)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_float32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(float32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyFloat64() */
cx_void _test_Overload_tc_anyFloat64(test_Overload this) {
/* $begin(::test::Overload::tc_anyFloat64) */

    cx_object o = cx_resolve(test_o, "ol_any(float64)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_float32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(float32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyInt16() */
cx_void _test_Overload_tc_anyInt16(test_Overload this) {
/* $begin(::test::Overload::tc_anyInt16) */

    cx_object o = cx_resolve(test_o, "ol_any(int16)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyInt32() */
cx_void _test_Overload_tc_anyInt32(test_Overload this) {
/* $begin(::test::Overload::tc_anyInt32) */

    cx_object o = cx_resolve(test_o, "ol_any(int32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyInt64() */
cx_void _test_Overload_tc_anyInt64(test_Overload this) {
/* $begin(::test::Overload::tc_anyInt64) */

    cx_object o = cx_resolve(test_o, "ol_any(int64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyInt8() */
cx_void _test_Overload_tc_anyInt8(test_Overload this) {
/* $begin(::test::Overload::tc_anyInt8) */

    cx_object o = cx_resolve(test_o, "ol_any(int8)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyOctet() */
cx_void _test_Overload_tc_anyOctet(test_Overload this) {
/* $begin(::test::Overload::tc_anyOctet) */

    cx_object o = cx_resolve(test_o, "ol_any(octet)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyString() */
cx_void _test_Overload_tc_anyString(test_Overload this) {
/* $begin(::test::Overload::tc_anyString) */

    cx_object o = cx_resolve(test_o, "ol_any(string)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_string_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(string a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyUint16() */
cx_void _test_Overload_tc_anyUint16(test_Overload this) {
/* $begin(::test::Overload::tc_anyUint16) */

    cx_object o = cx_resolve(test_o, "ol_any(uint16)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyUint32() */
cx_void _test_Overload_tc_anyUint32(test_Overload this) {
/* $begin(::test::Overload::tc_anyUint32) */

    cx_object o = cx_resolve(test_o, "ol_any(uint32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyUint64() */
cx_void _test_Overload_tc_anyUint64(test_Overload this) {
/* $begin(::test::Overload::tc_anyUint64) */

    cx_object o = cx_resolve(test_o, "ol_any(uint64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyUint8() */
cx_void _test_Overload_tc_anyUint8(test_Overload this) {
/* $begin(::test::Overload::tc_anyUint8) */

    cx_object o = cx_resolve(test_o, "ol_any(uint8)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_anyWord() */
cx_void _test_Overload_tc_anyWord(test_Overload this) {
/* $begin(::test::Overload::tc_anyWord) */

    cx_object o = cx_resolve(test_o, "ol_any(word)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_any(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_inheritanceBase() */
cx_void _test_Overload_tc_inheritanceBase(test_Overload this) {
/* $begin(::test::Overload::tc_inheritanceBase) */

    cx_object o = cx_resolve(test_o, "ol_inherit(Animal)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Animal_o);
    test_assert(!strcmp(cx_nameof(o), "ol_inherit(::test::Animal a)"));

/* $end */
}

/* ::test::Overload::tc_inheritanceMatchSub() */
cx_void _test_Overload_tc_inheritanceMatchSub(test_Overload this) {
/* $begin(::test::Overload::tc_inheritanceMatchSub) */

    cx_object o = cx_resolve(test_o, "ol_inherit(GoldenRetriever)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Dog_o);
    test_assert(!strcmp(cx_nameof(o), "ol_inherit(::test::Dog a)"));

/* $end */
}

/* ::test::Overload::tc_inheritanceSub() */
cx_void _test_Overload_tc_inheritanceSub(test_Overload this) {
/* $begin(::test::Overload::tc_inheritanceSub) */

    cx_object o = cx_resolve(test_o, "ol_inherit(Dog)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Dog_o);
    test_assert(!strcmp(cx_nameof(o), "ol_inherit(::test::Dog a)"));

/* $end */
}

/* ::test::Overload::tc_inheritSibling() */
cx_void _test_Overload_tc_inheritSibling(test_Overload this) {
/* $begin(::test::Overload::tc_inheritSibling) */

    cx_object o = cx_resolve(test_o, "ol_inherit(Cat)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Animal_o);
    test_assert(!strcmp(cx_nameof(o), "ol_inherit(::test::Animal a)"));

/* $end */
}

/* ::test::Overload::tc_nullBool() */
cx_void _test_Overload_tc_nullBool(test_Overload this) {
/* $begin(::test::Overload::tc_nullBool) */

    cx_object o = cx_resolve(test_o, "ol_bool(null)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(!cx_function(o)->overloaded);
    test_assert(o == test_ol_bool_o);
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_nullObject() */
cx_void _test_Overload_tc_nullObject(test_Overload this) {
/* $begin(::test::Overload::tc_nullObject) */

    cx_object o = cx_resolve(test_o, "ol_object(null)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(!cx_function(o)->overloaded);
    test_assert(o == test_ol_object_o);
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_nullString() */
cx_void _test_Overload_tc_nullString(test_Overload this) {
/* $begin(::test::Overload::tc_nullString) */

    cx_object o = cx_resolve(test_o, "ol_string(null)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(!cx_function(o)->overloaded);
    test_assert(o == test_ol_string_o);
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numChar() */
cx_void _test_Overload_tc_numChar(test_Overload this) {
/* $begin(::test::Overload::tc_numChar) */

    cx_object o = cx_resolve(test_o, "ol_num(char)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numColor() */
cx_void _test_Overload_tc_numColor(test_Overload this) {
/* $begin(::test::Overload::tc_numColor) */

    cx_object o = cx_resolve(test_o, "ol_num(Color)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numFloat32() */
cx_void _test_Overload_tc_numFloat32(test_Overload this) {
/* $begin(::test::Overload::tc_numFloat32) */

    cx_object o = cx_resolve(test_o, "ol_num(float32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_float64_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(float64 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numFloat64() */
cx_void _test_Overload_tc_numFloat64(test_Overload this) {
/* $begin(::test::Overload::tc_numFloat64) */

    cx_object o = cx_resolve(test_o, "ol_num(float64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_float64_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(float64 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numInt16() */
cx_void _test_Overload_tc_numInt16(test_Overload this) {
/* $begin(::test::Overload::tc_numInt16) */

    cx_object o = cx_resolve(test_o, "ol_num(int16)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numInt32() */
cx_void _test_Overload_tc_numInt32(test_Overload this) {
/* $begin(::test::Overload::tc_numInt32) */

    cx_object o = cx_resolve(test_o, "ol_num(int32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numInt64() */
cx_void _test_Overload_tc_numInt64(test_Overload this) {
/* $begin(::test::Overload::tc_numInt64) */

    cx_object o = cx_resolve(test_o, "ol_num(int64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numInt8() */
cx_void _test_Overload_tc_numInt8(test_Overload this) {
/* $begin(::test::Overload::tc_numInt8) */

    cx_object o = cx_resolve(test_o, "ol_num(int8)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));
    cx_release(o);

/* $end */
}

/* ::test::Overload::tc_numOctet() */
cx_void _test_Overload_tc_numOctet(test_Overload this) {
/* $begin(::test::Overload::tc_numOctet) */

    cx_object o = cx_resolve(test_o, "ol_num(octet)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numString() */
cx_void _test_Overload_tc_numString(test_Overload this) {
/* $begin(::test::Overload::tc_numString) */

    cx_object o = cx_resolve(test_o, "ol_num(string)");
    test_assert(o == NULL);
    test_assert(cx_lasterr() == NULL);

/* $end */
}

/* ::test::Overload::tc_numUint16() */
cx_void _test_Overload_tc_numUint16(test_Overload this) {
/* $begin(::test::Overload::tc_numUint16) */

    cx_object o = cx_resolve(test_o, "ol_num(uint16)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numUint32() */
cx_void _test_Overload_tc_numUint32(test_Overload this) {
/* $begin(::test::Overload::tc_numUint32) */

    cx_object o = cx_resolve(test_o, "ol_num(uint32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numUint64() */
cx_void _test_Overload_tc_numUint64(test_Overload this) {
/* $begin(::test::Overload::tc_numUint64) */

    cx_object o = cx_resolve(test_o, "ol_num(uint64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numUint8() */
cx_void _test_Overload_tc_numUint8(test_Overload this) {
/* $begin(::test::Overload::tc_numUint8) */

    cx_object o = cx_resolve(test_o, "ol_num(uint8)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numWord() */
cx_void _test_Overload_tc_numWord(test_Overload this) {
/* $begin(::test::Overload::tc_numWord) */

    cx_object o = cx_resolve(test_o, "ol_num(word)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_wildcard() */
cx_void _test_Overload_tc_wildcard(test_Overload this) {
/* $begin(::test::Overload::tc_wildcard) */

    cx_object o = cx_resolve(test_o, "ol_wildcard(int32,?)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(!strcmp(cx_nameof(o), "ol_wildcard(int32 a,string b)"));

/* $end */
}
