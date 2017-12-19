/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_LoaderSimulatorMount_construct(
    test_LoaderSimulatorMount this)
{
    corto_ptr_setstr(&corto_subscriber(this)->query.select, "//*");
    corto_ptr_setstr(&corto_subscriber(this)->query.from, "/");
    corto_ptr_setstr(&corto_subscriber(this)->query.type, "package");
    corto_ptr_setstr(&corto_subscriber(this)->contentType, "text/json");

    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
    corto_mount(this)->policy.filterResults = false;

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "corto",
        NULL,
        ".",
        "package",
        0,
        CORTO_RESULT_HIDDEN
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "p",
        NULL,
        ".",
        "package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "q",
        NULL,
        "p",
        "package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "s",
        NULL,
        "p/q",
        "package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "r",
        NULL,
        "corto",
        "package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "u",
        NULL,
        "corto/r",
        "package",
        0,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "v",
        NULL,
        ".",
        "package",
        0,
        FALSE
    );

    return corto_mount_construct(this);
}

/* Custom release function */
static void test_LoaderSimulatorMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_LoaderSimulatorMount_onQuery(
    test_LoaderSimulatorMount this,
    corto_query *query)
{
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
                    e.flags
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_LoaderSimulatorMount_iterRelease;

    this->queryCount ++;

    /* Return persistent iterator to request */
    return result;
}
