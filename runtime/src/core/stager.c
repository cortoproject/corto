/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_stager_add(
    corto_stager this,
    corto_string id,
    corto_string type,
    corto_string contentType,
    uintptr_t content,
    uint64_t childcount)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(id);
    CORTO_UNUSED(type);
    CORTO_UNUSED(contentType);
    CORTO_UNUSED(content);
    CORTO_UNUSED(childcount);
    return 0;
}

int16_t corto_stager_construct(
    corto_stager this)
{
    CORTO_UNUSED(this);
    return 0;
}

void corto_stager_destruct(
    corto_stager this)
{
    CORTO_UNUSED(this);
}

