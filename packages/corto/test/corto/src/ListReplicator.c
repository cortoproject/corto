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

corto_int16 _test_ListReplicator_construct(
    test_ListReplicator this)
{
/* $begin(test/ListReplicator/construct) */

    /* Create top level objects */
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "x",
        NULL,
        ".",
        "uint32",
        0
    );
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "yz",
        NULL,
        ".",
        "string",
        0
    );
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "xyz",
        NULL,
        ".",
        "float64",
        0
    );

    /* Create nested objects */
    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "x",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "b",
        NULL,
        "x",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "c",
        NULL,
        "x",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "xyz",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "abc",
        NULL,
        "xyz",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "bc",
        NULL,
        "xyz",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "foo",
        NULL,
        "xyz/abc",
        "uint32",
        0
    );

    corto_resultSet(
        corto_resultListAppendAlloc(this->items),
        "bar",
        NULL,
        "xyz/abc",
        "uint32",
        0
    );

    corto_mount_setContentType(this, "text/json");

    return corto_mount_construct(this);
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
corto_resultIter _test_ListReplicator_onRequest(
    test_ListReplicator this,
    corto_request *request)
{
/* $begin(test/ListReplicator/onRequest) */
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
    result.release = test_ListReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;

/* $end */
}
