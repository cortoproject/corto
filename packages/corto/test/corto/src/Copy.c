/* $CORTO_GENERATED
 *
 * Copy.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Copy_tc_any(
    test_Copy this)
{
/* $begin(test/Copy/tc_any) */
    corto_int32 v = 10;
    corto_any src = {corto_type(corto_int32_o), &v, FALSE};
    corto_any dst = {NULL, NULL, FALSE};

    corto_int16 ret = corto_copya(&dst, src);
    test_assert(ret == 0);
    test_assert(dst.type == corto_type(corto_int32_o));
    test_assert(dst.value != NULL);
    test_assert(dst.owner == TRUE);
    test_assert(*(corto_int32*)dst.value == 10);

    corto_deinitp(&dst, corto_any_o);

/* $end */
}

corto_void _test_Copy_tc_arrayToArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToArray) */
    corto_int32 v1[] = {10, 20, 30, 40};
    corto_int32 v2[] = {0, 0, 0, 0};
    corto_int16 ret;

    ret = corto_copyp(v2, test_PrimitiveArray_o, v1);
    test_assert(ret == 0);
    test_assert(v2[0] == 10);
    test_assert(v2[1] == 20);
    test_assert(v2[2] == 30);
    test_assert(v2[3] == 40);

/* $end */
}

corto_void _test_Copy_tc_arrayToArrayAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToArrayAlloc) */
    corto_int64 v1[] = {10, 20, 30, 40};
    corto_int64 v2[] = {0, 0, 0, 0};
    corto_int16 ret;

    ret = corto_copyp(v2, test_AllocArray_o, v1);
    test_assert(ret == 0);
    test_assert(v2[0] == 10);
    test_assert(v2[1] == 20);
    test_assert(v2[2] == 30);
    test_assert(v2[3] == 40);
/* $end */
}

corto_void _test_Copy_tc_arrayToList(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveArrayCreate_auto(v1, 4, v);
    test_PrimitiveListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(test_PrimitiveListGet(*v2, 0) == 10);
    test_assert(test_PrimitiveListGet(*v2, 1) == 20);
    test_assert(test_PrimitiveListGet(*v2, 2) == 30);
    test_assert(test_PrimitiveListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_arrayToListAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToListAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocArrayCreate_auto(v1, 4, v);
    test_AllocListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(test_AllocListGet(*v2, 0) == 10);
    test_assert(test_AllocListGet(*v2, 1) == 20);
    test_assert(test_AllocListGet(*v2, 2) == 30);
    test_assert(test_AllocListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_int(
    test_Copy this)
{
/* $begin(test/Copy/tc_int) */
    corto_int32 v1 = 10;
    corto_int32 v2 = 0;
    corto_int16 ret;

    ret = corto_copyp(&v2, corto_int32_o, &v1);
    test_assert(ret == 0);
    test_assert(v1 == 10);

/* $end */
}

corto_void _test_Copy_tc_listToArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToArray) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveListCreate_auto(v1, 4, v);
    test_PrimitiveArrayCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret != 0);
    test_assert(!strcmp(
      corto_lasterr(),
      "cannot copy value of type '/test/PrimitiveList' to '/test/PrimitiveArray'"));

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToArrayAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToArrayAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 4, v);
    test_AllocArrayCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret != 0);
    test_assert(!strcmp(
      corto_lasterr(),
      "cannot copy value of type '/test/AllocList' to '/test/AllocArray'"));

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToList(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveListCreate_auto(v1, 4, v);
    test_PrimitiveListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_llSize(*v2) == 4);
    test_assert(test_PrimitiveListGet(*v2, 0) == 10);
    test_assert(test_PrimitiveListGet(*v2, 1) == 20);
    test_assert(test_PrimitiveListGet(*v2, 2) == 30);
    test_assert(test_PrimitiveListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToListAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 4, v);
    test_AllocListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_llSize(*v2) == 4);
    test_assert(test_AllocListGet(*v2, 0) == 10);
    test_assert(test_AllocListGet(*v2, 1) == 20);
    test_assert(test_AllocListGet(*v2, 2) == 30);
    test_assert(test_AllocListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToListResize(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListResize) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveListCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_PrimitiveListCreate_auto(v2, 4, v);

    test_assert(corto_llSize(*v2) == 4);
    test_assert(test_PrimitiveListGet(*v2, 0) == 15);
    test_assert(test_PrimitiveListGet(*v2, 1) == 25);
    test_assert(test_PrimitiveListGet(*v2, 2) == 35);
    test_assert(test_PrimitiveListGet(*v2, 3) == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_llSize(*v2) == 3);
    test_assert(test_PrimitiveListGet(*v2, 0) == 10);
    test_assert(test_PrimitiveListGet(*v2, 1) == 20);
    test_assert(test_PrimitiveListGet(*v2, 2) == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToListResizeAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListResizeAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_AllocListCreate_auto(v2, 4, v);

    test_assert(corto_llSize(*v2) == 4);
    test_assert(test_AllocListGet(*v2, 0) == 15);
    test_assert(test_AllocListGet(*v2, 1) == 25);
    test_assert(test_AllocListGet(*v2, 2) == 35);
    test_assert(test_AllocListGet(*v2, 3) == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_llSize(*v2) == 3);
    test_assert(test_AllocListGet(*v2, 0) == 10);
    test_assert(test_AllocListGet(*v2, 1) == 20);
    test_assert(test_AllocListGet(*v2, 2) == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveListCreate_auto(v1, 4, v);
    test_PrimitiveSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);
    test_assert(v2->buffer[3] == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_listToSequenceAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToSequenceAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 4, v);
    test_AllocSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);
    test_assert(v2->buffer[3] == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveSequenceCreate_auto(v1, 4, v);
    test_PrimitiveSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);
    test_assert(v2->buffer[3] == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequenceAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocSequenceCreate_auto(v1, 4, v);
    test_AllocSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);
    test_assert(v2->buffer[3] == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequenceComposite(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceComposite) */
    corto_int16 ret;
    corto_parameter p1 = {"foo", corto_type(corto_int32_o), TRUE};
    corto_parameter p2 = {"bar", corto_type(corto_float32_o), FALSE};
    corto_parameter v[] = {p1, p2};
    corto_parameterseqCreate_auto(v1, 2, v);
    corto_parameterseqCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 2);
    test_assert(v2->buffer != NULL);
    test_assertstr(v2->buffer[0].name, "foo");
    test_assert(v2->buffer[0].type == corto_type(corto_int32_o));
    test_assert(v2->buffer[0].passByReference == TRUE);
    test_assertstr(v2->buffer[1].name, "bar");
    test_assert(v2->buffer[1].type == corto_type(corto_float32_o));
    test_assert(v2->buffer[1].passByReference == FALSE);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequenceResize(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceResize) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_PrimitiveSequenceCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_PrimitiveSequenceCreate_auto(v2, 4, v);

    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 15);
    test_assert(v2->buffer[1] == 25);
    test_assert(v2->buffer[2] == 35);
    test_assert(v2->buffer[3] == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 3);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequenceResizeAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceResizeAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocSequenceCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_AllocSequenceCreate_auto(v2, 4, v);

    test_assert(v2->length == 4);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 15);
    test_assert(v2->buffer[1] == 25);
    test_assert(v2->buffer[2] == 35);
    test_assert(v2->buffer[3] == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(v2->length == 3);
    test_assert(v2->buffer != NULL);
    test_assert(v2->buffer[0] == 10);
    test_assert(v2->buffer[1] == 20);
    test_assert(v2->buffer[2] == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

corto_void _test_Copy_tc_sequenceToSequenceValueComposite(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceValueComposite) */
    corto_int16 ret;
    corto_parameter p1 = {"foo", corto_type(corto_int32_o), TRUE};
    corto_parameter p2 = {"bar", corto_type(corto_float32_o), FALSE};
    corto_parameterseq v1 = {2, (corto_parameter[]){p1, p2}};
    corto_parameterseq v2 = {0, NULL};

    ret = corto_copyp(&v2, corto_parameterseq_o, &v1);
    test_assert(ret == 0);
    test_assertint(v2.length, 2);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0].name, "foo");
    test_assert(v2.buffer[0].type == corto_type(corto_int32_o));
    test_assert(v2.buffer[0].passByReference == TRUE);
    test_assertstr(v2.buffer[1].name, "bar");
    test_assert(v2.buffer[1].type == corto_type(corto_float32_o));
    test_assert(v2.buffer[1].passByReference == FALSE);

/* $end */
}

corto_void _test_Copy_tc_string(
    test_Copy this)
{
/* $begin(test/Copy/tc_string) */
    corto_string v1 = "foo";
    corto_string v2 = NULL;
    corto_int32 ret;

    ret = corto_copyp(&v2, corto_string_o, &v1);
    test_assert(ret == 0);
    test_assert(!strcmp(v2, "foo"));

/* $end */
}
