/* include/json.h
 *
 * This file is generated. Do not modify.
 */

#ifndef json_H
#define json_H

#include "corto.h"
#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
#include "corto_serializer.h"

#define CORTO_JSON_ROOT_NAME "::"
#define CORTO_JSON_ROOT_PARENT ""

/* JSON serializer data */
typedef struct corto_json_ser_t {
    /* Public */
    corto_string buffer;
    corto_string ptr;
    unsigned int length;
    unsigned int maxlength;
    unsigned int itemCount;
    corto_bool serializeMeta;
    corto_bool serializeValue;
    corto_bool serializeScope;
    corto_bool alwaysIncludeHeaders;
    corto_bool serializePrefix;
} corto_json_ser_t;

struct corto_serializer_s corto_json_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);
corto_object corto_json_deser(corto_string s);
corto_string json_serialize(corto_object o);

/* $end */

#ifdef __cplusplus
}
#endif
#endif

