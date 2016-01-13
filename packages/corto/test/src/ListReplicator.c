/* $CORTO_GENERATED
 *
 * ListReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

/* $header() */
#include "fnmatch.h"
/* $end */

corto_int16 _test_ListReplicator_construct(test_ListReplicator this) {
/* $begin(test/ListReplicator/construct) */

    /* Create top level objects */
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "x",
        ".",
        "/foo",
        0
    );
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "yz",
        ".",
        "/bar",
        0
    );
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "xyz",
        ".",
        "/panda",
        0
    );

    /* Creat nested objects */
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "a",
        "x",
        "/type",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "b",
        "x",
        "/type",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "c",
        "x",
        "/type",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "a",
        "xyz",
        "/type",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "abc",
        "xyz",
        "/type",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "bc",
        "xyz",
        "/type",
        0
    );

    return corto_replicator_construct(this);
/* $end */
}

/* $header(test/ListReplicator/onRequest) */
/* Custom release function */
void test_ListReplicator_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_ListReplicator_onRequest(test_ListReplicator this, corto_string parent, corto_string expr, corto_string param, corto_bool setContent) {
/* $begin(test/ListReplicator/onRequest) */
    corto_iter iter = corto_llIter(this->items);
    corto_ll data = corto_llNew();

    /* Filter items by parent */
    corto_resultIterForeach(iter, e) {
        if (!fnmatch(parent, e.parent, 0)) {
            corto_resultSet(
                corto_resultListAppendAlloc(data),
                e.name,
                e.parent,
                e.type,
                0
            );
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_ListReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;

/* $end */
}
