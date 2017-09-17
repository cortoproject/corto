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

#include <include/base.h>

extern corto_tls CORTO_KEY_THREAD_STRING;

typedef struct corto_threadString_t {
    char* strings[CORTO_MAX_TLS_STRINGS];
    int32_t max[CORTO_MAX_TLS_STRINGS];
    uint8_t current;
} corto_threadString_t;

/* Set intern TLS string */
char* corto_setThreadString(char* string) {
    corto_threadString_t *data = corto_tls_get(CORTO_KEY_THREAD_STRING);
    int32_t len = strlen(string);
    int32_t max = 0;

    if (!data) {
        data = corto_calloc(sizeof(corto_threadString_t));
        corto_tls_set(CORTO_KEY_THREAD_STRING, data);
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
        int32_t i;
        for (i = 0; i < CORTO_MAX_TLS_STRINGS; i++) {
            if (data->strings[i]) {
                corto_dealloc(data->strings[i]);
            }
        }
    }

    corto_dealloc(data);
}

static char* g_num = "0123456789";
static int nmax = 1;

char* corto_itoa(int num, char* buff) {
    char* buffptr;
    unsigned int ch;
    unsigned int ntest;
    int i;
    int ignoreNull;

    if (nmax == 1) {
        i = log10(INT_MAX);
        for (; i>=1; i--) {
            nmax *= 10;
        }
    }

    ntest = nmax;
    buffptr = buff;
    ignoreNull = TRUE;

    if (!num) {
        *buffptr = '0';
        buffptr++;
    } else {
        if (num < 0) {
            *buffptr = '-';
            buffptr++;
            num *= -1;
        }

        while (ntest) {
            ch = num / ntest;
            if (ch) ignoreNull = FALSE;

            if (!ignoreNull) {
                *buffptr = g_num[ch];
                buffptr++;
            }

            num -= ch * ntest;
            ntest /= 10;
        }
    }

    *buffptr = '\0';

    return buffptr;
}

char* corto_utoa(unsigned int num, char* buff) {
    CORTO_UNUSED(num);
    CORTO_UNUSED(buff);
    return NULL;
}

char* corto_ftoa(float num, char* buff) {
    CORTO_UNUSED(num);
    CORTO_UNUSED(buff);
    return NULL;
}

int32_t corto_pathToArray(char *path, char *elements[], char *sep) {
    int32_t count = 0;
    char *ptr = path;

    if (*ptr == *sep) {
        elements[count ++] = ptr;
        *ptr = '\0';
        ptr ++;
    }
    if (*ptr) {
        do {
            /* Never parse more elements than maximum scope depth */
            if (count == CORTO_MAX_SCOPE_DEPTH) {
                corto_seterr(
                    "number of elements in path exceeds MAX_SCOPE_DEPTH (%d)",
                    CORTO_MAX_SCOPE_DEPTH);
                goto error;
            }
            if (*ptr == *sep) {
                *ptr = '\0';
                ptr++;
            }
            elements[count ++] = ptr;
        } while ((ptr = strchr(ptr, *sep)));
    }

    return count;
error:
    return -1;
}

#if 0
struct corto_benchmark {
    char* name;
    corto_time start;
    double total;
    int count;
};
static struct corto_benchmark corto_benchmarks[CORTO_MAX_BENCHMARK];
static int corto_benchmark_count;

int corto_benchmark_init(char* name) {
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
