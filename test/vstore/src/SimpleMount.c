/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_resultIter test_SimpleMount_onQuery(
    test_SimpleMount this,
    corto_query *query)
{
    corto_result r = (corto_result) {
        .id = "foo",
        .parent = ".",
        .type = "int32",
        .flags = CORTO_RESULT_LEAF,
        .value = (corto_word)"10"
    };

    corto_mount_return(this, &r);

    return CORTO_ITER_EMPTY;
}
