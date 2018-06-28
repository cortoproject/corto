/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

static
bool test_MounterIterCount_hasNext(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->hasNextCount ++;
    return this->hasNextCount <= 10;
}

static
void* test_MounterIterCount_next(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->nextCount ++;
    this->result.id = this->id;
    this->result.flags = CORTO_RESULT_LEAF;
    this->id[0] ++;
    return &this->result;
}

static
void test_MounterIterCount_release(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->releaseCount ++;
}

corto_resultIter test_MountIterCount_on_query(
    test_MountIterCount this,
    corto_query *query)
{
    corto_iter it = CORTO_ITER_EMPTY;

    if (!strcmp(query->select, "*")) {
        it.ctx = this;
        it.next = test_MounterIterCount_next;
        it.hasNext = test_MounterIterCount_hasNext;
        it.release = test_MounterIterCount_release;

        this->result.id = "foo";
        this->result.parent = "/hello/world";
        this->result.type = "void";
        corto_set_str(&this->id, "a");
    }

    return it;
}

int16_t test_MountIterCount_construct(
    test_MountIterCount this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (!this->mount && corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_set_ref(&this->mount, this);
    }
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_mount(this)->filter_results = false;

    return corto_super_construct(this);
}
