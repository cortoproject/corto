/* $CORTO_GENERATED
 *
 * Err.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header(test/Err/tc_callback) */
void tc_callback_callback(corto_err level, char *category, char *msg, void* ctx)
{
    test_Err this = ctx;
    this->level = level;
    corto_setstr(&this->msg, msg);
}
/* $end */
corto_void _test_Err_tc_callback(
    test_Err this)
{
/* $begin(test/Err/tc_callback) */

    corto_verbosity(CORTO_WARNING);

    corto_err_callback cb = corto_err_callbackRegister(
        CORTO_OK, 
        CORTO_WARNING,
        NULL, 
        NULL,
        tc_callback_callback,
        this);

    test_assert(cb != NULL);

    test_assert(this->msg == NULL);
    test_assert(this->level == 0);

    corto_trace("Test trace");

    test_assert(this->msg == NULL);
    test_assert(this->level == 0);

    /* OK is below verbosity level but callback should get it */
    corto_ok("Test ok");

    test_assertstr(this->msg, "Test ok");
    test_assert(this->level == CORTO_OK);

    corto_warning("Test warning");

    test_assertstr(this->msg, "Test warning");
    test_assert(this->level == CORTO_WARNING);

    corto_error("Test error");

    /* Should not be picked up by callback */
    test_assertstr(this->msg, "Test warning");
    test_assert(this->level == CORTO_WARNING);

    corto_err_callbackUnregister(cb);

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
