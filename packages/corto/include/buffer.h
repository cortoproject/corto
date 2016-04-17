
#ifndef CORTO_BUFFER_H_
#define CORTO_BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_BUFFER_INIT (corto_buffer){NULL, 0, 0}
#define CORTO_BUFFER_ELEMENT_SIZE (511)

/* A buffer builds up a list of elements which individually can be up to N bytes
 * large. While appending, data is added to these elements. More elements are
 * added on the fly when needed. When an application calls corto_buffer_str, all
 * elements are combined in one string and the element administration is freed.
 *
 * This approach prevents reallocs of large blocks of memory, and therefore
 * copying large blocks of memory when appending to a large buffer. A buffer
 * preallocates some memory for the element overhead so that for small strings
 * there is hardly any overhead, while for large strings the overhead is offset
 * by the reduced time spent on copying memory.
 */

typedef struct corto_buffer_element {
   char buf[CORTO_BUFFER_ELEMENT_SIZE + 1];
   corto_uint32 pos;
   struct corto_buffer_element *next;
} corto_buffer_element;

typedef struct corto_buffer {
    /* When set by an application, append will write to this buffer */
    corto_string buf;

    /* The maximum number of characters that may be printed */
    corto_uint32 max;

    /* The number of elements in use */
    corto_uint32 elementCount;

    /* Always allocate at least one element */
    corto_buffer_element firstElement;

    /* The current element being appended to */
    corto_buffer_element *current;
} corto_buffer;

/* Append to a buffer.
 * Returns false when max is reached, true when there is still space */
corto_bool corto_buffer_append(
    corto_buffer *buffer,
    corto_string fmt,
    ...);

/* Return result string */
corto_string corto_buffer_str(corto_buffer *buffer);

#ifdef __cplusplus
}
#endif

#endif
