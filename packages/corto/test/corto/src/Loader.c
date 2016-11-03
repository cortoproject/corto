/* $CORTO_GENERATED
 *
 * Loader.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Loader_tc_loadNonExistent(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadNonExistent) */

    corto_int16 ret = corto_load("nonexistent.cx", 0, NULL);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assertstr(corto_lasterr(), "No such file or directory (nonexistent.cx)");

/* $end */
}
