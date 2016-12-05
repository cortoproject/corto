/* $CORTO_GENERATED
 *
 * SinkReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_SinkReplicator_construct(
    test_SinkReplicator this)
{
/* $begin(test/SinkReplicator/construct) */
    corto_string type =
      corto_observer(this)->type ? corto_observer(this)->type : "int32";

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

/* $header(test/SinkReplicator/onRequest) */
/* Custom release function */
static void test_SinkReplicator_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
}
/* $end */
corto_resultIter _test_SinkReplicator_onRequest(
    test_SinkReplicator this,
    corto_request *request)
{
/* $begin(test/SinkReplicator/onRequest) */
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
                    0,
                    e.leaf
                );
            }
        }
    }

    /* Create persistent iterator */
    corto_iter result = corto_llIterAlloc(data);

    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_SinkReplicator_iterRelease;

    /* Return persistent iterator to request */
    return result;
/* $end */
}

corto_object _test_SinkReplicator_onResume(
    test_SinkReplicator this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(test/SinkReplicator/onResume) */
    corto_iter iter = corto_llIter(this->items);
    corto_object result = NULL;

    /* Find object. Do proper error handling, so testcases are easy to debug */
    corto_resultIterForeach(iter, e) {
        if (!strcmp(parent, e.parent)) {
            if (!strcmp(name, e.id)) {
                corto_type t = corto_resolve(NULL, e.type);
                if (!t) {
                    corto_seterr("cannot resume object, unknown type '%s'",
                      e.type);
                    goto error;
                }

                if (o && (t != corto_typeof(o))) {
                    corto_seterr("type '%s' does not match type of object '%s'",
                      e.type, corto_fullpath(NULL, corto_typeof(o)));
                }

                corto_object p = corto_resolve(
                    corto_mount(this)->mount,
                    e.parent
                );
                if (!p) {
                    corto_seterr("cannot find parent '%s'", e.parent);
                    goto error;
                }

                if (o && (p != corto_parentof(o))) {
                    corto_seterr("parent '%s' does not match parent of object '%s'",
                      e.type, corto_fullpath(NULL, corto_parentof(o)));
                    goto error;
                }

                if (o) {
                    result = o;
                } else {
                    result = corto_declareChild(p, e.id, t);
                    if (!result) {
                        corto_seterr("cannot create object '%s': %s",
                            e.id, corto_lasterr());
                        goto error;
                    }
                }

                if (e.value) {
                    corto_fromStr(&result, (corto_string)e.value);
                }

                if (!o) {
                    corto_define(result);
                }

                corto_release(t);
                corto_release(p);
            }
        }
    }

    return result;
error:
    return NULL;
/* $end */
}
