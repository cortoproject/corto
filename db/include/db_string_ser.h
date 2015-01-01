/*
 * cx_string_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef DB_STRING_SER_H_
#define DB_STRING_SER_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct cx_string_ser_t {
    /* Public */
    char* buffer;
    unsigned int length;
    unsigned int maxlength;
    cx_bool prefixType;

    /* Private */
    char* ptr;
    unsigned int itemCount;
    cx_bool compactNotation;
    cx_ll anonymousObjects;
} cx_string_ser_t;

struct cx_serializer_s cx_string_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_SER_H_ */
