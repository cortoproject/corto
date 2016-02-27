/* $CORTO_GENERATED
 *
 * JsonReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_int16 _test_JsonReplicator_construct(
    test_JsonReplicator this)
{
/* $begin(test/JsonReplicator/construct) */

    corto_replicator_setContentType(this, "application/json");

    return corto_replicator_construct(this);
/* $end */
}

/* $header(test/JsonReplicator/onRequest) */
/* Custom release function */
void test_JsonReplicator_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_JsonReplicator_onRequest(
    test_JsonReplicator this,
    corto_string parent,
    corto_string expr,
    corto_string param,
    corto_bool setContent)
{
/* $begin(test/JsonReplicator/onRequest) */
    corto_ll data = corto_llNew();

    /* Create top level objects */
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "a",
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":10,\"y\":20}")
    );
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "b",
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":30,\"y\":40}")
    );
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "c",
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":50,\"y\":60}")
    );

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_JsonReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
/* $end */
}
