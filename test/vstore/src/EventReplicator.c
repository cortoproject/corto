/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_EventReplicator_on_notify(
    test_EventReplicator this,
    corto_subscriber_event *event)
{
    switch(event->event) {
        case CORTO_DECLARE: this->declareCount ++; break;
        case CORTO_DEFINE: this->updateCount ++; break;
        case CORTO_UPDATE: this->updateCount ++; break;
        case CORTO_DELETE: this->deleteCount ++; break;
    }
}


int16_t test_EventReplicator_construct(
    test_EventReplicator this)
{
    corto_mount(this)->sample_rate = this->policy.sampleRate;

    if (this->policy.mask) {
        corto_mount(this)->callbacks = this->policy.mask;
    }

    return corto_super_construct(this);
}
