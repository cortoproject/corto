/* $CORTO_GENERATED
 *
 * Overload.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Overload_tc_ambiguous(
    test_Overload this)
{
/* $begin(test/Overload/tc_ambiguous) */

    corto_object o = corto_resolve(test_o, "ol_null");
    test_assert(o == NULL);
    test_assert(corto_lastinfo() != NULL);
    test_assert(!strcmp(corto_lastinfo(), "ambiguous reference 'ol_null'"));

/* $end */
}

void _test_Overload_tc_ambiguousNull(
    test_Overload this)
{
/* $begin(test/Overload/tc_ambiguousNull) */

    corto_object o = corto_resolve(test_o, "ol_null(null)");
    test_assert(o == NULL);
    test_assert(corto_lastinfo() != NULL);
    test_assert(!strcmp(corto_lastinfo(), "ambiguous reference 'ol_null(null)'"));

/* $end */
}

void _test_Overload_tc_ambiguousWildcard(
    test_Overload this)
{
/* $begin(test/Overload/tc_ambiguousWildcard) */

    corto_object o = corto_resolve(test_o, "ol_null(?)");
    test_assert(o == NULL);
    test_assert(corto_lastinfo() != NULL);
    test_assert(!strcmp(corto_lastinfo(), "ambiguous reference 'ol_null(?)'"));

/* $end */
}

void _test_Overload_tc_anyChar(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyChar) */

    corto_object o = corto_resolve(test_o, "ol_any(char)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_char_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(char a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyColor(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyColor) */

    corto_object o = corto_resolve(test_o, "ol_any(test/Color)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any__test_Color_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(/test/Color a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyFloat32(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyFloat32) */

    corto_object o = corto_resolve(test_o, "ol_any(float32)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_float32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(float32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyFloat64(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyFloat64) */

    corto_object o = corto_resolve(test_o, "ol_any(float64)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_float32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(float32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyInt16(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyInt16) */

    corto_object o = corto_resolve(test_o, "ol_any(int16)");
    test_assert(o != NULL);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyInt32(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyInt32) */

    corto_object o = corto_resolve(test_o, "ol_any(int32)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyInt64(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyInt64) */

    corto_object o = corto_resolve(test_o, "ol_any(int64)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyInt8(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyInt8) */

    corto_object o = corto_resolve(test_o, "ol_any(int8)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyOctet(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyOctet) */

    corto_object o = corto_resolve(test_o, "ol_any(octet)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyString(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyString) */

    corto_object o = corto_resolve(test_o, "ol_any(string)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_string_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(string a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyUint16(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyUint16) */

    corto_object o = corto_resolve(test_o, "ol_any(uint16)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyUint32(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyUint32) */

    corto_object o = corto_resolve(test_o, "ol_any(uint32)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyUint64(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyUint64) */

    corto_object o = corto_resolve(test_o, "ol_any(uint64)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyUint8(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyUint8) */

    corto_object o = corto_resolve(test_o, "ol_any(uint8)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_anyWord(
    test_Overload this)
{
/* $begin(test/Overload/tc_anyWord) */

    corto_object o = corto_resolve(test_o, "ol_any(word)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_any_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_any(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_inheritanceBase(
    test_Overload this)
{
/* $begin(test/Overload/tc_inheritanceBase) */

    corto_object o = corto_resolve(test_o, "ol_inherit(test/Animal)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Animal_o);
    test_assert(!strcmp(corto_idof(o), "ol_inherit(/test/Animal a)"));

/* $end */
}

void _test_Overload_tc_inheritanceMatchSub(
    test_Overload this)
{
/* $begin(test/Overload/tc_inheritanceMatchSub) */

    corto_object o = corto_resolve(test_o, "ol_inherit(test/GoldenRetriever)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Dog_o);
    test_assert(!strcmp(corto_idof(o), "ol_inherit(/test/Dog a)"));

/* $end */
}

void _test_Overload_tc_inheritanceSub(
    test_Overload this)
{
/* $begin(test/Overload/tc_inheritanceSub) */

    corto_object o = corto_resolve(test_o, "ol_inherit(test/Dog)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Dog_o);
    test_assert(!strcmp(corto_idof(o), "ol_inherit(/test/Dog a)"));

/* $end */
}

void _test_Overload_tc_inheritSibling(
    test_Overload this)
{
/* $begin(test/Overload/tc_inheritSibling) */

    corto_object o = corto_resolve(test_o, "ol_inherit(test/Cat)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_inherit__test_Animal_o);
    test_assert(!strcmp(corto_idof(o), "ol_inherit(/test/Animal a)"));

/* $end */
}

void _test_Overload_tc_nullBool(
    test_Overload this)
{
/* $begin(test/Overload/tc_nullBool) */

    corto_object o = corto_resolve(test_o, "ol_bool(null)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(!corto_function(o)->overloaded);
    test_assert(o == test_ol_bool_o);
    corto_release(o);

/* $end */
}

void _test_Overload_tc_nullObject(
    test_Overload this)
{
/* $begin(test/Overload/tc_nullObject) */

    corto_object o = corto_resolve(test_o, "ol_object(null)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(!corto_function(o)->overloaded);
    test_assert(o == test_ol_object_o);
    corto_release(o);

/* $end */
}

void _test_Overload_tc_nullString(
    test_Overload this)
{
/* $begin(test/Overload/tc_nullString) */

    corto_object o = corto_resolve(test_o, "ol_string(null)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(!corto_function(o)->overloaded);
    test_assert(o == test_ol_string_o);
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numChar(
    test_Overload this)
{
/* $begin(test/Overload/tc_numChar) */

    corto_object o = corto_resolve(test_o, "ol_num(char)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numColor(
    test_Overload this)
{
/* $begin(test/Overload/tc_numColor) */

    corto_object o = corto_resolve(test_o, "ol_num(test/Color)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numFloat32(
    test_Overload this)
{
/* $begin(test/Overload/tc_numFloat32) */

    corto_object o = corto_resolve(test_o, "ol_num(float32)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_float64_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(float64 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numFloat64(
    test_Overload this)
{
/* $begin(test/Overload/tc_numFloat64) */

    corto_object o = corto_resolve(test_o, "ol_num(float64)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_float64_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(float64 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numInt16(
    test_Overload this)
{
/* $begin(test/Overload/tc_numInt16) */

    corto_object o = corto_resolve(test_o, "ol_num(int16)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numInt32(
    test_Overload this)
{
/* $begin(test/Overload/tc_numInt32) */

    corto_object o = corto_resolve(test_o, "ol_num(int32)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numInt64(
    test_Overload this)
{
/* $begin(test/Overload/tc_numInt64) */

    corto_object o = corto_resolve(test_o, "ol_num(int64)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numInt8(
    test_Overload this)
{
/* $begin(test/Overload/tc_numInt8) */

    corto_object o = corto_resolve(test_o, "ol_num(int8)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));
    corto_release(o);

/* $end */
}

void _test_Overload_tc_numOctet(
    test_Overload this)
{
/* $begin(test/Overload/tc_numOctet) */

    corto_object o = corto_resolve(test_o, "ol_num(octet)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_numString(
    test_Overload this)
{
/* $begin(test/Overload/tc_numString) */

    corto_object o = corto_resolve(test_o, "ol_num(string)");
    test_assert(o == NULL);
    test_assert(corto_lasterr() == NULL);

/* $end */
}

void _test_Overload_tc_numUint16(
    test_Overload this)
{
/* $begin(test/Overload/tc_numUint16) */

    corto_object o = corto_resolve(test_o, "ol_num(uint16)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_numUint32(
    test_Overload this)
{
/* $begin(test/Overload/tc_numUint32) */

    corto_object o = corto_resolve(test_o, "ol_num(uint32)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_numUint64(
    test_Overload this)
{
/* $begin(test/Overload/tc_numUint64) */

    corto_object o = corto_resolve(test_o, "ol_num(uint64)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_numUint8(
    test_Overload this)
{
/* $begin(test/Overload/tc_numUint8) */

    corto_object o = corto_resolve(test_o, "ol_num(uint8)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_numWord(
    test_Overload this)
{
/* $begin(test/Overload/tc_numWord) */

    corto_object o = corto_resolve(test_o, "ol_num(word)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(corto_function(o)->overloaded);
    test_assert(o == test_ol_num_int32_o);
    test_assert(!strcmp(corto_idof(o), "ol_num(int32 a)"));

/* $end */
}

void _test_Overload_tc_wildcard(
    test_Overload this)
{
/* $begin(test/Overload/tc_wildcard) */

    corto_object o = corto_resolve(test_o, "ol_wildcard(int32,?)");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_function_o));
    test_assert(!strcmp(corto_idof(o), "ol_wildcard(int32 a,string b)"));

/* $end */
}
