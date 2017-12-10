/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_string test_Point_nameof(
    test_Point* this)
{
    corto_string name;

    name = corto_asprintf("%d,%d", this->x, this->y);

    return name;
}

