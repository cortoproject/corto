/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_EventReplicator_onNotify(
    test_EventReplicator this,
    corto_subscriberEvent *event)
{
    switch(event->event) {
        case CORTO_DECLARE: this->declareCount ++; break;
        case CORTO_DEFINE: this->updateCount ++; break;
        case CORTO_UPDATE: this->updateCount ++; break;
        case CORTO_DELETE: this->deleteCount ++; break;
    }
}

