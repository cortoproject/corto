/*
 * db_string_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef DB_STRING_SER_H_
#define DB_STRING_SER_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* String serializer data */
typedef struct db_string_ser_t {
    /* Public */
    char* buffer;
    unsigned int length;
    unsigned int maxlength;
    db_bool prefixType;

    /* Private */
    char* ptr;
    unsigned int itemCount;
    db_bool compactNotation;
    db_ll anonymousObjects;
}db_string_ser_t;

struct db_serializer_s db_string_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* DB_STRING_SER_H_ */
