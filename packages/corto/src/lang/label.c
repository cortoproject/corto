/* $CORTO_GENERATED
 *
 * label.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_label_construct(
    corto_label this)
{
/* $begin(corto/lang/label/construct) */

    /* Add single label to case */
    corto_int32seqAppend(&corto_case(this)->discriminator, this->discriminator);

    return corto_case_construct(this);

/* $end */
}
