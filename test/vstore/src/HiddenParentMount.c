/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_HiddenParentMount_construct(
    test_HiddenParentMount this)
{
    /* Let corto filter results for the mount */
    corto_mount(this)->filter_records = true;

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "foo",
        NULL,
        ".",
        "int32",
        0,
        CORTO_RECORD_HIDDEN
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "bar",
        NULL,
        "foo",
        "void",
        0,
        CORTO_RECORD_LEAF
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "helloworld",
        NULL,
        ".",
        "unknown",
        0,
        CORTO_RECORD_LEAF | CORTO_RECORD_UNKNOWN
    );

    return corto_super_construct(this);
}

corto_recordIter test_HiddenParentMount_on_query(
    test_HiddenParentMount this,
    corto_query *query)
{
    this->on_query_count ++;
    return ut_ll_iterAlloc(this->items);
}
