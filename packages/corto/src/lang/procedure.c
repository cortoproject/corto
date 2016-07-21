/* $CORTO_GENERATED
 *
 * procedure.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_procedure_init(
    corto_procedure this)
{
/* $begin(corto/lang/procedure/init) */

    if (corto_interface_init(corto_interface(this))) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_PROCEDURE;
    corto_type(this)->reference = TRUE;

    return 0;
error:
    return -1;
/* $end */
}
