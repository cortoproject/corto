/* $CORTO_GENERATED
 *
 * Err.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Err_tc_callback(
    test_Err this)
{
/* $begin(test/Err/tc_callback) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_Err_tc_lasterr(
    test_Err this)
{
/* $begin(test/Err/tc_lasterr) */

    corto_seterr("Hello World");
    test_assertstr(corto_lasterr(), "Hello World");

/* $end */
}

corto_void _test_Err_tc_lastinfo(
    test_Err this)
{
/* $begin(test/Err/tc_lastinfo) */

    corto_setinfo("Hello World");
    test_assertstr(corto_lastinfo(), "Hello World");

/* $end */
}
