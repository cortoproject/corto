/* $CORTO_GENERATED
 *
 * metaprocedure.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
corto_int16 corto_type_bindMetaprocedure(
    corto_type this,
    corto_metaprocedure procedure);
/* $end */

corto_int16 _corto_metaprocedure_construct(
    corto_metaprocedure this)
{
/* $begin(corto/lang/metaprocedure/construct) */
    corto_object parent;

    parent = corto_parentof(this);
    if (corto_instanceof(corto_type(corto_type_o), parent)) {
        if (corto_type_bindMetaprocedure(corto_type(parent), this)) {
            goto error;
        }
    } else {
        corto_seterr("invalid declaration of '%s' in non-type scope '%s'",
            corto_fullpath(NULL, this), corto_fullpath(NULL, parent));
        goto error;
    }

    return corto_function_construct(corto_function(this));
error:
    return -1;
/* $end */
}
