/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include "enum.h"
#include "bitmask.h"

int16_t corto_constant_init(
    int32_t* this)
{
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
    return -1;}

