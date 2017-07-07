/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_AutoResumeSinkMount_construct(
    test_AutoResumeSinkMount this)
{
    corto_ptr_setstr(&corto_subscriber(this)->query.type, this->type);
    corto_string type =
      this->type ? this->type : "int32";

    corto_mount_setContentType(this, "text/corto");

    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
    corto_observer(this)->mask = CORTO_ON_TREE;

    // First tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "x",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "y",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "z",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Second tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "a",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "b",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "c",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Third tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Fourth tier
    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_resultAssign(
        corto_resultListAppendAlloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    return corto_mount_construct(this);
}


/* Custom release function */
static void test_SinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_AutoResumeSinkMount_onQuery(
    test_AutoResumeSinkMount this,
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
                    e.value,
                    e.leaf
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_SinkMount_iterRelease;

    /* Return persistent iterator to request */
    return result;
}

uintptr_t test_AutoResumeSinkMount_onSubscribe(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{

    /* Result is set to either this or 'expr' depending on the content of expr.
     * This allows the testcase to test both cases where onSubscribe returns the
     * same value of ctx, as well as cases where it doesn't */
    corto_word result = (corto_word)this;

    if (query->select[0] != '*') {
        result = rand();
    }

    corto_queryListAppend(
      this->subscribes,
      query
    );

    return result;
}

void test_AutoResumeSinkMount_onUnsubscribe(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{
    if (query->select[0] == '*') {
        test_assert(ctx == (corto_word)this);
    }

    corto_queryListAppend(
      this->unsubscribes,
      query
    );

}

