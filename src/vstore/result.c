/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "src/store/object.h"

corto_string corto_result_contentof(
    corto_result* this,
    const char *format)
{
    corto_string result = NULL;

    corto_fmt type = corto_fmt_lookup(format);
    if (!type) {
        goto error;
    }

    if (!(result = corto_fmt_from_result(type, NULL, this))) {
        goto error;
    }

    return 0;
error:
    return NULL;
}

int16_t corto_result_fromcontent(
    corto_result* this,
    const char *format,
    const char *content)
{
    corto_fmt type = corto_fmt_lookup(format);
    if (!type) {
        goto error;
    }

    if (corto_fmt_to_result(type, NULL, this, (void*)content)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_string corto_result_get_text(
    corto_result* this)
{
    return (corto_string)this->value;
}
