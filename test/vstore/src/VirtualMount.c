/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_VirtualMount_construct(
    test_VirtualMount this)
{

    corto_set_str(&corto_subscriber(this)->query.from, this->mount);

    /* Data served up by the mount is in the corto string format */
    corto_mount_set_format(this, "text/corto");

    /* Populate the mount with some demo data */
    corto_record__assign(
        corto_recordList__append_alloc(this->data),
        "a",                        /* id */
        NULL,                       /* name */
        ".",                        /* parent */
        "int32",                    /* type */
        (corto_word)"10",           /* value */
        TRUE                        /* is node a leaf */
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->data),
        "b",                        /* id */
        NULL,                       /* name */
        ".",                        /* parent */
        "string",                   /* type */
        (corto_word)"Hello World",  /* value */
        TRUE                        /* is node a leaf */
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->data),
        "c",                        /* id */
        NULL,                       /* name */
        ".",                        /* parent */
        "float64",                  /* type */
        (corto_word)"10.5",         /* value */
        TRUE                        /* is node a leaf */
    );

    return corto_super_construct(this);
}

corto_recordIter test_VirtualMount_on_query(
    test_VirtualMount this,
    corto_query *query)
{
    if (!strcmp(query->from, ".")) {
        return ut_ll_iterAlloc(this->data);
    } else {
        return CORTO_ITER_EMPTY;
    }
}

