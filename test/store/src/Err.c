/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void tc_callback_callback(corto_log_verbosity level, char *category[], char *msg, void* ctx)
{
    test_Err this = ctx;
    this->level = level;
    corto_set_str(&this->msg, msg);

    if (category) {
        corto_buffer buff = CORTO_BUFFER_INIT;
        corto_int32 i;
        for (i = 0; category[i]; i++) {
            if (i) corto_buffer_appendstr(&buff, ",");
            corto_buffer_appendstr(&buff, category[i]);
        }
        this->category = corto_buffer_str(&buff);
    }
}

void test_Err_tc_callback(
    test_Err this)
{

    corto_log_verbositySet(CORTO_WARNING);

    corto_log_handler cb = corto_log_handlerRegister(
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

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_category(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        NULL,
        NULL,
        tc_callback_callback,
        this);

    corto_trace("mycategory: test trace");

    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "mycategory");
    test_assert(this->level == CORTO_TRACE);

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_categoryColonNoCategory(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        NULL,
        NULL,
        tc_callback_callback,
        this);

    corto_trace("test trace");

    test_assertstr(this->msg, "test trace");
    test_assert(this->category == NULL);
    test_assert(this->level == CORTO_TRACE);

    corto_log_handlerUnregister(cb);
}

void test_Err_tc_categoryFilter(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        "foo",
        NULL,
        tc_callback_callback,
        this);

    corto_trace("bar: test trace"); /* no match */

    test_assert(this->level == 0);
    test_assert(this->msg == NULL);
    test_assert(this->category == NULL);

    corto_trace("foo: test trace"); /* match */

    test_assert(this->level == CORTO_TRACE);
    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "foo");

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_categoryFilterMulti(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        "foo/bar",
        NULL,
        tc_callback_callback,
        this);

    corto_trace("foo: hello: test trace"); /* no match */

    test_assert(this->level == 0);
    test_assert(this->msg == NULL);
    test_assert(this->category == NULL);

    corto_trace("foo: bar: test trace"); /* match */

    test_assert(this->level == CORTO_TRACE);
    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "foo,bar");

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_categoryFilterWildcard(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        "fo?",
        NULL,
        tc_callback_callback,
        this);

    corto_trace("bar: test trace"); /* no match */

    test_assert(this->level == 0);
    test_assert(this->msg == NULL);
    test_assert(this->category == NULL);

    corto_trace("foo: test trace"); /* match */

    test_assert(this->level == CORTO_TRACE);
    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "foo");

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_categoryMultiple(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        NULL,
        NULL,
        tc_callback_callback,
        this);

    corto_trace("mycategory1: mycategory2: test trace");

    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "mycategory1,mycategory2");
    test_assert(this->level == CORTO_TRACE);

    corto_log_handlerUnregister(cb);
}

void test_Err_tc_categoryRecursive(
    test_Err this)
{
    corto_log_handler cb = corto_log_handlerRegister(
        CORTO_DEBUG,
        CORTO_TRACE,
        "foo//",
        NULL,
        tc_callback_callback,
        this);

    corto_trace("bar: test trace"); /* no match */

    test_assert(this->level == 0);
    test_assert(this->msg == NULL);
    test_assert(this->category == NULL);

    corto_trace("foo: bar: test trace"); /* match */

    test_assert(this->level == CORTO_TRACE);
    test_assertstr(this->msg, "test trace");
    test_assertstr(this->category, "foo,bar");

    corto_debug("foo: bar: hello: more trace"); /* match */

    test_assert(this->level == CORTO_DEBUG);
    test_assertstr(this->msg, "more trace");
    test_assertstr(this->category, "foo,bar,hello");

    corto_log_handlerUnregister(cb);

}

void test_Err_tc_lastinfo(
    test_Err this)
{

    corto_setinfo("Hello World");
    test_assertstr(corto_lastinfo(), "Hello World");

}
