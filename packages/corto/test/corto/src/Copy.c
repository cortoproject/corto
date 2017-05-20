/* $CORTO_GENERATED
 *
 * Copy.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Copy_tc_any(
    test_Copy this)
{
/* $begin(test/Copy/tc_any) */
    corto_int32 v = 10;
    corto_any src = {corto_type(corto_int32_o), &v, FALSE};
    corto_any dst = {NULL, NULL, FALSE};

    corto_int16 ret = corto_ptr_copy(&dst, corto_any_o, &src);
    test_assert(ret == 0);
    test_assert(dst.type == corto_type(corto_int32_o));
    test_assert(dst.value != NULL);
    test_assert(dst.owner == TRUE);
    test_assert(*(corto_int32*)dst.value == 10);

    corto_ptr_deinit(&dst, corto_any_o);

/* $end */
}

void _test_Copy_tc_arrayToArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToArray) */
    corto_int32 v1[] = {10, 20, 30, 40};
    corto_int32 v2[] = {0, 0, 0, 0};
    corto_int16 ret;

    ret = corto_ptr_copy(v2, test_IntArray_o, v1);
    test_assert(ret == 0);
    test_assert(v2[0] == 10);
    test_assert(v2[1] == 20);
    test_assert(v2[2] == 30);
    test_assert(v2[3] == 40);

/* $end */
}

void _test_Copy_tc_arrayToArrayAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToArrayAlloc) */
    corto_int64 v1[] = {10, 20, 30, 40};
    corto_int64 v2[] = {0, 0, 0, 0};
    corto_int16 ret;

    ret = corto_ptr_copy(v2, test_AllocArray_o, v1);
    test_assert(ret == 0);
    test_assertint(v2[0], 10);
    test_assertint(v2[1], 20);
    test_assertint(v2[2], 30);
    test_assertint(v2[3], 40);
/* $end */
}

void _test_Copy_tc_arrayToArrayString(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToArrayString) */
    corto_string v1[] = {"Foo", "Bar", "Hello", "World"};
    corto_string v2[] = {0, 0, 0, 0};
    corto_int16 ret;

    ret = corto_ptr_copy(v2, test_StringArray_o, v1);
    test_assert(ret == 0);
    test_assertstr(v2[0], "Foo");
    test_assertstr(v2[1], "Bar");
    test_assertstr(v2[2], "Hello");
    test_assertstr(v2[3], "World");

    corto_ptr_deinit(v2, test_StringArray_o);

/* $end */
}

void _test_Copy_tc_arrayToExistingArrayString(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToExistingArrayString) */
    corto_string v1[] = {"HELLO", "WORLD", "FOO", "BAR"};
    corto_string v2[] = {NULL, NULL, NULL, NULL};
    corto_int16 ret;

    ret = corto_ptr_copy(v2, test_StringArray_o, v1);
    test_assert(ret == 0);
    test_assertstr(v2[0], "HELLO");
    test_assertstr(v2[1], "WORLD");
    test_assertstr(v2[2], "FOO");
    test_assertstr(v2[3], "BAR");

    corto_string v3[] = {"Foo", "Bar", "Hello", "World"};
    ret = corto_ptr_copy(v2, test_StringArray_o, v3);
    test_assert(ret == 0);
    test_assertstr(v2[0], "Foo");
    test_assertstr(v2[1], "Bar");
    test_assertstr(v2[2], "Hello");
    test_assertstr(v2[3], "World");

    corto_ptr_deinit(v2, test_StringArray_o);

/* $end */
}

void _test_Copy_tc_arrayToExistingList(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToExistingList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntArrayCreate_auto(v1, 4, v);
    test_IntListCreate_auto(v2, 0, NULL);
    test_IntListAppend(*v2, 1);
    test_IntListAppend(*v2, 2);
    test_IntListAppend(*v2, 3);
    test_IntListAppend(*v2, 4);
    test_IntListAppend(*v2, 5);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertint(test_IntListGet(*v2, 0), 10);
    test_assertint(test_IntListGet(*v2, 1), 20);
    test_assertint(test_IntListGet(*v2, 2), 30);
    test_assertint(test_IntListGet(*v2, 3), 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_arrayToExistingListString(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToExistingListString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    corto_string w[] = {"Foo", "Bar", "Hello", "World", "Zoo"};

    test_StringArrayCreate_auto(v1, 4, v);
    test_StringListCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertstr(test_StringListGet(*v2, 0), "HELLO");
    test_assertstr(test_StringListGet(*v2, 1), "WORLD");
    test_assertstr(test_StringListGet(*v2, 2), "FOO");
    test_assertstr(test_StringListGet(*v2, 3), "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_arrayToList(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntArrayCreate_auto(v1, 4, v);
    test_IntListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(test_IntListGet(*v2, 0) == 10);
    test_assert(test_IntListGet(*v2, 1) == 20);
    test_assert(test_IntListGet(*v2, 2) == 30);
    test_assert(test_IntListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_arrayToListAlloc(
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

void _test_Copy_tc_arrayToListString(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayToListString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    test_StringArrayCreate_auto(v1, 4, v);
    test_StringListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertstr(test_StringListGet(*v2, 0), "HELLO");
    test_assertstr(test_StringListGet(*v2, 1), "WORLD");
    test_assertstr(test_StringListGet(*v2, 2), "FOO");
    test_assertstr(test_StringListGet(*v2, 3), "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_arrayWithInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayWithInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_arrayWithReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayWithReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_arrayWithString(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayWithString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_arrayWithStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_arrayWithStruct) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_int(
    test_Copy this)
{
/* $begin(test/Copy/tc_int) */
    corto_int32 v1 = 10;
    corto_int32 v2 = 0;
    corto_int16 ret;

    ret = corto_ptr_copy(&v2, corto_int32_o, &v1);
    test_assert(ret == 0);
    test_assert(v1 == 10);

/* $end */
}

void _test_Copy_tc_listToArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToArray) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntListCreate_auto(v1, 4, v);
    test_IntArrayCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret != 0);
    test_assert(!strcmp(
      corto_lasterr(),
      "cannot copy value of type '/test/IntList' to '/test/IntArray'"));

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToArrayAlloc(
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

void _test_Copy_tc_listToArrayString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToArrayString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    test_StringListCreate_auto(v1, 4, v);
    test_StringArrayCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret != 0);
    test_assert(!strcmp(
      corto_lasterr(),
      "cannot copy value of type '/test/StringList' to '/test/StringArray'"));

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToExistingList(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToExistingList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    corto_int32 w[] = {11, 22, 33, 44, 55};
    test_IntListCreate_auto(v1, 4, v);
    test_IntListCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertint(test_IntListGet(*v2, 0), 10);
    test_assertint(test_IntListGet(*v2, 1), 20);
    test_assertint(test_IntListGet(*v2, 2), 30);
    test_assertint(test_IntListGet(*v2, 3), 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToExistingListString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToExistingListString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    corto_string w[] = {"Foo", "Bar", "Hello", "World", "Zoo"};
    test_StringListCreate_auto(v1, 4, v);
    test_StringListCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertstr(test_StringListGet(*v2, 0), "HELLO");
    test_assertstr(test_StringListGet(*v2, 1), "WORLD");
    test_assertstr(test_StringListGet(*v2, 2), "FOO");
    test_assertstr(test_StringListGet(*v2, 3), "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToExistingSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToExistingSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    corto_int32 w[] = {11, 22, 33, 44, 55};
    test_IntListCreate_auto(v1, 4, v);
    test_IntSequenceCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertint(v2->buffer[0], 10);
    test_assertint(v2->buffer[1], 20);
    test_assertint(v2->buffer[2], 30);
    test_assertint(v2->buffer[3], 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToExistingSequenceString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToExistingSequenceString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    corto_string w[] = {"Foo", "Bar", "Hello", "World", "Zoo"};

    test_StringListCreate_auto(v1, 4, v);
    test_StringSequenceCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertstr(v2->buffer[0], "HELLO");
    test_assertstr(v2->buffer[1], "WORLD");
    test_assertstr(v2->buffer[2], "FOO");
    test_assertstr(v2->buffer[3], "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToList(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToList) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntListCreate_auto(v1, 4, v);
    test_IntListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_ll_size(*v2) == 4);
    test_assert(test_IntListGet(*v2, 0) == 10);
    test_assert(test_IntListGet(*v2, 1) == 20);
    test_assert(test_IntListGet(*v2, 2) == 30);
    test_assert(test_IntListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToListAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 4, v);
    test_AllocListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_ll_size(*v2) == 4);
    test_assert(test_AllocListGet(*v2, 0) == 10);
    test_assert(test_AllocListGet(*v2, 1) == 20);
    test_assert(test_AllocListGet(*v2, 2) == 30);
    test_assert(test_AllocListGet(*v2, 3) == 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToListResize(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListResize) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntListCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_IntListCreate_auto(v2, 4, v);

    test_assert(corto_ll_size(*v2) == 4);
    test_assert(test_IntListGet(*v2, 0) == 15);
    test_assert(test_IntListGet(*v2, 1) == 25);
    test_assert(test_IntListGet(*v2, 2) == 35);
    test_assert(test_IntListGet(*v2, 3) == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_ll_size(*v2) == 3);
    test_assert(test_IntListGet(*v2, 0) == 10);
    test_assert(test_IntListGet(*v2, 1) == 20);
    test_assert(test_IntListGet(*v2, 2) == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToListResizeAlloc(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListResizeAlloc) */
    corto_int16 ret;
    corto_int64 v[] = {10, 20, 30, 40};
    test_AllocListCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_AllocListCreate_auto(v2, 4, v);

    test_assert(corto_ll_size(*v2) == 4);
    test_assert(test_AllocListGet(*v2, 0) == 15);
    test_assert(test_AllocListGet(*v2, 1) == 25);
    test_assert(test_AllocListGet(*v2, 2) == 35);
    test_assert(test_AllocListGet(*v2, 3) == 45);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assert(corto_ll_size(*v2) == 3);
    test_assert(test_AllocListGet(*v2, 0) == 10);
    test_assert(test_AllocListGet(*v2, 1) == 20);
    test_assert(test_AllocListGet(*v2, 2) == 30);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToListString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToListString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    test_StringListCreate_auto(v1, 4, v);
    test_StringListCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(corto_ll_size(*v2), 4);
    test_assertstr(test_StringListGet(*v2, 0), "HELLO");
    test_assertstr(test_StringListGet(*v2, 1), "WORLD");
    test_assertstr(test_StringListGet(*v2, 2), "FOO");
    test_assertstr(test_StringListGet(*v2, 3), "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listToSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntListCreate_auto(v1, 4, v);
    test_IntSequenceCreate_auto(v2, 0, NULL);

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

void _test_Copy_tc_listToSequenceAlloc(
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

void _test_Copy_tc_listToSequenceString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listToSequenceString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    test_StringListCreate_auto(v1, 4, v);
    test_StringSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertstr(v2->buffer[0], "HELLO");
    test_assertstr(v2->buffer[1], "WORLD");
    test_assertstr(v2->buffer[2], "FOO");
    test_assertstr(v2->buffer[3], "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_listWithInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_listWithInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_listWithReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_listWithReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_listWithString(
    test_Copy this)
{
/* $begin(test/Copy/tc_listWithString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_listWithStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_listWithStruct) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_reference(
    test_Copy this)
{
/* $begin(test/Copy/tc_reference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_sequenceToExistingSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToExistingSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    corto_int32 w[] = {11, 22, 33, 44, 55};
    test_IntSequenceCreate_auto(v1, 4, v);
    test_IntSequenceCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertint(v2->buffer[0], 10);
    test_assertint(v2->buffer[1], 20);
    test_assertint(v2->buffer[2], 30);
    test_assertint(v2->buffer[3], 40);

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_sequenceToExistingSequenceString(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToExistingSequenceString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    corto_string w[] = {"Foo", "Bar", "Hello", "World", "Zoo"};
    test_StringSequenceCreate_auto(v1, 4, v);
    test_StringSequenceCreate_auto(v2, 5, w);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertstr(v2->buffer[0], "HELLO");
    test_assertstr(v2->buffer[1], "WORLD");
    test_assertstr(v2->buffer[2], "FOO");
    test_assertstr(v2->buffer[3], "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_sequenceToExistingSequenceStringStack(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToExistingSequenceStringStack) */
    corto_int16 ret;
    test_StringSequence v1 = {4, (char*[]){"HELLO", "WORLD", "FOO", "BAR"}};
    test_StringSequence v2 = {0, NULL};

    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v1);
    test_assert(ret == 0);
    test_assertint(v2.length, 4);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "HELLO");
    test_assertstr(v2.buffer[1], "WORLD");
    test_assertstr(v2.buffer[2], "FOO");
    test_assertstr(v2.buffer[3], "BAR");

    /* Copy new value into existing sequence */
    test_StringSequence v3 = {4, (char*[]){"Foo", "Bar", "Hello", "World"}};
    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v3);
    test_assert(ret == 0);
    test_assertint(v2.length, 4);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "Foo");
    test_assertstr(v2.buffer[1], "Bar");
    test_assertstr(v2.buffer[2], "Hello");
    test_assertstr(v2.buffer[3], "World");

    corto_ptr_deinit(&v2, test_StringSequence_o);

/* $end */
}

void _test_Copy_tc_sequenceToExistingSequenceStringStackLarger(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToExistingSequenceStringStackLarger) */
    corto_int16 ret;
    test_StringSequence v1 = {4, (char*[]){"HELLO", "WORLD", "FOO", "BAR"}};
    test_StringSequence v2 = {0, NULL};

    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v1);
    test_assert(ret == 0);
    test_assertint(v2.length, 4);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "HELLO");
    test_assertstr(v2.buffer[1], "WORLD");
    test_assertstr(v2.buffer[2], "FOO");
    test_assertstr(v2.buffer[3], "BAR");

    /* Copy new value into existing sequence */
    test_StringSequence v3 = {5, (char*[]){"Foo", "Bar", "Hello", "World", "Zoo"}};
    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v3);
    test_assert(ret == 0);
    test_assertint(v2.length, 5);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "Foo");
    test_assertstr(v2.buffer[1], "Bar");
    test_assertstr(v2.buffer[2], "Hello");
    test_assertstr(v2.buffer[3], "World");
    test_assertstr(v2.buffer[4], "Zoo");

    corto_ptr_deinit(&v2, test_StringSequence_o);

/* $end */
}

void _test_Copy_tc_sequenceToExistingSequenceStringStackSmaller(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToExistingSequenceStringStackSmaller) */
    corto_int16 ret;
    test_StringSequence v1 = {4, (char*[]){"HELLO", "WORLD", "FOO", "BAR"}};
    test_StringSequence v2 = {0, NULL};

    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v1);
    test_assert(ret == 0);
    test_assertint(v2.length, 4);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "HELLO");
    test_assertstr(v2.buffer[1], "WORLD");
    test_assertstr(v2.buffer[2], "FOO");
    test_assertstr(v2.buffer[3], "BAR");

    /* Copy new value into existing sequence */
    test_StringSequence v3 = {3, (char*[]){"Foo", "Bar", "Hello"}};
    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v3);
    test_assert(ret == 0);
    test_assertint(v2.length, 3);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "Foo");
    test_assertstr(v2.buffer[1], "Bar");
    test_assertstr(v2.buffer[2], "Hello");

    corto_ptr_deinit(&v2, test_StringSequence_o);

/* $end */
}

void _test_Copy_tc_sequenceToSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequence) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntSequenceCreate_auto(v1, 4, v);
    test_IntSequenceCreate_auto(v2, 0, NULL);

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

void _test_Copy_tc_sequenceToSequenceAlloc(
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

void _test_Copy_tc_sequenceToSequenceComposite(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceComposite) */
    corto_int16 ret;
    corto_parameter p1 = {"foo", corto_type(corto_int32_o), CORTO_IN, TRUE};
    corto_parameter p2 = {"bar", corto_type(corto_float32_o), CORTO_IN, FALSE};
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

void _test_Copy_tc_sequenceToSequenceResize(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceResize) */
    corto_int16 ret;
    corto_int32 v[] = {10, 20, 30, 40};
    test_IntSequenceCreate_auto(v1, 3, v);
    v[0] = 15; v[1] = 25; v[2] = 35; v[3] = 45;
    test_IntSequenceCreate_auto(v2, 4, v);

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

void _test_Copy_tc_sequenceToSequenceResizeAlloc(
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

void _test_Copy_tc_sequenceToSequenceString(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceString) */
    corto_int16 ret;
    corto_string v[] = {"HELLO", "WORLD", "FOO", "BAR"};
    test_StringSequenceCreate_auto(v1, 4, v);
    test_StringSequenceCreate_auto(v2, 0, NULL);

    ret = corto_copy(&v2, v1);
    test_assert(ret == 0);
    test_assertint(v2->length, 4);
    test_assert(v2->buffer != NULL);
    test_assertstr(v2->buffer[0], "HELLO");
    test_assertstr(v2->buffer[1], "WORLD");
    test_assertstr(v2->buffer[2], "FOO");
    test_assertstr(v2->buffer[3], "BAR");

    corto_delete(v1);
    corto_delete(v2);

/* $end */
}

void _test_Copy_tc_sequenceToSequenceStringStack(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceStringStack) */
    corto_int16 ret;
    test_StringSequence v1 = {4, (char*[]){"HELLO", "WORLD", "FOO", "BAR"}};
    test_StringSequence v2 = {0, NULL};

    ret = corto_ptr_copy(&v2, test_StringSequence_o, &v1);
    test_assert(ret == 0);
    test_assertint(v2.length, 4);
    test_assert(v2.buffer != NULL);
    test_assertstr(v2.buffer[0], "HELLO");
    test_assertstr(v2.buffer[1], "WORLD");
    test_assertstr(v2.buffer[2], "FOO");
    test_assertstr(v2.buffer[3], "BAR");

    corto_ptr_deinit(&v2, test_StringSequence_o);

/* $end */
}

void _test_Copy_tc_sequenceToSequenceValueComposite(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceToSequenceValueComposite) */
    corto_int16 ret;
    corto_parameter p1 = {"foo", corto_type(corto_int32_o), CORTO_IN, TRUE};
    corto_parameter p2 = {"bar", corto_type(corto_float32_o), CORTO_IN, FALSE};
    corto_parameterseq v1 = {2, (corto_parameter[]){p1, p2}};
    corto_parameterseq v2 = {0, NULL};

    ret = corto_ptr_copy(&v2, corto_parameterseq_o, &v1);
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

void _test_Copy_tc_sequenceWithInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceWithInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_sequenceWithReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceWithReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_sequenceWithString(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceWithString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_sequenceWithStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_sequenceWithStruct) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_string(
    test_Copy this)
{
/* $begin(test/Copy/tc_string) */
    corto_string v1 = "foo";
    corto_string v2 = NULL;
    corto_int32 ret;

    ret = corto_ptr_copy(&v2, corto_string_o, &v1);
    test_assert(ret == 0);
    test_assert(!strcmp(v2, "foo"));

/* $end */
}

void _test_Copy_tc_struct(
    test_Copy this)
{
/* $begin(test/Copy/tc_struct) */
    test_Point v1 = {10, 20};
    test_Point v2 = {0};

    test_assert(corto_ptr_copy(&v2, test_Point_o, &v1) == 0);
    test_assertint(v2.x, 10);
    test_assertint(v2.y, 20);

/* $end */
}

void _test_Copy_tc_structWithObservableArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableArray) */
    test_struct_observableArray v1;
    test_struct_observableArray v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableArray_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableArray_o) == 0);

    test_IntArrayAssign(*v1.m, 4, ((int32_t[]){
        1, 2, 3, 4
    }));

    corto_ptr_copy(&v2, test_struct_observableArray_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint((*v2.m)[0], 1);
    test_assertint((*v2.m)[1], 2);
    test_assertint((*v2.m)[2], 3);
    test_assertint((*v2.m)[3], 4);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableArray_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableArray_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableInt) */
    test_struct_observableInt v1;
    test_struct_observableInt v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableInt_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableInt_o) == 0);

    *v1.m = 10;

    corto_ptr_copy(&v2, test_struct_observableInt_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(*v2.m, 10);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableInt_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableInt_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableList(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableList) */
    test_struct_observableList v1;
    test_struct_observableList v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableList_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableList_o) == 0);

    test_IntListAppend(*v1.m, 10);
    test_IntListAppend(*v1.m, 20);
    test_IntListAppend(*v1.m, 30);

    corto_ptr_copy(&v2, test_struct_observableList_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assert(*v2.m != *v1.m);
    test_assertint(corto_ll_size(*v2.m), 3);
    test_assertint(test_IntListGet(*v2.m, 0), 10);
    test_assertint(test_IntListGet(*v2.m, 1), 20);
    test_assertint(test_IntListGet(*v2.m, 2), 30);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableList_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableList_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableReference) */
    test_struct_observableReference v1;
    test_struct_observableReference v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableReference_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableReference_o) == 0);

    corto_ptr_setref(v1.m, corto_class_o);

    corto_ptr_copy(&v2, test_struct_observableReference_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(*(corto_object*)v2.m == corto_class_o);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableReference_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableReference_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableSequence) */
    test_struct_observableSequence v1;
    test_struct_observableSequence v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableSequence_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableSequence_o) == 0);

    test_IntSequenceAppend(v1.m, 10);
    test_IntSequenceAppend(v1.m, 20);
    test_IntSequenceAppend(v1.m, 30);

    corto_ptr_copy(&v2, test_struct_observableSequence_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->length, 3);
    test_assertint(v2.m->buffer[0], 10);
    test_assertint(v2.m->buffer[1], 20);
    test_assertint(v2.m->buffer[2], 30);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableSequence_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableSequence_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableString(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableString) */
    test_struct_observableString v1;
    test_struct_observableString v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableString_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableString_o) == 0);

    corto_ptr_setstr(v1.m, "Hello World");

    corto_ptr_copy(&v2, test_struct_observableString_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assert(*v2.m != *v1.m);
    test_assertstr(*v2.m, "Hello World");

    test_assert(corto_ptr_deinit(&v1, test_struct_observableString_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableString_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithObservableStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithObservableStruct) */
    test_struct_observableStruct v1;
    test_struct_observableStruct v2;

    test_assert(corto_ptr_init(&v1, test_struct_observableStruct_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_observableStruct_o) == 0);

    v1.m->x = 10;
    v1.m->y = 20;

    corto_ptr_copy(&v2, test_struct_observableStruct_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->x, 10);
    test_assertint(v2.m->y, 20);

    test_assert(corto_ptr_deinit(&v1, test_struct_observableStruct_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_observableStruct_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalArray) */
    test_struct_optionalStruct v1;
    test_struct_optionalStruct v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalStruct_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalStruct_o) == 0);

    test_PointSet(v1.m, 10, 20);

    corto_ptr_copy(&v2, test_struct_optionalStruct_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->x, 10);
    test_assertint(v2.m->y, 20);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalStruct_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalStruct_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalInt) */
    test_struct_optionalInt v1;
    test_struct_optionalInt v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalInt_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalInt_o) == 0);

    corto_int32Set(v1.m, 10);

    corto_ptr_copy(&v2, test_struct_optionalInt_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(*v2.m, 10);

    corto_int32Unset(v1.m);

    corto_ptr_copy(&v2, test_struct_optionalInt_o, &v1);
    test_assert(v2.m == NULL);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalInt_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalInt_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalList(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalList) */
    test_struct_optionalList v1;
    test_struct_optionalList v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalList_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalList_o) == 0);

    test_IntListSet(v1.m, 4, ((corto_int32[])
        {1, 2, 3, 4}
    ));

    corto_ptr_copy(&v2, test_struct_optionalList_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(corto_ll_size(*v2.m), 4);
    test_assertint(test_IntListGet(*v2.m, 0), 1);
    test_assertint(test_IntListGet(*v2.m, 1), 2);
    test_assertint(test_IntListGet(*v2.m, 2), 3);
    test_assertint(test_IntListGet(*v2.m, 3), 4);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalList_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalList_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalReference) */
    test_struct_optionalReference v1;
    test_struct_optionalReference v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalReference_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalReference_o) == 0);

    v1.m = corto_ptr_new(corto_object_o);
    corto_ptr_setref(v1.m, corto_class_o);

    corto_ptr_copy(&v2, test_struct_optionalReference_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assert(*v2.m == corto_class_o);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalReference_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalReference_o) == 0);
    
/* $end */
}

void _test_Copy_tc_structWithOptionalSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalSequence) */
    test_struct_optionalSequence v1;
    test_struct_optionalSequence v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalSequence_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalSequence_o) == 0);

    test_IntSequenceSet(v1.m, 4, ((corto_int32[])
        {1, 2, 3, 4}
    ));

    corto_ptr_copy(&v2, test_struct_optionalSequence_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->length, 4);
    test_assertint(v2.m->buffer[0], 1);
    test_assertint(v2.m->buffer[1], 2);
    test_assertint(v2.m->buffer[2], 3);
    test_assertint(v2.m->buffer[3], 4);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalSequence_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalSequence_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalString(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalString) */
    test_struct_optionalString v1;
    test_struct_optionalString v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalString_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalString_o) == 0);

    corto_stringSet(v1.m, "Hello World");

    corto_ptr_copy(&v2, test_struct_optionalString_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertstr(*v2.m, "Hello World");

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalString_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalString_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithOptionalStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithOptionalStruct) */
    test_struct_optionalStruct v1;
    test_struct_optionalStruct v2;

    test_assert(corto_ptr_init(&v1, test_struct_optionalStruct_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_optionalStruct_o) == 0);

    test_PointSet(v1.m, 10, 20);

    corto_ptr_copy(&v2, test_struct_optionalStruct_o, &v1);
    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->x, 10);
    test_assertint(v2.m->y, 20);

    test_assert(corto_ptr_deinit(&v1, test_struct_optionalStruct_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_optionalStruct_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetArray) */
    test_struct_targetArray v1;
    test_struct_targetArray v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetArray_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetArray_o) == 0);

    test_IntArray a = {10, 20, 30, 40};
    test_struct_targetArrayAssign(&v1, a);

    corto_ptr_copy(&v2, test_struct_targetArray_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->actual[0], 10);
    test_assertint(v2.m->actual[1], 20);
    test_assertint(v2.m->actual[2], 30);
    test_assertint(v2.m->actual[3], 40);
    test_assertint(v2.m->target[0], 0);
    test_assertint(v2.m->target[1], 0);
    test_assertint(v2.m->target[2], 0);
    test_assertint(v2.m->target[3], 0);
    test_assertint(v2.m->objective[0], 0);
    test_assertint(v2.m->objective[1], 0);
    test_assertint(v2.m->objective[2], 0);
    test_assertint(v2.m->objective[3], 0);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetArray_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetArray_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetInt) */
    test_struct_targetInt v1;
    test_struct_targetInt v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetInt_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetInt_o) == 0);

    test_struct_targetIntAssign(&v1, 10);
    test_assertint(v1.m->actual, 10);
    test_assertint(v1.m->target, 0);
    test_assertint(v1.m->objective, 0);

    corto_ptr_copy(&v2, test_struct_targetInt_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->actual, 10);
    test_assertint(v2.m->target, 0);
    test_assertint(v2.m->objective, 0);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetInt_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetInt_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetList(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetList) */
    test_struct_targetList v1;
    test_struct_targetList v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetList_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetList_o) == 0);

    test_IntListAppend(v1.m->actual, 10);
    test_IntListAppend(v1.m->actual, 20);
    test_IntListAppend(v1.m->actual, 30);
    test_IntListAppend(v1.m->actual, 40);

    corto_ptr_copy(&v2, test_struct_targetList_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(corto_ll_size(v2.m->actual), 4);
    test_assertint(corto_ll_size(v2.m->target), 0);
    test_assertint(corto_ll_size(v2.m->objective), 0);
    test_assertint(test_IntListGet(v2.m->actual, 0), 10);
    test_assertint(test_IntListGet(v2.m->actual, 1), 20);
    test_assertint(test_IntListGet(v2.m->actual, 2), 30);
    test_assertint(test_IntListGet(v2.m->actual, 3), 40);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetList_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetList_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetReference) */
    test_struct_targetReference v1;
    test_struct_targetReference v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetReference_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetReference_o) == 0);

    corto_ptr_setref(&v1.m->actual, corto_class_o);

    corto_ptr_copy(&v2, test_struct_targetReference_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assert(v2.m->actual == corto_class_o);
    test_assert(v2.m->target == NULL);
    test_assert(v2.m->objective == NULL);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetReference_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetReference_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetSequence) */
    test_struct_targetSequence v1;
    test_struct_targetSequence v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetSequence_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetSequence_o) == 0);

    test_IntSequence s = {4, (corto_int32[]){10, 20, 30, 40}};
    test_struct_targetSequenceAssign(&v1, s);

    corto_ptr_copy(&v2, test_struct_targetSequence_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->actual.length, 4);
    test_assert(v2.m->actual.buffer != v1.m->actual.buffer);
    test_assertint(v2.m->target.length, 0);
    test_assertint(v2.m->objective.length, 0);
    test_assertint(v2.m->actual.buffer[0], 10);
    test_assertint(v2.m->actual.buffer[1], 20);
    test_assertint(v2.m->actual.buffer[2], 30);
    test_assertint(v2.m->actual.buffer[3], 40);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetSequence_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetSequence_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetString(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetString) */
    test_struct_targetString v1;
    test_struct_targetString v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetString_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetString_o) == 0);

    test_struct_targetStringAssign(&v1, "Hello World");
    test_assertstr(v1.m->actual, "Hello World");

    corto_ptr_copy(&v2, test_struct_targetString_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assert(v2.m->actual != v1.m->actual);
    test_assert(v2.m->target == NULL);
    test_assert(v2.m->objective == NULL);
    test_assertstr(v2.m->actual, "Hello World");

    test_assert(corto_ptr_deinit(&v1, test_struct_targetString_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetString_o) == 0);

/* $end */
}

void _test_Copy_tc_structWithTargetStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_structWithTargetStruct) */
    test_struct_targetStruct v1;
    test_struct_targetStruct v2;

    test_assert(corto_ptr_init(&v1, test_struct_targetStruct_o) == 0);
    test_assert(corto_ptr_init(&v2, test_struct_targetStruct_o) == 0);

    test_Point p = {10, 20};
    test_struct_targetStructAssign(&v1, &p);
    test_assertint(v1.m->actual.x, 10);
    test_assertint(v1.m->actual.y, 20);

    corto_ptr_copy(&v2, test_struct_targetStruct_o, &v1);

    test_assert(v2.m != NULL);
    test_assert(v2.m != v1.m);
    test_assertint(v2.m->actual.x, 10);
    test_assertint(v2.m->actual.y, 20);
    test_assertint(v2.m->target.x, 0);
    test_assertint(v2.m->target.y, 0);
    test_assertint(v2.m->objective.x, 0);
    test_assertint(v2.m->objective.y, 0);

    test_assert(corto_ptr_deinit(&v1, test_struct_targetStruct_o) == 0);
    test_assert(corto_ptr_deinit(&v2, test_struct_targetStruct_o) == 0);

/* $end */
}

void _test_Copy_tc_union(
    test_Copy this)
{
/* $begin(test/Copy/tc_union) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableArray) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableList(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableList) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableSequence) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableString(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithObservableStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithObservableStruct) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalArray) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalList(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalList) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalSequence) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalString(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithOptionalStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithOptionalStruct) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetArray(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetArray) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetInt(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetInt) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetList(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetList) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetReference(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetReference) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetSequence(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetSequence) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetString(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetString) */

    /* << Insert implementation >> */

/* $end */
}

void _test_Copy_tc_unionWithTargetStruct(
    test_Copy this)
{
/* $begin(test/Copy/tc_unionWithTargetStruct) */

    /* << Insert implementation >> */

/* $end */
}
