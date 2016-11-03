/* $CORTO_GENERATED
 *
 * Point.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_string _test_Point_nameof(
    test_Point* this)
{
/* $begin(test/Point/nameof) */
    corto_string name;

    corto_asprintf(&name, "%d,%d", this->x, this->y);

    return name;
/* $end */
}
