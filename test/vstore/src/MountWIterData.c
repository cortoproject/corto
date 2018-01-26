/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

static
void *iterNext(
    corto_iter *iter)
{
    return NULL;
}

static
bool iterHasNext(
    corto_iter *iter)
{
    return 0;
}

corto_resultIter test_MountWIterData_on_query(
    test_MountWIterData this,
    corto_query *query)
{
    corto_resultIter result;

    result.ctx = corto_calloc(sizeof(char));
    result.hasNext = iterHasNext;
    result.next = iterNext;
    result.release = NULL;

    return result;
}
