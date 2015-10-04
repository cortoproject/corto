#include "_md_appendstr.h"

/* data->buffer was renamed to data->text */
cx_bool md_appendstrbuff(md_Doc data, char* str) {
    if (!data->ptr) {
        data->ptr = (cx_word)data->text;
    }
    if (!data->ptr) {
        data->text = cx_strdup(str);
        data->ptr = (cx_word)data->text;
    } else {
        cx_uint32 length, bufferLength;
        if (!data->length) {
            data->text = cx_realloc(data->text, strlen(data->text) + strlen(str) + 1);
            data->ptr = (cx_word)data->text;
        }
        length = strlen(str);
        bufferLength = strlen(data->text);

        if (data->maxlength && ((bufferLength + length) >= data->maxlength)) {
            strncat((char*)data->ptr, str, data->maxlength - bufferLength);
            goto maxreached;
        } else {
            strcat((char*)data->ptr, str);
        }
    }

    return TRUE;
maxreached:
    return FALSE;
}

/* Append string to serializer-result */
cx_bool md_appendstr(cx_object _data, cx_string fmt, ...) {
    md_Doc data = md_Doc(_data);
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    cx_uint32 memRequired;
    cx_uint32 result = TRUE;
    if (data) {
        va_list argcpy;
        va_copy(argcpy, args);
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = cx_alloc(memRequired + 1);
            vsprintf(buff, fmt, argcpy);
        }
        va_end(args);
        result = md_appendstrbuff(data, buff);
        if (buff != alloc) {
            cx_dealloc(buff);
        }
    }

    return result;
}
