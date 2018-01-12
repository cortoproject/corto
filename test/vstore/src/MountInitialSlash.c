/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_resultIter test_MountInitialSlash_onQuery(
    test_MountInitialSlash this,
    corto_query *query)
{
    corto_result r;

    if (!strcmp(query->from, ".")) {
        r = (corto_result){
            .id = "foo",
            .parent = "/",
            .type = "void"
        };
        corto_mount_return(this, &r);

    } else if (!strcmp(query->from, "foo")) {
        r = (corto_result){
            .id = "bar",
            .parent = "/foo",
            .type = "void"
        };
        corto_mount_return(this, &r);
    }

    return CORTO_ITER_EMPTY;
}
