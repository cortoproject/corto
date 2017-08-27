/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "corto/corto.h"

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
    data->current = (data->current + 1) % CORTO_MAX_TLS_STRINGS;
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
        for (i = 0; i < CORTO_MAX_TLS_STRINGS; i++) {
            if (data->strings[i]) {
                corto_dealloc(data->strings[i]);
            }
        }
    }

    corto_dealloc(data);
}

/* Check whether object is a builtin package */
corto_bool corto_isBuiltinPackage(corto_object o) {
    return (o == root_o) ||
           (o == corto_o) ||
           (o == corto_lang_o) ||
           (o == corto_core_o) ||
           (o == corto_native_o) ||
           (o == corto_secure_o);
}

void* corto_getMemberPtr(corto_object o, void *ptr, corto_member m) {
    void *result;

    if (!ptr) {
        return NULL;
    }

    result = CORTO_OFFSET(ptr, m->offset);

    /* If member is of target type, it represents either a target or actual
     * value. Actual members can only be set if the object is owned by thread
     * that deserializes the value. Target members can only be set if the thread
     * does not own the object. */
    if (corto_typeof(corto_parentof(m)) == (corto_type)corto_target_o) {
        corto_bool owned = corto_owned(ptr);
        corto_bool isActual = strcmp("target", corto_idof(m));
        if ((owned && !isActual) || (!owned && isActual)) {
            result = NULL;
        }
    } else if (o && !corto_owned(o)) {
        /* If type is composite, continue serializing as structure may contain
         * members of target types */
        if (m->type->kind != CORTO_COMPOSITE) {
            result = NULL;
        }
    }

    if (result && (m->modifiers & CORTO_OBSERVABLE)) {
        result = *(void**)result;
    }

    return result;
}

#if 0
struct corto_benchmark {
    corto_string name;
    corto_time start;
    double total;
    int count;
};
static struct corto_benchmark corto_benchmarks[CORTO_MAX_BENCHMARK];
static int corto_benchmark_count;

int corto_benchmark_init(corto_string name) {
    int id = corto_ainc(&corto_benchmark_count);
    corto_benchmarks[id].name = name;
    corto_benchmarks[id].total = 0;
    return id;
}

void corto_benchmark_stop(int id) {
    corto_time stop;
    corto_timeGet(&stop);
    corto_benchmarks[id].total += corto_timeToDouble(corto_timeSub(stop, corto_benchmarks[id].start));
    corto_benchmarks[id].count ++;
}

void corto_benchmark_start(int id) {
    corto_timeGet(&corto_benchmarks[id].start);
}

double corto_benchmark_fini(int id) {
    double result = corto_benchmarks[id].total;
    fprintf(stderr, "%24s: %fs (called %d times)\n", corto_benchmarks[id].name, result, corto_benchmarks[id].count);
    return result;
}
#endif
