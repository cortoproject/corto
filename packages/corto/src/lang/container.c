/* $CORTO_GENERATED
 *
 * container.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_container_construct(
    corto_container this)
{
/* $begin(corto/lang/container/construct) */

    /* Containers are always scoped */
    corto_type(this)->attr = CORTO_ATTR_DEFAULT|CORTO_ATTR_NAMED;

    return corto_class_construct(this);
/* $end */
}
