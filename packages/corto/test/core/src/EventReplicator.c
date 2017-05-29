/* $CORTO_GENERATED
 *
 * EventReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_EventReplicator_onNotify(
    test_EventReplicator this,
    corto_subscriberEvent *event)
{
/* $begin(test/EventReplicator/onNotify) */

    switch(event->event) {
        case CORTO_ON_DECLARE: this->declareCount ++; break;
        case CORTO_ON_DEFINE: this->updateCount ++; break;
        case CORTO_ON_UPDATE: this->updateCount ++; break;
        case CORTO_ON_DELETE: this->deleteCount ++; break;
    }

/* $end */
}
