#include <stdio.h>

#include "cortex.h"
#include "cx_serializer.h"

typedef struct cx_sqlite_ser_t {
    /**/
    cx_string buffer;
    cx_string ptr;
    /**/
    unsigned int length;
    unsigned int maxlength;
    unsigned int itemCount;
} cx_sqlite_ser_t;

struct cx_serializer_s cx_sqlite_declare_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
struct cx_serializer_s cx_sqlite_define_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
struct cx_serializer_s cx_sqlite_update_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
