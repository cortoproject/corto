/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Loader_tc_loadNonExistent(
    test_Loader this)
{

    corto_int16 ret = ut_use("nonexistent.cx", 0, NULL);
    test_assert(ret != 0);
    test_assert(ut_catch());
}
