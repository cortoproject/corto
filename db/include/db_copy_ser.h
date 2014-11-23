/*
 * db_copy_ser.h
 *
 *  Created on: Sep 20, 2014
 *      Author: sander
 */

#ifndef DB_COPY_SER_H_
#define DB_COPY_SER_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    /* String serializer data */
    typedef struct db_copy_ser_t {
        db_value value;
        
        /* Private members */
        void *base;
    }db_copy_ser_t;
    
    struct db_serializer_s db_copy_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);
    
#ifdef __cplusplus
}
#endif

#endif /* DB_COPY_SER_H_ */
