/*
 * db_compare_ser.h
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#ifndef DB_COMPARE_SER_H_
#define DB_COMPARE_SER_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
/* String serializer data */
typedef struct db_compare_ser_t {
    db_equalityKind equals;
    db_value value;
    db_equalityKind result;
    
    /* Private members */
    void *base;
}db_compare_ser_t;

struct db_serializer_s db_compare_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);
    
#ifdef __cplusplus
}
#endif

#endif /* DB_COMPARE_SER_H_ */
