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

#include <corto/corto.h>

/* Add an extra element to the buffer */
static void corto_buffer_grow(corto_buffer *b) {
    /* Allocate new element */
    corto_buffer_element *e = corto_alloc(sizeof(corto_buffer_element));
    b->current->next = e;
    b->current = e;
    e->pos = 0;
    e->next = NULL;
    b->elementCount ++;
}

static char* corto_buffer_ptr(corto_buffer *b) {
    if (b->buf) {
        return &b->buf[b->current->pos];
    } else {
        return &b->current->buf[b->current->pos];
    }
}

/* Copy string to element */
static void corto_buffer_copy(
    corto_buffer *b,
    corto_string str,
    corto_uint32 len)
{
    memcpy(corto_buffer_ptr(b), str, len);
    b->current->pos += len;
}

/* Compute the amount of space left in the current element */
static corto_int32 corto_buffer_spaceLeftInCurrentElement(corto_buffer *b) {
    if (b->buf) {
        return b->max - b->current->pos;
    } else {
        return CORTO_BUFFER_ELEMENT_SIZE - b->current->pos;
    }
}

/* Compute the amount of space left */
static corto_int32 corto_buffer_spaceLeft(corto_buffer *b) {
    if (b->buf) {
        return corto_buffer_spaceLeftInCurrentElement(b);
    } else {
        return
          b->max -
            ((b->elementCount - 1) * CORTO_BUFFER_ELEMENT_SIZE) -
            (b->current->pos);
    }
}

static void corto_buffer_init(corto_buffer *b) {
    /* Initialize buffer structure only once */
    if (!b->elementCount) {
        b->firstElement.next = NULL;
        b->firstElement.pos = 0;
        b->elementCount ++;
        b->current = &b->firstElement;
    }
}

/* Append a format string to a buffer */
static corto_bool corto_buffer_appendIntern(
    corto_buffer *b,
    corto_string str,
    void *data,
    corto_uint32 ___ (*copy)(char *dst, char *str, corto_int32 len, void *data))
{
    corto_bool result = TRUE;

    if (!str) {
        return result;
    }

    corto_buffer_init(b);

    corto_int32 spaceLeftInElement = corto_buffer_spaceLeftInCurrentElement(b);
    corto_int32 spaceLeft = corto_buffer_spaceLeft(b);

    /* Compute the memory required to add the string to the buffer */
    corto_int32 memRequired = copy(
        corto_buffer_ptr(b),
        str,
        (b->max && (spaceLeft < spaceLeftInElement)) ? spaceLeft : spaceLeftInElement + 1,
        data);

    if (b->max && (spaceLeft < memRequired)) {
        result = FALSE;
    }

    /* If the string required more memory than was available in the element,
     * grow the buffer */
    else if (memRequired >= spaceLeftInElement) {
        /* If writing to a user-provided buffer, the max is reached and append
         * should return false. Otherwise, the buffer needs to grow with extra
         * elements. */
        b->current->pos += spaceLeftInElement;
        if (!b->buf) {
            /* If the extra required memory doesn't exceed the elementsize, grow
             * a new element, vsnprintf into the element and then memmove to
             * truncate the part that was already added to the previous
             * element */
            if (memRequired < CORTO_BUFFER_ELEMENT_SIZE) {
                corto_buffer_grow(b);
                corto_int32 len = 0;

                if (b->max && (spaceLeft < CORTO_BUFFER_ELEMENT_SIZE)) {
                    len = spaceLeft;
                    result = FALSE;
                } else {
                    len = memRequired - spaceLeftInElement;
                }

                copy(corto_buffer_ptr(b), str, CORTO_BUFFER_ELEMENT_SIZE, data);
                memmove(
                    corto_buffer_ptr(b),
                    corto_buffer_ptr(b) + spaceLeftInElement,
                    len);
                b->current->pos = len;

            /* If the extra memory required exceeds the elementSize, allocate a
             * temporary string that will hold the full value, then distribute
             * the results over the new elements */
            } else {
                corto_string dst = corto_alloc(memRequired + 1);
                char *ptr = dst + spaceLeftInElement;
                corto_int32 memLeft = memRequired - spaceLeftInElement;

                /* Copy entire string to heap memory */
                copy(dst, str, memRequired + 1, data);

                /* Copy string to elements */
                while (memLeft > 0) {
                    corto_buffer_grow(b);
                    if (memLeft > CORTO_BUFFER_ELEMENT_SIZE) {
                        corto_buffer_copy(b, ptr, CORTO_BUFFER_ELEMENT_SIZE);
                        ptr += CORTO_BUFFER_ELEMENT_SIZE;
                        memLeft -= CORTO_BUFFER_ELEMENT_SIZE;
                    } else {
                        corto_buffer_copy(b, ptr, memLeft);
                        memLeft = 0;
                    }
                }
                corto_dealloc(dst);
            }
        } else {
            result = FALSE;
        }
    } else {
        b->current->pos += memRequired;
    }

    return result;
}

typedef struct corto_buffer_fmt_t {
    va_list args;
    va_list argcpy;
    corto_int8 call;
} corto_buffer_fmt_t;

static corto_uint32 corto_buffer_fmtcpy(
    char *dst,
    char *src,
    corto_int32 len,
    void *userData)
{
    corto_buffer_fmt_t *data = userData;
    data->call ++;
    return vsnprintf(dst, len, src, data->call == 1 ? data->args: data->argcpy);
}

corto_bool corto_buffer_vappend(
    corto_buffer *b,
    corto_string fmt,
    va_list args)
{
    corto_buffer_fmt_t data;

    va_copy(data.args, args);
    va_copy(data.argcpy, args);
    data.call = 0;

    corto_bool result = corto_buffer_appendIntern(
        b, fmt, &data, corto_buffer_fmtcpy
    );

    va_end(data.args);
    va_end(data.argcpy);

    return result;
}

corto_bool corto_buffer_append(
    corto_buffer *b,
    corto_string fmt,
    ...)
{
    corto_buffer_fmt_t data;

    va_start(data.args, fmt);
    va_copy(data.argcpy, data.args);
    data.call = 0;

    corto_bool result = corto_buffer_appendIntern(
        b, fmt, &data, corto_buffer_fmtcpy
    );

    va_end(data.args);
    va_end(data.argcpy);

    return result;
}

static corto_uint32 corto_buffer_strcpy(
    char *dst,
    char *src,
    corto_int32 len,
    void *userData)
{
    char *ptr, ch, *bptr = dst;
    CORTO_UNUSED(userData);

    /* Prevent doing both a strcpy and a strlen */
    for(ptr = src; (ch = *ptr); ptr++) {
        if ((ptr - src) < len) {
            *(bptr++) = ch;
        }
    }

    return ptr - src;
}

corto_bool corto_buffer_appendstr(
    corto_buffer *b,
    corto_string str)
{
    return corto_buffer_appendIntern(
        b, str, NULL, corto_buffer_strcpy
    );
}

static corto_uint32 corto_buffer_strncpy(
    char *dst,
    char *src,
    corto_int32 len,
    void *userData)
{
    char *ptr, ch, *bptr = dst;
    corto_uint32 srclen = *(corto_uint32*)userData;

    /* Prevent doing both a strcpy and a strlen */
    for(ptr = src; (ch = *ptr) && ((ptr - src) < srclen); ptr++) {
        if ((ptr - src) < len) {
            *(bptr++) = ch;
        }
    }

    return srclen;
}

corto_bool corto_buffer_appendstrn(
    corto_buffer *b,
    corto_string str,
    corto_uint32 len)
{
    return corto_buffer_appendIntern(
        b, str, &len, corto_buffer_strncpy
    );
}

corto_string corto_buffer_str(corto_buffer *b) {
    corto_string result = NULL;

    if (b->elementCount) {
        if (b->buf) {
            result = corto_strdup(b->buf);
        } else {
            void *next = NULL;
            corto_uint32 len = (b->elementCount - 1) * CORTO_BUFFER_ELEMENT_SIZE +
                b->current->pos + 1;

            corto_buffer_element *e = &b->firstElement;

            result = corto_alloc(len);
            corto_string ptr = result;

            do {
                memcpy(ptr, e->buf, e->pos);
                ptr += e->pos;
                next = e->next;
                if (e != &b->firstElement) {
                    corto_dealloc(e);
                }
            } while ((e = next));

            result[len - 1] = '\0';
        }
    } else {
        result = NULL;
    }

    b->elementCount = 0;

    return result;
}

void corto_buffer_reset(corto_buffer *b) {
    if (b->elementCount && !b->buf) {
        void *next = NULL;
        corto_buffer_element *e = &b->firstElement;
        do {
            next = e->next;
            if (e != &b->firstElement) {
                corto_dealloc(e);
            }
        } while ((e = next));
    }

    *b = CORTO_BUFFER_INIT;
}
