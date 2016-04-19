/* $CORTO_GENERATED
 *
 * StringReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_StringReplicator_construct(
    test_StringReplicator this)
{
/* $begin(test/StringReplicator/construct) */

    corto_mount_setContentType(this, "text/corto");

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/StringReplicator/onRequest) */
/* Custom release function */
void test_StringReplicator_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_StringReplicator_onRequest(
    test_StringReplicator this,
    corto_request *request)
{
/* $begin(test/StringReplicator/onRequest) */
    corto_ll data = corto_llNew();

    /* Create top level objects */
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "a",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{10,20}")
    );
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "b",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{30,40}")
    );
    corto_resultSet(
        corto_resultListAppendAlloc(data),
        "c",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{50,60}")
    );

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_StringReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
/* $end */
}
