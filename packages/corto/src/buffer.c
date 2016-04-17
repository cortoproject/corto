
#include "corto/corto.h"

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

/* Append a format string to a buffer */
corto_bool corto_buffer_append(
    corto_buffer *b,
    corto_string fmt,
    ...)
{
    va_list args;
    va_list argcpy;
    corto_bool result = TRUE;

    /* If this is the first time append is called, initialize buffer structure */
    if (!b->elementCount) {
        b->firstElement.next = NULL;
        b->firstElement.pos = 0;
        b->elementCount ++;
        b->current = &b->firstElement;
    }

    corto_int32 spaceLeftInElement = corto_buffer_spaceLeftInCurrentElement(b);
    corto_int32 spaceLeft = corto_buffer_spaceLeft(b);

    /* Compute the memory required to add the string to the buffer */
    va_start(args, fmt);
    va_copy(argcpy, args);
    corto_int32 memRequired = vsnprintf(
        corto_buffer_ptr(b),
        (b->max && (spaceLeft < spaceLeftInElement)) ? spaceLeft : spaceLeftInElement + 1,
        fmt,
        args);
    va_end(args);

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

                vsprintf(corto_buffer_ptr(b), fmt, argcpy);
                memmove(
                    corto_buffer_ptr(b),
                    corto_buffer_ptr(b) + spaceLeftInElement,
                    len);
                b->current->pos = len;

            /* If the extra memory required exceeds the elementSize, allocate a
             * temporary string that will hold the full value, then distribute
             * the results over the new elements */
            } else {
                corto_string str = corto_alloc(memRequired + 1);
                char *ptr = str + spaceLeftInElement;
                corto_int32 memLeft = memRequired - spaceLeftInElement;
                vsprintf(str, fmt, argcpy);

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

                corto_dealloc(str);
            }
        } else {
            result = FALSE;
        }
    } else {
        b->current->pos += memRequired;
    }

    va_end(argcpy);

    return result;
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
