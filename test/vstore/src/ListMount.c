/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


#include "fnmatch.h"

int16_t test_ListMount_construct(
    test_ListMount this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }
    
    corto_mount(this)->ownership = this->kind;

    /* Create top level objects */
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "x",
        NULL,
        ".",
        "uint32",
        0,
        0
    );
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "yz",
        NULL,
        ".",
        "string",
        0,
        0
    );
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "xyz",
        NULL,
        ".",
        "float64",
        0,
        0
    );

    /* Create nested objects */
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "a",
        NULL,
        "x",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "b",
        NULL,
        "x",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "c",
        NULL,
        "x",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "a",
        NULL,
        "xyz",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "abc",
        NULL,
        "xyz",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "bc",
        NULL,
        "xyz",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "foo",
        NULL,
        "xyz/abc",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "bar",
        NULL,
        "xyz/abc",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "hello",
        NULL,
        "xyz/abc/foo",
        "uint32",
        0,
        0
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "world",
        NULL,
        "xyz/abc/foo",
        "uint32",
        0,
        0
    );

    corto_mount_set_format(this, "text/json");

    return corto_mount_construct(this);
}


/* Custom release function */
void test_ListMount_iterRelease(ut_iter *iter) {
    ut_ll_iter_s *data = iter->ctx;
    corto_recordList__clear(data->list);
    ut_ll_free(data->list);
    ut_ll_iterRelease(iter);
}

corto_recordIter test_ListMount_on_query(
    test_ListMount this,
    corto_query *query)
{
    ut_iter iter = ut_ll_iter(this->items);
    ut_ll data = ut_ll_new();

    /* Filter items by parent */
    corto_recordIter__foreach(iter, e) {
        if (ut_expr(query->from, e.parent)) {
            if (ut_expr(query->select, e.id)) {
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
    result.release = test_ListMount_iterRelease;

    /* Return persistent iterator to request */
    return result;

}
