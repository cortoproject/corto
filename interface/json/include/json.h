#include <stdio.h>

#include "hyve.h"
#include "db_serializer.h"

/* String serializer data */
typedef struct db_json_ser_t {
    /* Public */
    db_string buffer;
    db_string ptr;
    unsigned int length;
    unsigned int maxlength;
    unsigned int itemCount;
    db_bool serializeMeta;
    db_bool serializeValue;
    db_bool serializeScope;
} db_json_ser_t;

struct db_serializer_s db_json_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);
