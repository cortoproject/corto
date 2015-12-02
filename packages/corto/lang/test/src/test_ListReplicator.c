/* $CORTO_GENERATED
 *
 * test_ListReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_resultIter _test_ListReplicator_onRequest(test_ListReplicator this, corto_object parent, corto_string expr) {
/* $begin(test/ListReplicator/onRequest) */

    /* Return persistent iterator to request */
    return corto_llIterAlloc(this->items);

/* $end */
}
