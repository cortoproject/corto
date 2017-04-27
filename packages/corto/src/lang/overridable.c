/* $CORTO_GENERATED
 *
 * overridable.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

int16_t _corto_overridable_init(
    corto_overridable this)
{
/* $begin(corto/lang/overridable/init) */
    corto_function(this)->overridable = TRUE;
    return corto_method_init(corto_method(this));
/* $end */
}
