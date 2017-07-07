/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_ObserverDispatcher_post(
    test_ObserverDispatcher this,
    corto_event *e)
{

    this->called = TRUE;
    corto_event_handle(e);

}

