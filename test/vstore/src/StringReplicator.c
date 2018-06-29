/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_StringReplicator_construct(
    test_StringReplicator this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }
    
    corto_mount_set_format(this, "text/corto");

    return corto_mount_construct(this);
}


/* Custom release function */
void test_StringReplicator_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultList__clear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_StringReplicator_on_query(
    test_StringReplicator this,
    corto_query *query)
{
    corto_ll data = corto_ll_new();

    /* Create top level objects */
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "a",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{10,20}"),
        CORTO_RESULT_LEAF
    );
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "b",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{30,40}"),
        CORTO_RESULT_LEAF
    );
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "c",
        NULL,
        ".",
        "/test/Point",
        (corto_word)corto_strdup("{50,60}"),
        CORTO_RESULT_LEAF
    );

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_StringReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
}
