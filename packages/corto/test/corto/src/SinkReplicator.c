/* $CORTO_GENERATED
 *
 * SinkReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_int16 _test_SinkReplicator_construct(
    test_SinkReplicator this)
{
/* $begin(test/SinkReplicator/construct) */
    corto_string type =
      corto_mount(this)->type ? corto_mount(this)->type : "int32";

    // First tier
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "x",
        NULL,
        ".",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "y",
        NULL,
        ".",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "z",
        NULL,
        ".",
        type,
        0
    );

    // Second tier
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "x",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "b",
        NULL,
        "x",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "c",
        NULL,
        "x",
        type,
        0
    );

    // Third tier
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        0
    );

    // Fourth tier
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        0
    );

    corto_mount(this)->kind = CORTO_SINK;
    corto_mount(this)->mask = CORTO_ON_TREE;

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/SinkReplicator/onRequest) */
/* Custom release function */
static void test_SinkReplicator_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_SinkReplicator_onRequest(
    test_SinkReplicator this,
    corto_request *request)
{
/* $begin(test/SinkReplicator/onRequest) */
    corto_iter iter = corto_llIter(this->items);
    corto_ll data = corto_llNew();

    /* Filter items by parent */
    corto_resultIterForeach(iter, e) {
        if (!fnmatch(request->parent, e.parent, 0)) {
            if (!fnmatch(request->expr, e.id, 0)) {
                corto_resultSet(
                    corto_resultListAppendAlloc(data),
                    e.id,
                    e.id,
                    ".",
                    e.type,
                    0
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_SinkReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
/* $end */
}
