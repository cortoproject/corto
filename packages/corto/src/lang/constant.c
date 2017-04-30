/* $CORTO_GENERATED
 *
 * constant.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

/* $header() */
#include "_enum.h"
#include "_bitmask.h"
/* $end */

int16_t _corto_constant_init(
    int32_t* this)
{
/* $begin(corto/lang/constant/init) */
    corto_object parent;
    corto_type parentType;

    parent = corto_parentof(this);
    parentType = corto_typeof(parent);

    /* Parent must be an enum */
    if ((parentType == corto_type(corto_bitmask_o)) ||
        corto_instanceof(corto_bitmask_o, parent))
    {
        corto__bitmask_bindConstant(parent, this);
    }
    else if ((parentType == corto_type(corto_enum_o)) ||
        corto_instanceof(corto_enum_o, parent))
    {
        corto__enum_bindConstant(parent, this);
    }
    else
    {
        corto_seterr("constant/init: parent of constant '%s' is not an enum.",
            corto_fullpath(NULL, this));
        goto error;
    }

    return 0;
error:
    return -1;/* $end */
}
