/* $CORTO_GENERATED
 *
 * AutoResumeSinkMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_AutoResumeSinkMount_construct(
    test_AutoResumeSinkMount this)
{
/* $begin(test/AutoResumeSinkMount/construct) */
    corto_string type =
      corto_observer(this)->type ? corto_observer(this)->type : "int32";

    corto_mount_setContentType(this, "text/corto");

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

    corto_mount(this)->kind = CORTO_SINK;
    corto_observer(this)->mask = CORTO_ON_TREE;

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/AutoResumeSinkMount/onRequest) */
/* Custom release function */
static void test_SinkMount_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_AutoResumeSinkMount_onRequest(
    test_AutoResumeSinkMount this,
    corto_request *request)
{
/* $begin(test/AutoResumeSinkMount/onRequest) */
    corto_iter iter = corto_llIter(this->items);
    corto_ll data = corto_llNew();

    /* Filter items by parent */
    corto_resultIterForeach(iter, e) {
        if (!fnmatch(request->parent, e.parent, 0)) {
            if (!fnmatch(request->expr, e.id, 0)) {
                corto_resultAssign(
                    corto_resultListAppendAlloc(data),
                    e.id,
                    e.id,
                    ".",
                    e.type,
                    e.value,
                    e.leaf
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_SinkMount_iterRelease;

    /* Return persistent iterator to request */
    return result;
/* $end */
}

uintptr_t _test_AutoResumeSinkMount_onSubscribe(
    test_AutoResumeSinkMount this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx)
{
/* $begin(test/AutoResumeSinkMount/onSubscribe) */
    corto_request r = {.parent = parent, .expr = expr};

    /* Result is set to either this or 'expr' depending on the content of expr.
     * This allows the testcase to test both cases where onSubscribe returns the
     * same value of ctx, as well as cases where it doesn't */
    corto_word result = (corto_word)this;

    if (expr[0] != '*') {
        result = rand();
    }

    corto_requestListAppend(
      this->subscribes,
      &r
    );

    return result;
/* $end */
}

void _test_AutoResumeSinkMount_onUnsubscribe(
    test_AutoResumeSinkMount this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx)
{
/* $begin(test/AutoResumeSinkMount/onUnsubscribe) */
    corto_request r = {.parent = parent, .expr = expr};

    if (expr[0] == '*') {
        test_assert(ctx == (corto_word)this);
    }

    corto_requestListAppend(
      this->unsubscribes,
      &r
    );

/* $end */
}
