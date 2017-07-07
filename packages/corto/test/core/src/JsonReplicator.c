/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_JsonReplicator_construct(
    test_JsonReplicator this)
{

    corto_mount_setContentType(this, "application/json");

    return corto_mount_construct(this);
}


/* Custom release function */
void test_JsonReplicator_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_JsonReplicator_onQuery(
    test_JsonReplicator this,
    corto_query *query)
{
    corto_ll data = corto_ll_new();

    /* Create top level objects */
    corto_resultAssign(
        corto_resultListAppendAlloc(data),
        "a",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":10,\"y\":20}"),
        FALSE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(data),
        "b",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":30,\"y\":40}"),
        FALSE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(data),
        "c",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{\"x\":50,\"y\":60}"),
        FALSE
    );

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_JsonReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
}

