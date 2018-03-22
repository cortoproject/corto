/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
int16_t test_SinkMount_construct(
    test_SinkMount this)
{

    corto_set_str(&corto_subscriber(this)->query.type, this->type);
    corto_string type =
      this->type ? this->type : "int32";

    // First tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "x",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "y",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "z",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Second tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "a",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "b",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "c",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Third tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Fourth tier
    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_mount(this)->policy.ownership = CORTO_LOCAL_SOURCE;
    corto_observer(this)->mask = CORTO_ON_TREE;

    return corto_mount_construct(this);
}

/* Custom release function */
static void test_SinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_resultList__clear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_resultIter test_SinkMount_on_query(
    test_SinkMount this,
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
    result.release = test_SinkMount_iterRelease;
    /* Return persistent iterator to request */
    return result;
}

int16_t test_SinkMount_on_resume(
    test_SinkMount this,
    const char *parent,
    const char *id,
    corto_object *object)
{
    corto_iter iter = corto_ll_iter(this->items);
    corto_object result = NULL;
    corto_object o = *object;

    /* Find object. Do proper error handling, so testcases are easy to debug */
    corto_resultIter__foreach(iter, e) {
        if (!strcmp(parent, e.parent)) {
            if (!strcmp(id, e.id)) {
                corto_type t = corto_resolve(NULL, e.type);
                if (!t) {
                    corto_throw("cannot resume object, unknown type '%s'",
                      e.type);
                    goto error;
                }

                if (o && (t != corto_typeof(o))) {
                    corto_throw("type '%s' does not match type of object '%s'",
                      e.type, corto_fullpath(NULL, corto_typeof(o)));
                }

                corto_object p = corto_lookup(
                    corto_mount(this)->mount,
                    e.parent
                );
                if (!p) {
                    corto_throw("cannot find parent '%s'", e.parent);
                    goto error;
                }

                if (o && (p != corto_parentof(o))) {
                    corto_throw("parent '%s' does not match parent of object '%s'",
                      e.type, corto_fullpath(NULL, corto_parentof(o)));
                    goto error;
                }

                if (o) {
                    result = o;
                } else {
                    result = corto_declare(p, e.id, t);
                    if (!result) {
                        corto_throw("cannot create object '%s': %s",
                            e.id, corto_lasterr());
                        goto error;
                    }

                }

                if (e.value) {
                    corto_deserialize_value(result, "text/corto", (corto_string)e.value);
                }

                if (!o) {
                    corto_define(result);
                }

                corto_release(t);
                corto_release(p);
            }
        }
    }

    *object = result;

    return 0;
error:
    return -1;
}
