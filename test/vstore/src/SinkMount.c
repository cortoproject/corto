/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_SinkMount_construct(
    test_SinkMount this)
{

    corto_ptr_setstr(&corto_subscriber(this)->query.type, this->type);
    corto_string type =
      this->type ? this->type : "int32";

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

    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
    corto_observer(this)->mask = CORTO_ON_TREE;

    return corto_mount_construct(this);
}


/* Custom release function */
static void test_SinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultListClear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_SinkMount_onQuery(
    test_SinkMount this,
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
    result.release = test_SinkMount_iterRelease;

    /* Return persistent iterator to request */
    return result;
}

corto_object test_SinkMount_onResume(
    test_SinkMount this,
    corto_string parent,
    corto_string id,
    corto_object object)
{
    corto_iter iter = corto_ll_iter(this->items);
    corto_object result = NULL;

    /* Find object. Do proper error handling, so testcases are easy to debug */
    corto_resultIterForeach(iter, e) {
        if (!strcmp(parent, e.parent)) {
            if (!strcmp(id, e.id)) {
                corto_type t = corto_resolve(NULL, e.type);
                if (!t) {
                    corto_throw("cannot resume object, unknown type '%s'",
                      e.type);
                    goto error;
                }

                if (object && (t != corto_typeof(object))) {
                    corto_throw("type '%s' does not match type of object '%s'",
                      e.type, corto_fullpath(NULL, corto_typeof(object)));
                }

                corto_object p = corto_lookup(
                    corto_mount(this)->mount,
                    e.parent
                );
                if (!p) {
                    corto_throw("cannot find parent '%s'", e.parent);
                    goto error;
                }

                if (object && (p != corto_parentof(object))) {
                    corto_throw("parent '%s' does not match parent of object '%s'",
                      e.type, corto_fullpath(NULL, corto_parentof(object)));
                    goto error;
                }

                if (object) {
                    result = object;
                } else {
                    result = corto_declare(p, e.id, t);
                    if (!result) {
                        corto_throw("cannot create object '%s': %s",
                            e.id, corto_lasterr());
                        goto error;
                    }
                }

                if (e.value) {
                    corto_fromStr(&result, (corto_string)e.value);
                }

                if (!object) {
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
}
