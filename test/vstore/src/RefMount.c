/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_RefMount_construct(
    test_RefMount this)
{
    corto_set_str(&corto_subscriber(this)->query.select, "//");

    if (this->from) {
        corto_set_str(&corto_subscriber(this)->query.from, this->from);
    }

    if (corto_mount_setContentType(this, "text/json")) {
        goto error;
    }

    /* Let corto filter results for the mount */
    corto_mount(this)->policy.filterResults = true;

    /* Enable resuming objects by configuring mount as local source */
    corto_mount(this)->policy.ownership = CORTO_LOCAL_SOURCE;

    char *json =
        "{\"sibling\":\"/config\","
         "\"nested_sibling\":\"/config/helloworld\","
         "\"at_from\":\"foo\","
         "\"inside_from\":\"foo/bar\","
         "\"inside_from_nested1\":\"foo/bar/hello\","
         "\"inside_from_nested2\":\"foo/bar/hello/world\","
         "\"parent_from\":null,"
         "\"at_root\":\"/data\","
         "\"from\":\"/data\","
         "\"root\":\"/\","
         "\"null_ref\":null}";

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "refs",
        NULL,
        ".",
        "test/Refs",
        (uintptr_t)corto_strdup(json),
        0
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "foo",
        NULL,
        ".",
        "void",
        0,
        0
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "bar",
        NULL,
        "foo",
        "void",
        0,
        0
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "hello",
        NULL,
        "foo/bar",
        "void",
        0,
        0
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "world",
        NULL,
        "foo/bar/hello",
        "void",
        0,
        0
    );

    return corto_super_construct(this);
error:
    return -1;
}


void test_RefMount_on_notify(
    test_RefMount this,
    corto_subscriber_event *event)
{
    corto_set_str(&this->last_json, (char*)event->data.value);
}


corto_resultIter test_RefMount_on_query(
    test_RefMount this,
    corto_query *query)
{
    return corto_ll_iterAlloc(this->items);
}
