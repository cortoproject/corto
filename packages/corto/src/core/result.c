/* $CORTO_GENERATED
 *
 * result.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"
/* $end */

corto_string _corto_result_contentof(
    corto_result* this,
    corto_string contentType)
{
/* $begin(corto/core/result/contentof) */
    corto_string result = NULL;

    corto_contentType type = corto_loadContentType(contentType);
    if (!type) {
        goto error;
    }

    if (!(result = (corto_string)type->fromResult(this))) {
        goto error;
    }

    return 0;
error:
    return NULL;
/* $end */
}

corto_int16 _corto_result_fromcontent(
    corto_result* this,
    corto_string contentType,
    corto_string content)
{
/* $begin(corto/core/result/fromcontent) */
    corto_contentType type = corto_loadContentType(contentType);
    if (!type) {
        goto error;
    }

    if (type->toResult(this, (corto_word)content)) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_string _corto_result_getText(
    corto_result* this)
{
/* $begin(corto/core/result/getText) */

    return (corto_string)this->value;

/* $end */
}
