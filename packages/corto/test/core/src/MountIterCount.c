/* $CORTO_GENERATED
 *
 * MountIterCount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header(test/MountIterCount/onRequest) */
int test_MounterIterCount_hasNext(corto_iter *it) {
    test_MountIterCount this = it->udata;
    this->hasNextCount ++;
    return this->hasNextCount <= 10;
}
void* test_MounterIterCount_next(corto_iter *it) {
    test_MountIterCount this = it->udata;
    this->nextCount ++;
    this->result.id = this->id;
    this->result.leaf = TRUE;
    this->id[0] ++;
    return &this->result;
}
void test_MounterIterCount_release(corto_iter *it) {
    test_MountIterCount this = it->udata;
    this->releaseCount ++;
}
/* $end */
corto_resultIter _test_MountIterCount_onRequest(
    test_MountIterCount this,
    corto_request *request)
{
/* $begin(test/MountIterCount/onRequest) */
    corto_iter it = CORTO_ITER_EMPTY;

    if (!strcmp(request->expr, "*")) {
        it.udata = this;
        it.next = test_MounterIterCount_next;
        it.hasNext = test_MounterIterCount_hasNext;
        it.release = test_MounterIterCount_release;

        this->result.id = "foo";
        this->result.parent = "/bar";
        this->result.parent = "/hello/world";
        corto_ptr_setstr(&this->id, "a");
    }

    return it;
/* $end */
}
