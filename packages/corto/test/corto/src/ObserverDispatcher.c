/* $CORTO_GENERATED
 *
 * ObserverDispatcher.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_ObserverDispatcher_post(
    test_ObserverDispatcher this,
    corto_event *e)
{
/* $begin(test/ObserverDispatcher/post) */

    this->called = TRUE;
    corto_event_handle(e);

/* $end */
}
