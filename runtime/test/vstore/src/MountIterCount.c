/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


int test_MounterIterCount_hasNext(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->hasNextCount ++;
    return this->hasNextCount <= 10;
}
void* test_MounterIterCount_next(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->nextCount ++;
    this->result.id = this->id;
    this->result.flags = CORTO_RESULT_LEAF;
    this->id[0] ++;
    return &this->result;
}
void test_MounterIterCount_release(corto_iter *it) {
    test_MountIterCount this = it->ctx;
    this->releaseCount ++;
}

corto_resultIter test_MountIterCount_onQuery(
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
        corto_ptr_setstr(&this->id, "a");
    }

    return it;
}

