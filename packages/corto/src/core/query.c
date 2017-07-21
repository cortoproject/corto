/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

uint32_t corto_query_cardinality(
    corto_query* this)
{
    if (!strchr(this->select, '*') || strstr(this->select, "//")) {
        return -1;
    } else {
        return 1;
    }
}

