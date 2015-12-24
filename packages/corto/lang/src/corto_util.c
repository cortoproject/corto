#include "corto.h"

extern corto_threadKey CORTO_KEY_THREAD_STRING;

typedef struct corto_threadString_t {
    corto_string strings[CORTO_MAX_TLS_STRINGS];
    corto_int32 max[CORTO_MAX_TLS_STRINGS];
    corto_uint8 current;
} corto_threadString_t;

corto_string corto_pathFromFullname(corto_id buffer) {
    char *ptr = buffer, *bptr, ch;
    bptr = ptr;

    for (; (ch = *ptr); ptr++, bptr++) {
        if (ch == ':') {
            *bptr = '/';
            ptr++;
        } else {
            *bptr = ch;
        }
    }

    *bptr = '\0';

    return buffer;
}

corto_string corto_nameFromFullname(corto_id buffer) {
    char *ptr = buffer, *name = buffer, ch;

    for (; (ch = *ptr); ptr++) {
        if (ch == ':') {
            ptr ++;
            name = ptr + 1;
        } else if (ch == '/') {
            name = ptr + 1;
        }
    }

    memmove(buffer, name, strlen(name) + 1);

    return buffer;
}

/* Set intern TLS string */
corto_string corto_setThreadString(corto_string string) {
    corto_threadString_t *data = corto_threadTlsGet(CORTO_KEY_THREAD_STRING);
    corto_int32 len = strlen(string);
    corto_int32 max = 0;

    if (!data) {
        data = corto_calloc(sizeof(corto_threadString_t));
        corto_threadTlsSet(CORTO_KEY_THREAD_STRING, data);
    }

    /* Select next string */
    data->current = data->current % CORTO_MAX_TLS_STRINGS;
    max = data->max[data->current];

    if (data->strings[data->current] &&
       ((max < len) || (max > CORTO_MAX_TLS_STRINGS_MAX))) {
        corto_dealloc(data->strings[data->current]);
        data->strings[data->current] = corto_strdup(string);
        data->max[data->current] = len;
    } else {
        if (data->strings[data->current]) {
            strcpy(data->strings[data->current], string);
        } else {
            data->strings[data->current] = corto_strdup(string);
            data->max[data->current] = len;
        }
    }

    return data->strings[data->current];
}

/* Clean TLS string data */
void corto_threadStringDealloc(void *tdata) {
    corto_threadString_t *data = tdata;

    if (data) {
        corto_int32 i;
        for (i = 0; i < CORTO_MAX_TLS_STRINGS_MAX; i++) {
            if (data->strings[i]) {
                corto_dealloc(data->strings[i]);
            }
        }
    }

    corto_dealloc(data);
}

/* Check whether object is a builtin package */
corto_bool corto_isBuiltinPackage(corto_object o) {
    return (o == corto_o) ||
           (o == corto_lang_o) ||
           (o == corto_core_o);
}
