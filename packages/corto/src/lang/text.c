/* $CORTO_GENERATED
 *
 * text.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_text_init(
    corto_text this)
{
/* $begin(corto/lang/text/init) */
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_primitive(this)->kind = CORTO_TEXT;
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
