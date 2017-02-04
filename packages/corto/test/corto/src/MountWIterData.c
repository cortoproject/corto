/* $CORTO_GENERATED
 *
 * MountWIterData.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header(test/MountWIterData/onRequest) */
void *iterNext(corto_iter *iter)
{
    return NULL;
}

int iterHasNext(corto_iter *iter)
{
    return 0;
}
/* $end */
corto_resultIter _test_MountWIterData_onRequest(
    test_MountWIterData this,
    corto_request *request)
{
/* $begin(test/MountWIterData/onRequest) */
    corto_resultIter result;

    result.udata = corto_calloc(sizeof(char));
    result.hasNext = iterHasNext;
    result.next = iterNext;
    result.release = NULL;

    return result;
/* $end */
}
