
#include "corto/corto.h"

static corto_bool corto_buffer_appendIntern(
    corto_buffer *b,
    char* str)
{
    if (!b->str) {
        b->str = corto_strdup(str);
    } else {
        corto_uint32 length, bufferLength;

        if (!b->len) {
            b->str = corto_realloc(b->str, strlen(b->str) + strlen(str) + 1);
        }

        length = strlen(str);
        bufferLength = strlen(b->str);

        if (b->max && ((bufferLength + length) >= b->len)) {
            strncat(b->str, str, b->max - bufferLength);
            goto maxreached;
        } else {
            strcat(b->str, str);
        }
    }

    return TRUE;
maxreached:
    return FALSE;
}

corto_bool corto_buffer_append(
    corto_buffer *buffer,
    corto_string fmt,
    ...)
{
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    corto_uint32 memRequired;
    corto_bool result = TRUE;

    va_list argcpy;
    va_copy(argcpy, args);
    va_start(args, fmt);
    memRequired = vsnprintf(buff, 1024, fmt, args);
    if (memRequired >= 1024) {
        buff = corto_alloc(memRequired + 1);
        vsprintf(buff, fmt, argcpy);
    }
    va_end(args);
    result = corto_buffer_appendIntern(buffer, buff);
    if (buff != alloc) {
        corto_dealloc(buff);
    }

    return result;

}
