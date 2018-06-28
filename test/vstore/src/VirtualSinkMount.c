/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_VirtualSinkMount_construct(
    test_VirtualSinkMount this)
{
    char *type = "int32";

    corto_set_str(&corto_subscriber(this)->query.select, "//");
    corto_set_str(&corto_subscriber(this)->query.from, this->from);
    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;

    // First tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "x",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "y",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "z",
        NULL,
        ".",
        type,
        0,
        FALSE
    );

    // Second tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "a",
        NULL,
        "x",
        "float32", /* Test resuming multiple objects of different type */
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "b",
        NULL,
        "x",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "c",
        NULL,
        "x",
        type,
        0,
        FALSE
    );

    // Third tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        0,
        FALSE
    );

    // Fourth tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        0,
        FALSE
    );

    return corto_mount_construct(this);
}


/* Custom release function */
static void test_VirtualSinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultList__clear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_VirtualSinkMount_on_query(
    test_VirtualSinkMount this,
    corto_query *query)
{
    corto_iter iter = corto_ll_iter(this->items);
    corto_ll data = corto_ll_new();

    /* Filter items by parent */
    corto_resultIter__foreach(iter, e) {
        if (!fnmatch(query->from, e.parent, 0)) {
            if (!fnmatch(query->select, e.id, 0)) {
                corto_result__assign(
                    corto_resultList__append_alloc(data),
                    e.id,
                    e.id,
                    e.parent,
                    e.type,
                    0,
                    e.flags
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
}
