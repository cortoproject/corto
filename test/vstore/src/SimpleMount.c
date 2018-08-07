/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_recordIter test_SimpleMount_on_query(
    test_SimpleMount this,
    corto_query *query)
{
    corto_record r = (corto_record) {
        .id = "foo",
        .parent = ".",
        .type = "int32",
        .flags = CORTO_RESULT_LEAF,
        .value = (corto_word)"10"
    };

    corto_mount_return(this, &r);

    return CORTO_ITER_EMPTY;
}
