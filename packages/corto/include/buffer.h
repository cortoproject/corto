
#ifndef CORTO_BUFFER_H_
#define CORTO_BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_buffer {
    corto_string str;
    corto_uint32 len;
    corto_uint32 max;
} corto_buffer;

corto_bool corto_buffer_append(
    corto_buffer *buffer,
    corto_string fmt,
    ...);

#ifdef __cplusplus
}
#endif

#endif
