/* $CORTO_GENERATED
 *
 * ListMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
#include "fnmatch.h"
/* $end */

int16_t _test_ListMount_construct(
    test_ListMount this)
{
/* $begin(test/ListMount/construct) */
    corto_mount(this)->policy.ownership = this->kind;

    /* Create top level objects */
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "x",
        NULL,
        ".",
        "uint32",
        0,
        FALSE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "yz",
        NULL,
        ".",
        "string",
        0,
        FALSE
    );
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "xyz",
        NULL,
        ".",
        "float64",
        0,
        FALSE
    );

    /* Create nested objects */
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "x",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "b",
        NULL,
        "x",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "c",
        NULL,
        "x",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "xyz",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "abc",
        NULL,
        "xyz",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "bc",
        NULL,
        "xyz",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "foo",
        NULL,
        "xyz/abc",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "bar",
        NULL,
        "xyz/abc",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "hello",
        NULL,
        "xyz/abc/foo",
        "uint32",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "world",
        NULL,
        "xyz/abc/foo",
        "uint32",
        0,
        FALSE
    );

    corto_mount_setContentType(this, "text/json");

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/ListMount/onQuery) */
/* Custom release function */
void test_ListMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}
/* $end */
corto_resultIter _test_ListMount_onQuery(
    test_ListMount this,
    corto_query *query)
{
/* $begin(test/ListMount/onQuery) */
    corto_iter iter = corto_ll_iter(this->items);
    corto_ll data = corto_ll_new();

    /* Filter items by parent */
    corto_resultIterForeach(iter, e) {
        if (corto_match(query->from, e.parent)) {
            if (corto_match(query->select, e.id)) {
                corto_resultAssign(
                    corto_resultListAppendAlloc(data),
                    e.id,
                    e.id,
                    e.parent,
                    e.type,
                    0,
                    e.leaf
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_ListMount_iterRelease;

    /* Return persistent iterator to request */
    return result;

/* $end */
}
