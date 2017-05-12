/* $CORTO_GENERATED
 *
 * table.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_table_construct(
    corto_table this)
{
/* $begin(corto/lang/table/construct) */

    corto_ptr_setref(&corto_type(this)->options.parentType, corto_tablescope_o);

    return corto_class_construct(this);
/* $end */
}
