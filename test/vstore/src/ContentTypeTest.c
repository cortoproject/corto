/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

static int construct_called = 0;

int16_t test_ContentTypeTest_construct(
    test_ContentTypeTest this)
{
    construct_called ++;
    return 0;
}

int32_t test_ContentTypeTest_get_construct_called_count(void)
{
    return construct_called;
}
