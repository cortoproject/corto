/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_JsonReplicator_construct(
    test_JsonReplicator this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }
    
    corto_mount_setContentType(this, "text/json");
    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
    corto_mount(this)->filter_results = true;
    return corto_mount_construct(this);
}

/* Custom release function */
void test_JsonReplicator_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultList__clear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_JsonReplicator_on_query(
    test_JsonReplicator this,
    corto_query *query)
{
    corto_ll data = corto_ll_new();

    /* Create top level objects */
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "a",
        NULL,
        ".",
        this->type,
        (corto_word)corto_strdup("{\"x\":10,\"y\":20}"),
        CORTO_RESULT_LEAF
    );
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "b",
        0,
        ".",
        this->type,
        (corto_word)corto_strdup("{\"x\":30,\"y\":40}"),
        CORTO_RESULT_LEAF
    );
    corto_result__assign(
        corto_resultList__append_alloc(data),
        "c",
        NULL,
        ".",
        this->type,
        (corto_word)corto_strdup("{\"x\":50,\"y\":60}"),
        CORTO_RESULT_LEAF
    );

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_JsonReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
}
