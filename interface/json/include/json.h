#include <stdio.h>

#include "cortex.h"
#include "cx_serializer.h"

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
