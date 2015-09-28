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

/* ::test::Overload::tc_null() */
cx_void _test_Overload_tc_null(test_Overload this) {
/* $begin(::test::Overload::tc_null) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::Overload::tc_numFloat32() */
cx_void _test_Overload_tc_numFloat32(test_Overload this) {
/* $begin(::test::Overload::tc_numFloat32) */

    cx_object o = cx_resolve(test_o, "ol_num(float32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(!strcmp(cx_nameof(o), "ol_num(float64 a)"));

/* $end */
}

/* ::test::Overload::tc_numFloat64() */
cx_void _test_Overload_tc_numFloat64(test_Overload this) {
/* $begin(::test::Overload::tc_numFloat64) */

    cx_object o = cx_resolve(test_o, "ol_num(float64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(!strcmp(cx_nameof(o), "ol_num(float64 a)"));

/* $end */
}

/* ::test::Overload::tc_numInt16() */
cx_void _test_Overload_tc_numInt16(test_Overload this) {
/* $begin(::test::Overload::tc_numInt16) */

    cx_object o = cx_resolve(test_o, "ol_num(int16)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numInt32() */
cx_void _test_Overload_tc_numInt32(test_Overload this) {
/* $begin(::test::Overload::tc_numInt32) */

    cx_object o = cx_resolve(test_o, "ol_num(int32)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numInt64() */
cx_void _test_Overload_tc_numInt64(test_Overload this) {
/* $begin(::test::Overload::tc_numInt64) */

    cx_object o = cx_resolve(test_o, "ol_num(int64)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
    test_assert(!strcmp(cx_nameof(o), "ol_num(int32 a)"));

/* $end */
}

/* ::test::Overload::tc_numInt8() */
cx_void _test_Overload_tc_numInt8(test_Overload this) {
/* $begin(::test::Overload::tc_numInt8) */

    cx_object o = cx_resolve(test_o, "ol_num(int8)");
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_type(cx_function_o));
    test_assert(cx_function(o)->overloaded);
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
