/* $CORTO_GENERATED
 *
 * verbatim.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_verbatim_init(
    corto_verbatim this)
{
/* $begin(corto/lang/verbatim/init) */
    corto_type(this)->hasResources = TRUE;
    corto_primitive(this)->kind = CORTO_TEXT;
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
