/* $CORTO_GENERATED
 *
 * Buffer.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Buffer_tc_append(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_append) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, "Foo");
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, "Foo");

/* $end */
}

corto_void _test_Buffer_tc_appendEmpty(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendEmpty) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, "");
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, "");

/* $end */
}

corto_void _test_Buffer_tc_appendEmptyToExisting(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendEmptyToExisting) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, "Foo");
    test_assert(proceed == TRUE);
    proceed = corto_buffer_append(&b, "");
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, "Foo");

/* $end */
}

corto_void _test_Buffer_tc_appendLarge(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendLarge) */
    /* Pick a size that doesn't align with buffer boundaries */
    char largeString[800];

    /* Use easy to recognize pattern */
    int i; for (i = 0; i < 799; i++) {
        if (i % 2) {
            largeString[i] = '.';
        } else {
            largeString[i] = '|';
        }
    }
    largeString[799] = '\0';

    corto_buffer b = CORTO_BUFFER_INIT;
    corto_bool proceed = corto_buffer_append(&b, largeString);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, largeString);

/* $end */
}

corto_void _test_Buffer_tc_appendLargeMulti(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendLargeMulti) */
    /* Pick a size that doesn't align with buffer and requires at least three
     * elements */
    char largeString[1400];

    /* Use easy to recognize pattern */
    int i; for (i = 0; i < 1399; i++) {
        if (i % 2) {
            largeString[i] = '.';
        } else {
            largeString[i] = '|';
        }
    }
    largeString[1399] = '\0';

    corto_buffer b = CORTO_BUFFER_INIT;
    corto_bool proceed = corto_buffer_append(&b, largeString);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, largeString);

/* $end */
}

corto_void _test_Buffer_tc_appendLargeOverflow(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendLargeOverflow) */
    /* Pick a size that doesn't align with buffer boundaries and is larger than
     * an element. */
    char largeString[800];

    /* Use easy to recognize pattern */
    int i; for (i = 0; i < 799; i++) {
        switch (i % 2) {
        case 0: largeString[i] = '.'; break;
        case 1: largeString[i] = '|'; break;
        }
    }
    largeString[799] = '\0';

    corto_buffer b = CORTO_BUFFER_INIT;
    corto_bool proceed = corto_buffer_append(&b, "HelloWorld!");
    test_assert(proceed == TRUE);
    proceed = corto_buffer_append(&b, largeString);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    char result[811];
    sprintf(result, "HelloWorld!%s", largeString);
    test_assertstr(str, result);

/* $end */
}

corto_void _test_Buffer_tc_appendNull(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendNull) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, NULL);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str == NULL);

/* $end */
}

corto_void _test_Buffer_tc_appendNullToExisting(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendNullToExisting) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, "Foo");
    proceed = corto_buffer_append(&b, NULL);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, "Foo");

/* $end */
}

corto_void _test_Buffer_tc_appendOverflow(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendOverflow) */
    /* Pick a size that doesn't align with buffer boundaries, fits within an
     * element but requires the buffer to allocate a new element. */
    char largeString[505];

    /* Use easy to recognize pattern */
    int i; for (i = 0; i < 504; i++) {
        switch (i % 2) {
        case 0: largeString[i] = '.'; break;
        case 1: largeString[i] = '|'; break;
        }
    }
    largeString[504] = '\0';

    corto_buffer b = CORTO_BUFFER_INIT;
    corto_bool proceed = corto_buffer_append(&b, "HelloWorld!");
    test_assert(proceed == TRUE);
    proceed = corto_buffer_append(&b, largeString);
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    char result[516];
    sprintf(result, "HelloWorld!%s", largeString);
    test_assertstr(str, result);

/* $end */
}

corto_void _test_Buffer_tc_appendToExisting(
    test_Buffer this)
{
/* $begin(test/Buffer/tc_appendToExisting) */
    corto_buffer b = CORTO_BUFFER_INIT;

    corto_bool proceed = corto_buffer_append(&b, "Foo");
    proceed = corto_buffer_append(&b, "Bar");
    test_assert(proceed == TRUE);

    corto_string str = corto_buffer_str(&b);
    test_assert(str != NULL);
    test_assertstr(str, "FooBar");

/* $end */
}
