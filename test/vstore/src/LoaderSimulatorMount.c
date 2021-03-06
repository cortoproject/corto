/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_LoaderSimulatorMount_construct(
    test_LoaderSimulatorMount this)
{
    corto_set_str(&corto_subscriber(this)->query.select, "//*");
    corto_set_str(&corto_subscriber(this)->query.from, "/");
    corto_set_str(&corto_subscriber(this)->query.type, "package");
    corto_set_str(&corto_subscriber(this)->format, "text/json");

    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
    corto_mount(this)->filter_records = false;

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "corto",
        NULL,
        ".",
        "package",
        0,
        CORTO_RECORD_HIDDEN
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "p",
        NULL,
        ".",
        "package",
        0,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "q",
        NULL,
        "p",
        "package",
        0,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "s",
        NULL,
        "p/q",
        "package",
        0,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "r",
        NULL,
        "corto",
        "package",
        0,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "u",
        NULL,
        "corto/r",
        "package",
        0,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
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
static void test_LoaderSimulatorMount_iterRelease(ut_iter *iter) {
    ut_ll_iter_s *data = iter->ctx;
    corto_recordList__clear(data->list);
    ut_ll_free(data->list);
    ut_ll_iterRelease(iter);
}

corto_recordIter test_LoaderSimulatorMount_on_query(
    test_LoaderSimulatorMount this,
    corto_query *query)
{
    ut_iter iter = ut_ll_iter(this->items);
    ut_ll data = ut_ll_new();

    /* Filter items by parent */
    corto_recordIter__foreach(iter, e) {
        if (!fnmatch(query->from, e.parent, 0)) {
            if (!fnmatch(query->select, e.id, 0)) {
                corto_record__assign(
                    corto_recordList__append_alloc(data),
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
    ut_iter result = ut_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_LoaderSimulatorMount_iterRelease;

    this->queryCount ++;

    /* Return persistent iterator to request */
    return result;
}
