/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_StringReplicator_construct(
    test_StringReplicator this)
{

    corto_mount_setContentType(this, "text/corto");

    return corto_mount_construct(this);
}


/* Custom release function */
void test_StringReplicator_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_StringReplicator_onQuery(
    test_StringReplicator this,
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
        (corto_word)corto_strdup("{10,20}"),
        TRUE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(data),
        "b",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{30,40}"),
        TRUE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(data),
        "c",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{50,60}"),
        TRUE
    );

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_StringReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
}

