/* $CORTO_GENERATED
 *
 * EventReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_EventReplicator_onDeclare(
    test_EventReplicator this,
    corto_object observable)
{
/* $begin(test/EventReplicator/onDeclare) */

    this->declareCount ++;

/* $end */
}

corto_void _test_EventReplicator_onDelete(
    test_EventReplicator this,
    corto_object observable)
{
/* $begin(test/EventReplicator/onDelete) */

    this->deleteCount ++;

/* $end */
}

corto_void _test_EventReplicator_onUpdate(
    test_EventReplicator this,
    corto_object observable)
{
/* $begin(test/EventReplicator/onUpdate) */

    this->updateCount ++;

/* $end */
}
