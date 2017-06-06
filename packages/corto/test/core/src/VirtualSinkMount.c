/* $CORTO_GENERATED
 *
 * VirtualSinkMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_VirtualSinkMount_construct(
    test_VirtualSinkMount this)
{
/* $begin(test/VirtualSinkMount/construct) */
    char *type = "int32";

    corto_ptr_setstr(&corto_subscriber(this)->query.select, "//");
    corto_ptr_setstr(&corto_subscriber(this)->query.from, this->from);
    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;

    // First tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "x",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "y",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "z",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    // Second tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "x",
        "float32", /* Test resuming multiple objects of different type */
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "b",
        NULL,
        "x",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "c",
        NULL,
        "x",
        type,
        0,
        FALSE
    );

    // Third tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    // Fourth tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/VirtualSinkMount/onQuery) */
/* Custom release function */
static void test_VirtualSinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}
/* $end */
corto_resultIter _test_VirtualSinkMount_onQuery(
    test_VirtualSinkMount this,
    corto_query *query)
{
/* $begin(test/VirtualSinkMount/onQuery) */
    corto_iter iter = corto_ll_iter(this->items);
    corto_ll data = corto_ll_new();

    /* Filter items by parent */
    corto_resultIterForeach(iter, e) {
        if (!fnmatch(query->from, e.parent, 0)) {
            if (!fnmatch(query->select, e.id, 0)) {
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
    result.release = test_VirtualSinkMount_iterRelease;

    this->count ++;

    /* Return persistent iterator to request */
    return result;
/* $end */
}
