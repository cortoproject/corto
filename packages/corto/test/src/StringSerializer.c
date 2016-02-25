/* $CORTO_GENERATED
 *
 * StringSerializer.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_StringSerializer_tc_serArray(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serArray) */
    corto_array t = corto_arrayCreate(corto_int32_o, 3);
    test_assert(t != NULL);
    corto_string result;

    corto_int32 v[] = {10, 20, 30};

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_delete(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serArrayComplex(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serArrayComplex) */
    corto_array t = corto_arrayCreate(test_Point_o, 3);
    test_assert(t != NULL);
    corto_string result;

    test_Point v[] = {{10, 20}, {30, 40}, {50, 60}};

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_delete(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serBoolFalse(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serBoolFalse) */
    corto_bool v = FALSE;
    corto_string result = NULL;

    result = corto_strp(&v, corto_bool_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "false"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serBoolTrue(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serBoolTrue) */
    corto_bool v = TRUE;
    corto_string result = NULL;

    result = corto_strp(&v, corto_bool_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "true"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serChar(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serChar) */
    corto_char v = 'a';
    corto_string result = NULL;

    result = corto_strp(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "'a'"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serCharEscape(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serCharEscape) */
    corto_char v = '\n';
    corto_string result = NULL;

    result = corto_strp(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "'\n'"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serCharNull(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serCharNull) */
    corto_char v = '\0';
    corto_string result = NULL;

    result = corto_strp(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "''"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serComposite(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serComposite) */
    test_Point v = {10, 20};
    corto_string result;

    result = corto_strp(&v, test_Point_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20}"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serCompositeNested(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serCompositeNested) */
    test_Line v = {{10, 20}, {30, 40}};
    corto_string result;

    result = corto_strp(&v, test_Line_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40}}"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInheritance(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInheritance) */
    test_Point3D v = {{10, 20}, 30};
    corto_string result;

    result = corto_strp(&v, test_Point3D_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt16(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt16) */
    corto_int16 v = 32767;
    corto_string result;

    result = corto_strp(&v, corto_int16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "32767"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt16Minus(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt16Minus) */
    corto_int16 v = -32768;
    corto_string result;

    result = corto_strp(&v, corto_int16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-32768"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt32(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt32) */
    corto_int32 v = 2147483647;
    corto_string result;

    result = corto_strp(&v, corto_int32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "2147483647"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt32Minus(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt32Minus) */
    corto_int32 v = -2147483648;
    corto_string result;

    result = corto_strp(&v, corto_int32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-2147483648"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt64(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt64) */
    corto_int64 v = 9223372036854775807;
    corto_string result;

    result = corto_strp(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "9223372036854775807"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt64Minus(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt64Minus) */
    corto_int64 v = -9223372036854775807 - 1;
    corto_string result;

    result = corto_strp(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-9223372036854775808"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt8(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt8) */
    corto_int64 v = 127;
    corto_string result;

    result = corto_strp(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "127"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serInt8Minus(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serInt8Minus) */
    corto_int64 v = -128;
    corto_string result;

    result = corto_strp(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-128"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serList(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serList) */
    corto_list t = corto_listCreate(corto_int32_o, 0);
    corto_ll v = corto_llNew();
    corto_string result;

    corto_llAppend(v, (void*)10);
    corto_llAppend(v, (void*)20);
    corto_llAppend(v, (void*)30);

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_llFree(v);
    corto_release(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serListComplex(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serListComplex) */
    corto_list t = corto_listCreate(test_Point_o, 0);
    corto_ll v = corto_llNew();
    test_Point e1 = {10, 20}, e2 = {30, 40}, e3 = {50, 60};
    corto_string result;

    corto_llAppend(v, &e1);
    corto_llAppend(v, &e2);
    corto_llAppend(v, &e3);

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_llFree(v);
    corto_release(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serSequence(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serSequence) */
    corto_sequence t = corto_sequenceCreate(corto_int32_o, 0);
    CORTO_SEQUENCE(seqType, corto_int32,);
    corto_int32 elements[] = {10, 20, 30};
    seqType v = {3, elements};
    corto_string result;

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_release(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serSequenceComplex(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serSequenceComplex) */
    corto_sequence t = corto_sequenceCreate(test_Point_o, 0);
    CORTO_SEQUENCE(seqType, test_Point,);
    test_Point elements[] = {{10, 20}, {30, 40}, {50, 60}};
    seqType v = {3, elements};
    corto_string result;

    result = corto_strp(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_release(t);

/* $end */
}

corto_void _test_StringSerializer_tc_serString(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serString) */
    corto_string v = "Hello World";
    corto_string result;

    result = corto_strp(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "\"Hello World\""));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serStringEscape(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serStringEscape) */
    corto_string v = "Hello World\n";
    corto_string result;

    result = corto_strp(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "\"Hello World\n\""));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serStringNull(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serStringNull) */
    corto_string v = NULL;
    corto_string result;

    result = corto_strp(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "null"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serStringWhitespace(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serStringWhitespace) */
    corto_string v = "  Hello World   ";
    corto_string result;

    result = corto_strp(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "\"  Hello World   \""));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serUint16(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serUint16) */
    corto_uint16 v = 65535;
    corto_string result;

    result = corto_strp(&v, corto_uint16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "65535"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serUint32(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serUint32) */
    corto_uint32 v = 4294967295;
    corto_string result;

    result = corto_strp(&v, corto_uint32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "4294967295"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serUint64(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serUint64) */
    corto_uint64 v = 18446744073709551615u;
    corto_string result;

    result = corto_strp(&v, corto_uint64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "18446744073709551615"));

    corto_dealloc(result);

/* $end */
}

corto_void _test_StringSerializer_tc_serUint8(
    test_StringSerializer this)
{
/* $begin(test/StringSerializer/tc_serUint8) */
    corto_uint64 v = 255;
    corto_string result;

    result = corto_strp(&v, corto_uint64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "255"));

    corto_dealloc(result);

/* $end */
}
