/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_recordIter test_MountInitialSlash_on_query(
    test_MountInitialSlash this,
    corto_query *query)
{
    corto_record r;

    if (!strcmp(query->from, ".")) {
        r = (corto_record){
            .id = "foo",
            .parent = "/",
            .type = "void"
        };
        corto_mount_return(this, &r);

    } else if (!strcmp(query->from, "foo")) {
        r = (corto_record){
            .id = "bar",
            .parent = "/foo",
            .type = "void"
        };
        corto_mount_return(this, &r);
    }

    return CORTO_ITER_EMPTY;
}
