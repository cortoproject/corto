#ifndef json_H
#define json_H

#include <stdio.h>

#include "cortex.h"
#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CX_JSON_ROOT_NAME "::"
#define CX_JSON_ROOT_PARENT ""

/* JSON serializer data */
typedef struct cx_json_ser_t {
    /* Public */
    cx_string buffer;
    cx_string ptr;
    unsigned int length;
    unsigned int maxlength;
    unsigned int itemCount;
    cx_bool serializeMeta;
    cx_bool serializeValue;
    cx_bool serializeScope;
    cx_bool alwaysIncludeHeaders;
} cx_json_ser_t;

struct cx_serializer_s cx_json_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);

cx_object cx_json_deser(cx_string s);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif
