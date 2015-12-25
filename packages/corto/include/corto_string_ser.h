/*
 * corto_string_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef CORTO_STRING_SER_H_
#define CORTO_STRING_SER_H_

#include "corto_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct corto_string_ser_t {
    /* Public */
    char* buffer;
    unsigned int length;
    unsigned int maxlength;
    corto_bool prefixType;
    corto_bool enableColors;

    /* Private */
    char* ptr;
    unsigned int itemCount;
    corto_bool compactNotation;
    corto_ll anonymousObjects;
} corto_string_ser_t;

struct corto_serializer_s corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_STRING_SER_H_ */
